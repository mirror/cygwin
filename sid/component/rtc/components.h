// components.h - A simulation of the Dallas 1x42 time-keeping NVRAMs.
// -*- C++ -*-

// Copyright (C) 1999-2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef COMPONENTS_H

#include <sidcomp.h>
#include <sidso.h>
#include <sidbusutil.h>
#include <sidattrutil.h>
#include <sidcomputil.h>
#include <sidschedutil.h>
#include <sidbusutil.h>
#include <sidwatchutil.h>

#include <cassert>
#include <time.h>

using std::vector;
using std::string;
using std::ostream;
using std::istream;
using std::ios;
using std::endl;

using sid::component;
using sid::bus;
using sid::host_int_1;
using sid::host_int_4;
using sid::big_int_1;
using sid::big_int_4;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;

using sidutil::fixed_pin_map_component;
using sidutil::no_pin_component;
using sidutil::fixed_bus_map_component;
using sidutil::fixed_attribute_map_component;
using sidutil::no_accessor_component;
using sidutil::fixed_accessor_map_component;
using sidutil::no_relation_component;
using sidutil::scheduler_event_subscription;
using sidutil::byte_bus;
using sidutil::word_bus;
using sidutil::make_attribute;
using sidutil::parse_attribute;
using sidutil::callback_pin;
using sidutil::self_watcher;


class ds1642: public virtual component,
	      protected fixed_pin_map_component,
	      protected fixed_accessor_map_component,
	      protected no_relation_component,
	      protected fixed_bus_map_component,
	      protected fixed_attribute_map_component
{
public:
  ds1642();

protected:
  virtual bus::status read_7f8(host_int_4 addr, host_int_1& data);
  virtual bus::status write_7f8(host_int_1 data);

  // Holds values for the time and date during a programmed update.
  struct tm timeValues;

  unsigned get_year();
  void set_year(unsigned year);
  
  class ds1642_bus: public byte_bus
  {
  public:
    ds1642_bus(ds1642* target)
      :target(target) {}
            
  protected:
    status write_data(host_int_4 addr, host_int_1 data) throw();
    status read_data(host_int_4 addr, host_int_1& data) throw();
    ds1642* target;
  };

  time_t now;

  // An auxillary memory for this device's NVRAM.
  sid::bus* membus;

  // Set to `true' when updating the time and date.
  bool update_p;

  void start_clock()
    {
      update_p = true;
    }
  void stop_clock()
    {
      update_p = false;
    }

  // Refresh the internal time maintained by the component.
  // Set the packed time_t value from broken-down time structure.
  void refresh();

  // Decide if this broken-down time structure is valid. That is, will
  // mktime() produce a meaningful result? This is used for validating
  // new settings prior to "commiting" them.
  bool valid(struct tm& tm);
 
  friend class self_watcher<ds1642>;
  self_watcher<ds1642> triggerpoint_manager;

private:
  enum { memSize = 2048 };

  friend class ds1642_bus;
  ds1642_bus bus_1642;

  // This component requires a scheduler to make the 512Hz frequency
  // test feature of the RTC work.  The component requests a
  // notification every 2ms (host time) from the scheduler to flip the 
  // test bit.
  friend class scheduler_event_subscription<ds1642>;
  scheduler_event_subscription<ds1642> ticker;

  callback_pin<ds1642> clock_pin;
  void tick(host_int_4);

  unsigned get_seconds();
  void set_seconds(unsigned seconds);
  string get_seconds_attribute();
  sid::component::status set_seconds_attribute(const string& value);
  
  unsigned get_minutes();
  void set_minutes(unsigned seconds);
  string get_minutes_attribute();
  sid::component::status set_minutes_attribute(const string& value);

  unsigned get_hours();
  void set_hours(unsigned seconds);
  string get_hours_attribute();
  sid::component::status set_hours_attribute(const string& value);

  unsigned get_month();
  void set_month(unsigned month);
  string get_month_attribute();
  sid::component::status set_month_attribute(const string& value);

  unsigned get_date();
  void set_date(unsigned date);
  string get_date_attribute();
  sid::component::status set_date_attribute(const string& value);
  
  unsigned get_day();
  void set_day(unsigned day);
  string get_day_attribute();
  sid::component::status set_day_attribute(const string& value);

  string get_year_attribute();
  sid::component::status set_year_attribute(const string& value);

  // True when the oscillator is disconnected.
  bool disconnected_p;

  void disconnect_oscillator()
    {
      stop_clock();
      disconnected_p = true;
    }
  void connect_oscillator()
    {
      start_clock();
      disconnected_p = false;
    }
  bool oscillator_running_p()
    {
      return !disconnected_p;
    }

  void start_frequency_test();
  void stop_frequency_test();

  bool frequency_testing;
  const unsigned short frequency;

  // Toggle the least significant bit of the seconds register, even
  // when in read mode.
  void toggle_test_bit() { test_bit = ~test_bit; }
  unsigned int test_bit:1;

  string save_state();
  sid::component::status restore_state (const string& state);
  friend ostream& operator << (ostream& op, const ds1642& copy_obj);
  friend istream& operator >> (istream& ip, ds1642& ovwrite_obj); 

  // Triggerpoint support.

  sid::component::status
  pin_factory(const string& name)
    {
      return this->triggerpoint_manager.create_virtual_pin(name);
    }

  void
  pin_junkyard(const string& name)
    {
      return this->triggerpoint_manager.destroy_virtual_pin(name);
    }
};  

class ds1742: public ds1642
{
public:
  ds1742();

private:
  bus::status read_7f8(host_int_4 addr, host_int_1& data);
  bus::status write_7f8(host_int_1 data);

  unsigned get_century();
  void set_century(unsigned century);
  string get_century_attribute();
  sid::component::status set_century_attribute(const string& value);
};


// This is a fictional RTC for special use only
class sidrtc: public virtual component,
	      protected no_pin_component,
	      protected no_accessor_component,
	      protected no_relation_component,
	      protected fixed_bus_map_component,
	      protected fixed_attribute_map_component
{
  class mybus: public word_bus<big_int_4>
  {
    bus::status word_write (host_int_4 addr, big_int_4 mask, big_int_4 data);
    bus::status word_read (host_int_4 addr, big_int_4 mask, big_int_4& data);

  public:
    mybus () {}
  };
  friend class mybus;

  mybus rtcbus;

  string get_seconds_attribute();
  string get_minutes_attribute();
  string get_hours_attribute();

  sid::component::status set_no_attribute(const string& value) 
    { return sid::component::bad_value; }

public:
  sidrtc();
  ~sidrtc() {}
};


#endif // COMPONENTS_H
