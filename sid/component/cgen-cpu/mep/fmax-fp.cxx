// fmax-fp.cxx - CPU components.  -*- C++ -*-
// CGEN fpu support for the MeP FMAX coprocessor for SID
//
// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "fmax-fp.h"

namespace sidutil
{

static const fmax_fp fmax_constant_qnan  (fp::class_qnan);

void
fmax_fp::integer (signed_host_int_4& i, round_mode_t mode)
{
  host_int_8 tmp;
  int shift;
  status = fp::ok;

  if (is_zero ())
    {
      i = 0;
      return;
    }

  if (is_snan ())
    {
      cgen::SF qnan;
      fmax_constant_qnan.pack (qnan);
      i = qnan;
      status = fp::invalid_snan;
      throw fp::error (status);
    }

  if (is_qnan () || is_infinity ())
    {
      cgen::SF qnan;
      fmax_constant_qnan.pack (qnan);
      i = qnan;
      status = fp::invalid_cvi;
      throw fp::error (status);
    }
    
  // Is the floating point MIN_INT or just close?
  if (sign && (normal_exp == (NR_INTBITS (false) - 1)))
    {
      assert (fraction >= IMPLICIT_1);
      if (fraction == IMPLICIT_1)
	{
	  i = ~0x7fffffff;
	  return; // exact
	}
    }

  // Would right shifting result in the FRAC being shifted into
  // (through) the integer's sign bit?
  if (normal_exp > (NR_INTBITS (false) - 2))
    {
      cgen::SF qnan;
      fmax_constant_qnan.pack (qnan);
      i = qnan;
      status = fp::invalid_cvi;
      throw fp::error (status);
    }

  // Normal number shift it into place.
  tmp = fraction;
  shift = (normal_exp - (NR_FRAC_GUARD));
  if (shift < 0)
    {
      // Perform rounding, if bits will be lost
      i = round_int_32 (mode);
      if (status != ok)
	throw fp::error (status);
    }
  else 
    {
      tmp <<= shift;
      i = sign ? (-tmp) : (tmp);
    }
  
}

// Perform rounding to integer according to the rules in:
//   FMAX: Fpu, a Mep Architecture eXtension User's Manual, section 1-3
//
signed_host_int_4
fmax_fp::round_int_32 (round_mode_t mode)
{
  // Compute the number of fraction bits.
  int shift = (normal_exp - (NR_FRAC_GUARD));
  assert (shift < 0);
  shift = -shift;

  // Compute the unrounded result
  signed_host_int_8 unrounded = sign ? -fraction : fraction;
  signed_host_int_4 result;
  if (shift >= sizeof (unrounded) * 8)
    result = (sign && unrounded < 0) ? ~(signed_host_int_8)0 : 0;
  else
    result = unrounded >> shift;

  // The round bit is the first fractional bit to the right of the binary
  // point.
  // The sticky bit is the OR of the remaining fractional bits.
  int round = 0;
  int sticky = 0;
  if (shift >= 1)
    {
      if (shift <= sizeof (unrounded) * 8)
	{
	  round = (fraction >> (shift - 1)) & 1;
	  if (shift >= 2)
	    sticky = (fraction & ((host_int_8 (1) << (shift - 1)) - 1)) != 0;
	}
      else
	sticky = (fraction != 0);

      if (round || sticky)
	status |= inexact;
    }

  // Perform the rounding based in the sign/round/sticky bits along with the
  // rounding mode according to the tables in section 1-3 of the spec
  int srs = (sign << 2) | (round << 1) | sticky;
  switch (mode)
    {
    case round_default:
    case round_near:
      switch (srs)
	{
	case 0: case 1: case 4: case 7:
	  break; // no rounding
	case 2: case 6:
	  if (result & 1)
	    ++result;
	  break;
	default:
	  ++result;
	  break;
	}
      break;
    case round_zero:
      if (sign && srs != 0x4)
	++result;
      break;
    case round_up:
      if (srs && srs != 0x4)
	++result;
      break;
    case round_down:
      // Already rounded correctly
      break;
    default:
      abort ();
      break;
    }

  return result;
}

// Always underflow to positive zero
fp::status_t
fmax_fp::do_normal_underflow (bool, round_mode_t)
{
  fp_class = class_zero;
  sign = 0;
  return (fp::inexact | fp::underflow);
}

// Use fp::operator+ with the difference that the sticky bit
// will be preserved for an operand which is of much smaller
// magnitude than the other.
fmax_fp
fmax_fp::operator+ (const fmax_fp& r) const
{
  fmax_fp f;

  if (! this->is_snan ()
      && ! r.is_snan ()
      && ! this->is_qnan ()
      && ! r.is_qnan ()
      && ! this->is_infinity ()
      && ! r.is_infinity ()
      && ! this->is_zero ()
      && ! r.is_zero ())
    {
      int shift = this->normal_exp - r.normal_exp;
      if (shift >= NR_FRAC_GUARD)
	{
	  // Left has much bigger magnitude.
	  f = *this;
	  f.sign = r.sign;
	  if (r.fraction)
	    {
	      bool double_p = false;
	      f.fraction = LSBIT64 (NR_GUARDS (double_p) - 2); // Sticky bit
	    }
	  return fp::operator+ (f);
	}
      if (shift <= - NR_FRAC_GUARD)
	return r + *this;
    }
  // Use fp::operator+
  const fp &fp_l = *this;
  const fp &fp_r = r;
  return fp_l + fp_r;
}

fmax_fp
fmax_fp::operator- (const fmax_fp& r) const
{
  if (! r.is_nan ())
    return *this + neg (r);
  return *this + r;
}

}; // namespace sidutil
