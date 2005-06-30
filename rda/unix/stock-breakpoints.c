/* stock-breakpoints.c

   Copyright 2004 Red Hat, Inc.

   This file is part of RDA, the Red Hat Debug Agent (and library).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
   
   Alternative licenses for RDA may be arranged by contacting Red Hat,
   Inc.  */

#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gdbserv.h"
#include "gdbserv-target.h"
#include "gdbserv-utils.h"
#include "server.h"
#include "stock-breakpoints.h"

struct stock_bp
{
  /* All breakpoints in a table are kept in a doubly-linked ring, with
     the table's HEAD member as the head of the ring.  */
  struct stock_bp *prev, *next;

  /* The table to which this breakpoint belongs.  */
  struct stock_bp_table *table;

  /* The address at which this breakpoint is set.  */
  struct gdbserv_reg addr;

  /* The reference count for this breakpoint.  (You must delete this
     breakpoint this many times before it actually goes away.)  */
  int ref_count;

  /* The original contents of the memory at the breakpoint address,
     before we wrote the breakpoint instructions into it.  The length
     is taken from TABLE.  */
  void *saved;
};

struct stock_bp_table
{
  /* The head of a doubly-linked ring of breakpoints.  */
  struct stock_bp head;

  /* The gdbserver whose breakpoints we manage, and a target to use to
     talk to it.  */
  struct gdbserv *serv;
  struct gdbserv_target *target;

  /* The target we use to operate on PROCESS.  */
  
  /* The breakpoint instruction we store, and its length.  */
  size_t bp_insn_len;
  void *bp_insn_data;
};


struct stock_bp_table *
stock_bp_make_table (struct gdbserv *serv,
		     struct gdbserv_target *target)
{
  struct stock_bp_table *t = malloc (sizeof (*t));

  memset (t, 0, sizeof (*t));
  t->head.prev = t->head.next = &t->head;
  t->serv = serv;
  t->target = target;
  t->bp_insn_len = 0;

  return t;
}


struct gdbserv *
stock_bp_table_serv (struct stock_bp_table *table)
{
  return table->serv;
}


struct gdbserv_target *
stock_bp_table_target (struct stock_bp_table *table)
{
  return table->target;
}


void
stock_bp_set_bp_insn (struct stock_bp_table *t,
		      size_t len, void *data)
{
  t->bp_insn_len = len;
  t->bp_insn_data = malloc (len);
  memcpy (t->bp_insn_data, data, len);
}


struct stock_bp *
stock_bp_set_bp (struct stock_bp_table *table,
		 struct gdbserv_reg *addr)
{
  struct gdbserv *serv = table->serv;
  struct gdbserv_target *target = table->target;
  struct stock_bp *b;
  unsigned long long addr_int;
  int status;

  gdbserv_reg_to_ulonglong (serv, addr, &addr_int);

  /* Search the breakpoint table for a breakpoint at this address.  */
  for (b = table->head.next; b != &table->head; b = b->next)
    {
      unsigned long long bp_addr_int;

      gdbserv_reg_to_ulonglong (serv, &b->addr, &bp_addr_int);
      if (addr_int == bp_addr_int)
	{
	  /* We've found an extant breakpoint at the same address.
	     Increment its reference count, and return it.  */
	  b->ref_count++;
	  return b;
	}

      /* If this breakpoint partially overlaps the one we're
	 inserting, that seems like either a mistake, or something
	 that arch-specific code would need to deal with (in which
	 case this breakpoint implementation is not appropriate for
	 that architecture), so print a warning.

	 Keep in mind the oddities of unsigned arithmetic and
	 comparison; think carefully before simplifying this.  */
      if (bp_addr_int - addr_int < table->bp_insn_len
	  || addr_int - bp_addr_int < table->bp_insn_len)
	fprintf (stderr, "warning: new breakpoint at 0x%llx overlaps "
		 "existing breakpoint at 0x%llx\n",
		 addr_int, bp_addr_int);
    }

  /* We didn't find any existing breakpoint, so let's make a new one.  */
  b = malloc (sizeof (*b));

  memset (b, 0, sizeof (*b));
  b->next = table->head.next;
  b->prev = &table->head;
  b->table = table;
  memcpy (&b->addr, addr, sizeof (b->addr));
  b->ref_count = 1;
  b->saved = malloc (table->bp_insn_len);

  /* Save the old contents of the memory at addr.  */
  status = target->get_mem (serv, addr, b->saved, table->bp_insn_len);
  if (status != table->bp_insn_len)
    {
      fprintf (stderr,
	       "warning: couldn't save memory under breakpoint at 0x%llx\n",
	       addr_int);
      free (b->saved);
      free (b);
      return 0;
    }

  /* Write the breakpoint instruction.  */
  status = target->set_mem (serv, addr,
			    table->bp_insn_data, table->bp_insn_len);
  if (status != table->bp_insn_len)
    {
      fprintf (stderr,
	       "warning: couldn't write breakpoint to memory at 0x%llx\n",
	       addr_int);
      free (b->saved);
      free (b);
      return 0;
    }

  /* Flush the instruction caches.  */
  target->flush_i_cache (serv);

  /* Link the successfully-inserted breakpoint into the table.  */
  table->head.next->prev = b;
  table->head.next = b;

  return b;
}


int
stock_bp_delete_bp (struct stock_bp *b)
{
  struct stock_bp_table *table = b->table;
  struct gdbserv *serv = table->serv;
  struct gdbserv_target *target = table->target;
  int status;

  /* Drop a reference to this breakpoint.  */
  if (--b->ref_count > 0)
    /* There are still other references to this breakpoint, so leave
       it in.  */
    return 0;

  /* Unlink this breakpoint from its table.  */
  b->next->prev = b->prev;
  b->prev->next = b->next;

  /* Write the original breakpoint contents back to memory.  */
  status = target->set_mem (serv, &b->addr, b->saved, table->bp_insn_len);
  if (status != table->bp_insn_len)
    {
      unsigned long long bp_addr_int;

      gdbserv_reg_to_ulonglong (serv, &b->addr, &bp_addr_int);
      fprintf (stderr,
	       "warning: couldn't remove breakpoint at 0x%llx\n",
	       bp_addr_int);

      free (b->saved);
      free (b);
      return -1;
    }

  /* Flush the instruction caches.  */
  target->flush_i_cache (serv);

  free (b->saved);
  free (b);
  return 0;
}


struct stock_bp_table *
stock_bp_table (struct stock_bp *breakpoint)
{
  return breakpoint->table;
}


void
stock_bp_addr (struct gdbserv_reg *addr,
	       struct stock_bp *breakpoint)
{
  memcpy (addr, &breakpoint->addr, sizeof (*addr));
}
