/* gdbserv-target.c

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
#include <stdio.h>
#include <assert.h>
#include "gdbserv-state.h"
#include "gdbserv-utils.h"
#include "gdbserv.h"

void
gdbserv_fromtarget (struct gdbserv *gdbserv,
		    struct gdbserv_thread *thread,
		    enum gdbserv_fromtarget_event event,
		    const struct gdbserv_reg *stop_addr,
		    int sigval)
{
  gdbserv->from->target->from (gdbserv->from, thread,
			       event, stop_addr, sigval);
}

/* compatibility */
void
gdbserv_fromtarget_break (struct gdbserv *gdbserv,
			  int sigval)
{
  gdbserv_fromtarget (gdbserv, NULL, GDBSERV_FROMTARGET_STOPPED,
		      NULL, sigval);
}

/* compatibility */
void
gdbserv_fromtarget_thread_break (struct gdbserv *gdbserv,
				 struct gdbserv_thread *thread,
				 int sigval)
{
  gdbserv_fromtarget (gdbserv, thread, GDBSERV_FROMTARGET_STOPPED,
		      NULL, sigval);
}

/* compatibility */
void
gdbserv_fromtarget_exit (struct gdbserv *gdbserv, int exitval)
{
  gdbserv_fromtarget (gdbserv, NULL, GDBSERV_FROMTARGET_EXITED,
		      NULL, exitval);
}

/* compatibility */
void
gdbserv_fromtarget_terminate (struct gdbserv *gdbserv, int exitval)
{
  gdbserv_fromtarget (gdbserv, NULL, GDBSERV_FROMTARGET_TERMINATED,
		      NULL, exitval);
}

/* compatibility */
void
gdbserv_fromtarget_restarted (struct gdbserv *gdbserv)
{
  gdbserv_fromtarget (gdbserv, NULL, GDBSERV_FROMTARGET_STOPPED,
		      NULL, GDBSERV_SIGNONE);
}

/* compatibility */
void
gdbserv_fromtarget_reset (struct gdbserv *gdbserv)
{
  gdbserv_fromtarget (gdbserv, NULL, GDBSERV_FROMTARGET_STOPPED,
		      NULL, GDBSERV_SIGNONE);
}


enum gdbserv_target_rc
gdbserv_totarget (struct gdbserv *parent,
		  struct gdbserv_thread *thread,
		  enum gdbserv_totarget_event event,
		  const struct gdbserv_reg *start_addr,
		  int sigval)
{
  struct gdbserv_reg tmpsig;
  struct gdbserv_reg *sig;
  struct gdbserv *gdbserv = parent->to;
  struct gdbserv_target *target = parent->to->target;
  if (target->to != NULL)
    return target->to (gdbserv, thread, event, start_addr, sigval);

  /* Hand hold older targets. */

  /* If there is a start_addr, then something needs to be done with
     it.  If the target hasn't provided a full-functional ->to()
     method then perhaphs they have provided the legacy
     process_set_pc() */
  if (start_addr != NULL
      && target->process_set_pc != NULL)
    {
      target->process_set_pc (gdbserv, start_addr);
      start_addr = NULL;
    }

  /* By now the target should have been told of the START_ADDR.  If it
     hasn't then things are seriously wrong - the client is expecting
     the target to resume at START_ADDR but it ain't going to
     happen. */
  assert (start_addr == NULL);

  /* Flush the instruction cache.  We may have deposited a breakpoint,
     and the icache probably has no way of knowing that a data ref to
     some location may have changed something that is in the
     instruction cache.  */
  if (target->flush_i_cache != NULL)
    target->flush_i_cache (gdbserv);

  /* Try the threaded version. If there was a signal, convert it to a
     gdbserv_reg and pass it down.  (Life would probably be easier if
     the threaded interface took a sigval instead of the ``struct
     gdbserv_reg''). */
  if (sigval == 0)
    sig = NULL;
  else
    {
      gdbserv_ulong_to_reg (gdbserv, sigval, &tmpsig);
      sig = &tmpsig;
    }
  switch (event) {
    case GDBSERV_TOTARGET_SINGLESTEP:
      if (target->singlestep_thread != NULL)
	{
	  target->singlestep_thread (gdbserv, thread, sig);
	  return GDBSERV_TARGET_RC_OK;
	}
      break;
    case GDBSERV_TOTARGET_CYCLESTEP:
      if (target->cyclestep_thread != NULL)
	{
	  target->cyclestep_thread (gdbserv, thread, sig);
	  return GDBSERV_TARGET_RC_OK;
	}
      break;
    case GDBSERV_TOTARGET_CONTINUE:
      if (target->continue_thread != NULL)
	{
	  target->continue_thread (gdbserv, thread, sig);
	  return GDBSERV_TARGET_RC_OK;
	}
      break;
    }

  /* Non-threaded RDAs get sent the signal as a separate
     operation. If we have a function to handle signals, call it. */
  if (sigval != 0)
    {
      if (target->process_signal != NULL)
	{
	  /* If 0 is returned, the signal was processed. */
	  if (target->process_signal (gdbserv, sigval) == 0)
	    sigval = 0;
	}
    }

  /* If we reach here and the signal still hasn't been processed then
     things are pretty serious.  Try killing the entire program.
     Target's really shouldn't need a sigkill_program() method.  No
     reason why process_signal() couldn't do it internally.  */
  if (sigval != 0)
    {
      if (target->sigkill_program != NULL)
	{
	  target->sigkill_program (gdbserv);
	  return GDBSERV_TARGET_RC_OK;
	}
    }

  /* If we've completly failed to deliver the signal, then die.
     Something is seriously wrong for this target. */
  assert (sigval == 0);

  /* Try resuming the entire program. */

  switch (event)
    {
    case GDBSERV_TOTARGET_SINGLESTEP:
      if (target->singlestep_program != NULL)
	{
	  target->singlestep_program (gdbserv);
	  return GDBSERV_TARGET_RC_OK;
	}
      break;
    case GDBSERV_TOTARGET_CYCLESTEP:
      if (target->singlestep_program != NULL)
	{
	  target->cyclestep_program (gdbserv);
	  return GDBSERV_TARGET_RC_OK;
	}
      break;
    case GDBSERV_TOTARGET_CONTINUE:
      if (target->continue_program != NULL)
	{
	  target->continue_program (gdbserv);
	  return GDBSERV_TARGET_RC_OK;
	}
      break;
    }

  /* Oops, nothing works. */
  return GDBSERV_TARGET_RC_UNKNOWN;
}

			 
