/* Simulator model support for mepcop1_48.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP1_48_MODEL_H
#define MEPCOP1_48_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace mep_ext1
{
using namespace cgen;

class mepcop1_48_mep_model : public cgen_model
{
public:
  mepcop1_48_mep_model (mep_ext1_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_store_ctrl_reg_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, INT /*storereg*/)
    {
      return 0;
    }
  virtual UINT model_u_store_ctrl_reg_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced, INT /*storereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_ctrl_reg_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_ctrl_reg_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mul_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, INT /*resultreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mul_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced, INT /*resultreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stcb_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stcb_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_divide_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_divide_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (mep_ext1_cpu *cpu, const struct mepcop1_48_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_cmov_crn_rm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmov_crn_rm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmov_rn_crm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmov_rn_crm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovc_ccrn_rm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovc_ccrn_rm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovc_rn_ccrm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovc_rn_ccrm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovh_crn_rm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovh_crn_rm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovh_rn_crm_p0_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cmovh_rn_crm_p0_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_c0nop_P0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_c0nop_P0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpfsftbi_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpfsftbi_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpeq_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpeq_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpeq_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpeq_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpeq_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpeq_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpne_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpne_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpne_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpne_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpne_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpne_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgtu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgtu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgt_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgt_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgt_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgt_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgtu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgtu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgt_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgt_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgeu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgeu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpge_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpge_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpge_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpge_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgeu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpgeu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpge_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpacmpge_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpeq_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpeq_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpeq_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpeq_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpeq_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpeq_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpne_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpne_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpne_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpne_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpne_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpne_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgtu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgtu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgt_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgt_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgt_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgt_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgtu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgtu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgt_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgt_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgeu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgeu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpge_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpge_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpge_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpge_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgeu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpgeu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpge_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpocmpge_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdadd3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdadd3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsub3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsub3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsub3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsub3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsub3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsub3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsadd3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsadd3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsadd3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsadd3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssub3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssub3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssub3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssub3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextuaddu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextuaddu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextuadd3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextuadd3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextladdu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextladdu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextladd3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextladd3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextusubu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextusubu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextusub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextusub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextlsubu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextlsubu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextlsub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpextlsub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaveu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaveu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpave3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpave3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpave3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpave3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpave3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpave3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsru3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsru3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsr3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsr3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsr3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsr3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsr3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpaddsr3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpabsu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpabsu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpabs3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpabs3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpabs3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpabs3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpand3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpand3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpnor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpnor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpxor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpxor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cppacku_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cppacku_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cppack_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cppack_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cppack_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cppack_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmaxu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmaxu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmax3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmax3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmax3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmax3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmaxu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmaxu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmax3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmax3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpminu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpminu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmin3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmin3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmin3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmin3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpminu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpminu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmin3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmin3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrl3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrl3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssrl3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssrl3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrl3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrl3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssrl3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssrl3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrl3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrl3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssrl3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssrl3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsrl3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsrl3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsra3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsra3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssra3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssra3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsra3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsra3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssra3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssra3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsra3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsra3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssra3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssra3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsra3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsra3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsll3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsll3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssll3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssll3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsll3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsll3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssll3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssll3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsll3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsll3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssll3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpssll3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsll3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsll3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsla3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsla3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsla3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsla3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrli3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrli3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrli3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrli3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrli3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrli3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsrli3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsrli3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrai3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrai3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrai3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrai3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrai3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpsrai3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsrai3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdsrai3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslli3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslli3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslli3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslli3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslli3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslli3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdslli3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdslli3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslai3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslai3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslai3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpslai3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpclipiu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpclipiu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpclipi3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpclipi3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdclipiu3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdclipiu3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdclipi3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdclipi3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmovi_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmovi_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmoviu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmoviu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmovi_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cpmovi_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdmoviu_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdmoviu_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdmovi_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);
  UINT model_cdmovi_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_48_scache *sem);

  /* Enum declaration for unit types.  */
typedef enum unit_number {
  UNIT_NONE, UNIT_U_STORE_CTRL_REG, UNIT_U_USE_CTRL_REG, UNIT_U_USE_GPR
 , UNIT_U_MUL_GPR, UNIT_U_LDCB_GPR, UNIT_U_LOAD_GPR, UNIT_U_LDCB
 , UNIT_U_STCB, UNIT_U_DIVIDE, UNIT_U_MULTIPLY, UNIT_U_BRANCH
 , UNIT_U_EXEC, UNIT_MAX
} UNIT_NUMBER;

  struct unit {
    unit_number unit;
    UINT issue;
    UINT done;
  };

  static const int MAX_UNITS = 1;

  typedef UINT (mepcop1_48_mep_model::*model_function) (mep_ext1_cpu* current_cpu, mepcop1_48_scache* sem);

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

} // namespace mep_ext1

#endif // MEPCOP1_48_MODEL_H
