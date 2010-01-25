// cgen-fpu.h - CPU components.  -*- C++ -*-
// CGEN fpu support for SID
//
// Copyright (C) 2005, 2010 Red Hat.
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
  virtual void check_result (const cgen_fpu*, fp &) {}

  /* basic SF ops */
  virtual SF addsf (const cgen_fpu*, SF, SF);
  virtual SF subsf (const cgen_fpu*, SF, SF);
  virtual SF mulsf (const cgen_fpu*, SF, SF);
  virtual SF divsf (const cgen_fpu*, SF, SF);
  virtual SF negsf (const cgen_fpu*, SF);
  virtual SF abssf (const cgen_fpu*, SF);
  virtual SF sqrtsf (const cgen_fpu*, SF);
#if 0
  virtual SF invsf (const cgen_fpu*, SF);
  virtual SF cossf (const cgen_fpu*, SF);
  virtual SF sinsf (const cgen_fpu*, SF);
  virtual SF minsf (const cgen_fpu*, SF, SF);
  virtual SF maxsf (const cgen_fpu*, SF, SF);
#endif
  virtual int eqsf (const cgen_fpu*, SF, SF);
  virtual int nesf (const cgen_fpu*, SF, SF);
  virtual int ltsf (const cgen_fpu*, SF, SF);
  virtual int lesf (const cgen_fpu*, SF, SF);
  virtual int gtsf (const cgen_fpu*, SF, SF);
  virtual int gesf (const cgen_fpu*, SF, SF);
  virtual int unorderedsf (const cgen_fpu*, SF, SF);

  /* basic DF ops */
  virtual DF adddf (const cgen_fpu*, DF, DF);
  virtual DF subdf (const cgen_fpu*, DF, DF);
  virtual DF muldf (const cgen_fpu*, DF, DF);
  virtual DF divdf (const cgen_fpu*, DF, DF);
  virtual DF negdf (const cgen_fpu*, DF);
  virtual DF absdf (const cgen_fpu*, DF);
  virtual DF sqrtdf (const cgen_fpu*, DF);
#if 0
  virtual DF invdf (const cgen_fpu*, DF);
  virtual DF cosdf (const cgen_fpu*, DF);
  virtual DF sindf (const cgen_fpu*, DF);
  virtual DF mindf (const cgen_fpu*, DF, DF);
  virtual DF maxdf (const cgen_fpu*, DF, DF);
#endif
  virtual int eqdf (const cgen_fpu*, DF, DF);
  virtual int nedf (const cgen_fpu*, DF, DF);
  virtual int ltdf (const cgen_fpu*, DF, DF);
  virtual int ledf (const cgen_fpu*, DF, DF);
  virtual int gtdf (const cgen_fpu*, DF, DF);
  virtual int gedf (const cgen_fpu*, DF, DF);
  virtual int unordereddf (const cgen_fpu*, DF, DF);

  /* SF/DF conversion ops */
  virtual DF fextsfdf (const cgen_fpu*, int, SF);
  virtual SF ftruncdfsf (const cgen_fpu*, int, DF);

  virtual SF floatsisf (const cgen_fpu*, int, SI);
  virtual SF floatdisf (const cgen_fpu*, int, DI);
#if 0 // not implemented yet
  virtual SF ufloatsisf (const cgen_fpu*, int, USI);
  virtual SF ufloatdisf (const cgen_fpu*, int, UDI);
#endif // not implemented yet

  virtual SI fixsfsi (const cgen_fpu*, int, SF);
  virtual DI fixsfdi (const cgen_fpu*, int, SF);
#if 0 // not implemented yet
  virtual USI ufixsfsi (const cgen_fpu*, int, SF);
  virtual UDI ufixsfdi (const cgen_fpu*, int, SF);
#endif
  virtual DF floatsidf (const cgen_fpu*, int, SI);
  virtual DF floatdidf (const cgen_fpu*, int, DI);
#if 0
  virtual DF ufloatsidf (const cgen_fpu*, int, USI);
  virtual DF ufloatdidf (const cgen_fpu*, int, UDI);
#endif
  virtual SI fixdfsi (const cgen_fpu*, int, DF);
  virtual DI fixdfdi (const cgen_fpu*, int, DF);
#if 0
  virtual USI ufixdfsi (const cgen_fpu*, int, DF);
  virtual UDI ufixdfdi (const cgen_fpu*, int, DF);

  /* XF mode support (kept separate 'cus not always present) */
  virtual XF addxf (const cgen_fpu*, XF, XF);
  virtual XF subxf (const cgen_fpu*, XF, XF);
  virtual XF mulxf (const cgen_fpu*, XF, XF);
  virtual XF divxf (const cgen_fpu*, XF, XF);
  virtual XF negxf (const cgen_fpu*, XF);
  virtual XF absxf (const cgen_fpu*, XF);
  virtual XF sqrtxf (const cgen_fpu*, XF);
  virtual XF invxf (const cgen_fpu*, XF);
  virtual XF cosxf (const cgen_fpu*, XF);
  virtual XF sinxf (const cgen_fpu*, XF);
  virtual XF minxf (const cgen_fpu*, XF, XF);
  virtual XF maxxf (const cgen_fpu*, XF, XF);

  virtual int eqxf (const cgen_fpu*, XF, XF);
  virtual int nexf (const cgen_fpu*, XF, XF);
  virtual int ltxf (const cgen_fpu*, XF, XF);
  virtual int lexf (const cgen_fpu*, XF, XF);
  virtual int gtxf (const cgen_fpu*, XF, XF);
  virtual int gexf (const cgen_fpu*, XF, XF);

  virtual XF extsfxf (const cgen_fpu*, int, SF);
  virtual XF extdfxf (const cgen_fpu*, int, DF);
  virtual SF truncxfsf (const cgen_fpu*, int, XF);
  virtual DF truncxfdf (const cgen_fpu*, int, XF);

  virtual XF floatsixf (const cgen_fpu*, int, SI);
  virtual XF floatdixf (const cgen_fpu*, int, DI);
  virtual XF ufloatsixf (const cgen_fpu*, int, USI);
  virtual XF ufloatdixf (const cgen_fpu*, int, UDI);

  virtual SI fixxfsi (const cgen_fpu*, int, XF);
  virtual DI fixxfdi (const cgen_fpu*, int, XF);
  virtual USI ufixxfsi (const cgen_fpu*, int, XF);
  virtual UDI ufixxfdi (const cgen_fpu*, int, XF);

  /* TF mode support (kept separate 'cus not always present) */
  virtual TF addtf (const cgen_fpu*, TF, TF);
  virtual TF subtf (const cgen_fpu*, TF, TF);
  virtual TF multf (const cgen_fpu*, TF, TF);
  virtual TF divtf (const cgen_fpu*, TF, TF);
  virtual TF negtf (const cgen_fpu*, TF);
  virtual TF abstf (const cgen_fpu*, TF);
  virtual TF sqrttf (const cgen_fpu*, TF);
  virtual TF invtf (const cgen_fpu*, TF);
  virtual TF costf (const cgen_fpu*, TF);
  virtual TF sintf (const cgen_fpu*, TF);
  virtual TF mintf (const cgen_fpu*, TF, TF);
  virtual TF maxtf (const cgen_fpu*, TF, TF);

  virtual int eqtf (const cgen_fpu*, TF, TF);
  virtual int netf (const cgen_fpu*, TF, TF);
  virtual int lttf (const cgen_fpu*, TF, TF);
  virtual int letf (const cgen_fpu*, TF, TF);
  virtual int gttf (const cgen_fpu*, TF, TF);
  virtual int getf (const cgen_fpu*, TF, TF);

  virtual TF extsftf (const cgen_fpu*, int, SF);
  virtual TF extdftf (const cgen_fpu*, int, DF);
  virtual SF trunctfsf (const cgen_fpu*, int, TF);
  virtual DF trunctfdf (const cgen_fpu*, int, TF);

  virtual TF floatsitf (const cgen_fpu*, int, SI);
  virtual TF floatditf (const cgen_fpu*, int, DI);
  virtual TF ufloatsitf (const cgen_fpu*, int, USI);
  virtual TF ufloatditf (const cgen_fpu*, int, UDI);

  virtual SI fixtfsi (const cgen_fpu*, int, TF);
  virtual DI fixtfdi (const cgen_fpu*, int, TF);
  virtual USI ufixtfsi (const cgen_fpu*, int, TF);
  virtual UDI ufixtfdi (const cgen_fpu*, int, TF);
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
