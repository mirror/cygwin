// sh2a_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh2a_model.h"
#include "sh2a_fpu.h"
#include "sh2a_nofpu.h"
#include "sh4.h"
#include "sh4_nofpu.h"
#include "sh4a.h"
#include "sh4a_nofpu.h"
#include "sh4al.h"

template <class BASE, class CPU, class IDESC>
sh2a_model<BASE,CPU,IDESC>::sh2a_model (CPU* cpu) :
  BASE (cpu),
  write_back_busy (0),
  gbr_busy (0),
  vbr_busy (0),
  current_branch_stall (0)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE, CPU, IDESC>::set_multiply_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->multiply_busy < cycles)
      this->multiply_busy = cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE,CPU,IDESC>::set_memory_access_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->memory_access_busy < cycles)
      this->memory_access_busy = cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE,CPU,IDESC>::add_memory_access_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    this->memory_access_busy += cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE, CPU, IDESC>::add_multiply_busy (sid::signed_host_int_4 cycles)
{
  // Simply add the cycles to the latency of the multiply unit.
  if (cycles > 0)
    this->multiply_busy += cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE,CPU,IDESC>::set_write_back_busy (sid::signed_host_int_4 cycles)
{
  // State from previous insns does not accumulate. Simply set the busy state.
  if (cycles > 0)
    this->write_back_busy = cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE,CPU,IDESC>::set_gbr_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->gbr_busy < cycles)
      this->gbr_busy = cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_model<BASE,CPU,IDESC>::set_vbr_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->vbr_busy < cycles)
      this->vbr_busy = cycles;
}

// --------------------------------------------------------------------------------
// Model overrides
//

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_memory_access_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // This insn must stall if the memory access unit is already busy.
  if (this->memory_access_busy)
    {
      this->set_current_stall (this->memory_access_busy);
      return 0;
    }

  // Save the total latency (before execution) so that it can be used to compute
  // any latency incurred during execution.
  memory_access_pre_execution_latency = cpu->get_total_latency ();
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE, CPU, IDESC>::model_u_use_multiply_result_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Insns which use the multiply result stall until the multiply unit is available.
  // The result is available during the last cycle of the multiplier execution.
  if (this->multiply_busy)
    {
      // LDS.L has a longer pipeline and can execute 1 cycle
      // earlier than other insns.
      if (insn_is_ldsl_mac (idesc) && this->multiply_busy >= 2)
	this->set_current_stall (this->multiply_busy - 2);
      else
	this->set_current_stall (this->multiply_busy - 1);
    }

  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE, CPU, IDESC>::model_u_write_back_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Only used by STS and STS.L. Stall until the multiply unit is completely free.
  if (write_back_busy)
    this->set_current_stall (this->multiply_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // There will be additional latency for accessing the memory itself.
  UINT latency = cpu->get_total_latency () - memory_access_pre_execution_latency;

  // The memory access unit will be busy for at least as long as the insn
  // executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (latency);
  return 0; // No contention with insn fetch!
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Cycles used by this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MACW);

  // The memory access unit will be busy for one cycle after the insn executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (1);

  // The multiply unit will not start until
  // after the insn cycles plus one more the the extra MA slot.
  this->set_multiply_busy (cycles + 1);

  // The multiply unit will be busy for 2 cycles.
  this->add_multiply_busy (2);
  
  // Just return the number of cycles used.
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Cycles used by this insn.
  UINT cycles = this->exec_cycles;

  // This insn actually uses one more cycle than obtained above.
  ++cycles;

  // The memory access unit will be busy for one cycle after the insn executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (1);

  // The multiply unit will not start until
  // after the insn cycles plus one more the the extra MA slot.
  this->set_multiply_busy (cycles + 1);

  // The multiply unit will be busy for 2 cycles.
  this->add_multiply_busy (2);
  
  // Just return the number of cycles used.
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Model the branch
  UINT cycles = BASE::model_u_branch_after (cpu, idesc, unit_num, referenced);

  if (cycles > 1)
    {
      // Branch destination stalls 3 cycles
      current_branch_stall = 3;
    }

  return cycles;
}

template <class BASE, class CPU, class IDESC>
void
sh2a_model<BASE,CPU,IDESC>::branch_stall ()
{
  this->set_current_stall (this->current_branch_stall);
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit  has a latency of 3 cycles.
  this->add_multiply_busy (3);

  // Cycles used by this insn.
  return 2;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_mulr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit  has a latency of 3 cycles.
  this->add_multiply_busy (3);

  // Cycles used by this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MULR);
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit  has a latency of 3 cycles.
  this->add_multiply_busy (3);

  // Cycles used by this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MULL);
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_multiply_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Some insns use fewer cycles than normal.
  UINT cycles;
  if (insn_is_mulsw (idesc))
    cycles = 1;
  else
    cycles = this->unit_cycles (idesc, BASE::UNIT_U_MULTIPLY);

  // Mark the multiply unit as busy.
  add_multiply_busy (cycles);

  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_use_multiply_result_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // No contention with MA or IF.
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_mulsw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Basic execution cycles for this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MULSW);
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE, CPU, IDESC>::model_u_mulr_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);
  // Basic execution cycles for this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MULR);

  // The gpr will not be available until the multiply unit finishes
  this->set_gpr_busy (loadreg, this->multiply_busy);

  // Write back will be busy for the next insn
  this->set_write_back_busy (cycles + 1);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
 // 3 cycles on this machine.
  this->exec_cycles += 3;
  return 3;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 3; // 3 cycles on this machine.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 1 cycle on this machine.
  this->exec_cycles += 1;
  return 1;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_load_gbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The gbr will not be available until 1 cycle after the insn executes
  set_gbr_busy (this->memory_access_busy);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_load_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The gbr will not be available until 1 cycle after the insn executes
  set_vbr_busy (this->memory_access_busy);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_load_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The mac register not be available until after the memory access.
  set_multiply_busy (this->memory_access_busy + 1);

  // Basic execution cycles for this insn.
  UINT cycles = this->exec_cycles;

  // Write back will be busy for the next insn
  this->set_write_back_busy (cycles + 1);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_set_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit will be busy for 2 cycles.
  add_multiply_busy (2);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_write_back_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Mark the multiply unit as busy.
  add_multiply_busy (1);

  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_model<BASE,CPU,IDESC>::model_u_trap_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 7; // 7 cycles on this machine
}

template <class BASE, class CPU, class IDESC>
void
sh2a_model<BASE,CPU,IDESC>::step_latency (sid::host_int_4 cycles)
{
  // Compute latency which has incurred since we were last called.
  sid::host_int_8 new_total_latency = BASE::cpu->get_total_latency ();
  sid::host_int_8 latency = cycles + (new_total_latency - this->save_total_latency);
  this->save_total_latency = new_total_latency;

  // If there's no latency, then nothing to do.
  if (LIKELY (latency == 0))
    return;

  this->advance_latency (latency);
}

template <class BASE, class CPU, class IDESC>
void
sh2a_model<BASE,CPU,IDESC>::advance_latency (sid::host_int_4 latency)
{
  BASE::advance_latency (latency);

  MODEL_ADVANCE_LATENCY (write_back_busy, latency);
  MODEL_ADVANCE_LATENCY (gbr_busy, latency);
  MODEL_ADVANCE_LATENCY (vbr_busy, latency);
  MODEL_ADVANCE_LATENCY (current_branch_stall, latency);
}

// ------------------------------------------------------------------------------------------------
// Other utility methods.
//
template <class BASE, class CPU, class IDESC>
sid::host_int_4
sh2a_model<BASE,CPU,IDESC>::check_if_ma_conflict (sid::host_int_4 stall)
{
  return stall; // No IF/MA conflicts
}

template <class BASE, class CPU, class IDESC>
bool
sh2a_model<BASE,CPU,IDESC>::parallel_possible (const IDESC *idesc1, const IDESC *idesc2)
{
  return true;
}

template <class BASE, class CPU, class IDESC>
bool
sh2a_model<BASE,CPU,IDESC>::uses_unit (const IDESC *idesc, int unit)
{
  for (int u = 0; u < BASE::MAX_UNITS; ++u)
    {
      if (this->timing[idesc->sem_index].units[u].unit == unit)
	return true;
    }
  return false;
}

// --------------------------------------------------------------------------------
// sh2a_fpu_model.
//
template <class BASE, class CPU, class IDESC>
sh2a_fpu_model<BASE,CPU,IDESC>::sh2a_fpu_model (CPU* cpu) :
  SH2A_FPU_MODEL_BASE (cpu),
  fpu_memory_access_busy (0)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC>
inline void
sh2a_fpu_model<BASE,CPU,IDESC>::set_fpu_memory_access_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->fpu_memory_access_busy < cycles)
      this->fpu_memory_access_busy = cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_fpu_model<BASE,CPU,IDESC>::add_fpu_memory_access_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    this->fpu_memory_access_busy += cycles;
}

template <class BASE, class CPU, class IDESC>
inline void
sh2a_fpu_model<BASE,CPU,IDESC>::set_tbit_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->tbit_busy < cycles)
      this->tbit_busy = cycles;
}

// --------------------------------------------------------------------------------
// Model overrides
//
template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_fpu_memory_access_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // This insn must stall if the fpu memory access unit is already busy.
  if (this->fpu_memory_access_busy)
    {
      this->set_current_stall (this->fpu_memory_access_busy);
      return 0;
    }

  // Save the total latency (before execution) so that it can be used to compute
  // any latency incurred during execution.
  this->memory_access_pre_execution_latency = cpu->get_total_latency ();
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_use_dr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT usereg)
{
  UINT cycles = this->model_u_use_fr_before (cpu, idesc, unit_num, usereg);
  cycles += this->model_u_use_fr_before (cpu, idesc, unit_num, usereg + 1);
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_use_fpul_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time. STS[.L] FPUL is able to access the result
  // 2 cycles early.
  if (this->insn_is_sts_fpul (idesc))
    {
      this->fpul_busy = this->fpul_busy > 2 ? this->fpul_busy - 2 : 0;
      this->fpu_busy = this->fpu_busy > 2 ? this->fpu_busy - 2 : 0;
    }
  else if (this->insn_is_stsl_fpul (idesc))
    {
      this->fpul_busy = this->fpul_busy > 1 ? this->fpul_busy - 1 : 0;
      this->fpu_busy = this->fpu_busy > 1 ? this->fpu_busy - 1 : 0;
    }
    
  return SH2A_FPU_MODEL_BASE::model_u_use_fpul_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_lds_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Must wait for fpu unit.
  this->set_current_stall (this->fpu_busy);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_sts_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Must wait for multiply result.
  this->set_current_stall (this->multiply_busy);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_fpu_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // There will be additional latency for accessing the memory itself.
  UINT latency = cpu->get_total_latency () - this->memory_access_pre_execution_latency;

  // Additional latency specified?
  latency += this->unit_cycles (idesc, SH2A_FPU_MODEL_BASE::UNIT_U_FPU_MEMORY_ACCESS);

  // The memory access unit will be busy for at least as long as the insn
  // executes.
  this->set_fpu_memory_access_busy (cycles);
  this->add_fpu_memory_access_busy (latency);
  return 0; // No contention with insn fetch!
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The fpu unit will be busy for 3 cycles.
  this->set_fpu_busy (3);

  // Basic execution cycles
  this->exec_cycles += 1;
  return 1;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The fpu unit will be busy for 3 cycles after loaded.
  this->set_fpu_busy (this->memory_access_busy + 3);

  return 0; // no additional latency.
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_flds_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 0; // No additional latency
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_load_fr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The fpr will not be available until 1 cycle after the insn executes
  if (cycles >= this->fpu_memory_access_busy)
    this->set_fpr_busy (loadreg, cycles + 1);
  else
    this->set_fpr_busy (loadreg, this->fpu_memory_access_busy);

  return this->unit_cycles (idesc, SH2A_FPU_MODEL_BASE::UNIT_U_LOAD_FR);
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_set_fr_0_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  return 0; // No additional latency
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_set_dr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = this->model_u_set_fr_after (cpu, idesc, unit_num, referenced, loadreg);
  cycles += this->model_u_set_fr_after (cpu, idesc, unit_num, referenced, loadreg + 1);
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_fpu_load_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The gpr will not be available until 1 cycle after the insn executes
  if (cycles >= fpu_memory_access_busy)
    this->set_gpr_busy (loadreg, cycles + 1);
  else
    this->set_gpr_busy (loadreg, fpu_memory_access_busy);

  return 0; // No direct cycles used
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_fdiv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = 11;
  this->set_fpu_busy (cycles);
  this->set_fpr_busy (loadreg, cycles);
  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC>
UINT
sh2a_fpu_model<BASE,CPU,IDESC>::model_u_fcmp_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // T-bit will be busy for 3 cycles.
  this->set_tbit_busy (3);

  return 0; // No additional latency
}

template <class BASE, class CPU, class IDESC>
void
sh2a_fpu_model<BASE,CPU,IDESC>::step_latency (sid::host_int_4 cycles)
{
  // Compute latency which has incurred since we were last called.
  sid::host_int_8 new_total_latency = SH2A_FPU_MODEL_BASE::cpu->get_total_latency ();
  sid::host_int_8 latency = cycles + (new_total_latency - this->save_total_latency);
  this->save_total_latency = new_total_latency;

  // If there's no latency, then nothing to do.
  if (LIKELY (latency == 0))
    return;

  this->advance_latency (latency);
}

template <class BASE, class CPU, class IDESC>
void
sh2a_fpu_model<BASE,CPU,IDESC>::advance_latency (sid::host_int_4 latency)
{
  SH2A_FPU_MODEL_BASE::advance_latency (latency);

  MODEL_ADVANCE_LATENCY (fpu_memory_access_busy, latency);
}

// Explicit instantiations
template class sh2a_model<
  sh_common_model_with_vliw<
    sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
    sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
  sh2a_nofpu_cpu,sh2a_nofpu_idesc>;

template class sh2a_model<
  sh_common_model_with_vliw<
    sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
    sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
  sh2a_fpu_cpu,sh2a_fpu_idesc>;
template class sh2a_fpu_model<
  sh_common_model_with_vliw<
    sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
    sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
  sh2a_fpu_cpu,sh2a_fpu_idesc>;

template class sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,sh4_nofpu_cpu,sh4_nofpu_idesc>;

template class sh2a_model<sh_common_model_with_fp<sh4_sh4_model,sh4_cpu,sh4_idesc,sh4_scache>,sh4_cpu,sh4_idesc>;
template class sh2a_fpu_model<sh_common_model_with_fp<sh4_sh4_model,sh4_cpu,sh4_idesc,sh4_scache>,sh4_cpu,sh4_idesc>;

template class sh2a_model<sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>,sh4a_nofpu_cpu,sh4a_nofpu_idesc>;

template class sh2a_model<sh_common_model_with_fp<sh4a_sh4a_model,sh4a_cpu,sh4a_idesc,sh4a_scache>,sh4a_cpu,sh4a_idesc>;
template class sh2a_fpu_model<sh_common_model_with_fp<sh4a_sh4a_model,sh4a_cpu,sh4a_idesc,sh4a_scache>,sh4a_cpu,sh4a_idesc>;

template class sh2a_model<sh_common_model<sh4al_sh4al_model,sh4al_cpu,sh4al_idesc,sh4al_scache>,sh4al_cpu,sh4al_idesc>;
