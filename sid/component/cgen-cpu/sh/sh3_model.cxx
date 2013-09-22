// sh3_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh3_model.h"
#include "sh3.h"
#include "sh3e.h"

using namespace sh3;
using namespace sh3e;

template <class BASE, class CPU, class IDESC>
sh3_model<BASE,CPU,IDESC>::sh3_model (CPU* cpu) :
  BASE (cpu),
  sr_busy (0)
{
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class BASE, class CPU, class IDESC>
inline void
sh3_model<BASE,CPU,IDESC>::set_sr_busy (sid::signed_host_int_4 cycles)
{
  if (cycles > 0)
    if (this->sr_busy < cycles)
      this->sr_busy = cycles;
}

template <class BASE, class CPU, class IDESC>
inline bool
sh3_model<BASE,CPU,IDESC>::insn_is_tstb (const sh3_idesc *idesc)
{
  return (idesc->sem_index == sh3::SH3_INSN_TSTB_COMPACT
	  || idesc->sem_index == sh3::SH3_INSN_TASB_COMPACT);
}

template <class BASE, class CPU, class IDESC>
inline bool
sh3_model<BASE,CPU,IDESC>::insn_is_tstb (const sh3e_idesc *idesc)
{
  return (idesc->sem_index == sh3e::SH3E_INSN_TSTB_COMPACT
	  || idesc->sem_index == sh3e::SH3E_INSN_TASB_COMPACT);
}

// --------------------------------------------------------------------------------
// Model overrides
//

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE,CPU,IDESC>::model_u_use_tbit_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  this->set_current_stall (this->sr_busy);
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE,CPU,IDESC>::model_u_set_sr_bit_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // SR will be busy for this number of cycles.
  UINT cycles = 3;

  // Some insns use more cycles.
  if (insn_is_tstb (idesc))
    cycles += 2;

  this->set_sr_busy (cycles);

  return 0; // No additional latency
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE,CPU,IDESC>::model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 5; // 5 cycles on this machine.
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE, CPU, IDESC>::model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 3.
  UINT extra_cycle = this->model_mac_after (cpu, 3);

  // Basic execution cycles for this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MACW);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE, CPU, IDESC>::model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 3.
  UINT extra_cycle = this->model_mac_after (cpu, 3);

  // Basic execution cycles for this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MACL);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE, CPU, IDESC>::model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 3.
  UINT extra_cycle = this->model_mac_after (cpu, 3);

  // Basic execution cycles for this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_DMUL);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE, CPU, IDESC>::model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // MAC model with multiply latency of 3.
  UINT extra_cycle = this->model_mac_after (cpu, 3);

  // Basic execution cycles for this insn.
  UINT cycles = this->unit_cycles (idesc, BASE::UNIT_U_MULL);

  return cycles + extra_cycle;
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE,CPU,IDESC>::model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // 1 cycle on this machine.
  this->exec_cycles += 1;
  return 1;
}

template <class BASE, class CPU, class IDESC>
UINT
sh3_model<BASE,CPU,IDESC>::model_u_trap_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return 6; // 6 cycles on this machine.
}

template <class BASE, class CPU, class IDESC>
void
sh3_model<BASE,CPU,IDESC>::step_latency (sid::host_int_4 cycles)
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
sh3_model<BASE,CPU,IDESC>::advance_latency (sid::host_int_4 latency)
{
  BASE::advance_latency (latency);

  MODEL_ADVANCE_LATENCY (sr_busy, latency);
}

// ------------------------------------------------------------------------------------------------
// Other utility methods.
//
// ... none yet

// ------------------------------------------------------------------------------------------------
// sh3e_model.
//
template <class BASE, class CPU, class IDESC>
sh3e_model<BASE,CPU,IDESC>::sh3e_model (CPU* cpu) :
  sh3_model<BASE,CPU,IDESC> (cpu)
{
}

template <class BASE, class CPU, class IDESC>
UINT
sh3e_model<BASE,CPU,IDESC>::model_u_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = 1;
  this->exec_cycles += cycles;
  this->set_fpu_busy (cycles);
  // NOTE: No special latency for fpscr
  return 0; // No direct cycles used
}

template <class BASE, class CPU, class IDESC>
UINT
sh3e_model<BASE,CPU,IDESC>::model_u_fcnv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  return this->model_u_fpu_after (cpu, idesc, unit_num, referenced);
}

template <class BASE, class CPU, class IDESC>
UINT
sh3e_model<BASE,CPU,IDESC>::model_u_fsqrt_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = 15;
  this->set_fpu_busy (cycles);
  this->set_fpr_busy (loadreg, cycles);
  return 0; // no direct cycles used
}

// Explicit instantiations
template class sh3_model<sh_common_model<sh3_sh3_model,sh3_cpu,sh3_idesc,sh3_scache>,sh3_cpu,sh3_idesc>;
template class sh3e_model<sh_common_model_with_fp<sh3e_sh3e_model,sh3e_cpu,sh3e_idesc,sh3e_scache>,sh3e_cpu,sh3e_idesc>;
