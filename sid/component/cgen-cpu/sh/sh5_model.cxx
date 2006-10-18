// sh5_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh5_model.h"
#include "sh5.h"

using namespace sh5_media;

sh5_media_model::sh5_media_model (sh5_cpu* cpu) :
  SH5_MEDIA_MODEL_BASE (cpu),
  fdiv_busy (0),
  fdivd_busy (0),
  fsqrt_busy (0),
  fsqrtd_busy (0)
{
  for (int i = 0; i < 32; ++i)
    {
      dr_busy[i] = 0;
      fp_busy[i] = 0;
    }
  for (int i = 0; i < 16; ++i)
    fv_busy[i] = 0;
  for (int i = 0; i < 4; ++i)
    mtrx_busy[i] = 0;
  for (int i = 0; i < 64; ++i)
    result_reg_busy[i] = 0;
  for (int i = 0; i < 8; ++i)
    {
      tr_busy_for_branch[i] = 0;
      tr_busy_for_gettr[i] = 0;
      pt_gap[i] = PT_GAP_MAX;
    }
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
inline void
sh5_media_model::set_dr_busy (INT reg, UINT cycles)
{
  reg /= 2; // slot
  if (dr_busy[reg] < cycles)
    dr_busy[reg] = cycles;
}

inline void
sh5_media_model::set_fp_busy (INT reg, UINT cycles)
{
  reg /= 2; // slot
  if (fp_busy[reg] < cycles)
    fp_busy[reg] = cycles;
}

inline void
sh5_media_model::set_fv_busy (INT reg, UINT cycles)
{
  reg /= 4; // slot
  if (fv_busy[reg] < cycles)
    fv_busy[reg] = cycles;
}

inline void
sh5_media_model::set_mtrx_busy (INT reg, UINT cycles)
{
  reg /= 16; // slot
  if (mtrx_busy[reg] < cycles)
    mtrx_busy[reg] = cycles;
}

inline void
sh5_media_model::set_tr_busy (INT reg, UINT cycles)
{
  if (tr_busy_for_branch[reg] < cycles)
    tr_busy_for_branch[reg] = cycles;

  cycles += 3;
  if (tr_busy_for_gettr[reg] < cycles)
    tr_busy_for_gettr[reg] = cycles;
}

inline void
sh5_media_model::set_fdiv_busy (UINT cycles)
{
  if (fdiv_busy < cycles)
    fdiv_busy = cycles;
}

inline void
sh5_media_model::set_fdivd_busy (UINT cycles)
{
  if (fdivd_busy < cycles)
    fdivd_busy = cycles;
}

inline void
sh5_media_model::set_fsqrt_busy (UINT cycles)
{
  if (fsqrt_busy < cycles)
    fsqrt_busy = cycles;
}

inline void
sh5_media_model::set_fsqrtd_busy (UINT cycles)
{
  if (fsqrtd_busy < cycles)
    fsqrtd_busy = cycles;
}

inline void
sh5_media_model::set_result_bank_busy (INT bank_size, INT reg, UINT cycles)
{
  reg = reg / bank_size * bank_size;
  for (int i = 0; i < bank_size; ++i)
    if (result_reg_busy[i] < cycles)
      result_reg_busy[i] = cycles;
}

void
sh5_media_model::set_memory_access_busy (UINT cycles)
{
  if (this->memory_access_busy < cycles)
    this->memory_access_busy = cycles;
}

void
sh5_media_model::reset_pt_gap (INT reg)
{
  pt_gap[reg] = -1;
}

// --------------------------------------------------------------------------------
// Model overrides
//
UINT
sh5_media_model::model_u_fpu_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num)
{
  // Must wait if fdiv or fsqrt is down to their final cycles
  if (fdiv_busy == 1 || fsqrt_busy == 1)
    this->set_current_stall (1);
  
  if (fdivd_busy <= 2)
    this->set_current_stall (fdivd_busy);

  if (fsqrtd_busy <= 2)
    this->set_current_stall (fsqrtd_busy);

  return 0;
}

UINT
sh5_media_model::model_u_use_fp_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (fp_busy[usereg]);

  return 0;
}

UINT
sh5_media_model::model_u_use_fv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (fv_busy[usereg]);

  return 0;
}

UINT
sh5_media_model::model_u_use_mtrx_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (mtrx_busy[usereg]);

  return 0;
}

UINT
sh5_media_model::model_u_use_tr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (tr_busy_for_gettr[usereg]);

  return 0;
}

UINT
sh5_media_model::model_u_fdiv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait for the fdiv unit.
  set_current_stall (fdiv_busy);
  set_current_stall (fdivd_busy);
  return 0;
}

UINT
sh5_media_model::model_u_fdivd_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait for the fdiv unit.
  set_current_stall (fdiv_busy);
  set_current_stall (fdivd_busy);
  return 0;
}

UINT
sh5_media_model::model_u_fsqrt_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait for the fsqrt unit.
  set_current_stall (fsqrt_busy);
  set_current_stall (fsqrtd_busy);
  return 0;
}

UINT
sh5_media_model::model_u_fsqrtd_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait for the fsqrt unit.
  set_current_stall (fsqrt_busy);
  set_current_stall (fsqrtd_busy);
  return 0;
}

UINT
sh5_media_model::model_u_set_fr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  return 0;
}

UINT
sh5_media_model::model_u_set_dr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  set_current_stall (result_reg_busy[loadreg + 1]);
  return 0;
}

UINT
sh5_media_model::model_u_set_fp_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  set_current_stall (result_reg_busy[loadreg + 1]);
  return 0;
}

UINT
sh5_media_model::model_u_set_fv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  set_current_stall (result_reg_busy[loadreg + 1]);
  set_current_stall (result_reg_busy[loadreg + 2]);
  set_current_stall (result_reg_busy[loadreg + 3]);
  return 0;
}

UINT
sh5_media_model::model_u_set_mtrx_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  for (int i = 0; i < 16; ++i)
    set_current_stall (result_reg_busy[loadreg + i]);
  return 0;
}

UINT
sh5_media_model::model_u_load_fr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  return 0;
}

UINT
sh5_media_model::model_u_load_dr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  set_current_stall (result_reg_busy[loadreg + 1]);
  return 0;
}

UINT
sh5_media_model::model_u_load_fp_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  set_current_stall (result_reg_busy[loadreg + 1]);
  return 0;
}

UINT
sh5_media_model::model_u_load_fv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  set_current_stall (result_reg_busy[loadreg]);
  set_current_stall (result_reg_busy[loadreg + 1]);
  set_current_stall (result_reg_busy[loadreg + 2]);
  set_current_stall (result_reg_busy[loadreg + 3]);
  return 0;
}

UINT
sh5_media_model::model_u_memory_access_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num)
{
  // Save the total latency (before execution) so that it can be used to compute
  // any latency incurred during execution.
  memory_access_pre_execution_latency = cpu->get_total_latency ();
  return 0;
}

UINT
sh5_media_model::model_u_load_mtrx_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg)
{
  // Must wait if this register is busy as a result register.
  for (int i = 0; i < 16; ++i)
    set_current_stall (result_reg_busy[loadreg + i]);
  return 0;
}

UINT
sh5_media_model::model_u_blink_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT targetreg)
{
  assert (targetreg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (tr_busy_for_branch[targetreg]);

  return 0;
}

UINT
sh5_media_model::model_u_cond_branch_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT targetreg)
{
  // Same as blink
  return model_u_blink_before (cpu, idesc, unit_num, targetreg);
}

UINT
sh5_media_model::model_u_fpu_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_fpu_after (cpu, idesc, unit_num, referenced);
  return cycles;
}

UINT
sh5_media_model::model_u_set_gr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_set_gr_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_gpr_busy (loadreg, cycles);
  return 0;
}

UINT
sh5_media_model::model_u_set_fr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_set_fr_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_fpr_busy (loadreg, cycles);
  return 0;
}

UINT
sh5_media_model::model_u_set_dr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_set_dr_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_dr_busy (loadreg, cycles);
  return 0;
}

UINT
sh5_media_model::model_u_set_fp_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_set_fp_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_fp_busy (loadreg, cycles);
  return 0;
}

UINT
sh5_media_model::model_u_set_fv_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_set_fv_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_fv_busy (loadreg, cycles);
  return 0;
}

UINT
sh5_media_model::model_u_set_mtrx_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_set_mtrx_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_mtrx_busy (loadreg, cycles);
  return 0;
}

UINT
sh5_media_model::model_u_memory_access_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
{
  // There will be additional latency for accessing the memory itself.
  UINT latency = cpu->get_total_latency () - memory_access_pre_execution_latency;

  // The memory access unit will be busy for as long as the insn
  // executes plus the memory latency.
  this->set_memory_access_busy (1 + latency);

  return latency;
}

UINT
sh5_media_model::model_u_load_gr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // The target will be available after memory access plus the given latency.
  UINT cycles = sh5_media_sh5_media_model::model_u_load_gr_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_gpr_busy (loadreg, this->memory_access_busy + cycles);
  return 0;
}

UINT
sh5_media_model::model_u_load_fr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_load_fr_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_fpr_busy (loadreg, this->memory_access_busy + cycles);
  return 0;
}

UINT
sh5_media_model::model_u_load_dr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_load_dr_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_dr_busy (loadreg, this->memory_access_busy + cycles);
  return 0;
}

UINT
sh5_media_model::model_u_load_fp_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_load_fp_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_fp_busy (loadreg, this->memory_access_busy + cycles);
  return 0;
}

UINT
sh5_media_model::model_u_load_fv_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_load_fv_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_fv_busy (loadreg, this->memory_access_busy + cycles);
  return 0;
}

UINT
sh5_media_model::model_u_load_mtrx_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  UINT cycles = sh5_media_sh5_media_model::model_u_load_mtrx_after (cpu, idesc, unit_num, referenced, loadreg);
  this->set_mtrx_busy (loadreg, this->memory_access_busy + cycles);
  return 0;
}

UINT
sh5_media_model::model_u_fdiv_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // The fdiv unit will be busy for 16 cycles.
  UINT cycles = 16;
  this->set_fdiv_busy (cycles);

  // The 4 register bank contaning the result will be busy as well.
  this->set_result_bank_busy (4, loadreg, cycles);

  // basic issue rate is 1 cycle.
  return 1;
}

UINT
sh5_media_model::model_u_fdivd_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // The fdiv unit will be busy for 32 cycles.
  UINT cycles = 32;
  this->set_fdivd_busy (cycles);

  // The 4 register bank contaning the result will be busy as well.
  this->set_result_bank_busy (4, loadreg, cycles);

  // basic issue rate is 1 cycle.
  return 1;
}

UINT
sh5_media_model::model_u_fsqrt_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // The fsqrt unit will be busy for 16 cycles.
  UINT cycles = 16;
  this->set_fsqrt_busy (cycles);

  // The 4 register bank contaning the result will be busy as well.
  this->set_result_bank_busy (4, loadreg, cycles);

  // basic issue rate is 1 cycle.
  return 1;
}

UINT
sh5_media_model::model_u_fsqrtd_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // The fsqrt unit will be busy for 32 cycles.
  UINT cycles = 32;
  this->set_fsqrtd_busy (cycles);

  // The 4 register bank contaning the result will be busy as well.
  this->set_result_bank_busy (4, loadreg, cycles);

  // basic issue rate is 1 cycle.
  return 1;
}

UINT
sh5_media_model::model_u_ftrvs_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  // The individual fr registers will be available in sequence.
  this->set_fpr_busy (loadreg,     6);
  this->set_fpr_busy (loadreg + 1, 7);
  this->set_fpr_busy (loadreg + 2, 8);
  this->set_fpr_busy (loadreg + 3, 9);

  // The individual dr registers will be available in sequence.
  this->set_dr_busy (loadreg,      8);
  this->set_dr_busy (loadreg + 2, 10);

  // The individual fp registers will be available in sequence.
  this->set_fp_busy (loadreg,      8);
  this->set_fp_busy (loadreg + 2, 10);

  // The fv and mtrx registers will be available in 10 cycles.
  this->set_fv_busy (loadreg, 10);
  this->set_mtrx_busy (loadreg, 10);

  return 0; // No additional direct cycles.
}

UINT
sh5_media_model::model_u_pt_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT targetreg)
{
  this->reset_pt_gap (targetreg);
  this->set_tr_busy (targetreg, 2);
  return 0; // No additional direct cycles.
}

UINT
sh5_media_model::model_u_blink_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT targetreg)
{
  UINT cycles = 1; // basic execution cycle

  if (cpu->get_branch_prediction (targetreg) == 0)
    cycles += 2; // 2 cycle penalty for mispredicted blink
  else
    {
      // Simulate the prefetch
      PCADDR target = cpu->h_tr_get (targetreg);
      cpu->prefetch (target);

      // Penalty depends on the gap since the target register was set
      switch (this->pt_gap[targetreg])
	{
	case 0:
	  cycles += 2; // PT*/L latency has already been accounted for
	  break;
	case 1:
	  cycles += 2;
	  break;
	case 2:
	  // pc is 8-byte aligned?
	  if ((cpu->h_pc_get () & 0x7) == 0)
	    cycles += 1;
	  else
	    cycles += 2;
	  break;
	case 3:
	  // target is 8-byte aligned?
	  if ((target & 0x7) == 0)
	    {
	      // pc is 8-byte aligned?
	      if ((cpu->h_pc_get () & 0x7) != 0)
		cycles += 1;
	    }
	  else
	    cycles += 1;
	  break;
	case 4:
	  // target is 8-byte aligned?
	  if ((target & 0x7) != 0)
	    {
	      // pc is 8-byte aligned?
	      if ((cpu->h_pc_get () & 0x7) != 0)
		cycles += 1;
	    }
	  break;
	default:
	  break; // no penalty
	}
    }

  return cycles; // additional cycles.
}

UINT
sh5_media_model::model_u_cond_branch_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT targetreg)
{
  UINT cycles = 0; // basic execution cycle

  // (1ULL << 1): The pc is the 2nd element in inputs, outputs.
  // ??? can be cleaned up
  bool taken = ((referenced & (1ULL << 1)) != 0);
  if (taken)
    {
      // Branch was taken
      if (cpu->get_branch_prediction (targetreg) == 0)
	{
	  // Branch was indicated as unlikely
	  if (cpu->get_branch_optimization () == 0)
	    cycles += 5; // Branch was mispredicted
	  else
	    cycles += 2; // Branch was predicted
	}
      else
	{
	  // Branch was indicated as likely
	  // Simulate the prefetch
	  PCADDR target = cpu->h_tr_get (targetreg);
	  cpu->prefetch (target);

	  if (cpu->get_branch_optimization () == 0)
	    {
	      // Branch was mispredicted
	      // Penalty depends on the gap since the target register was set
	      switch (this->pt_gap[targetreg])
		{
		case 0:
		  cycles += 2; // PT*/L latency has already been accounted for
		  break;
		case 1:
		  // pc is 8-byte aligned?
		  if ((cpu->h_pc_get () & 0x7) == 0)
		    cycles += 2;
		  else
		    cycles += 3;
		  break;
		default:
		  cycles += 2;
		  break;
		}
	    }
	  else
	    {
	      // Branch was predicted
	      // Penalty depends on the gap since the target register was set
	      switch (this->pt_gap[targetreg])
		{
		case 0:
		  cycles += 2; // PT*/L latency has already been accounted for
		  break;
		case 1:
		  cycles += 2;
		  break;
		case 2:
		  // pc is 8-byte aligned?
		  if ((cpu->h_pc_get () & 0x7) == 0)
		    cycles += 1;
		  else
		    cycles += 2;
		  break;
		case 3:
		  // target is 8-byte aligned?
		  if ((target & 0x7) == 0)
		    {
		      // pc is 8-byte aligned?
		      if ((cpu->h_pc_get () & 0x7) != 0)
			cycles += 1;
		    }
		  else
		    cycles += 1;
		  break;
		case 4:
		  // target is 8-byte aligned?
		  if ((target & 0x7) != 0)
		    {
		      // pc is 8-byte aligned?
		      if ((cpu->h_pc_get () & 0x7) != 0)
			cycles += 1;
		    }
		  break;
		default:
		  break; // no penalty
		}
	    } // branch predicted
	} // branch indictaed as likely
    } // branch taken
  else
    {
      // Branch was not taken
      // NOTE: No penalty for non-branch predicted
      if (cpu->get_branch_prediction (targetreg) == 0)
	{
	  // Branch was indicated as unlikely
	  if (cpu->get_branch_optimization () != 0)
	    cycles += 2; // Branch was mispredicted
	}
      else
	{
	  // Branch was indicated as likely
	  // Simulate the prefetch
	  PCADDR target = cpu->h_tr_get (targetreg);
	  cpu->prefetch (target);

	  if (cpu->get_branch_optimization () != 0)
	    {
	      // non-Branch was mispredicted
	      cycles += 2; // PT*/L latency has already been accounted for
	    }
	} // branch indicated as likely
    } // branch not taken

  return cycles; // additional cycles.
}

UINT
sh5_media_model:: model_u_getcfg_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
{
  // Assume the average case
  UINT address = this->cpu->sh64_get_cfg_address ();
  switch (address & 0xffff0000)
    {
    case 0x00000000: // MMUIR
    case 0x00100000: // ICACHETAG
    case 0x00120000: // ICACHEDATA
      return (10 + 28) / 2;
    case 0x00160000: // ICCR
      return 6;
    case 0x00080000: // MMUDR
    case 0x00180000: // OCACHETAG
    case 0x001a0000: // OCACHEDATA
    case 0x001e0000: // OCCR
      return 8;
    default:
      break;
    }

  return 6; // minimum
}

UINT
sh5_media_model:: model_u_putcfg_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
{
  // Assume the average case
  UINT address = this->cpu->sh64_get_cfg_address ();
  switch (address & 0xffff0000)
    {
    case 0x00000000: // MMUIR
      return (8 + 25) / 2;
    case 0x00080000: // MMUDR
    case 0x001e0000: // OCCR
      return 6;
    case 0x00160000: // ICCR
      return 8;
    default:
      break;
    }

  return 6; // minimum
}

void
sh5_media_model::step_latency (sid::host_int_4 cycles)
{
  // Compute latency which has incurred since we were last called.
  sid::host_int_8 new_total_latency = sh5_media_sh5_media_model::cpu->get_total_latency ();
  sid::host_int_8 latency = cycles + (new_total_latency - this->save_total_latency);
  this->save_total_latency = new_total_latency;

  // If there's no latency, then nothing to do.
  if (LIKELY (latency == 0))
    return;

  this->advance_latency (latency);
}

void
sh5_media_model::advance_latency (sid::host_int_4 latency)
{
  SH5_MEDIA_MODEL_BASE::advance_latency (latency);

  // Advance the hazard state information by the given number of cycles.
  for (int i = 0; i < 32; ++i)
    {
      MODEL_ADVANCE_LATENCY (dr_busy[i], latency);
      MODEL_ADVANCE_LATENCY (fp_busy[i], latency);
    }

  for (int i = 0; i < 16; ++i)
    MODEL_ADVANCE_LATENCY (fv_busy[i], latency);

  for (int i = 0; i < 4; ++i)
    MODEL_ADVANCE_LATENCY (mtrx_busy[i], latency);

  for (int i = 0; i < 64; ++i)
    MODEL_ADVANCE_LATENCY (result_reg_busy[i], latency);

  for (int i = 0; i < 8; ++i)
    {
      MODEL_ADVANCE_LATENCY (tr_busy_for_branch[i], latency);
      MODEL_ADVANCE_LATENCY (tr_busy_for_gettr[i], latency);
    }

  MODEL_ADVANCE_LATENCY (fdiv_busy, latency);
  MODEL_ADVANCE_LATENCY (fdivd_busy, latency);

  MODEL_ADVANCE_LATENCY (fsqrt_busy, latency);
  MODEL_ADVANCE_LATENCY (fsqrtd_busy, latency);
}

// Called after each insn is executed. last_p is
// true when the insn is the last of a group of parallel insns. cycles is the
// number of cycles used by each particular insn.
void
sh5_media_model::model_insn_after (bool last_p, sid::host_int_4 cycles)
{
  // Call up to the base class.
  SH5_MEDIA_MODEL_BASE::model_insn_after (last_p, cycles);

  // Adjust the count of the number of insns since each branch target
  // register was set.
  for (int i = 0; i < 8; ++i)
    if (pt_gap[i] < PT_GAP_MAX)
      ++pt_gap[i];
}
