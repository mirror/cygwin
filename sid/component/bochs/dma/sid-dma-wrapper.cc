// sid-dma-wrapper.cc - SID import of the bochs dma component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-dma-wrapper.h"

dma::dma ()
    : init_pin(this, & dma::init),
      hold_acknowledge_pin(this, & dma::hold_acknowledge),
      ports_0x00_0x0f_bus(this, & dma::read_port_0x00_0x0f, & dma::write_port_0x00_0x0f),
      ports_0x81_0x8d_bus(this, & dma::read_port_0x81_0x8d, & dma::write_port_0x81_0x8d),
      port_0x8f_bus(this, & dma::read_port_0x8f, & dma::write_port_0x8f),
      ports_0xc0_0xde_bus(this, & dma::read_port_0xc0_0xde, & dma::write_port_0xc0_0xde),
      channels_bus(this, & dma::channel_read_request, & dma::channel_write_request)
{
  add_pin("hold-request", & this->hold_request_pin);
  add_pin("terminal-count", & this->terminal_count_pin);

  add_pin("init", & this->init_pin);
  add_pin("hold-acknowledge", & this->hold_acknowledge_pin);

  add_bus("ports-0x00-0x0f", & this->ports_0x00_0x0f_bus);
  add_bus("ports-0x81-0x8d", & this->ports_0x81_0x8d_bus);
  add_bus("port-0x8f", & this->port_0x8f_bus);
  add_bus("ports-0xc0-0xde", & this->ports_0xc0_0xde_bus);
  add_bus("channels", & this->channels_bus);

  add_pin("read-write", & this->read_write_pin);

  add_pin("channel-0", & this->channel_pin[0]);
  add_pin("channel-1", & this->channel_pin[1]);
  add_pin("channel-2", & this->channel_pin[2]);
  add_pin("channel-3", & this->channel_pin[3]);
  add_pin("channel-4", & this->channel_pin[4]);
  add_pin("channel-5", & this->channel_pin[5]);
  add_pin("channel-6", & this->channel_pin[6]);
  add_pin("channel-7", & this->channel_pin[7]);
}

void
dma::init(host_int_4)
{
  bx_dma.init(this);
  terminal_count_pin.drive(0);
}

void
dma::hold_acknowledge(host_int_4)
{
  bx_dma.raise_HLDA();
}

void
dma::drive_hold_request_pin(host_int_4 value)
{
  hold_request_pin.drive(value);
}

void
dma::drive_terminal_count_pin(host_int_4 value)
{
  terminal_count_pin.drive(value);
}

void
dma::drive_channel_pin(host_int_4 channel, host_int_4 value, bool read_mode)
{
  read_write_pin.drive(read_mode);

  channel_pin[channel].drive(value);
}

bus::status
dma::read_port_0x00_0x0f (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x00;
  data = bx_dma.read(addr, 1);
  return bus::ok;
}

bus::status
dma::write_port_0x00_0x0f (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x00;
  bx_dma.write(addr, data, 1);
  return bus::ok;
}

bus::status
dma::read_port_0x81_0x8d (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x81;
  data = bx_dma.read(addr, 1);
  return bus::ok;
}

bus::status
dma::write_port_0x81_0x8d (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x81;
  bx_dma.write(addr, data, 1);
  return bus::ok;
}

bus::status
dma::read_port_0x8f (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x8f;
  data = bx_dma.read(addr, 1);
  return bus::ok;
}

bus::status
dma::write_port_0x8f (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x8f;
  bx_dma.write(addr, data, 1);
  return bus::ok;
}

bus::status
dma::read_port_0xc0_0xde (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0xc0;
  data = bx_dma.read(addr, 1);
  return bus::ok;
}

bus::status
dma::write_port_0xc0_0xde (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0xc0;
  bx_dma.write(addr, data, 1);
  return bus::ok;
}

bus::status
dma::channel_read_request(host_int_4 channel, little_int_1 mask, little_int_1 &val)
{
  // not used
  val = 0;
  return bus::ok;
}

bus::status
dma::channel_write_request(host_int_4 channel, little_int_1 mask, little_int_1 val)
{
  bx_dma.DRQ(channel, val);
  return bus::ok;
}
