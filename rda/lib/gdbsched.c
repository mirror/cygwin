/* gdbsched.c

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

#include <stdlib.h>

#include "gdbsched.h"
#include "gdblog.h"
#include "gdbsocket.h"

/* Database of scheduled events. */

struct event {
  long time;
  struct gdbsched *sched;
  gdbsched_handler_ftype *handler;
  struct gdbserv *gdbserv;
  struct gdbserv_thread *thread;
  void *context;
  struct event *next;
};

struct event *event_db;

/* Unique key generator. */
struct gdbsched {
  int i;
};
struct gdbsched *sched_db;

struct gdbsched *
gdbsched_schedule (long time,
		   gdbsched_handler_ftype *handler,
		   struct gdbserv *gdbserv,
		   struct gdbserv_thread *thread,
		   void *context)
{
  struct event **event;
  struct event *new = malloc (sizeof (struct event));
  gdblog_string (gdbsocket_log, "[schedule ");
  new->sched = ++sched_db;
  new->time = time;
  new->handler = handler;
  new->gdbserv = gdbserv;
  new->thread = thread;
  new->context = context;
  /* Insert it. */
  for (event = &event_db;
       (*event) != NULL && (*event)->time <= time;
       event = &(*event)->next);
  new->next = *event;
  *event = new;
  gdblog_long (gdbsocket_log, time);
  gdblog_string (gdbsocket_log, "]\n");
  return new->sched;
}

void
gdbsched_deschedule (struct gdbsched *sched,
		     long *time,
		     gdbsched_handler_ftype **handler,
		     struct gdbserv **gdbserv,
		     struct gdbserv_thread **thread,
		     void **context)
{
  struct event **event;
  long local_time;
  gdbsched_handler_ftype *local_handler;
  struct gdbserv *local_gdbserv;
  struct gdbserv_thread *local_thread;
  void *local_context;

  gdblog_string (gdbsocket_log, "[deschedule ");

  /* Find the event. */
  if (sched == NULL)
    {
      event = &event_db;
    }
  else
    {
      for (event = &event_db;
	   (*event) != NULL;
	   event = &(*event)->next)
	{
	  if ((*event)->sched == sched)
	    break;
	}
    }
  
  /* Save it's state and delete it. */
  if ((*event) == NULL)
    {
       local_time = -1;
       local_handler = NULL;
       local_gdbserv = NULL;
       local_thread = NULL;
       local_context = NULL;
    }
  else
    {
      struct event *dead = (*event);
      (*event) = dead->next;
      local_time = dead->time;
      local_handler = dead->handler;
      local_gdbserv = dead->gdbserv;
      local_thread = dead->thread;
      local_context = dead->context;
      free (dead);
    }

  /* Return any applicable values. */
  if (time != NULL)
    *time = local_time;
  if (handler != NULL)
    *handler = local_handler;
  if (gdbserv != NULL)
    *gdbserv = local_gdbserv;
  if (local_thread != NULL)
    *thread = local_thread;
  if (local_context != NULL)
    *context = local_context;
  gdblog_long (gdbsocket_log, local_time);
  gdblog_string (gdbsocket_log, "]");
}

long
gdbsched_dispatch (long current_time)
{
  long next_time;
  gdblog_string (gdbsocket_log, "[dispatch @");
  gdblog_long (gdbsocket_log, current_time);
  while (event_db != NULL
	 && event_db->time <= current_time)
    {
      long time;
      gdbsched_handler_ftype *handler;
      struct gdbserv *gdbserv;
      struct gdbserv_thread *thread;
      void *context;
      gdbsched_deschedule (NULL, &time, &handler, &gdbserv, &thread, &context);
      handler (gdbserv, thread, context);
    }
  if (event_db == NULL)
    next_time = -1;
  else
    next_time = event_db->time;
  gdblog_string (gdbsocket_log, " -> ");
  gdblog_long (gdbsocket_log, next_time);
  gdblog_string (gdbsocket_log, "]\n");
  return next_time;
}
