// sid-pit-wrapper.h - SID import of the bochs pit component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_PIT_WRAPPER_DEF_H
#define SID_PIT_WRAPPER_DEF_H	1

#include <sidtypes.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidattrutil.h>
#include <sidcpuutil.h>
#include <sidpinattrutil.h>
#include <sidmiscutil.h>
#include <sidwatchutil.h>
#include <sidso.h>

#include "bochs.h"

using sid::component;
using sid::bus;
using sid::host_int_4;
using sid::little_int_1;
using sidutil::callback_word_bus;
using sidutil::callback_pin;
using sidutil::output_pin;

class pit : public sidutil::fixed_pin_map_component,
            public sidutil::no_accessor_component,
            public sidutil::fixed_attribute_map_component,
            public sidutil::no_relation_component,
            public sidutil::fixed_bus_map_component
{
public:
  pit();
  ~pit() throw() {};

  void init(host_int_4);
  void update_pit(host_int_4);
  
protected:

  output_pin interrupt_pin;

  callback_pin<pit> init_pin;
  callback_pin<pit> update_pit_pin;

  bus::status read_port_0x40_0x43 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x40_0x43 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0x61 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x61 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<pit, little_int_1> ports_0x40_0x43_bus;
  callback_word_bus<pit, little_int_1> port_0x61_bus;

  host_int_4 timer_delta;
  bx_pit_c bx_pit;
};
#endif // SID_PIT_WRAPPER_DEF_H
