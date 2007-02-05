%{

#include "mepcfgtool.h"
#include "libiberty.h"
#include <stdio.h>
#include <assert.h>

extern int cmodellineno;
extern CModel *currentcmodel;
extern char *cmodelfilename;

static void
bad (const char *rulename, char *value)
{
  fprintf (stderr, "%s:%d: bad %s value: '%s'\n", 
	   cmodelfilename, cmodellineno, rulename, value);
}
  

static CModel *
new_cmodel ()
{
  CModel *g;

  g = calloc (sizeof (CModel), 1);
  if (! g)
    {
      fprintf (stderr, "%s:%d: calloc failed (fatal)\n", cmodelfilename, cmodellineno);
      abort ();
    }

#if 0 /* not necessary, since calloc was used above.  */
  /* Set some defaults.  */
  g->argc = 0;
  g->class_name = NULL;
  g->type = cmTypeUnknown;

  g->files_size = 0;
  g->num_files = 0;
  g->files = NULL;

  g->ints_size = 0;
  g->num_ints = 0;
  g->int_keys = NULL;
  g->int_channels = NULL;
#endif

  return g;
}


static void
add_cmodel_file (char *file)
{
  if (currentcmodel->num_files >= currentcmodel->files_size)
    {
      currentcmodel->files_size += 32;
      currentcmodel->files = xrealloc (currentcmodel->files,
				       currentcmodel->files_size * sizeof (*currentcmodel->files));
    }
  currentcmodel->files [currentcmodel->num_files ++] = file;
}

static void
add_cmodel_interrupt (char *key, unsigned channel)
{
  if (currentcmodel->num_ints >= currentcmodel->ints_size)
    {
      currentcmodel->ints_size += 32;
      currentcmodel->int_keys = xrealloc (currentcmodel->int_keys,
					  currentcmodel->ints_size * sizeof (*currentcmodel->int_keys));
      currentcmodel->int_channels = xrealloc (currentcmodel->int_channels,
					      currentcmodel->ints_size * sizeof (*currentcmodel->int_channels));
    }
  currentcmodel->int_keys [currentcmodel->num_ints] = key;
  currentcmodel->int_channels [currentcmodel->num_ints] = channel;
  currentcmodel->num_ints ++;
}

static void
add_cmodel_rtl_file (char *file)
{
  /* Just count them for later checking.  */
  ++currentcmodel->num_rtl_files;
}


#define YYDEBUG 1
#define YYERROR_VERBOSE 1

%}

%union {
  unsigned long num;
  char *str;
  CModel *cmodel;
}

%token NEWLINE
%token <str> STR
%token <str> QSTR
%token <num> NUM
%token KWD_CLASS_NAME
%token KWD_ARGC
%token KWD_BASE_DIR
%token KWD_INCLUDE_FILE
%token KWD_LIB_FILE
%token KWD_FILES
%token KWD_CPPFLAGS
%token KWD_END
%token KWD_INT_CHANNEL
%token KWD_MAPPED_REGION_NAME
%token KWD_MAPSTO
%token KWD_RTL_MODEL_TYPE
%token KWD_RTL_MODULE_NAME
%token KWD_RTL_FILES
%token KWD_RTL_BASE_DIR
%token KWD_RTL_INCLUDE_FILE

%type <cmodel> cmodel
%%

cmodel:
{
  CModel * nm = new_cmodel ();
  nm->prev = currentcmodel;
  currentcmodel = nm;
}
specs
{
  $$ = currentcmodel;
}
;

specs:
spec specs
|
;

spec:  
  KWD_CLASS_NAME '=' STR NEWLINE       { currentcmodel->class_name = $3; }
| KWD_ARGC '=' NUM NEWLINE             { currentcmodel->argc = $3; }
| KWD_BASE_DIR '=' STR NEWLINE         { currentcmodel->base_dir = $3; }
| KWD_INCLUDE_FILE '=' STR NEWLINE     { currentcmodel->include_file = $3; }
| KWD_LIB_FILE '=' STR NEWLINE         { currentcmodel->lib_file = $3; }
| KWD_FILES ':' NEWLINE files KWD_END ':' NEWLINE
| KWD_CPPFLAGS '=' QSTR NEWLINE        { currentcmodel->cppflags = $3; }
| KWD_INT_CHANNEL ':' NEWLINE intchannels KWD_END ':' NEWLINE
| KWD_MAPPED_REGION_NAME '=' QSTR NEWLINE { currentcmodel->mapped_region_name = $3; }
| KWD_RTL_MODEL_TYPE '=' STR NEWLINE   { currentcmodel->rtl_model_type = $3; }
| KWD_RTL_MODULE_NAME '=' STR NEWLINE  { currentcmodel->rtl_module_name = $3; }
| KWD_RTL_FILES ':' NEWLINE rtl_files KWD_END ':' NEWLINE
| KWD_RTL_BASE_DIR '=' STR NEWLINE     { currentcmodel->rtl_base_dir = $3; }
| KWD_RTL_INCLUDE_FILE '=' STR NEWLINE { currentcmodel->rtl_include_file = $3; }
| NEWLINE
;

files:
  file list_separator files
| file NEWLINE newlines
;

file:
  newlines STR                 { add_cmodel_file ($2); }
;

list_separator:
  NEWLINE newlines ','
| ','
;

rtl_files:
  rtl_file list_separator rtl_files
| rtl_file NEWLINE newlines
;

rtl_file:
  newlines STR                 { add_cmodel_rtl_file ($2); }
;

intchannels:
  intchannel list_separator intchannels
| intchannel NEWLINE newlines
  ;

intchannel:
  newlines STR KWD_MAPSTO NUM  { add_cmodel_interrupt ($2, $4); }
;

newlines:
NEWLINE newlines
|
;

%%

int
cmodelerror (char *s)
{
  fprintf (stderr, "%s:%d: %s\n", cmodelfilename, cmodellineno, s);
  currentcmodel = 0;
  return 0;
}
