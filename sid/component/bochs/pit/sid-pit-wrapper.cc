// sid-pit-wrapper.cc - SID import of the bochs pit component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-pit-wrapper.h"

pit::pit ()
    : init_pin(this, & pit::init),
      update_pit_pin(this, & pit::update_pit),
      ports_0x40_0x43_bus(this, & pit::read_port_0x40_0x43, & pit::write_port_0x40_0x43),
      port_0x61_bus(this, & pit::read_port_0x61, & pit::write_port_0x61),
      timer_delta(100), pit_irq_number(0)
{
  add_pin("trigger-irq", & this->trigger_irq_pin);

  add_pin("init", & this->init_pin);
  add_pin("update-pit", & this->update_pit_pin);

  add_bus("ports-0x40-0x43", & this->ports_0x40_0x43_bus);
  add_bus("port-0x61", & this->port_0x61_bus);

  add_attribute("irq-number", & this->pit_irq_number, "setting");
  add_attribute("timer-delta", & this->timer_delta, "setting");
}

void
pit::init(host_int_4)
{
  bx_pit.init();
}

void
pit::update_pit(host_int_4)
{
  if(bx_pit.periodic(timer_delta))
    trigger_irq_pin.drive(pit_irq_number);
}

bus::status
pit::read_port_0x40_0x43 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x40;
  data = bx_pit.read(addr, 1);
  return bus::ok;
}

bus::status
pit::write_port_0x40_0x43 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x40;
  bx_pit.write(addr, data, 1);
  return bus::ok;
}

bus::status
pit::read_port_0x61 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x61;
  data = bx_pit.read(addr, 1);
  return bus::ok;
}

bus::status
pit::write_port_0x61 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x61;
  bx_pit.write(addr, data, 1);
  return bus::ok;
}
