/*
 * gdbserv-client.h -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */

struct gdbserv_client {
  void *data;
  void (*write) (struct gdbserv *gdbserv, const unsigned char *ch, unsigned len);
};

void *gdbserv_client_data (struct gdbserv *gdbserv);

