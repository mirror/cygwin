/* server.cc

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
#include <getopt.h>

#if !HAVE_WINDOWS_H
#error The windows.h header is required when compiling for a Win32 target.
#endif
#include <windows.h>

#include "server.h"

int usage (const char *name)
{
  fprintf (stderr, "Usage: %s [OPTIONS]... program [args]...\n", name);
  fprintf (stderr, "Options:\n");
  fprintf (stderr, "  -c            create new console for child process.\n");
  fprintf (stderr, "  -D            debug RDA.\n");
  fprintf (stderr, "  -d            allow debug output from child process.\n");
  fprintf (stderr, "  -g            start child in new process group.\n");
  fprintf (stderr, "  -p portno     listen on port `portno' [def. 2345].\n");
  fprintf (stderr, "  -t            allow trace output as by `strace(1)'.\n");
  fprintf (stderr, "  -m hex_mask   trace mask when `-t' is set [def. 1].\n");
  return 1;
}

int
main (int argc, char **argv)
{
  int portno = 2345;
  int c;

  child_process *process = new child_process;

  if (getenv ("GDBSERVER_DEBUG_BACKEND") != NULL)
    process->set_debug ();

  // Process options
  while ((c = getopt (argc, argv, "cdDgm:p:t")) != EOF)
    switch (c)
      {
      case 'c':
        process->new_console = TRUE;
	break;

      case 'd':
        process->set_debug_process ();
	break;

      case 'D':
        process->set_debug ();
	break;

      case 'g':
        process->new_group = TRUE;
	break;

      case 'p':
        portno = atoi (optarg);
	if (portno < 0 || portno > 65535)
	  {
	    fprintf (stderr, "%s: Illegal portno.\n", argv[0]);
	    return usage (argv[0]);
          }
        break;

      case 't':
        process->set_trace ();
	break;

      case 'm':
        process->set_trace (strtoul (optarg, NULL, 16));
	break;

      default:
        return usage (argv[0]);
      }

  if (optind < argc)
    {
      process->argc       = argc - optind;
      process->argv       = &argv[optind];
      process->executable =  argv[optind];
    }
  else
    {
      fprintf (stderr, "%s: No target process specified.\n", argv[0]);
      return usage (argv[0]);
    }

  gdbsocket_startup (portno, win32_attach, process);
  printf ("Started listening socket on port %d.\n", portno);

  /* Poll for socket traffic. */
  while (! process->quit_server ())
    {
      gdbloop_poll (0 /* second */);
      if (process->check_state ())
	{
	  switch (process->status ())
	    {
	    case Break:
	      process->fromtarget_break ();
	      break;
	    case Terminate:
	      process->fromtarget_terminate ();
	      break;
	    case Exit:
	      process->fromtarget_exit ();
	      break;
	    }
	}
    }
  gdbsocket_shutdown ();
  printf ("Shut down sockets.\n");

  return 0;
}
