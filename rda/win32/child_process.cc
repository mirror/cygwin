/* child_process.cc

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

#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#if !HAVE_WINDOWS_H
#error The windows.h header is required when compiling for a Win32 target.
#endif
#include <windows.h>
#include <sys/cygwin.h>

#include "server.h"

struct {
  DWORD exc;
  const char *exc_txt;
  DWORD sig;
} sigmap[] = {
  EXCEPTION_ACCESS_VIOLATION,	   "EXCEPTION_ACCESS_VIOLATION",	SIGSEGV,
  EXCEPTION_ARRAY_BOUNDS_EXCEEDED, "EXCEPTION_ARRAY_BOUNDS_EXCEEDED",	SIGSEGV,
  EXCEPTION_BREAKPOINT,		   "EXCEPTION_BREAKPOINT",		SIGTRAP,
  EXCEPTION_DATATYPE_MISALIGNMENT, "EXCEPTION_DATATYPE_MISALIGNMENT",	SIGBUS,
  EXCEPTION_FLT_DENORMAL_OPERAND,  "EXCEPTION_FLT_DENORMAL_OPERAND",	SIGFPE,
  EXCEPTION_FLT_DIVIDE_BY_ZERO,	   "EXCEPTION_FLT_DIVIDE_BY_ZERO",	SIGFPE,
  EXCEPTION_FLT_INEXACT_RESULT,	   "EXCEPTION_FLT_INEXACT_RESULT",	SIGFPE,
  EXCEPTION_FLT_INVALID_OPERATION, "EXCEPTION_FLT_INVALID_OPERATION",	SIGILL,
  EXCEPTION_FLT_OVERFLOW,	   "EXCEPTION_FLT_OVERFLOW",		SIGFPE,
  EXCEPTION_FLT_STACK_CHECK,	   "EXCEPTION_FLT_STACK_CHECK",		SIGFPE,
  EXCEPTION_FLT_UNDERFLOW,	   "EXCEPTION_FLT_UNDERFLOW",		SIGFPE,
  EXCEPTION_ILLEGAL_INSTRUCTION,   "EXCEPTION_ILLEGAL_INSTRUCTION",	SIGILL,
  EXCEPTION_IN_PAGE_ERROR,	   "EXCEPTION_IN_PAGE_ERROR",		SIGSEGV,
  EXCEPTION_INT_DIVIDE_BY_ZERO,	   "EXCEPTION_INT_DIVIDE_BY_ZERO",	SIGFPE,
  EXCEPTION_INT_OVERFLOW,	   "EXCEPTION_INT_OVERFLOW",		SIGFPE,
  EXCEPTION_INVALID_DISPOSITION,   "EXCEPTION_INVALID_DISPOSITION",	SIGILL,
  EXCEPTION_NONCONTINUABLE_EXCEPTION,
  				   "EXCEPTION_NONCONTINUABLE_EXCEPTION",SIGILL,
  EXCEPTION_PRIV_INSTRUCTION,	   "EXCEPTION_PRIV_INSTRUCTION",	SIGILL,
  EXCEPTION_SINGLE_STEP,	   "EXCEPTION_SINGLE_STEP",		SIGTRAP,
  EXCEPTION_STACK_OVERFLOW,	   "EXCEPTION_STACK_OVERFLOW",		SIGSEGV,
  DBG_CONTROL_C,		   "DBG_CONTROL_C",			SIGINT,
  0,				   "Unknown exception",			SIGUSR1
};

/* Debug output method similar to fprintf. */
void
child_process::debug (const char *format, ...)
{
  if (!debug_backend)
    return;
  
  va_list ap;

  va_start (ap, format);
  vfprintf (stderr, format, ap);
  va_end (ap);
}

void
child_process::handle_exception (DEBUG_EVENT &ev)
{
  DWORD exc_code = ev.u.Exception.ExceptionRecord.ExceptionCode;
  DWORD exc_flag = ev.u.Exception.ExceptionRecord.ExceptionFlags;

  int i;
  for (i = 0; sigmap[i].exc && sigmap[i].exc != exc_code; ++i)
    ;

  debug ("Win32: Got exception 0x%08x = \"%s\", mapped to signal %d\n",
  	   	  exc_code, sigmap[i].exc_txt, sigmap[i].sig);

  if (exc_flag == EXCEPTION_NONCONTINUABLE)
    set_term (sigmap[i].sig);
  else
    set_break (sigmap[i].sig);
}

/* fetch registers vector. */
void
child_process::fetch_regs ()
{
  if (!suspend_cnt)
    {
      HANDLE thread_hdl = threads[cur_thread_id];
      suspend_cnt = SuspendThread (thread_hdl) + 1;
      context.ContextFlags = CONTEXT_FULL | CONTEXT_FLOATING_POINT;
      GetThreadContext (thread_hdl, &context);
    }
}

void
child_process::store_regs ()
{
  SetThreadContext (threads[cur_thread_id], &context);
}

BOOL
child_process::resume_program (BOOL step)
{
  fetch_regs ();

  if (step)
    context.EFlags |= FLAG_TRACE_BIT;

  store_regs ();

  if (ContinueDebugEvent (cur_process_id,
  			  cur_thread_id,
			  stop_signal () && stop_signal () != SIGTRAP
			  ? DBG_EXCEPTION_NOT_HANDLED : DBG_CONTINUE))
    {
      int i;

      for (i = 0; i < suspend_cnt; ++i)
        ResumeThread (threads[cur_thread_id]);
      suspend_cnt = 0;
      set_running ();
      return TRUE;
    }
  return FALSE;
}

void
child_process::load_dll_event (DEBUG_EVENT &ev)
{
  void *ptr;
  char buf[512];
  DWORD processed = 0;

  if (!debug ())
    return;

  if (ev.dwProcessId == process_id
      && ev.u.LoadDll.lpImageName
      && ReadProcessMemory (process_hdl, ev.u.LoadDll.lpImageName,
                            &ptr, sizeof ptr, &processed)
      && ptr
      && ReadProcessMemory (process_hdl, ptr, 
                            buf, sizeof buf, &processed))
    {
      buf[511] = '\0';
      char *name = buf;
      if (ev.u.LoadDll.fUnicode)
	{
	  name = (char *) alloca (256);
	  WideCharToMultiByte (CP_ACP, 0, (const WCHAR *) buf, -1,
			       name, 256, NULL, NULL);
	}
      debug ("Win32: Load DLL \"%s\"\n", name);
    }
  else
    debug ("Win32: Load DLL\n");
}

BOOL
child_process::create_child ()
{
  char real_path[PATH_MAX];
  char *winenv;
  char *temp;
  int envlen;
  int len, i;
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  BOOL ret;
  DWORD flags;
  char *args;

  memset (&si, 0, sizeof (si));
  si.cb = sizeof (si);

  cygwin_conv_to_win32_path (executable, real_path);

  flags = DEBUG_ONLY_THIS_PROCESS;

  if (new_group)
    flags |= CREATE_NEW_PROCESS_GROUP;

  if (new_console)
    flags |= CREATE_NEW_CONSOLE;

  len = strlen (real_path);
  for (i = 1; i < argc; ++i)
    len += strlen (argv[i]) + 1;
  
  args = (char *) alloca (len + 2);

  strcpy (args, real_path);

  for (i = 1; i < argc; ++i)
    {
      strcat (args, " ");
      strcat (args, argv[i]);
    }

  SetConsoleCtrlHandler (NULL, 0);
  ret = CreateProcess (0,
                       args,    /* command line */
                       NULL,    /* Security */
                       NULL,    /* thread */
                       TRUE,    /* inherit handles */
                       flags,   /* start flags */
                       NULL,
                       NULL,    /* current directory */
                       &si,
                       &pi);
  if (!ret)
    return FALSE;

  process_id = pi.dwProcessId;

  return TRUE;
}

int
child_process::check_state ()
{
  static DEBUG_EVENT ev;

#if 0
  SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_HIGHEST);
#endif

  if (!WaitForDebugEvent (&ev, 1000))
    return 0;

  /* found an event */

  cur_process_id = ev.dwProcessId;
  cur_thread_id = ev.dwThreadId;

  fetch_regs ();

  switch (ev.dwDebugEventCode)
    {
    case CREATE_PROCESS_DEBUG_EVENT:
      if (ev.dwProcessId != process_id)
        {
          debug ("Win32: Inferior process created\n");
	  set_break (SIGTRAP);
	  return 1;
	}
      else
        debug ("Win32: A child process was created\n");
      process_hdl = ev.u.CreateProcessInfo.hProcess;
      threads += ev;
      break;

    case CREATE_THREAD_DEBUG_EVENT:
      debug ("Win32: Create Thread\n");
      if (ev.dwProcessId == process_id)
	threads += ev;
      break;

    case LOAD_DLL_DEBUG_EVENT:
      load_dll_event (ev);
      break;

    case UNLOAD_DLL_DEBUG_EVENT:
      debug ("Win32: Unload DLL\n");
      break;

    case OUTPUT_DEBUG_STRING_EVENT:
      debug ("Win32: OutputDebugString\n");
      if (ev.dwProcessId == process_id
          && win32_output_debug_string (this, ev))
	return 1;
      break;

    case EXIT_PROCESS_DEBUG_EVENT:
      if (ev.dwProcessId == process_id)
        {
          debug ("Win32: Inferior exited with retcode = %d\n",
                          ev.u.ExitProcess.dwExitCode);
	  set_exit (ev.u.ExitProcess.dwExitCode);
	  return 1;
	}
      else
        debug ("Win32: Some child exited with retcode = %d\n",
                        ev.u.ExitProcess.dwExitCode);
      break;

    case EXIT_THREAD_DEBUG_EVENT:
      debug ("Win32: Thread exited with retcode = %d\n",
      	       ev.u.ExitThread.dwExitCode);
      threads -= ev;
      /* What to return??? */
      break;

    case EXCEPTION_DEBUG_EVENT:
      handle_exception (ev);
      return 1;
    }

  if (!resume_program (FALSE))
    {
      set_term (SIGILL);
      return 1;
    }
  return 0;
}

void
child_process::fromtarget_break ()
{
  debug ("Win32: from_target break\n");
  gdbserv_fromtarget_break (serv, stop_signal ());
}

void
child_process::fromtarget_exit ()
{
  debug ("Win32: from_target exit\n");
  gdbserv_fromtarget_exit (serv, exit_code ());
}

void
child_process::fromtarget_terminate ()
{
  debug ("Win32: from_target terminate\n");
  gdbserv_fromtarget_terminate (serv, term_signal ());
}

