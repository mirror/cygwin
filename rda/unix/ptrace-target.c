/* ptrace-target.c

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

#define _GNU_SOURCE

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/unistd.h>

#include "gdbserv.h" 
#include "gdbserv-target.h" 
#include "gdbserv-utils.h"
#include "gdb_proc_service.h"
#include "gdbserv-thread-db.h"

#include "server.h"
#include "ptrace-target.h"
#include "lwp-ctrl.h"
#include "diagnostics.h"

#include <syscall.h>

/* This is unix ptrace gdbserv target that uses the RDA library to implement
   a remote gdbserver on a unix ptrace host.  It controls the process
   to be debugged on the linux host, allowing GDB to pull the strings
   from any host on the network (or on a serial port).  */

/* Track sole connection to a remote gdb client. */
/* FIXME: needed? */
static struct gdbserv* ptrace_connect_lock = NULL;

/* Close all open file descriptors except for stdin, stdout, and
   stderr.  */

static void
close_open_files (void)
{
  long max_open_files = sysconf (_SC_OPEN_MAX);
  int fd;

  for (fd = 3; fd < max_open_files; fd++)
    {
      close (fd);
    }
}

/* ptrace_create_child:

   Either attach to an existing process or fork a child and capture
   it via PTRACE_TRACEME.

   The single argument PROCESS is a struct containing either the
   process id to attach to or the file name and arguments to execute.
   
*/

/* Local Functions: */

static int
ptrace_create_child (struct child_process *process)
{
  int pid;

  if (process->pid > 0)
    {
      pid = process->pid;

      errno = 0;
      ptrace (PTRACE_ATTACH, pid, 0L, 0L);
      if (errno != 0)
	{
	  fprintf (stderr, "Could not attach to process id %d\n", pid);
	  exit (1);
	}
    }
  else
    {
      pid = vfork ();
      if (pid < 0)
	{
	  fprintf (stderr, "PTRACE: vfork failed!\n");
	  return 0;
	}

      if (pid == 0)
	{
	  close_open_files ();
	  if (process->debug_backend)
	    fprintf (stderr, "PTRACE_TRACEME\n");
	  errno = 0;
	  ptrace (PTRACE_TRACEME, 0L, 0L, 0L);
	  if (errno != 0)
	    {
	      fprintf (stderr, "PTRACE: child cannot be traced!\n");
	      goto fail;
	    }
	  if (process->executable != NULL && process->argv != NULL)
	    execv (process->executable, process->argv);
	  else
	    sleep (-1);	/* FIXME ??? */

	  fprintf (stderr, "Cannot exec %s: %s.\n", process->executable,
		   strerror (errno));
	fail:
	  fflush (stderr);
	  _exit (0177);
	}
    }

  return pid;
}

/* Decode the waitstatus returned by waitpid, and return the appropriate
   stop status and stop_signal to gdb.  FIXME: this is not specific to 
   ptrace, but there's no better place to put it (server.c?) */

extern int
handle_waitstatus (struct child_process *process, union wait w)
{
  if (WIFEXITED (w))
    {
      if (process->debug_informational)
	fprintf (stderr, "\nChild %d exited with retcode = %d\n", 
		 process->pid, WEXITSTATUS (w));
      process->stop_status = 'W';
      return (process->stop_signal = WEXITSTATUS (w));
    }
  else if (!WIFSTOPPED (w))
    {
      if (process->debug_informational)
	fprintf (stderr, "\nChild %d terminated with signal = %d\n", 
		 process->pid, WTERMSIG (w));
      process->stop_status = 'X';
      return (process->stop_signal = WTERMSIG (w));
    }

#if defined(_MIPSEL) || defined(_MIPSEB) || defined(AM33_2_0_LINUX_TARGET)
  /*
   * If we were single_stepping, restore the opcodes hoisted
   * for the breakpoint[s].
   */
  if (process->is_ss)
    {
      int i;
      for (i = 0; i < 2; i++)
	if (process->ss_info[i].in_use)
	  {
	    ptrace_set_mem (process->serv,
	                    &process->ss_info[i].ss_addr,
			    process->ss_info[i].ss_val,
			    process->ss_info[i].ss_size);

	    /* Perform additional actions associated with this breakpoint.  */
	    if (process->ss_info[i].restore_action)
	      process->ss_info[i].restore_action (process->serv,
	                                          &process->ss_info[i]);

	    process->ss_info[i].in_use = 0;

	    if (process->debug_backend)
	      {
		long addr;
		gdbserv_host_bytes_from_reg (process->serv, &addr,
		                             sizeof (addr),
		                             &process->ss_info[i].ss_addr, 0);
		fprintf (stderr,
		         "Singlestep breakpoint %d cleared at location %lx\n",
			 i, addr);
	      }
	  }
      process->is_ss = 0;
    }
#endif /* _MIPSEL */

  process->stop_status = 'T';
  process->stop_signal = WSTOPSIG (w);
  return process->stop_signal;
}

static void
ptrace_kill_program (struct child_process *process, int signum)
{
  if (process->debug_backend)
    fprintf (stderr, "KILL %d, %d\n", process->pid, signum);
  kill (process->pid, signum);
}

/*
 * Exported functions
 */

/* Read user memory
 *
 * Returns 0 for success, errno for failure
 */

extern int
ptrace_read_user (struct gdbserv *serv,
		  int pid, 
		  ptrace_arg3_type addr, 
		  int len, 
		  void *buff)
{
  int i;

  /* Require: addr is on the proper boundary, and 
     len is a proper multiple of PTRACE_XFER_SIZE.  
     Caller's responsibility.  */

  for (i = 0; i < len; i+= PTRACE_XFER_SIZE)
    {
      errno = 0;
      *(ptrace_xfer_type *) &((char *)buff)[i] =
	ptrace (PTRACE_PEEKUSER, pid, addr + i, 0);
#if 0 /* too noisy!  */
      if (process->debug_backend)
	fprintf (stderr, "PTRACE_PEEKUSER 0x%08llx in %d, 0x%08llx\n", 
		 (long long) addr + i, pid,
	         (long long) * (ptrace_xfer_type *) &((char *)buff)[i]);
#endif
      if (errno != 0)
	return errno;
    }
  return 0;
}

/* Write user memory
 *
 * Returns 0 for success, errno for failure
 */

extern int
ptrace_write_user (struct gdbserv *serv,
		   int pid, 
		   ptrace_arg3_type addr, 
		   int len, 
		   const void *buff)
{
  struct child_process *process = gdbserv_target_data (serv);
  int i;

  /* Require: addr is on the proper boundary, and 
     len is a proper multiple of PTRACE_XFER_SIZE.  
     Caller's responsibility.  */

  for (i = 0; i < len; i+= PTRACE_XFER_SIZE)
    {
#ifdef X86_LINUX_TARGET
      if (addr + i == 44)
	continue;	/* Forbidden address/register, not writable. */
#endif
      errno = 0;
      ptrace (PTRACE_POKEUSER, pid, addr + i, 
	      * (ptrace_xfer_type *) &((char *)buff)[i]);
      if (process->debug_backend)
	fprintf (stderr, "PTRACE_POKEUSER 0x%08llx in %d, 0x%08llx\n", 
		 (long long) addr + i, pid,
	         (long long) * (ptrace_xfer_type *) &((char *)buff)[i]);
#if defined(_MIPSEL) || defined(MIPS_LINUX_TARGET)
      /* mips linux kernel 2.4 has a bug where PTRACE_POKEUSER
        returns -ESRCH even when it succeeds */
      if (errno == ESRCH)
	errno = 0;
#endif
      if (errno != 0)
	return errno;
    }
  return 0;
}

#if defined (PTRACE_GETREGS) || defined (PT_GETREGS)

/* get general regs */

int
ptrace_get_gregs (struct gdbserv *serv, int alt_pid, void *buff)
{
  struct child_process *process = gdbserv_target_data (serv);
  int pid = alt_pid == 0 ? process->pid : alt_pid;

  /* Require: buff is of the appropriate size for the target arch. */

  errno = 0;
  ptrace (PTRACE_GETREGS, pid, 0, (ptrace_arg4_type) buff);
  return errno;
}
#endif

#if defined (PTRACE_SETREGS) || defined (PT_SETREGS)
/* set general regs */

int
ptrace_set_gregs (struct gdbserv *serv, int alt_pid, const void *buff)
{
  struct child_process *process = gdbserv_target_data (serv);
  int pid = alt_pid == 0 ? process->pid : alt_pid;

  /* Require: buff is of the appropriate size for the target arch. */

  errno = 0;
  ptrace (PTRACE_SETREGS, pid, 0, (ptrace_arg4_type) buff);
  return errno;
}
#endif


/* get floating point regs */

extern int
ptrace_get_fpregs (struct gdbserv *serv, int alt_pid, void *buff)
{
#if defined (PTRACE_GETFPREGS) || defined (PT_GETFPREGS)
  struct child_process *process = gdbserv_target_data (serv);
  int pid = alt_pid == 0 ? process->pid : alt_pid;

  /* Require: buff is of the appropriate size for the target arch. */

  errno = 0;
  ptrace (PTRACE_GETFPREGS, pid, 0, (ptrace_arg4_type) buff);
  return errno;
#else
  return -1;
#endif
}


/* set floating point regs */

extern int
ptrace_set_fpregs (struct gdbserv *serv, int alt_pid, const void *buff)
{
#if defined (PTRACE_SETFPREGS) || defined (PT_SETFPREGS)
  struct child_process *process = gdbserv_target_data (serv);
  int pid = alt_pid == 0 ? process->pid : alt_pid;

  /* Require: buff is of the appropriate size for the target arch. */

  errno = 0;
  ptrace (PTRACE_SETFPREGS, pid, 0, (ptrace_arg4_type) buff);
  return errno;
#else
  return -1;
#endif
}


/* get extended floating point regs */

int
ptrace_get_fpxregs (struct gdbserv *serv, int alt_pid, void *buff)
{
#if defined (PTRACE_GETFPXREGS) || defined (PT_GETFPXREGS)
  struct child_process *process = gdbserv_target_data (serv);
  int pid = alt_pid == 0 ? process->pid : alt_pid;

  /* Require: buff is of the appropriate size for the target arch. */

  errno = 0;
  ptrace (PTRACE_GETFPXREGS, pid, 0, (ptrace_arg4_type) buff);
  return errno;
#else
  return -1;
#endif
}


/* set extended floating point regs */

int
ptrace_set_fpxregs (struct gdbserv *serv, int alt_pid, const void *buff)
{
#if defined (PTRACE_SETFPXREGS) || defined (PT_SETFPXREGS)
  struct child_process *process = gdbserv_target_data (serv);
  int pid = alt_pid == 0 ? process->pid : alt_pid;

  /* Require: buff is of the appropriate size for the target arch. */

  errno = 0;
  ptrace (PTRACE_SETFPXREGS, pid, 0, (ptrace_arg4_type) buff);
  return errno;
#else
  return -1;
#endif
}

/* target vector: */

static void
ptrace_flush_i_cache (struct gdbserv *serv)
{
  /* Calls to ptrace() take care of this for us automatically when
     needed.  I.e, nothing to do...  */
  return;
}

/* sigkill vector
 */

static void
ptrace_sigkill_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  ptrace_kill_program (process, SIGKILL);
}

/* exit program vector
 */
static void
ptrace_exit_program (struct gdbserv *serv)
{
  ptrace_sigkill_program (serv);
  gdbserv_fromtarget_exit (serv, GDBSERV_SIGKILL);
  /* Quit out of main loop.  */
  server_quit_p = 1;
}

/* break program vector
 */

static void
ptrace_break_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* We send SIGSTOP (rather than some other signal such as SIGINT)
     because SIGSTOP cannot be blocked or ignored.  */
  if (process->debug_backend)
    fprintf (stderr, " -- send SIGSTOP to child %d\n", process->pid);
  print_sigstop_message (serv);
  kill (process->pid, SIGSTOP);
}

/* get_trap_number vector
 */

static unsigned long
ptrace_get_trap_number (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  return process->stop_signal;
}

/* compute signal vector
 * No translation necessary -- using unix native signals .
 */

static unsigned long
ptrace_compute_signal (struct gdbserv *serv, unsigned long tgtsig)
{
  if (tgtsig == 0)
    return GDBSERV_SIGNONE;
#ifdef SIGHUP
  if (tgtsig == SIGHUP)
    return GDBSERV_SIGHUP;
#endif
#ifdef SIGINT
  if (tgtsig == SIGINT)
    return GDBSERV_SIGINT;
#endif
#ifdef SIGQUIT
  if (tgtsig == SIGQUIT)
    return GDBSERV_SIGQUIT;
#endif
#ifdef SIGILL
  if (tgtsig == SIGILL)
    return GDBSERV_SIGILL;
#endif
#ifdef SIGTRAP
  if (tgtsig == SIGTRAP)
    return GDBSERV_SIGTRAP;
#endif
#ifdef SIGABRT
  if (tgtsig == SIGABRT)
    return GDBSERV_SIGABRT;
#endif
#ifdef SIGIOT
  if (tgtsig == SIGIOT)
    return GDBSERV_SIGABRT;
#endif
#ifdef SIGEMT
  if (tgtsig == SIGEMT)
    return GDBSERV_SIGEMT;
#endif
#ifdef SIGFPE
  if (tgtsig == SIGFPE)
    return GDBSERV_SIGFPE;
#endif
#ifdef SIGKILL
  if (tgtsig == SIGKILL)
    return GDBSERV_SIGKILL;
#endif
#ifdef SIGBUS
  if (tgtsig == SIGBUS)
    return GDBSERV_SIGBUS;
#endif
#ifdef SIGSEGV
  if (tgtsig == SIGSEGV)
    return GDBSERV_SIGSEGV;
#endif
#ifdef SIGSYS
  if (tgtsig == SIGSYS)
    return GDBSERV_SIGSYS;
#endif
#ifdef SIGPIPE
  if (tgtsig == SIGPIPE)
    return GDBSERV_SIGPIPE;
#endif
#ifdef SIGALRM
  if (tgtsig == SIGALRM)
    return GDBSERV_SIGALRM;
#endif
#ifdef SIGTERM
  if (tgtsig == SIGTERM)
    return GDBSERV_SIGTERM;
#endif
#ifdef SIGURG
  if (tgtsig == SIGURG)
    return GDBSERV_SIGURG;
#endif
#ifdef SIGSTOP
  if (tgtsig == SIGSTOP)
    return GDBSERV_SIGSTOP;
#endif
#ifdef SIGTSTP
  if (tgtsig == SIGTSTP)
    return GDBSERV_SIGTSTP;
#endif
#ifdef SIGCONT
  if (tgtsig == SIGCONT)
    return GDBSERV_SIGCONT;
#endif
#ifdef SIGCHLD
  if (tgtsig == SIGCHLD)
    return GDBSERV_SIGCHLD;
#endif
#ifdef SIGCLD
  if (tgtsig == SIGCLD)
    return GDBSERV_SIGCHLD;
#endif
#ifdef SIGTTIN
  if (tgtsig == SIGTTIN)
    return GDBSERV_SIGTTIN;
#endif
#ifdef SIGTTOU
  if (tgtsig == SIGTTOU)
    return GDBSERV_SIGTTOU;
#endif
#ifdef SIGIO
  if (tgtsig == SIGIO)
    return GDBSERV_SIGIO;
#endif
#ifdef SIGXCPU
  if (tgtsig == SIGXCPU)
    return GDBSERV_SIGXCPU;
#endif
#ifdef SIGXFSZ
  if (tgtsig == SIGXFSZ)
    return GDBSERV_SIGXFSZ;
#endif
#ifdef SIGVTALRM
  if (tgtsig == SIGVTALRM)
    return GDBSERV_SIGVTALRM;
#endif
#ifdef SIGPROF
  if (tgtsig == SIGPROF)
    return GDBSERV_SIGPROF;
#endif
#ifdef SIGWINCH
  if (tgtsig == SIGWINCH)
    return GDBSERV_SIGWINCH;
#endif
#ifdef SIGLOST
  if (tgtsig == SIGLOST)
    return GDBSERV_SIGLOST;
#endif
#ifdef SIGUSR1
  if (tgtsig == SIGUSR1)
    return GDBSERV_SIGUSR1;
#endif
#ifdef SIGUSR2
  if (tgtsig == SIGUSR2)
    return GDBSERV_SIGUSR2;
#endif
#ifdef SIGPWR
  if (tgtsig == SIGPWR)
    return GDBSERV_SIGPWR;
#endif
#ifdef SIGPOLL
  if (tgtsig == SIGPOLL)
    return GDBSERV_SIGPOLL;
#endif
#ifdef SIGWIND
  if (tgtsig == SIGWIND)
    return GDBSERV_SIGWIND;
#endif
#ifdef SIGPHONE
  if (tgtsig == SIGPHONE)
    return GDBSERV_SIGPHONE;
#endif
#ifdef SIGWAITING
  if (tgtsig == SIGWAITING)
    return GDBSERV_SIGWAITING;
#endif
#ifdef SIGLWP
  if (tgtsig == SIGLWP)
    return GDBSERV_SIGLWP;
#endif
#ifdef SIGDANGER
  if (tgtsig == SIGDANGER)
    return GDBSERV_SIGDANGER;
#endif
#ifdef SIGGRANT
  if (tgtsig == SIGGRANT)
    return GDBSERV_SIGGRANT;
#endif
#ifdef SIGRETRACT
  if (tgtsig == SIGRETRACT)
    return GDBSERV_SIGRETRACT;
#endif
#ifdef SIGMSG
  if (tgtsig == SIGMSG)
    return GDBSERV_SIGMSG;
#endif
#ifdef SIGSOUND
  if (tgtsig == SIGSOUND)
    return GDBSERV_SIGSOUND;
#endif
#ifdef SIGSAC
  if (tgtsig == SIGSAC)
    return GDBSERV_SIGSAC;
#endif
#ifdef SIGPRIO
  if (tgtsig == SIGPRIO)
    return GDBSERV_SIGPRIO;
#endif
#ifdef SIGSTKFLT
  if (tgtsig == SIGSTKFLT)
    return GDBSERV_SIGSEGV;	/* ? */
#endif
#ifdef SIGPWR
  if (tgtsig == SIGPWR)
    return GDBSERV_SIGPWR;
#endif
#if defined (__SIGRTMIN) && defined (__SIGRTMAX)
    if (tgtsig >= __SIGRTMIN && tgtsig <  __SIGRTMAX)
      return GDBSERV_SIGRT32 + tgtsig - __SIGRTMIN;
    return GDBSERV_SIGNONE;	/* ? */
#endif
}

/* singlestep vector
 */

static void
ptrace_singlestep_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* FIXME: handle signals! */
  if (process->debug_backend)
    fprintf (stderr, "PTRACE_SINGLESTEP %d signal %ld\n", 
	     process->pid, process->signal_to_send);
  process->stop_signal = 0;
  process->stop_status = 0;

  errno = 0;
  ptrace (PTRACE_SINGLESTEP, process->pid, 1L, process->signal_to_send);
  if (errno)
    fprintf (stderr, "singlestep: ptrace error %s in %d\n",
	     strerror (errno), process->pid);
  process->signal_to_send = 0;
}

/*
 * Continue vector
 */

static void 
ptrace_continue_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* FIXME: handle signals! */
  if (process->debug_backend)
    fprintf (stderr, "PTRACE_CONT %d signal %ld\n", 
	     process->pid, process->signal_to_send);
  process->stop_signal = 0;
  process->stop_status = 0;

  errno = 0;
  ptrace (PTRACE_CONT, process->pid, 1L, process->signal_to_send);
  if (errno)
    fprintf (stderr, "continue: ptrace error %s in %d\n", 
	     strerror (errno), process->pid);
  process->signal_to_send = 0;
}

/* Set continue-signal vector 
 */

static int
ptrace_process_signal (struct gdbserv *serv, int sig)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* Save the signal value for later use by continue/singlestep.  */
  switch (sig) {
  case GDBSERV_SIGNONE:
    process->signal_to_send = 0;		break;
#ifdef SIGHUP
  case GDBSERV_SIGHUP:
    process->signal_to_send = SIGHUP;		break;
#endif
#ifdef SIGINT
  case GDBSERV_SIGINT:
    process->signal_to_send = SIGINT;		break;
#endif
#ifdef SIGQUIT
  case GDBSERV_SIGQUIT:
    process->signal_to_send = SIGQUIT;		break;
#endif
#ifdef SIGILL
  case GDBSERV_SIGILL:
    process->signal_to_send = SIGILL;		break;
#endif
#ifdef SIGTRAP
  case GDBSERV_SIGTRAP:
    process->signal_to_send = SIGTRAP;		break;
#endif
#ifdef SIGABRT
  case GDBSERV_SIGABRT:
    process->signal_to_send = SIGABRT;		break;
#endif
#ifdef SIGEMT
  case GDBSERV_SIGEMT:
    process->signal_to_send = SIGEMT;		break;
#endif
#ifdef SIGFPE
  case GDBSERV_SIGFPE:
    process->signal_to_send = SIGFPE;		break;
#endif
#ifdef SIGKILL
  case GDBSERV_SIGKILL:
    process->signal_to_send = SIGKILL;		break;
#endif
#ifdef SIGBUS
  case GDBSERV_SIGBUS:
    process->signal_to_send = SIGBUS;		break;
#endif
#ifdef SIGSEGV
  case GDBSERV_SIGSEGV:
    process->signal_to_send = SIGSEGV;		break;
#endif
#ifdef SIGSYS
  case GDBSERV_SIGSYS:
    process->signal_to_send = SIGSYS;		break;
#endif
#ifdef SIGPIPE
  case GDBSERV_SIGPIPE:
    process->signal_to_send = SIGPIPE;		break;
#endif
#ifdef SIGALRM
  case GDBSERV_SIGALRM:
    process->signal_to_send = SIGALRM;		break;
#endif
#ifdef SIGTERM
  case GDBSERV_SIGTERM:
    process->signal_to_send = SIGTERM;		break;
#endif
#ifdef SIGURG
  case GDBSERV_SIGURG:
    process->signal_to_send = SIGURG;		break;
#endif
#ifdef SIGSTOP
  case GDBSERV_SIGSTOP:
    process->signal_to_send = SIGSTOP;		break;
#endif
#ifdef SIGTSTP
  case GDBSERV_SIGTSTP:
    process->signal_to_send = SIGTSTP;		break;
#endif
#ifdef SIGCONT
  case GDBSERV_SIGCONT:
    process->signal_to_send = SIGCONT;		break;
#endif
#ifdef SIGCHLD
  case GDBSERV_SIGCHLD:
    process->signal_to_send = SIGCHLD;		break;
#endif
#if defined (SIGCLD) && !defined (SIGCHLD)
  case GDBSERV_SIGCHLD:
    process->signal_to_send = SIGCLD;		break;
#endif
#ifdef SIGTTIN
  case GDBSERV_SIGTTIN:
    process->signal_to_send = SIGTTIN;		break;
#endif
#ifdef SIGTTOU
  case GDBSERV_SIGTTOU:
    process->signal_to_send = SIGTTOU;		break;
#endif
#ifdef SIGIO
  case GDBSERV_SIGIO:
    process->signal_to_send = SIGIO;		break;
#endif
#ifdef SIGXCPU
  case GDBSERV_SIGXCPU:
    process->signal_to_send = SIGXCPU;		break;
#endif
#ifdef SIGXFSZ
  case GDBSERV_SIGXFSZ:
    process->signal_to_send = SIGXFSZ;		break;
#endif
#ifdef SIGVTALRM
  case GDBSERV_SIGVTALRM:
    process->signal_to_send = SIGVTALRM;	break;
#endif
#ifdef SIGPROF
  case GDBSERV_SIGPROF:
    process->signal_to_send = SIGPROF;		break;
#endif
#ifdef SIGWINCH
  case GDBSERV_SIGWINCH:
    process->signal_to_send = SIGWINCH;		break;
#endif
#ifdef SIGLOST
  case GDBSERV_SIGLOST:
    process->signal_to_send = SIGLOST;		break;
#endif
#ifdef SIGUSR1
  case GDBSERV_SIGUSR1:
    process->signal_to_send = SIGUSR1;		break;
#endif
#ifdef SIGUSR2
  case GDBSERV_SIGUSR2:
    process->signal_to_send = SIGUSR2;		break;
#endif
#ifdef SIGPWR
  case GDBSERV_SIGPWR:
    process->signal_to_send = SIGPWR;		break;
#endif
#ifdef SIGPOLL
  case GDBSERV_SIGPOLL:
    process->signal_to_send = SIGPOLL;		break;
#endif
#ifdef SIGWIND
  case GDBSERV_SIGWIND:
    process->signal_to_send = SIGWIND;		break;
#endif
#ifdef SIGPHONE
  case GDBSERV_SIGPHONE:
    process->signal_to_send = SIGPHONE;		break;
#endif
#ifdef SIGWAITING
  case GDBSERV_SIGWAITING:
    process->signal_to_send = SIGWAITING;	break;
#endif
#ifdef SIGLWP
  case GDBSERV_SIGLWP:
    process->signal_to_send = SIGLWP;		break;
#endif
#ifdef SIGDANGER
  case GDBSERV_SIGDANGER:
    process->signal_to_send = SIGDANGER;	break;
#endif
#ifdef SIGGRANT
  case GDBSERV_SIGGRANT:
    process->signal_to_send = SIGGRANT;		break;
#endif
#ifdef SIGRETRACT
  case GDBSERV_SIGRETRACT:
    process->signal_to_send = SIGRETRACT;	break;
#endif
#ifdef SIGMSG
  case GDBSERV_SIGMSG:
    process->signal_to_send = SIGMSG;		break;
#endif
#ifdef SIGSOUND
  case GDBSERV_SIGSOUND:
    process->signal_to_send = SIGSOUND;		break;
#endif
#ifdef SIGSAK
  case GDBSERV_SIGSAK:
    process->signal_to_send = SIGSAK;		break;
#endif
#ifdef SIGPRIO
  case GDBSERV_SIGPRIO:
    process->signal_to_send = SIGPRIO;		break;
#endif
#if defined (__SIGRTMIN) && defined (__SIGRTMAX)
  case GDBSERV_SIGRT32:
    process->signal_to_send = __SIGRTMIN;	break;
  case GDBSERV_SIGRT33:
    process->signal_to_send = __SIGRTMIN+1;	break;
  case GDBSERV_SIGRT34:
    process->signal_to_send = __SIGRTMIN+2;	break;
  case GDBSERV_SIGRT35:
    process->signal_to_send = __SIGRTMIN+3;	break;
  case GDBSERV_SIGRT36:
    process->signal_to_send = __SIGRTMIN+4;	break;
  case GDBSERV_SIGRT37:
    process->signal_to_send = __SIGRTMIN+5;	break;
  case GDBSERV_SIGRT38:
    process->signal_to_send = __SIGRTMIN+6;	break;
  case GDBSERV_SIGRT39:
    process->signal_to_send = __SIGRTMIN+7;	break;
  case GDBSERV_SIGRT40:
    process->signal_to_send = __SIGRTMIN+8;	break;
  case GDBSERV_SIGRT41:
    process->signal_to_send = __SIGRTMIN+9;	break;
  case GDBSERV_SIGRT42:
    process->signal_to_send = __SIGRTMIN+10;	break;
  case GDBSERV_SIGRT43:
    process->signal_to_send = __SIGRTMIN+11;	break;
  case GDBSERV_SIGRT44:
    process->signal_to_send = __SIGRTMIN+12;	break;
  case GDBSERV_SIGRT45:
    process->signal_to_send = __SIGRTMIN+13;	break;
  case GDBSERV_SIGRT46:
    process->signal_to_send = __SIGRTMIN+14;	break;
  case GDBSERV_SIGRT47:
    process->signal_to_send = __SIGRTMIN+15;	break;
  case GDBSERV_SIGRT48:
    process->signal_to_send = __SIGRTMIN+16;	break;
  case GDBSERV_SIGRT49:
    process->signal_to_send = __SIGRTMIN+17;	break;
  case GDBSERV_SIGRT50:
    process->signal_to_send = __SIGRTMIN+18;	break;
  case GDBSERV_SIGRT51:
    process->signal_to_send = __SIGRTMIN+19;	break;
  case GDBSERV_SIGRT52:
    process->signal_to_send = __SIGRTMIN+20;	break;
  case GDBSERV_SIGRT53:
    process->signal_to_send = __SIGRTMIN+21;	break;
  case GDBSERV_SIGRT54:
    process->signal_to_send = __SIGRTMIN+22;	break;
  case GDBSERV_SIGRT55:
    process->signal_to_send = __SIGRTMIN+23;	break;
  case GDBSERV_SIGRT56:
    process->signal_to_send = __SIGRTMIN+24;	break;
  case GDBSERV_SIGRT57:
    process->signal_to_send = __SIGRTMIN+25;	break;
  case GDBSERV_SIGRT58:
    process->signal_to_send = __SIGRTMIN+26;	break;
  case GDBSERV_SIGRT59:
    process->signal_to_send = __SIGRTMIN+27;	break;
  case GDBSERV_SIGRT60:
    process->signal_to_send = __SIGRTMIN+28;	break;
  case GDBSERV_SIGRT61:
    process->signal_to_send = __SIGRTMIN+29;	break;
  case GDBSERV_SIGRT62:
    process->signal_to_send = __SIGRTMIN+30;	break;
  case GDBSERV_SIGRT63:
    process->signal_to_send = __SIGRTMIN+31;	break;
  case GDBSERV_SIGRT64:
    process->signal_to_send = __SIGRTMIN+32;	break;
#endif
  }
  /* Since we will handle the signal, we don't want gdbserv
     to handle it by calling kill!  Return zero.  */
  return 0;
}

/* Read memory vector
 */

static long
ptrace_xfer_mem (struct gdbserv *serv, 
		 struct gdbserv_reg *addr, 
		 void *data, 
		 long len, 
		 int read)
{
  struct child_process *process = gdbserv_target_data (serv);
  ptrace_arg3_type request_base;
  ptrace_arg3_type xfer_base;
  ptrace_arg3_type temp_addr;
  ptrace_xfer_type *buf;
  long xfer_count;
  int i;

  /* Get request address.  */
  gdbserv_host_bytes_from_reg (serv, &request_base, sizeof (request_base),
                               addr, 0);
  /* Round down to a PTRACE word boundary. */
  xfer_base = request_base & - PTRACE_XFER_SIZE;
  /* Round length up to a PTRACE word boundary. */
  xfer_count = (((request_base + len) - xfer_base) + PTRACE_XFER_SIZE - 1)
    / PTRACE_XFER_SIZE;

  /* Allocate space for xfer.  */
  buf = (ptrace_xfer_type *) alloca (xfer_count * PTRACE_XFER_SIZE);

  /* Perform memory xfer.  */
  if (read)
    {
      for (i = 0; i < xfer_count; i++)
	{
	  temp_addr = xfer_base + i * PTRACE_XFER_SIZE;

	  errno = 0;
	  buf[i] = ptrace (PTRACE_PEEKTEXT, process->pid, temp_addr, 0L);

	  if (process->debug_backend)
	    fprintf (stderr, "PTRACE_PEEKTEXT-1 0x%08llx in %d, 0x%08llx\n", 
		     (long long) temp_addr, process->pid, (long long) buf[i]);
	  if (errno)
	    {
	      if (errno != EIO)
		fprintf (stderr, 
			 "xfer_mem(1): ptrace error at 0x%08lx in %d: %s\n", 
			 (long) temp_addr, process->pid, strerror (errno));
	      return -1;
	    }
	}
  
      /* Copy results to caller's buffer space.  */
      memcpy (data, (char *) buf + (request_base - xfer_base), len);
    }
  else /* write */
    {
      /* If the xfer buffer overlaps the write-request buffer, 
	 we must first read the values that are there before 
	 replacing with the desired values (otherwise these bytes
	 would be uninitialized).  */
      if ((unsigned long long) xfer_base < 
	  (unsigned long long) request_base)
	{
	  errno = 0;
	  buf[0] = ptrace (PTRACE_PEEKTEXT, 
			   process->pid, xfer_base, 0L);
	  if (process->debug_backend)
	    fprintf (stderr, "PTRACE_PEEKTEXT-2 0x%08llx in %d, 0x%08llx\n", 
		     (long long) xfer_base, process->pid, (long long) buf[0]);

	  if (errno)
	    {
	      if (errno != EIO)
		fprintf (stderr, 
			 "xfer_mem(2): ptrace error at 0x%08llx in %d: %s\n", 
			 (long long) xfer_base, process->pid, strerror (errno));
	      return -1;
	    }
	}
      if ((xfer_count > 0) &&
	  ((unsigned long long) (xfer_base + xfer_count * PTRACE_XFER_SIZE) > 
	   (unsigned long long) (request_base + len)))
	{
	  temp_addr = xfer_base + (xfer_count - 1) * PTRACE_XFER_SIZE;
	  errno = 0;
	  buf[xfer_count - 1] =
	    ptrace (PTRACE_PEEKTEXT, process->pid, temp_addr, 0L);
	  if (process->debug_backend)
	    fprintf (stderr, "PTRACE_PEEKTEXT-3 0x%08llx in %d, 0x%08llx\n", 
		     (long long) temp_addr, process->pid, 
		     (long long) buf[xfer_count - 1]);

	  if (errno)
	    {
	      if (errno != EIO)
		fprintf (stderr, 
			 "xfer_mem(3): ptrace error at 0x%08lx in %d: %s\n", 
			 (long) temp_addr, process->pid, strerror (errno));
	      return -1;
	    }
	}

      /* Now copy user buffer to xfer buffer.  */
      memcpy ((char *) buf + (request_base - xfer_base), data, len);
      /* Now write out the data.  */
      for (i = 0; i < xfer_count; i++)
	{
	  temp_addr = xfer_base + i * PTRACE_XFER_SIZE;

	  errno = 0;
	  ptrace (PTRACE_POKETEXT, process->pid, temp_addr, buf[i]);

	  if (process->debug_backend)
	    fprintf (stderr, "PTRACE_POKETEXT 0x%08llx in %d, 0x%08llx\n", 
		     (long long) temp_addr, process->pid, (long long) buf[i]);

	  if (errno)
	    {
	      if (errno != EIO)
		fprintf (stderr, 
			 "xfer_mem(4): ptrace error at 0x%08llx in %d: %s\n", 
			 (long long) temp_addr, process->pid, strerror (errno));
	      return -1;
	    }
	}
    }

  return len;
}

long
ptrace_set_mem (struct gdbserv *serv, 
		struct gdbserv_reg *addr, 
		void *data, 
		long len)
{
  return ptrace_xfer_mem (serv, addr, data, len, 0);
}

long
ptrace_get_mem (struct gdbserv *serv, 
		struct gdbserv_reg *addr, 
		void *data, 
		long len)
{
  return ptrace_xfer_mem (serv, addr, data, len, 1);
}




/* Detach vector -- shut down this target connection.
 */

static void
ptrace_detach (struct gdbserv *serv, struct gdbserv_target *target)
{
  struct child_process *process = gdbserv_target_data (serv);

  assert (ptrace_connect_lock == serv);

  if (process->debug_informational)
    fprintf (stderr, "ptrace - detached.\n");
  ptrace_connect_lock = NULL;

  /* Quit out of main loop for this demo.  In general, this is not
     necessary, as the next incoming connection could again be handled
     by ptrace_attach() above.  */
  server_quit_p = 1;
}

/* This function is called from gdbloop_poll when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted.  */

struct gdbserv_target* 
ptrace_attach (struct gdbserv *serv, void *data)
{
  struct gdbserv_target *ptrace_target;
  struct child_process *process = data;
  union wait w;
  int pid;


  /* Enable server tracing. */
  /*  gdbserv_state_trace = stderr;*/

  if (ptrace_connect_lock != NULL)
    {
      fprintf (stderr, "ptrace: rejected duplicate connection.\n");
      return NULL;
    }

  if (process->debug_informational)
    fprintf (stderr, "ptrace: accepted gdb connection.\n");
  ptrace_connect_lock = serv;

  process->pid = ptrace_create_child (process);

  do {
    pid = wait (&w);
  } while (pid != process->pid);

  handle_waitstatus (process, w);

  if (process->pid > 0)
    {
      if (process->debug_informational)
	fprintf (stderr, "ptrace: created child process %d, %s\n", 
		 process->pid, process->executable);
    }
  else
    {
      fprintf (stderr, "PTRACE: failed to create child process %s!\n",
	       process->executable);
      return NULL;
    }

  ptrace_target = malloc (sizeof (struct gdbserv_target));
  memset (ptrace_target, 0, sizeof (*ptrace_target));

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  ptrace_target->process_get_gen       = NULL;
  ptrace_target->process_set_gen       = NULL;
  ptrace_target->process_rcmd          = NULL;
  ptrace_target->process_set_args      = NULL;
  ptrace_target->process_set_reg       = NULL;
  ptrace_target->process_get_reg       = NULL;
  ptrace_target->process_set_regs      = NULL;
  ptrace_target->process_get_regs      = NULL;
  ptrace_target->input_reg             = NULL;
  ptrace_target->output_reg            = NULL;
  ptrace_target->gg_reg_nr             = NULL;
  ptrace_target->expedited_reg_nr      = NULL;
  ptrace_target->sizeof_reg            = NULL;
  ptrace_target->set_reg               = NULL;
  ptrace_target->get_reg               = NULL;
  ptrace_target->get_mem               = ptrace_get_mem;
  ptrace_target->set_mem               = ptrace_set_mem;
  ptrace_target->process_set_pc        = NULL;
  ptrace_target->flush_i_cache         = ptrace_flush_i_cache;
  ptrace_target->process_signal        = ptrace_process_signal;
  ptrace_target->compute_signal        = ptrace_compute_signal;
  ptrace_target->get_trap_number       = ptrace_get_trap_number;
  ptrace_target->exit_program          = ptrace_exit_program;
  ptrace_target->break_program         = ptrace_break_program;
  ptrace_target->reset_program         = NULL;
  ptrace_target->restart_program       = NULL;
  ptrace_target->singlestep_program    = ptrace_singlestep_program;
  ptrace_target->cyclestep_program     = NULL;
  ptrace_target->sigkill_program       = ptrace_sigkill_program;
  ptrace_target->continue_program      = ptrace_continue_program;
  ptrace_target->remove_breakpoint     = NULL;
  ptrace_target->set_breakpoint        = NULL;
  ptrace_target->process_target_packet = NULL;
  ptrace_target->detach                = ptrace_detach;

  ptrace_target->data = data;	/* Save ptr to child_process struct.  */

#if defined(_MIPSEL) || defined(_MIPSEB) || defined(AM33_2_0_LINUX_TARGET)
  process->is_ss = 0;
#endif

  return ptrace_target;
}

/* This function is called from the main loop, and waits for an event
   (such as a signal or exception) from the running child process. */

int
ptrace_check_child_state (struct child_process *process)
{
  int ret;
  union wait w;

  ret = waitpid (process->pid, (int *) &w, WNOHANG);

  if (ret > 0)	/* found an event */
    {
      ret = handle_waitstatus (process, w);
      if (process->debug_backend)
	fprintf (stderr, "wait returned %d\n", ret);
      return 1;
    }
  return 0;
}

/* Exported service functions; see "lwp-ctrl.h".  */

int
continue_lwp (pid_t lwp, int signal)
{
  if (thread_db_noisy)
    fprintf (stderr, "<ptrace (PTRACE_CONT, %d, 0, %d)>\n", lwp, signal);

  if (ptrace (PTRACE_CONT, lwp, 0, signal) < 0)
    {
      fprintf (stderr, "<<< ERROR: PTRACE_CONT %d failed: %s >>>\n", 
	       lwp, strerror (errno));
      return -1;
    }
  return 0;
}

int
singlestep_lwp (struct gdbserv *serv, pid_t lwp, int signal)
{

#if defined (AM33_2_0_LINUX_TARGET)
  if (thread_db_noisy)
    fprintf (stderr, "<singlestep_lwp lwpid=%d signal=%d>\n", lwp, signal);
  am33_singlestep (serv, lwp, signal);
  return 0;
#elif defined (MIPS_LINUX_TARGET) || defined (MIPS64_LINUX_TARGET)
  if (thread_db_noisy)
    fprintf (stderr, "<singlestep_lwp lwpid=%d signal=%d>\n", lwp, signal);
  mips_singlestep (serv, lwp, signal);
#else
  if (thread_db_noisy)
    fprintf (stderr, "<ptrace (PTRACE_SINGLESTEP, %d, 0, %d)>\n", lwp, signal);

  if (ptrace (PTRACE_SINGLESTEP, lwp, 0, signal) < 0)
    {
      int saved_errno = errno;

      fprintf (stderr, "<<< ERROR: PTRACE_SINGLESTEP %d failed: %s >>>\n",
	       lwp, strerror (errno));
      
      errno = saved_errno;
      return -1;
    }
#endif
  return 0;
}

int
attach_lwp (pid_t lwp)
{
  errno = 0;
  if (ptrace (PTRACE_ATTACH, lwp, 0, 0) == 0)
    {
      if (thread_db_noisy)
	fprintf (stderr, "<ptrace (PTRACE_ATTACH, %d, 0, 0)>\n", lwp);
      return 0;
    }
  else
    {
      int saved_errno = errno;

      fprintf (stderr, "<<< ERROR ptrace attach %d failed, %s >>>\n",
	       lwp, strerror (errno));

      errno = saved_errno;
      return -1;
    }
}


int
kill_lwp (pid_t lwp, int signal)
{
  int result;

  if (thread_db_noisy)
    fprintf (stderr, "kill_lwp (%d, %d)\n", (int) lwp, signal);

  /* Under NPTL, signals sent via kill get delivered to whatever
     thread in the group can handle them; they don't necessarily go to
     the thread whose PID you passed.  This makes kill useless for
     kill_lwp's purposes: it's trying to send a signal to a particular
     thread.

     The tkill system call lets you direct a signal at a particular
     thread.  Use that if it's available (as it is on all systems
     where it's necessary); otherwise, fall back to kill.  */
#ifdef SYS_tkill
  {
    /* This is true if we don't know for a fact that this kernel
       doesn't support tkill.  */
    static int could_have_tkill = 1;

    if (could_have_tkill)
      {
	errno = 0;
	result = syscall (SYS_tkill, lwp, signal);
	if (errno == 0)
	  return result;
	else if (errno == ENOSYS)
	  /* Fall through to kill, below, and don't try tkill again.  */
	  could_have_tkill = 0;
	else
	  {
	    int saved_errno = errno;

	    fprintf (stderr,
		     "<<< ERROR -- tkill (%d, %s) failed: %s >>>\n",
		     lwp, strsignal (signal), strerror (errno));

	    errno = saved_errno;
	    return -1;
	  }
      }
  }
#endif

  result = kill (lwp, signal);
  if (result != 0)
    {
      int saved_errno = errno;

      fprintf (stderr, "<<< ERROR -- kill (%d, %s) failed >>>\n", 
	       lwp, strsignal (signal));

      errno = saved_errno;
      return -1;
    }

  return 0;
}

/* proc_service callback functions */

ps_err_e
ps_pstop (gdb_ps_prochandle_t ph)		/* Process stop */
{
  fprintf (stderr, "<ps_pstop [UN-IMPLEMENTED]>\n");
  return PS_ERR; /* unimplemented. */
}

ps_err_e
ps_pcontinue (gdb_ps_prochandle_t ph)		/* Process continue */
{
  fprintf (stderr, "<ps_pcontinue [UN-IMPLEMENTED]>\n");
  return PS_ERR; /* unimplemented. */
}

ps_err_e
ps_lstop (gdb_ps_prochandle_t ph,		/* LWP stop */
	  lwpid_t lwpid)
{
  fprintf (stderr, "<ps_lstop [UN-IMPLEMENTED]>\n");
  return PS_ERR; /* unimplemented. */
}

ps_err_e
ps_lcontinue (gdb_ps_prochandle_t ph,		/* LWP continue */
	      lwpid_t lwpid)
{
  if (continue_lwp (lwpid, 0) < 0)
    return PS_OK;
  else
    return PS_ERR;
}

ps_err_e
ps_pdread (gdb_ps_prochandle_t ph, 	/* read from data segment */
	   paddr_t             addr,
	   gdb_ps_read_buf_t   buf,
	   gdb_ps_size_t       size)
{
  long bytes_read;
  struct gdbserv_reg addr_reg;

  /* Use unsigned long long for maximum portability. */
  gdbserv_ulonglong_to_reg (ph->serv, (unsigned long long) addr, &addr_reg);

  bytes_read = ptrace_get_mem (ph->serv, &addr_reg, buf, (long) size);

  if (bytes_read == (long) size)
    return PS_OK;
  else
    return PS_ERR;
}

ps_err_e
ps_pdwrite (gdb_ps_prochandle_t ph,	/* write to data segment */
	    paddr_t             addr,
	    gdb_ps_write_buf_t  buf,
	    gdb_ps_size_t       size)
{
  long bytes_written;
  struct gdbserv_reg addr_reg;

  /* Use unsigned long long for maximum portability. */
  gdbserv_ulonglong_to_reg (ph->serv, (unsigned long long) addr, &addr_reg);

  bytes_written = ptrace_set_mem (ph->serv, &addr_reg, buf, (long) size);

  if (bytes_written == (long) size)
    return PS_OK;
  else
    return PS_ERR;
}

ps_err_e
ps_ptread (gdb_ps_prochandle_t ph,	/* read from text segment */
	   paddr_t             addr,
	   gdb_ps_read_buf_t   buf,
	   gdb_ps_size_t       size)
{
  long bytes_read;
  struct gdbserv_reg addr_reg;

  /* Use unsigned long long for maximum portability. */
  gdbserv_ulonglong_to_reg (ph->serv, (unsigned long long) addr, &addr_reg);

  bytes_read = ptrace_get_mem (ph->serv, &addr_reg, buf, (long) size);

  if (bytes_read == (long) size)
    return PS_OK;
  else
    return PS_ERR;
}

ps_err_e
ps_ptwrite (gdb_ps_prochandle_t ph,	/* write to text segment */
	    paddr_t             addr,
	    gdb_ps_write_buf_t  buf,
	    gdb_ps_size_t       size)
{
  long bytes_written;
  struct gdbserv_reg addr_reg;

  /* Use unsigned long long for maximum portability. */
  gdbserv_ulonglong_to_reg (ph->serv, (unsigned long long) addr, &addr_reg);

  bytes_written = ptrace_set_mem (ph->serv, &addr_reg, buf, (long) size);

  if (bytes_written == (long) size)
    return PS_OK;
  else
    return PS_ERR;
}

