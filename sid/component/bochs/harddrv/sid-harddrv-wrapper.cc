// sid-harddrive-wrapper.cc - SID import of the bochs harddrive component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-harddrv-wrapper.h"

harddrive::harddrive ()
    : init_pin(this, & harddrive::init),
      port_0x1f0_bus(this, & harddrive::read_port_0x1f0, & harddrive::write_port_0x1f0),
      ports_0x1f1_0x1f7_bus(this, & harddrive::read_port_0x1f1_0x1f7, & harddrive::write_port_0x1f1_0x1f7),
      port_0x3f6_bus(this, & harddrive::read_port_0x3f6, & harddrive::write_port_0x3f6)
{
  add_pin("interrupt", & this->interrupt_pin);

  add_pin("init", & this->init_pin);

  add_bus("port-0x1f0", & this->port_0x1f0_bus);
  add_bus("ports-0x1f1-0x1f7", & this->ports_0x1f1_0x1f7_bus);
  add_bus("port-0x3f6", & this->port_0x3f6_bus);

  add_attribute("diskc-present", & this->diskc_present, "setting");
  add_attribute("diskc-path", & this->diskc_path, "setting");
  add_attribute("diskc-cylinders", & this->diskc_cylinders, "setting");
  add_attribute("diskc-heads", & this->diskc_heads, "setting");
  add_attribute("diskc-sectors-per-track", & this->diskc_spt, "setting");

  add_attribute("diskd-present", & this->diskd_present, "setting");
  add_attribute("diskd-path", & this->diskd_path, "setting");
  add_attribute("diskd-cylinders", & this->diskd_cylinders, "setting");
  add_attribute("diskd-heads", & this->diskd_heads, "setting");
  add_attribute("diskd-sectors-per-track", & this->diskd_spt, "setting");
}

void
harddrive::init(host_int_4)
{
  bx_harddrive.init(this);
}

void
harddrive::drive_interrupt_pin(void)
{
  interrupt_pin.drive(1);
}

bus::status
harddrive::read_port_0x1f0 (host_int_4 addr, little_int_2 mask, little_int_2 & data)
{
  addr += 0x1f0;
  data = bx_harddrive.read(addr, 2);
  return bus::ok;
}

bus::status
harddrive::write_port_0x1f0 (host_int_4 addr, little_int_2 mask, little_int_2 data)
{
  addr += 0x1f0;
  bx_harddrive.write(addr, data, 2);
  return bus::ok;
}

bus::status
harddrive::read_port_0x1f1_0x1f7 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x1f1;
  data = bx_harddrive.read(addr, 1);
  return bus::ok;
}

bus::status
harddrive::write_port_0x1f1_0x1f7 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x1f1;
  bx_harddrive.write(addr, data, 1);
  return bus::ok;
}

bus::status
harddrive::read_port_0x3f6 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3f6;
  data = bx_harddrive.read(addr, 1);
  return bus::ok;
}

bus::status
harddrive::write_port_0x3f6 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3f6;
  bx_harddrive.write(addr, data, 1);
  return bus::ok;
}
