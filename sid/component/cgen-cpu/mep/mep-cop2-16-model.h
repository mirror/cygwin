/* Simulator model support for mepcop2_16.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef MEPCOP2_16_MODEL_H
#define MEPCOP2_16_MODEL_H

#include "cgen-cpu.h"
#include "cgen-model.h"

namespace mep_ext2
{
using namespace cgen;

class mepcop2_16_mep_model : public cgen_model
{
public:
  mepcop2_16_mep_model (mep_ext2_cpu *cpu);

  // Call the proper unit modelling function for the given insn.
  UINT model_before (mep_ext2_cpu *current_cpu, mepcop2_16_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_before)) (current_cpu, sem);
    } 
  UINT model_after (mep_ext2_cpu *current_cpu, mepcop2_16_scache* sem)
    {
      return (this->*(timing[sem->idesc->sem_index].model_after)) (current_cpu, sem);
    } 

// Function unit handlers
// To be overridden as needed.
  virtual UINT model_u_store_ctrl_reg_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, INT /*storereg*/)
    {
      return 0;
    }
  virtual UINT model_u_store_ctrl_reg_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*storereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_ctrl_reg_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_ctrl_reg_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_use_gpr_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, INT /*usereg*/)
    {
      return 0;
    }
  virtual UINT model_u_use_gpr_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*usereg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_mul_gpr_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, INT /*resultreg*/)
    {
      return 0;
    }
  virtual UINT model_u_mul_gpr_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*resultreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_gpr_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_gpr_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_load_gpr_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, INT /*loadreg*/)
    {
      return 0;
    }
  virtual UINT model_u_load_gpr_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced, INT /*loadreg*/)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_ldcb_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_ldcb_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_stcb_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_stcb_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_divide_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_divide_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_multiply_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_multiply_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_branch_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_branch_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }
  virtual UINT model_u_exec_before (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num)
    {
      return 0;
    }
  virtual UINT model_u_exec_after (mep_ext2_cpu *cpu, const struct mepcop2_16_idesc *idesc, int unit_num, unsigned long long referenced)
    {
      return timing[idesc->sem_index].units[unit_num].done;
    }

protected:
  // These methods call the appropriate unit modeller(s) for each insn.

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

  typedef UINT (mepcop2_16_mep_model::*model_function) (mep_ext2_cpu* current_cpu, mepcop2_16_scache* sem);

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

} // namespace mep_ext2

#endif // MEPCOP2_16_MODEL_H
