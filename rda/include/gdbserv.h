/* gdbserv.h

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

#ifdef __cplusplus
extern "C" {
#elif 0
}
#endif

struct gdbserv;

/* A ``struct gdbserv_reg'' is an object for storing an arbitrary
   numeric value in a system independant way.  Part of an input packet
   will be parsed into a REG object (using gdbserv_input_reg_...) and
   then later converted into a specific value (using
   gdbserv_reg_to_...).  The bytes in BUF are always ordered
   big-endian. */

enum {
  GDBSERV_REG_SIZE = 16 /* space for a 128-bit quantity */
};
struct gdbserv_reg {
  int negative_p;
  int len;
  unsigned char buf[GDBSERV_REG_SIZE];
};



/* Fetch data from the current input packet.
   Return -1 on error. */


/* Number of characters remaining in input packet */
int gdbserv_input_size (struct gdbserv *gdbserv);

/* NIBBLE: 4 bit quantity represented by a single HEX digit.
   BYTE: 8 bit quantity represented by two HEX digits. */
int gdbserv_input_nibble (struct gdbserv *gdbserv);
int gdbserv_input_byte (struct gdbserv *gdbserv);

/* BYTES: LEN 8 bit stream represented by LEN*2 HEX digits.
   BINARY: LEN 8 bit stream represented by LEN bytes + escape characters */
int gdbserv_input_bytes (struct gdbserv *gdbserv, char *buf, int len);
int gdbserv_input_escaped_binary (struct gdbserv *gdbserv, char *buf, int len);

/* Next character/string in packet.  Return -1 on error. */
int gdbserv_input_peek (struct gdbserv *gdbserv);
int gdbserv_input_char (struct gdbserv *gdbserv);
int gdbserv_input_string (struct gdbserv *gdbserv, char *buf, int len);

/* Peek at input packet comparing next few characters against STRING.
   Return -1 on non or partial match.  Return strlen (STRING) on full
   match and skip corresponding number of characters in input
   packet. */
int gdbserv_input_string_match (struct gdbserv *gdbserv, const char *string);

/* Set VAL to a SMALL (unsigned) integer encoded in (network byte
   ordered) HEX.  Return a negative value if there is a parse
   error. */
int gdbserv_input_hex_long (struct gdbserv *gdbserv, long *val);
int gdbserv_input_hex_ulong (struct gdbserv *gdbserv, unsigned long *val);

/* Parse a HEX value of almost arbitrary length into the ``struct
   gdbserv_reg''.  When BYTE_LEN is zero, it may include a leading
   minus sign. When BYTE_LEN is non-zero it indicates the exact number
   of RAW BYTES (HEX digits / 2) that should be transfered to
   REG. ..._hex_beb () expects a true big-endian hex value.
   ..._hex_leb () expects a hybrid little-endian hex value - the bytes
   are ordered little-endian but the hex encoded nibble-pair that make
   up a byte is ordered big endian (ex: 0x12345678 is leb encoded as
   78563412). */
int gdbserv_input_reg_beb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);
int gdbserv_input_reg_leb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);


/* Write data to the current output packet. */


/* Integer values converted to HEX. */
void gdbserv_output_nibble (struct gdbserv *gdbserv, int h);
void gdbserv_output_byte (struct gdbserv *gdbserv, int h);
void gdbserv_output_bytes (struct gdbserv *gdbserv, const char *buf, unsigned sizeof_buf); 

/* Character values output verbatum. */
void gdbserv_output_char (struct gdbserv *gdbserv, char c);
void gdbserv_output_string (struct gdbserv *gdbserv, const char *buf);
void gdbserv_output_string_as_bytes (struct gdbserv *gdbserv, const char *buf);


/* Output a HEX value of almost arbitrary length in ``struct
   gdbserv_reg''.  May include a leading minus sign.  When BYTE_LEN is
   non-zero this specifies the exact number of RAW bytes (two HEX
   characters per byte) that should be output. */
/* FIXME: Can't have both a leading minus sign and a non-zero
   BYTE_LENGTH. */
void gdbserv_output_reg_beb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);
void gdbserv_output_reg_leb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);

#ifdef __cplusplus
}
#endif
