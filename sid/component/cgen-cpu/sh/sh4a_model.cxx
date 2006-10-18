// sh4a_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh4a_model.h"
#include "sh4a_nofpu.h"
#include "sh4al.h"

using namespace sh4a;
using namespace sh4a_nofpu;

template <class BASE, class CPU, class IDESC>
sh4a_model<BASE, CPU,IDESC>::sh4a_model (CPU* cpu) :
  BASE (cpu)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//

// --------------------------------------------------------------------------------
// Model overrides
//
template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU, IDESC>::model_u_write_back_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU,IDESC>::model_u_multiply_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  this->set_current_stall (this->multiply_busy);
  return 0;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU,IDESC>::model_u_dmul_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as u-multiply
  return this->model_u_multiply_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU,IDESC>::model_u_mull_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as u-multiply
  return this->model_u_multiply_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU,IDESC>::model_u_set_mac_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Same as u-multiply
  return this->model_u_multiply_before (cpu, idesc, unit_num);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Model the branch
  UINT cycles = BASE::model_u_branch_after (cpu, idesc, unit_num, referenced);

  // Branch destination stalls 3 cycles
  if (cycles > 1)
    this->current_branch_stall = 3;

  return 1; // 1 basic cycle
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_jmp_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Same as u-jsr on this machine.
  return this->model_u_jsr_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_jsr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Model the branch
  UINT cycles = BASE::model_u_branch_after (cpu, idesc, unit_num, referenced);

  // Branch destination stalls 4 cycles
  if (cycles > 1)
    this->current_branch_stall = 4;

  return 1; // 1 basic cycle
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_trap_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 14; // 14 cycles on this machine
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Return the specified number of cycles.
  return this->unit_cycles (idesc, BASE::UNIT_U_TAS);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_ocb_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 1; // 1 cycle on this machine
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 7; // 7 cycles on this machine.
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU, IDESC>::model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = 1;
  this->exec_cycles += cycles;
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE, CPU, IDESC>::model_u_ldcl_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return this->model_u_ldcl_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_load_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_write_back_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 0; // no direct cycles used
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit  has a latency of 3 cycles.
  this->add_multiply_busy (3);

  // Cycles used by this insn.
  return 1;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit  has a latency of 3 cycles.
  this->add_multiply_busy (3);

  // Cycles used by this insn.
  return 1;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_set_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The multiply unit will be busy for 1 cycles.
  this->add_multiply_busy (1);

  return 0; // No direct cycles used.
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Cycles used by this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MACW);

  // The memory access unit will be busy for one cycle after the insn executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (1);

  // The multiply unit will not start until
  // after the memory access.
  this->set_multiply_busy (cycles + 1);

  // The multiply unit will be busy for 1 additional cycle.
  this->add_multiply_busy (1);
  
  // Just return the number of cycles used.
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Cycles used by this insn.
  UINT cycles = this->exec_cycles;

  // The memory access unit will be busy for one cycle after the insn executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (1);

  // The multiply unit will not start until
  // after the memory access.
  this->set_multiply_busy (cycles + 1);

  // The multiply unit will be busy for 2 additional cycles.
  this->add_multiply_busy (2);
  
  // Just return the number of cycles used.
  return cycles;
}

template <class BASE, class CPU, class IDESC>
UINT
sh4a_model<BASE,CPU,IDESC>::model_u_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // The latency of the insn itself.
  UINT cycles = this->exec_cycles;
  // Any additional specified latency
  cycles += this->unit_cycles (idesc, BASE::UNIT_U_MEMORY_ACCESS);

  // There will be additional latency for accessing the memory itself.
  UINT latency = cpu->get_total_latency () - this->memory_access_pre_execution_latency;

  // The memory access unit will be busy for at least as long as the insn
  // executes.
  this->set_memory_access_busy (cycles);
  this->add_memory_access_busy (latency);
  return 0; // No contention with insn fetch!
}

// --------------------------------------------------------------------------------
// sh4a_fpu_model.
//
template <class CPU, class IDESC>
sh4a_fpu_model<CPU,IDESC>::sh4a_fpu_model (CPU* cpu) :
  SH4A_FPU_MODEL_BASE (cpu)
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
sh4a_fpu_model<CPU, IDESC>::model_u_maybe_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // No effect on this machine
  return 0;
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU,IDESC>::model_u_lds_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Must wait for fpu unit.
  this->set_current_stall (this->fpu_memory_access_busy);
  return 0;
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU,IDESC>::model_u_ldsl_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  return this->model_u_lds_fpscr_before (cpu, idesc, unit_num);
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU, IDESC>::model_u_maybe_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // No effect on this machine
  return 0;
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU,IDESC>::model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Uses fpu memory access unit
  this->set_fpu_memory_access_busy (1);

  // Basic execution cycles
  this->exec_cycles += 1;
  return 1;
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU,IDESC>::model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return this->model_u_lds_fpscr_after (cpu, idesc, unit_num, referenced);
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU, IDESC>::model_u_fdiv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = 14;
  this->set_fpu_busy (1);
  this->set_fpr_busy (loadreg, cycles);
  return 0; // no direct cycles used
}

template <class CPU, class IDESC>
UINT
sh4a_fpu_model<CPU, IDESC>::model_u_fsqrt_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = 30;
  this->set_fpu_busy (1);
  this->set_fpr_busy (loadreg, cycles);
  return 0; // no direct cycles used
}

// Explicit instantiations
template class sh4a_model<sh2a_model<sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>,
				     sh4a_nofpu_cpu,sh4a_nofpu_idesc>,
			  sh4a_nofpu_cpu,sh4a_nofpu_idesc>;
// NOTE: Need not be templates if never inherited from.
template class sh4a_fpu_model<sh4a_cpu,sh4a_idesc>;

template class sh4a_model<sh2a_model<sh_common_model<sh4al_sh4al_model,sh4al_cpu,sh4al_idesc,sh4al_scache>,sh4al_cpu,sh4al_idesc>,sh4al_cpu,sh4al_idesc>;
