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
      cmos_irq_number(8), use_host_time(true), start_time(917385580), use_image_file(false)
{
  add_pin("trigger-irq", & this->trigger_irq_pin);

  add_pin("periodic-timer-control", & this->periodic_timer_control_pin);
  add_pin("one-second-timer-control", & this->one_second_timer_control_pin);

  add_pin("init", & this->init_pin);
  add_pin("reset", & this->reset_pin);
  add_pin("image-load", & this->image_load_pin);
  add_pin("periodic-timer", & this->periodic_timer_pin);
  add_pin("one-second-timer", & this->one_second_timer_pin);
  add_pin("host-time", & this->host_time_pin);
  add_pin("time-query", & this->time_query_pin);

  add_bus("ports-0x70-0x71", & this->ports_0x70_0x71_bus);
  add_bus("registers", & this->register_bus);

  add_attribute("image-file", & this->image_file_path, "setting");
  add_attribute("use-image-file?", & this->use_image_file, "setting");
  add_attribute("irq-number", & this->cmos_irq_number, "setting");
  add_attribute("use-host-time?", & this->use_host_time, "setting");
  add_attribute("start-time", & this->start_time, "setting");
}

void
cmos::init(host_int_4)
{
  bx_cmos.init(this);
  bx_cmos.checksum_cmos();
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
    bx_cmos.generate_cmos_values();
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
cmos::drive_trigger_irq_pin(void)
{
  trigger_irq_pin.drive(cmos_irq_number);
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

host_int_4
cmos::get_time(void)
{
  static host_int_4 host_start_time = host_time_pin.sense();

  time_query_pin.drive(1);

  if (use_host_time)
    return host_time_pin.sense();
  else
    return start_time + (host_time_pin.sense() - host_start_time);
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
