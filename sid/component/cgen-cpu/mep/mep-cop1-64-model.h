/* Simulator model support for mepcop1_64.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP1_64_MODEL_H
#define MEPCOP1_64_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace mep_ext1
{
using namespace cgen;

class mepcop1_64_mep_model : public cgen_model
{
public:
  mepcop1_64_mep_model (mep_ext1_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_store_ctrl_reg_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, INT /*storereg*/)
    {
      return 0;
    }
  virtual UINT model_u_store_ctrl_reg_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced, INT /*storereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_ctrl_reg_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_ctrl_reg_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mul_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, INT /*resultreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mul_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced, INT /*resultreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gpr_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gpr_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stcb_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stcb_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_divide_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_divide_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (mep_ext1_cpu *cpu, const struct mepcop1_64_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_cpadd3_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadd3_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadd3_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadd3_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadd3_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadd3_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpacku_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpacku_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpacku_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpacku_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpacku_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpacku_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpackl_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpackl_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpackl_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpackl_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpackl_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpunpackl_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsel_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsel_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfsftbs0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfsftbs0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfsftbs1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfsftbs1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmov_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmov_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsz_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsz_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsz_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsz_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsz_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsz_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpldz_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpldz_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpldz_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpldz_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpnorm_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpnorm_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpnorm_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpnorm_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphaddu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphaddu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphadd_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphadd_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphadd_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphadd_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphadd_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cphadd_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpccadd_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpccadd_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpbcast_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpbcast_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpbcast_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpbcast_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpbcast_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpbcast_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextl_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextl_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlu_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlu_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextl_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextl_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastub_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastub_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastb_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastb_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastub_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastub_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastb_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastb_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastuh_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcastuh_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcasth_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcasth_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdcastuw_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdcastuw_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdcastw_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdcastw_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovfrcsar0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovfrcsar0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovfrcsar1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovfrcsar1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovfrcc_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovfrcc_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovtocsar0_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovtocsar0_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovtocsar1_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovtocsar1_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovtocc_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovtocc_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeqz_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeqz_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeq_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeq_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeq_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeq_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeq_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpeq_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpne_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpne_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpne_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpne_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpne_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpne_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgtu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgtu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgt_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgt_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgt_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgt_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgtu_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgtu_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgt_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgt_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgeu_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgeu_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpge_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpge_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpge_h_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpge_h_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgeu_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpgeu_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpge_w_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpcmpge_w_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfsftbi_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfsftbi_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpeq_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpeq_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpeq_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpeq_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpeq_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpeq_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpne_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpne_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpne_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpne_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpne_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpne_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgtu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgtu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgt_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgt_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgt_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgt_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgtu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgtu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgt_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgt_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgeu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgeu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpge_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpge_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpge_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpge_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgeu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpgeu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpge_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacmpge_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpeq_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpeq_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpeq_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpeq_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpeq_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpeq_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpne_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpne_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpne_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpne_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpne_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpne_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgtu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgtu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgt_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgt_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgt_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgt_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgtu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgtu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgt_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgt_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgeu_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgeu_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpge_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpge_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpge_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpge_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgeu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpgeu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpge_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpocmpge_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdadd3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdadd3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsub3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsub3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsub3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsub3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsub3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsub3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadd3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadd3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadd3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadd3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssub3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssub3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssub3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssub3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuaddu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuaddu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuadd3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextuadd3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextladdu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextladdu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextladd3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextladd3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextusubu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextusubu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextusub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextusub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlsubu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlsubu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlsub3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpextlsub3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaveu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaveu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpave3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpave3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpave3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpave3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpave3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpave3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsru3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsru3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsr3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsr3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsr3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsr3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsr3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddsr3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabs3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabs3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabs3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabs3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpand3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpand3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpnor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpnor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpxor3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpxor3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppacku_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppacku_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppack_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppack_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppack_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppack_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmaxu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmaxu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmax3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmax3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmax3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmax3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmaxu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmaxu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmax3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmax3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpminu3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpminu3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmin3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmin3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmin3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmin3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpminu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpminu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmin3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmin3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrl3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrl3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssrl3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssrl3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrl3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrl3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssrl3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssrl3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrl3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrl3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssrl3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssrl3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsrl3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsrl3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsra3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsra3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssra3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssra3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsra3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsra3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssra3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssra3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsra3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsra3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssra3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssra3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsra3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsra3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsll3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsll3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssll3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssll3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsll3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsll3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssll3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssll3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsll3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsll3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssll3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssll3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsll3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsll3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsla3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsla3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsla3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsla3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrli3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrli3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrli3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrli3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrli3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrli3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsrli3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsrli3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrai3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrai3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrai3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrai3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrai3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrai3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsrai3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdsrai3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslli3_b_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslli3_b_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslli3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslli3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslli3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslli3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdslli3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdslli3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslai3_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslai3_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslai3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslai3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpclipiu3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpclipiu3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpclipi3_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpclipi3_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdclipiu3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdclipiu3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdclipi3_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdclipi3_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovi_h_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovi_h_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmoviu_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmoviu_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovi_w_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovi_w_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdmoviu_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdmoviu_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdmovi_P0_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cdmovi_P0_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_c1nop_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_c1nop_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovi_b_P0S_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovi_b_P0S_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadda1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadda1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadda1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpadda1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddaca1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddaca1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddaca1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddaca1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddacua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddacua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddacla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaddacla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsuba1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsuba1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsuba1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsuba1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubaca1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubaca1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubaca1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubaca1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubacua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubacua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubacla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsubacla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsa1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsa1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsa1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsa1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpabsla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsada1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsada1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsada1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsada1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsadla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpseta1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpseta1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsetua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsetua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsetla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsetla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmova1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmova1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovuua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovuua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovula1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovula1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovlua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovlua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovlla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovlla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppacka1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppacka1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppacka1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppacka1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cppackla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovhua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovhua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovhla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmovhla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacsuma1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacsuma1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaccpa1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpaccpa1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacswp_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpacswp_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrla1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrla1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsraa1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsraa1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslla1_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpslla1_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrlia1_1_p1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsrlia1_1_p1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsraia1_1_p1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsraia1_1_p1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsllia1_1_p1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsllia1_1_p1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s0u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s0u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s0_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s0_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmuliua1s0_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmuliua1s0_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulila1s0_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulila1s0_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s0u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s0u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s0_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s0_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadiua1s0_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadiua1s0_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadila1s0_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadila1s0_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1s1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmuliua1s1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmuliua1s1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulila1s1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulila1s1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1s1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadiua1s1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadiua1s1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadila1s1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadila1s1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamulia1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamulia1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamulia1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamulia1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamuliua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamuliua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamulila1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamulila1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadia1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadia1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadia1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadia1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadiua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadiua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadila1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpamadila1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulia1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmuliua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmuliua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulila1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmulila1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadia1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadiua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadiua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadila1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpfmadila1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssqa1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssqa1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssqa1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssqa1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssda1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssda1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssda1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpssda1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmula1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmula1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmula1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmula1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulua1u_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulua1u_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulla1u_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulla1u_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmada1u_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmada1u_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmada1_b_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmada1_b_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadua1u_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadua1u_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadla1u_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadla1u_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmadla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbua1u_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbua1u_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbla1u_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbla1u_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmsbla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpmulslla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmadslla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslua1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslua1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslla1_h_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslla1_h_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslua1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslua1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslla1_w_P1_before (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);
  UINT model_cpsmsbslla1_w_P1_after (mep_ext1_cpu *current_cpu, mepcop1_64_scache *sem);

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

  typedef UINT (mepcop1_64_mep_model::*model_function) (mep_ext1_cpu* current_cpu, mepcop1_64_scache* sem);

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

#endif // MEPCOP1_64_MODEL_H
