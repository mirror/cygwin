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
      port_0x64_bus(this, & keyboard::read_port_0x64, & keyboard::write_port_0x64),
      cmos_registers_bus(0), timer_delta(100), keyboard_irq_number(1), have_mouse(false)
{
  add_pin("trigger-irq", & this->trigger_irq_pin);
  add_pin("enable-a20", & this->enable_a20_pin);
  add_pin("a20-enabled", & this->a20_enabled_pin);

  add_pin("init", & this->init_pin);
  add_pin("generate-scancode", & this->generate_scancode_pin);
  add_pin("update-keyboard", & this->update_keyboard_pin);

  add_bus("port-0x60", & this->port_0x60_bus);
  add_bus("port-0x64", & this->port_0x64_bus);

  add_attribute("timer-delta", & this->timer_delta, "setting");
  add_attribute("keyboard-irq-number", & this->keyboard_irq_number, "setting");
  add_attribute("have-mouse?", & this->have_mouse, "setting");

  add_accessor("cmos-registers", & this->cmos_registers_bus);
}

void
keyboard::init(host_int_4)
{
  bx_keyboard.init(this);
  if (have_mouse)
    {
      // mouse port installed on system board
      if (cmos_registers_bus)
        {
          little_int_1 old_register_value;
          little_int_1 new_register_value;

          cmos_registers_bus->read(host_int_4(0x14), old_register_value);
          new_register_value = old_register_value | 0x04;
          cmos_registers_bus->write(host_int_4(0x14), new_register_value);
        }
    }
}

void
keyboard::generate_scancode(host_int_4 code)
{
  bx_keyboard.gen_scancode(code);
}

void
keyboard::update_keyboard(host_int_4)
{
  unsigned val = bx_keyboard.periodic(timer_delta);

  if((val & 0x01))
    trigger_irq_pin.drive(keyboard_irq_number);
}

void
keyboard::drive_enable_a20_pin(host_int_4 value)
{
  enable_a20_pin.drive(value);
}

host_int_4
keyboard::sense_a20_enabled_pin(void)
{
  return a20_enabled_pin.sense();
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
