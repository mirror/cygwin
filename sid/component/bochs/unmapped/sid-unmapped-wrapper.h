// sid-unmapped-wrapper.h - SID import of the bochs unmapped component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_UNMAPPED_WRAPPER_DEF_H
#define SID_UNMAPPED_WRAPPER_DEF_H	1

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
using sid::little_int_4;
using sidutil::callback_word_bus;
using sidutil::callback_pin;
using sidutil::output_pin;

class unmapped : public sidutil::fixed_pin_map_component,
            public sidutil::no_accessor_component,
            public sidutil::fixed_attribute_map_component,
            public sidutil::no_relation_component,
            public sidutil::fixed_bus_map_component
{
public:
  unmapped();
  ~unmapped() throw() {};

protected:

  bus::status read_port_0xfff0 (host_int_4 addr, little_int_4 mask, little_int_4 & data);
  bus::status write_port_0xfff0 (host_int_4 addr, little_int_4 mask, little_int_4 data);

  bus::status read_port_0x400 (host_int_4 addr, little_int_4 mask, little_int_4 & data);
  bus::status write_port_0x400 (host_int_4 addr, little_int_4 mask, little_int_4 data);

  bus::status read_port_0x80 (host_int_4 addr, little_int_4 mask, little_int_4 & data);
  bus::status write_port_0x80 (host_int_4 addr, little_int_4 mask, little_int_4 data);

  callback_word_bus<unmapped, little_int_4> port_0xfff0_bus;
  callback_word_bus<unmapped, little_int_4> port_0x400_bus;
  callback_word_bus<unmapped, little_int_4> port_0x80_bus;

  bx_unmapped_c bx_unmapped;
};
#endif // SID_UNMAPPED_WRAPPER_DEF_H
