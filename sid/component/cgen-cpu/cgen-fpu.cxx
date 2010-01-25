// cgen-fpu.cxx - CPU components.  -*- C++ -*-
// CGEN fpu support for SID
//
// Copyright (C) 2005, 2010 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cgen-fpu.h"
#include "fp.h"

using namespace sidutil;

namespace cgen 
{
/* basic SF ops */
SF
cgen_fp_ops::addsf (const cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) + fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::subsf (const cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) - fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::mulsf (const cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) * fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::divsf (const cgen_fpu* fpu, SF x, SF y)
{
  fp r = fp (x) / fp (y);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::negsf (const cgen_fpu* fpu, SF x)
{
  fp r (x);
  r = fp::neg (r);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::abssf (const cgen_fpu* fpu, SF x)
{
  fp r (x);
  r = fp::abs (r);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::sqrtsf (const cgen_fpu* fpu, SF x)
{
  fp r (x);
  r = fp::sqrt (r);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}


#if 0 // not implemented yet
SF cgen_fp_ops::invsf (const cgen_fpu*, SF);
SF cgen_fp_ops::cossf (const cgen_fpu*, SF);
SF cgen_fp_ops::sinsf (const cgen_fpu*, SF);
SF cgen_fp_ops::minsf (const cgen_fpu*, SF, SF);
SF cgen_fp_ops::maxsf (const cgen_fpu*, SF, SF);
#endif

int cgen_fp_ops::eqsf (const cgen_fpu*, SF x, SF y)
{
  return fp (x) == fp (y);
}
int cgen_fp_ops::nesf (const cgen_fpu*, SF x, SF y)
{
  return fp (x) != fp (y);
}
int cgen_fp_ops::ltsf (const cgen_fpu*, SF x, SF y)
{
  return fp (x) < fp (y);
}
int cgen_fp_ops::lesf (const cgen_fpu*, SF x, SF y)
{
  return fp (x) <= fp (y);
}
int cgen_fp_ops::gtsf (const cgen_fpu*, SF x, SF y)
{
  return fp (x) > fp (y);
}
int cgen_fp_ops::gesf (const cgen_fpu*, SF x, SF y)
{
  return fp (x) >= fp (y);
}

int cgen_fp_ops::unorderedsf (const cgen_fpu*, SF x, SF y)
{
  fp f1(x);
  fp f2(y);
  return f1.is_nan () || f2.is_nan ();
}

/* basic DF ops */
DF cgen_fp_ops::adddf (const cgen_fpu *fpu, DF x, DF y)
{
  fp r = fp (x) + fp (y);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::subdf (const cgen_fpu *fpu, DF x, DF y)
{
  fp r = fp (x) - fp (y);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::muldf (const cgen_fpu *fpu, DF x, DF y)
{
  fp r = fp (x) * fp (y);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::divdf (const cgen_fpu *fpu, DF x, DF y)
{
  fp r = fp (x) / fp (y);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::negdf (const cgen_fpu *fpu, DF x)
{
  fp r (x);
  r = fp::neg (r);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::absdf (const cgen_fpu *fpu, DF x)
{
  fp r (x);
  r = fp::abs (r);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::sqrtdf (const cgen_fpu *fpu, DF x)
{
  fp r (x);
  r = fp::sqrt (r);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

#if 0
DF cgen_fp_ops::invdf (const cgen_fpu*, DF);
DF cgen_fp_ops::cosdf (const cgen_fpu*, DF);
DF cgen_fp_ops::sindf (const cgen_fpu*, DF);
DF cgen_fp_ops::mindf (const cgen_fpu*, DF, DF);
DF cgen_fp_ops::maxdf (const cgen_fpu*, DF, DF);
#endif

int cgen_fp_ops::eqdf (const cgen_fpu *fpu, DF x, DF y)
{
  return fp (x) == fp (y);
}

int cgen_fp_ops::nedf (const cgen_fpu *fpu, DF x, DF y)
{
  return fp (x) == fp (y);
}
int cgen_fp_ops::ltdf (const cgen_fpu *fpu, DF x, DF y)
{
  return fp (x) < fp (y);
}
int cgen_fp_ops::ledf (const cgen_fpu *fpu, DF x, DF y)
{
  return fp (x) <= fp (y);
}
int cgen_fp_ops::gtdf (const cgen_fpu *fpu, DF x, DF y)
{
  return fp (x) > fp (y);
}
int cgen_fp_ops::gedf (const cgen_fpu *fpu, DF x, DF y)
{
  return fp (x) >= fp (y);
}

int cgen_fp_ops::unordereddf (const cgen_fpu *fpu, DF x, DF y)
{
  fp f1(x);
  fp f2(y);
  return f1.is_nan () || f2.is_nan ();
}

/* SF/DF conversion ops */

DF cgen_fp_ops::fextsfdf (const cgen_fpu *fpu, int how, SF x)
{
  fp r (x);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::ftruncdfsf (const cgen_fpu *fpu, int how, DF x)
{
  fp r (x);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::floatsisf (const cgen_fpu* fpu, int how, SI x)
{
  fp r = fp::from_int (x);
  check_result (fpu, r);
  SF tmp;
  r.pack (tmp);
  return tmp;
}

SF cgen_fp_ops::floatdisf (const cgen_fpu *fpu, int how, DI x)
{
  fp r = fp::from_int (x);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

#if 0 // not implemented yet
SF cgen_fp_ops::ufloatsisf (const cgen_fpu*, int how, USI);
SF cgen_fp_ops::ufloatdisf (const cgen_fpu*, int how, UDI);
#endif // not implemented yet

SI cgen_fp_ops::fixsfsi (const cgen_fpu *fpu, int how, SF x)
{
  fp r (x);
  SI tmp;
  r.integer (tmp, fp::round_default);
  return tmp;
}

DI cgen_fp_ops::fixsfdi (const cgen_fpu *fpu, int how, SF x)
{
  fp r (x);
  DI tmp;
  r.integer (tmp, fp::round_default);
  return tmp;
}

#if 0 // not implemented yet
USI cgen_fp_ops::ufixsfsi (const cgen_fpu*, int how, SF);
UDI cgen_fp_ops::ufixsfdi (const cgen_fpu*, int how, SF);
#endif

DF cgen_fp_ops::floatsidf (const cgen_fpu *fpu, int how, SI x)
{
  fp r = fp::from_int (x);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

DF cgen_fp_ops::floatdidf (const cgen_fpu *fpu, int how, DI x)
{
  fp r = fp::from_int (x);
  check_result (fpu, r);
  DF tmp;
  r.pack (tmp);
  return tmp;
}

#if 0
DF cgen_fp_ops::ufloatsidf (const cgen_fpu*, int how, USI);
DF cgen_fp_ops::ufloatdidf (const cgen_fpu*, int how, UDI);
#endif

SI cgen_fp_ops::fixdfsi (const cgen_fpu *fpu, int how, DF x)
{
  fp r (x);
  SI tmp;
  r.integer (tmp, fp::round_default);
  return tmp;
}

DI cgen_fp_ops::fixdfdi (const cgen_fpu *fpu, int how, DF x)
{
  fp r (x);
  DI tmp;
  r.integer (tmp, fp::round_default);
  return tmp;
}

#if 0
USI cgen_fp_ops::ufixdfsi (const cgen_fpu*, int how, DF);
UDI cgen_fp_ops::ufixdfdi (const cgen_fpu*, int how, DF);

/* XF mode support (kept separate 'cus not always present) */
XF cgen_fp_ops::addxf (const cgen_fpu*, XF, XF);
XF cgen_fp_ops::subxf (const cgen_fpu*, XF, XF);
XF cgen_fp_ops::mulxf (const cgen_fpu*, XF, XF);
XF cgen_fp_ops::divxf (const cgen_fpu*, XF, XF);
XF cgen_fp_ops::negxf (const cgen_fpu*, XF);
XF cgen_fp_ops::absxf (const cgen_fpu*, XF);
XF cgen_fp_ops::sqrtxf (const cgen_fpu*, XF);
XF cgen_fp_ops::invxf (const cgen_fpu*, XF);
XF cgen_fp_ops::cosxf (const cgen_fpu*, XF);
XF cgen_fp_ops::sinxf (const cgen_fpu*, XF);
XF cgen_fp_ops::minxf (const cgen_fpu*, XF, XF);
XF cgen_fp_ops::maxxf (const cgen_fpu*, XF, XF);

int cgen_fp_ops::eqxf (const cgen_fpu*, XF, XF);
int cgen_fp_ops::nexf (const cgen_fpu*, XF, XF);
int cgen_fp_ops::ltxf (const cgen_fpu*, XF, XF);
int cgen_fp_ops::lexf (const cgen_fpu*, XF, XF);
int cgen_fp_ops::gtxf (const cgen_fpu*, XF, XF);
int cgen_fp_ops::gexf (const cgen_fpu*, XF, XF);

XF cgen_fp_ops::extsfxf (const cgen_fpu*, int how, SF);
XF cgen_fp_ops::extdfxf (const cgen_fpu*, int how, DF);
SF cgen_fp_ops::truncxfsf (const cgen_fpu*, int how, XF);
DF cgen_fp_ops::truncxfdf (const cgen_fpu*, int how, XF);

XF cgen_fp_ops::floatsixf (const cgen_fpu*, int how, SI);
XF cgen_fp_ops::floatdixf (const cgen_fpu*, int how, DI);
XF cgen_fp_ops::ufloatsixf (const cgen_fpu*, int how, USI);
XF cgen_fp_ops::ufloatdixf (const cgen_fpu*, int how, UDI);

SI cgen_fp_ops::fixxfsi (const cgen_fpu*, int how, XF);
DI cgen_fp_ops::fixxfdi (const cgen_fpu*, int how, XF);
USI cgen_fp_ops::ufixxfsi (const cgen_fpu*, int how, XF);
UDI cgen_fp_ops::ufixxfdi (const cgen_fpu*, int how, XF);

/* TF mode support (kept separate 'cus not always present) */
TF cgen_fp_ops::addtf (const cgen_fpu*, TF, TF);
TF cgen_fp_ops::subtf (const cgen_fpu*, TF, TF);
TF cgen_fp_ops::multf (const cgen_fpu*, TF, TF);
TF cgen_fp_ops::divtf (const cgen_fpu*, TF, TF);
TF cgen_fp_ops::negtf (const cgen_fpu*, TF);
TF cgen_fp_ops::abstf (const cgen_fpu*, TF);
TF cgen_fp_ops::sqrttf (const cgen_fpu*, TF);
TF cgen_fp_ops::invtf (const cgen_fpu*, TF);
TF cgen_fp_ops::costf (const cgen_fpu*, TF);
TF cgen_fp_ops::sintf (const cgen_fpu*, TF);
TF cgen_fp_ops::mintf (const cgen_fpu*, TF, TF);
TF cgen_fp_ops::maxtf (const cgen_fpu*, TF, TF);

int cgen_fp_ops::eqtf (const cgen_fpu*, TF, TF);
int cgen_fp_ops::netf (const cgen_fpu*, TF, TF);
int cgen_fp_ops::lttf (const cgen_fpu*, TF, TF);
int cgen_fp_ops::letf (const cgen_fpu*, TF, TF);
int cgen_fp_ops::gttf (const cgen_fpu*, TF, TF);
int cgen_fp_ops::getf (const cgen_fpu*, TF, TF);

TF cgen_fp_ops::extsftf (const cgen_fpu*, int how, SF);
TF cgen_fp_ops::extdftf (const cgen_fpu*, int how, DF);
SF cgen_fp_ops::trunctfsf (const cgen_fpu*, int how, TF);
DF cgen_fp_ops::trunctfdf (const cgen_fpu*, int how, TF);

TF cgen_fp_ops::floatsitf (const cgen_fpu*, int how, SI);
TF cgen_fp_ops::floatditf (const cgen_fpu*, int how, DI);
TF cgen_fp_ops::ufloatsitf (const cgen_fpu*, int how, USI);
TF cgen_fp_ops::ufloatditf (const cgen_fpu*, int how, UDI);

SI cgen_fp_ops::fixtfsi (const cgen_fpu*, int how, TF);
DI cgen_fp_ops::fixtfdi (const cgen_fpu*, int how, TF);
USI cgen_fp_ops::ufixtfsi (const cgen_fpu*, int how, TF);
UDI cgen_fp_ops::ufixtfdi (const cgen_fpu*, int how, TF);
#endif // not implemented yet

}; // namespace cgen 
