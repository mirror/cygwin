// fmax-fpu.h - CPU components.  -*- C++ -*-
// CGEN fpu support for the MeP FMAX coprocessor for SID
//
// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef FMAX_FPU_H
#define FMAX_FPU_H

#include "cgen-fpu.h"

class mep::mep_cpu;
class sidutil::fp;
class sidutil::fmax_fp;

namespace cgen 
{
class fmax_fp_ops : public cgen_fp_ops {
public: 
  virtual SF addsf (cgen_fpu*, SF, SF);
  virtual SF subsf (cgen_fpu*, SF, SF);
  virtual SF mulsf (cgen_fpu*, SF, SF);
  virtual SF divsf (cgen_fpu*, SF, SF);
  virtual SF negsf (cgen_fpu*, SF);
  virtual SF abssf (cgen_fpu*, SF);
  virtual SF sqrtsf (cgen_fpu*, SF);

  virtual int eqsf (cgen_fpu*, SF, SF);
  virtual int nesf (cgen_fpu*, SF, SF);
  virtual int ltsf (cgen_fpu*, SF, SF);
  virtual int lesf (cgen_fpu*, SF, SF);
  virtual int gtsf (cgen_fpu*, SF, SF);
  virtual int gesf (cgen_fpu*, SF, SF);

  virtual SF floatsisf (cgen_fpu*, SI);

  void check_operand (cgen_fpu*, const fmax_fp &);
  virtual void check_result (cgen_fpu*, fp &);

private:
  void round (cgen_fpu *, fp &);
  void check_zero_sum (cgen_fpu *fpu, fp& x, fp& y, fp &r);
};

// Instance of an fpu.
class fmax_fpu : public cgen_fpu {
 public:
  fmax_fpu (mep::mep_cpu *c, fmax_fp_ops *o);
  fmax_fp_ops* mep_ops;
};

} // namespace cgen 

#endif // FMAX_FPU_H
