// sid-cmos-wrapper.cc - SID import of the bochs cmos component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-cmos-wrapper.h"

cmos::cmos ()
    : init_pin(this, & cmos::init),
      reset_pin(this, & cmos::reset),
      image_load_pin(this, & cmos::image_load),
      periodic_timer_pin(this, & cmos::periodic_timer),
      one_second_timer_pin(this, & cmos::one_second_timer),
      register_0x10 (& this->register_bus, host_int_4(0x10), little_int_1(0xff),
                     true, true, this, & cmos::set_register_0x10, & cmos::get_register_0x10),
      register_0x14 (& this->register_bus, host_int_4(0x14), little_int_1(0xff),
                     true, true, this, & cmos::set_register_0x14, & cmos::get_register_0x14),
      ports_0x70_0x71_bus(this, & cmos::read_port_0x70_0x71, & cmos::write_port_0x70_0x71),
      base_memory_in_k(640), extended_memory_in_k(32768), use_image_file(false)
{
  add_pin("interrupt", & this->interrupt_pin);

  add_pin("periodic-timer-control", & this->periodic_timer_control_pin);
  add_pin("one-second-timer-control", & this->one_second_timer_control_pin);

  add_pin("init", & this->init_pin);
  add_pin("reset", & this->reset_pin);
  add_pin("image-load", & this->image_load_pin);
  add_pin("periodic-timer", & this->periodic_timer_pin);
  add_pin("one-second-timer", & this->one_second_timer_pin);

  add_bus("ports-0x70-0x71", & this->ports_0x70_0x71_bus);
  add_bus("registers", & this->register_bus);

  add_attribute("image-file", & this->image_file_path, "setting");
  add_attribute("use-image-file?", & this->use_image_file, "setting");
  add_attribute("base-memory-in-k", & this->base_memory_in_k, "setting");
  add_attribute("extended-memory-in-k", & this->extended_memory_in_k, "setting");
}

void
cmos::init(host_int_4)
{
  bx_cmos.init(this);
}

void
cmos::reset(host_int_4)
{
  bx_cmos.reset();
}

void
cmos::image_load(host_int_4)
{
  if (use_image_file)
    bx_cmos.load_cmos_image(image_file_path);
  else
    {
      bx_cmos.generate_cmos_values();

      bx_cmos.s.reg[0x15] = (Bit8u) base_memory_in_k;
      bx_cmos.s.reg[0x16] = (Bit8u) (base_memory_in_k >> 8);
      bx_cmos.s.reg[0x17] = (Bit8u) (extended_memory_in_k - 1024);
      bx_cmos.s.reg[0x18] = (Bit8u) ((extended_memory_in_k - 1024) >> 8);
      bx_cmos.s.reg[0x30] = (Bit8u) (extended_memory_in_k - 1024);
      bx_cmos.s.reg[0x31] = (Bit8u) ((extended_memory_in_k - 1024) >> 8);

      bx_cmos.checksum_cmos();
    }
}

void
cmos::periodic_timer(host_int_4)
{
  bx_cmos.periodic_timer_handler();
}

void
cmos::one_second_timer(host_int_4)
{
  bx_cmos.one_second_timer_handler();
}

void
cmos::drive_interrupt_pin(void)
{
  interrupt_pin.drive(1);
}

void
cmos::drive_periodic_timer_control_pin(host_int_4 value, bool regular)
{
  host_int_4 code = value | (regular << 31);

  periodic_timer_control_pin.drive(code);
}

void
cmos::drive_one_second_timer_control_pin(host_int_4 value, bool regular)
{
  host_int_4 code = value | (regular << 31);

  one_second_timer_control_pin.drive(code);
}

bus::status
cmos::read_port_0x70_0x71 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x70;
  data = bx_cmos.read(addr, 1);
  return bus::ok;
}

bus::status
cmos::write_port_0x70_0x71 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x70;
  bx_cmos.write(addr, data, 1);
  return bus::ok;
}

void
cmos::set_register_0x10 (little_int_1 data, little_int_1 mask)
{
  bx_cmos.s.reg[0x10] = data;
}

little_int_1
cmos::get_register_0x10 (void)
{
  return bx_cmos.s.reg[0x10];
}

void
cmos::set_register_0x14 (little_int_1 data, little_int_1 mask)
{
  bx_cmos.s.reg[0x14] = data;
}

little_int_1
cmos::get_register_0x14 (void)
{
  return bx_cmos.s.reg[0x14];
}
