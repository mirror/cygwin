/* gdbserv-log.c

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

#include <stdlib.h>

#include "gdblog.h"

struct gdblog
{
  void *context;
  gdblog_string_ftype *log_string;
  gdblog_long_ftype *log_long;
  gdblog_xlong_ftype *log_xlong;
  gdblog_char_ftype *log_char;
};

void
gdblog_string (struct gdblog *log, const char *val)
{
  if (log)
    log->log_string (log->context, val);
}

void
gdblog_long (struct gdblog *log, long val)
{
  if (log)
    log->log_long (log->context, val);
}

void
gdblog_xlong (struct gdblog *log, long val)
{
  if (log)
    log->log_xlong (log->context, val);
}

void
gdblog_char (struct gdblog *log, char val)
{
  if (log)
    log->log_char (log->context, val);
}

struct gdblog *
gdblog_new (void *context,
	    gdblog_string_ftype *log_string,
	    gdblog_long_ftype *log_long,
	    gdblog_xlong_ftype *log_xlong,
	    gdblog_char_ftype *log_char)
{
  struct gdblog *new_log = malloc (sizeof (struct gdblog));
  new_log->context = context;
  new_log->log_string = log_string;
  new_log->log_long = log_long;
  new_log->log_xlong = log_xlong;
  new_log->log_char = log_char;
  return new_log;
}
