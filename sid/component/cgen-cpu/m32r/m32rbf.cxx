// m32rbf.cxx - Implementations of hand-written functions for the M32R
// simulator. -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// Normally, cpu ports are divided into a common part (e.g. arm-cmn.{h,cxx})
// and one or more cpu-family specific parts.  The M32R is a fairly simple
// port so we don't currently do this.

#include "m32rbf.h"

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace m32rbf;


m32rbf_cpu::m32rbf_cpu ():
  engine (32768) // XXX: tune size
{
  for (unsigned i = 0; i < 15; ++i)
    {
      string name = string ("r") + make_numeric_attribute (i);
      SI* value = & this->hardware.h_gr[i];
      this->add_watchable_register (name, value);
    }

  {
    string name = "pc";
    USI* value = & this->hardware.h_pc;
    this->add_watchable_register (name, value);
  }
  // XXX: add h_cr also!

  this->create_gdb_register_attrs (24, "", & this->hardware.h_pc);
}


void
m32rbf_cpu::reset ()
{
  this->hardware.h_pc = 0;
  for (unsigned i=0; i<16; i++)
    this->hardware.h_gr[i] = this->hardware.h_cr[i] = 0;
  this->hardware.h_accum = 0;
  this->hardware.h_cond = this->hardware.h_lock = false;
  this->hardware.h_psw = this->hardware.h_bpsw = this->hardware.h_bbpsw = 0;
}


void
m32rbf_cpu::flush_icache ()
{
  this->engine.flush ();
}


void
m32rbf_cpu::invalid_insn (PCADDR pc)
{
  // Update recorded pc in case software trap handling component wants to
  // use it.  This is also needed if the insn is handled as hardware would.
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_invalid_insn, pc);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "hw-cpu-m32r: invalid insn not implemented" << endl;
      break;

    case cpu_trap_skip:
      {
	PCADDR npc = pc + 2;
	this->h_pc_set (npc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  throw cpu_exception ();
}



// Memory trap(/fault) handling.
void
m32rbf_cpu::memory_trap (const cpu_memory_fault& t)
{
  this->h_pc_set (t.pc);

  if (t.status == bus::delayed)
    return;

  if (this->debug_exec_p)
    cerr << "MEMORY TRAP "
	 << " operation=" << t.operation
	 << " pc=0x" << hex << t.pc << dec
	 << " address=0x" << hex << t.address << dec
	 << " status=" << (int) t.status 
	 << endl;
  
  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_memory_fault, t.address);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "hw-cpu-m32r: memory fault handler unimplemented!" << endl;
      break;

    case cpu_trap_skip:
      {
	PCADDR pc = t.pc + 4;
	this->h_pc_set (pc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }
}


SI
m32rbf_cpu::m32r_trap (PCADDR pc, USI trap)
{
  // Update recorded pc in case software trap handling component wants to
  // use it.  This is also needed if the insn is handled as hardware would.
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_software, trap);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "hw-cpu-m32r: trap insn not implemented" << endl;
      break;

    case cpu_trap_skip:
      {
	PCADDR npc = pc + 2;
	this->h_pc_set (npc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  throw cpu_exception ();
}

// Stepper

void
m32rbf_cpu::step_insns ()
{
  while (true)
    {
      // Fetch/decode the instruction  ------------------------------
      PCADDR pc = this->h_pc_get ();
      bool found;
      m32rbf_scache* sem = this->engine.find (pc, found);
      if (! found)
	{
	  if ((pc & 0x02) == 0x00) // beginning of instruction pair
	    {
	      USI insn;
	      try
		{
		  insn = this->GETIMEMSI (pc, pc);
		}
	      catch (cpu_memory_fault& t)
		{
		  this->memory_trap (t);
		  break;
		}
	      
	      if (insn & 0x80000000) // long instruction?
		{
		  UHI first = (insn >> 16);
		  sem->decode (this, pc, first, insn);
		}
	      else // pair of short instructions
		{
		  UHI first = insn >> 16;
		  sem->decode (this, pc, first, first);
		}
	    }
	  else // resuming at mid-instruction
	    {
	      // fetch half instruction
	      UHI insn;
	      try
		{
		  insn = this->GETIMEMHI (pc, pc);
		}
	      catch (cpu_memory_fault& t)
		{
		  this->memory_trap (t);
		  break;
		}

	      insn = insn & 0x7fff;
	      sem->decode (this, pc, insn, insn);
	    }
	}

      // Execute the instruction  -----------------------------------
      if (this->trace_result_p)
	this->begin_trace (pc, sem->idesc->insn_name);
      try
	{
	  sem->idesc->execute (this, sem);
	}
      catch (cpu_memory_fault& t)
	{
	  this->memory_trap (t);
	  this->yield ();
	}
      catch (cpu_exception& t)
	{
	  this->yield ();
	}
      if (this->trace_result_p)
	this->end_trace ();

      // Do post-instruction processing  ----------------------------
      if (this->enable_step_trap_p) 
	this->signal_trap (sidutil::cpu_trap_stepped);
      this->triggerpoint_manager.check_and_dispatch ();
      
      // test for exit condition
      if (stop_after_insns_p (1))
	break;
    }
}

// State save/restore

void 
m32rbf_cpu::stream_state (ostream& o) const
{
  // call base class first
  cgen_bi_endian_cpu::stream_state (o);

  o << " m32rbf-cpu";

  // XXX: no pins

  // XXX: Cheat by dumping the entire hardware struct in binary form.  That
  // means that this state image will not be restorable on a different
  // endianness host platform.
  string hw = string(reinterpret_cast<const char*>(& this->hardware), sizeof(this->hardware));
  o << " " << string2stream(hw);
}


void 
m32rbf_cpu::destream_state (istream& i)
{
  // call base class first
  cgen_bi_endian_cpu::destream_state (i);

  string key;
  i >> key;
  if (key != "m32rbf-cpu")
    {
      i.setstate (ios::badbit);
      return;
    }

  // XXX: no pins

  string hw;
  i >> stream2string(hw);
  if (hw.size() != sizeof(this->hardware))
    i.setstate (ios::badbit);
  else
    {
      const char* hwbin = hw.data();
      ::memcpy (reinterpret_cast<char*>(& this->hardware), hwbin, sizeof(this->hardware));
    }
}


// Debugger interface functions: return bitwise register images in
// "target byte order".

string
m32rbf_cpu::dbg_get_reg (host_int_4 reg)
{
  string attr;
  host_int_4 value;

  // This register number mapping must match gdb's: see gdb/config/m32r/tm-m32r.h
  if (reg < 16) // general purpose registers
    value = h_gr_get (reg);
  else if (reg == 16) // PSW
    value = h_cr_get (H_CR_PSW);
  else if (reg == 17)
    value = h_cr_get (H_CR_CBR);
  else if (reg == 18)
    value = h_cr_get (H_CR_SPI);
  else if (reg == 19)
    value = h_cr_get (H_CR_SPU);
  else if (reg == 20)
    value = h_cr_get (H_CR_BPC);
  else if (reg == 21)
    value = h_pc_get ();
  else if (reg == 22) // ACCL
    value = h_accum_get ();
  else if (reg == 23) // ACCH
    value = h_accum_get () >> 32;
  else
    value = 0;

  // change to "target endian"
  big_int_4 v = value;
  for (unsigned i=0; i<4; i++)
    attr += v.read_byte (i);

  return attr;
}


component::status 
m32rbf_cpu::dbg_set_reg (host_int_4 reg, const string& attr)
{
  // change from "target endian"
  big_int_4 v;
  for (unsigned i=0; i<4; i++)
    v.write_byte (i, attr[i]);
  host_int_4 value = v;

  // This register number mapping must match gdb's: see gdb/config/m32r/tm-m32r.h
  if (reg < 16) // general purpose registers
    h_gr_set (reg, value);
  else if (reg == 16) // PSW
    h_cr_set (H_CR_PSW, value);
  else if (reg == 17)
    h_cr_set (H_CR_CBR, value);
  else if (reg == 18)
    h_cr_set (H_CR_SPI, value);
  else if (reg == 19)
    h_cr_set (H_CR_SPU, value);
  else if (reg == 20)
    h_cr_set (H_CR_BPC, value);
  else if (reg == 21)
    h_pc_set (value);
  else if (reg == 22)
    {
      DI newvalue = h_accum_get ();
      SETLODI (newvalue, value);
      h_accum_set (newvalue);
    }
  else if (reg == 23) // ACCH
    {
      DI newvalue = h_accum_get ();
      SETHIDI (newvalue, value);
      h_accum_set (newvalue);
    }
  else
    ;

  return component::ok;
}
