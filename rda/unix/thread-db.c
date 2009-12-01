/* thread-db.c

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

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <thread_db.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <assert.h>

#include "gdbserv.h"
#include "gdbserv-target.h"
#include "gdbserv-utils.h"
#include "server.h"
#include "arch.h"
#include "gdb_proc_service.h"
#include "gdbserv-thread-db.h"
#include "lwp-ctrl.h"
#include "lwp-pool.h"
#include "diagnostics.h"

/* Make lots of noise (debugging output). */
int thread_db_noisy = 0;

#define ALWAYS_UPDATE_THREAD_LIST 0

/*
 * A tiny local symbol table.
 *
 * This is used by ps_pglobal_lookup, and is really just a 
 * local cache of symbols whose values we have obtained from gdb.
 *
 * Since the cache is expected to be small, and infrequently used,
 * there is no effort to sort or hash it.  Symbols may be added 
 * in an "undefined" state, and then defined later.
 */

/* The "defined_p" field may have one of the following three values. */
enum symbol_cache_defined { UNDEFINED, REQUESTED, DEFINED };

struct symbol_cache {
  char *name;
  paddr_t value;
  enum symbol_cache_defined  defined_p;
  struct symbol_cache *next;
} *symbol_list;

/* Function: add_symbol_to_list
   Add a symbol to the symbol cache.  First checks to see if 
   an entry is already in there, and re-uses it if so.  This way
   the cache may be used for symbols awaiting lookup as well as
   for those that have already been defined by the debugger. */

static void
add_symbol_to_list (const char *name, paddr_t value, int defined_p)
{
  struct symbol_cache *tmp;

  for (tmp = symbol_list; tmp; tmp = tmp->next)
    {
      if (strcmp (name, tmp->name) == 0)
	{
	  /* Symbol is already in cache -- set its value and definedness. */
	  tmp->value = value;
	  if (defined_p == DEFINED)
	    tmp->defined_p = defined_p;
	  return;
	}
    }

  /* Symbol is not in cache -- add it. */
  tmp = malloc (sizeof (struct symbol_cache));

  tmp->value = value;
  tmp->defined_p = defined_p;
  tmp->name = malloc (strlen (name) + 1);
  strcpy (tmp->name, name);
  /* LIFO */
  tmp->next = symbol_list;
  symbol_list = tmp;
}

/* Function: free_symbol_list
   Empty the symbol cache. */

static void
free_symbol_list (void)
{
  struct symbol_cache *tmp;

  for (tmp = symbol_list; tmp; tmp = symbol_list)
    {
      symbol_list = tmp->next;
      free (tmp->name);
      free (tmp);
    }
}

/* Function: sync_symbol_list
   Return all "requested" symbols to the "undefined" state
   (so they can be "requested" again).  Called when a new
   source of symbols becomes available (eg. a new shared object). */

static void
sync_symbol_list (void)
{
  struct symbol_cache *tmp;

  for (tmp = symbol_list; tmp; tmp = tmp->next)
    if (tmp->defined_p == REQUESTED)
      tmp->defined_p = UNDEFINED;
}

/* Function: lookup_cached_symbol
   If symbol is defined and cached, return its value in VALUE.
   Return:  0 if not found, 1 if found.  */

static int 
lookup_cached_symbol (char *name, paddr_t *value)
{
  struct symbol_cache *tmp;

  for (tmp = symbol_list; tmp; tmp = tmp->next)
    if (strcmp (name, tmp->name) == 0 && tmp->defined_p == DEFINED)
      {
	*value = tmp->value;	/* known and defined */
	return 1;
      }

  return 0;	/* not found */
}

/* Function: next_undefined_symbol
   Find a symbol in the cache that needs lookup by GDB.
   On returning a symbol, mark it REQUESTED, so that it won't
   be requested again until a new source of symbols opens up
   (eg. a new shared object). */

static char *
next_undefined_symbol (void)
{
  struct symbol_cache *tmp;
  /* Make a pass thru the list, and return the first symbol that
     hasn't been either requested or defined. */
  for (tmp = symbol_list; tmp; tmp = tmp->next)
    if (tmp->defined_p == UNDEFINED)
      {
	tmp->defined_p = REQUESTED;
	return tmp->name;
      }
  return NULL;
}

/*
 * A tiny local thread list.
 *
 * This local list of threads is used for gdbserv operations that
 * require a struct gdbserv_thread.  Its first use will be to 
 * implement "info threads" for gdb.
 */


/* Define the struct gdbserv_thread object. */

struct gdbserv_thread {

  /* A note about thread states (TI.ti_state):

     When a thread calls pthread_exit, it first runs all its
     cancellation cleanup functions (see pthread_cleanup_push), and
     then calls destructors for its thread-specific data (see
     pthread_key_create).  If the thread is not detached, it then
     makes the pointer passed to pthread_exit available for thread(s)
     calling pthread_join.  Then, the thread terminates.

     If a thread's start function, passed to pthread_create, returns,
     then an implementation may assume that the cleanups have run
     already (the POSIX threads interface requires user code to ensure
     that this is the case).  So it just runs the destructors, and
     terminates.

     In glibc 2.3.3's NPTL, if a thread calls pthread_exit,
     libthread_db says its state is TD_THR_ZOMBIE while it runs its
     cleanups and destructors.  However, if a thread simply returns
     from its start function, then libthread_db says it's
     TD_THR_ACTIVE while it runs its destructors.  Other versions of
     libthread_db seem to do inconsistent things like that as well.

     A note about LWP id's (TI.ti_lid):

     After a thread has exited, the libthread_db's for LinuxThreads
     and NPTL report its ti_lid as being equal to the pid of the main
     thread.  To be precise, it reports the LWP id's as being equal to
     ps_getpid (PROCHANDLE), where PROCHANDLE is the 'struct
     ps_prochandle' passed to td_ta_new when we created the thread
     agent in the first place.

     The idea here seems to be, "There are no kernel-level resources
     devoted to the thread any more that a debugger could talk to, so
     let's hand the debugger whatever info we used to create the
     thread agent in the first place, so it can at least talk to what
     remains of the process."  This is a nice thought, but since the
     thread_db interface doesn't give us any way to stop threads or
     wait for them, the debugger needs to break through the
     abstraction and operate on LWP's directly to do those things.
     libthread_db's attempt to be helpful, together with the
     sloppiness in the ti_state handling, makes figuring whether there
     even *is* an LWP to operate on pretty difficult.

     If we attach to a process using some pid P, whose corresponding
     thread happens to have called pthread_exit, then there's no way
     for us to distinguish threads whose lwp is reported as P because
     they're dead from the thread whose lwp is reported as P because
     it actually is: they're all zombies.  */
  td_thrinfo_t ti;

  struct gdbserv_thread *next;

} *thread_list;

/* Function: add_thread_to_list 
   Add a thread (provided by libthread_db) to the local list. */

static struct gdbserv_thread *
add_thread_to_list (td_thrinfo_t *ti)
{
  struct gdbserv_thread *new = malloc (sizeof (struct gdbserv_thread));

  /* First cut -- add to start of list. */
  memset (new, 0, sizeof (*new));
  memcpy (&new->ti, ti, sizeof (td_thrinfo_t));
  new->next = thread_list;
  thread_list = new;
  return new;
}

static struct gdbserv_thread *
first_thread_in_list (void)
{
  return thread_list;
}

static struct gdbserv_thread *
next_thread_in_list (struct gdbserv_thread *thread)
{
  if (thread == NULL)
    return thread_list;
  else
    return thread->next;
}

static void
delete_thread_from_list (struct gdbserv_thread *thread)
{
  struct gdbserv_thread *tmp;

  for (tmp = thread_list; tmp; tmp = tmp->next)
    {
      if (tmp->next == thread)
	{
	  tmp->next = tmp->next->next;		/* unlink */
	  free (thread);			/* discard */
	  return;				/* finished */
	}
    }
  /* Special case -- delete first element of list. */
  if (thread == thread_list)
    {
      thread_list = thread->next;		/* unlink */
      free (thread);				/* discard */
      return;					/* finished */
    }
  /* If we reach this point, the thread wasn't in the list. */
}

static void
free_thread_list (void)
{
  struct gdbserv_thread *tmp;

  for (tmp = thread_list; tmp; tmp = thread_list)
    {
      thread_list = tmp->next;
      free (tmp);
    }
}

static struct gdbserv_thread *
thread_list_lookup_by_tid (thread_t tid)
{
  struct gdbserv_thread *tmp;

  for (tmp = thread_list; tmp; tmp = tmp->next)
    if (tmp->ti.ti_tid == tid)
      break;

  return tmp;
}

/* A copy of the next lower layer's target vector, before we modify it. */
static struct gdbserv_target parentvec;

/* A pointer to the current target vector. */
static struct gdbserv_target *currentvec;

/* 
 * proc_service callback functions, called by thread_db.
 */

void
ps_plog (const char *fmt, ...)
{
  fprintf (stderr, "<ps_plog: %s>\n", fmt);
  return;
}

/* Look up a symbol in GDB's global symbol table.
   Return the symbol's address.
   FIXME: it would be more correct to look up the symbol in the context 
   of the LD_OBJECT_NAME provided.  However we're probably fairly safe 
   as long as there aren't name conflicts with other libraries.  */

ps_err_e
ps_pglobal_lookup (gdb_ps_prochandle_t ph,
		   const char *ld_object_name,	/* the library name */
		   const char *ld_symbol_name,	/* the symbol name */
		   paddr_t    *ld_symbol_addr)	/* return the symbol addr */
{
  paddr_t value;

  if (lookup_cached_symbol ((char *) ld_symbol_name, &value) == 0)
    {
      /* Symbol not in cache -- ask GDB to look it up. 
	 Add the symbol to the cache as undefined. */
      add_symbol_to_list ((char *) ld_symbol_name, 0, UNDEFINED);
      return PS_NOSYM;
    }
  else
    {
      /* Symbol is in the cache and defined -- return its value. */
      *ld_symbol_addr = value;
      return PS_OK;
    }
}


/* Connection to the libthread_db library.  */
static struct ps_prochandle  proc_handle;
static td_thragent_t *thread_agent = NULL;

/* Pointers to the libthread_db functions.  */
static td_err_e (*td_init_p) (void);

static td_err_e (*td_ta_new_p)           (struct ps_prochandle *ps, 
					  td_thragent_t **ta);
static td_err_e (*td_ta_delete_p)        (td_thragent_t *ta);
static td_err_e (*td_ta_map_id2thr_p)    (const td_thragent_t *ta, 
					  thread_t pt, 
					  td_thrhandle_t *__th);
static td_err_e (*td_ta_map_lwp2thr_p)   (const td_thragent_t *ta, 
					  lwpid_t lwpid, 
					  td_thrhandle_t *th);
static td_err_e (*td_ta_thr_iter_p)      (const td_thragent_t *ta, 
					  td_thr_iter_f *callback, 
					  void *cbdata, 
					  td_thr_state_e state, 
					  int ti_pri, 
					  sigset_t *ti_sigmask, 
					  unsigned int ti_user_flags);
static td_err_e (*td_ta_event_addr_p)    (const td_thragent_t *ta, 
					  td_event_e event, 
					  td_notify_t *ptr);
static td_err_e (*td_ta_set_event_p)     (const td_thragent_t *ta, 
					  td_thr_events_t *event);
static td_err_e (*td_ta_event_getmsg_p)  (const td_thragent_t *ta, 
					  td_event_msg_t *msg);
static td_err_e (*td_thr_validate_p)     (const td_thrhandle_t *th);
static td_err_e (*td_thr_get_info_p)     (const td_thrhandle_t *th, 
					  td_thrinfo_t *infop);
static td_err_e (*td_thr_getfpregs_p)    (const td_thrhandle_t *th, 
					  FPREGSET_T *regset);
static td_err_e (*td_thr_getgregs_p)     (const td_thrhandle_t *th, 
					  GREGSET_T gregs);
static td_err_e (*td_thr_setfpregs_p)    (const td_thrhandle_t *th, 
					  const FPREGSET_T *fpregs);
static td_err_e (*td_thr_setgregs_p)     (const td_thrhandle_t *th, 
					  GREGSET_T gregs);
static td_err_e (*td_thr_getxregsize_p)  (const td_thrhandle_t *th,
                                          int *sizep);
static td_err_e (*td_thr_getxregs_p)     (const td_thrhandle_t *th, 
					  void *xregs);
static td_err_e (*td_thr_setxregs_p)     (const td_thrhandle_t *th, 
					  void *xregs);
static td_err_e (*td_thr_event_enable_p) (const td_thrhandle_t *th, 
					  int event);
static const char **(*td_symbol_list_p)  (void);
static td_err_e (*td_thr_tls_get_addr_p) (const td_thrhandle_t *th,
                                          void *map_address,
					  size_t offset, void **address);


/* Function: thread_db_state_str
   Convert a thread_db state code to a string.
   If state code is unknown, return an <unknown> message. */

static char *
thread_db_state_str (td_thr_state_e statecode)
{
  static char buf[64];

  switch (statecode) {
  case TD_THR_ANY_STATE:	return "<any state>";
  case TD_THR_UNKNOWN:		return "<officially unknown>";
  case TD_THR_STOPPED:		return "<stopped>";
  case TD_THR_RUN:		return "<running>";
  case TD_THR_ACTIVE:		return "<active>";
  case TD_THR_ZOMBIE:		return "<zombie>";
  case TD_THR_SLEEP:		return "<sleep>";
  case TD_THR_STOPPED_ASLEEP:	return "<stopped asleep>";
  default:
    sprintf (buf, "<unknown state code %d>", statecode);
    return buf;
  }
}

static char *
thread_db_type_str (td_thr_type_e type)
{
  switch (type) {
  case TD_THR_USER:		return "<user>";
  case TD_THR_SYSTEM:		return "<system>";
  default:                      return "<unknown>";
  }
}

/* Function: thread_db_err_string
   Convert a thread_db error code to a string.
   If errcode is unknown, then return an <unknown> message. */

static char *
thread_db_err_str (td_err_e errcode)
{
  static char buf[64];

  switch (errcode) {
  case TD_OK:		return "generic 'call succeeded'";
  case TD_ERR:		return "generic error";
  case TD_NOTHR:	return "no thread to satisfy query";
  case TD_NOSV:		return "no sync handle to satisfy query";
  case TD_NOLWP:	return "no lwp to satisfy query";
  case TD_BADPH:	return "invalid process handle";
  case TD_BADTH:	return "invalid thread handle";
  case TD_BADSH:	return "invalid synchronization handle";
  case TD_BADTA:	return "invalid thread agent";
  case TD_BADKEY:	return "invalid key";
  case TD_NOMSG:	return "no event message for getmsg";
  case TD_NOFPREGS:	return "FPU register set not available";
  case TD_NOLIBTHREAD:	return "application not linked with libthread";
  case TD_NOEVENT:	return "requested event is not supported";
  case TD_NOCAPAB:	return "capability not available";
  case TD_DBERR:	return "debugger service failed";
  case TD_NOAPLIC:	return "operation not applicable to";
  case TD_NOTSD:	return "no thread-specific data for this thread";
  case TD_MALLOC:	return "malloc failed";
  case TD_PARTIALREG:	return "only part of register set was written/read";
  case TD_NOXREGS:	return "X register set not available for this thread";
  default:
    sprintf (buf, "unknown thread_db error '%d'", errcode);
    return buf;
  }
}


/* Return a string naming the event type EVENT.  */
static const char *
thread_db_event_str (td_event_e event)
{
  switch (event) {
  case TD_READY:		return "TD_READY";
  case TD_SLEEP:		return "TD_SLEEP";
  case TD_SWITCHTO:		return "TD_SWITCHTO";
  case TD_SWITCHFROM:		return "TD_SWITCHFROM";
  case TD_LOCK_TRY:		return "TD_LOCK_TRY";
  case TD_CATCHSIG:		return "TD_CATCHSIG";
  case TD_IDLE:			return "TD_IDLE";
  case TD_CREATE:		return "TD_CREATE";
  case TD_DEATH:		return "TD_DEATH";
  case TD_PREEMPT:		return "TD_PREEMPT";
  case TD_PRI_INHERIT:		return "TD_PRI_INHERIT";
  case TD_REAP:			return "TD_REAP";
  case TD_CONCURRENCY:		return "TD_CONCURRENCY";
  case TD_TIMEOUT:		return "TD_TIMEOUT";
  default:                      return "<unknown>";
  }
}

/* Return a pointer to a statically allocated string describing
   THREAD.  For debugging.  The resulting string has the form
   "(TID STATE LID PTR)", where:
   - TID is the thread ID, which you'll see in the user program and
     in the remote protocol,
   - STATE is the state of the thread, which can be important in 
     deciding how to interpret LID,
   - LID is the PID of the underlying LWP, and
   - PTR is the address of the 'struct thread' in RDA, so you can
     actually mess with it further if you want.  */
static const char *
thread_debug_name (struct gdbserv_thread *thread)
{
  if (thread)
    {
      static char buf[100];
      sprintf (buf, "(0x%lx %s %d %p)",
	       (unsigned long) thread->ti.ti_tid,
	       thread_db_state_str (thread->ti.ti_state),
	       thread->ti.ti_lid,
	       thread);
      return buf;
    }
  else
    return "(null thread)";
}

/* flag which indicates if the map_id2thr cache is valid.  See below.  */
static int thread_db_map_id2thr_cache_valid;

/* Function: thread_db_map_id2thr
   Calling td_ta_map_id2thr() is expensive.  This function invokes
   td_ta_map_id2thr() and caches the value for future reference.  The
   cache may be invalidated by calling thread_db_invalidate_cache().
   Returns: TD_OK on success, an appropriate error code otherwise.  */

static td_err_e
thread_db_map_id2thr (const td_thragent_t *ta, thread_t pt,
                      td_thrhandle_t *th)
{
  static td_thrhandle_t cached_handle;
  static thread_t input_pt;

  if (pt == input_pt && thread_db_map_id2thr_cache_valid)
    {
      *th = cached_handle;
      return TD_OK;
    }
  else
    {
      td_err_e status;

      status = td_ta_map_id2thr_p (ta, pt, th);
      if (status == TD_OK)
	{
	  thread_db_map_id2thr_cache_valid = 1;
	  input_pt = pt;
	  cached_handle = *th;
	}
      else
	thread_db_map_id2thr_cache_valid = 0;
      return status;
    }
}

/* Invalidate the map_id2thr cache.  */
static void
thread_db_invalidate_map_id2thr_cache (void)
{
  thread_db_map_id2thr_cache_valid = 0;
}

static struct gdbserv_thread *
thread_list_lookup_by_lid (lwpid_t pid)
{
  struct gdbserv_thread *t;
  struct gdbserv_thread *second_choice = NULL;

  /* Ideally, we'd be using td_ta_map_lwp2thr here.  */

  for (t = thread_list; t; t = t->next)
    if (t->ti.ti_lid == pid)
      {
	/* libthread_db reports the ti_lid of a deceased thread as
	   being equal to ps_getpid (&proc_handle).  So be a bit
	   skeptical of those.  */
	if (pid == proc_handle.pid
	    && (t->ti.ti_state == TD_THR_ZOMBIE
		|| t->ti.ti_state == TD_THR_UNKNOWN))
	  second_choice = t;
	else return t;
      }

  return second_choice;
}

/* The regset cache object.  This object keeps track of the most
   recently fetched or set gregset (of a particular type) and whether
   or not it needs to still needs to be synchronized with the target.  */
struct regset_cache
{
  /* Are the cache contents valid?  */
  int valid;

  /* Does cache need to be flushed?  */
  int needs_flush;

  /* Handle corresponding to cached regset.  */
  td_thrhandle_t handle;

  /* Size of memory area used to hold regset.  */
  int regset_size;

  /* Memory area used to hold regset.  */
  void *regset_buffer;

  /* Functions used to get/set regset.  */
  td_err_e (*getregset) (const td_thrhandle_t *th, void *regset);
  td_err_e (*setregset) (const td_thrhandle_t *th, const void *regset);
};

/* Declare fpregset and gregset cache objects.  */
static struct regset_cache fpregset_cache;
static struct regset_cache gregset_cache;

/* Wrappers for td_thr_getfpregs_p, td_thr_setfpregs_p, td_thr_getgregs_p,
   and td_thr_setgregs_p.  These simply allow us to pass a void * for the
   regset parameter.  */

static td_err_e
td_thr_getfpregs_wrapper (const td_thrhandle_t *th, void *fpregs)
{
  return td_thr_getfpregs_p (th, fpregs);
}

static td_err_e td_thr_getgregs_wrapper (const td_thrhandle_t *th, void *gregs)
{
  return td_thr_getgregs_p (th, gregs);
}

static td_err_e td_thr_setfpregs_wrapper (const td_thrhandle_t *th,
                                          const void *fpregs)
{
  return td_thr_setfpregs_p (th, fpregs);
}

static td_err_e td_thr_setgregs_wrapper (const td_thrhandle_t *th,
                                         const void *gregs)
{
  void * gregs_nonconst = (void *) gregs;

  return td_thr_setgregs_p (th, gregs_nonconst);
}

/* Initialize a regset cache object.  */
static void
initialize_regset_cache (struct regset_cache *regset_cache,
                         const int regset_size,
			 void * const regset_buffer,
			 td_err_e (* const getregset) (const td_thrhandle_t *th,
			                               void *regset),
                         td_err_e (* const setregset) (const td_thrhandle_t *th,
			                               const void *regset))
{
  regset_cache->valid = 0;
  regset_cache->needs_flush = 0;
  regset_cache->regset_size = regset_size;
  regset_cache->regset_buffer = regset_buffer;
  regset_cache->getregset = getregset;
  regset_cache->setregset = setregset;
}

/* Initialize the fpregset and gregset cache objects.  Space for
   the regset buffer is statically allocated to avoid calls to malloc().  */
static void
initialize_regset_caches (void)
{
  static FPREGSET_T fpregset;
  static GREGSET_T gregset;

  initialize_regset_cache (&fpregset_cache, sizeof fpregset, &fpregset,
                           td_thr_getfpregs_wrapper, td_thr_setfpregs_wrapper);
  initialize_regset_cache (&gregset_cache, sizeof gregset, gregset,
                           td_thr_getgregs_wrapper, td_thr_setgregs_wrapper);
}

/* Synchronize a cached regset with the target.  */
static td_err_e
thread_db_flush_regset_cache (struct regset_cache *regset_cache)
{
  td_err_e status = TD_OK;
  if (regset_cache->valid && regset_cache->needs_flush)
    {
      status = regset_cache->setregset (&regset_cache->handle,
					regset_cache->regset_buffer);
      if (status != TD_OK)
	regset_cache->valid = 0;
      regset_cache->needs_flush = 0;
    }
  return status;
}

/* Synchronize the gregset and fpregset caches with the target.  */
static td_err_e
thread_db_flush_regset_caches (void)
{
  td_err_e status;
  td_err_e ret_status = TD_OK;

  status = thread_db_flush_regset_cache (&fpregset_cache);
  if (status != TD_OK)
    ret_status = status;

  status = thread_db_flush_regset_cache (&gregset_cache);
  if (status != TD_OK)
    ret_status = status;

  return status;
}

/* Fetch a regset, using a previously cached copy if possible.  */
static td_err_e
thread_db_get_regset (struct regset_cache *regset_cache,
                     const td_thrhandle_t *th,
		     void *regset)
{
  if (regset_cache->valid
      && memcmp (&regset_cache->handle, th, sizeof *th) == 0)
    {
      /* Cache is valid and handles match.  Copy the cached regset.  */
      memcpy (regset, regset_cache->regset_buffer, regset_cache->regset_size);
      return TD_OK;
    }
  else
    {
      td_err_e status;

      /* Handles don't match.  Write out old cache contents before
         fetching contents w/ new handle if necessary.  */
      if (regset_cache->valid && regset_cache->needs_flush)
	{
	  status = regset_cache->setregset (&regset_cache->handle,
					    regset_cache->regset_buffer);
	  if (status != TD_OK)
	    {
	      regset_cache->needs_flush = 0;
	      regset_cache->valid = 0;
	      return status;
	    }
	}
      

      /* Fetch the regset.  */
      status = regset_cache->getregset (th, regset);
      if (status == TD_OK)
        {
	  /* Preserve it in the cache.  */
	  regset_cache->needs_flush = 0;
	  regset_cache->valid = 1;
	  memcpy (&regset_cache->handle, th, sizeof (*th));
	  memcpy (regset_cache->regset_buffer, regset,
	          regset_cache->regset_size);
	}
      else
	regset_cache->valid = 0;
      return status;
    }
}

/* Set a regset deferring synchronization with the target until
   later.  */
static td_err_e
thread_db_set_regset (struct regset_cache *regset_cache,
                     const td_thrhandle_t *th,
		     const void *regset)
{
  td_err_e ret_status = TD_OK;

  if (regset_cache->valid && regset_cache->needs_flush
      && memcmp (&regset_cache->handle, th, sizeof *th) != 0)
    {
      /* Cached regset needs to be flushed because handles don't
         match.  */
      ret_status = thread_db_flush_regset_cache (regset_cache);
    }

  memcpy (&regset_cache->handle, th, sizeof *th);
  memcpy (regset_cache->regset_buffer, regset, regset_cache->regset_size);
  regset_cache->valid = 1;
  regset_cache->needs_flush = 1;

  return ret_status;
}

/* Mark a regset cache as invalid.  */
static void
thread_db_invalidate_regset_cache (struct regset_cache *regset_cache)
{
  regset_cache->valid = 0;
}

/* Mark the gregset and fpregset caches as invalid.  */
static void
thread_db_invalidate_regset_caches (void)
{
  thread_db_invalidate_regset_cache (&fpregset_cache);
  thread_db_invalidate_regset_cache (&gregset_cache);
}

/* Invalidate all caches.  */
static void
thread_db_invalidate_caches (void)
{
  thread_db_invalidate_regset_caches ();
  thread_db_invalidate_map_id2thr_cache ();
}

/* Fetch the floating point registers via the fpregset cache.  */
static td_err_e
thread_db_getfpregs (const td_thrhandle_t *th, FPREGSET_T *fpregset)
{
  return thread_db_get_regset (&fpregset_cache, th, fpregset);
}

/* Set the floating point registers via the fpregset cache.  */
static td_err_e
thread_db_setfpregs (const td_thrhandle_t *th, const FPREGSET_T *fpregset)
{
  return thread_db_set_regset (&fpregset_cache, th, fpregset);
}

/* Fetch the general purpose registers via the gregset cache.  */
static td_err_e
thread_db_getgregs (const td_thrhandle_t *th, GREGSET_T gregset)
{
  return thread_db_get_regset (&gregset_cache, th, gregset);
}

/* Set the general purpose registers via the gregset cache.  */
static td_err_e
thread_db_setgregs (const td_thrhandle_t *th, const GREGSET_T gregset)
{
  return thread_db_set_regset (&gregset_cache, th, gregset);
}


/* Function: get_target_int_by_name
   Read the value of a target integer, given its name and size.
   Returns -1 for failure, zero for success. */

static int
get_target_int_by_name (char *name, void *value, int size)
{
  paddr_t addr;

  if (ps_pglobal_lookup (&proc_handle, NULL, name, &addr) == PS_OK)
    {
      if (ps_pdread (&proc_handle, addr,
		     (gdb_ps_read_buf_t) value,
		     (gdb_ps_size_t) size) == PS_OK)
	return 0;
    }
  return -1;		/* fail */
}

/* Function: set_target_int_by_name
   Read the value of a target integer, given its name and size.
   Returns -1 for failure, zero for success. */

static int
set_target_int_by_name (char *name, void *value, int size)
{
  paddr_t addr;

  if (ps_pglobal_lookup (&proc_handle, NULL, name, &addr) == PS_OK)
    {
      if (ps_pdwrite (&proc_handle, addr,
		      (gdb_ps_write_buf_t) value,
		      (gdb_ps_size_t) size) == PS_OK)
	return 0;
    }
  return -1;		/* fail */
}

/* Function: get_thread_signals

   Obtain the values of the "cancel", "restart" and "debug" signals
   used by LinuxThreads, and store them in a set of global variables
   for use by check_child_state and friends.

   Return 0 for success: we obtained the signal numbers and enabled
   debugging in the thread library.  Return -1 for failure.

   Recent versions of NPTL don't define these symbols at all; you must
   use the libthread_db event functions instead (td_ta_event_addr,
   ...) to find out about thread creation, thread exits, and so on.

   Older versions of LinuxThreads provide both interfaces.  To avoid
   changing RDA's behavior on any system it supports, we use the older
   signal-based interface if present, and use the event-based
   interface as a fall-back.  */

static int cancel_signal;
static int restart_signal;
static int debug_signal;
static int got_thread_signals;

static int
get_thread_signals (void)
{
  int cancel, restart, debug;

  /* If we've already gotten the thread signals, that's great.  */
  if (got_thread_signals)
    return 0;

  if (get_target_int_by_name ("__pthread_sig_cancel", 
			      &cancel, sizeof (cancel)) == -1
      || get_target_int_by_name ("__pthread_sig_restart",
				 &restart, sizeof (restart)) == -1
      || get_target_int_by_name ("__pthread_sig_debug", 
				 &debug, sizeof (debug)) == -1)
    return -1;

  restart_signal = restart;
  cancel_signal  = cancel;
  debug_signal   = debug;

  got_thread_signals = 1;

  {
    static int debug_flag = 1;
    set_target_int_by_name ("__pthread_threads_debug", 
			    &debug_flag, sizeof (debug_flag));
  }

  return 0;
}


/* Return true if PROCESS stopped for a libpthread-related signal that
   should not be reported to GDB.  */
static int
ignore_thread_signal (struct child_process *process)
{
  if (process->stop_status == 'T')
    /* Child stopped with a signal.  
       See if it was one of our special signals. */
    return (process->stop_signal == cancel_signal  ||	/* ignore */
	    process->stop_signal == restart_signal ||	/* ignore */
	    process->stop_signal == debug_signal   ||	/* ignore */
	    process->stop_signal == SIGCHLD);		/* ignore */

  return 0;
}


/* NPTL and later versions of LinuxThreads support a set of "event"
   functions for notifying the debugger of interesting events that
   have taken place in the thread library, like thread creation and
   thread death.

   There are three steps to using this interface:

   - First, the debugger asks libthread_db how a given event will be
     reported; libthread_db fills in a 'td_notify_t' structure whose
     'type' says how.  The debuggee may call functions on which the
     debugger can set breakpoints (type == NOTIFY_BPT), hit breakpoint
     instructions hard-coded into the program (type == NOTIFY_AUTOBPT),
     or perform system calls to indicate that an event has occurred
     (type == NOTIFY_SYSCALL).

   - Second, the debugger tells libthread_db which events it's
     interested in.  It can ask to be notified when a given event
     occurs in any thread, or when a given event occurs in a given
     thread.

   - Finally, the debugger watches for the given event to occur.

   We make a few simplifications here:

   - NPTL and LinuxThreads only actually use one kind of event
     notification: calling a function on which the debugger can set a
     breakpoint (NOTIFY_BPT).  So although, strictly speaking, the
     thread library could notify us in other ways, we only support
     NOTIFY_BPT.

   - NPTL and LinuxThreads only support a few kinds of events:
     TD_CREATE (a new thread has been created), TD_DEATH (a thread has
     exited), and TD_REAP (not sure).  We are only interested in
     TD_CREATE and TD_DEATH.  */

/* Ideally, these would be members of some structure somewhere, and
   not global variables, but that's how this file is written.  */

/* True if we're using libthread_db events.  */
int using_thread_db_events;

/* How we are notified of thread creation and death.  */
static td_notify_t create_notification, death_notification;

/* Breakpoints set at the addresses indicated by create_notification
   and death_notification.  These are raw arch breakpoints, so we have
   to delete them to step over them; the objects here will generally
   get regenerated every time we receive an event.  */
static struct arch_bp *create_event_breakpoint;
static struct arch_bp *death_event_breakpoint;
  

/* Set NOTIFICATION to the notification method for EVENT, and check
   that it uses NOTIFY_BPT notification.  Return -1 for failure, zero
   for success.  */
static int
get_event_notification (td_event_e event, td_notify_t *notification)
{
  td_err_e ret = td_ta_event_addr_p (thread_agent, event, notification);
  if (ret != TD_OK)
    {
      if (thread_db_noisy)
	fprintf (stderr, "td_ta_event_addr (%s) -> %s\n",
		 thread_db_event_str (event),
		 thread_db_err_str (ret));
      return -1;
    }

  if (notification->type != NOTIFY_BPT)
    {
      if (thread_db_noisy)
	fprintf (stderr, "notification for %s is not NOTIFY_BPT\n",
		 thread_db_event_str (event));
      return -1;
    }

  return 0;
}


/* Insert a breakpoint in SERV at the address given by NOTIFICATION.
   Return NULL for failure, or the breakpoint for success.  */
static struct arch_bp *
set_event_breakpoint (struct gdbserv *serv, td_notify_t *notification)
{
  struct child_process *process = gdbserv_target_data (serv);
  struct gdbserv_reg addr;

  /* Use the widest type for the conversion, just in case.  */
  gdbserv_ulonglong_to_reg (serv, (paddr_t) notification->u.bptaddr,
			    &addr);
  
  return process->arch->set_bp (process->breakpoint_table, &addr);
}


/* Insert breakpoints at all functions needed for communication with
   the underlying thread library.  Return 0 for success, -1 for
   failure.  */
static int
insert_thread_db_event_breakpoints (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  create_event_breakpoint = set_event_breakpoint (serv, &create_notification);
  death_event_breakpoint  = set_event_breakpoint (serv, &death_notification);

  if (! create_event_breakpoint || ! death_event_breakpoint)
    {
      if (create_event_breakpoint)
	process->arch->delete_bp (create_event_breakpoint);
      if (death_event_breakpoint)
	process->arch->delete_bp (death_event_breakpoint);
      create_event_breakpoint = death_event_breakpoint = 0;
      return -1;
    }

  return 0;
}


/* Remove breakpoints from all libthread_db event notification
   addresses.  Return 0 for success, -1 for failure.  */
static int
delete_thread_db_event_breakpoints (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);
  int create_ret, death_ret;

  create_ret = process->arch->delete_bp (create_event_breakpoint);
  death_ret = process->arch->delete_bp (death_event_breakpoint);

  create_event_breakpoint = death_event_breakpoint = 0;

  if (create_ret == 0 && death_ret == 0)
    return 0;
  else
    return -1;
}


/* If we don't have event set manipulation macros, then we can't use
   the event interface.  */
#if defined (td_event_emptyset)

/* Tell the program being debugged by SERV to notify us of thread
   creation and death.  Return -1 for failure, zero for success.  */
static int
request_thread_db_events (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* If we don't have the libthread_db functions we need, then we
     can't use the event interface.  */
  if (! td_ta_event_addr_p
      || ! td_ta_event_getmsg_p
      || ! td_thr_event_enable_p
      || ! td_ta_set_event_p)
    return -1;

  /* If we don't have an architecture object, then we don't know how
     to insert breakpoints, even if our thread library supports the
     event interface.  */
  if (! process->arch
      || ! process->breakpoint_table)
    return -1;

  /* Get the notification addresses for TD_CREATE and TD_DEATH,
     and ensure that they use NOTIFY_BPT notification.  */
  if (get_event_notification (TD_CREATE, &create_notification) == -1
      || get_event_notification (TD_DEATH,  &death_notification) == -1)
    return -1;

  insert_thread_db_event_breakpoints (serv);

  /* Tell the thread library to send us those events.  */
  {
    td_thr_events_t events;
    td_err_e err;

    /* The td_event_ thingies are all documented to be macros.  So we
       don't need to access them via pointers.  */
    td_event_emptyset (&events);
    td_event_addset (&events, TD_CREATE);
    td_event_addset (&events, TD_DEATH);
    err = td_ta_set_event_p (thread_agent, &events);
    if (err != TD_OK)
      fprintf (stderr, "couldn't set global event mask: %s",
	       thread_db_err_str (err));
  }

  using_thread_db_events = 1;
  return 0;
}

#else /* ! defined (td_event_emptyset) */

/* td_event_emptyset is not defined, so we can't use the event
   interface.  */
static int
request_thread_db_events (struct gdbserv *serv)
{
  return -1;
}

#endif /* ! defined (td_event_emptyset) */


/* Return non-zero if BREAKPOINT is a libthread_db event breakpoint,
   zero otherwise.  */
static int
hit_thread_db_event_breakpoint (struct gdbserv *serv,
				struct gdbserv_thread *thread)
{
  struct child_process *process = gdbserv_target_data (serv);

  return (process->arch->bp_hit_p (thread, create_event_breakpoint)
	  || process->arch->bp_hit_p (thread, death_event_breakpoint));
}


/* Call dlsym() to find the address of a symbol.  If symbol lookup fails,
   print the reason to stderr.  */

static void *
lookup_sym (void *dlhandle, char *symbol)
{
  void *addr;

  addr = dlsym (dlhandle, symbol);

  if (addr == NULL)
    fprintf (stderr, "Symbol lookup of %s failed: %s\n",
	     symbol, dlerror ());

  return addr;
}

/* Function: thread_db_dlopen
   Attach to the libthread_db library.  
   This function does all the dynamic library stuff (dlopen, dlsym).
   Return: -1 for failure, zero for success.  */

static int
thread_db_dlopen (void)
{
  void *dlhandle;

#ifndef LIBTHREAD_DB_SO
#define LIBTHREAD_DB_SO "libthread_db.so.1"
#endif

  if ((dlhandle = dlopen (LIBTHREAD_DB_SO, RTLD_NOW)) == NULL)
    {
      fprintf (stderr, "Unable to open %s: %s\n",
               LIBTHREAD_DB_SO, dlerror ());
      return -1;		/* fail */
    }

  /* Initialize pointers to the dynamic library functions we will use.
   */

  if ((td_init_p = lookup_sym (dlhandle, "td_init")) == NULL)
    return -1;		/* fail */

  if ((td_ta_new_p = lookup_sym (dlhandle, "td_ta_new")) == NULL)
    return -1;		/* fail */

  if ((td_ta_delete_p = lookup_sym (dlhandle, "td_ta_delete")) == NULL)
    return -1;		/* fail */

  if ((td_ta_map_id2thr_p = lookup_sym (dlhandle, "td_ta_map_id2thr")) == NULL)
    return -1;		/* fail */

  if ((td_ta_map_lwp2thr_p = lookup_sym (dlhandle, "td_ta_map_lwp2thr")) == NULL)
    return -1;		/* fail */

  if ((td_ta_thr_iter_p = lookup_sym (dlhandle, "td_ta_thr_iter")) == NULL)
    return -1;		/* fail */

  if ((td_thr_validate_p = lookup_sym (dlhandle, "td_thr_validate")) == NULL)
    return -1;		/* fail */

  if ((td_thr_get_info_p = lookup_sym (dlhandle, "td_thr_get_info")) == NULL)
    return -1;		/* fail */

  if ((td_thr_getfpregs_p = lookup_sym (dlhandle, "td_thr_getfpregs")) == NULL)
    return -1;		/* fail */

  if ((td_thr_getgregs_p = lookup_sym (dlhandle, "td_thr_getgregs")) == NULL)
    return -1;		/* fail */

  if ((td_thr_setfpregs_p = lookup_sym (dlhandle, "td_thr_setfpregs")) == NULL)
    return -1;		/* fail */

  if ((td_thr_setgregs_p = lookup_sym (dlhandle, "td_thr_setgregs")) == NULL)
    return -1;		/* fail */

  /* These are not essential.  */
  td_ta_event_addr_p    = dlsym (dlhandle, "td_ta_event_addr");
  td_ta_set_event_p     = dlsym (dlhandle, "td_ta_set_event");
  td_ta_event_getmsg_p  = dlsym (dlhandle, "td_ta_event_getmsg");
  td_thr_event_enable_p = dlsym (dlhandle, "td_thr_event_enable");
  td_thr_getxregsize_p  = dlsym (dlhandle, "td_thr_getxregsize");
  td_thr_getxregs_p     = dlsym (dlhandle, "td_thr_getxregs");
  td_thr_setxregs_p     = dlsym (dlhandle, "td_thr_setxregs");
  td_symbol_list_p      = dlsym (dlhandle, "td_symbol_list");
  td_thr_tls_get_addr_p = dlsym (dlhandle, "td_thr_tls_get_addr");

  return 0;		/* success */
}

/* Function: thread_db_open
   Open a channel to the child's thread library.
   Returns: 0 for success, -1 for failure
   FIXME: closure.
   FIXME: where should we be called from?  We will not succeed
   until the thread shlib is loaded.  The call from attach will not
   succeed even if the target is statically linked, 'cause there's 
   no symbol lookup handshake on attach.  Therefore I can't handle
   a statically linked threaded process.  */

static int
thread_db_open (struct gdbserv *serv, int pid)
{ /* FIXME: once we have the serv, we can derive the pid. 
     No, not true -- not when we're called from attach. 
     But then, there isn't much use in the call from attach unles
     I make GDB respond to symbol callbacks from there somehow. */
  td_err_e ret;

  /* If we already have a thread agent, we're all set.  */
  if (thread_agent)
    return 0;

  /* Have the proc service handle point back to our serv object and
     the target's overall pid. */
  proc_handle.pid = pid;
  proc_handle.serv = serv;
      
  ret = td_ta_new_p (&proc_handle, &thread_agent);
  if (ret != TD_OK)
    {
      if (thread_db_noisy)
	fprintf (stderr, "< -- failed, thread_agent = %p>\n", thread_agent);
      
      return -1;		/* failure */
    }

  if (thread_db_noisy)
    fprintf (stderr, "< -- succeeded, thread_agent = %p>\n", thread_agent);

  /* All LinuxThreads versions support the signal-based debugging
     interface.  Newer versions of LinuxThreads also provide the
     event-based debugging interface.  NPTL has only ever supported
     the event-based debugging interface.  Prefer the signal-based
     interface to the event-based interface, to leave behavior on
     older systems unchanged.  */
  if (get_thread_signals () == 0)
    {
      if (thread_db_noisy)
        fprintf (stderr,
                 "(using thread signals cancel=%d, restart=%d, debug=%d)\n",
                 cancel_signal, restart_signal, debug_signal);
      return 0;
    }

  if (request_thread_db_events (serv) == 0)
    {
      if (thread_db_noisy)
        fprintf (stderr, "(using thread_db events)\n");
      return 0;
    }

  return -1;
}


/* Function: thread_db_detach
   FIXME: gdbserv kills the inferior and exits when gdb detaches.
   This is the best place I have from which to shut down the 
   thread_db interface, but it's not really where this should
   be done. */

static void
thread_db_detach (struct gdbserv *serv, struct gdbserv_target *target)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* FIXME: this isn't really enough, and detach isn't really the
     right place for this anyway.  Do this in exit_program. */
  td_ta_delete_p (thread_agent);
  thread_agent = NULL;
  currentvec = NULL;

  if (process->debug_informational)
    fprintf (stderr, "<thread_db_detach>\n");
  if (parentvec.detach)
    parentvec.detach (serv, target);
}

static void
attach_thread (struct gdbserv *serv, struct gdbserv_thread *thread)
{
  if (thread->ti.ti_lid != 0)
    {
      /* We attach to all threads with a plausible LWP PID, including
	 TD_THR_ZOMBIE threads.  libthread_db sometimes reports
	 threads still executing cleanups or thread-specific data
	 destructors as zombies, so it may be important to attach to
	 them.

	 libthread_db never reports an invalid LWP PID in ti.ti_lid,
	 even when the LWP has exited --- in that case, it returns
	 ps_getpid (&proc_handle).  The LWP pool code tolerates
	 multiple requests to attach to the same PID.  */
      int status = lwp_pool_attach (serv, thread->ti.ti_lid);

      /* If we're using signals to communicate with the thread
	 library, send the newly attached thread the restart
	 signal.  It will remain stopped, but it will receive the
	 signal as soon as we continue it.  */
      if (got_thread_signals)
	{
	  if (status == 1)
	    kill_lwp (thread->ti.ti_lid, restart_signal);
	}
    }
}

/* Function: find_new_threads_callback
   Enter threads into a local thread database. */

static int
find_new_threads_callback (const td_thrhandle_t *thandle, void *data)
{
  struct gdbserv_thread *thread;
  struct gdbserv *serv = data;
  td_thrinfo_t ti;
  td_err_e     ret;

  if ((ret = td_thr_get_info_p (thandle, &ti)) != TD_OK)
    {
      fprintf (stderr, "<find_new_threads_callback: get_info failed! %s>\n", 
	       thread_db_err_str (ret));
      return -1;
    }

  /* Enter the thread into a local list
     (unless it is TD_THR_UNKNOWN, which means its defunct). */
  if ((thread = thread_list_lookup_by_tid (ti.ti_tid)) == NULL)
    {
      if (ti.ti_state != TD_THR_UNKNOWN)
	{
	  thread = add_thread_to_list (&ti);

	  if (thread_db_noisy)
	    fprintf (stderr, "(new thread %s)\n", thread_debug_name (thread));

	  attach_thread (serv, thread);

	  if (using_thread_db_events)
	    {
	      /* Enable event reporting in this thread.  */
	      if (td_thr_event_enable_p (thandle, 1) != TD_OK)
		fprintf (stderr, "couldn't enable event reporting "
			 "in thread %d\n",
			 ti.ti_lid);
	    }
	}
    }
  else
    {
      /* Already in list -- cache new thread info */
      memcpy (&thread->ti, &ti, sizeof (ti));
    }

  return 0;
}

/* Function: update_thread_list

   First run td_ta_thr_iter to find all threads.
   Then walk the list and validate that each thread is still running.
   If not, prune it from the list. */

static void
update_thread_list (struct child_process *process)
{
  struct gdbserv_thread *thread, *next;
  struct gdbserv *serv = process->serv;
  td_thrhandle_t handle;

  if (thread_db_noisy)
    fprintf (stderr, "thread-db.c: update_thread_list\n");

  /* First make sure all libthread threads are in the list. */
  td_ta_thr_iter_p (thread_agent, find_new_threads_callback, 
		    serv, 
		    TD_THR_ANY_STATE, 
		    TD_THR_LOWEST_PRIORITY,
		    TD_SIGNO_MASK,
		    TD_THR_ANY_USER_FLAGS);

  /* Next, remove any defunct threads from the list. */
  for (thread = first_thread_in_list ();
       thread;
       thread = next)
    {
      /* Thread may be deleted, so find its successor first! */
      next = next_thread_in_list (thread);

      /* Now ask if thread is still valid, and if not, delete it. */
      if (thread_db_map_id2thr (thread_agent, 
			        thread->ti.ti_tid, 
			        &handle) != TD_OK
          || td_thr_validate_p (&handle) != TD_OK)
	{
	  if (thread->ti.ti_state == TD_THR_UNKNOWN)
	    {
	      /* Thread is no longer "valid".
	         By the time this happens, it's too late for us to 
	         detach from it.  Just delete it from the list.  */

	      if (thread == process->focus_thread)
		process->focus_thread = NULL;
	      
	      delete_thread_from_list (thread);
	    }
	}
    }
}

/* Function: thread_db_thread_next
   Exported to gdbserv to implement "info threads" request from GDB. */

static struct gdbserv_thread *
thread_db_thread_next (struct gdbserv *serv, struct gdbserv_thread *thread)
{
  if (thread == NULL)
    {
      /* First request -- build up thread list using td_ta_thr_iter. */
      /* NOTE: this should be unnecessary, once we begin to keep the
	 list up to date all the time. */
      struct child_process *process = gdbserv_target_data (serv);
      update_thread_list (process);
    }
  return next_thread_in_list (thread);
}


/* Function: thread_db_get_gen
   Handle 'q' requests:
     qSymbol and qGetTLSAddr
*/

static void
thread_db_get_gen (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);
  char tempname[1024], *symbol_query;
  unsigned long tempval;
  int len;

  if (gdbserv_input_string_match (serv, "Symbol:") >= 0)
    {
      /* Message: qSymbol:<optional value>:<optional name hexified>
	 Reply:   OK
	 Reply:   qSymbol:<name hexified>

	 This message from GDB has three possible forms:

	 1) "qSymbol::" (no value, no name).
	 This means the start of a symbol query session.
	 GDB is offering to serve up symbols.
	 The target should reply with the FIRST symbol whose value 
	 it wants (or "OK" if it doesn't want any).

	 2) "qSymbol:<value>:<name hexified>
	 This means "here is the value of the symbol you requested".
	 The target should reply with the NEXT symbol whose value
	 it wants (or "OK" if it doesn't want any more).

	 3) "qSymbol::<name hexified>" (no value)
	 This means "I have no value for the symbol you requested".
	 The target should reply with the NEXT symbol whose value
	 it wants (or "OK" if it doesn't want any more).
      */
	 
      if (gdbserv_input_string_match (serv, ":") >= 0)
	{
	  /* So far we've matched "qSymbol::".  We're looking at either 
	     form #1 ("qSymbol::", open a symbol lookup session), or
	     form #3 ("qSymbol::<name>", a reply that "this symbol is
	     not defined".  */

	  len = gdbserv_input_bytes (serv, tempname, sizeof (tempname));

	  if (len == 0)
	    {
	      /* Form #1, open a new symbol lookup session.
		 Prepare to request the first symbol in the list. */
	      sync_symbol_list ();
	    }
	  else
	    {
	      /* Form #3, this symbol not currently defined.  Nothing
		 to do, since we marked it REQUESTED when we sent it,
		 and lookup_cached_symbol treats REQUESTED like
		 UNDEFINED. */
	    }
	}
      else if (gdbserv_input_hex_ulong (serv, &tempval) >= 0 &&
	       gdbserv_input_string_match (serv, ":") >= 0 &&
	       (len = gdbserv_input_bytes (serv, tempname, sizeof (tempname))) 
	       > 0)
	{
	  /* Message contains a symbol and a value (form #2). */

	  tempname[len] = '\0';
	  add_symbol_to_list (tempname, (paddr_t) tempval, DEFINED);
	  if (thread_agent != NULL)
	    {
	      /* We now have a new symbol in the cache, which was
		 requested by the last td_ta_new call.  Delete the
		 current (not-completely-valid) thread agent, so that
		 a new one will have to be opened.  */
	      td_ta_delete_p (thread_agent);
	      thread_agent = NULL;
	    }
	}

      /* If we have no more symbols to look up, try opening a thread
	 agent.  It's possible that opening an agent could succeed
	 before we have finished looking up all the symbols, but since
	 we always loop until all the symbols we know about have been
	 requested anyway, it's unnecessary.

	 This ensures that ps_pglobal_lookup will always succeed in
	 the case where we can obtain the full list of symbol names
	 before opening the agent; this may be a little more robust
	 than assuming it will handle all errors gracefully.
	 
	 Otherwise, if ps_pglobal_lookup fails, it will at least add
	 the missing symbol's name to the list, and we'll request
	 their values the next time around.  */
      symbol_query = next_undefined_symbol ();
      if (! symbol_query)
	{
	  thread_db_open (serv, process->pid);
	  symbol_query = next_undefined_symbol ();
	}

      /* Now the reply depends on whether there is another 
	 symbol in need of lookup.  */
      if (! symbol_query)
	{
	  gdbserv_output_string (serv, "OK");
	}
      else
	{
	  gdbserv_output_string (serv, "qSymbol:");
	  gdbserv_output_bytes (serv, symbol_query, strlen (symbol_query));
	}
    }
  else if (gdbserv_input_string_match (serv, "GetTLSAddr:") >= 0)
    {
      /* Message qGetTLSAddr:thread-id,offset,link-map-addr */
      unsigned long thread_id, offset, link_map_addr;

      if (thread_agent == NULL
          || td_thr_tls_get_addr_p == 0)
	{
	  /* Not supported by thread library.  */
	  gdbserv_output_string (serv, "E01");
	}
      else if (gdbserv_input_hex_ulong (serv, &thread_id) >= 0
          && gdbserv_input_string_match (serv, ",") >= 0
	  && gdbserv_input_hex_ulong (serv, &offset) >= 0
	  && gdbserv_input_string_match (serv, ",") >= 0
	  && gdbserv_input_hex_ulong (serv, &link_map_addr) >= 0)
	{
	  td_err_e ret;
	  td_thrhandle_t thread_handle;
	  ret = thread_db_map_id2thr (thread_agent, 
				      (thread_t) thread_id,
				      &thread_handle);

	  if (ret == TD_OK)
	    {
	      void *addr;

	      ret = td_thr_tls_get_addr_p (&thread_handle,
				           (void *) link_map_addr, 
				           (size_t) offset,
				           &addr);
	      if (ret == TD_OK)
	        {
		  struct gdbserv_reg addr_as_reg;

		  gdbserv_ulonglong_to_reg (serv,
		                            (unsigned long long)
		                              (unsigned long) addr,
		                            &addr_as_reg);
		  gdbserv_output_reg_beb (serv, &addr_as_reg, 0);
		}
	      else
		{
		  /* Can't find TLS address.  */
		  gdbserv_output_string (serv, "E04");
		}
	    }
	  else
	    {
	      /* Unable to find thread.  */
	      gdbserv_output_string (serv, "E03");
	    }
	}
      else
	{
	  /* Malformed qGetTLSAddr packet.  */
	  gdbserv_output_string (serv, "E02");
	}
    }
  else if (parentvec.process_get_gen)
    parentvec.process_get_gen (serv);
}

/* Function: thread_db_set_gen
   Handle 'Q' requests:
*/

static void
thread_db_set_gen (struct gdbserv *serv)
{
    if (parentvec.process_set_gen)
      parentvec.process_set_gen (serv);
}

static void
thread_db_thread_id (struct gdbserv *serv, 
		     struct gdbserv_thread *thread,
		     struct gdbserv_reg *id)
{
  gdbserv_ulonglong_to_reg (serv, 
			    (unsigned long long) thread->ti.ti_tid, 
			    id);
}

static int
thread_db_thread_lookup_by_id (struct gdbserv *serv,
			       const struct gdbserv_reg *thread_id,
			       struct gdbserv_thread **thread)
{
  unsigned long id;

  gdbserv_reg_to_ulong (serv, thread_id, &id);
  if (id == 0)			/* any thread */
    {
      *thread = next_thread_in_list (NULL);	/* FIXME curthread? */
      return 0;
    }
  else
    {
      *thread = thread_list_lookup_by_tid ((thread_t) id);
      if (*thread == NULL)	/* bad thread id */
	{
	  *thread = next_thread_in_list (NULL);	/* FIXME curthread? */
	  return -1;
	}
      else
	{
	  return 1;		/* success */
	}
    }
}

static char *
thread_db_thread_info (struct gdbserv *serv, struct gdbserv_thread *thread)
{
  char *info = malloc (128);

  /* When a thread's LWP has exited, NPTL reports its ti_lid as
     being equal to that of the main process.  Which is a little
     confusing.  So print the pid in a helpfully detailed way.  */
  sprintf (info, "Type %s State %s LWP %d%s",
	   thread_db_type_str (thread->ti.ti_type),
	   thread_db_state_str (thread->ti.ti_state),
	   thread->ti.ti_lid,
	   (thread->ti.ti_lid == proc_handle.pid ? " (main)" : ""));

  return info;
}


/* If we are using the libthread_db event interface, and PROCESS is
   stopped at an event breakpoint, handle the event.

   If we've taken care of PROCESS's situation and it needs no further
   attention, return non-zero.  If PROCESS still needs attention (say,
   because we're not using the event interface, or PROCESS didn't in
   fact hit an event breakpoint, or it did but had new interesting
   things happen when we tried to single-step it), return zero.  */
static int
handle_thread_db_event (struct child_process *process)
{
  struct gdbserv *serv = process->serv;
  struct gdbserv_thread *thread = process->event_thread;
  lwpid_t lwp;
  union wait w;
  int do_update = 0;

  /* We need to be actually using the event interface.  */
  if (! using_thread_db_events)
    return 0;

  /* We need a thread to work on.  */
  if (! thread)
    return 0;

  /* It needs to be stopped at an event breakpoint.  */
  if (! (process->stop_status == 'T'
	 && process->stop_signal == SIGTRAP
	 && hit_thread_db_event_breakpoint (serv, thread)))
    return 0;

  lwp = thread->ti.ti_lid;

  /* Consume events from the queue.  */
  for (;;)
    {
      td_event_msg_t msg;
      td_err_e status = td_ta_event_getmsg_p (thread_agent, &msg);

      if (status == TD_NOMSG)
	break;

      if (status != TD_OK)
	{
	  fprintf (stderr, "error getting thread messages: %s\n",
		   thread_db_err_str (status));
	  break;
	}

      if (msg.event == TD_CREATE || msg.event == TD_DEATH)
	do_update = 1;
    }

  if (do_update)
    {
#if !ALWAYS_UPDATE_THREAD_LIST
      /* Update the thread list.  */
      update_thread_list (process);
#endif
    }

  /* Disable the event breakpoints while we step the thread across them.  */
  delete_thread_db_event_breakpoints (serv);

  /* Back up the thread, if needed.  */
  decr_pc_after_break (serv, lwp);

  /* Single-step the thread across the breakpoint.  */
  lwp_pool_singlestep_lwp (serv, lwp, 0);

  /* Get a new status for that thread.  */
  if (thread_db_noisy)
    fprintf (stderr, "(waiting after event bp step %s)\n",
	     thread_debug_name (thread));
  if (lwp_pool_waitpid (serv, lwp, (int *) &w, 0) < 0)
    {
      fprintf (stderr, "error waiting for thread %d after "
	       "stepping over event breakpoint:\n%s",
	       lwp, strerror (errno));
      /* We don't have any new status to report...  */
      return 1;
    }
  /* Give underlying target a chance to look at the wait status.  This
     is necessary for software singlestep to work correctly.  */
  handle_waitstatus (process, w);

  /* Re-insert the event breakpoints.  */
  insert_thread_db_event_breakpoints (serv);

  /* If the wait status is a SIGTRAP signal, then that means the
     single-step proceeded normally.  Otherwise, it's a new event we
     should deal with.  */
  if (WIFSTOPPED (w) && WSTOPSIG (w) == SIGTRAP)
    return 1;
  else
    {
      handle_waitstatus (process, w);
      return 0;
    }
}


/* Function: continue_thread
   Send continue to a struct gdbserv_thread. */

static void
continue_thread (struct gdbserv *serv, struct gdbserv_thread *thread,
                 int signal)
{
  thread_db_flush_regset_caches();

  if (thread->ti.ti_lid != 0)
    lwp_pool_continue_lwp (serv, thread->ti.ti_lid, signal);

  thread_db_invalidate_caches ();
}

/* Function: continue_program
   Make sure every thread is running, starting with the event thread. */

static void
thread_db_continue_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* Synchronize the regset caches.  */
  thread_db_flush_regset_caches();

  /* First resume the event thread. */
  if (process->event_thread)
      continue_thread (serv, process->event_thread, process->signal_to_send);
  else
    lwp_pool_continue_lwp (serv, process->pid, process->signal_to_send);

  process->stop_signal = process->stop_status = 
    process->signal_to_send = 0;

  /* Then resume everyone else. */
  lwp_pool_continue_all (serv);
  process->running = 1;
  thread_db_invalidate_caches ();

  process->focus_thread = NULL;
}

/* Function: singlestep_thread
   Send SINGLESTEP to a struct gdbserv_thread. */

static void
singlestep_thread (struct gdbserv *serv,
                   struct gdbserv_thread *thread,
                   int signal)
{
  lwp_pool_singlestep_lwp (serv, thread->ti.ti_lid, signal);
}

/* Function: singlestep_program
   Make sure every thread is runnable, while the event thread gets to 
   do a singlestep. */

static void
thread_db_singlestep_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* Synchronize the regset caches.  */
  thread_db_flush_regset_caches();

  /* First singlestep the event thread. */
  if (process->event_thread)
    {
      if (thread_db_noisy)
	fprintf (stderr, "thread_db_singlestep_program: Single stepping event thread %d starting from %#lx\n",
	         process->event_thread->ti.ti_lid,
		 debug_get_pc (serv, process->event_thread->ti.ti_lid));
      singlestep_thread (serv, process->event_thread, process->signal_to_send);
    }
  else
    {
      if (thread_db_noisy)
	fprintf (stderr, "thread_db_singlestep_program: Single stepping %d starting from %#lx\n",
	         process->pid,
		 debug_get_pc (serv, process->pid));
      lwp_pool_singlestep_lwp (serv, process->pid, process->signal_to_send);
    }

  process->stop_status = process->stop_signal =
    process->signal_to_send = 0;

  /* Then resume everyone else. */
  lwp_pool_continue_all (serv);
  process->running = 1;
  thread_db_invalidate_caches ();

  process->focus_thread = NULL;
}

/* Function: thread_db_continue_thread
   Let a single thread continue, while everyone else waits. */

static void
thread_db_continue_thread (struct gdbserv *serv,
			   struct gdbserv_thread *thread,
			   const struct gdbserv_reg *signum)
{
  struct child_process *process = gdbserv_target_data (serv);
  unsigned long sig;

  /* Synchronize the regset caches.  */
  thread_db_flush_regset_caches();

  /* Handle the signal value. */
  if (parentvec.process_signal && signum)
    {
      gdbserv_reg_to_ulong (serv, signum, &sig);
      parentvec.process_signal (serv, (int) sig);
    }

  /* A null thread argument is to be taken as a continue for all. */
  if (thread == NULL)
    thread_db_continue_program (serv);
  else
    {
      process->pid = thread->ti.ti_lid;		/* thread to be continued */
      continue_thread (serv, thread, process->signal_to_send);
      process->stop_status = process->stop_signal =
	process->signal_to_send = 0;
      process->running = 1;
    }
  thread_db_invalidate_caches ();

  /* If we continued a particular thread, then collect wait statuses
     for that thread only.  Otherwise, look for events from
     everyone.  */
  process->focus_thread = thread;
}

/* Function: singlestep_thread
   Let a single thread step, while everyone else waits. */

static void
thread_db_singlestep_thread (struct gdbserv *serv,
			     struct gdbserv_thread *thread,
			     const struct gdbserv_reg *signum)
{
  struct child_process *process = gdbserv_target_data (serv);
  unsigned long sig;

  /* Synchronize the regset caches.  */
  thread_db_flush_regset_caches();

  /* Handle the signal value. */
  if (parentvec.process_signal && signum)
    {
      gdbserv_reg_to_ulong (serv, signum, &sig);
      parentvec.process_signal (serv, (int) sig);
    }

  /* A null thread argument is to be taken as a singlestep for all. */
  if (thread == NULL)
    thread_db_singlestep_program (serv);
  else
    {
      singlestep_thread (serv, thread, process->signal_to_send);
      process->stop_status = process->stop_signal =
	process->signal_to_send = 0;
      process->running = 1;
    }
  thread_db_invalidate_caches ();

  /* If we stepped a particular thread, then collect wait statuses for
     that thread only.  Otherwise, look for events from everyone.  */
  process->focus_thread = thread;
}

/* Function: exit_program
   Called by main loop when child exits. */

static void
thread_db_exit_program (struct gdbserv *serv)
{
  /* FIXME: stop and kill all threads. */

  /* Shut down the thread_db library interface. */
  td_ta_delete_p (thread_agent);
  thread_agent = NULL;
  currentvec = NULL;
  /* Discard all cached symbol lookups. */
  free_symbol_list ();
  /* Discard all cached threads. */
  free_thread_list ();
  /* Call underlying exit_program method. */
  parentvec.exit_program (serv);
}

static void
thread_db_break_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  /* We always send the signal to the main thread.  It's not correct
     to use process->pid; that's whatever thread last reported a
     status, and it may well have been exiting.
     
     We send either SIGSTOP or SIGINT depending upon user preference -
     a GDB monitor command may be used to change the signal used.  SIGINT
     has the advantage of allowing the user to continue in the usual
     manner via GDB's continue command.  SIGSTOP may be preferred in some
     settings because it cannot be blocked or ignored.  When SIGSTOP is
     used, it is slightly more difficult to continue without sending
     another SISSTOP.  */

  if (process->interrupt_with_SIGSTOP)
    {
      if (process->debug_backend)
	fprintf (stderr, " -- send SIGSTOP to child %d\n", proc_handle.pid);

      /* Tell the GDB user that SIGSTOP has been sent to the inferior.  */
      print_sigstop_message (serv);

      kill (proc_handle.pid, SIGSTOP);
    }
  else
    {
      if (process->debug_backend)
	fprintf (stderr, " -- send SIGINT to child %d\n", proc_handle.pid);

      /* Tell the GDB user that SIGINT has been sent to the inferior.  */
      print_sigint_message (serv);

      kill (proc_handle.pid, SIGINT);
    }
}

/* Function: check_child_state

   This function checks for signal events in the running child processes.
   It does not block if there is no event in any child, but if there is
   an event, it selectively calls other functions that will, if appropriate,
   make sure that all the other children are stopped as well. 

   This is a polling (non-blocking) function, and may be called when 
   the child is already stopped. */

static int
thread_db_check_child_state (struct child_process *process)
{
  struct gdbserv *serv = process->serv;
  int eventpid;
  union wait w;

  /* The "process" is likely to be the parent thread.
     We will have to manage a list of threads/pids. */

  /* Since this is a polling call, and threads don't all stop at once, 
     it is possible for a subsequent call to intercept a new wait event
     before we've resumed from the previous wait event.  Prevent this
     with a resume flag. */

  if (process->running)
    {
      eventpid = -1;

      /* If we only stepped or continued a single thread, check for
	 status results only from that thread, even though there may
	 be others collected from before.  */
      if (process->focus_thread)
	eventpid = lwp_pool_waitpid (serv, process->focus_thread->ti.ti_lid,
				     (int *) &w, WNOHANG);
      else
	eventpid = lwp_pool_waitpid (serv, -1, (int *) &w, WNOHANG);

      if (eventpid > 0)	/* found an event */
	{
	  /* Allow underlying target to use the event process by default,
	     since it is stopped and the others are still running. */
	  process->pid = eventpid;

	  handle_waitstatus (process, w);

	  /* Look for thread exit. 
	     This has to be done now -- if the eventpid has exited, I can't
	     run update_thread_list because there is no stopped process 
	     thru which I can read memory.  I could find another one to 
	     stop, but it's not really worth it. */
	  if (process->stop_status == 'W')
	    {
	      if (eventpid == proc_handle.pid)
		return 1;	/* Main thread exited! */
	      else
		return 0;	/* Just a thread exit, don't tell GDB. */
	    }

	  /* Stop all the threads we know about.  */
	  lwp_pool_stop_all (serv);

	  if (thread_db_noisy)
	    fprintf (stderr,
		     "\n<check_child_state: %d got '%c' - %d at 0x%08lx>\n", 
		     process->pid,
		     process->stop_status,
		     process->stop_signal,
		     (unsigned long) debug_get_pc (process->serv, process->pid));

#if !ALWAYS_UPDATE_THREAD_LIST
	  /* The thread_db event model requires that `event_thread' (see
	     below) gets set correctly, but this won't happen unless there's
	     a thread list to search.  So, if the thread_list is empty and
	     we're using the thread_db event model, we need to update the
	     thread list.  */
	  if (thread_list == NULL && using_thread_db_events)
#endif
	    {
	      /* Update the thread list, and attach to (and thereby stop)
		 any new threads we find.  */
	      update_thread_list (process);
	    }

	  process->event_thread = thread_list_lookup_by_lid (process->pid);

	  /* For now, call get_thread_signals from here (FIXME:) */
	  get_thread_signals ();

	  /* If we're using the thread_db event interface, and this is
	     a thread_db event, then just handle it silently and
	     continue.  */
	  if (handle_thread_db_event (process))
	    {
	      currentvec->continue_program (serv);
	      return 0;
	    }

	  /* If we're using the signal-based interface, and someone
	     got a thread-related signal, then deal with that.  */
	  if (got_thread_signals && ignore_thread_signal (process))
	    {
	      /* Ignore this signal, restart the child. */
	      if (thread_db_noisy)
		fprintf (stderr, 
			 "<check_child_state: ignoring signal %d for %d>\n",
			 process->stop_signal, process->pid);
	      if (process->stop_signal == debug_signal)
		{
		  /* The debug signal arrives under two circumstances:
		     1) The main thread raises it once, upon the first call
		     to pthread_create.  This lets us detect the manager
		     thread.  The main thread MUST be given the restart
		     signal when this occurs. 
		     2) The manager thread raises it each time a new
		     child thread is created.  The child thread will be
		     in sigsuspend, and MUST be sent the restart signal.
		     However, the manager thread, which raised the debug
		     signal, does not need to be restarted.  

		     Sending the restart signal to the newly attached
		     child thread (which is not the event thread) is
		     handled in continue_all_threads.  */

		  if (process->pid == proc_handle.pid)  /* main thread */
		    process->stop_signal = restart_signal;
		  else				/* not main thread */
		    process->stop_signal = 0;

#if !ALWAYS_UPDATE_THREAD_LIST
		  /* Update the thread list.  */
		  update_thread_list (process);
#endif

		}

	      /* Continue the program.  */
	      process->signal_to_send = process->stop_signal;
	      currentvec->continue_program (serv);
	      return 0;
	    }

	  process->running = 0;

	  /* Pass this event back to GDB. */
	  if (process->debug_backend)
	    fprintf (stderr, "wait returned '%c' (%d) for %d.\n", 
		     process->stop_status, process->stop_signal, process->pid);
	  return 1;
	}
    }

  /* NOTE: this function is called in a polling loop, so it
     probably (?) should not block.  Return when there's no event. */
  return 0;
}

/* Function: fromtarget_thread_break
   Called from the main loop when one of the child processes stops.
   Notifies the RDA library and lets it know which thread took the event. */

static void
thread_db_fromtarget_thread_break (struct child_process *process)
{
  int gdb_signal = parentvec.compute_signal (process->serv,
					     process->stop_signal);

  gdbserv_fromtarget_thread_break (process->serv, 
				   process->event_thread,
				   gdb_signal);
}

/* Function: get_thread_reg
   Get a register value for a specific thread. */

static int
thread_db_get_thread_reg (struct gdbserv *serv, 
			  struct gdbserv_thread *thread, 
			  int regnum, 
			  struct gdbserv_reg *reg)
{
  struct child_process *process = gdbserv_target_data (serv);
  td_thrhandle_t thread_handle;
  FPREGSET_T fpregset;
  GREGSET_T gregset;
  td_err_e ret;

  /* Initialize reg to 0 in the event that we return early due to a
     register being unsupported.  */
  gdbserv_ulonglong_to_reg (serv, 0LL, reg);

  if (thread == NULL)
    thread = process->event_thread;	/* Default to the event thread. */

  if (thread_agent == NULL || 		/* Thread layer not alive yet? */
      thread       == NULL)		/* No thread specified? */
    {
      /* Fall back on parentvec non-threaded method. */
      if (parentvec.get_reg)
	return parentvec.get_reg (serv, regnum, reg);
      else
	return -1;	/* give up. */
    }

  /* Thread_db active, thread_agent valid.
     The request goes to the thread_db library. 
     From there it will be dispatched to ps_lgetregs,
     and from there it will be kicked back to the parent. */

  if (thread->ti.ti_state == TD_THR_ZOMBIE ||
      thread->ti.ti_state == TD_THR_UNKNOWN)
    {
      /* This thread is dead!  Can't get its registers. */
      return -1;
    }

  ret = thread_db_map_id2thr (thread_agent, 
			      thread->ti.ti_tid,
			      &thread_handle);
  if (ret == TD_NOTHR)
    {
      /* Thread has exited, no registers. */
      return -1;
    }
  else if (ret != TD_OK)
    {
      fprintf (stderr, "<<< ERROR get_thread_reg map_id2thr %lu >>>\n",
	       (unsigned long) thread->ti.ti_tid);
      return -1;	/* fail */
    }

  if (is_fp_reg (regnum))
    {
      if (thread_db_getfpregs (&thread_handle, &fpregset) != TD_OK)
	{
	  /* Failure to get the fpregs isn't necessarily an error.
	     Assume that the target just doesn't support fpregs. */
	  return 0;
	}
      /* Now extract the register from the fpregset. */
      if (reg_from_fpregset (serv, reg, regnum, &fpregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_from_fpregset %lu %d>>>\n",
		   (unsigned long) thread->ti.ti_tid, regnum);
	  return -1;
	}
    }
  else if (td_thr_getxregsize_p != NULL
           && td_thr_getxregs_p != NULL
	   && is_extended_reg (regnum))
    {
      int xregsize;
      void *xregset;

      if (td_thr_getxregsize_p (&thread_handle, &xregsize) != TD_OK)
	{
	  /* Failure to get the size of the extended regs isn't
	     necessarily an error.  Assume that the target just
	     doesn't support them.  */
	  return 0;
	}

      if (xregsize <= 0)
	{
	  /* Another form of not being supported...  */
	  return 0;
	}

      /* Allocate space for the extended registers.  */
      xregset = alloca (xregsize);
      
      /* Fetch the extended registers.  */
      if (td_thr_getxregs_p (&thread_handle, xregset) != TD_OK)
	{
	  /* Failure to get the extended regs isn't necessarily an error.
	     Assume that the target just doesn't support them.  */
	  return 0;
	}

      /* Now extract the register from the extended regset.  */
      if (reg_from_xregset (serv, reg, regnum, xregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_from_xregset %lu %d>>>\n",
		   (unsigned long) thread->ti.ti_tid, regnum);
	  return -1;
	}
    }
  else if (is_gp_reg (regnum)) /* GP reg */
    {
      if (thread_db_getgregs (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr,
		   "<<< ERROR get_thread_reg td_thr_getgregs %lu >>>\n",
		   (unsigned long) thread->ti.ti_tid);
	  return -1;	/* fail */
	}
      /* Now extract the requested register from the gregset. */
      if (reg_from_gregset (serv, reg, regnum, gregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_from_gregset %lu %d>>>\n", 
		   (unsigned long) thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
    }
  else
    {
      /* Register not supported by this target.  This shouldn't be
         construed as an error though.  */
      return 0;
    }

  return 0;		/* success */
}

/* Function: set_thread_reg
   Set a register value for a specific thread. */

static int
thread_db_set_thread_reg (struct gdbserv *serv, 
			  struct gdbserv_thread *thread, 
			  int regnum, 
			  const struct gdbserv_reg *reg)
{
  struct child_process *process = gdbserv_target_data (serv);
  td_thrhandle_t thread_handle;
  FPREGSET_T fpregset;
  GREGSET_T gregset;
  td_err_e ret;

  if (thread == NULL)
    thread = process->event_thread;	/* Default to the event thread. */

  if (thread_agent == NULL || 		/* Thread layer not alive yet? */
      thread       == NULL)		/* No thread specified? */
    {
      /* Fall back on parentvec non-threaded method. */
      if (parentvec.set_reg)
	return parentvec.set_reg (serv, regnum, (struct gdbserv_reg *) reg);
      else
	return -1;	/* give up. */
    }

  /* Thread_db active, thread_agent valid.
     The request goes to the thread_db library. 
     From there it will be dispatched to ps_lsetregs,
     and from there it will be kicked back to the parent. */

  if (thread->ti.ti_state == TD_THR_ZOMBIE ||
      thread->ti.ti_state == TD_THR_UNKNOWN)
    {
      /* This thread is dead!  Can't get its registers. */
      return -1;
    }

  ret = thread_db_map_id2thr (thread_agent, 
			      thread->ti.ti_tid,
			      &thread_handle);
  if (ret == TD_NOTHR)
    {
      /* Thread has exited, no registers. */
      return -1;
    }
  else if (ret != TD_OK)
    {
      fprintf (stderr, "<<< ERROR set_thread_reg map_id2thr %lu >>>\n",
	       (unsigned long) thread->ti.ti_tid);
      return -1;	/* fail */
    }

  if (is_fp_reg (regnum))
    {
      /* Get the current fpregset.  */
      if (thread_db_getfpregs (&thread_handle, &fpregset) != TD_OK)
	{
	  /* Failing to get the fpregs is not necessarily an error.
	     Assume it simply means that this target doesn't support
	     fpregs. */
	  return 0;
	}
      /* Now write the new reg value into the fpregset. */
      if (reg_to_fpregset (serv, reg, regnum, &fpregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_to_fpregset %lu %d >>>\n",
		   (unsigned long) thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
      /* Now write the fpregset back to the child. */
      if (thread_db_setfpregs (&thread_handle, &fpregset) != TD_OK)
	{
	  fprintf (stderr,
		   "<<< ERROR set_thread_reg td_thr_setfpregs %lu>>>\n",
		   (unsigned long) thread->ti.ti_tid);
	  return -1;	/* fail */
	}
    }
  else if (td_thr_getxregsize_p != NULL
           && td_thr_getxregs_p != NULL
           && td_thr_setxregs_p != NULL
	   && is_extended_reg (regnum))
    {
      int xregsize;
      void *xregset;

      if (td_thr_getxregsize_p (&thread_handle, &xregsize) != TD_OK)
	{
	  /* Failure to get the size of the extended regs isn't
	     necessarily an error.  Assume that the target just
	     doesn't support them.  */
	  return 0;
	}

      if (xregsize <= 0)
	{
	  /* Another form of not being supported...  */
	  return 0;
	}

      /* Allocate space for the extended registers.  */
      xregset = alloca (xregsize);

      /* Fetch the extended registers.  */
      if (td_thr_getxregs_p (&thread_handle, xregset) != TD_OK)
	{
	  /* Failure to get the extended regs isn't necessarily an error.
	     Assume that the target just doesn't support them.  */
	  return 0;
	}
      /* Now write the new reg value into the extended regset. */
      if (reg_to_xregset (serv, reg, regnum, xregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_to_xregset %lu %d >>>\n", 
		   (unsigned long) thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
      /* Now write the extended regset back to the child. */
      if (td_thr_setxregs_p (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr,
		   "<<< ERROR set_thread_reg td_thr_setxregs %lu >>>\n",
		   (unsigned long) thread->ti.ti_tid);
	  return -1;	/* fail */
	}
    }
  else if (is_gp_reg (regnum))
    {
      /* First get the current gregset.  */
      if (thread_db_getgregs (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr,
		   "<<< ERROR set_thread_reg td_thr_getgregs %lu >>>\n",
		   (unsigned long) thread->ti.ti_tid);
	  return -1;	/* fail */
	}
      /* Now write the new reg value into the gregset. */
      if (reg_to_gregset (serv, reg, regnum, gregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_to_gregset %lu %d >>>\n", 
		   (unsigned long) thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
      /* Now write the gregset back to the child. */
      if (thread_db_setgregs (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr,
		   "<<< ERROR set_thread_reg td_thr_setgregs %lu >>>\n",
		   (unsigned long) thread->ti.ti_tid);
	  return -1;	/* fail */
	}
    }

  return 0;	/* success */
}

/* Function: thread_db_attach
   gdbserv target function called upon attaching to gdb. 
   Return -1 for failure, zero for success. 
   Note that this has nothing to do with attaching to a running process
   (which in fact we don't even know how to do), or a running thread. */

int
thread_db_attach (struct gdbserv *serv, struct gdbserv_target *target)
{
  td_err_e ret;
  struct child_process *process = target->data;
  extern struct server_vector gdbserver;

  if ((thread_db_dlopen ()) < 0)
    return -1;			/* fail */

  /* Save a copy of the existing target vector before we modify it. */
  memcpy (&parentvec, target, sizeof (parentvec));
  /* Save a pointer to the actual target vector. */
  currentvec = target;

  /* Initialize the library.  */
  if ((ret = td_init_p ()) != TD_OK)
    {
      fprintf (stderr, 
	       "Cannot initialize libthread_db: %s", thread_db_err_str (ret));
      currentvec = NULL;
      return -1;		/* fail */
    }

  /* Initialize threadish target methods. */
  target->thread_info         = thread_db_thread_info;
  target->thread_next         = thread_db_thread_next;
  target->thread_id           = thread_db_thread_id;
  target->thread_lookup_by_id = thread_db_thread_lookup_by_id;
  target->process_set_gen     = thread_db_set_gen;
  target->process_get_gen     = thread_db_get_gen;
  target->detach              = thread_db_detach;

  /* Take over selected target methods. */
  target->exit_program        = thread_db_exit_program;
  target->continue_program    = thread_db_continue_program;
  target->singlestep_program  = thread_db_singlestep_program;

  target->continue_thread     = thread_db_continue_thread;
  target->singlestep_thread   = thread_db_singlestep_thread;

  target->break_program       = thread_db_break_program;

  /* Take over get_reg / set_reg methods with threaded versions. */
  if (target->next_gg_reg != NULL &&
      target->reg_format  != NULL &&
      target->output_reg  != NULL &&
      target->input_reg   != NULL)
    {
      target->get_thread_reg      = thread_db_get_thread_reg;
      target->set_thread_reg      = thread_db_set_thread_reg;
    }
  else
    fprintf (stderr, "< ERROR attach: GDB will not read thread regs. >>>\n");

  /* Preload the symbol list with the names of the symbols whose names
     we use ourselves.  

     This might be a kludge, but it's not a gratuitous kludge.  On
     older LinuxThreads libraries, RDA must manage LinuxThreads
     signals.  Since libthread_db provides no abstraction for managing
     them, RDA must look up the addresses of the signal variables and
     read their values itself.  However, libthread_db may never look
     those symbols up itself, and they may not appear in the list
     provided by td_symbol_list_p.  (In fact, in glibc-2.2.93, they
     don't.)

     So RDA may as well preload them into the symbol list; otherwise,
     get_thread_signals will fail even though the symbols are defined,
     because the names will only get added to symbol_list as we
     attempt to look them up; each remote protocol symbol lookup dance
     will resolve exactly one new symbol, allowing get_thread_signal
     to get as far as requesting the next one and failing.

     As it turns out, this is actually necessary, not just efficient,
     because failures from get_thread_signal cause RDA to try the
     libthread_db event-based interface; we may end up using that even
     when the signal-based interface is actually available.  And we'd
     rather use the signal-based interface when we can, to avoid
     changing the behavior of RDA on older systems.  */
  add_symbol_to_list ("__pthread_sig_restart",   0, UNDEFINED);
  add_symbol_to_list ("__pthread_sig_cancel",    0, UNDEFINED);
  add_symbol_to_list ("__pthread_sig_debug",     0, UNDEFINED);
  add_symbol_to_list ("__pthread_threads_debug", 0, UNDEFINED);

  if (td_symbol_list_p)
    {
      /* Take all the symbol names libthread_db might try to look up
	 and place them in our cached symbol list, to be looked up
	 when invited by GDB.  */
      const char **symbol_list = td_symbol_list_p ();
      int i;

      for (i = 0; symbol_list[i]; i++)
	add_symbol_to_list (symbol_list[i], 0, UNDEFINED);
    }

  /* Attempt to open the thread_db interface.  This attempt will 
     most likely fail (unles the child is statically linked). */
  thread_db_open (serv, process->pid);	/* Don't test return value */

  /* Take over the "wait" vector. FIXME global object */
  gdbserver.check_child_state = thread_db_check_child_state;
  /* Take over the "fromtarget_break" vector. FIXME global object */
  gdbserver.fromtarget_break = thread_db_fromtarget_thread_break;
  /* FIXME what about terminate and exit? */

  /* Record the initial thread's pid in the LWP pool.  */
  lwp_pool_new_stopped (process->pid);

  /* Initially, there is no focus thread.  */
  process->focus_thread = NULL;

  /* Set up the regset caches.  */
  initialize_regset_caches ();
  return 0;		/* success */
}
