/* spu -- A program to make lots of random C/C++ code.
   Copyright (C) 1993, 1994, 2000 Free Software Foundation, Inc.
   Contributed by Cygnus Support.  Written by Stan Shebs.

This file is part of SPU.

SPU is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* This is a random program generator. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *version_string = "0.3";

/* These values are the builtin defaults, mainly useful for testing
   purposes, or if the user is uninterested in setting a value.  */

#define DEFAULT_NUM_FILES 5

#define DEFAULT_NUM_HEADER_FILES 1

#define DEFAULT_NUM_MACROS 10

#define DEFAULT_NUM_LIB_MACROS 30

#define DEFAULT_MAX_MACRO_ARGS 5

#define DEFAULT_NUM_ENUMS 10

#define DEFAULT_NUM_LIB_ENUMS 30

#define DEFAULT_NUM_ENUMERATORS 10

#define DEFAULT_NUM_STRUCTS 10

#define DEFAULT_NUM_LIB_STRUCTS 30

#define DEFAULT_NUM_FIELDS 20

#define DEFAULT_NUM_FUNCTIONS 100

#define DEFAULT_NUM_LIB_FUNCTIONS 300

#define DEFAULT_MAX_FUNCTION_ARGS 8

#define DEFAULT_FUNCTION_LENGTH 20

#define DEFAULT_FUNCTION_DEPTH 3

#define DEFAULT_LIB_PERCENT 10

/* Generic hash table.  */

struct hash_entry
{
  char *val;
  struct hash_entry *next;
};

struct hash_table
{
  struct hash_entry *entries[253];
  int numadds;
};

struct macro_desc
{
  char *name;
  int numargs;
  char **args;
  int use;
};

struct enumerator_desc
{
  char *name;
};

struct enum_desc
{
  char *name;
  int num_enumerators;
  struct enumerator_desc *enumerators;
  int use;
};

struct field_desc
{
  int type;
  char *name;
};

struct struct_desc
{
  char *name;
  int numfields;
  struct field_desc *fields;
  int use;
};

/* (should add unions as type of struct) */

struct type_desc
{
  char *name;
};

struct arg_desc
{
  int type;
  char *name;
};

struct function_desc
{
  char *name;
  int numargs;
  struct arg_desc *args;
  int use;
};

struct file_desc
{
  char *name;
};

/* Function declarations.  */

void display_usage (void);

int hash_string (char *str);

struct hash_entry *get_hash_entry (void);

char *add_to_hash_table (char *buf, struct hash_table *table);

char *get_from_hash_table (char *buf, struct hash_table *table);

void init_xrandom (int seed);

int xrandom (int n);

int probability (int prob);

char *copy_string (char *str);

char *xmalloc (int n);

char *gen_unique_global_name (char *root, int upcase);

void gen_random_global_name (char *root, char *namebuf);

char *gen_random_local_name (int n, char **others);

void create_macros (void);

void create_macro (struct macro_desc *macrodesc);

char *gen_new_macro_name (void);

void create_enums (void);

void create_enum (struct enum_desc *enumdesc);

char *gen_random_enumerator_name (void);

void create_structs (void);

void create_struct (struct struct_desc *structdesc);

char *gen_random_field_name (int n);

void create_functions (void);

void create_function (struct function_desc *fndesc);

void write_header_file (int n);

void write_lib_header_file (void);

void write_source_file (int n);

void write_macro (FILE *fp, struct macro_desc *macrodesc);

void write_enum (FILE *fp, struct enum_desc *enumdesc);

void write_struct (FILE *fp, struct struct_desc *structdesc);

void write_function_decl (FILE *fp, struct function_desc *functiondesc);

void write_function (FILE *fp, int n);

void write_lib_function (FILE *fp, int n);

void write_statement (FILE *fp, int depth, int max_depth);

void write_expression (FILE *fp, int depth, int max_depth);

void write_makefile (void);

/* Global variables.  */

/* The possible languages. */

enum languages { knr, c, cpp, objc };

enum languages language = c;

/* Filename extensions to use with each language type.  */

char *extensions[] = { "c", "c", "cc", "m" };

int num_files = DEFAULT_NUM_FILES;

int num_header_files = DEFAULT_NUM_HEADER_FILES;

char *file_base_name = "file";

int num_macros = DEFAULT_NUM_MACROS;

int num_lib_macros = DEFAULT_NUM_LIB_MACROS;

int num_enums = DEFAULT_NUM_ENUMS;

int num_lib_enums = DEFAULT_NUM_LIB_ENUMS;

int num_enumerators = DEFAULT_NUM_ENUMERATORS;

int num_structs = DEFAULT_NUM_STRUCTS;

int num_lib_structs = DEFAULT_NUM_LIB_STRUCTS;

int num_fields = DEFAULT_NUM_FIELDS;

int num_functions = DEFAULT_NUM_FUNCTIONS;

int num_lib_functions = DEFAULT_NUM_LIB_FUNCTIONS;

int max_function_args = DEFAULT_MAX_FUNCTION_ARGS;

int function_length = DEFAULT_FUNCTION_LENGTH;

int function_depth = DEFAULT_FUNCTION_DEPTH;

/* Percentage of library constructs that will be referenced.  */

int lib_percent = DEFAULT_LIB_PERCENT;

int num_functions_per_file;

/* The amount of commenting in the source.  */

int commenting = 0;

/* Hash table for globally visible symbols.  */

struct hash_table *global_hash_table;

/* The seed for the random number generator.  */

int seed = -1;

/* Space to record info about generated constructs.  */

struct macro_desc *macros;

struct macro_desc *lib_macros;

struct enum_desc *enums;

struct enum_desc *lib_enums;

struct struct_desc *structs;

struct struct_desc *lib_structs;

struct function_desc *functions;

struct function_desc *lib_functions;

int num_computer_terms;

/* Likely words to appear in names of things.  These must never be
   valid C/C++ keywords, since they may appear by themselves in some
   contexts.  */

char *computerese[] = {
  "add", "all", "alloc", "allocate", "area", "array", "at",
  "by", "btree",
  "count", "create", "cull",
  "del", "delete_", "desc", "discard", "dismiss",
  "fill", "find", "fn", "for_",
  "grok",
  "last", "line", "lis", "list", "lose",
  "make", "mod", "modify", "more",
  "new_", "node", "null", "num",
  "part", "partial",
  "query", "queue",
  "ob", "obj", "object", "of",
  "pnt", "point", "pos", "position",
  "rect", "rectangle", "remove", "reset",
  "see", "set", "shape", "str",
  "tag", "tree",
  "vary", "vec", "vect", "vector", "virt", "virtual_",
  "win", "wind", "window",
  "zbuf",
  NULL
};

/* Return a word that commonly appears in programs. */

char *
random_computer_word (void)
{
  if (num_computer_terms == 0)
    {
      int i;

      for (i = 0; computerese[i] != NULL; ++i)
	;
      num_computer_terms = i;
    }
  return computerese[xrandom (num_computer_terms)];
}

int
main (int argc, char **argv)
{
  int i, num;
  char *arg;

  
  /* Parse all the arguments. */
  /* (should check on numeric values) */
  for (i = 1; i < argc; ++i)
    {
      arg = argv[i];
      if (strcmp(arg, "--basename") == 0)
	{
	  file_base_name = copy_string(argv[++i]);
	}
      else if (strcmp(arg, "--comments") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  commenting = num;
	}
      else if (strcmp(arg, "--enums") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_enums = num;
	}
      else if (strcmp(arg, "--enumerators") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_enumerators = num;
	}
      else if (strcmp(arg, "--fields") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_fields = num;
	}
      else if (strcmp(arg, "--files") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_files = num;
	}
      else if (strcmp(arg, "--functions") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_functions = num;
	}
      else if (strcmp(arg, "--function-length") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  function_length = num;
	}
      else if (strcmp(arg, "--function-depth") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  function_depth = num;
	}
      else if (strcmp(arg, "--header-files") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_header_files = num;
	}
      else if (strcmp(arg, "--help") == 0)
	{
	  display_usage ();
	  exit (0);
	}
      else if (strcmp(arg, "--language") == 0)
	{
	  if (strcmp (argv[i+1], "c") == 0)
	    language = c;
	  else if (strcmp (argv[i+1], "cpp") == 0)
	    language = cpp;
	  else if (strcmp (argv[i+1], "knr") == 0)
	    language = knr;
	  else if (strcmp (argv[i+1], "objc") == 0)
	    language = objc;
	  ++i;
	}
      else if (strcmp(arg, "--lib-enums") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_lib_enums = num;
	}
      else if (strcmp(arg, "--lib-functions") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_lib_functions = num;
	}
      else if (strcmp(arg, "--lib-macros") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_lib_macros = num;
	}
      else if (strcmp(arg, "--lib-structs") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_lib_structs = num;
	}
      else if (strcmp(arg, "--macros") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_macros = num;
	}
      else if (strcmp(arg, "--seed") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  seed = num;
	}
      else if (strcmp(arg, "--structs") == 0)
	{
	  num = strtol (argv[++i], NULL, 10);
	  num_structs = num;
	}
      else if (strcmp(arg, "--version") == 0)
	{
	  fprintf (stderr, "SPU program generator version %s\n",
		   version_string);
	  exit (0);
	}
      else
	{
	  fprintf (stderr, "Usage: \"%s\" not valid, ignored\n", arg);
	  display_usage ();
	}
    }
  init_xrandom (seed);
  /* Create the definitions of objects internally. */
  create_macros ();
  create_enums ();
  create_structs ();
  create_functions ();
  /* Round up the number of functions so each file gets the same
     number. */
  num_functions_per_file = (num_functions + num_files - 1) / num_files;
  /* Write out a bunch of files. */
  printf ("Writing %d header files...\n", num_header_files);
  for (i = 0; i < num_header_files; ++i)
    write_header_file (i);
  write_lib_header_file ();
  write_lib_source_file ();
  printf ("Writing %d files...\n", num_files);
  for (i = 0; i < num_files; ++i)
    write_source_file (i);
  /* Write out a makefile. */
  write_makefile ();
  /* Succeed if we actually wrote out a whole program correctly. */
  exit (0);
}

void
display_usage (void)
{
  fprintf (stderr, "Usage: spu [ ... options ... ]\n");
  fprintf (stderr, "\t--basename str (default \"%s\")\n", "file");
  fprintf (stderr, "\t--comments n\n");
  fprintf (stderr, "\t--enums n (default %d)\n", DEFAULT_NUM_ENUMS);
  fprintf (stderr, "\t--enumerators n (default %d)\n", DEFAULT_NUM_ENUMERATORS);
  fprintf (stderr, "\t--fields n (default %d)\n", DEFAULT_NUM_FIELDS);
  fprintf (stderr, "\t--files n (default %d)\n", DEFAULT_NUM_FILES);
  fprintf (stderr, "\t--functions n (default %d)\n", DEFAULT_NUM_FUNCTIONS);
  fprintf (stderr, "\t--function-length n (default %d)\n", DEFAULT_FUNCTION_LENGTH);
  fprintf (stderr, "\t--function-depth n (default %d)\n", DEFAULT_FUNCTION_DEPTH);
  fprintf (stderr, "\t--header-files n (default %d)\n", DEFAULT_NUM_HEADER_FILES);
  fprintf (stderr, "\t--help\n");
  fprintf (stderr, "\t--language c|cpp|knr|objc (default c)\n");
  fprintf (stderr, "\t--lib-enums n (default %d)\n", DEFAULT_NUM_LIB_ENUMS);
  fprintf (stderr, "\t--lib-functions n (default %d)\n", DEFAULT_NUM_LIB_FUNCTIONS);
  fprintf (stderr, "\t--lib-macros n (default %d)\n", DEFAULT_NUM_LIB_MACROS);
  fprintf (stderr, "\t--lib-structs n (default %d)\n", DEFAULT_NUM_LIB_STRUCTS);
  fprintf (stderr, "\t--macros n (default %d)\n", DEFAULT_NUM_MACROS);
  fprintf (stderr, "\t--seed n\n");
  fprintf (stderr, "\t--structs n (default %d)\n", DEFAULT_NUM_STRUCTS);
  fprintf (stderr, "\t--version\n");
}

int
random_type (void)
{
  return xrandom (3);
}

/* Given a numbered type, return its name.  */

char *
name_from_type (int n)
{
  switch (n)
    {
    case 0:
      return "char";
    case 1:
      return "short";
    }
  return "int";
}

/* Create basic definitions of macros.  Negative number of arguments
   means a macros that looks like a constant instead of a function.  */

void
create_macros (void)
{
  int i;

  printf ("Creating %d macros...\n", num_macros);
  macros =
    (struct macro_desc *) xmalloc (num_macros * sizeof(struct macro_desc));
  for (i = 0; i < num_macros; ++i)
    {
      create_macro (&(macros[i]));
    }
  printf ("Creating %d library macros...\n", num_lib_macros);
  lib_macros =
    (struct macro_desc *) xmalloc (num_lib_macros * sizeof(struct macro_desc));
  for (i = 0; i < num_lib_macros; ++i)
    {
      create_macro (&(lib_macros[i]));
      if (!probability(lib_percent))
	lib_macros[i].use = 0;
    }
}

void
create_macro (struct macro_desc *macrodesc)
{
  int j, numargs;

  macrodesc->name = gen_new_macro_name ();
  numargs = xrandom (DEFAULT_MAX_MACRO_ARGS + 1);
  --numargs;
  if (numargs > 0)
    {
      macrodesc->args = (char **) xmalloc (numargs * sizeof(char *));
      for (j = 0; j < numargs; ++j)
	{
	  macrodesc->args[j] = gen_random_local_name (j, NULL);
	}
    }
  macrodesc->numargs = numargs;
  macrodesc->use = 1;
}

/* Generate a macro name.  */

char *
gen_new_macro_name (void)
{
  return gen_unique_global_name ("M", (xrandom (3) > 0));
}

/* Create definitions of the desired number of enums.  */

void
create_enums (void)
{
  int i;

  printf ("Creating %d enums...\n", num_enums);
  enums =
    (struct enum_desc *) xmalloc (num_enums * sizeof(struct enum_desc));
  for (i = 0; i < num_enums; ++i)
    {
      create_enum (&(enums[i]));
    }
  printf ("Creating %d lib_enums...\n", num_lib_enums);
  lib_enums =
    (struct enum_desc *) xmalloc (num_lib_enums * sizeof(struct enum_desc));
  for (i = 0; i < num_lib_enums; ++i)
    {
      create_enum (&(lib_enums[i]));
      if (!probability(lib_percent))
	lib_enums[i].use = 0;
    }
}

void
create_enum (struct enum_desc *enumdesc)
{
  int j, num;

  /* Let some enums be anonymous. */
  if (xrandom (100) < 50)
    enumdesc->name = gen_unique_global_name (NULL, 0);
  num = num_enumerators / 2 + xrandom (num_enumerators);
  if (num <= 0)
    num = 1;
  enumdesc->enumerators =
    (struct enumerator_desc *) xmalloc (num * sizeof(struct enumerator_desc));
  for (j = 0; j < num; ++j)
    {
      enumdesc->enumerators[j].name = gen_random_enumerator_name ();
    }
  enumdesc->num_enumerators = j;
  enumdesc->use = 1;
}

/* Generate a unique enumerator within an enum.  */

char *
gen_random_enumerator_name (void)
{
  return gen_unique_global_name ("enum", 0);
}

/* Create definitions of the desired number of structures.  */

void
create_structs (void)
{
  int i;

  printf ("Creating %d structs...\n", num_structs);
  structs =
    (struct struct_desc *) xmalloc (num_structs * sizeof(struct struct_desc));
  for (i = 0; i < num_structs; ++i)
    {
      create_struct (&(structs[i]));
    }
  printf ("Creating %d library structs...\n", num_lib_structs);
  lib_structs =
    (struct struct_desc *) xmalloc (num_lib_structs * sizeof(struct struct_desc));
  for (i = 0; i < num_lib_structs; ++i)
    {
      create_struct (&(lib_structs[i]));
      if (!probability(lib_percent))
	lib_structs[i].use = 0;
    }
}

void
create_struct (struct struct_desc *structdesc)
{
  int j, numf;

  structdesc->name = gen_unique_global_name (NULL, 0);
  numf = xrandom (num_fields) + 1;
  structdesc->fields =
    (struct field_desc *) xmalloc (numf * sizeof(struct field_desc));
  for (j = 0; j < numf; ++j)
    {
      structdesc->fields[j].type = random_type ();
      structdesc->fields[j].name = gen_random_field_name (j);
    }
  structdesc->numfields = numf;
  structdesc->use = 1;
}

char *
gen_random_field_name (int n)
{
  char namebuf[100];

  /* (should have more variety) */
  sprintf (namebuf, "field%d", n);
  return copy_string (namebuf);
}

/* Create a number of functions with random numbers of arguments. */

/* (should gen with random arg types also) */

void
create_functions (void)
{
  int i;

  printf ("Creating %d functions...\n", num_functions);
  functions =
    (struct function_desc *) xmalloc (num_functions * sizeof(struct function_desc));
  /* Generate the main program, as the first function.  */
  functions[0].name = "main";
  functions[0].numargs = 0;
  /* Generate all the other functions.  The bodies don't get created
     until the functions are being written out.  */
  for (i = 1; i < num_functions; ++i)
    {
      create_function (&(functions[i]));
    }

  printf ("Creating %d library functions...\n", num_lib_functions);
  lib_functions =
    (struct function_desc *) xmalloc (num_lib_functions * sizeof(struct function_desc));
  for (i = 0; i < num_lib_functions; ++i)
    {
      create_function (&(lib_functions[i]));
      if (!probability(lib_percent))
	lib_functions[i].use = 0;
    }
}

/* Generate the details of a single function.  */

void
create_function (struct function_desc *fndesc)
{
  int j, range, numargs;

  fndesc->name = gen_unique_global_name ("fn", 0);
  /* Choose the number of arguments, preferring shorter argument
     lists by using a simple binomial distribution.  */
  range = 2 * (max_function_args + 1);
  numargs = 0;
  for (j = 0; j < 6; ++j)
    numargs += xrandom (range + 1);
  if (j > 0)
    numargs /= j;
  /* Shift distribution so 0 is in the middle.  */
  numargs -= max_function_args;
  /* Fold negative values over to positive side.  */
  if (numargs < 0)
    numargs = -numargs;
  if (numargs > max_function_args)
    numargs = max_function_args;
  fndesc->args =
    (struct arg_desc *) xmalloc (numargs * sizeof(struct arg_desc));
  for (j = 0; j < numargs; ++j)
    {
      fndesc->args[j].type = 0;
      fndesc->args[j].name = gen_random_local_name (j, NULL);
    }
  fndesc->numargs = numargs;
  fndesc->use = 1;
}

void
write_header_file (int n)
{
  int i;
  char tmpbuf[100];
  FILE *fp;

  sprintf (tmpbuf, "%s%d.h", file_base_name, n);
  fp = fopen (tmpbuf, "w");
  if (fp)
    {
      if (commenting > 0)
	fprintf (fp, "/* header */\n");
      if (1)
	{
	  printf ("Writing %d macros...\n", num_macros);
	  for (i = 0; i < num_macros; ++i)
	    {
	      write_macro (fp, &(macros[i]));
	    }
	}
      if (1)
	{
	  printf ("Writing %d enums...\n", num_enums);
	  printf ("  (Each enum contains up to %d values)\n", num_enumerators);
	  for (i = 0; i < num_enums; ++i)
	    {
	      write_enum (fp, &(enums[i]));
	    }
	}
      if (1)
	{
	  printf ("Writing %d structs...\n", num_structs);
	  printf ("  (Each struct contains %d fields)\n", num_fields);
	  for (i = 0; i < num_structs; ++i)
	    {
	      write_struct (fp, &(structs[i]));
	    }
	}
      if (1)
	{
	  printf ("Writing %d function decls...\n", num_functions);
	  for (i = 0; i < num_functions; ++i)
	    {
	      write_function_decl (fp, &(functions[i]));
	    }
	}
      fclose (fp);
    }
}

void
write_lib_header_file (void)
{
  int i;
  char tmpbuf[100];
  FILE *fp;

  sprintf (tmpbuf, "%slib.h", file_base_name);
  fp = fopen (tmpbuf, "w");
  if (fp)
    {
      if (commenting > 0)
	fprintf (fp, "/* library header */\n");
      if (1)
	{
	  printf ("Writing %d library macros...\n", num_lib_macros);
	  for (i = 0; i < num_lib_macros; ++i)
	    {
	      write_macro (fp, &(lib_macros[i]));
	    }
	}
      if (1)
	{
	  printf ("Writing %d library enums...\n", num_lib_enums);
	  printf ("  (Each enum contains up to %d values)\n", num_enumerators);
	  for (i = 0; i < num_lib_enums; ++i)
	    {
	      write_enum (fp, &(lib_enums[i]));
	    }
	}
      if (1)
	{
	  printf ("Writing %d library structs...\n", num_lib_structs);
	  printf ("  (Each struct contains %d fields)\n", num_fields);
	  for (i = 0; i < num_lib_structs; ++i)
	    {
	      write_struct (fp, &(lib_structs[i]));
	    }
	}
      if (1)
	{
	  printf ("Writing %d lib function decls...\n", num_lib_functions);
	  for (i = 0; i < num_lib_functions; ++i)
	    {
	      write_function_decl (fp, &(lib_functions[i]));
	    }
	}
      fclose (fp);
    }
}

void
write_macro (FILE *fp, struct macro_desc *macrodesc)
{
  int i, j;

  fprintf (fp, "#define %s", macrodesc->name);
  /* Negative # arguments indicates an argumentless macro instead of
     one with zero arguments. */
  if (macrodesc->numargs >= 0)
    {
      fprintf (fp, "(");
      for (j = 0; j < macrodesc->numargs; ++j)
	{
	  if (j > 0)
	    fprintf (fp, ",");
	  fprintf (fp, "%s", macrodesc->args[j]);
	}
      fprintf (fp, ")");
    }
  /* Generate a macro body. */
  switch (xrandom(2))
    {
    case 0:
      fprintf (fp, " \\\n");
      fprintf (fp, "(");
      if (macrodesc->numargs > 0)
	{
	  for (i = 0; i < macrodesc->numargs; ++i)
	    {
	      if (i > 0)
		fprintf (fp, ",");
	      fprintf (fp, " \\\n");
	      fprintf (fp, "  (%s)", macrodesc->args[i]);
	      if (xrandom (2) == 0)
		{
		  fprintf (fp, ",");
		  fprintf (fp, " \\\n");
		  fprintf (fp, " ((int) (%s))", macrodesc->args[i]);
		}
	    }
	  fprintf (fp, " \\\n");
	}
      else
	{
	  fprintf (fp, " (1)");
	}
      fprintf (fp, ")");
      break;
    default:
      fprintf (fp, " (%d)", xrandom (100));
      break;
    }
  fprintf (fp, "\n\n");
}

/* Write out the definition of a enum. */

void
write_enum (FILE *fp, struct enum_desc *enumdesc)
{
  int j;

  fprintf (fp, "enum");
  if (enumdesc->name)
    fprintf (fp, " %s", enumdesc->name);
  fprintf (fp, " {");
  for (j = 0; j < enumdesc->num_enumerators; ++j)
    {
      if (j > 0)
	fprintf (fp, ",");
      fprintf (fp, "\n  %s", enumdesc->enumerators[j].name);
    }
  fprintf (fp, "\n};\n\n");
}

/* Write out the definition of a structure. */

void
write_struct (FILE *fp, struct struct_desc *structdesc)
{
  int j;

  fprintf (fp, "struct %s {\n", structdesc->name);
  for (j = 0; j < structdesc->numfields; ++j)
    {
      fprintf (fp, "  %s %s;\n",
	       name_from_type (structdesc->fields[j].type),
	       structdesc->fields[j].name);
    }
  fprintf (fp, "};\n\n");
}

void
write_function_decl (FILE *fp, struct function_desc *fndesc)
{
  int i;

  fprintf (fp, "int %s (", fndesc->name);
  if (language != knr)
    {
      for (i = 0; i < fndesc->numargs; ++i)
	{
	  fprintf (fp, "int %s", fndesc->args[i].name);
	  if (i + 1 < fndesc->numargs)
	    fprintf (fp, ", ");
	}
    }
  fprintf (fp, ");\n");
}

/* Write a complete source file. */

void
write_source_file (int n)
{
  char tmpbuf[100];
  int j;
  FILE *fp;
  extern unsigned long initial_randstate;

  sprintf (tmpbuf, "%s%d.%s",
	   file_base_name, n, extensions[language]);
  fp = fopen (tmpbuf, "w");
  if (fp)
    {
      fprintf (fp,
	       "/* A fine software product by SPU %s, random seed == %d */\n\n",
	       version_string, (int) initial_randstate);
      if (1 /*num_lib_header_files*/ > 0)
	{
	  for (j = 0; j < 1 /*num_header_files*/; ++j)
	    {
	      fprintf (fp, "#include \"%slib.h\"\n", file_base_name);
	    }
	  fprintf (fp, "\n");
	}
      if (num_header_files > 0)
	{
	  for (j = 0; j < num_header_files; ++j)
	    {
	      fprintf (fp, "#include \"%s%d.h\"\n", file_base_name, j);
	    }
	  fprintf (fp, "\n");
	}

      if (n == 0)
	printf ("  (Each file contains %d functions)\n",
		num_functions_per_file);

      for (j = 0; j < num_functions_per_file; ++j)
	{
	  write_function (fp, n * num_functions_per_file + j);
	}
    }
  fclose (fp);
}

void
write_function (FILE *fp, int n)
{
  int i, k;

  fprintf(fp, "int\n%s (", functions[n].name);
  for (i = 0; i < functions[n].numargs; ++i)
    {
      if (language != knr)
	{
	  fprintf (fp, "int ");
	}
      fprintf (fp, "%s", functions[n].args[i].name);
      if (i + 1 < functions[n].numargs)
	fprintf (fp, ", ");
    }
  fprintf(fp, ")\n");
  if (language == knr)
    {
      for (i = 0; i < functions[n].numargs; ++i)
	{
	  fprintf (fp, "int %s;\n", functions[n].args[i].name);
	}
    }
  fprintf(fp, "{\n");
  /* Generate a plausible function body by writing a number of
     statements. */
  for (k = 0; k < function_length; ++k)
    {
      write_statement (fp, 1, function_depth - 1 + xrandom (3));
    }
  fprintf (fp, "}\n\n");
}

void
write_lib_source_file (void)
{
  char tmpbuf[100];
  int j;
  FILE *fp;

  sprintf (tmpbuf, "%slib.%s", file_base_name, extensions[language]);
  fp = fopen (tmpbuf, "w");
  if (fp)
    {
      if (1 /*num_lib_header_files*/ > 0)
	{
	  for (j = 0; j < 1 /*num_header_files*/; ++j)
	    {
	      fprintf (fp, "#include \"%slib.h\"\n", file_base_name);
	    }
	  fprintf (fp, "\n");
	}

      for (j = 0; j < num_lib_functions; ++j)
	{
	  write_lib_function (fp, j);
	}
    }
  fclose (fp);
}

/* Generate empty bodies for library function definitions.  */

void
write_lib_function (FILE *fp, int n)
{
  int i;

  fprintf (fp, "int\n%s (", lib_functions[n].name);
  for (i = 0; i < lib_functions[n].numargs; ++i)
    {
      if (language != knr)
	{
	  fprintf (fp, "int ");
	}
      fprintf (fp, "%s", lib_functions[n].args[i].name);
      if (i + 1 < lib_functions[n].numargs)
	fprintf (fp, ", ");
    }
  fprintf (fp, ")");
  if (!lib_functions[n].use)
    fprintf (fp, "/* unused */");
  fprintf (fp, "\n");
  if (language == knr)
    {
      for (i = 0; i < lib_functions[n].numargs; ++i)
	{
	  fprintf (fp, "int %s;\n", lib_functions[n].args[i].name);
	}
    }
  fprintf (fp, "{\n");
  fprintf (fp, "}\n\n");
}

void
write_statement (FILE *fp, int depth, int max_depth)
{
  int i;

  for (i = 0; i < depth; ++i)
    fprintf (fp, "  ");
  /* Always do non-recursive statements if going too deep. */
  if (depth >= max_depth)
    {
      write_expression (fp, 0, xrandom(4) + 1);
      fprintf (fp, ";\n");
      return;
    }
  switch (xrandom(2))
    {
    case 0:
      write_expression (fp, 0, xrandom(4) + 1);
      fprintf (fp, ";");
      break;
    case 1:
      fprintf (fp, "if (");
      write_expression (fp, 0, xrandom(2) + 1);
      fprintf (fp, ") {\n");
      write_statement(fp, depth + 1, max_depth);
      for (i = 0; i < depth; ++i)
	fprintf (fp, "  ");
      fprintf (fp, "}");
      break;
    }
  fprintf(fp, "\n");
}

/* Write a single expression. */

void
write_expression (FILE *fp, int depth, int max_depth)
{
  int n, n2, j;

  /* Always do non-recursive statements if going too deep. */
  if (depth >= max_depth)
    {
    getout:
      switch (xrandom(10))
	{
	case 7:
	  fprintf (fp, "%d", xrandom (1000));
	  break;
	default:
	  fprintf (fp, "%d", xrandom (127));
	  break;
	}
      return;
    }
  switch (xrandom(10))
    {
    case 0:
      for (j = 0; j < 1000; ++j)
	{
	  n = xrandom (num_lib_functions);
	  if (lib_functions[n].use)
	    break;
	}
      if (!lib_functions[n].use)
	goto getout;
      n = xrandom (num_lib_functions);
      fprintf(fp, "%s (", lib_functions[n].name);
      for (j = 0; j < lib_functions[n].numargs; ++j)
	{
	  if (j > 0)
	    fprintf (fp, ", ");
	  write_expression(fp, depth + 1, max_depth - 1);
	}
      fprintf(fp, ")");
      break;
    case 7:
      n = xrandom (num_functions);
      fprintf(fp, "%s (", functions[n].name);
      for (j = 0; j < functions[n].numargs; ++j)
	{
	  if (j > 0)
	    fprintf (fp, ", ");
	  write_expression(fp, depth + 1, max_depth - 1);
	}
      fprintf(fp, ")");
      break;
    case 1:
    case 6:
      for (j = 0; j < 1000; ++j)
	{
	  n = xrandom (num_lib_macros);
	  if (lib_macros[n].use)
	    break;
	}
      if (!lib_macros[n].use)
	goto getout;
      fprintf(fp, "%s", lib_macros[n].name);
      if (lib_macros[n].numargs >= 0)
	{
	  fprintf(fp, " (");
	  for (j = 0; j < lib_macros[n].numargs; ++j)
	    {
	      if (j > 0)
		fprintf (fp, ", ");
	      write_expression(fp, depth + 1, max_depth - 1);
	    }
	  fprintf(fp, ")");
	}
      break;
    case 8:
      n = xrandom (num_macros);
      fprintf(fp, "%s", macros[n].name);
      if (macros[n].numargs >= 0)
	{
	  fprintf(fp, " (");
	  for (j = 0; j < macros[n].numargs; ++j)
	    {
	      if (j > 0)
		fprintf (fp, ", ");
	      write_expression(fp, depth + 1, max_depth - 1);
	    }
	  fprintf(fp, ")");
	}
      break;
    case 2:
      write_expression (fp, depth + 1, max_depth);
      fprintf (fp, " + ");
      write_expression (fp, depth + 1, max_depth);
      break;
    case 3:
      write_expression (fp, depth + 1, max_depth);
      fprintf (fp, " - ");
      write_expression (fp, depth + 1, max_depth);
      break;
    case 4:
      write_expression (fp, depth + 1, max_depth);
      fprintf (fp, " * ");
      write_expression (fp, depth + 1, max_depth);
      break;
    case 5:
      n = xrandom (num_enums);
      n2 = xrandom (enums[n].num_enumerators);
      fprintf (fp, "%s", enums[n].enumerators[n2].name);
      break;
    default:
      fprintf (fp, "%d", xrandom (127));
      break;
    }
}

/* Write out a makefile that will compile the program just generated. */

void
write_makefile (void)
{
  char tmpbuf[100];
  int i, j;
  FILE *fp;

  sprintf (tmpbuf, "%s.mk", file_base_name);
  fp = fopen (tmpbuf, "w");
  if (fp)
    {
      /* Name the compiler so we can change it easily.  */
      fprintf (fp, "CC = cc\n\n");
      /* Write dependencies and action line for the executable.  */
      fprintf (fp, "%s:	", file_base_name);
      for (i = 0; i < num_files; ++i)
	fprintf (fp, " %s%d.o", file_base_name, i);
      fprintf (fp, " %slib.o", file_base_name);
      fprintf (fp, "\n");
      fprintf (fp, "\t$(CC) -o %s.out", file_base_name);
      for (i = 0; i < num_files; ++i)
	fprintf (fp, " %s%d.o", file_base_name, i);
      fprintf (fp, " %slib.o", file_base_name);
      fprintf (fp, "\n\n");
      /* Write dependencies for individual files. */
      for (i = 0; i < num_files; ++i)
	{
	  fprintf (fp, " %s%d.o:	%s%d.%s",
		   file_base_name, i, file_base_name, i,
		   extensions[language]);
	  for (j = 0; j < num_header_files; ++j)
	    fprintf (fp, " %s%d.h", file_base_name, j);
	  fprintf (fp, "\n");
	  fprintf (fp, "\t$(CC) -c %s%d.%s\n",
		   file_base_name, i, extensions[language]);
	}
      fprintf (fp, " %slib.o:	%slib.%s %slib.h",
	       file_base_name, file_base_name, extensions[language],
	       file_base_name);
      fprintf (fp, "\n");
      fprintf (fp, "\t$(CC) -c %slib.%s\n",
	       file_base_name, extensions[language]);
      fclose (fp);
    }
}


/* Utility/general functions. */

char *
gen_unique_global_name (char *root, int upcase)
{
  int i, j;
  char *str, namebuf[100];

  if (global_hash_table == NULL)
    {
      global_hash_table =
	(struct hash_table *) xmalloc (sizeof (struct hash_table));
    }
  str = NULL;
  /* Keep trying until we get a unique name. */
  for (i = 0; i < 100; ++i)
    {
      gen_random_global_name (root, namebuf);
      if (upcase)
	{
	  for (j = 0; namebuf[j] != '\0'; ++j)
	    namebuf[j] = toupper (namebuf[j]);
	}
      if (get_from_hash_table (namebuf, global_hash_table) == NULL)
	{
	  str = add_to_hash_table (namebuf, global_hash_table);
	  break;
	}
    }
  if (str == NULL)
    {
      fprintf (stderr, "Can't get a unique name!\n");
      exit(1);
    }
  return str;
}

void
gen_random_global_name (char *root, char *namebuf)
{
  char smallbuf[100];
  int n, i, len;

  namebuf[0] = '\0';
  switch (xrandom (4))
    {
    case 0:
      namebuf[0] = 'a' + xrandom (26);
      namebuf[1] = '\0';
      break;
    case 1:
      /* Convert a random number into a string, maybe with some
	 underscores thrown in for flavor.  */
      n = xrandom (10000);
      i = 0;
      while (n > 0)
	{
	  if (xrandom(6) == 0)
	    namebuf[i++] = '_';
	  namebuf[i++] = 'a' + (n % 26);
	  n /= 26;
	}
      namebuf[i] = '\0';
      break;
    default:
      strcat (namebuf, random_computer_word ());
      break;
    }
  if (root != NULL)
    {
      strcat (namebuf, "_");
      strcat (namebuf, root);
    }
  switch (xrandom (4))
    {
    case 0:
      strcat (namebuf, "_");
      len = strlen (namebuf);
      namebuf[len] = 'a' + xrandom (26);
      namebuf[len + 1] = '\0';
      break;
    case 1:
      strcat (namebuf, "_");
      sprintf (smallbuf, "%d", xrandom (10000));
      strcat (namebuf, smallbuf);
      break;
    default:
      strcat (namebuf, "_");
      strcat (namebuf, random_computer_word ());
      break;
    }
}

/* Generate a local variable name. */

char *
gen_random_local_name (int numothers, char **others)
{
  char namebuf[100];

  sprintf (namebuf, "%s%d",
	   (xrandom (2) == 0 ? random_computer_word () : "arg"),
	   numothers + 1);
  return copy_string (namebuf);
}

/* Generic hash table code. */

int
hash_string (char *str)
{
  int i, rslt;

  rslt = 0;
  for (i = 0; str[i] != '\0'; ++i)
    {
      rslt ^= str[i];
      rslt %= 253;
    }
  return rslt;
}

struct hash_entry *
get_hash_entry (void)
{
  return (struct hash_entry *) xmalloc (sizeof (struct hash_entry));
}

char *
add_to_hash_table (char *buf, struct hash_table *table)
{
  int hash;
  struct hash_entry *ent, *lastent;

  if (buf == NULL)
    buf = "";
  ++(table->numadds);
  hash = hash_string (buf);
  if (table->entries[hash] == NULL)
    {
      table->entries[hash] = get_hash_entry ();
      table->entries[hash]->val = copy_string (buf);
      return table->entries[hash]->val;
    }
  else
    {
      for (ent = table->entries[hash]; ent != NULL; ent = ent->next)
	{
	  if (ent->val == NULL)
	    return "null!?!";
	  if (strcmp (buf, ent->val) == 0)
	    return ent->val;
	  lastent = ent;
	}
      if (lastent != NULL)
	{
	  lastent->next = get_hash_entry ();
	  lastent->next->val = copy_string (buf);
	  return lastent->next->val;
	}
    }
  /* should never happen */
  return "?!hash!?";
}

char *
get_from_hash_table (char *buf, struct hash_table *table)
{
  int hash;
  struct hash_entry *ent, *lastent;

  if (buf == NULL)
    buf = "";
  hash = hash_string (buf);
  if (table->entries[hash] == NULL)
    {
      return NULL;
    }
  else
    {
      for (ent = table->entries[hash]; ent != NULL; ent = ent->next)
	{
	  if (ent->val == NULL)
	    return "null!?!";
	  if (strcmp (buf, ent->val) == 0)
	    return ent->val;
	  lastent = ent;
	}
      if (lastent != NULL)
	{
	  return NULL;
	}
    }
  /* should never happen */
  return "?!hash!?";
}

#include <time.h>

/* Random number handling is important but terrible/nonexistent in
   some systems.  Do it ourselves.  Also, this will give repeatable
   results across multiple platforms, which is important if this is
   being used to generate test cases. */

/* The random state *must* be at least 32 bits.  */

unsigned long initial_randstate = 0;

unsigned long randstate = 0;

/* Seed can come from elsewhere, for repeatability.  Otherwise, it comes
   from the current time, scaled down to where 32-bit arithmetic won't
   overflow.  */

void
init_xrandom (int seed)
{
  time_t tm;
    	
  if (seed > 0)
    {
      /* If the random state is already set, changes are somewhat
	 suspicious.  */
      if (randstate > 0)
	{
	  fprintf (stderr, "Randstate being changed from %lu to %d\n",
		   randstate, seed);
	}
      randstate = seed;
    }
  else
    {
      time (&tm);
      randstate = tm;
    }
  /* Whatever its source, put the randstate into known range (0 - 99999).  */
  randstate = abs (randstate);
  randstate %= 100000L;
  /* This is kept around for the sake of error reporting. */
  initial_randstate = randstate;
}

/* Numbers lifted from Numerical Recipes, p. 198.  */
/* Arithmetic must be 32-bit.  */

int
xrandom (int m)
{
  randstate = (8121 * randstate + 28411) % 134456L;
  return ((m * randstate) / 134456L);
}

/* Percentage probability, with bounds checking. */

int
probability(int prob)
{
  if (prob <= 0)
    return 0;
  if (prob >= 100)
    return 1;
  return (xrandom(100) < prob);
}

char *
xmalloc (int amt)
{
  char *value = (char *) malloc (amt);

  if (value == NULL)
    {
      /* This is pretty serious, have to get out quickly.  */
      fprintf (stderr, "Memory exhausted!!\n");
      exit (1);
    }
  /* Save callers from having to clear things themselves.  */
  memset (value, 0, amt);
  return value;
}

/* Copy a string to newly-allocated space.  The new space is never
   freed.  */

char *
copy_string (char *str)
{
  int len = strlen (str);
  char *rslt;
  
  rslt = xmalloc (len + 1);
  strcpy (rslt, str);
  return rslt;
}
