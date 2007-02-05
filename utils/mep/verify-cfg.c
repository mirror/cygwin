/* Configuration Tool for Toshiba Media Processor
   Copyright (C)  2003, 2004, 2005 Free Software Foundation, Inc.
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
#include <limits.h>
#include <sys/stat.h>
#include <assert.h>

#include "libiberty.h"

#include "mepcfgtool.h"

extern int warn_all;
extern int toshapi;
extern int mep_core_type;
extern int mep_endian_type;

extern Node *currentcfg;
extern unsigned corecount;
extern unsigned isacount;

typedef void (*verify_func)(Node *);

/* ---------------------------------------------------------------------- */

static Node *
chain_new_node (Node *top, const char *name, int type)
{
  Node *p;
  Node *n = new_node (name, 0);
  n->next = 0;
  if (top->sub)
    {
      for (p=top->sub; p->next; p=p->next);
      p->next = n;
    }
  else
    top->sub = n;
  n->up = top;

  n->type = type;

  n->filename = top->filename;
  n->lineno = top->lineno;
  return n;
}

static void
default_node (Node *top, const char *name, const char *id)
{
  Node *n = find_sub (top, name, 0);
  if (n)
    return;
  n = chain_new_node (top, name, N_SUB);
  n->val = id;
}

static void
default_string (Node *top, const char *name, const char *val, int type)
{
  Node *n = find_sub (top, name, 0);
  if (n)
    return;
  n = chain_new_node (top, name, type);
  n->val = val;
}

static void
default_int (Node *top, const char *name, int ival)
{
  Node *n = find_sub (top, name, 0);
  if (n)
    return;
  n = chain_new_node (top, name, N_NUM);
  n->ival = ival;
}

/* ---------------------------------------------------------------------- */

/* Ignore any instances of the named node under TOP by removing them.
   Generate a warning if requested.  */
static int
ignore_node (Node *top, const char *name)
{
  Node *n, *prev;
  prev = NULL;
  for (n=top->sub; n; n=n->next)
    {
      if (strcmp (n->id, name) == 0)
	{
	  if (warn_all)
	    warnn (n, "%s is defined but ignored", name);
	  if (prev)
	    prev->next = n->next;
	  else
	    top->sub = n->next;
	  continue;
	}
      prev = n;
    }
}

/* Generate a warning for any instances of the named node under TOP, but don't
   remove them, as they are still processed.  */
static int
unsupported_node (Node *top, const char *name)
{
  Node *n;

  if (! warn_all)
    return; // No warnings to generate

  for (n=top->sub; n; n=n->next)
    {
      if (strcmp (n->id, name) == 0)
	warnn (n, "%s is unsupported", name);
    }
}

/* ---------------------------------------------------------------------- */


static int
check_node (Node *top, const char *name, int min, int max, verify_func vf)
{
  Node *n;
  int count = 0;
  for (n=top->sub; n; n=n->next)
    if (strcmp (n->id, name) == 0)
      {
	count ++;
	if (vf)
	  vf (n);
	n->counted = 1;
      }

  if (max == 0)
    return count;
  if (count >= min && count <= max)
    return count;

  if (min == max)
    errorn (top, "%s expects exactly %d of %s", top->id, min, name);
  else if (count < min)
    errorn (top, "%s expects at least %d of %s", top->id, min, name);
  else
    errorn (top, "%s expects at most %d of %s", top->id, max, name);
  return count;
}

static int
check_only_one (Node *top, const char *name)
{
  return check_node (top, name, 0, 1, 0) <= 1;
}

static void
check_for_file (Node *n)
{
  struct stat statbuf;
  unsigned int i;

  if (stat (n->val, & statbuf) < 0)
    {
      const char *filename;
      filename = resolve_local_filename (n->val);
      if (stat (filename, & statbuf) < 0)
	errorn (n, "%s: No such file or directory.\n", n->val);
      return;
    }
  
}

static const char *
ntype (int type)
{
  switch (type)
    {
    case N_WORD: return "a word";
    case N_QSTR: return "a string";
    case N_NUM:  return "a number";
    case N_SUB:  return "a sub-level";
    default:     return "an unknown type";
    }
}

static int
wrong_type (Node *top, int type)
{
  if (!top)
    return 0;
  if (top->type & type)
    return 0;
  if (type == N_QSTR && top->type == N_WORD)
    errorn (top, "%s must be quoted", top->id);
  else if (type == N_WORD && top->type == N_QSTR)
    errorn (top, "%s must not be quoted", top->id);
  else
    errorn (top, "%s must be %s, not %s", top->id, ntype (type), ntype (top->type));
  return 1;
}

static int
check_subnode (Node *top, const char *name, int min, int max, verify_func vf)
{
  Node *n;
  check_node (top, name, min, max, vf);
  for (n=top->sub; n; n=n->next)
    if (strcmp (n->id, name) == 0)
      wrong_type (n, N_SUB);
}

static void
check_string_nonempty (Node *top, const char *name)
{
  Node *t = find_sub (top, name, NULL);
  if (!t)
    return;

  if (wrong_type (t, N_QSTR))
    return;

  check_only_one (top, name);

  if (strlen (t->val) == 0)
    errorn (t ? t : top, "%s must be present and not empty for %s",
	    name, top->id);
}

/* If no options are given, any string is allowed.  */
static Node *
check_string (Node *top, int check_case, const char *name, ...)
{
  va_list ap;
  Node *t;
  int opt_count = 0;

  check_only_one (top, name);

  t = find_sub (top, name, NULL);
  if (!t)
    return NULL;

  va_start (ap, name);
  while (1)
    {
      int compare;
      char *s = va_arg (ap, char *);
      if (!s)
	break;
      if (opt_count == 0)
	if (wrong_type (t, N_WORD))
	  return NULL;

      compare = check_case ? strcmp (t->val, s) : strcasecmp (t->val, s);
      if (compare == 0)
	{
	  va_end (ap);
	  return t;
	}
      opt_count ++;
    }
  va_end (ap);

  if (opt_count)
    {
      errorn (t, "%s has unexpected value \"%s\"", name, t->val);
      return NULL;
    }

  if (wrong_type (t, N_QSTR))
    return NULL;

  return t;
}

/* If NR_OPTIONS is 0, any value is accepted.  */
static void
check_int_list (Node *top, const char *name, int nr_options, ...)
{
  Node *t;
  int i;
  va_list ap;
  va_start (ap, nr_options);

  check_only_one (top, name);

  t = find_sub (top, name, NULL);
  if (!t)
    return;

  if (wrong_type (t, N_NUM))
    return;

  if (nr_options == 0)
    return;
	  
  for (i = 0; i < nr_options; i++)
    {
      int val = va_arg (ap, int);
      if (t->ival == val)
	break;
    }
  va_end (ap);

  if (i == nr_options)
    errorn (t, "invalid %s (%s) for %s", name, hex_pr (t->ival), top->id);
}

static void
check_int_range (Node *top, const char *name, int min, int max)
{
  Node *t;
  int i;

  check_only_one (top, name);

  t = find_sub (top, name, NULL);
  if (!t)
    return;

  if (wrong_type (t, N_NUM))
    return;

  if (t->ival < min)
    errorn (t, "%s must be at least %s", name, hex_pr (min));
  if (t->ival > max)
    errorn (t, "%s must be no more than %s", name, hex_pr (max));
}

static void
check_arcadia_isa (Node *top)
{
  Node *a, *i, *s;

  a = check_string (top, 0, "ACDB", 0);
  i = check_string (top, 0, "CGEN_DEFINE", 0);
  s = check_string (top, 0, "SIM", 0);

  if (a)
    {
      ignore_node (top, "CGEN_DEFINE");
      ignore_node (top, "SIM");
      if (warn_all && strcmp (top->id, "COP") == 0)
	warnn (a, "ACDB is used but not recommended, use IP");
      if (! a->val[0])
	errorn (top, "ACDB must not be empty for %s", top->id);
    }
  else
    {
      if (warn_all)
	{
	  const char *recommended = strcmp (top->id, "COP") == 0 ? "IP" : "ACDB";
	  if (i)
	    warnn (i, "CGEN_DEFINE is used but not recommended, use %s", recommended);
	  if (s)
	    warnn (s, "SIM is used but not recommended, use %s", recommended);
	}
      if (i)
	{
	  if (! i->val[0])
	    errorn (top, "CGEN_DEFINE must not be empty for %s", top->id);
	  check_for_file (i);
	}
    }
}

static Node **named_nodes = 0;
static int n_named_nodes = 0;

static void
check_name (Node *top)
{
  int i;
  if (!top->val)
    {
      errorn (top, "%s requires a name", top->id);
      return;
    }

  for (i=0; i<n_named_nodes; i++)
    if (strcmp (top->val, named_nodes[i]->val) == 0)
      {
	Node *o = named_nodes[i];
	errorn (top, "Instance name \"%s\" also used at %s:%d",
		top->val, o->filename, o->lineno);
	return;
      }

  named_nodes = (Node **) xrealloc (named_nodes, (n_named_nodes+1) * sizeof (Node *));
  named_nodes[n_named_nodes] = top;
  n_named_nodes ++;
}

static void
check_opt_name (Node *top)
{
  if (top->val)
    check_name (top);
}

static void
check_no_name (Node *top)
{
  if (top->val)
    errorn (top, "%s does not allow a name", top->id);
}

/* Anything not checked for above is caught here.  */
static void
check_unexpected (Node *top)
{
  Node *n, *prev;
  for (prev = NULL, n=top->sub; n; prev = n, n = n->next)
    if (! n->counted)
      {
	errorn (n, "\"%s\" unexpected here", n->id);
	/* Remove the useless node */
	if (prev)
	  prev->next = n->next;
	else
	  top->sub = n->next;
      }
}

Node *core_ids_in_use[MAX_CORE_ID + 1];
int next_core_id = 0;

static void
check_core_id (Node *core, int check_count)
{
  Node *id, *i2;

  if (check_count)
    if (!check_only_one (core, "ID"))
      return;

  id = find_sub (core, "ID", 0);
  if (! id)
    return;

  if (wrong_type (id, N_NUM))
    return;

  if (id->ival < 0 || id->ival > MAX_CORE_ID)
    {
      errorn (core, "core ID must be 0..%d (was %d)",
	      MAX_CORE_ID, id->ival);
      return;
    }

  i2 = core_ids_in_use[id->ival];
  if (i2 != 0)
    {
      errorn (id, "core ID %d already used at %s:%d",
	      id->ival, i2->filename, i2->lineno);
      return;
    }

  core_ids_in_use[id->ival] = id;
  if (next_core_id <= id->ival)
    next_core_id = id->ival + 1;
}

#define PERIPHERAL_BUS	1
#define LOCAL_BUS	2
#define CONTROL_BUS	3

struct {
  int start;
  int end;
  char *region;
} bus_exclusions[] = {
  { 0x00200000, 0x002fffff, "IMEM/DMEM" },
  { 0x00300000, 0x003fffff, "Cache Test Area" },
  { 0x00600000, 0x006fffff, "LOCAL_BUS" },
  { 0x00700000, 0x007fffff, "Debugger Area" },
  { 0x00800000, 0x7FFfffff, "Cachable Area" },
  { 0xA0000000, 0xAFFfffff, "Global Address Area" },
  { 0xC0000000, 0xFFFfffff, "Cachable Area" },
  { 0, 0, 0 }
};

typedef struct {
  Node *node;
  int start;
  int end;
  int bus;
} addr_s;

static void
check_bus_addr (Node *node, int addr, int len, int which_bus)
{
  int i;
  static addr_s *addrs = 0;
  static int n_addrs = 0;
  int last_addr;

  if (node == 0)
    {
      n_addrs = 0;
      return;
    }

  last_addr = addr + len - 1;

  if (which_bus == PERIPHERAL_BUS)
    {
      int i;
      for (i=0; bus_exclusions[i].region; i++)
	if (addr <= bus_exclusions[i].end
	    && last_addr >= bus_exclusions[i].start)
	  {
	    errorn (node, "Bus address 0x%x conflicts with %s at 0x%x",
		    addr, bus_exclusions[i].region, bus_exclusions[i].start);
	  }
    }
  else if (which_bus == LOCAL_BUS)
    {
      assert (addr >= 0x600000); /* already checked */
      if (last_addr > 0x6fffff)
	errorn (node, "Bus address 0x%x + 0x%x is outside the range 0x600000-0x6fffff",
		addr, len);
    }

  for (i=0; i<n_addrs; i++)
    if (addrs[i].end >= addr
	&& addrs[i].start <= last_addr
	&& addrs[i].bus == which_bus)
      {
	errorn (node, "Bus address 0x%x conflicts with %s[%s] at %s:%d",
		addr, addrs[i].node->id, addrs[i].node->val,
		addrs[i].node->filename, addrs[i].node->lineno);
      }

  addrs = (addr_s *) xrealloc (addrs, (n_addrs+1) * sizeof (addr_s));
  addrs[n_addrs].node = node;
  addrs[n_addrs].start = addr;
  addrs[n_addrs].end = last_addr;
  addrs[n_addrs].bus = which_bus;
  n_addrs ++;
}

static int
has_me_module (Node *n, const char *str)
{
  for (n=n->sub; n; n=n->next)
    if (strcasecmp (n->id, "ME_MODULE") == 0
	&& n->val && strcmp (n->val, str) == 0)
      return 1;
  return 0;
}

static int
has_local_mem (Node *n, char *str)
{
  for (n=n->sub; n; n=n->next)
    if (strcasecmp (n->id, "LOCAL_MEM") == 0
	&& n->val && strcmp (n->val, str) == 0)
      return 1;
  return 0;
}

static void
check_bus_addresses (Node *top, Node *lbus_if)
{
  Node *node, *a, *s;

  if (lbus_if)
    {
      node = find_sub (top, "LOCAL_MEM_LIST", 0);
      if (node)
	errorn (node, "LOCAL_MEM_LIST is not allowed when LBUS_IF is ON");

      a = find_typed_sub (top, N_NUM, "LBUS_ADDRESS", 0);
      if (! a)
	errorn (lbus_if, "LBUS_ADDRESS must be specified when LBUS_IF is ON");

      s = find_typed_sub (top, N_NUM, "LBUS_SIZE", 0);
      if (! s)
	errorn (lbus_if, "LBUS_SIZE must be specified when LBUS_IF is ON");

      if (a && s)
	check_bus_addr (top, a->ival, s->ival, LOCAL_BUS);
    }
  else
    {
      node = find_sub (top, "LBUS_ADDRESS", 0);
      if (node)
	errorn (node, "LBUS_ADDRESS is not allowed when LBUS_IF is OFF");
      node = find_sub (top, "LBUS_SIZE", 0);
      if (node)
	errorn (node, "LBUS_SIZE is not allowed when LBUS_IF is OFF");

      node = find_typed_sub (top, N_QSTR, "LOCAL_MEM_LIST", 0);
      if (node)
	{
	  char *lml = xstrdup (node->val), *ml, *s;
	  s = lml;
	  while ((ml = strtok (s, ", ")) != 0)
	    {
	      s = 0;
	      if (! has_local_mem (top->up, ml))
		errorn (node, "No LOCAL_MEM [%s] found", ml);
	    }
	  free (lml);
	}
    }
}

static void
check_mep_core_type (Node *top)
{
  top = find_sub (top, "MEP_CORE_TYPE", 0);
  if (!top)
    return;

  if (strcasecmp (top->val, "c2") == 0)
    mep_core_type = MEP_CORE_C2;
  else if (strcasecmp (top->val, "c3") == 0)
    mep_core_type = MEP_CORE_C3;
  else if (strcasecmp (top->val, "c4") == 0)
    mep_core_type = MEP_CORE_C4;
  else if (strcasecmp (top->val, "h1") == 0)
    mep_core_type = MEP_CORE_H1;
  else
    {
      errorn (top, "%s has unexpected value \"%s\"", top->id, top->val);
      mep_core_type = MEP_CORE_C2;
    }
}

static void
check_mep_endian (Node *top)
{
  mep_endian_type = MEP_ENDIAN_BIG; /* default */

  /* Only allowed for MEP_CORE_TYPE=c4 */
  if (mep_core_type != MEP_CORE_C4)
    return;

  check_string (top, 0, "LITTLE_ENDIAN", "YES", "NO", 0);

  top = find_sub (top, "LITTLE_ENDIAN", 0);
  if (! top)
    return;

  assert (top->val);
  if (strcasecmp (top->val, "YES") == 0)
    mep_endian_type = MEP_ENDIAN_LITTLE;
}

static int
get_biu_width (Node *top)
{
  Node *bw = find_typed_sub (top, N_NUM, "ME_ENGINE", "BIU", "DATA_WIDTH", 0);
  if (bw && (bw->ival == 32 || bw->ival == 64))
    return bw->ival;
  return 64;
}

static int
get_dmem_size (Node *top)
{
  Node *n = find_typed_sub (top, N_NUM, "ME_ENGINE", "DMEM", "SIZE", 0);
  if (n)
    return n->ival;
  return 0;
}

/* ---------------------------------------------------------------------- */

static void
verify_mm_int (Node *top)
{
  default_int (top, "ADDRESS", 0x0041c000);
  default_int (top, "REG_NUM", 4);

  check_no_name (top);
  check_int_list (top, "ADDRESS", 0);
  check_int_list (top, "REG_NUM", 0);
  check_unexpected (top);
}

static void
verify_peripheral (Node *top)
{
  Node *a, *s, *r;
  int addr, size;

  default_int (top, "MAPPED_ADDRESS", 0x80000000);
  default_int (top, "MAPPED_SIZE", 256);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "BUS_MASTER", "NO", N_WORD);
  default_int (top, "NUMBER", 0);
  default_int (top, "DATA_WIDTH", 32);
#endif
  default_string (top, "ALL_MEMORY_MAP", "OFF", N_WORD);

  check_name (top);
  check_string (top, 0, "SIM", 0);
  check_int_list (top, "MAPPED_ADDRESS", 0);
  check_int_list (top, "MAPPED_SIZE", 0);
  check_string (top, 1, "BUS_MASTER", "YES", "NO", 0);
  check_int_list (top, "NUMBER", 0);
  check_int_list (top, "DATA_WIDTH", 0);
  check_string (top, 0, "RELATED_MM", 0);
  check_string (top, 0, "CMODEL_ARGS", 0);
  check_string (top, 1, "ALL_MEMORY_MAP", "ON", "OFF", 0);
  check_unexpected (top);

  ignore_node (top, "BUS_MASTER");
  ignore_node (top, "NUMBER");
  ignore_node (top, "DATA_WIDTH");

  a = find_typed_sub (top, N_NUM, "MAPPED_ADDRESS", 0);
  s = find_typed_sub (top, N_NUM, "MAPPED_SIZE", 0);
  if (a && s)
    check_bus_addr (top, a->ival, s->ival, PERIPHERAL_BUS);

  /* All_MEMORY_MAP overrides RELATED_MM.  */
  a = find_typed_sub (top, N_WORD, "ALL_MEMORY_MAP", 0);
  if (! a || ! a->val || strcmp (a->val, "ON") != 0)
    {
      r = find_typed_sub (top, N_QSTR, "RELATED_MM", 0);
      if (r && r->val[0] && !has_me_module (top->up, r->val))
	errorn (top, "No related ME_MODULE[%s]", r->val);
    }
  else
    ignore_node (top, "RELATED_MM");
}

static void
verify_main_bus_if (Node *top)
{
  default_int (top, "DATA_WIDTH", get_biu_width(top->up));
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "ADDRESS_IF", "OFF", N_WORD);
#endif

  check_opt_name (top);
  check_string (top, 0, "IP", 0);
  check_int_list (top, "DATA_WIDTH", 2, 32, 64);
  check_int_list (top, "SLAVE_ACCESS_ADDRESS", 0);
  check_string (top, 1, "ADDRESS_IF", "ON", "OFF", 0);
  check_unexpected (top);

  ignore_node (top, "IP");
  ignore_node (top, "SLAVE_ACCESS_ADDRESS");
  ignore_node (top, "ADDRESS_IF");
}

static void
verify_dmac (Node *top)
{
  default_int (top, "CHANNEL_BITW", 1);
  default_int (top, "DATA_WIDTH", get_biu_width (top->up));
  default_string (top, "RECTANGLE", "OFF", N_WORD);

  check_opt_name (top);
  check_int_range (top, "CHANNEL_BITW", 1, 6);
  check_int_list (top, "DATA_WIDTH", 2, 32, 64);
  check_string (top, 1, "RECTANGLE", "ON", "OFF", 0);
  check_string (top, 0, "SIM", 0);
  check_string (top, 0, "CMODEL_ARGS", 0);
  check_string (top, 0, "HW_REQ0", 0);
  check_string (top, 0, "HW_REQ1", 0);
  check_string (top, 0, "HW_REQ2", 0);
  check_string (top, 0, "HW_REQ3", 0);
  check_string (top, 0, "HW_REQ4", 0);
  check_string (top, 0, "HW_REQ5", 0);
  check_unexpected (top);

  ignore_node (top, "SIM");
}

static void
verify_timer (Node *top)
{
  default_int (top, "CHANNEL_BITW", 1);

  check_no_name (top);
  check_int_range (top, "CHANNEL_BITW", 1, 4);
  check_unexpected (top);
}

static void
verify_dsu (Node *top)
{
  check_no_name (top);
#if 0  /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "PC_TRACE", "OFF", N_WORD);
  default_string (top, "DATA_TRACE", "OFF", N_WORD);
#endif

  if (mep_core_type == MEP_CORE_C4 || mep_core_type == MEP_CORE_H1)
    check_string (top, 1, "PC_TRACE", "ON", "OFF", 0);
  else
    check_string (top, 1, "PC_TRACE", "OFF", 0);

  if (mep_core_type == MEP_CORE_H1)
    {
      Node *data_trace;
      check_string (top, 1, "DATA_TRACE", "ON", "OFF", 0);

      data_trace = find_typed_sub (top, N_WORD, "DATA_TRACE", 0);
      if (data_trace && strcmp (data_trace->val, "ON") == 0)
	{
	  Node *pc_trace = find_typed_sub (top, N_WORD, "PC_TRACE", 0);
	  if (! pc_trace || strcmp (pc_trace->val, "ON") != 0)
	    errorn (top, "DATA_TRACE must not be ON unless PC_TRACE is ON");
	}
    }
  else
    check_string (top, 1, "DATA_TRACE", "OFF", 0);

  check_unexpected (top);

  ignore_node (top, "PC_TRACE");
  ignore_node (top, "DATA_TRACE");
}

static void
verify_intc (Node *top)
{
  default_int (top, "CHANNEL_BITW", 8);
  default_int (top, "LEVEL", 15);

  check_opt_name (top);
  check_int_range (top, "CHANNEL_BITW", 1, 32);
  check_int_list (top, "LEVEL", 4, 1, 3, 7, 15);
  check_unexpected (top);
}

static void
verify_irq (Node *top)
{
  int i;
  char tmp[6];

  check_no_name (top);
  for (i=0; i<32; i++)
    {
      sprintf (tmp, "INT%d", i);
      check_string (top, 0, tmp, 0);
    }
  check_unexpected (top);
}

static void
verify_local_bus (Node *top)
{
  default_int (top, "DATA_WIDTH", get_biu_width (top->up));

  check_no_name (top);
  check_int_list (top, "DATA_WIDTH", 2, 32, 64);
  check_string (top, 0, "SIM", 0);
  check_unexpected (top);
}

static void
verify_global_bus (Node *top)
{
  check_string (top, 0, "IP", 0);
  check_string (top, 0, "SIM", 0);
  check_unexpected (top);
}

static void
clear_cop (Node *top)
{
  int tmp;
  ignore_node (top, "VLIW_TYPE");
  ignore_node (top, "VLIW_BITW");
  ignore_node (top, "DATA_BUS_WIDTH");
  ignore_node (top, "CBUS_IF");
  ignore_node (top, "SIM");
  ignore_node (top, "ACDB");
  ignore_node (top, "CGEN_DEFINE");
  tmp = warn_all;
  warn_all = 0;
  ignore_node (top, "IP");
  warn_all = tmp;
}

static void
process_cop_ip (Node *top, Node *ip)
{
  /* See which coprocessor was specified. The names are case sensitive.  */
  if (strcmp (ip->val, "AVC") == 0)
    {
      clear_cop (top);
      default_string (top, "VLIW_TYPE", "YES", N_WORD);
      default_int (top, "VLIW_BITW", 32);
      default_int (top, "DATA_BUS_WIDTH", 32);
      default_string (top, "CBUS_IF", "OFF", N_WORD);
      /* Restore and check the IP specification.  */
      default_string (top, "IP", "AVC", N_QSTR);
      check_string (top, 0, "IP", 0);
   }
  else if (strcmp (ip->val, "AVC2") == 0)
    {
      clear_cop (top);
      default_string (top, "VLIW_TYPE", "YES", N_WORD);
      default_int (top, "VLIW_BITW", 32);
      default_int (top, "DATA_BUS_WIDTH", 32);
      default_string (top, "CBUS_IF", "OFF", N_WORD);
      /* Restore and check the IP specification.  */
      default_string (top, "IP", "AVC2", N_QSTR);
      check_string (top, 0, "IP", 0);
    }
  else if (strcmp (ip->val, "FMAX") == 0)
    {
      clear_cop (top);
      default_string (top, "VLIW_TYPE", "NO", N_WORD);
      default_int (top, "VLIW_BITW", 32);
      default_int (top, "DATA_BUS_WIDTH", 32);
      default_string (top, "CBUS_IF", "OFF", N_WORD);
      /* Restore and check the IP specification.  */
      default_string (top, "IP", "FMAX", N_QSTR);
      check_string (top, 0, "IP", 0);
   }
  else
    errorn (top, "IP has unexpected value \"%s\"", ip->val);
}

static void
verify_cop (Node *top)
{
  Node *ip;

  check_name (top);
  ip = check_string (top, 0, "IP", 0);

  /* If IP is specified, then ignore any settings the user may have made and
     make new settings based on the value specified for IP.  */
  if (ip)
    process_cop_ip (top, ip);
  else
    {
      /* Only need these if IP not specified.  */
      default_string (top, "VLIW_TYPE", "YES", N_WORD);
      default_int (top, "VLIW_BITW", 32);
      default_int (top, "DATA_BUS_WIDTH", 32);
      default_string (top, "CBUS_IF", "OFF", N_WORD);
    }

  /* Check all entries for correctness, even if they will be ignored.  */
  check_string (top, 1, "VLIW_TYPE", "YES", "NO", 0);
  check_int_list (top, "VLIW_BITW", 2, 32, 64);
  check_int_list (top, "DATA_BUS_WIDTH", 2, 32, 64);
  check_string (top, 1, "CBUS_IF", "ON", "OFF", 0);
  check_arcadia_isa (top);
  check_unexpected (top);
}

static void
verify_uci (Node *top)
{
  check_name (top);
  check_arcadia_isa (top);
  check_string (top, 0, "CMODEL_ARGS", 0);
  check_unexpected (top);
}

static void
verify_dsp (Node *top)
{
  Node *n;
  Node *lbus_if = 0;
  int biu_width;

  default_string (top, "CBUS_IF", "OFF", N_WORD);
  default_string (top, "LBUS_IF", "OFF", N_WORD);

  lbus_if = find_typed_sub (top, N_WORD, "LBUS_IF", 0);
  if (lbus_if)
    if (strcmp (lbus_if->val, "ON") == 0)
      default_int (top, "LBUS_SIZE", 0x10000);
    else
      lbus_if = 0;

  check_name (top);
  check_string (top, 1, "CBUS_IF", "ON", "OFF", 0);
  check_string (top, 1, "LBUS_IF", "ON", "OFF", 0);
  check_int_list (top, "LBUS_ADDRESS", 16,
		  0x600000, 0x610000, 0x620000, 0x630000, 0x640000,
		  0x650000, 0x660000, 0x670000, 0x680000, 0x690000,
		  0x6A0000, 0x6B0000, 0x6C0000, 0x6D0000, 0x6E0000,
		  0x6F0000);
  check_int_list (top, "LBUS_SIZE", 0);
  check_string (top, 0, "LOCAL_MEM_LIST", 0);
  check_string (top, 0, "CMODEL_ARGS", 0);
  check_arcadia_isa (top);

  /* If no dmem or the core is c2, ignore any specified value for
     DMEM_IF_WIDTH and then silently set it to match the BIU width.  */
  biu_width = get_biu_width (top->up);
  if (mep_core_type == MEP_CORE_C2 || get_dmem_size (top->up) == 0)
    {
      ignore_node (top, "DMEM_IF_WIDTH");
      default_int (top, "DMEM_IF_WIDTH", biu_width);
      check_int_list (top, "DMEM_IF_WIDTH", 1, biu_width);
    }
  /* Otherwise, if the BIU width is 64, force DMEM_IF_WIDTH to match.  */
  else if (biu_width == 64)
    {
      default_int (top, "DMEM_IF_WIDTH", biu_width);
      n = find_typed_sub (top, N_NUM, "DMEM_IF_WIDTH", 0);
      if (n && n->ival != biu_width)
	{
	  warnn (n, "DMEM_IF_WIDTH forced to %d to match BIU width", biu_width);
	  n->ival = biu_width;
	}
      check_int_list (top, "DMEM_IF_WIDTH", 1, biu_width);
    }
  /* Otherwise, the values 32 and 64 are available with a default of 32.  */
  else
    {
      default_int (top, "DMEM_IF_WIDTH", 32);
      check_int_list (top, "DMEM_IF_WIDTH", 2, 32, 64);
    }

  check_unexpected (top);
  check_bus_addresses (top, lbus_if);
}

static void
verify_local_mem (Node *top)
{
  Node *addr, *size;

  addr = find_typed_sub (top, N_NUM, "ADDRESS", 0);
  if (!addr)
    errorn (top, "ADDRESS required here");
  size = find_typed_sub (top, N_NUM, "SIZE", 0);
  if (!size)
    errorn (top, "SIZE required here");

  if (addr && size
      && (addr->ival < 0x600000
	  || addr->ival + size->ival - 1 > 0x6fffff))
    errorn (top, "LOCAL_MEM must be within 0x0060_0000 to 0x006f_ffff");

  check_name (top);
  check_int_list (top, "ADDRESS", 0);
  check_int_list (top, "SIZE", 0);
  check_unexpected (top);
}

static void
verify_hw_engine (Node *top)
{
  Node *cbus, *a;
  Node *lbus_if;

  default_int (top, "NUMBER", 0);
  default_string (top, "CBUS_IF", "ON", N_WORD);
  default_string (top, "LBUS_IF", "OFF", N_WORD);

  lbus_if = find_typed_sub (top, N_WORD, "LBUS_IF", 0);
  if (lbus_if)
    if (strcmp (lbus_if->val, "ON") == 0)
      default_int (top, "LBUS_SIZE", 0x10000);
    else
      lbus_if = 0;

  check_name (top);
  check_int_range (top, "NUMBER", 0, 9);
  check_string (top, 0, "SIM", 0);
  check_string (top, 0, "LOCAL_MEM_LIST", 0);
  check_string (top, 1, "CBUS_IF", "ON", "OFF", 0);
  check_string (top, 1, "LBUS_IF", "ON", "OFF", 0);
  check_int_list (top, "CBUS_ADDRESS", 10,
		  0x4000, 0x5000, 0x6000, 0x7000, 0x8000,
		  0x9000, 0xA000, 0xB000, 0xC000, 0xD000);
  check_int_list (top, "LBUS_ADDRESS", 16,
		  0x600000, 0x610000, 0x620000, 0x630000, 0x640000,
		  0x650000, 0x660000, 0x670000, 0x680000, 0x690000,
		  0x6A0000, 0x6B0000, 0x6C0000, 0x6D0000, 0x6E0000,
		  0x6F0000);
  check_int_list (top, "LBUS_SIZE", 0);
  check_string (top, 0, "CMODEL_ARGS", 0);

  // ACDB = "..." should be parsed and checked but ignored for now.
  check_only_one (top, "ACDB");
  a = find_sub (top, "ACDB", NULL);
  wrong_type (a, N_QSTR);

  ignore_node (top, "ACDB");
  ignore_node (top, "NUMBER");

  check_unexpected (top);

  check_bus_addresses (top, lbus_if);

  cbus = find_typed_sub (top, N_NUM, "CBUS_ADDRESS", 0);
  if (cbus)
    check_bus_addr (top, cbus->ival, 1, CONTROL_BUS);
  else
    errorn (top, "CBUS_ADDRESS required here");
}

static void
verify_global_bus_if (Node *top)
{
  check_string (top, 0, "SIM", 0);
  check_unexpected (top);
}

static void
verify_biu (Node *top)
{
  Node *dn;

  dn = find_typed_sub (top, N_NUM, "DATA_WIDTH", 0);
  if (! dn)
    default_int (top, "DATA_WIDTH", 64);

  check_no_name (top);
  check_int_list (top, "DATA_WIDTH", 2, 32, 64);
  check_unexpected (top);
}

static void
verify_physical_cfg (Node *top)
{
  default_string (top, "BANK0", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "BANK1", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "BANK2", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "BANK3", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "DATA",  "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "DATA0", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "DATA1", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "TAG",   "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);
  default_string (top, "DIRTY", "lib=RAMS1H,type=A,row=1,column=1,bit_even=false", N_QSTR);

  check_no_name (top);
  check_string (top, 0, "BANK0", 0);
  check_string (top, 0, "BANK1", 0);
  check_string (top, 0, "BANK2", 0);
  check_string (top, 0, "BANK3", 0);
  check_string (top, 0, "DATA", 0); 
  check_string (top, 0, "DATA0", 0); 
  check_string (top, 0, "DATA1", 0); 
  check_string (top, 0, "TAG", 0);
  check_string (top, 0, "DIRTY", 0);
  check_unexpected (top);
}

static void
verify_cache (Node *top)
{
  check_int_list (top, "SIZE", 5, 1, 2, 4, 8, 16);
  switch (mep_core_type)
    {
    case MEP_CORE_C2:
    default:
      check_int_list (top, "LINE_SIZE", 1, 32);
      check_int_range (top, "WAY", 1, 1);
      check_string (top, 1, "CWF", "OFF", 0);
      break;
    case MEP_CORE_C3:
    case MEP_CORE_C4:
    case MEP_CORE_H1:
      if (get_biu_width (top->up->up) == 64)
	check_int_list (top, "LINE_SIZE", 3, 32, 64, 128);
      else
	check_int_list (top, "LINE_SIZE", 2, 32, 64);
      check_int_range (top, "WAY", 1, 2);
      check_string (top, 1, "CWF", "OFF", "ON", 0);
      break;
    }

  check_subnode (top, "PHYSICAL_CFG", 0, 1, verify_physical_cfg);
  check_unexpected (top);

  ignore_node (top, "PHYSICAL_CFG");
}

static void
verify_dcache (Node *top)
{
  default_int (top, "SIZE", 16);
  default_int (top, "LINE_SIZE", 32);
  default_int (top, "WAY", 1);
  default_string (top, "CWF", "OFF", N_WORD);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_node (top, "PHYSICAL_CFG", 0);
#endif

  check_opt_name (top);
  verify_cache (top);
}

static void
verify_dmem (Node *top)
{
  Node *sizenode, *banknode;
  int pair_ok = 0, size, bank, b1=2, b2=0;

  default_int (top, "SIZE", 8);
  sizenode = find_typed_sub (top, N_NUM, "SIZE", 0);
  if (sizenode)
    {
      size = sizenode->ival;
      switch (size)
	{
	case 24:  b2 = 3; break;
	case 32:  b2 = 4; break;
	case 48:
	case 96:  b1 = 3; break;
	case 64:
	case 128: b1 = 4; break;
	}
    }

  default_int (top, "BANK_NUM", b1);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_node (top, "PHYSICAL_CFG", 0);
#endif

  check_no_name (top);
  check_int_list (top, "SIZE", 13,
		  1, 2, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96, 128);
  check_int_list (top, "BANK_NUM", 3,
		  2, 3, 4);
  check_subnode (top, "PHYSICAL_CFG", 0, 1, verify_physical_cfg);
	      long dmem_base[4];

  if (mep_core_type == MEP_CORE_C4 || mep_core_type == MEP_CORE_H1)
    check_string (top, 1, "FIXED_START_ADDRESS", "YES", "NO", 0);
  else
    check_string (top, 1, "FIXED_START_ADDRESS", "NO", 0);

  check_unexpected (top);

  banknode = find_typed_sub (top, N_NUM, "BANK_NUM", 0);
  if (banknode && sizenode)
    {
      bank = banknode->ival;
      if (bank != b1 && bank != b2)
	errorn (top, "SIZE %d and BANK %d is not a valid combination", size, bank);
    }

  ignore_node (top, "PHYSICAL_CFG");
}

static void
verify_icache (Node *top)
{
  default_int (top, "SIZE", 16);
  default_int (top, "LINE_SIZE", 32);
  default_int (top, "WAY", 1);
  default_string (top, "CWF", "OFF", N_WORD);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_node (top, "PHYSICAL_CFG", 0);
#endif

  /* ICACHE names can overlap.  */
  /* check_opt_name (top); */
  verify_cache (top);
}

static void
verify_imem (Node *top)
{
  default_int (top, "SIZE", 8);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_node (top, "PHYSICAL_CFG", 0);
#endif

  check_no_name (top);
  check_int_list (top, "SIZE", 9, 1, 2, 4, 6, 8, 12, 16, 24, 32);
  check_subnode (top, "PHYSICAL_CFG", 0, 1, verify_physical_cfg);
  check_unexpected (top);

  ignore_node (top, "PHYSICAL_CFG");
}

static void
verify_core (Node *top)
{
  Node *m, *d;
  int ms=0, ds=0;

  /* DIV or MUL set to ON causes the other to default to ON as well.  */
  m = find_typed_sub (top, N_WORD, "MUL", NULL);
  if (m && strcmp (m->val, "ON") == 0)
    ms = 1;
  d = find_typed_sub (top, N_WORD, "DIV", NULL);
  if (d && strcmp (d->val, "ON") == 0)
    ds = 1;

  if (ms && !d)
    default_string (top, "DIV", m->val, N_WORD);
  else if (ds && !m)
    default_string (top, "MUL", d->val, N_WORD);
  else if (m && d && ms != ds)
    {
      warnn (top, "MULT and DIV must be set the same, so both set to ON");
      m->val = d->val = "ON";
    }

  default_string (top, "MUL", "OFF", N_WORD);
  default_string (top, "DIV", "OFF", N_WORD);
  default_string (top, "BIT", "OFF", N_WORD);
  default_string (top, "LDZ", "OFF", N_WORD);
  default_string (top, "ABS", "OFF", N_WORD);
  default_string (top, "AVE", "OFF", N_WORD);
  default_string (top, "MIN", "OFF", N_WORD);
  default_string (top, "CLP", "OFF", N_WORD);
  default_string (top, "SAT", "OFF", N_WORD);

  check_opt_name (top);
  check_core_id (top, 1);
  check_string (top, 1, "MUL", "ON", "OFF", 0);
  check_string (top, 1, "DIV", "ON", "OFF", 0);
  check_string (top, 1, "BIT", "ON", "OFF", 0);
  check_string (top, 1, "LDZ", "ON", "OFF", 0);
  check_string (top, 1, "ABS", "ON", "OFF", 0);
  check_string (top, 1, "AVE", "ON", "OFF", 0);
  check_string (top, 1, "MIN", "ON", "OFF", 0);
  check_string (top, 1, "CLP", "ON", "OFF", 0);
  check_string (top, 1, "SAT", "ON", "OFF", 0);
  check_unexpected (top);
}

static void
verify_sim_extra_config (Node *top)
{
  check_node (top, "DIR", 1, 1, 0);
  check_string (top, 0, "DIR", 0);
  check_string (top, 0, "SOURCES", 0);
  check_string (top, 0, "INCLUDES", 0);
  check_string (top, 0, "LDADD", 0);
  check_unexpected (top);
}

static void
verify_me_engine (Node *top)
{
  default_node (top, "CORE", 0);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "PRN_IF", "OFF", N_WORD);
#endif
  default_node (top, "BIU", 0);
  default_node (top, "INTC", 0);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "MEMORY_BIST_IF", "OFF", N_WORD);
  if (mep_core_type == MEP_CORE_H1)
    default_int (core, "TIMEOUT_CYCLE", 4);
#endif

  check_opt_name (top);
  check_subnode (top, "CORE", 0, 1, verify_core);
  check_subnode (top, "IMEM", 0, 1, verify_imem);
  check_subnode (top, "ICACHE", 0, 1, verify_icache);
  check_subnode (top, "DMEM", 0, 1, verify_dmem);
  check_subnode (top, "DCACHE", 0, 1, verify_dcache);
  check_string (top, 1, "PRN_IF", "ON", "OFF", 0);
  check_subnode (top, "BIU", 0, 1, verify_biu);
  check_subnode (top, "INTC", 0, 1, verify_intc);
  check_subnode (top, "DSU", 0, 1, verify_dsu);
  check_subnode (top, "TIMER", 0, 1, verify_timer);
  check_string (top, 1, "MEMORY_BIST_IF", "ON", "OFF", 0);
  if (mep_core_type == MEP_CORE_H1)
    check_int_list (top, "TIMEOUT_CYCLE", 3, 4, 16, 64);
  check_unexpected (top);

  ignore_node (top, "PRN_IF");
  unsupported_node (top, "DSU");
  ignore_node (top, "MEMORY_BIST_IF");
  if (mep_core_type == MEP_CORE_H1)
    ignore_node (top, "TIMEOUT_CYCLE");
}

static void
verify_me_module (Node *top)
{
  Node *bw, *dw, *tbw, *dbw;

  default_node (top, "ME_ENGINE", 0);
  default_node (top, "MAIN_BUS_IF", 0);
  default_node (top, "LOCAL_BUS", 0);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "RESET_ASYNC", "OFF", N_WORD);
  default_string (top, "GATED_CLOCK", "OFF", N_WORD);
  default_string (top, "USE_LPM", "OFF", N_WORD);
  default_string (top, "USE_DWF", "OFF", N_WORD);
#endif

  /* Clear out this table.  */
  check_bus_addr (0, 0, 0, 0);

  /* ME_ENGINE must precede MAIN_BUS_IF, DMAC, and LOCAL_BUS so that
     we can verify the DATA_WIDTH entries correctly.  */
  check_name (top);
  check_subnode (top, "ME_ENGINE", 0, 1, verify_me_engine);
  check_subnode (top, "HW_ENGINE", 0, 10, verify_hw_engine);
  check_subnode (top, "DSP", 0, 1, verify_dsp);
  check_subnode (top, "UCI", 0, 1, verify_uci);
  check_subnode (top, "COP", 0, 1, verify_cop);
  check_subnode (top, "LOCAL_MEM", 0, 0, verify_local_mem);
  check_subnode (top, "DMAC", 0, 1, verify_dmac);
  check_subnode (top, "MAIN_BUS_IF", 0, 1, verify_main_bus_if);
  check_subnode (top, "GLOBAL_BUS_IF", 0, 1, verify_global_bus_if);
  check_subnode (top, "LOCAL_BUS", 0, 1, verify_local_bus);
  check_subnode (top, "IRQ", 0, 1, verify_irq);
  check_string (top, 1, "RESET_ASYNC", "ON", "OFF", 0);
  check_string (top, 1, "GATED_CLOCK", "ON", "OFF", 0);
  check_string (top, 1, "CLK_CTRL", "ON", "OFF", 0);
  check_string (top, 1, "USE_LPM", "ON", "OFF", 0);
  check_string (top, 1, "USE_DWF", "ON", "OFF", 0);
  check_unexpected (top);

  /* These nodes are not used by MeP-Integrator.  */
  ignore_node (top, "RESET_ASYNC");
  ignore_node (top, "GATED_CLOCK");
  ignore_node (top, "CLK_CTRL");
  ignore_node (top, "USE_LPM");
  ignore_node (top, "USE_DWF");

  process_arcadia_files (top);

  /* Check that all the DATA_WIDTHs are consistent.  */
  bw = find_typed_sub (top, N_NUM, "ME_ENGINE", "BIU", "DATA_WIDTH", 0);
  if (bw && (bw->ival == 32 || bw->ival == 64))
    {
      dw = find_typed_sub (top, N_NUM, "MAIN_BUS_IF", "DATA_WIDTH", 0);
      if (dw && bw->ival != dw->ival)
	errorn (dw, "MAIN_BUS_IF must have the same size DATA_WIDTH (%d) as BIU (%d)",
		dw->ival, bw->ival);
      dw = find_typed_sub (top, N_NUM, "DMAC", "DATA_WIDTH", 0);
      if (dw && bw->ival != dw->ival)
	errorn (dw, "DMAC must have the same size DATA_WIDTH (%d) as BIU (%d)",
		dw->ival, bw->ival);
      dw = find_typed_sub (top, N_NUM, "LOCAL_BUS", "DATA_WIDTH", 0);
      if (dw && bw->ival != dw->ival)
	errorn (dw, "LOCAL_BUS must have the same size DATA_WIDTH (%d) as BIU (%d)",
		dw->ival, bw->ival);
    }

  /* Check that the CHANNEL_BITW of the INTC can accomodate the TIMER and the
     DMAC.  */
  bw = find_typed_sub (top, N_NUM, "ME_ENGINE", "INTC", "CHANNEL_BITW", 0);
  if (bw)
    {
      int tw, dw;
      tbw = find_typed_sub (top, N_NUM, "ME_ENGINE", "TIMER", "CHANNEL_BITW", 0);
      tw = tbw ? tbw->ival : 0;
      dbw = find_typed_sub (top, N_NUM, "DMAC", "CHANNEL_BITW", 0);
      dw = dbw ? dbw->ival : 0;
      if (bw->ival < tw + dw + 1)
	errorn (bw, "INTC.CHANNEL_BITW must not be less than TIMER.CHANNEL_BITW + DMAC.CHANNEL_BITW + 1");
    }
}

void
chain_ups (Node *n)
{
  Node *s;
  for (s=n->sub; s; s=s->next)
    {
      s->up = n;
      chain_ups (s);
    }
}

void
verify_config (Node *top)
{
  chain_ups (top);

  default_node (top, "ME_MODULE", "mm");
  default_string (top, "MEP_CORE_TYPE", "c2", N_QSTR);
#if 0 /* No point in adding these defaults, since they will be ignored.  */
  default_string (top, "REVISION", "0.0", N_QSTR);
  default_string (top, "RTL_VERIF", "OFF", N_WORD);
#endif

  /* This must come first. Other checks depend on it.  */
  check_mep_core_type (top);
  check_mep_endian (top);

  check_subnode (top, "ME_MODULE", 1, 256, verify_me_module);
  check_string (top, 0, "MEP_CORE_TYPE", 0);
  check_subnode (top, "PERIPHERAL", 0, 0, verify_peripheral);
  check_string (top, 0, "GLOBAL_MAP", 0);
  check_string (top, 0, "SIM_OPTION_FILE", 0);
  check_string (top, 0, "CHIP_NAME", 0);
  check_string (top, 0, "REVISION", 0);
  check_string (top, 1, "RTL_VERIF", "ON", "OFF", 0);
  check_string (top, 1, "MMNAME_TO_RTL", "YES", "NO", 0);
  check_subnode (top, "MM_INT", 0, 1, verify_mm_int);
  check_subnode (top, "GLOBAL_BUS", 0, 1, verify_global_bus);
  check_subnode (top, "SIM_EXTRA_CONFIG", 0, 0, verify_sim_extra_config);
  check_unexpected (top);

  /* These nodes are not used by MeP-Integrator.  */
  ignore_node (top, "CHIP_NAME");
  ignore_node (top, "REVISION");
  ignore_node (top, "RTL_VERIF");
  ignore_node (top, "MMNAME_TO_RTL");
  ignore_node (top, "SIM_OPTION_FILE");
}

/* Count the number of me_modules specified.  */
static void
get_corecount ()
{
  Node *cfgs;
  corecount = 0;
  isacount = 1;

  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  corecount ++;
	  isacount ++;
	  if (find_sub (modules, "cop", 0))
	    isacount += 4;
	}
    }
}

void
check_corecount_limit (void)
{
  Node *cfgs;

  /* No hard limit on the number of cores now.  */
  get_corecount ();

  /* If only one core has been specified, then the ID may be omitted. It will
     be assigned a default value of zero.  */
  if (corecount == 1)
    {
      for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
	{
	  Node *modules;
	  for (modules = find_sub (cfgs, "me_module", 0); modules; /**/)
	    {
	      Node *core = find_sub (modules, "me_engine", "core", 0);
	      assert (core);
	      if (! find_sub (core, "id", 0))
		{
		  default_int (core, "ID", 0);
		  core_ids_in_use[0] = find_sub (core, "id", 0);
		  assert (core_ids_in_use[0]);
		  next_core_id = 1;
		}
	      return;
	    }
	}
    }

  /* There are multiple cores specified. Each must have a unique ID
     explicitely specified.  Uniqueness has already been checked.  Check
     here for existence.  */
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  if (! find_sub (modules, "me_engine", "core", "id", 0))
	    errorn (modules, "ME_MODULE %s must have ME_ENGINE.CORE.ID", modules->val);
	}
    }
}

void
check_biu (void)
{
  Node *cfgs;
  Node *known_biu_width = 0;
  for (cfgs = currentcfg; cfgs; cfgs = cfgs->next)
    {
      Node *modules;
      for (modules = find_sub (cfgs, "me_module", 0); modules; modules = find_next (modules, "me_module"))
	{
	  Node *biu_width;
	  biu_width = find_sub (modules, "me_engine", "biu", "data_width", 0);
	  assert (biu_width);
	  if (known_biu_width != 0)
	    {
	      if (known_biu_width->ival != biu_width->ival)
		errorn (biu_width, "BIU width %d does not match %d specified at %s:%d",
			biu_width->ival, known_biu_width->ival,
			known_biu_width->filename, known_biu_width->lineno);
	    }
	  else
	    known_biu_width = biu_width;
	}
    }
}
