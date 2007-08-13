// common_model.h - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Common insn modelling functions for the 'mep' model.

// Copyright (C) 2003, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_COMMON_MODEL_H
#define MEP_COMMON_MODEL_H

#include <sidtypes.h>
#include "cgen-types.h"

using namespace cgen;

// This class is always a subclass of mep*_model and provides the common implementation.
template <class BASE, class CPU, class IDESC, class SCACHE>
class mep_common_model : public BASE
{
public:
  mep_common_model (CPU* cpu) :
    BASE (cpu),
    current_stall (0),
    divide_busy (0),
    multiply_busy (0),
    ldcb_busy (0),
    save_total_latency (0)
  {
    for (int i = 0; i < num_gpr; ++i)
      gpr_busy[i] = 0;
    for (int i = 0; i < num_ctrl_reg; ++i)
      ctrl_reg_busy[i] = 0;
  }

  // Called before each insn where first_p is true if the insn is the
  // first in a group of parallel insns.
  // This is an override of the method in cgen_model (cgen-model.h).
  // Toshiba wants insn fetch latency counted as part of the insns
  // execution cycles rather than as cycles before execution.
  virtual void model_insn_before (bool first_p = true)
  {
    if (first_p)
      this->vliw_cycles = 1;
  }

  // This is called before each insn.
  // Overrides the one defined by the BASE model.
  // Returns the number of cycles which the cpu must stall
  virtual UINT model_before (CPU *current_cpu, SCACHE *sem)
    {
      assert (sem);
      BASE::model_before (current_cpu, sem);
      sid::host_int_4 stall = this->current_stall;
      return stall;
    } 

  // Custom overrides of functions generated for the BASE model.
  virtual UINT model_u_multiply_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_divide_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_ldcb_before (CPU *cpu, const IDESC *idesc, int unit_num);
  virtual UINT model_u_use_ctrl_reg_before (CPU *cpu, const IDESC *idesc, int unit_num, INT /*usereg*/);
  virtual UINT model_u_store_ctrl_reg_before (CPU *cpu, const IDESC *idesc, int unit_num, INT storereg)
    { return this->model_u_use_ctrl_reg_before (cpu, idesc, unit_num, storereg); }
  virtual UINT model_u_use_gpr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT /*usereg*/);

  virtual UINT model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_multiply_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_divide_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_stcb_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced);
  virtual UINT model_u_load_gpr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_ldcb_gpr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/);
  virtual UINT model_u_mul_gpr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT /*resultreg*/);

  virtual void step_latency (sid::host_int_4 cycles);

private:
  void set_gpr_busy (INT reg, sid::host_int_4 cycles)
  {
    if (gpr_busy[reg] < cycles)
      gpr_busy[reg] = cycles;
  }

  void set_ctrl_reg_busy (INT reg, sid::host_int_4 cycles)
  {
    if (ctrl_reg_busy[reg] < cycles)
      ctrl_reg_busy[reg] = cycles;
  }

  void set_divide_busy (sid::host_int_4 cycles)
  {
    if (divide_busy < cycles)
      divide_busy = cycles;
  }

  void set_multiply_busy (sid::host_int_4 cycles)
  {
    if (multiply_busy < cycles)
      multiply_busy = cycles;
  }

  void set_ldcb_busy (sid::host_int_4 cycles)
  {
    if (ldcb_busy < cycles)
      ldcb_busy = cycles;
  }

  void set_current_stall (sid::host_int_4 cycles)
  {
    if (current_stall < cycles)
      current_stall = cycles;
  }

  UINT u_exec_cycles (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
  {
    for (int u = 0; u < BASE::MAX_UNITS; ++u)
      {
	if (this->timing[idesc->sem_index].units[u].unit == BASE::UNIT_U_EXEC)
	  return this->model_u_exec_after (cpu, idesc, u, referenced);
      }
    return 0;
  }

  static const int num_gpr = 16;
  static const int CTRL_HI = 7;
  static const int CTRL_LO = 8;
  static const int num_ctrl_reg = 32;

  sid::host_int_4 current_stall;
  sid::host_int_4 divide_busy;
  sid::host_int_4 multiply_busy;
  sid::host_int_4 ldcb_busy;
  sid::host_int_4 ctrl_reg_busy[num_ctrl_reg];
  sid::host_int_4 gpr_busy[num_gpr];
  sid::host_int_8 save_total_latency;
};

#endif /*  MEP_COMMON_MODEL_H */
