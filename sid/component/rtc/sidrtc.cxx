// sidrtc.cxx - A simple real-time clock component.  -*- C++ -*-

// Copyright (C) 1999-2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"

#include <sys/time.h>
#include <time.h>

sidrtc::sidrtc ()
{
  add_bus ("registers", & this->rtcbus);

  add_attribute_ro_value ("tk xclock clone", string("hw-visual-clock"), "gui");

  add_attribute_virtual("hour", this,
			&sidrtc::get_hours_attribute,
			&sidrtc::set_no_attribute,
			"register");
  add_attribute_virtual("minute", this,
			&sidrtc::get_minutes_attribute,
			&sidrtc::set_no_attribute,
			"register");
  add_attribute_virtual("second", this,
			&sidrtc::get_seconds_attribute,
			&sidrtc::set_no_attribute,
			"register");
}


// A couple of functions, just for use by tksm/hw-visual-clock
string
sidrtc::get_hours_attribute ()
{
  time_t now = time (0);
  struct tm *t = gmtime (& now);
  return t ? make_attribute (t->tm_hour) : "12";  // just like on a VCR :-)
}

string
sidrtc::get_minutes_attribute ()
{
  time_t now = time (0);
  struct tm *t = gmtime (& now);
  return t ? make_attribute (t->tm_min) : "0";
}

string
sidrtc::get_seconds_attribute ()
{
  time_t now = time (0);
  struct tm *t = gmtime (& now);
  return t ? make_attribute (t->tm_sec) : "0";
}


bus::status
sidrtc::mybus::word_write (host_int_4 addr, big_int_4 mask, big_int_4 data)
{ 
  return bus::unpermitted; 
}


bus::status
sidrtc::mybus::word_read (host_int_4 addr, big_int_4 mask, big_int_4& data)
{ 
  struct timeval tnow;
  gettimeofday (& tnow, NULL);

  if (addr == 0)
    {
      data = tnow.tv_sec;
      return bus::ok;
    }
  else if (addr == 1)
    {
      data = tnow.tv_usec * 1000;
      return bus::ok;
    }
  else
    return bus::unmapped;
}
