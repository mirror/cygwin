/* lwp-ctrl.h --- interface to functions for controlling LWP's

   Copyright 2004 Red Hat, Inc.

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

#ifndef RDA_UNIX_LWP_CTRL_H
#define RDA_UNIX_LWP_CTRL_H

#include <sys/types.h>

struct gdbserv;

/* Do a PTRACE_ATTACH on LWP.  Do not wait for the resulting wait
   status.  On success, return zero; on failure, print a message, set
   errno, and return -1.  */
int attach_lwp (pid_t lwp);

/* Singlestep the stopped lwp LWP, which is managed by SERV.  If LWP
   successfully completes the next instruction, it will receive a
   SIGTRAP signal.  If SIGNAL is non-zero, send it to LWP.  Do not
   wait for the resulting wait status.  On success, return zero; on
   failure, print a message, set errno, and return -1.  */
int singlestep_lwp (struct gdbserv *serv, pid_t lwp, int signal);

/* Continue the stopped lwp LWP.  If SIGNAL is non-zero, send it to
   LWP.  Do not wait for the resulting wait status.  On success,
   return zero; on failure, print a message, set errno, and return
   -1.  */
int continue_lwp (pid_t lwp, int signal);

/* Send LWP the signal SIGNAL.  Do not wait for the resulting wait
   status.  On success, return zero; on failure, print a message, set
   errno, and return -1.  

   If possible, this uses the 'tkill' system call to ensure the signal
   is sent to that exact LWP, and not distributed to whatever thread
   in the process is ready to handle it (as POSIX says ordinary 'kill'
   must do).  */
int kill_lwp (pid_t lwp, int signal);


#endif /* RDA_UNIX_LWP_CTRL_H */
