/* server.h

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

extern "C" {
#include "gdbserv.h" 
#include "gdbserv-target.h" 
#include "gdbserv-utils.h"
#include "gdbsocket.h"
#include "gdbloop.h"
};

/* Various possibilities for alloca.  */
#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* Not GNU C */
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#else
#ifdef _AIX
#pragma alloca
#else

/* We need to be careful not to declare this in a way which conflicts with
   bison.  Bison never declares it as char *, but under various circumstances
   (like __hpux) we need to use void *.  */
extern void *alloca ();
#endif /* Not _AIX */
#endif /* Not HAVE_ALLOCA_H */
#endif /* Not GNU C */
#endif /* alloca not defined */

/* Sequence of bytes for breakpoint instruction.  */
#define SIZEOF_BP  1
#define BREAKPOINT {0xcc}

#define FLAG_TRACE_BIT 0x100

enum proc_state {
  Running,
  Break,
  Exit,
  Terminate
};

class breakpoint {
  BOOL  used;
  DWORD bp_address;
  char  bp_instruction[SIZEOF_BP];

public:
  breakpoint () : used (FALSE), bp_address(0)
    {
      memset (bp_instruction, 0, SIZEOF_BP);
    }
  breakpoint (DWORD naddress, char *nbp_inst)
  : used (TRUE), bp_address(naddress)
    {
      memcpy (bp_instruction, nbp_inst, SIZEOF_BP);
    }
  virtual ~breakpoint () {}

  BOOL in_use () const { return used; }
  DWORD address () const { return used ? bp_address : 0L; }
  const char *instruction () const { return used ? bp_instruction : NULL; }
  operator DWORD() const { return used ? bp_address : 0L; }

  void set_in_use (BOOL nin_use) { used = nin_use; }
};

class bp_array {
  breakpoint  *bp;
  int          max_cnt;
  int          cur_cnt;

public:
  bp_array () : bp (NULL), max_cnt (0), cur_cnt (0) {}
  virtual ~bp_array () {}

  int add (breakpoint &new_bp)
    {
      for (int i = 0; i < cur_cnt; ++i)
	if (new_bp.address () == bp[i].address ())
	  return i;
      if (cur_cnt == max_cnt)
	{
	  breakpoint *tmp = (breakpoint *)
	  		realloc (bp, (max_cnt += 5) * sizeof (breakpoint));
          if (!tmp)
	    return -1;
	  bp = tmp;
        }
      bp[cur_cnt] = new_bp;
      return cur_cnt++;
    }
  int add (DWORD address, char *instruction)
    {
      breakpoint new_bp (address, instruction);
      return add (new_bp);
    }
  BOOL remove (DWORD address)
    {
      for (int i = 0; i < cur_cnt; ++i)
        if (bp[i].address () == address && bp[i].in_use ())
	  {
	    bp[i].set_in_use (FALSE);
	    return TRUE;
	  }
      return FALSE;
    }
  BOOL remove (int bp_id)
    {
      if (bp_id >= cur_cnt || !bp[bp_id].in_use ())
        return FALSE;
      bp[bp_id].set_in_use (FALSE);
      return TRUE;
    }
  const char *instruction (DWORD address) const
    {
      for (int i = 0; i < cur_cnt; ++i)
        if (bp[i].address () == address)
	  return bp[i].instruction ();
      return NULL;
    }

  void operator +=(breakpoint &new_bp) { add (new_bp); }
  void operator -=(DWORD address) { remove (address); }
  const char *operator [](DWORD address) const { return instruction (address); }
};

class thread_slot {
  BOOL			   used;
  DWORD			   id;
  CREATE_THREAD_DEBUG_INFO info;

public:
  thread_slot () : used (FALSE), id (0) {}
  thread_slot (DEBUG_EVENT &ev)
    {
      used = TRUE;
      id = ev.dwThreadId;
      switch (ev.dwDebugEventCode)
        {
	case CREATE_THREAD_DEBUG_EVENT:
	  info = ev.u.CreateThread;
	  break;
	case CREATE_PROCESS_DEBUG_EVENT:
	  info.hThread = ev.u.CreateProcessInfo.hThread;
	  info.lpThreadLocalBase = ev.u.CreateProcessInfo.lpThreadLocalBase;
	  info.lpStartAddress = ev.u.CreateProcessInfo.lpStartAddress;
	  break;
	default:
	  used = 0;
	  break;
	}
    }
  virtual ~thread_slot () {}

  BOOL in_use () { return used; }
  DWORD get_id () { return id; }
  HANDLE get_hdl () { return info.hThread; }

  void set_in_use (BOOL nin_use) { used = nin_use; }
};

class thread_array {
  thread_slot *thread;
  int          max_cnt;
  int          cur_cnt;

public:
  thread_array () : thread (NULL), max_cnt (0), cur_cnt (0) {}
  virtual ~thread_array () {}

  BOOL add (thread_slot &new_slot)
    {
      if (cur_cnt == max_cnt)
	{
	  thread_slot *tmp = (thread_slot *)
	  		realloc (thread, (max_cnt += 5) * sizeof (thread_slot));
          if (!tmp)
	    return FALSE;
	  thread = tmp;
        }
      thread[cur_cnt++] = new_slot;
      return TRUE;
    }
  BOOL add (DEBUG_EVENT &ev)
    {
      thread_slot new_slot (ev);
      return add (new_slot);
    }
  BOOL remove (DWORD thread_id)
    {
      for (int i = 0; i < cur_cnt; ++i)
        if (thread[i].get_id () == thread_id)
	  {
	    memcpy (thread + i, thread + i + 1,
	    	    (cur_cnt - i - 1) * sizeof (thread_slot));
	    --cur_cnt;
	    return TRUE;
	  }
      return FALSE;
    }
  BOOL remove (DEBUG_EVENT &ev)
    {
      if (ev.dwDebugEventCode == EXIT_THREAD_DEBUG_EVENT)
        return remove (ev.dwThreadId);
      return FALSE;
    }
  HANDLE get_hdl (DWORD thread_id)
    {
      for (int i = 0; i < cur_cnt; ++i)
        if (thread[i].get_id () == thread_id)
	  return thread[i].get_hdl ();
      return INVALID_HANDLE_VALUE;
    }
  DWORD get_id (HANDLE thread_hdl)
    {
      for (int i = 0; i < cur_cnt; ++i)
        if (thread[i].get_hdl () == thread_hdl)
	  return thread[i].get_id ();
      return 0L;
    }

  void operator +=(thread_slot &new_slot) { add (new_slot); }
  void operator +=(DEBUG_EVENT &ev) { add (ev); }
  void operator -=(DWORD thread_id) { remove (thread_id); }
  void operator -=(DEBUG_EVENT &ev) { remove (ev); }
  HANDLE operator [](DWORD thread_id) { get_hdl (thread_id); }
  DWORD operator [](HANDLE thread_hdl) { get_id (thread_hdl); }
};

class child_process {
  BOOL            debug_backend;
  BOOL            debug_child;
  DWORD           trace_child;
  proc_state      stop_status;
  int             stop_sig;
  BOOL            server_quit_p;

public:
  struct gdbserv *serv;
  char           *executable;
  int             argc;
  char          **argv;
  BOOL            new_group;
  BOOL            new_console;
  DWORD           process_id;
  HANDLE	  process_hdl;
  DWORD           cur_process_id;
  DWORD           cur_thread_id;
  thread_array    threads;
  bp_array	  breakpoints;
  CONTEXT         context;
  int             suspend_cnt;
  long            signal_to_send;

  int             saw_stars;
  char            nfields;
  long long       start_time;
  DWORD           last_usecs;

  child_process () 
  : serv (NULL),
    executable (NULL),
    argc (0),
    argv (NULL),
    new_group (FALSE),
    new_console (FALSE),
    process_id (0),
    cur_process_id (0),
    cur_thread_id (0),
    suspend_cnt (0),
    signal_to_send (0),
    debug_backend (FALSE),
    debug_child (FALSE),
    trace_child (0),
    stop_status (Running),
    stop_sig (0),
    server_quit_p (FALSE),
    saw_stars (0),
    nfields (0),
    start_time (0),
    last_usecs (0)
    {
      memset (&context, 0, sizeof context);
    }

  void set_debug (BOOL ndebug = TRUE) { debug_backend = ndebug ? TRUE : FALSE; }
  BOOL debug () const { return debug_backend; }
  void debug (const char *format, ...);

  void set_debug_process (BOOL ndebug = TRUE)
				      { debug_child = ndebug ? TRUE : FALSE; }
  int debug_process () const { return debug_child; }

  void set_trace (DWORD ntrace = 1) { trace_child = ntrace; }
  DWORD trace () const { return trace_child; }

  void set_running ()           { stop_status = Running; stop_sig = 0; }
  void set_break (int nsignal)  { stop_status = Break; stop_sig = nsignal; }
  void set_exit (int nexitcode) { stop_status = Exit; stop_sig = nexitcode; }
  void set_term (int nsignal)   { stop_status = Terminate; stop_sig = nsignal;}

  proc_state status () const { return stop_status; }
  int stop_signal () const { return stop_sig; }
  int term_signal () const { return stop_sig; }
  int exit_code () const { return stop_sig; }

  void quit_server (BOOL quit) { server_quit_p = quit ? TRUE : FALSE; }
  BOOL quit_server () const { return server_quit_p; }

  void handle_exception (DEBUG_EVENT &ev);
  void fetch_regs ();
  void store_regs ();
  BOOL resume_program (BOOL step);
  void load_dll_event (DEBUG_EVENT &ev);
  BOOL create_child ();

  int check_state ();
  void fromtarget_break ();
  void fromtarget_exit ();
  void fromtarget_terminate ();
};

/* win32-strace.cc */
extern int win32_output_debug_string (child_process *, DEBUG_EVENT &);

/* win32-target.cc */
extern "C" struct gdbserv_target *win32_attach (struct gdbserv *, void *);
