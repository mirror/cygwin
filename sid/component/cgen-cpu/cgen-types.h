// cgen-types.h - Types for CGEN-based SID simulators.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2010 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_TYPES_H
#define CGEN_TYPES_H

namespace cgen {

// Modes.

typedef bool BI;
typedef void VOID;

typedef sid::signed_host_int_1 QI;
typedef sid::signed_host_int_2 HI;
typedef sid::signed_host_int_4 SI;
typedef sid::signed_host_int_8 DI;

typedef sid::host_int_1 UQI;
typedef sid::host_int_2 UHI;
typedef sid::host_int_4 USI;
typedef sid::host_int_8 UDI;

typedef USI SF;
typedef UDI DF;

#define GETLODI(di) ((SI) (di))
#define GETHIDI(di) ((SI) ((UDI) (di) >> 32))
#define SETLODI(di, val) ((di) = (((di) & 0xffffffff00000000LL) | (val)))
#define SETHIDI(di, val) ((di) = (((di) & 0xffffffffLL) | (((DI) (val)) << 32)))
#define SETDI(di, hi, lo) ((di) = MAKEDI (hi, lo))
#define MAKEDI(hi, lo) ((((DI) (SI) (hi)) << 32) | ((UDI) (USI) (lo)))

// Variable width small ints.
typedef int INT;
typedef unsigned int UINT;

// Addresses.
// Instruction addresses.
typedef unsigned long IADDR;
// Data addresses.
typedef unsigned long ADDR;
// Deprecated.
typedef IADDR PCADDR;  

// Builtin floating point conversion kinds.
// The values here are defined by cgen.

enum fpconv_kind {
  FPCONV_DEFAULT = 0,
  FPCONV_TIES_TO_EVEN = 1,
  FPCONV_TIES_TO_AWAY = 2,
  FPCONV_TOWARD_ZERO = 3,
  FPCONV_TOWARD_POSITIVE = 4,
  FPCONV_TOWARD_NEGATIVE = 5
};

} // namespace cgen

#endif // CGEN_TYPES_H
