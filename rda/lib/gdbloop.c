/* gdbloop.c

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

#include "config.h"

#include <stdio.h>
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>
#include <fcntl.h>

#include "gdblog.h"
#include "gdbsocket.h"
#include "gdbsched.h"

#include "gdbloop.h"

/* Poll all of GDBSOCKET's open file descriptors. */

struct fds
{
  fd_set read;
  fd_set write;
  int nr;
};

static void
fds_set (int fd, void *context, enum gdbsocket_fd_event event)
{
  struct fds *fds = context;
  switch (event)
    {
    case GDBSOCKET_FD_READ:
      FD_SET (fd, &fds->read);
      break;
    case GDBSOCKET_FD_WRITE:
      FD_SET (fd, &fds->write);
      break;
    }
  if (fds->nr <= fd)
    fds->nr = fd + 1;
}

static int
fds_isset (int fd, void *context, enum gdbsocket_fd_event event)
{
  struct fds *fds = context;
  switch (event)
    {
    case GDBSOCKET_FD_READ:
      return FD_ISSET (fd, &fds->read);
    case GDBSOCKET_FD_WRITE:
      return FD_ISSET (fd, &fds->write);
    }
  return 0;
}

static void
poll_gdbsocket (long timeout)
{
  int s;
  struct fds fds;
  
  /* Collect up the FDs of interest. */
  FD_ZERO (&fds.read);
  FD_ZERO (&fds.write);
  fds.nr = 0;
  gdbsocket_fd_set (fds_set, &fds);
  
  /* Do the select. */
  gdblog_string (gdbsocket_log, "[select ");
  gdblog_long (gdbsocket_log, timeout);
  if (timeout >= 0)
    {
      struct timeval timeval;
      timeval.tv_sec = timeout;
      timeval.tv_usec = 0;
      s = select (fds.nr, &fds.read, &fds.write, NULL, &timeval);
    }
  else
    {
      s = select (fds.nr, &fds.read, &fds.write, NULL, NULL);
    }
  gdblog_string (gdbsocket_log, " -> ");
  gdblog_long (gdbsocket_log, s);
  gdblog_string (gdbsocket_log, "]\n");

  if (s < 0)
    {
      if (errno == EINTR)
	return;
      perror ("select");
      return;
    }
  
  /* Process any pending events. */
  gdbsocket_fd_isset (fds_isset, &fds);
}  

void
gdbloop (long current_time, int timeout)
{
  long sched_time;

  /* Compute the time until the next event. */
  sched_time = gdbsched_dispatch (-1);

  /* Reduce the timeout if the next scheduled event is sooner. */
  if (sched_time > current_time)
    {
      if (timeout < 0
	  || sched_time - current_time < timeout)
	timeout = sched_time - current_time;
    }
  else if (sched_time >= 0)
    {
      if (timeout <= 0)
	timeout = 0;
    }

  /* check the event queue for events. */
  poll_gdbsocket (timeout);

  /* Drain the queue of any outstanding events. */
  gdbsched_dispatch (current_time);
}

void
gdbloop_poll (int timeout)
{
  gdbloop (time (NULL), timeout);
}
