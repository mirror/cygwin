// sh4a_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Common insn modelling functions for all sh models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH4A_MODEL_IMPL_H
#define SH4A_MODEL_IMPL_H

#include "sh2a_model.h"

// Common model for sh4a and sh4a_nofpu
//
template <class BASE, class CPU, class IDESC>
class sh4a_model : public BASE
{
public:
  sh4a_model (CPU* cpu);

  virtual UINT model_u_write_back_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_set_mac_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_multiply_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_dmul_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_mull_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_jmp_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_jsr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_trap_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_set_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_write_back_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ocb_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
};

// Model for sh4a 
//
using namespace sh4a;

#define SH4A_FPU_MODEL_BASE sh4a_model<sh2a_fpu_model<sh_common_model_with_fp<sh4a_sh4a_model,sh4a_cpu,sh4a_idesc,sh4a_scache>,sh4a_cpu,sh4a_idesc>,sh4a_cpu,sh4a_idesc>

template <class CPU, class IDESC>
class sh4a_fpu_model : public SH4A_FPU_MODEL_BASE
{
public:
  sh4a_fpu_model (CPU* cpu);

  virtual UINT model_u_maybe_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_lds_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ldsl_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_maybe_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fdiv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_fsqrt_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
};

#endif // SH4A_MODEL_IMPL_H
