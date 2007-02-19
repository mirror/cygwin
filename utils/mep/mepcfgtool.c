/* Configuration Tool for Toshiba Media Processor
   Copyright (C) 2001-2005, 2007 Free Software Foundation, Inc.
   Contributed by Red Hat Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with This program; see the file COPYING.  If not, write to the
Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>

#include "filenames.h"
#include "libiberty.h"
#include "mepcfgtool.h"

/* We had a problem finding strsep or strtok_r on all our supported 
   platforms.  Stick a private version here for now... */
char *mep_strtok_r (char *s, const char *delim, char **lasts);

/* SRCDIR is set appropriately when you do a build.  In case the user
   manually builds this file, provide a reasonable default.  */
#ifndef SRCDIR
#define SRCDIR "."
#endif

/* these are defined in the parser.  */
extern Node *core_ids_in_use[MAX_CORE_ID + 1];
extern int next_core_id;

Node *currentcfg = 0;
Gmap *currentgmap = 0;
CModel *currentcmodel = 0;

int warn_all = 0;

unsigned corecount = 0;
unsigned isacount = 0;

int cfgparse ();
const char *cfgfilename;
extern int cfglineno;
int cfgdebug;
int gmapparse ();
const char *gmapfilename;
extern int gmaplineno;
int gmapdebug;
int cmodelparse ();
const char *cmodelfilename;
extern int cmodellineno;
int cmodeldebug;

/* these are defined in the lexers */
extern FILE *cfgin;
extern FILE *gmapin;
extern FILE *cmodelin;

const char *srcdir = SRCDIR;
static char *instdir = 0;
static char *outdir = 0;
static const char *configdir = 0;
static char *localdir = 0;
static int nobuild = 0;
static int verbose = 0;
static int testing = 0;
static int num_files_changed = 0;
static char *rebuild_extra = "";
int toshapi = 1;
static int toshapi_version = 1; /* default version is 1. */
static const char *main_argv0;

mep_core_ty mep_core_type = MEP_CORE_C2;
mep_endian_ty mep_endian_type = MEP_ENDIAN_BIG;
static const char* mep_core_names[] = {"MeP", "c2", "c3", "c4", "h1"};
static const char* mep_mach_names[] = {"mep", "mep", "mep", "mep", "h1"};

int errors = 0;

typedef struct header_s {
  struct header_s *next;
  char *header;
} header_s;

static header_s *the_headers = 0;

static void
show_copyright ()
{
  static int done_it = 0;
  if (done_it == 0)
    {
      printf ("MeP-Integrator - "
	      "Copyright 2001-2005 Free Software Foundation\n");
      printf ("This program is free software, see the file COPYING for details.\n");
      done_it = 1;
    }
}

static void
usage ()
{
  show_copyright ();
  fprintf (stderr, "\n");
  fprintf (stderr, "Usage: MeP-Integrator [options] config.cfg\n");
  fprintf (stderr, "\nOptions:\n");
  fprintf (stderr, "-s <srcdir>     Specifies the location of your sources\n");
  fprintf (stderr, "                (the directory with the gcc, cgen, and gas subdirectories).\n");
  fprintf (stderr, "-i <instdir>    Installation directory (where bin/gcc is)\n");
  fprintf (stderr, "-o <outdir>     Output directory for generation of output using --nobuild or -i\n");
  fprintf (stderr, "-c <configdir>  Specifies the location of your config files (*.cfg).\n");
  fprintf (stderr, "--nobuild       Configure the installed files, not the source files\n");
  fprintf (stderr, "--warn-all      Generate all warnings\n");
  fprintf (stderr, "-v              Increases verbosity level.\n");
  fprintf (stderr, "-t              Turns on test mode.\n");
  fprintf (stderr, "-a              Turn on Toshiba sim api (cmodel) mode.\n");
  fprintf (stderr, "--api <num>     Use version <num> of the Toshiba sim api.\n");
  fprintf (stderr, "\n");
  fprintf (stderr, "With --nobuild and/or -i, your installation area will be updated with\n");
  fprintf (stderr, "  as much of the new configuration as possible.  Otherwise, your\n");
  fprintf (stderr, "  source tree (-s) will be updated and a rebuild will be required.\n");
  exit (EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */

enum context { fl_none, fl_cfg, fl_gmap, fl_cmodel } fl_context;
enum automake_version { AM_NONE, AM_1_4, AM_1_9_5 };

static void
msg (const char *f, int l, const char *msg, const char *fmt, va_list args)
{
  if (f == 0)
    {
      switch (fl_context)
	{
	case fl_none:                                         break;
	case fl_cfg:    f = cfgfilename;    l = cfglineno;    break;
	case fl_gmap:   f = gmapfilename;   l = gmaplineno;   break;
	case fl_cmodel: f = cmodelfilename; l = cmodellineno; break;
	}
    }
  if (f)
    fprintf (stderr, "%s:%d: ", f, l);
  fputs (msg, stderr);
  vfprintf (stderr, fmt, args);
  fputs (".\n", stderr);
}

void
warn (const char *fmt, ...)
{
  va_list a;
  va_start (a, fmt);
  msg (0, 0, "Warning: ", fmt, a);
  va_end (a);
}

void
warnn (Node *n, const char *fmt, ...)
{
  va_list a;
  va_start (a, fmt);
  msg (n->filename, n->lineno, "Warning: ", fmt, a);
  va_end (a);
}

void
error (const char *fmt, ...)
{
  va_list a;
  va_start (a, fmt);
  msg (0, 0, "Error: ", fmt, a);
  va_end (a);
  errors ++;
}

void
errorn (Node *n, const char *fmt, ...)
{
  va_list a;
  va_start (a, fmt);
  msg (n->filename, n->lineno, "Error: ", fmt, a);
  va_end (a);
  errors ++;
}

void
fatal (const char *fmt, ...)
{
  va_list a;
  va_start (a, fmt);
  msg (0, 0, "Fatal: ", fmt, a);
  va_end (a);
  exit (EXIT_FAILURE);
}

char *
hex_pr (int v)
{
  static char b[4][20];
  static int i = 0;
  i = (i+1) % 4;
  if (v > 0x1000 && ! (v & 0xfff))
    sprintf (b[i], "0x%X", v);
  else
    sprintf (b[i], "%d", v);
  return b[i];
}

static char *
upcase (const char *string)
{
  static char *buf = 0;
  int i;

  if (buf)
    free (buf);
  buf = strdup (string);
  for (i = 0; buf[i]; i++)
    buf[i] = toupper (buf[i]);
  return buf;
}

static char *
downcase (const char *string)
{
  static char *buf = 0;
  int i;

  if (buf)
    free (buf);
  buf = strdup (string);
  for (i = 0; buf[i]; i++)
    buf[i] = tolower (buf[i]);
  return buf;
}

/* ---------------------------------------------------------------------- */

/* Determine the directory containing the given file name.  */
static void
resolve_localdir (const char *filename)
{
  const char *c;
  assert (strlen (filename) > 0);
  for (c = filename + strlen (filename); c > filename; --c)
    {
      if (IS_DIR_SEPARATOR (*(c - 1)) || IS_DRIVE_SEPARATOR (*(c - 1)))
	break;
    }
  if (c > filename)
    {
      localdir = xrealloc (localdir, c - filename + 1);
      memcpy (localdir, filename, c - filename);
      localdir[c - filename] = '\0';
    }
  else
    {
      localdir = xrealloc (localdir, 1);
      *localdir = '\0';
    }
}

/* Construct a path to the given file name relative to the configdir, if
   filename is relative.  Also, set localdir to the directory containing the
   file. */
static const char *
resolve_config_filename (const char *filename)
{
  if (configdir && ! IS_ABSOLUTE_PATH (filename))
    {
      char *nfilename = (char *) xmalloc (strlen (configdir) + 1
					 + strlen (filename) + 1);
      strcpy (nfilename, configdir);
      strcat (nfilename, "/");
      strcat (nfilename, filename);
      filename = nfilename;
    }
  resolve_localdir (filename);
  return filename;
}

/* Construct a path to the given file name relative to the localdir, if
   filename is relative.  */
const char *
resolve_local_filename (const char *filename)
{
  assert (localdir);
  if (! IS_ABSOLUTE_PATH (filename))
    {
      char *nfilename = (char *) xmalloc (strlen (localdir)
					 + strlen (filename) + 1);
      if (*localdir)
	{
	  strcpy (nfilename, localdir);
	  if (! IS_DIR_SEPARATOR (localdir[strlen (localdir) - 1])
	      && ! IS_DRIVE_SEPARATOR (localdir[strlen (localdir) - 1]))
	    strcat (nfilename, "/");
	}
      else
	*nfilename = '\0';
      strcat (nfilename, filename);
      filename = nfilename;
    }
  return filename;
}

/* Construct a path to the given file name relative to the srcdir, if
   filename is relative.  */
const char *
resolve_source_filename (const char *filename)
{
  assert (srcdir);
  if (! IS_ABSOLUTE_PATH (filename))
    {
      char *nfilename = (char *) xmalloc (strlen (srcdir) + 1
					 + strlen (filename) + 1);
      strcpy (nfilename, srcdir);
      if (! IS_DIR_SEPARATOR (srcdir[strlen (srcdir) - 1])
	  && ! IS_DRIVE_SEPARATOR (srcdir[strlen (srcdir) - 1]))
	strcat (nfilename, "/");
      strcat (nfilename, filename);
      filename = nfilename;
    }
  return filename;
}

static char *
absolute_filename (const char *filename)
{
  static char *cwd = 0;
  static unsigned cwd_len = 0;
  static unsigned cwd_size = 0;
  char *abs_name;

  if (IS_ABSOLUTE_PATH (filename))
    return strdup (filename);

  if (cwd == 0)
    {
      int rc;
      do
	{
	  cwd_size += 128;
	  cwd = xrealloc (cwd, cwd_size);
	}
      while (! getcwd (cwd, cwd_size));
      cwd_len = strlen (cwd);
    }

  abs_name = xmalloc (cwd_len + 1 + strlen (filename) + 1);
  strcpy (abs_name, cwd);
  strcat (abs_name, "/");
  strcat (abs_name, filename);

  return abs_name;
}


static void
push_node (const char *id)
{
  Node *n;
  if (currentcfg == 0)
    {
      currentcfg = (Node *) xcalloc (sizeof (struct Node), 1);
      currentcfg->id = id;
    }

  for (n = currentcfg->sub; n; n = n->next)
    if (strcasecmp (n->id, id) == 0)
      {
	currentcfg = n;
	return;
      }
  n = (Node *) xcalloc (sizeof (struct Node), 1);
  n->id = strdup (id);
  n->up = currentcfg;
  n->filename = n->id;
  n->lineno = 1;
  if (currentcfg->sub)
    {
      Node *s;
      for (s = currentcfg->sub; s->next; s = s->next);
      s->next = n;
    }
  else
    currentcfg->sub = n;
  currentcfg = n;
}

static void
pop_node ()
{
  assert (currentcfg != NULL);
  currentcfg = currentcfg->up;
}

static void
dump (FILE *f, Node *c)
{
  static int indent = 0;
  while (c)
    {
      if (indent)
	fprintf (f, "%*c", indent, ' ');
      fprintf (f, "%s", c->id);
      switch (c->type)
	{
	case N_WORD:
	  fprintf (f, " = %s;\n", c->val);
	  break;
	case N_QSTR:
	  fprintf (f, " = \"%s\";\n", c->val);
	  break;
	case N_NUM:
	  if (c->ival >= 0x1000 && !(c->ival & 0xfff))
	    fprintf (f, " = 0x%lX;\n", c->ival);
	  else
	    fprintf (f, " = %lu;\n", c->ival);
	  break;
	case N_SUB:
	  if (c->val)
	    fprintf (f, " [%s]", c->val);
	  fprintf (f, " {\n");
	  indent += 4;
	  dump (f, c->sub);
	  indent -= 4;
	  if (indent)
	    fprintf (f, "%*c", indent, ' ');
	  fprintf (f, "};\n");
	}
      if (strcmp (c->id, "ACDB") == 0 && ! nobuild)
	{
	  /* Skip the CGEN_DEFINE and SIM optionally added by
	     process_arcadia_files after ACDB */
	  c = c->next;
	  if (c && c->id && strcmp (c->id, "CGEN_DEFINE") == 0)
	    c = c->next;
	  if (c && c->id && strcmp (c->id, "SIM") == 0)
	    c = c->next;
	}
      else
	c = c->next;
    }
}

/**********************************************************************/

Node *
find_sub (Node *parent, ...)
{
  va_list ap;
  Node *rv = parent;

  va_start (ap, parent);
  while (1)
    {
      char *id = va_arg (ap, char *);
      if (id == 0)
	return rv;
      rv = parent->sub;
      while (rv && strcasecmp (rv->id, id) != 0)
	rv = rv->next;
      if (!rv)
	return 0;
      parent = rv;
    }
}

Node *
find_typed_sub (Node *parent, int type, ...)
{
  va_list ap;
  Node *rv = parent;
  char *last_id;

  va_start (ap, type);
  while (1)
    {
      char *id = va_arg (ap, char *);
      if (id == 0)
	{
	  while (rv && (strcasecmp (rv->id, last_id) != 0 || rv->type != type))
	    rv = rv->next;
	  return rv;
	}
      last_id = id;
      rv = parent->sub;
      while (rv && strcasecmp (rv->id, id) != 0)
	rv = rv->next;
      if (!rv)
	return 0;
      parent = rv;
    }
}

Node *
find_next (Node *current, const char *id)
{
  assert (current);
  for (current = current->next; current; current = current->next)
    {
      assert (current->id);
      if (strcasecmp (current->id, id) == 0)
	break;
    }
  return current;
}

/**********************************************************************/

/* Pass pointer to the ME_MODULE subnode */
static int
core_opt_set (Node *n, const char *opt)
{
  Node *o = find_sub (n, "me_engine", "core", opt, 0);
  if (!o || !o->val || strcmp (o->val, "ON") != 0)
    return 0;
  return 1;
}

/* Likewise.  */
static int
cop_vliw_bits (Node *modules)
{
  int vliw_bits = 0;
  Node *item, *vbits, *vtype;

  item = find_sub (modules, "cop", 0);
  if (item)
    {
      vtype = find_sub (item, "vliw_type", 0);
      if (vtype && vtype->val && strcmp (vtype->val, "YES") == 0)
	{
	  vliw_bits = 32;
	  vbits = find_sub (item, "vliw_bitw", 0);
	  if (vbits)
	    vliw_bits = vbits->ival;
	}
    }
  return vliw_bits;
}

static int
cop_data_bus_width (Node *modules)
{
  int bus_width = 0;
  Node *item;

  item = find_sub (modules, "cop", 0);
  if (item)
    {
      item = find_sub (item, "data_bus_width", 0);
      if (item)
	bus_width = item->ival;
    }
  return bus_width;
}

static int
timer_channel_bitw (Node *module)
{
  Node *item;

  item = find_sub (module, "me_engine", "timer", 0);
  if (! item)
    return 0;

  Node *bitw = find_sub (item, "channel_bitw", 0);
  if (bitw)
    return bitw->ival;

  /* Default is 1 channel */
  return 1; 
}

static int
dmac_channel_bitw (Node *module)
{
  Node *item;

  item = find_sub (module, "dmac", 0);
  if (! item)
    return 0;

  Node *bitw = find_sub (item, "channel_bitw", 0);
  if (bitw)
    return bitw->ival;

  /* Default is 1 channel */
  return 1; 
}

/**********************************************************************/

static FILE *src_file;
static FILE *dst_file;
static char *src_name;
static char *tmp_name;
static const char *template_name;
static char line[10000];

static void
mkdir_p (char *path)
{
  struct stat s;
  char *ls;

  if (stat (path, &s) == 0)
    return;
  if (mkdir (path, 0777) == 0)
    return;
  ls = strrchr (path, '/');
  if (!ls || errno != ENOENT)
    {
      error ("cannot make directory %s", path);
      perror ("The error was");
      exit (EXIT_FAILURE);
    }
  *ls = 0;
  mkdir_p (path);
  *ls = '/';
  if (mkdir (path, 0777) != 0)
    {
      error ("cannot make directory %s", path);
      perror ("The error was");
      exit (EXIT_FAILURE);
    }
}

static void
start_file (const char *basedir, char *filename, const char *template_filename)
{
  char *nfilename = 0;

  if (! template_filename)
    template_filename = filename;

  if (basedir)
    {
      if (!IS_ABSOLUTE_PATH (template_filename))
	template_filename = concat (basedir, "/", template_filename, NULL);

      if (!IS_ABSOLUTE_PATH (filename))
	filename = concat (basedir, "/", filename, NULL);
    }

  if (testing)
    {
      printf ("======== %s from %s\n", filename, template_filename);
      dst_file = stdout;
      return;
    }

  src_name = filename;
  tmp_name = (char *) xmalloc (strlen (src_name) + 5);
  sprintf (tmp_name, "%s.tmp", src_name);
  template_name = template_filename;
  src_file = fopen (template_name, "r");
  if (!src_file)
    {
      if (errno == ENOENT)
	{
	  /* Create a new file in this spot. */
	  tmp_name = src_name;
	}
      else
	{
	  fprintf (stderr, "Unable to open file %s for reading\n", template_filename);
	  perror ("The error was");
	  exit (EXIT_FAILURE);
	}
    }
  dst_file = fopen (tmp_name, "w");
  if (!dst_file)
    {
      fprintf (stderr, "Unable to open file %s for writing\n", tmp_name);
      perror ("The error was");
      exit (EXIT_FAILURE);
    }
}


#define LINKER_SCRIPT_PATH "libgloss/mep"
#define LINKER_SCRIPT_PATH_LEN 12
#define LINKER_SCRIPT_DEFAULT "gmap_default.ld"

static const char *linker_script_path = "libgloss/mep/";
static const char *linker_script_default = "gmap_default.ld";

static char *linker_scripts = NULL;
static unsigned linker_scripts_len = 0;
static unsigned linker_scripts_size = 0;

static void
start_linker_script (const char *basedir, const char *modname)
{
  char *filename;
  const char *template;
  int modlen;

  filename = concat (linker_script_path, modname, ".ld", NULL);

  if (IS_ABSOLUTE_PATH (linker_script_default))
    template = linker_script_default;
  else
    template = concat (linker_script_path, linker_script_default, NULL);

  /* Add this script to the list of generated scripts.  */
  modlen = strlen (modname);
  if (linker_scripts_len + 1 + modlen + 3 + 1 > linker_scripts_size)
    {
      linker_scripts_size += 1 + modlen + 3 + 1 + 100;
      linker_scripts = xrealloc (linker_scripts, linker_scripts_size);
      assert (linker_scripts != NULL);
    }
  sprintf (linker_scripts + linker_scripts_len, " %s.ld", modname);
  linker_scripts_len += 1 + modlen + 3;
      
  start_file (basedir, filename, template);
}

static int
have_sdram ()
{
  Gmap *g;

   for (g = currentgmap; g; g = g->next)
     if (strstr (g->name, "SDRAM")
	 &&  g->start == 0x800000 && g->size >= 0xb8)
       return 1;
   return 0;
}


static int
read_line ()
{
  if (! src_file)
    return 0;

  if (! ferror (src_file) && fgets (line, sizeof (line), src_file))
    return 1;

  if (! feof (src_file))
    {
      fprintf (stderr, "Error: Cannot read file %s\n", template_name);
      exit (EXIT_FAILURE);
    }
  return 0;
}

static int
find_line (char *contains, int keep_others, int keep_this, int exit_on_error)
{
  if (testing)
    {
      printf (">>>>>>>> %s\n", contains ? contains : "(null)");
      return 0; /* not found */
    }

  while (read_line ())
    {
      if (contains && strstr (line, contains))
	{
	  if (keep_this)
	    fputs (line, dst_file);
	  return 1; /* found */
	}
      if (keep_others)
	fputs (line, dst_file);
    }
  if (contains && exit_on_error)
    {
      fprintf (stderr, "Error: Cannot find line `%s' in %s\n", contains, template_name);
      exit (EXIT_FAILURE);
    }
  return 0; /* not found */
}

static int
files_differ (char *n1, char *n2)
{
  FILE *f1;
  FILE *f2;
  int c1, c2;

  if (strcmp (n1, n2) == 0)
    return 0;

  f1 = fopen (n1, "r");
  f2 = fopen (n2, "r");
  if (!f1)
    {
      if (f2)
	fclose (f2);
      perror (n1);
      exit (EXIT_FAILURE);
    }
  if (!f2)
    {
      fclose (f1);
      perror (n2);
      exit (EXIT_FAILURE);
    }

  while (1)
    {
      c1 = fgetc (f1);
      c2 = fgetc (f2);
      if (c1 != c2)
	{
	  fclose (f1);
	  fclose (f2);
	  return 1;
	}
      if (c1 == EOF)
	{
	  fclose (f1);
	  fclose (f2);
	  return 0;
	}
    }
}

static int
end_file ()
{
  char *save_name = NULL;
  struct stat st;

  if (testing)
    {
      printf ("\n");
      dst_file = NULL;
      return 0; /* file not changed */
    }

  if (src_file == NULL)
    {
      num_files_changed ++;
      if (verbose)
	fprintf (stderr, "Created       %s\n", src_name);
      fclose (dst_file);
      dst_file = NULL;
      return 1; /* file changed */
    }

  find_line (0, 1, 1, 1);
  fclose (src_file);
  fclose (dst_file);
  src_file = dst_file = NULL;

  if (stat (src_name, &st) < 0)
    {
      num_files_changed ++;
      if (verbose)
	fprintf (stderr, "Created       %s\n", src_name);
    }
  else if (! files_differ (src_name, tmp_name))
    {
      if (verbose)
	fprintf (stderr, "No changes to %s\n", src_name);
      remove (tmp_name);
      return 0; /* file not changed */
    }
  else
    {
      num_files_changed ++;
      if (verbose)
	fprintf (stderr, "Updated       %s\n", src_name);

      save_name = (char *) xmalloc (strlen (src_name) + 6);
      strcpy (save_name, src_name);
      strcat (save_name, ".save");

      if (rename (src_name, save_name) < 0)
	{
	  fprintf (stderr, "Error: unable to rename %s to %s\n",
		   src_name, save_name);
	  perror ("The error was");
	  exit (EXIT_FAILURE);
	}
    }

  if (rename (tmp_name, src_name) < 0)
    {
      fprintf (stderr, "Error: unable to rename %s to %s\n",
	       tmp_name, src_name);
      perror ("The error was");
      rename (save_name, src_name);
      exit (EXIT_FAILURE);
    }

  if (save_name)
    remove (save_name);

  return 1; /* file changed */
}


/*
 *-------------------------------------------------------------------------------
 *
 *  add_node 
 *
 *  expects:  current - pointer to the node where the new node is to be added.
 *            id - the null terminated character string that identifies the node.
 *            val - the null terminated character string value for the node (or 0).
 *            ival - the integer value for the node (or 0).
 *  returns:  n - a Node pointer which references the new node.
 *  description:
 *
 *  create a new node, populate it with the values provided, and add it to the 
 *  tail (after the last node) of the sub tree of the current node.
 *
 *-------------------------------------------------------------------------------
 */

static Node *
add_node(Node *current, char *id, char* val, int type, int ival,
	 const char *filename, int lineno)
{

  Node *n;

  n = (Node *) xmalloc (sizeof (Node));
  n->id = strdup (id);
  n->val = val;
  n->type = type;
  n->ival = ival;
  n->sub = 0;
  n->up = current;
  n->next = current->next;
  n->filename = filename;
  n->lineno = lineno;
  current->next = n;

  return (n);

}


static void
check_cmodel_irq (CModel *cmodel, Node *module)
{
  Node *irq;

  assert (module);
  if (! cmodel)
    return;

  /* If IRQ is specified in the module, then ignore any int_channel specified
     in the cmodel.  */
  if (cmodel->num_ints == 0)
    return;

  irq = find_sub (module, "irq", 0);
  if (! irq)
    return;

  warn ("Ignoring int_channel because IRQ was specified in ME_MODULE %s",
	module->val);
  cmodel->num_ints = 0;
}

static void
check_cmodel_lbus_if (CModel *cmodel, Node *engine)
{
  Node *lbus_if;

  assert (engine);
  if (! cmodel)
    return;

  if (! cmodel->mapped_region_name)
    return;

  /* Ignore mapped_region_name specified in the cmodel of a UCI.  */
  if (cmodel->type == cmTypeUci)
    {
      warn ("Ignoring mapped_region_name specified in UCI model %s",
	    cmodel->instance_name);
      cmodel->mapped_region_name = 0;
      return;
    }

  /* If LBUS_IF is specified in the engine, then ignore any mapped_region_name
     specified in the cmodel.  */
  lbus_if = find_sub (engine, "lbus_if", 0);
  if (lbus_if && strcmp (lbus_if->val, "ON") == 0)
    return;

  warn ("Ignoring mapped_region_name because LBUS_IF is ON in %s %s",
	cmodel->type == cmTypeHWengine ? "HW_ENGINE" : "DSP",
	engine->val);
  cmodel->mapped_region_name = 0;
}

static void
check_cmodel_rtl (CModel *cmodel)
{
  assert (cmodel);

  /* Only "SystemC" or "VerilogRTL" may be specified for rtl_model_type.  */
  assert (cmodel->rtl_model_type);
  if (strcmp (cmodel->rtl_model_type, "SystemC") != 0
      && strcmp (cmodel->rtl_model_type, "VerilogRTL") != 0)
    error ("rtl_model_type must be \"SystemC\" or \"VerilogRTL\"");

  /* No non-rtl specifications are allowed.  */
  if (cmodel->class_name)
    error ("class_name not allowed when rtl_model_type has been specified");
  if (cmodel->argc)
    error ("argc not allowed when rtl_model_type has been specified");
  if (cmodel->base_dir)
    error ("base_dir not allowed when rtl_model_type has been specified");
  if (cmodel->include_file)
    error ("include_file not allowed when rtl_model_type has been specified");
  if (cmodel->lib_file)
    error ("lib_file not allowed when rtl_model_type has been specified");
  if (cmodel->cppflags)
    error ("cppflags not allowed when rtl_model_type has been specified");
  if (cmodel->num_files)
    error ("files not allowed when rtl_model_type has been specified");
  if (cmodel->num_ints)
    error ("int_channel not allowed when rtl_model_type has been specified");
  if (cmodel->mapped_region_name)
    error ("mapped_region_name not allowed when rtl_model_type has been specified");
}

static void
check_cmodel_no_rtl (CModel *cmodel)
{
  assert (cmodel);
  assert (! cmodel->rtl_model_type);

  /* No rtl_* specs are allowed.  */
  if (cmodel->rtl_module_name)
    error ("rtl_module_name not allowed when rtl_model_type has not been specified");
  if (cmodel->num_rtl_files)
    error ("rtl_files not allowed when rtl_model_type has not been specified");
  if (cmodel->rtl_base_dir)
    error ("rtl_base_dir not allowed when rtl_model_type has not been specified");
  if (cmodel->rtl_include_file)
    error ("rtl_include_file not allowed when rtl_model_type has not been specified");

  if (! cmodel->class_name)
    error ("class_name must be specified when rtl_model_type has not been specified");
}

static CModel *
verify_cmodel (CModel *cmodel, Node *component, Node *module)
{
  assert (cmodel);

  /* If the rtl_model_type is specified, then this cmodel is assumed to be for
     co-simulation.  */
  if (cmodel->rtl_model_type)
    {
      check_cmodel_rtl (cmodel);
      return NULL; /* cmodel to be checked but ignored.  */
    }

  check_cmodel_no_rtl (cmodel);

  /* Specific checks for different cmodel types.  */
  switch (cmodel->type)
    {
    case cmTypeHWengine:
    case cmTypeDsp:
      assert (module);
      check_cmodel_irq (cmodel, module);
      check_cmodel_lbus_if (cmodel, component);
      break;
    case cmTypeUci:
      check_cmodel_lbus_if (cmodel, component);
      break;
    default:
      break;
    }

  /* Set some defaults.  */
  if (! cmodel->argc)
    cmodel->argc = 1;

  return cmodel;
}

/* Parse a cmodel_info file for a uci/dsp/hw_engine/peripheral.  Take the
   file name from the given Node, which should be a SIM node.  */
static CModel*
parse_cmodel (Node *cmodel_node, CmodelType type, Node *component, Node *module)
{
  enum context save_context;
  CModel *thiscmodel = NULL;

  assert (toshapi != 0);

  cmodelfilename = NULL;
  cmodeldebug = (verbose > 3);

  assert (cmodel_node && cmodel_node->val);

  cmodelfilename = resolve_local_filename (cmodel_node->val);
  cmodelin = fopen (cmodelfilename, "r");
  if (! cmodelin)
    {
      fprintf (stderr, "cannot open cmodel file %s\n", cmodelfilename);
      exit (EXIT_FAILURE);
    }
  fl_context = fl_cmodel;
  cmodelparse ();
  if (errors)
    exit (EXIT_FAILURE);
  if (! currentcmodel)
    {
      fprintf (stderr, "parse error in cmodel file %s\n", cmodelfilename);
      exit (EXIT_FAILURE);
    }
  fclose (cmodelin);
  cmodelin = NULL;

  if (errors)
    exit (EXIT_FAILURE);

  thiscmodel = currentcmodel;

  if (verbose)
    fprintf (stderr, "parsed cmodel file %s OK\n", cmodelfilename);

  /* Verify the cmodel.  Return NULL if it can't be used.  */
  save_context = fl_context;
  fl_context = fl_none;
  thiscmodel = verify_cmodel (thiscmodel, component, module);
  fl_context = save_context;

  if (errors)
    exit (EXIT_FAILURE);
  if (! thiscmodel)
    return NULL;

  /* Postprocess thiscmodel.
     We want the base_dir to be relative to the cmodel_node->val.  */
  if (thiscmodel->base_dir == NULL || ! IS_ABSOLUTE_PATH (thiscmodel->base_dir))
    {
      char fn [1024];
      unsigned fn_length;
      char *dirend;

      /* Identify the final directory separator. One which terminates the filename
	 does not count.  */
      fn_length = strlen (cmodel_node->val);
      memcpy (fn, cmodel_node->val, fn_length + 1);
      dirend = fn + fn_length - 1;
      if (IS_DIR_SEPARATOR (*dirend) && dirend > fn)
	--dirend;
      for (/**/; dirend > fn; --dirend)
	if (IS_DIR_SEPARATOR (*dirend) || IS_DRIVE_SEPARATOR (*dirend))
	  break;

      /* Check to see whether we found a separator.  */
      if (dirend == fn && ! IS_DIR_SEPARATOR (*dirend))
	dirend = NULL;

      /* Append the base_dir to the relative directory, if any.  */
      if (dirend != NULL)
	{
	  *(dirend + 1) = '\0';
	  if (thiscmodel->base_dir != NULL)
	    strcat (fn, thiscmodel->base_dir);
	  thiscmodel->base_dir = strdup (fn);

	  if (verbose > 1)
	    fprintf (stderr, "setting cmodel base_dir to `%s'\n",
		     thiscmodel->base_dir);
	}
    }

  /* Make sure the base_dir ends with a path separator.  */
  if (thiscmodel->base_dir != NULL
      && ! IS_DIR_SEPARATOR (thiscmodel->base_dir[strlen (thiscmodel->base_dir) - 1])
      && ! IS_DRIVE_SEPARATOR (thiscmodel->base_dir[strlen (thiscmodel->base_dir) - 1]))
    {
      char fn [1024];
      sprintf (fn, "%s/", thiscmodel->base_dir);
      thiscmodel->base_dir = strdup (fn);
    }

  thiscmodel->type = type;
  thiscmodel->instance_name = component->val;
  return thiscmodel;
}

/*----------------------------------------------------------------------*/

/* Create a temporary filename to store the converted ACD file.
   We drop any .acd suffix, and add .#.cpu where # is 1..N.  */
static char *
cpu_fname_from_arcadia_fname (const char *fname, int module_num, const char *suffix)
{
  const char *s;
  char *cpu_fname, *d;
  int flen;

  flen = strlen(fname);
  cpu_fname = (char *) xmalloc (flen + 5 + 20);
  for (s=fname, d=cpu_fname; *s; s++)
    {
      if (*s == '/' || *s == '\\')
	d = cpu_fname;
      else
	*d++ = *s;
    }
  *d = *s;
  if (d-cpu_fname > 4 && strcasecmp (d-4, ".acd") == 0)
    d -= 4;
  sprintf(d, ".%d.%s", module_num, suffix);
  return cpu_fname;
}

/* Locate a usable a2cgen program.  We let the user override by
   specifying the A2CGEN environment variable.  The next choice is the
   same directory as this program.  Failing that, search the path.  */
static char *
find_a2cgen (void)
{
  char *e, *d;
  const char *s;
  static char *buf;

  /* See if the user specified it.  */
  e = getenv ("A2CGEN");
  if (e && access (e, X_OK) == 0)
    return e;

  /* Try the same directory as this program.  */
  buf = (char *) xmalloc (strlen(main_argv0) + strlen("a2cgen") + 2);
  e = 0;
  d = buf;
  for (s=main_argv0; *s; s++)
    {
      *d++ = *s;
      if (*s == '/' || *s == '\\')
	e = d;
    }
  if (e == 0)
    e = buf;
  strcpy (e, "a2cgen");
  if (access (buf, X_OK) == 0)
    return buf;

  /* Hope it's on the path.  */
  return "a2cgen";
}

/*----------------------------------------------------------------------*/


static struct {
  const char *opt;
  const char *ifon;
  const char *ifoff;
} cc_opt_map[] = {
  /* This table is used twice.  do_config_cc_spec skips the first
     two entries, and generate_compiler_script uses them all.  */
  {"mul",    " -mmult",    " -mno-mult"},
  {"div",    " -mdiv",     " -mno-div"},

  {"bit",    " -mbitops",  " -mno-bitops"},
  {"ldz",    " -mleadz",   " -mno-leadz"},
  {"abs",    " -mabsdiff", " -mno-absdiff"},
  {"ave",    " -maverage", " -mno-average"},
  {"min",    " -mminmax",  " -mno-minmax"},
  {"clp",    " -mclip",    " -mno-clip"},
  {"sat",    " -msatur",   " -mno-satur"},

  {0, 0, 0}
};

static void
do_config_cc_spec ()
{
  Node *cfgs, *modules, *cop, *ip;
  int i;

  find_line ("#define CONFIG_CC_SPEC", 1, 0, 1);
  fprintf (dst_file, "#define CONFIG_CC_SPEC \"\\\n");

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, "%%{mconfig=%s:", modules->val);
	  /* Note: this is where we skip the first two entries of cc_opt_map.  */
	  for (i = 2; cc_opt_map[i].opt; i++)
	    if (core_opt_set (modules, cc_opt_map[i].opt))
	      fprintf (dst_file, cc_opt_map[i].ifon);
	  switch (cop_vliw_bits (modules))
	    {
	    case 0:
	      fprintf (dst_file, " %%{!mvliw:-mno-vliw}");
	      break;
	    case 32:
	      fprintf (dst_file, " -mvl32 -mvliw");
	      break;
	    case 64:
	      fprintf (dst_file, " -mvl64 -mvliw");
	      break;
	    }
	  cop = find_sub (modules, "cop", 0);
	  if (cop)
	    {
	      int width = cop_data_bus_width (modules);
	      switch (width)
		{
		case 0:
		default:
		  width = 32;
		  fprintf (dst_file, " -mcop");
		  break;
		case 32:
		  fprintf (dst_file, " -mcop32");
		  break;
		case 64:
		  fprintf (dst_file, " -mcop64");
		  break;
		}
	      fprintf (dst_file, " -D__MEP_CONFIG_CP_DATA_BUS_WIDTH=%d", width);
	    }
	  else
	    fprintf (dst_file, " %%{mcop*:-mno-cop}");
	  
	  ip = find_sub (modules, "cop", "ip", 0);
	  if (ip && ip->val && strcmp (downcase (ip->val), "fmax") == 0)
	    fprintf (dst_file, " -mfmax");
	  fprintf (dst_file, "}\\\n");
	}
    }

  fprintf (dst_file, "%%{!mconfig*:%%nwarning: Missing -mconfig option}\\\n");
  fprintf (dst_file, "\"\n");
  find_line ("/* end-config-cc-spec */", 0, 1, 1);
}

static void
do_config_link_spec ()
{
  Node *cfgs, *modules;

  find_line ("#define CONFIG_LINK_SPEC", 1, 0, 1);
  fprintf (dst_file, "#define CONFIG_LINK_SPEC \"\\\n");

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  
	  fprintf (dst_file, "%%{mconfig=%s:", modules->val);
	  fprintf (dst_file, " %%{!T*:-T%s.ld}", modules->val);
	  fprintf (dst_file, "}\\\n");
	}
    }

  fprintf (dst_file, "\"\n");
  find_line ("/* end-config-link-spec */", 0, 1, 1);
}

static void
do_config_start_spec ()
{
  find_line ("#define CONFIG_START_SPEC", 1, 0, 1);
  fprintf (dst_file, "#define CONFIG_START_SPEC \"\\\n");
 
  if (have_sdram ())
    {
      fprintf (dst_file, "%%{!msdram:%%{!mno-sdram:%%{!msim*:sdram-crt0.o%%s}}} \\\n");
      fprintf (dst_file, "%%{!msdram:%%{!mno-sdram:%%{msim:simsdram-crt0.o%%s}}} \\\n");
    }
  else
    {
      fprintf (dst_file, "%%{!msdram:%%{!mno-sdram:%%{!msim*:crt0.o%%s}}} \\\n");
      fprintf (dst_file, "%%{!msdram:%%{!mno-sdram:%%{msim:sim-crt0.o%%s}}} \\\n");
    }

  fprintf (dst_file, "\"\n");
  find_line ("/* end-config-start-spec */", 0, 1, 1);
}

static void
do_gcc_target_h1_selection ()
{
  find_line ("#define TARGET_H1", 1, 0, 1);
  fprintf (dst_file, "#define TARGET_H1\t\t%d\n",
	   mep_core_type == MEP_CORE_H1);
}

static void
do_config_driver_option ()
{
  Node *cfgs, *modules;
  unsigned cfgnum=0;

  find_line ("start-target-option-table", 1, 1, 1);

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  int mult = core_opt_set (modules, "mul");
	  int div = core_opt_set (modules, "div");
	  Node *ip = find_sub (modules, "cop", "ip", 0);
	  
	  cfgnum ++;
	  fprintf (dst_file, ", {\"-mconfig=%s\", \"-mconfig=%s",
		   modules->val, modules->val);
	  if (mult)
	    fprintf (dst_file, " -mmult");
	  if (div)
	    fprintf (dst_file, " -mdiv");
	  if (ip && ip->val && strcmp (downcase (ip->val), "fmax") == 0)
	    fprintf (dst_file, " -mfmax-abi");
	  fprintf (dst_file, " -D__MEP_CONFIG_ISA=%d", cfgnum);
	  fprintf (dst_file, "\" } \\\n");
	}
    }

  find_line ("end-target-option-table", 0, 1, 1);

  find_line ("#define DEFAULT_ENDIAN_SPEC", 1, 0, 1);
  fprintf (dst_file, "#define DEFAULT_ENDIAN_SPEC \"%s\"\n",
	   mep_endian_type == MEP_ENDIAN_LITTLE
	   ? "%{!meb: -mel}"
	   : "%{!mel: -meb}");
}

static void
do_config_library_spec (void)
{
  Node *cfgs, *modules, *ip;
  const char *config_name;

  find_line ("LIBRARY_CONFIG_SPEC", 1, 0, 1);
  fprintf (dst_file, "#define LIBRARY_CONFIG_SPEC \"");
  config_name = 0;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    for (modules = find_sub (cfgs, "me_module", 0);
	 modules;
	 modules = find_next (modules, "me_module"))
      {
	config_name = modules->val;
	ip = find_sub (modules, "cop", "ip", 0);
	if (ip && ip->val && strcmp (downcase (ip->val), "fmax") == 0)
	  {
	    fprintf (dst_file, "%%{mfmax-abi:-mfmax} ");
	    goto done;
	  }
      }
 done:
  if (config_name)
    fprintf (dst_file, "-mconfig=%s", config_name);
  fprintf (dst_file, "\"\n");
}

static void
do_gcc_isas ()
{
  Node *cfgs, *modules;
  char prefix;
  int i;

  find_line ("begin-isas", 1, 1, 1);

  fputs ("MEP_CORE =", dst_file);
  prefix = ' ';
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, "%cext_core%d", prefix, i);
	  prefix = ',';
	  ++i;
	}
    }
  fputc ('\n', dst_file);

  fputs ("MEP_COPRO =", dst_file);
  prefix = ' ';
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  if (find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, "%cext_cop%d_16,ext_cop%d_32,ext_cop%d_48,ext_cop%d_64", prefix, i, i, i, i);
	      prefix = ',';
	    }
	  ++i;
	}
    }
  fputc ('\n', dst_file);

  find_line ("end-isas", 0, 1, 1);
}

static void
do_extra_headers ()
{
  struct header_s *h;

  find_line ("start-extra-headers", 1, 1, 1);

  fprintf (dst_file, "EXTRA_HEADERS = $(srcdir)/config/mep/intrinsics.h \\\n");
  fprintf (dst_file, "\t$(srcdir)/config/mep/stdint.h");

  for (h=the_headers; h; h=h->next)
    fprintf (dst_file, " \\\n\t$(srcdir)/config/mep/%s.h", h->header);
  fprintf (dst_file, "\n");

  find_line ("end-extra-headers", 0, 1, 1);
}

static void
do_config_coproc_selection ()
{
  Node *cfgs, *modules;
  int ext_isa = 1;
  const char *header = "#define COPROC_SELECTION_TABLE";

  find_line ("start-coproc-selection-table", 1, 1, 1);

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, "%s \\\n{\"%s\", ISA_EXT%d}",
		   header, modules->val, ext_isa++);
	  header = ",";
	}
    }
  fprintf (dst_file, "\n");

  find_line ("end-coproc-selection-table", 0, 1, 1);
}

static void
generate_define_isa (int num, const char *name_fmt, const char* comment_frag)
{
  fputs ("(define-isa\n  (name ", dst_file);
  fprintf (dst_file, name_fmt, num);
  fprintf (dst_file, ")\n\
  (comment \"MeP %s instruction set\")\n\
  (default-insn-word-bitsize 32)\n\
  (default-insn-bitsize 32)\n\
  (base-insn-bitsize 32)\n\
)\n\n", comment_frag);
}

static void
do_cpu_config ()
{
  Node *cfgs, *modules;
  int i;

  find_line ("begin-isa-enum", 1, 1, 1);

  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, "\text_core%d", i);
	  if (find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, " ext_cop%d_16 ext_cop%d_32 ext_cop%d_48 ext_cop%d_64",
		       i, i, i, i);
	    }
	  fputc ('\n', dst_file);
	  ++i;
	}
    }

  find_line ("end-isa-enum", 0, 1, 1);

  find_line ("begin-isas", 1, 1, 1);

  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  generate_define_isa (i, "ext_core%d", "core extension");
	  if (find_sub (modules, "cop", 0))
	    {
	      generate_define_isa (i, "ext_cop%d_16", "coprocessor");
	      generate_define_isa (i, "ext_cop%d_32", "coprocessor");
	      generate_define_isa (i, "ext_cop%d_48", "coprocessor");
	      generate_define_isa (i, "ext_cop%d_64", "coprocessor");
	    }
	  ++i;
	}
    }
  fputs ("(define-pmacro all-mep-isas () (ISA mep", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, ",ext_core%d", i);
	  if (find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, ",ext_cop%d_16,ext_cop%d_32,ext_cop%d_48,ext_cop%d_64",
		       i, i, i, i);
	    }
	  ++i;
	}
    }
  fputs ("))\n\n", dst_file);
  fputs ("(define-pmacro all-mep-core-isas () (ISA mep", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, ",ext_core%d", i);
	  ++i;
	}
    }
  fputs ("))\n\n", dst_file);
  fputs ("(define-pmacro all-core-isa-list () mep", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, ",ext_core%d", i);
	  ++i;
	}
    }
  fputs (")\n", dst_file);

  find_line ("end-isas", 0, 1, 1);

  find_line ("mach gets changed by MeP-Integrator", 1, 0, 1);
  fprintf (dst_file, "  (mach %s) ; mach gets changed by MeP-Integrator\n",
	   mep_mach_names[mep_core_type]);

  find_line ("begin-extra-csr-registers", 1, 1, 1);
  switch (mep_core_type)
    {
    case MEP_CORE_H1:
      fputs ("	    (vid 22) (bea 29) (tepc 30)\n", dst_file);
      break;
    case MEP_CORE_C3:
    case MEP_CORE_C4:
      fputs ("	    (vid 22)\n", dst_file);
      break;
    default:
      break;
    }
  find_line ("end-extra-csr-registers", 0, 1, 1);

  find_line ("config-attr-start", 1, 1, 1);

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	fprintf (dst_file, "\t%s\n", modules->val);
    }

  find_line ("config-attr-end", 0, 1, 1);

  find_line ("mep-h1.cpu", 1, 0, 1);
  if (mep_core_type != MEP_CORE_H1)
    fputs ("; ", dst_file);
  fputs ("(include \"mep-h1.cpu\") ; -- exposed by MeP-Integrator\n", dst_file);

  find_line ("begin non-mep-h1 reserved insns", 1, 1, 1);
  if (mep_core_type != MEP_CORE_H1)
    {
      fputs ("(dnri 16 MAJ_7   5)\n", dst_file);
      fputs ("(dnri 18 MAJ_7  12)\n", dst_file);
      fputs ("(dnri 19 MAJ_7  13)\n", dst_file);
    }
  find_line ("end non-mep-h1 reserved insns", 0, 1, 1);
}

void 
include_from (const char *filename, FILE *dest)
{
  size_t c;
  FILE *incl;
  char buf [1024];

  /* Try first the given filename, unresolved.  */
  incl = fopen (filename, "r");
  if (! incl)
    {
      filename = resolve_local_filename (filename);
      incl = fopen (filename, "r");
    }

  if (! incl)
    {
      fprintf (stderr, "%s: ", filename);
      perror ("fopen");
      return;
    }
  
  while (! feof (incl))
    {
      c = fread (buf, 1, 1024, incl);
      if ((c == 0) && ferror (incl))
	{
	  perror ("fread");
	  goto end;
	}
      if ((c != fwrite (buf, 1, c, dest)) && ferror (dest))
	{
	  perror ("fwrite");
	  goto end;
	}
    }

 end:
  fclose (incl);
  return;
}

/* Return non zero if the class repreneting the given cmodel is the
   same as the class used by another cmodel priori to it in the
   list of cmodels.  */
static int
cmodel_class_is_duplicate (const CModel *m)
{
  const CModel *cm;
  for (cm = currentcmodel; cm != m; cm = cm->prev)
    {
      assert (cm != NULL);
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      if (strcmp (m->class_name, cm->class_name) == 0)
	return 1; /* duplicate */
    }

  return 0; /* not duplicate */
}


/* See if this is Makefile.in and, if so, which version of automake created it. */
static enum automake_version
get_automake_version (const char *makefile)
{
  enum automake_version automake_version = AM_NONE;
  if (read_line ())
    {
      fputs (line, dst_file);
      if (strncmp (line, "# Makefile.in", 13) == 0)
	{
	  const char *version = strstr (line, "automake ");
	  assert (version);
	  version += 9;
	  if (strncmp (version, "1.4", 3) == 0)
	    automake_version = AM_1_4;
	  else if (strncmp (version, "1.9.5", 5) == 0)
	    automake_version = AM_1_9_5;
	  else
	    {
	      char *space = strchr (version, ' ');
	      if (space)
		*space = '\0';
	      error ("%s was generated by an unsupported version of automake: %s\n",
		     makefile, version);
	    }
	}
    }
  return automake_version;
}


/* Make config changes to Makefile.{am,in} in sid/component/families/mep.  */
static void
do_toshmep_Makefile_config (char *makefile)
{
  const CModel *cm;
  int i;
  const char *suffix;
  enum automake_version automake_version;

  start_file (srcdir, makefile, 0);

  /* See if this is Makefile.in and, if so, which version of automake created it. */
  automake_version = get_automake_version (makefile);

  /* Do config specific to Makefile.in, if that's the file we're working on.  */
  if (automake_version == AM_1_9_5)
    {
      find_line ("libmepfamily_la_OBJECTS = $(am_libmepfamily_la_OBJECTS)", 1, 0, 1);
      fputs ("libmepfamily_la_OBJECTS = $(am_libmepfamily_la_OBJECTS)", dst_file);
      for (cm = currentcmodel; cm != NULL; cm = cm->prev)
	{
	  /* Ignore rtl cmodels.  */
	  if (cm->rtl_model_type)
	    continue;
	  /* Don't include the same class definition twice.  */
	  if (cmodel_class_is_duplicate (cm))
	    continue;

	  /* Include all the listed model object files.  */
	  for (i=0; i<cm->num_files; i++)
	    {
	      /* Paste only objects of .cc/.cxx files.  */
	      if ((suffix = strstr (cm->files[i], ".cc")) ||
		  (suffix = strstr (cm->files[i], ".cxx")))
		fprintf (dst_file, " %.*s.lo", suffix - cm->files[i], cm->files[i]);
	    }
	}
      fputc ('\n', dst_file);
    }

  find_line ("TOSHAPI_SOURCES", 1, 0, 1);
  fputs ("TOSHAPI_SOURCES =", dst_file);
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      /* Don't include the same class definition twice.  */
      if (cmodel_class_is_duplicate (cm))
	continue;

      /* Include all the listed model source files.  */
      for (i=0; i<cm->num_files; i++)
	{
	  const char *suffix;
	  /* Paste only .cc/.cxx files.  */
	  if ((suffix = strstr (cm->files[i], ".cc")) ||
	      (suffix = strstr (cm->files[i], ".cxx")))
	    fprintf (dst_file, " %.*s.cxx", suffix - cm->files[i], cm->files[i]);
	  else if (! strstr (cm->files[i], ".h"))
	    {
	      fprintf (stderr, "warning: ignored unknown sim file extension `%s'\n",
		       cm->files[i]);
	    }
	}
    }
  fputc ('\n', dst_file);

  /* Do config specific to Makefile.in, if that's the file we're working on.  */
  if (automake_version != AM_NONE)
    {
      if (automake_version == AM_1_4)
	{
	  find_line ("libmepfamily_la_OBJECTS", 1, 0, 1);
	  fputs ("libmepfamily_la_OBJECTS = dsu.lo dmac.lo intc.lo components.lo mm_int.lo timer.lo gbif.lo lbif.lo gbmif.lo \\\n", dst_file);
	  fputs ("toshapi.lo", dst_file);
	  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
	    {
	      /* Ignore rtl cmodels.  */
	      if (cm->rtl_model_type)
		continue;
	      /* Don't include the same class definition twice.  */
	      if (cmodel_class_is_duplicate (cm))
		continue;

	      /* Include all the listed model object files.  */
	      for (i=0; i<cm->num_files; i++)
		{
		  /* Paste only objects of .cc/.cxx files.  */
		  if ((suffix = strstr (cm->files[i], ".cc")) ||
		      (suffix = strstr (cm->files[i], ".cxx")))
		    fprintf (dst_file, " %.*s.lo", suffix - cm->files[i], cm->files[i]);
		}
	    }
	  fputc ('\n', dst_file);
	  find_line ("CXXFLAGS", 0, 1, 1);
	  find_line ("DEP_FILES", 1, 0, 1);
	  fputs ("DEP_FILES = .deps/components.P .deps/dmac.P .deps/dsu.P .deps/intc.P .deps/mm_int.P .deps/timer.P .deps/gbif.P .deps/lbif.P .deps/gbmif.P \\\n", dst_file);
	  fputs (".deps/toshapi.P", dst_file);
	}
      else /* if (automake_version == AM_1_9_5) */
	find_line ("toshapi.Plo", 1, 1, 1);

      for (cm = currentcmodel; cm != NULL; cm = cm->prev)
	{
	  /* Ignore rtl cmodels.  */
	  if (cm->rtl_model_type)
	    continue;
	  /* Don't include the same class definition twice.  */
	  if (cmodel_class_is_duplicate (cm))
	    continue;

	  /* Include all the listed model object files.  */
	  for (i=0; i<cm->num_files; i++)
	    {
	      /* Paste only objects of .cc/.cxx files.  */
	      if ((suffix = strstr (cm->files[i], ".cc")) ||
		  (suffix = strstr (cm->files[i], ".cxx")))
		{
		  if (automake_version == AM_1_4)
		    fprintf (dst_file, " .deps/%.*s.P", suffix - cm->files[i], cm->files[i]);
		  else /* if (automake_version == AM_1_9_5) */
		    fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/%.*s.Plo@am__quote@\n",
			     suffix - cm->files[i], cm->files[i]);
		}
	    }
	}
      fputc ('\n', dst_file);
      if (automake_version == AM_1_4)
	find_line ("SOURCES", 0, 1, 1);
      else /* if (automake_version == AM_1_9_5) */
	find_line (".cxx.o:", 0, 1, 1);
    }

  end_file ();
}

static void
do_user_cmodel_includes ()
{
  CModel *cm;
  int i;
  Node *cfg, *module, *lmem;
  char typename [1024];
  int namespace_written = 0;
  static unsigned ctr = 0;

  start_file (srcdir, "sid/component/families/mep/components.cxx", 0);
  find_line ("begin-toshapi-headers", 1, 1, 1);
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      char incfile [1024];

      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;

      /* Don't include the same class declaration twice.  */
      if (cmodel_class_is_duplicate (cm))
	continue;

      if (! namespace_written)
	{
	  fputs ("namespace toshapi {\n", dst_file);
	  namespace_written = 1;
	}

      if (cm->include_file)
	{
	  sprintf (incfile, "%s%s",
		   (cm->base_dir ? cm->base_dir : ""), 
		   cm->include_file);
	  fprintf (dst_file, "#include \"%s\"\n", absolute_filename (resolve_local_filename (incfile)));
	}
      /* Do this for all the listed model source files.  */
      for (i=0; i<cm->num_files; i++)
	{
	  /* Don't do the .cc or .cxx files or the include_file */
	  if (strstr (cm->files[i], ".cc") == 0 &&
	      strstr (cm->files[i], ".cxx") == 0 &&
	      (! cm->include_file || strcmp (cm->files[i], cm->include_file) != 0))
	    {
	      sprintf (incfile, "%s%s",
		       (cm->base_dir ? cm->base_dir : ""), 
		       cm->files[i]);
	      fprintf (dst_file, "#include \"%s\"\n", absolute_filename (resolve_local_filename (incfile)));
	    }
	}
    }
  if (namespace_written)
    fputs ("}\n", dst_file);
  find_line ("end-toshapi-headers", 0, 1, 1);

  find_line ("begin-toshapi-constructor-names", 1, 1, 1);
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      assert (cm->class_name != NULL);
      sprintf (typename, "hw-toshapi-%s-%s", cm->class_name, cm->instance_name);
      fprintf (dst_file, "  types.push_back (\"%s\");\n", typename);
    }
  for (cfg = currentcfg; cfg; cfg = cfg->next)
    {
      for (module = find_sub (cfg, "me_module", 0); module; module = find_next (module, "me_module"))
	{
	  for (lmem = find_sub (module, "local_mem", 0); lmem; lmem = find_next (lmem, "local_mem"))
	    {
	      assert (lmem->val != NULL);
	      sprintf (typename, "hw-toshapi-%s", lmem->val);
	      fprintf (dst_file, "  types.push_back (\"%s\");\n", typename);
	    }
	}
    }
  find_line ("end-toshapi-constructor-names", 0, 1, 1);

  find_line ("begin-toshapi-constructors", 1, 1, 1);
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      /* Generate a pointer to static instance of each cmodel and a macro to construct it
	 on the fly when it is referenced.  */
      assert (cm->class_name != NULL);
      fprintf(dst_file, "  static %s *a_%s = 0;\n", cm->class_name, cm->instance_name);
      fprintf(dst_file, "  #define %s (a_%s ? a_%s : (a_%s = new %s (",
	      cm->instance_name, cm->instance_name, cm->instance_name, cm->instance_name,
	      cm->class_name);

      /* Generate the arguments for the constructor call.  */
      switch (cm->type)
	{
	  case cmTypeUci:
	    /* UCI does not take an instance name argument */
	    if (cm->argc >= 1)
	      fputs ("0", dst_file);	
	    break;
	case cmTypeBusArbitrator:
	  break;
	default:
	  fprintf (dst_file, "\"%s\"", cm->instance_name);
	  if (cm->argc >= 2)
	    fputs (", 0", dst_file);	
	  break;
	}
      if (cm->cfg_args)
	fprintf (dst_file, ", %s", cm->cfg_args);
      fprintf (dst_file, ")))\n");
    }
  for (cfg = currentcfg; cfg; cfg = cfg->next)
    {
      /* Generate a pointer to static instance of each local memory and a macro to construct it
	 on the fly when it is referenced.  */
      for (module = find_sub (cfg, "me_module", 0); module; module = find_next (module, "me_module"))
	{
	  for (lmem = find_sub (module, "local_mem", 0); lmem; lmem = find_next (lmem, "local_mem"))
	    {
	      assert (lmem->val != NULL);
	      fprintf(dst_file, "  static Memory *a_%s = 0;\n", lmem->val);
	      fprintf(dst_file, "  #define %s (a_%s ? a_%s : (a_%s = new Memory (\"%s\")))\n",
		      lmem->val, lmem->val, lmem->val, lmem->val, lmem->val);
	    }
	}
    }
  /* Generate code to return the static pointer to the appropriate object based on the
     given type.  */
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      assert (cm->class_name != NULL);
      sprintf (typename, "hw-toshapi-%s-%s", cm->class_name, cm->instance_name);
      fprintf (dst_file, "  if (typeName == \"%s\")\n", typename);
      fprintf (dst_file, "    return %s;\n", cm->instance_name);
    }
  for (cfg = currentcfg; cfg; cfg = cfg->next)
    {
      for (module = find_sub (cfg, "me_module", 0); module; module = find_next (module, "me_module"))
	{
	  for (lmem = find_sub (module, "local_mem", 0); lmem; lmem = find_next (lmem, "local_mem"))
	    {
	      assert (lmem->val != NULL);
	      sprintf (typename, "hw-toshapi-%s", lmem->val);
	      fprintf (dst_file, "  if (typeName == \"%s\")\n", typename);
	      fprintf (dst_file, "    return %s;\n", lmem->val);
	    }
	}
    }
  /* Generate #undefs of the macros used to construct each object */
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      fprintf(dst_file, "  #undef %s\n", cm->instance_name);
    }
  for (cfg = currentcfg; cfg; cfg = cfg->next)
    for (module = find_sub (cfg, "me_module", 0); module; module = find_next (module, "me_module"))
      for (lmem = find_sub (module, "local_mem", 0); lmem; lmem = find_next (lmem, "local_mem"))
	fprintf(dst_file, "  #undef %s\n", lmem->val);
  find_line ("end-toshapi-constructors", 0, 1, 1);

  find_line ("begin-toshapi-destructors", 1, 1, 1);
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      /* Don't include the same class definition twice.  */
      if (cmodel_class_is_duplicate (cm))
	continue;

      assert (cm->class_name != NULL);
      fprintf (dst_file, "  %s* t%u = dynamic_cast<%s*> (c);\n",
	       cm->class_name, ++ctr, cm->class_name);
      fprintf (dst_file, "  if (t%u) { delete t%u; return; }\n",
	       ctr, ctr);
    }
  fprintf (dst_file, "  Memory* t%u = dynamic_cast<Memory*> (c);\n",
	   ++ctr);
  fprintf (dst_file, "  if (t%u) { delete t%u; return; }\n",
	   ctr, ctr);
  find_line ("end-toshapi-destructors", 0, 1, 1);
  end_file ();

  /* Generate toshmep source files.  */
  for (cm = currentcmodel; cm != NULL; cm = cm->prev)
    {
      /* Ignore rtl cmodels.  */
      if (cm->rtl_model_type)
	continue;
      /* Don't include the same class definition twice.  */
      if (cmodel_class_is_duplicate (cm))
	continue;

      for (i=0; i<cm->num_files; i++)
	{
	  /* Paste only .cc/.cxx files.  */
	  if (strstr (cm->files[i], ".cc") ||
	      strstr (cm->files[i], ".cxx"))
	    {
	      const char* suffix;
	      /* Generate only for .cc/.cxx files.  */
	      if ((suffix = strstr (cm->files[i], ".cc")) ||
		  (suffix = strstr (cm->files[i], ".cxx")))
		{
		  char newfile [1024];
		  char srcfile [1024];
		  sprintf (newfile, "sid/component/families/mep/%.*s.cxx", suffix - cm->files[i], cm->files[i]);

		  start_file (srcdir, newfile, 0);
		  fputs ("#include \"toshapi.h\"\n\n", dst_file);
		  fputs ("namespace toshapi {\n", dst_file);

		  sprintf (srcfile, "%s%s",
			   (cm->base_dir ? cm->base_dir : ""), 
			   cm->files[i]);
		  fprintf (dst_file, "#include \"%s\"\n", absolute_filename (resolve_local_filename (srcfile)));
		  fputs ("} // namespace toshapi\n", dst_file);

		  find_line (NULL, 0, 0, 1);
		  end_file ();
		}
	    }
	}
    }

  do_toshmep_Makefile_config ("sid/component/families/mep/Makefile.am");
  do_toshmep_Makefile_config ("sid/component/families/mep/Makefile.in");
}

struct cop_ip
{
  struct cop_ip *next;
  const char *ip;
  char *modules;
};

static struct cop_ip *cop_ips = NULL;

static void
record_cop_ip (Node *ip_node, int module_num)
{
  const char* ip_name;
  struct cop_ip* ip;
  char modnum[sizeof ("4294967295")];
			  
  if (! ip_node->val)
    return;

  /* The names are kept in lower case, since that's how they are used most
     often.  */
  ip_name = downcase (ip_node->val);
  for (ip = cop_ips; ip; ip = ip->next)
    {
      if (strcmp (ip_name, ip->ip) == 0)
	break;
    }

  if (! ip)
    {
      ip = xmalloc (sizeof (*ip));
      ip->ip = strdup (ip_name);
      ip->modules = "";
      ip->next = cop_ips;
      cop_ips = ip;
    }

  sprintf (modnum, "%d", module_num);
  ip->modules = concat (ip->modules, ",", modnum, 0);
}

static void
scan_cop_ip ()
{
  Node *cfgs, *modules;
  int i;

  if (cop_ips)
    return; /* already done! */

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (i = 1, modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"), ++i)
	{
	  Node *ip = find_sub (modules, "cop", "ip", 0);
	  if (ip)
	    record_cop_ip (ip, i);
	}
    }
}

static void
do_user_cop_ip ()
{
  struct cop_ip *ip;

  /* Here we customize the .cpu file for each user specified coprocessor which
     was specified using IP.  */
  scan_cop_ip ();
  for (ip = cop_ips; ip; ip = ip->next)
    {
      char *module;
      char *modend;
      char *ch;
      /* Note which of the core and 4 coprocessor isas are used.  */
      int have_isa[] = {0, 0, 0, 0, 0};
      char *filename = concat ("cgen/cpu/mep-", ip->ip, ".cpu", 0);

      start_file (srcdir, filename, 0);
      find_line ("begin-isas", 1, 1, 1);

      /* For each line containing "isa" define the corresponding isas for all the
	 necessary ME_MODULES using that coprocessor.  */
      for (;;)
	{
	  char *isa_str, *isa_str1, *isa_str2;

	  /* Find the next line containing "isa".  */
	  find_line ("isa", 0, 0, 1);

	  /* End of the isa specs.  */
	  if (strstr (line, "all-") != 0)
	    break;

	  /* Output the beginning of the line as is, up to the ISA list.  */
	  ch = strstr (line, "ISA ");
	  assert (ch);
	  ch += 3;
	  *ch = '\0';
	  fprintf (dst_file, "%s ", line);

	  /* Build an isa string to use for each module.  */
	  ch = strstr (ch + 1, "ext_");
	  assert (ch);
	  ch += 4;

	  if (memcmp (ch, "core", 4) == 0)
	    {
	      /* There is be a core isa in the list.  */
	      isa_str = "ext_core%s";
	      /* Advance to the cop isa, if specified. */
	      ch = strstr (ch + 5, "ext_");
	      if (ch)
		ch += 4;
	      have_isa[4] = 1;
	    }
	  else if (ch && memcmp (ch, "cop", 3) == 0)
	    {
	      /* There is  a coprocessor isa in the list.  */
	      isa_str1 = "ext_cop%s_";
	      /* Find the bitwidth suffix.  */
	      for (ch += 4; *ch != '_'; ++ch)
		;
	      isa_str2 = ++ch;
	      for (/**/; isdigit (*ch); ++ch)
		;
	      *ch = '\0';
	      isa_str = concat (isa_str1, isa_str2, 0);
	      /* It just turns out that if the take the first digit of 16, 32, 48 and 64,
		 and divide them by 2 you get 0, 1, 2 and 3 respectively.
		 Use this to index the have_isa array.  */
	      have_isa[(*isa_str2 - '0') / 2] = 1;
	    }
	  else
	    continue;

	  /* Emit an instance of the isas defined on this line for each module
	     using this coprocessor.  */
	  for (module = ip->modules; *module; module = modend)
	    {
	      char tmp;
	      ++module; /* get past initial comma */
	      for (modend = module; *modend && *modend != ','; ++modend)
		;
	      tmp = *modend;
	      *modend = '\0';
	      fprintf (dst_file, isa_str, module, module);
	      if (tmp)
		fputc (tmp, dst_file);
	      *modend = tmp;
	    }

	  /* Finish of the macro definition.  */
	  fputs ("))\n", dst_file);
	}

      /* Output the macro representing all isas */
      /* Output the beginning of the line as is, up to the ISA list.  */
      ch = strstr (line, "ISA ");
      assert (ch);
      ch += 3;
      *ch = '\0';
      fprintf (dst_file, "%s ", line);

      /* Now output the isas collected above.  */
      for (module = ip->modules; *module; module = modend)
	{
	  char *comma = "";
	  char tmp;
	  int i;

	  ++module; /* get past initial comma */
	  for (modend = module; *modend && *modend != ','; ++modend)
	    ;
	  tmp = *modend;
	  *modend = '\0';

	  /* Output the core isa, if it's used.  */
	  if (have_isa[4])
	    {
	      fprintf (dst_file, "ext_core%s", module);
	      comma = ",";
	    }
	  /* Output the coprocessor isas, if used.  */
	  for (i = 0; i < 4; ++i)
	    {
	      if (have_isa[i])
		{
		  fprintf (dst_file, "%sext_cop%s_%d", comma, module, 16 * (i + 1));
		  comma = ",";
		}
	    }
	  if (tmp)
	    fputc (tmp, dst_file);
	  *modend = tmp;
	}
      fputs ("))\n", dst_file);

      /* Find the terminating comment.  */
      find_line ("isa", 0, 1, 1);
      end_file ();
    }
}

static void
do_user_isa_includes ()
{
  Node *cfgs, *modules, *items[3]; 
  int i, j;
  char *v[3] = {"uci", "dsp", "cop"};
  struct cop_ip *ip;
  int have_fmax;

  do_user_cop_ip ();

  start_file (srcdir, "cgen/cpu/mep-ext-cop.cpu", 0);
  find_line ("begin-user-isa-includes", 1, 1, 1);

  /* Insert custom frags into mep-ext-cop.cpu file */
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (i = 1, modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"), ++i)
	{
	  memset (items, 0, sizeof(Node *) * 3);
	  for (j=0; j < 3; ++j)
	    items[j] = find_sub (modules, v[j], "cgen_define", 0);
	  
	  if (items[0] || items[1] || items[2])
	    {
	      for (j=0; j < 3; ++j)
		{
		  if (items[j] && items[j]->val)
		    include_from (items[j]->val, dst_file);
		}
	    }
	}
    }

  /* Insert frags from coprocessors specified using IP into mep-ext-cop.cpu file */
  have_fmax = 0;
  for (ip = cop_ips; ip; ip = ip->next)
    {
      fprintf (dst_file, "(include \"mep-%s.cpu\")\n", ip->ip);
      if (strcmp (ip->ip, "fmax") == 0)
	have_fmax = 1;
    }

  find_line ("end-user-isa-includes", 0, 1, 1);
  end_file (); 

  /* Insert simulator C++ functions into sid's CPU core */
  start_file (srcdir, "sid/component/cgen-cpu/mep/mep.h", 0);

  find_line ("begin-fpu-includes", 1, 1, 1);
  if (have_fmax)
    {
      fputs ("#include \"fmax-fp.h\"\n", dst_file);
      fputs ("using sidutil::fmax_fp;\n", dst_file);
    }
  find_line ("end-fpu-includes", 0, 1, 1);

  find_line ("begin-copro-cpu-includes", 1, 1, 1);
  for (ip = cop_ips; ip; ip = ip->next)
    fprintf (dst_file, "#include \"%s-cpu.h\"\n", ip->ip);
  find_line ("end-copro-cpu-includes", 0, 1, 1);

  find_line ("begin-user-sim-includes", 1, 1, 1);
  if (! toshapi) for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (i = 1, modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"), ++i)
	{
	  memset (items, 0, sizeof(Node *) * 3);
	  for (j=0; j < 3; ++j)
	    items[j] = find_sub (modules, v[j], "sim", 0);

	  if (items[0] || items[1] || items[2])
	    {
	      for (j=0; j < 3; ++j)
		if (items[j] && items[j]->val)
		  include_from (items[j]->val, dst_file);
	    }	  
	}
    }
  find_line ("end-user-sim-includes", 0, 1, 1);
  end_file ();
}

static struct dir_table
{
  const char *name;
  int processed;
} sid_dir_table []
= {
  { "component/audio", 0 },
  { "component/bochs", 0 },
  { "component/bochs/cmos", 0 },
  { "component/bochs/cpu", 0 },
  { "component/bochs/cpu/fpu", 0 },
  { "component/bochs/cpu/memory", 0 },
  { "component/bochs/dma", 0 },
  { "component/bochs/floppy", 0 },
  { "component/bochs/gui", 0 },
  { "component/bochs/harddrv", 0 },
  { "component/bochs/keyboard", 0 },
  { "component/bochs/pic", 0 },
  { "component/bochs/pit", 0 },
  { "component/bochs/unmapped", 0 },
  { "component/bochs/vga", 0 },
  { "component/cache", 0 },
  { "component/cfgroot", 0 },
  { "component/cfgroot/libltdl", 0 },
  { "component/cgen-cpu", 0 },
  { "component/cgen-cpu/arm7t", 0 },
  { "component/cgen-cpu/m32r", 0 },
  { "component/cgen-cpu/mep", 0 },
  { "component/cgen-cpu/xstormy16", 0 },
  { "component/consoles", 0 },
  { "component/families/mep", 0 },
  { "component/gdb", 0 },
  { "component/gloss", 0 },
  { "component/glue", 0 },
  { "component/ide", 0 },
  { "component/interrupt", 0 },
  { "component/lcd", 0 },
  { "component/loader", 0 },
  { "component/mapper", 0 },
  { "component/memory", 0 },
  { "component/mmu", 0 },
  { "component/parport", 0 },
  { "component/profiling", 0 },
  { "component/rtc", 0 },
  { "component/sched", 0 },
  { "component/tcl", 0 },
  { "component/timers", 0 },
  { "component/timers/arm7t", 0 },
  { "component/uart", 0 },
  { "main/dynamic", 0 },
  { NULL, 0 }
};

static int
add_to_make_variable (const char *value)
{
  char *equal;

  /* The line containing the variable declaration is in 'line'. Find the line
     containing the '='.  */
  while (! (equal = strchr (line, '=')))
    {
      fputs (line, dst_file);
      if (! read_line ())
	return 1; /* assignment not found */
    }

  /* Make sure that the value is not already there.  */
  if (strstr (line, value))
    {
      fputs (line, dst_file);
      return 0;
    }

  /* Add the new value to the beginning of the variable's value.  */
  fprintf (dst_file, "%.*s", equal - line + 1, line);
  fprintf (dst_file, " %s ", value);
  fputs (equal + 1, dst_file);
  return 0;
}

static void
remove_from_make_variable (const char *value)
{
  const char *substr;

  /* The line containing the variable declaration is in 'line'. See if it
     contains the given value.  */
  substr = strstr (line, value);
  if (substr)
    {
      /* If there is nothing else specified other than 'value', then just
	 leave out the entire variable assignment.  */
      if (substr [strlen (value)] == '\n')
	return;

      /* Remove the value along with the spaces on either side.  */
      fprintf (dst_file, "%.*s", substr - line - 1, line);
      fputs (substr + strlen (value) + 1, dst_file);
    }
  else
    fputs (line, dst_file);
}

static int
do_usercode_variable_config (const char* ldadd, const char *fulldir,
			   char *makefile,
			   char *prefix, char *suffix)
{
  int found;
  int dir_configured;
  char *var_ref;

  /* Add ldadd, if specified. */
  start_file (fulldir, makefile, 0);

  /* We need to find the automake variable of the form <prefix>_<suffix> */
  for (;;)
    {
      found = find_line (suffix, 1, 0, 0);
      if (! found)
	break;

      /* Remove the line beginning with MEPI_... if it is found first.
	 It will be re-added, if necessary.  The variable setting we want
	 will then be on the next line.  */
      if (strncmp (line, "MEPI_", 5) == 0)
	{
	  found = find_line (suffix, 1, 0, 1);
	  assert (found);
	  break;
	}

      /* Verify that this is the right instance by looking for the prefix
	 at the start of the line or after a conditional test.  */
      if (strncmp (line, prefix, strlen (prefix)) == 0)
	break;
      if (strncmp (line, "@SIDTARGET_MEP_TRUE@", 20) == 0 &&
	  strncmp (line + 20, prefix, strlen (prefix)) == 0)
	break;

      /* Not the right one. Keep the line and search again.  */
      fputs (line, dst_file);
    }
  var_ref = concat ("$(MEPI", suffix, ")", 0);
  if (ldadd)
    {
      char *ldadd_name = concat (prefix, suffix, 0);
      fprintf (dst_file, "MEPI%s = %s\n", suffix, ldadd);
      if (found)
	{
	  if (add_to_make_variable (var_ref) != 0)
	    error ("Unable to find assignment for %s in %s\n", ldadd_name, src_name);
	}
      else
	fprintf (dst_file, "%s = %s\n", ldadd_name, var_ref);
    }
  else if (found)
    remove_from_make_variable (var_ref);
  dir_configured = end_file ();

  return dir_configured;
}

static char *
sources_to_lo (const char *s)
{
  char *p;
  char *lo = NULL;
  unsigned lo_len = 0;

  /* If s is NULL, then nothing to do.  */
  if (! s)
    return (NULL);

  /* Convert a list of source file names to a list of .lo file names  */
  for (p = strchr (s, '.'); p; p = strchr (s, '.'))
    {
      unsigned len = p - s;
      lo = xrealloc (lo, lo_len + len + 5);
      memcpy (lo + lo_len, s, len);
      memcpy (lo + lo_len + len, ".lo", 4);
      lo_len += len + 3;

      /* look for the next whitespace */
      for (s = p + 1; *s && ! isspace (*s); ++s)
	;
      if (! *s)
	break;
      /* look for the next non whitespace */
      for (++s; *s && isspace (*s); ++s)
	;
      if (! *s)
	break;
      lo[lo_len++] = ' ';
    }
  return lo;
}

static char *
sources_to_P (const char *s)
{
  char *p;
  char *P = NULL;
  unsigned P_len = 0;

  /* If s is NULL, then nothing to do.  */
  if (! s)
    return (NULL);

  /* Convert a list of source file names to a list of .P file names  */
  for (p = strchr (s, '.'); p; p = strchr (s, '.'))
    {
      unsigned len = p - s;
      P = xrealloc (P, P_len + 6 + len + 4);
      memcpy (P + P_len, ".deps/", 6);
      P_len += 6;
      memcpy (P + P_len, s, len);
      memcpy (P + P_len + len, ".P", 3);
      P_len += len + 2;

      /* look for the next whitespace */
      for (s = p + 1; *s && ! isspace (*s); ++s)
	;
      if (! *s)
	break;
      /* look for the next non whitespace */
      for (++s; *s && isspace (*s); ++s)
	;
      if (! *s)
	break;
      P[P_len++] = ' ';
    }
  return P;
}

static int
do_usercode_Makefile_config (const char *basedir, const char *dir,
			     const char *sources, const char *includes,
			     const char *ldadd, char* makefile)
{
  int dir_configured = 0;
  char *fulldir;
  char *prefix;
  char *substr;
  unsigned prefix_len;
  int found;

  /* Construct the full name of the directory.  */
  fulldir = concat (basedir, dir, 0);

  /* We need to look up the *_SOURCES variable in order to determine the
     prefix.  We need to find the automake variable of the form
     <lowercase>_SOURCES */
  start_file (fulldir, makefile, 0);
  for (;;)
    {
      found = find_line ("_SOURCES", 1, 0, 1);
      assert (found);
      substr = strstr (line, "_SOURCES");

      /* Remove the line beginning with MEPI_... if it is found first.  It will
	 be re-added, if necessary.  The variable setting we want will then be
	 on the next line.  */
      if (strncmp (line, "MEPI_", 5) == 0)
	{
	  found = find_line ("_SOURCES", 1, 0, 1);
	  assert (found);
	  substr = strstr (line, "_SOURCES");
	  break;
	}
      if (substr > line && islower (*(substr - 1)))
	break;
      /* Not the right one. Keep the line and search again.  */
      fputs (line, dst_file);
    }
  prefix_len = substr - line;
  prefix = xmalloc (prefix_len + 1);
  memcpy (prefix, line, prefix_len);
  prefix [prefix_len] = '\0';
  
  /* Add sources, if specified.  */
  if (sources)
    {
      fprintf (dst_file, "MEPI_SOURCES = %s\n", sources);
      if (add_to_make_variable ("$(MEPI_SOURCES)") != 0)
	error ("Unable to find assignment for %s_SOURCES in %s\n", prefix, src_name);
    }
  else
    remove_from_make_variable ("$(MEPI_SOURCES)");
  dir_configured = end_file ();

  /* Add includes, if specified. */
  start_file (fulldir, makefile, 0);
  for (;;)
    {
      found = find_line ("INCLUDES", 1, 0, 0);
      if (! found)
	break;

      /* Remove the line beginning with MEPI_INCLUDES if it is found first.  It
	 will be re-added, if necessary.  */
      if (strncmp (line, "MEPI_INCLUDES", 13) == 0)
	{
	  found = find_line ("INCLUDES", 1, 0, 1);
	  assert (found);
	  break;
	}

      /* Make sure that 'INCLUDES' is the first thing on the line.  */
      if (strncmp (line, "INCLUDES", 8) == 0)
	break;
      /* Not the right one. Keep the line and search again.  */
      fputs (line, dst_file);
    }
  if (includes)
    {
      fprintf (dst_file, "MEPI_INCLUDES = %s\n", includes);
      if (found)
	{
	  if (add_to_make_variable ("$(MEPI_INCLUDES)") != 0)
	    error ("Unable to find assignment for INCLUDES in %s\n", src_name);
	}
      else
	fputs ("INCLUDES = $(MEPI_INCLUDES)\n", dst_file);
    }
  else if (found)
    remove_from_make_variable ("$(MEPI_INCLUDES)");
  dir_configured |= end_file ();

  /* Process LDADD, if specified.  Use LIBADD if the prefix ends with 'la',
     otherwise, use LDADD.  */
  if (prefix [prefix_len - 2] == 'l' && prefix [prefix_len - 1] == 'a')
    dir_configured |= do_usercode_variable_config (ldadd, fulldir, makefile, prefix, "_LIBADD");
  else
    dir_configured |= do_usercode_variable_config (ldadd, fulldir, makefile, prefix, "_LDADD");

  /* Extra config for 'Makefile.in'  */
  if (strcmp (makefile, "Makefile.in") == 0)
    {
      dir_configured |= do_usercode_variable_config (sources_to_lo (sources), fulldir, makefile, prefix, "_OBJECTS");
      dir_configured |= do_usercode_variable_config (sources_to_P (sources), fulldir, makefile, "DEP", "_FILES");
    }

  return dir_configured;
}

static void
do_usercode_config (const char *basedir, const char *dir,
		    const char *sources, const char *includes,
		    const char *ldadd)
{
  int dir_configured;

  /* Can't do this in test mode, since the actions depend on which variables
     are found in the Makefiles.  */
  if (testing)
    return;

  /* Perform the actual configuration.  */
  dir_configured  = do_usercode_Makefile_config (srcdir, dir, sources, includes, ldadd, "Makefile.am");
  dir_configured |= do_usercode_Makefile_config (srcdir, dir, sources, includes, ldadd, "Makefile.in");

  /* Add instructions for rebuilding this directory, if the configuration has
     changed.  */
  if (dir_configured)
    {
      rebuild_extra = concat (rebuild_extra,
			      "   cd $BUILDDIR", dir, "\n",
			      "   ./config.status\n", NULL);
    }
}

static void
do_user_code_includes ()
{
  /* Scan the configs for SIM_EXTRA_CONFIG. Add the specified code and libraries
     to the specified Makefiles.  */
  struct dir_table *p;
  char *dir;
  Node* cfgs;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *extra;
      for (extra = find_sub (cfgs, "sim_extra_config", 0); extra; extra = find_next (extra, "sim_extra_config"))
	{
	  Node *node;
	  const char *sources = 0, *includes = 0, *ldadd = 0;

	  /* The SID directory to add user code to.  */
	  node = find_sub (extra, "dir", 0);
	  assert (node && node->val);

	  /* Make sure it supports SIM_EXTRA_CONFIG and has not already been
	     processed.  */
	  for (p = sid_dir_table; p->name; ++p)
	    {
	      if (strcmp (node->val, p->name) == 0)
		break;
	    }
	  if (! p->name)
	    {
	      error ("%s is not allowed for SIM_EXTRA_CONFIG.DIR\n", node->val);
	      continue;
	    }
	  if (p->processed)
	    {
	      error ("SIM_EXTRA_CONFIG.DIR=%s has already been specified\n",
		     p->name);
	      continue;
	    }
	  p->processed = 1;

	  /* Construct the full path name.  */
	  dir = concat ("/sid/", node->val, 0);

	  /* List of user source files.  */
	  node = find_sub (extra, "sources", 0);
	  if (node)
	    {
	      assert (node->val);
	      sources = node->val;
	    }

	  /* List of user #include files.  */
	  node = find_sub (extra, "includes", 0);
	  if (node)
	    {
	      assert (node->val);
	      includes = node->val;
	    }

	  /* List of libraries and linker options.  */
	  node = find_sub (extra, "ldadd", 0);
	  if (node)
	    {
	      assert (node->val);
	      ldadd = node->val;
	    }

	  /* Perform the actual configuration.  */
	  do_usercode_config (srcdir, dir, sources, includes, ldadd);
	}
    }

  /* Now process the remaining directories, in case user code has been removed.
   */
  for (p = sid_dir_table; p->name; ++p)
    {
      if (p->processed)
	continue;
	  /* Construct the full path name.  */
      dir = concat ("/sid/", p->name, 0);
      do_usercode_config (srcdir, dir, 0, 0, 0);
    }
}

static void
gen_user_cpu (int i, Node *copro)
{
  Node *cop_ip = copro ? find_sub (copro, "ip", 0) : NULL;
  const char *cop_ip_name = cop_ip ? downcase (cop_ip->val) : NULL;
  int have_fpu = (cop_ip_name && strcmp (cop_ip_name, "fmax") == 0);
  char filename[sizeof ("sid/component/cgen-cpu/mep/mep_ext.h") + 20];

  sprintf (filename, "sid/component/cgen-cpu/mep/mep_ext%d.h", i);
  start_file (srcdir, filename, 0);

  fputs ("// Do not edit!!!!!!!\n"
	 "// This file was generated by MeP-Integrator\n"
	 "\n"
         "#include \"mep.h\"\n"
	 "\n", dst_file);
  fprintf (dst_file, "#include \"mep-core%d-defs.h\"\n", i);
  fprintf (dst_file, "#include \"mep-core%d-decode.h\"\n", i);
  fprintf (dst_file, "#include \"mep-core%d-model.h\"\n", i);
  if (copro)
    {
      fprintf (dst_file, "#include \"mep-cop%d-16-defs.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-16-decode.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-16-model.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-32-defs.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-32-decode.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-32-model.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-48-defs.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-48-decode.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-48-model.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-64-defs.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-64-decode.h\"\n", i);
      fprintf (dst_file, "#include \"mep-cop%d-64-model.h\"\n", i);
    }
  fputs ("\n"
	 "#include \"common_model.h\"\n", dst_file);
  if (have_fpu)
    {
      fprintf (dst_file, "#include \"%s-fpu.h\"\n", cop_ip_name);
      fprintf (dst_file, "#include \"%s-fp.h\"\n", cop_ip_name);
      fprintf (dst_file, "using sidutil::%s_fp;\n", cop_ip_name);
    }
  fputs ("\n"
	 "using namespace mep;\n"
	 "\n", dst_file);
  fprintf (dst_file, "namespace mep_ext%d {\n", i);

  if (copro)
    fprintf (dst_file, "  class mep_ext%d_cpu: public mep_cpu_vliw<mep_ext%d_cpu,mepcore%d_scache,mepcop%d_16_scache,mepcop%d_32_scache,mepcop%d_48_scache,mepcop%d_64_scache>\n", i, i, i, i, i, i, i);
  else
    fprintf (dst_file, "  class mep_ext%d_cpu: public mep_cpu_vliw<mep_ext%d_cpu,mepcore%d_scache,dummy_scache,dummy_scache,dummy_scache,dummy_scache>\n", i, i, i);

  fputs ("  {\n", dst_file);
  fputs ("  public:\n", dst_file);
  fprintf (dst_file, "    mep_ext%d_cpu() :\n", i);

  if (copro)
    {
      fprintf (dst_file, "      mep_cpu_vliw<mep_ext%d_cpu,mepcore%d_scache,mepcop%d_16_scache,mepcop%d_32_scache,mepcop%d_48_scache,mepcop%d_64_scache>\n", i, i, i, i, i, i);
      fprintf (dst_file, "      (this,ISA_EXT_CORE%d,ISA_EXT_COP%d_16,ISA_EXT_COP%d_32,ISA_EXT_COP%d_48,ISA_EXT_COP%d_64),\n", i, i, i, i, i);
      fputs ("      my_core_model (this),\n", dst_file);
      fputs ("      my_cop16_model (this),\n", dst_file);
      fputs ("      my_cop32_model (this),\n", dst_file);
      fputs ("      my_cop48_model (this),\n", dst_file);
      fputs ("      my_cop64_model (this)", dst_file);
      if (have_fpu)
	fprintf (dst_file, ",\n      fpu (this, new %s_fp_ops)", cop_ip_name);
      fputc ('\n', dst_file);
    }
  else
    {
      fprintf (dst_file, "      mep_cpu_vliw<mep_ext%d_cpu,mepcore%d_scache,dummy_scache,dummy_scache,dummy_scache,dummy_scache>\n", i, i);
      fprintf (dst_file, "      (this,ISA_EXT_CORE%d,ISA_MAX,ISA_MAX,ISA_MAX,ISA_MAX),\n", i);
      fputs ("      my_core_model (this)\n", dst_file);
    }

  fputs ("    {}\n", dst_file);
  fputs ("\n", dst_file);
  fputs ("    void core_model_insn_before (bool first_p = true) { my_core_model.model_insn_before (first_p); }\n", dst_file);
  fputs ("    void core_model_step_latency (sid::host_int_4 cycles = 0) { my_core_model.step_latency (cycles); }\n", dst_file);

  fputs ("\n", dst_file);
  fprintf (dst_file, "    UINT model_before (mepcore%d_scache* sem)\n", i);
  fputs ("      {\n", dst_file);
  fputs ("        UINT stall = my_core_model.model_before (this, sem);\n", dst_file);
  fputs ("        if (stall) update_total_latency (stall);\n", dst_file);
  fputs ("        return stall;\n", dst_file);
  fputs ("      }\n", dst_file);

  fputs ("\n", dst_file);
  fprintf (dst_file, "    UINT model_after (mepcore%d_scache* sem) { return my_core_model.model_after (this, sem); }\n", i);
  if (copro)
    {
      fprintf (dst_file, "    UINT model_after (mepcop%d_16_scache* sem) { return my_cop16_model.model_after (this, sem); }\n", i);
      fprintf (dst_file, "    UINT model_after (mepcop%d_32_scache* sem) { return my_cop32_model.model_after (this, sem); }\n", i);
      fprintf (dst_file, "    UINT model_after (mepcop%d_48_scache* sem) { return my_cop48_model.model_after (this, sem); }\n", i);
      fprintf (dst_file, "    UINT model_after (mepcop%d_64_scache* sem) { return my_cop64_model.model_after (this, sem); }\n", i);
    }
  else
    fputs ("    UINT model_after (dummy_scache* sem) { return 1; }\n", dst_file);

  fputs ("\n", dst_file);
  fputs ("    void core_model_insn_after (bool last_p = true, UINT cycles = 1) { my_core_model.model_insn_after (last_p, cycles); }\n", dst_file);
  fputs ("\n", dst_file);
  if (cop_ip_name)
    {
      fprintf (dst_file, "  public:\n"
	       "#include \"%s.h\"\n"
	       "\n", cop_ip_name);
      if (have_fpu)
	fprintf (dst_file, "    %s_fpu fpu;\n\n", cop_ip_name);
    }
  fputs ("  private:\n", dst_file);
  fprintf (dst_file, "    mep_common_model<mepcore%d_mep_model, mep_ext%d_cpu, mepcore%d_idesc, mepcore%d_scache> my_core_model;\n", i, i, i, i);
  if (copro)
    {
      fprintf (dst_file, "    mep_common_model<mepcop%d_16_mep_model, mep_ext%d_cpu, mepcop%d_16_idesc, mepcop%d_16_scache> my_cop16_model;\n", i, i, i, i);
      fprintf (dst_file, "    mep_common_model<mepcop%d_32_mep_model, mep_ext%d_cpu, mepcop%d_32_idesc, mepcop%d_32_scache> my_cop32_model;\n", i, i, i, i);
      fprintf (dst_file, "    mep_common_model<mepcop%d_48_mep_model, mep_ext%d_cpu, mepcop%d_48_idesc, mepcop%d_48_scache> my_cop48_model;\n", i, i, i, i);
      fprintf (dst_file, "    mep_common_model<mepcop%d_64_mep_model, mep_ext%d_cpu, mepcop%d_64_idesc, mepcop%d_64_scache> my_cop64_model;\n", i, i, i, i);
    }

  fputs ("  };\n\n", dst_file);
  fprintf (dst_file, "#define mep_ext%d_hardware hardware\n", i);
  if (copro)
    fputs ("#define CGEN_CPU_FPU(cpu) (&cpu->fpu)\n", dst_file);
  fputs ("}\n", dst_file);

  find_line (NULL, 0, 0, 1);
  end_file ();
}

static void
do_user_cpu_config ()
{
  Node* cfgs;
  int i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  gen_user_cpu (i, find_sub (modules, "cop", 0));
	  ++i;
	}
    }
}

/* hw_engines get multiple passes made over them, and they're a little ugly
   to re-verify at the nodes-n-string level each time, so we verify them
   in a single pass and store them in a structured array for later passes. */

typedef struct {
  Node *module;
  const char *name;
  const char *sim;
  unsigned long cbus_addr;
  int lbus_if;
  unsigned long lbus_addr;
  unsigned long lbus_size;
  const char *local_mem_list;
  const char *cmodel_args;
  CModel *cmodel;
} hw_engine;

static hw_engine *engines = 0;
static int hw_engines_len = 0;
static int n_hw_engines = 0;

static void
scan_hw_engines ()
{
  Node *cfgs, *modules, *engine, *sim, *cbus_addr, *local_mem_list;
  Node *lbus_if, *lbus_addr, *lbus_size, *cmodel_args;
  CModel *cmodel = NULL;
  int i = 0;

  if (engines)
    return;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  for (engine = modules->sub; engine; engine = engine->next)
	    {
	      if (strcasecmp (engine->id, "hw_engine")  != 0)
		continue;
	      ++i;
	      if (! engine->val)
		{
		  fprintf (stderr, "warning: hw_engine %d has no name, skipping.\n", i);
		  continue;
		}
	      if (! (sim = find_sub (engine, "sim", 0)))		
		{
		  fprintf (stderr, "warning: hw_engine %s has no sim component, skipping.\n", engine->val);
		  continue;
		}
	      if (! sim->val)
		{
		  fprintf (stderr, "warning: hw_engine %s has no SIM child, skipping.\n", engine->val);
		  continue;
		}
	      if (toshapi)
		{
		  cmodel = parse_cmodel (sim, cmTypeHWengine, engine, modules);
		  if (! cmodel)
		    {
		      fprintf (stderr, "warning: hw_engine %s has no usable cmodel, skipping.\n", engine->val);
		  continue;		  
		    }
		}
	      if (! (cbus_addr = find_sub (engine, "cbus_address", 0)))
		{
		  fprintf (stderr, "warning: hw_engine %s has no CBUS_ADDRESS child, skipping.\n", engine->val);
		  continue;		  
		}

	      /* LBUS_IF is optional.  */
	      lbus_if = find_sub (engine, "lbus_if", 0);

	      /* LOCAL_MEM_LIST is optional, but can't be specified with LBUS_IF=ON.  */
	      local_mem_list = find_sub (engine, "local_mem_list", 0);
	      if (lbus_if && local_mem_list && lbus_if->val && local_mem_list->val
		  && strcmp (lbus_if->val, "ON") == 0)
		{
		  fprintf (stderr, "warning: hw_engine %s has both LBUS_IF=ON and LOCAL_MEM_LIST specified, skipping.\n", engine->val);
		  continue;		  
		}

	      /* LBUS_IF, LBUS_ADDRESS and LBUS_SIZE are optional.  */
	      lbus_addr = find_sub (engine, "lbus_address", 0);
	      lbus_size = find_sub (engine, "lbus_size", 0);

	      /* CMODEL_ARGS is optional.  */
	      cmodel_args = find_sub (engine, "cmodel_args", 0);

	      if (! engines || (n_hw_engines >= hw_engines_len))
		{
		  hw_engines_len += 128;
		  engines = xrealloc (engines, sizeof (hw_engine) * hw_engines_len);
		}
	      engines [n_hw_engines].module = modules;
	      engines [n_hw_engines].name = engine->val;
	      engines [n_hw_engines].sim = sim->val;
	      engines [n_hw_engines].cmodel = cmodel;
	      engines [n_hw_engines].cbus_addr = cbus_addr->ival;

	      if (local_mem_list == NULL)
		engines [n_hw_engines].local_mem_list = NULL;
	      else
		engines [n_hw_engines].local_mem_list = local_mem_list->val;

	      engines [n_hw_engines].lbus_if = 0;
	      if (engines [n_hw_engines].local_mem_list == NULL)
		{
		  if (lbus_if && lbus_if->val && strcmp (lbus_if->val, "ON") == 0)
		    {
		      engines [n_hw_engines].lbus_if = 1;
		      if (lbus_addr)
			engines [n_hw_engines].lbus_addr = lbus_addr->ival;
		      else
			engines [n_hw_engines].lbus_addr = 0x00010000;
		      if (lbus_size)
			engines [n_hw_engines].lbus_size = lbus_size->ival;
		      else
			engines [n_hw_engines].lbus_size = 0x00010000;
		    }
		}

	      if (cmodel_args)
		{
		  engines [n_hw_engines].cmodel_args = cmodel_args->val;
		  if (cmodel)
		    cmodel->cfg_args = cmodel_args->val;
		}
	      else
		{
		  engines [n_hw_engines].cmodel_args = NULL;
		  if (cmodel)
		    cmodel->cfg_args = NULL;
		}

	      ++n_hw_engines;
	    }
	}
    }
}


static void
do_hw_engine_includes ()
{
  int i;
  scan_hw_engines ();

  start_file (srcdir, "sid/component/families/mep/components.cxx", 0);

  find_line ("begin-hw-engine-definitions", 1, 1, 1);
  if (engines && ! toshapi) for (i = 0; i < n_hw_engines; ++i)
    {
      assert (engines[i].name);
      assert (engines[i].sim);
      fprintf (dst_file, "#ifndef _HW_ENGINE_%s_\n", engines[i].name);
      fprintf (dst_file, "#define _HW_ENGINE_%s_\n", engines[i].name);
      include_from (engines[i].sim, dst_file);
      fprintf (dst_file, "#endif // _HW_ENGINE_%s_\n", engines[i].name);
    }
  find_line ("end-hw-engine-definitions", 0, 1, 1);

  find_line ("begin-hw-engine-constructor-names", 1, 1, 1);
  if (engines && ! toshapi) for (i = 0; i < n_hw_engines; ++i)
    {
      assert (engines[i].name);
      assert (engines[i].sim);
      fprintf (dst_file, "  types.push_back (\"hw-engine-%s\");\n", engines[i].name);
    }
  find_line ("end-hw-engine-constructor-names", 0, 1, 1);

  find_line ("begin-hw-engine-constructors", 1, 1, 1);
  if (engines && ! toshapi) for (i = 0; i < n_hw_engines; ++i)
    {
      assert (engines[i].name);
      assert (engines[i].sim);
      fprintf (dst_file, "  if (typeName == \"hw-engine-%s\")\n", engines[i].name);
      fprintf (dst_file, "    return new %s (", engines[i].name);
      if (engines[i].cmodel_args)
	fputs (engines[i].cmodel_args, dst_file);
      fputs (");\n", dst_file);
    }
  find_line ("end-hw-engine-constructors", 0, 1, 1);

  find_line ("begin-hw-engine-destructors", 1, 1, 1);
  if (engines && ! toshapi) for (i = 0; i < n_hw_engines; ++i)
    {
      assert (engines[i].name);
      assert (engines[i].sim);
      fprintf (dst_file, "  %s* hw%d = dynamic_cast<%s*> (c);\n", engines[i].name, i, engines[i].name);
      fprintf (dst_file, "  if (hw%d) { delete hw%d; return; }\n", i, i);
    }
  find_line ("end-hw-engine-destructors", 0, 1, 1);

  end_file ();
}



typedef struct {
  Node *module;
  CModel *cmodel;
} uci;


enum {ucis_len = 100};
static uci ucis [ucis_len];
static int n_ucis = 0;

static void
scan_ucis ()
{
  Node *cfgs, *modules, *engine, *sim;
  int i = 0;
  static int scanned_ucis = 0;

  if (scanned_ucis) return;
  scanned_ucis ++;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  for (engine = modules->sub; engine; engine = engine->next)
	    {
	      if (strcasecmp (engine->id, "uci")  != 0)
		continue;
	      ++i;
	      if (! engine->val)
		{
		  fprintf (stderr, "warning: uci %d has no name, skipping.\n", i);
		  continue;
		}
	      if (! (sim = find_sub (engine, "sim", 0)))		
		{
		  fprintf (stderr, "warning: uci %s has no sim component, skipping.\n", engine->val);
		  continue;
		}
	      if (! sim->val)
		{
		  fprintf (stderr, "warning: uci %s has no SIM child, skipping.\n", engine->val);
		  continue;
		}
	      if (toshapi)
		{
		  ucis [n_ucis].cmodel = parse_cmodel (sim, cmTypeUci, engine, modules);
		  if (! ucis [n_ucis].cmodel)
		    {
		      fprintf (stderr, "warning: uci %s has no usable cmodel, skipping.\n", engine->val);
		  continue;		  
		    }
		  ucis [n_ucis].module = modules;
		  n_ucis ++;
		  assert (n_ucis < ucis_len);
		}
	    }
	}
    }
}


static void
add_lbif (Node *module)
{
  Node *sim = find_sub (module, "local_bus", "sim", 0);
  if (! sim)
    return;

  if (! sim->val)
    {
      fprintf (stderr, "warning: local_bus for module %s has no SIM child, skipping.\n", module->val);
      return;
    }

  if (toshapi)
    {
      CModel *cmodel = parse_cmodel (sim, cmTypeBusArbitrator, module, module);
      char *iname;
      if (! cmodel)
	{
	  fprintf (stderr, "warning: local_bus for %s has no usable cmodel, skipping.\n", module->val);
	  return;
	}
      iname = xmalloc (10 + strlen (module->val) + 1);
      sprintf (iname, "local_bus_%s", module->val);
      cmodel->instance_name = iname;

      assert (cmodel->class_name);
      fprintf (dst_file, "  b->add_toshapi_local_bus_model (\"%s\", \"%s\");\n",
	       cmodel->class_name, cmodel->instance_name);
    }
}


static void
add_gbif (Node *module)
{
  Node *sim = find_sub (module, "global_bus_if", "sim", 0);
  if (! sim)
    return;

  if (! sim->val)
    {
      fprintf (stderr, "warning: global_bus_if for module %s has no SIM child, skipping.\n", module->val);
      return;
    }

  if (toshapi)
    {
      CModel *cmodel = parse_cmodel (sim, cmTypeBusArbitrator, module, module);
      char *iname;
      if (! cmodel)
	{
	  fprintf (stderr, "warning: global_bus_if for %s has no usable cmodel, skipping.\n", module->val);
	  return;
	}
      iname = xmalloc (14 + strlen (module->val) + 1);
      sprintf (iname, "global_bus_if_%s", module->val);
      cmodel->instance_name = iname;

      assert (cmodel->class_name);
      fprintf (dst_file, "  b->add_toshapi_global_bus_if_model (\"%s\", \"%s\");\n",
	       cmodel->class_name, cmodel->instance_name);
    }
}


static void
add_gbmif (Node *top)
{
  Node *sim = find_sub (top, "global_bus", "sim", 0);
  if (! sim)
    return;

  if (! sim->val)
    {
      fprintf (stderr, "warning: global_bus has no SIM child, skipping.\n");
      return;
    }

  if (toshapi)
    {
      CModel *cmodel = parse_cmodel (sim, cmTypeBusArbitrator, top, top);
      if (! cmodel)
	{
	  fprintf (stderr, "warning: global_bus has no usable cmodel, skipping.\n");
	  return;
	}
      assert (cmodel->class_name);
      cmodel->instance_name = "global_bus";
      fprintf (dst_file, "        add_toshapi_global_bus_model (\"%s\", \"%s\");\n",
	       cmodel->class_name, cmodel->instance_name);
    }
}



/* dsps get multiple passes made over them, and they're a little ugly
   to re-verify at the nodes-n-string level each time, so we verify them
   in a single pass and store them in a structured array for later passes. */

typedef struct dsp {
  Node *module;
  const char *name;
  const char *cgen_define;
  const char *sim;
  int cbus_if;
  int lbus_if;
  unsigned long lbus_addr;
  unsigned long lbus_size;
  const char *local_mem_list;
  int dmem_if_width;
  const char *cmodel_args;
  CModel *cmodel;
} dsp;

static dsp *dsps = 0;
static int dsps_len = 0;
static int n_dsps = 0;

static void
scan_dsps ()
{
  Node *cfgs, *modules, *dsp, *sim, *cgen_define;
  Node *cbus_if, *local_mem_list, *dmem_if_width;
  Node *lbus_if, *lbus_addr, *lbus_size, *cmodel_args;
  CModel *cmodel = NULL;
  int i = 0;

  if (dsps)
    return;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  for (dsp = modules->sub; dsp; dsp = dsp->next)
	    {
	      if (strcasecmp (dsp->id, "dsp")  != 0)
		continue;
	      ++i;
	      if (! dsp->val)
		{
		  fprintf (stderr, "warning: dsp %d has no name, skipping.\n", i);
		  continue;
		}
	      if (! (sim = find_sub (dsp, "sim", 0)))		
		{
		  fprintf (stderr, "warning: dsp %s has no SIM component, skipping.\n", dsp->val);
		  continue;
		}
	      if (! sim->val)
		{
		  fprintf (stderr, "warning: dsp %s has no SIM child, skipping.\n", dsp->val);
		  continue;
		}
	      if (toshapi)
		{
		  cmodel = parse_cmodel (sim, cmTypeDsp, dsp, modules);
		  if (! cmodel)
		    {
		      fprintf (stderr, "warning: dsp %s has no usable cmodel, skipping.\n", dsp->val);
		  continue;		  
		    }
		}

	      /* CBUS_IF is optional.  */
	      cgen_define = find_sub (dsp, "cgen_define", 0);
	      /* CBUS_IF is optional.  */
	      cbus_if = find_sub (dsp, "cbus_if", 0);
	      /* LBUS_IF is optional.  */
	      lbus_if = find_sub (dsp, "lbus_if", 0);

	      /* LOCAL_MEM_LIST is optional, but can't be specified with LBUS_IF=ON.  */
	      local_mem_list = find_sub (dsp, "local_mem_list", 0);
	      if (lbus_if && local_mem_list && lbus_if->val && local_mem_list->val
		  && strcmp (lbus_if->val, "ON") == 0)
		{
		  fprintf (stderr, "warning: DSP %s has both LBUS_IF=ON and LOCAL_MEM_LIST specified, skipping.\n", dsp->val);
		  continue;		  
		}

	      /* LBUS_IF, LBUS_ADDRESS and LBUS_SIZE are optional.  */
	      lbus_addr = find_sub (dsp, "lbus_address", 0);
	      lbus_size = find_sub (dsp, "lbus_size", 0);

	      /* DMEM_IF_WIDTH will be specified or provided with a default.  */
	      dmem_if_width = find_sub (dsp, "dmem_if_width", 0);
	      assert (dmem_if_width);

	      /* CMODEL_ARGS is optional.  */
	      cmodel_args = find_sub (dsp, "cmodel_args", 0);

	      if (! dsps || (n_dsps >= dsps_len))
		{
		  dsps_len += 128;
		  dsps = xrealloc (dsps, sizeof (struct dsp) * dsps_len);
		}
	      dsps [n_dsps].module = modules;
	      dsps [n_dsps].name = dsp->val;
	      dsps [n_dsps].sim = sim->val;
	      dsps [n_dsps].cmodel = cmodel;
	      dsps [n_dsps].dmem_if_width = dmem_if_width->ival;
	      if (cgen_define)
		dsps [n_dsps].cgen_define = cgen_define->val;
	      else
		dsps [n_dsps].cgen_define = NULL;

	      if (local_mem_list == NULL)
		dsps [n_dsps].local_mem_list = NULL;
	      else
		dsps [n_dsps].local_mem_list = local_mem_list->val;

	      dsps [n_dsps].cbus_if = (cbus_if && cbus_if->val && strcmp (cbus_if->val, "ON") == 0);
	      dsps [n_dsps].lbus_if = 0;
	      if (dsps [n_dsps].local_mem_list == NULL)
		{
		  if (lbus_if && lbus_if->val && strcmp (lbus_if->val, "ON") == 0)
		    {
		      dsps [n_dsps].lbus_if = 1;
		      if (lbus_addr)
			dsps [n_dsps].lbus_addr = lbus_addr->ival;
		      else
			dsps [n_dsps].lbus_addr = 0x00010000;
		      if (lbus_size)
			dsps [n_dsps].lbus_size = lbus_size->ival;
		      else
			dsps [n_dsps].lbus_size = 0x00010000;
		    }
		}

	      if (cmodel_args)
		{
		  dsps [n_dsps].cmodel_args = cmodel_args->val;
		  if (cmodel)
		    cmodel->cfg_args = cmodel_args->val;
		}
	      else
		{
		  dsps [n_dsps].cmodel_args = NULL;
		  if (cmodel)
		    cmodel->cfg_args = NULL;
		}

	      ++n_dsps;
	    }
	}
    }
}

/* peripherals get multiple passes made over them, and they're a little ugly
   to re-verify at the nodes-n-string level each time, so we verify them
   in a single pass and store them in a structured array for later passes. */

typedef struct hw_peripheral {
  const char *name;
  const char *sim;
  unsigned long mapped_addr;
  unsigned long mapped_size;
  const char *cmodel_args;
  const char *related_mm;
  int all_memory_map;
  CModel *cmodel;
} hw_peripheral;

static hw_peripheral *peripherals = 0;
static int peripherals_len = 0;
static int n_peripherals = 0;

static void
scan_peripherals ()
{
  Node *cfgs, *item, *sim;
  Node *mapped_addr, *mapped_size;
  Node *cmodel_args;
  Node *related_mm;
  Node *all_memory_map;
  CModel *cmodel = NULL;
  int i = 0;

  if (peripherals)
    return;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (item = find_sub (cfgs, "peripheral", 0); item; item = find_next (item, "peripheral"))
	{
	  ++i;

	  /* Check required sub-items.  */
	  if (! item->val)
	    {
	      fprintf (stderr, "warning: peripheral %d has no name, skipping.\n", i);
	      continue;
	    }
	  if (! (sim = find_sub (item, "sim", 0)))		
	    {
	      fprintf (stderr, "warning: peripheral %s has no sim component, skipping.\n", item->val);
	      continue;
	    }
	  if (! sim->val)
	    {
	      fprintf (stderr, "warning: peripheral %s has no SIM child, skipping.\n", item->val);
	      continue;
	    }
	  if (toshapi)
	    {
	      cmodel = parse_cmodel (sim, cmTypePeripheral, item, NULL);
	      if (! cmodel)
		{
		  fprintf (stderr, "warning: peripheral %s has no usable cmodel, skipping.\n", item->val);
		  continue;		  
		}
	    }
	  if (! (mapped_addr = find_sub (item, "mapped_address", 0)))
	    {
	      fprintf (stderr, "warning: peripheral %s has no MAPPED_ADDRESS child, skipping.\n", item->val);
	      continue;		  
	    }
	  if (! (mapped_size = find_sub (item, "mapped_size", 0)))
	    {
	      fprintf (stderr, "warning: peripheral %s has no MAPPED_SIZE child, skipping.\n", item->val);
	      continue;		  
	    }

	  /* ALL_MEMORY_MAP and RELATED_MM are optional, but one of them must be specified.  */
	  all_memory_map = find_sub (item, "all_memory_map", 0);

	  related_mm = find_sub (item, "related_mm", 0);
	  if ((! all_memory_map || ! all_memory_map->val || strcmp (all_memory_map->val, "ON") != 0)
	      && (! related_mm || ! related_mm->val))
	    {
	      fprintf (stderr, "warning: peripheral %s requires one of RELATED_MM or ALL_MEMORY_MAP=ON, skipping.\n", item->val);
	      continue;		  
	    }

	  /* CMODEL_ARGS is optional.  */
	  cmodel_args = find_sub (item, "cmodel_args", 0);

	  /* Allocate and populate the new peripheral.  */
	  if (! peripherals || (n_peripherals >= peripherals_len))
	    {
	      peripherals_len += 128;
	      peripherals = xrealloc (peripherals, sizeof (struct hw_peripheral) * peripherals_len);
	    }
	  peripherals [n_peripherals].name = item->val;
	  peripherals [n_peripherals].sim = sim->val;
	  peripherals [n_peripherals].cmodel = cmodel;
	  peripherals [n_peripherals].mapped_addr = mapped_addr->ival;
	  peripherals [n_peripherals].mapped_size = mapped_size->ival;

	  if (cmodel_args)
	    {
	      peripherals [n_peripherals].cmodel_args = cmodel_args->val;
	      if (cmodel)
		cmodel->cfg_args = cmodel_args->val;
	    }
	  else
	    {
	      peripherals [n_peripherals].cmodel_args = NULL;
	      if (cmodel)
		cmodel->cfg_args = NULL;
	    }

	  if (related_mm)
	    peripherals [n_peripherals].related_mm = related_mm->val;
	  else
	    peripherals [n_peripherals].related_mm = NULL;

	  if (all_memory_map && all_memory_map->val && strcmp (all_memory_map->val, "ON") == 0)
	    peripherals [n_peripherals].all_memory_map = 1;
	  else
	    peripherals [n_peripherals].all_memory_map = 0;

	  ++n_peripherals;
	}
    }
}

static void
do_peripheral_includes ()
{
  int i;

  scan_peripherals ();

  start_file (srcdir, "sid/component/families/mep/components.cxx", 0);

  find_line ("begin-peripheral-definitions", 1, 1, 1);
  if (peripherals && ! toshapi) for (i = 0; i < n_peripherals; ++i)
    {
      assert (peripherals[i].name);
      assert (peripherals[i].sim);
      fprintf (dst_file, "#ifndef _PERIPHERAL_%s_\n", peripherals[i].name);
      fprintf (dst_file, "#define _PERIPHERAL_%s_\n", peripherals[i].name);
      include_from (peripherals[i].sim, dst_file);
      fprintf (dst_file, "#endif // _PERIPHERAL_%s_\n", peripherals[i].name);
    }
  find_line ("end-peripheral-definitions", 0, 1, 1);

  find_line ("begin-peripheral-constructor-names", 1, 1, 1);
  if (peripherals && ! toshapi) for (i = 0; i < n_peripherals; ++i)
    {
      assert (peripherals[i].name);
      assert (peripherals[i].sim);
      fprintf (dst_file, "  types.push_back (\"peripheral-%s\");\n", peripherals[i].name);
    }
  find_line ("end-peripheral-constructor-names", 0, 1, 1);

  find_line ("begin-peripheral-constructors", 1, 1, 1);
  if (peripherals && ! toshapi) for (i = 0; i < n_peripherals; ++i)
    {
      assert (peripherals[i].name);
      assert (peripherals[i].sim);
      fprintf (dst_file, "  if (typeName == \"peripheral-%s\")\n", peripherals[i].name);
      fprintf (dst_file, "    return new %s (", peripherals[i].name);
      if (peripherals[i].cmodel_args)
	fputs (peripherals[i].cmodel_args, dst_file);
      fputs (");\n", dst_file);
    }
  find_line ("end-peripheral-constructors", 0, 1, 1);

  find_line ("begin-peripheral-destructors", 1, 1, 1);
  if (peripherals && ! toshapi) for (i = 0; i < n_peripherals; ++i)
    {
      assert (peripherals[i].name);
      assert (peripherals[i].sim);
      fprintf (dst_file, "  %s* p%d = dynamic_cast<%s*> (c);\n", peripherals[i].name, i, peripherals[i].name);
      fprintf (dst_file, "  if (p%d) { delete p%d; return; }\n", i, i);
    }
  find_line ("end-peripheral-destructors", 0, 1, 1);

  end_file ();
}


static struct { char *opt; char *mopt; } as_opt_map[] = {
  {"mul", "MUL"},     {"div", "DIV"},  {"bit", "BIT"},
  {"ldz", "LDZ"},     {"abs", "ABS"},  {"ave", "AVE"},
  {"min", "MINMAX"},  {"clp", "CLIP"}, {"sat", "SAT"},
  {"debug", "DEBUG"}, {"uci", "UCI"},  {"dsp", "DSP"},
  {0, 0}
};

static void
set_isa_mask_bit (unsigned isano, char *mask, unsigned mask_length)
{
  unsigned byteno = isano / 8;
  unsigned bitno = isano % 8;
  unsigned bitmask = 0x80 >> bitno;

  assert (byteno < mask_length);
  mask[byteno] |= bitmask;
}

static void
clear_isa_mask_bit (unsigned isano, char *mask, unsigned mask_length)
{
  unsigned byteno = isano / 8;
  unsigned bitno = isano % 8;
  unsigned bitmask = 0x80 >> bitno;

  assert (byteno < mask_length);
  mask[byteno] &= ~bitmask;
}

static void
print_isa_mask (char *mask, unsigned mask_length)
{
  int i;
  fprintf (dst_file, " { %d, \"", mask_length);
  for (i = 0; i < mask_length; ++i)
    fprintf (dst_file, "\\x%x", mask[i] & 0xff);
  fprintf (dst_file, "\" },");
}

static void
gen_isa_mask (unsigned isano, char *mask, unsigned mask_length)
{
  set_isa_mask_bit (isano, mask, mask_length);
  print_isa_mask (mask, mask_length);
  clear_isa_mask_bit (isano, mask, mask_length);
}

/* Generate CGEN bitmasks representing the isas supported by the
   given me_module beginning at the given isa_num.  */
static int
gen_isa_masks (Node *module, int isa_start)
{
  static unsigned mask_length = 0;
  static char *mask = NULL;
  unsigned isano;
  int copro_isas;
  int i;

  /* Allocate space for the masks.  Need space to generate masks
     to represent all isas.  */
  if (mask_length == 0)
    {
      mask_length = (isacount + 7) / 8;
      mask = xmalloc (mask_length);
    }
  for (i = 0; i < mask_length; ++i)
    mask[i] = 0;

  
  if (find_sub (module, "cop", 0))
    {
      /* Generate a mask for each coprocessor configuration.  */
      for (i = 0; i < 4; ++i)
	{
	  /* Mask for ISA_EXT_COPn_<length>.  */
	  isano = isa_start + 1 + i;
	  gen_isa_mask (isano, mask, mask_length);
	}

      /* Generate a mask for all cop isas.  */
      for (i = 0; i < 4; ++i)
	{
	  /* Mask for ISA_EXT_COPn_<length>.  */
	  isano = isa_start + 1 + i;
	  set_isa_mask_bit (isano, mask, mask_length);
	}
      print_isa_mask (mask, mask_length);
      for (i = 0; i < 4; ++i)
	{
	  /* Mask for ISA_EXT_COPn_<length>.  */
	  isano = isa_start + 1 + i;
	  clear_isa_mask_bit (isano, mask, mask_length);
	}
      copro_isas = 4;
    }
  else
    {
      /* Generate empty masks for each coprocessor configuration and
	 one empty mask for all cop isas.  */
      for (i = 0; i < 5; ++i)
	print_isa_mask (mask, mask_length);
      copro_isas = 0;
    }

  /* Generate a mask for all core isas.  */
  set_isa_mask_bit (0, mask, mask_length); /* ISA_MEP */
  isano = isa_start;  /* ISA_EXT_COREn */
  set_isa_mask_bit (isano, mask, mask_length);
  print_isa_mask (mask, mask_length);

  return isa_start + 1 + copro_isas;
}

static void
do_cgen_config_opc ()
{
  Node *cfgs, *modules;
  int vliw_bits;
  int i;
  struct cop_ip *ip;

  find_line ("begin-cop-ip-parse-handlers", 1, 1, 1);

  scan_cop_ip ();
  for (ip = cop_ips; ip; ip = ip->next)
    {
      fprintf (dst_file,
	       "static const char *\n"
	       "parse_%s_cr (CGEN_CPU_DESC cd,\n"
	       "\tconst char **strp,\n"
	       "\tCGEN_KEYWORD *keyword_table  ATTRIBUTE_UNUSED,\n"
	       "\tlong *field)\n"
	       "{\n"
	       "  return cgen_parse_keyword (cd, strp, & mep_cgen_opval_h_cr_%s, field);\n"
	       "}\n",
	       ip->ip, ip->ip);
      fprintf (dst_file,
	       "static const char *\n"
	       "parse_%s_ccr (CGEN_CPU_DESC cd,\n"
	       "\tconst char **strp,\n"
	       "\tCGEN_KEYWORD *keyword_table  ATTRIBUTE_UNUSED,\n"
	       "\tlong *field)\n"
	       "{\n"
	       "  return cgen_parse_keyword (cd, strp, & mep_cgen_opval_h_ccr_%s, field);\n"
	       "}\n",
	       ip->ip, ip->ip);
    }

  find_line ("end-cop-ip-parse-handlers", 0, 1, 1);

  find_line ("begin-cop-ip-print-handlers", 1, 1, 1);

  for (ip = cop_ips; ip; ip = ip->next)
    {
      fprintf (dst_file,
	       "static void\n"
	       "print_%s_cr (CGEN_CPU_DESC cd,\n"
	       "\tvoid *dis_info,\n"
	       "\tCGEN_KEYWORD *keyword_table ATTRIBUTE_UNUSED,\n"
	       "\tlong value,\n"
	       "\tunsigned int attrs)\n"
	       "{\n"
	       "  print_keyword (cd, dis_info, & mep_cgen_opval_h_cr_%s, value, attrs);\n"
	       "}\n",
	       ip->ip, ip->ip);
      fprintf (dst_file,
	       "static void\n"
	       "print_%s_ccr (CGEN_CPU_DESC cd,\n"
	       "\tvoid *dis_info,\n"
	       "\tCGEN_KEYWORD *keyword_table ATTRIBUTE_UNUSED,\n"
	       "\tlong value,\n"
	       "\tunsigned int attrs)\n"
	       "{\n"
	       "  print_keyword (cd, dis_info, & mep_cgen_opval_h_ccr_%s, value, attrs);\n"
	       "}\n",
	       ip->ip, ip->ip);
    }

  find_line ("end-cop-ip-print-handlers", 0, 1, 1);

  find_line ("begin-all-core-isas", 1, 1, 1);

  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, "  cgen_bitset_add (& mep_all_core_isas_mask, ISA_EXT_CORE%d);\n", i);
	  ++i;
	}
      
    }

  find_line ("end-all-core-isas", 0, 1, 1);

  find_line ("begin-all-cop-isas", 1, 1, 1);

  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  if (find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, "  cgen_bitset_add (& mep_all_cop_isas_mask, ISA_EXT_COP%d_16);\n", i);
	      fprintf (dst_file, "  cgen_bitset_add (& mep_all_cop_isas_mask, ISA_EXT_COP%d_32);\n", i);
	      fprintf (dst_file, "  cgen_bitset_add (& mep_all_cop_isas_mask, ISA_EXT_COP%d_48);\n", i);
	      fprintf (dst_file, "  cgen_bitset_add (& mep_all_cop_isas_mask, ISA_EXT_COP%d_64);\n", i);
	    }
	  ++i;
	}
      
    }

  find_line ("end-all-cop-isas", 0, 1, 1);

  find_line ("config-map-start", 1, 1, 1);
  fputs ("  /* Default entry: mep core only, all options enabled. */\n", dst_file);
  fprintf (dst_file, "  { \"\", 0, EF_MEP_CPU_%s, 1, 0, {1,\"\\x0\"}, {1,\"\\x0\"}, {1,\"\\x0\"}, {1,\"\\x0\"}, {1,\"\\x0\"}, {1,\"\\x80\"}, OPTION_MASK },\n",
	   upcase (mep_core_names[mep_core_type]));

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      int ext_isa = 1;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  vliw_bits = cop_vliw_bits (modules);
	  
	  fprintf (dst_file, "  { \"%s\",", modules->val);
	  fprintf (dst_file, " CONFIG_%s,", upcase (modules->val));
	  fprintf (dst_file, " EF_MEP_CPU_%s,", upcase (mep_core_names[mep_core_type]));
	  fprintf (dst_file, " %d,", mep_endian_type == MEP_ENDIAN_LITTLE ? 0 : 1);
	  fprintf (dst_file, " %d,", vliw_bits);
	  ext_isa = gen_isa_masks (modules, ext_isa);

	  fprintf (dst_file, "\n\t  0");
	  if (core_opt_set (modules, "cop") || find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, "\n\t| (1 << CGEN_INSN_OPTIONAL_CP_INSN)");
	      if (cop_data_bus_width (modules) == 64)
		fprintf (dst_file, "\n\t| (1 << CGEN_INSN_OPTIONAL_CP64_INSN)");
	    }
	  if (core_opt_set (modules, "dsp") || find_sub (modules, "dsp", 0))
	    fprintf (dst_file, "\n\t| (1 << CGEN_INSN_OPTIONAL_DSP_INSN)");
	  if (core_opt_set (modules, "uci") || find_sub (modules, "uci", 0))
	    fprintf (dst_file, "\n\t| (1 << CGEN_INSN_OPTIONAL_UCI_INSN)");
	  for (i = 0; as_opt_map[i].opt; i++)
	    if (core_opt_set (modules, as_opt_map[i].opt))
	      fprintf (dst_file, "\n\t| (1 << CGEN_INSN_OPTIONAL_%s_INSN)", as_opt_map[i].mopt);
	  fprintf (dst_file, " },\n");
	}
    }

  find_line ("config-map-end", 0, 1, 1);
}



static void
parse_any_gmap ()
{
  Node *gmap_node = find_sub (currentcfg, "global_map", 0);
  Gmap *g;
  Gmap *prev;

  /* If no gmap was specified, provide a default.  */    
  if (! gmap_node || ! gmap_node->val)
    {
      /*
	0x0000_0000:0x0020_0000:ROM :     ::global:memory:ro;
	0x0080_0000:0x0080_0000:RAM1:Cache::global:memory:rw;
	0x8080_0000:0x0080_0000:RAM2:     ::global:memory:rw;
      */
      name_and_num s = {0, 0};
      g = new_gmap (0x0, 0x200000, "ROM", nocache, s,
		    sc_global, memory, readonly);
      currentgmap = g;
      g->next = new_gmap (0x800000, 0x800000, "RAM1", cache, s,
			  sc_global, memory, readwrite);
      g = g->next;
      g->next = new_gmap (0x80800000, 0x800000, "RAM2", nocache, s,
			  sc_global, memory, readwrite);
      return;
    }

  /* Otherwise, parse the gmap file which was specified.  */
  gmapfilename = resolve_local_filename (gmap_node->val);
  gmapin = fopen (gmapfilename, "r");
  if (! gmapin)
    {
      fprintf (stderr, "cannot open gmap file %s\n", gmapfilename);
      exit (EXIT_FAILURE);
    }
  fl_context = fl_gmap;
  gmapparse ();
  if (! currentgmap)
    {
      fprintf (stderr, "parse error in gmap file %s\n", gmapfilename);
      exit (EXIT_FAILURE);
    }
  fclose (gmapin);

  /* Check that module names specified in local shadows exist.  */
  prev = NULL;
  for (g = currentgmap; g; prev = g, g = g->next)
    {
      Node *m;
      if (! g->shadow_mod_name)
	continue;
      for (m = find_sub (currentcfg, "me_module", 0); m; m = find_next (m, "me_module"))
	{
	  if (m->val && strcasecmp (m->val, g->shadow_mod_name) == 0)
	    break;
	}
      if (m)
	continue;
      fprintf (stderr, "Warning: Ignoring %s region: "
	       "Module name %s for local shadow does not exist\n",
	       g->name ? g->name : "unnamed", g->shadow_mod_name);
      if (prev)
	prev->next = g->next;
      else
	currentgmap = g->next;
    }

  if (verbose)
    fprintf (stderr, "parsed gmap file %s OK\n", gmapfilename);

  /* Trim whitespace from the end of the name of each map.  */
  for (g = currentgmap; g; g = g->next)
    {
      int i, len = strlen (g->name);
      for (i = len - 1; i >= 0; --i)
	if (! isspace (g->name[i]))
	  break;
      if (i < len - 1)
	{
	  char *p = strdup (g->name);
	  p[i + 1] = '\0';
	  g->name = p;
	}

      if (verbose >= 3)
	{
	  fprintf (stderr, "%8.8lx %8.8lx \"%s\" %d %8.8lx %d %d %d\n", 
		   g->start, g->size, g->name, g->cache, 
		   g->shadow, g->scope, g->type, g->access);
	}
    }
}

static int
test_module (const char *mod_name, int need_else)
{
  fprintf (dst_file, "  %sif (get_module_type () == \"%s\")\n",
	   need_else ? "else " : "", mod_name);
  fputs ("    {\n", dst_file);
  return 1;
}

static void
pass_peripheral_areas (Node *module, const char *cache_type)
{
  /* pass the addresses of any peripheral accessible from this module.
     That is, peripherals which are ALL_MEMORY_MAP or which name this
     particular module as the RELATED_MM.  */
  int i;
  scan_peripherals ();
  for (i = 0; i < n_peripherals; ++i)
    {
      if (! peripherals[i].all_memory_map
	  && strcasecmp (peripherals[i].related_mm, module->val) != 0)
	continue;
      fprintf (dst_file, "      %s->pass (m.low(0x%lx).high(0x%lx));\n",
	       cache_type,
	       peripherals[i].mapped_addr,
	       peripherals[i].mapped_addr + peripherals[i].mapped_size - 1);
	       
    }
}

/* Set up cache/pass regions for the caches in the configuration.  */
static void
map_cache (const char *cache_type)
{
  Gmap *gmap;
  Node *cfgs;

  /* Pass local memory and cache test areas.  */
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      Node *icache_size;
      Node *dcache_size;
      int mod_num = 0;
      for (modules = find_sub (cfgs, "me_module", 0); 
	   modules; modules = find_next (modules, "me_module"))
	{
	  icache_size = find_sub (modules, "me_engine", "icache", "size", 0);
	  dcache_size = find_sub (modules, "me_engine", "dcache", "size", 0);

	  /* If the cache we're configuring was not specified, then there is
	     nothing to generate.  */
	  if (*cache_type == 'i')
	    {
	      if (! icache_size)
		continue;
	    }
	  else if (! dcache_size)
	    continue;
	  assert (icache_size || dcache_size);

	  test_module (modules->val, mod_num);
	  pass_peripheral_areas (modules, cache_type);
	  fputs ("    }\n", dst_file);

	  ++mod_num;
	}
    }
}

static void
do_sid_gmap_config ()
{
  int i, j;
  Gmap *gmap;
  Node *cfgs;

  /* construct global memory objects */
  find_line ("begin-global-memory-regions", 1, 1, 1);
  for (i = 0, j=0, gmap = currentgmap; gmap; gmap = gmap->next, ++i)
    {
      if (gmap->scope == sc_global 
	  && ((gmap->type == memory && ! gmap->shadow_specified)
	      || gmap->type == mainbus))
	{
	  fprintf (dst_file, 
		   "    mems.push_back (new MepMemRegionCfg (\"shared-mem%d\", 0x%lx, 0x%lx, 10, 1, %s, %s));\n",
		   j++, gmap->start, gmap->size,
		   gmap->cache == cache ? "true" : "false",
		   gmap->access == readonly ? "true" : "false");
	}
    }
  find_line ("end-global-memory-regions", 0, 1, 1);

  /* global map -> global map (shadows)
     Implement global shadows by having the global map map back onto itself
     at the shadow address.  */

  find_line ("begin-shadow-regions", 1, 1, 1);
  for (gmap = currentgmap; gmap; gmap = gmap->next)
    {
      if (gmap->type == shadow || gmap->shadow_specified)
	{
	  fprintf (dst_file, 
		   "    shadows.push_back (new MepShadowRegion (0x%lx, 0x%lx, 0x%lx, %s",
		   gmap->start, gmap->size, gmap->shadow,
		   gmap->cache == cache ? "true": "false");
	  if (gmap->shadow_mod_name)
	    fprintf (dst_file, ", \"%s\"", gmap->shadow_mod_name);
	  fputs ("));\n", dst_file);
	}
    }
  find_line ("end-shadow-regions", 0, 1, 1);

  /* construct peripheral objects */
  scan_peripherals ();
  find_line ("begin-peripherals", 1, 1, 1);
  if (peripherals)
    {
      for (i = 0; i < n_peripherals; ++i)
	{
	  if (toshapi)
	    {
	      fprintf (dst_file, 
		       "    add_toshapi_peripheral (\"%s\", \"%s\", 0x%lx, 0x%lx);\n",
		       peripherals[i].cmodel->class_name,
		       peripherals[i].cmodel->instance_name,
		       peripherals[i].mapped_addr, peripherals[i].mapped_size);
	    }
	  else
	    {
	      fprintf (dst_file, 
		       "    add_peripheral (\"%s\", 0x%lx, 0x%lx);\n",
		       peripherals[i].name,
		       peripherals[i].mapped_addr, peripherals[i].mapped_size);
	    }
	}
    }

  /* Pull in GBMIF definitions.  */
  add_gbmif (currentcfg);
  find_line ("end-peripherals", 0, 1, 1);

  /* board main map -> peripherals.
     Map board's main memory to global memory for access to peripheral
     components which are already mapped there.  */
  scan_peripherals ();
  find_line ("begin-local-peripheral-mappings", 1, 1, 1);
  if (peripherals)
    {
      for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
	{
	  const char *_else = "";
	  Node *modules;
	  for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	    {
	      /* incorporate any accessible peripherals into the module. Only add
		 peripherals which are ALL_MEMORY_MAP or which name this
		 particular module as the RELATED_MM.  */
	      int test_printed = 0;
	      int i;
	      for (i = 0; i < n_peripherals; ++i)
		{
		  if (! peripherals[i].all_memory_map
		      && strcasecmp (peripherals[i].related_mm, modules->val) != 0)
		    continue;
		  if (! test_printed)
		    {
		      fprintf (dst_file, "      %sif (board->get_module_type () == \"%s\")\n",
			       _else, modules->val);
		      fputs ("        {\n", dst_file);
		      test_printed = 1;
		    }
		  fprintf (dst_file, 
			   "          map_peripheral (board, 0x%lx, 0x%lx);\n",
			   peripherals[i].mapped_addr,
			   peripherals[i].mapped_size);
		}
	      if (test_printed)
		{
		  fputs ("        }\n", dst_file);
		  _else = "else ";
		}
	    }
	}
    }
  find_line ("end-local-peripheral-mappings", 0, 1, 1);

  /* local memories defined in gmap file */
  find_line ("begin-gmap-local-memory", 1, 1, 1);
  for (gmap = currentgmap; gmap; gmap = gmap->next)
    {
      /* 0x200000 - 0x2FFFFF is the IMEM/DMEM local region, which we
	 configure separately since it is part of the "standard" mep memory
	 map, if such a thing can really be said to exist. Other
	 globally-defined local memory regions we add here. */
      if (gmap->scope == sc_local
	  && (gmap->start < 0x200000 || 0x2FFFFF < gmap->start)) 
	fprintf (dst_file,
		 "   add_local_mem (0x%lx, 0x%lx);\n",
		 gmap->start, gmap->size);
    }
  find_line ("end-gmap-local-memory", 0, 1, 1);

  /* cache/pass regions */
  find_line ("begin-icache-settings", 1, 1, 1);
  map_cache ("icache");
  find_line ("end-icache-settings", 0, 1, 1);

  find_line ("begin-dcache-settings", 1, 1, 1);
  map_cache ("dcache");
  find_line ("end-dcache-settings", 0, 1, 1);
}


static struct {
  int specified;
  unsigned long address;
  unsigned reg_num;
} mm_int = {0, 0, 0};

static void
scan_mm_int ()
{
  Node *cfgs;
  if (mm_int.specified)
    return; /* already done */

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *address, *reg_num;
      Node *item = find_sub (cfgs, "mm_int", 0);
      if (! item)
	continue;

      address = find_sub (item, "address", 0);
      if (! address)
	{
	  fputs ("Warning: No address specified for MM_INT. Skipping\n", stderr);
	  continue;
	}
      mm_int.address = address->ival;

      reg_num = find_sub (item, "reg_num", 0);
      if (reg_num)
	mm_int.reg_num = reg_num->ival;

      mm_int.specified = 1;
      break; /* only configure one MM_INT */
    }
}

typedef enum irq_type_t
{irq_engine = 0, irq_dsp = 1, irq_peripheral = 2} irq_type_t;

typedef struct {
  Node *irq_node;
  Node *module;
  irq_type_t irq_type; 
  int written;
  int channel;
  char irq_str [64];
  const char *src_module;
  const char *instance;
  const char *signal;
} irq_t;

static irq_t *irq = 0;
static int irq_len = 0;
static int n_irq = 0;
enum {irq_hw_bound = 6};

static void
scan_irq (Node *modules)
{
  int i;
  Node *item;
  Node *item2;

  item = find_sub (modules, "irq", 0);
  if (! item)
    return;

  if (n_irq >= irq_len)
    {
      irq_len += 32;
      irq = xrealloc (irq, sizeof (irq_t) * irq_len);
    }

  for (i = 0 ; i < 32 ; i++)
    {
      char namebuf [7];
      char *item_val = &irq [n_irq].irq_str[0];

      if (sprintf (namebuf, "int%d", i) == -1)
	{
	  perror ("sprintf");
	  continue;
	}
      item2 = find_sub (item, namebuf, 0);
      if (!item2)
	continue;

      irq [n_irq].irq_node = item2;
      irq [n_irq].module = modules;
      irq [n_irq].written = 0;
      irq [n_irq].channel = i;
      strcpy (item_val, item2->val);
      irq [n_irq].src_module = mep_strtok_r (item_val, ":", &item_val);
      irq [n_irq].instance = mep_strtok_r (item_val, ":", &item_val);
      irq [n_irq].signal = mep_strtok_r (item_val, ":", &item_val);
      if (!irq [n_irq].signal)
	{
	  irq [n_irq].signal = irq [n_irq].instance;
	  irq [n_irq].instance = irq [n_irq].src_module;
	  irq [n_irq].src_module = modules->val;
	}
      n_irq += 1;
    }
}


Node*
acdb_scan_dsps (Node *modules, const char **dsp_name, const char **local_mem_list_val)
{
  Node *dsp, *local_mem_list;
  Node *lbus_if;

  *dsp_name = NULL;
  *local_mem_list_val = NULL;
  for (dsp = modules->sub; dsp; dsp = dsp->next)
    {
      if (strcasecmp (dsp->id, "dsp")  != 0)
	continue;

      *dsp_name = dsp->val;

      lbus_if = find_sub (dsp, "lbus_if", 0);
      if( lbus_if != NULL && lbus_if->val && strcmp(lbus_if->val, "ON") == 0)
	return lbus_if;

      local_mem_list = find_sub (dsp, "local_mem_list", 0);
      if (local_mem_list != NULL)
	*local_mem_list_val = local_mem_list->val;
    }
  return NULL;
}


typedef struct {
  Node *module;
  int channel_bitw;
  int n_hw_req;
  struct 
  {
    char hw_req_str [32];
    const char *instance;
    const char *signal;} hw_req [6];
} dmac_t;

static dmac_t *dmac = 0;
static int dmac_len = 0;
static int n_dmac = 0;
enum {dmac_hw_bound = 6};

/* Parse the DMAC clause and cache into dmac.  
   ??? Enhance for use by emit_dmac_hw_req.  */

static void
scan_dmac ()
{
  int i;
  char *instance;
  Node *cfgs;
  Node *mod;
  Node *item;
  Node *item2;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (mod = find_sub (cfgs, "me_module", 0);
           mod;
           mod = find_next (mod, "me_module"))
        {
	  int hr;
          if (! dmac || (n_dmac >= dmac_len))
                {
                  dmac_len += 32;
                  dmac = xrealloc (dmac, sizeof (dmac_t) * dmac_len);
                }

          item = find_sub (mod, "dmac", 0);
          if (! item)
            continue;
          item2 = find_sub (item, "channel_bitw", 0);
          dmac [n_dmac].channel_bitw = item2 ? item2->ival : 1;
          dmac [n_dmac].module = mod;

	  hr = 0;
          for (i = 0 ; i < dmac [n_dmac].channel_bitw ; i++)
            {
              char namebuf [8];
              char *item_val;

              if (sprintf (namebuf, "hw_req%d", i) == -1)
                {
                  perror ("sprintf");
                  continue;
                }
              item2 = find_sub (item, namebuf, 0);
              if (!item2)
                continue;
      
              item_val = &dmac [n_dmac].hw_req[hr].hw_req_str[0];
              strcpy (item_val, item2->val);
              instance = mep_strtok_r (item_val, ":", &item_val);
              dmac [n_dmac].hw_req[hr].signal = mep_strtok_r (item_val, ":", &item_val);
              if (dmac [n_dmac].hw_req[hr].signal)
		{
		  dmac [n_dmac].hw_req[hr].instance = instance;
		  ++hr;
		}
            }
          dmac [n_dmac].n_hw_req = hr;
          n_dmac += 1;
        }
    }
}

typedef struct {
  Node *module;
  int origin;
  int length;
} dmem_t;

static dmem_t *dmem = 0;
static int dmem_len = 0;
static int n_dmem = 0;
enum {dmem_hw_bound = 6};

/* Parse the DMEM clause and cache into dmem.  
   ??? Enhance for use by find_ld_imem_dmem.  */

static void
scan_dmem (Node *module)
{
  const Node *item;
  long imem_size = 0;

  dmem_len += 32;
  dmem = xrealloc (dmem, sizeof (dmem_t) * dmem_len);

  dmem [n_dmem].module = module;

  item = find_sub (module, "me_engine", "imem", "size", 0);
  if (item)
    {
      imem_size = item->ival;
    }

  /* Add the DMEM sections.  */
  item = find_sub (module, "me_engine", "dmem", "size", 0);
  if (item)
    {
      long dmem_size = item->ival;
      if (dmem_size)
	{
	  long dmem_base[4];
	  long dmem_banks;
	  long i;
	  if ((item = find_sub (module, "me_engine", "dmem", "fixed_start_address", 0))
	      && strcmp (item->val, "YES") == 0)
	    dmem_base[0] = 0x80000;
	  else
	    {
	      /* 
	       * These tables represent the dmem base address values for the various
	       * dmem (rows) and imem (columns) combinations possible as per the 
	       * MeP Media User's Manual Rev. 5.0, section 4.6.2.
	       * 
	       */
	      int imem_limit[] = {0, 8, 16, 32};
	      int dmem_limit[] = {0, 8, 16, 32, 64, 128};
	      long dmem_base_address[][4] = {
/*             imem:	none,    1-8k,  12-16k,  24-32k */
/* dmem:    none */ {0x00000, 0x02000, 0x04000, 0x08000},
/* dmem:   1-8k  */ {0x00000, 0x02000, 0x04000, 0x08000},
/* dmem:  12-16k */ {0x00000, 0x04000, 0x04000, 0x08000},
/* dmem:  24-32k */ {0x00000, 0x08000, 0x08000, 0x08000},
/* dmem:  48-64k */ {0x00000, 0x10000, 0x10000, 0x10000},
/* dmem: 96-128k */ {0x00000, 0x20000, 0x20000, 0x20000},
	      };
	      int imem_index = -1;
	      int dmem_index = -1;
	      /*  find the imem limit in the table.  */
	      for (i = 0; i < sizeof (imem_limit)/sizeof (*imem_limit); i++) 
		{
		  if (imem_size <= imem_limit[i]) 
		    {
		      imem_index = i;
		      break;
		    }
		}
	      /*  find the dmem limit in the table.  */
	      assert (dmem_size);
	      for (i = 0; i < sizeof (dmem_limit)/sizeof (*dmem_limit); i++) 
		{
		  if (dmem_size <= dmem_limit[i]) 
		    {
		      dmem_index = i;
		      break;
		    }
		}
	      assert (dmem_index >= 0 && imem_index >= 0);
	      dmem_base[0] = dmem_base_address[dmem_index][imem_index];
	    }

	  item = find_sub (module, "me_engine", "dmem", "bank_num", 0);
	  dmem_banks = item ? item->ival : 2;
	  assert (dmem_banks <= 4);
	  for (i = 0; i < dmem_banks; ++i)
	    {
	      if (! dmem || (n_dmem >= dmem_len))
		{
		  dmem_len += 32;
		  dmem = xrealloc (dmem, sizeof (dmem_t) * dmem_len);
		}

	      if (((dmem_size == 6) || (dmem_size == 12) || (dmem_size == 24)) &&
		  (dmem_banks == 2)) 
		{ /* adjust up to the next power of two  */
		  dmem_base[i] = dmem_base[0] + (i * ((dmem_size * 1024) * 2 / 3));	
		} 
	      else 
		dmem_base[i] = dmem_base[0] + (i * (dmem_size * 1024 / dmem_banks));

	      dmem [n_dmem].origin = 0x200000 + dmem_base[i];
	      dmem [n_dmem].length = (dmem_size * 1024) / dmem_banks;
	      n_dmem += 1;
	    }
	}
    }
}

/* Given X, an unsigned number, return the largest int Y such that 2**Y <= X.
   If X is 0, return -1.  */

static int
floor_log16 (x)
     int x;
{
  int log = -1;
  while (x != 0)
    log++,
    x >>= 4;
  return log;
}

/* Convert Arcadia input files to cgen files as needed.  */

void
process_arcadia_files (Node *top)
{
  static char *a2cgen = 0;
  static int module_num = 0;
  static char *subs_to_check[] = {"uci", "dsp", "cop"};
  static char *opts_to_pass[] = {"-u", "-d", "-c"};
  static char *arcadia_cmd = "%s --api %d %s %s -n %d -o %s %s %s";
  int i, j, k;
  Node *acd;
  Node *cfgs; Node *modules;
  char *isa_fname, *cmd, *iopt;
  char *header_fname, *class_fname, *info_fname;
  const char *acd_fname;
  char *extra_opts;
  int extra_opts_len;

  if (nobuild)
    return; /* Nothing to do */

  module_num ++;

  for (i=0; i<3; i++)
    {
      header_s *h;
      acd = find_sub (top, subs_to_check[i], "acdb", NULL);
      if (! acd || !acd->val || !acd->val[0])
	{
	  if (i == 2 && top->val)
	    {
	      /* If we're processing the coprocessor, create a header
		 for this module.  */
	      Node *ip;
	      static const char *hfmt = "gcc/config/mep/%s.h";
	      char *header = (char *) xmalloc (strlen (hfmt) + strlen (top->val) + 1);
	      sprintf (header, hfmt, top->val);
	      start_file (srcdir, header, 0);

	      fputs ("/* Header created by MeP-Integrator */\n", dst_file);

	      /* If the coprocessor has an IP spec, then copy the contents of the
		 pregenerated header.  Otherwise generate the contents.  */
	      ip = find_sub (top, "COP", "IP", 0);
	      if (ip)
		{
		  char *fname = concat (srcdir, "/gcc/config/mep/", downcase (ip->val), "-template.h", 0);
		  include_from (fname, dst_file);
		}
	      else
		{
		  fputs ("#undef __section\n", dst_file);
		  fputs ("#define __section(_secname) __attribute__((section(#_secname)))\n", dst_file);
		  fputs ("#undef mep_nop\n", dst_file);
		  fputs ("#define mep_nop() __asm__ volatile (\"nop\")\n", dst_file);
		}

	      find_line (NULL, 0, 0, 1);
	      end_file ();
	      h = (header_s *) xmalloc (sizeof (header_s));
	      h->next = the_headers;
	      the_headers = h;
	      h->header = strdup (top->val);
	    }
	  continue;
	}

      if (a2cgen == 0)
	a2cgen = find_a2cgen ();

      isa_fname = cpu_fname_from_arcadia_fname (acd->val, module_num, "cpu");

      if (i == 2 && top->val)
	{
	  const char *ifmt = "-i %s/gcc/config/mep/%s.h";
	  iopt = (char *) xmalloc (strlen(ifmt) + strlen(srcdir) + strlen (top->val) + 1);
	  sprintf(iopt, ifmt, srcdir, top->val);
	  h = (header_s *) xmalloc (sizeof (header_s));
	  h->next = the_headers;
	  the_headers = h;
	  h->header = strdup (top->val);
	}
      else
	iopt = "";

      extra_opts = NULL;
      extra_opts_len = 0;
      if (subs_to_check [i] == "dsp"
	  || subs_to_check [i] == "uci")
	{
	  header_fname = cpu_fname_from_arcadia_fname (acd->val, module_num, "h");
	  class_fname = cpu_fname_from_arcadia_fname (acd->val, module_num, "cxx");
	  info_fname = cpu_fname_from_arcadia_fname (acd->val, module_num, "info");
	  extra_opts_len = 16	/* -g1 X -g2 Y -g3 Z */
	    + strlen (header_fname) + strlen (class_fname) + strlen (info_fname);
	  extra_opts = (char *) xmalloc (extra_opts_len + 1); /* + 1 for nul */
	  sprintf (extra_opts, " -g1 %s -g2 %s -g3 %s ", header_fname, class_fname, info_fname);
	}

      if (warn_all)
	{
	  int old_len = extra_opts_len;
	  extra_opts_len += 11;
	  extra_opts = xrealloc (extra_opts, extra_opts_len + 1);
	  extra_opts [old_len] = '\0';
	  strcat (extra_opts, " --warn-all");
	}

      acd_fname = resolve_local_filename(acd->val);
      cmd = (char *) xmalloc (strlen (arcadia_cmd)
			      + strlen (a2cgen)
			      + 2	/* longest opts_to_pass */
			      + 12	/* largest integer for -n */
			      + strlen (iopt)
			      + strlen (acd_fname)
			      + strlen (isa_fname)
			      + extra_opts_len
			      + 1	/* nul */);
      sprintf (cmd, arcadia_cmd, a2cgen, toshapi_version, opts_to_pass[i],
	       iopt, module_num, isa_fname, extra_opts ? extra_opts : "" ,
	       acd_fname);
      if (extra_opts)
	free (extra_opts);

      add_node (acd, "CGEN_DEFINE", isa_fname, N_QSTR, 0, acd->filename,
		acd->lineno);

      if (subs_to_check [i] == "dsp"
	  || subs_to_check [i] == "uci")
	{
	  char *sim_fname = absolute_filename (info_fname);
	  add_node (acd->next, "SIM", sim_fname, N_QSTR, 0, acd->filename,
		    acd->lineno);
	}

      if (subs_to_check [i] == "dsp")
	{
	  /* DSP [..] {ACDB...; LOCAL_MEM_LIST...;} */
	  int have_opt_name;
	  int add_comma;
	  const char *local_mem_list;
	  const char *dsp_name;

	  cmd = xrealloc (cmd, strlen (cmd) + 9 + strlen (mep_core_names[mep_core_type]) + 1);
	  sprintf (cmd + strlen(cmd), " --core %s ", mep_core_names[mep_core_type]);

	  if (acdb_scan_dsps (top, &dsp_name, &local_mem_list))
	    {
	      cmd = xrealloc(cmd,strlen(cmd) + 14);
	      strcat(cmd, " --lbus lbus ");
	    }
	  else if (local_mem_list)
	    {
	      int cmd_len;
	      cmd = xrealloc (cmd, strlen (cmd) + strlen (local_mem_list) + 9);
	      strcat (cmd, " --lmem ");
	      for (j = 0, cmd_len = strlen (cmd);
		   j < strlen (local_mem_list); j++)
		{
		  if (local_mem_list[j] == ',')
		    cmd[cmd_len] = ':';
		  else
		    cmd[cmd_len] = local_mem_list[j];
		  cmd_len += 1;
		}
	      cmd[cmd_len] = '\0';
	    }

	  /* IRQ {INT0 = "dsp_sample:sig";} */
	  have_opt_name = add_comma = 0;
	  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next) {
	    for(modules = find_sub(cfgs,"me_module",0); modules; modules = find_next (modules,"me_module")) {
	      scan_irq (modules);
	      for (j = 0; j < n_irq; ++j)
		{
		  if (strcmp(irq[j].src_module,top->val) == 0
		      && strcmp (irq[j].instance, dsp_name) == 0)
		    {
		      if (! have_opt_name)
			{
			  cmd = xrealloc (cmd, strlen (cmd) + 9);
			  strcat (cmd, " --intr ");
			  have_opt_name = 1;
			}
		      cmd = xrealloc (cmd, strlen (cmd) + strlen (irq[j].signal) + 2);
		      if (add_comma)
			strcat (cmd, ":");
		      strcat (cmd, irq[j].signal);
		      add_comma = 1;
		    }
		}
	      n_irq = 0;
	    }
	  }

	  /* DMAC {HW_REQ0 = "dsp_sample:sig";} */
	  scan_dmac ();
	  have_opt_name = add_comma = 0;
	  for (j = 0; j < n_dmac; ++j)
	    {
	      if (dmac[j].module == top)
		for (k = 0; k < dmac[j].n_hw_req; k++)
		  if (dmac[j].hw_req[k].instance &&
		      strcmp (dmac[j].hw_req[k].instance, dsp_name) == 0)
		    {
		      if (! have_opt_name)
			{
			  cmd = xrealloc (cmd, strlen (cmd) + 8);
			  strcat (cmd, " --dma ");
			  have_opt_name = 1;
			}
		      cmd = xrealloc (cmd, strlen (cmd)
				      + strlen (dmac[j].hw_req[k].signal) + 2);
		      if (add_comma)
			strcat (cmd, ":");
		      strcat (cmd, dmac[j].hw_req[k].signal);
		      add_comma = 1;
		    }
	    }
	  n_dmac = 0;

	  /* DMEM {SIZE = N; BANK_NUM = N;} */
	  scan_dmem (top);
	  add_comma = 0;
	  for (j = 0; j < n_dmem; ++j)
	    {
	      char buffer [64];
	      if (! add_comma)
		{
		  cmd = xrealloc (cmd, strlen (cmd) + 9);
		  strcat (cmd, " --dmem ");
		}
		  
	      cmd = xrealloc (cmd, strlen (cmd)
			      + floor_log16 (dmem[j].origin)
			      + floor_log16 (dmem[j].length)
			      + 9 /* :0xN:0xN */);
	      if (add_comma)
		strcat (cmd, ":");
	      sprintf (buffer, "0x%x:0x%x",
		       dmem[j].origin, dmem[j].length);
	      strcat (cmd, buffer);
	      add_comma = 1;
	    }
	  n_dmem = 0;
	}

      if (verbose)
	fprintf(stderr, "Converting: %s\n", cmd);
      if (system (cmd))
	exit (EXIT_FAILURE);

      free (cmd);
      if (iopt[0])
	free (iopt);
    }
}

static Node *modules_so_far [32];
static int n_msf = 0;

static void
add_msf (Node *module)
{
  int i;
  for (i = 0 ; i < n_msf; i++)
    if (modules_so_far [i] == module)
      return; /* already added */

  assert (n_msf < 32);
  modules_so_far [n_msf] = module;
  n_msf += 1;
}

static int
is_irq_source (Node *module)
{
  int i;
  for (i = 0; i < n_irq; ++i)
    if (strcasecmp (module->val, irq [i].src_module) == 0)
      return 1;
  return 0;
}

static Node *
check_irq_mod (Node *modules, int irq_idx)
{
  int i;

  add_msf (modules);
  
  if (irq [irq_idx].written == 1)
    return 0;
  irq [irq_idx].written = 1;

  /* destination in the current module  */
  if (modules == irq [irq_idx].module)
    {
      /* source in the current module  */
      if (strcasecmp (modules->val, irq [irq_idx].src_module) == 0)
	return modules;
  
      /* source in a previous module */
      for (i = 0 ; i < n_msf; i++)
	if (strcasecmp (modules_so_far [i]->val, irq [irq_idx].src_module) == 0)
	  return modules_so_far [i];
    }

  /* destination in a previous module, source in the current module */
  for (i = 0 ; i < n_msf; i++)
    if (modules_so_far [i] == irq [irq_idx].module)
      {
	if (strcasecmp (modules->val, irq [irq_idx].src_module) == 0)
	  return modules;
	break;
      }

  irq [irq_idx].written = 0;
  return 0;
}


static void
check_irq_range (int irq_idx)
{
  Node *module = irq [irq_idx].module;
  int timer_bitw = timer_channel_bitw (module);
  int dmac_bitw;

  if (irq [irq_idx].channel < timer_bitw)
    {
      errorn (irq [irq_idx].irq_node, "IRQ assigment for %s conflicts with the IRQ assigment for timer channel %d",
	      irq [irq_idx].irq_node->val, irq [irq_idx].channel);
      return;
    }
	    
  dmac_bitw = dmac_channel_bitw (module);
  if (dmac_bitw == 0)
    return;

  if (irq [irq_idx].channel < timer_bitw + 1)
    {
      errorn (irq [irq_idx].irq_node, "IRQ assigment for %s conflicts with the IRQ assigment for the dmac bus error",
	      irq [irq_idx].irq_node->val);
      return;
    }

  if (irq [irq_idx].channel < timer_bitw + 1 + dmac_bitw)
    errorn (irq [irq_idx].irq_node, "IRQ assigment for %s conflicts with the IRQ assigment for dmac channel %d",
	    irq [irq_idx].irq_node->val, irq [irq_idx].channel - timer_bitw - 1);
}

static void
do_mm_int_config ()
{
  scan_mm_int ();
  find_line ("begin-mm_int", 1, 1, 1);
  if (mm_int.specified)
    {
      fprintf (dst_file, "  need_mm_int (0x%lx, %d, %d);\n",
	       mm_int.address, mm_int.reg_num, corecount);
    }
  find_line ("end-mm_int", 0, 1, 1);
}

static void
do_mm_int_max_config ()
{
  find_line ("static const int max_modules", 1, 0, 1);
  fprintf (dst_file, "  static const int max_modules = %d;\n", corecount);
}

static void
emit_intc_setup (CModel* cm)
{
  assert (cm);
  if (cm->num_ints > 0)
    {
      unsigned i;
      for (i=0; i<cm->num_ints; i++)
	{
	  assert (cm->int_keys[i]);
	  fprintf (dst_file, "  b->intc_set (\"interrupt-name-%u\", \"%s\");\n",
		   cm->int_channels[i],
		   cm->int_keys[i]);
	}
    }
}

static void
emit_dmac_hw_req (Node *dmac, const char* hw_name)
{
  Node *item;
  int i;
  int num_channels;
  char req[] = "hw_reqn";

  assert (dmac);
  assert (hw_name);

  /* Obtain the number of dma channels.  */
  item = find_sub (dmac, "channel_bitw", 0);
  num_channels = item ? item->ival : 1;

  /* For each channel n, look for a DMAC.HW_REQn spec.  */
  for (i = 0; i < num_channels; ++i)
    {
      sprintf (req, "hw_req%1d", i);
      item = find_sub (dmac, req, 0);
      if (item)
	{
	  /* HW_REQn has been found. Check the format.  */
	  const char* spec = item->val;
	  const char* sep = strchr (spec, ':');
	  const char* signal;
	  if (! sep || sep == spec || sep[1] == '\0')
	    {
	      fprintf (stderr, "Warning: %s=%s: Incorrect format. Item ignored\n",
		       req, spec);
	      continue;
	    }

	  /* Format is ok. If the name of the hw matches,
	     generate a call to add_dmac_hw_req.  */
	  signal = sep + 1;
	  if (strncasecmp (spec, hw_name, sep - spec) == 0)
	    {
	      fprintf (dst_file, "  h->add_dmac_hw_req (\"%s\", %d);\n",
		       signal, i);
	    }
	}
    }
}

static void
do_sidmain_config () 
{
  Node *cfgs, *item, *dmac;
  Node *modules;
  FILE *fd = dst_file;
  static char* sid_core_options[] = {
    "abs", "ave", "bit", "clp", /* "cp", - automatically inferred from VLIW specs*/
    "div", "ldz", "min", "mul", "sat", 0 
  };

  find_line ("begin-mepcfgtool-factories", 1, 1, 1);

  /* We need all of the IRQ information in advance.  */
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    for(modules = find_sub(cfgs,"me_module",0); modules; modules = find_next (modules,"me_module"))
      scan_irq (modules);

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      int module_index = 1;
      for (modules = find_sub (cfgs, "me_module", 0); 
	   modules; modules = find_next (modules, "me_module"), module_index ++)
	{
	  int channel_bitw;
	  const char *mod = modules->val;
	  int i = 0;
	  fprintf (fd, 
		   "static BoardCfg *\n"
		   "mk_%s (const string name, SessionCfg *sess)\n"
		   "{\n"
		   "  MepBoardCfg *b = new MepBoardCfg (name, \"%s\", sess);\n",
		   mod, mod);
	  fprintf (fd, "  b->set_core_type (MEP_CORE_%s);\n", upcase (mep_core_names[mep_core_type]));
	  fprintf (fd, "  b->set_cpu (\"mep-ext%d\");\n", module_index);

	  fprintf (fd, "  b->add_irq_board ();\n");

#define HANDLE_PARAM_I(name1, name2) do { \
item = find_sub (modules, "me_engine", #name1, #name2, 0); \
if (item) fprintf (fd, "  b->set_" #name1 "_" #name2 " (%lu);\n", item->ival);\
} while (0)

	  HANDLE_PARAM_I (imem, size);
	  HANDLE_PARAM_I (dmem, bank_num);	/* NOTE: define bank_num before size */
	  HANDLE_PARAM_I (dmem, size);
	  HANDLE_PARAM_I (icache, size);
	  HANDLE_PARAM_I (icache, way);
	  HANDLE_PARAM_I (icache, line_size);
	  HANDLE_PARAM_I (dcache, size);
	  HANDLE_PARAM_I (dcache, way);
	  HANDLE_PARAM_I (dcache, line_size);
	  HANDLE_PARAM_I (core, id);
	  HANDLE_PARAM_I (intc, channel_bitw);
	  HANDLE_PARAM_I (intc, level);

#undef HANDLE_PARAM_I

	  item = find_sub (modules, "me_engine", "dmem", "fixed_start_address", 0);
	  if (item)
	    fprintf (fd, "  b->set_dmem_fixed_start_address (%s);\n",
		     item->val && strcmp (item->val, "YES") == 0 ? "true" : "false");

	  /* Set the CWF option for the caches */
	  if (item = find_sub (modules, "me_engine", "icache", "cwf", 0))
	    fprintf (fd, "  b->set_icache_cwf (%s);\n",
		     item->val && strcmp (item->val, "ON") == 0 ? "true" : "false");
	  if (item = find_sub (modules, "me_engine", "dcache", "cwf", 0))
	    fprintf (fd, "  b->set_dcache_cwf (%s);\n",
		     item->val && strcmp (item->val, "ON") == 0 ? "true" : "false");

	  /* Add the ME_ENGINE.TIMER, if specified.  */
	  channel_bitw = timer_channel_bitw (modules);
	  if (channel_bitw)
	    fprintf (fd, "  b->add_timer (%d);\n", channel_bitw);

	  /* Incorporate the DMAC into the module, if specified.  The DMAC must
	     be added after the INTC (if any).  */
	  dmac = find_sub (modules, "dmac", 0);
	  if (dmac)
	    {
	      int data_width;
	      const char *rectangle;
	      Node *item2 = find_sub (dmac, "channel_bitw", 0);
	      channel_bitw = item2 ? item2->ival : 1;
	      item2 = find_sub (dmac, "data_width", 0);
	      data_width = item2 ? item2->ival : 64;
	      item2 = find_sub (dmac, "rectangle", 0);
	      rectangle = (item2 && item2->val && strcmp (item2->val, "ON") == 0)
		          ? "true" : "false";
	      fprintf (fd, "  b->add_dmac (%d, %d, %s);\n",
		       channel_bitw, data_width, rectangle);
	    }
	  
	  /* incorporate any extra local memory for the module. Local
	     memory must be added after the caches are defined. */
	  for (item = modules->sub; item; item = item->next)
	    {
	      if (item->val && strcasecmp (item->id, "local_mem") == 0)
		{
		  Node *addr = 0;
		  Node *size = 0;
		  addr = find_sub (item, "address", 0);
		  size = find_sub (item, "size", 0);
		  if (addr && size)
		    {
		      fprintf (fd, "  b->add_local_mem (0x%lx, 0x%lx, \"%s\", %s);\n",
			       addr->ival, size->ival, item->val,
			       toshapi ? "true" : "false");
		    }
		}
	    }

	  /* Declare this pointer before it gets used.  */
	  scan_hw_engines ();
	  scan_dsps ();
	  if (toshapi && (engines || dsps))
	    fprintf (fd, "  MepToshapiHWengineCfg *h;\n");

	  /* incorporate any hw_engines into the module. hw_engines must
	     be added after local memory.  */
	  if (engines)
	    for (i = 0; i < n_hw_engines; ++i)
	      {
		if (engines[i].module != modules)
		  continue;
		assert (engines[i].name);
		if (toshapi)
		  {
		    assert (engines[i].cmodel);
		    assert (engines[i].cmodel->class_name);
		    emit_intc_setup (engines[i].cmodel);
		    fprintf (fd,
			     "  h = b->add_toshapi_hw_engine (\"%s\", \"%s\", "
			     "0x%lx, %u, 0x%lx, 0x%lx",
			     engines[i].cmodel->class_name,
			     engines[i].cmodel->instance_name,
			     engines[i].cbus_addr,
			     engines[i].lbus_if,
			     engines[i].lbus_addr,
			     engines[i].lbus_size);
		    if (engines[i].local_mem_list != NULL)
		      fprintf (fd, ", \"%s\"", engines[i].local_mem_list);
		    else if (engines[i].lbus_if)
		      fprintf (fd, ", \"%s\"", engines[i].cmodel->mapped_region_name);
		    else
		      fprintf (fd, ", NULL");
		    fprintf (fd, ");\n");
		    if (dmac)
		      emit_dmac_hw_req (dmac, engines[i].name);
		  }
		else
		  {
		    fprintf (fd, "  b->add_hw_engine (\"%s\", 0x%lx, %u, 0x%lx, 0x%lx",
			     engines[i].name, 
			     engines[i].cbus_addr,
			     engines[i].lbus_if,
			     engines[i].lbus_addr,
			     engines[i].lbus_size);
		    if (engines[i].local_mem_list != NULL)
		      fprintf (fd, ", \"%s\"", engines[i].local_mem_list);
		    else
		      fputs (", NULL", fd);
		    fputs (");\n", fd);
		  }
	      }

	  /* incorporate any dsps into the module. dsps must
	     be added after local memory.  */
	  if (dsps)
	    for (i = 0; i < n_dsps; ++i)
	      {
		if (dsps[i].module != modules)
		  continue;
		assert (dsps[i].name);
		if (toshapi)
		  {
		    assert (dsps[i].cmodel);
		    assert (dsps[i].cmodel->class_name);
		    emit_intc_setup (dsps[i].cmodel);
		    fprintf (fd, "  h = b->add_toshapi_dsp (\"%s\", \"%s\", %d, %d, 0x%lx, 0x%lx, %d",
			     dsps[i].cmodel->class_name, 
			     dsps[i].cmodel->instance_name, 
			     dsps[i].cbus_if,
			     dsps[i].lbus_if,
			     dsps[i].lbus_addr,
			     dsps[i].lbus_size,
			     dsps[i].dmem_if_width);
		    if (dsps[i].local_mem_list != NULL)
		      fprintf (fd, ", \"%s\"", dsps[i].local_mem_list);
		    else if (dsps[i].lbus_if)
		      fprintf (fd, ", \"%s\"", dsps[i].cmodel->mapped_region_name);
		    else
		      fputs (", NULL", fd);
		    fputs (");\n", fd);
		    if (dmac)
		      emit_dmac_hw_req (dmac, dsps[i].name);
		  }
		else
		  {
		    fprintf (fd, "  b->add_dsp (\"%s\", %d, %d, 0x%lx, 0x%lx, %d",
			     dsps[i].name, 
			     dsps[i].cbus_if,
			     dsps[i].lbus_if,
			     dsps[i].lbus_addr,
			     dsps[i].lbus_size,
			     dsps[i].dmem_if_width);
		    if (dsps[i].local_mem_list != NULL)
		      fprintf (fd, ", \"%s\"", dsps[i].local_mem_list);
		    else
		      fputs (", NULL", fd);
		    fputs (");\n", fd);
		  }
	      }

	  /* Pull in UCI definitions.  */
	  scan_ucis ();
	  if (n_ucis && toshapi)
	    for (i = 0; i < n_ucis; ++i)
	      {
		if (ucis[i].module != modules)
		  continue;
		assert (ucis[i].cmodel);
		assert (ucis[i].cmodel->class_name);
		emit_intc_setup (ucis[i].cmodel);
		fprintf (fd, "  b->add_toshapi_uci (\"%s\", \"%s\");\n",
			 ucis[i].cmodel->class_name,
			 ucis[i].cmodel->instance_name);
	      }

	  /* Incorporate the coprocessor into the module, if specified.  */
	  item = find_sub (modules, "cop", 0);
	  if (item) 
	    {
	      Node *item2;
	      if (! item->val)
		fprintf (stderr, "warning: COP %d has no name, skipping.\n", i);
	      else
		{
		  Node *cbus_if;
		  cbus_if = find_sub (item, "cbus_if", 0);
		  if (cbus_if && (! cbus_if->val || strcmp (cbus_if->val, "ON") != 0))
		    cbus_if = NULL;
		  fprintf (fd, "  b->add_cop (\"%s\", %d);\n", item->val, cbus_if ? 1 : 0);
		  item2 = find_sub (item, "vliw_type", 0);
		  if (item2 && item2->val && (strcmp (item2->val, "YES") == 0))
		    {
		      item2 = find_sub (item, "vliw_bitw", 0);
		      fprintf (fd, "  b->set_cop_vliw_bitw (%lu);\n", item2 ? item2->ival : 64);
		    }
		  item2 = find_sub (item, "data_bus_width", 0);
		  if (item2)
		    fprintf (fd, "  b->set_cop_data_bus_width (%lu);\n", item2->ival);

		  /* Initialize coprocessor registers for known coprocessors.  Clear them
		     for unknown ones.  */
		  item2 = find_sub (item, "ip", 0);
		  if (item2 && item2->val
		      && strcmp (downcase (item2->val), "fmax") == 0)
		    {
		      fputs ("  b->set_cop_ccr ( 0, 0x00000101);\n", fd); /* cirr */
		      fputs ("  b->set_cop_ccr ( 1, 0x00000000);\n", fd); /* cbcr */
		      fputs ("  b->set_cop_ccr (15, 0x00000000);\n", fd); /* cerr */
		    }
		  else
		    {
		      fputs ("  for (int ccr = 0; ccr < 64; ++ccr)\n", fd);
		      fputs ("    b->set_cop_ccr (ccr, 0x00000000);\n", fd);
		    }
		}
	    }
	  
	  /* Incorporate the IRQ into the module, if specified. */
	  item = find_sub (modules, "irq", 0);
	  if (! item) 
	    add_msf (modules);

	  /* Recheck irqs for ones that can be processed now.  */
	  if (irq)
	    {
	      /* Check whether this module is an IRQ source.  */
	      if (is_irq_source (modules))
		fprintf (fd, "  b->intc_set (\"have_irq\", \"true\");\n");

	      scan_peripherals ();
	      for (i = 0 ; i < n_irq ; i++)
	       {
		 int engine_idx = 0;
		 int found, j;
		 Node *src_mod;

		 /* Determine whether this IRQ entry has already been processed or
		    whether the source module has been processed yet.  */
		 src_mod = check_irq_mod (modules, i);
		 if (! src_mod)
		   continue;

		 check_irq_range (i);
		 found = 0;
		 if (engines)
		   for (j = 0; j < n_hw_engines; ++j)
		     {
		       if (engines[j].module != src_mod)
			 continue;
		       if (strcasecmp (engines[j].name, irq [i].instance) == 0)
			 {
			   irq [i].irq_type = irq_engine;
			   found = 1;				 
			   engine_idx = j;
			   break;
			 }
		     } /* engines */

		 if (dsps && ! found)
		   for (j = 0; j < n_dsps; ++j)
		     {
		       if (dsps[j].module != src_mod)
			 continue;
		       if (strcasecmp (dsps[j].name, irq [i].instance) == 0)
			 {
			   irq [i].irq_type = irq_dsp;
			   found = 1;				 
			   engine_idx = j;
			   break;
			 }
		     } /* dsps */

		 if (peripherals && ! found)
		   for (j = 0; j < n_peripherals; ++j)
		     {
		       if (strcasecmp (peripherals[j].name, irq [i].instance) == 0)
			 {
			   irq [i].irq_type = irq_peripheral;
			   found = 1;				 
			   break;
			 }
		     } /* peripherals */

		 if (! found)
		   {
		     fprintf (stderr, "Error: No match for irq entry \"%s:%s\"\n",
			      irq [i].instance, irq [i].signal);
		     ++errors;
		   }
		 else
		   fprintf (fd, "  b->add_irq (%d, \"%s\", \"%s\", \"%s\", \"%s\", %d, %d);\n",
			    irq [i].irq_type, irq [i].src_module,
			    irq [i].module->val, irq [i].instance, irq [i].signal,
			    engine_idx, irq [i].channel);
	       }
	    }
	     
	  /* Pull in global_bus_if user model, if specified.  */
	  add_gbif (modules);

	  /* Pull in local_bus user model, if specified.  */
	  add_lbif (modules);

	  /* Incorporate the mm_int into the module, if specified.  */
	  /* Add the BIU.DATA_WIDTH, if specified.  */
	  item = find_sub (modules, "me_engine", "biu", "data_width", 0);
	  if (item)
	    fprintf (fd, "  b->set_opt_biu (%lu);\n", item->ival);

	  /* this is implicit in setting the channel number, above.
	     fprintf (fd, "      $mepcfg_intc = %d;\n",
	     find_sub (modules, "me_engine", "intc", 0) ? 1 : 0); */

	  fprintf (fd, "  b->set_endian (\"%s\");\n",
		   mep_endian_type == MEP_ENDIAN_LITTLE ? "little" : "big");

	  for (i = 0; sid_core_options[i]; i++)
	    {
	      char *key = sid_core_options[i];
	      int value = core_opt_set (modules, key);
	      fprintf (fd, "  b->set_opt_%s (%s);\n", key, value ? "true" : "false");
	    }

#define SET_OPT_IF(name, path) \
fprintf (fd, "  b->set_opt_" #name " (%s);\n", (find_sub path) ? "true" : "false");

	  SET_OPT_IF (dsu,  (modules, "me_engine", "dsu", 0));
	  SET_OPT_IF (uci,  (modules, "uci", 0));

#undef SET_OPT_IF

	  fprintf (fd, "  return b;\n}\n");
	}

      /* Check for unmatched IRQ entries */
      if (irq)
	{
	  int i;
	  for (i = 0 ; i < n_irq ; i++)
	    {
	      if (! irq [i].written)
		{
		  fprintf (stderr, "Error: No match for irq entry \"%s:%s\"\n",
			   irq [i].instance, irq [i].signal);
		  ++errors;
		}
	    }
	}
    }
  find_line ("end-mepcfgtool-factories", 0, 1, 1);

  find_line ("begin-mepcfgtool-boards", 1, 1, 1);
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  const char *mod = modules->val;
	  fprintf (fd, "  { \"%s\", \"MeP custom board '%s'\", & mk_%s },\n", 
		   mod, mod, mod);
	}
    }
  find_line ("end-mepcfgtool-boards", 0, 1, 1);

}

static void
do_compCGEN_config ()
{
  int i;
  find_line ("begin-mep-includes", 1, 1, 1);

  for (i = 1; i <= corecount; ++i)
    fprintf (dst_file, "#include \"mep_ext%d.h\"\n", i);

  find_line ("end-mep-includes", 0, 1, 1);

  find_line ("begin-mep-types", 1, 1, 1);

  for (i = 1; i <= corecount; ++i)
    fprintf (dst_file, "  types.push_back (\"hw-cpu-mep-ext%d\");\n", i);

  find_line ("end-mep-types", 0, 1, 1);

  find_line ("begin-mep-constructors", 1, 1, 1);

  for (i = 1; i <= corecount; ++i)
    {
      fprintf (dst_file, "  if (typeName == \"hw-cpu-mep-ext%d\")\n", i);
      fprintf (dst_file, "    return new mep_ext%d::mep_ext%d_cpu ();\n", i, i);
    }

  find_line ("end-mep-constructors", 0, 1, 1);
}

static void
gen_mep_model_fn_instantiation (const char* rtype, const char *fn_name, const char *fn_parms, int generated_model_func)
{
  const char* required_parms = generated_model_func ? "mep_basic_cpu *, const mep_idesc *" : "";
  fprintf (dst_file, "template %s mep_common_model<mep_mep_model,mep_basic_cpu,mep_idesc,mep_scache>::%s (%s%s\n",
	   rtype, fn_name, required_parms, fn_parms);
}

static void
gen_core_model_fn_instantiation (int i, const char* rtype, const char *fn_name, const char *fn_parms, int generated_model_func)
{
  char required_parms[] = "mep_ext%d_cpu *, const mepcore%d_idesc *";
  if (generated_model_func)
    sprintf (required_parms, "mep_ext%d_cpu *, const mepcore%d_idesc *", i, i);
  else
    required_parms[0] = '\0';
  fprintf (dst_file, "template %s mep_common_model<mepcore%d_mep_model,mep_ext%d_cpu,mepcore%d_idesc,mepcore%d_scache>::%s (%s%s\n",
	   rtype, i, i, i, i, fn_name, required_parms, fn_parms);
}

static void
gen_cop_model_fn_instantiation (int i, int width, const char* rtype, const char *fn_name, const char *fn_parms, int generated_model_func)
{
  char required_parms[] = "mep_ext%d_cpu *, const mepcop%d_%d_idesc *";
  if (generated_model_func)
    sprintf (required_parms, "mep_ext%d_cpu *, const mepcop%d_%d_idesc *", i, i, width);
  else
    required_parms[0] = '\0';
  fprintf (dst_file, "template %s mep_common_model<mepcop%d_%d_mep_model,mep_ext%d_cpu,mepcop%d_%d_idesc,mepcop%d_%d_scache>::%s (%s%s\n",
	   rtype, i, width, i, i, width, i, width, fn_name, required_parms, fn_parms);
}

static void
gen_sid_model_instantiations ()
{
  int i;
  Node* cfgs;
  char fn_name[sizeof (line)];
  char fn_parms[sizeof (line)];
  int generated_model_func;
  char *ptr1, *ptr2;
  char* rt_buffer;
  unsigned rt_size;

  /* Generates instantiations of each common_model template member function.
     One for each core and coprocessor configured.  */
  while (read_line ())
    {
      /* Look for a template header.  */
      fputs (line, dst_file);
      if (strstr (line, "template <class BASE, class CPU, class IDESC, class SCACHE>") == 0)
	continue;

      /* Now find the return type.  */
      if (! read_line ())
	continue;
      fputs (line, dst_file);
      rt_size = strlen (line);
      rt_buffer = xmalloc (rt_size);
      memcpy (rt_buffer, line, rt_size);
      rt_buffer[rt_size - 1] = '\0';

      /* Now find the function name.  */
      find_line ("::", 1, 1, 1);
      ptr1 = strrchr (line, '>');
      ptr1 += 3;
      ptr2 = strchr (ptr1, ' ');
      if (! ptr2)
	continue;
      *ptr2 = '\0';
      strcpy (fn_name, ptr1);

      /* Find the function parameters.  */
      ++ptr2;
      ptr1 = strchr (ptr2, '(');
      if (! ptr1)
	continue;
      ++ptr1;

      /* Now find the beginning of the non-template function parameters, if any.  */
      if (memcmp (ptr1, "CPU *cpu, const IDESC *idesc", 28) == 0)
	{
	  ptr1 += 28;
	  generated_model_func = 1;
	}
      else
	generated_model_func = 0;

      ptr2 = ptr1 + strlen (ptr1) - 1;
      *ptr2 = ';';
      strcpy (fn_parms, ptr1);

      /* Now generate the instantiations.  */
      find_line ("begin-generated-instantiations", 1, 1, 1);
      gen_mep_model_fn_instantiation (rt_buffer, fn_name, fn_parms, generated_model_func);
      i = 1;
      for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
	{
	  Node *modules;
	  for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	    {
	      gen_core_model_fn_instantiation (i, rt_buffer, fn_name, fn_parms, generated_model_func);
	      if (find_sub (modules, "cop", 0))
		{
		  gen_cop_model_fn_instantiation (i, 16, rt_buffer, fn_name, fn_parms, generated_model_func);
		  gen_cop_model_fn_instantiation (i, 32, rt_buffer, fn_name, fn_parms, generated_model_func);
		  gen_cop_model_fn_instantiation (i, 48, rt_buffer, fn_name, fn_parms, generated_model_func);
		  gen_cop_model_fn_instantiation (i, 64, rt_buffer, fn_name, fn_parms, generated_model_func);
		}
	      ++i;
	    }
	}
      free (rt_buffer);
      find_line ("end-generated-instantiations", 0, 1, 1);
    }
}

static void
do_sid_model_config ()
{
  int i;

  /* Generate #includes of other generatewd files.  */
  find_line ("begin-includes", 1, 1, 1);
  for (i = 1; i <= corecount; ++i)
    fprintf (dst_file, "#include \"mep_ext%d.h\"\n", i);
  find_line ("end-includes", 0, 1, 1);

  /* Generate a list of namespaces for each cpu.  */
  find_line ("begin-namespaces", 1, 1, 1);
  for (i = 1; i <= corecount; ++i)
    fprintf (dst_file, "using namespace mep_ext%d;\n", i);
  find_line ("end-namespaces", 0, 1, 1);

  gen_sid_model_instantiations ();
}

static void
gen_cgen_core (int i)
{
  fprintf (dst_file, "mep-core%d:\n\
\t$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) \"$(CGENFLAGS)\" \\\n\
\tmep \"with-multiple-isa with-scache with-profile=fn\" mep_ext%d ext_core%d $(CGEN_MACH) mepcore%d \"mep-core%d-\" \\\n\
\t$(cgendir)/cpu/mep.cpu \\\n\
\t\"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h\"\n",
	   i, i, i, i, i);
}

static void
gen_cgen_cop (int i, int width)
{
  fprintf (dst_file, "mep-cop%d-%d:\n\
\t$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) \"$(CGENFLAGS)\" \\\n\
\tmep \"with-multiple-isa with-scache with-profile=fn\" mep_ext%d ext_cop%d_%d $(CGEN_MACH) mepcop%d_%d \"mep-cop%d-%d-\" \\\n\
\t$(cgendir)/cpu/mep.cpu \\\n\
\t\"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h\"\n",
	   i, width, i, i, width, i, width, i, width);
}

/* Generate config specific to Makefile.in.  */
static void
gen_cpu_Makefile_in_only_config1 (enum automake_version automake_version)
{
  Node *cfgs;
  int i;
  struct cop_ip *cop_ip;

  if (automake_version != AM_1_9_5)
    return;

  find_line ("am__objects_1 =", 1, 0, 1);
  fputs ("am__objects_1 =", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, " \\\nmep-core%d-decode.lo mep-core%d-sem.lo mep-core%d-model.lo", i, i, i);
	  if (find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, " \\\nmep-cop%d-16-decode.lo mep-cop%d-16-sem.lo mep-cop%d-16-model.lo", i, i, i);
	      fprintf (dst_file, " \\\nmep-cop%d-32-decode.lo mep-cop%d-32-sem.lo mep-cop%d-32-model.lo", i, i, i);
	      fprintf (dst_file, " \\\nmep-cop%d-48-decode.lo mep-cop%d-48-sem.lo mep-cop%d-48-model.lo", i, i, i);
	      fprintf (dst_file, " \\\nmep-cop%d-64-decode.lo mep-cop%d-64-sem.lo mep-cop%d-64-model.lo", i, i, i);
	    }
	  ++i;
	}
    }
  for (cop_ip = cop_ips; cop_ip; cop_ip = cop_ip->next)
    {
      if (strcmp (cop_ip->ip, "fmax") == 0)
	fprintf (dst_file, " \\\n%s-fp.lo %s-fpu.lo", cop_ip->ip, cop_ip->ip);
    }
  fputc ('\n', dst_file);
  find_line ("am_libmep_la_OBJECTS", 0, 1, 1);
}

static void
gen_cpu_Makefile_in_only_config2 (enum automake_version automake_version)
{
  Node *cfgs;
  int i;
  struct cop_ip *cop_ip;

  if (automake_version == AM_NONE)
    return;

  if (automake_version == AM_1_4)
    {
      find_line ("libmep_la_OBJECTS", 1, 0, 1);
      fputs ("libmep_la_OBJECTS = mep.lo common_model.lo mep-decode.lo mep-sem.lo mep-model.lo", dst_file);
      i = 1;
      for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
	{
	  Node *modules;
	  for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	    {
	      fprintf (dst_file, " \\\nmep-core%d-decode.lo mep-core%d-sem.lo mep-core%d-model.lo", i, i, i);
	      if (find_sub (modules, "cop", 0))
		{
		  fprintf (dst_file, " \\\nmep-cop%d-16-decode.lo mep-cop%d-16-sem.lo mep-cop%d-16-model.lo", i, i, i);
		  fprintf (dst_file, " \\\nmep-cop%d-32-decode.lo mep-cop%d-32-sem.lo mep-cop%d-32-model.lo", i, i, i);
		  fprintf (dst_file, " \\\nmep-cop%d-48-decode.lo mep-cop%d-48-sem.lo mep-cop%d-48-model.lo", i, i, i);
		  fprintf (dst_file, " \\\nmep-cop%d-64-decode.lo mep-cop%d-64-sem.lo mep-cop%d-64-model.lo", i, i, i);
		}
	      ++i;
	    }
	}
      for (cop_ip = cop_ips; cop_ip; cop_ip = cop_ip->next)
	{
	  if (strcmp (cop_ip->ip, "fmax") == 0)
	    fprintf (dst_file, " \\\n%s-fp.lo %s-fpu.lo", cop_ip->ip, cop_ip->ip);
	}
      fputc ('\n', dst_file);
      find_line ("CXXCOMPILE", 0, 1, 1);

      find_line ("DEP_FILES", 1, 0, 1);
      fputs ("DEP_FILES = .deps/mep.P .deps/common_model.P .deps/mep-decode.P .deps/mep-sem.P .deps/mep-model.P", dst_file);
    }
  else /* if (automake_version == AM_1_9_5) */
    find_line ("common_model.Plo", 1, 1, 1);

  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  if (automake_version == AM_1_4)
	    {
	      fprintf (dst_file, " \\\n.deps/mep-core%d-decode.P .deps/mep-core%d-sem.P .deps/mep-core%d-model.P", i, i, i);
	      if (find_sub (modules, "cop", 0))
		{
		  fprintf (dst_file, " \\\n.deps/mep-cop%d-16-decode.P .deps/mep-cop%d-16-sem.P .deps/mep-cop%d-16-model.P", i, i, i);
		  fprintf (dst_file, " \\\n.deps/mep-cop%d-32-decode.P .deps/mep-cop%d-32-sem.P .deps/mep-cop%d-32-model.P", i, i, i);
		  fprintf (dst_file, " \\\n.deps/mep-cop%d-48-decode.P .deps/mep-cop%d-48-sem.P .deps/mep-cop%d-48-model.P", i, i, i);
		  fprintf (dst_file, " \\\n.deps/mep-cop%d-64-decode.P .deps/mep-cop%d-64-sem.P .deps/mep-cop%d-64-model.P", i, i, i);
		}
	    }
	  else /* if (automake_version == AM_1_9_5) */
	    {
	      if (find_sub (modules, "cop", 0))
		{
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-16-decode.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-16-model.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-16-sem.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-32-decode.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-32-model.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-32-sem.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-48-decode.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-48-model.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-48-sem.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-64-decode.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-64-model.Plo@am__quote@\n", i);
		  fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-cop%d-64-sem.Plo@am__quote@\n", i);
		}
	      fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-core%d-decode.Plo@am__quote@\n", i);
	      fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-core%d-model.Plo@am__quote@\n", i);
	      fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/mep-core%d-sem.Plo@am__quote@\n", i);
	    }
	  ++i;
	}
    }
  for (cop_ip = cop_ips; cop_ip; cop_ip = cop_ip->next)
    {
      if (strcmp (cop_ip->ip, "fmax") == 0)
	{
	  if (automake_version == AM_1_4)
	    fprintf (dst_file, " \\\n.deps/%s-fp.P .deps/%s-fpu.P", cop_ip->ip, cop_ip->ip);
	  else /* if (automake_version == AM_1_9_5) */
	    {
	      fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/%s-fp.Plo@am__quote@\n", cop_ip->ip);
	      fprintf (dst_file, "@AMDEP_TRUE@@am__include@ @am__quote@./$(DEPDIR)/%s-fpu.Plo@am__quote@\n", cop_ip->ip);
	    }
	}
    }
  if (automake_version == AM_1_4)
    {
      fputc ('\n', dst_file);
      find_line ("SOURCES", 0, 1, 1);
    }
  else /* if (automake_version == AM_1_9_5) */
    find_line ("mep-decode.Plo", 0, 1, 1);
}

static void
do_cpu_Makefile_config (char *makefile)
{
  Node *cfgs;
  int i;
  struct cop_ip *cop_ip;
  enum automake_version automake_version;

  start_file (srcdir, makefile, 0);

  /* See if this is Makefile.in and, if so, which version of automake created it. */
  automake_version = get_automake_version (makefile);

  gen_cpu_Makefile_in_only_config1 (automake_version);

  find_line ("CPU_SOURCES", 1, 0, 1);
  fputs ("CPU_SOURCES =", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, " mep-core%d-decode.cxx mep-core%d-sem.cxx mep-core%d-model.cxx", i, i, i);
	  if (find_sub (modules, "cop", 0))
	    {
	      fprintf (dst_file, " mep-cop%d-16-decode.cxx mep-cop%d-16-sem.cxx mep-cop%d-16-model.cxx", i, i, i);
	      fprintf (dst_file, " mep-cop%d-32-decode.cxx mep-cop%d-32-sem.cxx mep-cop%d-32-model.cxx", i, i, i);
	      fprintf (dst_file, " mep-cop%d-48-decode.cxx mep-cop%d-48-sem.cxx mep-cop%d-48-model.cxx", i, i, i);
	      fprintf (dst_file, " mep-cop%d-64-decode.cxx mep-cop%d-64-sem.cxx mep-cop%d-64-model.cxx", i, i, i);
	    }
	  ++i;
	}
    }
  for (cop_ip = cop_ips; cop_ip; cop_ip = cop_ip->next)
    {
      if (strcmp (cop_ip->ip, "fmax") == 0)
	fprintf (dst_file, " %s-fp.cxx %s-fpu.cxx", cop_ip->ip, cop_ip->ip);
    }
  fputc ('\n', dst_file);

  find_line ("CGEN_MACH", 1, 0, 1);
  fprintf (dst_file, "CGEN_MACH = %s\n", mep_mach_names[mep_core_type]);

  find_line ("CPU_TARGETS", 1, 0, 1);
  fputs ("CPU_TARGETS =", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, " mep-core%d", i);
	  if (find_sub (modules, "cop", 0))
	    fprintf (dst_file, " mep-cop%d-16 mep-cop%d-32 mep-cop%d-48 mep-cop%d-64", i, i, i, i);
	  ++i;
	}
    }
  fputc ('\n', dst_file);

  find_line ("CPU_LIST", 1, 0, 1);
  fputs ("CPU_LIST = mep", dst_file);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  fprintf (dst_file, ",ext_core%d", i);
	  if (find_sub (modules, "cop", 0))
	    fprintf (dst_file, ",ext_cop%d_16,ext_cop%d_32,ext_cop%d_48,ext_cop%d_64", i, i, i, i);
	  ++i;
	}
    }
  fputc ('\n', dst_file);

  /* Do config specific to Makefile.in, if that's the file we're working on.  */
  gen_cpu_Makefile_in_only_config2 (automake_version);
  
  find_line ("begin-cpus", 1, 1, 1);
  i = 1;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  gen_cgen_core(i);
	  if (find_sub (modules, "cop", 0))
	    {
	      gen_cgen_cop (i, 16);
	      gen_cgen_cop (i, 32);
	      gen_cgen_cop (i, 48);
	      gen_cgen_cop (i, 64);
	    }
	  ++i;
	}
    }

  find_line ("end-cpus", 0, 1, 1);
  end_file();
}

static void
map_ld_stack_and_heap (const Gmap *section)
{
  int i;
  int count;

  /* Generate the stack table which is indexed by ME_MODULE.ID.  */
  find_line ("begin-stack-table", 1, 1, 1);
  count = 0;
  for (i = 0; i < next_core_id; ++i)
    {
      if (! core_ids_in_use [i])
	continue;
      fprintf (dst_file,
	       "  __stack%d = (__stack - (%d *  (__stack_size / %d)) + 15) / 16 * 16;\n",
	       i, count, corecount);
      ++count;
    }

  fputs ("\n"
	 "  .rostacktab :\n"
	 "  {\n"
	 "    /* Emit a table describing the location of the different stacks.  */\n"
	 "    . = ALIGN(4);\n"
	 "    __stack_table = .;\n", dst_file);

  for (i = 0; i < next_core_id; ++i)
    {
      int stack_to_use = core_ids_in_use [i] ? i : (next_core_id - 1);

      fprintf (dst_file, "    LONG (__stack%d);\n", stack_to_use);
    }

  fputs ("    __stack_end = .;\n", dst_file);
  fprintf (dst_file, "  } >%s\n", section->name);
  find_line ("end-stack-table", 0, 1, 1);

  find_line ("begin-heap", 1, 1, 1);
  fprintf (dst_file,
	   "  /* End of DATA is 0x%08lx + 0x%08lx. That's where the heap will end.  */\n"
	   "  __heap_end = 0x%08lx + 0x%08lx - 1;\n",
	   section->start, section->size, section->start, section->size);
  find_line ("end-heap", 0, 1, 1);
}

static void
map_ld_output_section (const Gmap *section, const char *label)
{
  char *endchar;
  char *mapchar = strrchr (line, '>');
  if (mapchar != NULL)
    {
      *mapchar = '\0';
      endchar = strstr (mapchar + 1, "-section */");
      if (endchar != NULL)
	{
	  endchar += 11;
	  fprintf (dst_file, "%s", line);
	  fprintf (dst_file, ">%s /* %s */%s", section->name, label, endchar);
	  return;
	}
    }

  /* This is not one of our target lines, so just echo it.  */
  fputs (line, dst_file);
}

static void
map_ld_output_sections (const Gmap *vec, const Gmap *hwinit, const Gmap *vec_warm,
			const Gmap *rom, const Gmap *ram, const Gmap *imem,
			const Gmap *dmem)
{
  const Gmap *code;
  const Gmap *data;
  int error = 0;

  assert (vec);

  /* Determine which MEMORY sections will contain rom, code and data.
     Rom goes into the ROM region if one was specified, otherwise into
     IMEM0.  */
  if (! rom)
    {
      rom = imem;
      if (! rom)
	{
	  fprintf (stderr, "Error: No memory region for suitable for ROM "
		   "specified in the global map file %s\n",
		   gmapfilename);
	  error = 1;
	}
    }

  /* Code and data go into the RAM region if one was found, otherwise,
     code goes into ROM and data goes into DMEM0. If no DMEM0, then data
     goes with the code.  */
  if (ram)
    {
      code = ram;
      data = ram;
    }
  else
    {
      code = rom;
      if (! code)
	{
	  fprintf (stderr, "Error: No memory region suitable for code "
		   "specified in the global map file %s\n",
		   gmapfilename);
	  error = 1;
	}
      data = dmem;
      if (! data)
	{
	  fprintf (stderr, "Warning: No memory region suitable for data "
		   "specified in the global map file %s.\n",
		   gmapfilename);
	  data = code;
	}
    }
  if (error)
    exit (EXIT_FAILURE);

  assert (rom);
  assert (code);
  assert (data);

  if (! hwinit)
    hwinit = code;

  /* Find the SECTIONS command and map the known section names to
     the appropriate MEMORY regions.  */
  find_line ("SECTIONS", 1, 1, 1);

  /* Modify each line that contains the notation "XXX-section".  */
  while (read_line ())
    {
      if (strstr (line, "DATA-section"))
	map_ld_output_section (data, "DATA-section");
      else if (strstr (line, "CODE-section"))
	map_ld_output_section (code, "CODE-section");
      else if (strstr (line, "ROM-section"))
	map_ld_output_section (rom, "ROM-section");
      else if (strstr (line, "VEC-section"))
	map_ld_output_section (vec, "VEC-section");
      else if (strstr (line, "HWINIT-section"))
	map_ld_output_section (hwinit, "HWINIT-section");
      else
	{
	  fputs (line, dst_file);
	  if (strstr (line, "END-mep-sections") != NULL)
	    break; /* no more sections */
	}
    }

  /* Ouput the .vec_warm section, if needed.  */
  if (vec_warm)
    {
      fputc ('\n', dst_file);
      fputs ("  .vec_warm :\n", dst_file);
      fputs ("  {\n", dst_file);
      fputs ("    /* vec_warm is a place for the startup code to write the interrupt\n", dst_file);
      fputs ("       vectors.  Allow 0xb8 bytes of space aligned on a 4 byte boundary.  */\n", dst_file);
      fputs ("    . = ALIGN(4);\n", dst_file);
      fputs ("    vec_warm = .;\n", dst_file);
      fputs ("    . += 0xb8;\n", dst_file);
      fprintf (dst_file, "  } >%s\n", vec_warm->name);
    }

  /* Map the stack and heap  */
  map_ld_stack_and_heap (data);
}

static Gmap *
map_ld_memory (Gmap* vec, Gmap *hwinit, Gmap *rom, Gmap **ram,
	       Gmap *imem, Gmap *dmem)
{
  Gmap *g;
  Gmap *vec_warm;

  /* Determine which region will contain the vec_warm section.
     If there is IMEM, then vec_warm comes from IMEM0, otherwise
     if RAM begins at 0x800000, then vec_warm
     comes from RAM.  Otherwise, leave it unassigned.  */
  if (imem)
    {
      assert (imem->size > 0xb8);
      g = imem;
    }
  else if (*ram && (*ram)->start == 0x800000 && (*ram)->size >= 0xb8)
    g = *ram;
  else
    g = NULL;

  if (g)
    {
      /* If the size of the selected region is exactly 0xb8, then VEC_WARM
	 will simply replace it.  Otherwise create a new region.  */
      if (g->size == 0xb8)
	{
	  g->name = "VEC_WARM";
	  vec_warm = g;
	  assert (g == *ram);
	  *ram = NULL;
	}
      else
	{
	  name_and_num s = {g->shadow, g->shadow_mod_name};
	  vec_warm = new_gmap (g->start, 0xb8, "VEC_WARM", g->cache, s,
			       g->scope, g->type, g->access);
	  g->start += 0xb8;
	  g->size  -= 0xb8;

	  /* Insert vec_warm into the gmap table if it came from ram.  */
	  if (g == *ram)
	    {
	      vec_warm->next = g->next;
	      g->next = vec_warm;
	    }
	}
    }
  else
    vec_warm = NULL;

  /* Write the MEMORY entries from the ROM and RAM sections from the
     gmap file.  */
  find_line ("begin-memory", 1, 1, 1);

  /* Output the VEC region.  */
  assert (vec);
  fprintf (dst_file, "  %s\t(%c) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	   vec->name, vec->access == readonly ? 'r' : 'w',
	   vec->start, 0xb8);

  /* Output the VEC_WARM region.  */
  if (vec_warm)
    {
      fprintf (dst_file, "  %s\t(%c) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	       vec_warm->name, vec_warm->access == readonly ? 'r' : 'w',
	       vec_warm->start, vec_warm->size);
    }

  /* Output the HWINIT region.  */
  if (hwinit)
    {
      fprintf (dst_file, "  %s\t(%c) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	       hwinit->name, hwinit->access == readonly ? 'r' : 'w',
	       hwinit->start, hwinit->size);
    }

  /* Output the ROM region.  */
  if (rom)
    {
      assert (rom != vec);
      assert (rom != vec_warm);
      fprintf (dst_file, "  %s\t(%c) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	       rom->name, rom->access == readonly ? 'r' : 'w',
	       rom->start, rom->size);
    }

  /* Output the RAM region.  */
  if (*ram)
    {
      assert (*ram != rom);
      assert (*ram != vec);
      assert (rom != vec_warm);
      fprintf (dst_file, "  %s\t(w) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	       (*ram)->name, (*ram)->start, (*ram)->size);
    }

  /* Output any rejected regions as comments.  */
  for (g = currentgmap; g; g = g->next)
    {
      if (g != vec && g != hwinit && g != vec_warm
	  && g != rom && g != *ram && ! g->shadow_specified)
	fprintf (dst_file, "/*%s\t(%c) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx */\n",
		 g->name, g->access == readonly ? 'r' : 'w', g->start, g->size);
    }

  /* Add the IMEM sections.  */
  for (g = imem; g; g = g->next)
    {
      fprintf (dst_file, "  %s\t(w) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	       g->name, g->start, g->size);
    }

  /* Add the DMEM sections.  */
  for (g = dmem; g; g = g->next)
    {
      fprintf (dst_file, "  %s\t(w) : ORIGIN = 0x%08lx, LENGTH = 0x%08lx\n",
	       g->name, g->start, g->size);
    }

  find_line ("end-memory", 0, 1, 1);
  return vec_warm;
}

static void
write_ld_header (const char *modname)
{
  /* Rewrite the header comment to indicate a generated file.  */
  find_line ("begin-header", 1, 1, 1);
  fprintf (dst_file,
	   "\n"
	   "  DO NOT EDIT. THIS FILE IS MACHINE-GENERATED \n"
	   "  FROM THE TEMPLATE FILE %s.\n"
	   "  ALL EDITS WILL BE ERASED WITH NEXT MeP-Integrator RUN. \n"
	   "\n"
	   "  Custom linker script for the MeP Module %s.\n",
	   linker_script_default, modname);
  find_line ("end-header", 0, 1, 1);
}

static void
find_ld_sections (Gmap **vec, Gmap **hwinit, Gmap **rom, Gmap **ram)
{
  int rom_found;
  int ram_800000_found;
  int ram_400000_found;
  Gmap *gmap;

  *vec = NULL;
  *hwinit = NULL;
  *rom = NULL;
  *ram = NULL;
  ram_800000_found = 0;
  ram_400000_found = 0;

  /* Discover the relevent gmap entries -- for VEC, ROM and RAM.  */
  for (gmap = currentgmap; gmap; gmap = gmap->next)
    {
      /* Check the starting address and size for the VEC region.
	 These are constants supplied by Toshiba.  */
      if (gmap->start == 0x0 && gmap->size >= 0xb8)
	{
	  /* Issue a warning if more than one VEC area has been specified.  */
	  if (*vec != NULL)
	    {
	      fprintf (stderr, "Warning: More than one VEC area specified "
		       "in the global map file %s\n", gmapfilename);
	      continue;
	    }
	  *vec = gmap;
	  if ((*vec)->size == 0xb8)
	    {
	      (*vec)->name = "VEC";
	      continue;
	    }

	  /* If the vec region is larger than 0xb8, then split it up, in case
	     the extra space can be used for another region.  */
	    {
	      name_and_num s = {gmap->shadow, gmap->shadow_mod_name};
	      *vec = new_gmap (0x0, 0xb8, "VEC", gmap->cache, s, gmap->scope, gmap->type, gmap->access);
	      gmap->start = 0xb8;
	      gmap->size -= 0xb8;
	    }

	  /* The HWINIT section must be exactly this big.  */
	  if (gmap->size < 0x148)
	    continue;

	  *hwinit = gmap;
	  if ((*hwinit)->size == 0x148)
	    {
	      (*hwinit)->name = "HWINIT";
	      continue;
	    }

	  /* If the hwinit region is larger than 0x148, then split it up, in case
	     the extra space can be used for another region.  */
	    {
	      name_and_num s = {gmap->shadow, gmap->shadow_mod_name};
	      *hwinit = new_gmap (0xb8, 0x148, "HWINIT", gmap->cache, s, gmap->scope, gmap->type, gmap->access);
	      gmap->start = 0x200;
	      gmap->size -= 0x148;
	    }
	}
      /* Check the starting address and size for the HWINIT region.
	 This is the same as above, but captures the case where the
	 VEC region is separately defined from the memory immediately
	 following it.  */
      if (gmap->start == 0xb8 && gmap->size >= 0x148)
	{
	  /* Issue a warning if more than one VEC area has been specified.  */
	  if (*hwinit != NULL)
	    {
	      fprintf (stderr, "Warning: More than one HWINIT area specified "
		       "in the global map file %s\n", gmapfilename);
	      continue;
	    }
	  *hwinit = gmap;
	  if ((*hwinit)->size == 0x148)
	    {
	      (*hwinit)->name = "HWINIT";
	      continue;
	    }

	  /* If the hwinit region is larger than 0x148, then split it up, in case
	     the extra space can be used for another region.  */
	    {
	      name_and_num s = {gmap->shadow, gmap->shadow_mod_name};
	      *hwinit = new_gmap (0xb8, 0x148, "HWINIT", gmap->cache, s, gmap->scope, gmap->type, gmap->access);
	      gmap->start = 0x148;
	      gmap->size -= 0x148;
	    }
	}

      /* Check to see if this could be the ROMable area.  */
      if (gmap->access == readonly)
	{
	  /* Prefer the region with the lowest starting address.  */
	  if (*rom != NULL)
	    {
	      if ((*rom)->start <= gmap->start)
		continue;
	    }
	  *rom = gmap;
	  continue;
	}

      /* The preferred range for the RAM section is 0x800000-0xffffff.  */
      if (gmap->start >= 0x800000 && gmap->start <= 0xffffff)
	{
	  if (*ram != NULL && ram_800000_found)
	    {
	      /* More than one possible section has been specified.
		 Prefer regions ending within the range 0x800000-0xffffff.  */
	      if ((*ram)->start + (*ram)->size - 1 > 0xffffff)
		{
		  if (gmap->start + gmap->size - 1 <= 0xffffff)
		    {
		      *ram = gmap;
		      continue;
		    }
		}
	      else if (gmap->start + gmap->size - 1 > 0xffffff)
		continue;

	      /* Prefer larger regions over smaller.
		 If the sizes are the same, select the region with the lowest
		 address.  */
	      if ((*ram)->size > gmap->size)
		continue;
	      if ((*ram)->size == gmap->size && (*ram)->start <= gmap->start)
		continue;
	    }
	  ram_800000_found = 1;
	  *ram = gmap;
	}
      if (ram_800000_found)
	continue;

      /* The next preferred region for the RAM section is 0x400000-0x5fffff.  */
      if (gmap->start >= 0x400000 && gmap->start + gmap->size - 1 <= 0x5fffff)
	{
	  if (*ram != NULL && ram_400000_found)
	    {
	      /* More than one possible section has been specified.
	         Prefer larger regions over smaller.
		 If the sizes are the same, select the region with the lowest
		 address.  */
	      if ((*ram)->size > gmap->size)
		continue;
	      if ((*ram)->size == gmap->size && (*ram)->start <= gmap->start)
		continue;
	    }
	  ram_400000_found = 1;
	  *ram = gmap;
	}
      if (ram_400000_found)
	continue;

      /* The lowest preference for the RAM section is 0x0-0x1fffff.  */
      if (gmap->start + gmap->size - 1 <= 0x1fffff)
	{
	  if (*ram != NULL)
	    {
	      /* More than one possible section has been specified.
		 Prefer larger regions over smaller.
		 If the sizes are the same, select the region with the lowest
		 address.  */
	      if ((*ram)->size > gmap->size)
		continue;
	      if ((*ram)->size == gmap->size && (*ram)->start <= gmap->start)
		continue;
	    }
	  *ram = gmap;
	}
    } /* loop over gmap records.  */

  /* Warn for a less than perfect RAM area.  */
  if (*ram != NULL && (*ram)->start + (*ram)->size - 1 > 0xffffff)
    {
      fprintf (stderr, "Warning: RAM area ends beyond the address 0xffffff "
	       "in the global map file %s\n", gmapfilename);
    }
  /* The VEC area must be specified.  */
  if (*vec == NULL)
    {
      fprintf (stderr, "Error: No memory region for suitable for the vector "
	       "table specified in the global map file %s\n",
	       gmapfilename);
      exit (EXIT_FAILURE);
    }
  /* The HWINIT area must be specified.  */
  if (*hwinit == NULL)
    {
      fprintf (stderr, "Error: No memory region for suitable for hardware initialization"
	       " specified in the global map file %s\n",
	       gmapfilename);
      exit (EXIT_FAILURE);
    }
}

static void
find_ld_imem_dmem (Node *module, Gmap **imem, Gmap **dmem)
{
  Node *item;
  long imem_size = 0;

  *imem = NULL;
  *dmem = NULL;

  /* Identify IMEM sections.  */
  item = find_sub (module, "me_engine", "imem", "size", 0);
  if (item)
    {
      imem_size = item->ival;
      if (imem_size)
	{
	  long bank_size;
	  name_and_num s = {0, 0};

	  if (imem_size == 6 || imem_size == 12 || imem_size == 24)
	    bank_size = (imem_size * 1024) * 2 / 3;
	  else
	    bank_size = (imem_size * 1024) / 2;

	  *imem = new_gmap (0x200000, bank_size, "IMEM0", nocache, s,
			   sc_local, memory, readwrite);
	  (*imem)->next = new_gmap (0x200000 + bank_size, imem_size*1024 - bank_size, "IMEM1", nocache, s,
				    sc_local, memory, readwrite);
	}
    }

  /* Add the DMEM sections.  */
  item = find_sub (module, "me_engine", "dmem", "size", 0);
  if (item)
    {
      long dmem_size = item->ival;
      if (dmem_size)
	{
	  long dmem_base[4];
	  long dmem_banks;
	  long i;
	  name_and_num s = {0, 0};

	  if ((item = find_sub (module, "me_engine", "dmem", "fixed_start_address", 0))
	      && strcmp (item->val, "YES") == 0)
	    dmem_base[0] = 0x80000;
	  else
	    {
	      /* 
	       * These tables represent the dmem base address values for the various
	       * dmem (rows) and imem (columns) combinations possible as per the 
	       * MeP Media User's Manual Rev. 5.0, section 4.6.2.
	       * 
	       */
	      int imem_limit[] = {0, 8, 16, 32};
	      int dmem_limit[] = {0, 8, 16, 32, 64, 128};
	      long dmem_base_address[][4] = {
/*             imem:	none,    1-8k,  12-16k,  24-32k */
/* dmem:    none */ {0x00000, 0x02000, 0x04000, 0x08000},
/* dmem:   1-8k  */ {0x00000, 0x02000, 0x04000, 0x08000},
/* dmem:  12-16k */ {0x00000, 0x04000, 0x04000, 0x08000},
/* dmem:  24-32k */ {0x00000, 0x08000, 0x08000, 0x08000},
/* dmem:  48-64k */ {0x00000, 0x10000, 0x10000, 0x10000},
/* dmem: 96-128k */ {0x00000, 0x20000, 0x20000, 0x20000},
	      };
	      int imem_index = -1;
	      int dmem_index = -1;
	      /*  find the imem limit in the table.  */
	      for (i = 0; i < sizeof (imem_limit)/sizeof (*imem_limit); i++) 
		{
		  if (imem_size <= imem_limit[i]) 
		    {
		      imem_index = i;
		      break;
		    }
		}
	      /*  find the dmem limit in the table.  */
	      assert (dmem_size);
	      for (i = 0; i < sizeof (dmem_limit)/sizeof (*dmem_limit); i++) 
		{
		  if (dmem_size <= dmem_limit[i]) 
		    {
		      dmem_index = i;
		      break;
		    }
		}
	      assert (dmem_index >= 0 && imem_index >= 0);
	      dmem_base[0] = dmem_base_address[dmem_index][imem_index];
	    }

	  item = find_sub (module, "me_engine", "dmem", "bank_num", 0);
	  dmem_banks = item ? item->ival : 2;
	  assert (dmem_banks <= 4);
	  for (i = dmem_banks - 1; i >= 0; --i)
	    {
	      Gmap *d;
	      char *name;
	      if (((dmem_size == 6) || (dmem_size == 12) || (dmem_size == 24)) &&
		  (dmem_banks == 2)) 
		{ /* adjust up to the next power of two  */
		  dmem_base[i] = dmem_base[0] + (i * ((dmem_size * 1024) * 2 / 3));	
		} 
	      else 
		dmem_base[i] = dmem_base[0] + (i * (dmem_size * 1024 / dmem_banks));

	      name = xmalloc (5 + 1);
	      sprintf (name, "DMEM%c", '0' + i);
	      d = new_gmap (0x200000 + dmem_base[i], (dmem_size * 1024) / dmem_banks,
			    name, nocache, s,
			    sc_local, memory, readwrite);
	      d->next = *dmem;
	      *dmem = d;
	    }
	}
    }
}

static void
do_ld_gmap_config (const char *basedir)
{
  Node *cfgs, *modules;
  Gmap *vec;
  Gmap *hwinit;
  Gmap *vec_warm;
  Gmap *rom;
  Gmap *ram;
  Gmap *imem;
  Gmap *dmem;
  Gmap *g;

  assert (currentgmap);

  /* First find the VEC, ROM and RAM regions in the gmap.  */
  find_ld_sections (& vec, & hwinit, & rom, & ram);

  /* Now modify one linker script for each module defined.  */
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  start_linker_script (basedir, modules->val);
	  write_ld_header (modules->val);
	  find_ld_imem_dmem (modules, & imem, & dmem);
	  vec_warm = map_ld_memory (vec, hwinit, rom, & ram, imem, dmem);
	  map_ld_output_sections (vec, hwinit, vec_warm, rom, ram, imem, dmem);
	  end_file ();
	}
    }

  if (!instdir)
    {
      /* Add the generated linker scripts to libgloss/mep/Makefile.in.  */
      start_file (srcdir, "libgloss/mep/Makefile.in", 0);
      find_line ("SCRIPTS =", 1, 0, 1);
      fputs ("SCRIPTS = min.ld", dst_file);
      if (linker_scripts != NULL)
	fputs (linker_scripts, dst_file);
      putc ('\n', dst_file);
      end_file ();
    }
}

static void
do_bfd_config_names ()
{
  Node *cfgs, *modules;

  find_line ("start-mepcfgtool", 1, 1, 1);
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	fprintf (dst_file, "  ,\"%s\"\n", modules->val);
    }
  find_line ("end-mepcfgtool", 0, 1, 1);
}

/*----------------------------------------------------------------------*/

static void
generate_script_start (const char *cmd, const char *pre)
{
  fprintf (dst_file, "#!/bin/sh\n");
  fprintf (dst_file, "\n");
  fprintf (dst_file, "mydir=`echo $0 | sed 's@/[^/]*$@@'`\n");
  if (outdir == instdir)
    {
      /* Call the executable relative to the location of the script.  */
      fprintf (dst_file, "cmd=\"exec $mydir/../../bin/%s\"\n", cmd);
    }
  else
    {
      /* Call the executable in the install directory directly.  */
      fprintf (dst_file, "cmd=\"exec %s/bin/%s\"\n", absolute_filename (instdir), cmd);
    }
  fprintf (dst_file, "%s\n", pre);
  fprintf (dst_file, "for option\n");
  fprintf (dst_file, "do\n");
  fprintf (dst_file, "  case \"$option\" in\n");
}

static void
generate_script_end (const char *post)
{
  fprintf (dst_file, "    -e ) opts=\"$opts -e\" ;;\n");
  fprintf (dst_file, "    -E ) opts=\"$opts -E\" ;;\n");
  fprintf (dst_file, "    -n ) opts=\"$opts -n\" ;;\n");
  fprintf (dst_file, "    * )\n");
  fprintf (dst_file, "      temp=`echo \"$option\" | sed \"s/'/'\\\\\\\\\\''/g\"`\n");
  fprintf (dst_file, "      opts=\"$opts $temp\"\n");
  fprintf (dst_file, "      ;;\n");
  fprintf (dst_file, "  esac\n");
  fprintf (dst_file, "done\n");
  fprintf (dst_file, "%s\n", post);
  fprintf (dst_file, "eval \"$cmd $opts\"\n");
}

static void
make_executable (char *path)
{
  int m = umask(0);
  umask (m);
  chmod (path, 0777 & ~m);
}

static void
generate_compiler_script ()
{
  Node *cfgs, *modules, *cop;
  int i;

  start_file (outdir, "bin/mep-elf-gcc", 0);
  generate_script_start ("mep-elf-gcc", "topt=\"\"; have_topt=\"\"");

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "ME_MODULE", 0); modules; modules = find_next (modules, "ME_MODULE"))
	{
	  fprintf (dst_file, " \"-mconfig=%s\" )\n\t opts=\"$opts '$option'", modules->val);

	  fprintf (dst_file, " -me%c", mep_endian_type == MEP_ENDIAN_LITTLE ? 'l' : 'b');

	  for (i = 0; cc_opt_map[i].opt; i++)
	    if (core_opt_set (modules, cc_opt_map[i].opt))
	      fprintf (dst_file, cc_opt_map[i].ifon);
	    else
	      fprintf (dst_file, cc_opt_map[i].ifoff);
	  
	  if (have_sdram ())
	    fprintf (dst_file, " -msdram");
	  else
	    fprintf (dst_file, " -mno-sdram");
	  fprintf (dst_file, "\"\n\ttopt=\" -T$mydir/../mep-elf/lib/%s.ld\" ;;\n", modules->val);
	}
    }

  fprintf (dst_file, "    -T* ) have_topt=x; opts=\"$opts '$option'\" ;;\n");
  generate_script_end ("test \"$have_topt\" || opts=\"$opts$topt\"");
  find_line (NULL, 0, 0, 1);
  end_file ();
  make_executable (concat (outdir, "/bin/mep-elf-gcc", NULL));
}

static void
sidscr_bool(const char *ifon, const char *ifoff, Node *node)
{
  if (node && node->val
      && (strcmp (node->val, "ON") == 0
	  || strcmp (node->val, "YES") == 0))
    fputs (ifon, dst_file);
  else
    fputs (ifoff, dst_file);
}

static void
sidscr_parm(const char *ifon, const char *ifoff, Node *node)
{
  if (node && node->val)
    fprintf (dst_file, ifon, node->val);
  else if (node && node->ival)
    fprintf (dst_file, ifon, node->ival);
  else
    fputs (ifoff, dst_file);
}

static const char* gmap_options ()
{
  Gmap *gmap;
  char *gmap_buffer = NULL;
  int gmap_buffer_size = 0;
  int old_size;
  int i;

  for (i = 0, gmap = currentgmap; gmap; gmap = gmap->next, ++i)
    {
      char buffer [256];
      if (gmap->scope == sc_global 
	  && ((gmap->type == memory && ! gmap->shadow_specified)
	      || gmap->type == mainbus))
	{
	  sprintf (buffer, " '--global-mem=0x%lx,0x%lx%s%s'",
		   gmap->start, gmap->size,
		   gmap->cache == cache ? ",cached" : "",
		   gmap->access == readonly ? ",rom" : "");
	      
	  /* Make room for the previous contents plus the additional contents */
	  old_size = gmap_buffer_size;
	  gmap_buffer_size += strlen (buffer);
	  gmap_buffer = xrealloc (gmap_buffer, gmap_buffer_size + 1);
	  gmap_buffer[old_size] = '\0'; /* needed for first allocation */
	  strcat (gmap_buffer, buffer);
	}
    }

  for (gmap = currentgmap; gmap; gmap = gmap->next)
    {
      char buffer [256];
      if (gmap->type == shadow || gmap->shadow_specified)
	{
	  sprintf (buffer, " '--shadow-mem=0x%lx,0x%lx,0x%lx%s",
		   gmap->start, gmap->size, gmap->shadow,
		   gmap->cache == cache ? ",cached" : "");
	  if (gmap->shadow_mod_name)
	    {
	      strcat (buffer, ",");
	      strcat (buffer, gmap->shadow_mod_name);
	    }
	  strcat (buffer, "'");
	  /* Make room for the previous contents plus the additional contents */
	  old_size = gmap_buffer_size;
	  gmap_buffer_size += strlen (buffer);
	  gmap_buffer = xrealloc (gmap_buffer, gmap_buffer_size + 1);
	  gmap_buffer[old_size] = '\0'; /* needed for first allocation */
	  strcat (gmap_buffer, buffer);
	}
    }

  return gmap_buffer;
}

static void
generate_simulator_script ()
{
  Node *cfgs, *modules, *lmem, *timer;
  const char *gmap_opts = NULL;
  int channel_bitw;
  Node *n;

  start_file (outdir, "bin/sid", 0);
  generate_script_start ("sid", "");

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      for (modules = find_sub (cfgs, "ME_MODULE", 0); modules; modules = find_next (modules, "ME_MODULE"))
	{
	  fprintf (dst_file, " \"--board=%s\" )\n\t opts=\"$opts '$option'", modules->val);

	  fputs (mep_endian_type == MEP_ENDIAN_LITTLE ? " --EL" : " --EB", dst_file);
	  sidscr_parm (" --biu-width=%d", " --biu-width=64",
		       find_typed_sub (modules, N_NUM, "ME_ENGINE", "BIU", "DATA_WIDTH", 0));
	  sidscr_parm (" --dmac-channel-bitw=%d", " --dmac-channel-bitw=0",
		       find_typed_sub (modules, N_NUM, "DMAC", "CHANNEL_BITW", 0));
	  sidscr_bool (" --dmac-rectangle", " --dmac-no-rectangle",
		       find_typed_sub (modules, N_WORD, "DMAC", "RECTANGLE", 0));
	  fputs (core_opt_set (modules, "ABS") ? " --insn=abs" : " --no-insn=abs", dst_file);
	  fputs (core_opt_set (modules, "AVE") ? " --insn=ave" : " --no-insn=ave", dst_file);
	  fputs (core_opt_set (modules, "BIT") ? " --insn=bit" : " --no-insn=bit", dst_file);
	  fputs (core_opt_set (modules, "CLP") ? " --insn=clp" : " --no-insn=clp", dst_file);
	  fputs (core_opt_set (modules, "DIV") ? " --insn=div" : " --no-insn=div", dst_file);
	  fputs (core_opt_set (modules, "LDZ") ? " --insn=ldz" : " --no-insn=ldz", dst_file);
	  fputs (core_opt_set (modules, "MIN") ? " --insn=min" : " --no-insn=min", dst_file);
	  fputs (core_opt_set (modules, "MUL") ? " --insn=mul" : " --no-insn=mul", dst_file);
	  fputs (core_opt_set (modules, "SAT") ? " --insn=sat" : " --no-insn=sat", dst_file);
	  sidscr_parm (" --imem-size=%d", " --imem-size=0",
		       find_typed_sub (modules, N_NUM, "ME_ENGINE", "IMEM", "SIZE", 0));
	  sidscr_parm (" --dmem-size=%d", " --dmem-size=0",
		       find_typed_sub (modules, N_NUM, "ME_ENGINE", "DMEM", "SIZE", 0));
	  sidscr_parm (" --dmem-bank-num=%d", " --dmem-bank-num=0",
		       find_typed_sub (modules, N_NUM, "ME_ENGINE", "DMEM", "BANK_NUM", 0));
	  sidscr_bool (" --dmem-fixed-start-address", " --dmem-no-fixed-start-address",
		       find_typed_sub (modules, N_WORD, "ME_ENGINE", "DMEM", "FIXED_START_ADDRESS", 0));
	  sidscr_parm (" --icache-size=%d", " --icache-size=0",
		       n = find_typed_sub (modules, N_NUM, "ME_ENGINE", "ICACHE", "SIZE", 0));
	  if (n)
	    {
	      sidscr_parm (" --icache-line-size=%d", "",
			   find_typed_sub (modules, N_NUM, "ME_ENGINE", "ICACHE", "LINE_SIZE", 0));
	      sidscr_parm (" --icache-way=%d", "",
			   find_typed_sub (modules, N_NUM, "ME_ENGINE", "ICACHE", "WAY", 0));
	      sidscr_bool (" --icache-cwf=on", " --icache-cwf=off",
			   find_typed_sub (modules, N_WORD, "ME_ENGINE", "ICACHE", "CWF", 0));
	    }
	  sidscr_parm (" --dcache-size=%d", " --dcache-size=0",
		       n = find_typed_sub (modules, N_NUM, "ME_ENGINE", "DCACHE", "SIZE", 0));
	  if (n)
	    {
	      sidscr_parm (" --dcache-line-size=%d", "",
			   find_typed_sub (modules, N_NUM, "ME_ENGINE", "DCACHE", "LINE_SIZE", 0));
	      sidscr_parm (" --dcache-way=%d", "",
			   find_typed_sub (modules, N_NUM, "ME_ENGINE", "DCACHE", "WAY", 0));
	      sidscr_bool (" --dcache-cwf=on", " --dcache-cwf=off",
			   find_typed_sub (modules, N_WORD, "ME_ENGINE", "DCACHE", "CWF", 0));
	    }
	  sidscr_parm (" --intc-channel-bitw=%d", " --intc-channel-bitw=0",
		       find_typed_sub (modules, N_NUM, "ME_ENGINE", "INTC", "CHANNEL_BITW", 0));
	  sidscr_parm (" --intc-level=%d", " --intc-level=0",
		       find_typed_sub (modules, N_NUM, "ME_ENGINE", "INTC", "LEVEL", 0));

	  for (lmem = find_sub (modules, "LOCAL_MEM", 0); lmem; lmem = find_next (lmem, "LOCAL_MEM"))
	    {
	      Node *a, *s;

	      a = find_typed_sub (lmem, N_NUM, "ADDRESS", 0);
	      s = find_typed_sub (lmem, N_NUM, "SIZE", 0);
	      if (a && s && lmem->val)
	      fprintf (dst_file, " '--local-mem=0x%lx,0x%lx,%s", a->ival, s->ival, lmem->val);
	      if (toshapi)
		fputs (",api", dst_file);
	      fputc ('\'', dst_file);
	    }

	  /* Generate option for the timer, if any */
	  channel_bitw = timer_channel_bitw (modules);
	  fprintf (dst_file, " --timer-channel-bitw=%d\"\n", channel_bitw);

	  /* Generate settings for the global memory map.  */
	  if (! gmap_opts)
	    gmap_opts = gmap_options ();
	  if (gmap_opts)
	    fprintf (dst_file, "\t mem=\"%s\"\n", gmap_opts);

	  fprintf (dst_file, "\t;;\n");
	}
    }

  generate_script_end ("opts=\"$opts $mem\"");
  find_line (NULL, 0, 0, 1);
  end_file ();
  make_executable (concat (outdir, "/bin/sid", NULL));
}

/*----------------------------------------------------------------------*/


static void
validate_directory (const char *dir)
{
  struct stat s;

  if (stat (dir, &s) < 0)
    {
      fprintf (stderr, "Error: %s does not exist.\n", dir);
      exit (EXIT_FAILURE);
    }
  if (! S_ISDIR (s.st_mode))
    {
      fprintf (stderr, "Error: %s is not a directory\n", dir);
      exit (EXIT_FAILURE);
    }
}

/* Note: used for both files and directories.  */
static int
file_exists_p (const char *file)
{
  struct stat s;

  if (stat (file, &s) < 0)
    return 0;
  return 1;
}

static void
read_in_config_file (const char *filename)
{
  cfgin = fopen (filename, "r");
  if (! cfgin)
    {
      fprintf (stderr, "%s: ", filename);
      perror ("cannot open configuration file");
      exit (EXIT_FAILURE);
    }
  cfgfilename = filename;
  cfglineno = 1;
  push_node (filename);
  if (cfgparse () != 0)
    {
      if (errors == 0)
	fprintf (stderr, "configuration failure: parse error\n");
      exit (EXIT_FAILURE);
    }
  /* Save the number of lines in the node representing the config file.  */
  currentcfg->lineno = cfglineno - 1;
  pop_node ();
  fclose (cfgin);
}

int
main (int argc, char **argv)
{
  int i;
  Node *cfg;

  main_argv0 = argv[0];
  
  while (argc > 1 && argv[1][0] == '-')
    {
      if (argc > 2 && strcmp (argv[1], "-s") == 0)
	{
	  validate_directory (argv[2]);
	  srcdir = argv[2];
	  argc -= 2;
	  argv += 2;
	}
      else if (argc > 2 && strcmp (argv[1], "-i") == 0)
	{
	  validate_directory (argv[2]);
	  instdir = argv[2];
	  argc -= 2;
	  argv += 2;
	}
      else if (argc > 2 && strcmp (argv[1], "-o") == 0)
	{
	  validate_directory (argv[2]);
	  outdir = argv[2];
	  argc -= 2;
	  argv += 2;
	}
      else if (strcmp (argv[1], "--nobuild") == 0)
	{
	  if (instdir == 0)
	    instdir = "";
	  nobuild++;
	  argc --;
	  argv ++;
	}
      else if (strcmp (argv[1], "--warn-all") == 0)
	{
	  warn_all ++;
	  argc --;
	  argv ++;
	}
      else if (argc > 2 && strcmp (argv[1], "-c") == 0)
	{
	  validate_directory (argv[2]);
	  configdir = argv[2];
	  argc -= 2;
	  argv += 2;
	}
      else if (strcmp (argv[1], "-v") == 0)
	{
	  verbose ++;
	  argc--;
	  argv++;
	}
      else if (strcmp (argv[1], "-t") == 0)
	{
	  testing ++;
	  argc--;
	  argv++;
	}
      else if (strcmp (argv[1], "-a") == 0)
	{
	  toshapi ++;
	  argc--;
	  argv++;
	}
      else if (argc > 2 && strcmp (argv[1], "--api") == 0)
	{
	  char *ch;
	  int version = strtoul (argv[2], &ch, 10);
	  argc--;
	  argv++;
	  if (*ch == '\0')
	    {
	      if (version >= 0 && version <= 1)
		toshapi_version = version;
	      else
		error ("The value specified for --api must be between 0 and 1.");	      argc--;
	      argv++;
	    }
	}
      else
	{
	  usage ();
	}
    }

  if (verbose)
    show_copyright ();

  if (argc < 2)
    usage ();

  if (instdir)
    {
      char *tagfile;
      if (instdir[0] == 0)
	{
	  char *bp, *tp;
	  /* Guess */
	  instdir = (char *) xmalloc (strlen (main_argv0) + strlen ("/..") + 1);
	  strcpy (instdir, main_argv0);
	  for (bp=0, tp=instdir; *tp; tp++)
	    if (*tp == '/' || *tp == '\\')
	      bp = tp;
	  if (bp)
	    *bp = 0;
	  strcat (instdir, "/..");
	  validate_directory (instdir);
	}

      tagfile = concat (instdir, "/bin/mep-elf-gcc", NULL);
      if (! file_exists_p (tagfile)
	  && ! file_exists_p (concat (instdir, "/bin/mep-elf-gcc.exe", NULL)))
	{
	  error ("%s does not look like an installation directory.\n(no %s)",
		 instdir, tagfile);
	  exit (EXIT_FAILURE);
	}
    }
  else
    validate_directory (srcdir);

  cfgdebug = (verbose > 3);

  fl_context = fl_cfg;
  for (i = 1; i < argc; i++)
    {
      const char *filename = resolve_config_filename (argv[i]);
      read_in_config_file (filename);
    }

  assert (currentcfg != NULL);
  currentcfg = currentcfg->sub;

  for (cfg = currentcfg; cfg; cfg = cfg->next)
    verify_config (cfg);

  if (verbose >= 3)
    {
      dump (stdout, currentcfg);
      fflush(stdout);
    }

  fl_context = fl_none;
  check_corecount_limit ();
  if (verbose)
    fprintf (stderr, "me_module count: %d\n", corecount);
  check_biu ();
  parse_any_gmap ();

  if (instdir)
    {
      Node *oldconfig, *savedconfig, *n, *o;
      char *oldfile, *newdir, *cp;

      savedconfig = currentcfg;
      currentcfg = 0;

      oldfile = concat (instdir, "/mep-elf/current.cfg", NULL);
      if (!file_exists_p (oldfile))
	{
	  error ("The installation at %s does not have a mep-elf/current.cfg", instdir);
	  fprintf (stderr, "Reconfiguring without rebuilding requires that the original build be\n");
	  fprintf (stderr, "configured with a MeP-Integrator that supports this feature.\n");
	  exit (EXIT_FAILURE);
	}

      read_in_config_file (oldfile);
      oldconfig = currentcfg->sub;
      currentcfg = savedconfig;

      for (o = oldconfig, n = currentcfg; o && n; o = o->next, n = n->next)
	compare_configs (o, n);
      if (errors)
	exit (EXIT_FAILURE);

      linker_script_default = concat (instdir, "/mep-elf/lib/gmap_default.tmpl", NULL);

      newdir = strdup (lbasename (currentcfg->id));
      cp = strrchr (newdir, '.');
      if (cp)
	*cp = 0;

      if (outdir)
	outdir = concat (outdir, "/", newdir, NULL);
      else
	{
	  instdir = concat (instdir, "/", newdir, NULL);
	  outdir = instdir;
	}

      cp = concat (outdir, "/mep-elf/lib/", NULL);

      cp[strlen(cp)-1] = 0;
      mkdir_p (cp);
      cp[strlen(cp)] = '/';
      mkdir_p (concat (outdir, "/bin", NULL));

      linker_script_path = cp;

      generate_compiler_script ();
      generate_simulator_script ();
      do_ld_gmap_config (outdir);

      return 0;
    }

  if (errors)
    exit (EXIT_FAILURE);

  start_file (srcdir, "gcc/config/mep/mep.h", 0);
  do_config_cc_spec ();
  do_config_link_spec ();
  do_config_start_spec ();
  do_gcc_target_h1_selection ();
  do_config_driver_option ();
  do_config_library_spec ();
  do_config_coproc_selection ();
  end_file ();

  start_file (srcdir, "gcc/config/mep/t-mep", 0);
  do_gcc_isas ();
  do_extra_headers ();
  end_file ();

  start_file (srcdir, "cgen/cpu/mep-core.cpu", 0);
  do_cpu_config ();
  end_file ();

  start_file (srcdir, "cgen/cpu/mep.opc", 0);
  do_cgen_config_opc ();
  end_file ();

  start_file (srcdir, "sid/main/dynamic/mainDynamic.cxx", 0);
  do_sidmain_config ();
  end_file ();

  start_file (srcdir, "sid/main/dynamic/mepCfg.cxx", 0);
  do_sid_gmap_config ();
  do_mm_int_config ();
  end_file ();

  start_file (srcdir, "sid/component/families/mep/mm_int.h", 0);
  do_mm_int_max_config ();
  end_file ();

  start_file (srcdir, "sid/component/cgen-cpu/compCGEN.cxx", 0);
  do_compCGEN_config ();
  end_file ();

  start_file (srcdir, "sid/component/cgen-cpu/mep/common_model.cxx", 0);
  do_sid_model_config ();
  end_file ();

  do_ld_gmap_config (srcdir);

  start_file (srcdir, "bfd/elf32-mep.c", 0);
  do_bfd_config_names ();
  end_file ();

  do_user_cpu_config ();
  do_user_isa_includes ();
  do_hw_engine_includes ();
  do_peripheral_includes ();
  do_user_cmodel_includes ();
  do_user_code_includes ();

  do_cpu_Makefile_config ("sid/component/cgen-cpu/mep/Makefile.am");
  do_cpu_Makefile_config ("sid/component/cgen-cpu/mep/Makefile.in");

  if (errors)
    exit (EXIT_FAILURE);

  if (num_files_changed == 0)
    printf ("Done.  No files were changed: toolchain recompilation not required.\n");
  else
    {
      start_file (srcdir, "utils/mep/current.cfg", 0);
      dump (dst_file, currentcfg->sub);
      find_line (NULL, 0, 0, 1);
      end_file ();

      printf ("Done.  Please regenerate and rebuild the toolchain:\n");
      printf (rebuild_extra);
      printf ("   cd $BUILDDIR/mep-elf/libgloss/mep\n");
      printf ("   ./config.status\n");
      printf ("   cd $BUILDDIR/sid/component/cgen-cpu/mep\n");
      printf ("   ./config.status\n");
      printf ("   make cgen-all\n");
      printf ("   cd $BUILDDIR/sid/component/families/mep\n");
      printf ("   ./config.status\n");
      printf ("   cd $BUILDDIR/opcodes\n");
      printf ("   make stamp-mep\n");
      printf ("   cd $BUILDDIR/gcc\n");
      printf ("   make cgen-maint\n");
      printf ("   cd $BUILDDIR\n");
      printf ("   make all install\n");
    }

  return 0;
}

/* The remaining code in this file has the following copyright and
   license.  */
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

char *
mep__strtok_r (char *s, const char *delim, 
	       char **lasts, int skip_leading_delim)
{
  register char *spanp;
  register int c, sc;
  char *tok;


  if (s == NULL && (s = *lasts) == NULL)
    return (NULL);

  /*
   * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
   */
 cont:
  c = *s++;
  for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
    if (c == sc) {
      if (skip_leading_delim) {
	goto cont;
      }
      else {
	*lasts = s;
	s[-1] = 0;
	return (s - 1);
      }
    }
  }

  if (c == 0) {/* no non-delimiter characters */
    *lasts = NULL;
    return (NULL);
  }
  tok = s - 1;

  /*
   * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
   * Note that delim must have one NUL; we stop if we see that, too.
   */
  for (;;) {
    c = *s++;
    spanp = (char *)delim;
    do {
      if ((sc = *spanp++) == c) {
	if (c == 0)
	  s = NULL;
	else
	  s[-1] = 0;
	*lasts = s;
	return (tok);
      }
    } while (sc != 0);
  }
  /* NOTREACHED */
}

char *
mep_strtok_r (char *s, const char *delim, char **lasts)
{
  return mep__strtok_r (s, delim, lasts, 1);
}
