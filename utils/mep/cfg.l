%{
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "libiberty.h"
#include "mepcfgtool.h"
#include "parse.cfg.h"

extern char *cfgfilename;

static char *
var (char *ch)
{
 char *res;
 res = getenv (ch);
 if (res == NULL)
 {
   error ("unknown variable \"%s\"", ch);
   return "";
 }
 return res;
}

static char *
extend (char *base, char *ext)
{
  char *rv;
  if (! ext)
    return base;
  if (base == 0)
    {
      base = malloc (strlen (ext) + 1);
      base[0] = 0;
    }
  else
    base = realloc (base, strlen (base) + strlen (ext) + 1);
  if (! base)
    {
      fprintf (stderr, "%s:%d realloc failed (fatal)\n", 
	       cfgfilename, cfglineno);
      abort ();
    }
  return strcat (base, ext);
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
		   cfgfilename, cfglineno);
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

static int in_brackets = 0;

static void
note_punct (int punct)
{
  in_brackets += punct == '[';
  in_brackets -= punct == ']';
  if (in_brackets < 0)
    in_brackets = 0;
}

%}

%option noyywrap
%option yylineno
%option case-insensitive

%x STRING

RN [\r\n]

Q  \"
NQV [^\"\$\\\n\r]
QD \\[\"\$]
V "$"
VC [a-zA-Z0-9_]

INIT [a-zA-Z_\.()]
ID [a-zA-Z0-9_\.()/:,-]
SP [ \t\r\n]
COM "//"

HEX [0-9a-fA-F_]
OCT [0-7_]
DEC [0-9_]
NZ [1-9]

PUNCT [\{\}\[\]\=\;]

%%

{Q}              { cfglval.str = xstrdup (""); BEGIN(STRING);     }
<STRING>{RN}	 { error ("Unterminated string");
		   BEGIN(INITIAL); return STR; }
<STRING>{V}{VC}+ { cfglval.str = extend ( cfglval.str, var (cfgtext + 1) ); }
<STRING>{NQV}+   { cfglval.str = extend ( cfglval.str, cfgtext );           }
<STRING>{QD}     { cfglval.str = extend ( cfglval.str, cfgtext+1 );         }
<STRING>{Q}      { BEGIN(INITIAL); return STR;                           }

{V}{VC}+         { cfglval.str = var (cfgtext + 1);   return WORD;  }
{INIT}{ID}*      { cfglval.str = strdup (cfgtext);    return WORD;  }
{SP}*            ;
{COM}.*	         ;

0x{HEX}+         { cfglval.num = num (cfgtext, 16);   return NUM; } 
0{OCT}*          { cfglval.num = num (cfgtext, 8);    return NUM; } 
{NZ}{DEC}*       { cfglval.num = num (cfgtext, 10);   return NUM; } 

.                { note_punct (cfgtext[0]); return cfgtext[0]; }

%%

