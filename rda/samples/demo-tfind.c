/* demo-tfind.c

   Copyright 2005 Red Hat, Inc.

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
#include <ctype.h>
#include <string.h>

#include "gdbserv.h" 
#include "gdbserv-target.h" 
#include "gdbserv-utils.h"
#include "demo-target.h"

static void tfind_set_gen (struct gdbserv *);
static void tfind_get_regs (struct gdbserv *);
static int  tfind_get_mem (unsigned long);
static void tfind_index_file (void);
void (*demo_set_gen_hook)  (struct gdbserv *);
void (*demo_get_regs_hook) (struct gdbserv *);
int  (*demo_get_mem_hook)  (unsigned long);

#define FILE_OPEN_ERROR 0x40
#define FILE_FORMAT_ERROR 0x41

static FILE *tfind_file;

extern void
demo_tfind_open (char *filename)
{
  char buf[80];

  demo_set_gen_hook = tfind_set_gen;

  if ((tfind_file = fopen (filename, "r")) == NULL)
    {
      fprintf (stderr, "tfind: could not open file %s for input.\n",
	       filename);
      exit (FILE_OPEN_ERROR);
    }

  if (strcmp (fgets (buf, sizeof (buf), tfind_file),
	      "CHECKPOINT FILE\n") != 0)
    {
      fprintf (stderr, "tfind: file %s is not a checkpoint file.\n",
	       filename);
      exit (FILE_FORMAT_ERROR);
    }
  tfind_index_file ();
}

/* find_frame_index reads in frames on demand, caches them, 
   and returns an index into the cache.  */

#define INBUF_SIZE 1024
static char inbuf[INBUF_SIZE];

#define NUM_FRAMES 1000
typedef struct TFRAME {
  unsigned int frame_id;
  unsigned long pc;
  long regpos;
  long mempos;
  long memlines;
} tframe;

tframe frame[NUM_FRAMES];
int last_cached_frame = 0;
int cur_frame = -1;

static void
tfind_index_file (void)
{
  /* Make a pass over the entire file -- cache the record positions.  */
  const char *const cpid = "CHECKPOINT ID";
  const char *const regs = "REGISTERS\n";
  const char *const mems = "MEMORY\n";

  char *tmp;

  while (last_cached_frame < NUM_FRAMES)
    {
      do { /* Skip empty lines.  */
	tmp = fgets (inbuf, sizeof (inbuf), tfind_file);
      } while (tmp != NULL && inbuf[0] == '\n');

      if (tmp == NULL)
	return;	/* End of file, all done.  */

      if (strncmp (inbuf, cpid, strlen (cpid)) != 0)
	{
	  fprintf (stderr, "tfind: input record error: '%s'.\n", inbuf);
	  exit (FILE_FORMAT_ERROR);
	}
      /* Should have frame id.  */
      frame[last_cached_frame].frame_id = strtol (inbuf + strlen (cpid), 
						  NULL, 0);

      tmp = fgets (inbuf, sizeof (inbuf), tfind_file);

      /* A checkpoint record will be terminated by
	 a newline or EOF.  */
      while (tmp && inbuf[0] != '\0' && inbuf[0] != '\n')
	{
	  if (strcmp (inbuf, regs) == 0)
	    {
	      /* Got registers -- all on one line.  */
	      frame[last_cached_frame].regpos = ftell (tfind_file);
	      /* Advance past registers.  */
	      tmp = fgets (inbuf, sizeof (inbuf), tfind_file);
	      /* ... and load the next line for parsing.  */
	      tmp = fgets (inbuf, sizeof (inbuf), tfind_file);
	      continue;
	    }
	  else if (strcmp (inbuf, mems) == 0)
	    {
	      /* Arbitrary number of lines in srec (subset) format:
		 'S' + '3' + size (2 bytes) + addr (8 bytes) + content.  */
	      frame[last_cached_frame].mempos = ftell (tfind_file);
	      frame[last_cached_frame].memlines = 0;
	      do {
		tmp = fgets (inbuf, sizeof (inbuf), tfind_file);
		if (tmp != NULL &&
		    inbuf[0] == 'S' &&
		    inbuf[1] == '3')
		  frame[last_cached_frame].memlines ++;
		else
		  break;
	      } while (1);
	      /* And we now have an input line that's not memory...
		 ready to be parsed on the next iteration.  */
	      continue;
	    }
	  else if (strncmp (inbuf, "PC=", 3) == 0)
	    {
	      frame[last_cached_frame].pc = strtoul (&inbuf[3], NULL, 16);
	      /* Get the next input line ready.  */
	      tmp = fgets (inbuf, sizeof (inbuf), tfind_file);
	      continue;
	    }
	  else
	    {
	      fprintf (stderr, "Bad input line: %s", (char *) inbuf);
	      /* Get the next input line ready.  */
	      tmp = fgets (inbuf, sizeof (inbuf), tfind_file);
	      continue;
	    }
	}
      last_cached_frame++;
    }
}

static int
find_frame_by_id (int start_frame, int frame_id)
{
  int i;

  if (start_frame < 0 ||  start_frame >= last_cached_frame)
    start_frame = -1;

  for (i = ++start_frame; i < last_cached_frame; i++)
    if (frame[i].frame_id == frame_id)
      return i;

  /* OK, wrap around and search from the start.  */
  for (i = 0; i < start_frame; i++)
    if (frame[i].frame_id == frame_id)
      return i;

  return -1;
}

static int
find_frame_by_pc (int start_frame, unsigned long pc)
{
  int i;

  if (start_frame < 0 ||  start_frame >= last_cached_frame)
    start_frame = -1;

  for (i = ++start_frame; i < last_cached_frame; i++)
    if (frame[i].pc == pc)
      return i;

  /* OK, wrap around and search from the start.  */
  for (i = 0; i < start_frame; i++)
    if (frame[i].pc == pc)
      return i;

  return -1;
}


/* tfind_set_gen gets hooked into the set_gen hook.  
   For now there is no chain.  */

static void tfind_set_gen (struct gdbserv *serv)
{
  const char *const prefix = "TFrame:";
  char buf[40];
  int tmp_frame;

  if (gdbserv_input_string_match (serv, prefix) != strlen (prefix))
    {
      fprintf (stderr, "Tfind: bad command prefix.\n");
    }

  if (gdbserv_input_string (serv, inbuf, INBUF_SIZE) > 0)
    {
      /* TFind frame by index.  */
      if (isxdigit (inbuf[0]))
	{
	  tmp_frame = strtoul (inbuf, NULL, 16);

	  if (tmp_frame == 0xffffffff)	/* Magic number meaning "none".  */
	    {
	      demo_get_regs_hook = NULL;
	      demo_get_mem_hook  = NULL;
	      cur_frame = -1;
	      gdbserv_output_string (serv, "OK");
	      return;
	    }
	  else if (tmp_frame >= 0 && tmp_frame < last_cached_frame)
	    {
	      demo_get_regs_hook = tfind_get_regs;
	      demo_get_mem_hook  = tfind_get_mem;
	      cur_frame = tmp_frame;
	    }

	  if (cur_frame >= 0)
	    {
	      fprintf (stderr, "Tfind: frame number %d.\n", cur_frame);
	      sprintf (buf, "F%x", cur_frame);
	      gdbserv_output_string (serv, buf);
	    }
	  else if (tmp_frame >= last_cached_frame)
	    {
	      fprintf (stderr, "Error, no such frame '%d'\n", tmp_frame);
	      gdbserv_output_string (serv, "F-1");
	    }
	}
      /* TFind frame by PC.  */
      else if (inbuf[0] == 'p' &&
	       inbuf[1] == 'c' &&
	       inbuf[2] == ':')
	{
	  unsigned long pc = strtoul (&inbuf[3], NULL, 16);
	  int tmp_frame = find_frame_by_pc (cur_frame, pc);

	  if (tmp_frame >= 0)
	    {
	      cur_frame = tmp_frame;
	      fprintf (stderr, "Tfind: frame %d, pc = 0x%08lx\n", 
		       (int) cur_frame, (unsigned long) pc);
	      sprintf (buf, "F%x", (int) cur_frame);
	      gdbserv_output_string (serv, buf);
	    }
	  else
	    {
	      fprintf (stderr, "Tfind: pc 0x%08lx not found.\n", pc);
	      gdbserv_output_string (serv, "F-1");
	    }
	}
      /* TFind frame by tracepoint/checkpoint ID.  */
      else if (inbuf[0] == 't' &&
	       inbuf[1] == 'd' &&
	       inbuf[2] == 'p' &&
	       inbuf[3] == ':')
	{
	  unsigned long id = strtoul (&inbuf[4], NULL, 16);
	  int tmp_frame = find_frame_by_id (cur_frame, id);

	  if (tmp_frame >= 0)
	    {
	      cur_frame = tmp_frame;
	      fprintf (stderr, "Tfind: frame %d, ID = 0x%08lx\n", 
		       (int) cur_frame, (unsigned long) id);
	      sprintf (buf, "F%x", (int) cur_frame);
	      gdbserv_output_string (serv, buf);
	    }
	  else
	    {
	      fprintf (stderr, "Tfind: id 0x%8lx not found.\n", id);
	      gdbserv_output_string (serv, "F-1");
	    }
	}
      else
	{
	  fprintf (stderr, "Tfind: bad data error: '%s'.\n", inbuf);
	  gdbserv_output_string (serv, "F-1");
	}
    }
  else
    {
      fprintf (stderr, "Tfind: no argument error.\n");
      gdbserv_output_string (serv, "E0E");
    }
}


static void
tfind_get_regs (struct gdbserv *serv)
{
  /* Trust but verify.  */
  int c;

  if (cur_frame < last_cached_frame &&
      frame[cur_frame].regpos != 0)
    {
      fseek (tfind_file, frame[cur_frame].regpos, SEEK_SET);
      while (isxdigit (c = fgetc (tfind_file)))
	gdbserv_output_char (serv, c);
    }
  else
    {
      /* I think gdb will be happy with this... */
      gdbserv_output_string (serv, "00000000");
    }
}

static int
tfind_get_mem (unsigned long addr)
{
  int i, len;
  unsigned long line_addr;

  if (cur_frame < last_cached_frame &&
      frame[cur_frame].mempos != 0)
    {
      fseek (tfind_file, frame[cur_frame].mempos, SEEK_SET);
      for (i = 0; i < frame[cur_frame].memlines; i++)
	{
	  fgets (inbuf, sizeof (inbuf), tfind_file);
	  len = (gdbserv_hex_to (inbuf[2]) << 4) +
	    gdbserv_hex_to (inbuf[3]);
	  len -= 5;

	  line_addr = (gdbserv_hex_to (inbuf[4]) << 28) +
	    (gdbserv_hex_to (inbuf[5]) << 24) +
	    (gdbserv_hex_to (inbuf[6]) << 20) +
	    (gdbserv_hex_to (inbuf[7]) << 16) +
	    (gdbserv_hex_to (inbuf[8]) << 12) +
	    (gdbserv_hex_to (inbuf[9])  << 8) +
	    (gdbserv_hex_to (inbuf[10]) << 4) +
	    gdbserv_hex_to (inbuf[11]);

	  if (addr >= line_addr &&
	      addr < line_addr + len)
	    {
	      int offset = 12 + (2 * (addr - line_addr));
	      return (gdbserv_hex_to (inbuf[offset]) << 4) +
		gdbserv_hex_to (inbuf[offset + 1]);
	    }
	}
      /* No match.  */
      return 0;
    }
  else
    return 0;
}

extern int
tfind_singlestep_program (struct gdbserv *serv)
{
  if (cur_frame == -1)
    {
      return 2; /*sched_break (serv, 2);*/
    }
  else if (cur_frame >= last_cached_frame - 1)
    {
      /* Stepped past the end of the tfind buffer.  */
      demo_get_regs_hook = NULL;
      demo_get_mem_hook  = NULL;
      cur_frame = -1;
      return 0; /*sched_break (serv, 0);*/
    }
  else
    {
      /* Increment cur_frame and schedule an immediate break.  */
      cur_frame++;
      return 0; /*sched_break (serv, 0);*/
    }
}
