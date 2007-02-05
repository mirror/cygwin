#include "mepcfgtool.h"

#define trace 0

static Node *new_config;

static void
clear_counted (Node *n)
{
  n->counted = 0;
  if (n->next)
    clear_counted (n->next);
  if (n->sub)
    clear_counted (n->sub);
}

typedef void (*compare_func)(Node *, Node *);

static int
same_ids (const char *a, const char *b)
{
  if (a == 0 && b == 0)
    return 1;
  if (a == 0 || b == 0)
    return 0;
  return (strcmp (a, b) == 0);
}

static void
unmatched (Node *n, const char *subname)
{
  /* Use the node for the new config for the error since it contains the
     last line number of the file.  */
  if (n->val)
    errorn (new_config, "removing %s '%s' is not allowed", subname, n->val);
  else
    errorn (new_config, "removing %s is not allowed", subname);
  n->counted = 1;
}

static void
added (Node *n, const char *subname)
{
  errorn (n, "adding %s is not allowed", subname);
  n->counted = 1;
}

static void
match_subs (Node *oc, Node *nc, const char *subname, compare_func cfun)
{
  Node *o, *n;
  if (trace)
    fprintf(stderr, "in match_subs %s %s: match %s\n", oc->id, nc->id, subname);

  for (n=nc->sub; n; n=n->next)
    if (!n->counted
	&& same_ids (subname, n->id))
      {
	if (trace)
	  fprintf(stderr, "looking at %s [%s]\n", n->id, n->val);
	for (o=oc->sub; o; o=o->next)
	  if (!o->counted
	      && same_ids (o->id, subname))
	    {
	      if (trace)
		fprintf(stderr, "\tcomparing against %s [%s]\n", o->id, o->val);
	      if (n->type == o->type
		  && (n->type != N_SUB || same_ids (n->val, o->val)))
		{
		  if (trace)
		    fprintf(stderr, "\t\tmatch!\n");
		  n->counted = 1;
		  o->counted = 1;
		  cfun (o, n);
		}
	    }
	if (!n->counted)
	  added (n, subname);
      }
  for (o=oc->sub; o; o=o->next)
    if (!o->counted && same_ids (o->id, subname))
      unmatched (o, subname);
}

static void
no_compare (Node *oc, Node *nc)
{
}

static void
strict_compare (Node *oc, Node *nc)
{
  Node *n;
  if (oc->type != nc->type)
    {
      errorn (nc, "%s is a different type", nc->id);
      return;
    }
  switch (oc->type)
    {
    case N_NUM:
      if (oc->ival != nc->ival)
	{
	  errorn (nc, "Value of %s changed", nc->id);
	  return;
	}
      break;
    case N_WORD:
    case N_QSTR:
      if (strcmp (oc->val, nc->val) != 0)
	{
	  errorn (nc, "Value of %s changed", nc->id);
	  return;
	}
      break;
    }
  for (n=oc->sub; n; n=n->next)
    if (!n->counted)
      match_subs (oc, nc, n->id, strict_compare);

  for (n=oc->sub; n; n=n->next)
    if (!n->counted)
      unmatched (n, n->id);
}

void
me_module_compare (Node *oc, Node *nc)
{
  match_subs (oc, nc, "HW_ENGINE", strict_compare);
  match_subs (oc, nc, "DSP", strict_compare);
  match_subs (oc, nc, "UCI", strict_compare);
  match_subs (oc, nc, "COP", strict_compare);
}

void
compare_configs (Node *oc, Node *nc)
{
  if (trace)
    fprintf(stderr, "in compare_configs\n");
  clear_counted (oc);
  clear_counted (nc);
  new_config = nc;

  /* Must have the same number of ME_MODULEs, and they must have the same name.  */
  match_subs (oc, nc, "MEP_CORE_TYPE", strict_compare);
  match_subs (oc, nc, "ME_MODULE", me_module_compare);
  match_subs (oc, nc, "PERIPHERAL", strict_compare);
}
