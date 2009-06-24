// ivc2-cop.cxx - CPU components.  -*- C++ -*-
// CGEN cop support for the MeP IVC2 coprocessor for SID
//
// Copyright (C) 2009 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "mep.h"

extern "C" {
#include "bfd.h"
#include "dis-asm.h"
}

#define cr(x)   h_cr_ivc2_get ((x))
#define cw(x,v) h_cr_ivc2_set ((x), (v))
#define ccr(x)   h_ccr_ivc2_get ((x))
#define ccw(x,v) h_ccr_ivc2_set ((x), (v))

template <typename TY>
static void unpack (DI val, TY ptr[])
{
  int i;
  for (i=0; i<sizeof(DI)/sizeof(TY); i++)
    ptr[i] = val >> (i*sizeof(TY)*8);
}

template <typename TY>
static DI pack (TY ptr[])
{
  DI rv = 0;
  int i;
  for (i=0; i<sizeof(DI)/sizeof(TY); i++)
    rv |= (DI)(ptr[i] & ((1LL<<(sizeof(TY)*8))-1)) << (i*sizeof(TY)*8);
  return rv;
}
  

// Definitions of special-purpose coprocessor control registers.

#define IVC2_CSAR0	0
#define IVC2_CC		1
#define IVC2_COFR0	4
#define IVC2_COFR1	5
#define IVC2_COFA0	6
#define IVC2_COFA1	7

#define IVC2_CSAR1	15

#define IVC2_ACC0_0	16
#define IVC2_ACC0_1	17
#define IVC2_ACC0_2	18
#define IVC2_ACC0_3	19
#define IVC2_ACC0_4	20
#define IVC2_ACC0_5	21
#define IVC2_ACC0_6	22
#define IVC2_ACC0_7	23

#define IVC2_ACC1_0	24
#define IVC2_ACC1_1	25
#define IVC2_ACC1_2	26
#define IVC2_ACC1_3	27
#define IVC2_ACC1_4	28
#define IVC2_ACC1_5	29
#define IVC2_ACC1_6	30
#define IVC2_ACC1_7	31

#define A1r(i)		ccr (IVC2_ACC1_0+(i))
#define A1w(i,d)	ccw (IVC2_ACC1_0+(i),(d))
#define A0r(i)		ccr (IVC2_ACC0_0+(i))
#define A0w(i,d)	ccw (IVC2_ACC0_0+(i),(d))

static int
di_msbs (DI a, DI b, DI c)
{
  int rv = (a >> 61) & 4;
  rv |= (b >> 62) & 2;
  rv |= (c >> 63) & 1;
  return rv;
}

static const char *
di(DI op)
{
  static char buf[4][40];
  static int bi = 0;
  static const char hex[] = "0123456789abcdef";
  int i;
  char *bp;

  bi = (bi+1) % 4;
  bp = buf[bi];
  for (i=0; i<16; i++)
    {
      if (i && (i%4==0))
	*bp++ = '_';
      *bp++ = hex[(op >> ((15-i)*4)) & 0x0f];
    }
  *bp = 0;
  return buf[bi];
}
static const char *
si(SI op)
{
  static char buf[4][40];
  static int bi = 0;
  static const char hex[] = "0123456789abcdef";
  int i;
  char *bp;

  bi = (bi+1) % 4;
  bp = buf[bi];
  for (i=0; i<8; i++)
    {
      if (i && (i%4==0))
	*bp++ = '_';
      *bp++ = hex[(op >> ((7-i)*4)) & 0x0f];
    }
  *bp = 0;
  return buf[bi];
}


// 1111 000 ooooo 0111 00000 qqqqq ppppp 0   cpadd3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpadd3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] + p[i];

  return pack(o);
}

// 1111 001 ooooo 0111 00000 qqqqq ppppp 0   cpadd3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpadd3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] + p[i];

  return pack(o);
}

// 1111 010 ooooo 0111 00000 qqqqq ppppp 0   cpadd3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpadd3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] + p[i];

  return pack(o);
}

// 1111 011 ooooo 0111 00000 qqqqq ppppp 0   cdadd3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdadd3 (PCADDR &pc, DI crqc, DI crpc)
{
  return crqc + crpc;
}

// 1111 100 ooooo 0111 00000 qqqqq ppppp 0   cpsub3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsub3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] - p[i];

  return pack(o);
}

// 1111 101 ooooo 0111 00000 qqqqq ppppp 0   cpsub3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsub3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] - p[i];

  return pack(o);
}

// 1111 110 ooooo 0111 00000 qqqqq ppppp 0   cpsub3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsub3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] - p[i];

  return pack(o);
}

// 1111 111 ooooo 0111 00000 qqqqq ppppp 0   cdsub3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdsub3 (PCADDR &pc, DI crqc, DI crpc)
{
  return crqc - crpc;
}

// 1111 000 ooooo 0111 00001 qqqqq ppppp 0   cpand3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpand3 (PCADDR &pc, DI crqc, DI crpc)
{
  return crqc & crpc;
}

// 1111 001 ooooo 0111 00001 qqqqq ppppp 0   cpor3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpor3 (PCADDR &pc, DI crqc, DI crpc)
{
  return crqc | crpc;
}

// 1111 010 ooooo 0111 00001 qqqqq ppppp 0   cpnor3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpnor3 (PCADDR &pc, DI crqc, DI crpc)
{
  return ~ ( crqc | crpc );
}

// 1111 011 ooooo 0111 00001 qqqqq ppppp 0   cpxor3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpxor3 (PCADDR &pc, DI crqc, DI crpc)
{
  return crqc ^ crpc;
}

// 1111 100 ooooo 0111 00001 qqqqq ppppp 0   cpsel =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsel (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  int cc = ccr(IVC2_CC);
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);
  for (i=0; i<8; i++)
    o[i] = (cc & (1<<i)) ? q[i] : p[i];

  return pack(o);
}

// 1111 iii ooooo 0111 11101 qqqqq ppppp 0   cpfsftbi =croc,crqc,crpc,imm3 (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpfsftbi (PCADDR &pc, DI crqc, DI crpc, SI imm3)
{
  return (crqc << (imm3*8)) | (crpc >> (64-imm3*8));
}

// 1111 110 ooooo 0111 00001 qqqqq ppppp 0   cpfsftbs0 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpfsftbs0 (PCADDR &pc, DI crqc, DI crpc)
{
  int shift = ccr (IVC2_CSAR0) * 8;

  return (crqc << (shift)) | (crpc >> (64-shift));
}

// 1111 111 ooooo 0111 00001 qqqqq ppppp 0   cpfsftbs1 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpfsftbs1 (PCADDR &pc, DI crqc, DI crpc)
{
  int shift = ccr (IVC2_CSAR1) * 8;

  return (crqc << (shift)) | (crpc >> (64-shift));
}

// 1111 000 ooooo 0111 00010 qqqqq ppppp 0   cpunpacku.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpunpacku_b (PCADDR &pc, DI crqc, DI crpc)
{
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  o[7] = q[7]; o[6] = p[7];
  o[5] = q[6]; o[4] = p[6];
  o[3] = q[5]; o[2] = p[5];
  o[1] = q[4]; o[0] = p[4];

  return pack (o);
}

// 1111 001 ooooo 0111 00010 qqqqq ppppp 0   cpunpacku.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpunpacku_h (PCADDR &pc, DI crqc, DI crpc)
{
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  o[3] = q[3]; o[2] = p[3];
  o[1] = q[2]; o[0] = p[2];

  return pack (o);
}

// 1111 010 ooooo 0111 00010 qqqqq ppppp 0   cpunpacku.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpunpacku_w (PCADDR &pc, DI crqc, DI crpc)
{
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  o[1] = q[1]; o[0] = p[1];

  return pack (o);
}

// 1111 100 ooooo 0111 00010 qqqqq ppppp 0   cpunpackl.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpunpackl_b (PCADDR &pc, DI crqc, DI crpc)
{
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  o[7] = q[3]; o[6] = p[3];
  o[5] = q[2]; o[4] = p[2];
  o[3] = q[1]; o[2] = p[1];
  o[1] = q[0]; o[0] = p[0];

  return pack (o);
}

// 1111 101 ooooo 0111 00010 qqqqq ppppp 0   cpunpackl.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpunpackl_h (PCADDR &pc, DI crqc, DI crpc)
{
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  o[3] = q[1]; o[2] = p[1];
  o[1] = q[0]; o[0] = p[0];

  return pack (o);
}

// 1111 110 ooooo 0111 00010 qqqqq ppppp 0   cpunpackl.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpunpackl_w (PCADDR &pc, DI crqc, DI crpc)
{
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  o[1] = q[0]; o[0] = p[0];

  return pack (o);
}

// 1111 100 ooooo 0111 00011 qqqqq ppppp 0   cppacku.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppacku_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI o[8];
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      o[i+4] = (q[i] > 255) ? 255 : (q[i] < 0) ? 0 : q[i];
      o[i]   = (p[i] > 255) ? 255 : (p[i] < 0) ? 0 : p[i];
    }

  return pack (o);
}

// 1111 101 ooooo 0111 00011 qqqqq ppppp 0   cppack.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppack_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI o[8];
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      o[i+4] = (q[i] > 127) ? 127 : (q[i] < -128) ? -128 : q[i];
      o[i]   = (p[i] > 127) ? 127 : (p[i] < -128) ? -128 : p[i];
    }

  return pack (o);
}

// 1111 111 ooooo 0111 00011 qqqqq ppppp 0   cppack.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppack_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI o[4];
  SI q[2], p[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      o[i+2] = (q[i] > 32767) ? 32767 : (q[i] < -32768) ? -32768 : q[i];
      o[i]   = (p[i] > 32767) ? 32767 : (p[i] < -32768) ? -32768 : p[i];
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 qqqqq ppppp 0   cpsrl3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsrl3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], o[8];

  unpack (crqc, q);

  for (i=0; i<8; i++)
    o[i] = q[i] >> (crpc & 7);

  return pack (o);
}

// 1111 001 ooooo 0111 00100 qqqqq ppppp 0   cpssrl3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssrl3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] >> (p[i] & 7);

  return pack (o);
}

// 1111 010 ooooo 0111 00100 qqqqq ppppp 0   cpsrl3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsrl3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UHI q[4], o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i] >> (crpc & 15);

  return pack (o);
}

// 1111 011 ooooo 0111 00100 qqqqq ppppp 0   cpssrl3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssrl3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UHI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] >> (p[i] & 15);

  return pack (o);
}

// 1111 100 ooooo 0111 00100 qqqqq ppppp 0   cpsrl3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsrl3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i] >> (crpc & 31);

  return pack (o);
}

// 1111 101 ooooo 0111 00100 qqqqq ppppp 0   cpssrl3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssrl3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] >> (p[i] & 31);

  return pack (o);
}

// 1111 110 ooooo 0111 00100 qqqqq ppppp 0   cdsrl3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdsrl3 (PCADDR &pc, DI crqc, DI crpc)
{
  return (UDI)crqc >> (crpc & 63);
}

// 1111 000 ooooo 0111 00101 qqqqq ppppp 0   cpsra3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsra3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], o[8];

  unpack (crqc, q);

  for (i=0; i<8; i++)
    o[i] = q[i] >> (crpc & 7);

  return pack (o);
}

// 1111 001 ooooo 0111 00101 qqqqq ppppp 0   cpssra3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssra3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] >> (p[i] & 7);

  return pack (o);
}

// 1111 010 ooooo 0111 00101 qqqqq ppppp 0   cpsra3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsra3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i] >> (crpc & 15);

  return pack (o);
}

// 1111 011 ooooo 0111 00101 qqqqq ppppp 0   cpssra3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssra3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] >> (p[i] & 15);

  return pack (o);
}

// 1111 100 ooooo 0111 00101 qqqqq ppppp 0   cpsra3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsra3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i] >> (crpc & 31);

  return pack (o);
}

// 1111 101 ooooo 0111 00101 qqqqq ppppp 0   cpssra3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssra3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] >> (p[i] & 31);

  return pack (o);
}

// 1111 110 ooooo 0111 00101 qqqqq ppppp 0   cdsra3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdsra3 (PCADDR &pc, DI crqc, DI crpc)
{
  return crqc >> (crpc & 63);
}

// 1111 000 ooooo 0111 00110 qqqqq ppppp 0   cpsll3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsll3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], o[8];

  unpack (crqc, q);

  for (i=0; i<8; i++)
    o[i] = q[i] << (crpc & 7);

  return pack (o);
}

// 1111 001 ooooo 0111 00110 qqqqq ppppp 0   cpssll3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssll3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] << (p[i] & 7);

  return pack (o);
}

// 1111 010 ooooo 0111 00110 qqqqq ppppp 0   cpsll3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsll3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UHI q[4], o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i] << (crpc & 15);

  return pack (o);
}

// 1111 011 ooooo 0111 00110 qqqqq ppppp 0   cpssll3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssll3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UHI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] << (p[i] & 15);

  return pack (o);
}

// 1111 100 ooooo 0111 00110 qqqqq ppppp 0   cpsll3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsll3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i] << (crpc & 31);

  return pack (o);
}

// 1111 101 ooooo 0111 00110 qqqqq ppppp 0   cpssll3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssll3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] << (p[i] & 31);

  return pack (o);
}

// 1111 110 ooooo 0111 00110 qqqqq ppppp 0   cdsll3 =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdsll3 (PCADDR &pc, DI crqc, DI crpc)
{
  return (UDI)crqc << (crpc & 63);
}

// 1111 010 ooooo 0111 00111 qqqqq ppppp 0   cpsla3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsla3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i, cofr_idx;
  USI cofr;
  HI q[4], o[4];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);

  for (i=0; i<4; i++)
    {
      SI tmp = q[i];
      tmp <<= (crpc & 15);
      if (tmp > 0x7fff)
	{
	  o[i] = 0x7fff;
	  cofr |= (3 << i*2);
	}
      else if (tmp < -0x8000)
	{
	  o[i] = -0x8000;
	  cofr |= (3 << i*2);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack (o);
}

// 1111 100 ooooo 0111 00111 qqqqq ppppp 0   cpsla3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsla3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i, cofr_idx;
  USI cofr;
  SI q[2], o[2];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);

  for (i=0; i<2; i++)
    {
      DI tmp = q[i];
      tmp <<= (crpc & 15);
      if (tmp > 0x7fffffffLL)
	{
	  o[i] = 0x7fffffffLL;
	  cofr |= (15 << i*4);
	}
      else if (tmp < -0x80000000LL)
	{
	  o[i] = -0x80000000LL;
	  cofr |= (15 << i*4);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack (o);
}

// 1111 010 ooooo 0111 01000 qqqqq ppppp 0   cpsadd3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsadd3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i, cofr_idx;
  USI cofr;
  HI q[4], p[4], o[4];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      SI tmp = (SI)q[i] + (SI)p[i];
      if (tmp > 0x7fff)
	{
	  o[i] = 0x7fff;
	  cofr |= (3 << i*2);
	}
      else if (tmp < -0x8000)
	{
	  o[i] = -0x8000;
	  cofr |= (3 << i*2);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack(o);
}

// 1111 011 ooooo 0111 01000 qqqqq ppppp 0   cpsadd3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpsadd3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i, cofr_idx;
  USI cofr;
  SI q[2], p[2], o[2];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      DI tmp = (DI)q[i] + (DI)p[i];
      if (tmp > 0x7fffffffLL)
	{
	  o[i] = 0x7fffffffLL;
	  cofr |= (15 << i*4);
	}
      else if (tmp < -0x80000000LL)
	{
	  o[i] = -0x80000000LL;
	  cofr |= (15 << i*4);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack(o);
}

// 1111 110 ooooo 0111 01000 qqqqq ppppp 0   cpssub3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssub3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i, cofr_idx;
  USI cofr;
  HI q[4], p[4], o[4];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      SI tmp = (SI)q[i] - (SI)p[i];
      if (tmp > 0x7fff)
	{
	  o[i] = 0x7fff;
	  cofr |= (3 << i*2);
	}
      else if (tmp < -0x8000)
	{
	  o[i] = -0x8000;
	  cofr |= (3 << i*2);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack(o);
}

// 1111 111 ooooo 0111 01000 qqqqq ppppp 0   cpssub3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpssub3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i, cofr_idx;
  USI cofr;
  SI q[2], p[2], o[2];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      DI tmp = (DI)q[i] - (DI)p[i];
      if (tmp > 0x7fffffffLL)
	{
	  o[i] = 0x7fffffffLL;
	  cofr |= (15 << i*4);
	}
      else if (tmp < -0x80000000LL)
	{
	  o[i] = -0x80000000LL;
	  cofr |= (15 << i*4);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack(o);
}

// 1111 000 ooooo 0111 01001 qqqqq ppppp 0   cpextuaddu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextuaddu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  UHI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (UHI) q[i+4] + (UHI) p[i+4];

  return pack (o);
}

// 1111 001 ooooo 0111 01001 qqqqq ppppp 0   cpextuadd3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextuadd3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  HI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (HI) q[i+4] + (HI) p[i+4];

  return pack (o);
}

// 1111 010 ooooo 0111 01001 qqqqq ppppp 0   cpextladdu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextladdu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  UHI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (UHI) q[i] + (UHI) p[i];

  return pack (o);
}

// 1111 011 ooooo 0111 01001 qqqqq ppppp 0   cpextladd3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextladd3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  HI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (HI) q[i] + (HI) p[i];

  return pack (o);
}

// 1111 100 ooooo 0111 01001 qqqqq ppppp 0   cpextusubu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextusubu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  HI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (HI) q[i+4] - (HI) p[i+4];

  return pack (o);
}

// 1111 101 ooooo 0111 01001 qqqqq ppppp 0   cpextusub3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextusub3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  HI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (HI) q[i+4] - (HI) p[i+4];

  return pack (o);
}

// 1111 110 ooooo 0111 01001 qqqqq ppppp 0   cpextlsubu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextlsubu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  HI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (HI) q[i] - (HI) p[i];

  return pack (o);
}

// 1111 111 ooooo 0111 01001 qqqqq ppppp 0   cpextlsub3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextlsub3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  HI o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = (HI) q[i] - (HI) p[i];

  return pack (o);
}

// 1111 000 ooooo 0111 01010 qqqqq ppppp 0   cpaveu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpaveu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = ((UHI)q[i] + (UHI)p[i] + 1) >> 1;

  return pack(o);
}

// 1111 001 ooooo 0111 01010 qqqqq ppppp 0   cpave3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpave3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = ((HI)q[i] + (HI)p[i] + 1) >> 1;

  return pack(o);
}

// 1111 010 ooooo 0111 01010 qqqqq ppppp 0   cpave3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpave3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = ((SI)q[i] + (SI)p[i] + 1) >> 1;

  return pack(o);
}

// 1111 011 ooooo 0111 01010 qqqqq ppppp 0   cpave3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpave3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = ((DI)q[i] + (DI)p[i] + 1) >> 1;

  return pack(o);
}

// 1111 100 ooooo 0111 01010 qqqqq ppppp 0   cpaddsru3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpaddsru3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = ((UHI)q[i] + (UHI)p[i]) >> 1;

  return pack(o);
}

// 1111 101 ooooo 0111 01010 qqqqq ppppp 0   cpaddsr3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpaddsr3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = ((HI)q[i] + (HI)p[i]) >> 1;

  return pack(o);
}

// 1111 110 ooooo 0111 01010 qqqqq ppppp 0   cpaddsr3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpaddsr3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = ((SI)q[i] + (SI)p[i]) >> 1;

  return pack(o);
}

// 1111 111 ooooo 0111 01010 qqqqq ppppp 0   cpaddsr3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpaddsr3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = ((DI)q[i] + (DI)p[i]) >> 1;

  return pack(o);
}

// 1111 000 ooooo 0111 01011 qqqqq ppppp 0   cpabsu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpabsu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = abs ((UHI)q[i] - (UHI)p[i]);

  return pack(o);
}

// 1111 001 ooooo 0111 01011 qqqqq ppppp 0   cpabs3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpabs3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = abs ((HI)q[i] - (HI)p[i]);

  return pack(o);
}

// 1111 010 ooooo 0111 01011 qqqqq ppppp 0   cpabs3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpabs3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = abs ((SI)q[i] - (SI)p[i]);

  return pack(o);
}

// 1111 000 ooooo 0111 01100 qqqqq ppppp 0   cpmaxu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmaxu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] > p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 001 ooooo 0111 01100 qqqqq ppppp 0   cpmax3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmax3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] > p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 011 ooooo 0111 01100 qqqqq ppppp 0   cpmax3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmax3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] > p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 100 ooooo 0111 01100 qqqqq ppppp 0   cpmaxu3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmaxu3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] > p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 101 ooooo 0111 01100 qqqqq ppppp 0   cpmax3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmax3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] > p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 000 ooooo 0111 01101 qqqqq ppppp 0   cpminu3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpminu3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] < p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 001 ooooo 0111 01101 qqqqq ppppp 0   cpmin3.b =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmin3_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8], o[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = q[i] < p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 011 ooooo 0111 01101 qqqqq ppppp 0   cpmin3.h =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmin3_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4], o[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = q[i] < p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 100 ooooo 0111 01101 qqqqq ppppp 0   cpminu3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpminu3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] < p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 101 ooooo 0111 01101 qqqqq ppppp 0   cpmin3.w =croc,crqc,crpc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmin3_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2], o[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = q[i] < p[i] ? q[i] : p[i];

  return pack(o);
}

// 1111 000 ooooo 0111 10000 00000 00000 0   cpmovfrcsar0 =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovfrcsar0 (PCADDR &pc)
{
  return (USI) ccr (IVC2_CSAR0);
}

// 1111 000 ooooo 0111 10000 00000 01111 0   cpmovfrcsar1 =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovfrcsar1 (PCADDR &pc)
{
  return (USI) ccr (IVC2_CSAR1);
}

// 1111 000 ooooo 0111 10000 00000 00001 0   cpmovfrcc =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovfrcc (PCADDR &pc)
{
  return (USI) ccr (IVC2_CC);
}

// 1111 0000 0000 0111 10000 qqqqq 10000 0   cpmovtocsar0 crqc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmovtocsar0 (PCADDR &pc, DI crqc)
{
  ccw (IVC2_CSAR0, crqc & 7);
}

// 1111 0000 0000 0111 10000 qqqqq 11111 0   cpmovtocsar1 crqc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmovtocsar1 (PCADDR &pc, DI crqc)
{
  ccw (IVC2_CSAR1, crqc & 7);
}

// 1111 0000 0000 0111 10000 qqqqq 10001 0   cpmovtocc crqc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmovtocc (PCADDR &pc, DI crqc)
{
  ccw (IVC2_CC, crqc & 0xff);
}

// 1111 000 ooooo 0111 10001 qqqqq 00000 0   cpmov =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmov (PCADDR &pc, DI crqc)
{
  return crqc;
}

// 1111 000 ooooo 0111 10001 qqqqq 00001 0   cpabsz.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpabsz_b (PCADDR &pc, DI crqc)
{
  int i;
  QI o[8], q[8];

  unpack (crqc, q);

  for (i=0; i<8; i++)
    o[i] = abs (q[i]);

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 00010 0   cpabsz.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpabsz_h (PCADDR &pc, DI crqc)
{
  int i;
  HI o[4], q[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = abs (q[i]);

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 00011 0   cpabsz.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpabsz_w (PCADDR &pc, DI crqc)
{
  int i;
  SI o[2], q[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = abs (q[i]);

  return pack (o);
}

template <typename TY>
static int leading_zeros (TY v)
{
  int b;

  for (b = sizeof (v) * 8 - 1; b >= 0; b --)
    if (v & (1 << b))
      return sizeof (v) * 8 - 1 - b;

  return sizeof(v) * 8;
}

template <typename TY>
static int leading_ones (TY v)
{
  int b;

  for (b = sizeof(v) * 8 - 1; b >= 0; b --)
    if ((~v) & (1 << b))
      return sizeof (v) * 8 - 1 - b;

  return sizeof(v) * 8;
}

// 1111 000 ooooo 0111 10001 qqqqq 00100 0   cpldz.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpldz_h (PCADDR &pc, DI crqc)
{
  int i;
  HI q[4], o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = leading_zeros (q[i]);

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 00101 0   cpldz.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpldz_w (PCADDR &pc, DI crqc)
{
  int i;
  SI q[2], o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = leading_zeros (q[i]);

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 00110 0   cpnorm.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpnorm_h (PCADDR &pc, DI crqc)
{
  int i;
  HI q[4], o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    if (q[i] >= 0)
      o[i] = leading_zeros (q[i]) - 1;
    else
      o[i] = leading_ones (q[i]) - 1;

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 00111 0   cpnorm.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpnorm_w (PCADDR &pc, DI crqc)
{
  int i;
  SI q[2], o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    if (q[i] >= 0)
      o[i] = leading_zeros (q[i]) - 1;
    else
      o[i] = leading_ones (q[i]) - 1;

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01000 0   cphaddu.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cphaddu_b (PCADDR &pc, DI crqc)
{
  int i;
  UQI q[8];
  UHI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i*2+1] + q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01001 0   cphadd.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cphadd_b (PCADDR &pc, DI crqc)
{
  int i;
  QI q[8];
  HI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i*2+1] + q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01010 0   cphadd.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cphadd_h (PCADDR &pc, DI crqc)
{
  int i;
  HI q[4];
  HI o[4];

  unpack (crqc, q);

  o[3] = o[2] = 0;
  for (i=0; i<2; i++)
    o[i] = q[i*2+1] + q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01011 0   cphadd.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cphadd_w (PCADDR &pc, DI crqc)
{
  int i;
  SI q[2];
  SI o[2];

  unpack (crqc, q);

  o[1] = 0;
  o[0] = q[1] + q[0];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01100 0   cpccadd.b +crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpccadd_b (PCADDR &pc, DI crqc)
{
  int i;
  int cc = ccr (IVC2_CC);

  for (i=0; i<8; i++)
    if ((cc >> (i*2)) & 3)
      crqc ++;

  return crqc;
}

// 1111 000 ooooo 0111 10001 qqqqq 01101 0   cpbcast.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpbcast_b (PCADDR &pc, DI crqc)
{
  int i;
  QI o[8], q[8];

  unpack (crqc, q);

  for (i=0; i<8; i++)
    o[i] = q[0];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01110 0   cpbcast.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpbcast_h (PCADDR &pc, DI crqc)
{
  int i;
  HI o[4], q[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[0];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 01111 0   cpbcast.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpbcast_w (PCADDR &pc, DI crqc)
{
  int i;
  SI o[2], q[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[0];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10000 0   cpextuu.b =croc,crqc  (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextuu_b (PCADDR &pc, DI crqc)
{
  int i;
  UQI q[8];
  UHI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i+4];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10001 0   cpextu.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextu_b (PCADDR &pc, DI crqc)
{
  int i;
  QI q[8];
  HI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i+4];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10010 0   cpextuu.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextuu_h (PCADDR &pc, DI crqc)
{
  int i;
  UHI q[4];
  USI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i+2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10011 0   cpextu.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextu_h (PCADDR &pc, DI crqc)
{
  int i;
  HI q[4];
  SI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i+2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10100 0   cpextlu.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextlu_b (PCADDR &pc, DI crqc)
{
  int i;
  UQI q[8];
  UHI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10101 0   cpextl.b =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextl_b (PCADDR &pc, DI crqc)
{
  int i;
  QI q[8];
  HI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10110 0   cpextlu.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextlu_h (PCADDR &pc, DI crqc)
{
  int i;
  UHI q[4];
  USI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 10111 0   cpextl.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpextl_h (PCADDR &pc, DI crqc)
{
  int i;
  HI q[4];
  SI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11000 0   cpcastub.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpcastub_h (PCADDR &pc, DI crqc)
{
  int i;
  UQI q[8];
  UHI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11001 0   cpcastb.h =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpcastb_h (PCADDR &pc, DI crqc)
{
  int i;
  QI q[8];
  HI o[4];

  unpack (crqc, q);

  for (i=0; i<4; i++)
    o[i] = q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11100 0   cpcastub.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpcastub_w (PCADDR &pc, DI crqc)
{
  int i;
  UQI q[8];
  USI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i*4];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11101 0   cpcastb.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpcastb_w (PCADDR &pc, DI crqc)
{
  int i;
  QI q[8];
  SI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i*4];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11110 0   cpcastuh.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpcastuh_w (PCADDR &pc, DI crqc)
{
  int i;
  UHI q[4];
  USI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11111 0   cpcasth.w =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpcasth_w (PCADDR &pc, DI crqc)
{
  int i;
  HI q[4];
  SI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    o[i] = q[i*2];

  return pack (o);
}

// 1111 000 ooooo 0111 10001 qqqqq 11010 0   cdcastuw =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdcastuw (PCADDR &pc, DI crqc)
{
  int i;
  USI q[2];

  unpack (crqc, q);

  return q[0];
}

// 1111 000 ooooo 0111 10001 qqqqq 11011 0   cdcastw =croc,crqc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cdcastw (PCADDR &pc, DI crqc)
{
  int i;
  SI q[2];

  unpack (crqc, q);

  return q[0];
}

// 1111 0000 0000 0111 10010 qqqqq ppppp 0   cpcmpeqz.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpeqz_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  SI cond;

  unpack (crqc, q);
  unpack (crpc, p);

  cond = 0xff;

  for (i=0; i<8; i++)
    if (q[i] == 0 || p[i] == 0)
      cond &= ~(1 << i);

  ccw (IVC2_CC, cond);
}

#define CMP(TY,OP)							\
  int i;								\
  TY q[8/sizeof(TY)], p[8/sizeof(TY)];					\
  SI cond;								\
  unpack (crqc, q);							\
  unpack (crpc, p);							\
  cond = 0x00;								\
  for (i=0; i<(8/sizeof(TY)); i++)					\
    if (q[i] OP p[i])							\
      cond |= ((1<<(8/(8/sizeof(TY))))-1) << (i*8/(8/sizeof(TY)));	\
  ccw (IVC2_CC, cond)

#define CMPO(TY,OP) \
  int i;								\
  TY q[8/sizeof(TY)], p[8/sizeof(TY)];					\
  SI cond = ccr (IVC2_CC);						\
  unpack (crqc, q);							\
  unpack (crpc, p);							\
  for (i=0; i<(8/sizeof(TY)); i++)					\
    if (q[i] OP p[i])							\
      cond |= ((1<<(8/(8/sizeof(TY))))-1) << (i*8/(8/sizeof(TY)));	\
  ccw (IVC2_CC, cond)

#define CMPA(TY,OP) \
  int i;								\
  TY q[8/sizeof(TY)], p[8/sizeof(TY)];					\
  SI cond = ccr (IVC2_CC);						\
  unpack (crqc, q);							\
  unpack (crpc, p);							\
  for (i=0; i<(8/sizeof(TY)); i++)					\
    if (!(q[i] OP p[i]))						\
      cond &= ~(((1<<(8/(8/sizeof(TY))))-1) << (i*8/(8/sizeof(TY))));	\
  ccw (IVC2_CC, cond)

// 1111 0000 0001 0111 10010 qqqqq ppppp 0   cpcmpeq.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpeq_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (QI, ==);
}

// 1111 0000 0011 0111 10010 qqqqq ppppp 0   cpcmpeq.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpeq_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (HI, ==);
}

// 1111 0000 0101 0111 10010 qqqqq ppppp 0   cpcmpeq.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpeq_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (SI, ==);
}

// 1111 0000 1001 0111 10010 qqqqq ppppp 0   cpcmpne.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpne_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (QI, !=);
}

// 1111 0000 1011 0111 10010 qqqqq ppppp 0   cpcmpne.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpne_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (HI, !=);
}

// 1111 0000 1101 0111 10010 qqqqq ppppp 0   cpcmpne.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpne_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (SI, !=);
}

// 1111 0001 0000 0111 10010 qqqqq ppppp 0   cpcmpgtu.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgtu_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (UQI, >);
}

// 1111 0001 0001 0111 10010 qqqqq ppppp 0   cpcmpgt.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgt_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (QI, >);
}

// 1111 0001 0011 0111 10010 qqqqq ppppp 0   cpcmpgt.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgt_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (HI, >);
}

// 1111 0001 0100 0111 10010 qqqqq ppppp 0   cpcmpgtu.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgtu_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (USI, >);
}

// 1111 0001 0101 0111 10010 qqqqq ppppp 0   cpcmpgt.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgt_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (SI, >);
}

// 1111 0001 1000 0111 10010 qqqqq ppppp 0   cpcmpgeu.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgeu_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (UQI, >=);
}

// 1111 0001 1001 0111 10010 qqqqq ppppp 0   cpcmpge.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpge_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (QI, >=);
}

// 1111 0001 1011 0111 10010 qqqqq ppppp 0   cpcmpge.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpge_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (HI, >=);
}

// 1111 0001 1100 0111 10010 qqqqq ppppp 0   cpcmpgeu.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpgeu_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (USI, >=);
}

// 1111 0001 1101 0111 10010 qqqqq ppppp 0   cpcmpge.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpcmpge_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMP (SI, >=);
}

// 1111 0010 0001 0111 10010 qqqqq ppppp 0   cpacmpeq.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpeq_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (QI, ==);
}

// 1111 0010 0011 0111 10010 qqqqq ppppp 0   cpacmpeq.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpeq_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (HI, ==);
}

// 1111 0010 0101 0111 10010 qqqqq ppppp 0   cpacmpeq.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpeq_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (SI, ==);
}

// 1111 0010 1001 0111 10010 qqqqq ppppp 0   cpacmpne.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpne_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (QI, !=);
}

// 1111 0010 1011 0111 10010 qqqqq ppppp 0   cpacmpne.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpne_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (HI, !=);
}

// 1111 0010 1101 0111 10010 qqqqq ppppp 0   cpacmpne.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpne_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (SI, !=);
}

// 1111 0011 0000 0111 10010 qqqqq ppppp 0   cpacmpgtu.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgtu_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (UQI, >);
}

// 1111 0011 0001 0111 10010 qqqqq ppppp 0   cpacmpgt.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgt_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (QI, >);
}

// 1111 0011 0011 0111 10010 qqqqq ppppp 0   cpacmpgt.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgt_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (HI, >);
}

// 1111 0011 0100 0111 10010 qqqqq ppppp 0   cpacmpgtu.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgtu_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (USI, >);
}

// 1111 0011 0101 0111 10010 qqqqq ppppp 0   cpacmpgt.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgt_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (SI, >);
}

// 1111 0011 1000 0111 10010 qqqqq ppppp 0   cpacmpgeu.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgeu_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (UQI, >=);
}

// 1111 0011 1001 0111 10010 qqqqq ppppp 0   cpacmpge.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpge_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (QI, >=);
}

// 1111 0011 1011 0111 10010 qqqqq ppppp 0   cpacmpge.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpge_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (HI, >=);
}

// 1111 0011 1100 0111 10010 qqqqq ppppp 0   cpacmpgeu.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpgeu_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (USI, >=);
}

// 1111 0011 1101 0111 10010 qqqqq ppppp 0   cpacmpge.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpacmpge_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPA (SI, >=);
}

// 1111 0100 0001 0111 10010 qqqqq ppppp 0   cpocmpeq.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpeq_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (QI, ==);
}

// 1111 0100 0011 0111 10010 qqqqq ppppp 0   cpocmpeq.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpeq_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (HI, ==);
}

// 1111 0100 0101 0111 10010 qqqqq ppppp 0   cpocmpeq.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpeq_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (SI, ==);
}

// 1111 0100 1001 0111 10010 qqqqq ppppp 0   cpocmpne.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpne_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (QI, !=);
}

// 1111 0100 1011 0111 10010 qqqqq ppppp 0   cpocmpne.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpne_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (HI, !=);
}

// 1111 0100 1101 0111 10010 qqqqq ppppp 0   cpocmpne.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpne_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (SI, !=);
}

// 1111 0101 0000 0111 10010 qqqqq ppppp 0   cpocmpgtu.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgtu_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (UQI, >);
}

// 1111 0101 0001 0111 10010 qqqqq ppppp 0   cpocmpgt.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgt_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (QI, >);
}

// 1111 0101 0011 0111 10010 qqqqq ppppp 0   cpocmpgt.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgt_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (HI, >);
}

// 1111 0101 0100 0111 10010 qqqqq ppppp 0   cpocmpgtu.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgtu_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (USI, >);
}

// 1111 0101 0101 0111 10010 qqqqq ppppp 0   cpocmpgt.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgt_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (SI, >);
}

// 1111 0101 1000 0111 10010 qqqqq ppppp 0   cpocmpgeu.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgeu_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (UQI, >=);
}

// 1111 0101 1001 0111 10010 qqqqq ppppp 0   cpocmpge.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpge_b (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (QI, >=);
}

// 1111 0101 1011 0111 10010 qqqqq ppppp 0   cpocmpge.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpge_h (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (HI, >=);
}

// 1111 0101 1100 0111 10010 qqqqq ppppp 0   cpocmpgeu.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpgeu_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (USI, >=);
}

// 1111 0101 1101 0111 10010 qqqqq ppppp 0   cpocmpge.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpocmpge_w (PCADDR &pc, DI crqc, DI crpc)
{
  CMPO (SI, >=);
}

// 1111 00xx xiii 0111 10100 qqqqq ppppp 0   cpsrli3.b =crqc,crpc,imm3 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpsrli3_b (PCADDR &pc, DI crpc, SI imm3)
{
  int i;
  UQI p[8], o[8];

  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = p[i] >> imm3;

  return pack (o);
}

// 1111 01xx iiii 0111 10100 qqqqq ppppp 0   cpsrli3.h =crqc,crpc,imm4 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpsrli3_h (PCADDR &pc, DI crpc, SI imm4)
{
  int i;
  UHI p[4], o[4];

  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = p[i] >> imm4;

  return pack (o);
}

// 1111 10xi iiii 0111 10100 qqqqq ppppp 0   cpsrli3.w =crqc,crpc,imm5 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpsrli3_w (PCADDR &pc, DI crpc, SI imm5)
{
  int i;
  USI p[2], o[2];

  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = p[i] >> imm5;

  return pack (o);
}

// 1111 11ii iiii 0111 10100 qqqqq ppppp 0   cdsrli3 =crqc,crpc,imm6 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdsrli3 (PCADDR &pc, DI crpc, SI imm6)
{
  return (UDI)crpc >> imm6;
}

// 1111 00xx xiii 0111 10101 qqqqq ppppp 0   cpsrai3.b =crqc,crpc,imm3 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpsrai3_b (PCADDR &pc, DI crpc, SI imm3)
{
  int i;
  QI p[8], o[8];

  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = p[i] >> imm3;

  return pack (o);
}

// 1111 01xx iiii 0111 10101 qqqqq ppppp 0   cpsrai3.h =crqc,crpc,imm4 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpsrai3_h (PCADDR &pc, DI crpc, SI imm4)
{
  int i;
  HI p[4], o[4];

  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = p[i] >> imm4;

  return pack (o);
}

// 1111 10xi iiii 0111 10101 qqqqq ppppp 0   cpsrai3.w =crqc,crpc,imm5 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpsrai3_w (PCADDR &pc, DI crpc, SI imm5)
{
  int i;
  SI p[2], o[2];

  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = p[i] >> imm5;

  return pack (o);
}

// 1111 11ii iiii 0111 10101 qqqqq ppppp 0   cdsrai3 =crqc,crpc,imm6 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdsrai3 (PCADDR &pc, DI crpc, SI imm6)
{
  return (DI)crpc >> imm6;
}

// 1111 00xx xiii 0111 10110 qqqqq ppppp 0   cpslli3.b =crqc,crpc,imm3 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpslli3_b (PCADDR &pc, DI crpc, SI imm3)
{
  int i;
  QI p[8], o[8];

  unpack (crpc, p);

  for (i=0; i<8; i++)
    o[i] = p[i] << imm3;

  return pack (o);
}

// 1111 01xx iiii 0111 10110 qqqqq ppppp 0   cpslli3.h =crqc,crpc,imm4 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpslli3_h (PCADDR &pc, DI crpc, SI imm4)
{
  int i;
  HI p[4], o[4];

  unpack (crpc, p);

  for (i=0; i<4; i++)
    o[i] = p[i] << imm4;

  return pack (o);
}

// 1111 10xi iiii 0111 10110 qqqqq ppppp 0   cpslli3.w =crqc,crpc,imm5 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpslli3_w (PCADDR &pc, DI crpc, SI imm5)
{
  int i;
  SI p[2], o[2];

  unpack (crpc, p);

  for (i=0; i<2; i++)
    o[i] = p[i] << imm5;

  return pack (o);
}

// 1111 11ii iiii 0111 10110 qqqqq ppppp 0   cdslli3 =crqc,crpc,imm6 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdslli3 (PCADDR &pc, DI crpc, SI imm6)
{
  return crpc << imm6;
}

// 1111 01xx iiii 0111 10111 qqqqq ppppp 0   cpslai3.h =crqc,crpc,imm4 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpslai3_h (PCADDR &pc, DI crqc, SI imm4)
{
  int i, cofr_idx;
  USI cofr;
  HI q[4], o[4];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);

  for (i=0; i<4; i++)
    {
      SI tmp = q[i];
      tmp <<= imm4;
      if (tmp > 0x7fff)
	{
	  o[i] = 0x7fff;
	  cofr |= (3 << i*2);
	}
      else if (tmp < -0x8000)
	{
	  o[i] = -0x8000;
	  cofr |= (3 << i*2);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack (o);
}

// 1111 10xi iiii 0111 10111 qqqqq ppppp 0   cpslai3.w =crqc,crpc,imm5 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpslai3_w (PCADDR &pc, DI crqc, SI imm5)
{
  int i, cofr_idx;
  USI cofr;
  SI q[2], o[2];

  if (ivc2_slot == IVC2_P0 || ivc2_slot == IVC2_P0S)
    cofr_idx = IVC2_COFR0;
  else /* C3 or P1 */
    cofr_idx = IVC2_COFR1;
  cofr = ccr (cofr_idx);

  unpack (crqc, q);

  for (i=0; i<2; i++)
    {
      DI tmp = q[i];
      tmp <<= imm5;
      if (tmp > 0x7fffffffLL)
	{
	  o[i] = 0x7fffffffLL;
	  cofr |= (15 << i*4);
	}
      else if (tmp < -0x80000000LL)
	{
	  o[i] = -0x80000000LL;
	  cofr |= (15 << i*4);
	}
      else
	o[i] = tmp;
    }
  ccw (cofr_idx, cofr);

  return pack (o);
}

// 1111 00xi iiii 0111 11000 qqqqq ppppp 0   cpclipiu3.w =crqc,crpc,imm5 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpclipiu3_w (PCADDR &pc, DI crqc, SI imm5)
{
  int i;
  SI q[2];
  SI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    {
      if (imm5 == 0)
	o[i] = 0;
      else if (q[i] > (1<<imm5)-1)
	o[i] = (1<<imm5)-1;
      else if (q[i] < 0)
	o[i] = 0;
      else
	o[i] = q[i];
    }

  return pack (o);
}

// 1111 01xi iiii 0111 11000 qqqqq ppppp 0   cpclipi3.w =crqc,crpc,imm5 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpclipi3_w (PCADDR &pc, DI crqc, SI imm5)
{
  int i;
  SI q[2];
  SI o[2];

  unpack (crqc, q);

  for (i=0; i<2; i++)
    {
      if (imm5 == 0)
	o[i] = 0;
      else if (q[i] > (1<<(imm5-1))-1)
	o[i] = (1<<(imm5-1))-1;
      else if (q[i] < -(1<<(imm5-1)))
	o[i] = -(1<<(imm5-1));
      else
	o[i] = q[i];
    }

  return pack (o);
}

// 1111 10ii iiii 0111 11000 qqqqq ppppp 0   cdclipiu3 =crqc,crpc,imm6 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdclipiu3 (PCADDR &pc, DI crqc, SI imm6)
{
  DI o;

  if (imm6 == 0)
    o = 0;
  else if (crqc > (1LL<<imm6)-1)
    o = (1LL<<imm6)-1;
  else if (crqc < 0)
    o = 0;
  else
    o = crqc;

  return o;
}

// 1111 11ii iiii 0111 11000 qqqqq ppppp 0   cdclipi3 =crqc,crpc,imm6 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdclipi3 (PCADDR &pc, DI crqc, SI imm6)
{
  DI o;

  if (imm6 == 0)
    o = 0;
  else if (crqc > (1LL<<(imm6-1))-1)
    o = (1LL<<(imm6-1))-1;
  else if (crqc < -((1LL<<(imm6-1))))
    o = -((1LL<<(imm6-1)));
  else
    o = crqc;

  return o;
}

// 1111 iiii iiii 0111 11001 qqqqq 00000 0   cpmovi.b =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpmovi_b (PCADDR &pc, SI imm8)
{
  int i;
  QI o[8];
  for (i=0; i<8; i++)
    o[i] = imm8;

  return pack (o);
}

// 1111 iiii iiii 0111 11001 qqqqq 00010 0   cpmoviu.h =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpmoviu_h (PCADDR &pc, SI imm8)
{
  int i;
  HI o[4];
  for (i=0; i<4; i++)
    o[i] = (UQI)imm8;

  return pack (o);
}

// 1111 iiii iiii 0111 11001 qqqqq 00011 0   cpmovi.h =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpmovi_h (PCADDR &pc, SI imm8)
{
  int i;
  HI o[4];
  for (i=0; i<4; i++)
    o[i] = (QI)imm8;

  return pack (o);
}

// 1111 iiii iiii 0111 11001 qqqqq 00100 0   cpmoviu.w =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpmoviu_w (PCADDR &pc, SI imm8)
{
  int i;
  SI o[2];
  for (i=0; i<2; i++)
    o[i] = imm8;

  return pack (o);
}

// 1111 iiii iiii 0111 11001 qqqqq 00101 0   cpmovi.w =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cpmovi_w (PCADDR &pc, SI imm8)
{
  int i;
  SI o[2];
  for (i=0; i<2; i++)
    o[i] = (QI)imm8;

  return pack (o);
}

// 1111 iiii iiii 0111 11001 qqqqq 00110 0   cdmoviu =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdmoviu (PCADDR &pc, SI imm8)
{
  return (UQI)imm8;
}

// 1111 iiii iiii 0111 11001 qqqqq 00111 0   cdmovi =crqc,imm8 (c3_imm)
DI mep::mep_cpu_cgen::ivc2_cdmovi (PCADDR &pc, SI imm8)
{
  return (QI)imm8;
}

// 1111 0000 0000 0111 00000 qqqqq ppppp 1   cpadda1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpadda1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, (SI)q[i] + (SI)p[i]);
}

// 1111 0000 0001 0111 00000 qqqqq ppppp 1   cpadda1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpadda1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, (SI)q[i] + (SI)p[i]);
}

// 1111 0000 0010 0111 00000 qqqqq ppppp 1   cpaddua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpaddua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i+4, (SI)q[i] + (SI)p[i]);
}

// 1111 0000 0011 0111 00000 qqqqq ppppp 1   cpaddla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpaddla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i, (SI)q[i] + (SI)p[i]);
}

// 1111 0000 0100 0111 00000 qqqqq ppppp 1   cpaddaca1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpaddaca1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = A1r (i);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 0101 0111 00000 qqqqq ppppp 1   cpaddaca1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpaddaca1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 0110 0111 00000 qqqqq ppppp 1   cpaddacua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpaddacua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 0111 0111 00000 qqqqq ppppp 1   cpaddacla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpaddacla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 1000 0111 00000 qqqqq ppppp 1   cpsuba1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsuba1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, (SI)q[i] - (SI)p[i]);
}

// 1111 0000 1001 0111 00000 qqqqq ppppp 1   cpsuba1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsuba1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, (SI)q[i] - (SI)p[i]);
}

// 1111 0000 1010 0111 00000 qqqqq ppppp 1   cpsubua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsubua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i+4, (SI)q[i] - (SI)p[i]);
}

// 1111 0000 1011 0111 00000 qqqqq ppppp 1   cpsubla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsubla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i, (SI)q[i] - (SI)p[i]);
}

// 1111 0000 1100 0111 00000 qqqqq ppppp 1   cpsubaca1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsubaca1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = A1r (i);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 1101 0111 00000 qqqqq ppppp 1   cpsubaca1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsubaca1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 1110 0111 00000 qqqqq ppppp 1   cpsubacua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsubacua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 1111 0111 00000 qqqqq ppppp 1   cpsubacla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsubacla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0000 0111 00000 qqqqq ppppp 1   cpabsa1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpabsa1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, abs ((SI)q[i] - (SI)p[i]));
}

// 1111 0001 0001 0111 00000 qqqqq ppppp 1   cpabsa1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpabsa1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, abs ((SI)q[i] - (SI)p[i]));
}

// 1111 0001 0010 0111 00000 qqqqq ppppp 1   cpabsua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpabsua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i+4, abs ((SI)q[i] - (SI)p[i]));
}

// 1111 0001 0011 0111 00000 qqqqq ppppp 1   cpabsla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpabsla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i, abs ((SI)q[i] - (SI)p[i]));
}

// 1111 0001 0100 0111 00000 qqqqq ppppp 1   cpsada1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsada1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = A1r (i);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0101 0111 00000 qqqqq ppppp 1   cpsada1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsada1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0110 0111 00000 qqqqq ppppp 1   cpsadua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsadua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0111 0111 00000 qqqqq ppppp 1   cpsadla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsadla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0010 0000 0111 00000 qqqqq ppppp 1   cpseta1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpseta1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      A1w (i+4, q[i]);
      A1w (i, p[i]);
    }
}

// 1111 0010 0010 0111 00000 qqqqq ppppp 1   cpsetua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsetua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      A1w (i+2, q[i]);
      A1w (i, p[i]);
    }
}

// 1111 0010 0011 0111 00000 qqqqq ppppp 1   cpsetla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsetla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      A1w (i+6, q[i]);
      A1w (i+4, p[i]);
    }
}

// 1111 000 ooooo 0111 00100 00000 00000 1   cpmova1.b =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmova1_b (PCADDR &pc)
{
  int i;
  QI o[8];

  for (i=0; i<8; i++)
    o[i] = A1r (i);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 00010 1   cpmovua1.h =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovua1_h (PCADDR &pc)
{
  int i;
  HI o[4];

  for (i=0; i<4; i++)
    o[i] = A1r (i+4);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 00011 1   cpmovla1.h =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovla1_h (PCADDR &pc)
{
  int i;
  HI o[4];

  for (i=0; i<4; i++)
    o[i] = A1r (i);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 00100 1   cpmovuua1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovuua1_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A1r (i+6);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 00101 1   cpmovula1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovula1_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A1r (i+4);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 00110 1   cpmovlua1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovlua1_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A1r (i+2);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 00111 1   cpmovlla1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovlla1_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A1r (i);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10000 1   cppacka1u.b =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppacka1u_b (PCADDR &pc)
{
  int i;
  QI o[8];
  DI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      o[i] = (acc > 255) ? 255 : (acc < 0) ? 0 : acc;
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10001 1   cppacka1.b =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppacka1_b (PCADDR &pc)
{
  int i;
  QI o[8];
  DI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      o[i] = (acc > 127) ? 127 : (acc < -128) ? -128 : acc;
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10010 1   cppackua1.h =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppackua1_h (PCADDR &pc)
{
  int i;
  HI o[4];
  DI acc;

  for (i=0; i<4; i++)
    {
      acc = A1r (i+4);
      o[i] = (acc > 32767) ? 32767 : (acc < -32768) ? -32768 : acc;
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10011 1   cppackla1.h =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppackla1_h (PCADDR &pc)
{
  int i;
  HI o[4];
  DI acc;

  for (i=0; i<4; i++)
    {
      acc = A1r (i);
      o[i] = (acc > 32767) ? 32767 : (acc < -32768) ? -32768 : acc;
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10100 1   cppackua1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppackua1_w (PCADDR &pc)
{
  int i;
  SI o[2];
  DI acc;

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      o[i] = (acc > 2147483647LL) ? 2147483647LL : (acc < -2147483648LL) ? -2147483648LL : acc;
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10101 1   cppackla1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cppackla1_w (PCADDR &pc)
{
  int i;
  SI o[2];
  DI acc;

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2);
      o[i] = (acc > 2147483647LL) ? 2147483647LL : (acc < -2147483648LL) ? -2147483648LL : acc;
    }

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10110 1   cpmovhua1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovhua1_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A1r (i*2+5);

  return pack (o);
}

// 1111 000 ooooo 0111 00100 00000 10111 1   cpmovhla1.w =croc (c3_1)
DI mep::mep_cpu_cgen::ivc2_cpmovhla1_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A1r (i*2+1);

  return pack (o);
}

// 1111 0000 0000 0111 00010 qqqqq 00000 1   cpsrla1 crqc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsrla1 (PCADDR &pc, DI crqc)
{
  int i;
  USI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      A1w (i, acc >> crqc);
    }
}

// 1111 0000 0001 0111 00010 qqqqq 00000 1   cpsraa1 crqc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsraa1 (PCADDR &pc, DI crqc)
{
  int i;
  SI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      A1w (i, acc >> crqc);
    }
}

// 1111 0000 0010 0111 00010 qqqqq 00000 1   cpslla1 crqc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpslla1 (PCADDR &pc, DI crqc)
{
  int i;
  SI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      A1w (i, acc << crqc);
    }
}

// 1111 00xi iiii 0111 00011 00000 00000 1   cpsrlia1 imm5 (c3_imm)
void mep::mep_cpu_cgen::ivc2_cpsrlia1 (PCADDR &pc, SI imm5)
{
  int i;
  USI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      A1w (i, acc >> imm5);
    }
}

// 1111 01xi iiii 0111 00011 00000 00000 1   cpsraia1 imm5 (c3_imm)
void mep::mep_cpu_cgen::ivc2_cpsraia1 (PCADDR &pc, SI imm5)
{
  int i;
  SI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      A1w (i, acc >> imm5);
    }
}

// 1111 10xi iiii 0111 00011 00000 00000 1   cpsllia1 imm5 (c3_imm)
void mep::mep_cpu_cgen::ivc2_cpsllia1 (PCADDR &pc, SI imm5)
{
  int i;
  SI acc;

  for (i=0; i<8; i++)
    {
      acc = A1r (i);
      A1w (i, acc << imm5);
    }
}

// 1111 0000 0000 0111 00001 qqqqq ppppp 1   cpssqa1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpssqa1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    {
      SI d = q[i] - p[i];
      A1w (i, d*d);
    }
}

// 1111 0000 0001 0111 00001 qqqqq ppppp 1   cpssqa1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpssqa1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    {
      SI d = q[i] - p[i];
      A1w (i, d*d);
    }
}

// 1111 0000 0100 0111 00001 qqqqq ppppp 1   cpssda1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpssda1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = A1r (i);
      SI d = (SI)q[i] - (SI)p[i];
      acc += d * d;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 0101 0111 00001 qqqqq ppppp 1   cpssda1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpssda1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = A1r (i);
      SI d = (SI)q[i] - (SI)p[i];
      acc += d * d;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0000 1000 0111 00001 qqqqq ppppp 1   cpmula1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmula1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, (SI)q[i] * (SI)p[i]);
}

// 1111 0000 1001 0111 00001 qqqqq ppppp 1   cpmula1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmula1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<8; i++)
    A1w (i, (SI)q[i] * (SI)p[i]);
}

// 1111 0000 1010 0111 00001 qqqqq ppppp 1   cpmulua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i+4, (SI)q[i] * (SI)p[i]);
}

// 1111 0000 1011 0111 00001 qqqqq ppppp 1   cpmulla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    A1w (i, (SI)q[i] * (SI)p[i]);
}

// 1111 0000 1100 0111 00001 qqqqq ppppp 1   cpmulua1u.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulua1u_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  UDI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = (UDI)q[i] * (UDI)p[i];
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }
}

// 1111 0000 1101 0111 00001 qqqqq ppppp 1   cpmulla1u.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulla1u_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  UDI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = (UDI)q[i] * (UDI)p[i];
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }
}

// 1111 0000 1110 0111 00001 qqqqq ppppp 1   cpmulua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  DI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = (DI)q[i] * (DI)p[i];
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }
}

// 1111 0000 1111 0111 00001 qqqqq ppppp 1   cpmulla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  DI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = (DI)q[i] * (DI)p[i];
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }
}

// 1111 0001 0000 0111 00001 qqqqq ppppp 1   cpmada1u.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmada1u_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = A1r (i);
      acc += (SI)q[i] * (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0001 0111 00001 qqqqq ppppp 1   cpmada1.b crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmada1_b (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (SI)q[i] * (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0010 0111 00001 qqqqq ppppp 1   cpmadua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmadua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += (SI)q[i] * (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0011 0111 00001 qqqqq ppppp 1   cpmadla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmadla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (SI)q[i] * (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0100 0111 00001 qqqqq ppppp 1   cpmadua1u.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmadua1u_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  USI cc;
  UDI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      acc += (UDI)q[i] * (UDI)p[i];
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }
}

// 1111 0001 0101 0111 00001 qqqqq ppppp 1   cpmadla1u.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmadla1u_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  USI cc;
  UDI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2+0);
      acc += (UDI)q[i] * (UDI)p[i];
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }
}

// 1111 0001 0110 0111 00001 qqqqq ppppp 1   cpmadua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmadua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI oacc, acc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      oacc = acc;
      acc += (DI)q[i] * (DI)p[i];
      if (acc < oacc)
	cc |= (1 << i);
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 0111 0111 00001 qqqqq ppppp 1   cpmadla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmadla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI oacc, acc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2+0);
      oacc = acc;
      acc += (DI)q[i] * (DI)p[i];
      if (acc < oacc)
	cc |= (1 << i);
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 1010 0111 00001 qqqqq ppppp 1   cpmsbua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmsbua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc -= (SI)q[i] * (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 1011 0111 00001 qqqqq ppppp 1   cpmsbla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmsbla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc -= (SI)q[i] * (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 1100 0111 00001 qqqqq ppppp 1   cpmsbua1u.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmsbua1u_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  USI cc;
  UDI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      acc -= (UDI)q[i] * (UDI)p[i];
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }
}

// 1111 0001 1101 0111 00001 qqqqq ppppp 1   cpmsbla1u.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmsbla1u_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  USI cc;
  UDI acc;

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2+0);
      acc -= (UDI)q[i] * (UDI)p[i];
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }
}

// 1111 0001 1110 0111 00001 qqqqq ppppp 1   cpmsbua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmsbua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI oacc, acc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      oacc = acc;
      acc -= (DI)q[i] * (DI)p[i];
      if (acc < oacc)
	cc |= (1 << i);
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0001 1111 0111 00001 qqqqq ppppp 1   cpmsbla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmsbla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI oacc, acc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2+0);
      oacc = acc;
      acc -= (DI)q[i] * (DI)p[i];
      if (acc < oacc)
	cc |= (1 << i);
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 0010 0111 00001 qqqqq ppppp 1   cpsmadua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += abs ((SI)q[i] * (SI)p[i]);
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << (i+4));
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << (i+4));
	}
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 0011 0111 00001 qqqqq ppppp 1   cpsmadla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += (abs ((SI)q[i] * (SI)p[i])) << 1;
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << i);
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << i);
	}
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 0110 0111 00001 qqqqq ppppp 1   cpsmadua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      oacc = acc;
      term = (DI)q[i] * (DI)p[i];
      acc += term;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P + P
	case 1: // P = P + N
	case 6: // N = N + P
	case 7: // N = N + N
	  // no range crossing
	  break;
	case 2: // P = N + P
	case 5: // N = P + N
	  // cross through zero
	  break;
	case 3: // P = N + N
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2+4));
	  break;
	case 4: // N = P + P
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	  break;
	}
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 0111 0111 00001 qqqqq ppppp 1   cpsmadla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2+0);
      oacc = acc;
      term = (DI)q[i] * (DI)p[i];
      acc += term;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P + P
	case 1: // P = P + N
	case 6: // N = N + P
	case 7: // N = N + N
	  // no range crossing
	  break;
	case 2: // P = N + P
	case 5: // N = P + N
	  // cross through zero
	  break;
	case 3: // P = N + N
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2+0));
	  break;
	case 4: // N = P + P
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+0));
	  break;
	}
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 1010 0111 00001 qqqqq ppppp 1   cpsmsbua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc -= abs ((SI)q[i] * (SI)p[i]);
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << (i+4));
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << (i+4));
	}
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 1011 0111 00001 qqqqq ppppp 1   cpsmsbla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc -= abs ((SI)q[i] * (SI)p[i]);
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << i);
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << i);
	}
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 1110 0111 00001 qqqqq ppppp 1   cpsmsbua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      oacc = acc;
      term = (DI)q[i] * (DI)p[i];
      acc -= term;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P - P
	case 1: // P = P - N
	case 6: // N = N - P
	case 7: // N = N - N
	  // no range crossing
	  break;
	case 3: // P = N - N
	case 4: // N = P - P
	  // cross through zero
	  break;
	case 2: // P = N - P
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2+4));
	  break;
	case 5: // N = P - N
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	  break;
	}
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0011 1111 0111 00001 qqqqq ppppp 1   cpsmsbla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2);
      oacc = acc;
      term = (DI)q[i] * (DI)p[i];
      acc -= term;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P - P
	case 1: // P = P - N
	case 6: // N = N - P
	case 7: // N = N - N
	  // no range crossing
	  break;
	case 3: // P = N - N
	case 4: // N = P - P
	  // cross through zero
	  break;
	case 2: // P = N - P
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2));
	  break;
	case 5: // N = P - N
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2));
	  break;
	}
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0100 1010 0111 00001 qqqqq ppppp 1   cpmulslua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulslua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      if (q[i] == 0x8000 && p[i] == 0x8000)
	A1w (i+4, 0x7fffffff);
      else
	A1w (i+4, ((SI)q[i] * (SI)p[i]) << 1);
    }
}

// 1111 0100 1011 0111 00001 qqqqq ppppp 1   cpmulslla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulslla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];

  unpack (crqc, q);
  unpack (crpc, p);

  for (i=0; i<4; i++)
    {
      if (q[i] == 0x8000 && p[i] == 0x8000)
	A1w (i, 0x7fffffff);
      else
	A1w (i, ((SI)q[i] * (SI)p[i]) << 1);
    }
}

// 1111 0100 1110 0111 00001 qqqqq ppppp 1   cpmulslua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulslua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  UDI acc;
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      if (q[i] == 0x80000000ULL && p[i] == 0x80000000ULL)
	{
	  acc =  0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	}
      else
	acc = ((UDI)q[i] * (UDI)p[i]) << 1;
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0100 1111 0111 00001 qqqqq ppppp 1   cpmulslla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpmulslla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  USI q[2], p[2];
  UDI acc;
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      if (q[i] == 0x80000000ULL && p[i] == 0x80000000ULL)
	{
	  acc =  0x7fffffffffffffffLL;
	  cc |= (3 << (i*2));
	}
      else
	acc = ((UDI)q[i] * (UDI)p[i]) << 1;
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 0010 0111 00001 qqqqq ppppp 1   cpsmadslua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadslua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      DI tmp;

      if (q[i] == 0x8000 && p[i] == 0x8000)
	{
	  tmp = 0x7ffffff;
	  cc |= (1 << (i+4));
	}
      else
	tmp = ((SI)q[i] * (SI)p[i]) << 1;

      acc += tmp;
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << (i+4));
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << (i+4));
	}
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 0011 0111 00001 qqqqq ppppp 1   cpsmadslla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadslla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      DI tmp;

      if (q[i] == 0x8000 && p[i] == 0x8000)
	{
	  tmp = 0x7ffffff;
	  cc |= (1 << (i));
	}
      else
	tmp = ((SI)q[i] * (SI)p[i]) << 1;

      acc += tmp;
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << (i));
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << (i));
	}
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 0110 0111 00001 qqqqq ppppp 1   cpsmadslua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadslua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      oacc = acc;
      if (q[i] == 0x80000000 && p[i] == 0x80000000)
	{
	  term = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	}
      else
	term = (DI)q[i] * (DI)p[i];
      acc += term << 1;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P + P
	case 1: // P = P + N
	case 6: // N = N + P
	case 7: // N = N + N
	  // no range crossing
	  break;
	case 2: // P = N + P
	case 5: // N = P + N
	  // cross through zero
	  break;
	case 3: // P = N + N
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2+4));
	  break;
	case 4: // N = P + P
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	  break;
	}
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 0111 0111 00001 qqqqq ppppp 1   cpsmadslla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmadslla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2);
      oacc = acc;
      if (q[i] == 0x80000000 && p[i] == 0x80000000)
	{
	  term = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	}
      else
	term = (DI)q[i] * (DI)p[i];
      acc += term << 1;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P + P
	case 1: // P = P + N
	case 6: // N = N + P
	case 7: // N = N + N
	  // no range crossing
	  break;
	case 2: // P = N + P
	case 5: // N = P + N
	  // cross through zero
	  break;
	case 3: // P = N + N
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2));
	  break;
	case 4: // N = P + P
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2));
	  break;
	}
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 1010 0111 00001 qqqqq ppppp 1   cpsmsbslua1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbslua1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      DI tmp;

      if (q[i] == 0x8000 && p[i] == 0x8000)
	{
	  tmp = 0x7ffffff;
	  cc |= (1 << (i+4));
	}
      else
	tmp = ((SI)q[i] * (SI)p[i]) << 1;

      acc -= tmp;
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << (i+4));
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << (i+4));
	}
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 1011 0111 00001 qqqqq ppppp 1   cpsmsbslla1.h crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbslla1_h (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      DI tmp;

      if (q[i] == 0x8000 && p[i] == 0x8000)
	{
	  tmp = 0x7ffffff;
	  cc |= (1 << (i));
	}
      else
	tmp = ((SI)q[i] * (SI)p[i]) << 1;

      acc -= tmp;
      if (acc > 0x7fffffffLL)
	{
	  acc = 0x7fffffffLL;
	  cc |= (1 << (i));
	}
      else if (acc < -0x80000000LL)
	{
	  acc = -0x80000000LL;
	  cc |= (1 << (i));
	}
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 1110 0111 00001 qqqqq ppppp 1   cpsmsbslua1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbslua1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+5)) << 32) | (USI) A1r (i*2+4);
      oacc = acc;
      if (q[i] == 0x80000000 && p[i] == 0x80000000)
	{
	  term = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	}
      else
	term = (DI)q[i] * (DI)p[i];
      acc -= term << 1;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P - P
	case 1: // P = P - N
	case 6: // N = N - P
	case 7: // N = N - N
	  // no range crossing
	  break;
	case 3: // P = N - N
	case 4: // N = P - P
	  // cross through zero
	  break;
	case 2: // P = N - P
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2+4));
	  break;
	case 5: // N = P - N
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	  break;
	}
      A1w (i*2+5, acc >> 32);
      A1w (i*2+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 1111 0111 1111 0111 00001 qqqqq ppppp 1   cpsmsbslla1.w crqc,crpc (c3_1)
void mep::mep_cpu_cgen::ivc2_cpsmsbslla1_w (PCADDR &pc, DI crqc, DI crpc)
{
  int i;
  SI q[2], p[2];
  USI cc;
  UDI acc, oacc, term;

  unpack (crqc, q);
  unpack (crpc, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A1r (i*2+1)) << 32) | (USI) A1r (i*2);
      oacc = acc;
      if (q[i] == 0x80000000 && p[i] == 0x80000000)
	{
	  term = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2+4));
	}
      else
	term = (DI)q[i] * (DI)p[i];
      acc -= term << 1;
      switch (di_msbs (acc, oacc, term))
	{
	case 0: // P = P - P
	case 1: // P = P - N
	case 6: // N = N - P
	case 7: // N = N - N
	  // no range crossing
	  break;
	case 3: // P = N - N
	case 4: // N = P - P
	  // cross through zero
	  break;
	case 2: // P = N - P
	  acc = -0x8000000000000000LL;
	  cc |= (3 << (i*2));
	  break;
	case 5: // N = P - N
	  acc = 0x7fffffffffffffffLL;
	  cc |= (3 << (i*2));
	  break;
	}
      A1w (i*2+1, acc >> 32);
      A1w (i*2+0, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// 00000 00000 00000 00000   c0nop  (p0_1)
void mep::mep_cpu_cgen::ivc2_c0nop (PCADDR &pc)
{
}

// 11000 qqqqq ppppp 00000   cpadda0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpadda0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  UQI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A0w (i, (SI)q[i] + (SI)p[i]);
}

// 11000 qqqqq ppppp 00001   cpadda0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpadda0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  QI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A0w (i, (SI)q[i] + (SI)p[i]);
}

// 11000 qqqqq ppppp 00010   cpaddua0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaddua0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A0w (i+4, (SI)q[i] + (SI)p[i]);
}

// 11000 qqqqq ppppp 00011   cpaddla0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaddla0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A0w (i, (SI)q[i] + (SI)p[i]);
}

// 11000 qqqqq ppppp 00100   cpaddaca0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaddaca0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      DI acc = A0r (i);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 00101   cpaddaca0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaddaca0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A0r (i);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 00110   cpaddacua0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaddacua0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A0r (i+4);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i+4, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 00111   cpaddacla0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaddacla0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A0r (i);
      acc += (SI)q[i] + (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 01000   cpsuba0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsuba0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  UQI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A0w (i, (SI)q[i] - (SI)p[i]);
}

// 11000 qqqqq ppppp 01001   cpsuba0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsuba0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  QI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A0w (i, (SI)q[i] - (SI)p[i]);
}

// 11000 qqqqq ppppp 01010   cpsubua0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsubua0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A0w (i+4, (SI)q[i] - (SI)p[i]);
}

// 11000 qqqqq ppppp 01011   cpsubla0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsubla0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A0w (i, (SI)q[i] - (SI)p[i]);
}

// 11000 qqqqq ppppp 01100   cpsubaca0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsubaca0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      DI acc = A0r (i);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 01101   cpsubaca0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsubaca0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A0r (i);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 01110   cpsubacua0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsubacua0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A0r (i+4);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i+4, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 01111   cpsubacla0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsubacla0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A0r (i);
      acc += (SI)q[i] - (SI)p[i];
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 10000   cpabsa0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpabsa0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  UQI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A0w (i, abs ((SI)q[i] - (SI)p[i]));
}

// 11000 qqqqq ppppp 10001   cpabsa0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpabsa0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  QI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A0w (i, abs ((SI)q[i] - (SI)p[i]));
}

// 11000 qqqqq ppppp 10010   cpabsua0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpabsua0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A0w (i+4, abs ((SI)q[i] - (SI)p[i]));
}

// 11000 qqqqq ppppp 10011   cpabsla0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpabsla0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A0w (i, abs ((SI)q[i] - (SI)p[i]));
}

// 11000 qqqqq ppppp 10100   cpsada0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsada0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      DI acc = A0r (i);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 10101   cpsada0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsada0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A0r (i);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 10110   cpsadua0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsadua0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A0r (i+4);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i+4, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 10111   cpsadla0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsadla0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A0r (i);
      acc += abs ((SI)q[i] - (SI)p[i]);
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A0w (i, acc);
    }

  ccw (IVC2_COFA0, cc);
}

// 11000 qqqqq ppppp 11011   cpseta0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpseta0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    {
      A0w (i+4, q[i]);
      A0w (i, p[i]);
    }
}

// 11000 qqqqq ppppp 11100   cpsetua0.w crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsetua0_w (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  SI q[2], p[2];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<2; i++)
    {
      A0w (i+2, q[i]);
      A0w (i, p[i]);
    }
}

// 11000 qqqqq ppppp 11101   cpsetla0.w crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsetla0_w (PCADDR &pc, DI crqp, DI crpp)
{
  int i;
  SI q[2], p[2];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<2; i++)
    {
      A0w (i+6, q[i]);
      A0w (i+4, p[i]);
    }
}

// 11001 00000 00001 ooooo   cpmova0.b =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmova0_b (PCADDR &pc)
{
  int i;
  QI o[8];

  for (i=0; i<8; i++)
    o[i] = A0r (i);

  return pack (o);
}

// 11001 00000 00010 ooooo   cpmovua0.h =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovua0_h (PCADDR &pc)
{
  int i;
  HI o[4];

  for (i=0; i<4; i++)
    o[i] = A0r (i+4);

  return pack (o);
}

// 11001 00000 00011 ooooo   cpmovla0.h =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovla0_h (PCADDR &pc)
{
  int i;
  HI o[4];

  for (i=0; i<4; i++)
    o[i] = A0r (i);

  return pack (o);
}

// 11001 00000 00100 ooooo   cpmovuua0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovuua0_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A0r (i+6);

  return pack (o);
}

// 11001 00000 00101 ooooo   cpmovula0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovula0_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A0r (i+4);

  return pack (o);
}

// 11001 00000 00110 ooooo   cpmovlua0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovlua0_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A0r (i+2);

  return pack (o);
}

// 11001 00000 00111 ooooo   cpmovlla0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovlla0_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A0r (i);

  return pack (o);
}

// 11001 00000 01000 ooooo   cppacka0u.b =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cppacka0u_b (PCADDR &pc)
{
  int i;
  QI o[8];
  DI acc;

  for (i=0; i<8; i++)
    {
      acc = A0r (i);
      o[i] = (acc > 255) ? 255 : (acc < 0) ? 0 : acc;
    }

  return pack (o);
}

// 11001 00000 01001 ooooo   cppacka0.b =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cppacka0_b (PCADDR &pc)
{
  int i;
  QI o[8];
  DI acc;

  for (i=0; i<8; i++)
    {
      acc = A0r (i);
      o[i] = (acc > 127) ? 127 : (acc < -128) ? -128 : acc;
    }

  return pack (o);
}

// 11001 00000 01010 ooooo   cppackua0.h =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cppackua0_h (PCADDR &pc)
{
  int i;
  HI o[4];
  DI acc;

  for (i=0; i<4; i++)
    {
      acc = A0r (i+4);
      o[i] = (acc > 32767) ? 32767 : (acc < -32768) ? -32768 : acc;
    }

  return pack (o);
}

// 11001 00000 01011 ooooo   cppackla0.h =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cppackla0_h (PCADDR &pc)
{
  int i;
  HI o[4];
  DI acc;

  for (i=0; i<4; i++)
    {
      acc = A0r (i);
      o[i] = (acc > 32767) ? 32767 : (acc < -32768) ? -32768 : acc;
    }

  return pack (o);
}

// 11001 00000 01100 ooooo   cppackua0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cppackua0_w (PCADDR &pc)
{
  int i;
  SI o[2];
  DI acc;

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A0r (i*2+5)) << 32) | (USI) A0r (i*2+4);
      o[i] = (acc > 2147483647LL) ? 2147483647LL : (acc < -2147483648LL) ? -2147483648LL : acc;
    }

  return pack (o);
}

// 11001 00000 01101 ooooo   cppackla0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cppackla0_w (PCADDR &pc)
{
  int i;
  SI o[2];
  DI acc;

  for (i=0; i<2; i++)
    {
      acc = ((UDI) ((USI) A0r (i*2+1)) << 32) | (USI) A0r (i*2);
      o[i] = (acc > 2147483647LL) ? 2147483647LL : (acc < -2147483648LL) ? -2147483648LL : acc;
    }

  return pack (o);
}

// 11001 00000 01110 ooooo   cpmovhua0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovhua0_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A0r (i*2+5);

  return pack (o);
}

// 11001 00000 01111 ooooo   cpmovhla0.w =crop (p0_1)
DI mep::mep_cpu_cgen::ivc2_cpmovhla0_w (PCADDR &pc)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = A0r (i*2+1);

  return pack (o);
}

// 11001 00000 10000 00000   cpacsuma0  (p0_1)
void mep::mep_cpu_cgen::ivc2_cpacsuma0 (PCADDR &pc)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, A0r (i) + A1r (i));
}

// 11001 00000 10001 00000   cpaccpa0  (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaccpa0 (PCADDR &pc)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, A1r (i));
}

// 11001 qqqqq 11000 00000   cpsrla0 crqp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsrla0 (PCADDR &pc, DI crqp)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, (USI) A0r (i) >> (crqp & 0x1f));
}

// 11001 qqqqq 11001 00000   cpsraa0 crqp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsraa0 (PCADDR &pc, DI crqp)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, (SI) A0r (i) >> (crqp & 0x1f));
}

// 11001 qqqqq 11010 00000   cpslla0 crqp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpslla0 (PCADDR &pc, DI crqp)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, (USI) A0r (i) << (crqp & 0x1f));
}

// 11001 00000 11100 iiiii   cpsrlia0 imm5 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsrlia0 (PCADDR &pc, SI imm5)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, (USI) A0r (i) >> imm5);
}

// 11001 00000 11101 iiiii   cpsraia0 imm5 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsraia0 (PCADDR &pc, SI imm5)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, (SI) A0r (i) >> imm5);
}

// 11001 00000 11110 iiiii   cpsllia0 imm5 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpsllia0 (PCADDR &pc, SI imm5)
{
  int i;

  for (i=0; i<8; i++)
    A0w (i, (USI) A0r (i) << imm5);
}

// 11111 qqqqq ppppp 00000   cpfsftba0s0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftba0s0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  UDI tmp;
  UQI tmpv[8];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A0w (i, tmpv[i]);
}

// 11111 qqqqq ppppp 00001   cpfsftba0s0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftba0s0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  QI tmpv[8];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A0w (i, tmpv[i]);
}

// 11111 qqqqq ppppp 00010   cpfsftbua0s0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftbua0s0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A0w (i+4, tmpv[i]);
}

// 11111 qqqqq ppppp 00011   cpfsftbla0s0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftbla0s0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A0w (i, tmpv[i]);
}

// 11111 qqqqq ppppp 00100   cpfaca0s0u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfaca0s0u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  UQI tmpv[8];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      tmp = A0r (i);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << i);
      A0w (i, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 00101   cpfaca0s0.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfaca0s0_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  QI tmpv[8];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      tmp = A0r (i);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << i);
      A0w (i, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 00110   cpfacua0s0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfacua0s0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      tmp = A0r (i+4);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << (i+4));
      A0w (i+4, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 00111   cpfacla0s0.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfacla0s0_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      tmp = A0r (i);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << i);
      A0w (i, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 01000   cpfsftba0s1u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftba0s1u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  UDI tmp;
  UQI tmpv[8];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A0w (i, tmpv[i]);
}

// 11111 qqqqq ppppp 01001   cpfsftba0s1.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftba0s1_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  QI tmpv[8];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A0w (i, tmpv[i]);
}

// 11111 qqqqq ppppp 01010   cpfsftbua0s1.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftbua0s1_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A0w (i+4, tmpv[i]);
}

// 11111 qqqqq ppppp 01011   cpfsftbla0s1.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfsftbla0s1_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A0w (i, tmpv[i]);
}

// 11111 qqqqq ppppp 01100   cpfaca0s1u.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfaca0s1u_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  UQI tmpv[8];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);
  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      tmp = A0r (i);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << i);
      A0w (i, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 01101   cpfaca0s1.b crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfaca0s1_b (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  QI tmpv[8];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);
  cc = ccr (IVC2_COFA0);

  for (i=0; i<8; i++)
    {
      tmp = A0r (i);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << i);
      A0w (i, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 01110   cpfacua0s1.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfacua0s1_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      tmp = A0r (i+4);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << (i+4));
      A0w (i+4, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// 11111 qqqqq ppppp 01111   cpfacla0s1.h crqp,crpp (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfacla0s1_h (PCADDR &pc, DI crqp, DI crpp)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA0);

  for (i=0; i<4; i++)
    {
      tmp = A0r (i);
      tmp += tmpv[i];
      if (tmp > 0x7fffffffLL || tmp < -0x80000000LL)
	cc |= (1 << i);
      A0w (i, tmp);
    }

  ccw (IVC2_COFA0, cc);
}

// iiiiiiii 10110 qqqqq 01iii iiiii   cpmovi.h =crqp,imm16p0 (p0_i)
DI mep::mep_cpu_cgen::ivc2_cpmovi_h16 (PCADDR &pc, SI imm16)
{
  int i;
  HI o[4];
  for (i=0; i<4; i++)
    o[i] = (HI)imm16;

  return pack (o);
}

// iiiiiiii 10111 qqqqq 00iii iiiii   cpmoviu.w =crqp,imm16p0 (p0_i)
DI mep::mep_cpu_cgen::ivc2_cpmoviu_w16 (PCADDR &pc, SI imm16)
{
  int i;
  USI o[2];

  for (i=0; i<2; i++)
    o[i] = (UHI)imm16;

  return pack (o);
}

// iiiiiiii 10111 qqqqq 01iii iiiii   cpmovi.w =crqp,imm16p0 (p0_i)
DI mep::mep_cpu_cgen::ivc2_cpmovi_w16 (PCADDR &pc, SI imm16)
{
  int i;
  SI o[2];

  for (i=0; i<2; i++)
    o[i] = (HI)imm16;

  return pack (o);
}

// iiiiiiii 10111 qqqqq 10iii iiiii   cdmoviu =crqp,imm16p0 (p0_i)
DI mep::mep_cpu_cgen::ivc2_cdmoviu16 (PCADDR &pc, SI imm16)
{
  return (UHI)imm16;
}

// iiiiiiii 10111 qqqqq 11iii iiiii   cdmovi =crqp,imm16p0 (p0_i)
DI mep::mep_cpu_cgen::ivc2_cdmovi16 (PCADDR &pc, SI imm16)
{
  return (HI)imm16;
}
// 00000000 00000 00000 00000 00000   c1nop  (p0_1)
void mep::mep_cpu_cgen::ivc2_c1nop (PCADDR &pc)
{
}

// 00000000 11001 00000 10000 00000   cpacsuma1  (p0_1)
void mep::mep_cpu_cgen::ivc2_cpacsuma1 (PCADDR &pc)
{
  int i;

  for (i=0; i<8; i++)
    A1w (i, A0r (i) + A1r (i));
}

// 00000000 11001 00000 10001 00000   cpaccpa1  (p0_1)
void mep::mep_cpu_cgen::ivc2_cpaccpa1 (PCADDR &pc)
{
  int i;

  for (i=0; i<8; i++)
    A1w (i, A0r (i));
}

// 00000000 11001 00000 10010 00000   cpacswp  (p0_1)
void mep::mep_cpu_cgen::ivc2_cpacswp (PCADDR &pc)
{
  int i;
  USI tmp;

  for (i=0; i<8; i++)
    {
      tmp = A0r (i);
      A0w (i, A1r (i));
      A1w (i, tmp);
    }
}

// iiiiiiii 11111 qqqqq ppppp 00000   cpfmulia1s0u.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmulia1s0u_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  UQI tmpv[8];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 00001   cpfmulia1s0.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmulia1s0_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  QI tmpv[8];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 00010   cpfmuliua1s0.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmuliua1s0_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A1w (i+4, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 00011   cpfmulila1s0.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmulila1s0_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 00100   cpfmadia1s0u.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadia1s0u_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  UQI tmpv[8];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 00101   cpfmadia1s0.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadia1s0_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  QI tmpv[8];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 00110   cpfmadiua1s0.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadiua1s0_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << (i+4));
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 00111   cpfmadila1s0.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadila1s0_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar0;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar0 = ccr (IVC2_CSAR0) * 8;
  tmp = ((UDI) crqp << csar0) | (UDI) crpp >> (64-csar0);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 01000   cpfmulia1s1u.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmulia1s1u_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  UQI tmpv[8];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 01001   cpfmulia1s1.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmulia1s1_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  QI tmpv[8];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 01010   cpfmuliua1s1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmuliua1s1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A1w (i+4, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 01011   cpfmulila1s1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmulila1s1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 01100   cpfmadia1s1u.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadia1s1u_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  UQI tmpv[8];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 01101   cpfmadia1s1.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadia1s1_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  QI tmpv[8];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 01110   cpfmadiua1s1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadiua1s1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << (i+4));
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 01111   cpfmadila1s1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpfmadila1s1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i, csar1;
  DI tmp;
  HI tmpv[4];
  USI cc;

  csar1 = ccr (IVC2_CSAR1) * 8;
  tmp = ((UDI) crqp << csar1) | (UDI) crpp >> (64-csar1);
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 10000   cpamulia1u.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamulia1u_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  UQI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A1w (i, ((SI)q[i] + (SI)p[i]) * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 10001   cpamulia1.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamulia1_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  QI q[8], p[8];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<8; i++)
    A1w (i, ((SI)q[i] + (SI)p[i]) * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 10010   cpamuliua1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamuliua1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A1w (i+4, ((SI)q[i] + (SI)p[i]) * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 10011   cpamulila1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamulila1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  HI q[4], p[4];

  unpack (crqp, q);
  unpack (crpp, p);

  for (i=0; i<4; i++)
    A1w (i, ((SI)q[i] + (SI)p[i]) * imm8);
}

// iiiiiiii 11111 qqqqq ppppp 10100   cpamadia1u.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamadia1u_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  UQI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += ((SI)q[i] + (SI)p[i]) * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 10101   cpamadia1.b crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamadia1_b (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  QI q[8], p[8];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += ((SI)q[i] + (SI)p[i]) * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 10110   cpamadiua1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamadiua1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += ((SI)q[i] + (SI)p[i]) * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << (i+4));
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11111 qqqqq ppppp 10111   cpamadila1.h crqp,crpp,imm8 (p0_1)
void mep::mep_cpu_cgen::ivc2_cpamadila1_h (PCADDR &pc, DI crqp, DI crpp, SI imm8)
{
  int i;
  HI q[4], p[4];
  USI cc;

  unpack (crqp, q);
  unpack (crpp, p);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += ((SI)q[i] + (SI)p[i]) * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11100 qqqqq ppppp 00 III   cpfmulia1u.b crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmulia1u_b (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  UQI tmpv[8];

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11100 qqqqq ppppp 01 III   cpfmulia1.b crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmulia1_b (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  QI tmpv[8];

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  for (i=0; i<8; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11100 qqqqq ppppp 10 III   cpfmuliua1.h crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmuliua1_h (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  HI tmpv[4];

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A1w (i+4, tmpv[i] * imm8);
}

// iiiiiiii 11100 qqqqq ppppp 11 III   cpfmulila1.h crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmulila1_h (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  HI tmpv[4];

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  for (i=0; i<4; i++)
    A1w (i, tmpv[i] * imm8);
}

// iiiiiiii 11101 qqqqq ppppp 00 III   cpfmadia1u.b crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmadia1u_b (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  UQI tmpv[8];
  USI cc;

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11101 qqqqq ppppp 01 III   cpfmadia1.b crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmadia1_b (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  QI tmpv[8];
  USI cc;

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<8; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11101 qqqqq ppppp 10 III   cpfmadiua1.h crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmadiua1_h (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  HI tmpv[4];
  USI cc;

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i+4);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << (i+4));
      A1w (i+4, acc);
    }

  ccw (IVC2_COFA1, cc);
}

// iiiiiiii 11101 qqqqq ppppp 11 III   cpfmadila1.h crqp,crpp,imm3p25,imm8p0 (cpfm)
void mep::mep_cpu_cgen::ivc2_cpfmadila1_h (PCADDR &pc, DI crqp, DI crpp, SI imm3, SI imm8)
{
  int i;
  DI tmp;
  HI tmpv[4];
  USI cc;

  tmp = ((UDI) crqp << (imm3*8)) | (UDI) crpp >> (64-(imm3*8));
  unpack (tmp, tmpv);

  cc = ccr (IVC2_COFA1);

  for (i=0; i<4; i++)
    {
      DI acc = (SI) A1r (i);
      acc += tmpv[i] * imm8;
      if (acc < -0x80000000LL
	  || acc > 0x7fffffffLL)
	cc |= (1 << i);
      A1w (i, acc);
    }

  ccw (IVC2_COFA1, cc);
}

