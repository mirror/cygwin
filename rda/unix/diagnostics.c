/* diagnostics.c - Functions and variables used in RDA diagnostics.

   Copyright 2005 Red Hat, Inc.

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
#include "gdbserv.h"
#include "gdbserv-output.h"

/* Output an "O" packet.  */
void
output_O_packet (struct gdbserv *serv, char *message)
{
  gdbserv_output_attach (serv);
  gdbserv_output_char (serv, 'O');
  gdbserv_output_string_as_bytes (serv, message);
  gdbserv_output_packet (serv);
  gdbserv_output_discard (serv);
}

/* Print out a helpful message regarding SIGSTOP to the GDB console using
   an "O" packet.  This message will be printed at most once per session.  */
void
print_sigstop_message (struct gdbserv *serv)
{
  static int once = 0;

  if (!once)
    {
      output_O_packet (serv, "\n"
      "RDA has sent SIGSTOP to the inferior process.  If you wish to continue\n"
      "without sending this signal, make sure that \"handle SIGSTOP nopass\" has\n"
      "been set or use \"signal 0\" to continue.\n");
      once = 1;
    }
}

/* Print out a helpful message regarding SIGINT to the GDB console using
   an "O" packet.  This message will be printed at most once per session.  */
void
print_sigint_message (struct gdbserv *serv)
{
  static int once = 0;

  if (!once)
    {
      output_O_packet (serv, "\n"
      "RDA has sent SIGINT to the inferior process.  If the process does not\n"
      "stop in a timely fashion, it is possible that SIGINT is being blocked.\n"
      "If that's the case, consider using SIGSTOP to interrupt the process\n"
      "instead.  The monitor command \"monitor interrupt-with-SIGSTOP\" may\n"
      "be used to turn on RDA's internal flag for effecting this behavior.\n");
      once = 1;
    }
}
