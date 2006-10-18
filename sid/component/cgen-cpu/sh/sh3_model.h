// sh3_model.h - Hand-written code for sh modelling. -*- C++ -*-

// Common insn modelling functions for all sh models.

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SH3_MODEL_IMPL_H
#define SH3_MODEL_IMPL_H

#include "common_model.h"

namespace sh3
{
  class sh3_idesc;
};

namespace sh3e
{
  class sh3e_idesc;
};

// Model for sh3
//
template <class BASE, class CPU, class IDESC>
class sh3_model : public BASE
{
public:
  sh3_model (CPU* cpu);

  virtual UINT model_u_use_tbit_before (CPU *cpu, const IDESC *idesc, int unit_num);

  virtual UINT model_u_set_sr_bit_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldc_sr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macw_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_macl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_dmul_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_mull_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_ldcl_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_trap_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);

  virtual void step_latency (sid::host_int_4 cycles = 0);

protected:
  void advance_latency (sid::host_int_4 latency);
  void set_sr_busy (sid::signed_host_int_4 cycles);

  bool insn_is_tstb (const sh3::sh3_idesc *idesc);
  bool insn_is_tstb (const sh3e::sh3e_idesc *idesc);

protected:
  sid::host_int_4 sr_busy;
};

// Model for sh3e
//
template <class BASE, class CPU, class IDESC>
class sh3e_model : public sh3_model<BASE,CPU,IDESC>
{
public:
  sh3e_model (CPU* cpu);

  virtual UINT model_u_fpu_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fcnv_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_fsqrt_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg);
};

#endif // SH3_MODEL_IMPL_H
