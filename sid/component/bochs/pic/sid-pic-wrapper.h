// sid-pic-wrapper.h - SID import of the bochs pic component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_PIC_WRAPPER_DEF_H
#define SID_PIC_WRAPPER_DEF_H	1

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

class pic : public sidutil::fixed_pin_map_component,
            public sidutil::no_accessor_component,
            public sidutil::fixed_attribute_map_component,
            public sidutil::no_relation_component,
            public sidutil::fixed_bus_map_component
{
public:
  pic();
  ~pic() throw() {};

  void init(host_int_4);
  void trigger_irq(host_int_4 irq_number);
  void untrigger_irq(host_int_4 irq_number);
  void interrupt_acknowledge(host_int_4);

  void drive_interrupt_pin(host_int_4 value);

protected:

  output_pin interrupt_pin;
  output_pin interrupt_acknowledge_response_pin;

  callback_pin<pic> interrupt_acknowledge_pin;
  callback_pin<pic> init_pin;
  callback_pin<pic> trigger_irq_pin;
  callback_pin<pic> untrigger_irq_pin;

  bus::status read_port_0x20_0x21 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x20_0x21 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0xa0_0xa1 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0xa0_0xa1 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<pic, little_int_1> ports_0x20_0x21_bus;
  callback_word_bus<pic, little_int_1> ports_0xa0_0xa1_bus;

  bx_pic_c bx_pic;
};
#endif // SID_PIC_WRAPPER_DEF_H
