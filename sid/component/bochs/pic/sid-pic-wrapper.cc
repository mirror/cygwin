// sid-pic-wrapper.cc - SID import of the bochs pic component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-pic-wrapper.h"

pic::pic ()
    : init_pin(this, & pic::init),
      irq0_pin(this, & pic::irq0),
      irq1_pin(this, & pic::irq1),
      irq2_pin(this, & pic::irq2),
      irq3_pin(this, & pic::irq3),
      irq4_pin(this, & pic::irq4),
      irq5_pin(this, & pic::irq5),
      irq6_pin(this, & pic::irq6),
      irq7_pin(this, & pic::irq7),
      irq8_pin(this, & pic::irq8),
      irq9_pin(this, & pic::irq9),
      irq10_pin(this, & pic::irq10),
      irq11_pin(this, & pic::irq11),
      irq12_pin(this, & pic::irq12),
      irq13_pin(this, & pic::irq13),
      irq14_pin(this, & pic::irq14),
      irq15_pin(this, & pic::irq15),
      interrupt_acknowledge_pin(this, & pic::interrupt_acknowledge),
      ports_0x20_0x21_bus(this, & pic::read_port_0x20_0x21, & pic::write_port_0x20_0x21),
      ports_0xa0_0xa1_bus(this, & pic::read_port_0xa0_0xa1, & pic::write_port_0xa0_0xa1)
{
  add_pin("interrupt", & this->interrupt_pin);
  
  add_pin("interrupt-acknowledge", & this->interrupt_acknowledge_pin);
  add_pin("interrupt-ack-response", & this->interrupt_acknowledge_response_pin);

  add_pin("init", & this->init_pin);

  add_pin("irq0", & this->irq0_pin);
  add_pin("irq1", & this->irq1_pin);
  add_pin("irq2", & this->irq2_pin);
  add_pin("irq3", & this->irq3_pin);
  add_pin("irq4", & this->irq4_pin);
  add_pin("irq5", & this->irq5_pin);
  add_pin("irq6", & this->irq6_pin);
  add_pin("irq7", & this->irq7_pin);
  add_pin("irq8", & this->irq8_pin);
  add_pin("irq9", & this->irq9_pin);
  add_pin("irq10", & this->irq10_pin);
  add_pin("irq11", & this->irq11_pin);
  add_pin("irq12", & this->irq12_pin);
  add_pin("irq13", & this->irq13_pin);
  add_pin("irq14", & this->irq14_pin);
  add_pin("irq15", & this->irq15_pin);

  add_bus("ports-0x20-0x21", & this->ports_0x20_0x21_bus);
  add_bus("ports-0xa0-0xa1", & this->ports_0xa0_0xa1_bus);
}

void
pic::init(host_int_4)
{
  bx_pic.init(this);
}

void
pic::irq0(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(0);
}

void
pic::irq1(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(1);
}

void
pic::irq2(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(2);
}

void
pic::irq3(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(3);
}

void
pic::irq4(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(4);
}

void
pic::irq5(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(5);
}

void
pic::irq6(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(6);
}

void
pic::irq7(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(7);
}

void
pic::irq8(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(8);
}

void
pic::irq9(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(9);
}

void
pic::irq10(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(10);
}

void
pic::irq11(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(11);
}

void
pic::irq12(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(12);
}

void
pic::irq13(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(13);
}

void
pic::irq14(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(14);
}

void
pic::irq15(host_int_4 value)
{
  if (value)
    bx_pic.trigger_irq(15);
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
