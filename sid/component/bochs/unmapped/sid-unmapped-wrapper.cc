// sid-unmapped-wrapper.cc - SID import of the bochs unmapped component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-unmapped-wrapper.h"

unmapped::unmapped ()
    : port_0xfff0_bus(this, & unmapped::read_port_0xfff0, & unmapped::write_port_0xfff0),
      port_0x400_bus(this, & unmapped::read_port_0x400, & unmapped::write_port_0x400),
      port_0x80_bus(this, & unmapped::read_port_0x80, & unmapped::write_port_0x80)
{
  add_bus("port-0xfff0", & this->port_0xfff0_bus);
  add_bus("port-0x400", & this->port_0x400_bus);
  add_bus("port-0x80", & this->port_0x80_bus);
}

bus::status
unmapped::read_port_0xfff0 (host_int_4 addr, little_int_4 mask, little_int_4 & data)
{
  addr += 0xfff0;
  data = bx_unmapped.read(addr, 1);
  return bus::ok;
}

bus::status
unmapped::write_port_0xfff0 (host_int_4 addr, little_int_4 mask, little_int_4 data)
{
  addr += 0xfff0;
  bx_unmapped.write(addr, data, 1);
  return bus::ok;
}

bus::status
unmapped::read_port_0x400 (host_int_4 addr, little_int_4 mask, little_int_4 & data)
{
  addr += 0x400;
  data = bx_unmapped.read(addr, 1);
  return bus::ok;
}

bus::status
unmapped::write_port_0x400 (host_int_4 addr, little_int_4 mask, little_int_4 data)
{
  addr += 0x400;
  bx_unmapped.write(addr, data, 1);
  return bus::ok;
}

bus::status
unmapped::read_port_0x80 (host_int_4 addr, little_int_4 mask, little_int_4 & data)
{
  addr += 0x80;
  data = bx_unmapped.read(addr, 1);
  return bus::ok;
}

bus::status
unmapped::write_port_0x80 (host_int_4 addr, little_int_4 mask, little_int_4 data)
{
  addr += 0x80;
  bx_unmapped.write(addr, data, 1);
  return bus::ok;
}
