/* lwp-pool.h --- interface to a stoppable, waitable LWP pool.

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

#ifndef RDA_UNIX_LWP_POOL_H
#define RDA_UNIX_LWP_POOL_H

#include <sys/types.h>
#include <sys/wait.h>

struct gdbserv;

/* These functions manage a set of LWPs that you can wait for for á là
   waitpid, but that you can also stop and continue as a group without
   disturbing individual threads' wait statuses.

   Here we use "LWP" to mean the kernel-level thingy that is running
   code, and "thread" to mean the POSIX threads / libthread_db-level
   object.  The Linux kernel calls an 'LWP' a 'thread', which would be
   confusing.

   The LWPs must be either children of the calling process, or
   processes we have attached to --- something we will hear about when
   we call 'waitpid'.

   We have separate tables for Unix LWP's and libthread_db threads,
   because even though standard Linux distributions have never used
   M:N threads, there still isn't a simple 1:1 relationship between
   them.  Before the thread library has been loaded and initialized
   itself, you have an LWP with no thread.  After a thread has exited,
   but before any other thread has joined with it, you can have a
   thread with no LWP.  Add that to the way libthread_db reports the
   id of an exited LWP as being equal to ps_getpid (proc_handle), and
   it becomes worthwhile having a clear separation between the two.  */


/* Add PID to the LWP pool, assuming that PID is stopped, and the
   uninteresting wait status has been received (and thrown away).  Use
   this for a child that has been forked, and where we've waited for
   the exec SIGSTOP.  */
void lwp_pool_new_stopped (pid_t pid);


/* Attach to PID, add it to the LWP pool, and wait for it to stop.  If
   PID is already in the pool, do nothing and return 0.  If PID was
   not already in the pool and we successfully attached to it, return
   1.  On failure, return -1 and set errno.

   If there is an interesting wait status available for PID,
   lwp_pool_waitpid will report it, but the wait status caused by the
   attach is handled internally, and will not be reported via
   lwp_pool_waitpid.  */
int lwp_pool_attach (pid_t pid);


/* Do we need a function for detaching from each LWP in the pool
   individually?  */


/* Behave like 'waitpid (PID, STAT_LOC, OPTIONS)', but do not report
   boring wait statuses --- those due to calls to lwp_pool_attach,
   lwp_pool_stop_all, etc.

   PID must be either -1 (wait for any process) or a positive
   integer (wait for the process with that specific pid).

   The only bit that may be set in OPTIONS is WNOHANG.  We need to
   monitor the status of all LWP's, so we add __WALL as appropriate.  */
pid_t lwp_pool_waitpid (pid_t pid, int *stat_loc, int options);


/* Stop all running LWP's in the pool.  This function does not return
   until all LWP's are known to be stopped.

   The wait status caused by the stop is handled internally, and will
   not be reported by lwp_pool_waitpid.  */
void lwp_pool_stop_all (void);


/* Continue all stopped, uninteresting LWP's in the pool.
   If some of the LWP's have been resumed with lwp_pool_singlestep or
   lwp_pool_continue, those will be left to continue to run.  */
void lwp_pool_continue_all (void);


/* Continue LWP.  If SIGNAL is non-zero, continue it with signal
   SIGNAL.  Return zero on success, -1 on failure.  */
int lwp_pool_continue_lwp (pid_t pid, int signal);


/* Continue LWP in SERV for one instruction, delivering SIGNAL if it
   is non-zero, and stop with SIGSTOP if/when that instruction has
   been completed.

   The SERV argument is there because singlestep_lwp requires it.
   Inconsistency, bleah.  */
int lwp_pool_singlestep_lwp (struct gdbserv *serv, pid_t lwp, int signal);


/* Under NPTL, LWP's simply disappear, without becoming a zombie or
   producing any wait status.  At the kernel level, we have no way of
   knowing that the LWP's PID is now free and may be reused ---
   perhaps by an entirely different program!  So we need to use the
   death events from libthread_db to help us keep our LWP table clean.

   There are two steps:

   - first, the thread sends RDA a libthread_db TD_DEATH event,
     indicating that it is about to exit.

   - then, the thread takes some pre-negotiated action (hitting a
     breakpoint; making a system call) to notify libthread_db that
     there are events queued it should attend to.

   What's tricky here is that the queueing of the event and the
   notification are not synchronized.  So RDA could easily receive
   TD_DEATH events for several threads when the first of those threads
   performs its notification.  We need to continue to manage the LWPs
   of the remaining threads whose death is foretold (are there any
   named Santiago?) until they have completed their notifications.

   (And since RDA consumes all the events each time a notification is
   received, we should be prepared to receive notifications even when
   the queue is empty.  But that's not our problem here.)

   So the LWP pool code has the following two entry points:

   - The first indicates that a TD_DEATH event has been received for a
     given thread, and that once it has completed its notification, we
     should expect to hear nothing from it again.

   - The second indicates that some LWP, whether marked for death or
     not, has completed its notification.

   So when a thread completes its notification, *and* that thread has
   been marked for death, we should drop it from the LWP pool.  */


/* Indicate that LWP's death has been foretold by a TD_DEATH message
   from libthread_db.  Once we are told that it has completed its
   event notification by a call to lwp_pool_nptl_death_notified, we
   will forget about LWP entirely.  */
void lwp_pool_thread_db_death_event (pid_t lwp);


/* Indicate that LWP has completed its event notification.  LWP must
   be currently stopped.  If LWP's death has been fortold by a call to
   lwp_pool_nptl_death_event, when LWP is continued, we will remove it
   from the LWP pool and forget about it entirely.  */
void lwp_pool_thread_db_death_notified (pid_t lwp);


#endif /* RDA_UNIX_LWP_POOL_H */
