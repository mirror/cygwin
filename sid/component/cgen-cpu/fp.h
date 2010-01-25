// fp.h - Floating point number class using host integer ops.  -*- C++ -*-

// Copyright 1997, 1998, 2002, 2005, 2006, 2010 Free Software Foundation, Inc.
// Copyright 2002 Red Hat, Inc.
// This file is part of SID.

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

// This file is heavily lifted from the GDB simulators' sim-fpu.{h,c},
// which in turn is heavily lifted from GCC's fp-bit library.

#ifndef FP_H
#define FP_H

#include <stdlib.h>
#include "sidtypes.h"
#include "cgen-types.h"

using sid::host_int_4;
using sid::host_int_8;
using sid::signed_host_int_8;

// XXX: more of this cruft should be C++-ed.

#define FRAC32MASK   LSMASK64 (63, NR_FRAC_GUARD - 32 + 1)
#define MAX_UINT32() LSMASK64 (31, 0)
#define MAX_UINT64() LSMASK64 (63, 0)
#define MAX_INT      (is_64bit ? MAX_INT64 ()  : MAX_INT32 ())
#define MIN_INT      (is_64bit ? MIN_INT64 ()  : MIN_INT32 ())
#define MAX_UINT     (is_64bit ? MAX_UINT64 () : MAX_UINT32 ())
#define QUIET_NAN     LSBIT64 (NR_FRACBITS (double_p) - 1)
#define IMPLICIT_1    LSBIT64 (NR_FRAC_GUARD)
#define IMPLICIT_2    LSBIT64 (NR_FRAC_GUARD + 1)
#define IMPLICIT_4    LSBIT64 (NR_FRAC_GUARD + 2)
#define NORMAL_EXPMIN (-(EXPBIAS (double_p) )+1)
#define NORMAL_EXPMAX (EXPBIAS (double_p))

#if (WITH_TARGET_WORD_MSB == 0)
#define _LSB_SHIFT(WIDTH, POS) (WIDTH - 1 - POS)
#else
#define _LSB_SHIFT(WIDTH, POS) (POS)
#endif

#if (WITH_TARGET_WORD_MSB == 0)
#define _MSB_SHIFT(WIDTH, POS) (POS)
#else
#define _MSB_SHIFT(WIDTH, POS) (WIDTH - 1 - POS)
#endif

#define _MASK64(WIDTH, START, STOP) (((static_cast<host_int_8>(-1)) \
				     >> (_MSB_SHIFT (WIDTH, START) \
					 + _LSB_SHIFT (WIDTH, STOP))) \
				    << _LSB_SHIFT (WIDTH, STOP))

#if (WITH_TARGET_WORD_MSB == 0)
#define _LSB_POS(WIDTH, SHIFT) (WIDTH - 1 - SHIFT)
#else
#define _LSB_POS(WIDTH, SHIFT) (SHIFT)
#endif

#define _LSMASK64(WIDTH, FIRST, LAST) _MASK64 (WIDTH, \
					     _LSB_POS (WIDTH, FIRST), \
					     _LSB_POS (WIDTH, LAST))

#define LSMASK64(FIRST, LAST)  _LSMASK64 (64, (FIRST), (LAST))

#define GUARDMSB   LSBIT64  (NR_GUARDS (double_p) - 1)
#define GUARDLSB   LSBIT64  (NR_PADS (double_p))
#define GUARDMASK  LSMASK64 (NR_GUARDS (double_p) - 1, 0)
#define GUARDROUND LSMASK64 (NR_GUARDS (double_p) - 2, 0)

#define PADMASK    LSMASK64 (NR_PADS (double_p) - 1, 0)

static const int NR_SPARE = 2;
static const int EXPMAX32 = 255;
static const int EXPMAX64 = 2047;
static const int NR_FRAC_GUARD = 60;
static const int EXPBIAS32 = 127;
static const int EXPBIAS64 = 1023;
static const int NR_PAD32 = 30;
static const int NR_PAD64 = 0;
static const int NR_GUARDS32 = 7 + NR_PAD32;
static const int NR_GUARDS64 = 8 + NR_PAD64;
static const int NORMAL_EXPMAX32 = EXPBIAS32;
static const int NORMAL_EXPMAX64 = EXPBIAS64;

static inline
signed_host_int_8 MAX_INT32 ()
{
  return LSMASK64 (30, 0);
}

static inline
signed_host_int_8 MIN_INT32 ()
{
  return LSMASK64 (63, 31);
}

static inline
signed_host_int_8 MAX_INT64 ()
{
  return LSMASK64 (62, 0);
}

static inline
signed_host_int_8 MIN_INT64 ()
{
  return LSMASK64 (63, 63);
}

static inline
unsigned EXPMAX (bool double_p)
{
  return double_p ? EXPMAX64 : EXPMAX32;
} 

static inline
int EXPBIAS (bool double_p)
{
  return double_p ? EXPBIAS64 : EXPBIAS32;
}

static inline
int NR_GUARDS (bool double_p)
{
  return double_p ? NR_GUARDS64 : NR_GUARDS32;
}

static inline
int NR_PADS (bool double_p)
{
  return double_p ? NR_PAD64 : NR_PAD32;
}

static inline
int NR_EXPBITS (bool double_p)
{
  return double_p ? 11 : 8;
}

static inline
int NR_FRACBITS (bool double_p)
{
  return double_p ? 52 : 23;
}

static inline
int NR_INTBITS (bool is_64bit)
{
  return is_64bit ? 64 : 32;
}

static inline
host_int_8 LSBIT64 (int pos)
{
  return host_int_8 (1) << pos;
}

static inline
host_int_8 MSBIT64 (int pos)
{
  return host_int_8 (1) << (64 - 1 - pos);
}

static inline
host_int_8 SIGNBIT (bool double_p)
{
  return double_p ? MSBIT64 (0) : MSBIT64 (32);
}

namespace sidutil
{
  class fp
    {
    public:
      typedef int status_t;
      typedef int exp_t;
      typedef sid::host_int_8 fraction_t;
      
      enum round_mode_t
	{
	  round_default = cgen::FPCONV_DEFAULT,
	  round_near = cgen::FPCONV_TIES_TO_EVEN,
	  round_zero = cgen::FPCONV_TOWARD_ZERO,
	  round_up = cgen::FPCONV_TOWARD_POSITIVE,
	  round_down = cgen::FPCONV_TOWARD_NEGATIVE
	};
      
      enum denorm_t
	{
	  denorm_default,
	  denorm_underflow_inexact,
	  denorm_zero
	};
      
      enum class_t
	{
	  class_zero,
	  class_snan,
	  class_qnan,
	  class_number,
	  class_denorm,
	  class_infinity
	};

      // Type thrown by operators.
      class error
      {
      public:
	error (fp::status_t s) :status (s) {}
	operator int() { return static_cast<int> (status); }
      private:
	fp::status_t status;
      };

      // Construct a float from packed registers.
      fp (const cgen::SF&);
      fp (const cgen::DF&);
      fp (const cgen::SF& high, const cgen::SF& low);

      fp ()
	:status (ok), fp_class (class_zero), sign (0), fraction (0), normal_exp (0) {}
      fp (enum class_t c)
	:status (ok), fp_class (c), sign (0), fraction (0), normal_exp (0) {}
      fp (enum class_t c, int s, sid::host_int_8 f, exp_t exp)
	:status (ok), fp_class (c), sign (s), fraction (f), normal_exp (exp) {}

      // Is this fp NaN?
      bool is_nan () const;

      // Is this fp a signalling NaN?
      bool is_snan () const;
      
      // Is this fp a quiet NaN?
      bool is_qnan () const;

      bool is_denorm () const;
      bool is_zero () const;
      bool is_infinity () const;
      bool is_number () const;
      bool is_inexact () const;
      bool is_negative () const;

      status_t get_status () const { return status; }
      class_t get_class () const { return fp_class; }

      // Conversions to integers.
      virtual void integer (int&, round_mode_t = round_default);
      virtual void integer (long&, round_mode_t = round_default);
      virtual void integer (long long&, round_mode_t = round_default);
      virtual void integer (unsigned int&, round_mode_t = round_default);
      virtual void integer (unsigned long&, round_mode_t = round_default);
      virtual void integer (unsigned long long&, round_mode_t = round_default);

      // Pack an fp into registers of various sizes.
      void pack (cgen::SF&) const;
      void pack (cgen::DF&) const;
      void pack (cgen::SF& upper, cgen::SF& lower) const;

      virtual host_int_8 qnan_exponent (bool double_p) const
      {
	return EXPMAX (double_p);
      }

      virtual host_int_8 qnan_fraction (bool double_p) const
      {
	// Force fraction to correct class.
	host_int_8 frac = fraction;
	frac >>= NR_GUARDS (double_p);
	frac |= QUIET_NAN;
	return frac;
      }

      virtual host_int_8 snan_exponent (bool double_p) const
      {
	return EXPMAX (double_p);
      }

      virtual host_int_8 snan_fraction (bool double_p) const
      {
	// Force fraction to correct class.
	host_int_8 frac = fraction;
	frac >>= NR_GUARDS (double_p);
	frac &= ~QUIET_NAN;
	return frac;
      }

      virtual bool is_qnan_fraction (host_int_8 frac, bool double_p) const { return frac >= QUIET_NAN; }

      // Round an fp suitable for packing.
      void round_32 (round_mode_t = round_default, enum denorm_t = denorm_default);
      void round_64 (round_mode_t = round_default, enum denorm_t = denorm_default);

      template <typename T> static fp from_int (T i);
      template <typename T> static fp from_uint (T u);

      static fp max (const fp& l, const fp& r);
      static fp min (const fp& l, const fp& r);
      static fp neg (const fp& f);
      static fp abs (const fp& f);
      static fp inv (const fp& f);
      static fp sqrt (const fp& f);

      // Status codes (can be bitwise ORed).
      enum
	{
	  ok = 0x0,
	  invalid_snan = 0x1,
	  invalid_qnan = 0x2,
	  invalid_isi = 0x4,
	  invalid_idi = 0x8,
	  invalid_zdz = 0x10,
	  invalid_imz = 0x20,
	  invalid_cvi = 0x40,
	  invalid_div0 = 0x80,
	  invalid_cmp = 0x100,
	  invalid_sqrt = 0x200,
	  rounded = 0x400,
	  inexact = 0x800,
	  overflow = 0x1000,
	  underflow = 0x2000,
	  denorm = 0x4000
	};

    protected:
      status_t status;
      enum class_t fp_class;
      int sign;
      fraction_t fraction;
      exp_t normal_exp;

      virtual void do_round (bool double_p, round_mode_t round, enum denorm_t denorm);
      virtual status_t do_normal_round (int nr_guards, enum round_mode_t round);
      virtual status_t do_normal_overflow (bool double_p, enum round_mode_t round);
      virtual status_t do_normal_underflow (bool double_p, enum round_mode_t round);

      void int_to_fp (cgen::SI i);
      void uint_to_fp (cgen::USI i);
      template <typename T> void fp_to_int (T& t, round_mode_t round);
      template <typename T> void fp_to_uint (T& t);
      template <typename T> void unpack (const T& t);
      template <typename T> void pack_any (T& t) const;

    public:
      fp operator+ (const fp& r) const;
      fp operator- (const fp& r) const; 
      fp operator* (const fp& r) const;
      fp operator/ (const fp& r) const;

      bool operator<  (const fp& r) const;
      bool operator<= (const fp& r) const;
      bool operator== (const fp& r) const;
      bool operator!= (const fp& r) const;
      bool operator>= (const fp& r) const;
      bool operator>  (const fp& r) const;

      friend std::ostream& operator<< (std::ostream& out, const fp& f);
    };

  std::ostream& operator<< (std::ostream& op, const fp& f);
  
  // A number of useful constants.
  extern const fp constant_zero;
  extern const fp constant_one;
  extern const fp constant_two;
  extern const fp constant_qnan;
  extern const fp constant_max32;
  extern const fp constant_max64;

  inline bool
  fp::is_nan () const 
    {
      return fp_class == class_qnan || fp_class == class_snan;
    }

  inline bool
  fp::is_snan () const
    {
      return fp_class == class_snan;
    }

  inline bool
  fp::is_qnan () const
    {
      return fp_class == class_qnan;
    }

  inline bool
  fp::is_zero () const
    {
      return fp_class == class_zero;
    }

  inline bool
  fp::is_infinity () const
    {
      return fp_class == class_infinity;
    }

  inline bool
  fp::is_number () const
    {
      return fp_class == class_denorm || fp_class == class_number;
    }

  inline bool
  fp::is_negative () const
    {
      return (is_number () || is_zero ()) && sign;
    }

  inline bool
  fp::is_inexact () const
    {
      return status == inexact;
    }

  inline bool
  fp::is_denorm () const
    {
      return fp_class == class_denorm;
    }

  inline void
  fp::pack (cgen::SF& sf) const
    { 
      pack_any (sf);
    }

  inline void
  fp::pack (cgen::DF& df) const
    {
      pack_any (df);
    }

  inline void
  fp::pack (cgen::SF& high, cgen::SF& low) const
    {
      sid::host_int_8 temp = high;
      temp = (temp << 32) | low;
      pack_any (temp);
    }

  template <typename T>
  fp
  fp::from_int (T i)
  {
    fp f;
    f.int_to_fp (i);
    return f;
  }
  
  template <typename T>
  fp
  fp::from_uint (T u)
  {
    fp f;
    f.uint_to_fp (u);
    return f;
  }
};

#endif // FP_H
