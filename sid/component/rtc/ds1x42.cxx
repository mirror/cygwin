// ds1x42.cxx - A simulation of the Dallas DS1x42 time-keeping NVRAMs.
// -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"

static struct tm dummy;

// Placate the C++ compiler with a known type to pass into bus
// read/write // methods.  Of course, big_int_1 == host_int_1 anyway.
static big_int_1 temp;

// Convert 2-digit BCD numbers (8 bits) to 8-bit binary numbers.
static unsigned bcd_to_bin(host_int_1 bcd);

// And vice-versa.
static host_int_1 bin_to_bcd(unsigned short bin);

bus::status
ds1642::ds1642_bus::write_data(host_int_4 address,
			       host_int_1 data) throw()
{
  bus::status st;

  if ((!target->membus) || (address >= target->memSize))
    return unmapped;

  switch (address)
    {
    case 0x7FF:
      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data);
	  target->set_year_attribute(make_attribute(value));
	}
      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7FE:
      // Some precious bits of NVRAM we can use!
      temp = data & 0xE0;
      st = target->membus->write(address, temp);
      if (st != ok)
	return st;

      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data & 0x1F);
	  target->set_month_attribute(make_attribute(value));
	}

      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7FD:
      // Some precious bits of NVRAM we can use!
      temp = data & 0xC0;
      st = target->membus->write(address, temp);
      if (st != ok)
	return st;

      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data & 0x3F);
	  target->set_date_attribute(make_attribute(value));
	}

      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7FC:
      // Some precious bits of NVRAM we can use!
      temp = data & 0x38;
      st = target->membus->write(address, temp);
      if (st != ok)
	return st;

      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data & 0x07);
	  target->set_day_attribute(make_attribute(value));
	}

      if ((data & 0x40) == 0)
	{
	  target->stop_frequency_test();
	}
      if (target->disconnected_p && (data & 0x40))
	{
	  target->start_frequency_test();
	}

      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7FB:
      // Some precious bits of NVRAM we can use!
      temp = data & 0xC0;
      st = target->membus->write(address, temp);
      if (st != ok)
	return st;

      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data & 0x3F);
	  target->set_hours_attribute(make_attribute(value));
	}

      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7FA:
      // Some precious bits of NVRAM we can use!
      temp = data & 0x80;
      st = target->membus->write(address, temp);
      if (st != ok)
	return st;

      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data & 0x7F);
	  target->set_minutes_attribute(make_attribute(value));
	}

      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7F9:
      if (target->disconnected_p && !(data & 0x80))
	{
	  target->connect_oscillator();
	  return ok;
	}

      if (!target->update_p)
	{
	  unsigned value = bcd_to_bin(data & 0x7F);
	  target->set_seconds_attribute(make_attribute(value));
	}
      else if (data & 0x80)
	{
	  target->stop_clock();
	  target->disconnect_oscillator();
	}

      target->triggerpoint_manager.check_and_dispatch();
      return ok;

    case 0x7F8:
      return target->write_7f8(data);
      
    default:
      // Any of the remaining 2K NVRAM can be written to.
      temp = data;
      return target->membus->write(address, temp);
    }
}

bus::status
ds1642::ds1642_bus::read_data(host_int_4 address, 
			      host_int_1& data) throw()
{
  bus::status st;

  if (!target->membus)
    return unpermitted;

  if (address >= target->memSize)
    return unmapped;

  switch (address)
    {
    case 0x7FF:
      data = bin_to_bcd(target->get_year());
      return ok;

    case 0x7FE:
      st = target->membus->read(address, temp);
      if (st != ok)
	return st;
      
      data = (temp & 0xE0) | bin_to_bcd(target->get_month());
      return ok;
	
    case 0x7FD:
      st = target->membus->read(address, temp);
      if (st != ok)
	return st;
      data = (temp & 0xC0) | bin_to_bcd(target->get_date());
      return ok;

    case 0x7FC:
      st = target->membus->read(address, temp);
      if (st != ok)
	return st;
      data = (1 << 7) | (temp & 0x38) | bin_to_bcd(target->get_day());
      return ok;
      
    case 0x7FB:
      st = target->membus->read(address, temp);
      if (st != ok)
	return st;
      data = (temp & 0xC0) | bin_to_bcd(target->get_hours());
      return ok;
      
    case 0x7FA:
      st = target->membus->read(address, temp);
      if (st != ok)
	return st;
      data = (temp & 0x80) | bin_to_bcd(target->get_minutes());
      return ok;
      
    case 0x7F9:
      data = bin_to_bcd(target->get_seconds());
      if (target->frequency_testing && target->oscillator_running_p())
	{
	  data = data | target->test_bit;
	}
      return ok;

    case 0x7F8:
      return target->read_7f8(address, data);
          
    default:
      {
	big_int_1 big_data;
	st = target->membus->read(address, big_data);
	data = big_data;
	return st;
      }
    }
}

ds1642::ds1642()
  :update_p(true), bus_1642(this),
   ticker("clock", this, &ds1642::toggle_test_bit),
   clock_pin(this, & ds1642::tick),
   disconnected_p(false), frequency_testing(false), frequency(512),
   test_bit(0), triggerpoint_manager(this),
   membus(0)
{
  now = ::time(NULL);
  assert(now != -1);
  memcpy(&timeValues, gmtime(&now), sizeof(struct tm));

  add_pin("clock", &clock_pin);
  add_accessor("memory-bus", &membus);
  add_bus("read-write-port", &bus_1642);
  add_attribute_ro("epoch-time", &now);

  // register friend gui
  add_attribute_ro_value ("tk xclock clone", string("hw-visual-clock"), "gui");

  add_attribute_virtual("year", this,
			&ds1642::get_year_attribute,
			&ds1642::set_year_attribute,
			"register");
  add_attribute_virtual("month", this,
			&ds1642::get_month_attribute,
			&ds1642::set_month_attribute,
			"register");
  add_attribute_virtual("date", this,
			&ds1642::get_date_attribute,
			&ds1642::set_date_attribute,
			"register");
  add_attribute_virtual("day-of-week", this,
			&ds1642::get_day_attribute,
			&ds1642::set_day_attribute,
			"register");
  add_attribute_virtual("hour", this,
			&ds1642::get_hours_attribute,
			&ds1642::set_hours_attribute,
			"register");
  add_attribute_virtual("minute", this,
			&ds1642::get_minutes_attribute,
			&ds1642::set_minutes_attribute,
			"register");
  add_attribute_virtual("second", this,
			&ds1642::get_seconds_attribute,
			&ds1642::set_seconds_attribute,
			"register");

  add_attribute_virtual ("state-snapshot", this,
			 & ds1642::save_state,
			 & ds1642::restore_state);

  triggerpoint_manager.add_watchable_value("epoch-time", &now);
  triggerpoint_manager.add_watchable_value("oscillating", &disconnected_p);
  triggerpoint_manager.add_watchable_value("write-mode", &update_p);
}

void
ds1642::refresh()
{
  string localtz("TZ=");
  char* p = getenv("TZ");
  if (p)
    localtz += p;

  // Switch the local time zone to GMT so that mktime()
  // works as we expect.  A bit nasty!

  putenv("TZ=GMT");
  now = mktime(&timeValues);
  putenv(const_cast<char *>(localtz.c_str()));
}

bool
ds1642::valid(struct tm& tm)
{
  return (mktime(&tm) != -1);
}

bus::status
ds1642::read_7f8(host_int_4 address, host_int_1& data)
{
  data = 0;
  return bus::ok;
}

bus::status
ds1642::write_7f8(host_int_1 data)
{
  bus::status st;

  // Some precious bits of NVRAM we can use!
  temp = data & 0x3F;
  st = membus->write(0x7F8, temp);
  if (st != sid::bus::ok)
    return st;

  if (update_p)
    {
      // Enter read or write mode?
      if (data & 0xC0)
	{
	  stop_clock();
	}
    }
  else {
    // Finished in either read or write mode.  Return to
    // normal operation.
    if (!(data & 0xC0))
      {
	// Write bit is cleared. Re-compute `now'.
	refresh();
	start_clock();
      }
  }

  // Trigger checkpoint.
  triggerpoint_manager.check_and_dispatch();

  return bus::ok;
}

void
ds1642::tick(host_int_4)
{
  if (update_p)
    {
      now++;
      memcpy(&timeValues, gmtime(&now), sizeof(struct tm));

      // Trigger checkpoint.
      triggerpoint_manager.check_and_dispatch();
    }
}

sid::component::status
ds1642::set_seconds_attribute(const string& value)
{
  long seconds = strtol(value.c_str(), NULL, 0);
  if (seconds < 0 || seconds > 59)
    return sid::component::bad_value;

  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_sec = seconds;
  if (valid(dummy))
    {
      set_seconds(seconds);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}

string
ds1642::get_seconds_attribute()
{
  return make_attribute(get_seconds());
}

void
ds1642::set_seconds(unsigned seconds)
{
  timeValues.tm_sec = seconds;
  refresh();
}

unsigned
ds1642::get_seconds()
{
  // Handle leap seconds by stalling until the seconds value falls
  // between 0 and 59, as bus clients will expect.
  return (timeValues.tm_sec > 59) ? 59 : timeValues.tm_sec;
}

sid::component::status
ds1642::set_minutes_attribute(const string& value)
{
  long minutes = strtol(value.c_str(), NULL, 0);
  if (minutes < 0 || minutes > 59)
    return sid::component::bad_value;

  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_min = minutes;
  if (valid(dummy))
    {
      set_minutes(minutes);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}


string
ds1642::get_minutes_attribute()
{
  return make_attribute(get_minutes());
}

void
ds1642::set_minutes(unsigned minutes)
{
  timeValues.tm_min = minutes;
  refresh();
}

unsigned
ds1642::get_minutes()
{
  return timeValues.tm_min;
}

sid::component::status
ds1642::set_hours_attribute(const string& value)
{
  long hours = strtol(value.c_str(), NULL, 0);
  if (hours < 0 || hours > 23)
    return sid::component::bad_value;

  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_hour = hours;
  if (valid(dummy))
    {
      set_hours(hours);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}


string
ds1642::get_hours_attribute()
{
  return make_attribute(get_hours());
}


void
ds1642::set_hours(unsigned hours)
{
  timeValues.tm_hour = hours;
  refresh();
}

unsigned
ds1642::get_hours()
{
  return timeValues.tm_hour;
}

sid::component::status
ds1642::set_date_attribute(const string& value)
{
  long date = strtol(value.c_str(), NULL, 0);

  if (date < 1 || date > 31)
    return sid::component::bad_value;

  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_mday = date;
  if (valid(dummy))
    {
      set_date(date);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}

string
ds1642::get_date_attribute()
{
  return make_attribute(get_date());
}

void
ds1642::set_date(unsigned date)
{
  timeValues.tm_mday = date;
  refresh(); 
}

unsigned
ds1642::get_date()
{
  return timeValues.tm_mday;
}

sid::component::status
ds1642::set_day_attribute(const string& value)
{
  long day = strtol(value.c_str(), NULL, 0);

  if (day < 1 || day > 7)
    return sid::component::bad_value;
  
  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_wday = day;
  if (valid(dummy))
    {
      set_day(day);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}

string
ds1642::get_day_attribute()
{
  return make_attribute(get_day());
}

void
ds1642::set_day(unsigned day)
{
  timeValues.tm_wday = day - 1;
  refresh();
}

unsigned
ds1642::get_day()
{
  return timeValues.tm_wday + 1;
}

sid::component::status
ds1642::set_month_attribute(const string& value)
{
  long month = strtol(value.c_str(), NULL, 0);
  if (month < 1 || month > 12)
    return sid::component::bad_value;
  
  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_mon = month;
  if (valid(dummy))
    {
      set_month(month);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}

string
ds1642::get_month_attribute()
{
  return make_attribute(get_month());
}


void
ds1642::set_month(unsigned month)
{
  timeValues.tm_mon = month - 1;
  refresh();
}

unsigned
ds1642::get_month()
{
  return timeValues.tm_mon + 1;
}

sid::component::status
ds1642::set_year_attribute(const string& value)
{
  long year = strtol(value.c_str(), NULL, 0);

  if (year < 0 || year > 99)
    return sid::component::bad_value;
  
  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_year = dummy.tm_year - (dummy.tm_year % 100) + year;
  if (valid(dummy))
    {
      set_year(year);
      return sid::component::ok;
    }
  return sid::component::bad_value;
}

string
ds1642::get_year_attribute()
{ 
  return make_attribute(get_year());
}

void
ds1642::set_year(unsigned year)
{
  timeValues.tm_year = timeValues.tm_year - (timeValues.tm_year % 100) + year;
  refresh();
}

unsigned
ds1642::get_year()
{
  return timeValues.tm_year % 100;
}

void
ds1642::start_frequency_test()
{
  frequency_testing = true;
  // Cancel any pending scheduling registration.
  ticker.cancel();

  // FIXME: compute the period for `frequency'.
  ticker.schedule_regular(2);
}

void
ds1642::stop_frequency_test()
{
  frequency_testing = false;
  ticker.cancel();
}

static unsigned
bcd_to_bin(host_int_1 bcd)
{
  return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

static host_int_1
bin_to_bcd(unsigned short bin)
{
  assert(bin < 100);

  unsigned tens = bin / 10;
  unsigned ones = bin % 10;

  return ((tens << 4) | ones);
}


string 
ds1642::save_state()
{
  return make_attribute(*this);
}


sid::component::status
ds1642::restore_state(const string& state)
{
  return parse_attribute (state, *this);
}


ostream&
operator << (ostream& op, const ds1642& obj)
{
  op << "epoch-time " << obj.now << ":";
  op << "frequency-test " << obj.frequency_testing << ":";
  op << "update-mode " << obj.update_p;

  return op;
}


istream&
operator >> (istream& ip, ds1642& obj)
{
  char sep;
  string key;

  ip >> key;
  if (key != "epoch-time")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> obj.now;

  ip.get (sep);
  if (sep !=  ':')
    {
      ip.setstate(ios::badbit);
      return ip;
    }

  ip >> key;
  if (key != "frequency-test")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> obj.frequency_testing;

  ip.get(sep);
  if (sep != ':')
    {
      ip.setstate(ios::badbit);
      return ip;
    }

  ip >> key;
  if (key != "update-mode")
    {
      ip.setstate(ios::badbit);
      return ip;
    }
  ip >> obj.update_p;

  // Our idea of "now" has changed; recompute the individual time
  // elements.

  memcpy(&obj.timeValues,
	 gmtime(&obj.now),
	 sizeof(struct tm));

  return ip;
}


ds1742::ds1742()
{
  add_attribute_virtual("century", this,
			&ds1742::get_century_attribute,
			&ds1742::set_century_attribute,
			"register");
}

bus::status
ds1742::write_7f8(host_int_1 data)
{
  if (update_p)
    {
      // Enter read or write mode?
      if (data & 0xC0)
	{
	  stop_clock();
	}
    }
  else {
    // Finished in either read or write mode.
    if (!(data & 0xC0))
      {
	// Write bit is cleared. Re-compute `now'.
	refresh();
	start_clock();
      }
    else
      {
	// Write bit is still set--modify the century register.
	unsigned value = bcd_to_bin(data & 0x3F);
	set_century_attribute(make_attribute(value));
      }
  }

  // Trigger checkpoint.
  ds1642::triggerpoint_manager.check_and_dispatch();

  return bus::ok;
}

bus::status
ds1742::read_7f8(host_int_4 address, host_int_1& data)
{
  data = bin_to_bcd(get_century());
  return bus::ok;
}

string
ds1742::get_century_attribute()
{
  return make_attribute(get_century());
}

sid::component::status
ds1742::set_century_attribute(const string& value)
{
  long century = strtol(value.c_str(), NULL, 0);
  if (century < 19 || century >= 25)
    return sid::component::bad_value;
  
  memcpy(&dummy, &timeValues, sizeof(struct tm));
  dummy.tm_year = ((century - 19) * 100) + (dummy.tm_year % 100);
  
  if (valid(dummy))
    {
      set_century(century);
      return sid::component::ok;
    }
  else
    return sid::component::bad_value;
}

void
ds1742::set_century(unsigned century)
{
  unsigned year = timeValues.tm_year % 100;
  timeValues.tm_year = ((century - 19) * 100) + year;
  refresh();
}

unsigned
ds1742::get_century()
{
  return 19 + (timeValues.tm_year / 100);
}
