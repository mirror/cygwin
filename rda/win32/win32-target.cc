/* win32-target.cc

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

#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a win32 Cygwin gdbserv target that uses the RDA library to
   implement a remote gdbserver on a Win32 host.  It controls the
   process to be debugged on the Win32 host, allowing GDB to pull the
   strings from any host on the network (or on a serial port).  */

#if !HAVE_WINDOWS_H
#error The windows.h header is required when compiling for a Win32 target.
#endif
#include <windows.h>
#include <sys/cygwin.h>

#include "server.h"

/* This vector maps GDB's idea of a register's number into an address
   in the win32 exception context vector.

   It also contains the bit mask needed to load the register in question.

   One day we could read a reg, we could inspect the context we
   already have loaded, if it doesn't have the bit set that we need,
   we read that set of registers in using GetThreadContext.  If the
   context already contains what we need, we just unpack it. Then to
   write a register, first we have to ensure that the context contains
   the other regs of the group, and then we copy the info in and set
   out bit. */
#define context_offset(x) ((int)&(((CONTEXT *)NULL)->x))
static const int mappings[] =
{
  context_offset (Eax),
  context_offset (Ecx),
  context_offset (Edx),
  context_offset (Ebx),
  context_offset (Esp),
  context_offset (Ebp),
  context_offset (Esi),
  context_offset (Edi),
  context_offset (Eip),
  context_offset (EFlags),
  context_offset (SegCs),
  context_offset (SegSs),
  context_offset (SegDs),
  context_offset (SegEs),
  context_offset (SegFs),
  context_offset (SegGs),
  context_offset (FloatSave.RegisterArea[0 * 10]),
  context_offset (FloatSave.RegisterArea[1 * 10]),
  context_offset (FloatSave.RegisterArea[2 * 10]),
  context_offset (FloatSave.RegisterArea[3 * 10]),
  context_offset (FloatSave.RegisterArea[4 * 10]),
  context_offset (FloatSave.RegisterArea[5 * 10]),
  context_offset (FloatSave.RegisterArea[6 * 10]),
  context_offset (FloatSave.RegisterArea[7 * 10]),
  context_offset (FloatSave.ControlWord),
  context_offset (FloatSave.StatusWord),
  context_offset (FloatSave.TagWord),
  context_offset (FloatSave.ErrorSelector),
  context_offset (FloatSave.ErrorOffset),
  context_offset (FloatSave.DataSelector),
  context_offset (FloatSave.DataOffset),
  context_offset (FloatSave.ErrorSelector)
};
#undef context_offset

#define REG_SIZE     4
#define FP_REG_SIZE 10

#define FP_REG_0    16
#define FP_REG_7    23

#define SIZEOF_REGMAP  32

#define IS_REG(x)    ((x) >= 0 && (x) <= SIZEOF_REGMAP)
#define IS_FP_REG(x) ((x) >= FP_REG_0 && (x) <= FP_REG_7)

/* Track sole connection to a remote gdb client. */
/* FIXME: needed? */
static struct gdbserv *win32_connect_lock = NULL;

/* Retrieves the Cygwin PID which is attached to the windows PID. */
static pid_t
win32_get_cygwin_pid (DWORD winpid)
{
  external_pinfo *p;
  cygwin_getinfo_types query = CW_GETPINFO;

  cygwin_internal (CW_LOCK_PINFO, 1000);
  for (int pid = 0;
       (p = (external_pinfo *) cygwin_internal (query, pid | CW_NEXTPID));
       pid = p->pid)
    if (p->dwProcessId == winpid)
      break;
  cygwin_internal (CW_UNLOCK_PINFO);

  return p ? p->pid : 0;
}

inline child_process *
win32_get_process (struct gdbserv *serv)
{
  return (child_process *) gdbserv_target_data (serv);
}

extern "C" int
win32_process_get_reg (struct gdbserv *serv, int regno)
{
  child_process *process = win32_get_process (serv);

  process->fetch_regs ();
  if (!IS_REG (regno))
    { /* Illegal register number, return 0. */
      DWORD regval = 0;
      gdbserv_output_bytes (serv, (const char *) &regval, sizeof regval);
    }
  else
    gdbserv_output_bytes (serv,
    			  (char *) &process->context + mappings[regno],
			  IS_FP_REG (regno) ? FP_REG_SIZE : REG_SIZE);
  return 0;
}

extern "C" void
win32_process_get_regs (struct gdbserv *serv)
{
  int regno;

  for (regno = 0; regno < SIZEOF_REGMAP; regno++)
    win32_process_get_reg (serv, regno);
}

extern "C" int
win32_process_set_reg (struct gdbserv *serv, int regno)
{
  child_process *process = win32_get_process (serv);

  process->fetch_regs ();
  if (IS_REG (regno))
    gdbserv_input_bytes (serv,
			 (char *) &process->context + mappings[regno],
	      		 IS_FP_REG (regno) ? FP_REG_SIZE : REG_SIZE);
  return 0;
}

extern "C" int
win32_process_set_regs (struct gdbserv *serv)
{
  int regno;

  for (regno = 0; regno < SIZEOF_REGMAP; regno++)
    win32_process_set_reg (serv, regno);
  return 0;
}

extern "C" void
win32_process_set_pc (struct gdbserv *serv, const struct gdbserv_reg *addr)
{
  child_process *process = win32_get_process (serv);

  process->fetch_regs ();
  gdbserv_reg_to_ulong (serv, addr, &process->context.Eip);
}

static long
win32_xfer_mem (struct gdbserv *serv, 
		 struct gdbserv_reg *addr, 
		 void *data, 
		 long len, 
		 int read)
{
  child_process *process = win32_get_process (serv);
  DWORD tgtaddr;
  DWORD processed = 0;

  /* Get request address.  */
  gdbserv_reg_to_ulong (serv, addr, &tgtaddr);

  if (read)
    {
      ReadProcessMemory (process->process_hdl, (LPCVOID) tgtaddr,
			 data, len, &processed);
    }
  else /* write */
    {
      WriteProcessMemory (process->process_hdl, (LPVOID) tgtaddr,
			  data, len, &processed);
      FlushInstructionCache (process->process_hdl, (LPCVOID) tgtaddr, len);
    }

  return processed;
}

extern "C" long
win32_set_mem (struct gdbserv *serv, 
		struct gdbserv_reg *addr, 
		void *data, 
		long len)
{
  return win32_xfer_mem (serv, addr, data, len, 0);
}

extern "C" long
win32_get_mem (struct gdbserv *serv, 
		struct gdbserv_reg *addr, 
		void *data, 
		long len)
{
  return win32_xfer_mem (serv, addr, data, len, 1);
}

extern "C" void
win32_flush_i_cache (struct gdbserv *serv)
{
  child_process *process = win32_get_process (serv);

  FlushInstructionCache (process->process_hdl, NULL, 0L);
}

/* exit program vector 
 */
extern "C" void
win32_exit_program (struct gdbserv *serv)
{ 
  child_process *process = win32_get_process (serv);

  process->debug ("Win32: KILL %d\n", process->process_id);

  pid_t pid = win32_get_cygwin_pid (process->process_id);

  if (pid)
    kill (pid, SIGKILL);
  else
    TerminateThread (process->process_hdl, SIGKILL);

  gdbserv_fromtarget_exit (serv, GDBSERV_SIGQUIT);
}

/* break program vector
 */
extern "C" void
win32_break_program (struct gdbserv *serv)
{
  child_process *process = win32_get_process (serv);

  process->debug ("Win32: Send SIGINT to child %d\n", process->process_id);

  pid_t pid = win32_get_cygwin_pid (process->process_id);

  if (pid)
    kill (pid, SIGINT);
  else
    TerminateThread (process->process_hdl, SIGINT);
}

extern "C" void
win32_singlestep_program (struct gdbserv *serv)
{
  child_process *process = win32_get_process (serv);

  process->resume_program (TRUE);
}

extern "C" void
win32_continue_program (struct gdbserv *serv)
{
  child_process *process = win32_get_process (serv);

  process->resume_program (FALSE);
}

/* Process Rcmd vector
 * (apparently a target-specific remote command).
 */

extern "C" void
win32_process_rcmd (struct gdbserv *serv, const char *cmd, int cmdsize)
{
  child_process *process = win32_get_process (serv);

  if (!strcmp (cmd, "debug"))
    process->set_debug (TRUE);
  else if (!strcmp (cmd, "nodebug"))
    process->set_debug (FALSE);
  else if (!strcmp (cmd, "debug_child"))
    process->set_debug_process (TRUE);
  else if (!strcmp (cmd, "nodebug_child"))
    process->set_debug_process (FALSE);
  else if (!strcmp (cmd, "trace"))
    process->set_trace (FALSE);
  else if (!strcmp (cmd, "notrace"))
    process->set_trace (FALSE);
}

/* Set continue-signal vector 
 */

extern "C" int
win32_process_signal (struct gdbserv *serv, int sig)
{
  /* This is disfunctional on Win32. */
  return 0;
}

extern "C" unsigned long
win32_get_trap_number (struct gdbserv *serv)
{
  child_process *process = win32_get_process (serv);

  return process->stop_signal ();
}

/* compute signal vector
 * No translation necessary -- using unix native signals.
 */
extern "C" unsigned long
win32_compute_signal (struct gdbserv *serv, unsigned long tgtsig)
{
  return tgtsig;
}

/* Reset a breakpoint. */

extern "C" enum gdbserv_target_rc
win32_remove_breakpoint (struct gdbserv *serv,
		         enum gdbserv_target_bp type,
                         struct gdbserv_reg *addr,
		         struct gdbserv_reg *len)
{
  child_process *process = win32_get_process (serv);
  enum gdbserv_target_rc tgt_rc = GDBSERV_TARGET_RC_OK;
  DWORD pc;
  const char *old_instruction;

  process->debug ("Win32: remove breakpoint\n");
  switch (type)
    {
    case GDBSERV_TARGET_BP_SOFTWARE:
      gdbserv_reg_to_ulong (serv, addr, &pc);
      if (old_instruction = process->breakpoints[pc])
        {
	  win32_set_mem (serv, addr, (void *) old_instruction, SIZEOF_BP);
	  process->breakpoints.remove (pc);
	}
      break;

    case GDBSERV_TARGET_BP_HARDWARE:
    case GDBSERV_TARGET_BP_WRITE:
    case GDBSERV_TARGET_BP_READ:
    case GDBSERV_TARGET_BP_ACCESS:
    default:
      tgt_rc = GDBSERV_TARGET_RC_UNKNOWN;
      break;
    }
  return tgt_rc;
}

/* Set a breakpoint. */

extern "C" enum gdbserv_target_rc
win32_set_breakpoint (struct gdbserv *serv,
		      enum gdbserv_target_bp type,
                      struct gdbserv_reg *addr,
		      struct gdbserv_reg *len)
{
  child_process *process = win32_get_process (serv);
  enum gdbserv_target_rc tgt_rc = GDBSERV_TARGET_RC_OK;
  DWORD pc;
  char buf[SIZEOF_BP];
  char bp[SIZEOF_BP] = BREAKPOINT;

  process->debug ("Win32: set breakpoint\n");
  switch (type)
    {
    case GDBSERV_TARGET_BP_SOFTWARE:
      gdbserv_reg_to_ulong (serv, addr, &pc);
      win32_get_mem (serv, addr, buf, SIZEOF_BP);
      process->breakpoints.add (pc, buf);
      win32_set_mem (serv, addr, bp, SIZEOF_BP);
      break;

    case GDBSERV_TARGET_BP_HARDWARE:
    case GDBSERV_TARGET_BP_WRITE:
    case GDBSERV_TARGET_BP_READ:
    case GDBSERV_TARGET_BP_ACCESS:
    default:
      tgt_rc = GDBSERV_TARGET_RC_UNKNOWN;
      break;
    }
  return tgt_rc;
}

/* Detach vector -- shut down this target connection.
 */
extern "C" void
win32_detach (struct gdbserv *serv, struct gdbserv_target *target)
{
  assert (win32_connect_lock == serv);

  child_process *process = win32_get_process (serv);

  process->debug ("Win32: Detached.\n");
  win32_connect_lock = NULL;

  /* Quit out of main loop. This kills the target process on Win32 as well.  */
  process->quit_server (TRUE);
}

/* This function is called from gdbloop_poll when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted.  */

extern "C" struct gdbserv_target *
win32_attach (struct gdbserv *serv, void *data)
{
  struct gdbserv_target *win32_target;
  child_process *process = (child_process *) data;

  /* Enable server tracing. */
  /*  gdbserv_state_trace = stderr;*/

  if (win32_connect_lock != NULL)
    {
      process->debug ("Win32: rejected duplicate connection.\n");
      return NULL;
    }

  process->debug ("Win32: accepted gdb connection.\n");
  win32_connect_lock = serv;

  if (!process->create_child ())
    {
      process->debug ("Win32: Creating target process failed.\n");
      win32_connect_lock = NULL;
      return NULL;
    }

  win32_target = (struct gdbserv_target *)
  			malloc (sizeof (struct gdbserv_target));
  memset (win32_target, 0, sizeof (*win32_target));

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  win32_target->process_get_gen       = NULL;
  win32_target->process_set_gen       = NULL;
  win32_target->process_rcmd          = win32_process_rcmd;
  win32_target->process_set_args      = NULL;
  win32_target->process_set_reg       = win32_process_set_reg;
  win32_target->process_get_reg       = win32_process_get_reg;
  win32_target->process_set_regs      = win32_process_set_regs;
  win32_target->process_get_regs      = win32_process_get_regs;
  win32_target->input_reg             = NULL;
  win32_target->output_reg            = NULL;
  win32_target->gg_reg_nr             = NULL;
  win32_target->expedited_reg_nr      = NULL;
  win32_target->sizeof_reg            = NULL;
  win32_target->set_reg               = NULL;
  win32_target->get_reg               = NULL;
  win32_target->get_mem               = win32_get_mem;
  win32_target->set_mem               = win32_set_mem;
  win32_target->process_set_pc        = win32_process_set_pc;
  win32_target->flush_i_cache         = win32_flush_i_cache;
  win32_target->process_signal        = win32_process_signal;
  win32_target->compute_signal        = win32_compute_signal;
  win32_target->get_trap_number       = win32_get_trap_number;
  win32_target->exit_program          = win32_exit_program;
  win32_target->break_program         = win32_break_program;
  win32_target->reset_program         = NULL;
  win32_target->restart_program       = NULL;
  win32_target->singlestep_program    = win32_singlestep_program;
  win32_target->cyclestep_program     = NULL;
  win32_target->sigkill_program       = NULL;
  win32_target->continue_program      = win32_continue_program;
  win32_target->remove_breakpoint     = win32_remove_breakpoint;
  win32_target->set_breakpoint        = win32_set_breakpoint;
  win32_target->process_target_packet = NULL;
  win32_target->detach                = win32_detach;

  win32_target->data = data;
  process->serv = serv;
  return win32_target;
}
