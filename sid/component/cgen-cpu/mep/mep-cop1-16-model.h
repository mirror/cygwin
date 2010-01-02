/* Simulator model support for mepcop1_16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP1_16_MODEL_H
#define MEPCOP1_16_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace mep_ext1
{
using namespace cgen;

class mepcop1_16_mep_model : public cgen_model
{
public:
  mepcop1_16_mep_model (mep_ext1_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_store_ctrl_reg_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, INT /*storereg*/)
    {
      return 0;
    }
  virtual UINT model_u_store_ctrl_reg_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*storereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_ctrl_reg_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_ctrl_reg_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mul_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, INT /*resultreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mul_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*resultreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stcb_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stcb_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_divide_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_divide_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (mep_ext1_cpu *cpu, const struct mepcop1_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_c0nop_P0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_c0nop_P0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadd3_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadd3_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadd3_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadd3_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadd3_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadd3_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpacku_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpacku_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpacku_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpacku_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpacku_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpacku_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpackl_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpackl_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpackl_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpackl_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpackl_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpunpackl_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsel_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsel_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbs0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbs0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbs1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbs1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmov_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmov_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsz_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsz_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsz_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsz_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsz_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsz_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpldz_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpldz_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpldz_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpldz_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpnorm_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpnorm_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpnorm_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpnorm_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphaddu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphaddu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphadd_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphadd_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphadd_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphadd_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphadd_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cphadd_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpccadd_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpccadd_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpbcast_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpbcast_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpbcast_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpbcast_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpbcast_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpbcast_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextuu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextuu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextuu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextuu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextlu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextlu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextl_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextl_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextlu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextlu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextl_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpextl_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastub_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastub_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastb_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastb_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastub_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastub_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastb_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastb_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastuh_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcastuh_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcasth_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcasth_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cdcastuw_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cdcastuw_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cdcastw_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cdcastw_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovfrcsar0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovfrcsar0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovfrcsar1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovfrcsar1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovfrcc_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovfrcc_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovtocsar0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovtocsar0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovtocsar1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovtocsar1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovtocc_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovtocc_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeqz_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeqz_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeq_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeq_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeq_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeq_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeq_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpeq_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpne_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpne_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpne_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpne_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpne_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpne_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgtu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgtu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgt_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgt_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgt_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgt_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgtu_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgtu_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgt_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgt_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgeu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgeu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpge_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpge_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpge_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpge_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgeu_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpgeu_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpge_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpcmpge_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadda0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadda0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadda0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpadda0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddaca0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddaca0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddaca0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddaca0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddacua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddacua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddacla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaddacla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsuba0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsuba0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsuba0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsuba0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubaca0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubaca0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubaca0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubaca0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubacua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubacua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubacla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsubacla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsa0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsa0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsa0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsa0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpabsla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsada0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsada0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsada0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsada0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsadua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsadua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsadla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsadla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpseta0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpseta0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsetua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsetua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsetla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsetla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmova0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmova0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovuua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovuua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovula0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovula0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovlua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovlua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovlla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovlla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppacka0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppacka0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppacka0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppacka0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackua0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackua0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackla0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackla0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cppackla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovhua0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovhua0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovhla0_w_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovhla0_w_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpacsuma0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpacsuma0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaccpa0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpaccpa0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsrla0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsrla0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsraa0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsraa0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpslla0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpslla0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsrlia0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsrlia0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsraia0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsraia0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsllia0_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpsllia0_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbua0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbua0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbla0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbla0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s0u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s0u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s0_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s0_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacua0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacua0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacla0s0_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacla0s0_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s1u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s1u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s1_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftba0s1_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbua0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbua0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbla0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfsftbla0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s1u_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s1u_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s1_b_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfaca0s1_b_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacua0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacua0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacla0s1_h_P0S_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpfacla0s1_h_P0S_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovi_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);
  UINT model_cpmovi_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_16_scache *sem);

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

  typedef UINT (mepcop1_16_mep_model::*model_function) (mep_ext1_cpu* current_cpu, mepcop1_16_scache* sem);

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

#endif // MEPCOP1_16_MODEL_H
