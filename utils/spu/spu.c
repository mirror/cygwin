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

char *version_string = "0.2";

/* These values are the builtin defaults, mainly useful for testing
   purposes, or if the user is uninterested in setting a value.  */

#define DEFAULT_NUM_FILES 5

#define DEFAULT_NUM_HEADER_FILES 1

#define DEFAULT_NUM_MACROS 10

#define DEFAULT_NUM_ENUMS 10

#define DEFAULT_NUM_ENUMERATORS 5

#define DEFAULT_NUM_STRUCTS 20

#define DEFAULT_NUM_FIELDS 20

#define DEFAULT_NUM_FUNCTIONS 100

#define DEFAULT_FUNCTION_LENGTH 20

#define DEFAULT_FUNCTION_DEPTH 3

/* The limits on these should be eliminated... */

#define MAX_MACROS 50000

#define MAX_MACRO_ARGS 10

#define MAX_ENUMS 1000

#define MAX_ENUMERATORS 1000

#define MAX_STRUCTS 1000

#define MAX_STRUCT_FIELDS 100

#define MAX_FUNCTIONS 100000

#define MAX_FUNCTION_ARGS 20

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
  char *args[MAX_MACRO_ARGS];
};

struct enumerator_desc
{
  char *name;
};

struct enum_desc
{
  char *name;
  int num_enumerators;
  struct enumerator_desc enumerators[MAX_ENUMERATORS];
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
  struct field_desc fields[MAX_STRUCT_FIELDS];
};

/* (should add unions as type of struct) */

struct type_desc
{
  char *name;
};

struct function_desc
{
  char *name;
  int numargs;
  char *args[MAX_FUNCTION_ARGS];
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

char *copy_string (char *str);

char *xmalloc (int n);

char *gen_unique_global_name (char *root, int upcase);

void gen_random_global_name (char *root, char *namebuf);

char *gen_random_local_name (int n, char **others);

void create_macros (void);

char *gen_new_macro_name (void);

void create_enums (void);

char *gen_new_enum_name (void);

char *gen_random_enumerator_name (void);

void create_structs (void);

char *gen_new_struct_name (void);

char *gen_random_field_name (int n);

void create_functions (void);

char *gen_new_function_name (void);

void write_header_file (int n);

void write_source_file (int n);

void write_macro (FILE *fp, int n);

void write_enum (FILE *fp, int n);

void write_struct (FILE *fp, int n);

void write_function_decl (FILE *fp, int n);

void write_function (FILE *fp, int n);

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

int num_enums = DEFAULT_NUM_ENUMS;

int num_enumerators = DEFAULT_NUM_ENUMERATORS;

int num_structs = DEFAULT_NUM_STRUCTS;

int num_fields = DEFAULT_NUM_FIELDS;

int num_functions = DEFAULT_NUM_FUNCTIONS;

int function_length = DEFAULT_FUNCTION_LENGTH;

int function_depth = DEFAULT_FUNCTION_DEPTH;

int num_functions_per_file;

/* The amount of commenting in the source.  */

int commenting = 0;

/* Hash table for globally visible symbols.  */

struct hash_table *global_hash_table;

/* The seed for the random number generator.  */

int seed = -1;

/* Space to record info about generated constructs.  */

struct macro_desc macros[MAX_MACROS];

struct enum_desc enums[MAX_ENUMS];

struct struct_desc structs[MAX_STRUCTS];

struct function_desc functions[MAX_FUNCTIONS];

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

/* Create basic definitions of macros.  */

void
create_macros (void)
{
  int i, j, numargs;

  printf ("Creating %d macros...\n", num_macros);
  for (i = 0; i < num_macros; ++i)
    {
      macros[i].name = gen_new_macro_name ();
      numargs = xrandom (MAX_MACRO_ARGS + 1);
      --numargs;
      for (j = 0; j < numargs; ++j)
	{
	  macros[i].args[j] = gen_random_local_name (j, NULL);
	}
      macros[i].numargs = numargs;
    }
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
  int i, j, num;

  printf ("Creating %d enums...\n", num_enums);
  for (i = 0; i < num_enums; ++i)
    {
      /* Let some enums be anonymous. */
      if (xrandom (100) < 50)
	enums[i].name = gen_new_enum_name ();
      num = num_enumerators / 2 + xrandom (num_enumerators);
      for (j = 0; j < num; ++j)
	{
	  enums[i].enumerators[j].name = gen_random_enumerator_name ();
	}
      enums[i].num_enumerators = j;
    }
}

/* Generate a unique enum name.  */

char *
gen_new_enum_name ()
{
  return gen_unique_global_name (NULL, 0);
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
  int i, j;

  printf ("Creating %d structs...\n", num_structs);
  for (i = 0; i < num_structs; ++i)
    {
      structs[i].name = gen_new_struct_name ();
      structs[i].numfields = xrandom (num_fields) + 1;
      for (j = 0; j < structs[i].numfields; ++j)
	{
	  structs[i].fields[j].type = random_type ();
	  structs[i].fields[j].name = gen_random_field_name (j);
	}
    }
}

/* Generate a unique structure tag name.  */

char *
gen_new_struct_name (void)
{
  return gen_unique_global_name (NULL, 0);
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
  int i, j, maxargs, numargs;

  printf ("Creating %d functions...\n", num_functions);
  /* Generate the main program.  */
  functions[0].name = "main";
  functions[0].numargs = 0;
  /* Generate all the other functions.  The bodies don't get created
     until the functions are being written out.  */
  for (i = 1; i < num_functions; ++i)
    {
      functions[i].name = gen_new_function_name ();
      /* Choose the number of arguments, preferring shorter argument
	 lists by using a simple binomial distribution.  */
      maxargs = 2 * (MAX_FUNCTION_ARGS + 1);
      numargs = 0;
      for (j = 0; j < 6; ++j)
	{
	  numargs += xrandom (maxargs);
	}
      if (j > 0)
	numargs /= j;
      numargs -= MAX_FUNCTION_ARGS + 1;
      if (numargs < 0)
	numargs = -numargs;
      if (numargs > MAX_FUNCTION_ARGS)
	numargs = MAX_FUNCTION_ARGS;
      for (j = 0; j < numargs; ++j)
	{
	  functions[i].args[j] = gen_random_local_name (j, NULL);
	}
      functions[i].numargs = numargs;
    }
}

/* Generate a function name.  */

char *
gen_new_function_name (void)
{
  return gen_unique_global_name ("fn", 0);
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
	      write_macro (fp, i);
	    }
	}
      if (1)
	{
	  printf ("Writing %d enums...\n", num_enums);
	  for (i = 0; i < num_enums; ++i)
	    {
	      write_enum (fp, i);
	    }
	}
      if (1)
	{
	  printf ("Writing %d structs...\n", num_structs);
	  for (i = 0; i < num_structs; ++i)
	    {
	      write_struct (fp, i);
	    }
	}
      if (1)
	{
	  printf ("Writing %d function decls...\n", num_functions);
	  for (i = 0; i < num_functions; ++i)
	    {
	      write_function_decl (fp, i);
	    }
	}
      fclose (fp);
    }
}

void
write_macro (FILE *fp, int n)
{
  int i, j;

  fprintf (fp, "#define %s", macros[n].name);
  /* Negative # arguments indicates an argumentless macro instead of
     one with zero arguments. */
  if (macros[n].numargs >= 0)
    {
      fprintf (fp, "(");
      for (j = 0; j < macros[n].numargs; ++j)
	{
	  if (j > 0)
	    fprintf (fp, ",");
	  fprintf (fp, "%s", macros[n].args[j]);
	}
      fprintf (fp, ")");
    }
  /* Generate a macro body. */
  switch (xrandom(2))
    {
    case 0:
      fprintf (fp, "\\\n");
      fprintf (fp, "(");
      if (macros[n].numargs > 0)
	{
	  for (i = 0; i < macros[n].numargs; ++i)
	    {
	      if (i > 0)
		fprintf (fp, ",");
	      fprintf (fp, " \\\n");
	      fprintf (fp, "  (%s)", macros[n].args[i]);
	      if (xrandom (2) == 0)
		{
		  fprintf (fp, ",");
		  fprintf (fp, " \\\n");
		  fprintf (fp, " ((int) (%s))", macros[n].args[i]);
		}
	    }
	  fprintf (fp, "\\\n");
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
write_enum (FILE *fp, int i)
{
  int j;

  if (i == 0)
    printf ("  (Each enum contains up to %d values)\n", num_enumerators);
  fprintf (fp, "enum");
  if (enums[i].name)
    fprintf (fp, " %s", enums[i].name);
  fprintf (fp, " {");
  for (j = 0; j < enums[i].num_enumerators; ++j)
    {
      if (j > 0)
	fprintf (fp, ",");
      fprintf (fp, "\n  %s", enums[i].enumerators[j].name);
    }
  fprintf (fp, "\n};\n\n");
}

/* Write out the definition of a structure. */

void
write_struct (FILE *fp, int i)
{
  int j;

  if (i == 0)
    printf ("  (Each struct contains %d fields)\n", num_fields);
  fprintf (fp, "struct %s {\n", structs[i].name);
  for (j = 0; j < structs[i].numfields; ++j)
    {
      fprintf (fp, "  %s %s;\n",
	       name_from_type (structs[i].fields[j].type),
	       structs[i].fields[j].name);
    }
  fprintf (fp, "};\n\n");
}

void
write_function_decl (FILE *fp, int n)
{
  int i;

  fprintf (fp, "int %s (", functions[n].name);
  if (language != knr)
    {
      for (i = 0; i < functions[n].numargs; ++i)
	{
	  fprintf (fp, "int %s", functions[n].args[i]);
	  if (i + 1 < functions[n].numargs)
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
      fprintf (fp, "%s", functions[n].args[i]);
      if (i + 1 < functions[n].numargs)
	fprintf (fp, ", ");
    }
  fprintf(fp, ")\n");
  if (language == knr)
    {
      for (i = 0; i < functions[n].numargs; ++i)
	{
	  fprintf (fp, "int %s;\n", functions[n].args[i]);
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
    case 8:
      n = xrandom (num_macros);
      fprintf(fp, "%s(", macros[n].name);
      for (j = 0; j < macros[n].numargs; ++j)
	{
	  if (j > 0)
	    fprintf (fp, ", ");
	  write_expression(fp, depth + 1, max_depth - 1);
	}
      fprintf(fp, ")");
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
      fprintf (fp, "\n");
      fprintf (fp, "\t$(CC) -o %s.out", file_base_name);
      for (i = 0; i < num_files; ++i)
	fprintf (fp, " %s%d.o", file_base_name, i);
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
