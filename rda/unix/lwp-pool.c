/* lwp-pool.c --- implementation of a stoppable, waitable LWP pool.

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

#include "config.h"

#define _GNU_SOURCE /* for strerror */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "lwp-pool.h"
#include "lwp-ctrl.h"

#include "diagnostics.h"

int debug_lwp_pool = 0;


/* THE LIFETIME OF A TRACED LWP

   POSIX uses these terms in talking about signals:

   - To "generate" a signal is to call kill or raise, divide by zero,
     etc.

   - To "deliver" a signal is to do whatever that signal's designated
     action is: ignore it, enter a signal handler, terminate the
     process, or stop the process.

   - To "accept" a signal is to have 'sigwait' or a similar function
     select and return the signal.

   - A signal is "pending" between the time it is generated and the
     time it is delivered.

   So, here is the life cycle of a traced LWP:

   - It is created by fork or vfork and does a PTRACE_TRACEME.  The
     PTRACE_TRACEME makes it a traced, running LWP.  When a traced LWP
     does an exec, it gets a SIGTRAP before executing the first
     instruction in the new process image, so the LWP will then stop.

     Or, we attach to it with a PTRACE_ATTACH.  This sends a SIGSTOP
     to the LWP, so it will stop.

   - While a traced LWP is stopped, we can read and write its
     registers and memory.  We can also send it signals; they become
     pending on the LWP, and will be reported by waitpid.

   - A stopped LWP can be set running again in one of two ways:

     + by doing a PTRACE_CONT, PTRACE_SINGLESTEP, or PTRACE_SYSCALL; or

     + by sending it a SIGCONT.

     The ptrace requests all let you specify a signal to be delivered
     to the process.  This is the only way signals (other than
     SIGKILL) ever get actually delivered: every other signal just
     gets reported to the debugger via waitpid when delivery is
     attempted.

     Sending a SIGCONT clears any pending SIGSTOPs; PTRACE_CONT and
     PTRACE_SINGLESTEP don't have that side effect.

     (Sending an LWP a SIGKILL via the 'kill' or 'tkill' system calls
     acts like sending it a SIGKILL followed by a SIGCONT.)

   - A running LWP may exit or be terminated by a signal at any time,
     so accessing its memory or registers or sending it a signal is
     always a race.

   - waitpid will eventually return a status S for a continued LWP:

     + If WIFEXITED (S) or WIFSIGNALED (S), the LWP no longer exists.
     
     + IF WIFSTOPPED (S), the LWP is stopped again, because some
       signal WSTOPSIG (S) was about to be delivered to it.  Here we
       go back to the second step.

       Note that the signal WSTOPSIG (S) has not yet been delivered to
       the process, and is no longer pending on the process.  Only
       signals passed to the ptrace requests get delivered.  In
       effect, the debugger gets to intercept signals before they are
       delivered, and decide whether to pass them through or not.
       (The exception is SIGKILL: that always produces a WIFSIGNALED
       wait status, and terminates the process.)

   So, to put all that together:

   - A traced LWP goes back and forth from running to stopped, until
     eventually it goes from running to exited or killed.

   - Running->stopped transitions are always attempted signal
     deliveries, yielding WIFSTOPPED wait statuses.

   - Stopping->running transitions are generally due to ptrace
     requests by the debugger.  (The debugger could use kill to send
     SIGCONT, but that's messy.)

   - Running->exited transitions are due to, duh, the LWP exiting.

   - Running->killed transitions are due to a signal being delivered
     to the LWP that is neither ignored nor caught.


   Under NPTL, this life cycle is a bit different: LWPs simply exit,
   without creating a zombie; they produce no wait status.  The NPTL
   libthread_db generates a TD_DEATH event for them, but at the kernel
   level the only indication that they're gone is that the tkill
   system call fails with ESRCH ("No such process").

   Under LinuxThreads, LWPs remain zombie processes until they're
   waited for.  Attempts to send them signals while zombies have no
   effect, but return no error.


   STOPPING A PROCESS

   The major challenge here is implementing the lwp_pool_stop_all
   function.  The only way to stop a running LWP is to send it a
   SIGSTOP, and then wait for a status acknowledging the stop.  But as
   explained above, a running LWP could stop at any time of its own
   accord, so sending it a SIGSTOP is always a race.  By the time you
   call waitpid, you don't know whether you'll get a status for the
   SIGSTOP you just sent, or for something else: some other signal, an
   exit, or a termination by signal.

   If the LWP turns out to have exited or died, then that's pretty
   easy to handle.  Your attempt to send a SIGSTOP will get an error,
   and then you'll get a wait status for the termination.  A
   termination status is always the last status you'll get from wait
   for that LWP, so there'll be no further record of your SIGSTOP.

   If the LWP was about to have some other signal delivered to it,
   then the next wait will return a WIFSTOPPED status for that signal;
   we'll have to continue the LWP and wait again until we get the
   status for our SIGSTOP.  The kernel forgets about any signals the
   LWP has received once it has reported them to us, so it's up to us
   to keep track of them and report them via lwp_pool_waitpid.  */



/* The LWP structure.  */

/* The states an LWP we're managing might be in.

   For the purposes of these states, we classify wait statuses as
   follows:

   - An "interesting" wait status is one that isn't a result of us
     attaching to the LWP or sending it a SIGSTOP for
     lwp_pool_stop_all.  It indicates something that happened to the
     LWP other than as a result of this code's fiddling with it.  We
     report all interesting wait statuses via lwp_pool_waitpid.

   - A "boring" wait status is one that results from our attaching to
     it or sending it a SIGSTOP for lwp_pool_stop_all.  We do not
     report these via lwp_pool_stop_all.

   Most of these states are combinations of various semi-independent
   factors, which we'll name and define here:

   - RUNNING / STOPPED / DEAD: These are the kernel states of the LWP:
     it's either running freely and could stop at any moment, is
     stopped but can be continued, or has died.

   - INTERESTING: this LWP has stopped or died with a wait status that
     has not yet been reported via lwp_pool_waitpid.  It is on the
     interesting LWP queue.

     This never applies to RUNNING LWPs: we never continue an
     INTERESTING LWP until we've reported its status.

     It always applies to DEAD LWPs.

   - STOP PENDING: we've sent this LWP a SIGSTOP, or attached to it,
     but we haven't yet received the boring WIFSTOPPED SIGSTOP status.

     This never applies to DEAD LWPs; the wait status that announces a
     LWP's death is always the last for that LWP.

   We could certainly represent these with independent bits or
   bitfields, but not all combinations are possible.  So instead, we
   assign each possible combination a distinct enum value, to make it
   easier to enumerate all the valid possibilities and be sure we've
   handled them.  */

enum lwp_state {

  /* An uninitialized LWP entry.  Only the lookup function itself,
     hash_find, creates entries in this state, and any function
     that calls that should put the entry in a meaningful state before
     returning.  */
  lwp_state_uninitialized,

  /* RUNNING.  This LWP is running --- last we knew.  It may have
     exited or been terminated by a signal, or it may have had a
     signal about to be delivered to it.  We won't know until we wait
     for it.  */
  lwp_state_running,

  /* STOPPED.  This LWP has stopped, and has no interesting status to
     report.  */
  lwp_state_stopped,

  /* STOPPED, INTERESTING.  This LWP has stopped with an interesting
     wait status, which we haven't yet reported to the user.  It is on
     the interesting LWP queue.  */
  lwp_state_stopped_interesting,

  /* DEAD, INTERESTING.  This LWP exited, or was killed by a signal.
     This LWP is on the interesting LWP queue.  Once we've reported it
     to the user, we'll delete it altogether.  */
  lwp_state_dead_interesting,

  /* RUNNING, STOP PENDING.  This LWP was running, and will eventually
     stop with a boring WIFSTOPPED SIGSTOP status, but may report an
     interesting status first.

     It's always safe to wait for an LWP in this state, so we do that
     as soon as possible; there shouldn't be any LWPs in this state
     between calls to public lwp_pool functions.  This is an
     internal-use state.  */
  lwp_state_running_stop_pending,

  /* STOPPED, STOP PENDING.  This LWP is stopped, and has no
     interesting status to report, but still has a boring status on
     the way.  After we report the status for a STOPPED, STOP PENDING,
     and INTERESTING LWP, this is the state it enters.

     See the note below on why this state is not avoidable.  */
  lwp_state_stopped_stop_pending,

  /* STOPPED, STOP PENDING, and INTERESTING.  This LWP has stopped with
     an interesting wait status.  We're also expecting a boring wait
     status from it.  */
  lwp_state_stopped_stop_pending_interesting,

};


/* Why we need lwp_state_stopped_stop_pending:

   I originally thought we could avoid having this state at all by
   simply always continuing STOPPED, STOP PENDING, INTERESTING LWPs
   in lwp_pool_waitpid as soon as we reported their wait status, and
   then waiting for them immediately, making them either STOPPED and
   un-INTERESTING, or STOPPED, STOP PENDING, and INTERESTING again.

   But the user has the right to call lwp_pool_continue_lwp on any LWP
   they've just gotten a wait status for --- and this simplification
   interferes with that.  First, note that you mustn't call
   continue_lwp on an interesting LWP: you might get yet another
   interesting wait status, and we don't want to queue up multiple
   interesting wait statuses per LWP --- the job is complex enough
   already.  Then, note that the proposed simplification means that
   lwp_pool_waitpid could return a status for some LWP, and have that
   LWP still be interesting.  If that happens, then you've got an LWP
   the user has the right to continue, but that can't actually be
   continued.

   I first tried to deal with this by having lwp_pool_continue_lwp
   simply do nothing if the user continues an interesting LWP.  After
   all, it's already in the interesting queue, so lwp_pool_waitpid
   will report it, and the user will be none the wiser.  But that's
   wrong: the user can specify a signal to deliver when they continue
   the LWP, and the only way signals are ever delivered to traced LWPs
   is via ptrace continue and single-step requests.  You can't use
   kill: that *generates* a signal, it doesn't *deliver* it.  You'd
   just get the signal back again via waitpid.  So if we don't
   actually continue the LWP with the user's signal, we've lost our
   only chance to deliver it.

   Clear as mud, no doubt.  I did my best.  */


struct lwp
{
  /* This lwp's PID.  */
  pid_t pid;

  /* The state this LWP is in.  */
  enum lwp_state state;

  /* If STATE is one of the lwp_state_*_interesting states, then this
     LWP is on the interesting LWP queue, headed by interesting_queue.

     If STATE is lwp_state_running_stop_pending, then this LWP is on
     the stopping LWP queue, stopping_queue.  (Note that
     stopping_queue is local to lwp_pool_stop_all; no LWP should be in
     that state by the time that function returns.  */
  struct lwp *prev, *next;

  /* If STATE is one of the lwp_state_*_interesting states, then
     STATUS is the interesting wait status.  */
  int status;

  /* Indicates the stepping status.  We must be prepared to step the
     given lwp upon continue since it's possible to get thread notification
     signals prior to a step actually occuring.  Receipt of a SIGTRAP is
     sufficient to clear this flag.  */
  int do_step;
};
 
  

/* The LWP hash table.  */

/* A hash table of all the live LWP's we know about.
   hash_population is the number of occupied entries in the table.

   hash_size is the total length of the table; it is always a power of
   two.  We resize the table to ensure that it is between 12.5% and
   50% occupied.  (Since the table's size is a power of two, resizing
   the table will always halve or double the populated ratio.  So
   there should be comfortably more than a factor of two between the
   maximum and minimum populations, for hysteresis.)

   The first slot we try is hash[PID % hash_size].  After C
   collisions, we try hash[(PID + C * STRIDE) % hash_size], where
   STRIDE is hash_size / 4 + 1.  The kernel assigns pids sequentially,
   so a STRIDE of 1, as many hash tables use, would make further
   collisions very likely.  But since hash_size is always a power of
   two, and hash_size / 4 + 1 is always odd, they are always
   relatively prime, so stepping by that many elements each time will
   eventually visit every table element.  A constant odd stride would
   be fine, but it's nice to have it scale with the overall population
   of the table.

   The table is an array of pointers to lwp's, rather than a direct
   array of lwp structures, so that pointers to lwp's don't become
   invalid when we rehash or delete entries.  */
static size_t hash_size, hash_population;
static struct lwp **hash;

/* The minimum size for the hash table.  Small for testing.  */
enum { minimum_hash_size = 8 };


/* Return the hash slot for pid PID.  */
static int
hash_slot (pid_t pid, size_t size)
{
  return pid & (size - 1);
}


/* If there was a collision in SLOT, return the next slot.  */
static int
hash_next_slot (int slot, size_t size)
{
  int stride = size / 4 + 1;

  return (slot + stride) & (size - 1);
}


/* Return the earliest empty hash slot for PID.  */
static int
hash_empty_slot (pid_t pid)
{
  int slot = hash_slot (pid, hash_size);

  /* Since hash_next_slot will eventually visit every slot, and we
     know the table isn't full, this loop will terminate.  */
  while (hash[slot])
    slot = hash_next_slot (slot, hash_size);

  return slot;
}


/* Return a new, empty hash table containing ELEMENTS elements.  This has
   no effect on the LWP pool's global variables.  */
static struct lwp **
make_hash_table (size_t elements)
{
  struct lwp **hash;
  size_t size = elements * sizeof (*hash);

  hash = malloc (size);
  memset (hash, 0, size);

  return hash;
}


/* Resize hash as needed to ensure that the table's population is
   between 12.5% and 50% of its size.  */
static void
resize_hash (void)
{
  struct lwp **new_hash;
  size_t new_hash_size;
  int new_hash_population; /* just for sanity checking */
  int i;

  /* Pick a new size.  */
  new_hash_size = hash_size;
  while (new_hash_size < hash_population * 2)
    new_hash_size *= 2;
  while (new_hash_size > minimum_hash_size
	 && new_hash_size > hash_population * 8)
    new_hash_size /= 2;

  /* We may have re-chosen the minimum table size.  */
  if (new_hash_size == hash_size)
    return;

  new_hash = make_hash_table (new_hash_size);
  new_hash_population = 0;

  /* Re-insert all the old lwp's in the new table.  */
  for (i = 0; i < hash_size; i++)
    if (hash[i])
      {
	struct lwp *l = hash[i];
	int new_slot = hash_slot (l->pid, new_hash_size);

	while (new_hash[new_slot])
	  new_slot = hash_next_slot (new_slot, new_hash_size);

	new_hash[new_slot] = l;
	new_hash_population++;
      }

  if (new_hash_population != hash_population)
    fprintf (stderr, "ERROR: rehashing changed population from %d to %d\n",
	     hash_population, new_hash_population);

  /* Free the old table, and drop in the new one.  */
  free (hash);
  hash = new_hash;
  hash_size = new_hash_size;
}


/* Find an existing hash table entry for LWP.  If there is none,
   create one in state lwp_state_uninitialized.  */
static struct lwp *
hash_find (pid_t lwp)
{
  int slot;
  struct lwp *l;

  /* Do we need to initialize the hash table?  */
  if (! hash)
    {
      hash_size = minimum_hash_size;
      hash = make_hash_table (hash_size);
      hash_population = 0;
    }

  for (slot = hash_slot (lwp, hash_size);
       hash[slot];
       slot = hash_next_slot (slot, hash_size))
    if (hash[slot]->pid == lwp)
      return hash[slot];

  /* There is no entry for this lwp.  Create one.  */
  l = malloc (sizeof (*l));
  l->pid = lwp;
  l->state = lwp_state_uninitialized;
  l->next = l->prev = NULL;
  l->status = 42;
  l->do_step = 0;

  hash[slot] = l;
  hash_population++;

  /* Do we need to resize?  */
  if (hash_size < hash_population * 2)
    resize_hash ();

  return l;
}


/* Remove the LWP L from the pool.  This does not free L itself.  */
static void
hash_delete (struct lwp *l)
{
  int slot;

  for (slot = hash_slot (l->pid, hash_size);
       hash[slot];
       slot = hash_next_slot (slot, hash_size))
    if (hash[slot]->pid == l->pid)
      break;

  /* We shouldn't ever be asked to delete a 'struct lwp' that isn't in
     the table.  */
  assert (hash[slot]);

  /* There should be only one 'struct lwp' with a given PID.  */
  assert (hash[slot] == l);

  /* Deleting from this kind of hash table is interesting, because of
     the way we handle collisions.

     For the sake of discussion, pretend that STRIDE is 1 (the
     reasoning is basically the same either way, but this has less
     hair).

     When we search for an LWP that hashes to slot S, because there
     may be collisions, the set of slots we'll actually search is the
     contiguous run of non-empty table entries that starts at S,
     heading towards higher indices (and possibly wrapping around at
     the end of the table).  When we find an empty table entry, we
     give up the search.

     When we delete an LWP, if we simply set its slot to zero, that
     could cause us to cut off later searches too early.  For example,
     if three LWP's all hash to slot S, and have been placed in slots
     S, S+1, and S+2, and we set slot S+1 to zero, then a search for
     the LWP at S+2 will start at S, and then stop at S+1 without ever
     seeing the right entry at S+2.

     Some implementations place a special "deleted" marker in the slot
     to let searches continue.  But then it's hard to ensure that the
     table doesn't get choked with deleted markers; and should deleted
     markers count towards the population for resizing purposes?  It's
     a mess.

     So after clearing a slot, we walk the remainder of the contiguous
     run of entries and re-hash them all.  If the hash function is
     doing a good job distributing entries across the table,
     contiguous runs should be short.  And it had better be good,
     because this is potentially quadratic.

     Of course, if we're going to resize the table, that removes all
     deleted elements, so we needn't bother with any of this.  */

  hash[slot] = NULL;
  hash_population--;

  if (hash_size > minimum_hash_size
      && hash_size > hash_population * 8)
    resize_hash ();
  else
    for (slot = hash_next_slot (slot, hash_size);
	 hash[slot];
	 slot = hash_next_slot (slot, hash_size))
      {
	struct lwp *refugee = hash[slot];

	hash[slot] = NULL;
	hash[hash_empty_slot (refugee->pid)] = refugee;
      }
}



/* Queue functions.  */ 

/* Insert L at the end of the queue headed by QUEUE.  */ 
static void
queue_enqueue (struct lwp *queue, struct lwp *l)
{
  assert (! l->next && ! l->prev);

  l->next = queue;
  l->prev = queue->prev;
  l->prev->next = l;
  l->next->prev = l;
}


/* If L is part of some queue, remove it.  */
static void
queue_delete (struct lwp *l)
{
  assert (l->next && l->prev);

  l->next->prev = l->prev;
  l->prev->next = l->next;
  l->next = l->prev = NULL;
}


/* Return non-zero if there is anything in QUEUE, zero otherwise.  */
static int
queue_non_empty (struct lwp *queue)
{
  return queue->next != queue;
}


/* Return the first LWP from QUEUE, but don't remove it.  If QUEUE is
   empty, return NULL.  */
static struct lwp *
queue_first (struct lwp *queue)
{
  struct lwp *l = queue->next;

  if (l != queue)
    return l;
  else
    return NULL;
}



/* Hashing LWP's, but with error checking and cleanup.  */


/* Add an entry for LWP to the pool and return it.  There should be no
   existing entry for LWP; if there is, clean it up.  The returned
   LWP's state is always lwp_state_uninitialized; the caller must
   initialize the LWP before returning.  */
static struct lwp *
hash_find_new (pid_t lwp)
{
  struct lwp *l = hash_find (lwp);

  if (l->state != lwp_state_uninitialized)
    {
      fprintf (stderr, "ERROR: new LWP %d already in table\n", (int) lwp);

      /* Remove ourselves from any queue we might be in.  */
      if (l->next)
	queue_delete (l);
    }

  l->state = lwp_state_uninitialized;

  return l;
}


/* Find an entry for an existing LWP, and return it.  If we have no
   existing entry for LWP, print an error message, but return the new,
   uninitialized entry anyway.  */
static struct lwp *
hash_find_known (pid_t lwp)
{
  struct lwp *l = hash_find (lwp);

  if (l->state == lwp_state_uninitialized)
    fprintf (stderr, "ERROR: unexpected lwp: %d\n", (int) lwp);

  return l;
}



/* Waiting.  */


/* The head of the queue of LWP's with interesting wait statuses.
   Only the prev and next members are meaningful.

   Every LWP in one of the lwp_state_*_interesting states should be on
   this queue.  If an LWP's state is lwp_state_dead_interesting, the
   LWP is not in the hash table any more.  */
static struct lwp interesting_queue
= { -1, 0, &interesting_queue, &interesting_queue, 42 };


static const char *
wait_status_str (int status)
{
  static char buf[100];

  if (WIFSTOPPED (status))
    sprintf (buf, "WIFSTOPPED (s) && WSTOPSIG (s) == %d (%s)",
	     WSTOPSIG (status), strsignal (WSTOPSIG (status)));
  else if (WIFEXITED (status))
    sprintf (buf, "WIFEXITED (s) && WEXITSTATUS (s) == %d",
	     WEXITSTATUS (status));
  else if (WIFSIGNALED (status))
    sprintf (buf, "WIFSIGNALED (s) && WTERMSIG (s) == %d (%s)%s",
	     WTERMSIG (status),
	     strsignal (WTERMSIG (status)),
	     WCOREDUMP (status) ? " && WCOREDUMP(s)" : "");
  else
    sprintf (buf, "%d (unrecognized status)", status);

  return buf;
}


static const char *
wait_flags_str (int flags)
{
  static const struct {
    int flag;
    const char *name;
  } flag_table[] = {
    { WNOHANG, "WNOHANG" },
    { WUNTRACED, "WUNTRACED" },
#ifdef __WCLONE
    { __WCLONE, "__WCLONE" },
#endif
#ifdef __WALL
    { __WALL, "__WALL" },
#endif
#ifdef __WNOTHREAD
    { __WNOTHREAD, "__WNOTHREAD" },
#endif
    { 0, 0 }
  };
  static char buf[100];
  int i;

  buf[0] = '\0';
  for (i = 0; flag_table[i].flag; i++)
    if (flags & flag_table[i].flag)
      {
	strcat (buf, flag_table[i].name);
	flags &= ~flag_table[i].flag;
	if (flags)
	  strcat (buf, " | ");
      }

  if (flags)
    sprintf (buf + strlen (buf), "0x%x", (unsigned) flags);

  if (buf[0] == '\0')
    return "0";
  else
    return buf;
}


static const char *
lwp_state_str (enum lwp_state state)
{
  switch (state)
    {
    case lwp_state_uninitialized:
      return "uninitialized";
    case lwp_state_running:
      return "running";
    case lwp_state_stopped:
      return "stopped";
    case lwp_state_stopped_interesting:
      return "stopped_interesting";
    case lwp_state_dead_interesting:
      return "dead_interesting";
    case lwp_state_running_stop_pending:
      return "running_stop_pending";
    case lwp_state_stopped_stop_pending:
      return "stopped_stop_pending";
    case lwp_state_stopped_stop_pending_interesting:
      return "stopped_stop_pending_interesting";
    default:
      {
	static char buf[100];
	sprintf (buf, "%d (unrecognized lwp_state)", state);
	return buf;
      }
    }
}


static void
debug_report_state_change (struct gdbserv *serv,
                           pid_t lwp,
			   enum lwp_state old,
			   enum lwp_state new)
{
  if (debug_lwp_pool && old != new)
    {
      fprintf (stderr,
	       "%32s -- %5d -> %s",
	       lwp_state_str (old), (int) lwp, lwp_state_str (new));
      if (new == lwp_state_stopped)
	fprintf (stderr, "    (at %#lx)", debug_get_pc (serv, lwp));
      fprintf (stderr, "\n");
    }
}

/* Remove (dead) LWP from the hash table and put it on the `interesting'
   queue.  */
static void
mark_lwp_as_dead_but_interesting (struct lwp *l)
{
  hash_delete (l);
  l->state = lwp_state_dead_interesting;
  if (l->next)
    queue_delete (l);
  queue_enqueue (&interesting_queue, l);
}

/* Wait for a status from the LWP L (or any LWP, if L is NULL),
   passing FLAGS to waitpid, and record the resulting wait status in
   the LWP pool appropriately.

   If no wait status was available (if FLAGS & WNOHANG), return zero.
   If we successfully processed some wait status, return 1.  If an
   error occurs, set errno and return -1.

   If waitpid returns an error, print a message to stderr.  */
static int
wait_and_handle (struct gdbserv *serv, struct lwp *l, int flags)
{
  int status;
  pid_t new_pid; 
  enum lwp_state old_state;
  
  /* We can only wait for LWP's that are running.  */
  if (l)
    assert (l->state == lwp_state_running
	    || l->state == lwp_state_running_stop_pending);

  /* This should be the only call to waitpid in this module, to ensure
     that we always keep each LWP's state up to date.  In fact, it
     should be the only call to waitpid used by any module using the
     LWP pool code at all.  */
  new_pid = waitpid (l ? l->pid : -1, &status, flags);

  if (debug_lwp_pool)
    {
      fprintf (stderr,
	       "lwp_pool: wait_and_handle: waitpid (%d, %s, %s) == %d\n",
	       l ? l->pid : -1,
	       (new_pid <= 0 ? "(unset)" : wait_status_str (status)),
	       wait_flags_str (flags),
	       new_pid);
    }

  if (new_pid == -1)
    {
      /* If we call fprintf, that'll wipe out the value of errno.  */
      int saved_errno = errno;

      fprintf (stderr, "ERROR: waitpid (%d) failed: %s\n",
	       l ? (int) l->pid : -1,
	       strerror (saved_errno));

      errno = saved_errno;
      return -1;
    }

  if (new_pid == 0)
    /* No status, so no LWP has changed state.  */
    return 0;

  if (l)
    {
      if (l->pid != new_pid)
	{
	  fprintf (stderr, "ERROR: waited for %d, but got %d\n",
		   l->pid, new_pid);
	  l = hash_find_known (new_pid);
	}
    }
  else
    l = hash_find_known (new_pid);

  old_state = l->state;
  
  l->status = status;

  if (WIFEXITED (status) || WIFSIGNALED (status))
    mark_lwp_as_dead_but_interesting (l);
  else
    {
      int stopsig;

      assert (WIFSTOPPED (status));
      
      stopsig = WSTOPSIG (status);

      if (stopsig == SIGTRAP)
	{
	  /* No longer stepping once a SIGTRAP is received.  */
	  l->do_step = 0;
	}

      switch (l->state)
	{
	case lwp_state_uninitialized:
	  /* Might as well clean it up.  */
	case lwp_state_running:
	  /* It stopped, but not because of anything we did, so it's
	     interesting even if it was a SIGSTOP.  */
	  l->state = lwp_state_stopped_interesting;
	  queue_enqueue (&interesting_queue, l);
	  break;

	case lwp_state_running_stop_pending:

	  /* If we were in stopping_queue, we're stopped now.  */
	  if (l->next)
	    queue_delete (l);

	  /* We are expecting a boring SIGSTOP.  Is this it?  */
	  if (stopsig == SIGSTOP)
	    l->state = lwp_state_stopped;
	  else
	    {
	      /* Report this status, but remember that we're still
		 expecting the boring SIGSTOP.  */
	      l->state = lwp_state_stopped_stop_pending_interesting;
	      queue_enqueue (&interesting_queue, l);
	    }
	  break;

	default:
	  /* The assert at top should prevent any other states from
	     showing up here.  */
	  fprintf (stderr, "ERROR: called waitpid on LWP %d in bad state %s\n",
		   (int) l->pid, lwp_state_str (l->state));
	  abort ();
	  break;
	}
    }

  debug_report_state_change (serv, l->pid, old_state, l->state);

  return 1;
}


/* Wait for a pending stop on the running LWP L.  Return non-zero if L
   ends up in an interesting state, or zero if L ends up in
   lwp_state_stopped.

   Whenever we have an LWP with no interesting status, but with a stop
   pending, we can always wait on it:

   - Since SIGCONT can't be blocked, caught, or ignored, the wait will
     always return immediately.  The process won't run amok.

   - Since the LWP is uninteresting to begin with, we'll end up with
     at most one interesting wait status to report; no need to queue
     up multiple statuses per LWP (which we'd rather not implement if
     we can avoid it).

   So, this function takes an LWP in lwp_state_running_stop_pending,
   and puts that LWP in either lwp_state_stopped (no stop pending) or
   some INTERESTING state.  It's really just wait_and_handle, with
   some error checking wrapped around it.  */
static int
check_stop_pending (struct gdbserv *serv, struct lwp *l)
{
  assert (l->state == lwp_state_running_stop_pending);

  wait_and_handle (serv, l, __WALL);

  switch (l->state)
    {
    case lwp_state_stopped:
      return 0;

    case lwp_state_stopped_stop_pending_interesting:
    case lwp_state_dead_interesting:
      return 1;

    case lwp_state_stopped_interesting:
      /* This state shouldn't happen: since there was a pending stop,
         a single waitpid on that LWP should have either gotten the
         SIGSTOP, yielding 'lwp_state_stopped', or something interesting,
         yielding 'lwp_state_stopped_stop_pending_interesting'.  */
    default:
      fprintf (stderr,
	       "ERROR: checking lwp %d for pending stop yielded "
	       "bad state %s\n",
	       (int) l->pid, lwp_state_str (l->state));
      hash_delete (l);
      if (l->next)
	queue_delete (l);
      free (l);
      return 0;
    }
}


pid_t
lwp_pool_waitpid (struct gdbserv *serv, pid_t pid, int *stat_loc, int options)
{
  struct lwp *l;
  enum lwp_state old_state;
  
  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_waitpid (%d, stat_loc, %s)\n",
	     (int) pid, wait_flags_str (options));

  /* Check that we're not being passed arguments that would be
     meaningful for the real waitpid, but that we can't handle.  */
  assert (pid == -1 || pid > 0);
  assert (! (options & ~WNOHANG));

  /* Do the wait, and choose an LWP to report on.  */
  if (pid == -1)
    {
      /* Handle wait statuses of any sort until something appears on
	 the interesting queue.  */
      while (! queue_non_empty (&interesting_queue))
	{
	  int result = wait_and_handle (serv, NULL, options | __WALL);

	  if (result <= 0)
	    return result;
	}

      l = queue_first (&interesting_queue);
    }
  else
    {
      /* Waiting for a status from a specific pid PID.  */
      l = hash_find_known (pid);

      /* We should only wait for known, running LWP's.  */
      assert (l->state == lwp_state_running
	      || l->state == lwp_state_running_stop_pending);

      /* Wait until this pid is no longer running.  */
      while (l->state == lwp_state_running
	     || l->state == lwp_state_running_stop_pending)
	{
	  int result = wait_and_handle (serv, l, options | __WALL);

	  if (result <= 0)
	    return result;
	}
    }

  /* Gather info from L early, in case we free it.  */
  pid = l->pid;
  old_state = l->state;
  if (stat_loc)
    *stat_loc = l->status;

  /* The INTERESTING states specifically mean that the LWP has a
     status which should be reported to the user, but that hasn't been
     yet.  Now we're about to report that status, so we need to mark
     interesting LWP's as uninteresting.  */
  switch (l->state)
    {
    case lwp_state_uninitialized:
    case lwp_state_running:
    case lwp_state_stopped:
    case lwp_state_stopped_stop_pending:
    case lwp_state_running_stop_pending:
      /* These are uninteresting states.  The waiting code above
	 should never have chosen an LWP in one of these states.  */
      fprintf (stderr,
	       "ERROR: %s: selected uninteresting LWP %d state %s\n",
	       __func__, l->pid, lwp_state_str (l->state));
      abort ();
      break;

    case lwp_state_stopped_interesting:
      /* Now that we've reported this wait status to the user, the LWP
	 is not interesting any more.  */
      l->state = lwp_state_stopped;
      queue_delete (l);
      debug_report_state_change (serv, l->pid, old_state, l->state);
      break;

    case lwp_state_dead_interesting:
      /* Once we've reported this status, we have washed our hands of
	 this LWP entirely.  */
      queue_delete (l);
      free (l);
      if (debug_lwp_pool)
	fprintf (stderr, 
		 "lwp_pool: %s: LWP %d state dead_interesting -> freed\n",
		 __func__, pid);
      break;

    case lwp_state_stopped_stop_pending_interesting:
      /* We're about to report this LWP's status, making it
	 uninteresting, but it's still got a stop pending.  */
      queue_delete (l);
      l->state = lwp_state_stopped_stop_pending;
      debug_report_state_change (serv, l->pid, old_state, l->state);
      break;

    default:
      fprintf (stderr, "ERROR: lwp %d in bad state: %s\n",
	       (int) l->pid, lwp_state_str (l->state));
      abort ();
      break;
    }

  return pid;
}



/* Stopping and continuing.  */


void
lwp_pool_stop_all (struct gdbserv *serv)
{
  int i;

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_stop_all ()\n");

  /* The head of the queue of running LWP's that we are stopping.
     Only the prev and next members are meaningful.  */
  struct lwp stopping_queue;

  stopping_queue.next = stopping_queue.prev = &stopping_queue;

  /* First, put every LWP that's not already STOPPED or DEAD in a STOP
     PENDING state, and put them all on stopping_queue.  */ 
  for (i = 0; i < hash_size; i++)
    {
      struct lwp *l = hash[i];

      if (l)
	{
	  enum lwp_state old_state = l->state;

	  switch (l->state)
	    {
	      /* There should never be 'uninitialized' entries left in
		 the table.  Whoever created them ought to have put them
		 in some meaningful state before returning.  */
	    case lwp_state_uninitialized:
	      assert (l->state != lwp_state_uninitialized);
	      break;

	    case lwp_state_running:
	      /* A 'no such process' error here indicates an NPTL thread
		 that has exited.  */
	      if (kill_lwp (l->pid, SIGSTOP) < 0)
		{
		  /* Thread has exited.  See if a status is available.  */
		  if (wait_and_handle (serv, l, WNOHANG) < 0)
		    {
		      /* Nope, it's truly gone without providing a status.
		         Put it on the interesting queue so that GDB is
			 notified that it's gone.  */
		      l->status = 0;
		      mark_lwp_as_dead_but_interesting (l);
		    }
		}
	      else
		{
		  l->state = lwp_state_running_stop_pending;
		  queue_enqueue (&stopping_queue, l);
		}

	      break;

	    case lwp_state_stopped:
            case lwp_state_stopped_stop_pending:
	    case lwp_state_stopped_interesting:
	    case lwp_state_dead_interesting:
	    case lwp_state_stopped_stop_pending_interesting:
	      /* Nothing needs to be done here.  */
	      break;

	    case lwp_state_running_stop_pending:
	      /* LWPs should never be in this state between calls to
		 public lwp_pool functions.  */
	      assert (l->state != lwp_state_running_stop_pending);
	      break;

	    default:
	      fprintf (stderr, "ERROR: lwp %d in bad state: %s\n",
		       (int) l->pid, lwp_state_str (l->state));
	      abort ();
	      break;
	    }

	  debug_report_state_change (serv, l->pid, old_state, l->state);
	}
    }

  /* Gather wait results until the stopping queue is empty.  */
  while (queue_non_empty (&stopping_queue))
    if (wait_and_handle (serv, NULL, __WALL) < 0)
      {
	fprintf (stderr, "ERROR: lwp_pool_stop_all wait failed: %s",
		 strerror (errno));
	return;
      }

  /* Now all LWPs should be stopped or dead.  But let's check.  */
  for (i = 0; i < hash_size; i++)
    {
      struct lwp *l = hash[i];
      if (l)
	switch (l->state)
	  {
	  case lwp_state_uninitialized:
	    assert (l->state != lwp_state_uninitialized);
	    break;

	  case lwp_state_running:
	  case lwp_state_running_stop_pending:
	    fprintf (stderr,
		     "ERROR: lwp_pool_stop_all failed: LWP %d still running\n",
		     (int) l->pid);
	    break;

	  case lwp_state_stopped:
          case lwp_state_stopped_stop_pending:
	  case lwp_state_stopped_interesting:
	  case lwp_state_dead_interesting:
	  case lwp_state_stopped_stop_pending_interesting:
	    /* That's all as it should be.  */
	    break;

	  default:
	    fprintf (stderr, "ERROR: lwp %d in bad state: %s\n",
		     (int) l->pid, lwp_state_str (l->state));
	    abort ();
	    break;
	  }
    }
}

int
continue_or_step_lwp (struct gdbserv *serv, struct lwp *l, int sig)
{
  int status;
  if (l->do_step)
    status = singlestep_lwp (serv, l->pid, sig);
  else
    status = continue_lwp (l->pid, sig);

  return status;
}


void
lwp_pool_continue_all (struct gdbserv *serv)
{
  int i;

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_continue_all ()\n");

  /* This loop makes every LWP either INTERESTING, or RUNNING.  */
  for (i = 0; i < hash_size; i++)
    {
      struct lwp *l = hash[i];

      if (l)
	{
	  enum lwp_state old_state = l->state;

	  switch (l->state)
	    {
	      /* There should never be 'uninitialized' entries left in
		 the table.  Whoever created them ought to have put them
		 in some meaningful state before returning.  */
	    case lwp_state_uninitialized:
	      assert (l->state != lwp_state_uninitialized);
	      break;

	    case lwp_state_running:
	      /* It's already running, so nothing needs to be done.  */
	      break;

	    case lwp_state_stopped:
	      if (continue_or_step_lwp (serv, l, 0) == 0)
		l->state = lwp_state_running;
	      break;

	    case lwp_state_stopped_interesting:
	    case lwp_state_dead_interesting:
	    case lwp_state_stopped_stop_pending_interesting:
	      /* We still have an unreported wait status here, so leave it
		 alone; we'll report it.  */
	      break;

	    case lwp_state_running_stop_pending:
	      /* There shouldn't be any LWPs in this state at this
		 point.  We should be calling check_stop_pending or
		 wait_and_handle as soon as we create them.  */
	      assert (l->state != lwp_state_running_stop_pending);
	      break;

            case lwp_state_stopped_stop_pending:
              /* Continue it, and then wait for the pending stop.
                 Since SIGSTOP cannot be blocked, caught, or ignored,
                 the wait will always return immediately; the LWP
                 won't run amok.  */
              if (continue_lwp (l->pid, 0) == 0)
                {
                  l->state = lwp_state_running_stop_pending;
                  if (check_stop_pending (serv, l) == 0)
                    {
                      if (continue_or_step_lwp (serv, l, 0) == 0)
                        l->state = lwp_state_running;
                    }
                }
              break;

	    default:
	      fprintf (stderr, "ERROR: lwp %d in bad state: %s\n", 
		       (int) l->pid, lwp_state_str (l->state));
	      abort ();
	      break;
	    }

	  debug_report_state_change (serv, l->pid, old_state, l->state);
	}
    }
}


int
lwp_pool_continue_lwp (struct gdbserv *serv, pid_t pid, int signal)
{
  struct lwp *l = hash_find_known (pid);
  enum lwp_state old_state = l->state;
  int result = 0;

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_continue_lwp (%d, %d)\n",
	     (int) pid, signal);

  switch (l->state)
    {
    case lwp_state_uninitialized:
      assert (l->state != lwp_state_uninitialized);
      break;

      /* We should only be continuing LWPs that have reported a
         WIFSTOPPED status via lwp_pool_waitpid and have not been
         continued or singlestepped since.  */
    case lwp_state_running:
    case lwp_state_stopped_interesting:
    case lwp_state_dead_interesting:
    case lwp_state_running_stop_pending:
    case lwp_state_stopped_stop_pending_interesting:
      fprintf (stderr, "ERROR: continuing LWP %d in unwaited state: %s\n",
               (int) l->pid, lwp_state_str (l->state));
      break;

    case lwp_state_stopped:
      result = continue_or_step_lwp (serv, l, signal);
      if (result == 0)
        l->state = lwp_state_running;
      break;

    case lwp_state_stopped_stop_pending:
      /* Continue it, delivering the given signal, and then wait for
         the pending stop.  Since SIGSTOP cannot be blocked, caught,
         or ignored, the wait will always return immediately; the LWP
         won't run amok.

         We must deliver the signal with the first continue_lwp call;
         if check_stop_pending says the LWP has a new interesting
         status, then we'll never reach the second continue_lwp, and
         we'll lose our chance to deliver the signal.  */
      if (continue_lwp (l->pid, signal) == 0)
        {
          l->state = lwp_state_running_stop_pending;
          if (check_stop_pending (serv, l) == 0)
            {
              if (continue_or_step_lwp (serv, l, 0) == 0)
                l->state = lwp_state_running;
            }
        }
      break;

    default:
      fprintf (stderr, "ERROR: lwp %d in bad state: %s\n", 
               (int) l->pid, lwp_state_str (l->state));
      abort ();
      break;
    }

  debug_report_state_change (serv, l->pid, old_state, l->state);

  return result;
}


/* Clear the `do_step' flags for all LWPs in the hash table.  */

static void
clear_all_do_step_flags (void)
{
  int i;

  for (i = 0; i < hash_size; i++)
    {
      struct lwp *l = hash[i];

      if (l)
	l->do_step = 0;
    }
}


int
lwp_pool_singlestep_lwp (struct gdbserv *serv, pid_t lwp, int signal)
{
  struct lwp *l = hash_find_known (lwp);
  enum lwp_state old_state = l->state;
  int result = 0;

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_singlestep_lwp (%p, %d, %d)\n",
	     serv, (int) lwp, signal);

  /* Neither GDB nor the software singlestep code contained in RDA
     expect more than one LWP to be stepped simultaneously.  Clear the
     `do_step' flag in all LWPs.  The flag for the LWP that we're about
     to step will be set later on.  */
  clear_all_do_step_flags ();

  switch (l->state)
    {
    case lwp_state_uninitialized:
      assert (l->state != lwp_state_uninitialized);
      break;

      /* We should only be stepping LWPs that have reported a
         WIFSTOPPED status via lwp_pool_waitpid and have not been
         continued or singlestepped since.  */
    case lwp_state_running:
    case lwp_state_stopped_interesting:
    case lwp_state_dead_interesting:
    case lwp_state_running_stop_pending:
    case lwp_state_stopped_stop_pending_interesting:
      fprintf (stderr, "ERROR: stepping LWP %d in unwaited state: %s\n",
               (int) l->pid, lwp_state_str (l->state));
      break;

    case lwp_state_stopped:
      result = singlestep_lwp (serv, l->pid, signal);
      if (result == 0)
	{
	  l->state = lwp_state_running;
	  l->do_step = 1;
	}
      break;

    case lwp_state_stopped_stop_pending:
      /* Continue it, delivering the given signal, and then wait for
         the pending stop.  Since SIGSTOP cannot be blocked, caught,
         or ignored, the wait will always return immediately; the LWP
         won't run amok.

         We must deliver the signal with the continue_lwp call; if
         check_stop_pending says the LWP has a new interesting status,
         then we'll never reach the singlestep_lwp, and we'll lose our
         chance to deliver the signal at all.  */
      if (continue_lwp (l->pid, signal) == 0)
        {
          l->state = lwp_state_running_stop_pending;
          if (check_stop_pending (serv, l) == 0)
            {
              if (singlestep_lwp (serv, l->pid, 0) == 0)
		{
		  l->state = lwp_state_running;
		  l->do_step = 1;
		}
            }
        }
      break;

    default:
      fprintf (stderr, "ERROR: lwp %d in bad state: %s\n", 
               (int) l->pid, lwp_state_str (l->state));
      abort ();
      break;
    }

  debug_report_state_change (serv, l->pid, old_state, l->state);

  return result;
}



/* Adding new LWP's to the pool.  */

void
lwp_pool_new_stopped (pid_t pid)
{
  struct lwp *l = hash_find_new (pid);

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_new_stopped (%d)\n", (int) pid);

  l->state = lwp_state_stopped;

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool: %s: new LWP %d state %s\n",
	     __func__, l->pid, lwp_state_str (l->state));
}


int
lwp_pool_attach (struct gdbserv *serv, pid_t pid)
{
  /* Are we already managing this LWP?  */
  struct lwp *l = hash_find (pid);

  if (debug_lwp_pool)
    fprintf (stderr, "lwp_pool_attach (%d)\n", (int) pid);

  if (l->state == lwp_state_uninitialized)
    {
      /* No, we really need to attach to it.  */
      int status = attach_lwp (pid);

      if (status)
	{
	  /* Forget about the lwp.  */
	  hash_delete (l);
	  free (l);
	  return status;
	}

      /* Since we attached to it, we'll get a SIGSTOP for this
	 eventually.  Wait for it now, to put it in either
	 lwp_state_stopped, or in some interesting state.  */
      l->state = lwp_state_running_stop_pending;

      if (debug_lwp_pool)
	fprintf (stderr, "lwp_pool: %s: new LWP %d state %s\n",
		 __func__, l->pid, lwp_state_str (l->state));

      check_stop_pending (serv, l);

      return 1;
    }
     
  return 0;
}
