/* async.c

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
#include <string.h>		/* for strsignal() on windows. */
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#include <signal.h>
#include <unistd.h>

#include "gdbsocket.h"
#include "demo-target.h"
#include "stdio-log.h"
#include "gdbserv-log.h"
#include "gdbloop.h"
#include "gdblog.h"
#include "gdbsched.h"

/* This is a sample main program that demonstrates use of the RDA library
   routines running in async / non-stop / sigio mode.  It acts to gdb
   like a strange generic remote target. */

static volatile int poll_p;

static void
set_poll_p (int sig)
{
  poll_p = 1;
  gdblog_string (gdbsocket_log, "[");
  gdblog_string (gdbsocket_log, strsignal (sig));
  gdblog_string (gdbsocket_log, "]\n");
  signal (sig, set_poll_p);
}

int
main (int argc, char* argv[])
{
  int portno;
  if (argc > 1)
    portno = atoi(argv[1]);
  else
    portno = 2345;

  /* Enable tracing */
  gdbsocket_log = stdio_log (stderr);
  gdbserv_warning_log = stdio_log (stderr);
 
  /* Whenever an event arrives, call the corresponding handler, that
     in turn will set the poll flag. */
  poll_p = 0;
  signal (SIGIO, set_poll_p);
  signal (SIGALRM, set_poll_p);

  /* Tell the gdbsocket code that all sockets should be created with
     O_ASYNC set.  Such sockets will SIGIO whenever there is input
     available.  Then start the server. */
  gdbsocket_async (1);
  gdbsocket_startup (portno, demo_attach, NULL);
  printf ("Started listening socket on port %d.\n", portno);

  /* Poll for socket traffic. */
  while (! demo_quit_p)
    {
      if (poll_p)
	{
	  long current_time;
	  long sched_time;
	  long new_timeout;
	  long old_timeout;

	  /* Clear the polling flag. Do it first to avoid any problems
	     with race conditions.  If the event-loop is ever modified
	     to handle more complex events then the logic needed to
	     clear this flag will also need to be made correspondingly
	     more complex. */
	  poll_p = 0;

	  /* Clear any backlog of events. */
	  current_time = time (NULL);
	  gdbloop (current_time, 0);

	  /* Schedule a sig alarm to take care of any new events.  Use
             a more up-to-date current time. */
	  current_time = time (NULL);
	  sched_time = gdbsched_dispatch (current_time);
	  assert (sched_time > current_time || sched_time < 0);
	  if (sched_time > current_time)
	    new_timeout = sched_time - current_time;
	  else
	    new_timeout = 0;
	  gdblog_string (gdbsocket_log, "[alarm ");
	  gdblog_long (gdbsocket_log, new_timeout);
	  old_timeout = alarm (new_timeout);
	  gdblog_string (gdbsocket_log, " -> ");
	  gdblog_long (gdbsocket_log, old_timeout);
	  gdblog_string (gdbsocket_log, "]\n");
	}

    }

  gdbsocket_shutdown ();
  printf ("Shut down sockets.\n");

  return 0;
}
