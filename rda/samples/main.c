/* main.c

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
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif

#include "gdbsocket.h"
#include "demo-target.h"
#include "stdio-log.h"
#include "gdbserv-log.h"
#include "gdbloop.h"
#include "gdbsched.h"
#include "gdbserv-target.h"

#include <signal.h>

struct gdbserv_thread;

/* This is a sample main program that demonstrates use of the RDA library
   routines.  It acts to gdb like a strange generic remote target.  */

void
do_close (int readfd, int writefd)
{
  /* Ignore it for moment. */
}

void
fake_exit (struct gdbserv *gdbserv,
	   struct gdbserv_thread *thread,
	   void *context)
{
  fprintf (stderr, "Target exiting\n");
  gdbserv_fromtarget_exit (gdbserv, GDBSERV_SIGQUIT);
}

void
usage (void)
{
  fprintf (stderr,
	   "Usage: sample [-d] [-|<port>]\n"
	   "Where:\n"
	   "\t-d\tDaemon mode\n"
	   "\t-v\tVerbose/trace\n"
	   "\t-\tUse stdin/stdout\n"
	   "\t<port>\tSocket number\n"
	   );
}


int
main (int argc, char* argv[])
{
  void (*shutdown) (void);
  int i;
  int daemon_p;
  char *port;

  /* Enable tracing */
  gdbserv_warning_log = stdio_log (stderr);
 
  /* This is a workaround for
     //https://bugzilla.redhat.com/bugzilla/show_bug.cgi?id=53191

     SuS says that an action of SIG_IGN for SIGCHLD means that the
     kernel can automatically reap dead child processes. So when
     ignoring the SIGCHLD from the traced (and still alive) process,
     the kernel goes ahead and calls wait4 on behalf of the parent and
     discards the information which strace requires.
     
     This breaks strace and gdbserver, and may break anything else
     which uses ptrace. gdb is safe because it installs its own
     SIGCHLD handler.
     
     strace can work around this by setting the SIGCHLD action to
     SIG_DFL. */
  signal (SIGCHLD, SIG_DFL);
 
  /* options? */
  daemon_p = 0;
  for (i = 1; i < argc; i++)
    {
      if (strcmp (argv[i], "-d") == 0)
	daemon_p = 1;
      else if (strcmp (argv[i], "-v") == 0)
	gdbsocket_log = stdio_log (stderr);
      else if (strcmp (argv[i], "-?") == 0
	       || strcmp (argv[i], "-h") == 0)
	{
	  usage ();
	  return 0;
	}
      else
	break;
    }

  /* Parameter? */
  if (i >= argc)
    port = "2345";
  else
    port = argv[i];

  shutdown = NULL;
  if (strcmp (port, "-") == 0)
    {
      /* ``-'': use stdin/stdout. */
      gdbsocket_reopen (STDIN_FILENO, STDOUT_FILENO,
			do_close, demo_attach, NULL);
      fprintf (stderr, "Server started, using stdin/stdout.\n");
      /* FIXME: thinko: CNTRL-C on stdin gets converted into a signal.
	 Ignore the signal for moment.  Should be doing something like
	 putting the input and output TTY's into raw mode. */
      signal (SIGINT, SIG_IGN);
      shutdown = gdbsocket_shutdown;
    }
  else if (isdigit (port[0]))
    {
      /* ``[0-9]*'': use the specified port. */
      char *end = port;
      int portno = strtol (port, &end, 0);
      if (end[0] == '\0')
	{
	  gdbsocket_startup (portno, demo_attach, NULL);
	  fprintf (stderr, "Server started, listening on port %d.\n", portno);
	  shutdown = gdbsocket_shutdown;
	}
    }
  if (shutdown == NULL)
    {
      usage ();
      return 1;
    }
  if (daemon_p)
    fprintf (stderr, "Daemon mode\n");

  /* Keep the server alive. */
  while (!demo_quit_p || daemon_p)
    {
      gdbloop_poll (-1);
    }

  shutdown ();
  printf ("Server shutdown.\n");

  return 0;
}
