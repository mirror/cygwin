/* gdbserv-utils.c

   Copyright 1998, 2000, 2001, 2002 Red Hat, Inc.

   This file is part of RDA, the Red Hat Debug Agent (and library).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
   
   Alternative licenses for RDA may be arranged by contacting Red Hat,
   Inc.  */


#include "config.h"

#include <stdio.h>
#include <string.h>

#include "gdbserv.h"
#include "gdbserv-utils.h"


unsigned char
gdbserv_to_hex (int c)
{
  static const unsigned char hexchars[] = "0123456789abcdef";
  return hexchars[c & 0xf];
}


/* Convert ch from a hex digit to an int. */

int
gdbserv_hex_to (unsigned char ch)
{
  switch (ch)
    {
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
      return ch-'a'+10;
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':      
      return ch-'A'+10;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      return ch-'0';
    default:
      return -1;
    }
}

unsigned int
gdbserv_ulong_to_hex (char *ptr, unsigned long ulong_value, int num_bits)
{
  int num_chars = 0;

  if (ulong_value == 0)
    {
      *(ptr++) = '0';
      *(ptr++) = '0';
      return 2;
    }

  num_bits = (num_bits + 7) / 8;
  while (num_bits)
    {
      int v = (ulong_value >> ((num_bits - 1) * 8));
      if (v || (num_bits == 1))
	{
	  v = v & 255;
	  *(ptr++) = gdbserv_to_hex ((v / 16) & 15);
	  *(ptr++) = gdbserv_to_hex (v & 15);
	  num_chars += 2;
	}
      num_bits--;
    }

  return (num_chars);
}

unsigned int
gdbserv_raw_to_hex (char **ptr, char *mem, int nr_bytes)
{
  int i;
  for (i = 0; i < nr_bytes; i++)
    {
      *(*ptr)++ = gdbserv_to_hex (*mem >> 4);
      *(*ptr)++ = gdbserv_to_hex (*mem++);
    }
  return i;
}

void
gdbserv_reg_to_ulong (struct gdbserv *gdbserv,
		      const struct gdbserv_reg *reg,
		      unsigned long *val)
{
  int i;
  unsigned long l = 0;
  for (i = 0; i < reg->len; i++)
    {
      l <<= 8;
      l |= (unsigned char) reg->buf[i];
    }
  if (reg->negative_p)
    (*val) = -l;
  else
    (*val) = l;
}


void
gdbserv_reg_to_ulonglong (struct gdbserv *gdbserv,
			  const struct gdbserv_reg *reg,
			  unsigned long long *val)
{
  int i;
  unsigned long long l = 0;
  for (i = 0; i < reg->len; i++)
    {
      l <<= 8;
      l |= (unsigned char) reg->buf[i];
    }
  if (reg->negative_p)
    (*val) = -l;
  else
    (*val) = l;
}

static void
unpack_ulongest (struct gdbserv_reg *reg,
		 unsigned long long val)
{
  int len;
  int idx;
  /* unpack */
  len = 0;
  do
    {
      reg->buf[sizeof (reg->buf) - len - 1] = val & 0xff;
      val >>= 8;
      len++;
    }
  while (val != 0);
  /* left shift */
  for (idx = 0; idx < len; idx++)
    {
      reg->buf[idx] = reg->buf[sizeof (reg->buf) - len + idx];
    }
  reg->len = len;
}

void
gdbserv_ulong_to_reg (struct gdbserv *gdbserv,
		      unsigned long val,
		      struct gdbserv_reg *reg)
{
  reg->negative_p = 0;
  unpack_ulongest (reg, val);
}

void
gdbserv_long_to_reg (struct gdbserv *gdbserv,
		     long val,
		     struct gdbserv_reg *reg)
{
  if (val < 0)
    {
      reg->negative_p = 1;
      val = -val;
    }
  else
    reg->negative_p = 0;
  unpack_ulongest (reg, val);
}

void
gdbserv_ulonglong_to_reg (struct gdbserv *gdbserv,
			  unsigned long long val,
			  struct gdbserv_reg *reg)
{
  reg->negative_p = 0;
  unpack_ulongest (reg, val);
}

void
gdbserv_longlong_to_reg (struct gdbserv *gdbserv,
			 long long val,
			 struct gdbserv_reg *reg)
{
  if (val < 0)
    {
      reg->negative_p = 1;
      val = -val;
    }
  else
    reg->negative_p = 0;
  unpack_ulongest (reg, val);
}

/* Copy bytes from one buffer to another in reverse order.  Used for
   converting byte order from big endian to little endian or vice versa.  */

static void
reverse_copy_bytes (void *dest, const void *src, int len)
{
  char *d = dest;
  const char *s = src;
  int i;

  for (i = 0; i < len; i++)
    {
      d[i] = s[len - i - 1];
    }
}

void
gdbserv_be_bytes_to_reg (struct gdbserv *gdbserv,
		         const void *buf,
		         int buflen,
		         struct gdbserv_reg *reg,
			 int reglen,
			 int sign_extend)
{
  int bufoffset = 0;
  int regoffset = 0;
  int len = buflen;

  reg->negative_p = 0;
  reg->len = reglen;

  if (reglen > buflen)
    {
      memset (reg->buf,
              (sign_extend && (((char *) buf)[0] & 0x80)) ? 0xff : 0,
	      reglen - buflen);
      regoffset = reglen - buflen;
    }

  if (buflen > reglen)
    {
      bufoffset = buflen - reglen;
      len = reglen;
    }

  memcpy (reg->buf + regoffset, (char *)buf + bufoffset, len);
}

void
gdbserv_be_bytes_from_reg (struct gdbserv *gdbserv,
		           void *buf,
		           int buflen,
                           const struct gdbserv_reg *reg,
			   int sign_extend)
{
  int bufoffset = 0;
  int regoffset = 0;
  int len = reg->len;

  if (reg->len > buflen)
    {
      regoffset = reg->len - buflen;
      len = buflen;
    }

  if (buflen > reg->len)
    {
      memset (buf,
              (sign_extend && (reg->buf[0] & 0x80)) ? 0xff : 0,
	      buflen - reg->len);
      bufoffset = buflen - reg->len;
    }

  memcpy ((char *)buf + bufoffset, reg->buf + regoffset, len);
}

void
gdbserv_le_bytes_to_reg (struct gdbserv *gdbserv,
		         const void *buf,
		         int buflen,
		         struct gdbserv_reg *reg,
			 int reglen,
			 int sign_extend)
{
  int regoffset = 0;
  int len = buflen;

  reg->negative_p = 0;
  reg->len = reglen;

  if (reglen > buflen)
    {
      memset (reg->buf,
              (sign_extend && (((char *) buf)[buflen - 1] & 0x80)) ? 0xff : 0,
	      reglen - buflen);
      regoffset = reglen - buflen;
    }

  if (buflen > reglen)
      len = reglen;

  reverse_copy_bytes (reg->buf + regoffset, buf, len);
}

void
gdbserv_le_bytes_from_reg (struct gdbserv *gdbserv,
		           void *buf,
		           int buflen,
                           const struct gdbserv_reg *reg,
			   int sign_extend)
{
  int bufoffset = 0;
  int regoffset = 0;
  int len = reg->len;

  if (reg->len > buflen)
    {
      regoffset = reg->len - buflen;
      len = buflen;
    }

  if (buflen > reg->len)
    {
      memset ((char *)buf + reg->len,
              (sign_extend && (reg->buf[reg->len - 1] & 0x80)) ? 0xff : 0,
	      buflen - reg->len);
    }

  reverse_copy_bytes (buf, reg->buf + regoffset, reg->len);
}

void
gdbserv_host_bytes_to_reg (struct gdbserv *gdbserv,
		           const void *buf,
		           int buflen,
		           struct gdbserv_reg *reg,
			   int reglen,
			   int sign_extend)
{
#ifdef WORDS_BIGENDIAN
  gdbserv_be_bytes_to_reg (gdbserv, buf, buflen, reg, reglen, sign_extend);
#else
  gdbserv_le_bytes_to_reg (gdbserv, buf, buflen, reg, reglen, sign_extend);
#endif
}

void
gdbserv_host_bytes_from_reg (struct gdbserv *gdbserv,
		             void *buf,
		             int buflen,
                             const struct gdbserv_reg *reg,
			     int sign_extend)
{
#ifdef WORDS_BIGENDIAN
  gdbserv_be_bytes_from_reg (gdbserv, buf, buflen, reg, sign_extend);
#else
  gdbserv_le_bytes_from_reg (gdbserv, buf, buflen, reg, sign_extend);
#endif
}
