/* server-main.c

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
#include <signal.h>
#include <errno.h>

#include "gdbsocket.h"
#include "gdbloop.h"
#include "server.h"

/* Signal a request to terminate main loop. */
int server_quit_p = 0;

/* FIXME -- move to header file.  */
struct gdbserv_target *linux_attach (struct gdbserv* serv, void* data);

/* We have an empty SIGCHLD handler in order to make sure that
   the timed, but blocking call to select will be interrupted
   by SIGCHLD signals.  */

static void
chld_handler (int sig)
{
}

/* Print a usage message and exit.  */
static void
usage (char *progname)
{
  fprintf (stderr,
    "Usage: %s [-h] [-v] tcp-port-num executable-file [arguments ...]\n\n"
    "Start the Red Hat debug agent listening on port ``tcp-port-num'' for\n"
    "debugging``executable-file'' with optional arguments.\n\n"
    "Options and arguments:\n"
    "  -h               Print this usage message.\n"
    "  -v               Increase verbosity.  One -v flag enables informational\n"
    "                   messages.  Two -v flags turn on internal debugging\n"
    "                   messages.\n"
    "  tcp-port-num     Port number to which debugger connects for purpose\n"
    "                   of communicating with the debug agent using the GDB\n"
    "                   remote protocol.\n"
    "  executable-file  Name of program to debug.\n"
    "  arguments ...    Command line arguments with which to start program\n"
    "                   being debugged.\n",
    progname);
  exit (1);
}

int
main (int argc, char **argv)
{
  int portno;
  char *endptr;
  int verbose = 0;
  int optidx;
  struct child_process *process;

  /* Parse options.  */
  for (optidx = 1; optidx < argc; optidx++)
    {
      if (argv[optidx][0] == '-' && argv[optidx][1] != '\0')
	{
	  switch (argv[optidx][1])
	    {
	      case 'h':
		usage (argv[0]);
		/* not reached */
		break;
	      case 'v':
		verbose++;
		break;
	      default:
		usage (argv[0]);
		/* not reached */
		break;
	    }
	}
      else
	break;
    }

  if (argc - optidx < 2)
    usage (argv[0]);

  errno = 0;
  portno = strtol (argv[optidx], &endptr, 10);
  if (errno != 0 || endptr == argv[optidx])
    usage (argv[0]);

  process = malloc (sizeof (struct child_process));
  memset (process, 0, sizeof (struct child_process));
  process->argv       = &argv[optidx + 1];
  process->executable =  argv[optidx + 1];

  if (verbose > 1)
    process->debug_backend = 1;
  if (verbose)
    process->debug_informational = 1;

  signal (SIGCHLD, chld_handler);

  gdbsocket_startup (portno, gdbserver.attach, process);
  if (process->debug_informational)
    fprintf (stderr, "Started listening socket on port %d.\n", portno);

  /* Poll for socket traffic. */
  while (! server_quit_p)
    {
      gdbloop_poll (1 /* second */);
      if (! server_quit_p)
	{
	  if (gdbserver.check_child_state (process))
	    {
	      switch (process->stop_status) {
	      case 'T':
		gdbserver.fromtarget_break (process);
		break;
	      case 'X':
		gdbserver.fromtarget_terminate (process);
		break;
	      case 'W':
		gdbserver.fromtarget_exit (process);
		break;
	      }
	    }
	}
    }
  gdbsocket_shutdown ();
  if (process->debug_informational)
    fprintf (stderr, "Shut down sockets.\n");

  return 0;
}
