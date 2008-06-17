/*
 * gdbserv-state.c -- part of GDB remote server
 *
 * Copyright (C) 2000, 2002, 2006 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


#include <stdio.h>
#include <stdlib.h>

#include "gdbserv.h"
#include "gdbserv-state.h"
#include "gdbserv-utils.h"

FILE *gdbserv_state_trace = NULL;

static const char *
state2str (struct gdbserv *gdbserv)
{
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_UNINITIALIZED: return "UNINITIALIZED";
    case GDBSERV_STATE_RESETTING: return "RESETTING";
    case GDBSERV_STATE_STUMBLING: return "STUMBLING";
    case GDBSERV_STATE_STEPPING: return "STEPPING";
    case GDBSERV_STATE_RUNNING: return "RUNNING";
    case GDBSERV_STATE_BROKEN: return "BROKEN";
    case GDBSERV_STATE_EXITING: return "EXITING";
    case GDBSERV_STATE_EXITED: return "EXITED";
    }
  return "?";
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

struct gdbserv *
gdbserv_fromclient_attach (struct gdbserv_client *gdbclient,
			   gdbserv_target_attach *to_target_attach,
			   void *target_attach_data)
{
  struct gdbserv *gdbserv = malloc (sizeof (struct gdbserv));
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromclient_attach %s>\n",
	     state2str (gdbserv));
  gdbserv->client = gdbclient;
  gdbserv_input_attach (gdbserv);
  gdbserv_output_attach (gdbserv);
  gdbserv->target = to_target_attach (gdbserv, target_attach_data);
  if (gdbserv->target == NULL)
    {
      gdbserv_output_detach (gdbserv);
      gdbserv_input_detach (gdbserv);
      free (gdbserv);
      return NULL;
    }
  else
    {
      gdbserv->state = GDBSERV_STATE_RESETTING;
      return gdbserv;
    }
}

void
gdbserv_fromclient_detach (struct gdbserv *gdbserv)
{
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromclient_detach %s>\n",
	     state2str (gdbserv));
  gdbserv->target->detach (gdbserv);
  gdbserv_input_detach (gdbserv);
  gdbserv_output_detach (gdbserv);
  free (gdbserv);
}


void
gdbserv_fromclient_break (struct gdbserv *gdbserv)
{
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromclient_break %s>\n",
	     state2str (gdbserv));
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_RUNNING:
    case GDBSERV_STATE_STEPPING:
    case GDBSERV_STATE_STUMBLING:
      gdbserv->target->break_program (gdbserv);
      /* NOTE: no state change - we might break the program at the
         same time as it stops itself */
      break;
    default:
      ;
    }
}


void
gdbserv_fromclient_data (struct gdbserv *gdbserv,
			 const char *buf,
			 int len)
{
#if 0
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromclient_data %s>\n",
	     state2str (gdbserv));
#endif
  gdbserv_input_data_packet (gdbserv, buf, len);
}


void
gdbserv_data_packet (struct gdbserv *gdbserv)
{
  const char *exec_direction = "forward";
  char packet_type = gdbserv_input_char (gdbserv);
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_data_packet:%c>\n", packet_type);
  
  /* NB: default is for this to send an empty packet */

  /* Check for a 'b' (backward) prefix for S, s, C and c.  This indicates that
     the direction of execution is to be backward.  */
  if (packet_type == 'b')
    {
      char next = gdbserv_input_peek (gdbserv);
      switch (next)
	{
	case 'S': case 's': case 'C': case 'c':
	  exec_direction = "backward";
	  packet_type = gdbserv_input_char (gdbserv);
	  break;
	default:
	  break;
	}
    }

  switch (packet_type)
    {

    case '?':
      {
	unsigned long sigval = gdbserv->target->compute_signal (gdbserv, gdbserv->target->get_trap_number (gdbserv));
	gdbserv_output_char (gdbserv, 'S');
	gdbserv_output_byte (gdbserv, sigval);
	break;
      }

    case 'd': /* toggle debug flag */
      gdbserv_output_string (gdbserv, "");
      break;

    case 'q': /* general query packet */
      if (gdbserv_input_string_match (gdbserv, "Rcmd,") >= 0
	  && gdbserv->target->process_rcmd)
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
	  /* Decode/read the command into the buffer, check that the
             command exactly fits - not to many, not to few bytes of
             input. */
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
      else if (gdbserv->target->process_get_gen)
	{
	  gdbserv->target->process_get_gen (gdbserv);
	}
      else
	{
	  if (gdbserv_state_trace)
	    fprintf (gdbserv_state_trace, "<general_query>\n");
	}
      break;

    case 'Q': /* general set packet */
      if (gdbserv->target->process_set_gen)
	gdbserv->target->process_set_gen (gdbserv);
      else
	{
	  if (gdbserv_state_trace)
	    fprintf (gdbserv_state_trace, "<general_set>\n");
	}
      break;

    case 'g': /* return the value of the CPU registers. */
      if (gdbserv->target->gg_reg_nr != NULL
	  && gdbserv->target->get_reg != NULL
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
		gdbserv->target->get_reg (gdbserv, reg_nr, &reg);
	      else
		memset (&reg, sizeof (reg), 0);
	      gdbserv->target->output_reg (gdbserv, &reg, len);
	    }
	}
      else if (gdbserv->target->process_get_regs != NULL)
	{
	  gdbserv->target->process_get_regs (gdbserv);
	}
      break;

    case 'G': /* set the value of the CPU registers - return OK */
      if (gdbserv->target->gg_reg_nr != NULL
	  && gdbserv->target->set_reg != NULL
	  && gdbserv->target->sizeof_reg != NULL
	  && gdbserv->target->input_reg != NULL)
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
      break;

    case 'A': /* UNOFFICIAL: set program arguments */
      gdbserv->target->process_set_args (gdbserv);
      break;
    
#if 0
    case 'p': /* UNOFFICIAL/BROKEN: read single reg */
      {
	char *ptr = &packet[1];
	unsigned long regnr;
	struct gdbserv_reg reg;
	if (__gdbserv_hex_to_ulong (&ptr, &regnr)
	    && *ptr++ == '\0'
	    && gdbserv->target->process_get_reg (gdbserv, regnr, &reg))
	  {
	    /* FIXME: Return single register */
	    gdbserv_output_string (gdbserv, "P01");
	  }
	else
	  {
	    gdbserv_output_string (gdbserv, "P01");
	  }
	break;
      }
#endif

    case 'P': /* write single reg */
      if (gdbserv->target->set_reg != NULL
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
      break;

    case 'm': /* mAA..AA,LLLL  Read LLLL bytes at address AA..AA */
    case 'M': /* MAA..AA,LLLL: Write LLLL bytes at address AA.AA return OK */
    case 'X': /* XAA..AA,LLLL: Write LLLL binary bytes at AA.AA return OK */
      if ((packet_type == 'm' && gdbserv->target->get_mem != NULL)
	  || ((packet_type == 'M' || packet_type == 'X')
	      && gdbserv->target->set_mem != NULL))
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
	      long nr_read = gdbserv->target->get_mem (gdbserv, &addr, data, len);
	      gdbserv_output_bytes (gdbserv, data, nr_read);
	    }
	  else if (gdbserv_input_char (gdbserv) == ':')
	    {
	      if (packet_type == 'X')
		{
		  void *data = alloca (len);
		  if (gdbserv_input_escaped_binary (gdbserv, data, len) != len)
		    gdbserv_output_string (gdbserv, "E05");
		  else if (gdbserv->target->set_mem (gdbserv, &addr, data, len) != len)
		    gdbserv_output_string (gdbserv, "E07");
		  else
		    gdbserv_output_string (gdbserv, "OK");
		}
	      else
		{
		  void *data = alloca (len);
		  if (gdbserv_input_bytes (gdbserv, data, len) != len)
		    gdbserv_output_string (gdbserv, "E06");
		  else if (gdbserv->target->set_mem (gdbserv, &addr, data, len) != len)
		    gdbserv_output_string (gdbserv, "E09");
		  else
		    gdbserv_output_string (gdbserv, "OK");
		}
	      gdbserv_output_string (gdbserv, "OK");
	    }
	  else
	    {
	      gdbserv_output_string (gdbserv, "E04");
	    }
	}
      /* Deprecated / SID Interface. */
      else if ((packet_type == 'm'
		&& gdbserv->target->process_get_mem != NULL)
	       || ((packet_type == 'M' || packet_type == 'X')
		   && gdbserv->target->process_set_mem != NULL))
	{
	  struct gdbserv_reg addr;
	  struct gdbserv_reg len;
	  if (gdbserv_input_reg_beb (gdbserv, &addr, 0) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E01");
	    }
	  else if (gdbserv_input_char (gdbserv) != ',')
	    {
	      gdbserv_output_string (gdbserv, "E02");
	    }
	  else if (gdbserv_input_reg_beb (gdbserv, &len, 0) < 0)
	    {
	      gdbserv_output_string (gdbserv, "E03");
	    }
	  else if (packet_type == 'm')
	    {
	      gdbserv->target->process_get_mem (gdbserv, &addr, &len);
	    }
	  else if (gdbserv_input_char (gdbserv) == ':')
	    {
	      if (packet_type == 'X')
		gdbserv->target->process_set_mem (gdbserv, &addr, &len, 1);
	      else
		gdbserv->target->process_set_mem (gdbserv, &addr, &len, 0);
	      gdbserv_output_string (gdbserv, "OK");
	    }
	  else
	    {
	      gdbserv_output_string (gdbserv, "E04");
	    }
	}
      break;

    case 'S':
    case 's':	 /* sAA..AA    Step from address AA..AA(optional) */
    case 'C':
    case 'c':    /* cAA..AA    Continue at address AA..AA(optional) */
      /* try to read optional parameter, pc unchanged if no parm */

      {
	struct gdbserv_reg addr;
	unsigned long sigval = 0;

	if (packet_type == 'C' || packet_type == 'S')
	  {
	    gdbserv_input_hex_ulong (gdbserv, &sigval);
	    if (gdbserv_input_peek (gdbserv) == ';')
	      gdbserv_input_char (gdbserv);
	  }

	// If there was a first address argument, set it as as the PC
	if (gdbserv_input_reg_beb (gdbserv, &addr, 0) >= 0)
	  gdbserv->target->process_set_pc (gdbserv, &addr);

	/* Need to flush the instruction cache here, as we may have
	   deposited a breakpoint, and the icache probably has no way of
	   knowing that a data ref to some location may have changed
	   something that is in the instruction cache.  */
	
	gdbserv->target->flush_i_cache (gdbserv);
	
	/* If we have a function to handle signals, call it. */
	if (sigval != 0 && gdbserv->target->process_signal != NULL)
	  {
	    /* If 0 is returned, we either ignored the signal or invoked a user
	       handler. Otherwise, the user program should die. */
	    if (! gdbserv->target->process_signal (gdbserv, sigval))
	      sigval = 0;
	  }
	
	/* if we didn't have a function to handle signals, nuke the
           target program */
	if (sigval != 0)
	  {
	    gdbserv->target->sigkill_program (gdbserv);
	    return;
	  }

	/* Set the direction.  */
	gdbserv->target->set_exec_direction (gdbserv, exec_direction);

	/* Set machine state to force a single step.  */
	if (packet_type == 's' || packet_type == 'S')
	  {
	    gdbserv->target->singlestep_program (gdbserv);
	    gdbserv->state = GDBSERV_STATE_STEPPING;
	  }
	else
	  {
	    gdbserv->target->continue_program (gdbserv);
	    gdbserv->state = GDBSERV_STATE_RUNNING;
	  }
	return;
      }

    case 'E':
    case 'e':    /* eAA..AA,BB..BB   Step out of address range [AA .. BB) */
      /* try to read optional parameter, pc unchanged if no parm */

      {
	struct gdbserv_reg addr;
	struct gdbserv_reg addr_limit;
	unsigned long sigval = 0;
	int rc;

	if (packet_type == 'E')
	  {
	    gdbserv_input_hex_ulong (gdbserv, &sigval);
	    if (gdbserv_input_peek (gdbserv) == ',')
	      gdbserv_input_char (gdbserv);
	  }

	if (gdbserv_input_reg_beb (gdbserv, &addr, 0) < 0)
 	  {
	    gdbserv_output_string (gdbserv, "E01");
	    break;
	  }

	if (gdbserv_input_peek (gdbserv) == ',')
	  gdbserv_input_char (gdbserv);

	if (gdbserv_input_reg_beb (gdbserv, &addr_limit, 0) < 0)
	  {
	    gdbserv_output_string (gdbserv, "E02"); 
	    break;
	  }
	
	gdbserv->target->flush_i_cache (gdbserv);
	
	/* If we have a function to handle signals, call it. */
	if (sigval != 0 && gdbserv->target->process_signal != NULL)
	  {
	    /* If 0 is returned, we either ignored the signal or invoked a user
	       handler. Otherwise, the user program should die. */
	    if (! gdbserv->target->process_signal (gdbserv, sigval))
	      sigval = 0;
	  }
	
	/* if we didn't have a function to handle signals, nuke the
           target program */
	if (sigval != 0)
	  {
	    gdbserv->target->sigkill_program (gdbserv);
	    return;
	  }
	
	rc = gdbserv->target->rangestep_program (gdbserv, & addr, & addr_limit);
	if (rc == GDBSERV_TARGET_RC_OK)
	  {
	    gdbserv->state = GDBSERV_STATE_RUNNING;
	    gdbserv_output_string (gdbserv, "OK");
	  }
	else
	  {
	    gdbserv_output_string (gdbserv, ""); /* act as if unsupported */
	  }

	break;
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
	  gdbserv->state = GDBSERV_STATE_RESETTING;
	}
      gdbserv_output_string (gdbserv, "");
      break;


    case 'R': /* Rnn restart server */
      if (gdbserv->target->restart_program)
	{
	  gdbserv->target->restart_program (gdbserv);
	  gdbserv->state = GDBSERV_STATE_RESETTING;
	  return;
	}
      else
	{
	  gdbserv_output_string (gdbserv, "");
	}
      break;


    case 'i':
      /* cycle-step [ <addr> ] [ "," <nnn> ] */
      if (gdbserv->target->cyclestep_program)
	{
	  gdbserv->target->cyclestep_program (gdbserv);
	  gdbserv->state = GDBSERV_STATE_STEPPING;
	  return;
	}
      gdbserv_output_string (gdbserv, "");
      break;


    default:
      if (gdbserv->target->process_target_packet)
	gdbserv->target->process_target_packet (gdbserv);
      else
	{
	  if (gdbserv_state_trace)
	    fprintf (gdbserv_state_trace, "<target_packet>\n");
	  gdbserv_output_string (gdbserv, "");
	}
      break;

    }
  gdbserv_output_packet (gdbserv);
}

void
gdbserv_fromtarget_reset (struct gdbserv *gdbserv)
{
  enum gdbserv_state nextstate;
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromtarget_reset %s>\n",
	     state2str (gdbserv));
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_RESETTING:
      /* After a reset / power-on GDB is always expecting the remote
         target to stop and receive further commands.  Hence NO NOTIFY
         and SINGLESTEP */
      gdbserv->target->singlestep_program (gdbserv);
      nextstate = GDBSERV_STATE_STUMBLING;
      break;
    default:
      nextstate = gdbserv->state;
    }
  gdbserv->state = nextstate;
}

void
gdbserv_fromtarget_break (struct gdbserv *gdbserv,
			  int sigval)
{
  enum gdbserv_state nextstate;
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromtarget_break %s>\n",
	     state2str (gdbserv));
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_STUMBLING:
      /* Server has gone through a reset.  GDB expects the client to
         be ready for further commands */
      nextstate = GDBSERV_STATE_BROKEN;
      break;
    case GDBSERV_STATE_RUNNING:
    case GDBSERV_STATE_STEPPING:
      gdbserv_output_discard (gdbserv);
      gdbserv_output_char (gdbserv, 'T');
      gdbserv_output_byte (gdbserv, sigval);
      /* When the target knows how, expedite the supply of register
         values back to GDB.  Do this by appending them to the end of
         the T packet response. */
      if (gdbserv->target->expedited_reg_nr != NULL
	  && gdbserv->target->get_reg != NULL
	  && gdbserv->target->output_reg != NULL)
	{
	  int i;
	  int reg_nr;
	  for (i = 0, reg_nr = gdbserv->target->expedited_reg_nr (gdbserv, i);
	       reg_nr >= 0;
	       i++, reg_nr = gdbserv->target->expedited_reg_nr (gdbserv, i))
	    {
	      struct gdbserv_reg reg;
	      gdbserv_output_char (gdbserv, ';');
	      gdbserv_output_byte (gdbserv, reg_nr);
	      gdbserv_output_char (gdbserv, ':');
	      gdbserv->target->get_reg (gdbserv, reg_nr, &reg);
	      gdbserv->target->output_reg (gdbserv, &reg, 0);
	    }
	  gdbserv_output_char (gdbserv, ';');
	}
      /* Deprecated / SID Interface. */
      else if (gdbserv->target->process_get_exp_regs)
	gdbserv->target->process_get_exp_regs (gdbserv);
      gdbserv_output_packet (gdbserv);
      nextstate = GDBSERV_STATE_BROKEN;
      break;
    default:
      nextstate = gdbserv->state;
    }
  gdbserv->state = nextstate;
}

void
gdbserv_fromtarget_exit (struct gdbserv *gdbserv,
			 int sigval)
{
  enum gdbserv_state nextstate;
  if (gdbserv_state_trace)
    fprintf (gdbserv_state_trace, "<gdbserv_fromtarget_exit %s>\n",
	     state2str (gdbserv));
  switch (gdbserv->state)
    {
    case GDBSERV_STATE_RUNNING:
    case GDBSERV_STATE_STEPPING:
      gdbserv_output_char (gdbserv, 'W');
      gdbserv_output_byte (gdbserv, sigval);
      gdbserv_output_packet (gdbserv);
      nextstate = GDBSERV_STATE_EXITED;
      break;
    default:
      nextstate = gdbserv->state;
    }
  gdbserv->state = nextstate;
}
