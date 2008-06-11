/* demo-target.c

   Copyright 2000, 2001, 2002 Red Hat, Inc.

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
#include <string.h>
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif

#include "gdbserv.h" 
#include "gdbserv-target.h" 
#include "gdbserv-utils.h"

#include "demo-target.h"
#include "gdbsched.h"

/* This is a sample gdbserv target that demonstrates use of the RDA library
   routines.  It acts to gdb like a strange generic remote target. */

 /* process_get_gen */
 /* process_set_gen */
static void demo_process_rcmd (struct gdbserv* serv, const char* cmd, int sizeof_cmd);
 /* process_set_args */
 /* process_set_reg */
static int  demo_process_set_regs (struct gdbserv *serv);
static void demo_process_get_regs (struct gdbserv* serv);
 /* input_reg */
 /* output_reg */
 /* gg_reg_nr */
 /* expedited_reg_nr */
 /* sizeof_reg */
 /* set_reg */
 /* get_reg */
static long demo_get_mem (struct gdbserv* serv, struct gdbserv_reg* addr, void* data, long len);
static long demo_set_thread_mem (struct gdbserv *serv,
				 struct gdbserv_thread *thread,
				 struct gdbserv_reg *addr,
				 void *data, long len);
static void demo_process_set_pc (struct gdbserv *gdbserv,
				 const struct gdbserv_reg *pc);
 /* process_signal */
static void demo_flush_i_cache (struct gdbserv* serv);
static unsigned long demo_compute_signal (struct gdbserv* serv, unsigned long);
static unsigned long demo_get_trap_number (struct gdbserv* serv);
static void demo_exit_program (struct gdbserv* serv);
static void demo_break_program (struct gdbserv* serv);
static int demo_reset_program (struct gdbserv* serv);
static void demo_restart_program (struct gdbserv* serv);
static void demo_singlestep_program (struct gdbserv* serv);
static void demo_cyclestep_program (struct gdbserv* serv);
static void demo_sigkill_program (struct gdbserv* serv);
static void demo_continue_thread (struct gdbserv *serv,
				  struct gdbserv_thread *thread,
				  const struct gdbserv_reg *sigval);
 /* remove_breakpoint */
 /* set_breakpoint */
 /* process_target */
static void demo_detach (struct gdbserv* serv, struct gdbserv_target* target);





/* Signal a request to terminate main loop. */
int demo_quit_p = 0;

/* Simple minded event handler to dispatch break events after an
   arbitrary time. */

static void
dispatch_break (struct gdbserv *gdbserv,
		struct gdbserv_thread *thread,
		void *context)
{
  /* THREAD is probably NULL.  Since we don't know what thread we
     "stopped" in, we'll let the RDA library figure it out. */
  gdbserv_fromtarget_thread_break (gdbserv, thread, GDBSERV_SIGTRAP);
}

static void
sched_break (struct gdbserv *serv, long timeout)
{
  static struct gdbsched *break_event = NULL;
  long sched_time;
  assert (timeout >= 0);
  /* Re-schedule the event being careful to not zap the ``NULL''
     event. */
  if (break_event != NULL)
    gdbsched_deschedule (break_event, NULL, NULL, NULL, NULL, NULL);
  /* If the timeout is ZERO don't use time() to compute the time that
     the event should be scheduled.  Instead, force it to NOW.  There
     could easily be a skew between the time() call below and the
     event loops current time.  That in turn can cause ``NOW'' to be
     scheduled in a second or more.... */
  if (timeout == 0)
    sched_time = 0;
  else
    sched_time = time (NULL) + timeout;
  break_event = gdbsched_schedule (sched_time, dispatch_break,
				   serv, NULL, NULL);
}

static void
demo_process_set_gen (struct gdbserv *serv)
{
  if (demo_set_gen_hook)
    demo_set_gen_hook (serv);
}

/* Track sole connection to a remote gdb client. */
static struct gdbserv* sole_connection = NULL;

struct gdbserv_target *
demo_target (struct gdbserv *serv, void *context)
{
  static struct gdbserv_target *target = NULL;

  if (sole_connection != NULL)
    {
      fprintf (stderr, "Rejected duplicate connection.\n");
      return NULL;
    }

  fprintf (stderr, "Accepted gdb connection.\n");
  sole_connection = serv;

  if (target == NULL)
    target = malloc (sizeof (struct gdbserv_target));
  memset (target, sizeof (*target), 0);

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  target->process_get_gen = NULL;
  target->process_set_gen = demo_process_set_gen;
  target->process_rcmd = demo_process_rcmd;
  target->process_set_args = NULL;
  target->process_set_reg = NULL;
  target->process_get_reg = NULL;
  target->process_set_regs = demo_process_set_regs /* <deprecated?> */;
  target->process_get_regs = demo_process_get_regs /* (deprecated) */;
  target->input_reg = NULL;
  target->output_reg = NULL;
  target->gg_reg_nr = NULL;
  target->expedited_reg_nr = NULL;
  target->sizeof_reg = NULL;
  target->set_reg = NULL;
  target->get_reg = NULL;
  target->get_mem = demo_get_mem;
  target->set_thread_mem = demo_set_thread_mem;
  target->process_set_pc = demo_process_set_pc;
  target->flush_i_cache = demo_flush_i_cache;
  target->process_signal = NULL;
  target->compute_signal = demo_compute_signal;
  target->get_trap_number = demo_get_trap_number;
  target->exit_program = demo_exit_program;
  target->break_program = demo_break_program;
  target->reset_program = demo_reset_program;
  target->restart_program = demo_restart_program;
  target->singlestep_program = demo_singlestep_program;
  target->cyclestep_program = demo_cyclestep_program;
  target->sigkill_program = demo_sigkill_program;
  target->continue_thread = demo_continue_thread;
  target->remove_breakpoint = NULL;
  target->set_breakpoint = NULL;
  target->process_target_packet = NULL;
  target->detach = demo_detach;

  /* DATA can be assigned any value.  That value is accessible via
     gdbserv_target_data().  This example just happens to use
     CONTEXT. */
  target->data = context;

  return target;
}

/* This function is called from gdbloop_poll when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted.  The helper function do_fromtarget_ready() is to notify
   the server that the target has finished initializing and is ready
   to talk to GDB.  */

static void
do_fromtarget_ready (struct gdbserv *gdbserv,
		     struct gdbserv_thread *ignore2,
		     void *ignore3)
{
  gdbserv_fromtarget (gdbserv, NULL, GDBSERV_FROMTARGET_STOPPED, NULL, 0);
}

struct gdbserv_target * 
demo_attach (struct gdbserv *serv, void *context)
{
  struct gdbserv_target *target = demo_target (serv, context);
  if (target == NULL)
    return NULL;
  /* Take the target out of reset. */
  gdbsched_schedule (0, do_fromtarget_ready, serv, NULL, NULL);
  return target;
}


void
demo_detach (struct gdbserv* serv, struct gdbserv_target* target)
{
  assert (serv == sole_connection);

  fprintf (stderr, "Detached.\n");
  sole_connection = NULL;

  /* Quit out of main loop for this demo.  In general, this is not necessary, as the
     next incoming connection could again be handled by demo_attach() above. */
  demo_quit_p = 1;
}



unsigned long
demo_get_trap_number (struct gdbserv* serv)
{
  /* Return a target-dependent trap number. */
  return 0;
}


unsigned long
demo_compute_signal (struct gdbserv* serv, unsigned long tgtsig)
{
  assert (tgtsig == 0); /* comes from get_trap_number above */
  /* Return standard signal number */
  return GDBSERV_SIGTRAP;
}


void
demo_process_rcmd (struct gdbserv* serv, const char* cmd, int sizeof_cmd)
{
  gdbserv_output_bytes (serv, cmd, sizeof_cmd);
}


/*
 * Get/Set Registers
 * 
 * (including a primitive register cache) 
 */

#define TARGET_REGBUF_SIZE 312

static struct target_regs {	/* register cache */
  unsigned int len;
  char buf[TARGET_REGBUF_SIZE];
} target_regs;

static void 
demo_process_get_regs (struct gdbserv* serv)
{
  int i;

  if (demo_get_regs_hook)
    {
      demo_get_regs_hook (serv);
      return;
    }
  for (i=0; i<TARGET_REGBUF_SIZE; i++)
    gdbserv_output_byte (serv, target_regs.buf[i]);
}

static int 
demo_process_set_regs (struct gdbserv *serv)
{
  gdbserv_input_bytes (serv, &target_regs.buf[0], sizeof (target_regs.buf));
  return 0;
}

void
demo_exit_program (struct gdbserv* serv)
{
  gdbserv_fromtarget_exit (serv, GDBSERV_SIGQUIT);
}

void
demo_break_program (struct gdbserv* serv)
{
  fprintf (stderr, "<BREAK>\n");
  /* Enqueue a break response NOW */
  sched_break (serv, 0);
}

int
demo_reset_program (struct gdbserv* serv)
{
  gdbserv_fromtarget_reset (serv);
  return 0;
}

void
demo_restart_program (struct gdbserv* serv)
{
  sched_break (serv, 1);
}


void
demo_singlestep_program (struct gdbserv* serv)
{
  sched_break (serv, 2);
}

void
demo_cyclestep_program (struct gdbserv* serv)
{
  sched_break (serv, 1);
}

void
demo_sigkill_program (struct gdbserv* serv)
{
  gdbserv_fromtarget_exit (serv, GDBSERV_SIGKILL);
}

void
demo_continue_thread (struct gdbserv *serv,
		      struct gdbserv_thread *thread,
		      const struct gdbserv_reg *sigval)
{
  fprintf (stderr, "Resumed fictional target program - send break from gdb or wait a while.\n");
  /* Enqueue a break response */
  sched_break (serv, 10);
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
demo_get_mem (struct gdbserv* serv, 
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
      if (demo_get_mem_hook)
	*d++ = demo_get_mem_hook (request_base + n);
      else if (request_base + n >= target_mem.base &&
	       request_base + n <  target_mem.base + target_mem.len)
	*d++ = target_mem.buf[request_base + n - target_mem.base];
      else
	*d++ = 0;
    }

  return n;
}

#define ALLOC_UNIT  0x1000
#define alloc_roundup(LEN) ((((LEN)+ALLOC_UNIT-1) / ALLOC_UNIT) * ALLOC_UNIT)
  

static long
demo_set_thread_mem (struct gdbserv *serv, 
		     struct gdbserv_thread *thread,
		     struct gdbserv_reg *addr, 
		     void *data, 
		     long len)
{
  unsigned long request_base;

  gdbserv_reg_to_ulong (serv, addr, &request_base);
  if (target_mem.len == 0)
    {
      target_mem.len  = alloc_roundup (len);
      target_mem.buf  = malloc (target_mem.len);
      target_mem.base = request_base;
    }
  else
    {
      if (request_base < target_mem.base)
	{
	  unsigned long oldlen = target_mem.len;
	  unsigned long movlen = target_mem.base - request_base;

	  target_mem.len += alloc_roundup (target_mem.base - request_base);
	  target_mem.base = request_base;
	  target_mem.buf  = realloc (target_mem.buf, target_mem.len);
	  memmove (target_mem.buf + movlen, target_mem.buf, oldlen);
	}
      if (request_base + len > 
	  target_mem.base + target_mem.len)
	{
	  target_mem.len += alloc_roundup ((request_base + len) - 
					   (target_mem.base + target_mem.len));
	  target_mem.buf  = realloc (target_mem.buf, target_mem.len);
	}
    }

  if (target_mem.buf == NULL)
    return 0;

  memcpy (target_mem.buf + (request_base - target_mem.base), 
	  data, 
	  len);
  return  len;
}


void
demo_process_set_pc (struct gdbserv *gdbserv, const struct gdbserv_reg *pc)
{
  unsigned long addr;
  gdbserv_reg_to_ulong (gdbserv, pc, &addr);
  fprintf (stderr, "demo target pc set to 0x%lx\n", addr);
}


void
demo_flush_i_cache (struct gdbserv* serv)
{
}
