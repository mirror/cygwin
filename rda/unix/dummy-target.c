/* dummy-target.c

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

/* This is a sample gdbserv target that demonstrates use of the RDA
   library routines.  It acts to gdb like a strange generic remote target. */

 /* process_get_gen */
 /* process_set_gen */
static void server_process_rcmd (struct gdbserv* serv, 
				const char* cmd, int sizeof_cmd);
 /* process_set_args */
 /* process_set_reg */
static int  server_process_set_regs (struct gdbserv* serv);
static void server_process_get_regs (struct gdbserv* serv);
 /* input_reg */
 /* output_reg */
 /* gg_reg_nr */
 /* expedited_reg_nr */
 /* sizeof_reg */
 /* set_reg */
 /* get_reg */
static long server_get_mem (struct gdbserv* serv, 
			   struct gdbserv_reg* addr, 
			   void* data, 
			   long len);
static long server_set_mem (struct gdbserv* serv, 
			   struct gdbserv_reg* addr, 
			   void* data, 
			   long len);
 /* process_set_pc */
 /* process_signal */
static void server_flush_i_cache (struct gdbserv* serv);
static unsigned long server_compute_signal (struct gdbserv* serv, 
					   unsigned long);
static unsigned long server_get_trap_number (struct gdbserv* serv);
static void server_exit_program (struct gdbserv* serv);
static void server_break_program (struct gdbserv* serv);
static int  server_reset_program (struct gdbserv* serv);
static void server_restart_program (struct gdbserv* serv);
static void server_singlestep_program (struct gdbserv* serv);
static void server_cyclestep_program (struct gdbserv* serv);
static void server_sigkill_program (struct gdbserv* serv);
static void server_continue_program (struct gdbserv* serv);
 /* remove_breakpoint */
 /* set_breakpoint */
 /* process_target */
static void server_detach (struct gdbserv* serv, struct gdbserv_target* target);





int server_ticks_before_break_p = 0;

/* Track sole connection to a remote gdb client. */
static struct gdbserv* sole_connection = NULL;

/* This function is called from gdbloop_poll() when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted. */
struct gdbserv_target* 
dummy_attach (struct gdbserv* serv, void* context)
{
  struct gdbserv_target *target;
  /* Enable server tracing. */
  gdbserv_state_trace = stderr;
  /* gdbserv_input_trace = stderr; */
  /* gdbserv_output_trace = stderr; */

  if (sole_connection != NULL)
    {
      fprintf (stderr, "Rejected duplicate connection.\n");
      return NULL;
    }

  fprintf (stderr, "Accepted gdb connection.\n");
  sole_connection = serv;

  target = malloc (sizeof (struct gdbserv_target));
  memset (target, 0, sizeof (*target));

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  target->process_get_gen       = NULL;
  target->process_set_gen       = NULL;
  target->process_rcmd          = server_process_rcmd;
  target->process_set_args      = NULL;
  target->process_set_reg       = NULL;
  target->process_get_reg       = NULL;
  target->process_set_regs      = server_process_set_regs /* (deprecated) */;
  target->process_get_regs      = server_process_get_regs /* (deprecated) */;
  target->input_reg             = NULL;
  target->output_reg            = NULL;
  target->gg_reg_nr             = NULL;
  target->expedited_reg_nr      = NULL;
  target->sizeof_reg            = NULL;
  target->set_reg               = NULL;
  target->get_reg               = NULL;
  target->get_mem               = server_get_mem;
  target->set_mem               = server_set_mem;
  target->process_set_pc        = NULL;
  target->flush_i_cache         = server_flush_i_cache;
  target->process_signal        = NULL;
  target->compute_signal        = server_compute_signal;
  target->get_trap_number       = server_get_trap_number;
  target->exit_program          = server_exit_program;
  target->break_program         = server_break_program;
  target->reset_program         = server_reset_program;
  target->restart_program       = server_restart_program;
  target->singlestep_program    = server_singlestep_program;
  target->cyclestep_program     = server_cyclestep_program;
  target->sigkill_program       = server_sigkill_program;
  target->continue_program      = server_continue_program;
  target->remove_breakpoint     = NULL;
  target->set_breakpoint        = NULL;
  target->process_target_packet = NULL;
  target->detach                = server_detach;

  /* DATA can be assigned any value.  That value is accessible via
     gdbserv_target_data().  This example just happens to use
     CONTEXT. */
  target->data = context;

  return target;
}

static void
server_detach (struct gdbserv* serv, struct gdbserv_target* target)
{
  assert (serv == sole_connection);

  fprintf (stderr, "Detached.\n");
  sole_connection = NULL;

  /* Quit out of main loop for this demo.  In general, this is not
     necessary, as the next incoming connection could again be handled
     by server_attach() above.  */
  server_quit_p = 1;
}



static unsigned long
server_get_trap_number (struct gdbserv* serv)
{
  /* Return a target-dependent trap number. */
  return 0;
}


static unsigned long
server_compute_signal (struct gdbserv* serv, unsigned long tgtsig)
{
  assert (tgtsig == 0); /* comes from get_trap_number above */
  /* Return standard signal number */
  return GDBSERV_SIGTRAP;
}


static void
server_process_rcmd (struct gdbserv* serv, const char* cmd, int sizeof_cmd)
{
  gdbserv_output_bytes (serv, cmd, sizeof_cmd);
}

/*
 * Get/Set Registers
 * 
 * (including a primitive register cache) 
 */

static struct target_regs {	/* register cache */
  unsigned int len;
  unsigned char buf[180];
} target_regs;

static void 
server_process_get_regs (struct gdbserv* serv)
{
  int i;

  for (i=0; i<180; i++) /* 180 bytes < gdb's PBUFSIZ/2 */
    gdbserv_output_byte (serv, target_regs.buf[i]);
}

static int 
server_process_set_regs (struct gdbserv *serv)
{
  gdbserv_input_bytes (serv, (char *) &target_regs.buf, 
		       sizeof (target_regs.buf));
  return 0;
}

static void
server_exit_program (struct gdbserv* serv)
{
  gdbserv_fromtarget_exit (serv, GDBSERV_SIGQUIT);
}

static void
server_break_program (struct gdbserv* serv)
{
  /* Enqueue a break response */
  server_ticks_before_break_p = 1;
}

static int
server_reset_program (struct gdbserv* serv)
{
  gdbserv_fromtarget_reset (serv);
  return 0;
}

static void
server_restart_program (struct gdbserv* serv)
{
  /* Enqueue a break response */
  server_ticks_before_break_p = 1;
}


static void
server_singlestep_program (struct gdbserv* serv)
{
  /* Enqueue a break response */
  server_ticks_before_break_p = 2;
}

static void
server_cyclestep_program (struct gdbserv* serv)
{
  /* Enqueue a break response */
  server_ticks_before_break_p = 1;
}

static void
server_sigkill_program (struct gdbserv* serv)
{
  gdbserv_fromtarget_exit (serv, GDBSERV_SIGKILL);
}

static void 
server_continue_program (struct gdbserv* serv)
{
  fprintf (stderr, "Resumed fictional target program - send break from gdb or wait a while.\n");
  /* Enqueue a break response */
  server_ticks_before_break_p = 10;
}

/*
 * Get/Set memory
 *
 * (including a primitive memory cache)
 */

static struct target_mem {	/* memory cache */
  unsigned long base;
  unsigned long len;
  unsigned char *buf;
} target_mem;

static long
server_get_mem (struct gdbserv* serv, 
	      struct gdbserv_reg* addr, 
	      void* data, 
	      long len)
{
  long n;
  unsigned char *d = data;
  unsigned long request_base;

  gdbserv_reg_to_ulong (serv, addr, &request_base);

  for (n=0; n<len; n++)
    {
      if (request_base + n >= target_mem.base &&
	  request_base + n <  target_mem.base + target_mem.len)
	*d++ = target_mem.buf[request_base + n - target_mem.base];
      else
	*d++ = 0;
    }

  return n;
}

static long
server_set_mem (struct gdbserv* serv, 
	      struct gdbserv_reg* addr, 
	      void* data, 
	      long len)
{
  unsigned long request_base;

  gdbserv_reg_to_ulong (serv, addr, &request_base);
  if (target_mem.len == 0)
    {
      target_mem.buf  = malloc (len);
      target_mem.len  = len;
      gdbserv_reg_to_ulong (serv, addr, &target_mem.base);
    }
  else
    {
      if (request_base < target_mem.base)
	{
	  target_mem.len += target_mem.base - request_base;
	  target_mem.base = request_base;
	  target_mem.buf  = realloc (target_mem.buf, target_mem.len);
	}
      if (request_base + len > 
	  target_mem.base + target_mem.len)
	{
	  target_mem.len += 
	    (request_base + len) - (target_mem.base + target_mem.len);
	  target_mem.buf  = realloc (target_mem.buf, target_mem.len);
	}
    }

  memcpy (target_mem.buf + (request_base - target_mem.base), 
	  data, 
	  len);
  return  len;
}


static void
server_flush_i_cache (struct gdbserv* serv)
{
}


int
dummy_check_child_state (struct nativeserver *process)
{
  return 0; 	/* simulate an event right away */
}

void
dummy_break ()
{
  gdbserv_fromtarget_break (sole_connection, GDBSERV_SIGTRAP);
}


void
dummy_exit ()
{
  gdbserv_fromtarget_exit (sole_connection, GDBSERV_SIGTRAP);
}


