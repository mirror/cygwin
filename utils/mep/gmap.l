%{
#include "mepcfgtool.h"
#include "parse.gmap.h"
#include "string.h"
#include "ctype.h"
#include <stdlib.h>

extern char *gmapfilename;

static unsigned long
num (char *in, int base)
{
 char *tmp, *p;
 unsigned long res;
 tmp = strdup (in);
 if (! tmp)
 {
  fprintf (stderr, "%s:%d strdup failed (fatal)\n", 
		   gmapfilename, gmaplineno);
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

%}

%option noyywrap
%option yylineno
%option case-insensitive

WS [ \t\r\n]
EOL  [\n] 
NEOL [^\n]
COM  "//"

HEX [0-9a-fA-F_]
OCT [0-7_]
DEC [0-9_]
NZ [1-9]
PUNCT [\;\:\(\)]
IDENT [a-zA-Z][a-zA-Z0-9_]*

%%

{WS}*                ;
{COM}{NEOL}*{EOL}    ;

0x{HEX}+   { gmaplval.num = num (gmaptext, 16); return NUM; } 
0{OCT}*    { gmaplval.num = num (gmaptext, 8);  return NUM; } 
{NZ}{DEC}* { gmaplval.num = num (gmaptext, 10); return NUM; } 

{PUNCT}    { return gmaptext[0]; }
{IDENT}   { gmaplval.str = strdup (gmaptext); return STR; }

.          { printf( "%s:%d: bad token %s\n", gmapfilename, gmaplineno, gmaptext ); }

%%

