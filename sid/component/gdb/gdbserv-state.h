/*
 * gdbserv-state.h -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */

#include "gdbserv-input.h"
#include "gdbserv-output.h"
#include "gdbserv-client.h"
#include "gdbserv-target.h"

enum gdbserv_state {
  GDBSERV_STATE_UNINITIALIZED = 0,
  GDBSERV_STATE_RESETTING,
  GDBSERV_STATE_STUMBLING,
  GDBSERV_STATE_STEPPING,
  GDBSERV_STATE_RUNNING,
  GDBSERV_STATE_BROKEN,
  GDBSERV_STATE_EXITING,
  GDBSERV_STATE_EXITED,
};

struct gdbserv {

  struct gdbserv_input input;
  struct gdbserv_output output;
  struct gdbserv_target *target;
  struct gdbserv_client *client;

  enum gdbserv_state state;

  /* argv */
  char **program_argv;
  unsigned long program_argc;
  unsigned long last_arg_len;
  unsigned long last_arg_num;
  
};


/* Present an unpacked packet to the gdbserv state machine */
void gdbserv_data_packet (struct gdbserv *gdbserv);
