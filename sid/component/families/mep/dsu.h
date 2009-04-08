// dsu.h -- Class declaration for the Toshiba Media Engine (MeP) debug
// support unit (DSU).  -*- C++ -*-

// Copyright (C) 2001, 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef DSU_H
#define DSU_H

#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidbusutil.h>
#include <sidpinutil.h>

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;

// The values are significant. They represent the value of the ID field of the
// ID register.
#define MEP_CORE_MEP     0x00
#define MEP_CORE_C2      0x02
#define MEP_CORE_C3      0x03
#define MEP_CORE_C4      0x04
#define MEP_CORE_C5      0x08
#define MEP_CORE_H1      0x10

class mep_dsu;
class debug_bus: public bus
{
public:
  debug_bus (mep_dsu& c, bool insn_bus_p)
    :debug_unit (c),
     insn_bus_p (insn_bus_p) 
  { }

private:
  mep_dsu& debug_unit;
  bool insn_bus_p;
  
  template <typename DataType>
  bus::status write_any (host_int_4 addr, DataType data);
  
  template <typename DataType>
  bus::status read_any (host_int_4 addr, DataType& data);

#define DEFN_METHOD(DataType) \
  bus::status write(host_int_4 addr, DataType data) throw (); \
  bus::status read(host_int_4 addr, DataType& data) throw ();
  
  DEFN_METHOD (sid::big_int_1)
  DEFN_METHOD (sid::big_int_2)
  DEFN_METHOD (sid::big_int_4)
  DEFN_METHOD (sid::big_int_8)
  DEFN_METHOD (sid::little_int_1)
  DEFN_METHOD (sid::little_int_2)
  DEFN_METHOD (sid::little_int_4)
  DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD
};

class insn_debug_bus: public debug_bus
{
public:
  insn_debug_bus (mep_dsu& c)
    :debug_bus (c, true) {}  
};

class data_debug_bus: public debug_bus
{
public:
  data_debug_bus (mep_dsu& c)
    :debug_bus (c, false) {}
};


class mep_dsu: public virtual component,
		protected fixed_attribute_map_component,
		protected fixed_bus_map_component,
		protected fixed_pin_map_component,
		protected fixed_accessor_map_component,
		protected no_relation_component
{
public:
  mep_dsu ();

  template <typename DataType> bus::status 
  write_any (bool insn_bus_p, host_int_4 addr, DataType data);
  
  template <typename DataType> bus::status
  read_any (bool insn_bus_p, host_int_4 addr, DataType& data);

private:
  int core_type;

  enum {
    single_step_exception = 0x1,
    insn_break_exception = 0x2,
    data_break_exception = 0x4,
    debug_breakpoint_exception = 0x8,
    debug_interrupt_exception = 0x10
  };

  output_pin exception_pin;
  output_pin interrupt_out_pin;
  output_pin nmi_out_pin;

  callback_pin<mep_dsu> interrupt_pin;
  void interrupt (host_int_4 value);
  big_int_4 get_eint () { return interrupts_enabled; }
  void set_eint (big_int_4 value, big_int_4 mask);
  int interrupts_enabled;
  bool interrupt_pending_p;
  host_int_4 interrupt_pending_value;

  callback_pin<mep_dsu> nmi_pin;
  void nmi (host_int_4 value);
  big_int_4 get_enmi () { return nmi_enabled; }
  void set_enmi (big_int_4 value, big_int_4 mask);
  int nmi_enabled;
  bool nmi_pending_p;
  host_int_4 nmi_pending_value;

  int insn_break_status_p;
  int data_break_status_p;
  big_int_4 get_ibs0 () { return insn_break_status_p; }
  big_int_4 get_dbs0 () { return data_break_status_p; }
  void set_ibs0 (big_int_4 value, big_int_4 mask) { if (!(value & mask)) { insn_break_status_p = 0; } }
  void set_db0s (big_int_4 value, big_int_4 mask) { if (!(value & mask)) { data_break_status_p = 0; } }

  big_int_4 ibc0_te;
  big_int_4 get_ibc0_te () { return ibc0_te; }
  void set_ibc0_te (big_int_4 value, big_int_4 mask)
    {
      if (core_type == MEP_CORE_C4 || core_type == MEP_CORE_H1
	  || core_type == MEP_CORE_C5)
	ibc0_te = value & mask;
    }

  big_int_4 dbc0_te;
  big_int_4 get_dbc0_te () { return dbc0_te; }
  void set_dbc0_te (big_int_4 value, big_int_4 mask)
    {
      if (core_type == MEP_CORE_C4 || core_type == MEP_CORE_H1
	  || core_type == MEP_CORE_C5)
	dbc0_te = value & mask;
    }

  // Break predicates.
  bool insn_break_p (host_int_4 addr);
  template <typename DataType>
  bool data_break_p (bool load_p, host_int_4 addr, DataType value);

  control_register_bus<big_int_4> status_regs;
  control_register_bus<big_int_4> insn_regs;
  control_register_bus<big_int_4> data_regs;

  // DCR.
  fixed_control_register<big_int_4> halt_status;
  fixed_control_register<big_int_4> sleep_status;
  callback_control_register<big_int_4, mep_dsu> enable_interrupt;
  callback_control_register<big_int_4, mep_dsu> enable_nmi;
  fixed_control_register<big_int_4> dcr_reserved;

  // IBS.
  value_control_register<big_int_4> insn_break_channel_num;
  value_control_register<big_int_4> insn_break_write_ign; // to ignore writes
  callback_control_register<big_int_4, mep_dsu> insn_break_status;
  fixed_control_register<big_int_4> ibs_reserved;

  // DBS.
  value_control_register<big_int_4> data_break_channel_num;
  value_control_register<big_int_4> data_break_write_ign; // to ignore writes
  callback_control_register<big_int_4, mep_dsu> data_break_status;
  fixed_control_register<big_int_4> dbs_reserved;

  // Tracing registers
  fixed_control_register<big_int_4> trace_control;
  fixed_control_register<big_int_4> trace_filter_address_1;
  fixed_control_register<big_int_4> trace_filter_address_2;

  // IBA0.
  value_control_register<big_int_4> insn_break_addr;
  fixed_control_register<big_int_4> iba_reserved;

  // IBC0.
  value_control_register<big_int_4> insn_break_enable;
  callback_control_register<big_int_4, mep_dsu> insn_trigger_enable;
  fixed_control_register<big_int_4> ibc_reserved;

  // IBM0.
  value_control_register<big_int_4> insn_break_mask;
  fixed_control_register<big_int_4> ibm_reserved;

  // DBA0.
  value_control_register<big_int_4> data_break_addr;
  fixed_control_register<big_int_4> dba_reserved;

  // DBM0.
  value_control_register<big_int_4> data_break_mask;
  fixed_control_register<big_int_4> dbm_reserved;

  // DB0.
  value_control_register<big_int_4> data_value_break;

  // DBU0.
  value_control_register<big_int_4> data_value_break_upper;

  // DBC0.
  value_control_register<big_int_4> data_break_enable;
  callback_control_register<big_int_4, mep_dsu> data_trigger_enable;
  value_control_register<big_int_4> no_store_break;
  value_control_register<big_int_4> no_load_break;
  value_control_register<big_int_4> byte_address_ignored_0;
  value_control_register<big_int_4> byte_address_ignored_1;
  value_control_register<big_int_4> byte_address_ignored_2;
  value_control_register<big_int_4> byte_address_ignored_3;
  fixed_control_register<big_int_4> byte_address_ignored_4;
  fixed_control_register<big_int_4> byte_address_ignored_5;
  fixed_control_register<big_int_4> byte_address_ignored_6;
  fixed_control_register<big_int_4> byte_address_ignored_7;
  value_control_register<big_int_4> byte_lane_mask_0;
  value_control_register<big_int_4> byte_lane_mask_1;
  value_control_register<big_int_4> byte_lane_mask_2;
  value_control_register<big_int_4> byte_lane_mask_3;
  value_control_register<big_int_4> byte_lane_mask_4;
  value_control_register<big_int_4> byte_lane_mask_5;
  value_control_register<big_int_4> byte_lane_mask_6;
  value_control_register<big_int_4> byte_lane_mask_7;
  fixed_control_register<big_int_4> dbc_reserved;

  // Reserved field in data regs.
  fixed_control_register<big_int_4> reserved;

  insn_debug_bus insn_upstream;
  data_debug_bus data_upstream;

  bus* insn_downstream;
  bus* data_downstream;
};

template <typename DataType>
bool
mep_dsu::data_break_p (bool load_p, host_int_4 addr, DataType value)
{
  if (!data_break_enable)
    return false;

  if ((load_p && no_load_break) || (!load_p && no_store_break))
    return false;

  // Address test.
  if (addr != (data_break_addr & ~(data_break_mask | 3)))
    return false;

  // Value test.
}

template <typename DataType>
bus::status
debug_bus::write_any (host_int_4 addr, DataType data)
{
  return debug_unit.write_any (insn_bus_p, addr, data);
}
  
template <typename DataType>
bus::status
debug_bus::read_any (host_int_4 addr, DataType& data)
{
  return debug_unit.read_any (insn_bus_p, addr, data);
}

#define DEFN_METHOD(DataType) \
  inline bus::status debug_bus::write(host_int_4 addr, DataType data) throw () { return this->write_any(addr, data); } \
  inline bus::status debug_bus::read(host_int_4 addr, DataType& data) throw () { return this->read_any(addr, data); }
  
DEFN_METHOD (sid::big_int_1)
DEFN_METHOD (sid::big_int_2)
DEFN_METHOD (sid::big_int_4)
DEFN_METHOD (sid::big_int_8)
DEFN_METHOD (sid::little_int_1)
DEFN_METHOD (sid::little_int_2)
DEFN_METHOD (sid::little_int_4)
DEFN_METHOD (sid::little_int_8)
#undef DEFN_METHOD

#endif // DSU_H
