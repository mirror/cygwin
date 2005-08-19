// cgen-fpu.cxx - CPU components.  -*- C++ -*-
// CGEN fpu support for SID
//
// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cgen-fpu.h"
#include "fp.h"

using namespace sidutil;

namespace cgen 
{
/* basic SF ops */
SF
cgen_fp_ops::addsf (cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) + fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::subsf (cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) - fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::mulsf (cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) * fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::divsf (cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) / fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::negsf (cgen_fpu* fpu, SF x)
{
  fp r (x);
  r = fp::neg (r);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::abssf (cgen_fpu* fpu, SF x)
{
  fp r (x);
  r = fp::abs (r);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::sqrtsf (cgen_fpu* fpu, SF x)
{
  fp r (x);
  r = fp::sqrt (r);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}


#if 0 // not implemented yet
SF cgen_fp_ops::invsf (cgen_fpu*, SF);
SF cgen_fp_ops::cossf (cgen_fpu*, SF);
SF cgen_fp_ops::sinsf (cgen_fpu*, SF);
SF cgen_fp_ops::minsf (cgen_fpu*, SF, SF);
SF cgen_fp_ops::maxsf (cgen_fpu*, SF, SF);
#endif

int cgen_fp_ops::eqsf (cgen_fpu*, SF x, SF y)
{
  return fp (x) == fp (y);
}
int cgen_fp_ops::nesf (cgen_fpu*, SF x, SF y)
{
  return fp (x) != fp (y);
}
int cgen_fp_ops::ltsf (cgen_fpu*, SF x, SF y)
{
  return fp (x) < fp (y);
}
int cgen_fp_ops::lesf (cgen_fpu*, SF x, SF y)
{
  return fp (x) <= fp (y);
}
int cgen_fp_ops::gtsf (cgen_fpu*, SF x, SF y)
{
  return fp (x) > fp (y);
}
int cgen_fp_ops::gesf (cgen_fpu*, SF x, SF y)
{
  return fp (x) >= fp (y);
}

#if 0
/* basic DF ops */
DF cgen_fp_ops::adddf (cgen_fpu*, DF, DF);
DF cgen_fp_ops::subdf (cgen_fpu*, DF, DF);
DF cgen_fp_ops::muldf (cgen_fpu*, DF, DF);
DF cgen_fp_ops::divdf (cgen_fpu*, DF, DF);
DF cgen_fp_ops::negdf (cgen_fpu*, DF);
DF cgen_fp_ops::absdf (cgen_fpu*, DF);
DF cgen_fp_ops::sqrtdf (cgen_fpu*, DF);
DF cgen_fp_ops::invdf (cgen_fpu*, DF);
DF cgen_fp_ops::cosdf (cgen_fpu*, DF);
DF cgen_fp_ops::sindf (cgen_fpu*, DF);
DF cgen_fp_ops::mindf (cgen_fpu*, DF, DF);
DF cgen_fp_ops::maxdf (cgen_fpu*, DF, DF);

int cgen_fp_ops::eqdf (cgen_fpu*, DF, DF);
int cgen_fp_ops::nedf (cgen_fpu*, DF, DF);
int cgen_fp_ops::ltdf (cgen_fpu*, DF, DF);
int cgen_fp_ops::ledf (cgen_fpu*, DF, DF);
int cgen_fp_ops::gtdf (cgen_fpu*, DF, DF);
int cgen_fp_ops::gedf (cgen_fpu*, DF, DF);

  /* SF/DF conversion ops */
DF cgen_fp_ops::fextsfdf (cgen_fpu*, SF);
SF cgen_fp_ops::ftruncdfsf (cgen_fpu*, DF);

#endif // not implemented yet
SF cgen_fp_ops::floatsisf (cgen_fpu* fpu, SI x)
{
  fp r = fp::from_int (x);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}
#if 0 // not implemented yet
SF cgen_fp_ops::floatdisf (cgen_fpu*, DI);
SF cgen_fp_ops::ufloatsisf (cgen_fpu*, USI);
SF cgen_fp_ops::ufloatdisf (cgen_fpu*, UDI);
#endif // not implemented yet

SI cgen_fp_ops::fixsfsi (cgen_fpu*, SF x)
{
  fp r (x);
  unsigned int tmp;
  r.integer (tmp, fp::round_default);
  return tmp;
}
#if 0 // not implemented yet
DI cgen_fp_ops::fixsfdi (cgen_fpu*, SF);
USI cgen_fp_ops::ufixsfsi (cgen_fpu*, SF)
UDI cgen_fp_ops::ufixsfdi (cgen_fpu*, SF);

DF cgen_fp_ops::floatsidf (cgen_fpu*, SI);
DF cgen_fp_ops::floatdidf (cgen_fpu*, DI);
DF cgen_fp_ops::ufloatsidf (cgen_fpu*, USI);
DF cgen_fp_ops::ufloatdidf (cgen_fpu*, UDI);

SI cgen_fp_ops::fixdfsi (cgen_fpu*, DF);
DI cgen_fp_ops::fixdfdi (cgen_fpu*, DF);
USI cgen_fp_ops::ufixdfsi (cgen_fpu*, DF);
UDI cgen_fp_ops::ufixdfdi (cgen_fpu*, DF);

/* XF mode support (kept separate 'cus not always present) */
XF cgen_fp_ops::addxf (cgen_fpu*, XF, XF);
XF cgen_fp_ops::subxf (cgen_fpu*, XF, XF);
XF cgen_fp_ops::mulxf (cgen_fpu*, XF, XF);
XF cgen_fp_ops::divxf (cgen_fpu*, XF, XF);
XF cgen_fp_ops::negxf (cgen_fpu*, XF);
XF cgen_fp_ops::absxf (cgen_fpu*, XF);
XF cgen_fp_ops::sqrtxf (cgen_fpu*, XF);
XF cgen_fp_ops::invxf (cgen_fpu*, XF);
XF cgen_fp_ops::cosxf (cgen_fpu*, XF);
XF cgen_fp_ops::sinxf (cgen_fpu*, XF);
XF cgen_fp_ops::minxf (cgen_fpu*, XF, XF);
XF cgen_fp_ops::maxxf (cgen_fpu*, XF, XF);

int cgen_fp_ops::eqxf (cgen_fpu*, XF, XF);
int cgen_fp_ops::nexf (cgen_fpu*, XF, XF);
int cgen_fp_ops::ltxf (cgen_fpu*, XF, XF);
int cgen_fp_ops::lexf (cgen_fpu*, XF, XF);
int cgen_fp_ops::gtxf (cgen_fpu*, XF, XF);
int cgen_fp_ops::gexf (cgen_fpu*, XF, XF);

XF cgen_fp_ops::extsfxf (cgen_fpu*, SF);
XF cgen_fp_ops::extdfxf (cgen_fpu*, DF);
SF cgen_fp_ops::truncxfsf (cgen_fpu*, XF);
DF cgen_fp_ops::truncxfdf (cgen_fpu*, XF);

XF cgen_fp_ops::floatsixf (cgen_fpu*, SI);
XF cgen_fp_ops::floatdixf (cgen_fpu*, DI);
XF cgen_fp_ops::ufloatsixf (cgen_fpu*, USI);
XF cgen_fp_ops::ufloatdixf (cgen_fpu*, UDI);

SI cgen_fp_ops::fixxfsi (cgen_fpu*, XF);
DI cgen_fp_ops::fixxfdi (cgen_fpu*, XF);
USI cgen_fp_ops::ufixxfsi (cgen_fpu*, XF);
UDI cgen_fp_ops::ufixxfdi (cgen_fpu*, XF);

/* TF mode support (kept separate 'cus not always present) */
TF cgen_fp_ops::addtf (cgen_fpu*, TF, TF);
TF cgen_fp_ops::subtf (cgen_fpu*, TF, TF);
TF cgen_fp_ops::multf (cgen_fpu*, TF, TF);
TF cgen_fp_ops::divtf (cgen_fpu*, TF, TF);
TF cgen_fp_ops::negtf (cgen_fpu*, TF);
TF cgen_fp_ops::abstf (cgen_fpu*, TF);
TF cgen_fp_ops::sqrttf (cgen_fpu*, TF);
TF cgen_fp_ops::invtf (cgen_fpu*, TF);
TF cgen_fp_ops::costf (cgen_fpu*, TF);
TF cgen_fp_ops::sintf (cgen_fpu*, TF);
TF cgen_fp_ops::mintf (cgen_fpu*, TF, TF);
TF cgen_fp_ops::maxtf (cgen_fpu*, TF, TF);

int cgen_fp_ops::eqtf (cgen_fpu*, TF, TF);
int cgen_fp_ops::netf (cgen_fpu*, TF, TF);
int cgen_fp_ops::lttf (cgen_fpu*, TF, TF);
int cgen_fp_ops::letf (cgen_fpu*, TF, TF);
int cgen_fp_ops::gttf (cgen_fpu*, TF, TF);
int cgen_fp_ops::getf (cgen_fpu*, TF, TF);

TF cgen_fp_ops::extsftf (cgen_fpu*, SF);
TF cgen_fp_ops::extdftf (cgen_fpu*, DF);
SF cgen_fp_ops::trunctfsf (cgen_fpu*, TF);
DF cgen_fp_ops::trunctfdf (cgen_fpu*, TF);

TF cgen_fp_ops::floatsitf (cgen_fpu*, SI);
TF cgen_fp_ops::floatditf (cgen_fpu*, DI);
TF cgen_fp_ops::ufloatsitf (cgen_fpu*, USI);
TF cgen_fp_ops::ufloatditf (cgen_fpu*, UDI);

SI cgen_fp_ops::fixtfsi (cgen_fpu*, TF);
DI cgen_fp_ops::fixtfdi (cgen_fpu*, TF);
USI cgen_fp_ops::ufixtfsi (cgen_fpu*, TF);
UDI cgen_fp_ops::ufixtfdi (cgen_fpu*, TF);
#endif // not implemented yet

}; // namespace cgen 
