/* gdbserv-input.c

   Copyright 1998, 2000, 2001, 2002 Red Hat, Inc.

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
#include <assert.h>

#include "gdbserv.h"
#include "gdbserv-state.h"
#include "gdbserv-utils.h"
#include "gdblog.h"
#include "gdbserv-log.h"

void
gdbserv_input_attach (struct gdbserv *gdbserv)
{
  gdbserv->input.state = GDBINPUT_STATE_IDLE;
  gdbserv->input.buf = NULL;
  gdbserv->input.sizeof_buf = 0; /* allocate buffer on first use */
  gdbserv->input.len = 0;
  gdbserv->input.out = 0;
}

void
gdbserv_input_detach (struct gdbserv *gdbserv)
{
}

static int
add_char_to_packet (struct gdbserv *gdbserv, int ch)
{
  while (1)
    {
      switch (gdbserv->input.state)
	{

	case GDBINPUT_STATE_IDLE:
	  if (ch == '$')
	    {
	      gdbserv->input.state = GDBINPUT_STATE_TERM;
	      gdbserv->input.len = 0;
	      gdbserv->input.out = 0;
	      gdbserv->input.checksum = 0;
	      gdbserv->input.xmitcsum = -1;
	    }
	  else if (ch == 0x03 /* CNTRL-C */ )
	    {
	      /* CNTRL-C packet: No check-sum or anything else.  Hence not
	         very safe. */
	      gdbserv_fromclient_break (gdbserv);
	    }
	  return 0;

	case GDBINPUT_STATE_TERM:
	  /* enlarge receive buffer if necessary/possible */
	  if (gdbserv->input.sizeof_buf == gdbserv->input.len)
	    {
	      char *newbuf;
	      unsigned new_sizeof_buf = gdbserv->input.sizeof_buf + 4000;
	      newbuf = realloc (gdbserv->input.buf, new_sizeof_buf);
	      if (newbuf == NULL)
		{
		  gdbserv->client->write (gdbserv, "-", 1);	/* failed */
		  gdbserv->input.state = GDBINPUT_STATE_IDLE;
		  return -1;
		}
	      gdbserv->input.buf = newbuf;
	      gdbserv->input.sizeof_buf = new_sizeof_buf;
	    }
	  assert (gdbserv->input.buf != NULL);
	  assert (gdbserv->input.sizeof_buf > gdbserv->input.len);
	  if (ch == '#')
	    {
	      gdbserv->input.buf[gdbserv->input.len] = 0;
	      gdbserv->input.state = GDBINPUT_STATE_CRC1;
	    }
	  else
	    {
	      gdbserv->input.buf[gdbserv->input.len] = ch;
	      gdbserv->input.len++;
	      gdbserv->input.checksum += ch;
	    }
	  return 0;

	case GDBINPUT_STATE_CRC1:
	  gdbserv->input.xmitcsum = gdbserv_hex_to (ch) << 4;
	  gdbserv->input.state = GDBINPUT_STATE_CRC2;
	  return 0;

	case GDBINPUT_STATE_CRC2:
	  gdbserv->input.xmitcsum |= gdbserv_hex_to (ch);
	  if ((gdbserv->input.checksum & 255) != gdbserv->input.xmitcsum)
	    {
	      gdbserv->client->write (gdbserv, "-", 1);	/* failed checksum */
	      gdbserv->input.state = GDBINPUT_STATE_IDLE;
	      return -1;
	    }
	  else
	    {
	      char ack[3];
	      int sizeof_ack = 0;
	      ack[sizeof_ack++] = '+';
	      /* if a sequence char is present, reply the sequence ID */
	      assert (gdbserv->input.buf != NULL);
	      assert (gdbserv->input.sizeof_buf > gdbserv->input.len);
	      if (gdbserv->input.buf[2] == ':')
		{
		  unsigned long count = gdbserv->input.len;
		  unsigned long i;
		  ack[sizeof_ack++] = gdbserv->input.buf[0];
		  ack[sizeof_ack++] = gdbserv->input.buf[1];
		  /* remove sequence chars from buffer */
		  for (i = 3; i <= count; i++)
		    gdbserv->input.buf[i - 3] = gdbserv->input.buf[i];
		}
	      gdbserv->client->write (gdbserv, ack, sizeof_ack);
	      gdbserv->input.state = GDBINPUT_STATE_IDLE;
	      return 1;
	    }

	case GDBINPUT_STATE_ACK:
	  if (ch == '+')
	    {
	      gdbserv_output_discard (gdbserv);
	      gdbserv->input.state = GDBINPUT_STATE_IDLE;
	    }
	  else if (ch == '-')
	    {
	      gdbserv_output_packet (gdbserv);
	    }
	  else if (ch == '$')
	    {
	      gdblog_string (gdbserv_warning_log,
			     "Unexpected packet start received "
			     "(ACK missing?)");
	      /* Give up waiting for ACK and go receive the new packet. */
	      gdbserv->input.state = GDBINPUT_STATE_IDLE;
	      continue;
	    }
	  /* else: ignore junk characters. */
	  return 0;

	} /* switch */

    } /* while */
  return 0;
}

void
gdbserv_input_data_packet (struct gdbserv *gdbserv,
			   const char *data,
			   int sizeof_data)
{
  int i;
  if (gdbserv_input_log)
    {
      gdblog_string (gdbserv_input_log, "[->");
      gdblog_long (gdbserv_input_log, sizeof_data);
      gdblog_string (gdbserv_input_log, " ");
      for (i = 0; i < sizeof_data; i++)
	{
	  gdblog_char (gdbserv_input_log, data[i]);
	}
      gdblog_string (gdbserv_input_log, "]\n");
    }
  for (i = 0; i < sizeof_data; i++)
    {
      switch (add_char_to_packet (gdbserv, data[i]))
	{
	case 0:
	  break;
	case +1:
	  gdbserv->input.out = 0;
	  gdbserv_data_packet (gdbserv);
	  break;
	case -1:
	  return;
	}
    }
}

void
gdbserv_input_wait_for_ack (struct gdbserv *gdbserv)
{
  /* FIXME: cagney/2000-03-21: This stub framework lacks a mechanism
     for a encapsulating console output (via the ``O'' packet).
     Because of this, some targets just send raw ``O'' packets down
     the output stream and ignore all acknowledgments. */
  if ((gdbserv->input.state != GDBINPUT_STATE_IDLE)
      && (gdbserv->input.state != GDBINPUT_STATE_ACK))
    {
      if (gdbserv_warning_log)
	{
	  gdblog_string (gdbserv_warning_log,
			 "Unexpected transition to ACK (");
	  gdblog_long (gdbserv_warning_log, gdbserv->input.state);
	  gdblog_string (gdbserv_warning_log, ")\n");
	}
    }
  gdbserv->input.state = GDBINPUT_STATE_ACK;
}

int
gdbserv_input_size (struct gdbserv *gdbserv)
{
  if (gdbserv->input.out <= gdbserv->input.len)
    return gdbserv->input.len - gdbserv->input.out;
  else
    return -1;
}

int
gdbserv_input_char (struct gdbserv *gdbserv)
{
  if (gdbserv->input.out < gdbserv->input.len)
    return (unsigned char) gdbserv->input.buf[gdbserv->input.out++];
  else
    return -1;
}

int
gdbserv_input_string (struct gdbserv *gdbserv,
		      char *buf,
		      int len)
{
  int i;
  for (i = 0; i < (len - 1); i++)
    {
      int byte = gdbserv_input_char (gdbserv);
      if (byte < 0)
	break;
      buf[i] = byte;
    }
  buf[i] = '\0';
  return i;
}

int
gdbserv_input_string_match (struct gdbserv *gdbserv,
			    const char *buf)
{
  int i;
  /* compare strings */
  for (i = 0; buf[i] != '\0'; i++)
    {
      if (gdbserv->input.out + i >= gdbserv->input.len)
	return -1;
      if (buf[i] != gdbserv->input.buf[gdbserv->input.out + i])
	return -1;
    }

  /* match */
  gdbserv->input.out += i;
  return i;
}

int
gdbserv_input_peek (struct gdbserv *gdbserv)
{
  if (gdbserv->input.out < gdbserv->input.len)
    return (unsigned char) gdbserv->input.buf[gdbserv->input.out];
  else
    return -1;
}

int
gdbserv_input_byte (struct gdbserv *gdbserv)
{
  if (gdbserv->input.out + 1 < gdbserv->input.len)
    {
      int h0;
      int h1;
      h0 = gdbserv_hex_to (gdbserv->input.buf[gdbserv->input.out + 0]);
      if (h0 < 0)
	return -1;
      h1 = gdbserv_hex_to (gdbserv->input.buf[gdbserv->input.out + 1]);
      if (h1 < 0)
	return -1;
      gdbserv->input.out += 2;
      return (h0 << 4) | h1;
    }
  else
    return -1;
}

int
gdbserv_input_nibble (struct gdbserv *gdbserv)
{
  if (gdbserv->input.out < gdbserv->input.len)
    {
      int nibble = gdbserv_hex_to (gdbserv->input.buf[gdbserv->input.out]);
      if (nibble < 0)
	return -1;
      gdbserv->input.out++;
      return nibble;
    }
  else
    return -1;
}

static int
unpack_reg_bytes (struct gdbserv *gdbserv,
		  struct gdbserv_reg *reg,
		  int buf[],
		  int byte_len)
{
  int len;
  int buf_len;

  /* Leading sign? */
  if (gdbserv->input.out < gdbserv->input.len
      && gdbserv->input.buf[gdbserv->input.out] == '-')
    {
      reg->negative_p = 1;
    }
  else
    {
      reg->negative_p = 0;
    }

  /* How many characters are allowed? */
  if (byte_len <= 0)
    buf_len = sizeof (reg->buf) * 2;
  else if (byte_len <= sizeof (reg->buf))
    buf_len = byte_len * 2;
  else
    return -1;

  /* unpack the half bytes */
  for (len = 0; len < buf_len; len++)
    {
      int pos = gdbserv->input.out + reg->negative_p + len;
      if (pos >= gdbserv->input.len)
	break;
      buf[len] = gdbserv_hex_to (gdbserv->input.buf[pos]);
      if (buf[len] < 0)
	break;
    }

  /* Correct number of digits found? */
  if (byte_len > 0 && len != buf_len)
    return -1;

  gdbserv->input.out += len + reg->negative_p;
  return len;
}

int
gdbserv_input_reg_beb (struct gdbserv *gdbserv,
		       struct gdbserv_reg *reg,
		       int byte_len)
{
  int buf[sizeof (reg->buf) * 2];
  int len;
  int pos;

  /* decode the input stream */
  len = unpack_reg_bytes (gdbserv, reg, buf, byte_len);
  if (len <= 0)
    return -1;

  /* re-pack as bytes, allow for odd starting byte */
  pos = 0;
  reg->len = 0;
  if (len % 2)
    {
      reg->buf[reg->len++] = buf[pos++];
    }
  while (pos < len)
    {
      int byte = 0;
      byte |= (buf[pos++] << 4);
      byte |= (buf[pos++] << 0);
      reg->buf[reg->len++] = byte;
    }

  /* provided something was found, succeed */
  if (reg->len > 0)
    {
      return reg->len;
    }
  else
    return -1;
}

int
gdbserv_input_reg_leb (struct gdbserv *gdbserv,
		       struct gdbserv_reg *reg,
		       int byte_len)
{
  int buf[sizeof (reg->buf) * 2];
  int len;
  int pos;

  /* decode the input stream, check something was found. */
  len = unpack_reg_bytes (gdbserv, reg, buf, byte_len);
  if (len <= 0)
    return -1;

  /* re-pack as bytes BE, allow for odd ending byte */
  pos = len;
  reg->len = 0;
  if (len % 2)
    {
      pos -= 1;
      reg->buf[reg->len++] = buf[pos];
    }
  while (pos > 1)
    {
      int byte = 0;
      pos -= 2;
      byte |= (buf[pos + 0] << 4);
      byte |= (buf[pos + 1] << 0);
      reg->buf[reg->len++] = byte;
    }

  /* provided something was found, succeed */
  if (reg->len > 0)
    {
      return reg->len;
    }
  else
    return -1;
}

int
gdbserv_input_bytes (struct gdbserv *gdbserv,
		     char *buf,
		     int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
      int byte = gdbserv_input_byte (gdbserv);
      if (byte < 0)
	break;
      buf[i] = byte;
    }
  return i;
}

int
gdbserv_input_escaped_binary (struct gdbserv *gdbserv,
		              char *buf,
		              int len)
{
  int i;
  int ch;

  for (i = 0; i < len; i++)
    {
      ch = gdbserv_input_char (gdbserv);
      if (ch < 0)
	return ch;
      if (ch == 0x7d)
	{
	  ch = gdbserv_input_char (gdbserv);
	  if (ch < 0)
	    return ch;
	  buf[i] = 0x20 | (ch & 0xff);
	}
      else
	{
	  buf[i] = ch;
	}
    }
  return i;
}

int
gdbserv_input_hex_ulong (struct gdbserv *gdbserv,
			 unsigned long *l)
{
  unsigned long val = 0;
  int nr = 0;
  while (gdbserv->input.out < gdbserv->input.len)
    {
      int h = gdbserv_hex_to (gdbserv->input.buf[gdbserv->input.out]);
      if (h < 0)
	break;
      val = (val << 4) | h;
      gdbserv->input.out++;
      nr++;
    }
  if (nr <= 0)
    return -1;
  else
    {
      *l = val;
      return 0;
    }
}

int
gdbserv_input_hex_long (struct gdbserv *gdbserv,
			long *l)
{
  unsigned long val = 0;
  int nr;
  int negative = 0;
  if (gdbserv->input.out < gdbserv->input.len
      && gdbserv->input.buf[gdbserv->input.out] == '-')
    {
      negative = 1;
      gdbserv->input.out++;
    }
  nr = 0;
  while (gdbserv->input.out < gdbserv->input.len)
    {
      int h = gdbserv_hex_to (gdbserv->input.buf[gdbserv->input.out]);
      if (h < 0)
	break;
      val = (val << 4) | h;
      gdbserv->input.out++;
      nr++;
    }
  if (nr <= 0)
    return -1;
  else
    {
      if (negative)
	*l = -val;
      else
	*l = val;
      return 0;
    }
}
