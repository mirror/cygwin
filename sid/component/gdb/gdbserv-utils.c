/*
 * gdbserv-utils.c -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


#include <stdio.h>

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
      *(*ptr)++ = gdbserv_to_hex (*mem);
    }
  return i;
}

unsigned int
gdbserv_reg_to_hex (char **ptr, struct gdbserv_reg *reg)
{
  return gdbserv_raw_to_hex (ptr, &reg->buf[0], reg->len);
}


unsigned int
gdbserv_reg_to_ulong (struct gdbserv *gdbserv,
		      struct gdbserv_reg *reg,
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
  return 0;
}


unsigned int
gdbserv_reg_to_ulonglong (struct gdbserv *gdbserv,
			  struct gdbserv_reg *reg,
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
  return 0;
}
