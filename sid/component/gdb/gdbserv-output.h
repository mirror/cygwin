/*
 * gdbserv-output.h -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */

struct gdbserv_output {
  
  /* serial data */
  int len;
  char buf[2048];
  /* additional space incase the checksum overflows the buf */
  char padding_for_checksum[3];
};

void gdbserv_output_attach (struct gdbserv *gdbserv);
void gdbserv_output_detach (struct gdbserv *gdbserv);

void gdbserv_output_packet (struct gdbserv *gdbserv);
void gdbserv_output_discard (struct gdbserv *gdbserv);
