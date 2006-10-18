// sh2a_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Common insn modelling functions for all sh models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH2A_MODEL_H
#define SH2A_MODEL_H

#include "sh2a.h"
#include "common_model.h"

// Common model for sh2a_fpu and sh2a_nofpu
//
template <class BASE, class CPU, class IDESC>
class sh2a_model : public BASE
{
public:
  sh2a_model (CPU* cpu);

  virtual UINT model_u_memory_access_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_multiply_result_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_write_back_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mulr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_multiply_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_use_multiply_result_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mulsw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mulr_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_gbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_set_mac_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_write_back_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_trap_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);

  // TODO: May not need to be virtual
  virtual void branch_stall ();
  virtual void step_latency (sid::host_int_4 cycles = 0);

  bool parallel_possible (const IDESC *insn1, const IDESC *insn2);

protected:
  void advance_latency (sid::host_int_4 latency);
  bool uses_unit (const IDESC *idesc, int unit);

  #define FUNC_insn_is_ldsl_mac(namespace, upnamespace) \
  bool insn_is_ldsl_mac (const namespace::namespace##_idesc *idesc) \
    { \
      return (idesc->sem_index == namespace::upnamespace##_INSN_LDSL_MACH_COMPACT \
	      || idesc->sem_index == namespace::upnamespace##_INSN_LDSL_MACL_COMPACT); \
    }
  FUNC_insn_is_ldsl_mac (sh2a_fpu, SH2A_FPU);
  FUNC_insn_is_ldsl_mac (sh2a_nofpu, SH2A_NOFPU);
  FUNC_insn_is_ldsl_mac (sh4, SH4);
  FUNC_insn_is_ldsl_mac (sh4_nofpu, SH4_NOFPU);
  FUNC_insn_is_ldsl_mac (sh4a, SH4A);
  FUNC_insn_is_ldsl_mac (sh4a_nofpu, SH4A_NOFPU);
  FUNC_insn_is_ldsl_mac (sh4al, SH4AL);

  #define FUNC_insn_is_mulsw(namespace, upnamespace) \
  bool insn_is_mulsw (const namespace::namespace##_idesc *idesc) \
    { \
      return (idesc->sem_index == namespace::upnamespace##_INSN_MULSW_COMPACT \
	      || idesc->sem_index == namespace::upnamespace##_INSN_MULUW_COMPACT); \
    }
  FUNC_insn_is_mulsw (sh2a_fpu, SH2A_FPU);
  FUNC_insn_is_mulsw (sh2a_nofpu, SH2A_NOFPU);
  FUNC_insn_is_mulsw (sh4, SH4);
  FUNC_insn_is_mulsw (sh4_nofpu, SH4_NOFPU);
  FUNC_insn_is_mulsw (sh4a, SH4A);
  FUNC_insn_is_mulsw (sh4a_nofpu, SH4A_NOFPU);
  FUNC_insn_is_mulsw (sh4al, SH4AL);

  #define FUNC_insn_is_ldcl(namespace,upnamespace) \
  bool insn_is_ldcl (const namespace::namespace##_idesc *idesc) \
    { \
      return (idesc->sem_index == namespace::upnamespace##_INSN_LDCL_GBR_COMPACT \
	      || idesc->sem_index == namespace::upnamespace##_INSN_LDCL_VBR_COMPACT \
	      || idesc->sem_index == namespace::upnamespace##_INSN_STCL_GBR_COMPACT \
	      || idesc->sem_index == namespace::upnamespace##_INSN_STCL_VBR_COMPACT); \
    }
  FUNC_insn_is_ldcl (sh2a_fpu, SH2A_FPU);
  FUNC_insn_is_ldcl (sh2a_nofpu, SH2A_NOFPU);
  FUNC_insn_is_ldcl (sh4, SH4);
  FUNC_insn_is_ldcl (sh4_nofpu, SH4_NOFPU);
  FUNC_insn_is_ldcl (sh4a, SH4A);
  FUNC_insn_is_ldcl (sh4a_nofpu, SH4A_NOFPU);
  FUNC_insn_is_ldcl (sh4al, SH4AL);

  void set_memory_access_busy (sid::signed_host_int_4 cycles);
  void add_memory_access_busy (sid::signed_host_int_4 cycles);
  void set_multiply_busy (sid::signed_host_int_4 cycles);
  void add_multiply_busy (sid::signed_host_int_4 cycles);
  void set_write_back_busy (sid::signed_host_int_4 cycles);
  void set_gbr_busy (sid::signed_host_int_4 cycles);
  void set_vbr_busy (sid::signed_host_int_4 cycles);

  virtual sid::host_int_4 check_if_ma_conflict (sid::host_int_4 stall);

protected:
  sid::host_int_8 memory_access_pre_execution_latency;
  sid::host_int_4 write_back_busy;
  sid::host_int_4 gbr_busy;
  sid::host_int_4 vbr_busy;
  sid::host_int_4 current_branch_stall;
};

// Model for sh2a_fpu
//
using namespace sh2a_fpu;

#define SH2A_FPU_MODEL_BASE sh2a_model<BASE,CPU,IDESC>

template <class BASE, class CPU, class IDESC>
class sh2a_fpu_model : public SH2A_FPU_MODEL_BASE
{
public:
  sh2a_fpu_model (CPU* cpu);

  virtual UINT model_u_fpu_memory_access_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_fpul_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_lds_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_sts_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_dr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT usereg);

  virtual UINT model_u_fpu_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fpu_load_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_flds_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_fr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_set_fr_0_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_set_dr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_fdiv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_fcmp_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);

  virtual void step_latency (sid::host_int_4 cycles = 0);

protected:
  void advance_latency (sid::host_int_4 latency);
  void set_fpu_memory_access_busy (sid::signed_host_int_4 cycles);
  void add_fpu_memory_access_busy (sid::signed_host_int_4 cycles);
  void set_tbit_busy (sid::signed_host_int_4 cycles);

  #define FUNC_insn_is_sts_fpul(namespace, upnamespace) \
  bool insn_is_sts_fpul (const namespace::namespace##_idesc *idesc) \
    { \
      return (idesc->sem_index == namespace::upnamespace##_INSN_STS_FPUL_COMPACT); \
    }
  FUNC_insn_is_sts_fpul (sh2a_fpu, SH2A_FPU);
  FUNC_insn_is_sts_fpul (sh4, SH4);
  FUNC_insn_is_sts_fpul (sh4a, SH4A);

  #define FUNC_insn_is_stsl_fpul(namespace, upnamespace) \
  bool insn_is_stsl_fpul (const namespace::namespace##_idesc *idesc) \
    { \
      return (idesc->sem_index == namespace::upnamespace##_INSN_STSL_FPUL_COMPACT); \
    }
  FUNC_insn_is_stsl_fpul (sh2a_fpu, SH2A_FPU);
  FUNC_insn_is_stsl_fpul (sh4, SH4);
  FUNC_insn_is_stsl_fpul (sh4a, SH4A);

protected:
  sid::host_int_4 fpu_memory_access_busy;
};

#endif // SH2A_MODEL_H
