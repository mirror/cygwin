// sid-vga-wrapper.cc - SID import of the bochs vga component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-vga-wrapper.h"

vga::vga ()
    : init_pin(this, & vga::init),
      ports_3b4_3b5_bus(this, & vga::read_port_3b4_3b5, &vga::write_port_3b4_3b5),
      ports_3ba_bus(this, & vga::read_port_3ba, &vga::write_port_3ba),
      ports_3c0_3cf_bus(this, & vga::read_port_3c0_3cf, &vga::write_port_3c0_3cf),
      ports_3d4_3d5_bus(this, & vga::read_port_3d4_3d5, &vga::write_port_3d4_3d5),
      ports_3da_bus(this, & vga::read_port_3da, &vga::write_port_3da),
      framebuffer_bus(this, & vga::read_mem, &vga::write_mem)
{
  add_pin("init", & this->init_pin);

  add_pin("text-start-address", & this->text_start_address_pin);
  add_pin("text-cursor-x", & this->text_cursor_x_pin);
  add_pin("text-cursor-y", & this->text_cursor_y_pin);
  add_pin("text-memory-updated", & this->text_memory_updated_pin);

  add_pin("dimension-width", & this->dimension_width_pin);
  add_pin("dimension-height", & this->dimension_height_pin);
  add_pin("dimensions-updated", & this->dimensions_updated_pin);

  add_pin("palette-change-index", & this->palette_change_index_pin);

  add_bus("ports-0x3b4-0x3b5", & this->ports_3b4_3b5_bus);
  add_bus("port-0x3ba", & this->ports_3ba_bus);
  add_bus("ports-0x3c0-0x3cf", & this->ports_3c0_3cf_bus);
  add_bus("ports-0x3d4-0x3d5", & this->ports_3d4_3d5_bus);
  add_bus("port-0x3da", & this->ports_3da_bus);

  add_bus("framebuffer", & this->framebuffer_bus);
}

void
vga::init (host_int_4)
{
  bx_vga.init(this, this->buffer);
}

bus::status
vga::read_port_3b4_3b5 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x03b4;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_3b4_3b5 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x03b4;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_3ba (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x03ba;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_3ba (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x03ba;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_3c0_3cf (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x03c0;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_3c0_3cf (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x03c0;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_3d4_3d5 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x03d4;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_3d4_3d5 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x03d4;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_port_3da (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x03da;
  data = bx_vga.read(addr, 1);
  return bus::ok;
}

bus::status
vga::write_port_3da (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x03da;
  bx_vga.write(addr, data, 1, true);
  return bus::ok;
}

bus::status
vga::read_mem (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0xa0000;
  data = bx_vga.mem_read(addr);
  return bus::ok;
}

bus::status
vga::write_mem (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0xa0000;
  bx_vga.mem_write(addr, data);
  return bus::ok;
}

void
vga::drive_text_start_address_pin (host_int_4 addr)
{
  this->text_start_address_pin.drive(addr);
}

void
vga::drive_text_cursor_x_pin (host_int_4 x)
{
  this->text_cursor_x_pin.drive(x);
}

void
vga::drive_text_cursor_y_pin (host_int_4 y)
{
  this->text_cursor_y_pin.drive(y);
}

void
vga::drive_text_memory_updated_pin (void)
{
  this->text_memory_updated_pin.drive(1);
}

void
vga::drive_dimension_width_pin (host_int_4 width)
{
  this->dimension_width_pin.drive(width);
}

void
vga::drive_dimension_height_pin (host_int_4 height)
{
  this->dimension_height_pin.drive(height);
}

void
vga::drive_dimensions_updated_pin (void)
{
  this->dimensions_updated_pin.drive(1);
}

void
vga::drive_palette_change_index_pin (host_int_4 index)
{
  this->palette_change_index_pin.drive(index);
}
