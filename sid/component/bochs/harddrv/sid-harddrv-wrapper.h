// sid-harddrive-wrapper.h - SID import of the bochs harddrive component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_HARDDRIVE_WRAPPER_DEF_H
#define SID_HARDDRIVE_WRAPPER_DEF_H	1

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
using sid::little_int_2;
using sid::little_int_4;
using sidutil::callback_word_bus;
using sidutil::callback_pin;
using sidutil::output_pin;

class harddrive : public sidutil::fixed_pin_map_component,
            public sidutil::no_accessor_component,
            public sidutil::fixed_attribute_map_component,
            public sidutil::no_relation_component,
            public sidutil::fixed_bus_map_component
{
public:
  harddrive();
  ~harddrive() throw() {};

  void init(host_int_4);
  void drive_interrupt_pin(void);
  
protected:

  callback_pin<harddrive> init_pin;

  output_pin interrupt_pin;

  bus::status read_port_0x1f0 (host_int_4 addr, little_int_2 mask, little_int_2 & data);
  bus::status write_port_0x1f0 (host_int_4 addr, little_int_2 mask, little_int_2 data);

  bus::status read_port_0x1f1_0x1f7 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x1f1_0x1f7 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0x3f6 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x3f6 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<harddrive, little_int_2> port_0x1f0_bus;
  callback_word_bus<harddrive, little_int_1> ports_0x1f1_0x1f7_bus;
  callback_word_bus<harddrive, little_int_1> port_0x3f6_bus;

  bx_hard_drive_c bx_harddrive;

public:
  bool diskc_present;
  std::string diskc_path;
  host_int_4 diskc_cylinders;
  host_int_4 diskc_heads;
  host_int_4 diskc_spt;

  bool diskd_present;
  std::string diskd_path;
  host_int_4 diskd_cylinders;
  host_int_4 diskd_heads;
  host_int_4 diskd_spt;
};
#endif // SID_HARDDRIVE_WRAPPER_DEF_H
