// sh4_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh4_model.h"
#include "sh4_nofpu.h"

using namespace sh4;
using namespace sh4_nofpu;

template <class BASE, class CPU, class IDESC>
sh4_model<BASE, CPU,IDESC>::sh4_model (CPU* cpu) :
  BASE (cpu),
  f1_busy (0),
  sx_busy (0)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC>
inline void
sh4_model<BASE, CPU, IDESC>::add_fpu_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    this->fpu_busy += cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh4_model<BASE, CPU, IDESC>::set_f1_busy (sid::signed_host_int_4 cycles)
{
  // The f1 unit conflicts with the fpu unit, but not with itself
  if (cycles > 0)
    this->f1_busy = this->fpu_busy + cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh4_model<BASE, CPU, IDESC>::set_sx_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    this->sx_busy = cycles;
}

// --------------------------------------------------------------------------------
// Model overrides
//
template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_write_back_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // No effect on this machine.
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  // The fpu unit conflicts with itself and with the f1 unit.
  this->set_current_stall (this->fpu_busy);
  this->set_current_stall (this->f1_busy);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_sx_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  this->set_current_stall (this->sx_busy);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_logic_b_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_tas_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldc_gbr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldc_sr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldcl_vbr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldcl_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_stc_vbr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_lds_pr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_sts_pr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_jsr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Uses the sx unit..
  this->model_u_sx_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_set_mac_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Must wait for the fpu unit and f1 unit
  return this->model_u_fpu_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_load_mac_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Must wait for the fpu unit and f1 unit
  return this->model_u_fpu_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_dmul_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Must wait for the fpu unit, but not the f1 unit
  this->set_current_stall (this->fpu_busy);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_mull_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as dmul
  return this->model_u_dmul_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_mulsw_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as dmul
  return this->model_u_dmul_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_macw_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as dmul
  return this->model_u_dmul_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_macl_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as dmul
  return this->model_u_dmul_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ocb_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Wait for memory access
  return this->model_u_memory_access_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_sx_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_SX);
  this->set_sx_busy (cycles);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_logic_b_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 4 cycles on this machine.
  this->exec_cycles += 4;
  this->set_sx_busy (4);
  return 4;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 5 cycles on this machine.
  this->exec_cycles += 5;
  this->set_sx_busy (5);
  return 5;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldc_gbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  this->set_sx_busy (3);
  return 3;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  this->set_sx_busy (4);
  return 4;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldcl_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 1 cycle on this machine.
  this->exec_cycles += 1;
  // SX busy for 3 cycles
  this->set_sx_busy (3);
  return 1;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_LDCL);

  // 1 cycle on this machine.
  this->exec_cycles += cycles;

  // SX busy for the given number of cycles.
  this->set_sx_busy (cycles);

  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_stc_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 2 cycles on this machine.
  this->exec_cycles += 2;
  this->set_sx_busy (2);
  return 2;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_lds_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  this->exec_cycles += 2;
  this->set_sx_busy (3); // one extra cycle
  return 2;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_sts_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 2 cycles on this machine.
  this->exec_cycles += 2;
  this->set_sx_busy (2);
  return 2;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_load_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = 2;

  // The pr register will not be available until 1 cycle after the insn executes
  this->set_pr_busy (cycles + 1);

  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_set_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The fpu unit will be busy for 3 cycles.
  this->add_fpu_busy (3);

  // The multiply unit will be busy for 4 cycles.
  this->add_multiply_busy (4);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_load_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The fpu unit will be busy for 1 cycles after the memory access.
  this->add_fpu_busy (this->memory_access_busy + 1);

  // The multiply unit will be busy for 3 cycles after the memory access.
  this->add_multiply_busy (this->memory_access_busy + 3);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_write_back_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // No effect on this machine.
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Basic execution cycles for this insn
  UINT cycles = 2;

  // The f1 unit has a latency of an additional 2 cycles.
  this->set_f1_busy (cycles + 2);

  // The multiply unit has a latency of an additional 2 cycles.
  this->set_multiply_busy (this->fpu_busy + 2);

  // Cycles used by this insn.
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same as dmul
  return this->model_u_dmul_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_mulsw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Basic execution cycles for this insn
  UINT cycles = 2;

  // The f1 unit has a latency of an additional 2 cycles.
  this->set_f1_busy (cycles + 2);

  // The multiply unit will be busy as well.
  // The u-multiply unit will top up the latency by 2 more cycles.
  this->set_multiply_busy (this->f1_busy);

  // Cycles used by this insn.
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same as dmul
  return this->model_u_dmul_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same as dmul
  return this->model_u_dmul_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU,IDESC>::model_u_ocb_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = 1;

  // The number of memory accesses
  UINT latency = this->unit_cycles (idesc, BASE::UNIT_U_OCB);

  // There will be additional latency for accessing the memory itself.
  latency += cpu->get_total_latency () - this->memory_access_pre_execution_latency;

  // The memory access unit will be busy for at least as long as the insn
  // executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (latency);
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Model the branch
  UINT cycles = BASE::model_u_branch_after (cpu, idesc, unit_num, referenced);

  if (cycles > 1)
    {
      // One fewer cycles than specified for branches taken.
      cycles -= 1;
      // Branch destination stalls 2 cycles
      this->current_branch_stall = 2;
    }

  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4_model<BASE, CPU, IDESC>::model_u_jsr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  this->set_sx_busy (3);
  // Same as u_branch otherwise.
  return this->model_u_branch_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
void
sh4_model<BASE, CPU,IDESC>::step_latency (sid::host_int_4 cycles)
{
  // Compute latency which has incurred since we were last called.
  sid::host_int_8 new_total_latency = this->cpu->get_total_latency ();
  sid::host_int_8 latency = cycles + (new_total_latency - this->save_total_latency);
  this->save_total_latency = new_total_latency;

  // If there's no latency, then nothing to do.
  if (LIKELY (latency == 0))
    return;

  this->advance_latency (latency);
}

template <class BASE, class CPU, class IDESC>
void
sh4_model<BASE, CPU,IDESC>::advance_latency (sid::host_int_4 latency)
{
  BASE::advance_latency (latency);

  MODEL_ADVANCE_LATENCY (sx_busy, latency);
  MODEL_ADVANCE_LATENCY (f1_busy, latency);
}

// --------------------------------------------------------------------------------
// sh4_fpu_model.
//
template <class CPU, class IDESC>
sh4_fpu_model<CPU,IDESC>::sh4_fpu_model (CPU* cpu) :
  SH4_FPU_MODEL_BASE (cpu)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
// ... none right now

// --------------------------------------------------------------------------------
// Model overrides
//
template <class CPU, class IDESC>
UINT
sh4_fpu_model<CPU, IDESC>::model_u_maybe_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Insns using this unit do not use the fpu on this machine.
  return 0;
}

template <class CPU, class IDESC>
UINT
sh4_fpu_model<CPU, IDESC>::model_u_maybe_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Insns using this unit do not use the fpu on this machine.
  return 0;
}

template <class CPU, class IDESC>
UINT
sh4_fpu_model<CPU,IDESC>::model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The fpu unit will be busy for 4 cycles.
  this->set_fpu_busy (4);

  // Basic execution cycles
  this->exec_cycles += 1;
  return 1;
}

template <class CPU, class IDESC>
UINT
sh4_fpu_model<CPU,IDESC>::model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The fpu unit will be busy for 4 cycles after loaded.
  this->set_fpu_busy (this->memory_access_busy + 4);

  return 0; // no additional latency.
}

// Explicit instantiations
template class sh4_model<sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,
				    sh4_nofpu_cpu,sh4_nofpu_idesc>,
			 sh4_nofpu_cpu,sh4_nofpu_idesc>;
// NOTE: Need not be templates if never inherited from.
template class sh4_fpu_model<sh4_cpu,sh4_idesc>;
