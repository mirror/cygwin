/* Simulator model support for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEP_MODEL_H
#define MEP_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace mep_basic
{
using namespace cgen;

class mep_mep_model : public cgen_model
{
public:
  mep_mep_model (mep_basic_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (mep_basic_cpu *current_cpu, mep_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (mep_basic_cpu *current_cpu, mep_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_store_ctrl_reg_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, INT /*storereg*/)
    {
      return 0;
    }
  virtual UINT model_u_store_ctrl_reg_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced, INT /*storereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_ctrl_reg_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_ctrl_reg_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gpr_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gpr_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mul_gpr_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, INT /*resultreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mul_gpr_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced, INT /*resultreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_gpr_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_gpr_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gpr_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gpr_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stcb_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stcb_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_divide_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_divide_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (mep_basic_cpu *cpu, const struct mep_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.
  UINT model_stcb_r_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stcb_r_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldcb_r_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldcb_r_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_pref_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_pref_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_prefd_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_prefd_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_casb3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_casb3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_cash3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_cash3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_casw3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_casw3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbucpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhucpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_uci_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_uci_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_dsp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_dsp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sb_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sb_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sh_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sh_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lb_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lb_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lh_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lh_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw_sp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw_sp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw_sp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw_sp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sb_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sb_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sh_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sh_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lb_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lb_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lh_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lh_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbu_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbu_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhu_tp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhu_tp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sb16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sb16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sh16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sh16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lb16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lb16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lh16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lh16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbu16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbu16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhu16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhu16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw24_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sw24_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw24_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lw24_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_extb_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_extb_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_exth_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_exth_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_extub_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_extub_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_extuh_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_extuh_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ssarb_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ssarb_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mov_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mov_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movi8_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movi8_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movi16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movi16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movu24_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movu24_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movu16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movu16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movh_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_movh_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add3i_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add3i_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_advck3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_advck3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sub_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sub_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbvck3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbvck3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_neg_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_neg_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slt3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slt3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sltu3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sltu3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slt3i_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slt3i_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sltu3i_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sltu3i_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sl1ad3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sl1ad3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sl2ad3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sl2ad3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add3x_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_add3x_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slt3x_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slt3x_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sltu3x_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sltu3x_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_or_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_or_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_and_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_and_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_xor_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_xor_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_nor_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_nor_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_or3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_or3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_and3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_and3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_xor3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_xor3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sra_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sra_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_srl_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_srl_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sll_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sll_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_srai_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_srai_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_srli_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_srli_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slli_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_slli_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sll3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sll3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_fsft_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_fsft_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bra_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bra_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_beqz_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_beqz_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bnez_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bnez_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_beqi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_beqi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bnei_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bnei_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_blti_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_blti_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bgei_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bgei_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_beq_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_beq_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bne_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bne_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsr12_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsr12_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsr24_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsr24_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jmp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jmp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jmp24_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jmp24_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jsr_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jsr_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ret_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ret_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_repeat_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_repeat_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_erepeat_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_erepeat_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_lp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_lp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_hi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_hi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_lo_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_lo_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stc_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_lp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_lp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_hi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_hi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_lo_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_lo_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldc_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_di_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_di_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ei_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ei_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_reti_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_reti_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_halt_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_halt_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sleep_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sleep_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_break_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_break_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_syncm_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_syncm_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stcb_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_stcb_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldcb_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldcb_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsetm_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsetm_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bclrm_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bclrm_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bnotm_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bnotm_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_btstm_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_btstm_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_tas_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_tas_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_cache_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_cache_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mul_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mul_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mulu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mulu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mulr_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mulr_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mulru_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_mulru_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_madd_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_madd_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maddu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maddu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maddr_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maddr_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maddru_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maddru_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_div_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_div_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_divu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_divu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_dret_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_dret_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_dbreak_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_dbreak_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldz_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ldz_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_abs_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_abs_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ave_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ave_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_min_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_min_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_max_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_max_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_minu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_minu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maxu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_maxu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_clip_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_clip_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_clipu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_clipu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sadd_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sadd_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ssub_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ssub_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_saddu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_saddu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ssubu_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ssubu_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpi_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpi_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcp16_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcp16_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpa_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpa_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpm0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpm0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sbcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lbcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_shcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lhcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_swcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lwcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_smcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpm1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_lmcpm1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpeq_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpeq_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpne_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpne_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpat_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpat_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpaf_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bcpaf_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_synccp_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_synccp_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jsrv_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_jsrv_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsrv_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_bsrv_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sim_syscall_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_sim_syscall_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_0_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_0_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_1_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_1_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_2_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_2_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_3_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_3_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_4_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_4_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_5_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_5_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_6_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_6_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_7_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_7_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_8_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_8_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_9_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_9_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_10_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_10_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_11_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_11_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_12_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_12_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_13_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_13_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_14_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_14_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_15_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_15_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_17_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_17_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_20_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_20_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_21_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_21_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_22_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_22_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_23_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_23_after (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_26_before (mep_basic_cpu *current_cpu, mep_scache *sem);
  UINT model_ri_26_after (mep_basic_cpu *current_cpu, mep_scache *sem);

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

  static const int MAX_UNITS = 5;

  typedef UINT (mep_mep_model::*model_function) (mep_basic_cpu* current_cpu, mep_scache* sem);

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

} // namespace mep_basic

#endif // MEP_MODEL_H
