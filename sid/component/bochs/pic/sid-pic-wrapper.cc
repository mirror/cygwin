// sid-pic-wrapper.cc - SID import of the bochs pic component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-pic-wrapper.h"

pic::pic ()
    : init_pin(this, & pic::init),
      trigger_irq_pin(this, & pic::trigger_irq),
      untrigger_irq_pin(this, & pic::untrigger_irq),
      interrupt_acknowledge_pin(this, & pic::interrupt_acknowledge),
      ports_0x20_0x21_bus(this, & pic::read_port_0x20_0x21, & pic::write_port_0x20_0x21),
      ports_0xa0_0xa1_bus(this, & pic::read_port_0xa0_0xa1, & pic::write_port_0xa0_0xa1)
{
  add_pin("interrupt", & this->interrupt_pin);
  
  add_pin("interrupt-acknowledge", & this->interrupt_acknowledge_pin);
  add_pin("interrupt-ack-response", & this->interrupt_acknowledge_response_pin);

  add_pin("init", & this->init_pin);
  add_pin("trigger-irq", & this->trigger_irq_pin);
  add_pin("untrigger-irq", & this->untrigger_irq_pin);

  add_bus("ports-0x20-0x21", & this->ports_0x20_0x21_bus);
  add_bus("ports-0xa0-0xa1", & this->ports_0xa0_0xa1_bus);
}

void
pic::init(host_int_4)
{
  bx_pic.init(this);
}

void
pic::trigger_irq(host_int_4 irq_number)
{
  bx_pic.trigger_irq(irq_number);
}

void
pic::untrigger_irq(host_int_4 irq_number)
{
  bx_pic.untrigger_irq(irq_number);
}

void
pic::interrupt_acknowledge(host_int_4)
{
  interrupt_acknowledge_response_pin.drive(bx_pic.IAC());
}

void
pic::drive_interrupt_pin(host_int_4 value)
{
  interrupt_pin.drive(value);
}

bus::status
pic::read_port_0x20_0x21 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x20;
  data = bx_pic.read(addr, 1);
  return bus::ok;
}

bus::status
pic::write_port_0x20_0x21 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x20;
  bx_pic.write(addr, data, 1);
  return bus::ok;
}

bus::status
pic::read_port_0xa0_0xa1 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0xa0;
  data = bx_pic.read(addr, 1);
  return bus::ok;
}

bus::status
pic::write_port_0xa0_0xa1 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0xa0;
  bx_pic.write(addr, data, 1);
  return bus::ok;
}
