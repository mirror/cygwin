// arm7t-timer.h- An implementation of the timers from the ARM PID7T
// development board.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.
// arm7t-timer.h

// A more thorough description of this component may be found at
// <http://www.arm.com/Documentation/UserMans/rps/#timer>

#ifndef _ARM7T_TIMER_H
#define _ARM7T_TIMER_H

#include <sidcomp.h>
#include <sidso.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidpinattrutil.h>
#include <sidbusutil.h>
#include <sidschedutil.h>
#include <sidtypes.h>
#include <sidwatchutil.h>

#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::cerr;
using std::endl;

using sid::component;
using sid::bus;
using sid::little_int_4;
using sid::host_int_2;
using sid::host_int_4;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_attribute_map_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_pin_map_component;
using sidutil::no_accessor_component;
using sidutil::no_relation_component;
using sidutil::callback_pin;
using sidutil::output_pin;
using sidutil::word_bus;
using sidutil::scheduler_event_subscription;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::self_watcher;

#include <vector>
#include <string>

class armTimer: public virtual component, 
		protected fixed_attribute_map_component,
		protected fixed_bus_map_component,
		protected fixed_pin_map_component,
		protected no_accessor_component,
		protected no_relation_component
{
public:
  armTimer();
  ~armTimer() throw () { }

private:
  class bus_interface: public word_bus<little_int_4>
  {
  public:
    bus_interface(armTimer *h): host(h) {}
    bus::status word_write(host_int_4 addr,
			   little_int_4 mask,
			   little_int_4 data);

    bus::status word_read(host_int_4 addr,
			  little_int_4 mask,
			  little_int_4& data);
  private:
    armTimer *host;
  };
  friend class bus_interface;
  friend class armTimerSched;

protected:
  virtual void tick();
  virtual void reset_schedule() {}

  host_int_2 counter;
  bool enabled;
  host_int_2 loadValue;

  enum timer_mode { periodic, free_running };
  timer_mode mode;
  friend istream& operator >> (istream&, timer_mode&);
  friend ostream& operator << (ostream&, const timer_mode&);

  host_int_2 prescale;
  output_pin interrupt_pin;
  bus_interface bus;

  callback_pin<armTimer> reset_pin;
  void reset_pin_handler (host_int_4) { this->reset(); }
  virtual void reset ();
  
  // State save and restore.
  std::string save_state();
  sid::component::status restore_state ( const string& state );
  friend ostream& operator << (ostream& op, const armTimer& copy_obj);
  friend istream& operator >> (istream& ip, armTimer& ovwrite_obj);
  
  // Triggerpoint manager
  friend class self_watcher<armTimer>;
  self_watcher<armTimer> triggerpoint_manager;
  
  sid::component::status
  pin_factory(const string& name)
    {
      return triggerpoint_manager.create_virtual_pin(name);
    }
  
  void
  pin_junkyard(const string& name)
    {
      return triggerpoint_manager.destroy_virtual_pin(name);
    }

  // These are made virtual so that derived classes may stream out
  // additional data.  Override these methods.

  virtual void stream(ostream& op) const;
  virtual void destream(istream& ip);
};


class armTimerNoSched: public armTimer
{
public:
  armTimerNoSched();

private:
  callback_pin<armTimerNoSched> clockpin;
  unsigned ticks; // does not get larger than 0 .. divider
  void tick(); // perform divisor calculations here
  void tick(host_int_4) { this->tick(); } // indirection for callback_pin
  void reset ();

  void stream(ostream& op) const;
  void destream(istream& ip);
};


class armTimerSched: public armTimer
{
public:
  armTimerSched();

private:
  friend class scheduler_event_subscription<armTimerSched>;
  scheduler_event_subscription<armTimerSched> ticker;

  void reset_schedule();
};

#endif // _ARM7T_TIMER_H

