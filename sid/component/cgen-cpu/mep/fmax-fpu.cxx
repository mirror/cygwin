// fmax-fpu.cxx - CPU components.  -*- C++ -*-
// CGEN fpu support for the MeP FMAX coprocessor for SID
//
// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "mep.h"
#include "fmax-fpu.h"

using namespace sidutil;
using namespace mep;

namespace cgen 
{
fmax_fpu::fmax_fpu (mep_cpu *c, fmax_fp_ops *o) :
  cgen_fpu (c, o), mep_ops (o)
{}

/* basic SF ops */
SF
fmax_fp_ops::addsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  fmax_fp fr = fx + fy;
  check_zero_sum (fpu, fx, fy, fr);
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

SF fmax_fp_ops::subsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  fmax_fp fr = fx - fy;
  fy = fp::neg (fy);
  check_zero_sum (fpu, fx, fy, fr);
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

SF fmax_fp_ops::mulsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  fmax_fp fr = fx * fy;
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

SF fmax_fp_ops::divsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  fmax_fp fr = fx / fy;
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

SF fmax_fp_ops::negsf (cgen_fpu *fpu, SF x)
{
  fmax_fp fr;
  fr = x;
  check_operand (fpu, fr);
  fr = fp::neg (fr);
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

SF fmax_fp_ops::abssf (cgen_fpu* fpu, SF x)
{
  fmax_fp fr;
  fr = x;
  check_operand (fpu, fr);
  fr = fp::abs (fr);
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

SF fmax_fp_ops::sqrtsf (cgen_fpu* fpu, SF x)
{
  fmax_fp fr;
  fr = x;
  check_operand (fpu, fr);
  fr = fp::sqrt (fr);
  check_result (fpu, fr);
  SF tmp;
  fr.pack (tmp);
  return tmp;
}

int fmax_fp_ops::eqsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  int r;
  try {
    r = (fx == fy);
  }
  catch (fp::error &e) {
    check_result (fpu, fx.is_nan () ? fx : fy);
    r = 0;
  }
  return r;
}

int fmax_fp_ops::nesf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  int r;
  try {
    r = (fx != fy);
  }
  catch (fp::error &e) {
    check_result (fpu, fx.is_nan () ? fx : fy);
    r = 0;
  }
  return r;
}

int fmax_fp_ops::ltsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  int r;
  try {
    r = (fx < fy);
  }
  catch (fp::error &e) {
    check_result (fpu, fx.is_nan () ? fx : fy);
    r = 0;
  }
  return r;
}

int fmax_fp_ops::lesf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  int r;
  try {
    r = (fx <= fy);
  }
  catch (fp::error &e) {
    check_result (fpu, fx.is_nan () ? fx : fy);
    r = 0;
  }
  return r;
}

int fmax_fp_ops::gtsf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  int r;
  try {
    r = (fx > fy);
  }
  catch (fp::error &e) {
    check_result (fpu, fx.is_nan () ? fx : fy);
    r = 0;
  }
  return r;
}

int fmax_fp_ops::gesf (cgen_fpu* fpu, SF x, SF y)
{
  fmax_fp fx, fy;
  fx = x;
  check_operand (fpu, fx);
  fy = y;
  check_operand (fpu, fy);
  int r;
  try {
    r = (fx >= fy);
  }
  catch (fp::error &e) {
    check_result (fpu, fx.is_nan () ? fx : fy);
    r = 0;
  }
  return r;
}

SF fmax_fp_ops::floatsisf (cgen_fpu* fpu, SI x)
{
  fmax_fp r;
  r = fp::from_int (x);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

void
fmax_fp_ops::check_operand (cgen_fpu *fpu, const fmax_fp &x)
{
  mep::mep_cpu *cpu = dynamic_cast<mep::mep_cpu*>(fpu->owner);
  if (x.is_denorm () || x.is_qnan ())
    {
      // reserved_exception cannot be masked.
      cpu->fmax_record_exception (mep::mep_cpu::FMAX_E_MASK);
      if (x.is_denorm ())
	throw fp::error (fp::denorm);
      throw fp::error (fp::invalid_qnan);
    }
}

void
fmax_fp_ops::check_result (cgen_fpu *fpu, fp &r)
{
  // Get the status of the operation first
  fp::status_t status = r.get_status ();

  // Perform rounding and merge the rounding status.
  round (fpu, r);
  status |= r.get_status ();

  // Now check the status
  bool exception = false;
  mep::mep_cpu *cpu = dynamic_cast<mep::mep_cpu*>(fpu->owner);

  // If 'overflow' or 'underflow' is detected then also set 'inexact'. We want an inexact exception for
  // overflow/underflow when overflow/underflow is not enabled.
  if ((status & fp::invalid_snan)      != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_isi)  != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_idi)  != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_zdz)  != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_imz)  != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_cvi)  != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_div0) != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_Z_MASK); }
  else if ((status & fp::invalid_cmp)  != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::invalid_sqrt) != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK); }
  else if ((status & fp::rounded)      != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_I_MASK); }
  else if ((status & fp::overflow)     != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_O_MASK | mep::mep_cpu::FMAX_I_MASK); }
  else if ((status & fp::underflow)    != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_U_MASK | mep::mep_cpu::FMAX_I_MASK); }
  else if ((status & fp::denorm)       != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_E_MASK); }
  else if ((status & fp::inexact)      != 0) { exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_I_MASK); }
  else if ((status & fp::invalid_qnan) != 0)
    {
      if (cpu->hardware.h_fmax_compare_i_p)
	exception = cpu->fmax_record_exception (mep::mep_cpu::FMAX_V_MASK);
      else
	exception = false;
    }

  if (exception)
    throw fp::error (status);
}

void
fmax_fp_ops::round (cgen_fpu *fpu, fp &f)
{
  // Get the rounding mode
  mep::mep_cpu *cpu = dynamic_cast<mep::mep_cpu*>(fpu->owner);
  fp::round_mode_t round_mode = static_cast<fp::round_mode_t>((cpu->hardware.h_ccr[mep::mep_cpu::FMAX_CERR] & 0x3) + 1);
  f.round_32 (round_mode, fp::denorm_zero);
}

void
fmax_fp_ops::check_zero_sum (cgen_fpu *fpu, fp& x, fp& y, fp &r)
{
  // IEEE 754 section 6.3: If the result of a sum of operands with opposite signs
  // (or the difference of operands with like signs) is zero, then the
  // sign of the result shall be positive unless the rounding mode is toward
  // negative infinity, in which case it shall be negative.
  //
  if (! r.is_zero ())
    return;

  if (x.is_negative () == y.is_negative ())
    return;

  // Get the rounding mode
  mep::mep_cpu *cpu = dynamic_cast<mep::mep_cpu*>(fpu->owner);
  fp::round_mode_t round_mode = static_cast<fp::round_mode_t>((cpu->hardware.h_ccr[mep::mep_cpu::FMAX_CERR] & 0x3) + 1);
  if (round_mode != fp::round_down)
    return;
  
  r = fp::neg (constant_zero);
}

}; // namespace cgen 
