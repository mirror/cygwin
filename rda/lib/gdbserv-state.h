/* gdbserv-state.h

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

/* GDBSERV internal data structures.  */

/* Clients/targets SHOULD NOT include this file!!!! */


#ifdef __cplusplus
extern "C" {
#endif

#include "gdbserv-input.h"
#include "gdbserv-output.h"
#include "gdbserv-client.h"
#include "gdbserv-target.h"

/* The server's current state. */

enum gdbserv_state {
  GDBSERV_STATE_UNINITIALIZED = 0,
  GDBSERV_STATE_RESETTING,
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

  /* Several GDBSERV objects for a stack of targets (well,
     technically, they right now form a cycle).  These links take you
     closer TO and further FROM the target. */
  struct gdbserv *to;
  struct gdbserv *from;

  enum gdbserv_state state;

  /* The thread (and signal) that were supplied by the target for the
     event that triggered the stop. */
  struct gdbserv_thread *event_thread;
  int event_sigval;

  /* The thread for examining current state. */
  struct gdbserv_thread *general_thread;

  /* The thread to resume.  If NULL, the entire system is resumed. */
  struct gdbserv_thread *continue_thread;

  /* Selected thread for thread query. */
  struct gdbserv_thread *query_thread;

  /* argv */
  char **program_argv;
  unsigned long program_argc;
  unsigned long last_arg_len;
  unsigned long last_arg_num;
  
};


/* Present an unpacked packet to the gdbserv state machine */
void gdbserv_data_packet (struct gdbserv *gdbserv);

#ifdef __cplusplus
}
#endif
