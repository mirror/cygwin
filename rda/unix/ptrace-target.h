/* ptrace-target.h

   Copyright 2001, 2002 Red Hat, Inc.

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

#include <sys/ptrace.h>
#include <sys/user.h>

/* Shared definitions for an RDA based native gdb server using ptrace. */

#ifdef PTRACE_XFER_TYPE_LONG
typedef long ptrace_xfer_type;
#endif

#ifdef PTRACE_XFER_TYPE_LONG_LONG
typedef long long ptrace_xfer_type;
#endif

#ifdef PTRACE_ARG1_TYPE_LONG
typedef long ptrace_arg1_type;
#endif

#ifdef PTRACE_ARG1_TYPE_LONG_LONG
typedef long long ptrace_arg1_type;
#endif

#ifdef PTRACE_ARG2_TYPE_LONG
typedef long ptrace_arg2_type;
#endif

#ifdef PTRACE_ARG2_TYPE_LONG_LONG
typedef long long ptrace_arg2_type;
#endif

#ifdef PTRACE_ARG3_TYPE_LONG
typedef long ptrace_arg3_type;
#endif

#ifdef PTRACE_ARG3_TYPE_LONG_LONG
typedef long long ptrace_arg3_type;
#endif

#ifdef PTRACE_ARG4_TYPE_LONG
typedef long ptrace_arg4_type;
#endif

#ifdef PTRACE_ARG4_TYPE_LONG_LONG
typedef long long ptrace_arg4_type;
#endif

int ptrace_write_user (struct gdbserv *serv, int pid, ptrace_arg3_type addr,
                       int len, const void *buff);
int ptrace_read_user (struct gdbserv *serv, int pid, ptrace_arg3_type addr,
                      int len, void *buff);
int ptrace_get_gregs (struct gdbserv *serv, int alt_pid, void *buff);
int ptrace_set_gregs (struct gdbserv *serv, int alt_pid, const void *buff);
int ptrace_get_fpregs (struct gdbserv *serv, int alt_pid, void *buff);
int ptrace_set_fpregs (struct gdbserv *serv, int alt_pid,  const void *buff);
int ptrace_get_fpxregs (struct gdbserv *serv, int alt_pid, void *buff);
int ptrace_set_fpxregs (struct gdbserv *serv, int alt_pid, const void *buff);
int ptrace_check_child_state (struct child_process *process);
