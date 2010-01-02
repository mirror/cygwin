/* Simulator model support for sh2e.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef SH2E_MODEL_H
#define SH2E_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace sh2e
{
using namespace cgen;

class sh2e_sh2e_model : public cgen_model
{
public:
  sh2e_sh2e_model (sh2e_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (sh2e_cpu *current_cpu, sh2e_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (sh2e_cpu *current_cpu, sh2e_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_fcnv_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fcnv_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fcmp_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fcmp_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fsqrt_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fsqrt_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fdiv_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fdiv_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_load_gr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_fpu_load_gr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fpscr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_fpscr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldsl_fpscr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldsl_fpscr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_lds_fpscr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_lds_fpscr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fpul_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_fpul_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_flds_fpul_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_flds_fpul_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fpul_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_fpul_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fpul_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_fpul_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_memory_access_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fpu_memory_access_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_fr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_fr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fr_0_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fr_0_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_fr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_set_fr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_fr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_fr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_maybe_fpu_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_maybe_fpu_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_fpu_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_fpu_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_trap_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_trap_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_write_back_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_write_back_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_multiply_result_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_multiply_result_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_shift_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_shift_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_tas_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_tas_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mulsw_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mulsw_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mull_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_mull_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_dmul_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_dmul_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_macl_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_macl_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_macw_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_macw_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_mac_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_mac_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_mac_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_mac_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_vbr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_vbr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gbr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_gbr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stc_vbr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stc_vbr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcl_vbr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcl_vbr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcl_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcl_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_tbit_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_tbit_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldc_gbr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldc_gbr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldc_sr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldc_sr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_set_sr_bit_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_set_sr_bit_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_pr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_use_pr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_pr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_load_pr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_sts_pr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_sts_pr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_lds_pr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_lds_pr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_memory_access_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_memory_access_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_logic_b_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_logic_b_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_jsr_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_jsr_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_jmp_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_jmp_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_sx_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_sx_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (sh2e_cpu *cpu, const struct sh2e_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_add_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_add_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_addi_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_addi_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_addc_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_addc_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_addv_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_addv_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_and_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_and_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_andi_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_andi_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_andb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_andb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bf_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bf_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bfs_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bfs_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bra_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bra_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_braf_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_braf_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bsr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bsr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bsrf_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bsrf_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bt_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bt_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bts_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_bts_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_clrmac_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_clrmac_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_clrt_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_clrt_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpeq_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpeq_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpeqi_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpeqi_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpge_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpge_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpgt_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpgt_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmphi_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmphi_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmphs_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmphs_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmppl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmppl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmppz_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmppz_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpstr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_cmpstr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_div0s_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_div0s_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_div0u_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_div0u_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_div1_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_div1_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_dmulsl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_dmulsl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_dmulul_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_dmulul_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_dt_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_dt_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extsb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extsb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extsw_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extsw_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extub_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extub_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extuw_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_extuw_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fabs_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fabs_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fadd_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fadd_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fcmpeq_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fcmpeq_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fcmpgt_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fcmpgt_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fdiv_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fdiv_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_flds_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_flds_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fldi0_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fldi0_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fldi1_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fldi1_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_float_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_float_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmac_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmac_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov1_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov1_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov2_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov2_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov3_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov3_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov4_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov4_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov5_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov5_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov6_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov6_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov7_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmov7_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmul_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fmul_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fneg_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fneg_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_frchg_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_frchg_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fschg_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fschg_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fsts_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fsts_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fsub_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_fsub_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ftrc_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ftrc_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_jmp_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_jmp_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_jsr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_jsr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldc_gbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldc_gbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldc_vbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldc_vbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldc_sr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldc_sr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldcl_gbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldcl_gbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldcl_vbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldcl_vbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_fpscr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_fpscr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_fpscr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_fpscr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_fpul_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_fpul_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_fpul_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_fpul_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_mach_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_mach_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_mach_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_mach_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_macl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_macl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_macl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_macl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_pr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_lds_pr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_pr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ldsl_pr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_macl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_macl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_macw_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_macw_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mov_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mov_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movi_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movi_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb1_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb1_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb2_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb2_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb3_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb3_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb4_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb4_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb5_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb5_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb6_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb6_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb7_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb7_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb8_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb8_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb9_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb9_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb10_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movb10_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl1_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl1_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl2_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl2_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl3_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl3_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl4_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl4_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl5_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl5_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl6_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl6_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl7_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl7_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl8_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl8_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl9_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl9_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl10_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl10_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl11_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movl11_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw1_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw1_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw2_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw2_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw3_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw3_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw4_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw4_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw5_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw5_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw6_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw6_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw7_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw7_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw8_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw8_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw9_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw9_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw10_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw10_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw11_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movw11_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mova_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mova_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movt_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_movt_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mull_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mull_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mulsw_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_mulsw_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_muluw_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_muluw_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_neg_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_neg_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_negc_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_negc_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_nop_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_nop_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_not_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_not_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_or_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_or_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ori_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_ori_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_orb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_orb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotcl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotcl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotcr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotcr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rotr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rts_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_rts_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sett_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sett_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shal_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shal_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shar_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shar_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll2_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll2_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll8_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll8_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll16_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shll16_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr2_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr2_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr8_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr8_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr16_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_shlr16_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stc_gbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stc_gbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stc_vbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stc_vbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stcl_gbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stcl_gbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stcl_vbr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stcl_vbr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_fpscr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_fpscr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_fpscr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_fpscr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_fpul_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_fpul_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_fpul_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_fpul_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_mach_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_mach_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_mach_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_mach_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_macl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_macl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_macl_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_macl_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_pr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sts_pr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_pr_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_stsl_pr_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sub_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_sub_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_subc_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_subc_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_subv_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_subv_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_swapb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_swapb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_swapw_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_swapw_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tasb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tasb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_trapa_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_trapa_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tst_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tst_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tsti_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tsti_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tstb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_tstb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xor_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xor_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xori_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xori_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xorb_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xorb_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xtrct_compact_before (sh2e_cpu *current_cpu, sh2e_scache *sem);
  UINT model_xtrct_compact_after (sh2e_cpu *current_cpu, sh2e_scache *sem);

  /* Enum declaration for unit types.  */
typedef enum unit_number {
  UNIT_NONE, UNIT_U_FCNV, UNIT_U_FCMP, UNIT_U_FSQRT
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

  static const int MAX_UNITS = 6;

  typedef UINT (sh2e_sh2e_model::*model_function) (sh2e_cpu* current_cpu, sh2e_scache* sem);

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

} // namespace sh2e

#endif // SH2E_MODEL_H
