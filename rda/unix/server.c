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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <termios.h>

#include "gdbsocket.h"
#include "gdbloop.h"
#include "gdbserv.h"
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

static struct termios save_termios;

static void
close_device (int infd, int outfd)
{
  if (isatty (infd))
    {
      tcsetattr (infd, TCSAFLUSH, &save_termios);
    }
  close (infd);
  close (outfd);
}

/* Put a tty into "raw" mode.  Mostly taken from Stevens' book, "Advanced
   Programming in the UNIX Environment.  */
static int
tty_raw (int fd, speed_t speed)
{
  struct termios buf;

  /* Don't do anything for non-tty devices.  */
  if (!isatty (fd))
    return 0;

  if (tcgetattr (fd, &save_termios) < 0)
    return -1;

  buf = save_termios;

  /* Set the following local modes: echo off, canonical mode off, extended
     input processing off, signal chars off.  */
  buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  /* Set the following input modes: no SIGINT on BREAK, CR-to-NL off, input
     parity check off, don't strip 7th bit on input, output flow control
     off.  */
  buf.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

  /* Set the following control modes: clear size bits, parity checking off.  */
  buf.c_cflag &= ~(CSIZE | PARENB); 

  /* Enable 8 bits/char.  */
  buf.c_cflag |= CS8;

  /* Turn output processing off.  */
  buf.c_oflag &= ~(OPOST);

  /* Case B: 1 byte at a time, no timer */
  buf.c_cc[VMIN] = 1;
  buf.c_cc[VTIME] = 0;

  if (speed != 0)
    {
      cfsetispeed (&buf, speed);
      cfsetospeed (&buf, speed);
    }

  if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
    return -1;
  return 0;
}

/* Table of serial port speed values.  */
static struct
  {
    long speed;		/* speed value as an integer */
    speed_t bspeed;	/* speed value as one of the termios.h constants
    			   suitable for passing to cfsetispeed() or
			   cfsetospeed().  */
  }
speed_table[] = {
  { 50, B50 },
  { 75, B75 },
  { 110, B110 },
  { 134, B134 },
  { 150, B150 },
  { 200, B200 },
  { 300, B300 },
  { 600, B600 },
  { 1200, B1200 },
  { 1800, B1800 },
  { 2400, B2400 },
  { 4800, B4800 },
  { 9600, B9600 },
  { 19200, B19200 },
  { 38400, B38400 }
#ifdef B57600 
  ,{ 57600, B57600 }
#endif
#ifdef B115200
  ,{ 115200, B115200 }
#endif
#ifdef B230400
  ,{ 230400, B230400 }
#endif
#ifdef B460800
  ,{ 460800, B460800 }
#endif
#ifdef B500000
  ,{ 500000, B500000 }
#endif
#ifdef B576000
  ,{ 576000, B576000 }
#endif
#ifdef B921600
  ,{ 921600, B921600 }
#endif
#ifdef B2000000
  ,{ 1000000, B1000000 }
#endif
#ifdef B1152000
  ,{ 1152000, B1152000 }
#endif
#ifdef B1500000
  ,{ 1500000, B1500000 }
#endif
#ifdef B2000000
  ,{ 2000000, B2000000 }
#endif
#ifdef B2500000
  ,{ 2500000, B2500000 }
#endif
#ifdef B3000000
  ,{ 3000000, B3000000 }
#endif
#ifdef B3500000
  ,{ 3500000, B3500000 }
#endif
#ifdef B4000000
  ,{ 4000000, B4000000 }
#endif
};

/* Print error for erroneous -s switch and exit.  */
static void
invalid_speed (char *str)
{
  int i;
  int ll;

  fprintf (stderr, "Error: Invalid -s switch \"%s\".\n", str);
  ll = fprintf (stderr, "Valid speeds are:");
  
  for (i = 0; i < sizeof (speed_table) / sizeof (speed_table[0]); i++)
    {
      char str[20];
      int cnt;
      cnt = snprintf (str, sizeof (str), "%d", speed_table[i].speed);
      if (cnt + ll + 1 > 80)
	{
	  fprintf (stderr, "\n");
	  ll = 0;
	}
      else
	{
	  fprintf (stderr, " ");
	  ll++;
	}
      fprintf (stderr, "%s", str);
      ll += cnt;
    }
  fprintf (stderr, "\n");
  exit (1);
}

/* Attempt to parse a speed and return the speed value.  */
static speed_t
parse_speed (char *str)
{
  int i;
  long speed;
  char *endptr;

  speed = strtol (str, &endptr, 10);
  if (speed == 0 || *endptr != '\0')
    {
      invalid_speed (str);
      /* won't return */
    }

  for (i = 0; i < sizeof (speed_table) / sizeof (speed_table[0]); i++)
    if (speed_table[i].speed == speed)
      return speed_table[i].bspeed;

  /* Speed not found.  Error out.  */
  invalid_speed (str);
  return 0;	/* won't actually return */
}

/* Print a usage message and exit.  */
static void
usage (char *progname)
{
  fprintf (stderr,
    "Usage: %s [-v] tcp-port-num executable-file [arguments ...]\n"
    "   or: %s -a [-v] tcp-port-num process-id\n"
    "   or: %s [-v] [-s speed] device-name executable-file [arguments ...]\n"
    "   or: %s -a [-v] [-s speed] device-name process-id\n"
    "   or: %s -h\n"
    "Start the Red Hat debug agent for use with a remote debugger.\n"
    "Options and arguments:\n"
    "  -a               Attach to already running process.\n"
    "  -h               Print this usage message.\n"
    "  -s speed         Set speed (e.g. 115200) at which device \"device-name\"\n"
    "                   will communicate with remote debugger.\n"
    "  -v               Increase verbosity.  One -v flag enables informational\n"
    "                   messages.  Two -v flags turn on internal debugging\n"
    "                   messages.\n"
    "  arguments ...    Command line arguments with which to start program\n"
    "                   being debugged.\n"
    "  device-name      Name of serial device over which RDA will communicate\n"
    "                   with remote debugger.\n"
    "  executable-file  Name of program to debug.\n"
    "  process-id       Process ID (PID) of process to attach to.\n"
    "  tcp-port-num     Port number to which debugger connects for purpose\n"
    "                   of communicating with the debug agent using the GDB\n"
    "                   remote protocol.\n",
    progname, progname, progname, progname, progname);
  exit (1);
}

int
main (int argc, char **argv)
{
  int portno = 0;
  char *endptr;
  int verbose = 0;
  int attach = 0;
  int optidx;
  int infd, outfd;
  struct child_process *process;
  char *devicename = "";
  speed_t speed;

  /* Parse options.  */
  for (optidx = 1; optidx < argc; optidx++)
    {
      if (argv[optidx][0] == '-' && argv[optidx][1] != '\0')
	{
	  switch (argv[optidx][1])
	    {
	      case 'a':
		attach = 1;
		break;
	      case 'h':
		usage (argv[0]);
		/* not reached */
		break;
	      case 's':
		optidx++;
		if (optidx >= argc)
		  usage(argv[0]);
		speed = parse_speed (argv[optidx]);
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

  if (isdigit (*argv[optidx]))
    {
      errno = 0;
      portno = strtol (argv[optidx], &endptr, 10);
      if (errno != 0 || portno == 0)
	usage (argv[0]);
    }
  else if (strcmp (argv[optidx], "-") == 0)
    {
      infd = STDIN_FILENO;
      outfd = STDOUT_FILENO;
      devicename = "stdin/stdout";
    }
  else
    {
      devicename = argv[optidx];
      infd = open (devicename, O_RDWR);
      if (infd < 0)
	{
	  fprintf (stderr, "Error opening device %s: %s\n", devicename,
	           strerror (errno));
	  exit (1);
	}
      outfd = infd;
    }

  process = malloc (sizeof (struct child_process));
  memset (process, 0, sizeof (struct child_process));
  if (attach)
    {
      process->pid = strtol (argv[optidx + 1], &endptr, 10);
      if (errno != 0 || endptr == argv[optidx] || process->pid <= 0)
	usage (argv[0]);
    }
  else
    {
      process->argv       = &argv[optidx + 1];
      process->executable =  argv[optidx + 1];
    }

  if (verbose > 1)
    process->debug_backend = 1;
  if (verbose)
    process->debug_informational = 1;

  signal (SIGCHLD, chld_handler);

  if (portno != 0)
    {
      gdbsocket_startup (portno, gdbserver.attach, process);
      if (process->debug_informational)
	fprintf (stderr, "Started listening socket on port %d.\n", portno);
    }
  else
    {
      tty_raw (infd, speed);
      if (process->debug_informational)
	fprintf (stderr, "Waiting for input on %s.\n", devicename);
      gdbsocket_reopen (infd, outfd, close_device, gdbserver.attach, process);
    }

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
