/* thread.c

   Copyright 2001, 2002 Red Hat, Inc.

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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "gdbserv.h"
#include "gdbserv-utils.h"
#include "gdbserv-target.h"
#include "gdbserv-log.h"
#include "gdbsocket.h"
#include "gdbsched.h"
#include "gdbloop.h"
#include "stdio-log.h"

#include "demo-target.h"

/* A simplistic cache for memory and register transfers. */

enum { NR_THREADS = 4 };
enum { NR_REGS = 8 };

struct mem {
  unsigned long base;
  unsigned long len;
  unsigned char *buf;
};

struct gdbserv_thread {
  struct gdbserv_reg reg[NR_REGS];
  struct mem mem;
};

/* A mini-thread database */
struct gdbserv_thread thread_db[NR_THREADS];



static char *
thread_info (struct gdbserv *serv, struct gdbserv_thread *thread)
{
  char buf[20];
  char *info;
  long id =  thread - thread_db;
  assert (thread != NULL);
  sprintf (buf, "ID-%ld", id);
  info = strdup (buf);
  return info;
}

static void
thread_id (struct gdbserv *serv, struct gdbserv_thread *thread, struct gdbserv_reg *thread_id)
{
  assert (thread != NULL);
  gdbserv_ulong_to_reg (serv, thread - thread_db + 1, thread_id);
}

static int
thread_lookup_by_id (struct gdbserv *serv,
		     const struct gdbserv_reg *thread_id,
		     struct gdbserv_thread **thread)
{
  long id;
  assert (thread != NULL);
  gdbserv_reg_to_ulong (serv, thread_id, &id);
  fprintf (stderr, "lookup_by_id %ld\n", id);
  if (id == 0)
    {
      *thread = &thread_db[0];
      return 0;
    }
  else if (id < 0 || id > NR_THREADS)
    {
      *thread = &thread_db[0];
      return -1;
    }
  else
    {
      *thread = &thread_db[id - 1];
      return 1;
    }
}

static struct gdbserv_thread *
thread_next (struct gdbserv *serv, struct gdbserv_thread *thread)
{
  if (thread == NULL)
    {
      return &thread_db[0];
    }
  else if (thread >= thread_db + NR_THREADS - 1)
    {
      return NULL;
    }
  else
    return thread + 1;
}


/*
 * Get/Set Registers
 * 
 * (including a primitive register cache) 
 */

static int
thread_next_reg (struct gdbserv *serv, struct gdbserv_thread *thread,
		 int reg)
{
  assert (thread != NULL);
  if (reg < 0)
    return 0;
  if (reg >= NR_REGS - 1)
    return -1;
  return reg + 1;
}

static int
thread_reg_format (struct gdbserv *serv, struct gdbserv_thread *thread,
		   int reg, int *size, int *padding)
{
  assert (thread != NULL);
  *size = 4;
  *padding = 0;
  return 0;
}

static int
thread_set_reg (struct gdbserv *serv,
		struct gdbserv_thread *thread,
		int nr,
		const struct gdbserv_reg *val)
{
  assert (thread != NULL);
  if (nr < 0 || nr >= NR_REGS)
    return -1;
  memmove (&thread->reg[nr], val, sizeof (*val));
  return 0;
}

static int 
thread_get_reg (struct gdbserv *serv,
		struct gdbserv_thread *thread,
		int nr,
		struct gdbserv_reg *val)
{
  assert (thread != NULL);
  if (nr < 0 || nr >= NR_REGS)
    return -1;
  memmove (val, &thread->reg[nr], sizeof (*val));
  return 0;
}

/*
 * Get/Set memory
 *
 * (including a primitive memory cache)
 */

static long
thread_get_mem (struct gdbserv *serv, 
		struct gdbserv_thread *thread,
		struct gdbserv_reg *addr, 
		void *data, 
		long len)
{
  long n;
  unsigned char *d = data;
  unsigned long request_base;

  gdbserv_reg_to_ulong (serv, addr, &request_base);

  for (n = 0; n < len; n++)
    {
      if (request_base + n >= thread->mem.base
	  && request_base + n < thread->mem.base + thread->mem.len)
	*d++ = thread->mem.buf[request_base + n - thread->mem.base];
      else
	*d++ = 0;
    }

  return n;
}


static long
thread_set_mem (struct gdbserv *serv, 
		struct gdbserv_thread *thread,
		struct gdbserv_reg* addr, 
		void* data, 
		long len)
{
  unsigned long request_base;

  gdbserv_reg_to_ulong (serv, addr, &request_base);
  if (thread->mem.len == 0)
    {
      thread->mem.buf  = malloc (len);
      thread->mem.len  = len;
      gdbserv_reg_to_ulong (serv, addr, &thread->mem.base);
    }
  else
    {
      if (request_base < thread->mem.base)
	{
	  thread->mem.len += thread->mem.base - request_base;
	  thread->mem.base = request_base;
	  thread->mem.buf  = realloc (thread->mem.buf, thread->mem.len);
	}
      if (request_base + len > 
	  thread->mem.base + thread->mem.len)
	{
	  thread->mem.len += 
	    (request_base + len) - (thread->mem.base + thread->mem.len);
	  thread->mem.buf  = realloc (thread->mem.buf, thread->mem.len);
	}
    }

  if (thread->mem.buf == NULL)
    return 0;

  memcpy (thread->mem.buf + (request_base - thread->mem.base), 
	  data, len);
  return  len;
}


void
select_initial_thread (struct gdbserv *gdbserv,
		       struct gdbserv_thread *thread,
		       void *context)
{
  gdbserv_fromtarget_thread_break (gdbserv, thread, GDBSERV_SIGNONE);
}


/* This function is called from gdbloop_poll when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted. */

struct gdbserv_target* 
thread_attach (struct gdbserv *serv, void* context)
{
  struct gdbserv_target *target;

  /* Grap the demo target. */
  target = demo_target (serv, context);
  if (target == NULL)
    return NULL;

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  target->next_gg_reg = thread_next_reg;
  target->next_expedited_reg = thread_next_reg;
  target->reg_format = thread_reg_format;
  target->input_reg = gdbserv_input_reg_beb;
  target->output_reg = gdbserv_output_reg_beb;
  target->get_thread_reg = thread_get_reg;
  target->set_thread_reg = thread_set_reg;
  target->get_thread_mem = thread_get_mem;
  target->set_thread_mem = thread_set_mem;

  /* thread support */
  target->thread_info = thread_info;
  target->thread_id = thread_id;
  target->thread_lookup_by_id = thread_lookup_by_id;
  target->thread_next = thread_next;

  /* Schedule an event to take us out of reset and to attach a
     thread. */
  gdbsched_schedule (0, select_initial_thread, serv, &thread_db[0], NULL);

  return target;
}

int
main (int argc, char *argv[])
{
  int portno;
  if (argc > 1)
    portno = atoi (argv[1]);
  else
    portno = 2345;

  /* Enable tracing */
  gdbsocket_log = stdio_log (stderr);
  gdbserv_warning_log = stdio_log (stderr);
 
  gdbsocket_startup (portno, thread_attach, NULL);
  printf ("Started listening socket on port %d.\n", portno);

  /* Poll for socket traffic. */
  while (! demo_quit_p)
    {
      gdbloop (time (NULL), -1);
    }

  gdbsocket_shutdown ();
  printf ("Shut down sockets.\n");

  return 0;
}
