/* win32-strace.cc

   Copyright 2000, 2002 Red Hat, Inc.

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
#include <stdlib.h>
#include <string.h>
#include <sys/strace.h>

#if !HAVE_WINDOWS_H
#error The windows.h header is required when compiling for a Win32 target.
#endif
#include <windows.h>
#include <sys/cygwin.h>

#include "server.h"

static int
output_winerror (FILE *ofile, char *s)
{
  char *winerr = strstr (s, "Win32 error ");
  if (!winerr)
    return 0;

  DWORD errnum = atoi (winerr + sizeof ("Win32 error ") - 1);
  if (!errnum)
    return 0;

  /*
   * NOTE: Currently there is no policy for how long the
   * the buffers are, and looks like 256 is a smallest one
   * (dlfcn.cc). Other than error 1395 (length 213) and
   * error 1015 (length 249), the rest are all under 188
   * characters, and so I'll use 189 as the buffer length.
   * For those longer error messages, FormatMessage will
   * return FALSE, and we'll get the old behaviour such as
   * ``Win32 error 1395'' etc.
   */
  char buf[4096];
  if (!FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM
		      | FORMAT_MESSAGE_IGNORE_INSERTS,
		      NULL,
		      errnum,
		      MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
		      (LPTSTR) buf, sizeof (buf), NULL))
    return 0;

  /* Get rid the trailing CR/NL pair. */
  char *p = strchr (buf, '\0');
  p[-2] = '\n';
  p[-1] = '\0';

  *winerr = '\0';
  fputs (s, ofile);
  fputs (buf, ofile);
  return 1;
}

static SYSTEMTIME *
syst (long long t)
{
  FILETIME n;
  static SYSTEMTIME st;
  long long now = t + ((long long) 1/*usecs*/ * 10);
  n.dwHighDateTime = now >> 32;
  n.dwLowDateTime = now & 0xffffffff;
  FileTimeToSystemTime (&n, &st);
  return &st;
}

#define CYGWIN_SIGNAL_STRING "cygwin: signal"
#define INTROLEN (3 + 8)

int
win32_output_debug_string (child_process *process, DEBUG_EVENT &ev)
{
  /* This includes the terminating null character already. */
  DWORD size = ev.u.DebugString.nDebugStringLength;
  BOOL unicode = ev.u.DebugString.fUnicode;

  char *s = (char *) alloca (unicode ? 2 * size : size);

  if (!ReadProcessMemory (process->process_hdl,
  		          ev.u.DebugString.lpDebugStringData,
		          s, unicode ? 2 * size : size, NULL))
    {
      process->debug ("\nReadProcessMemory failed with error %d\n",
                      GetLastError ());
      return 0;
    }
  if (!strncmp (s, CYGWIN_SIGNAL_STRING, sizeof CYGWIN_SIGNAL_STRING - 1))
    {
      /* Cygwin raised a signal. */
      process->set_break (strtol (s + sizeof CYGWIN_SIGNAL_STRING - 1, NULL,0));

      process->debug ("Win32: Cygwin raised a signal %d\n",
      	              process->stop_signal ());

      return process->stop_signal ();
    }

  char *str = s;
  if (unicode)
    {
      str = (char *) alloca (size);
      WideCharToMultiByte (CP_ACP, 0, (const WCHAR *) s, -1,
      			   str, size, NULL, NULL);
    }

  if (strncmp (s, "cYg", 3) && process->debug_process ())
    {
      fprintf (stderr, "%s\n", s);
      return 0;
    }

  if (!process->trace ())
    return 0;

  int len = (int) strtoul (s + 3, NULL, 16);
  if (!len)
    return 0;

  int special;
  if (len > 0)
    special = 0;
  else
    {
      special = len;
      if (special == _STRACE_INTERFACE_ACTIVATE_ADDR)
        len = 17;
    }
  char *buf = s + INTROLEN;
  buf[len] = '\0';

  s = strtok (buf, " ");

  unsigned n = strtoul (s, NULL, 16);

  s = strchr (s, '\0') + 1;

  if (special == _STRACE_INTERFACE_ACTIVATE_ADDR)
    {
      DWORD nbytes;
      DWORD new_flag = 1;
      if (!WriteProcessMemory (process->process_hdl, (LPVOID) n, &new_flag,
                               sizeof (new_flag), &nbytes))
        process->debug ("Win32: couldn't write strace flag to child, "
		       "windows error %d", GetLastError ());
      return 0;
    }

  char *origs = s;

  if (process->trace () & n)
    /* got it */ ;
  else if (!(process->trace () & _STRACE_ALL) || (n & _STRACE_NOTALL))
    return 0;			/* This should not be included in "all" output */

  DWORD dusecs, usecs;
  char *ptusec, *ptrest;

  dusecs = strtoul (s, &ptusec, 10);
  char *q = ptusec;
  while (*q == ' ')
    q++;
  if (*q != '[')
    {
      usecs = strtoul (q, &ptrest, 10);
      while (*ptrest == ' ')
	ptrest++;
    }
  else
    {
      ptrest = q;
      ptusec = s;
      usecs = dusecs;
    }

  if (process->saw_stars == 0)
    {
      FILETIME st;
      char *news;

      GetSystemTimeAsFileTime (&st);
      FileTimeToLocalFileTime (&st, &st);
      process->start_time = st.dwHighDateTime;
      process->start_time <<= 32;
      process->start_time |= st.dwLowDateTime;
      if (*(news = ptrest) != '[')
	process->saw_stars = 2;
      else
	{
	  process->saw_stars++;
	  while ((news = strchr (news, ' ')) != NULL && *++news != '*')
	    process->nfields++;
	  if (news == NULL)
	    process->saw_stars++;
	  else
	    {
	      s = news;
	      process->nfields++;
	    }
	}
    }
  else if (process->saw_stars < 2)
    {
      int i;
      char *news;
      if (*(news = ptrest) != '[')
	process->saw_stars = 2;
      else
	{
	  for (i = 0; i < process->nfields; i++)
	    if ((news = strchr (news, ' ')) == NULL)
	      break;		// Should never happen
	    else
	      news++;

	  if (news == NULL)
	    process->saw_stars = 2;
	  else
	    {
	      s = news;
	      if (*s == '*')
		{
		  SYSTEMTIME *st = syst (process->start_time);
		  fprintf (stderr,
			   "Date/Time:    %d-%02d-%02d %02d:%02d:%02d\n",
			   st->wYear, st->wMonth, st->wDay, st->wHour,
			   st->wMinute, st->wSecond);
		  process->saw_stars++;
		}
	    }
	}
    }

  long long d = usecs - process->last_usecs;
  char intbuf[40];

  s = ptusec;
  sprintf (intbuf, "%5d ", (int) d);
  len = strlen (intbuf);

  memcpy ((s -= len), intbuf, len);

  process->last_usecs = usecs;
  if (!output_winerror (stderr, s))
    fputs (s, stderr);

  return 0;
}
