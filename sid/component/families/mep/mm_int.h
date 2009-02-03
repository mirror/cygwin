// mm_int.h - The Toshiba MeP interrupt arbitrator.
// -*- C++ -*-

// Copyright (C) 2002, 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MM_INT_H
#define MM_INT_H

#include <sidcomp.h>
#include <sidbusutil.h>
#include <sidpinutil.h>

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;

class mep_mm_int: public virtual component,
		protected no_attribute_component,
		protected fixed_bus_map_component,
		protected fixed_pin_map_component,
		protected no_accessor_component,
		protected no_relation_component
{
public:
  mep_mm_int ();

  void drive_pin (unsigned modnum, unsigned channel);
  
private:
  // A bus for accessing the mm_int registers.  To the outside world
  // These look like 32 bit, 4 byte aligned registers.
  class mm_int_interface: public word_bus<big_int_4>
  { 
  public:
    mm_int_interface (mep_mm_int *h) : host (h) {}
    bus::status word_write(host_int_4 addr,
			   big_int_4 mask,
			   big_int_4 data);

    bus::status word_read(host_int_4 addr,
			  big_int_4 mask,
			  big_int_4& data);
  private:
    mep_mm_int *host;
  };
  friend class mm_int_interface;

  // parameters
  static const int max_modules = 1;
  static const int max_channels = 0x100 / 4;
  // Control bus.
  mm_int_interface ctrl_bus; 

  // Output pins
  output_pin exception_pin[max_modules][max_channels];
};

#endif // MM_INT_H
