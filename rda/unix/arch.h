/* arch.h

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

#ifndef RDA_UNIX_ARCH_H
#define RDA_UNIX_ARCH_H

struct gdbserv;
struct gdbserv_target;
struct gdbserv_thread;
struct gdbserv_reg;
struct arch_bp_table;
struct arch_bp;


/* A machine architecture.

   Once constructed, an arch object should be basically read-only.
   You ought to be able to share architecture objects among multiple
   processes, servers, targets, etc.

   At the moment, this just declares stuff related to software
   breakpoints, but hopefully we can move more information into it
   over time.  */
struct arch {

  /* Pointer to arch-specific data.  */
  void *closure;

  /* Arch-level breakpoints are simple creatures.  They're either set,
     or not.  You can't disable them; you can't step over them.
     You'll need to build those behaviors on top of these primitives.

     You *do*, however, need to let architecture-specific code handle
     the entire list of such breakpoints, since whether two addresses
     are "the same" is architecture-dependent anyway: consider the
     FRV, where breakpoints need to be backed up to the beginning of
     the bundle.  And breakpoints set near each other may interact in
     interesting ways.  So arch-specific code handles detecting
     overlapping breakpoints and saving and restoring the original
     code overwritten by the breakpoint.  */

  /* Create a new software breakpoint table, dealing with TARGET,
     which is part of SERV.  */
  struct arch_bp_table *(*make_bp_table) (struct arch *arch,
					  struct gdbserv *serv,
					  struct gdbserv_target *target);

  /* Create a new software breakpoint at ADDR in SERV, and return a
     pointer to a new arch-specific breakpoint object.  Return NULL if
     an error occurs.  */
  struct arch_bp *(*set_bp) (struct arch_bp_table *table,
			     struct gdbserv_reg *addr);

  /* Remove the software breakpoint BREAKPOINT.  Free all resources
     allocated to it; after this call, BREAKPOINT is no longer a valid
     pointer.  Return zero on success, -1 on failure.  */
  int (*delete_bp) (struct arch_bp *breakpoint);

  /* Return true if THREAD's state is consistent with just having hit
     the software breakpoint BREAKPOINT; return false otherwise.
     THREAD must belong to the 'struct gdbserv' we passed to
     MAKE_BP_TABLE when we made BREAKPOINT's table.  */
  int (*bp_hit_p) (struct gdbserv_thread *thread,
		   struct arch_bp *breakpoint);
};


#endif /* RDA_UNIX_ARCH_H */
