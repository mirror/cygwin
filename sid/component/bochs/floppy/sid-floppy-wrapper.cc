// sid-floppy-wrapper.cc - SID import of the bochs floppy component.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sid-floppy-wrapper.h"

floppy::floppy ()
    : init_pin(this, & floppy::init),
      reset_pin(this, & floppy::reset),
      command_delay_pin(this, & floppy::command_delay),
      dma_channel_pin(this, & floppy::dma_channel),
      ports_0x3f2_0x3f7_bus(this, & floppy::read_port_0x3f2_0x3f7, & floppy::write_port_0x3f2_0x3f7),
      floppy_dma_channel(2), floppy_irq_number(6), floppy_a_type("1.44"), floppy_b_type("none"),
      cmos_registers_bus(0), dma_channels_bus(0), dma_bus(0)
{
  add_pin("terminal-count", & this->terminal_count_pin);

  add_pin("trigger-irq", & this->trigger_irq_pin);
  add_pin("command-delay-control", & this->command_delay_control_pin);

  add_pin("init", & this->init_pin);
  add_pin("reset", & this->reset_pin);
  add_pin("command-delay", & this->command_delay_pin);

  add_bus("ports-0x3f2-0x3f7", & this->ports_0x3f2_0x3f7_bus);

  add_accessor("cmos-registers", & this->cmos_registers_bus);
  add_accessor("dma-channels", & this->dma_channels_bus);
  add_accessor("dma", & this->dma_bus);

  add_pin("read-write", & this->read_write_pin);
  add_pin("dma-channel", & this->dma_channel_pin);

  add_attribute("floppy-a-type", & this->floppy_a_type, "setting");
  add_attribute("floppy-b-type", & this->floppy_b_type, "setting");

  add_attribute("floppy-a-path", & this->floppy_a_path, "setting");
  add_attribute("floppy-b-path", & this->floppy_b_path, "setting");

  add_attribute("floppy-a-inserted?", & this->floppy_a_is_inserted, "setting");
  add_attribute("floppy-b-inserted?", & this->floppy_b_is_inserted, "setting");

  add_attribute("dma-channel", & this->floppy_dma_channel, "setting");
  add_attribute("irq-number", & this->floppy_irq_number, "setting");
}

void
floppy::init(host_int_4)
{
  host_int_1 num_floppies = 0;
  host_int_1 bx_floppy_type = BX_FLOPPY_NONE;
  little_int_1 old_register_value;
  little_int_1 new_register_value;

  bx_floppy.init(this);

  // Check for floppy a:

  // start out with no drive 0 and no drive 1
  old_register_value = 0x0;

  if (cmos_registers_bus)
    cmos_registers_bus->write(host_int_4(0x10), old_register_value);

  if (floppy_a_type == "none")
    {
      new_register_value = (old_register_value & 0x0f) | 0x00;
      bx_floppy_type = BX_FLOPPY_NONE;
    }
  else if (floppy_a_type == "1.2")
    {
      new_register_value = (old_register_value & 0x0f) | 0x20;
      bx_floppy_type = BX_FLOPPY_1_2;
    }
  else if (floppy_a_type == "720")
    {
      new_register_value = (old_register_value & 0x0f) | 0x30;
      bx_floppy_type = BX_FLOPPY_720K;
    }
  else if (floppy_a_type == "1.44")
    {
      new_register_value = (old_register_value & 0x0f) | 0x40;
      bx_floppy_type = BX_FLOPPY_1_44;
    }
  else if (floppy_a_type == "2.88")
    {
      new_register_value = (old_register_value & 0x0f) | 0x50;
      bx_floppy_type = BX_FLOPPY_2_88;
    }
  else
    cerr << "floppy: Invalid floppy a type." << endl;

  if (bx_floppy_type != BX_FLOPPY_NONE)
    {
      num_floppies++;
      if (floppy_a_is_inserted)
        bx_floppy.call_evaluate_media(bx_floppy_type, floppy_a_path.c_str(), 0);
    }

  // Check for floppy b:
  if (floppy_b_type == "none")
    {
      new_register_value = (new_register_value & 0xf0) | 0x00;
      bx_floppy_type = BX_FLOPPY_NONE;        
    }
  else if (floppy_b_type == "1.2")
    {
      new_register_value = (new_register_value & 0xf0) | 0x02;
      bx_floppy_type = BX_FLOPPY_1_2;
    }
  else if (floppy_b_type == "720")
    {
      new_register_value = (new_register_value & 0xf0) | 0x03;
      bx_floppy_type = BX_FLOPPY_720K;
    }
  else if (floppy_b_type == "1.44")
    {
      new_register_value = (new_register_value & 0xf0) | 0x04;
      bx_floppy_type = BX_FLOPPY_1_44;
    }
  else if (floppy_b_type == "2.88")
    {
      new_register_value = (new_register_value & 0xf0) | 0x05;
      bx_floppy_type = BX_FLOPPY_2_88;
    }
  else
    cerr << "floppy: Invalid floppy b type." << endl;
  
  if (bx_floppy_type != BX_FLOPPY_NONE)
    {
      num_floppies++;
      if (floppy_b_is_inserted)
        bx_floppy.call_evaluate_media(bx_floppy_type, floppy_b_path.c_str(), 1);
    }

  if (cmos_registers_bus)
    {
      cmos_registers_bus->write(host_int_4(0x10), new_register_value);

      cmos_registers_bus->read(host_int_4(0x14), old_register_value);

      if (num_floppies > 0)
        {
          new_register_value = (old_register_value & 0x3e) | ((num_floppies - 1) << 6) | 1;
          cmos_registers_bus->write(host_int_4(0x14), new_register_value);
        }
      else
        {
          new_register_value = old_register_value & 0x3e;
          cmos_registers_bus->write(host_int_4(0x14), new_register_value);
        }
    }
}

void
floppy::reset(host_int_4)
{
  bx_floppy.reset(BX_RESET_HARDWARE);
}

void
floppy::drive_trigger_irq_pin(void)
{
  trigger_irq_pin.drive(floppy_irq_number);
}

void
floppy::drive_command_delay_control_pin(host_int_4 value, bool regular)
{
  host_int_4 code = value | (regular << 31);

  command_delay_control_pin.drive(code);
}

void
floppy::channel_request(host_int_4 channel, little_int_1 val)
{
  if (dma_channels_bus)
    dma_channels_bus->write(channel, val);
  else
    cerr << "floppy: dma-channels bus not connected." << endl;
}

bool
floppy::terminal_count(void)
{
  return terminal_count_pin.sense();
}

bus::status
floppy::read_port_0x3f2_0x3f7 (host_int_4 addr, little_int_1 mask, little_int_1 & data)
{
  addr += 0x3f2;
  data = bx_floppy.read(addr, 1);
  return bus::ok;
}

bus::status
floppy::write_port_0x3f2_0x3f7 (host_int_4 addr, little_int_1 mask, little_int_1 data)
{
  addr += 0x3f2;
  bx_floppy.write(addr, data, 1);
  return bus::ok;
}

host_int_4
floppy::dma_channel_number(void)
{
  return floppy_dma_channel;
}

void
floppy::dma_channel(host_int_4 phy_addr)
{
  if (read_write_pin.sense())
    // read mode
    bx_floppy.dma_read(phy_addr);
  else
    // write mode
    bx_floppy.dma_write(phy_addr);
}

void
floppy::dma_write(host_int_4 addr, little_int_1 data)
{
  dma_bus->write(addr, data);
}

void
floppy::dma_read(host_int_4 addr, unsigned char *data)
{
  little_int_1 read_data;

  dma_bus->read(addr, read_data);

  *data = read_data;
}

void
floppy::command_delay(host_int_4)
{
  bx_floppy.timer();
}
