// cgen-ops.h - CGEN semantic ops.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_OPS_H
#define CGEN_OPS_H

namespace cgen {

#define ANDIF(x, y) ((x) && (y))
#define ORIF(x, y) ((x) || (y))

#define ANDBI(x, y) ((x) & (y))
#define ORBI(x, y) ((x) | (y))
#define XORBI(x, y) ((x) ^ (y))
#define NEGBI(x) (- (x))
#define NOTBI(x) (! (BI) (x))
#define INVBI(x) (~ (x))
#define EQBI(x, y) ((BI) (x) == (BI) (y))
#define NEBI(x, y) ((BI) (x) != (BI) (y))
#define LTBI(x, y) ((BI) (x) < (BI) (y))
#define LEBI(x, y) ((BI) (x) <= (BI) (y))
#define GTBI(x, y) ((BI) (x) > (BI) (y))
#define GEBI(x, y) ((BI) (x) >= (BI) (y))
#define LTUBI(x, y) ((BI) (x) < (BI) (y))
#define LEUBI(x, y) ((BI) (x) <= (BI) (y))
#define GTUBI(x, y) ((BI) (x) > (BI) (y))
#define GEUBI(x, y) ((BI) (x) >= (BI) (y))

#define ADDQI(x, y) ((x) + (y))
#define SUBQI(x, y) ((x) - (y))
#define MULQI(x, y) ((x) * (y))
#define DIVQI(x, y) ((QI) (x) / (QI) (y))
#define UDIVQI(x, y) ((UQI) (x) / (UQI) (y))
#define MODQI(x, y) ((QI) (x) % (QI) (y))
#define UMODQI(x, y) ((UQI) (x) % (UQI) (y))
#define SRAQI(x, y) ((QI) (x) >> (y))
#define SRLQI(x, y) ((UQI) (x) >> (y))
#define SLLQI(x, y) ((UQI) (x) << (y))
#define ANDQI(x, y) ((x) & (y))
#define ORQI(x, y) ((x) | (y))
#define XORQI(x, y) ((x) ^ (y))
#define NEGQI(x) (- (x))
#define NOTQI(x) (! (QI) (x))
#define INVQI(x) (~ (x))
#define EQQI(x, y) ((QI) (x) == (QI) (y))
#define NEQI(x, y) ((QI) (x) != (QI) (y))
#define LTQI(x, y) ((QI) (x) < (QI) (y))
#define LEQI(x, y) ((QI) (x) <= (QI) (y))
#define GTQI(x, y) ((QI) (x) > (QI) (y))
#define GEQI(x, y) ((QI) (x) >= (QI) (y))
#define LTUQI(x, y) ((UQI) (x) < (UQI) (y))
#define LEUQI(x, y) ((UQI) (x) <= (UQI) (y))
#define GTUQI(x, y) ((UQI) (x) > (UQI) (y))
#define GEUQI(x, y) ((UQI) (x) >= (UQI) (y))
#define ABSQI(x)  ((x) > 0 ? (x) : -(x))

#define ADDHI(x, y) ((x) + (y))
#define SUBHI(x, y) ((x) - (y))
#define MULHI(x, y) ((x) * (y))
#define DIVHI(x, y) ((HI) (x) / (HI) (y))
#define UDIVHI(x, y) ((UHI) (x) / (UHI) (y))
#define MODHI(x, y) ((HI) (x) % (HI) (y))
#define UMODHI(x, y) ((UHI) (x) % (UHI) (y))
#define SRAHI(x, y) ((HI) (x) >> (y))
#define SRLHI(x, y) ((UHI) (x) >> (y))
#define SLLHI(x, y) ((UHI) (x) << (y))
#define ANDHI(x, y) ((x) & (y))
#define ORHI(x, y) ((x) | (y))
#define XORHI(x, y) ((x) ^ (y))
#define NEGHI(x) (- (x))
#define NOTHI(x) (! (HI) (x))
#define INVHI(x) (~ (x))
#define EQHI(x, y) ((HI) (x) == (HI) (y))
#define NEHI(x, y) ((HI) (x) != (HI) (y))
#define LTHI(x, y) ((HI) (x) < (HI) (y))
#define LEHI(x, y) ((HI) (x) <= (HI) (y))
#define GTHI(x, y) ((HI) (x) > (HI) (y))
#define GEHI(x, y) ((HI) (x) >= (HI) (y))
#define LTUHI(x, y) ((UHI) (x) < (UHI) (y))
#define LEUHI(x, y) ((UHI) (x) <= (UHI) (y))
#define GTUHI(x, y) ((UHI) (x) > (UHI) (y))
#define GEUHI(x, y) ((UHI) (x) >= (UHI) (y))
#define ABSHI(x)  ((x) > 0 ? (x) : -(x))

#define ADDSI(x, y) ((x) + (y))
#define SUBSI(x, y) ((x) - (y))
#define MULSI(x, y) ((x) * (y))
#define DIVSI(x, y) ((SI) (x) / (SI) (y))
#define UDIVSI(x, y) ((USI) (x) / (USI) (y))
#define MODSI(x, y) ((SI) (x) % (SI) (y))
#define UMODSI(x, y) ((USI) (x) % (USI) (y))
#define SRASI(x, y) ((SI) (x) >> (y))
#define SRLSI(x, y) ((USI) (x) >> (y))
#define SLLSI(x, y) ((USI) (x) << (y))
#define ANDSI(x, y) ((x) & (y))
#define ORSI(x, y) ((x) | (y))
#define XORSI(x, y) ((x) ^ (y))
#define NEGSI(x) (- (x))
#define NOTSI(x) (! (SI) (x))
#define INVSI(x) (~ (x))
#define EQSI(x, y) ((SI) (x) == (SI) (y))
#define NESI(x, y) ((SI) (x) != (SI) (y))
#define LTSI(x, y) ((SI) (x) < (SI) (y))
#define LESI(x, y) ((SI) (x) <= (SI) (y))
#define GTSI(x, y) ((SI) (x) > (SI) (y))
#define GESI(x, y) ((SI) (x) >= (SI) (y))
#define LTUSI(x, y) ((USI) (x) < (USI) (y))
#define LEUSI(x, y) ((USI) (x) <= (USI) (y))
#define GTUSI(x, y) ((USI) (x) > (USI) (y))
#define GEUSI(x, y) ((USI) (x) >= (USI) (y))
#define ABSSI(x)  ((x) > 0 ? (x) : -(x))

#define ADDDI(x, y) ((x) + (y))
#define SUBDI(x, y) ((x) - (y))
#define MULDI(x, y) ((x) * (y))
#define DIVDI(x, y) ((DI) (x) / (DI) (y))
#define UDIVDI(x, y) ((UDI) (x) / (UDI) (y))
#define MODDI(x, y) ((DI) (x) % (DI) (y))
#define UMODDI(x, y) ((UDI) (x) % (UDI) (y))
#define SRADI(x, y) ((DI) (x) >> (y))
#define SRLDI(x, y) ((UDI) (x) >> (y))
#define SLLDI(x, y) ((UDI) (x) << (y))
#define ANDDI(x, y) ((x) & (y))
#define ORDI(x, y) ((x) | (y))
#define XORDI(x, y) ((x) ^ (y))
#define NEGDI(x) (- (x))
#define NOTDI(x) (! (DI) (x))
#define INVDI(x) (~ (x))
#define EQDI(x, y) ((DI) (x) == (DI) (y))
#define NEDI(x, y) ((DI) (x) != (DI) (y))
#define LTDI(x, y) ((DI) (x) < (DI) (y))
#define LEDI(x, y) ((DI) (x) <= (DI) (y))
#define GTDI(x, y) ((DI) (x) > (DI) (y))
#define GEDI(x, y) ((DI) (x) >= (DI) (y))
#define LTUDI(x, y) ((UDI) (x) < (UDI) (y))
#define LEUDI(x, y) ((UDI) (x) <= (UDI) (y))
#define GTUDI(x, y) ((UDI) (x) > (UDI) (y))
#define GEUDI(x, y) ((UDI) (x) >= (UDI) (y))
#define ABSDI(x)  ((x) > 0 ? (x) : -(x))

#define LTUINT(x, y) ((UINT) (x) < (UINT) (y))
#define LEUINT(x, y) ((UINT) (x) <= (UINT) (y))
#define GTUINT(x, y) ((UINT) (x) > (UINT) (y))
#define GEUINT(x, y) ((UINT) (x) >= (UINT) (y))

// XXX: fill out families of functions
#define RORQI(x, y) (SRLQI((x), (y)) | SLLQI((x), 8-(y)))
#define ROLQI(x, y) (SLLQI((x), (y)) | SRLQI((x), 8-(y)))
#define RORHI(x, y) (SRLHI((x), (y)) | SLLHI((x), 16-(y)))
#define ROLHI(x, y) (SLLHI((x), (y)) | SRLHI((x), 16-(y)))
#define RORSI(x, y) (SRLSI((x), (y)) | SLLSI((x), 32-(y)))
#define ROLSI(x, y) (SLLSI((x), (y)) | SRLSI((x), 32-(y)))
#define JOINSIDI(x, y)  (MAKEDI(x, y))
#define JOINUQIUHI(x, y)  (((x) << 8) | (y))
#define JOINHISI(x, y)  (((x) << 16) | (y))
// XXX: endianness issues undecided
#define SUBWORDDISI(x, y) ((y) == 0 ? GETHIDI(x) : GETLODI(x))
#define SUBWORDSISI(x) ((SI) (x))
#define SUBWORDHIQI(x, y) ((y) == 0 ? ((x) >> 8) : ((QI) (x)))
#define SUBWORDHIHI(x) ((HI) (x))
#define SUBWORDHIUHI(x) ((HI) (x))
#define SUBWORDUHIUQI(x, y) (SUBWORDHIQI((x), (y)))
#define SUBWORDBIHI(x) ((x) ? true : false)

// Floating point.

#define ADDSF(x, y) ((x) + (y))
#define SUBSF(x, y) ((x) - (y))
#define NEGSF(x) (- (x))
#define MULSF(x, y) ((x) * (y))
#define DIVSF(x, y) ((x) / (y))
#define EQSF(x, y) ((SF) (x) == (SF) (y))
#define NESF(x, y) ((SF) (x) != (SF) (y))
#define LTSF(x, y) ((SF) (x) < (SF) (y))
#define LESF(x, y) ((SF) (x) <= (SF) (y))
#define GTSF(x, y) ((SF) (x) > (SF) (y))
#define GESF(x, y) ((SF) (x) >= (SF) (y))

#define ADDDF(x, y) ((x) + (y))
#define SUBDF(x, y) ((x) - (y))
#define NEGDF(x) (- (x))
#define MULDF(x, y) ((x) * (y))
#define DIVDF(x, y) ((x) / (y))
#define EQDF(x, y) ((DF) (x) == (DF) (y))
#define NEDF(x, y) ((DF) (x) != (DF) (y))
#define LTDF(x, y) ((DF) (x) < (DF) (y))
#define LEDF(x, y) ((DF) (x) <= (DF) (y))
#define GTDF(x, y) ((DF) (x) > (DF) (y))
#define GEDF(x, y) ((DF) (x) >= (DF) (y))

#define ADDXF(x, y) ((x) + (y))
#define SUBXF(x, y) ((x) - (y))
#define NEGXF(x) (- (x))
#define MULXF(x, y) ((x) * (y))
#define DIVXF(x, y) ((x) / (y))
#define EQXF(x, y) ((XF) (x) == (XF) (y))
#define NEXF(x, y) ((XF) (x) != (XF) (y))
#define LTXF(x, y) ((XF) (x) < (XF) (y))
#define LEXF(x, y) ((XF) (x) <= (XF) (y))
#define GTXF(x, y) ((XF) (x) > (XF) (y))
#define GEXF(x, y) ((XF) (x) >= (XF) (y))

#define ADDTF(x, y) ((x) + (y))
#define SUBTF(x, y) ((x) - (y))
#define NEGTF(x) (- (x))
#define MULTF(x, y) ((x) * (y))
#define DIVTF(x, y) ((x) / (y))
#define EQTF(x, y) ((TF) (x) == (TF) (y))
#define NETF(x, y) ((TF) (x) != (TF) (y))
#define LTTF(x, y) ((TF) (x) < (TF) (y))
#define LETF(x, y) ((TF) (x) <= (TF) (y))
#define GTTF(x, y) ((TF) (x) > (TF) (y))
#define GETF(x, y) ((TF) (x) >= (TF) (y))

#define EXTBIQI(x) ((QI) (BI) (x))
#define EXTBIHI(x) ((HI) (BI) (x))
#define EXTBISI(x) ((SI) (BI) (x))
#define EXTBIDI(x) ((DI) (BI) (x))
#define EXTQIQI(x) ((QI) (x))
#define EXTQIHI(x) ((HI) (QI) (x))
#define EXTQISI(x) ((SI) (QI) (x))
#define EXTQIDI(x) ((DI) (QI) (x))
#define EXTHIHI(x) ((HI) (x))
#define EXTHISI(x) ((SI) (HI) (x))
#define EXTHIDI(x) ((DI) (HI) (x))
#define EXTSISI(x) ((SI) (x))
#define EXTSIDI(x) ((DI) (SI) (x))
#define EXTDIDI(x) ((DI) (x))
#define EXTSFDF(x) ((DF) (SF) (x))
#define EXTSFXF(x) ((XF) (SF) (x))
#define EXTSFTF(x) ((TF) (SF) (x))
#define EXTDFXF(x) ((XF) (DF) (x))
#define EXTDFTF(x) ((TF) (DF) (x))
#define EXTXFTF(x) ((TF) (XF) (x))

#define ZEXTBIQI(x) ((QI) (BI) (x))
#define ZEXTBIHI(x) ((HI) (BI) (x))
#define ZEXTBISI(x) ((SI) (BI) (x))
#define ZEXTBIDI(x) ((DI) (BI) (x))
#define ZEXTQIQI(x) ((UQI) (x))
#define ZEXTQIHI(x) ((HI) (UQI) (x))
#define ZEXTQISI(x) ((SI) (UQI) (x))
#define ZEXTQIDI(x) ((DI) (UQI) (x))
#define ZEXTHIHI(x) ((UHI) (x))
#define ZEXTHISI(x) ((SI) (UHI) (x))
#define ZEXTHIDI(x) ((DI) (UHI) (x))
#define ZEXTSISI(x) ((USI) (x))
#define ZEXTSIDI(x) ((DI) (USI) (x))
#define ZEXTDIDI(x) ((UDI) (x))

#define TRUNCQIBI(x) ((BI) (QI) (x))
#define TRUNCQIQI(x) ((QI) (x))
#define TRUNCHIBI(x) ((BI) (HI) (x))
#define TRUNCHIQI(x) ((QI) (HI) (x))
#define TRUNCHIHI(x) ((HI) (x))
#define TRUNCSIBI(x) ((BI) (SI) (x))
#define TRUNCSIQI(x) ((QI) (SI) (x))
#define TRUNCSIHI(x) ((HI) (SI) (x))
#define TRUNCSISI(x) ((SI) (x))
#define TRUNCDIBI(x) ((BI) (DI) (x))
#define TRUNCDIQI(x) ((QI) (DI) (x))
#define TRUNCDIHI(x) ((HI) (DI) (x))
#define TRUNCDISI(x) ((SI) (DI) (x))
#define TRUNCDIDI(x) ((DI) (x))
#define TRUNCDFSF(x) ((SF) (DF) (x))
#define TRUNCXFSF(x) ((SF) (XF) (x))
#define TRUNCXFDF(x) ((DF) (XF) (x))
#define TRUNCTFSF(x) ((SF) (TF) (x))
#define TRUNCTFDF(x) ((DF) (TF) (x))
#define TRUNCTFXF(x) ((XF) (TF) (x))

#define FLOATQISF(x) ((SF) (QI) (x))
#define FLOATQIDF(x) ((DF) (QI) (x))
#define FLOATQIXF(x) ((XF) (QI) (x))
#define FLOATQITF(x) ((TF) (QI) (x))
#define FLOATHISF(x) ((SF) (HI) (x))
#define FLOATHIDF(x) ((DF) (HI) (x))
#define FLOATHIXF(x) ((XF) (HI) (x))
#define FLOATHITF(x) ((TF) (HI) (x))
#define FLOATSISF(x) ((SF) (SI) (x))
#define FLOATSIDF(x) ((DF) (SI) (x))
#define FLOATSIXF(x) ((XF) (SI) (x))
#define FLOATSITF(x) ((TF) (SI) (x))
#define FLOATDISF(x) ((SF) (DI) (x))
#define FLOATDIDF(x) ((DF) (DI) (x))
#define FLOATDIXF(x) ((XF) (DI) (x))
#define FLOATDITF(x) ((TF) (DI) (x))

#define UFLOATQISF(x) ((SF) (UQI) (x))
#define UFLOATQIDF(x) ((DF) (UQI) (x))
#define UFLOATQIXF(x) ((XF) (UQI) (x))
#define UFLOATQITF(x) ((TF) (UQI) (x))
#define UFLOATHISF(x) ((SF) (UHI) (x))
#define UFLOATHIDF(x) ((DF) (UHI) (x))
#define UFLOATHIXF(x) ((XF) (UHI) (x))
#define UFLOATHITF(x) ((TF) (UHI) (x))
#define UFLOATSISF(x) ((SF) (USI) (x))
#define UFLOATSIDF(x) ((DF) (USI) (x))
#define UFLOATSIXF(x) ((XF) (USI) (x))
#define UFLOATSITF(x) ((TF) (USI) (x))
#define UFLOATDISF(x) ((SF) (UDI) (x))
#define UFLOATDIDF(x) ((DF) (UDI) (x))
#define UFLOATDIXF(x) ((XF) (UDI) (x))
#define UFLOATDITF(x) ((TF) (UDI) (x))

#define FIXSFBI(x) ((BI) (SF) (x))
#define FIXSFQI(x) ((QI) (SF) (x))
#define FIXSFHI(x) ((HI) (SF) (x))
#define FIXSFSI(x) ((SI) (SF) (x))
#define FIXSFDI(x) ((DI) (SF) (x))
#define FIXDFBI(x) ((BI) (DF) (x))
#define FIXDFQI(x) ((QI) (DF) (x))
#define FIXDFHI(x) ((HI) (DF) (x))
#define FIXDFSI(x) ((SI) (DF) (x))
#define FIXDFDI(x) ((DI) (DF) (x))
#define FIXXFBI(x) ((BI) (XF) (x))
#define FIXXFQI(x) ((QI) (XF) (x))
#define FIXXFHI(x) ((HI) (XF) (x))
#define FIXXFSI(x) ((SI) (XF) (x))
#define FIXXFDI(x) ((DI) (XF) (x))
#define FIXTFBI(x) ((BI) (TF) (x))
#define FIXTFQI(x) ((QI) (TF) (x))
#define FIXTFHI(x) ((HI) (TF) (x))
#define FIXTFSI(x) ((SI) (TF) (x))
#define FIXTFDI(x) ((DI) (TF) (x))

#define UFIXSFQI(x) ((UQI) (SF) (x))
#define UFIXSFHI(x) ((UHI) (SF) (x))
#define UFIXSFSI(x) ((USI) (SF) (x))
#define UFIXSFDI(x) ((UDI) (SF) (x))
#define UFIXDFQI(x) ((UQI) (DF) (x))
#define UFIXDFHI(x) ((UHI) (DF) (x))
#define UFIXDFSI(x) ((USI) (DF) (x))
#define UFIXDFDI(x) ((UDI) (DF) (x))
#define UFIXXFQI(x) ((UQI) (XF) (x))
#define UFIXXFHI(x) ((UHI) (XF) (x))
#define UFIXXFSI(x) ((USI) (XF) (x))
#define UFIXXFDI(x) ((UDI) (XF) (x))
#define UFIXTFQI(x) ((UQI) (TF) (x))
#define UFIXTFHI(x) ((UHI) (TF) (x))
#define UFIXTFSI(x) ((USI) (TF) (x))
#define UFIXTFDI(x) ((UDI) (TF) (x))

// Semantic support utilities.

inline QI
ADDCQI (QI a, QI b, BI c)
{
  QI res = ADDQI (a, ADDQI (b, c));
  return res;
}

inline HI
ADDCHI (HI a, HI b, HI c)
{
  HI res = ADDHI (a, ADDHI (b, c));
  return res;
}

inline SI
ADDCSI (SI a, SI b, BI c)
{
  SI res = ADDSI (a, ADDSI (b, c));
  return res;
}

inline DI
ADDCDI (DI a, DI b, DI c)
{
  DI res = ADDDI (a, ADDDI (b, c));
  return res;
}

inline BI
ADDCFQI (QI a, QI b, BI c)
{
  QI tmp = ADDQI (a, ADDQI (b, c));
  BI res = ((UQI) tmp < (UQI) a) || (c && tmp == a);
  return res;
}

inline BI
ADDCFHI (HI a, HI b, BI c)
{
  HI tmp = ADDHI (a, ADDHI (b, c));
  BI res = ((UHI) tmp < (UHI) a) || (c && tmp == a);
  return res;
}

inline BI
ADDCFSI (SI a, SI b, BI c)
{
  SI tmp = ADDSI (a, ADDSI (b, c));
  BI res = ((USI) tmp < (USI) a) || (c && tmp == a);
  return res;
}

inline BI
ADDCFDI (DI a, DI b, BI c)
{
  DI tmp = ADDDI (a, ADDDI (b, c));
  BI res = ((UDI) tmp < (UDI) a) || (c && tmp == a);
  return res;
}

inline BI
ADDOFHI (HI a, HI b, BI c)
{
  HI tmp = ADDHI (a, ADDHI (b, c));
  BI res = (((a < 0) == (b < 0))
	    && ((a < 0) != (tmp < 0)));
  return res;
}

inline BI
ADDOFSI (SI a, SI b, BI c)
{
  SI tmp = ADDSI (a, ADDSI (b, c));
  BI res = (((a < 0) == (b < 0))
	    && ((a < 0) != (tmp < 0)));
  return res;
}


inline BI
ADDOFDI (DI a, DI b, BI c)
{
  DI tmp = ADDDI (a, ADDDI (b, c));
  BI res = (((a < 0) == (b < 0))
	    && ((a < 0) != (tmp < 0)));
  return res;
}

inline QI
SUBCQI (QI a, QI b, BI c)
{
  QI res = SUBQI (a, ADDQI (b, c));
  return res;
}

inline HI
SUBCHI (HI a, HI b, BI c)
{
  HI res = SUBHI (a, ADDHI (b, c));
  return res;
}

inline SI
SUBCSI (SI a, SI b, BI c)
{
  SI res = SUBSI (a, ADDSI (b, c));
  return res;
}

inline BI
SUBCFQI (QI a, QI b, BI c)
{
  BI res = ((UQI) a < (UQI) b) || (c && a == b);
  return res;
}

inline BI
SUBCFHI (HI a, HI b, BI c)
{
  BI res = ((UHI) a < (UHI) b) || (c && a == b);
  return res;
}

inline BI
SUBCFSI (SI a, SI b, BI c)
{
  BI res = ((USI) a < (USI) b) || (c && a == b);
  return res;
}

inline BI
SUBOFHI (HI a, HI b, BI c)
{
  HI tmp = SUBHI (a, ADDHI (b, c));
  BI res = (((a < 0) != (b < 0))
	    && ((a < 0) != (tmp < 0)));
  return res;
}

inline BI
SUBOFSI (SI a, SI b, BI c)
{
  SI tmp = SUBSI (a, ADDSI (b, c));
  BI res = (((a < 0) != (b < 0))
	    && ((a < 0) != (tmp < 0)));
  return res;
}

inline BI
SUBOFDI (DI a, DI b, DI c)
{
  DI tmp = SUBDI (a, ADDDI (b, c));
  BI res = (((a < 0) != (b < 0))
	    && ((a < 0) != (tmp < 0)));
  return res;
}

inline QI
SUBWORDSIQI (SI in, int byte)
{
  assert (byte >= 0 && byte <= 3);
  return static_cast<UQI> ((in >> (8 * (3 - byte))) & 0xFF);
}


inline HI
SUBWORDSIHI (SI in, int word)
{
  if (word == 0)
    return static_cast<USI> (in >> 16);
  else
    return in;
}

inline SI
SUBWORDSFSI (SF in)
{
  SI* out = reinterpret_cast<SI*> (&in);
  return *out;
}

inline SF
SUBWORDSISF (SI in)
{
  SF* out = reinterpret_cast<SF*> (&in);
  return *out;
}

inline DF
SUBWORDDIDF (DI in)
{
  DF* out = reinterpret_cast<DF*> (&in);
  return *out;
}

inline SI
SUBWORDDFSI (DF in, int word)
{
  DI* di = reinterpret_cast<DI*> (&in);
  return SUBWORDDISI (*di, word);
}

inline UQI
SUBWORDSIUQI (SI in, int byte)
{
  assert (byte >= 0 && byte <= 7);
  return static_cast<UQI> ((in >> (8 * (3 - byte))) & 0xFF);
}

} // namespace cgen

#endif // CGEN_OPS_H
