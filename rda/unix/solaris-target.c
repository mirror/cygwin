/* solaris-target.c

   Copyright 2000, 2002 Red Hat, Inc.

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
#include <assert.h>
#include <stdlib.h>

#include "gdbserv.h" 
#include "gdbserv-target.h" 
#include "gdbserv-utils.h"

#include "server.h"

/* This is a Solaris native gdbserv target that uses the RDA library to
   implement a remote gdbserver on a solaris host.  It controls the
   process to be debugged on the solaris host, allowing GDB to pull the
   strings from any host on the network (or on a serial port).  */



/* Track sole connection to a remote gdb client. */
/* FIXME: needed? */
static struct gdbserv *solaris_connect_lock = NULL;



/* target vector: */

/* private sub-vector for dummy target: */
static struct gdbserv_target *dummy_target;	/* FIXME global */

/* Detach vector -- shut down this target connection.
 */

static void
solaris_detach (struct gdbserv *serv, struct gdbserv_target *target)
{
  assert (solaris_connect_lock == serv);

  dummy_target->detach (serv);
  fprintf (stderr, "linux - detached.\n");
  solaris_connect_lock = NULL;

  /* Quit out of main loop for this demo.  In general, this is not
     necessary, as the next incoming connection could again be handled
     by solaris_attach() above.  */
  server_quit_p = 1;
}

/* fetch registers vector.

   NOTE: registers do not generalize well in ptrace, so
   we're gonna handle them separately per target.

   */

static int
solaris_process_get_reg (struct gdbserv *serv, int regno)
{
  if (dummy_target->get_reg)
    return dummy_target->process_get_reg (serv, regno);
}

static void
solaris_process_get_regs (struct gdbserv *serv)
{
  dummy_target->process_get_regs (serv);
}

static int
solaris_process_set_reg (struct gdbserv *serv, int regno)
{
  if (dummy_target->set_reg)
  return dummy_target->process_set_reg (serv, regno);
}

static int
solaris_process_set_regs (struct gdbserv *serv)
{
  return dummy_target->process_set_regs (serv);
}



/* This function is called from gdbloop_poll() when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted.  */

struct gdbserv_target *
solaris_attach (struct gdbserv *serv, void *data)
{
  struct gdbserv_target *solaris_target;
  struct child_process *process = data;
  extern struct gdbserv_target *dummy_attach (struct gdbserv *, void *);

  /* Enable server tracing. */
  /*  gdbserv_state_trace = stderr;*/

  if (solaris_connect_lock != NULL)
    {
      fprintf (stderr, "linux: rejected duplicate connection.\n");
      return NULL;
    }

  if ((dummy_target = dummy_attach (serv, data)) == NULL)
    {
      fprintf (stderr, "Linux: unable to open %s\n", process->argv[0]);
      return NULL;
    }

  fprintf (stderr, "linux: accepted gdb connection.\n");
  solaris_connect_lock = serv;

  solaris_target = malloc (sizeof (struct gdbserv_target));
  memset (solaris_target, 0, sizeof (*solaris_target));

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  solaris_target->process_get_gen       = NULL;
  solaris_target->process_set_gen       = NULL;
  solaris_target->process_rcmd          = NULL;
  solaris_target->process_set_args      = NULL;
  solaris_target->process_set_reg       = NULL;
  solaris_target->process_get_reg       = NULL;
  solaris_target->process_set_regs      = solaris_process_set_regs;
  solaris_target->process_get_regs      = solaris_process_get_regs;
  solaris_target->input_reg             = NULL;
  solaris_target->output_reg            = NULL;
  solaris_target->gg_reg_nr             = NULL;
  solaris_target->expedited_reg_nr      = NULL;
  solaris_target->sizeof_reg            = NULL;
  solaris_target->set_reg               = NULL;
  solaris_target->get_reg               = NULL;
  solaris_target->get_mem               = dummy_target->get_mem;
  solaris_target->set_mem               = dummy_target->set_mem;
  solaris_target->process_set_pc        = NULL;
  solaris_target->flush_i_cache         = dummy_target->flush_i_cache;
  solaris_target->process_signal        = dummy_target->process_signal;
  solaris_target->compute_signal        = dummy_target->compute_signal;
  solaris_target->get_trap_number       = dummy_target->get_trap_number;
  solaris_target->exit_program          = dummy_target->exit_program;
  solaris_target->break_program         = dummy_target->break_program;
  solaris_target->reset_program         = NULL;
  solaris_target->restart_program       = NULL;
  solaris_target->singlestep_program    = dummy_target->singlestep_program;
  solaris_target->cyclestep_program     = NULL;
  solaris_target->sigkill_program       = NULL;
  solaris_target->continue_program      = dummy_target->continue_program;
  solaris_target->remove_breakpoint     = NULL;
  solaris_target->set_breakpoint        = NULL;
  solaris_target->process_target_packet = NULL;
  solaris_target->detach                = solaris_detach;

  solaris_target->data = data;
  process->serv = serv;
  return solaris_target;
}

static int
solaris_check_child_state (struct child_process *process)
{
  return dummy_check_child_state (process);
}

static void
solaris_fromtarget_break (struct child_process *process)
{
  gdbserv_fromtarget_break (process->serv, process->stop_signal);
}

static void
solaris_fromtarget_exit (struct child_process *process)
{
  gdbserv_fromtarget_exit (process->serv, process->stop_signal);
}

static void
solaris_fromtarget_terminate (struct child_process *process)
{
  gdbserv_fromtarget_terminate (process->serv, process->stop_signal);
}

/* This struct contains the vectors that connect us to main:
 */
struct server_vector gdbserver = 
{
  solaris_attach, 
  solaris_check_child_state, 
  solaris_fromtarget_break, 
  solaris_fromtarget_exit,
  solaris_fromtarget_terminate
};
