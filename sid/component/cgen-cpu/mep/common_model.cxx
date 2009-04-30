// common_model.cxx - Hand-written code for the Toshiba Media Engine modelling. -*- C++ -*-

// Common insn modelling functions for the 'mep' model.

// Copyright (C) 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "mep_basic.h"
// begin-includes
#include "mep_ext1.h"
// end-includes

using namespace cgen;
using namespace mep_basic;
// begin-namespaces
using namespace mep_ext1;
// end-namespaces

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// MeP-Integrator looks for function headers formatted as below and
// automatically generates explicit instantiations.
//   - The template header must be on one line.
//   - The return type must appear alone on the next line.
//   - The function declaration and all parameters must be on one line.
// Follow each function by a {begin,end}-generated-instantiations bracket for MeP-Integrator to generate instantiations for all modules.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_ldcb_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  set_current_stall (ldcb_busy);

  return 0;
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_ldcb_before (mep_basic_cpu *, const mep_idesc *, int unit_num);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_ldcb_before (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_ldcb_before (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_ldcb_before (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_ldcb_before (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_ldcb_before (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_divide_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  set_current_stall (divide_busy);

  return 0;
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_divide_before (mep_basic_cpu *, const mep_idesc *, int unit_num);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_divide_before (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_divide_before (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_divide_before (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_divide_before (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_divide_before (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_multiply_before (CPU *cpu, const IDESC *idesc, int unit_num)
{
  // Accumulate the maximum stall time.
  set_current_stall (multiply_busy);

  return 0;
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_multiply_before (mep_basic_cpu *, const mep_idesc *, int unit_num);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_multiply_before (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_multiply_before (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_multiply_before (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_multiply_before (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_multiply_before (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_ctrl_reg_before (CPU *cpu, const IDESC *idesc, int unit_num, INT usereg)
{
  // Accumulate the maximum stall time.
  set_current_stall (ctrl_reg_busy[usereg]);

  return 0;
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_use_ctrl_reg_before (mep_basic_cpu *, const mep_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_use_ctrl_reg_before (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_use_ctrl_reg_before (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_use_ctrl_reg_before (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_use_ctrl_reg_before (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_use_ctrl_reg_before (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, INT usereg);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_use_gpr_before (CPU *cpu, const IDESC *idesc, int unit_num, INT usereg)
{
  assert (usereg >= 0);
  // Accumulate the maximum stall time.
  set_current_stall (gpr_busy[usereg]);

  return 0;
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_use_gpr_before (mep_basic_cpu *, const mep_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_use_gpr_before (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_use_gpr_before (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_use_gpr_before (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_use_gpr_before (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, INT usereg);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_use_gpr_before (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, INT usereg);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_branch_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // (1ULL << 0): The pc is the 1st element in inputs, outputs.
  // ??? can be cleaned up
  bool taken = referenced & (1ULL << 0);
  if (taken)
    {
      // Obtain the actual latency of the insn.
      UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);
      // 2 cycle penalty for branches taken.
      set_current_stall (cycles + 2);
    }

  return BASE::model_u_branch_after (cpu, idesc, unit_num, referenced);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_branch_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_branch_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_branch_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_branch_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_branch_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_branch_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_multiply_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Obtain the actual latency of the insn.
  UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);

  // The divide unit will not be available until 1 cycle after the insn executes
  set_divide_busy (cycles + 1);

  return BASE::model_u_multiply_after (cpu, idesc, unit_num, referenced);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_multiply_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_multiply_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_multiply_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_multiply_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_multiply_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_multiply_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_stcb_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Obtain the actual latency of the insn.
  UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);

  // The ldcb unit will not be available until 1 cycle after the insn executes
  set_ldcb_busy (cycles + 1);

  return BASE::model_u_stcb_after (cpu, idesc, unit_num, referenced);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_stcb_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_stcb_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_stcb_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_stcb_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_stcb_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_stcb_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_divide_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced)
{
  // Obtain the actual latency of the insn.
  UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);

  // The hi/lo registers will not be available until 34 cycles after the insn executes
  set_ctrl_reg_busy (CTRL_HI, cycles + 34);
  set_ctrl_reg_busy (CTRL_LO, cycles + 34);

  // The divide unit will not be available until 36 cycles after the insn executes
  set_divide_busy (cycles + 36);

  // The multiply unit will not be available until 36 cycles after the insn executes
  set_multiply_busy (cycles + 36);

  return BASE::model_u_divide_after (cpu, idesc, unit_num, referenced);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_divide_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_divide_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_divide_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_divide_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_divide_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_divide_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_load_gpr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);

  // The gpr will not be available until 1 cycle after the insn executes
  set_gpr_busy (loadreg, cycles + 1);

  return BASE::model_u_load_gpr_after (cpu, idesc, unit_num, referenced, loadreg);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_load_gpr_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_load_gpr_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_load_gpr_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_load_gpr_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_load_gpr_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_load_gpr_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_ldcb_gpr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT loadreg)
{
  assert (loadreg >= 0);

  // The latency of the insn itself.
  UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);

  // The gpr will not be available until 2 cycles after the insn executes
  set_gpr_busy (loadreg, cycles + 2);

  return BASE::model_u_ldcb_gpr_after (cpu, idesc, unit_num, referenced, loadreg);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_ldcb_gpr_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_ldcb_gpr_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_ldcb_gpr_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_ldcb_gpr_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_ldcb_gpr_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_ldcb_gpr_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced, INT loadreg);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
UINT
mep_common_model<BASE, CPU, IDESC, SCACHE>::model_u_mul_gpr_after (CPU *cpu, const IDESC *idesc, int unit_num, unsigned long long referenced, INT resultreg)
{
  assert (resultreg >= 0);

  // The latency of the insn itself.
  UINT cycles = u_exec_cycles (cpu, idesc, unit_num, referenced);

  // The gpr will not be available until 2 cycles after the insn executes
  set_gpr_busy (resultreg, cycles + 2);

  return BASE::model_u_mul_gpr_after (cpu, idesc, unit_num, referenced, resultreg);
}
// begin-generated-instantiations
template UINT mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::model_u_mul_gpr_after (mep_basic_cpu *, const mep_idesc *, int unit_num, unsigned long long referenced, INT resultreg);
template UINT mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::model_u_mul_gpr_after (mep_ext1_cpu *, const mepcore1_idesc *, int unit_num, unsigned long long referenced, INT resultreg);
template UINT mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::model_u_mul_gpr_after (mep_ext1_cpu *, const mepcop1_16_idesc *, int unit_num, unsigned long long referenced, INT resultreg);
template UINT mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::model_u_mul_gpr_after (mep_ext1_cpu *, const mepcop1_32_idesc *, int unit_num, unsigned long long referenced, INT resultreg);
template UINT mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::model_u_mul_gpr_after (mep_ext1_cpu *, const mepcop1_48_idesc *, int unit_num, unsigned long long referenced, INT resultreg);
template UINT mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::model_u_mul_gpr_after (mep_ext1_cpu *, const mepcop1_64_idesc *, int unit_num, unsigned long long referenced, INT resultreg);
// end-generated-instantiations

template <class BASE, class CPU, class IDESC, class SCACHE>
void
mep_common_model<BASE, CPU, IDESC, SCACHE>::step_latency (sid::host_int_4 cycles)
{
  // Call the base class.
  BASE::step_latency (cycles);

  sid::host_int_8 new_total_latency = BASE::cpu->get_total_latency ();
  sid::host_int_8 latency = cycles + (new_total_latency - save_total_latency);

  // If there's no latency, then nothing to do.
  if (latency == 0)
    return;

  // Advance the hazard state information by the given number of cycles.
  for (int g = 0; g < num_gpr; ++g)
    gpr_busy[g] = gpr_busy[g] > latency ? gpr_busy[g] - latency : 0;

  for (int c = 0; c < num_ctrl_reg; ++c)
    ctrl_reg_busy[c] = ctrl_reg_busy[c] > latency ? ctrl_reg_busy[c] - latency : 0;

  multiply_busy = multiply_busy > latency ? multiply_busy - latency : 0;

  divide_busy = divide_busy > latency ? divide_busy - latency : 0;

  ldcb_busy = ldcb_busy > latency ? ldcb_busy - latency : 0;

  current_stall = current_stall > latency ? current_stall - latency : 0;

  save_total_latency = new_total_latency;
}
// begin-generated-instantiations
template void mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::step_latency (sid::host_int_4 cycles);
template void mep_common_model<mepcore1_mep_model,mep_ext1_cpu,mepcore1_idesc,mepcore1_scache>::step_latency (sid::host_int_4 cycles);
template void mep_common_model<mepcop1_16_mep_model,mep_ext1_cpu,mepcop1_16_idesc,mepcop1_16_scache>::step_latency (sid::host_int_4 cycles);
template void mep_common_model<mepcop1_32_mep_model,mep_ext1_cpu,mepcop1_32_idesc,mepcop1_32_scache>::step_latency (sid::host_int_4 cycles);
template void mep_common_model<mepcop1_48_mep_model,mep_ext1_cpu,mepcop1_48_idesc,mepcop1_48_scache>::step_latency (sid::host_int_4 cycles);
template void mep_common_model<mepcop1_64_mep_model,mep_ext1_cpu,mepcop1_64_idesc,mepcop1_64_scache>::step_latency (sid::host_int_4 cycles);
// end-generated-instantiations
