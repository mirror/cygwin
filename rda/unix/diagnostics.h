/* diagnostics.h - Functions and variables used in RDA diagnostics.

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

/* When non-zero, print thread-db related diagnostic messages.  */
extern int thread_db_noisy;

/* When non-zero, print lwp pool related diagnostic messages.  */
extern int debug_lwp_pool;

/* Fetch the PC value for a given pid.  */
struct gdbserv;
extern unsigned long debug_get_pc (struct gdbserv *serv, pid_t pid);

/* Output an "O" packet.  */
void output_O_packet (struct gdbserv *serv, char *message);

/* Print out a helpful message regarding SIGSTOP to the GDB console using
   an "O" packet.  This message will only be printed at most once per
   session.  */
void print_sigstop_message (struct gdbserv *serv);

/* Print out a helpful message regarding SIGINT to the GDB console using
   an "O" packet.  This message will only be printed at most once per
   session.  */
void print_sigint_message (struct gdbserv *serv);
