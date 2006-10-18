// sh5_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Sh5 insn modelling functions

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH5_MODEL_H
#define SH5_MODEL_H

namespace sh5
{
  class sh5_cpu;
};

#include "ansidecl.h"
#include "sidconfig.h"
#include "sidtypes.h"
#include "sidcomp.h"
#include "cgen-types.h"
#include "cgen-engine.h"
#include "sh-desc.h"
#include "sh5-media-decode.h"
#include "sh5-media-model.h"
#include "common_model.h"

using namespace cgen;
using namespace sh5;
using namespace sh5_media;

#define SH5_MEDIA_MODEL_BASE sh_common_model_with_fp<sh5_media_sh5_media_model,sh5_cpu,sh5_media_idesc,sh5_media_scache>

class sh5_media_model : public SH5_MEDIA_MODEL_BASE
{
public:
  sh5_media_model (sh5_cpu* cpu);

protected:
  virtual int num_gpr () const { return 64; }
  virtual int num_fpr () const { return 64; }

public:
  // Custom overrides of functions generated for the BASE model.
  virtual UINT model_u_fpu_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num);
  virtual UINT model_u_memory_access_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num);
  virtual UINT model_u_use_fp_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_use_fv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_use_mtrx_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_use_tr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_fdiv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg);
  virtual UINT model_u_fdivd_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg);
  virtual UINT model_u_fsqrt_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg);
  virtual UINT model_u_fsqrtd_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT loadreg);
  virtual UINT model_u_set_fr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_set_dr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_set_fp_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_set_fv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_set_mtrx_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_load_fr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_load_dr_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_load_fp_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_load_fv_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_load_mtrx_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*loadreg*/);
  virtual UINT model_u_blink_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*targetreg*/);
  virtual UINT model_u_cond_branch_before (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, INT /*targetreg*/);

  virtual UINT model_u_fpu_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_memory_access_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_getcfg_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_putcfg_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_set_gr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_fr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_dr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_fp_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_fv_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_set_mtrx_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_gr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_fr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_dr_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_fp_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_fv_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_load_mtrx_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_fdiv_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_fdivd_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_fsqrt_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_fsqrtd_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_ftrvs_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT loadreg);
  virtual UINT model_u_pt_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT targetreg);
  virtual UINT model_u_blink_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT targetreg);
  virtual UINT model_u_cond_branch_after (sh5_cpu *cpu, const sh5_media_idesc *idesc, int unit_num, unsigned long long referenced, INT targetreg);

  virtual void step_latency (sid::host_int_4 cycles);

  // Called after each insn is executed. last_p is
  // true when the insn is the last of a group of parallel insns. cycles is the
  // number of cycles used by each particular insn.
  virtual void model_insn_after (bool last_p = true, sid::host_int_4 cycles = 1);

protected:
  void advance_latency (sid::host_int_4 latency);
  void set_dr_busy (INT reg, UINT cycles);
  void set_fp_busy (INT reg, UINT cycles);
  void set_fv_busy (INT reg, UINT cycles);
  void set_mtrx_busy (INT reg, UINT cycles);
  void set_tr_busy (INT reg, UINT cycles);
  void set_fdiv_busy (UINT cycles);
  void set_fdivd_busy (UINT cycles);
  void set_fsqrt_busy (UINT cycles);
  void set_fsqrtd_busy (UINT cycles);
  void set_result_bank_busy (INT bank_size, INT reg, UINT cycles);
  void set_memory_access_busy (UINT cycles);
  void reset_pt_gap (INT reg);

protected:
  sid::host_int_8 memory_access_pre_execution_latency;
  sid::host_int_4 dr_busy[32];
  sid::host_int_4 fp_busy[32];
  sid::host_int_4 fv_busy[16];
  sid::host_int_4 mtrx_busy[4];
  sid::host_int_4 result_reg_busy[64];
  sid::host_int_4 tr_busy_for_branch[8];
  sid::host_int_4 tr_busy_for_gettr[8];
  sid::host_int_4 fdiv_busy;
  sid::host_int_4 fdivd_busy;
  sid::host_int_4 fsqrt_busy;
  sid::host_int_4 fsqrtd_busy;

  static const int PT_GAP_MAX = 5;
  int pt_gap[8];
};

#endif /*  SH5_MODEL_H */
