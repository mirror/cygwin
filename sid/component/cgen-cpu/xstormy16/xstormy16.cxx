// xstormy16.cxx - Implementations of hand-written functions for the Xstormy16
// simulator. -*- C++ -*-

// Copyright (C) 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "xstormy16.h"

extern "C" {
#include "bfd.h"
#include "dis-asm.h"
}

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace xstormy16;

xstormy16_cpu::xstormy16_cpu ()
  :engine (32768) // XXX: tune size
{
  for (unsigned i = 0; i < 16; ++i)
    {
      string name = string ("GR") + make_numeric_attribute (i);
      SI* value = & this->hardware.h_gr[i];
      this->add_watchable_register (name, value);
    }
  
  // add syscall registers
  this->add_watchable_register (string("syscall-arg0"), &syscall_arg0);
  this->add_watchable_register (string("syscall-arg1"), &syscall_arg1);
  this->add_watchable_register (string("syscall-arg2"), &syscall_arg2);
  this->add_watchable_register (string("syscall-arg3"), &syscall_arg3);
  this->add_watchable_register (string("syscall-result"), &syscall_result);
  this->add_watchable_register (string("syscall-error"), &syscall_error);
  syscall_trap_num = 0;
  this->add_attribute (string("syscall-trap"), &syscall_trap_num, "setting");

  USI* value;
  value = & this->hardware.h_pc;
  this->add_watchable_register (string("pc"), value);
  
  this->create_gdb_register_attrs (17, "", & this->hardware.h_pc);
}

void
xstormy16_cpu::flush_icache ()
{
  this->engine.flush ();
}

void
xstormy16_cpu::reset()
{
  this->hardware.h_pc = 0;
  for (unsigned i = 0; i < 16; i++)
    this->hardware.h_gr[i] = 0;
}

void
xstormy16_cpu::invalid_insn (PCADDR pc)
{
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_invalid_insn, pc);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "xstormy16: unhandled invalid insn, pc=" << pc << endl;
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

  this->yield();
  throw cpu_exception ();
}

// Memory trap(/fault) handling.
void
xstormy16_cpu::memory_trap (const cpu_memory_fault& t)
{
  this->h_pc_set (t.pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_memory_fault, t.address);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "xstormy16: unhandled memory trap, pc=" << t.pc << endl;
      break;

    case cpu_trap_skip:
      {
	PCADDR pc = t.pc + 2;
	this->h_pc_set (pc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
}

// Stepper
void
xstormy16_cpu::step_insns ()
{
  bool found;
  
  while (true)
    {
      PCADDR pc = this->h_pc_get ();
      bool found;
      xstormy16_scache* sem = engine.find (pc, found);
      if (!found)
	{
	  try
	    {
	      // Fetch 16-bit pieces separately, so endianness
	      // conversions can be done on this chunk size.
	      UHI insn_hi = this->GETIMEMHI (pc, pc);
	      UHI insn_lo = this->GETIMEMHI (pc+2, pc+2);
	      USI insn = (insn_hi << 16) | insn_lo;
	      // BTW, this means that a 16-bit instruction will be
	      // shifted to the top 16 bits of `insn'.

	      // XXX: handle case of 16-bit insn placed at the very
	      // end of mapped memory (ie. causing unintentional
	      // SIGSEGV with the second GETIMEMHI call).

	      sem->decode (this, pc, insn, insn);
	    }
	  catch (cpu_memory_fault& t)
	    {
	      this->memory_trap (t);
	      break;
	    }
	}

      // Execute the instruction  -----------------------------------
      if (trace_result_p)
	{
          if (trace_counter_p)
	    this->trace_counter (pc);
	  if (trace_semantics_p)
	    this->begin_trace (pc, sem->idesc->insn_name);
          if (trace_disass_p)
	    this->disassemble (pc, print_insn_xstormy16,
                               bfd_target_elf_flavour,
                               bfd_arch_xstormy16,
                               BFD_ENDIAN_LITTLE, "xstormy16");
	}
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
      if (trace_result_p)
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

string
xstormy16_cpu::dbg_get_reg (host_int_4 reg)
{
  string attr;
  host_int_4 val;
  int size = reg < 16 ? 2 : 4;

  /* Bank zero regs */
  if (reg < 16)
    val = h_gr_get (reg);
  else if (reg == 16)
    val = h_pc_get ();
  else
    val = 0;

  // Change to "target endian".
  little_int_4 v = val;
  for (unsigned i = 0; i < size; i++)
    attr += v.read_byte (i);

  return attr;
}

component::status
xstormy16_cpu::dbg_set_reg (host_int_4 reg, const string& attr)
{
  // change from "target endian"
  little_int_4 v;
  int size = reg < 16 ? 2 : 4;
  for (unsigned i = 0; i < size; i++)
    v.write_byte (i, attr[i]);
  host_int_4 val = v;

  /* Bank zero regs */
  if (reg < 16)
    h_gr_set (reg, val);
  else if (reg == 16)
    h_pc_set (val);
  else
    return component::bad_value;

  return component::ok;
}

// C++ implementations of instructions follow here

// sys -- testsuite syscall functionality
void
xstormy16_cpu::syscall ()
{
#if 1 // testsuite support
  syscall_arg0 = this->hardware.h_gr[1];
  syscall_arg1 = this->hardware.h_gr[2];
  syscall_arg2 = this->hardware.h_gr[3];
  syscall_arg3 = this->hardware.h_gr[4];

  string attrValue = make_attribute(0);
  this->set_attribute_value ("syscall-error", attrValue);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_software, syscall_trap_num);
  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "hw-cpu-xstormy16: invalid insn handler unimplemented!" << endl;
      return;
      
    case cpu_trap_reissue:
      break;

    case cpu_trap_skip:
      this->h_pc_set (this->h_pc_get() + 2);
      /* fall-through */

    case cpu_trap_handled:
      {
	string errAttr = this->attribute_value ("syscall-error");
	string resultAttr = this->attribute_value ("syscall-result");
	
	host_int_4 errValue;
	host_int_4 resultValue;
	parse_attribute(errAttr, errValue);
	parse_attribute(resultAttr, resultValue);
	
	this->hardware.h_gr[0] = errValue;
	this->hardware.h_gr[1] = errValue != 0;
	this->hardware.h_gr[2] = resultValue;
      }
      return;
      
    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
#endif
}

// break - perform breakpoint
void
xstormy16_cpu::do_brk ()
{
#if 1 // gdb suport
  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_breakpoint, 0);
  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "hw-cpu-xstormy16: breakpoint handler unimplemented!" << endl;
      break;

    case cpu_trap_skip:
      this->h_pc_set (this->h_pc_get () + 2);
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
#endif
}

// XXX finish me
// CPU stops the execution of the instruction and stops oscillation.
// Status is released by the generation of a port 0, port 1 or base
// timer interrupt request, the CPU is transferred to halt mode and
// returns to normal operation when it accepts the interrupt.
// In HALTX mode, the base timer continues operating, otherwise it is
// identical to HALT mode.
void
xstormy16_cpu::do_hold ()
{
}

void
xstormy16_cpu::do_holdx ()
{
}

// XXX finish me
// CPU stops the execution of the instruction, the peripheral
// circuits continue operating.  Status is released when then
// CPU accepts a reset or interrupt signal.
void
xstormy16_cpu::do_halt ()
{
}

// Count the bits in (16bit) register `reg', modulo 2.
int
xstormy16_cpu::parity (int reg)
{
  int tmp;
  tmp = reg ^ (reg >> 8);
  tmp ^= tmp >> 4;
  tmp ^= tmp >> 2;
  tmp ^= tmp >> 1;
  return tmp & 1;
}
