// sidrtc.cxx - A simple real-time clock component.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"

#include <sys/time.h>

sidrtc::sidrtc ()
{
  add_bus ("registers", & this->rtcbus);
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
