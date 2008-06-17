// compSched.cxx - the scheduler component.  -*- C++ -*-

// Copyright (C) 1999-2003, 2005, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidtypes.h>
#include <sidmiscutil.h>
#include <sidpinattrutil.h>

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cassert>


#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif
#ifdef HAVE_SYS_TIMEB_H
#include <sys/timeb.h>
#endif
#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif
#ifdef HAVE_MMSYSTEM_H
#include <mmsystem.h>
#endif

#ifdef HAVE_SCHED_H
#include <sched.h>
#endif

#ifndef HAVE_USLEEP_DECL
extern "C" void usleep (unsigned long);
#endif
#ifndef HAVE_FTIME_DECL
extern "C" int ftime (struct timeb *);
#endif



namespace scheduler_component
{
  using sid::host_int_8;
  using sid::host_int_4;
  using sid::host_int_2;
  using sid::host_int_1;
  using sid::component;

  using sidutil::fixed_pin_map_component;
  using sidutil::fixed_attribute_map_component;
  using sidutil::no_accessor_component;
  using sidutil::no_relation_component;
  using sidutil::no_bus_component;
  using sidutil::output_pin;
  using sidutil::input_pin;
  using sidutil::callback_pin;
  using sidutil::bijection;
  using sidutil::make_attribute;
  using sidutil::make_numeric_attribute;
  using sidutil::parse_attribute;
  using sidutil::tokenize;
  using sidutil::recursion_limited;
  using sidutil::recursion_record;

  using std::map;
  using std::deque;
  using std::vector;
  using std::string;
  using std::pop_heap;
  using std::push_heap;
  using std::sort_heap;
  using std::ostream;
  using std::istream;
  using std::pair;
  using std::make_pair;
  using std::ios;
  using std::endl;
  using std::cerr;


  // some forward declarations
  template <unsigned> class apprx_host_time_keeper;
  template <unsigned d> ostream& operator << (ostream& o, const apprx_host_time_keeper<d>& it);
  template <unsigned d> istream& operator >> (istream& i, apprx_host_time_keeper<d>& it);

  template <class T> class generic_scheduler;
  template <class T> ostream& operator << (ostream& o, const generic_scheduler<T>& it);
  template <class T> istream& operator >> (istream& i, generic_scheduler<T>& it);

  template <class T> class scheduler_component;
  template <class T> ostream& operator << (ostream& o, const scheduler_component<T>& it);
  template <class T> istream& operator >> (istream& i, scheduler_component<T>& it);



// ----------------------------------------------------------------------------

  // Measure time in this size value.
  typedef host_int_8 tick_t;

  struct scheduling_event
  {
    tick_t      when;
    tick_t      interval;
    output_pin* what;
    host_int_4  priority;

    scheduling_event(): when(0), interval(0), what(0), priority (0) {}
    scheduling_event(tick_t when, output_pin* what, host_int_4 priority): 
      when(when), interval(0), what(what), priority(priority) {}
    scheduling_event(tick_t when, tick_t interval, output_pin* what, host_int_4 priority): 
      when(when), interval(interval), what(what), priority(priority) {}
  };

  // Define a comparison function for heaps of scheduling events.  It
  // uses REVERSE ordering, so [a.time < b.time] ==> [a > b]
  inline bool
  operator < (const scheduling_event& a, const scheduling_event& b)
{
  return (a.when > b.when) || ((a.when == b.when) && (a.priority < b.priority));
}


// ----------------------------------------------------------------------------


  // Measure target time in some configuration-implied units
  class target_time_keeper
  {
    friend ostream& operator << (ostream& o, const target_time_keeper& it);
    friend istream& operator >> (istream& i, target_time_keeper& it);

    tick_t master_clock;

  public:
    target_time_keeper(): master_clock(0) {}

    void get_now(tick_t& out) const
      {
	// cerr << "target_time_keeper.now = " << this->master_clock << endl;
	out = this->master_clock; 
      }

    void set_now(tick_t then)
      {
	// cerr << "target_time_keeper.now := " << then << endl;
	this->master_clock = then; 
      }

    void advance(tick_t when)
      {
	assert(this->master_clock <= when);
	// cerr << "target_time_keeper.advance " << when << endl;
	this->master_clock = when;
      }

    void yield(tick_t when)
      {
	// cannot yield fictitious "target time".
      }
  };


ostream& 
operator << (ostream& o, const target_time_keeper& it)
{
  o << "ttk t=" << it.master_clock;
  return o;
}

// Not called but needs to be present.
istream& 
operator >> (istream& i, target_time_keeper& it)
{
  assert (0);
  return i;
}


// ------------------------------------------------------------------------


  // Provide common yield() functionality for both host_time_keepers
  // 
  class host_time_keeper_base
  {
  protected:
    unsigned long num_yields;
    tick_t total_yield_time;
    unsigned long num_sleeping_yields;
    tick_t total_sleep_time;
    float drowsiness; // the amount by which select/usleep tend to oversleep

  public:

    void system_now (tick_t& out) const;

    host_time_keeper_base() 
      {
	this->drowsiness = 0.0;
	this->num_yields = 0;
	this->total_yield_time = 0;
	this->num_sleeping_yields = 0;
	this->total_sleep_time = 0;

#if HAVE_LIBWINMM
	// On Windows, this call is needed to request that the kernel
	// scheduler make its granularity smaller than the default
	// 10-100 ms.
	timeBeginPeriod (1); // 1 ms
#endif
      }

    ~host_time_keeper_base () throw ()
    {
#if HAVE_LIBWINMM
      timeEndPeriod (1);
#endif
    }

    // Put the process to sleep until `then'.
    void yield(tick_t then);
  };



// Put the process to sleep until `then'.
void host_time_keeper_base::yield(tick_t then)
{
  tick_t n;
  this->system_now (n);

  if (then < n) then = n;

  // NB: Since we've been asked to yield, let's do so,
  // even if then == n.

  this->num_yields ++;
  this->total_yield_time += (then - n);

  // compensate for drowsiness
  tick_t drowsiness_int = (tick_t) drowsiness;

  if ((then - n) <= drowsiness_int)
    {
      // usleep is deemed too drowsy .. but we can do a plain process
      // yield anyway
#if HAVE_SCHED_YIELD
      sched_yield ();
#elif __CYGWIN__
      Sleep (0);
#endif

      // Decay drowsiness slowly, to prevent a momentary
      // high-drowsiness pulse from keeping us from trying 
      // again.
      if (UNLIKELY(((this->num_yields & 0xff) == 0) &&
		   (this->drowsiness > 3.0)))
	this->drowsiness *= 0.5;

      return;
    }

  unsigned long ms = ((then - n) - drowsiness_int);
  if (ms > 1000) ms = 1000; // Clamp it
  unsigned long us = ms * 1000;
	
  this->num_sleeping_yields ++;
  this->total_sleep_time += ms;
	
#if HAVE_USLEEP
  usleep (us);
#else
  sleep (us / 1000000);
#endif
	
  // Help recalibrate the drowsiness measure periodically
  if (UNLIKELY((this->num_sleeping_yields & 0xf) == 0))
    {
      tick_t n2;
      this->system_now (n2);
	    
      // Update moving average
      tick_t drowsiness_error = (n2 - (n + ms));
      this->drowsiness += 0.01 * drowsiness_error;

      // Clamp it to within reasonable limits
      if (this->drowsiness < 0.0) this->drowsiness = 0.0;
      if (this->drowsiness > 100.0) this->drowsiness = 100.0;
    }
}


void host_time_keeper_base::system_now (tick_t& out) const
{
#ifdef HAVE_GETTIMEOFDAY
  struct timeval tv;
  (void) gettimeofday (& tv, 0); // assume success
  out = ((tick_t)tv.tv_sec * (tick_t)1000) + ((tick_t)tv.tv_usec / (tick_t)1000);
#else
#ifdef HAVE_FTIME
  struct ::timeb system_time;
  ftime (& system_time);
  out = (tick_t)system_time.time * (tick_t)1000 + (tick_t)system_time.millitm;
#else
  // XXX: alternatives:
  // time
  // __asm__ access to hardware clock
#error "Don't know how to fetch system ms time on this platform"
#endif
#endif
  // cerr << "apprx_host_time_keeper.now = " << t << endl;
}


// ----------------------------------------------------------------------------


  // Measure host CPU time in fractions of seconds.
  // The accuracy is 1000/dilution Hz; the precision is 1000 Hz.
  template <unsigned dilution>
  class apprx_host_time_keeper: public host_time_keeper_base
  {
    friend ostream& operator << <> (ostream& o, const apprx_host_time_keeper& it);
    friend istream& operator >> <> (istream& i, apprx_host_time_keeper& it);

    mutable tick_t prev_now;                   // previous system_now() value
    mutable host_int_4 iterations;         // now() invocation counter
    mutable host_int_4 iterations_per_dms; // limit for counter "diluted milliseconds"

  public:
    apprx_host_time_keeper(): prev_now(0), iterations(0), iterations_per_dms(1)
      {}

    void
    system_now(tick_t& out) const
      {
	host_time_keeper_base::system_now (out);

	// Detect the host time going backward
	if (out < this->prev_now)
	  {
	    cerr << "Host time stepped backward: " 
		 << this->prev_now << " to " << out << endl;
	    out = this->prev_now;
	  }
      }


    // out-of-line
    void get_now(tick_t& out) const;

    void set_now (tick_t then)
      {
	// cannot set host time
	// Reset iteration heuristics, since we're probably fresh
	// from a state restore.
	this->iterations_per_dms = 1;
      }

    void advance(tick_t then) 
      { 
	// cannot advance host time
      }

    void yield(tick_t then)
      {
	host_time_keeper_base::yield (then);

	// Advance iteration counter so that system time is queried next
	this->iterations = this->iterations_per_dms;
      }
  };


template <unsigned dilution>
ostream& 
operator << (ostream& o, const apprx_host_time_keeper<dilution>& it)
{
  o << "htk" << dilution
    //    << " pn=" << it.prev_now
    << " it=" << it.iterations
    << " it/dms=" << it.iterations_per_dms
    << " drowsy=" << it.drowsiness;
  return o;
}


// Not called but needs to be present.
template <unsigned dilution>
istream& 
operator >> (istream& i, apprx_host_time_keeper<dilution>& it)
{
  assert (0);
  return i;
}




// Return the current host time in fractional-seconds since some
// epoch.  Minimize the rate of system calls needed for this by
// assuming that this function tends to get called regularly, but
// much more frequently than 1000/dilution Hz.
//
// This wants to grow up into a real PLL.
//
template <unsigned dilution>
void
apprx_host_time_keeper<dilution>::get_now(tick_t& out) const
{
  // this->iterations_per_dms = 1;
  // cerr << "iters=" << this->iterations << " max=" << this->iterations_per_dms << endl;

  this->iterations ++;

  // Short circuit measurement using heuristic
  if (LIKELY(this->iterations < this->iterations_per_dms))
    {
      // Don't fetch new system time yet.  Assume we're
      // still in the same host interval.

      out = this->prev_now;

#if 0
      // XXX: good idea?
      // Interpolate to keep time moving forward
      out += ((this->iterations_per_dms - this->iterations) * dilution)
	/ (this->iterations_per_dms);
#endif

      return;
    }

  // Fetch new system time
  tick_t new_now;
  this->system_now (new_now);

  // cerr << "new=" << new_now << " last=" << this->prev_now << endl;

  // Analyze the jump (if any) in host time, to adjust the iterations counter.
  
  // Still close to the same host time?  Too few iterations!
  if (new_now <= this->prev_now + dilution/2)
    {
      // We should not come near overflowing even 31 bits of
      // this 32-bit counter!
      assert (this->iterations_per_dms < 2147483647L); // LONG_MAX

      // Increase no. of iterations by 10% + 1
      // XXX: confirm that this heuristic behaves well
      this->iterations_per_dms += (this->iterations_per_dms / 10) + 1;
      // this->iterations = 0;     -- no - continue iterating instead
      // this->prev_now = new_now; -- no - unnecessary since they are equal
    }
  // In the ideal case, within around one tick past the previous,
  // so we must have skipped the right number of iterations.
  else if (UNLIKELY(new_now <= this->prev_now + dilution*3/2))
    {
      this->iterations = 0;
      this->prev_now = new_now;
    }
  // Host time went way ahead?  Too many iterations!
  else
    {
      assert (new_now > this->prev_now + dilution*3/2);
      tick_t delta = (new_now - this->prev_now) / dilution;
      // Divide no. of iterations by delta
      // (This should work even if prev_now == 0 -- we've just booted).
      // XXX: confirm that this heuristic behaves well
      this->iterations_per_dms /= delta;
      this->iterations = 0;
      this->prev_now = new_now;
    }

  // Return value
  out = new_now;
}


// ------------------------------------------------------------------------


  // Measure host CPU time in fractions of seconds.
  // The accuracy is 1000 Hz; the precision is 1000 Hz.
  class exact_host_time_keeper: public host_time_keeper_base
  {
    friend ostream& operator << (ostream& o, const exact_host_time_keeper& it);
    friend istream& operator >> (istream& i, exact_host_time_keeper& it);

  public:

    exact_host_time_keeper() {}

    void
    get_now(tick_t& out) const
      {
	system_now (out);
      }


    void set_now (tick_t then)
      {
	// cannot set host time
      }

    void advance(tick_t then) 
      { 
	// cannot advance host time
      }
  };


ostream& 
operator << (ostream& o, const exact_host_time_keeper& it)
{
  tick_t n;
  it.get_now (n);
  o << "ahtk"
    << " drwsy=" << it.drowsiness;
  if (it.num_yields > 0)
    o << " yld=" << it.num_yields
      << "*" << it.total_yield_time / (float)it.num_yields << "ms";
  if (it.num_sleeping_yields > 0)
    o << " sleep=" << it.num_sleeping_yields
      << "*" << it.total_sleep_time / (float)it.num_sleeping_yields << "ms";
  return o;
}


// Not called but needs to be present.
istream& 
operator >> (istream& i, exact_host_time_keeper& it)
{
  assert (0);
  return i;
}


// ----------------------------------------------------------------------------

  // The meaty class!
  template <class Timekeeper>
  class generic_scheduler
  {
  protected:
    mutable vector<scheduling_event> irregular_events;     // sorted as a heap
    mutable vector<scheduling_event> regular_events;       // unsorted
    mutable vector<scheduling_event> regular_events_table; // sorted linearly by time
    static const unsigned regular_event_table_size = 1000; // has this many entries
    vector<scheduling_event>::iterator regular_table_iter;
    mutable bijection<string,output_pin*> pin_state_map;   // map pin*<->string for state dumps

  public:
    Timekeeper timer;

    // expose for attribute setting from scheduler_component<>
    host_int_4 step_cycle_limit;     // max number of event loop iterations per tick
    bool yield_step_loop_p;              // nonlocal abort request for loop

  protected:

    // This scheduler has been instructed to yield unused time back to
    // the OS.  Yield back the "time" to the next event.
    void
    yield()
      {
	// cerr << "yield" << endl;
	scheduling_event* irnext = 0;
	if (! this->irregular_events.empty ())
	  irnext = & this->irregular_events.front ();

	scheduling_event* rnext = 0;
	if (! this->regular_events.empty ())
	  {
	    assert (this->regular_table_iter != this->regular_events_table.end());
	    rnext = & * this->regular_table_iter;
	  }

	tick_t yield_until;
	if ((rnext && irnext
	     && ((rnext->when < irnext->when)
		 || (rnext->when == irnext->when && rnext->priority > irnext->priority)))
	    || (rnext && !irnext))
	  yield_until = rnext->when;
	else if (irnext)
	  yield_until = irnext->when;
	else
	  // We have no pending events -> no idea how long to yield.
	  // Yield just one quantum.
	  {
	    this->timer.get_now (yield_until);
	    yield_until ++;
	  }

	this->timer.yield (yield_until);
      }


    // out-of-line
    void refill_regular_events_table();


    // Deliver the regular event at the front of the regular event table.
    void 
    deliver_regular(scheduling_event* rnext)
      {
	// cerr << "deliver_regular" << endl;
	assert (rnext == & * this->regular_table_iter);
	output_pin* victim = rnext->what;
	// advance regular-event table iterator and refill cache
	this->regular_table_iter ++;
	if (this->regular_table_iter == this->regular_events_table.end())
	  this->refill_regular_events_table();
	// deliver event
	assert (victim);
	victim->drive (rnext->when);
      }


    // Deliver the irregular event at the front of the irregular event heap.
    void 
    deliver_irregular(scheduling_event* irnext)
      {
	// cerr << "deliver_irregular" << endl;
	assert (irnext == & this->irregular_events.front ());
	// next is the irregular event
	output_pin* victim = irnext->what;
	// drop event from heap
	pop_heap(this->irregular_events.begin(), this->irregular_events.end());
	this->irregular_events.pop_back();
	// deliver event
	assert (victim);
	victim->drive (irnext->when);
      }



    // Set the earliest pending event.
    pair<scheduling_event*,bool>
    next_event()
      {
	scheduling_event* irnext = 0;
	if (! this->irregular_events.empty ())
	  irnext = & this->irregular_events.front ();

	scheduling_event* rnext = 0;
	if (! this->regular_events.empty ())
	  {
	    assert (this->regular_table_iter != this->regular_events_table.end());
	    rnext = & * this->regular_table_iter;
	  }

	if ((rnext && irnext
	     && ((rnext->when < irnext->when)
		 || (rnext->when == irnext->when && rnext->priority > irnext->priority)))
	    || (rnext && !irnext))
	  {
	    return make_pair(rnext,true);
	  }
	else if (irnext)
	  {
	    return make_pair(irnext,false);
	  }
	return make_pair((scheduling_event*)0,false);
      }


    // Advance up to one event from either the regular or irregular
    // event lists.
    bool
    advance_any()
      {
	// test whether first event is due or overdue
	pair <scheduling_event*,bool> evpair = this->next_event ();
	if (evpair.first == 0)
	  return false;
	tick_t now;
	this->timer.advance (evpair.first->when);
	this->timer.get_now (now);
	if (evpair.first->when > now)
	  return false;

	// handle all other events that have become due or overdue
	unsigned due_count = 0;
	const unsigned due_limit = 1000;
	do
	  {
	    due_count ++;

	    if (evpair.second) // regular?
	      this->deliver_regular (evpair.first);
	    else // irregular?
	      this->deliver_irregular (evpair.first);

	    evpair = this->next_event ();
	  } while ((evpair.first != 0) // still an event
		   && (evpair.first->when <= now) // still due
		   && (due_count < due_limit)  // not too many iterations
		   && ! this->yield_step_loop_p);

	// cout << "sid-sched: delivered " << due_count << " due/overdue events." << endl;

	// spinning our wheels?
	if (due_count == due_limit)
	  cerr << "sid-sched: overloaded with too many overdue events!" << endl;

	return true;
      }


  public:
    generic_scheduler():
      irregular_events(),
      regular_events(),
      regular_events_table(regular_event_table_size),
      pin_state_map(),
      timer(),
      step_cycle_limit(1),
      yield_step_loop_p(false)
      {
	// Initialize iterator.  Any use in this state will trip an assert().
	this->regular_table_iter = this->regular_events_table.end();
      }


    // Return the current time.
    void
    get_now(tick_t& out) const
      {
	// cerr << "generic_scheduler.now" << endl;
	this->timer.get_now (out);
      }

    // Set the current time (as from a state restore)
    void
    set_now(tick_t when)
      {
	// cerr << "generic_scheduler.now = " << when << endl;
	this->timer.set_now (when);
      }

    // Advance the time.  Dispatch all events up to and including "now".
    void
    advance(bool yield_host_time_p)
      {
	bool loop = false;
	this->yield_step_loop_p = false;
	unsigned count = 0;
	do
	  {
	    // cerr << "scheduler::advance" << endl;
	    loop = this->advance_any();
            if (! loop) break;
	    count ++;
	  } while (LIKELY((this->yield_step_loop_p == false) 
			  && (count < this->step_cycle_limit)));

	// Yield the CPU if this scheduling cycle did not run to
	// conclusion.  This can happen if there aren't enough
	// events in the queue to keep this scheduler busy.
	if (UNLIKELY(yield_host_time_p && (count < this->step_cycle_limit)))
	  {
	    // cerr << "yielding; count=" << count << " limit=" << this->step_cycle_limit << endl;
	    this->yield();
	  }
      }


    // Schedule an irregular event.
    void
    schedule_irregular(tick_t delta, output_pin* what, host_int_4 priority)
      {
	// cerr << "schedule_irregular when=" << when << endl;

	// "when" is a delta
	tick_t now;
	this->get_now(now);
	tick_t when = now + delta;

	this->irregular_events.push_back(scheduling_event(when, what, priority));
	push_heap(this->irregular_events.begin(), this->irregular_events.end());
      }


    // Schedule a regular event, starting "when"
    void
    schedule_regular(tick_t when, tick_t interval, output_pin* what, host_int_4 priority)
      {
	// cerr << "schedule_regular when=" << when << " interval=" << interval << endl;
	this->regular_events.push_back (scheduling_event(when, interval, what, priority));
	this->refill_regular_events_table();
      }
    // Schedule a regular event starting "now"
    void
    schedule_regular(tick_t interval, output_pin* what, host_int_4 priority)
      {
	// cerr << "scheduler_regular interval=" << interval << endl;

	// infer "now" as starting time 
	tick_t now;
	this->get_now(now);
	this->schedule_regular (now, interval, what, priority);
      }


    // Unschedule all events for a particular output pin
    // (subscription)
    void
    cancel (output_pin* what)
      {
	// cerr << "cancel pin=" << what << endl;

	// zap it from the irregular event list - if it's there
	for (vector<scheduling_event>::iterator it = this->irregular_events.begin();
	     it != this->irregular_events.end();
	     it ++)
	  {
	    if (UNLIKELY(it->what == what)) // found it
	      {
		this->irregular_events.erase(it);	// zap it
		// resort irregular event heap
		sort_heap(this->irregular_events.begin(), this->irregular_events.end());
		// there should be no other occurrences of this guy
		// XXX: assert this?
		return;
	      }
	  }

	// zap it from the regular event list - if it's there
	for (vector<scheduling_event>::iterator it2 = this->regular_events.begin();
	     it2 != this->regular_events.end();
	     it2 ++)
	  {
	    if (UNLIKELY(it2->what == what)) // found it
	      {
		this->regular_events.erase(it2); 	// zap it
		// refill regular event table
		this->refill_regular_events_table(); 
		// there should be no other occurrences of this guy
		// XXX: assert this?
		return;
	      }
	  }

	// hmm -- pin does not appear in the schedules anywhere -- multiple cancel()s?
      }


    // Cancel all pending events.
    void
    cancel_all ()
      {
	this->irregular_events.clear ();
	this->regular_table_iter = this->regular_events_table.end();
	this->yield_step_loop_p = true;
      }

    // Add a pin<->string mapping
    void
    clear_pin_mappings ()
      {
	this->pin_state_map.erase_all ();
      }

    void
    add_pin_mapping (const string& s, output_pin* p)
      {
	this->pin_state_map.add (s, p);
      }

  friend ostream& operator << <> (ostream& o, const generic_scheduler& it);
  friend istream& operator >> <> (istream& i, generic_scheduler& it);
  };



// Fill the regular_events_table with entries corresponding to the
// regular_events.  Reset regular_table_iter.

template <class Timekeeper>
void
generic_scheduler<Timekeeper>::refill_regular_events_table()
{
  // cerr << "refill_regular_events_table" << endl;

  // initialize next-tick counters: time of first tick after
  // present moment
  unsigned num_tickers = this->regular_events.size();
  if (num_tickers == 0) 
    {
      // set to "unset" state
      this->regular_table_iter = this->regular_events_table.end();
      return;
    }

  // cerr << "refill_regular_events_table (phase 1)" << endl;

  tick_t now;
  this->timer.get_now (now);

  vector<tick_t> next_tick_time (num_tickers);
  for (unsigned i=0; i<num_tickers; i++)
    {
      scheduling_event* it = & this->regular_events[i];
      tick_t next_tick_index = 0;
      assert (it->interval != 0);
      if (now >= it->when)
	next_tick_index = ((now - it->when) / it->interval) + 1;
      next_tick_time[i] = it->when + (it->interval * next_tick_index);
      // cerr << " next[" << i << "]=" << next_tick_time[i] << endl;
      assert (next_tick_time[i] > now);
    }

  // cerr << "refill_regular_events_table (phase 2)" << endl;

	// fill in event_table from regular event schedule; sort of like a merge sort
  for (vector<scheduling_event>::iterator slot = this->regular_events_table.begin();
       slot != this->regular_events_table.end();
       slot++)
    {
      unsigned reg = 0; // regular_events[] index of earliest following regular event
      for (unsigned k=1; k<num_tickers; k++)
	{
	  if (next_tick_time[reg] > next_tick_time[k])
	    reg = k;
	  else if (next_tick_time[reg] == next_tick_time[k]
		   && this->regular_events[reg].priority < this->regular_events[k].priority)
	    reg = k;
	}

      slot->when = next_tick_time[reg];
      slot->interval = 0; // initialize unused field
      slot->what = this->regular_events[reg].what;
      slot->priority = this->regular_events[reg].priority;
      // cerr << " slot: when=" << slot->when << " what=" << slot->what << " priority=" << slot->priority << endl;

      next_tick_time[reg] += this->regular_events[reg].interval;
    }

  // cerr << "refill_regular_events_table (phase 3)" << endl;

	// send back results
  this->regular_table_iter = this->regular_events_table.begin();
}



// state control
template <class Timekeeper>
ostream& 
operator << (ostream& o, const generic_scheduler<Timekeeper>& it)
{
  o << "generic-scheduler ";

  // Save timer state
  tick_t now;
  it.timer.get_now (now);
  o << now << endl;

  o << it.irregular_events.size() << endl;
  // Save irregular events, relative to "now"
  for (vector<scheduling_event>::iterator t = it.irregular_events.begin();
       t != it.irregular_events.end();
       t++)
    {
      scheduling_event* e = & * t;
      string name;
      bool ok = it.pin_state_map.find(e->what, name);
      assert (ok);
      o << "  " << e->when << " " << e->priority << " " << e->interval << " " << name << endl;
    }

  o << it.regular_events.size() << endl;
  // Save regular events, relative to "now"
  for (vector<scheduling_event>::iterator t = it.regular_events.begin();
       t != it.regular_events.end();
       t++)
    {
      scheduling_event* e = & * t;
      string name;
      bool ok = it.pin_state_map.find(e->what, name);
      assert (ok);
      o << "  " << e->when << " " << e->priority << " " << e->interval << " " << name << endl;
    }

  return o;
}


template <class Timekeeper>
istream& 
operator >> (istream& i, generic_scheduler<Timekeeper>& it)
{
  string key;
  i >> key;
  if (key == "generic-scheduler")
    {
      // Restore timer state
      tick_t then;
      i >> then;
      it.timer.set_now(then);
      // In case timer cannot be reset, use the post-set-attempt time
      // as the relative "time" base for restored events.
      tick_t now;
      it.timer.get_now(now);
      // This is the delta between the two times.
      tick_t delta = now - then;


      // Clear irregular events table
      it.irregular_events.erase(it.irregular_events.begin(), it.irregular_events.end());

      // Read in irregular events
      size_t num_irregular_events;
      i >> num_irregular_events;
      for(unsigned t=0; t<num_irregular_events; t++)
	{
	  clock_t when, interval;
	  host_int_4 priority;
	  string name;
	  i >> when >> priority >> interval >> name;
	  // make base time absolute
	  when += delta;
	  // find new pin
	  output_pin* pin;
	  bool ok = it.pin_state_map.find(name, pin);
	  assert (ok);
	  // add it
	  it.irregular_events.push_back(scheduling_event(when, interval, pin, priority));
	}

      // Clear regular events table
      it.regular_events.erase(it.regular_events.begin(), it.regular_events.end());

      // Read in regular events
      size_t num_regular_events;
      i >> num_regular_events;
      for(unsigned t=0; t<num_regular_events; t++)
	{
	  clock_t when, interval;
	  host_int_4 priority;
	  string name;
	  i >> when >> priority >> interval >> name;
	  // make base time absolute
	  when += delta;
	  // find new pin
	  output_pin* pin;
	  bool ok = it.pin_state_map.find(name, pin);
	  assert (ok);
	  // add it
	  it.regular_events.push_back(scheduling_event(when, interval, pin, priority));
	}

      // get scheduler ready for operation with new data
      it.refill_regular_events_table();
    }
  else
    {
      i.setstate(ios::badbit);	  
    }
  
  return i;
}




// ----------------------------------------------------------------------------



template <class SchedComponent>
class scheduler_client
{
public:
  // These are public members for direct attribute map twiddlers
  host_int_2 scale_mul, scale_div;  // time-to-ticks conversion factor
  tick_t time;       // time of next event (irregular) or interval (regular)
  bool regular_p;    // regular (vs irregular) event source
  host_int_4 priority; // priority of client
  string name;       // "pretty" name, for use in scheduler GUI

  // These are public members for direct pin map twiddlers
  sidutil::output_pin event_pin;
  sidutil::callback_pin<scheduler_client> control_pin;

private:
  SchedComponent* comp;

private:
  void
  set_time(tick_t t)
    {
      // cerr << "client set_time t=" << t << " last=" << this->time << endl;
      this->comp->sched.cancel (& this->event_pin);
      this->time = t;

      // silently prevent division-by-zero
      if (this->scale_div == 0)
	this->scale_div = 1;

      if (LIKELY(t != 0))
	{
	  // round up away from zero
	  tick_t sched_time = t * this->scale_mul / this->scale_div;
	  if (sched_time == 0)
	    sched_time = 1;

	  if (this->regular_p)
	    this->comp->sched.schedule_regular (sched_time, & this->event_pin, this->priority);
	  else
	    this->comp->sched.schedule_irregular (sched_time, & this->event_pin, this->priority);
	}
    }

  // pin-driven event control: #ticks to next event; cancel on 0
  void
  set_control(host_int_4 t)
    {
      // cerr << "-control: t=" << t << endl;
      host_int_4 delta = 0x7fffffff & t;
      this->regular_p = (0x80000000 & t) ? true : false;
      this->set_time (delta); // will cancel() too
    }

public:
  ~scheduler_client() throw ()
    {
      // unschedule my events
      set_time (0);
    }

  scheduler_client(SchedComponent* comp): 
    scale_mul (1),
    scale_div (1),
    time (0),
    regular_p (true),
    priority (0),
    event_pin (),
    control_pin(this, & scheduler_client::set_control),
    comp(comp)
    {
      this->set_time(time);
    }

  // callback functions for direct attribute twiddlers
  void
  reset_events()
    {
      // unschedule then reschedule entries
      tick_t last_time = this->time;
      set_time (0);
      if (last_time != 0)
	set_time (last_time);
    }

  // Callbacks for scale attribute set/get
  string
  get_scale_attr ()
    {
      string mul_str = make_numeric_attribute(this->scale_mul, ios::dec);
      if (this->scale_div == 1)
	return mul_str;
      string div_str = make_numeric_attribute(this->scale_div, ios::dec);
      return (mul_str + "/" + div_str);
    }

  component::status
  set_scale_attr (const string& str)
    {
      vector<string> parts = tokenize (str, "/");
      if (parts.size() == 0) return component::bad_value;
      else if (parts.size() == 1)
	{
	  host_int_2 new_mul = 0;
	  component::status s = parse_attribute (parts[0], new_mul);
	  if (s != component::ok || new_mul == 0) return component::bad_value;

	  this->scale_mul = new_mul;
	  this->scale_div = 1;
	  this->reset_events ();
	  return component::ok;
	}
      else if (parts.size() == 2)
	{
	  host_int_2 new_mul = 0;
	  host_int_2 new_div = 0;
	  component::status s1 = parse_attribute (parts[0], new_mul);
	  component::status s2 = parse_attribute (parts[1], new_div);
	  if (s1 != component::ok || new_mul == 0) return component::bad_value;
	  if (s2 != component::ok || new_div == 0) return component::bad_value;

	  this->scale_mul = new_mul;
	  this->scale_div = new_div;
	  this->reset_events ();
	  return component::ok;
	}
      else 
	return component::bad_value;
    }
};


template <class Scheduler> class scheduler_component;

// state control
template <class Scheduler>
ostream& 
operator << (ostream& o, const scheduler_component<Scheduler>& it)
{
  o << "scheduler-state "
    << it.enable_threshold << " "
    << it.enable_p << " "
    << it.yield_host_time_threshold << " "
    << it.yield_host_time_p << " "
    << it.sched.step_cycle_limit << " "   // this is a component attribute
    << it.advance_count << " "
    << it.active_pin << " "
    << it.yield_pin << " "
    << it.advance_pin << endl;

  // Print this as a 2-byte value
  host_int_2 nc = it.num_clients;
  o << nc << endl;

  // set string<->pin mappings
  Scheduler& its = const_cast<Scheduler&>(it.sched);
  its.clear_pin_mappings ();
  for (unsigned j=0; j<it.num_clients; j++)
    {
      o << "  " 
	<< it.clients[j]->time << " "
	<< it.clients[j]->scale_mul << " "
	<< it.clients[j]->scale_div << " "
	<< it.clients[j]->regular_p << " "
	<< it.clients[j]->priority << " "
	<< endl;
      its.add_pin_mapping((make_numeric_attribute(j) + "-event"),
			  & it.clients[j]->event_pin);
    }
  
  o << it.sched;

  // NB: write dummy number without trailing whitespace, to ensure
  // that parser consumes entire string.
  int dummy = 0;
  o << dummy;

  return o;
}

template <class Scheduler>
istream& 
operator >> (istream& i, scheduler_component<Scheduler>& it)
{
  string key;
  i >> key;
  if (key == "scheduler-state")
    {
      i >> it.enable_threshold
        >> it.enable_p
	>> it.yield_host_time_threshold
	>> it.yield_host_time_p
	>> it.sched.step_cycle_limit
	>> it.advance_count
	>> it.active_pin
	>> it.yield_pin
	>> it.advance_pin;

      // Read this as a 2-byte value
      host_int_2 nc;
      i >> nc;
      it.num_clients = (host_int_1) nc;
      it.client_num_update();

      // set string<->pin mappings
      it.sched.clear_pin_mappings ();
      for (unsigned j=0; j<it.num_clients; j++)
	{
	  i >> it.clients[j]->time 
	    >> it.clients[j]->scale_mul
	    >> it.clients[j]->scale_div 
	    >> it.clients[j]->regular_p
	    >> it.clients[j]->priority;

	  it.sched.add_pin_mapping((make_numeric_attribute(j) + "-event"),
				   & it.clients[j]->event_pin);
	}

      i >> it.sched;

      int dummy;
      i >> dummy;
    }
  else
    {
      i.setstate(ios::badbit);	  
    }
  
  return i;
}


// This base class is used just to have a single place to cast
// component* to, for the deletion via virtual destructors.
class scheduler_component_base: public virtual component,
				protected fixed_pin_map_component,
				protected no_accessor_component,
				protected fixed_attribute_map_component,
				protected no_relation_component,
				protected no_bus_component,
				protected recursion_limited
{
public:
  scheduler_component_base():
    recursion_limited ("advancing", 1)
    {}
  ~scheduler_component_base() throw () {}
};



template <class Scheduler>
class scheduler_component: public scheduler_component_base
{
  Scheduler sched;
  typedef scheduler_component<Scheduler> this_t;
  typedef scheduler_client<this_t> client_t;
  friend class scheduler_client<this_t>;

  vector<client_t*> clients;  
  host_int_1 num_clients;
  int enable_threshold;
  int enable_p;
  int yield_host_time_threshold;
  int yield_host_time_p;
  host_int_8 advance_count;
  callback_pin<this_t> advance_pin;
  callback_pin<this_t> time_query_pin;
  callback_pin<this_t> yield_pin;
  output_pin time_low_pin;
  output_pin time_high_pin;
  output_pin active_pin;
  output_pin time_set_pin;

public:

private:
  friend ostream& operator << <> (ostream& o, const scheduler_component& it);
  friend istream& operator >> <> (istream& i, scheduler_component& it);

  string save_state() { return make_attribute(*this); }
  sid::component::status restore_state(const string& state)
    { return parse_attribute(state, *this); }

  string get_time()
    {
      tick_t now;
      this->sched.get_now (now);
      return make_numeric_attribute(now); 
    }
  sid::component::status set_time(const string& t)
    {
      tick_t then;
      component::status s = parse_attribute(t, then); 
      if (UNLIKELY(s != component::ok)) return s;
      this->sched.set_now (then - 1);
      tick_t now;
      this->sched.get_now (now);
      if (then - 1 != now)
	return component::bad_value;
      this->sched.cancel_all ();
      time_set_pin.drive (then);
      return component::ok;
    }

protected:

  // Callback for advance pin
  void 
  advance(host_int_4)
    {
      recursion_record limit (this);
      if (UNLIKELY(!limit.ok()))
	return;
#if 0
      cerr << "Scheduler:" << endl;
      cerr << "  enable_p==" << this->enable_p
	   << " enable_threshold==" << this->enable_threshold << endl;
#endif
      if (LIKELY(this->enable_p >= this->enable_threshold))
        {
#if 0
	  cerr << "  yield_host_time_p=="
	       << this->yield_host_time_p
	       << " yield_host_time_threshold=="
	       << this->yield_host_time_threshold << endl;
#endif
	  // Drive the active pin if the threshold has been crossed.
	  if (this->active_pin.recall() != 1)
	    this->active_pin.drive(1);

          this->advance_count ++;
  	  this->sched.advance (this->yield_host_time_p >= this->yield_host_time_threshold);
        }
      else
	{
	  // Drive the active pin if the threshold has been crossed.
	  if (this->active_pin.recall() != 0)
	    this->active_pin.drive(0);
	}
    }


  // Callback for time query pin
  void
  time_query(host_int_4)
    {
      tick_t now;
      this->sched.get_now (now);
      this->time_high_pin.drive ((now >> 32) & 0xFFFFFFFF);
      this->time_low_pin.drive (now & 0xFFFFFFFF);
    }


  // Callback for client_list attribute update: grow new client slots
  // or delete superfluous clients.  Leave alone existing clients.
  void client_num_update();

  // Request any pending generic_scheduler::advance() loop to exit prematurely
  void
  yield_step_loop(host_int_4)
    {
      this->sched.yield_step_loop_p = true;
    }

  // Factoring out constructor guts
  void scheduler_component_ctor_1();
  void scheduler_component_ctor_2();
  void scheduler_component_ctor_3();

public:
  scheduler_component():
    sched(),
    clients(0),
    num_clients(0),
    enable_threshold(1),
    enable_p(1),
    yield_host_time_threshold(1), 
    yield_host_time_p(0), 
    advance_count(0),
    advance_pin(this, & scheduler_component::advance),
    time_query_pin(this, & scheduler_component::time_query),
    yield_pin(this, & scheduler_component::yield_step_loop)
    {
      scheduler_component_ctor_1();
      scheduler_component_ctor_2();
      scheduler_component_ctor_3();
    }
  ~scheduler_component() throw () { }
};


template <class Scheduler>
void
scheduler_component<Scheduler>::scheduler_component_ctor_1()
{
  add_pin ("advance", & this->advance_pin);
  add_attribute ("advance", & this->advance_pin, "pin");
  add_pin ("time-query", & this->time_query_pin);
  add_pin ("time-high", & this->time_high_pin);
  add_pin ("time-low", & this->time_low_pin);
  add_pin ("yield", & this->yield_pin);
  add_pin ("active", & this->active_pin);
  add_pin ("time-set", & this->time_set_pin);
  add_attribute ("yield", & this->yield_pin, "pin");
  add_attribute ("enable-threshold", & this->enable_threshold, "setting");
  add_attribute ("enabled?", & this->enable_p, "setting");
  add_attribute ("yield-host-time-threshold", & this->yield_host_time_threshold, "setting");
  add_attribute ("yield-host-time?", & this->yield_host_time_p, "setting");
  add_attribute_ro_value ("scheduler-control-gui", string("sid-visual-sched"), "gui");
}

template <class Scheduler>
void
scheduler_component<Scheduler>::scheduler_component_ctor_2()
{
  add_attribute_notify ("num-clients", & this->num_clients, this,
			& scheduler_component::client_num_update);
  add_attribute ("step-cycle-limit", & this->sched.step_cycle_limit, "setting");
  add_attribute_virtual ("state-snapshot", this,
			 & scheduler_component::save_state,
			 & scheduler_component::restore_state);
  add_attribute_ro ("timekeeper-info", & this->sched.timer, "register");
}

template <class Scheduler>
void
scheduler_component<Scheduler>::scheduler_component_ctor_3()
{
  add_attribute_ro ("advance-count", & this->advance_count, "register");
  add_attribute_virtual ("time", this, 
			 & scheduler_component::get_time,
			 & scheduler_component::set_time,
			 "register");
}



// Callback for client_list attribute update: grow new client slots
// or delete superfluous clients.  Leave alone existing clients.
template <class Scheduler>
void
scheduler_component<Scheduler>::client_num_update ()
{
  unsigned last_size = this->clients.size();

  // Drop old entries (if any)
  // XXX: what about connected pins?
  for(unsigned n=this->num_clients; n < last_size; n++)
    {
      client_t* c = this->clients[n];

      string num = sidutil::make_numeric_attribute(n);
      this->remove_attribute (num + "-regular?");
      this->remove_attribute (num + "-time");
      this->remove_attribute (num + "-priority");
      this->remove_attribute (num + "-scale"); 
      this->remove_attribute (num + "-name");
      this->remove_attribute (num + "-event");
      this->remove_attribute (num + "-control");
      this->remove_pin (num + "-event");
      this->remove_pin (num + "-control");
      delete c;
      this->clients[n] = 0;
    }

  // Resize array
  this->clients.resize (this->num_clients);

  // Create new entries (if any)
  for(unsigned i=last_size; i < this->num_clients; i++)
    {
      client_t* c = new client_t(this);

      string num = sidutil::make_numeric_attribute (i);
      this->add_attribute_notify (num + "-regular?", 
				  & c->regular_p, c,
				  & client_t::reset_events,
				  "setting");
      this->add_attribute_notify (num + "-time", 
				  & c->time, c,
				  & client_t::reset_events, 
				  "setting");
      this->add_attribute_notify (num + "-priority", 
				  & c->priority, c,
				  & client_t::reset_events, 
				  "setting");
      this->add_attribute_virtual (num + "-scale", 
				   c, & client_t::get_scale_attr, & client_t::set_scale_attr,
				   "setting");
      this->add_attribute (num + "-name", & c->name, 
			   "setting");
      this->add_attribute (num + "-event", & c->event_pin,
			   "pin");
      this->add_attribute (num + "-control", & c->control_pin,
			   "pin");
      this->add_pin (num + "-event", & c->event_pin);
      this->add_pin (num + "-control", & c->control_pin);

      assert (this->clients[i] == 0);
      this->clients[i] = c;
    }

  assert(this->num_clients == this->clients.size());
}




// ----------------------------------------------------------------------------


  static
  vector<string>
  list_types()
{
  vector<string> types;
  types.push_back("sid-sched-host");
  types.push_back("sid-sched-host-accurate");
  types.push_back("sid-sched-sim");
  return types;
}
  
  
  static
  component*
  create(const string& typeName)
{
  if (typeName == "sid-sched-host")
    // Be accurate to 25 ms.
    return new scheduler_component< generic_scheduler<apprx_host_time_keeper<25> > >();
  else if (typeName == "sid-sched-host-accurate")
    return new scheduler_component< generic_scheduler<exact_host_time_keeper> >();
  else if (typeName == "sid-sched-sim")
    return new scheduler_component< generic_scheduler<target_time_keeper> >();
  return 0;
}


  static
  void
  do_delete(component* c)
{
  delete dynamic_cast<scheduler_component_base*>(c);
}

  
}


// static object in root namespace
DLLEXPORT extern const sid::component_library sched_component_library;

const sid::component_library sched_component_library =
{
  sid::COMPONENT_LIBRARY_MAGIC,
  & scheduler_component::list_types, 
  & scheduler_component::create,
  & scheduler_component::do_delete
};

