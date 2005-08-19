// cgen-fpu.h - CPU components.  -*- C++ -*-
// CGEN fpu support for SID
//
// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_FPU_H
#define CGEN_FPU_H

#include "cgen-cpu.h"
#include "fp.h"

namespace cgen 
{
/* Floating point support is a little more complicated.
   We want to support using either host fp insns or an accurate fp library.
   We also want to support easily added variants (e.g. modified ieee).
   This is done by using a virtual helper class 'cgen_fp_ops'.  */
class cgen_fpu;

/* fpu operation class */
class cgen_fp_ops {
public: 
  // default is no error checking
  virtual void check_result (cgen_fpu*, fp &) {}

  /* basic SF ops */
  virtual SF addsf (cgen_fpu*, SF, SF);
  virtual SF subsf (cgen_fpu*, SF, SF);
  virtual SF mulsf (cgen_fpu*, SF, SF);
  virtual SF divsf (cgen_fpu*, SF, SF);
  virtual SF negsf (cgen_fpu*, SF);
  virtual SF abssf (cgen_fpu*, SF);
  virtual SF sqrtsf (cgen_fpu*, SF);
#if 0
  virtual SF invsf (cgen_fpu*, SF);
  virtual SF cossf (cgen_fpu*, SF);
  virtual SF sinsf (cgen_fpu*, SF);
  virtual SF minsf (cgen_fpu*, SF, SF);
  virtual SF maxsf (cgen_fpu*, SF, SF);
#endif
  virtual int eqsf (cgen_fpu*, SF, SF);
  virtual int nesf (cgen_fpu*, SF, SF);
  virtual int ltsf (cgen_fpu*, SF, SF);
  virtual int lesf (cgen_fpu*, SF, SF);
  virtual int gtsf (cgen_fpu*, SF, SF);
  virtual int gesf (cgen_fpu*, SF, SF);

#if 0
  /* basic DF ops */
  virtual DF adddf (cgen_fpu*, DF, DF);
  virtual DF subdf (cgen_fpu*, DF, DF);
  virtual DF muldf (cgen_fpu*, DF, DF);
  virtual DF divdf (cgen_fpu*, DF, DF);
  virtual DF negdf (cgen_fpu*, DF);
  virtual DF absdf (cgen_fpu*, DF);
  virtual DF sqrtdf (cgen_fpu*, DF);
  virtual DF invdf (cgen_fpu*, DF);
  virtual DF cosdf (cgen_fpu*, DF);
  virtual DF sindf (cgen_fpu*, DF);
  virtual DF mindf (cgen_fpu*, DF, DF);
  virtual DF maxdf (cgen_fpu*, DF, DF);

  virtual int eqdf (cgen_fpu*, DF, DF);
  virtual int nedf (cgen_fpu*, DF, DF);
  virtual int ltdf (cgen_fpu*, DF, DF);
  virtual int ledf (cgen_fpu*, DF, DF);
  virtual int gtdf (cgen_fpu*, DF, DF);
  virtual int gedf (cgen_fpu*, DF, DF);

  /* SF/DF conversion ops */
  virtual DF fextsfdf (cgen_fpu*, SF);
  virtual SF ftruncdfsf (cgen_fpu*, DF);
#endif // not implemented yet

  virtual SF floatsisf (cgen_fpu*, SI);
#if 0 // not implemented yet
  virtual SF floatdisf (cgen_fpu*, DI);
  virtual SF ufloatsisf (cgen_fpu*, USI);
  virtual SF ufloatdisf (cgen_fpu*, UDI);
#endif // not implemented yet

  virtual SI fixsfsi (cgen_fpu*, SF);
#if 0 // not implemented yet
  virtual DI fixsfdi (cgen_fpu*, SF);
  virtual USI ufixsfsi (cgen_fpu*, SF);
  virtual UDI ufixsfdi (cgen_fpu*, SF);

  virtual DF floatsidf (cgen_fpu*, SI);
  virtual DF floatdidf (cgen_fpu*, DI);
  virtual DF ufloatsidf (cgen_fpu*, USI);
  virtual DF ufloatdidf (cgen_fpu*, UDI);

  virtual SI fixdfsi (cgen_fpu*, DF);
  virtual DI fixdfdi (cgen_fpu*, DF);
  virtual USI ufixdfsi (cgen_fpu*, DF);
  virtual UDI ufixdfdi (cgen_fpu*, DF);

  /* XF mode support (kept separate 'cus not always present) */
  virtual XF addxf (cgen_fpu*, XF, XF);
  virtual XF subxf (cgen_fpu*, XF, XF);
  virtual XF mulxf (cgen_fpu*, XF, XF);
  virtual XF divxf (cgen_fpu*, XF, XF);
  virtual XF negxf (cgen_fpu*, XF);
  virtual XF absxf (cgen_fpu*, XF);
  virtual XF sqrtxf (cgen_fpu*, XF);
  virtual XF invxf (cgen_fpu*, XF);
  virtual XF cosxf (cgen_fpu*, XF);
  virtual XF sinxf (cgen_fpu*, XF);
  virtual XF minxf (cgen_fpu*, XF, XF);
  virtual XF maxxf (cgen_fpu*, XF, XF);

  virtual int eqxf (cgen_fpu*, XF, XF);
  virtual int nexf (cgen_fpu*, XF, XF);
  virtual int ltxf (cgen_fpu*, XF, XF);
  virtual int lexf (cgen_fpu*, XF, XF);
  virtual int gtxf (cgen_fpu*, XF, XF);
  virtual int gexf (cgen_fpu*, XF, XF);

  virtual XF extsfxf (cgen_fpu*, SF);
  virtual XF extdfxf (cgen_fpu*, DF);
  virtual SF truncxfsf (cgen_fpu*, XF);
  virtual DF truncxfdf (cgen_fpu*, XF);

  virtual XF floatsixf (cgen_fpu*, SI);
  virtual XF floatdixf (cgen_fpu*, DI);
  virtual XF ufloatsixf (cgen_fpu*, USI);
  virtual XF ufloatdixf (cgen_fpu*, UDI);

  virtual SI fixxfsi (cgen_fpu*, XF);
  virtual DI fixxfdi (cgen_fpu*, XF);
  virtual USI ufixxfsi (cgen_fpu*, XF);
  virtual UDI ufixxfdi (cgen_fpu*, XF);

  /* TF mode support (kept separate 'cus not always present) */
  virtual TF addtf (cgen_fpu*, TF, TF);
  virtual TF subtf (cgen_fpu*, TF, TF);
  virtual TF multf (cgen_fpu*, TF, TF);
  virtual TF divtf (cgen_fpu*, TF, TF);
  virtual TF negtf (cgen_fpu*, TF);
  virtual TF abstf (cgen_fpu*, TF);
  virtual TF sqrttf (cgen_fpu*, TF);
  virtual TF invtf (cgen_fpu*, TF);
  virtual TF costf (cgen_fpu*, TF);
  virtual TF sintf (cgen_fpu*, TF);
  virtual TF mintf (cgen_fpu*, TF, TF);
  virtual TF maxtf (cgen_fpu*, TF, TF);

  virtual int eqtf (cgen_fpu*, TF, TF);
  virtual int netf (cgen_fpu*, TF, TF);
  virtual int lttf (cgen_fpu*, TF, TF);
  virtual int letf (cgen_fpu*, TF, TF);
  virtual int gttf (cgen_fpu*, TF, TF);
  virtual int getf (cgen_fpu*, TF, TF);

  virtual TF extsftf (cgen_fpu*, SF);
  virtual TF extdftf (cgen_fpu*, DF);
  virtual SF trunctfsf (cgen_fpu*, TF);
  virtual DF trunctfdf (cgen_fpu*, TF);

  virtual TF floatsitf (cgen_fpu*, SI);
  virtual TF floatditf (cgen_fpu*, DI);
  virtual TF ufloatsitf (cgen_fpu*, USI);
  virtual TF ufloatditf (cgen_fpu*, UDI);

  virtual SI fixtfsi (cgen_fpu*, TF);
  virtual DI fixtfdi (cgen_fpu*, TF);
  virtual USI ufixtfsi (cgen_fpu*, TF);
  virtual UDI ufixtfdi (cgen_fpu*, TF);
#endif // not implemented yet
};

/* Instance of an fpu.  */
class cgen_fpu {
 public:
  cgen_fpu (cgen_bi_endian_cpu *c, cgen_fp_ops *o) : owner (c), ops (o) {}
  cgen_bi_endian_cpu* owner;
  cgen_fp_ops* ops;
};

}; // namespace cgen 

#endif /* CGEN_FPU_H */
