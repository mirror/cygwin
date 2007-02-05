// intc.cxx - An implementation of the interrupt arbitrator for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// A more thorough description of this component may be found in the
// External Specification of the MPI Integrator.

#include "components.h"
#include "mm_int.h"

mep_mm_int::mep_mm_int () :
  ctrl_bus (this)
{
  // The control bus
  add_bus ("access-port", &ctrl_bus);

  // Add pins for each possible channel of each module.
  for (int module = 0; module < max_modules; ++module)
    for (int channel = 0; channel < max_channels; ++ channel)
      this->add_pin ("interrupt-"
		     + sidutil::make_attribute (module) + "-"
		     + sidutil::make_attribute (channel),
		     & this->exception_pin[module][channel]);
}

void
mep_mm_int::drive_pin (unsigned modnum, unsigned channel)
{
  exception_pin[modnum][channel].drive (1);
}

bus::status
mep_mm_int::mm_int_interface::word_write(host_int_4 addr,
					 big_int_4 mask,
					 big_int_4 be_data)
{
  // The address space is divided into 0x100 bytes per media module and
  // 4 bytes for each interrupt channel in each module.
  host_int_4 byte_addr = addr * 4;

  unsigned module = byte_addr / 0x100;
  if (module >= max_modules)
    return bus::unmapped;

  unsigned channel = byte_addr % 0x100 / 4;
  if (channel >= max_channels)
    return bus::unmapped;

  // Now drive the appropriate output pin to generate the interrupt
  host->drive_pin (module, channel);
  return bus::ok;
}

bus::status
mep_mm_int::mm_int_interface::word_read(host_int_4 addr,
					big_int_4 mask,
					big_int_4& data)
{
  return bus::ok;
}
