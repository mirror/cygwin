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
#include <dlfcn.h>
#include <thread_db.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>

#include "gdbserv.h"
#include "gdbserv-target.h"
#include "server.h"
#include "gdb_proc_service.h"
#include "gdbserv-thread-db.h"

/* Make lots of noise (debugging output). */
int thread_db_noisy = 0;
int proc_service_noisy = 0;

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

struct symbol_cache {
  char *name;
  paddr_t value;
  int  defined_p;
  struct symbol_cache *next;
} *symbol_list;

/* The "defined_p" field may have one of the following three values. */
enum { UNDEFINED, REQUESTED, DEFINED };

/* Function: add_symbol_to_list
   Add a symbol to the symbol cache.  First checks to see if 
   an entry is already in there, and re-uses it if so.  This way
   the cache may be used for symbols awaiting lookup as well as
   for those that have already been defined by the debugger. */

static void
add_symbol_to_list (char *name, paddr_t value, int defined_p)
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
  td_thrinfo_t ti;
  int attached : 1;
  int stopped : 1;
  int waited : 1;
  int stepping : 1;
  struct gdbserv_thread *next;
} *thread_list;

/* Function: add_thread_to_list 
   Add a thread (provided by libthread_db) to the local list. */

static struct gdbserv_thread *
add_thread_to_list (td_thrinfo_t *ti)
{
  struct gdbserv_thread *new = malloc (sizeof (struct gdbserv_thread));

  /* First cut -- add to start of list. */
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

static struct gdbserv_thread *
thread_list_lookup_by_lid (lwpid_t pid)
{
  struct gdbserv_thread *tmp;

  for (tmp = thread_list; tmp; tmp = tmp->next)
    if (tmp->ti.ti_lid == pid)
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
  case TD_THR_ACTIVE:		return "<active> ";
  case TD_THR_ZOMBIE:		return "<zombie> ";
  case TD_THR_SLEEP:		return "<sleep>  ";
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
  case TD_THR_USER:		return "<user>  ";
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
    return -1;		/* fail */

  /* Initialize pointers to the dynamic library functions we will use.
   */

  if ((td_init_p = dlsym (dlhandle, "td_init")) == NULL)
    return -1;		/* fail */

  if ((td_ta_new_p = dlsym (dlhandle, "td_ta_new")) == NULL)
    return -1;		/* fail */

  if ((td_ta_delete_p = dlsym (dlhandle, "td_ta_delete")) == NULL)
    return -1;		/* fail */

  if ((td_ta_map_id2thr_p = dlsym (dlhandle, "td_ta_map_id2thr")) == NULL)
    return -1;		/* fail */

  if ((td_ta_map_lwp2thr_p = dlsym (dlhandle, "td_ta_map_lwp2thr")) == NULL)
    return -1;		/* fail */

  if ((td_ta_thr_iter_p = dlsym (dlhandle, "td_ta_thr_iter")) == NULL)
    return -1;		/* fail */

  if ((td_thr_validate_p = dlsym (dlhandle, "td_thr_validate")) == NULL)
    return -1;		/* fail */

  if ((td_thr_get_info_p = dlsym (dlhandle, "td_thr_get_info")) == NULL)
    return -1;		/* fail */

  if ((td_thr_getfpregs_p = dlsym (dlhandle, "td_thr_getfpregs")) == NULL)
    return -1;		/* fail */

  if ((td_thr_getgregs_p = dlsym (dlhandle, "td_thr_getgregs")) == NULL)
    return -1;		/* fail */

  if ((td_thr_setfpregs_p = dlsym (dlhandle, "td_thr_setfpregs")) == NULL)
    return -1;		/* fail */

  if ((td_thr_setgregs_p = dlsym (dlhandle, "td_thr_setgregs")) == NULL)
    return -1;		/* fail */

  /* These are not essential.  */
  td_ta_event_addr_p    = dlsym (dlhandle, "td_ta_event_addr");
  td_ta_set_event_p     = dlsym (dlhandle, "td_ta_set_event");
  td_ta_event_getmsg_p  = dlsym (dlhandle, "td_ta_event_getmsg");
  td_thr_event_enable_p = dlsym (dlhandle, "td_thr_event_enable");
  td_thr_getxregsize_p  = dlsym (dlhandle, "td_thr_getxregsize");
  td_thr_getxregs_p     = dlsym (dlhandle, "td_thr_getxregs");
  td_thr_setxregs_p     = dlsym (dlhandle, "td_thr_setxregs");

  return 0;		/* success */
}

/* Function: thread_db_open
   Open a channel to the child's thread library.
   Returns: -1 for failure, 0 for success
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

  if (thread_agent == NULL)
    {
      proc_handle.pid = pid;
      proc_handle.serv = serv;
      
      ret = td_ta_new_p (&proc_handle, &thread_agent);
      if (ret == TD_OK)
	{
	  return -1;	/* success */
	}
      else if (thread_db_noisy)
	{
	  fprintf (stderr, "< -- failed, thread_agent = 0x%08x>\n", 
		   (long) thread_agent);
	}
      return 0;		/* failure */
    }
  return -1;		/* success */
}

/* Function: thread_db_detach
   FIXME: gdbserv kills the inferior and exits when gdb detaches.
   This is the best place I have from which to shut down the 
   thread_db interface, but it's not really where this should
   be done. */

void
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
attach_thread (struct gdbserv_thread *thread)
{
  if (thread->ti.ti_lid   != 0 &&
      thread->ti.ti_state != TD_THR_ZOMBIE)	/* Don't attach a zombie. */
    {
      if (attach_lwp (thread->ti.ti_lid) == 0)
	thread->attached = 1;
      else
	thread->attached = 0;
    }
}

/* Function: find_new_threads_callback
   Enter threads into a local thread database. */

static int
find_new_threads_callback (const td_thrhandle_t *thandle, void *data)
{
  struct gdbserv_thread *thread;
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
	  /* Now make sure we've attached to it.  
	     Skip the main pid (already attached). */
	  if (thread->ti.ti_lid != proc_handle.pid)
	    {
	      attach_thread (thread);
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
update_thread_list (void)
{
  struct gdbserv_thread *thread, *next;
  td_thrhandle_t handle;

  /* First make sure all libthread threads are in the list. */
  td_ta_thr_iter_p (thread_agent, find_new_threads_callback, 
		    (void *) 0, 
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
      update_thread_list ();
    }
  return next_thread_in_list (thread);
}


/* Function: thread_db_get_gen
   Handle 'q' requests:
     qSymbol
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
	     form #2 ("qSymbol::<name>", a reply that "this symbol is
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
	      /* Form #2, this symbol not currently defined.
		 Nothing to do, since we already have it marked undefined. */
	    }
	}
      else if (gdbserv_input_hex_ulong (serv, &tempval) >= 0 &&
	       gdbserv_input_string_match (serv, ":") >= 0 &&
	       (len = gdbserv_input_bytes (serv, tempname, sizeof (tempname))) 
	       > 0)
	{
	  /* Message contains a symbol and a value (form #3). */

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

      /* Now the reply depends on whether there is another 
	 symbol in need of lookup.  */
      thread_db_open (serv, process->pid);
      if ((symbol_query = next_undefined_symbol ()) == NULL)
	{
	  gdbserv_output_string (serv, "OK");
	}
      else
	{
	  gdbserv_output_string (serv, "qSymbol:");
	  gdbserv_output_bytes (serv, symbol_query, strlen (symbol_query));
	}
    }
  else if (parentvec.process_get_gen)
    parentvec.process_get_gen (serv);
}

/* Function: thread_db_set_gen
   Handle 'Q' requests:
*/

void
thread_db_set_gen (struct gdbserv *serv)
{
    if (parentvec.process_set_gen)
      parentvec.process_set_gen (serv);
}

void
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

  sprintf (info, "PID %d Type %s State %s",
	   thread->ti.ti_lid, 
	   thread_db_type_str (thread->ti.ti_type),
	   thread_db_state_str (thread->ti.ti_state));
  return info;
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
   used by linux threads, and store them in a set of global variables
   for use by check_child_state and friends. */

static int cancel_signal;
static int restart_signal;
static int debug_signal;
static int got_thread_signals;

static void
get_thread_signals (void)
{
  int cancel, restart, debug, debug_flag;

  if (!got_thread_signals)
    {
      if (get_target_int_by_name ("__pthread_sig_cancel", 
				  &cancel, sizeof (cancel)) == 0 &&
	  get_target_int_by_name ("__pthread_sig_restart",
				  &restart, sizeof (restart)) == 0 &&
	  get_target_int_by_name ("__pthread_sig_debug", 
				  &debug, sizeof (debug)) == 0)
	{
	  restart_signal = restart;
	  cancel_signal  = cancel;
	  debug_signal   = debug;
	  got_thread_signals = 1;
	}
      debug_flag = 1;
      set_target_int_by_name ("__pthread_threads_debug", 
			      &debug_flag, sizeof (debug_flag));
    }
}

/* Function: stop_thread 
   Use SIGSTOP to force a thread to stop. */

static void
stop_thread (struct gdbserv_thread *thread)
{
  if (thread->ti.ti_lid != 0)
    {
      if (stop_lwp (thread->ti.ti_lid) == 0)
	thread->stopped = 1;
      else
	thread->stopped = 0;
    }
}

/* Function: stop_all_threads
   Use SIGSTOP to make sure all child threads are stopped.
   Do not send SIGSTOP to the event thread, or to any 
   new threads that have just been attached. */

static void
stop_all_threads (struct child_process *process)
{
  struct gdbserv_thread *thread;

  for (thread = first_thread_in_list ();
       thread;
       thread = next_thread_in_list (thread))
    {
      if (thread->ti.ti_lid == process->pid)
	{
	  /* HACK mark him signalled. */
	  thread->stopped = 1;
	  continue;	/* This thread is already stopped. */
	}
      /* All threads must be stopped, unles
	 a) they have only just been attached, or 
	 b) they're already stopped. */
      if (!thread->attached && !thread->stopped &&
	  thread->ti.ti_state != TD_THR_ZOMBIE &&
	  thread->ti.ti_state != TD_THR_UNKNOWN)
	{
	  stop_thread (thread);
	}
    }
}

/* A list of signals that have been prematurely sucked out of the threads.
   Because of the complexities of linux threads, we must send SIGSTOP to
   every thread, and then call waitpid on the thread to retrieve the 
   SIGSTOP event.  Sometimes another signal is pending on the thread,
   and we get that one by mistake.  Throw all such signals into this
   list, and send them back to their respective threads once we're
   finished calling waitpid. */

static struct event_list {
  struct gdbserv_thread *thread;
  union wait waited;
  int selected;
} *pending_events;
static int pending_events_listsize;
static int pending_events_top;

/* Function: add_pending_event
   Helper function for wait_all_threads.

   When we call waitpid for each thread (trying to consume the SIGSTOP
   events that we sent from stop_all_threads), we sometimes inadvertantly
   get other events that we didn't send.  We pend these to a list, and 
   then resend them to the child threads after our own SIGSTOP events
   have been consumed.  

   This list will be used to choose which of the possible events 
   will be returned to the debugger by check_child_status. */

static void
add_pending_event (struct gdbserv_thread *thread, union wait waited)
{
  if (pending_events_top >= pending_events_listsize)
    {
      pending_events_listsize += 64;
      pending_events = 
	realloc (pending_events, 
		 pending_events_listsize * sizeof (*pending_events));
    }
  pending_events [pending_events_top].thread = thread;
  pending_events [pending_events_top].waited = waited;
  pending_events [pending_events_top].selected = 0;
  pending_events_top ++;
}

/* Function: select_pending_event
   Helper function for wait_all_threads.

   Having collected a list of events from various threads, 
   choose one "favored event" to be returned to the debugger. */


static void
select_pending_event (struct child_process *process)
{
  int i = 0;
  int num_wifstopped_events = 0;
  int random_key;

  /* Select the event that will be returned to the debugger. */

  /* Selection criterion #0:
     If there are no events, don't do anything!  (paranoia) */
  if (pending_events_top == 0)
    return;

  /* Selection criterion #1: 
     If the thread pointer is null, then the thread library is
     not in play yet, so this is the only thread and the only event. */
  if (pending_events[0].thread == NULL)
    {
      i = 0;
      goto selected;
    }

  /* Selection criterion #2:
     Exit and terminate events take priority. */
  for (i = 0; i < pending_events_top; i++)
    if (WIFEXITED (pending_events[i].waited) ||
	WIFSIGNALED (pending_events[i].waited))
      {
	goto selected;
      }

  /* Selection criterion #3: 
     Give priority to a stepping SIGTRAP. */
  for (i = 0; i < pending_events_top; i++)
    if (pending_events[i].thread->stepping &&
	WIFSTOPPED (pending_events[i].waited) &&
	WSTOPSIG (pending_events[i].waited) == SIGTRAP)
      {
	/* We don't actually know whether this sigtrap was the result
	   of a singlestep, or of executing a trap instruction.  But
	   GDB has a better chance of figuring it out than we do. */
	goto selected;
      }

  /* Selection criterion #4:
     Count the WIFSTOPPED events and choose one at random. */
  for (i = 0; i < pending_events_top; i++)
    if (WIFSTOPPED (pending_events[i].waited))
      num_wifstopped_events ++;

  random_key = (int) 
    ((num_wifstopped_events * (double) rand ()) / (RAND_MAX + 1.0));

  for (i = pending_events_top - 1; i >= 0; i--)
    if (WIFSTOPPED (pending_events[i].waited))
      {
	if (random_key == --num_wifstopped_events)
	  {
	    goto selected;
	  }
	else if (WSTOPSIG (pending_events[i].waited) == SIGINT)
	  {
	    goto selected;	/* Give preference to SIGINT. */
	  }
      }

  /* Selection criterion #4 (should never get here):
     If all else fails, take the first event in the list. */
  i = 0;

 selected:	/* Got our favored event. */
  pending_events[i].selected = 1;
  process->event_thread = pending_events[i].thread;
  if (pending_events[i].thread)
    process->pid = pending_events[i].thread->ti.ti_lid;

  handle_waitstatus (process, pending_events[i].waited);
  if (thread_db_noisy)
    fprintf (stderr, "<select_pending_event: pid %d '%c' %d>\n",
	    process->pid, process->stop_status, process->stop_signal);
  return;
}

/* Function: send_pending_signals
   Helper function for wait_all_threads.

   When we call waitpid for each thread (trying to consume the SIGSTOP
   events that we sent from stop_all_threads), we sometimes inadvertantly
   get other events that we didn't send.  We pend these to a list, and 
   then resend them to the child threads after our own SIGSTOP events
   have been consumed. 

   Some events in the list require special treatment:
    * One event is "selected" to be returned to the debugger. 
      Skip that one.
    * Trap events may represent breakpoints.  We can't just resend
      the signal.  Instead we must arrange for the breakpoint to be
      hit again when the thread resumes.  */

static void
send_pending_signals (struct child_process *process)
{
  int i;
  int signum;

  for (i = 0; i < pending_events_top; i++)
    {
      if (WIFSTOPPED (pending_events[i].waited) &&
	  ! pending_events[i].selected)
	{
	  signum = WSTOPSIG (pending_events[i].waited);
	  if (signum == SIGTRAP &&
	      pending_events[i].thread->stepping == 0)
	    {
	      /* Breakpoint.  Push it back.  */
	      if (thread_db_noisy)
		fprintf (stderr, "<send_pending_events: pushing back SIGTRAP for %d>\n",
			pending_events[i].thread->ti.ti_lid);
	      decr_pc_after_break (process->serv,
	                           pending_events[i].thread->ti.ti_lid);
	    }
	  else /* FIXME we're letting SIGINT go thru as normal */
	    {
	      /* Put the signal back into the child's queue. */
	      kill (pending_events[i].thread->ti.ti_lid, 
		    WSTOPSIG (pending_events[i].waited));
	    }
	}
    }
  pending_events_top = 0;
}

/* Function: wait_all_threads
   Use waitpid to close the loop on all threads that have been
   attached or SIGSTOP'd.  Skip the eventpid -- it's already been waited. 

   Special considerations:
     The debug signal does not go into the event queue, 
     does not get forwarded to the thread etc. */

static void
wait_all_threads (struct child_process *process)
{
  struct gdbserv_thread *thread;
  union  wait w;
  int    ret, stopsig;

  for (thread = first_thread_in_list ();
       thread;
       thread = next_thread_in_list (thread))
    {
      /* Special handling for the thread that has already been waited. */
      if (thread->ti.ti_lid == process->pid)
	{
	  /* HACK mark him waited. */
	  thread->waited = 1;
	  continue;
	}

      while ((thread->stopped || thread->attached) &&
	     !thread->waited)
	{
	  errno = 0;
	  ret = waitpid (thread->ti.ti_lid, (int *) &w, 
			 thread->ti.ti_lid == proc_handle.pid ? 0 : __WCLONE);
	  if (ret == -1)
	    {
	      if (errno == ECHILD)
		fprintf (stderr, "<wait_all_threads: %d has disappeared>\n", 
			thread->ti.ti_lid);
	      else
		fprintf (stderr, "<wait_all_threads: waitpid %d failed, '%s'>\n", 
			thread->ti.ti_lid, strerror (errno));
	      break;
	    }
	  if (WIFEXITED (w))
	    {
	      add_pending_event (thread, w);
	      fprintf (stderr, "<wait_all_threads: %d has exited>\n", 
		      thread->ti.ti_lid);
	      break;
	    }
	  if (WIFSIGNALED (w))
	    {
	      add_pending_event (thread, w);
	      fprintf (stderr, "<wait_all_threads: %d died with signal %d>\n", 
		      thread->ti.ti_lid, WTERMSIG (w));
	      break;
	    }
	  stopsig = WSTOPSIG (w);
	  switch (stopsig) {
	  case SIGSTOP:
	    /* This is the one we're looking for.
	       Mark the thread as 'waited' and move on to the next thread. */
#if 0 /* too noisy! */
	    if (thread_db_noisy)
	      fprintf (stderr, "<waitpid (%d, SIGSTOP)>\n", thread->ti.ti_lid);
#endif
	    thread->waited = 1;
	    break;
	  default:
	    if (stopsig == debug_signal)
	      {
		/* This signal does not need to be forwarded. */
		if (thread_db_noisy)
		  fprintf (stderr, "<wait_all_threads: ignoring SIGDEBUG for %d>\n",
			  thread->ti.ti_lid);
	      }
	    else
	      {
		if (thread_db_noisy)
		  fprintf (stderr, "<wait_all_threads: stash sig %d for %d at 0x%08x>\n",
			   stopsig, thread->ti.ti_lid,
			  (unsigned long) debug_get_pc (process->serv,
			                                thread->ti.ti_lid));
		add_pending_event (thread, w);
	      }
	  }

	  if (!thread->waited)	/* Signal was something other than STOP. */
	    {
	      /* Continue the thread so it can stop on the next signal. */
	      continue_lwp (thread->ti.ti_lid, 0);
	    }
	}
    }
  select_pending_event (process);
  send_pending_signals (process);
}

/* Function: continue_thread
   Send continue to a struct gdbserv_thread. */

static void
continue_thread (struct gdbserv_thread *thread, int signal)
{
  thread_db_flush_regset_caches();

  /* Continue thread only if (a) it was just attached, or 
     (b) we stopped it and waited for it. */
  if (thread->ti.ti_lid != 0)
    if (thread->attached || (thread->stopped && thread->waited))
      {
	continue_lwp (thread->ti.ti_lid, signal);
	thread->stopped = thread->attached = thread->waited = 0;
      }
  thread_db_invalidate_caches ();
}

/* Function: continue_all_threads 
   Send continue to all stopped or attached threads
   except the event thread (which will be continued separately). */

static void
continue_all_threads (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);
  struct gdbserv_thread *thread;
  int signal;

  for (thread = first_thread_in_list ();
       thread;
       thread = next_thread_in_list (thread))
    {
      /* Send any newly attached thread the restart signal. */
      if (thread->attached)
	continue_thread (thread, restart_signal);
      else
	continue_thread (thread, 0);
    }
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
    continue_thread (process->event_thread, process->signal_to_send);
  else
    continue_lwp (process->pid, process->signal_to_send);

  process->stop_signal = process->stop_status = 
    process->signal_to_send = 0;

  /* Then resume everyone else. */
  continue_all_threads (serv);
  process->running = 1;
  thread_db_invalidate_caches ();
}

/* Function: singlestep_thread
   Send SINGLESTEP to a struct gdbserv_thread. */

static void
singlestep_thread (struct gdbserv_thread *thread, int signal)
{
  singlestep_lwp (thread->ti.ti_lid, signal);
  thread->stopped = thread->attached = thread->waited = 0;
  thread->stepping = 1;
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
    singlestep_thread (process->event_thread, process->signal_to_send);
  else
    singlestep_lwp (process->pid, process->signal_to_send);

  process->stop_status = process->stop_signal =
    process->signal_to_send = 0;

  /* Then resume everyone else. */
  continue_all_threads (serv);		/* All but the event thread. */
  process->running = 1;
  thread_db_invalidate_caches ();
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
      continue_thread (thread, process->signal_to_send);
      process->stop_status = process->stop_signal =
	process->signal_to_send = 0;
      process->running = 1;
    }
  thread_db_invalidate_caches ();
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
      singlestep_thread (thread, process->signal_to_send);
      process->stop_status = process->stop_signal =
	process->signal_to_send = 0;
      process->running = 1;
    }
  thread_db_invalidate_caches ();
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
      eventpid = waitpid (-1, (int *) &w, WNOHANG);
      /* If no event on main thread, check clone threads. 
         It doesn't matter what event we find first, since we now have
         a fair algorithm for choosing which event to handle next. */
      if (eventpid <= 0)
	eventpid = waitpid (-1, (int *) &w, WNOHANG | __WCLONE);

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

	  /* FIXME: this debugging output will be removed soon, but 
	     putting it here before the update_thread_list etc. is
	     bad from the point of view of synchronization. */
	  handle_waitstatus (process, w);
	  if (thread_db_noisy)
	    fprintf (stderr, "<check_child_state: %d got '%c' - %d at 0x%08x>\n", 
		     process->pid, process->stop_status, process->stop_signal,
		     (unsigned long) debug_get_pc (process->serv, process->pid));

	  /* Update the thread list. */
	  update_thread_list ();

	  /* For now, call get_thread_signals from here (FIXME:) */
	  get_thread_signals ();

	  /* Put this child's event into the pending list. */
	  add_pending_event (thread_list_lookup_by_lid ((lwpid_t) eventpid), 
			     w);

	  stop_all_threads (process);
	  wait_all_threads (process);
	  /* Note: if more than one thread has an event ready to be
	     handled, wait_all_threads will have chosen one at random. */

	  if (got_thread_signals && process->stop_status == 'T')
	    {
	      /* Child stopped with a signal.  
		 See if it was one of our special signals. */

	      if (process->stop_signal == cancel_signal  ||	/* ignore */
		  process->stop_signal == restart_signal ||	/* ignore */
		  process->stop_signal == debug_signal   ||	/* ignore */
		  process->stop_signal == SIGCHLD)		/* ignore */
		{
		  /* Ignore this signal, restart the child. */
		  if (thread_db_noisy)
		    fprintf (stderr, "<check_child_state: ignoring signal %d for %d>\n",
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
		    }
		  process->signal_to_send = process->stop_signal;
		  currentvec->continue_program (serv);
		  return 0;
		}
	    }
	  if (process->stop_status == 'W')
	    {
	      if (process->pid == proc_handle.pid)
		return 1;	/* Main thread exited! */
	      else
		{
		  currentvec->continue_program (serv);
		  return 0;	/* Just a thread exit, don't tell GDB. */
		}
	    }

	  process->running = 0;

	  /* This is the place to cancel its 'stepping' flag. */
	  if (process && process->event_thread)
	    process->event_thread->stepping = 0;

	  /* Pass this event back to GDB. */
	  if (process->debug_backend)
	    fprintf (stderr, "wait returned '%c' (%d) for %d.\n", 
		     process->stop_status, process->stop_signal, eventpid);
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
  td_thrinfo_t   ti;
  FPREGSET_T fpregset;
  GREGSET_T gregset;
  td_err_e ret;

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
      fprintf (stderr, "<<< ERROR get_thread_reg map_id2thr %d >>>\n",
	       thread->ti.ti_tid);
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
	  fprintf (stderr, "<<< ERROR reg_from_fpregset %d %d>>>\n",
		   thread->ti.ti_tid, regnum);
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
	  fprintf (stderr, "<<< ERROR reg_from_xregset %d %d>>>\n",
		   thread->ti.ti_tid, regnum);
	  return -1;
	}
    }
  else if (is_gp_reg (regnum)) /* GP reg */
    {
      if (thread_db_getgregs (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr, "<<< ERROR get_thread_reg td_thr_getgregs %d >>>\n",
		   thread->ti.ti_tid);
	  return -1;	/* fail */
	}
      /* Now extract the requested register from the gregset. */
      if (reg_from_gregset (serv, reg, regnum, gregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_from_gregset %d %d>>>\n", 
		   thread->ti.ti_tid, regnum);
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
      fprintf (stderr, "<<< ERROR set_thread_reg map_id2thr %d >>>\n",
	       thread->ti.ti_tid);
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
	  fprintf (stderr, "<<< ERROR reg_to_fpregset %d %d >>>\n",
		   thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
      /* Now write the fpregset back to the child. */
      if (thread_db_setfpregs (&thread_handle, &fpregset) != TD_OK)
	{
	  fprintf (stderr, "<<< ERROR set_thread_reg td_thr_setfpregs %d>>>\n",
		   thread->ti.ti_tid);
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
	  fprintf (stderr, "<<< ERROR reg_to_xregset %d %d >>>\n", 
		   thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
      /* Now write the extended regset back to the child. */
      if (td_thr_setxregs_p (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr, "<<< ERROR set_thread_reg td_thr_setxregs %d >>>\n",
		   thread->ti.ti_tid);
	  return -1;	/* fail */
	}
    }
  else if (is_gp_reg (regnum))
    {
      /* First get the current gregset.  */
      if (thread_db_getgregs (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr, "<<< ERROR set_thread_reg td_thr_getgregs %d >>>\n",
		   thread->ti.ti_tid);
	  return -1;	/* fail */
	}
      /* Now write the new reg value into the gregset. */
      if (reg_to_gregset (serv, reg, regnum, gregset) < 0)
	{
	  fprintf (stderr, "<<< ERROR reg_to_gregset %d %d >>>\n", 
		   thread->ti.ti_tid, regnum);
	  return -1;	/* fail */
	}
      /* Now write the gregset back to the child. */
      if (thread_db_setgregs (&thread_handle, gregset) != TD_OK)
	{
	  fprintf (stderr, "<<< ERROR set_thread_reg td_thr_setgregs %d >>>\n",
		   thread->ti.ti_tid);
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
  paddr_t dummy;

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

  /* KLUDGE: Insert some magic symbols into the cached symbol list,
     to be looked up later.  This is badly wrong -- we should be 
     obtaining these values thru the thread_db interface.  Their names
     should not be hard-coded here <sob>. */
  add_symbol_to_list ("__pthread_sig_restart",   0, UNDEFINED);
  add_symbol_to_list ("__pthread_sig_cancel",    0, UNDEFINED);
  add_symbol_to_list ("__pthread_sig_debug",     0, UNDEFINED);
  add_symbol_to_list ("__pthread_threads_debug", 0, UNDEFINED);

  /* Attempt to open the thread_db interface.  This attempt will 
     most likely fail (unles the child is statically linked). */
  thread_db_open (serv, process->pid);	/* Don't test return value */

  /* Take over the "wait" vector. FIXME global object */
  gdbserver.check_child_state = thread_db_check_child_state;
  /* Take over the "fromtarget_break" vector. FIXME global object */
  gdbserver.fromtarget_break = thread_db_fromtarget_thread_break;
  /* FIXME what about terminate and exit? */

  /* Set up the regset caches.  */
  initialize_regset_caches ();
  return 0;		/* success */
}
