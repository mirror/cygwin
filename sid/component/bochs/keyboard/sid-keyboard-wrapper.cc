// sid-keyboard-wrapper.cc - SID import of the bochs keyboard component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-keyboard-wrapper.h"

keyboard::keyboard ()
    : init_pin(this, & keyboard::init),
      generate_scancode_pin(this, & keyboard::generate_scancode),
      update_keyboard_pin(this, & keyboard::update_keyboard),
      port_0x60_bus(this, & keyboard::read_port_0x60, & keyboard::write_port_0x60),
      port_0x64_bus(this, & keyboard::read_port_0x64, & keyboard::write_port_0x64)
{
  add_pin("init", & this->init_pin);
  add_pin("generate-scancode", & this->generate_scancode_pin);
  add_pin("update-keyboard", & this->update_keyboard_pin);
  add_pin("serial-delay", & this->serial_delay_pin);

  add_bus("port-0x60", & this->port_0x60_bus);
  add_bus("port-0x64", & this->port_0x64_bus);
}

void
keyboard::init(host_int_4)
{
  bx_keyboard.init(this);
}

void
keyboard::generate_scancode(host_int_4 code)
{
  bx_keyboard.gen_scancode(code);
}

void
keyboard::update_keyboard(host_int_4)
{
  bx_keyboard.periodic(0);
}

void
keyboard::drive_serial_delay_pin(host_int_4 delay)
{
  // The serial-delay pin is intended to be connected to
  // a sid-sched component's N-control pin, and the
  // update-keyboard pin is intended to be connected to
  // the corresponding N-event pin.  Since update-keyboard
  // should be driven regularly, we must ensure that the
  // the top bit (the regular? flag) of the code driven on
  // the serial-delay pin is 1.
  host_int_4 code = delay | 0x80000000;
  serial_delay_pin.drive(code);
}

bus::status
keyboard::read_port_0x60 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x060;
  data = bx_keyboard.read(addr, 1);
  return bus::ok;
}

bus::status
keyboard::write_port_0x60 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x060;
  bx_keyboard.write(addr, data, 1);
  return bus::ok;
}

bus::status
keyboard::read_port_0x64 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x064;
  data = bx_keyboard.read(addr, 1);
  return bus::ok;
}

bus::status
keyboard::write_port_0x64 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x064;
  bx_keyboard.write(addr, data, 1);
  return bus::ok;
}
