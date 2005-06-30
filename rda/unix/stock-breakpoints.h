/* stock-breakpoints.h

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

#ifndef RDA_UNIX_STOCK_BREAKPOINTS_H
#define RDA_UNIX_STOCK_BREAKPOINTS_H

#include <stddef.h>

struct gdbserv;
struct gdbserv_reg;
struct gdbserv_target;

/* These functions implement a simple breakpoint table, suitable for
   use by architectures where software breakpoints work in the
   simplest way:

   - inserting a software breakpoint entails simply overwriting the
     instruction at the address, and

   - removing a software breakpoint entails restoring the original
     instruction.  */

/* The opaque type representing a table of stock breakpoints.  */
struct stock_bp_table; 

/* The opaque type representing a stock breakpoint.  */
struct stock_bp;

/* Create a new, empty breakpoint table managing memory for SERV,
   using TARGET.  */
struct stock_bp_table *stock_bp_make_table (struct gdbserv *serv,
					    struct gdbserv_target *target);

/* Return TABLE's gdbserv or gdbserv_target.  */
struct gdbserv *stock_bp_table_serv (struct stock_bp_table *table);
struct gdbserv_target *stock_bp_table_target (struct stock_bp_table *table);


/* Tell TABLE that inserting a breakpoint entails writing the LEN
   bytes at DATA to the breakpoint address, after saving the original
   contents.  */
void stock_bp_set_bp_insn (struct stock_bp_table *table,
			   size_t len, void *data);

/* Set a breakpoint at ADDR in TABLE's process.  This actually writes
   the breakpoint into TABLE's process's memory.  On success, return a
   pointer to the breakpoint; on failure, return NULL.  */
struct stock_bp *stock_bp_set_bp (struct stock_bp_table *table,
				  struct gdbserv_reg *addr);

/* Return the breakpoint table to which BREAKPOINT belongs.  */
struct stock_bp_table *stock_bp_table (struct stock_bp *breakpoint);

/* Set ADDR to the address at which BREAKPOINT is set.  */
void stock_bp_addr (struct gdbserv_reg *addr,
		    struct stock_bp *breakpoint);

/* Remove BREAKPOINT.  On success, return 0; on failure, return -1.
   After calling this function, BREAKPOINT is no longer guaranteed to
   be a valid pointer, even if the call fails.  */
int stock_bp_delete_bp (struct stock_bp *breakpoint);



#endif /* RDA_UNIX_STOCK_BREAKPOINTS_H */
