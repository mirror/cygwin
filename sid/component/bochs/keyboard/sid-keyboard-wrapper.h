// sid-keyboard-wrapper.h - SID import of the bochs keyboard component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SID_KEYBOARD_WRAPPER_DEF_H
#define SID_KEYBOARD_WRAPPER_DEF_H	1

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

class keyboard : public sidutil::fixed_pin_map_component,
                 public sidutil::no_accessor_component,
                 public sidutil::fixed_attribute_map_component,
                 public sidutil::no_relation_component,
                 public sidutil::fixed_bus_map_component
{
public:
  keyboard();
  ~keyboard() throw() {};

  void init(host_int_4);
  void generate_scancode(host_int_4 code);
  void update_keyboard(host_int_4);

  void drive_serial_delay_pin(host_int_4 delay);
  
protected:

  callback_pin<keyboard> init_pin;
  callback_pin<keyboard> generate_scancode_pin;
  callback_pin<keyboard> update_keyboard_pin;

  output_pin serial_delay_pin;

  bus::status read_port_0x60 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x60 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  bus::status read_port_0x64 (host_int_4 addr, little_int_1 mask, little_int_1 & data);
  bus::status write_port_0x64 (host_int_4 addr, little_int_1 mask, little_int_1 data);

  callback_word_bus<keyboard, little_int_1> port_0x60_bus;
  callback_word_bus<keyboard, little_int_1> port_0x64_bus;

  bx_keyb_c bx_keyboard;
};
#endif // SID_KEYBOARD_WRAPPER_DEF_H
