/* gdbserv-output.c

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
#include <assert.h>
#include <string.h>
#include "gdbserv.h"
#include "gdbserv-state.h"
#include "gdbserv-utils.h"
#include "gdblog.h"
#include "gdbserv-log.h"

void
gdbserv_output_attach (struct gdbserv *gdbserv)
{
  gdbserv->output.buf[0] = '$';
  gdbserv->output.len = 1;
}

void
gdbserv_output_detach (struct gdbserv *gdbserv)
{
  gdbserv->output.len = 0;
}

void
gdbserv_output_char (struct gdbserv *gdbserv, char c)
{
  if (gdbserv->output.len < sizeof (gdbserv->output.buf))
    {
      gdbserv->output.buf[gdbserv->output.len++] = c;
    }
}

void
gdbserv_output_string_as_bytes (struct gdbserv *gdbserv, const char *packet)
{
  int i;
  int len = strlen (packet);

  for (i = 0; i < len; i++)
    {
      gdbserv_output_byte (gdbserv, packet[i]);
    }
}

void
gdbserv_output_string (struct gdbserv *gdbserv, const char *packet)
{
  int i;
  int len = strlen (packet);

  for (i = 0; i < len; i++)
    gdbserv_output_char (gdbserv, packet[i]);
}

void
gdbserv_output_byte (struct gdbserv *gdbserv, int h)
{
  gdbserv_output_char (gdbserv, gdbserv_to_hex (h >> 4));
  gdbserv_output_char (gdbserv, gdbserv_to_hex (h >> 0));
}

void
gdbserv_output_nibble (struct gdbserv *gdbserv, int h)
{
  gdbserv_output_char (gdbserv, gdbserv_to_hex (h));
}

void
gdbserv_output_bytes (struct gdbserv *gdbserv, const char *buf, unsigned sizeof_buf)
{
  int i;
  for (i = 0; i < sizeof_buf; i++)
    {
      gdbserv_output_byte (gdbserv, buf[i]);
    }
}

void
gdbserv_output_reg_leb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int len)
{
  int i;
  if (len == 0)
    {
      if (reg->negative_p)
	gdbserv_output_char (gdbserv, '-');
      if (reg->len == 0)
	gdbserv_output_byte (gdbserv, 0);
      else
	{
	  for (i = reg->len - 1 ; i >= 0; i--)
	    gdbserv_output_byte (gdbserv, reg->buf[i]);
	}
    }
  else
    {
      /* FIXME - discard the negative sign. */
      assert (!reg->negative_p);
      for (i = len - 1; i >= 0; i--)
	{
	  int byte = reg->len - len + i;
	  if (byte < 0 || byte >= reg->len)
	    gdbserv_output_byte (gdbserv, 0);
	  else
	    gdbserv_output_byte (gdbserv, reg->buf[byte]);
	}
    }
}

void
gdbserv_output_reg_beb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int len)
{
  int i;
  if (len == 0)
    {
      if (reg->negative_p)
	gdbserv_output_char (gdbserv, '-');
      if (reg->len == 0)
	gdbserv_output_byte (gdbserv, 0);
      else
	{
	  for (i = 0; i < reg->len; i++)
	    gdbserv_output_byte (gdbserv, reg->buf[i]);
	}
    }
  else
    {
      /* FIXME - discard the negative sign. */
      assert (!reg->negative_p);
      for (i = 0; i < len; i++)
	{
	  int byte = reg->len - len + i;
	  if (byte < 0 || byte >= reg->len)
	    gdbserv_output_byte (gdbserv, 0);
	  else
	    gdbserv_output_byte (gdbserv, reg->buf[byte]);
	}
    }
}

void
gdbserv_output_discard (struct gdbserv *gdbserv)
{
  gdbserv->output.len = 1;
}

void
gdbserv_output_packet (struct gdbserv *gdbserv)
{
  /* compute / append a checksum.  Do not include that in the packet
     size. */
  int i;
  int sizeof_buf;
  unsigned long checksum = 0;
  for (i = 1; i < gdbserv->output.len; i++)
    {
      checksum += gdbserv->output.buf[i];
    }
  sizeof_buf = gdbserv->output.len;
  gdbserv->output.buf[sizeof_buf++] = '#';
  gdbserv->output.buf[sizeof_buf++] = gdbserv_to_hex (checksum >> 4);
  gdbserv->output.buf[sizeof_buf++] = gdbserv_to_hex (checksum >> 0);
  if (gdbserv_output_log)
    {
      int i;
      gdblog_string (gdbserv_output_log, "[<-");
      gdblog_long (gdbserv_output_log, sizeof_buf);
      gdblog_string (gdbserv_output_log, " ");
      for (i = 0; i < sizeof_buf; i++)
	{
	  gdblog_char (gdbserv_output_log, gdbserv->output.buf[i]);
	}
      gdblog_string (gdbserv_output_log, "]\n");
    }
  gdbserv->client->write (gdbserv, gdbserv->output.buf, sizeof_buf);
  /* assume that it gets through */
  /* gdbserv_output_discard (gdbserv); */
  gdbserv_input_wait_for_ack (gdbserv);
}
