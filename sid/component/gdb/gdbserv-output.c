/*
 * gdbserv-output.c -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


#include <stdio.h>
#include "gdbserv.h"
#include "gdbserv-state.h"
#include "gdbserv-utils.h"

FILE *gdbserv_output_trace;

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
gdbserv_output_string (struct gdbserv *gdbserv, const char *packet)
{
  int i;
  for (i = 0; i < strlen (packet); i++)
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
      for (i = reg->len -1 ; i >= 0; i--)
	gdbserv_output_byte (gdbserv, reg->buf[i]);
    }
  else
    {
      /* FIXME - discard the negative sign. */
      if (reg->negative_p)
	abort ();
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
	{
	  gdbserv_output_char (gdbserv, '-');
	}
      for (i = 0; i < reg->len; i++)
	gdbserv_output_byte (gdbserv, reg->buf[i]);
    }
  else
    {
      /* FIXME - discard the negative sign. */
      if (reg->negative_p)
	abort ();
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
  if (gdbserv_output_trace)
    {
      int i;
      fprintf (gdbserv_output_trace, "[<-%d ", sizeof_buf);
      for (i = 0; i < sizeof_buf; i++)
	{
	  fprintf (gdbserv_output_trace, "%c", gdbserv->output.buf[i]);
	}
      fprintf (gdbserv_output_trace, " ]\n");
    }
  gdbserv->client->write (gdbserv, gdbserv->output.buf, sizeof_buf);
  /* assume that it gets through */
  /* gdbserv_output_discard (gdbserv); */
  gdbserv_input_wait_for_ack (gdbserv);
}
