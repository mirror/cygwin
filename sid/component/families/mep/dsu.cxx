// dsu.cxx - An implementation of the debug support unit (DSU) of the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2001, 2002, 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <iostream>
#include "dsu.h"

mep_dsu::mep_dsu ()
  :core_type (MEP_CORE_C2),
   halt_status            (&status_regs, 0, 0x00004000, true, true, 0),
   sleep_status           (&status_regs, 0, 0x00002000, true, true, 0),
   enable_interrupt       (&status_regs, 0, 0x00000010, true, true, this, &mep_dsu::set_eint, &mep_dsu::get_eint),
   enable_nmi             (&status_regs, 0, 0x00000008, true, true, this, &mep_dsu::set_enmi, &mep_dsu::get_enmi),
   dcr_reserved           (&status_regs, 0, 0xFFFF9FE7),
   insn_break_channel_num (&status_regs, 1, 0x0F000000, true, false, 0x01000000),
   insn_break_write_ign   (&status_regs, 1, 0x0F000000, false, true, 0x01000000),
   insn_break_status      (&status_regs, 1, 0x00000001, true, true, this, &mep_dsu::set_ibs0, &mep_dsu::get_ibs0),
   ibs_reserved           (&status_regs, 1, 0xF0FFFFFE),
   data_break_channel_num (&status_regs, 2, 0x0F000000, true, false, 0x01000000),
   data_break_write_ign   (&status_regs, 2, 0x0F000000, false, true, 0x01000000),
   data_break_status      (&status_regs, 2, 0x00000001, true, true, this, &mep_dsu::set_db0s, &mep_dsu::get_dbs0),
   dbs_reserved           (&status_regs, 2, 0xF0FFFFFE),
   trace_control          (&status_regs, 3, 0xFFFFFFFF),
   trace_filter_address_1 (&status_regs, 4, 0xFFFFFFFF),
   trace_filter_address_2 (&status_regs, 5, 0xFFFFFFFF),
   insn_break_addr        (&insn_regs,   0, 0xFFFFFFFE, true, true),
   iba_reserved	          (&insn_regs,   0, 0x00000001),
   ibc_reserved           (&insn_regs,   1, 0xFFFFFFFC),
   insn_trigger_enable    (&insn_regs,   1, 0x00000002, true, true, this, &mep_dsu::set_ibc0_te, &mep_dsu::get_ibc0_te),
   insn_break_enable      (&insn_regs,   1, 0x00000001, true, true),
   ibm_reserved           (&insn_regs,   2, 0x00000001),
   insn_break_mask        (&insn_regs,   2, 0xFFFFFFFE, true, true),
   dba_reserved           (&data_regs,   0, 0x00000003),
   data_break_addr        (&data_regs,   0, 0xFFFFFFFC, true, true),
   data_trigger_enable    (&data_regs,   1, 0x00000002, true, true, this, &mep_dsu::set_dbc0_te, &mep_dsu::get_dbc0_te),
   data_break_enable      (&data_regs,   1, 0x00000001, true, true),
   no_store_break         (&data_regs,   1, 0x00002000, true, true),
   no_load_break          (&data_regs,   1, 0x00001000, true, true),
   byte_lane_mask_0       (&data_regs,   1, 0x00000010, true, true),
   byte_lane_mask_1       (&data_regs,   1, 0x00000020, true, true),
   byte_lane_mask_2       (&data_regs,   1, 0x00000040, true, true),
   byte_lane_mask_3       (&data_regs,   1, 0x00000080, true, true),
   byte_lane_mask_4       (&data_regs,   1, 0x00000100, true, true),
   byte_lane_mask_5       (&data_regs,   1, 0x00000200, true, true),
   byte_lane_mask_6       (&data_regs,   1, 0x00000400, true, true),
   byte_lane_mask_7       (&data_regs,   1, 0x00000800, true, true),
   byte_address_ignored_0 (&data_regs,   1, 0x00004000, true, true),
   byte_address_ignored_1 (&data_regs,   1, 0x00008000, true, true),
   byte_address_ignored_2 (&data_regs,   1, 0x00010000, true, true),
   byte_address_ignored_3 (&data_regs,   1, 0x00020000, true, true),
   byte_address_ignored_4 (&data_regs,   1, 0x00040000),
   byte_address_ignored_5 (&data_regs,   1, 0x00080000),
   byte_address_ignored_6 (&data_regs,   1, 0x00100000),
   byte_address_ignored_7 (&data_regs,   1, 0x00200000),
   dbc_reserved           (&data_regs,   1, 0xFFC0000C),
   data_break_mask        (&data_regs,   2, 0xFFFFFFFC, true, true),
   dbm_reserved           (&data_regs,   2, 0x00000003),
   reserved               (&data_regs,   3, 0xFFFFFFFF),
   data_value_break       (&data_regs,   4, 0xFFFFFFFF, true, true),
   data_value_break_upper (&data_regs,   5, 0xFFFFFFFF, true, true),

   interrupt_pin (this, &mep_dsu::interrupt),
   nmi_pin (this, &mep_dsu::nmi),
   insn_downstream (0), data_downstream (0),
   insn_upstream (*this), data_upstream (*this),
   interrupt_pending_p (false), interrupt_pending_value (0), interrupts_enabled (0x10),
   nmi_pending_p (false), nmi_pending_value (0), nmi_enabled (0x8),
   insn_break_status_p (0), data_break_status_p (0),
   ibc0_te (0), dbc0_te (0)
{
  add_accessor ("insn-downstream", &insn_downstream);
  add_accessor ("data-downstream", &data_downstream);
  add_bus ("insn-upstream", &insn_upstream);
  add_bus ("data-upstream", &data_upstream);

  add_bus ("status-regs", &status_regs);
  add_bus ("insn-regs", &insn_regs);
  add_bus ("data-regs", &data_regs);

  add_attribute ("core-type", &core_type, "setting");
  add_attribute_ro ("insn-break-enabled?", &insn_break_enable, "register");
  add_attribute_ro ("data-break-enabled?", &data_break_enable, "register");
  add_attribute_ro ("interrupts-enabled?", &interrupts_enabled, "register");
  add_attribute_ro ("nmi-enabled?", &nmi_enabled, "register");
  add_attribute_ro ("halted?", &halt_status, "register");
  add_attribute_ro ("sleeping?", &sleep_status, "register");
  add_attribute_ro ("insn-break-channel-#", &insn_break_channel_num, "register");
  add_attribute_ro ("data-break-channel-#", &data_break_channel_num, "register");
  add_attribute_ro ("insn-break-status", &insn_break_status_p, "register");
  add_attribute_ro ("data-break-status", &data_break_status_p, "register");

  add_pin ("exception!", &exception_pin);
  add_pin ("interrupt-in", &interrupt_pin);
  add_pin ("interrupt-out", &interrupt_out_pin);
  add_pin ("nmi-in", &nmi_pin);
  add_pin ("nmi-out", &nmi_out_pin);
}

void
mep_dsu::set_enmi (big_int_4 mask, big_int_4 value)
{
  if (!nmi_enabled && (mask & value))
    {
      nmi_out_pin.drive (nmi_pending_value);
      nmi_pending_p = false;
    }
  nmi_enabled = (mask & value);
}

void
mep_dsu::nmi (host_int_4 value)
{
  if (nmi_enabled)
    nmi_out_pin.drive (value);
  else
    {
      nmi_pending_p = true;
      nmi_pending_value = value;
    }
}

void
mep_dsu::set_eint (big_int_4 mask, big_int_4 value)
{
  if (!interrupts_enabled && (mask & value))
    {
      interrupt_out_pin.drive (interrupt_pending_value);
      interrupt_pending_p = false;
    }
  interrupts_enabled = (mask & value);
}

void
mep_dsu::interrupt (host_int_4 value)
{
  if (interrupts_enabled)
    interrupt_out_pin.drive (value);
  else
    {
      interrupt_pending_p = true;
      interrupt_pending_value = value;
    }
}

bool
mep_dsu::insn_break_p (host_int_4 addr)
{
  host_int_4 mask = ~((insn_break_mask << 1) | 1);
  return insn_break_enable && ((addr & mask) == ((insn_break_addr << 1) & mask));
}

template <typename DataType>
bus::status
mep_dsu::read_any (bool insn_bus_p, host_int_4 addr, DataType& data)
{
  if (insn_bus_p && insn_downstream)
    {
      if (insn_break_p (addr))
	{
	  insn_break_status_p = true;
	  exception_pin.drive (insn_break_exception);
	}
      else
	return insn_downstream->read (addr, data);
    }
  
  if (!insn_bus_p && data_downstream)
    {
      if (data_break_p (true, addr, data))
	{
	  // Break!
	  data_break_status_p = true;
	}
      else
        return data_downstream->read (addr, data);
    }
  
  return bus::unmapped;
}

template <typename DataType>
bus::status
mep_dsu::write_any (bool insn_bus_p, host_int_4 addr, DataType data)
{
  if (insn_bus_p && insn_downstream)
    {
      if (insn_break_p (addr))
	{
	  insn_break_status_p = true;
	  exception_pin.drive (insn_break_exception);
	}
      else
	return insn_downstream->write (addr, data);
    }

  if (!insn_bus_p && data_downstream)
    {
      if (data_break_p (false, addr, data))
	{
	  // Break!
	  data_break_status_p = true;
	}
      else
	return data_downstream->write (addr, data);
    }

  return bus::unmapped;
}








