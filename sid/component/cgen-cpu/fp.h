// fp.h - Floating point number class using host integer ops.  -*- C++ -*-

// Copyright 1997, 1998, 2002 Free Software Foundation, Inc.
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

namespace sidutil
{
  class fp
    {
    public:
      typedef int status_t;
      typedef int exp_t;
      typedef sid::host_int_8 fraction_t;
      
      typedef enum round_mode_t
	{
	  round_default,
	  round_near,
	  round_zero,
	  round_up,
	  round_down
	};
      
      typedef enum denorm_t
	{
	  denorm_default,
	  denorm_underflow_inexact,
	  denorm_zero
	};
      
      typedef enum class_t
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

      // Conversions to integers.
      void integer (int&, round_mode_t = round_default);
      void integer (long&, round_mode_t = round_default);
      void integer (unsigned int&, round_mode_t = round_default);
      void integer (unsigned long&, round_mode_t = round_default);

      // Pack an fp into registers of various sizes.
      void pack (cgen::SF&) const;
      void pack (cgen::DF&) const;
      void pack (cgen::SF& upper, cgen::SF& lower) const;

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

    private:
      status_t status;
      enum class_t fp_class;
      int sign;
      fraction_t fraction;
      exp_t normal_exp;

      void do_round (bool double_p, round_mode_t round, enum denorm_t denorm);
      status_t do_normal_round (int nr_guards, enum round_mode_t round);
      status_t do_normal_overflow (bool double_p, enum round_mode_t round);
      status_t do_normal_underflow (bool double_p, enum round_mode_t round);

      void int_to_fp (cgen::SI i);
      void uint_to_fp (cgen::USI i);
      template <typename T> void fp_to_int (T& t, round_mode_t round);
      template <typename T> void fp_to_uint (T& t);
      template <typename T> void unpack (const T& t);
      template <typename T> void pack_any (T& t) const;

      friend std::ostream& operator<< (std::ostream& out, const fp& f);
      friend fp operator+ (const fp& l, const fp& r);
      friend fp operator- (const fp& l, const fp& r);
      friend fp operator* (const fp& l, const fp& r);
      friend fp operator/ (const fp& l, const fp& r);
    };

  fp operator+ (const fp& l, const fp& r);
  fp operator- (const fp& l, const fp& r);
  fp operator* (const fp& l, const fp& r);
  fp operator/ (const fp& l, const fp& r);

  bool operator<  (const fp& l, const fp& r);
  bool operator<= (const fp& l, const fp& r);
  bool operator== (const fp& l, const fp& r);
  bool operator!= (const fp& l, const fp& r);
  bool operator>= (const fp& l, const fp& r);
  bool operator>  (const fp& l, const fp& r);

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
