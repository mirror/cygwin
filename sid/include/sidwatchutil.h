// sidwatchutil.cxx - Classes for implementing "triggerpoints", a.k.a.
// simulator state watchpoints.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDWATCHUTIL_H
#define SIDWATCHUTIL_H

#include <sidconfig.h>

#include <sidtypes.h>
#include <sidpinutil.h>
#include <sidattrutil.h>
#include <sidmiscutil.h>

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <cassert>

namespace sidutil
{
  class state_watchable_base
  {
  protected:
    int num_watchers;
    unsigned change_test_repeat;
    bool last_change_test_value;

  public:
    state_watchable_base(): 
      num_watchers(0), 
      change_test_repeat(0),
      last_change_test_value(false) {}
    virtual ~state_watchable_base () {}
   
    // These are reference counting functions
    void one_more_watcher ()
      { 
	this->num_watchers ++; 
	assert (this->num_watchers > 0);
	this->change_test_repeat = 0;
      }

    void one_less_watcher () 
      { 
	assert (this->num_watchers > 0);
	this->num_watchers --; 
	this->change_test_repeat = 0;
      }

    bool test_change ()
      {
	// Don't test for new changes if multiple watchers are still
	// in process of polling.
	if (this->change_test_repeat == 0)
	  {
	    this->last_change_test_value = this->test_change_value ();
	    this->change_test_repeat = this->num_watchers;
	  }

	this->change_test_repeat --;
	return this->last_change_test_value;
      }

    // These are the various types of triggerpoint criteria
    virtual bool test_change_value () = 0;
    virtual bool test_mask_value (sid::host_int_8 mask,
				  sid::host_int_8 value) = 0;
    virtual bool test_range (sid::host_int_8 low,
			     sid::host_int_8 high) = 0;
  };

  // This kind of watchable is a fast raw pointer to any value type of
  // object.  The usual C++ operators are used for assignment and
  // comparison.  The replica is deliberately uninitialized so the first
  // test_change is bound to succeed.
  template <typename Value>
  class state_watchable_value: public state_watchable_base
  {
  public:
    state_watchable_value (const Value* v): master(v), replica() {}
    
    bool test_change_value ()
      {
	bool changed = (this->replica != * this->master);
	if (changed)
	  {
	    this->replica = * this->master;
	    assert (this->replica == * this->master);
	  }
	return changed;
      }
    
    bool test_mask_value (sid::host_int_8 mask, sid::host_int_8 value)
      {
	bool changed = this->test_change();
	if (changed)
	  {
	    if ((this->replica & mask) == value)
	      return true;
	  }
	return false;
      }

    bool test_range (sid::host_int_8 low, sid::host_int_8 high)
      {
	bool changed = this->test_change();
	if (changed)
	  {
	    if (this->replica >= low && this->replica <= high)
	      return true;
	  }
	return false;
      }


  private:
    const Value* master;
    Value replica;
  };


  // This kind of watchable is a component attribute string.  For
  // mask/value test, it uses sidutil::parse_attribute to convert it
  // to host_int_8.  The replica is deliberately uninitialized so the first
  // test_change is bound to succeed.
  class state_watchable_attribute: public state_watchable_base
  {
  public:
    state_watchable_attribute(sid::component* o, const std::string& a): 
      owner(o), attribute(a), replica()
      {
	assert (this->owner != 0);
      }

    bool test_change_value ()
      {
	std::string master = this->owner->attribute_value (this->attribute);
	bool changed = (this->replica != master);

	if (changed)
	  {
	    this->replica = master;
	    assert (this->replica == master);
	  }
	return changed;
      }

    bool test_mask_value (sid::host_int_8 mask, sid::host_int_8 value)
      {
	bool changed = this->test_change();
	if (changed)
	  {
	    sid::host_int_8 as_number;
	    sid::component::status s =
	      sidutil::parse_attribute (this->replica, as_number);
	    if ((s == sid::component::ok) && ((as_number & mask) == value))
	      return true;
	  }
	return false;
      }

    bool test_range (sid::host_int_8 low, sid::host_int_8 high)
      {
	bool changed = this->test_change();
	if (changed)
	  {
	    sid::host_int_8 as_number;
	    sid::component::status s =
	      sidutil::parse_attribute (this->replica, as_number);
	    if ((s == sid::component::ok) && ((as_number >= low && as_number <= high)))
	      return true;
	  }
	return false;
      }


  private:
    sid::component* owner;
    std::string attribute;
    std::string replica;
  };


  class state_watcher_base
  {
  public:
    state_watcher_base (const std::string& n, state_watchable_base* p)
      :name(n), producer(p) 
      {
	assert (this->producer != 0);
	producer->one_more_watcher ();
      }
    virtual ~state_watcher_base () 
      {
	producer->one_less_watcher ();
      }
    virtual void check_and_inform () = 0;
    std::string get_name() { return this->name; }
    sidutil::output_pin* get_consumer_pin() { return & this->consumer;
    }
    
  protected:
    std::string name;
    sidutil::output_pin consumer;
    state_watchable_base* producer;
  };
  
  
  class state_watcher_change: public state_watcher_base
  {
  public:
    state_watcher_change (const std::string& n, state_watchable_base* p)
      :state_watcher_base (n, p) { }
    
    void check_and_inform()
      {
	if (this->producer->test_change())
	  this->consumer.drive (0);
      }
  };


  class state_watcher_mask_value: public state_watcher_base
  {
  public:
    state_watcher_mask_value (const std::string& n, state_watchable_base* p,
			      sid::host_int_8 m, sid::host_int_8 v)
      :state_watcher_base (n, p), mask(m), value(v) { }

    state_watcher_mask_value (const std::string& n, state_watchable_base* p, sid::host_int_8 v)
      :state_watcher_base (n, p), mask(~0ULL), value(v) { }

    void check_and_inform()
      {
	if (this->producer->test_mask_value (mask, value))
	  this->consumer.drive (0);
      }

  private:
    sid::host_int_8 mask;
    sid::host_int_8 value;
  };


  class state_watcher_range: public state_watcher_base
  {
  public:
    state_watcher_range (const std::string& n, state_watchable_base* p,
			      sid::host_int_8 l, sid::host_int_8 h)
      :state_watcher_base (n, p), low(l), high(h) { }

    void check_and_inform()
      {
	if (this->producer->test_range (low, high))
	  this->consumer.drive (0);
      }

  private:
    sid::host_int_8 low;
    sid::host_int_8 high;
  };


// Make an arbitrary watchable name string into an encoded form, if
// needed, for safe parsing in the "watch:NAME:..." pin name.  This
// needs to be a simple mapping (since triggerpoint clients need to
// perform this mapping also), and produce a unique string with only
// safe characters.  The reverse mapping is not actually needed.
//
// The algorithm is simply to URL-encode ("%xx" with xx hex digits)
// each character not in [a-zA-Z0-9_].
//
  inline std::string
  map_watchable_name (const std::string& name)
    {
      std::string out;
      for (unsigned i = 0; i < name.length(); i++)
	{
	  char c = name[i];
	  if ((c >= 'a' && c <= 'z') ||
	      (c >= 'A' && c <= 'Z') ||
	      (c >= '0' && c <= '9') ||
	      (c == '_'))
	    {
	      out += c;
	    }
	  else
	    {
	      char hex[] = "0123456789ABCDEF";
	      out += '%';
	      out += hex[(c >> 4) & 0x0f];
	      out += hex[c & 0x0f];
	    }
	}
      return out;
    }
  

  template <class Component>
  class self_watcher
  {

  public:
    self_watcher(Component* c): 
      component(c), watchables(), 
      watchers(), watching_any_p(false), checking_now_p(false)
      {
	assert (component != 0);
      }

    ~self_watcher();

    // Register watchable state
    template <typename Value>
    void add_watchable_value(const std::string& name, Value* v);
    void add_watchable_attribute(const std::string& name);

    // XXX: How to unregister?

    // Callbacks for virtual pin handling
    sid::component::status create_virtual_pin(const std::string& name);
    void destroy_virtual_pin(const std::string& name);


    bool checking_any_p ()
      {
	return this->watching_any_p;
      }

    void check_and_dispatch () 
      {
	// assert invariant
	assert (this->watching_any_p == (this->watchers.size() != 0));

	if (! this->watching_any_p)
	  return;
	
	// jump to out-of-line function
	this->check_and_dispatch2();
      }
    
  private:
    // target component
    Component* component;

    // watchable state, by name
    typedef std::map<std::string,state_watchable_base*> watchables_t;
    watchables_t watchables;

    // active watch requests
    typedef std::vector<state_watcher_base*> watchers_t;
    watchers_t watchers;
    bool watching_any_p; // cached invariant: ``watchers.size() != 0''
    bool checking_now_p; // check in progress (recursion protection)

    // out-of-line worker function
    void check_and_dispatch2 ();
  };


  template <class Component>
  self_watcher<Component>::~self_watcher ()
    {
      // drop the watchers
      for (unsigned i=0; i < this->watchers.size(); i++)
	{
	  state_watcher_base* watcher = this->watchers[i];
	  std::string n = watcher->get_name();
	  this->component->remove_pin (n);
	  delete watcher;
	}
      
      // drop the watchables
      for (watchables_t::iterator it = this->watchables.begin();
	   it != this->watchables.end();
	   it ++)
	{
	  state_watchable_base* watchable = it->second;
	  delete watchable;
	}
    }
  
  
  // Register a piece of component state.  Register appropriate
  // virtual pins to the component to make these watchable.
  template <class Component>
  template <typename Value>
  void self_watcher<Component>::add_watchable_value (const std::string& name, Value* v)
    {
      state_watchable_base* w = new state_watchable_value<Value> (v);
      std::string mapped_name = map_watchable_name (name);
      this->watchables[mapped_name] = w;
    }

  template <class Component>
  void self_watcher<Component>::add_watchable_attribute (const std::string& name)
{
  state_watchable_base* w = new state_watchable_attribute (this->component, name);
  std::string mapped_name = map_watchable_name (name);
  this->watchables[mapped_name] = w;
}
  

  
  // Parse a new state watch request.  Create appropriate watcher.
  // Accepted virtual pin names are of these forms:
  //
  // watch:WATCHABLE:change
  // watch:WATCHABLE:mask/value:MASK:VALUE
  // watch:WATCHABLE:value:VALUE
  // watch:WATCHABLE:range:MINVALUE:MAXVALUE
  //
  // where WATCHABLE matches some existing watchable state,
  //       MASK, *VALUE are specified in host_int_8 parseable format
  //
  template <class Component>
  sid::component::status 
  self_watcher<Component>::create_virtual_pin(const std::string& name)
    {
      std::vector<std::string> tokens = sidutil::tokenize (name, ":");
      
      // look for "watch" keyword
      if ((tokens.size() < 1) || (tokens[0] != "watch"))
	return sid::component::not_found;
      
      // look up watchable
      if (tokens.size() < 2)
	return sid::component::bad_value;
      std::string watchable_name = tokens[1];
      state_watchable_base* watch_me = this->watchables[watchable_name];
      if (watch_me == 0)
	return sid::component::not_found;
      
      // look up watching criteria
      if ((tokens.size() == 3) && (tokens[2] == "change"))
	{
	  state_watcher_base* watcher = new state_watcher_change (name, watch_me);
	  this->watchers.push_back (watcher);
	  this->watching_any_p = true;
	  // fulfill requirements of virtual pin handler
	  this->component->add_pin (name, watcher->get_consumer_pin());
	  return sid::component::ok;
	}
      else if ((tokens.size() == 4) && (tokens[2] == "value"))
	{
	  std::string watch_value = tokens[3];
	  
	  // parse value
	  sid::host_int_8 value;
	  sid::component::status s = sidutil::parse_attribute (watch_value, value);
	  if (s != sid::component::ok) return s;
	  
	  state_watcher_base* watcher = new state_watcher_mask_value (name, watch_me, value);
	  this->watchers.push_back (watcher);
	  this->watching_any_p = true;
	  // fulfill requirements of virtual pin handler
	  this->component->add_pin (name, watcher->get_consumer_pin());
	  return sid::component::ok;
	}
      else if ((tokens.size() == 5) && (tokens[2] == "mask/value"))
	{
	  std::string watch_mask = tokens[3];
	  std::string watch_value = tokens[4];
	  
	  // parse mask/value
	  sid::host_int_8 mask, value;
	  sid::component::status s1 = sidutil::parse_attribute (watch_mask, mask);
	  sid::component::status s2 = sidutil::parse_attribute (watch_value, value);
	  if (s1 != sid::component::ok) return s1;
	  if (s2 != sid::component::ok) return s2;
	  
	  state_watcher_base* watcher = new state_watcher_mask_value (name, watch_me, mask, value);
	  this->watchers.push_back (watcher);
	  this->watching_any_p = true;
	  // fulfill requirements of virtual pin handler
	  this->component->add_pin (name, watcher->get_consumer_pin());
	  return sid::component::ok;
	}
      else if ((tokens.size() == 5) && (tokens[2] == "range"))
	{
	  std::string watch_low = tokens[3];
	  std::string watch_high = tokens[4];
	  
	  // parse mask/value
	  sid::host_int_8 low, high;
	  sid::component::status s1 = sidutil::parse_attribute (watch_low, low);
	  sid::component::status s2 = sidutil::parse_attribute (watch_high, high);
	  if (s1 != sid::component::ok) return s1;
	  if (s2 != sid::component::ok) return s2;
	  
	  state_watcher_base* watcher = new state_watcher_range (name, watch_me, low, high);
	  this->watchers.push_back (watcher);
	  this->watching_any_p = true;
	  // fulfill requirements of virtual pin handler
	  this->component->add_pin (name, watcher->get_consumer_pin());
	  return sid::component::ok;
	}
      else
	return sid::component::bad_value;
    }
  
  
  // Look for and destroy a watcher that has become obsolete.
  template <class Component>
  void
  self_watcher<Component>::destroy_virtual_pin(const std::string& name)
    {
      for (watchers_t::iterator it = this->watchers.begin();
	   it != this->watchers.end();
	   it++)
	{
	  state_watcher_base* w = *it;
	  if (w->get_name() == name) // found it!
	    {
	      // fulfill requirements of virtual pin junkyard
	      this->component->remove_pin (name);
	      this->watchers.erase (it);
	      delete w;
	      // XXX: assert that no more duplicate watchers exist?
	      break; // iteration invalid
	    }
	}
      
      // recalculate cached invariant
      this->watching_any_p = (this->watchers.size() != 0);
    }
  
  template <class Component>
  void self_watcher<Component>::check_and_dispatch2()
    {
      // In case of recursion, exit here
      if (this->checking_now_p)
	return;
      
      this->checking_now_p = true;
      for (unsigned i=0; i<this->watchers.size(); i++)
	{
	  state_watcher_base* w = this->watchers[i];
	  assert (w);
	  w->check_and_inform();
	}
      this->checking_now_p = false;
    }
}

#endif // SIDWATCHUTIL_H
