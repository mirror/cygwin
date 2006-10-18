// common_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Common insn modelling functions for all 'sh' models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh2.h"
#include "sh2e.h"
#include "sh2a_fpu.h"
#include "sh2a_nofpu.h"
#include "sh3.h"
#include "sh3e.h"
#include "sh4.h"
#include "sh4_nofpu.h"
#include "sh4a.h"
#include "sh4a_nofpu.h"
#include "sh4al.h"
#include "sh5.h"

using namespace cgen;
using namespace sh;
using namespace sh2;
using namespace sh2e;
using namespace sh2a_fpu;
using namespace sh2a_nofpu;
using namespace sh3;
using namespace sh3e;
using namespace sh4_nofpu;
using namespace sh4;
using namespace sh4a_nofpu;
using namespace sh4a;
using namespace sh4al;
using namespace sh5;
using namespace sh5_compact;
using namespace sh5_media;

// --------------------------------------------------------------------------------
// Basic common model -- constructor
template <class BASE, class CPU, class IDESC, class SCACHE>
sh_common_model<BASE, CPU, IDESC, SCACHE>::sh_common_model (CPU* cpu) :
  BASE (cpu),
  cpu (cpu),
  current_stall (0),
  memory_access_busy (0),
  multiply_busy (0),
  fpu_busy (0),
  tbit_busy (0),
  pr_busy (0),
  save_total_latency (0)
{
  int n = num_gpr ();
  for (int i = 0; i < n; ++i)
    gpr_busy[i] = 0;
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model<BASE, CPU, IDESC, SCACHE>::set_pr_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (pr_busy < cycles)
      pr_busy = cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model<BASE, CPU, IDESC, SCACHE>::set_gpr_busy (INT reg, sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (gpr_busy[reg] < cycles)
      gpr_busy[reg] = cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model<BASE, CPU, IDESC, SCACHE>::add_memory_access_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    {
      // Memory access contends with the multiplier unit and vice-versa.
      // If the multiply unit us already busy, then this memory access will
      // occur after it is done. Model this by simply adding this latency
      // to that of the multiply unit.
      if (memory_access_busy < multiply_busy)
	memory_access_busy = multiply_busy;
      memory_access_busy += cycles;
    }
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model<BASE, CPU, IDESC, SCACHE>::add_multiply_busy (sid::signed_host_int_4 cycles)
{
  // Memory access contends with the multiplier unit and vice-versa.
  // If the memory access unit us already busy, then this multiply will
  // occur after it is done. Model this by simply adding this latency
  // to that of the memory access unit.
  if (cycles > 0)
    {
      if (multiply_busy < memory_access_busy)
	multiply_busy = memory_access_busy;
      multiply_busy += cycles;
    }
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model<BASE, CPU, IDESC, SCACHE>::set_fpu_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (fpu_busy < cycles)
      fpu_busy = cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model<BASE, CPU, IDESC, SCACHE>::set_current_stall (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (current_stall < cycles)
      current_stall = cycles;
}

// --------------------------------------------------------------------------------
// Model overrides
//

// This is called before each insn.
// Overrides the one defined by the BASE model.
// Returns the number of cycles which the cpu must stall
template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_before (CPU *current_cpu, SCACHE *sem)
{
  assert (sem);
  BASE::model_before (current_cpu, sem);

  // Has a stall already been identified?
  sid::host_int_4 stall = this->current_stall;

  // Check for an insn-fetch/memory-access conflict with this insn.
  stall = check_if_ma_conflict (stall);

  this->exec_cycles = 0;

  return stall;
} 

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_gr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (gpr_busy[usereg]);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_pr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  set_current_stall (pr_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_tbit_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  set_current_stall (tbit_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_multiply_result_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Insns which use the multiply result stall until the MA unit is available.
  // This latency has already been modelled, however, if the insn is aligned
  // on the insn_buffer, there will be one extra cycle
  // due to MA/insn-fetch contention.
  if (multiply_busy)
    {
      UINT extra_cycle = (pc_aligned_in_insn_buffer (cpu) == true);
      set_current_stall (extra_cycle);
    }

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_exec_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = BASE::model_u_exec_after (cpu, idesc, unit_num, referenced);
  this->exec_cycles += cycles;
  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_sx_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 0; // No effect on most machines
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_logic_b_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_ldcl_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_sts_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_lds_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // (1ULL << 0): The pc is the 1st element in inputs, outputs.
  // ??? can be cleaned up
  bool taken = referenced & (1ULL << 0);
  cpu->model_branch_taken (taken);
  if (taken)
    return BASE::model_u_branch_after (cpu, idesc, unit_num, referenced);

  return 1;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_jmp_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same as u-branch on most machines
  return this->model_u_branch_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_jsr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same as u_branch on most machines
  return this->model_u_branch_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_load_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The pr register will not be available until 1 cycle after the insn executes
  set_pr_busy (cycles + 1);

  return this->unit_cycles (idesc, BASE::UNIT_U_LOAD_PR);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_load_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The gpr will not be available until 1 cycle after the insn executes
  if (cycles >= memory_access_busy)
    set_gpr_busy (loadreg, cycles + 1);
  else
    set_gpr_busy (loadreg, memory_access_busy);

  return BASE::model_u_load_gr_after (cpu, idesc, unit_num, referenced, loadreg);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = BASE::model_u_memory_access_after (cpu, idesc, unit_num, referenced);

  // If this insn is not on a double insn word boundary, then there will be an
  // insn-fetch/memory-access conflict with a future insn. This adds 1 cycle.
  if (! pc_aligned_in_insn_buffer (cpu))
    ++cycles;

  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_multiply_result_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // There will MA/insn-fetch contention between this insn and a future insn.
  // The stall will be until the multiply unit is free plus the number of cycles used by
  // this unit.
  UINT cycles = BASE::model_u_use_multiply_result_after (cpu, idesc, unit_num, referenced);
  cycles += multiply_busy;
  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_multiply_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Mark the multiply unit as busy.
  UINT cycles = BASE::model_u_multiply_after (cpu, idesc, unit_num, referenced);
  add_multiply_busy (cycles);
  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 2.
  UINT extra_cycle = model_mac_after (cpu, 2);

  // Basic execution cycles for this insn.
  UINT cycles = BASE::model_u_macw_after (cpu, idesc, unit_num, referenced);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 4.
  UINT extra_cycle = model_mac_after (cpu, 4);

  // Basic execution cycles for this insn.
  UINT cycles = BASE::model_u_macl_after (cpu, idesc, unit_num, referenced);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 4.
  UINT extra_cycle = model_mac_after (cpu, 4);

  // Basic execution cycles for this insn.
  UINT cycles = BASE::model_u_dmul_after (cpu, idesc, unit_num, referenced);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 4.
  UINT extra_cycle = model_mac_after (cpu, 4);

  // Basic execution cycles for this insn.
  UINT cycles = BASE::model_u_mull_after (cpu, idesc, unit_num, referenced);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_mulsw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // There is one memory access slot for accessing the multiply unit.
  add_memory_access_busy (1);

  // Basic execution cycles for this insn.
  UINT cycles = BASE::model_u_mulsw_after (cpu, idesc, unit_num, referenced);

  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
void
sh_common_model<BASE, CPU, IDESC, SCACHE>::step_latency (sid::host_int_4 cycles)
{
#if 0 // currently does nothing
  // Call the base class.
  BASE::step_latency (cycles);
#endif
  // Compute latency which has incurred since we were last called.
  sid::host_int_8 new_total_latency = BASE::cpu->get_total_latency ();
  sid::host_int_8 latency = cycles + (new_total_latency - save_total_latency);
  save_total_latency = new_total_latency;

  // If there's no latency, then nothing to do.
  if (LIKELY (latency == 0))
    return;

  this->advance_latency (latency);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
void
sh_common_model<BASE, CPU, IDESC, SCACHE>::advance_latency (sid::host_int_4 latency)
{
  // Advance the hazard state information by the given number of cycles.
  int n = num_gpr ();
  for (int g = 0; g < n; ++g)
    MODEL_ADVANCE_LATENCY (gpr_busy[g], latency);

  MODEL_ADVANCE_LATENCY (pr_busy, latency);
  MODEL_ADVANCE_LATENCY (tbit_busy, latency);
  MODEL_ADVANCE_LATENCY (memory_access_busy, latency);
  MODEL_ADVANCE_LATENCY (multiply_busy, latency);
  MODEL_ADVANCE_LATENCY (fpu_busy, latency);
  MODEL_ADVANCE_LATENCY (current_stall, latency);
}

// ------------------------------------------------------------------------------------------------
// Other utility methods.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::unit_cycles (const IDESC *idesc, int unit)
{
  for (int u = 0; u < BASE::MAX_UNITS; ++u)
    {
      if (this->timing[idesc->sem_index].units[u].unit == unit)
	return this->timing[idesc->sem_index].units[u].done;
    }
  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
bool
sh_common_model<BASE, CPU, IDESC, SCACHE>::pc_aligned_in_insn_buffer (CPU *cpu)
{
  // Check whether the current insn is aligned at the beginning of the insn fetch
  // buffer.
  UDI pc = cpu->get_fetched_insn_pc ();
  host_int_4 insn_size = cpu->insn_size (pc);
  UDI mask = (2 * insn_size) - 1;
  return (pc & mask) == 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
sid::host_int_4
sh_common_model<BASE, CPU, IDESC, SCACHE>::check_if_ma_conflict (sid::host_int_4 stall)
{
  // Any insn which is aligned on the insn buffer boundary will experience
  // conflict with an active memory access (MA) unit.
  if (memory_access_busy && stall <= memory_access_busy &&
      pc_aligned_in_insn_buffer (cpu) == true)
    return memory_access_busy + 1;

  return stall;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model<BASE, CPU, IDESC, SCACHE>::model_mac_after (CPU *cpu, UINT multiply_latency)
{
  // If this insn *is* on a double insn word boundary, then there will be an
  // insn-fetch/memory-access conflict with a future insn. This adds 1 cycle.
  UINT extra_cycle = (pc_aligned_in_insn_buffer (cpu) == true);

  // There are two memory access slots. One of them can overlap with the processing
  // of a previous multiply.
  if (multiply_busy > memory_access_busy)
    add_memory_access_busy (1);
  else
    add_memory_access_busy (2 + extra_cycle);

  // Mark the multiply unit as busy for two cycles.
  add_multiply_busy (multiply_latency);

  return extra_cycle;
}

// --------------------------------------------------------------------------------
// Basic common model with floating point -- constructor
template <class BASE, class CPU, class IDESC, class SCACHE>
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::sh_common_model_with_fp (CPU* cpu) :
  sh_common_model<BASE, CPU, IDESC, SCACHE> (cpu),
  fpul_busy (0),
  fpscr_busy (0)
{
  int n = num_fpr ();
  for (int i = 0; i < n; ++i)
    fpr_busy[i] = 0;
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::set_fpul_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (fpul_busy < cycles)
      fpul_busy = cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::set_fpscr_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (fpscr_busy < cycles)
      fpscr_busy = cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::set_fpr_busy (INT reg, sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (fpr_busy[reg] < cycles)
      fpr_busy[reg] = cycles;
}

// --------------------------------------------------------------------------------
// Model overrides
//
template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  this->set_current_stall (this->fpu_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_maybe_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // For most machines, just use the u-fpu model
  return this->model_u_fpu_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_use_fr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  this->set_current_stall (fpr_busy[usereg]);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_use_fpul_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  this->set_current_stall (fpul_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_use_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  this->set_current_stall (this->fpscr_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_flds_fpul_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  this->model_u_maybe_fpu_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fdiv_before (CPU *cpu, const IDESC *idesc, int unit_num, INT loadreg)
{
  this->model_u_fpu_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fsqrt_before (CPU *cpu, const IDESC *idesc, int unit_num, INT loadreg)
{
  this->model_u_fpu_before (cpu, idesc, unit_num);
  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return this->model_u_exec_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Busy until loaded from memory
  set_fpscr_busy (this->memory_access_busy);

  return 0; // no additional latency
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fpu_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same pipeline as cpu memory access of most machines.
  return this->model_u_memory_access_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 1 additional cycle for cpu insns.
  UINT cycles = 1;
  this->exec_cycles += cycles;
  this->set_fpu_busy (cycles);
  set_fpscr_busy (cycles + 2);
  return 0; // No direct cycles used
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_maybe_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // For most machines, simply use the u-fpu model
  return this->model_u_fpu_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fcnv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 2 cycle latency for the fpu.
  UINT cycles = 2;
  this->set_fpu_busy (cycles);
  set_fpscr_busy (cycles + 2);
  return 0; // No direct cycles used
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_load_fr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The fpr will not be available until 1 cycle after the insn executes
  if (cycles >= this->memory_access_busy)
    set_fpr_busy (loadreg, cycles + 1);
  else
    set_fpr_busy (loadreg, this->memory_access_busy);

  return BASE::model_u_load_fr_after (cpu, idesc, unit_num, referenced, loadreg);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_load_dr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = this->model_u_load_fr_after (cpu, idesc, unit_num, referenced, loadreg);
  cycles += this->model_u_load_fr_after (cpu, idesc, unit_num, referenced, loadreg + 1);
  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_set_fr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The fpr will not be available until 1 cycle after the insn executes
  if (cycles >= this->fpu_busy + 2)
    set_fpr_busy (loadreg, cycles + 1);
  else
    set_fpr_busy (loadreg, this->fpu_busy + 2);

  return BASE::model_u_set_fr_after (cpu, idesc, unit_num, referenced, loadreg);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_set_fr_0_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = this->model_u_set_fr_after (cpu, idesc, unit_num, referenced, loadreg);
  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_set_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The fpul will not be available until 1 cycle after the insn executes
  if (cycles >= this->fpu_busy + 2)
    set_fpul_busy (cycles + 1);
  else
    set_fpul_busy (this->fpu_busy + 2);

  return BASE::model_u_set_fpul_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_load_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The fpul register will not be available until 1 cycle after the insn executes
  set_fpul_busy (cycles + 1);

  return BASE::model_u_load_fpul_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_flds_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = this->model_u_maybe_fpu_after (cpu, idesc, unit_num, referenced);
  cycles += this->model_u_load_fpul_after (cpu, idesc, unit_num, referenced);
  return cycles;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fpu_load_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // Same as u_load_gr on this machine.
  return sh_common_model<BASE, CPU, IDESC, SCACHE>::model_u_load_gr_after (cpu, idesc, unit_num, referenced, loadreg);
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fdiv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = 15;
  this->set_fpu_busy (cycles);
  this->set_fpr_busy (loadreg, cycles);
  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::model_u_fsqrt_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = 10; // sh2a value
  this->set_fpu_busy (cycles);
  this->set_fpr_busy (loadreg, cycles);
  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC, class SCACHE>
void
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::step_latency (sid::host_int_4 cycles)
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

template <class BASE, class CPU, class IDESC, class SCACHE>
void
sh_common_model_with_fp<BASE, CPU, IDESC, SCACHE>::advance_latency (sid::host_int_4 latency)
{
  // Call the base class -- updates save_total_latency
  sh_common_model<BASE, CPU, IDESC, SCACHE>::advance_latency (latency);

  // Advance the hazard state information by the given number of cycles.
  int n = num_fpr ();
  for (int f = 0; f < n; ++f)
    MODEL_ADVANCE_LATENCY (fpr_busy[f], latency);

  MODEL_ADVANCE_LATENCY (fpul_busy, latency);
  MODEL_ADVANCE_LATENCY (fpscr_busy, latency);
}

// --------------------------------------------------------------------------------
// Common model with floating point and vliw -- constructor
template <class BASE, class CPU, class IDESC, class SCACHE>
sh_common_model_with_vliw<BASE, CPU, IDESC, SCACHE>::sh_common_model_with_vliw (CPU* cpu) :
  BASE (cpu),
  shift_busy (0)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
inline void
sh_common_model_with_vliw<BASE, CPU, IDESC, SCACHE>::set_shift_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (shift_busy < cycles)
      shift_busy = cycles;
}

// --------------------------------------------------------------------------------
// Model overrides
//
template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_vliw<BASE, CPU, IDESC, SCACHE>::model_u_shift_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  this->set_current_stall (shift_busy);

  return 0;
}

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
sh_common_model_with_vliw<BASE, CPU, IDESC, SCACHE>::model_u_shift_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;

  // The shifter unit will be busy until after execution.
  set_shift_busy (cycles);

  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC, class SCACHE>
void
sh_common_model_with_vliw<BASE, CPU, IDESC, SCACHE>::step_latency (sid::host_int_4 cycles)
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

template <class BASE, class CPU, class IDESC, class SCACHE>
void
sh_common_model_with_vliw<BASE, CPU, IDESC, SCACHE>::advance_latency (sid::host_int_4 latency)
{
  BASE::advance_latency (latency);

  MODEL_ADVANCE_LATENCY (shift_busy, latency);
}

// Explicit instantiations
template class sh_common_model<sh2_sh2_model,sh2_cpu,sh2_idesc,sh2_scache>;
template class sh_common_model<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>;
template class sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>;
template class sh_common_model<sh3_sh3_model,sh3_cpu,sh3_idesc,sh3_scache>;
template class sh_common_model<sh3e_sh3e_model,sh3e_cpu,sh3e_idesc,sh3e_scache>;
template class sh_common_model<sh4_sh4_model,sh4_cpu,sh4_idesc,sh4_scache>;
template class sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>;
template class sh_common_model<sh4a_sh4a_model,sh4a_cpu,sh4a_idesc,sh4a_scache>;
template class sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>;
template class sh_common_model<sh4al_sh4al_model,sh4al_cpu,sh4al_idesc,sh4al_scache>;
template class sh_common_model<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache>;
template class sh_common_model<sh5_media_sh5_media_model,sh5_cpu,sh5_media_idesc,sh5_media_scache>;

template class sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>;
template class sh_common_model_with_fp<sh2e_sh2e_model,sh2e_cpu,sh2e_idesc,sh2e_scache>;
template class sh_common_model_with_fp<sh3e_sh3e_model,sh3e_cpu,sh3e_idesc,sh3e_scache>;
template class sh_common_model_with_fp<sh4_sh4_model,sh4_cpu,sh4_idesc,sh4_scache>;
template class sh_common_model_with_fp<sh4a_sh4a_model,sh4a_cpu,sh4a_idesc,sh4a_scache>;
template class sh_common_model_with_fp<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache>;
template class sh_common_model_with_fp<sh5_media_sh5_media_model,sh5_cpu,sh5_media_idesc,sh5_media_scache>;

template class sh_common_model_with_vliw<sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
					 sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>;
template class sh_common_model_with_vliw<sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
					 sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>;
