/* stdio-log.c

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

#include <stdio.h>
#include "gdblog.h"
#include "stdio-log.h"

/* Create a log that sends everything to stdio.  */

static void
do_stdio_log_string (void *context, const char *val)
{
  FILE *stdio = context;
  fprintf (stdio, "%s", val);
}

static void
do_stdio_log_long (void *context, long val)
{
  FILE *stdio = context;
  fprintf (stdio, "%ld", val);
}

static void
do_stdio_log_xlong (void *context, long val)
{
  FILE *stdio = context;
  fprintf (stdio, "%lx", val);
}

static void
do_stdio_log_char (void *context, char val)
{
  FILE *stdio = context;
  fprintf (stdio, "%c", val);
}

extern struct gdblog *
stdio_log (FILE *stdio)
{
  return gdblog_new (stdio,
		     do_stdio_log_string,
		     do_stdio_log_long,
		     do_stdio_log_xlong,
		     do_stdio_log_char);
}

#ifdef __cplusplus
}
#endif
