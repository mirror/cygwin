// common_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Common insn modelling functions for all sh models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH_COMMON_MODEL_H
#define SH_COMMON_MODEL_H

#include <sidtypes.h>
#include "cgen-types.h"

using namespace cgen;

// This class is always a subclass of sh*_sh*_model and provides the common implementation.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
class sh_common_model : public BASE
{
public:
  sh_common_model (CPU* cpu);

  // This is called before each insn.
  // Overrides the one defined by the BASE model.
  // Returns the number of cycles which the cpu must stall
  virtual UINT model_before (CPU *current_cpu, SCACHE *sem);

  // Custom overrides of functions generated for the BASE model.
  virtual UINT model_u_use_gr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_use_pr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_tbit_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_multiply_result_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_exec_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_sx_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_logic_b_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_vbr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_sts_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_lds_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_tas_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_jmp_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_jsr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_pr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_use_multiply_result_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_multiply_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mulsw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);

  virtual void step_latency (sid::host_int_4 cycles = 0);
  void reduce_saved_latency (sid::host_int_4 l = 1) { this->save_total_latency -= l; }
  // NOTE: May not be necessary once sh5 is implemented
  virtual void branch_stall () {}

protected:
  #define MODEL_ADVANCE_LATENCY(x, latency) ((x) = UNLIKELY ((x) > (latency)) ? (x) - (latency) : 0)
  void advance_latency (sid::host_int_4 latency);
  void set_current_stall (sid::signed_host_int_4 cycles);
  void set_pr_busy (sid::signed_host_int_4 cycles);
  void set_gpr_busy (INT reg, sid::signed_host_int_4 cycles);
  void add_memory_access_busy (sid::signed_host_int_4 cycles);
  void add_multiply_busy (sid::signed_host_int_4 cycles);
  void set_fpu_busy (sid::signed_host_int_4 cycles); // some machines use fpu for integer multiply

  UINT model_mac_after (CPU *cpu, UINT multiply_latency);

  UINT unit_cycles (const IDESC *idesc, int unit);
  bool pc_aligned_in_insn_buffer (CPU *cpu);
  virtual sid::host_int_4 check_if_ma_conflict (sid::host_int_4 stall);

  virtual int num_gpr () const { return 16; }

  CPU *cpu;
  sid::host_int_4 current_stall;
  sid::host_int_4 memory_access_busy;
  sid::host_int_4 multiply_busy;
  sid::host_int_4 fpu_busy;
  sid::host_int_4 tbit_busy;
  sid::host_int_4 pr_busy;
  sid::host_int_4 gpr_busy[64];
  sid::host_int_8 save_total_latency;
  UINT            exec_cycles;
};

// This class adds a floating point common model to the basic common model.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
class sh_common_model_with_fp : public sh_common_model<BASE,CPU,IDESC,SCACHE>
{
public:
  sh_common_model_with_fp (CPU* cpu);

  virtual UINT model_u_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_maybe_fpu_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_fr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_use_fpul_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_fpscr_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_flds_fpul_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_fdiv_before (CPU *cpu, const IDESC *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_fsqrt_before (CPU *cpu, const IDESC *idesc, int unit_num, INT /*loadreg*/);

  virtual UINT model_u_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_maybe_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fcnv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fpu_memory_access_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_fr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_dr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_fr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_fr_0_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fpu_load_gr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_flds_fpul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_lds_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldsl_fpscr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fdiv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_fsqrt_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);

  virtual void step_latency (sid::host_int_4 cycles = 0);

protected:
  void advance_latency (sid::host_int_4 latency);
  void set_fpr_busy (INT reg, sid::signed_host_int_4 cycles);
  void set_fpul_busy (sid::signed_host_int_4 cycles);
  void set_fpscr_busy (sid::signed_host_int_4 cycles);

  virtual int num_fpr () const { return 16; }

  sid::host_int_4 fpul_busy;
  sid::host_int_4 fpscr_busy;
  sid::host_int_4 fpr_busy[64];
};

// This class adds a vliw pipeline to the common model with floating point.
// TODO: This is really sh2a-specific and only used by sh2a.
//
template <class BASE, class CPU, class IDESC, class SCACHE>
class sh_common_model_with_vliw : public BASE
{
public:
  sh_common_model_with_vliw (CPU* cpu);

  virtual UINT model_u_shift_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_shift_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);

  virtual void step_latency (sid::host_int_4 cycles = 0);

protected:
  void advance_latency (sid::host_int_4 latency);
  void set_shift_busy (sid::signed_host_int_4 cycles);

  sid::host_int_4 shift_busy;
};

#endif /*  SH_COMMON_MODEL_H */
