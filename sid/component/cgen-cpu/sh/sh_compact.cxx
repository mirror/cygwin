// sh-compact.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh_compact.h"
#include "sh2a_model.h"
#include "sh3_model.h"
#include "sh4_model.h"
#include "sh4a_model.h"
#include "sh4al_model.h"

using namespace sh_compact;

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::sh_compact_cpu (CPU *cpu) :
  sh_cpu_impl<CGEN_CPU> (),
  thisp (cpu),
  engine (32768),
  model (cpu),
  dcix (0),
  drix (0)
{
  UDI* value;
  value = & this->hardware.h_pc;
  this->add_watchable_register ("pc", value);
  this->add_attribute_ro_value ("pc-hi", 0);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::reset()
{
  sh_cpu_impl<CGEN_CPU>::reset ();
  this->h_vbr_set (0);
}

// Stepper
template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::step_insns ()
{
  for (;;)
    {
      PCADDR pc = this->h_pc_get ();
      
      sem_status s;
      try 
	{
	  // Call down to VLIW or non-VLIW steppers
	  s = this->step_one_insn (pc);
	}
      catch (cpu_memory_fault& t)
        {
          this->memory_trap (t);
          break;
        }
      catch (cpu_exception& t)
        {
           this->yield ();
        }
      catch (fp::error& fe)
        {
	  int status = fe;
	  this->fpu_exception (pc, status);
	  if (status == 0) // no exception
	    this->h_pc_set (pc + 2);
	  else
	    this->h_pc_set (pc);
        }

      // Check to see if we're stalled
      if (LIKELY (s != SEM_STATUS_STALLED))
	{
	  if (UNLIKELY (this->trace_counter_p || this->trace_semantics_p
			|| this->trace_disass_p || this->trace_result_p))
	    this->end_trace ();
        
	  // Execute writeback
	  try {
	    write_stacks_writeback ();
	  }
	  catch (cpu_memory_fault& t)
	    {
	      this->memory_trap (t);
	    }
	  catch (cpu_exception& t)
	    {
	      this->yield ();
	    }

	  // move ahead thru circular pipeline
	  update_tick ();

	  // Do post-instruction processing  ----------------------------
	  if (this->enable_step_trap_p) 
	    this->signal_trap (sidutil::cpu_trap_stepped);
	  this->triggerpoint_manager.check_and_dispatch ();

	  // test for exit condition
	  if (this->stop_after_insns_p (1))
	    break;
	} // Not stalled
    } // loop over insns
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
sem_status
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::step_one_insn (PCADDR pc)
{
  // Decode the insn  ----------------------------
  this->fetched_insn_pc = pc;
  this->decode_insn (pc);

  // Pre execution processing ----------------------------
  bool model_enabled_p;
  if (UNLIKELY (this->final_insn_count_p || this->trace_counter_p))
    {
      model_enabled_p = true;

      // This is what model_insn_before boils down to for this port.
      this->model.step_latency ();

      // See if we're stalled.
      UINT stall = this->model.model_before (thisp, this->fetched_insn);
      if (UNLIKELY (stall))
	{
	  this->update_total_latency (stall);
	  this->model.step_latency ();
	  return SEM_STATUS_STALLED;
	}

      if (UNLIKELY (this->trace_counter_p))
	this->trace_counter (pc);
    }
  else
    model_enabled_p = false;

  if (UNLIKELY (this->trace_disass_p))
    this->disassemble (pc);

  // Run the insn  ----------------------------
  this->execute_insn ();

  // Post execution processing ----------------------------
  if (UNLIKELY (model_enabled_p))
    {
      sid::host_int_4 cycles = this->model.model_after (thisp, this->fetched_insn);
      // This is what model_insn_after boils down to for this port.
      this->model.step_cycles (cycles);
    }

  return SEM_STATUS_NORMAL;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::decode_insn (PCADDR pc)
{
  // Decode the insn  ----------------------------
  bool found;
  USI base_insn, entire_insn;

  fetched_insn = this->engine.find (pc, found);
  if (UNLIKELY (! found))
    {
      this->fetch_insn (pc, base_insn, entire_insn);
      fetched_insn->decode (thisp, pc, base_insn, entire_insn);
    }
  else if (UNLIKELY (this->final_insn_count_p || this->trace_counter_p))
    {
      // Must fetch the insn in order to model insn fetch latency.
      this->fetch_insn (pc, base_insn, entire_insn);
    }
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::fetch_insn (PCADDR pc, USI &base_insn, USI &entire_insn)
{
  // 16 bit insns.
  base_insn = this->GETIMEMHI (pc, pc) << 16;
  entire_insn = base_insn;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::sh64_compact_trapa (UQI trapnum, PCADDR pc)
{
  if (trapnum != this->syscall_trap_num)
    return;

  // Get the syscall arguments
  bool sh5_abi_p = this->mach_sh5_p ();
  this->syscall_arg0 = this->h_gr_get (sh5_abi_p ? 2 : 4);
  this->syscall_arg1 = this->h_gr_get (sh5_abi_p ? 3 : 5);
  this->syscall_arg2 = this->h_gr_get (sh5_abi_p ? 4 : 6);
  this->syscall_arg3 = this->h_gr_get (sh5_abi_p ? 5 : 7);

  cpu_trap_disposition whatnext = 
    this->signal_trap (cpu_trap_software, this->syscall_trap_num);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      this->invalid_insn (pc);
      return;

    case cpu_trap_reissue:
      break;

    case cpu_trap_skip:
      // fall thru
    case cpu_trap_handled:
      // must get syscall results and place them in current context registers
      string err_attr = this->attribute_value ("syscall-error");
      string result_attr = this->attribute_value ("syscall-result");
      
      host_int_4 err_num, result_num;
      parse_attribute(err_attr, err_num);
      parse_attribute(result_attr, result_num);

      // return code in $0
      this->h_gr_set (sh5_abi_p ? 2 : 0, result_num);

      if (! sh5_abi_p)
	{
	  // errno in $1
	  this->h_gr_set (1, err_num);
	}

      return;
    }

  this->yield();
  throw cpu_exception ();
}

extern int
print_insn_sh (bfd_vma memaddr, struct disassemble_info *info);

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::disassemble (PCADDR pc)
{
  static CGEN_BITSET *isas = NULL;
  if (! isas)
    isas = cgen_bitset_create (ISA_MAX);
  cgen_bitset_clear (isas);
  cgen_bitset_add (isas, ISA_COMPACT);
  cgen_bi_endian_cpu::disassemble (pc, print_insn_sh,
				   bfd_target_elf_flavour,
				   bfd_arch_sh,
				   (this->current_endianness() == endian_little ?
				    BFD_ENDIAN_LITTLE : BFD_ENDIAN_BIG),
				   "sh", isas, this->bfd_machine ());
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::cg_profile (sid::host_int_4 caller, sid::host_int_4 callee)
{
  callee &= ~(sid::host_int_4)1;
  return_addresses.push_back (return_address (caller));
  sh_cpu_impl<CGEN_CPU>::cg_profile (caller, callee);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::notify_ret (sid::host_int_4 returnee)
{
  returnee &= ~(sid::host_int_4)1;
  if (find_return_address (returnee))
    {
      sid::host_int_4 addr;
      do
	{
	  addr = return_addresses.back ();
	  return_addresses.pop_back ();
	}
      while (addr != returnee);
    }

  sh_cpu_impl<CGEN_CPU>::notify_ret (returnee);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
bool
sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::find_return_address (sid::host_int_4 addr)
{
  for (vector <sid::host_int_4>::const_iterator i = return_addresses.begin();
       i != return_addresses.end (); ++i)
    if (*i == addr)
      return true;

  return false;
}

// Explicit instantiations
template class sh_compact_cpu<sh2_cpu,sh2_cpu_cgen,sh2_idesc,sh2_scache,
			      sh_common_model<sh2_sh2_model,sh2_cpu,sh2_idesc,sh2_scache> >;
template class sh_compact_cpu<sh2e_cpu,sh2e_cpu_cgen,sh2e_idesc,sh2e_scache,
			      sh_common_model_with_fp<sh2e_sh2e_model,sh2e_cpu,sh2e_idesc,sh2e_scache> >;
template class sh_compact_cpu<sh2a_fpu_cpu,sh2a_fpu_cpu_cgen,sh2a_fpu_idesc,sh2a_fpu_scache,
			      sh2a_fpu_model<
                                sh_common_model_with_vliw<
                                  sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
                                  sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
                                sh2a_fpu_cpu,sh2a_fpu_idesc> >;
template class sh_compact_cpu<sh2a_nofpu_cpu,sh2a_nofpu_cpu_cgen,sh2a_nofpu_idesc,sh2a_nofpu_scache,
			      sh2a_model<
                                sh_common_model_with_vliw<
                                  sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
                                  sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
                                sh2a_nofpu_cpu,sh2a_nofpu_idesc> >;
template class sh_compact_cpu<sh3_cpu,sh3_cpu_cgen,sh3_idesc,sh3_scache,
			      sh3_model<sh_common_model<sh3_sh3_model,sh3_cpu,sh3_idesc,sh3_scache>,sh3_cpu,sh3_idesc> >;
template class sh_compact_cpu<sh3e_cpu,sh3e_cpu_cgen,sh3e_idesc,sh3e_scache,
			      sh3e_model<
                                sh_common_model_with_fp<sh3e_sh3e_model,sh3e_cpu,sh3e_idesc,sh3e_scache>,
                                sh3e_cpu,sh3e_idesc> >;
template class sh_compact_cpu<sh4_nofpu_cpu,sh4_nofpu_cpu_cgen,sh4_nofpu_idesc,sh4_nofpu_scache,
			      sh4_model<sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,
						   sh4_nofpu_cpu,sh4_nofpu_idesc>,
					sh4_nofpu_cpu,sh4_nofpu_idesc> >;
template class sh_compact_cpu<sh4_cpu,sh4_cpu_cgen,sh4_idesc,sh4_scache,sh4_fpu_model<sh4_cpu,sh4_idesc> >;
template class sh_compact_cpu<sh4a_nofpu_cpu,sh4a_nofpu_cpu_cgen,sh4a_nofpu_idesc,sh4a_nofpu_scache,
			      sh4a_model<sh2a_model<sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>,
						    sh4a_nofpu_cpu,sh4a_nofpu_idesc>,
					 sh4a_nofpu_cpu,sh4a_nofpu_idesc> >;
template class sh_compact_cpu<sh4a_cpu,sh4a_cpu_cgen,sh4a_idesc,sh4a_scache,sh4a_fpu_model<sh4a_cpu,sh4a_idesc> >;
template class sh_compact_cpu<sh4al_cpu,sh4al_cpu_cgen,sh4al_idesc,sh4al_scache,sh4al_model>;
template class sh_compact_cpu<sh5_cpu,sh5_cpu_cgen,sh5_compact_idesc,sh5_compact_scache,
			      sh_common_model_with_fp<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache> >;
