/* poll.c

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
#include <errno.h>
#include <stdlib.h>
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif

#include <sys/types.h>
#include <poll.h>

#include "gdbsocket.h"
#include "gdblog.h"
#include "stdio-log.h"
#include "gdbserv-log.h"
#include "gdbsched.h"

#include "demo-target.h"

/* This is a sample main program that demonstrates use of the RDA
   library routines using UNIX poll.  It acts to gdb like a strange
   generic remote target.  */

struct pollfds {
  struct pollfd *fds;
  int nfds;
};

static void
set (int fd, void *context, enum gdbsocket_fd_event event)
{
  struct pollfds *pollfds = context;
  struct pollfd *pollfd;
  for (pollfd = pollfds->fds; pollfd < pollfds->fds + pollfds->nfds; pollfd++)
    {
      if (pollfd->fd == fd)
	break;
    }
  if (pollfd == pollfds->fds + pollfds->nfds)
    {
      pollfds->nfds++;
      /* Be slack.  Let realloc handle need to srink/grow allocated
         pollfds. */
      pollfds->fds = realloc (pollfds->fds,
			      pollfds->nfds * sizeof (struct pollfd));
      pollfd = &pollfds->fds[pollfds->nfds - 1];
      pollfd->fd = fd;
      pollfd->events = 0;
      pollfd->revents = 0;
    }
  switch (event)
    {
    case GDBSOCKET_FD_READ:
      pollfd->events |= POLLIN;
      break;
    case GDBSOCKET_FD_WRITE:
      pollfd->events |= POLLOUT;
      break;
    }
}

static int
isset (int fd, void *context, enum gdbsocket_fd_event event)
{
  struct pollfds *pollfds = context;
  struct pollfd *pollfd;
  for (pollfd = pollfds->fds; pollfd < pollfds->fds + pollfds->nfds; pollfd++)
    {
      if (pollfd->fd == fd)
	{
	  switch (event)
	    {
	    case GDBSOCKET_FD_READ:
	      return (pollfd->revents & POLLIN);
	      break;
	    case GDBSOCKET_FD_WRITE:
	      return (pollfd->revents & POLLOUT);
	      break;
	    }
	}
    }
  return 0;
}

int
main (int argc, char* argv[])
{
  int portno;
  struct pollfds pollfds;
  memset (&pollfds, 0, sizeof (pollfds));
  if (argc > 1)
    portno = atoi(argv[1]);
  else
    portno = 2345;

  /* Enable socket tracing */
  gdbsocket_log = stdio_log (stderr);
  gdbserv_warning_log = stdio_log (stderr);
 
  gdbsocket_startup (portno, demo_attach, NULL);
  printf ("Started listening socket on port %d.\n", portno);

  /* Poll for socket traffic. */
  while (! demo_quit_p)
    {
      int s;
      int seconds = 1;
  
      /* Process any outstanding events. NOTE: The code should be
         using the value returned to determine the length of the
         poll() but the below is lazy and just waits for a second. */
      gdbsched_dispatch (time (NULL));

      /* wait on all the open inputs */
      pollfds.nfds = 0;
      gdbsocket_fd_set (set, &pollfds);
  
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, "[select ");
	  gdblog_long (gdbsocket_log, seconds);
	}
      s = poll (pollfds.fds, pollfds.nfds, seconds * 1000);

      if (s < 0)
	{
	  if (errno == EINTR)
	    break;
	  else
	    {
	      perror ("poll");
	      break;
	    }
	}
  
      /* Process any pending events. */
      gdbsocket_fd_isset (isset, &pollfds);
    }

  gdbsocket_shutdown ();
  printf ("Shut down sockets.\n");

  return 0;
}
