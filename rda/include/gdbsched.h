/* gdbsched.h -- event scheduling facitilies
 
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

#ifdef __cplusplus
extern "C" {
#elif 0
}
#endif

struct gdbserv;
struct gdbserv_target;
struct gdblog;
struct gdbserv_thread;

/* Simple minded event scheduler. */

/* Handle for a scheduled event.  Use this when removing scheduled
   events. */

struct gdbsched;

/* Ftype for handling events.  To make life easier (?) the handler
   takes a GDBSERV and a THREAD as well as a context. */

typedef void gdbsched_handler_ftype (struct gdbserv *gdbserv,
				     struct gdbserv_thread *thread,
				     void *context);

/* Schedule an event at absolute TIME.  The TIME ``0'' is special and
   implies that the event should be scheduled immediatly.  The unit of
   TIME is target implementation dependant.  Typically it will be
   seconds. */

struct gdbsched *gdbsched_schedule (long time,
				    gdbsched_handler_ftype *sched,
				    struct gdbserv *gdbserv,
				    struct gdbserv_thread *thread,
				    void *context);

/* Unschedule an event.  Pass in NULL to just unschedule the first
   event on the queue.  Any of TIME, HANDLER, GDBSERV, THREAD and
   CONTEXT will be assigned if non-NULL.  If there is no event, *TIME
   is set to ``-1'' and everything else is set to NULL. */

void gdbsched_deschedule (struct gdbsched *sched,
			  long *time,
			  gdbsched_handler_ftype **handler,
			  struct gdbserv **gdbserv,
			  struct gdbserv_thread **thread,
			  void **context);

/* Process any events scheduled on or before TIME.  Call with ``0'' to
   process any events scheduled for immediate delivery.  Call with
   ``-1'' to determine the time of the next event. Return the absolute
   time of the next unprocessed event or ``-1'' if no events are
   outstanding. */

long gdbsched_dispatch (long time);


#ifdef __cplusplus
}
#endif
