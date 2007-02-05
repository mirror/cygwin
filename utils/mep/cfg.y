%{

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

#include "mepcfgtool.h"

/* Just to be paranoid.  */
#ifndef X_OK
#define X_OK 1
#endif

extern int cfglineno;
extern Node *currentcfg;
extern char *cfgfilename;

static int hide_errors = 0;

Node *
new_node (const char *name, Node *sub)
{
  Node *n;

  n = (Node *) calloc (sizeof (Node), 1);
  n->type = N_NONE;
  n->id = name;
  n->sub = sub;
  n->filename = cfgfilename;
  n->lineno = cfglineno;
  return n;
}

static Node *
intnode (Node *n, int val)
{
  n->type = N_NUM;
  n->ival = val;
  return n;
}

static Node *
strnode (Node *n, char *val)
{
  n->type = N_QSTR;
  n->val = val;
  return n;
}

static Node *
wordnode (Node *n, char *val)
{
  n->type = N_WORD;
  n->val = val;
  return n;
}

static Node *
subnode (Node *n, Node *s, char *name)
{
  n->type = N_SUB;
  n->sub = s;
  n->val = name;
  return n;
}

#define CHAIN(up, one, two) if (one) { one->next = two; up = one; } else { up = two; }

%}


%union {
  unsigned long num;
  char *str;
  Node *node;
}

%token <str> STR WORD
%token <num> NUM

%type <node> nodes node word
%%

file:
  nodes					{ currentcfg->sub = $1; currentcfg->type = N_SUB; }
| error
;

nodes:
  node ';' nodes			{ CHAIN ($$, $1, $3); }
|					{ $$ = 0; }
;

node:
  word '=' STR				{ $$ = strnode ($1, $3); }
| word '=' WORD				{ $$ = wordnode ($1, $3); }
| word '=' NUM				{ $$ = intnode ($1, $3); }
| word '=' '-' NUM			{ error ("%s must not be negative", $1->id); $$ = intnode ($1, $4);}
| word '[' WORD ']' '{' nodes '}'	{ $$ = subnode ($1, $6, $3); }
| word '{' nodes '}'			{ $$ = subnode ($1, $3, 0); }
;

word:
  WORD					{ $$ = new_node ($1, 0); }
;

%%

/* New string must be no longer than old string.  */
static const char *swap_strings[][2] = {
  { " `$' or `error' or ", " " },
  { " `error' or ", " " },
  { " `$' or ", " " },
  { "`'", "\"" },
  { "''", "\"" },
  { "'", "\"" },
  { "`", "\"" },
  { 0, 0 }
};

int
cfgerror (char *s)
{
  int ssi, ol, nl;
  if (strncmp (s, "parse error", 11) == 0)
    {
      s += 11;
      for (ssi=0; swap_strings[ssi][0]; ssi++)
	{
	  char *old = strstr (s, swap_strings[ssi][0]);
	  if (old)
	    {
	      ol = strlen (swap_strings[ssi][0]);
	      nl = strlen (swap_strings[ssi][1]);
	      memcpy (old, swap_strings[ssi][1], nl);
	      strcpy (old+nl, old+ol);
	      ssi --;
	    }
	}
      switch (yychar)
	{
	case 0:
	  error ("Unexpected end-of-file%s", s);
	  break;
	case STR:
	  error ("Quoted string \"%s\" unexpected here%s", yylval.str, s);
	  break;
	case NUM:
	  error ("Value \"%s\" unexpected here%s", hex_pr (yylval.num), s);
	  break;
	default:
	  if (yychar < 255)
	    {
	      error ("\"%c\" unexpected here%s", yychar, s);
	      /* Cause an immediate exit to cfgparse() to avoid
	         multiple errors; bad punctuation tends to cause them.  */
	      if (*s)
		yychar = YYEOF;
	    }
	  else 
	    error ("\"%s\" unexpected here%s", yylval.str, s);
	  break;
	}
    }
  else
    error (s);
}
