/*
 * gdbserv-utils.h -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


/* Return the ASCII equivalent of C (C>=0 && C<=15). The result will be 
   lower-case. */

extern unsigned char gdbserv_to_hex (int c);
extern int gdbserv_hex_to (unsigned char c);

extern unsigned int gdbserv_ulong_to_hex (char *ptr, unsigned long val, int num_bits);


extern unsigned int gdbserv_raw_to_hex (char **ptr, char *mem, int nr_bytes);

extern unsigned int gdbserv_reg_to_hex (char **ptr, struct gdbserv_reg *reg);

extern unsigned int gdbserv_reg_to_ulong (struct gdbserv *gdbserv, struct gdbserv_reg *reg, unsigned long *val);

extern unsigned int gdbserv_reg_to_ulonglong (struct gdbserv *gdbserv, struct gdbserv_reg *reg, unsigned long long *val);

