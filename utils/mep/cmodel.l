%{
#include "mepcfgtool.h"
#include "parse.cmodel.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

extern char *cmodelfilename;

static int eof_seen = 0;

static char *
var (char *ch)
{
 char *res;
 res = getenv (ch);
 if (res == NULL)
  fprintf (stderr, "%s:%d unknown variable '%s'\n", 
		   cmodelfilename, cmodellineno, ch);
 return res;
}

static unsigned long
num (char *in, int base)
{
 char *tmp, *p;
 unsigned long res;
 tmp = strdup (in);
 if (! tmp)
 {
  fprintf (stderr, "%s:%d strdup failed (fatal)\n", 
		   cmodelfilename, cmodellineno);
  abort ();   
 }
 for (p = tmp; *in; ++in)
 {
   if (*in == '_')
    continue;
   *p++ = *in;
 }
 *p = 0;
 res = strtoul (tmp, NULL, base);
 free (tmp);
 return res;
}

static char *
extend (char *base, char *ext)
{
  if (! ext) return base;
  base = realloc (base, (base ? strlen(base) : 0) + strlen (ext) + 1);
  assert (base);
  return strcat (base, ext);
}

%}

%option noyywrap
%option yylineno

WS [ \t\r]
EOL  [\n] 
NEOL [^\n]
COM  "//"

DEC [0-9_]
NZ [1-9]
NAME [a-zA-Z_/.][a-zA-Z0-9_/.\-]*
PUNCT [:,=]

%x STRING
Q    \"
NQ   [^\"]

%x NM
V "$"
VC [a-zA-Z0-9_]

%%

{EOL} { return NEWLINE; }
{WS}*                ;
{COM}{NEOL}*    ;

{DEC}{DEC}* { cmodellval.num = num (cmodeltext, 10); return NUM; } 
{PUNCT}    { return cmodeltext[0]; }
class_name { return KWD_CLASS_NAME; }
argc       { return KWD_ARGC; }
lib_file   { return KWD_LIB_FILE; }
base_dir   { return KWD_BASE_DIR; }
include_file        { return KWD_INCLUDE_FILE; }
files      { return KWD_FILES; }
CPPFLAGS   { return KWD_CPPFLAGS; }
end        { return KWD_END; }
int_channel         { return KWD_INT_CHANNEL; }
mapped_region_name  { return KWD_MAPPED_REGION_NAME; }
=>         { return KWD_MAPSTO; }
rtl_model_type      { return KWD_RTL_MODEL_TYPE; }
rtl_module_name     { return KWD_RTL_MODULE_NAME; }
rtl_files  { return KWD_RTL_FILES; }
rtl_base_dir        { return KWD_RTL_BASE_DIR; }
rtl_include_file    { return KWD_RTL_INCLUDE_FILE; }
{NAME}     { cmodellval.str = strdup (cmodeltext); return STR; }
{V}{VC}+   { cmodellval.str = var (cmodeltext + 1); BEGIN (NM); }
<NM>{NAME}   { cmodellval.str = extend ( cmodellval.str, cmodeltext ); BEGIN(INITIAL); return STR; }
{Q}{NQ}+{Q}  { cmodellval.str = strdup (cmodeltext);
               * (char *) strrchr (cmodellval.str, '\"') = '\0'; 
               cmodellval.str ++; 
               return QSTR; }
.          { fprintf (stderr, "%s:%d: bad token %s\n", cmodelfilename, cmodellineno, cmodeltext ); }

<<EOF>> {
  if (! eof_seen) {
     eof_seen = 1;
     return NEWLINE;
   }
 else
  {
    eof_seen = 0;
    yyterminate ();
  }
}

%%

