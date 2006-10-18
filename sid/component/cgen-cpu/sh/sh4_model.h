// sh4_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Common insn modelling functions for all sh models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH4_MODEL_IMPL_H
#define SH4_MODEL_IMPL_H

#include "sh2a_model.h"

// Common model for sh4 and sh4_nofpu
//
template <class BASE, class CPU, class IDESC>
class sh4_model : public BASE
{
public:
  sh4_model (CPU* cpu);

  virtual UINT model_u_sx_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_logic_b_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_tas_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ldc_gbr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ldc_sr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ldcl_vbr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ldcl_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_stc_vbr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_lds_pr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_sts_pr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_jsr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_write_back_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_set_mac_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_load_mac_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_dmul_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_mull_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_mulsw_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_macw_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_macl_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ocb_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_sx_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_logic_b_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldc_gbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_stc_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_lds_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_sts_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_jsr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_set_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_write_back_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mulsw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ocb_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);

  virtual void step_latency (sid::host_int_4 cycles = 0);

protected:
  void advance_latency (sid::host_int_4 latency);

  // Some cpu insns use the fpu pipeline
  void add_fpu_busy (sid::signed_host_int_4 cycles);
  void set_f1_busy (sid::signed_host_int_4 cycles);
  void set_sx_busy (sid::signed_host_int_4 cycles);

  sid::host_int_4 f1_busy;
  sid::host_int_4 sx_busy;
};

// Model for sh4 
//
using namespace sh4;

#define SH4_FPU_MODEL_BASE sh4_model<sh2a_fpu_model<sh_common_model_with_fp<sh4_sh4_model,sh4_cpu,sh4_idesc,sh4_scache>,sh4_cpu,sh4_idesc>,sh4_cpu,sh4_idesc>

template <class CPU, class IDESC>
class sh4_fpu_model : public SH4_FPU_MODEL_BASE
{
public:
  sh4_fpu_model (CPU* cpu);

  virtual UINT model_u_maybe_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_maybe_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
};

#endif // SH4_MODEL_IMPL_H
