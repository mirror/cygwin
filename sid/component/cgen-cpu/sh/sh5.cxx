// sh5.cxx - Implementations of hand-written functions for the sh5
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh5.h"

using namespace sh5;

sh5_cpu::sh5_cpu () :
  SH5_CPU_BASE (this),
  engine (32768),
  model (this),
  compact_tick (0),
  media_tick (0)
{
  remove_attribute ("pc");
  this->add_watchable_register ("pc", this,
				& sh5_cpu::get_pc_attribute,
				& sh5_cpu::set_pc_attribute);
  remove_attribute ("pc-hi");
  this->add_watchable_register ("pc-hi", this,
				& sh5_cpu::get_pc_hi_attribute,
				& sh5_cpu::set_pc_hi_attribute);
}

void
sh5_cpu::decode_insn (PCADDR pc)
{
  // Call up to the base class if in compact mode
  if (compact_p ())
    {
      fetched_insn_is_compact = true;
      SH5_CPU_BASE::decode_insn (pc);
      return;
    }
  fetched_insn_is_compact = false;

  // Is there a compact insn pending? If so, don't
  // fetch this one.
  if (compact_insn_pending ())
    return;

  // Decode the insn  ----------------------------
  bool found;
  USI base_insn, entire_insn;

  this->fetched_insn = this->engine.find (pc, found);
  if (UNLIKELY (! found))
    {
      this->fetch_insn (pc, base_insn, entire_insn);
      this->fetched_insn->decode (this, pc, base_insn, entire_insn);
    }
  else if (UNLIKELY (this->trace_counter_p || this->final_insn_count_p))
    {
      // Must fetch the insn in order to model insn fetch latency.
      this->fetch_insn (pc, base_insn, entire_insn);
    }
}

void
sh5_cpu::fetch_insn (PCADDR pc, USI &base_insn, USI &entire_insn)
{
  // Call up to the base class if in compact mode
  if (compact_p ())
    {
      SH5_CPU_BASE::fetch_insn (pc, base_insn, entire_insn);
      return;
    }

  // 32 bit insns
  entire_insn = this->GETIMEMSI (pc, pc);
  base_insn = entire_insn;
}

void
sh5_cpu::execute_insn (sh5_compact_scache *sc)
{
  sc->idesc->execute (this, sc, this->compact_tick, this->compact_write_stacks);
}

void
sh5_cpu::execute_insn ()
{
  // Call up to the base class if in compact mode
  if (compact_p () || compact_insn_pending ())
    {
      SH5_CPU_BASE::execute_insn ();
      return;
    }

  this->fetched_insn->idesc->execute (this, this->fetched_insn, this->media_tick, this->media_write_stacks);
}

void
sh5_cpu::prefetch (PCADDR target)
{
  // Read from the target address. This will prime the insn buffer.
  // Read as HI, incase the target is a compact insn which is not
  // 4 byte aligned.
  // Discard any latency which results.
  sid::host_int_8 save_total_latency = this->get_total_latency ();
  this->GETIMEMHI (this->h_pc_get (), target & ~(PCADDR)1);
  this->set_total_latency (save_total_latency);
}

DI
sh5_cpu::sh64_nsb (DI rm)
{
  int result = 0, count;
  UDI source = (UDI) rm;

  if ((source >> 63))
    source = ~source;
  source <<= 1;

  for (count = 32; count; count >>= 1)
    {
      UDI newval = source << count;

      if ((newval >> count) == source)
	{
	  result |= count;
	  source = newval;
	}
    }
  
  return result;
}

void
sh5_cpu::sh64_trapa (DI rm, PCADDR pc)
{
  DI trapnum = rm & 0xff;
  if (trapnum != this->syscall_trap_num)
    return; // for now

  syscall_arg0 = this->h_gr_get (2);
  syscall_arg1 = this->h_gr_get (3);
  syscall_arg2 = this->h_gr_get (4);
  syscall_arg3 = this->h_gr_get (5);

  cpu_trap_disposition whatnext = 
    this->signal_trap (cpu_trap_software, syscall_trap_num);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      invalid_insn (pc);
      return;

    case cpu_trap_reissue:
      break;

    case cpu_trap_skip:
      // Fall thu
    case cpu_trap_handled:
      // must get syscall results and place them in current context registers
      string err_attr = attribute_value ("syscall-error");
      string result_attr = attribute_value ("syscall-result");
      
      host_int_4 err_num, result_num;
      parse_attribute(err_attr, err_num);
      parse_attribute(result_attr, result_num);

      // return code in $2
      this->h_gr_set (2, result_num);

      // errno in ???
      // this->h_gr_set (1, err_num);
      return;
    }

  this->yield();
  throw cpu_exception ();
}

extern int
print_insn_sh64x_media (bfd_vma memaddr, struct disassemble_info *info);

asection bfd_abs_section;
asection bfd_und_section;

void
sh5_cpu::trace_counter (PCADDR pc)
{
  // Call up to the base class if in compact mode
  if (compact_p () || compact_insn_pending ())
    {
      SH5_CPU_BASE::trace_counter (pc);
      return;
    }

  // Call up the heirarchy past the vliw implementation.
  SH5_CPU_NON_VLIW_BASE::trace_counter (pc);
}

void
sh5_cpu::disassemble (PCADDR pc)
{
  // Call up to the base class if in compact mode
  if (compact_p () || compact_insn_pending ())
    {
      SH5_CPU_BASE::disassemble (pc);
      return;
    }

  static CGEN_BITSET *isas = NULL;
  if (! isas)
    isas = cgen_bitset_create (ISA_MAX);
  cgen_bitset_clear (isas);
  cgen_bitset_add (isas, ISA_MEDIA);
  cgen_bi_endian_cpu::disassemble (pc, print_insn_sh64x_media,
				   bfd_target_elf_flavour,
				   bfd_arch_sh,
				   (current_endianness() == endian_little ?
				    BFD_ENDIAN_LITTLE : BFD_ENDIAN_BIG),
				   "sh64", isas, bfd_mach_sh5);
}

void
sh5_cpu::cg_profile_jump (sid::host_int_4 caller, sid::host_int_4 callee)
{
  callee &= ~(sid::host_int_4)1;
  if (return_addresses.empty () || ! find_return_address (callee))
    {
      return_addresses.push_back (return_address (caller));
      SH5_CPU_BASE::cg_profile_jump (caller, callee);
      return;
    }

  // This is a function return. Profile it.
  this->notify_ret (callee);
}

SF
sh5_cpu::sh64_fiprs (unsigned g, unsigned h)
{
  SF temp = sh64_fmuls (h_fr_get (g), h_fr_get (h));
  temp = sh64_fadds (temp, sh64_fmuls (h_fr_get (g + 1), h_fr_get (h + 1)));
  temp = sh64_fadds (temp, sh64_fmuls (h_fr_get (g + 2), h_fr_get (h + 2)));
  temp = sh64_fadds (temp, sh64_fmuls (h_fr_get (g + 3), h_fr_get (h + 3)));
  return temp;
}

void
sh5_cpu::sh64_fldp (PCADDR pc, DI rm, DI rn, unsigned f)
{
  h_fr_set (f,     GETMEMSF (pc, rm + rn));
  h_fr_set (f + 1, GETMEMSF (pc, rm + rn + 4));
}

void
sh5_cpu::sh64_fstp (PCADDR pc, DI rm, DI rn, unsigned f)
{
  SETMEMSF (pc, rm + rn,     h_fr_get (f));
  SETMEMSF (pc, rm + rn + 4, h_fr_get (f + 1));
}

void
sh5_cpu::model_insn_before ()
{
  return fetched_insn_is_compact || compact_insn_pending () ?
    SH5_CPU_BASE::model_insn_before () :
    this->model.model_insn_before (true);
}

void
sh5_cpu::model_step_latency (sid::host_int_4 cycles)
{
  return fetched_insn_is_compact || compact_insn_pending () ?
    SH5_CPU_BASE::model_step_latency (cycles) :
    this->model.step_latency (cycles);
}

UINT
sh5_cpu::model_before (sh5_compact_scache *sc)
{
  if (fetched_insn_is_compact)
    return SH5_CPU_BASE::model_before (sc);

  if (compact_insn_pending ())
    return SH5_CPU_BASE::model_before (this->fetched_insn);

  UINT stall = this->model.model_before (this, this->fetched_insn);
  return stall;
}

UINT
sh5_cpu::model_after (sh5_compact_scache *sc)
{
  if (fetched_insn_is_compact)
    return SH5_CPU_BASE::model_after (sc);
	
  if (compact_insn_pending ())
    return SH5_CPU_BASE::model_after (this->fetched_insn);

  return this->model.model_after (this, this->fetched_insn);
}

model_status
sh5_cpu::model_insn_after (UINT cycles, PCADDR &pc)
{
  if (fetched_insn_is_compact || compact_insn_pending ())
    return SH5_CPU_BASE::model_insn_after (cycles, pc);

  this->model.model_insn_after (true, cycles);
  return model_ok;
}
