/* gdbserv-state.c

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "gdbserv.h"
#include "gdbserv-state.h"
#include "gdbserv-utils.h"
#include "gdblog.h"
#include "gdbserv-log.h"
#include "crc32.h"

static int output_thread_reg (struct gdbserv *gdbserv,
			      struct gdbserv_thread *thread,
			      int reg_nr,
			      int reg_nr_p);

static void fromtarget (struct gdbserv *gdbserv,
			struct gdbserv_thread *ignore1,
			enum gdbserv_fromtarget_event event,
			const struct gdbserv_reg *stop_addr,
			int exitcode);

static const char *
state2str (struct gdbserv *gdbserv)
{
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_UNINITIALIZED: return "UNINITIALIZED";
    case GDBSERV_STATE_RESETTING: return "RESETTING";
    case GDBSERV_STATE_RUNNING: return "RUNNING";
    case GDBSERV_STATE_BROKEN: return "BROKEN";
    case GDBSERV_STATE_EXITING: return "EXITING";
    case GDBSERV_STATE_EXITED: return "EXITED";
    }
  return "?";
}

enum gdbserv_state
gdbserv_state (struct gdbserv *gdbserv)
{
  return gdbserv->state;
}

void *
gdbserv_client_data (struct gdbserv *gdbserv)
{
  return gdbserv->client->data;
}

void *
gdbserv_target_data (struct gdbserv *gdbserv)
{
  return gdbserv->target->data;
}

void
log_state (struct gdbserv *gdbserv, const char *function)
{
  if (gdbserv_state_log)
    {
      gdblog_string (gdbserv_state_log, "<");
      gdblog_string (gdbserv_state_log, function);
      gdblog_string (gdbserv_state_log, " ");
      gdblog_string (gdbserv_state_log, state2str (gdbserv));
      gdblog_string (gdbserv_state_log, ">\n");
    }
}

static void
reset_state (struct gdbserv *gdbserv)
{
  gdbserv->state = GDBSERV_STATE_RESETTING;
  gdbserv->continue_thread = NULL;
  gdbserv->general_thread = NULL;
  gdbserv->event_thread = NULL;
  gdbserv->event_sigval = GDBSERV_SIGNONE;
}

struct gdbserv *
gdbserv_fromclient_attach (struct gdbserv_client *gdbclient,
			   gdbserv_target_attach *to_target_attach,
			   void *target_attach_data)
{
  struct gdbserv *gdbserv = malloc (sizeof (struct gdbserv));
  log_state (gdbserv, "gdbserv_fromclient_attach");
  gdbserv->client = gdbclient;
  /* HACK: Create a cycle of gdbservers. This allows the new stack
     based fromtarget code to climb the stack while, at the same time,
     keeping the old flat totarget code working.  Once the totarget
     code is converted to a stack this hack can be removed. */
  gdbserv->from = gdbserv;
  gdbserv->to = gdbserv;
  /* Wire up the servers input and output handlers. */
  gdbserv_input_attach (gdbserv);
  gdbserv_output_attach (gdbserv);
  /* Try to connect the client, if it fails bail out. */
  gdbserv->target = to_target_attach (gdbserv, target_attach_data);
  if (gdbserv->target == NULL)
    {
      gdbserv_output_detach (gdbserv);
      gdbserv_input_detach (gdbserv);
      free (gdbserv);
      return NULL;
    }
  /* Check that the target has supplied all the manditory methods.  It
     had better, at least be able to handle a detach. */
  assert (gdbserv->target->detach != NULL);
  /* HACK: Plug gdbserv-state's local fromtarget() method into the
     target vector returned by the attatch.  Since that target is at
     the bottom of the stack, the fromtarget method is NULL. Once
     there is a true stack, this hack can be eliminated necessary. */
  assert (gdbserv->target->from == NULL);
  gdbserv->target->from = fromtarget;
  reset_state (gdbserv);
  return gdbserv;
}

void
gdbserv_fromclient_detach (struct gdbserv *gdbserv)
{
  log_state (gdbserv, "gdbserv_fromclient_detach");
  gdbserv->target->from = NULL;
  gdbserv->target->detach (gdbserv, gdbserv->target);
  /* Avoid a dangling reference. */
  gdbserv->target = NULL;
  gdbserv_input_detach (gdbserv);
  gdbserv_output_detach (gdbserv);
  free (gdbserv);
}


void
gdbserv_fromclient_break (struct gdbserv *gdbserv)
{
  log_state (gdbserv, "gdbserv_fromclient_break");
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_RUNNING:
      gdbserv->target->break_program (gdbserv);
      /* NOTE: no state change - we might break the program at the
         same time as it stops itself */
      break;
    default:
      break;
    }
}


void
gdbserv_fromclient_data (struct gdbserv *gdbserv,
			 const char *buf,
			 int len)
{
  log_state (gdbserv, "gdbserv_fromclient_data");
  gdbserv_input_data_packet (gdbserv, buf, len);
}

static void
do_status_packet (struct gdbserv *gdbserv)
{
  gdbserv_output_char (gdbserv, 'T');
  gdbserv_output_byte (gdbserv, gdbserv->event_sigval);
  /* If the thread is known, pass that back to GDB. */
  if (gdbserv->event_thread != NULL
      && gdbserv->target->thread_id != NULL)
    {
      struct gdbserv_reg thread_id;
      gdbserv_output_string (gdbserv, "thread");
      gdbserv_output_char (gdbserv, ':');
      gdbserv->target->thread_id (gdbserv, gdbserv->event_thread, &thread_id);
      gdbserv_output_reg_beb (gdbserv, &thread_id, 0);
      gdbserv_output_string (gdbserv, ";");
    }
  /* When the target knows how, expedite the supply of register
     values back to GDB.  Do this by appending them to the end of
     the T packet response. */
  if (gdbserv->target->next_expedited_reg != NULL
      && gdbserv->target->get_thread_reg != NULL
      && gdbserv->target->output_reg != NULL)
    {
      int reg_nr;
      for (reg_nr = gdbserv->target->next_expedited_reg (gdbserv,
							 gdbserv->event_thread,
							 -1);
	   reg_nr >= 0;
	   reg_nr = gdbserv->target->next_expedited_reg (gdbserv,
							 gdbserv->event_thread,
							 reg_nr))
	{
	  if (output_thread_reg (gdbserv, gdbserv->event_thread, reg_nr, 1)
	      < 0)
	    continue;
	  gdbserv_output_string (gdbserv, ";");
	}
      return;
    }
  if (gdbserv->target->expedited_reg_nr != NULL
      && gdbserv->target->get_reg != NULL
      && gdbserv->target->sizeof_reg != NULL
      && gdbserv->target->output_reg != NULL)
    {
      int i;
      int reg_nr;
      for (i = 0, reg_nr = gdbserv->target->expedited_reg_nr (gdbserv, i);
	   reg_nr >= 0;
	   i++, reg_nr = gdbserv->target->expedited_reg_nr (gdbserv, i))
	{
	  struct gdbserv_reg reg;
	  long sizeof_reg = gdbserv->target->sizeof_reg (gdbserv, reg_nr);
	  long len = (sizeof_reg < 0 ? -sizeof_reg : sizeof_reg);
	  
	  gdbserv_output_byte (gdbserv, reg_nr);
	  gdbserv_output_char (gdbserv, ':');
	  if (sizeof_reg > 0)
	    gdbserv->target->get_reg (gdbserv, reg_nr, &reg);
	  else
	    memset (&reg, 0, sizeof (reg));
	  gdbserv->target->output_reg (gdbserv, &reg, len);
	  gdbserv_output_char (gdbserv, ';');
	}
      return;
    }
}

static void
do_exit_packet (struct gdbserv *gdbserv,
		enum gdbserv_fromtarget_event event,
		int sigval)
{
  switch (event)
    {
    case GDBSERV_FROMTARGET_TERMINATED:
      gdbserv_output_char (gdbserv, 'X');
      break;
    case GDBSERV_FROMTARGET_EXITED:
      gdbserv_output_char (gdbserv, 'W');
      break;
    }
  gdbserv_output_byte (gdbserv, sigval);
}

static void
do_select_thread_packet (struct gdbserv *gdbserv)
{
  if (gdbserv->target->thread_lookup_by_id != NULL)
    {
      struct gdbserv_reg thread_id;
      struct gdbserv_thread *thread;
      int id;
      int gen;

      gen = gdbserv_input_char (gdbserv);
      if (gen != 'g' && gen != 'c')
	{
	  gdbserv_output_string (gdbserv, "E01");
	  return;
	}
      if (gdbserv_input_reg_beb (gdbserv, &thread_id, 0) < 0)
	{
	  gdbserv_output_string (gdbserv, "E02");
	  return;
	}
      
      id = gdbserv->target->thread_lookup_by_id (gdbserv, &thread_id,
						 &thread);
      if (id > 0)
	  assert (thread != NULL);

      if (gen == 'c' && id <= 0)
	{
	  /* A thread ID of ``0'' or ``-1'' (well anything) indicates
	     that GDB wants all threads to continue.  Pass that
	     information on by selecting a NULL continuation thread.
	     NB: This won't scale to where GDB wants to select a
	     number of continuation threads.  A new protocol extension
	     will be needed.  */
	  gdbserv->continue_thread = NULL;
	}
      else if (gen == 'c')
	{
	  gdbserv->continue_thread = thread;
	}
      else if (gen == 'g')
	{
	  gdbserv->general_thread = thread;
	}
      else
	assert (0);
      gdbserv_output_string (gdbserv, "OK");
    }
}
  
static void
do_thread_alive_packet (struct gdbserv *gdbserv)
{
  /* thread-alive [ thread ] */
  if (gdbserv->target->thread_lookup_by_id != NULL)
    {
      struct gdbserv_reg thread_id;
      struct gdbserv_thread *thread;
      int id;
      if (gdbserv_input_reg_beb (gdbserv, &thread_id, 0) < 0)
	{
	  gdbserv_output_string (gdbserv, "E01");
	  return;
	}
      id = gdbserv->target->thread_lookup_by_id (gdbserv, &thread_id,
						 &thread);
      if (id > 0)
	gdbserv_output_string (gdbserv, "OK");
    }
}

static void
do_current_thread_query (struct gdbserv *gdbserv)
{
  struct gdbserv_thread *thread = gdbserv->general_thread;
  if (gdbserv->target->thread_id != NULL && thread != NULL)
    {
      struct gdbserv_reg thread_id;
      gdbserv->target->thread_id (gdbserv, thread, &thread_id);
      gdbserv_output_string (gdbserv, "QC");
      gdbserv_output_reg_beb (gdbserv, &thread_id, 0);
    }
}

static void
do_thread_info_query (struct gdbserv *gdbserv,
		      struct gdbserv_thread *last_thread)
{
  if (gdbserv->target->thread_id != NULL
      && gdbserv->target->thread_next != NULL)
    {
      struct gdbserv_thread *next_thread;
      struct gdbserv_reg thread_id;
      next_thread = gdbserv->target->thread_next (gdbserv, last_thread);
      if (next_thread == NULL)
	{
	  gdbserv_output_string (gdbserv, "l");
	  return;
	}
      gdbserv->query_thread = next_thread; /* for next time */
      gdbserv->target->thread_id (gdbserv, next_thread, &thread_id);
      gdbserv_output_string (gdbserv, "m");
      gdbserv_output_reg_beb (gdbserv, &thread_id, 0);
    }
}

static void
do_thread_extra_info_query (struct gdbserv *gdbserv)
{
  if (gdbserv->target->thread_lookup_by_id != NULL
      && gdbserv->target->thread_info != NULL)
    {
      struct gdbserv_reg thread_id;
      struct gdbserv_thread *thread;
      int id;
      char *info;
      
      if (gdbserv_input_reg_beb (gdbserv, &thread_id, 0) < 0)
	{
	  gdbserv_output_string (gdbserv, "E01");
	  return;
	}
      id = gdbserv->target->thread_lookup_by_id (gdbserv, &thread_id,
						 &thread);
      assert (thread != NULL);
      if (id <= 0)
	{
	  gdbserv_output_string (gdbserv, "E02");
	  return;
	}
      
      info = gdbserv->target->thread_info (gdbserv, thread);
      if (info == NULL)
	{
	  gdbserv_output_string (gdbserv, "E03");
	  return;
	}
      gdbserv_output_string_as_bytes (gdbserv, info);
      free (info);
    }
}


static int
output_thread_reg (struct gdbserv *gdbserv,
		   struct gdbserv_thread *thread,
		   int reg_nr,
		   int reg_nr_p)
{
  int size;
  int padding;
  struct gdbserv_reg reg;
  assert (gdbserv->target->reg_format != NULL);
  assert (gdbserv->target->get_thread_reg != NULL);
  assert (gdbserv->target->output_reg != NULL);
  if (gdbserv->target->reg_format (gdbserv, thread,
				   reg_nr, &size, &padding) < 0)
    return -1;
  if (gdbserv->target->get_thread_reg (gdbserv, thread,
				       reg_nr, &reg) >= 0)
    {
      if (reg_nr_p)
	{
	  gdbserv_output_byte (gdbserv, reg_nr);
	  gdbserv_output_char (gdbserv, ':');
	}
      for (; padding < 0; padding++)
	gdbserv_output_string (gdbserv, "00");
      if (size > 0)
	gdbserv->target->output_reg (gdbserv,
				     &reg, size);
      for (; padding > 0; padding--)
	gdbserv_output_string (gdbserv, "00");
    }
  else
    {
      if (reg_nr_p)
	{
	  gdbserv_output_byte (gdbserv, reg_nr);
	  gdbserv_output_char (gdbserv, ':');
	}
      for (; padding < 0; padding++)
	gdbserv_output_string (gdbserv, "xx");
      for (; size > 0; size--)
	gdbserv_output_string (gdbserv, "xx");
      for (; padding > 0; padding--)
	gdbserv_output_string (gdbserv, "xx");
    }
  return 0;
}

static void
do_get_registers_g_packet (struct gdbserv *gdbserv)
{
  if (gdbserv->target->next_gg_reg != NULL
      && gdbserv->target->get_thread_reg != NULL
      && gdbserv->target->reg_format != NULL
      && gdbserv->target->output_reg != NULL)
    {
      int reg_nr;
      for (reg_nr = gdbserv->target->next_gg_reg (gdbserv,
						  gdbserv->general_thread,
						  -1);
	   reg_nr >= 0;
	   reg_nr = gdbserv->target->next_gg_reg (gdbserv,
						  gdbserv->general_thread,
						  reg_nr))
	{
	  if (output_thread_reg (gdbserv, gdbserv->general_thread,
				 reg_nr, 0) < 0)
	    {
	      gdbserv_output_discard (gdbserv);
	      gdbserv_output_string (gdbserv, "E99");
	      return;
	    }
	}
    }
}

static void
do_set_registers_g_packet (struct gdbserv *gdbserv)
{
  if (gdbserv->target->next_gg_reg != NULL
      && gdbserv->target->set_thread_reg != NULL
      && gdbserv->target->reg_format != NULL
      && gdbserv->target->input_reg != NULL)
    {
      int reg_nr;
      for (reg_nr = gdbserv->target->next_gg_reg (gdbserv,
						  gdbserv->general_thread,
						  -1);
	   reg_nr >= 0;
	   reg_nr = gdbserv->target->next_gg_reg (gdbserv,
						  gdbserv->general_thread,
						  reg_nr))
	{
	  int size;
	  int padding;
	  gdbserv->target->reg_format (gdbserv, gdbserv->general_thread,
				       reg_nr, &size, &padding);
	  for (; padding < 0; padding++)
	    gdbserv_input_byte (gdbserv);
	  if (size > 0)
	    {
	      struct gdbserv_reg reg;
	      if (gdbserv->target->input_reg (gdbserv,
					      &reg, size) >= 0)
		/* only supply registers that are useful. */
		gdbserv->target->set_thread_reg (gdbserv,
						 gdbserv->general_thread,
						 reg_nr, &reg);
	    }
	  for (; padding > 0; padding--)
	    gdbserv_input_byte (gdbserv);
	}
      gdbserv_output_string (gdbserv, "OK");
    }
}

static void
do_set_registers_p_packet (struct gdbserv *gdbserv)
{
  /* FIXME: This accepts a list of registers which isn't in the
     protocol. */
  if (gdbserv->target->set_thread_reg != NULL
      && gdbserv->target->input_reg != NULL)
    {
      const char *result = "OK";
      while (gdbserv_input_size (gdbserv) > 0)
	{
	  unsigned long regnr;
	  struct gdbserv_reg reg;
	  if (gdbserv_input_hex_ulong (gdbserv, &regnr) < 0)
	    {
	      result = "E01";
	      break;
	    }
	  if (gdbserv_input_string_match (gdbserv, "=") >= 0)
	    {
	      if (gdbserv->target->input_reg (gdbserv, &reg, 0) < 0)
		{
		  result = "E02";
		  break;
		}
	    }
	  else
	    {
	      result = "E04";
	      break;
	    }
	  if (gdbserv->target->set_thread_reg (gdbserv,
					       gdbserv->general_thread,
					       regnr, &reg) < 0)
	    {
	      result = "E05";
	      break;
	    }
	  if (gdbserv_input_string_match (gdbserv, ";") < 0)
	    {
	      if (gdbserv_input_size (gdbserv) > 0)
		result = "E06";
	      break;
	    }
	}
      if (result == NULL)
	gdbserv_output_string (gdbserv, "OK");
      else
	{
	  gdbserv_output_discard (gdbserv);
	  gdbserv_output_string (gdbserv, result);
	}
    }
}

static void
do_get_registers_p_packet (struct gdbserv *gdbserv)
{
  /* FIXME: This returns a list of registers which isn't in the
     protocol. */
  /* FIXME: This would really like to return ;REGNR!VALUE ... */

  if (gdbserv->target->get_thread_reg != NULL
      && gdbserv->target->reg_format  != NULL
      && gdbserv->target->output_reg  != NULL)
    {
      const char *result = NULL;
      while (gdbserv_input_size (gdbserv) > 0)
	{
	  unsigned long regnr;
	  struct gdbserv_reg reg;
	  if (gdbserv_input_hex_ulong (gdbserv, &regnr) < 0)
	    {
	      result = "E01";
	      break;
	    }
	  if (output_thread_reg (gdbserv, gdbserv->general_thread,
				 regnr, 0) < 0)
	    {
	      result = "E02";
	      break;
	    }
	  if (gdbserv_input_string_match (gdbserv, ";") < 0)
	    {
	      if (gdbserv_input_size (gdbserv) > 0)
		result = "E03";
	      break;
	    }
          gdbserv_output_string (gdbserv, ";");
	}
      if (result != NULL)
	{
	  gdbserv_output_discard (gdbserv);
	  gdbserv_output_string (gdbserv, result);
	}
    }
}

static long
read_memory (struct gdbserv *gdbserv, struct gdbserv_reg *addr_p, void *block,
             long len)
{
  long nr_read;
  if (gdbserv->target->get_thread_mem != NULL)
    nr_read = 
      gdbserv->target->get_thread_mem (gdbserv, 
				       gdbserv->general_thread,
				       addr_p, block, len);
  else if (gdbserv->target->get_mem != NULL)
    nr_read = gdbserv->target->get_mem (gdbserv, addr_p, block, len);
  else
    assert (0);
  return nr_read;
}

static void
do_qCRC_packet (struct gdbserv *gdbserv)
{
  struct gdbserv_reg addr;
  long len;
  unsigned long crc = 0xffffffff;	/* See crc32.h.  */
  struct gdbserv_reg crc_reg;

  /* Fetch addr,length.  */
  if (gdbserv_input_reg_beb (gdbserv, &addr, 0) < 0)
    {
      gdbserv_output_string (gdbserv, "E01");
    }
  else if (gdbserv_input_char (gdbserv) != ',')
    {
      gdbserv_output_string (gdbserv, "E02");
    }
  else if (gdbserv_input_hex_ulong (gdbserv, &len) < 0)
    {
      gdbserv_output_string (gdbserv, "E03");
    }

  while (len > 0)
    {
      char buf[1024];
      unsigned long long addr_ull;
      int size = sizeof (buf) < len ? sizeof (buf) : len;

      /* Read a block.  Quit early if the read doesn't succeed.  */
      size = read_memory (gdbserv, &addr, buf, size);
      if (size <= 0)
	{
	  gdbserv_output_string (gdbserv, "E07");
	  return;
	}

      /* Compute the accumlated CRC.  */
      crc = crc32 (buf, size, crc);

      /* Advance ``addr'' by ``size''.  */
      gdbserv_reg_to_ulonglong (gdbserv, &addr, &addr_ull);
      addr_ull += size;
      gdbserv_ulonglong_to_reg (gdbserv, addr_ull, &addr);

      /* Adjust the length based on amount actually read.  */
      len -= size;
    }

  /* Output the CRC in the format expected by GDB.  */
  gdbserv_output_char (gdbserv, 'C');
  gdbserv_ulong_to_reg (gdbserv, crc, &crc_reg);
  gdbserv_output_reg_beb (gdbserv, &crc_reg, 0);
}

int demo_reverse_flag;

void
gdbserv_data_packet (struct gdbserv *gdbserv)
{
  char packet_type = gdbserv_input_char (gdbserv);

  demo_reverse_flag = 0;

  if (gdbserv_state_log)
    {
      gdblog_string (gdbserv_state_log, "<gdbserv_data_packet:");
      gdblog_char (gdbserv_state_log, packet_type);
      gdblog_string (gdbserv_state_log, ">\n");
    }
  
  /* NB: default is for this to send an empty packet */

 backward:
  switch (packet_type)
    {

    case '?':
      do_status_packet (gdbserv);
      break;

    case 'H': /* select general/continue thread */
      do_select_thread_packet (gdbserv);
      break;

    case 'd': /* toggle debug flag */
      gdbserv_output_string (gdbserv, "");
      break;

    case 'D': /* detach from target */
      gdbserv_output_string (gdbserv, "");
      /* NOP. We detach when an EOF is sensed on the socket. */
      break;

    case 'q': /* general query packet */
      if (gdbserv_input_string_match (gdbserv, "Rcmd,") >= 0)
	{
	  if (gdbserv->target->process_rcmd)
	    {
	      /* Format: qRcmd,<hex-encoded-command> */
	      char *cmd;
	      int sizeof_cmd;
	      /* create a buffer sufficent to hold the decoded
		 command. There are two hex digits per encoded byte. */
	      sizeof_cmd = gdbserv_input_size (gdbserv) / 2;
	      if (sizeof_cmd < 0)
		{
		  gdbserv_output_string (gdbserv, "E11");
		  break;
		}
	      cmd = alloca (sizeof_cmd + 1);
	      /* Decode/read the command into the buffer, check that
		 the command exactly fits - not to many, not to few
		 bytes of input. */
	      if (gdbserv_input_bytes (gdbserv, cmd, sizeof_cmd) < sizeof_cmd
		  || gdbserv_input_size (gdbserv) != 0)
		{
		  gdbserv_output_string (gdbserv, "E12");
		  break;
		}
	      /* Process the command.  Guarentee that that it is NUL
		 terminated. */
	      cmd[sizeof_cmd] = '\0';
	      gdbserv->target->process_rcmd (gdbserv, cmd, sizeof_cmd);
	    }
	}
      else if (gdbserv_input_string_match (gdbserv, "CRC:") >= 0)
	{
	  do_qCRC_packet (gdbserv);
	}
      else if (gdbserv_input_string_match (gdbserv, "C") >= 0)
	{
	  do_current_thread_query (gdbserv);
	}
      else if (gdbserv_input_string_match (gdbserv, "fThreadInfo") >= 0)
	{
	  do_thread_info_query (gdbserv, NULL);
	}
      else if (gdbserv_input_string_match (gdbserv, "sThreadInfo") >= 0)
	{
	  do_thread_info_query (gdbserv, gdbserv->query_thread);
	}
      else if (gdbserv_input_string_match (gdbserv, "ThreadExtraInfo,") >= 0)
	{
	  do_thread_extra_info_query (gdbserv);
	}
      else if (gdbserv->target->process_get_gen)
	{
	  gdbserv->target->process_get_gen (gdbserv);
	}
      else
	{
	  if (gdbserv_state_log != NULL)
	    gdblog_string (gdbserv_state_log, "<general_query>\n");
	}
      break;

    case 'Q': /* general set packet */
      if (gdbserv->target->process_set_gen)
	gdbserv->target->process_set_gen (gdbserv);
      else
	{
	  if (gdbserv_state_log)
	    gdblog_string (gdbserv_state_log, "<general_set>\n");
	}
      break;

    case 'g': /* return the value of the CPU registers. */
      /* Give first preference to the thread-aware method. */
      if (gdbserv->target->get_thread_reg != NULL 
	  && gdbserv->target->next_gg_reg != NULL
	  && gdbserv->target->reg_format  != NULL
	  && gdbserv->target->output_reg  != NULL)
	{
	  do_get_registers_g_packet (gdbserv);
	}
      /* Give second preference to the get_reg method. */
      else if (gdbserv->target->get_reg       != NULL
	       && gdbserv->target->gg_reg_nr  != NULL
	       && gdbserv->target->sizeof_reg != NULL
	       && gdbserv->target->output_reg != NULL)
	{
	  int i;
	  int reg_nr;
	  for (i = 0, reg_nr = gdbserv->target->gg_reg_nr (gdbserv, i);
	       reg_nr >= 0;
	       i++, reg_nr = gdbserv->target->gg_reg_nr (gdbserv, i))
	    {
	      struct gdbserv_reg reg;
	      long sizeof_reg = gdbserv->target->sizeof_reg (gdbserv, reg_nr);
	      long len = (sizeof_reg < 0 ? -sizeof_reg : sizeof_reg);
	      if (sizeof_reg > 0)
		{
		  int status;
		  status = gdbserv->target->get_reg (gdbserv, reg_nr, &reg);
		  if (status < 0)
		    memset (&reg, 0, sizeof (reg));
		}
	      else
		memset (&reg, 0, sizeof (reg));
	      gdbserv->target->output_reg (gdbserv, &reg, len);
	    }
	}
      else if (gdbserv->target->process_get_regs != NULL)
	{
	  gdbserv->target->process_get_regs (gdbserv);
	}
      /* else error? */
      break;

    case 'G': /* set the value of the CPU registers - return OK */
      /* Give first preference to the thread-aware method. */
      if (gdbserv->target->set_thread_reg != NULL
	  && gdbserv->target->next_gg_reg != NULL
	  && gdbserv->target->reg_format  != NULL
	  && gdbserv->target->input_reg   != NULL)
	{
	  do_set_registers_g_packet (gdbserv);
	}
      /* Give second preference to the set_reg method. */
      else if (gdbserv->target->gg_reg_nr     != NULL
	       && gdbserv->target->set_reg    != NULL
	       && gdbserv->target->sizeof_reg != NULL
	       && gdbserv->target->input_reg  != NULL)
	{
	  int i;
	  int reg_nr;
	  for (i = 0, reg_nr = gdbserv->target->gg_reg_nr (gdbserv, i);
	       reg_nr >= 0;
	       i++, reg_nr = gdbserv->target->gg_reg_nr (gdbserv, i))
	    {
	      struct gdbserv_reg reg;
	      long sizeof_reg = gdbserv->target->sizeof_reg (gdbserv, reg_nr);
	      long len = (sizeof_reg < 0 ? -sizeof_reg : sizeof_reg);
	      gdbserv->target->input_reg (gdbserv, &reg, len);
	      if (sizeof_reg > 0)
		/* only supply registers that are useful. */
		gdbserv->target->set_reg (gdbserv, reg_nr, &reg);
	    }
	  gdbserv_output_string (gdbserv, "OK");
	}
      else if (gdbserv->target->process_set_regs != NULL)
	{
	  gdbserv->target->process_set_regs (gdbserv);
	}
      /* else error? */
      break;

    case 'A': /* UNOFFICIAL: set program arguments */
      gdbserv->target->process_set_args (gdbserv);
      break;
    
    case 'p': /* UNOFFICIAL: read single reg */
      /* Give first preference to the thread-aware method. */
      if (gdbserv->target->get_thread_reg != NULL
	  && gdbserv->target->output_reg  != NULL
	  && gdbserv->target->reg_format  != NULL)
	{
	  do_get_registers_p_packet (gdbserv);
	}
      /* FIXME: Give second preference to the get_reg method? */
      else if (gdbserv->target->process_get_reg != NULL)
	{
	  unsigned long regnr;
	  if (gdbserv_input_hex_ulong (gdbserv, &regnr) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E01");
	    }
	  else if (gdbserv->target->process_get_reg (gdbserv, regnr) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E03");
	    }
	}
      /* else error? */
      break;

    case 'P': /* write single reg */
      /* Give first preference to the thread-aware method. */
      if (gdbserv->target->set_thread_reg != NULL
	  && gdbserv->target->input_reg   != NULL)
	{
	  do_set_registers_p_packet (gdbserv);
	}
      /* Give second preference to the set_reg method. */
      else if (gdbserv->target->set_reg != NULL
	  && gdbserv->target->input_reg != NULL)
	{
	  unsigned long regnr;
	  struct gdbserv_reg reg;
	  if (gdbserv_input_hex_ulong (gdbserv, &regnr) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E01");
	    }
	  else if (gdbserv_input_char (gdbserv) != '=')
	    {
	      gdbserv_output_string (gdbserv, "E02");
	    }
	  else if (gdbserv->target->input_reg (gdbserv, &reg, 0) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E03");
	    }
	  else
	    {
	      gdbserv->target->set_reg (gdbserv, regnr, &reg);
	      gdbserv_output_string (gdbserv, "OK");
	    }
	}
      else if (gdbserv->target->process_set_reg != NULL)
	{
	  unsigned long regnr;
	  if (gdbserv_input_hex_ulong (gdbserv, &regnr) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E01");
	    }
	  else if (gdbserv_input_char (gdbserv) != '=')
	    {
	      gdbserv_output_string (gdbserv, "E02");
	    }
	  else if (gdbserv->target->process_set_reg (gdbserv, regnr) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E03");
	    }
	  else
	    {
	      gdbserv_output_string (gdbserv, "OK");
	    }
	}
      /* else error? */
      break;

    case 'm': /* mAA..AA,LLLL  Read LLLL bytes at address AA..AA */
    case 'M': /* MAA..AA,LLLL: Write LLLL bytes at address AA.AA return OK */
    case 'X': /* XAA..AA,LLLL: Write LLLL binary bytes at AA.AA return OK */
      if ((packet_type == 'm'
	   && (gdbserv->target->get_mem != NULL
	       || gdbserv->target->get_thread_mem != NULL))
	  || ((packet_type == 'M' || packet_type == 'X')
	      && (gdbserv->target->set_mem != NULL
		  || gdbserv->target->set_thread_mem != NULL)))
	{
	  struct gdbserv_reg addr;
	  long len;
	  if (gdbserv_input_reg_beb (gdbserv, &addr, 0) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E01");
	    }
	  else if (gdbserv_input_char (gdbserv) != ',')
	    {
	      gdbserv_output_string (gdbserv, "E02");
	    }
	  else if (gdbserv_input_hex_ulong (gdbserv, &len) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E03");
	    }
	  else if (packet_type == 'm')
	    {
	      void *data = alloca (len);
	      long nr_read;
	      if (gdbserv->target->get_thread_mem != NULL)
		nr_read = 
		  gdbserv->target->get_thread_mem (gdbserv, 
						   gdbserv->general_thread,
						   &addr, data, len);
	      else if (gdbserv->target->get_mem != NULL)
		nr_read = gdbserv->target->get_mem (gdbserv, &addr, data, len);
	      else
		assert (0);
	      if (nr_read < 0)
		gdbserv_output_string (gdbserv, "E07");
	      else
		gdbserv_output_bytes (gdbserv, data, nr_read);
	    }
	  else if (gdbserv_input_char (gdbserv) == ':')
	    {
	      void *data = alloca (len);
	      int nr_written;
	      if (packet_type == 'X')
		{
		  if (gdbserv_input_escaped_binary (gdbserv, data, len) != len)
		    {
		      gdbserv_output_string (gdbserv, "E08");
		      break;
		    }
		}
	      else
		{
		  if (gdbserv_input_bytes (gdbserv, data, len) != len)
		    {
		      gdbserv_output_string (gdbserv, "E09");
		      break;
		    }
		}
	      if (gdbserv->target->set_thread_mem != NULL)
		nr_written = 
		  gdbserv->target->set_thread_mem (gdbserv, 
						   gdbserv->general_thread,
						   &addr, data, len);
	      else if (gdbserv->target->set_mem != NULL)
		nr_written = gdbserv->target->set_mem (gdbserv, 
						       &addr, data, len);
	      else
		assert (0);
	      if (nr_written < 0)
		gdbserv_output_string (gdbserv, "E10");
	      else if (nr_written != len)
		gdbserv_output_string (gdbserv, "E10");
	      else
		gdbserv_output_string (gdbserv, "OK");
	    }
	  else
	    {
	      gdbserv_output_string (gdbserv, "E04");
	    }
	}
      break;

    case 'b':
      /* The 'b' prefix before 's' or 'c' means "backward".
	 This is for reverse debugging.  

	 Fetch the next char, and if it is 's' or 'c', then
	 just set reverse_flag and go back to the switch statement
	 (from there to return to step or continue as appropriate).
	 
	 Else, error.  */

      packet_type = gdbserv_input_char (gdbserv);
      switch (packet_type) {
      case 'S': case 's':
      case 'C': case 'c': 
	demo_reverse_flag = 1;
	goto backward;
	break;

      default:
	if (gdbserv_state_log)
	  gdblog_string (gdbserv_state_log, "<target_packet>\n");
	gdbserv_output_string (gdbserv, "");
	break;
      }
      break;

    case 's': case 'c': case 'i':
      /* [isc]AA..AA
	 Resume program execution (at optional address ``AA..AA''). */
    case 'S': case 'C': /* case 'I': */
      /* [ISC]ss;AA..AA
	 Deliver signal ``ss'' (after setting program up to resume
	 execution at optional address ``AA..AA''). */
      {
	int sigval;
	enum gdbserv_totarget_event event;
	struct gdbserv_reg tmppc;
	struct gdbserv_reg *pc;

	switch (packet_type)
	  {
	  case 'c': case 'C': event = GDBSERV_TOTARGET_CONTINUE; break;
	  case 'i': case 'I': event = GDBSERV_TOTARGET_CYCLESTEP; break;
	  case 's': case 'S': event = GDBSERV_TOTARGET_SINGLESTEP; break;
	  default: assert (0);
	  }

	/* Get the signal.  The signal is a small GDB defined integer.
           It is not a target dependant value. */
	switch (packet_type)
	  {
	  case 'C': case 'S': case 'I':
	    sigval = gdbserv_input_byte (gdbserv);
	    if (sigval < 0)
	      {
		gdbserv_output_string (gdbserv, "E01");
		break;
	      }
	    if (gdbserv_input_peek (gdbserv) == ';')
	      gdbserv_input_char (gdbserv);
	    break;
	  case 'c': case 's': case 'i':
	    sigval = 0;
	    break;
	  }

	/* NOTE: While GDB never passes an address down as part of a
           continue packet, target stack entries might.  For instance,
           a ``load 'n' go'' target might need to set the continue
           address as part of starting a target. */

	if (gdbserv_input_reg_beb (gdbserv, &tmppc, 0) >= 0)
	  pc = &tmppc;
	else
	  pc = NULL;

	switch (gdbserv_totarget (gdbserv, gdbserv->continue_thread,
				  event, pc, sigval))
	  {
	  case GDBSERV_TARGET_RC_OK:
	    gdbserv->state = GDBSERV_STATE_RUNNING;
	    return;
	  default:
	    gdbserv_output_string (gdbserv, "E99");
	    break;
	  }
      }
    
    /* kill the program */
    case 'k' :
      {
	gdbserv->target->exit_program (gdbserv);
	gdbserv->state = GDBSERV_STATE_EXITING;
	return;
      }
     
    case 'Z':
    case 'z':
      /* breakpoint [Zz]<type>,<address>,<length> */
      if (gdbserv->target->remove_breakpoint != NULL
	  && gdbserv->target->set_breakpoint != NULL)
	{
	  enum gdbserv_target_bp bp;
	  enum gdbserv_target_rc rc;
	  unsigned long type;
	  struct gdbserv_reg addr;
	  struct gdbserv_reg len;
	  if (gdbserv_input_hex_ulong (gdbserv, &type) < 0
	      || gdbserv_input_char (gdbserv) != ','
	      || gdbserv_input_reg_beb (gdbserv, &addr, 0) < 0
	      || gdbserv_input_char (gdbserv) != ','
	      || gdbserv_input_reg_beb (gdbserv, &len, 0) < 0)
	    {
	      /* Signal parse error */
	      gdbserv_output_string (gdbserv, "E01");
	      break;
	    }
	  switch (type)
	    {
	    case 0: bp = GDBSERV_TARGET_BP_SOFTWARE; break;
	    case 1: bp = GDBSERV_TARGET_BP_HARDWARE; break;
	    case 2: bp = GDBSERV_TARGET_BP_WRITE; break;
	    case 3: bp = GDBSERV_TARGET_BP_READ; break;
	    case 4: bp = GDBSERV_TARGET_BP_ACCESS; break;
	    default: bp = GDBSERV_TARGET_BP_UNKNOWN; break;
	    }
	  if (bp == GDBSERV_TARGET_BP_UNKNOWN)
	    {
	      /* only recognize software breakpoints */
	      gdbserv_output_string (gdbserv, "E02");
	      break;
	    }
	  if (packet_type == 'z')
	    rc = gdbserv->target->remove_breakpoint (gdbserv, bp, &addr, &len);
	  else
	    rc = gdbserv->target->set_breakpoint (gdbserv, bp, &addr, &len);
	  switch (rc)
	    {
	    case GDBSERV_TARGET_RC_OK:
	      gdbserv_output_string (gdbserv, "OK");
	      break;
	    case GDBSERV_TARGET_RC_ERROR:
	      gdbserv_output_string (gdbserv, "E03");
	      break;
	    case GDBSERV_TARGET_RC_UNKNOWN:
	      /* Behave as if operation isn't supported. */
	      break;
	    }
	}
      break;


    case 'r':		/* Reset */
      if (gdbserv->target->reset_program)
	{
	  gdbserv->target->reset_program (gdbserv);
	  reset_state (gdbserv);
	}
      break;


    case 'R': /* Rnn restart server */
      if (gdbserv->target->restart_program)
	{
	  gdbserv->target->restart_program (gdbserv);
	  reset_state (gdbserv);
	  return;
	}
      break;


    case 'T':
      do_thread_alive_packet (gdbserv);
      break;

    default:
      if (gdbserv->target->process_target_packet)
	gdbserv->target->process_target_packet (gdbserv);
      else
	{
	  if (gdbserv_state_log)
	    gdblog_string (gdbserv_state_log, "<target_packet>\n");
	  gdbserv_output_string (gdbserv, "");
	}
      break;

    }
  gdbserv_output_packet (gdbserv);
}

static void
fromtarget (struct gdbserv *gdbserv,
	    struct gdbserv_thread *thread,
	    enum gdbserv_fromtarget_event event,
	    const struct gdbserv_reg *stop_addr,
	    int sigval)
{
  enum gdbserv_state nextstate;
  log_state (gdbserv, "fromtarget");

  /* A multi-threaded target may not necessarily have a thread to bind
     the event to.  This happens when the event, such as ``cntrl-c''
     isn't directed at a specific thread.  Since GDB assumes that
     every event is bound to a specific thread the below fudges things
     by selecting an earlier thread.  If at the end, there is still no
     thread then that is OK as the target wasn't multi-threaded to
     start with.  If GDB is ever modified so that it doesn't assume
     that all events belong to threads then this heuristic can be
     eliminated. */
  if (thread == NULL)
    thread = gdbserv->continue_thread;
  if (thread == NULL)
    thread = gdbserv->event_thread;
  if (thread == NULL)
    thread = gdbserv->general_thread;
  gdbserv->event_thread = thread;
  gdbserv->event_sigval = sigval;

  /* GDB assumes that, unless the target is told otherwize, a "g"
     query will return the regiters for the event that triggered the
     event. */
  gdbserv->general_thread = gdbserv->event_thread;

  /* GDB assumes that, unless told otherwize, the target will resume
     the entire system.  A NULL "continue" thread implies this. */
  gdbserv->continue_thread = NULL;

  switch (event)
    {
    case GDBSERV_FROMTARGET_STOPPED:
      switch (gdbserv->state)
	{
	case GDBSERV_STATE_RESETTING:
	  nextstate = GDBSERV_STATE_BROKEN;
	  /* After a reset / power-on GDB expects the remote target to
	     silently stop at the first instruction ready for further
	     commands.  Hence NO NOTIFY. */
	  break;
	case GDBSERV_STATE_RUNNING:
	  nextstate = GDBSERV_STATE_BROKEN;
	  do_status_packet (gdbserv);
	  gdbserv_output_packet (gdbserv);
	  break;
	default:
	  nextstate = gdbserv->state;
	  gdblog_string (gdbserv_warning_log, "STOPPED -> unknown event\n");
	  break;
	}
      break;
    case GDBSERV_FROMTARGET_EXITED:
    case GDBSERV_FROMTARGET_TERMINATED:
      switch (gdbserv->state)
	{
	case GDBSERV_STATE_RUNNING:
	  nextstate = GDBSERV_STATE_EXITED;
	  do_exit_packet (gdbserv, event, sigval);
	  gdbserv_output_packet (gdbserv);
	  break;
	default:
	  nextstate = gdbserv->state;
	  gdblog_string (gdbserv_warning_log, "EXITED/TERMINATED -> unknown event\n");
	  break;
	}
      break;
    default:
      nextstate = gdbserv->state;
      gdblog_string (gdbserv_warning_log, "UNKNOWN STATE -> unknown event\n");
      break;
    }
  gdbserv->state = nextstate;
}
