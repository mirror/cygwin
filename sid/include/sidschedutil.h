// sidschedutil.h - Useful mix-in classes for interfacing to the
// generic scheduler components.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef H_SIDSCHEDUTIL_H
#define H_SIDSCHEDUTIL_H

#include <sidconfig.h>

#include <sidcomp.h>
#include <sidpinutil.h>

#include <string>
#include <vector>
#include <map>

namespace sidutil
{
  // The template <Master> class should be a kind of
  // fixed_pin_map_component so we can register the various
  // communication pins.
  
  template <class Master>
  class scheduler_event_subscription
  {
  public:
    scheduler_event_subscription(const std::string& name,
				 Master* c,
				 void (Master::*f)()):
      master (c),
      pmf (f),
      event_pin (this, & scheduler_event_subscription<Master>::event_handler)
      {
	// It's not important to remove these at destruction time.
	master->add_pin (name + "-control", & this->control_pin);
	master->add_pin (name + "-event", & this->event_pin);
      }
    
    void cancel() { this->control_pin.drive (0); }
    
    void schedule(bool regular_p, sid::host_int_4 time)
      {
	assert ((time & 0x80000000) == 0);
	assert ((time & 0x7FFFFFFF) != 0);
	sid::host_int_4 value = regular_p ? (0x80000000 | time) : (time);
	this->control_pin.drive(value);
      }
    
    void schedule_irregular(sid::host_int_4 time)
      {
	this->schedule(false, time);
      }
    
    void schedule_regular(sid::host_int_4 time)
      {
	this->schedule(true, time);
      }
    
  private:
    Master* master;
    void (Master::*pmf)();
    sidutil::output_pin control_pin;
    sidutil::callback_pin<sidutil::scheduler_event_subscription<Master> > event_pin;
    void event_handler (sid::host_int_4)
      {
	(master->*pmf) ();
      }
  };
  
  
  // The template <Master> class should be a kind of
  // fixed_pin_map_component so we can register the various
  // communication pins.

  template <class Master>
  class scheduler_time_query
  {
  public:
    // The constructor must specify the component to whom we belong.
    scheduler_time_query(Master* m)
      :master(m)
      {
	master->add_pin ("time-query", & this->query_pin);
	master->add_pin ("time-high", & this->result_high_pin);
	master->add_pin ("time-low", & this->result_low_pin);
      }
    
    // XXX: This could be a host_int_8 just as easily, but Cygwin g++
    // seems to have problems returning that type in some contexts.
    
    sid::host_int_8 now()
      {
	this->query_pin.drive (0);
	// We should receive a callback on both result_*_pins.
	sid::host_int_4 high = this->result_high_pin.sense();
	sid::host_int_4 low = this->result_low_pin.sense();
	sid::host_int_8 value = 
	  (((sid::host_int_8) high) << 32) | (sid::host_int_8) low;
	return value;
      }

  private:
    Master* master;
    sidutil::output_pin query_pin;
    sidutil::input_pin result_high_pin;
    sidutil::input_pin result_low_pin;
  };

} // namespace sidutil

#endif // SIDSCHEDUTIL_H
