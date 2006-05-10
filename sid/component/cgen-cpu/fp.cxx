// fp.cxx - Floating point number class implementation. -*- C++ -*-

// Copyright 1997, 1998, 2002, 2005, 2006 Free Software Foundation, Inc.
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

#include "fp.h"

static void
print_bits (std::ostream& out, host_int_8 x, int msbit, int digits)
{
  host_int_8 bit = LSBIT64 (msbit);
  int i = 4;
  while (bit && digits)
    {
      if (i == 0)
	out << ",";

      if ((x & bit))
	out << "1";
      else
	out << "0";
      bit >>= 1;

      if (digits > 0) digits--;
      i = (i + 1) % 4;
    }
}

namespace sidutil
{
  // Quick and dirty conversion between a host double and host 64bit int.

  typedef union
  {
    double d;
    host_int_8 i;
  } map_t;

  static inline
  host_int_8 LSMASKED64 (host_int_8 word, int start, int stop)
  {
    word &= LSMASK64 (start, stop);
    return word;
  }


  static inline
  host_int_8 LSEXTRACTED64 (host_int_8 val, int start, int stop)
  {
    int num_bits = sizeof (val) * 8;
    val <<= (num_bits - 1 - start); // drop high bits 
    val >>= (num_bits - 1 - start) + stop; // drop low bits
    return val;
  }

  template <typename T> void
  fp::fp_to_int (T& i, round_mode_t round)
  {
    // Convert a floating point into an integer.

    host_int_8 tmp;
    int shift;
    int is_64bit = (sizeof i == 8);
    fp::status_t status = fp::ok;

    if (is_zero ())
      {
	i = 0;
	return;
      }
    if (is_snan ())
      {
	// XXX: FIXME from sim-fpu.c?
	i = MIN_INT;
	throw fp::error (fp::invalid_cvi);
      }
    if (is_qnan ())
      {
	i = MIN_INT;
	throw fp::error (fp::invalid_cvi);
      }
    
    // Map infinity onto MAX_INT.
    if (is_infinity ())
      {
	i = (sign) ? MIN_INT : MAX_INT;
	throw fp::error (fp::invalid_cvi);
      }

    // It is a number, but a small one.
    if (normal_exp < 0)
      {
	i = 0;
	throw fp::error (fp::inexact);
      }

    // Is the floating point MIN_INT or just close?
    if (sign && normal_exp == (NR_INTBITS (is_64bit) - 1))
      {
	i = MIN_INT;
	assert (fraction >= IMPLICIT_1);
	if (fraction == IMPLICIT_1)
	  return; // exact
	if (is_64bit) // can't round
	  throw fp::error (fp::overflow); // must be overflow

	// For a 32bit with MAX_INT, rounding is possible.
	switch (round)
	  {
	  case fp::round_default:
	    abort ();
	  case fp::round_zero:
	    if ((fraction & FRAC32MASK) != IMPLICIT_1)
	      throw fp::error (fp::invalid_cvi);
	    else
	      throw fp::error (fp::inexact);
	    break;
	  case fp::round_near:
	    {
	      if ((fraction & FRAC32MASK) != IMPLICIT_1)
		throw fp::error (fp::invalid_cvi);
	      else if ((fraction & !FRAC32MASK) >= (~FRAC32MASK >> 1))
		throw fp::error (fp::invalid_cvi);
	      else
		throw fp::error (fp::inexact);
	    }
	  case fp::round_up:
	    if ((fraction & FRAC32MASK) == IMPLICIT_1)
	      throw fp::error (fp::inexact);
	    else
	      throw fp::error (fp::invalid_cvi);
	  case fp::round_down:
	    throw fp::error (fp::invalid_cvi);
	  }
      }
 
    // Would right shifting result in the FRAC being shifted into
    // (through) the integer's sign bit?

    if (normal_exp > (NR_INTBITS (is_64bit) - 2))
      {
	i = sign ? MIN_INT : MAX_INT;
	throw fp::error (fp::overflow);
      }
    // Normal number shift it into place.
    tmp = fraction;
    shift = (normal_exp - (NR_FRAC_GUARD));
    if (shift > 0)
      {
	tmp <<= shift;
      }
    else
      {
	shift = -shift;
	if (tmp & ((host_int_8 (1) << shift) - 1))
	  status = fp::inexact;
	tmp >>= shift;
      }
    i = sign ? (-tmp) : (tmp);
    if (status != fp::ok)
      throw fp::error (status);
  }

  // Convert a floating point into an integer.
  template <typename T> void
  fp::fp_to_uint (T& u)
  {
    host_int_8 tmp;
    int shift;
    int is_64bit = (sizeof u == 8);
    bool double_p = (sizeof u == 8);

    if (is_zero ())
      {
	u = 0;
	return;
      }

    if (is_nan ())
      {
	u = 0;
	return;

      }
    // It is a negative number.
    if (sign)
      {
	u = 0;
	return;
      }
    // Get reasonable MAX_USI_INT.
    if (is_infinity ())
      {
	u = MAX_UINT;
	return;
      }
    // It is a number, but a small one.
    if (normal_exp < 0)
      {
	u = 0;
	return;
      }
    // Overflow.
    if (normal_exp > (NR_INTBITS (is_64bit) - 1))
      {
	u = MAX_UINT;
	return;
      }
    // Normal number.
    tmp = (fraction & ~PADMASK);
    shift = (normal_exp - (NR_FRACBITS (double_p) + NR_GUARDS (double_p)));
    if (shift > 0)
      tmp <<= shift;
    else
      {
	shift = -shift;
	tmp >>= shift;
      }
    u = tmp;
  }

  // Convert a signed integer into an fp.
  void
  fp::int_to_fp (cgen::SI i)
  {
    int is_64bit = (sizeof i == 8);

    if (i == 0)
      {
	fp_class = fp::class_zero;
	sign = 0;
      }
    else
      {
	fp_class = fp::class_number;
	sign = (i < 0);
	normal_exp = NR_FRAC_GUARD;

	if (sign)
	  {
	    // Special case for minint, since there is no corresponding
	    // +ve integer representation for it.
	    if (i == MIN_INT)
	      {
		fraction = IMPLICIT_1;
		normal_exp = NR_INTBITS (is_64bit) - 1;
	      }
	    else
	      fraction = (-i);
	  }
	else
	  fraction = i;

	if (fraction >= IMPLICIT_2)
	  {
	    do 
	      {
		fraction = (fraction >> 1) | (fraction & 1);
		normal_exp ++;
	      }
	    while (fraction >= IMPLICIT_2);
	  }
	else if (fraction < IMPLICIT_1)
	  {
	    do
	      {
		fraction <<= 1;
		normal_exp --;
	      }
	    while (fraction < IMPLICIT_1);
	  }
      }

    // Sanity check.
    {
      long val;
      integer (val, fp::round_zero);
      if (i >= MIN_INT32 () && i <= MAX_INT32 ())
	{
	  assert (val == i);
	}
    }
  }

  // Convert an unsigned integer into an fp.
  void
  fp::uint_to_fp (cgen::USI u)
  {
    if (u == 0)
      {
	fp_class = fp::class_zero;
	sign = 0;
      }
    else
      {
	fp_class = fp::class_number;
	sign = 0;
	normal_exp = NR_FRAC_GUARD;
	fraction = u;
	
	while (fraction < IMPLICIT_1)
	  {
	    fraction <<= 1;
	    normal_exp -= 1;
	  }
      }
  }

  template <typename T> void
  fp::pack_any (T& t) const
  {
    // Squeeze an unpacked sim_fpu struct into a 32/64 bit integer.

    bool double_p = (sizeof t == 8);
    host_int_8 exp;
    host_int_8 frac;
    host_int_8 packed;
    int sign_bit = sign;

    switch (fp_class)
      {
	// Create a NaN.
      case fp::class_qnan:
	sign_bit = 0;
	exp = qnan_exponent (double_p);
	frac = qnan_fraction (double_p);
	break;
      case fp::class_snan:
	sign_bit = 0;
	exp = snan_exponent (double_p);
	frac = snan_fraction (double_p);
	break;
      case fp::class_infinity:
	exp = EXPMAX (double_p);
	frac = 0;
	break;
      case fp::class_zero:
	exp = 0;
	frac = 0;
	break;
      case fp::class_number:
      case fp::class_denorm:
	assert (fraction >= IMPLICIT_1);
	assert (fraction < IMPLICIT_2);
	if (normal_exp < NORMAL_EXPMIN)
	  {
	    // This number's exponent is too low to fit into the bits
	    // available in the number We'll denormalize the number by
	    // storing zero in the exponent and shift the fraction to
	    // the right to make up for it.

	    int nr_shift = NORMAL_EXPMIN - normal_exp;
	    if (nr_shift > NR_FRACBITS (double_p))
	      {
		// Underflow, just make the number zero.
		exp = 0;
		frac = 0;
	      }
	    else
	      {
		exp = 0;
		// Shift by the value.
		frac = fraction;
		frac >>= NR_GUARDS (double_p);
		frac >>= nr_shift;
	      }
	  }
	else if (normal_exp > NORMAL_EXPMAX)
	  {
	    // Infinity.
	    exp = EXPMAX (double_p);
	    frac = 0; 
	  }
	else
	  {
	    exp = (normal_exp + EXPBIAS (double_p));
	    frac = fraction;
	    // FIXME: Need to round according to WITH_SIM_FPU_ROUNDING
	    // or some such.

	    // Round to nearest: If the guard bits are the all zero, but
	    // the first, then we're half way between two numbers,
	    // choose the one which makes the lsb of the answer 0.
	    if ((frac & GUARDMASK) == GUARDMSB)
	      {
		if ((frac & (GUARDMSB << 1)))
		  frac += (GUARDMSB << 1);
	      }
	    else
	      {
		// Add a one to the guards to force round to nearest.
		frac += GUARDROUND;
	      }
	    if ((frac & IMPLICIT_2)) // Rounding resulted in carry.
	      {
		exp += 1;
		frac >>= 1;
	      }
	    frac >>= NR_GUARDS (double_p);
	    
	    // When exp == EXPMAX (overflow from carry) fraction must
	    // have been made zero.
	    assert ((exp == EXPMAX (double_p)) <= ((frac & ~IMPLICIT_1) == 0));
	  }
	break;
      default:
	abort ();
      }

    packed = ((sign_bit ? SIGNBIT (double_p) : 0) | 
	      (exp << NR_FRACBITS (double_p)) | LSMASKED64 (frac, NR_FRACBITS (double_p) - 1, 0));
    t = packed;
  }

  template <typename T> void
  fp::unpack (const T& packed)
  {
    status = ok;
    // Unpack a 32/64 bit integer into an fp object.
    bool double_p = (sizeof packed == 8);

    host_int_8 frac = LSMASKED64 (packed, NR_FRACBITS (double_p) - 1, 0);
    unsigned exp = LSEXTRACTED64 (packed, NR_EXPBITS (double_p) + NR_FRACBITS (double_p) - 1, NR_FRACBITS (double_p));
    int signbit = (packed & SIGNBIT (double_p)) != 0;

    if (exp == 0)
      {
	// Hmm.  Looks like 0.
	if (frac == 0)
	  {
	    // Tastes like zero.
	    fp_class = fp::class_zero;
	    sign = signbit;
	  }
	else
	  {
	    // Zero exponent with non zero fraction - it's
	    // denormalized, so there isn't a leading implicit one -
	    // we'll shift it so it gets one.
	    normal_exp = exp - EXPBIAS (double_p) + 1;
	    fp_class = fp::class_denorm;
	    sign = signbit;
	    frac <<= NR_GUARDS (double_p);
	    while (frac < IMPLICIT_1)
	      {
		frac <<= 1;
		normal_exp--;
	      }
	    fraction = frac;
	  }
      }
    else if (exp == EXPMAX (double_p))
      {
	// Huge exponent.
	if (frac == 0)
	  {
	    // Attached to a zero fraction - means infinity.
	    fp_class = fp::class_infinity;
	    sign = signbit;
	    // dst->normal_exp = EXPBIAS (double_p);
	    // dst->fraction = 0;
	  }
	else
	  {
	    // Non zero fraction, means NaN.
	    sign = signbit;
	    fraction = (frac << NR_GUARDS (double_p));
	    fp_class = is_qnan_fraction (frac, double_p) ? fp::class_qnan : fp::class_snan;
	    status = is_qnan () ? invalid_qnan : invalid_snan;
	  }
      }
    else
      {
	// Nothing strange about this number.
	fp_class = fp::class_number;
	sign = signbit;
	fraction = ((frac << NR_GUARDS (double_p)) | IMPLICIT_1);
	normal_exp = exp - EXPBIAS (double_p);
      }

    // Sanity checks.
    if (! is_nan ())
    {
      if (double_p)
	{
	  map_t val;
	  pack (val.i);
	  assert (val.i == packed);
	}
      else
	{
	  host_int_4 val;
	  pack (val);
	  host_int_4 org = packed;
	  assert (val == org);
	}
    }
  }

  void
  fp::do_round (bool double_p, round_mode_t round, denorm_t denorm)
  {
    switch (fp_class)
      {
      case fp::class_qnan:
      case fp::class_zero:
      case fp::class_infinity:
	status = fp::ok;
	break;
      case fp::class_snan:
	// Quieten a SignalingNaN.
	fp_class = fp::class_qnan;
	status = fp::invalid_snan;
	break;
      case fp::class_number:
      case fp::class_denorm:
	{
	  assert (fraction < IMPLICIT_2);
	  assert (fraction >= IMPLICIT_1);
	  if (normal_exp < NORMAL_EXPMIN)
	  {
	    // This number's exponent is too low to fit into the bits
	    // available in the number.  Round off any bits that will
	    // be discarded as a result of denormalization.  Edge case
	    // is the implicit bit shifted to GUARD0 and then rounded
	    // up.

	    int shift = NORMAL_EXPMIN - normal_exp;
	    if (shift + NR_GUARDS (double_p) <= NR_FRAC_GUARD + 1
		&& !(denorm & fp::denorm_zero))
	      {
		status = do_normal_round (shift + NR_GUARDS (double_p), round);
		if (fraction == 0) // Rounding underflowed.
		  {
		    status |= do_normal_underflow (double_p, round);
		  }
		else if (normal_exp < NORMAL_EXPMIN) // Still underflow?
		  {
		    status |= fp::denorm;
		    // Any loss of precision when denormalizing is
		    // underflow. Some processors check for underflow
		    // before rounding, some after!
		    if (status & fp::inexact)
		      status |= fp::underflow;

		    // Flag that resultant value has been
		    // denormalized.

		    fp_class = fp::class_denorm;
		  }
		else if ((denorm & fp::denorm_underflow_inexact))
		  {
		    if ((status & fp::inexact))
		      status |= fp::underflow;
		  }
	      }
	    else
	      {
		status = do_normal_underflow (double_p, round);
	      }
	  }
	  else if (normal_exp > NORMAL_EXPMAX)
	  {
	    // Infinity.
	    status = do_normal_overflow (double_p, round);
	  }
	  else
	  {
	    status = do_normal_round (NR_GUARDS (double_p), round);
	    if (fraction == 0)
	      // f->class = sim_fpu_class_zero;
	      status |= do_normal_underflow (double_p, round);
	    else if (normal_exp > NORMAL_EXPMAX)
	      // Oops! rounding caused overflow.
	      status |= do_normal_overflow (double_p, round);
	  }
	  assert ((fp_class == fp::class_number
		   || fp_class == fp::class_denorm)
		  <= (fraction < IMPLICIT_2 && fraction >= IMPLICIT_1));
	  return;
      }
      }
    status = fp::ok;
  }

  // Round a number using NR_GUARDS.
  // Will return the rounded number or F->FRACTION == 0 when underflow.

  fp::status_t
  fp::do_normal_round (int nr_guards, fp::round_mode_t round)
  {
    host_int_8 guardmask = LSMASK64 (nr_guards - 1, 0);
    host_int_8 guardmsb = LSBIT64 (nr_guards - 1);
    host_int_8 fraclsb = guardmsb << 1;
    if ((fraction & guardmask))
      {
	int status = fp::inexact;
	switch (round)
	  {
	  case fp::round_default:
	    return fp::ok;
	  case fp::round_near:
	    if ((fraction & guardmsb))
	      {
		if ((fraction & fraclsb))
		  {
		    status |= fp::rounded;
		  }
		else if ((fraction & (guardmask >> 1)))
		  {
		    status |= fp::rounded;
		  }
	      }
	    break;
	  case fp::round_up:
	    if (!sign)
	      status |= fp::rounded;
	    break;
	  case fp::round_down:
	    if (sign)
	      status |= fp::rounded;
	    break;
	  case fp::round_zero:
	    break;
	  }
	fraction &= ~guardmask;
	// Round if needed, handle resulting overflow.
	if ((status & fp::rounded))
	  {
	    fraction += fraclsb;
	    if ((fraction & IMPLICIT_2))
	      {
		fraction >>= 1;
		normal_exp += 1;
	      }
	  }
	return status;
      }
    else
      return fp::ok;
  }


  fp::status_t
  fp::do_normal_overflow (bool double_p, round_mode_t round)
  {
    switch (round)
      {
      case fp::round_default:
	return fp::ok;
      case fp::round_near:
	fp_class = fp::class_infinity;
	break;
      case fp::round_up:
	if (! sign)
	  fp_class = fp::class_infinity;
	break;
      case fp::round_down:
	if (sign)
	  fp_class = fp::class_infinity;
	break;
      case fp::round_zero:
	break;
      }
    normal_exp = NORMAL_EXPMAX;
    fraction = LSMASK64 (NR_FRAC_GUARD, NR_GUARDS (double_p));
    return (fp::overflow | fp::inexact);
  }

  fp::status_t
  fp::do_normal_underflow (bool double_p, round_mode_t round)
  {
    switch (round)
      {
      case fp::round_default:
	return fp::ok;
      case fp::round_near:
	fp_class = class_zero;
	break;
      case fp::round_up:
	if (sign)
	  fp_class = fp::class_zero;
	break;
      case fp::round_down:
	if (!sign)
	  fp_class = fp::class_zero;
	break;
      case fp::round_zero:
	fp_class = fp::class_zero;
	break;
      }
    normal_exp = NORMAL_EXPMIN - NR_FRACBITS (double_p);
    fraction = IMPLICIT_1;
    return (fp::inexact | fp::underflow);
  }

  void
  fp::round_32 (round_mode_t round, denorm_t denorm)
  {
    do_round (false, round, denorm);
  }

  void
  fp::round_64 (round_mode_t round, denorm_t denorm)
  {
    do_round (true, round, denorm);
  }

  fp::fp (const host_int_4& u32)
  {
    unpack (u32);
  }

  fp::fp (const host_int_8& u64)
  {
    unpack (u64);
  }

  fp::fp (const host_int_4& upper32, const host_int_4& lower32)
  {
    host_int_8 temp = upper32;
    temp = (temp << 32) | lower32;
    unpack (temp);
  }

  void
  fp::integer (int& i, round_mode_t mode)
  {
    fp_to_int (i, mode);
  }

  void
  fp::integer (long& i, round_mode_t mode)
  {
    fp_to_int (i, mode);
  }

  void
  fp::integer (long long& i, round_mode_t mode)
  {
    fp_to_int (i, mode);
  }

  void
  fp::integer (unsigned int& i, round_mode_t mode)
  {
    fp_to_int (i, mode);
  }

  void
  fp::integer (unsigned long& i, round_mode_t mode)
  {
    fp_to_int (i, mode);
  }

  void
  fp::integer (unsigned long long& i, round_mode_t mode)
  {
    fp_to_int (i, mode);
  }

  std::ostream& operator<< (std::ostream& out, const fp& f)
  {
    out << ((f.sign) ? "-" : "+");
    
    switch (f.fp_class)
      {
      case fp::class_qnan:
	out << "0.";
	print_bits (out, f.fraction, NR_FRAC_GUARD - 1, out.precision());
	out << "*QuietNaN";
	break;
      case fp::class_snan:
	out << "0.";
	print_bits (out, f.fraction, NR_FRAC_GUARD - 1, out.precision());
	out << "*SignalNaN";
	break;
      case fp::class_zero:
	out << "0.0";
	break;
      case fp::class_infinity:
	out << "INF";
	break;
      case fp::class_number:
      case fp::class_denorm:
	out << "1.";
	print_bits (out, f.fraction, NR_FRAC_GUARD - 1, out.precision());
	out << "*2^";
	out << ((f.normal_exp >= 0) ? "+" : "-");
	out << f.normal_exp;
	assert (f.fraction >= IMPLICIT_1);
	assert (f.fraction < IMPLICIT_2);
      }
    return out;
  }

  bool
  fp::operator<  (const fp& r) const
  {
    if (!this->is_nan () && !r.is_nan ())
      {
	map_t lval, rval;
	this->pack (lval.i);
	r.pack (rval.i);
	return (lval.d < rval.d);
      }
    else if (this->is_snan () || r.is_snan ())
      throw fp::error (fp::invalid_snan);
    else
      throw fp::error (fp::invalid_qnan);
  }

  bool
  fp::operator<= (const fp& r) const
  {
    if (!this->is_nan () && !r.is_nan ())
      {
	map_t lval, rval;
	this->pack (lval.i);
	r.pack (rval.i);
	return (lval.d <= rval.d);
      }
    else if (this->is_snan () || r.is_snan ())
      throw fp::error (fp::invalid_snan);
    else
      throw fp::error (fp::invalid_qnan);
  }

  bool 
  fp::operator== (const fp& r) const
  {
    if (!this->is_nan () && !r.is_nan ())
      {
	map_t lval, rval;
	this->pack (lval.i);
	r.pack (rval.i);
	return (lval.d == rval.d);
      }
    else if (this->is_snan () || r.is_snan ())
      throw fp::error (fp::invalid_snan);
    else
      throw fp::error (fp::invalid_qnan);
  }


  bool
  fp::operator!= (const fp& r) const
  {
    return !(*this == r);
  }

  bool
  fp::operator>= (const fp& r) const
  {
    return r <= *this;
  }

  bool
  fp::operator>  (const fp& r) const
  {
    return r < *this;
  }

  fp
  fp::operator+ (const fp& r) const
  {
    fp f;

    if (this->is_snan ())
      {
	f = *this;
	f.fp_class = fp::class_qnan;
	f.status = fp::invalid_snan;
	return f;
      }

    if (r.is_snan ())
      {
	f = r;
	f.fp_class = fp::class_qnan;
	f.status = fp::invalid_snan;
	return f;
      }

    if (this->is_qnan ())
      {
	f = *this;
	f.status = fp::ok;
	return f;
      }

    if (r.is_qnan ())
      {
	f = r;
	f.status = fp::ok;
	return f;
      }

    if (this->is_infinity ())
      {
	if (r.is_infinity () && this->sign != r.sign)
	  {
	    f = constant_qnan;
	    f.status = fp::invalid_isi;
	    return f;
	  }
	f = *this;
	f.status = fp::ok;
	return f;
      }

    if (r.is_infinity ())
      {
	f = r;
	f.status = fp::ok;
	return f;
      }

    if (this->is_zero ())
      {
	if (r.is_zero ())
	  {
	    f = constant_zero;
	    f.sign = this->sign & r.sign;
	  }
	else
	  f = r;
	f.status = fp::ok;
	return f;
      }
  
    if (r.is_zero ())
      {
	f = *this;
	f.status = fp::ok;
	return f;
      }

    fp::status_t status = fp::ok;
    int shift = this->normal_exp - r.normal_exp;
    host_int_8 lfraction;
    host_int_8 rfraction;
    // Use exp of larger.
    if (shift >= NR_FRAC_GUARD)
      {
	// Left has much bigger magnitude.
	f = *this;
	f.status = fp::inexact;
	return f;
      }
    if (shift <= - NR_FRAC_GUARD)
      {
	// Right has much bigger magnitude.
	f = r;
	f.status = fp::inexact;
	return f;
      }
    lfraction = this->fraction;
    rfraction = r.fraction;
    if (shift > 0)
      {
	f.normal_exp = this->normal_exp;
	if (rfraction & LSMASK64 (shift - 1, 0))
	  {
	    status |= fp::inexact;
	    rfraction |= LSBIT64 (shift); // Stick LSBit.
	  }
	rfraction >>= shift;
      }
    else if (shift < 0)
      {
	f.normal_exp = r.normal_exp;
	if (lfraction & LSMASK64 (- shift - 1, 0))
	  {
	    status |= fp::inexact;
	    lfraction |= LSBIT64 (- shift); // Stick LSBit.
	  }
	lfraction >>= -shift;
      }
    else
      f.normal_exp = r.normal_exp;

    // Perform the addition.
    if (this->sign)
      lfraction = - lfraction;
    if (r.sign)
      rfraction = - rfraction;
    f.fraction = lfraction + rfraction;

    // Zero?
    if (f.fraction == 0)
      {
	f = constant_zero;
	f.status = fp::ok;
	return f;
      }

    // Sign?
    f.fp_class = fp::class_number;
    if (static_cast<signed_host_int_8> (f.fraction) >= 0)
      f.sign = 0;
    else
      {
	f.sign = 1;
	f.fraction = - f.fraction;
      }

    // Normalize it.
    if ((f.fraction & IMPLICIT_2))
      {
	f.fraction = (f.fraction >> 1) | (f.fraction & 1);
	f.normal_exp ++;
      }
    else if (f.fraction < IMPLICIT_1)
      {
	do
	  {
	    f.fraction <<= 1;
	    f.normal_exp --;
	  }
	while (f.fraction < IMPLICIT_1);
      }
    assert (f.fraction >= IMPLICIT_1 && f.fraction < IMPLICIT_2);
    f.status = status;
    return f;
  }

  fp
  fp::operator- (const fp& r) const
  {
    if (! r.is_nan ())
      return *this + neg (r);
    return *this + r;
  }

  fp
  fp::operator* (const fp& r) const
  {
    fp f;

    if (this->is_snan ())
      {
	f = *this;
	f.fp_class = fp::class_qnan;
	f.status = fp::invalid_snan;
	return f;
      }
    if (r.is_snan ())
      {
	f = r;
	f.fp_class = fp::class_qnan;
	f.status = fp::invalid_snan;
	return f;
      }
    if (this->is_qnan ())
      {
	f = *this;
	f.status = fp::ok;
	return f;
      }
    if (r.is_qnan ())
      {
	f = r;
	f.status = fp::ok;
	return f;
      }
    if (this->is_infinity ())
      {
	if (r.is_zero ())
	  {
	    f = constant_qnan;
	    f.status = fp::invalid_imz;
	    return f;
	  }
	f = *this;
	f.sign = this->sign ^ r.sign;
	return f;
      }
    if (r.is_infinity ())
      {
	if (this->is_zero ())
	  {
	    f = constant_qnan;
	    f.status = fp::invalid_imz;
	    return f;
	  }
	f = r;
	f.sign = this->sign ^ r.sign;
	return f;
      }
    if (this->is_zero () || r.is_zero ())
      {
	f = constant_zero;
	f.sign = this->sign ^ r.sign;
	return f;
      }

    // Calculate the mantissa by multiplying both 64bit numbers to get a
    // 128 bit number.
  
    host_int_8 low;
    host_int_8 high;
    host_int_8 nl = this->fraction & 0xffffffff;
    host_int_8 nh = this->fraction >> 32;
    host_int_8 ml = r.fraction & 0xffffffff;
    host_int_8 mh = r.fraction >>32;
    host_int_8 pp_ll = ml * nl;
    host_int_8 pp_hl = mh * nl;
    host_int_8 pp_lh = ml * nh;
    host_int_8 pp_hh = mh * nh;
    host_int_8 res2 = 0;
    host_int_8 res0 = 0;
    host_int_8 ps_hh__ = pp_hl + pp_lh;
    if (ps_hh__ < pp_hl)
      res2 += 0x100000000ULL;
    pp_hl = (ps_hh__ << 32) & 0xffffffff00000000ULL;
    res0 = pp_ll + pp_hl;
    if (res0 < pp_ll)
      res2++;
    res2 += ((ps_hh__ >> 32) & 0xffffffff) + pp_hh;
    high = res2;
    low = res0;
    
    f.normal_exp = this->normal_exp + r.normal_exp;
    f.sign = this->sign ^ r.sign;
    f.fp_class = fp::class_number;

    // Input is bounded by [1,2)   ;   [2^60,2^61)
    // Output is bounded by [1,4)  ;   [2^120,2^122)
 
    // Adjust the exponent according to where the decimal point ended
    // up in the high 64 bit word.  In the source the decimal point
    // was at NR_FRAC_GUARD.

    f.normal_exp += NR_FRAC_GUARD + 64 - (NR_FRAC_GUARD * 2);

    // The high word is bounded according to the above.  Consequently
    // it has never overflowed into IMPLICIT_2.

    assert (high < LSBIT64 (((NR_FRAC_GUARD + 1) * 2) - 64));
    assert (high >= LSBIT64 ((NR_FRAC_GUARD * 2) - 64));
    assert (LSBIT64 (((NR_FRAC_GUARD + 1) * 2) - 64) < IMPLICIT_1);
    
    // Normalize.
    do
      {
	f.normal_exp--;
	high <<= 1;
	if (low & LSBIT64 (63))
	  high |= 1;
	low <<= 1;
      }
    while (high < IMPLICIT_1);

    assert (high >= IMPLICIT_1 && high < IMPLICIT_2);
    if (low != 0)
      {
	f.fraction = (high | 1); // Sticky.
	f.status = fp::inexact;
      }
    else
      f.fraction = high;

    return f;
  }

  fp
  fp::operator/ (const fp& r) const
  {
    fp f;

    if (this->is_snan ())
      {
	f = *this;
	f.fp_class = fp::class_qnan;
	f.status = fp::invalid_snan;
	return f;
      }
    if (r.is_snan ())
      {
	f = r;
	f.fp_class = fp::class_qnan;
	f.status = fp::invalid_snan;
	return f;
      }
    if (this->is_qnan ())
      {
	f = *this;
	f.fp_class = fp::class_qnan;
	return f;
      }
    if (r.is_qnan ())
      {
	f = r;
	f.fp_class = fp::class_qnan;
	return f;
      }
    if (this->is_infinity ())
      {
	if (r.is_infinity ())
	  {
	    f = constant_qnan;
	    f.status = fp::invalid_idi;
	  }
	else
	  {
	    f = *this;
	    f.sign = this->sign ^ r.sign;
	  }
	return f;
      }

    if (this->is_zero ())
      {
	if (r.is_zero ())
	  {
	    f = constant_qnan;
	    f.status = fp::invalid_zdz;
	  }
	else
	  {
	    f = *this;
	    f.sign = this->sign ^ r.sign;
	  }
	return f;
      }

    if (r.is_infinity ())
      {
	f = constant_zero;
	f.sign = this->sign ^ r.sign;
	return f;
      }

    if (r.is_zero ())
      {
	f.fp_class = fp::class_infinity;
	f.sign = this->sign ^ r.sign;
	f.status = fp::invalid_div0;
	return f;
      }

    // Calculate the mantissa by multiplying both 64bit numbers to get
    // a 128 bit number.

    // quotient =  ( ( numerator / denominator)
    //            x 2^(numerator exponent -  denominator exponent)
  
    host_int_8 numerator;
    host_int_8 denominator;
    host_int_8 quotient;
    host_int_8 bit;

    f.fp_class = fp::class_number;
    f.sign = this->sign ^ r.sign;
    f.normal_exp = this->normal_exp - r.normal_exp;

    numerator = this->fraction;
    denominator = r.fraction;

    // Fraction will be less than 1.0.
    if (numerator < denominator)
      {
	numerator <<= 1;
	f.normal_exp--;
      }
    assert (numerator >= denominator);
    
    // Gain extra precision, already used one spare bit.
    numerator <<= NR_SPARE;
    denominator <<= NR_SPARE;

    // Does divide one bit at a time.  Optimize?
    quotient = 0;
    bit = (IMPLICIT_1 << NR_SPARE);
    while (bit)
      {
	if (numerator >= denominator)
	  {
	    quotient |= bit;
	    numerator -= denominator;
	  }
	bit >>= 1;
	numerator <<= 1;
      }

    // Discard (but save) the extra bits.
    if ((quotient & LSMASK64 (NR_SPARE -1, 0)))
      quotient = (quotient >> NR_SPARE) | 1;
    else
      quotient = (quotient >> NR_SPARE);

    f.fraction = quotient;
    assert (f.fraction >= IMPLICIT_1 && f.fraction < IMPLICIT_2);
    if (numerator != 0)
      {
	f.fraction |= 1; // Stick remaining bits.
	f.status = fp::inexact;
      }
    else
      f.status = fp::ok;
    return f;
  }

  fp
  fp::max (const fp& l, const fp& r)
  {
    fp dest;

    if (l.is_snan ())
      {
	dest = l;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::invalid_snan;
	return dest;
      }

    if (r.is_snan ())
      {
	dest = r;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::invalid_snan;
	return dest;
      }

    if (l.is_qnan ())
      {
	dest = l;
	dest.status = fp::ok;
	return dest;
      }

    if (r.is_qnan ())
      {
	dest = r;
	dest.status = fp::ok;
	return dest;
      }

    if (l.is_infinity ())
      {
	if (r.is_infinity () && l.sign == r.sign)
	  {
	    dest = constant_qnan;
	    dest.status = fp::invalid_isi;
	    return dest;
	  }
	if (l.sign)
	  dest = r; // -inf < anything
	else
	  dest = l; // +inf > anything
	dest.status = fp::ok;
	return dest;
      }
	
    if (r.is_infinity ())
      {
	if (r.sign)
	  dest = l; // anything > -inf
	else
	  dest = r; // anything < +inf
	dest.status = fp::ok;
	return dest;
      }

    if (l.sign > r.sign)
      {
	dest = r; // -ve < +ve
	dest.status = fp::ok;
	return dest;
      }

    if (l.sign < r.sign)
      {
	dest = l; // +ve > -ve
	dest.status = fp::ok;
	return dest;
      }

    assert (l.sign == r.sign);
    if (l.normal_exp > r.normal_exp ||
	(l.normal_exp == r.normal_exp && l.fraction > r.fraction))
      {
	// |l| > |r|
	if (l.sign)
	  dest = r; // -ve < -ve
	else
	  dest = l; // +ve > +ve
	dest.status = fp::ok;
	return dest;
      }
    else
      {
	// |l| <= |r|
	if (l.sign)
	  dest = l; // -ve > -ve
	else
	  dest = r; // +ve < +ve
	dest.status = fp::ok;
	return dest;
      }
  }

  fp
  fp::min (const fp& l, const fp& r)
  {
    fp dest;

    if (l.is_snan ())
      {
	dest = l;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::ok;
	return dest;
      }
    if (r.is_snan ())
      {
	dest = r;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::ok;
	return dest;
      }
    if (l.is_qnan ())
      {
	dest = l;
	dest.status = fp::ok;
	return dest;
      }
    if (r.is_qnan ())
      {
	dest = r;
	dest.status = fp::ok;
	return dest;
      }
    if (l.is_infinity ())
      {
	if (r.is_infinity () && l.sign == r.sign)
	  {
	    dest = constant_qnan;
	    dest.status = fp::invalid_isi;
	    return dest;
	  }
	if (l.sign)
	  dest = l; // -inf < anything
	else
	  dest = r; // +inf > anthing
	dest.status = fp::ok;
	return dest;
      }
    if (r.is_infinity ())
      {
	if (r.sign)
	  dest = r; // anything > -inf
	else
	  dest = l; // anything < +inf
	dest.status = fp::ok;
	return dest;
      }

    if (l.sign > r.sign)
      {
	dest = l; // -ve < +ve
	dest.status = fp::ok;
	return dest;
      }

    if (l.sign < r.sign)
      {
	dest = r;
	dest.status = fp::ok;
	return dest;
      }

    assert (l.sign == r.sign);
    if (l.normal_exp > r.normal_exp ||
	(l.normal_exp == r.normal_exp && l.fraction > r.fraction))
      {
	// |l| > |r|
	if (l.sign)
	  dest = l; // -ve < -ve
	else
	  dest = r; // +ve > +ve
	dest.status = fp::ok;
	return dest;
      }
    else
      {
	// |l| <= |r|
	if (l.sign)
	  dest = r; // -ve > -ve
	else
	  dest = l; // +ve < +ve
	dest.status = fp::ok;
	return dest;
      }
  }

  fp
  fp::neg (const fp& src)
  {
    fp dest;

    if (src.is_snan())
      {
	dest = src;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::invalid_snan;
	return dest;
      }
    if (src.is_qnan())
      {
	return src;
      }
    dest = src;
    dest.sign = !src.sign;
    return dest;
  }

  fp
  fp::abs (const fp& src)
  {
    fp dest;

    if (src.is_snan ())
      {
	dest = src;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::invalid_snan;
	return dest;
      }
    if (src.is_qnan ())
      {
	dest = src;
	return dest;
      }

    dest = src;
    dest.sign = 0;
    return dest;
  }


  fp
  fp::sqrt (const fp& r)
  {
    fp f;

    if (r.is_snan ())
      {
	f = constant_qnan;
	f.status = fp::invalid_snan;
	return f;
      }
    if (r.is_qnan ())
      {
	f = constant_qnan;
	return f;
      }
    if (r.is_zero ())
      {
	f.fp_class = fp::class_zero;
	f.sign = r.sign;
	f.status = fp::ok;
	return f;
      }
    if (r.is_infinity ())
      {
	if (r.sign)
	  {
	    f = constant_qnan;
	    f.status = fp::invalid_sqrt;
	  }
	else
	  {
	    f.fp_class = fp::class_infinity;
	    f.sign = 0;
	    f.status = fp::ok;
	  }
	return f;
      }
    if (r.sign)
      {
	f = constant_qnan;
	f.status = fp::invalid_sqrt;
	return f;
      }

    /* @(#)e_sqrt.c 5.1 93/09/24 */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice 
     * is preserved.
     * ====================================================
     */
  
    /* __ieee754_sqrt(x)
     * Return correctly rounded sqrt.
     *           ------------------------------------------
     *           |  Use the hardware sqrt if you have one |
     *           ------------------------------------------
     * Method: 
     *   Bit by bit method using integer arithmetic. (Slow, but portable) 
     *   1. Normalization
     *	Scale x to y in [1,4) with even powers of 2: 
     *	find an integer k such that  1 <= (y=x*2^(2k)) < 4, then
     *		sqrt(x) = 2^k * sqrt(y)
     -
     - Since:
     -   sqrt ( x*2^(2m) )     = sqrt(x).2^m    ; m even
     -   sqrt ( x*2^(2m + 1) ) = sqrt(2.x).2^m  ; m odd
     - Define:
     -   y = ((m even) ? x : 2.x)
     - Then:
     -   y in [1, 4)                            ; [IMPLICIT_1,IMPLICIT_4)
     - And:
     -   sqrt (y) in [1, 2)                     ; [IMPLICIT_1,IMPLICIT_2)
     -
     *   2. Bit by bit computation
     *	Let q  = sqrt(y) truncated to i bit after binary point (q = 1),
     *	     i							 0
     *                                     i+1         2
     *	    s  = 2*q , and	y  =  2   * ( y - q  ).		(1)
     *	     i      i            i                 i
     *                                                        
     *	To compute q    from q , one checks whether 
     *		    i+1       i                       
     *
     *			      -(i+1) 2
     *			(q + 2      ) <= y.			(2)
     *     			  i
     *							      -(i+1)
     *	If (2) is false, then q   = q ; otherwise q   = q  + 2      .
     *		 	       i+1   i             i+1   i
     *
     *	With some algebric manipulation, it is not difficult to see
     *	that (2) is equivalent to 
     *                             -(i+1)
     *			s  +  2       <= y			(3)
     *			 i                i
     *
     *	The advantage of (3) is that s  and y  can be computed by 
     *				      i      i
     *	the following recurrence formula:
     *	    if (3) is false
     *
     *	    s     =  s  ,	y    = y   ;			(4)
     *	     i+1      i		 i+1    i
     *
     -
     -                      NOTE: y    = 2*y
     -                             i+1      i
     -
     *	    otherwise,
     *                       -i                      -(i+1)
     *	    s	  =  s  + 2  ,  y    = y  -  s  - 2  		(5)
     *         i+1      i          i+1    i     i
     *				
     -
     -                                                   -(i+1)
     -                      NOTE: y    = 2 (y  -  s  -  2      ) 		
     -                             i+1       i     i
     -
     *	One may easily use induction to prove (4) and (5). 
     *	Note. Since the left hand side of (3) contain only i+2 bits,
     *	      it does not necessary to do a full (53-bit) comparison 
     *	      in (3).
     *   3. Final rounding
     *	After generating the 53 bits result, we compute one more bit.
     *	Together with the remainder, we can decide whether the
     *	result is exact, bigger than 1/2ulp, or less than 1/2ulp
     *	(it will never equal to 1/2ulp).
     *	The rounding mode can be detected by checking whether
     *	huge + tiny is equal to huge, and whether huge - tiny is
     *	equal to huge for some floating point number "huge" and "tiny".
     *		
     * Special cases:
     *	sqrt(+-0) = +-0 	... exact
     *	sqrt(inf) = inf
     *	sqrt(-ve) = NaN		... with invalid signal
     *	sqrt(NaN) = NaN		... with invalid signal for signaling NaN
     *
     * Other methods : see the appended file at the end of the program below.
     *---------------
     */

    // Generate sqrt(x) bit by bit.
    host_int_8 y;
    host_int_8 q;
    host_int_8 s;
    host_int_8 b;

    f.fp_class = fp::class_number;
    f.sign = 0;
    y = r.fraction;
    f.normal_exp = (r.normal_exp >> 1);	// exp = [exp/2]

    // Odd exp, double x to make it even.
    assert (y >= IMPLICIT_1 && y < IMPLICIT_4);
    if ((r.normal_exp & 1))
      {
	y += y;
      }
    assert (y >= IMPLICIT_1 && y < (IMPLICIT_2 << 1));

    // Let loop determine first value of s (either 1 or 2).
    b = IMPLICIT_1;
    q = 0;
    s = 0;
    
    while (b)
      {
	host_int_8 t = s + b;
	if (t <= y)
	  {
	    s |= (b << 1);
	    y -= t;
	    q |= b;
	  }
	y <<= 1;
	b >>= 1;
      }

    assert (q >= IMPLICIT_1 && q < IMPLICIT_2);
    f.fraction = q;
    if (y != 0)
      {
	f.fraction |= 1; // Stick remaining bits.
	f.status = fp::inexact;
      }
    else
      f.status = fp::ok;
    return f;
  }


  fp
  fp::inv (const fp& src)
  {
    fp dest;
    if (src.is_snan())
      {
	dest = src;
	dest.fp_class = fp::class_qnan;
	dest.status = fp::invalid_snan;
	return dest;
      }
    if (src.is_qnan())
      {
	dest = src;
	dest.fp_class = fp::class_qnan;
	return dest;
      }
    if (src.is_infinity())
      {
	dest = constant_zero;
	dest.sign = src.sign;
	return dest;
      }
    if (src.is_zero())
      {
	dest.fp_class = fp::class_infinity;
	dest.sign = src.sign;
	dest.status = fp::invalid_div0;
	return dest;
      }
    dest = src;
    dest.normal_exp = - src.normal_exp;
    return dest;
  }

  const fp constant_zero  (fp::class_zero);
  const fp constant_qnan  (fp::class_qnan);
  const fp constant_one   (fp::class_number, 0, IMPLICIT_1, 0);
  const fp constant_two   (fp::class_number, 0, IMPLICIT_1, 1);
  const fp constant_max32 (fp::class_number, 0, LSMASK64 (NR_FRAC_GUARD, NR_GUARDS32), NORMAL_EXPMAX32);
  const fp constant_max64 (fp::class_number, 0, LSMASK64 (NR_FRAC_GUARD, NR_GUARDS64), NORMAL_EXPMAX64);
};


