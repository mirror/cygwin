// fmax-fp.h - CPU components.  -*- C++ -*-
// CGEN fpu support for the MeP FMAX coprocessor for SID
//
// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef FMAX_FP_H
#define FMAX_FP_H

#include "sidtypes.h"
#include "fp.h"

namespace sidutil 
{
using namespace sid;

// Specialization of the fp class for fmax
class fmax_fp : public fp
{
public:
  fmax_fp (const cgen::SF& x = 0) : fp (x) {}
  fmax_fp (const fp &x) : fp (x) {}
  fmax_fp (enum class_t c) : fp (c) {}

  virtual void integer (signed_host_int_4& i, round_mode_t mode);

  // snan and qnan for fmax are reversed from the generic fp implementation
  virtual host_int_8 qnan_fraction (bool double_p) const { return 0x3fffff; }
  virtual host_int_8 snan_fraction (bool double_p) const { return 0x7fffff; }
  virtual bool is_qnan_fraction (host_int_8 frac, bool double_p) const { return frac <= 0x3fffff; }

  virtual status_t do_normal_underflow (bool double_p, enum round_mode_t round);

  const fmax_fp& operator= (cgen::SF x)
  {
    unpack (x);
    return *this;
  }

  fmax_fp operator+ (const fmax_fp& r) const;
  fmax_fp operator- (const fmax_fp& r) const; 

private:
  signed_host_int_4 round_int_32 (round_mode_t mode);
};

} // namespace sidutil

#endif // FMAX_FP_H
