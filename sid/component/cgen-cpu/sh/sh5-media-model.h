/* Simulator model support for sh5_media.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef SH5_MEDIA_MODEL_H
#define SH5_MEDIA_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace sh5
{
using namespace cgen;

class sh5_media_sh5_model : public cgen_model
{
public:
  sh5_media_sh5_model (sh5_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (sh5_cpu *current_cpu, sh5_media_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (sh5_cpu *current_cpu, sh5_media_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_ftrv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*fvn*/)
    {
      return 0;
    }
  virtual UINT model_u_ftrv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*fvn*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fipr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*fvm*/, INT /*fvn*/)
    {
      return 0;
    }
  virtual UINT model_u_fipr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*fvm*/, INT /*fvn*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ocb_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ocb_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulr_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mulr_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mulr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_dr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_dr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_dr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_dr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_dr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_dr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fcnv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fcnv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fcmp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fcmp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fsqrt_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fsqrt_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fdiv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fdiv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_load_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fpu_load_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fpscr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_fpscr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldsl_fpscr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldsl_fpscr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_lds_fpscr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_lds_fpscr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_flds_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_flds_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_memory_access_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fpu_memory_access_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_fr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fr_0_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fr_0_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_fr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_maybe_fpu_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_maybe_fpu_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fpu_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_trap_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_trap_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_write_back_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_write_back_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_multiply_result_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_multiply_result_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_shift_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_shift_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_tas_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_tas_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulsw_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mulsw_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mull_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mull_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_dmul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_dmul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_macl_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_macl_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_macw_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_macw_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_mac_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_mac_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_mac_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_mac_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_vbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_vbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_gbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stc_vbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stc_vbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcl_vbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcl_vbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcl_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcl_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_tbit_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_tbit_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldc_gbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldc_gbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldc_sr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldc_sr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_sr_bit_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_sr_bit_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_sts_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_sts_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_lds_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_lds_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_memory_access_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_memory_access_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_logic_b_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_logic_b_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_jsr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_jsr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_jmp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_jmp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_sx_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_sx_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_add_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_add_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addzl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addzl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_alloco_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_alloco_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_and_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_and_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andc_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andc_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beqi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beqi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bge_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bge_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgeu_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgeu_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_blink_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_blink_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bne_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bne_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bnei_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bnei_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_brk_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_brk_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_byterev_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_byterev_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpeq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpeq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmveq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmveq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmvne_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmvne_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabss_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabss_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_faddd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_faddd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fadds_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fadds_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpged_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpged_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpges_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpges_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgts_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgts_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpund_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpund_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpuns_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpuns_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvds_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvds_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fgetscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fgetscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fiprs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fiprs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_flds_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_flds_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatld_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatld_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatls_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatls_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmacs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmacs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovls_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovls_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuld_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuld_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuls_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuls_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fputscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fputscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrts_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrts_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsts_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsts_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrvs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrvs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_gettr_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_gettr_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_icbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_icbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_lduw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_lduw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxuw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxuw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeql_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeql_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmv_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmv_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvslw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvslw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr1_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr1_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr2_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr2_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr3_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr3_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr4_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr4_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr5_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr5_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr6_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr6_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr7_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr7_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacfxwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacfxwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacnfx_wl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacnfx_wl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmull_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmull_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxrpw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxrpw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulhiwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulhiwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmullowl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmullowl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulsumwq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulsumwq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_movi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_movi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mpermw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mpermw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msadubq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msadubq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhib_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhib_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhiw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhiw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflob_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflob_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflol_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflol_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflow_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflow_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulul_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulul_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nop_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nop_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nsb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nsb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbwb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbwb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_or_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_or_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ori_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ori_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_prefi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_prefi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_pta_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_pta_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptabs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptabs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptrel_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptrel_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_rte_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_rte_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shard_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shard_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shari_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shari_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sharil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sharil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlld_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlld_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlli_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlli_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shllil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shllil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlri_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlri_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlril_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlril_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shori_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shori_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sleep_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sleep_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_subl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_subl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_swapq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_swapq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synci_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synci_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synco_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synco_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_trapa_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_trapa_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xor_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xor_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xori_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xori_after (sh5_cpu *current_cpu, sh5_media_scache *sem);

  /* Enum declaration for unit types.  */
typedef enum unit_number {
  UNIT_NONE, UNIT_U_FTRV, UNIT_U_FIPR, UNIT_U_OCB
 , UNIT_U_MULR_GR, UNIT_U_MULR, UNIT_U_USE_DR, UNIT_U_LOAD_DR
 , UNIT_U_SET_DR, UNIT_U_FCNV, UNIT_U_FCMP, UNIT_U_FSQRT
 , UNIT_U_FDIV, UNIT_U_FPU_LOAD_GR, UNIT_U_USE_FPSCR, UNIT_U_LDSL_FPSCR
 , UNIT_U_LDS_FPSCR, UNIT_U_USE_FPUL, UNIT_U_FLDS_FPUL, UNIT_U_LOAD_FPUL
 , UNIT_U_SET_FPUL, UNIT_U_FPU_MEMORY_ACCESS, UNIT_U_USE_FR, UNIT_U_SET_FR_0
 , UNIT_U_SET_FR, UNIT_U_LOAD_FR, UNIT_U_MAYBE_FPU, UNIT_U_FPU
 , UNIT_U_TRAP, UNIT_U_WRITE_BACK, UNIT_U_USE_MULTIPLY_RESULT, UNIT_U_SHIFT
 , UNIT_U_TAS, UNIT_U_MULSW, UNIT_U_MULL, UNIT_U_DMUL
 , UNIT_U_MACL, UNIT_U_MACW, UNIT_U_MULTIPLY, UNIT_U_SET_MAC
 , UNIT_U_LOAD_MAC, UNIT_U_LOAD_VBR, UNIT_U_LOAD_GBR, UNIT_U_USE_GR
 , UNIT_U_LOAD_GR, UNIT_U_STC_VBR, UNIT_U_LDCL_VBR, UNIT_U_LDCL
 , UNIT_U_USE_TBIT, UNIT_U_LDC_GBR, UNIT_U_LDC_SR, UNIT_U_SET_SR_BIT
 , UNIT_U_USE_PR, UNIT_U_LOAD_PR, UNIT_U_STS_PR, UNIT_U_LDS_PR
 , UNIT_U_MEMORY_ACCESS, UNIT_U_LOGIC_B, UNIT_U_JSR, UNIT_U_JMP
 , UNIT_U_BRANCH, UNIT_U_SX, UNIT_U_EXEC, UNIT_MAX
} UNIT_NUMBER;

  struct unit {
    unit_number unit;
    UINT issue;
    UINT done;
  };

  static const int MAX_UNITS = 9;

  typedef UINT (sh5_media_sh5_model::*model_function) (sh5_cpu* current_cpu, sh5_media_scache* sem);

  struct insn_timing {
    // This is an integer that identifies this insn.
    UINT num;
    // Functions to handle insn-specific profiling.
    model_function model_before;
    model_function model_after;
    // Array of function units used by this insn.
    unit units[MAX_UNITS];
  };

  static const insn_timing timing[];
};

class sh5_media_sh5_media_model : public cgen_model
{
public:
  sh5_media_sh5_media_model (sh5_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (sh5_cpu *current_cpu, sh5_media_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (sh5_cpu *current_cpu, sh5_media_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_putcfg_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_putcfg_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_getcfg_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_getcfg_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_pt_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*targetreg*/)
    {
      return 0;
    }
  virtual UINT model_u_pt_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*targetreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ftrvs_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_ftrvs_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fsqrtd_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fsqrtd_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fdivd_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fdivd_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_cond_branch_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*targetreg*/)
    {
      return 0;
    }
  virtual UINT model_u_cond_branch_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*targetreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_blink_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*targetreg*/)
    {
      return 0;
    }
  virtual UINT model_u_blink_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*targetreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_tr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_tr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_mtrx_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_mtrx_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_fv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_fp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_mtrx_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_mtrx_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_fv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_fp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_mtrx_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_mtrx_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ftrv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*fvn*/)
    {
      return 0;
    }
  virtual UINT model_u_ftrv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*fvn*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fipr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*fvm*/, INT /*fvn*/)
    {
      return 0;
    }
  virtual UINT model_u_fipr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*fvm*/, INT /*fvn*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ocb_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ocb_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulr_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mulr_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mulr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_dr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_dr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_dr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_dr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_dr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_dr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fcnv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fcnv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fcmp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fcmp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fsqrt_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fsqrt_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fdiv_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fdiv_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_load_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fpu_load_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fpscr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_fpscr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldsl_fpscr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldsl_fpscr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_lds_fpscr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_lds_fpscr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_flds_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_flds_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fpul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_fpul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_memory_access_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fpu_memory_access_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_fr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fr_0_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fr_0_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_fr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_maybe_fpu_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_maybe_fpu_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fpu_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_trap_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_trap_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_write_back_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_write_back_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_multiply_result_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_multiply_result_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_shift_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_shift_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_tas_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_tas_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulsw_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mulsw_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mull_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mull_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_dmul_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_dmul_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_macl_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_macl_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_macw_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_macw_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_mac_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_mac_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_mac_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_mac_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_vbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_vbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_gbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stc_vbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stc_vbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcl_vbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcl_vbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcl_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcl_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_tbit_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_tbit_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldc_gbr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldc_gbr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldc_sr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldc_sr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_sr_bit_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_sr_bit_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_sts_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_sts_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_lds_pr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_lds_pr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_memory_access_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_memory_access_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_logic_b_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_logic_b_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_jsr_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_jsr_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_jmp_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_jmp_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_sx_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_sx_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (sh5_cpu *cpu, const struct sh5_media_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_add_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_add_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addzl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_addzl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_alloco_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_alloco_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_and_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_and_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andc_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andc_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_andi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beqi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_beqi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bge_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bge_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgeu_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgeu_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_blink_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_blink_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bne_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bne_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bnei_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_bnei_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_brk_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_brk_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_byterev_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_byterev_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpeq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpeq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgt_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgt_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgtu_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmpgtu_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmveq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmveq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmvne_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_cmvne_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabss_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fabss_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_faddd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_faddd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fadds_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fadds_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpeqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpged_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpged_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpges_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpges_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgts_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpgts_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpund_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpund_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpuns_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcmpuns_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvds_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvds_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvsd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fcnvsd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fdivs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fgetscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fgetscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fiprs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fiprs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_flds_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_flds_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fldxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatld_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatld_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatls_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatls_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_floatqs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmacs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmacs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovls_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovls_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovqd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovqd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmovsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuld_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuld_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuls_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fmuls_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fnegs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fputscr_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fputscr_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrtd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrtd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrts_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsqrts_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsts_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsts_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fstxs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_fsubs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcdq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrcsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrvs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ftrvs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_getcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_gettr_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_gettr_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_icbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_icbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_lduw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_lduw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldhiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxuw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxuw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ldxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mabsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_maddsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeql_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeql_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpeqw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmpgtw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmv_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcmv_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvslw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvslw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mcnvswub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr1_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr1_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr2_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr2_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr3_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr3_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr4_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr4_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr5_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr5_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr6_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr6_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr7_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mextr7_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacfxwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacfxwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacnfx_wl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmacnfx_wl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmull_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmull_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxrpw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulfxrpw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulhiwl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulhiwl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmullowl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmullowl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulsumwq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mmulsumwq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_movi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_movi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mpermw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mpermw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msadubq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msadubq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshaldsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardsq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshardsq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhib_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhib_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhiw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshfhiw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflob_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflob_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflol_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflol_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflow_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshflow_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlldw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mshlrdw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_msubsw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulsl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulsl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulul_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_mulul_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nop_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nop_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nsb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_nsb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbp_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbp_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbwb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ocbwb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_or_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_or_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ori_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ori_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_prefi_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_prefi_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_pta_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_pta_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptabs_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptabs_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptrel_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_ptrel_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcfg_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcfg_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcon_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_putcon_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_rte_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_rte_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shard_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shard_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shardl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shardl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shari_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shari_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sharil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sharil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlld_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlld_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlldl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlldl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlli_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlli_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shllil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shllil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrd_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrd_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrdl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlrdl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlri_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlri_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlril_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shlril_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shori_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_shori_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sleep_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sleep_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthil_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthil_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthiq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sthiq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stlol_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stlol_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stloq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stloq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxb_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxb_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxw_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_stxw_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sub_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_sub_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_subl_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_subl_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_swapq_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_swapq_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synci_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synci_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synco_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_synco_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_trapa_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_trapa_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xor_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xor_after (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xori_before (sh5_cpu *current_cpu, sh5_media_scache *sem);
  UINT model_xori_after (sh5_cpu *current_cpu, sh5_media_scache *sem);

  /* Enum declaration for unit types.  */
typedef enum unit_number {
  UNIT_NONE, UNIT_U_PUTCFG, UNIT_U_GETCFG, UNIT_U_PT
 , UNIT_U_FTRVS, UNIT_U_FSQRTD, UNIT_U_FDIVD, UNIT_U_COND_BRANCH
 , UNIT_U_BLINK, UNIT_U_USE_TR, UNIT_U_USE_MTRX, UNIT_U_USE_FV
 , UNIT_U_USE_FP, UNIT_U_LOAD_MTRX, UNIT_U_LOAD_FV, UNIT_U_LOAD_FP
 , UNIT_U_SET_MTRX, UNIT_U_SET_FV, UNIT_U_SET_FP, UNIT_U_SET_GR
 , UNIT_U_FTRV, UNIT_U_FIPR, UNIT_U_OCB, UNIT_U_MULR_GR
 , UNIT_U_MULR, UNIT_U_USE_DR, UNIT_U_LOAD_DR, UNIT_U_SET_DR
 , UNIT_U_FCNV, UNIT_U_FCMP, UNIT_U_FSQRT, UNIT_U_FDIV
 , UNIT_U_FPU_LOAD_GR, UNIT_U_USE_FPSCR, UNIT_U_LDSL_FPSCR, UNIT_U_LDS_FPSCR
 , UNIT_U_USE_FPUL, UNIT_U_FLDS_FPUL, UNIT_U_LOAD_FPUL, UNIT_U_SET_FPUL
 , UNIT_U_FPU_MEMORY_ACCESS, UNIT_U_USE_FR, UNIT_U_SET_FR_0, UNIT_U_SET_FR
 , UNIT_U_LOAD_FR, UNIT_U_MAYBE_FPU, UNIT_U_FPU, UNIT_U_TRAP
 , UNIT_U_WRITE_BACK, UNIT_U_USE_MULTIPLY_RESULT, UNIT_U_SHIFT, UNIT_U_TAS
 , UNIT_U_MULSW, UNIT_U_MULL, UNIT_U_DMUL, UNIT_U_MACL
 , UNIT_U_MACW, UNIT_U_MULTIPLY, UNIT_U_SET_MAC, UNIT_U_LOAD_MAC
 , UNIT_U_LOAD_VBR, UNIT_U_LOAD_GBR, UNIT_U_USE_GR, UNIT_U_LOAD_GR
 , UNIT_U_STC_VBR, UNIT_U_LDCL_VBR, UNIT_U_LDCL, UNIT_U_USE_TBIT
 , UNIT_U_LDC_GBR, UNIT_U_LDC_SR, UNIT_U_SET_SR_BIT, UNIT_U_USE_PR
 , UNIT_U_LOAD_PR, UNIT_U_STS_PR, UNIT_U_LDS_PR, UNIT_U_MEMORY_ACCESS
 , UNIT_U_LOGIC_B, UNIT_U_JSR, UNIT_U_JMP, UNIT_U_BRANCH
 , UNIT_U_SX, UNIT_U_EXEC, UNIT_MAX
} UNIT_NUMBER;

  struct unit {
    unit_number unit;
    UINT issue;
    UINT done;
  };

  static const int MAX_UNITS = 9;

  typedef UINT (sh5_media_sh5_media_model::*model_function) (sh5_cpu* current_cpu, sh5_media_scache* sem);

  struct insn_timing {
    // This is an integer that identifies this insn.
    UINT num;
    // Functions to handle insn-specific profiling.
    model_function model_before;
    model_function model_after;
    // Array of function units used by this insn.
    unit units[MAX_UNITS];
  };

  static const insn_timing timing[];
};

} // namespace sh5

#endif // SH5_MEDIA_MODEL_H
