/* demo-target.c

   Copyright 2000, 2002 Red Hat, Inc.

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

#ifndef DEMO_TARGET_H
#define DEMO_TARGET_H

struct gdbserv;

/* Signal a request to terminate main loop. */
extern int demo_quit_p;

/* Create a demo target vector.  Used by demo_attach but can also be
   used by other demo targets that just need to tweek the target
   interface. */

struct gdbserv_target *demo_target (struct gdbserv *gdbserv, void *data);

/* This function is called from gdbloop_poll when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted. */

struct gdbserv_target *demo_attach (struct gdbserv* serv, void* data);

extern void (*demo_set_gen_hook)  (struct gdbserv *);
extern void (*demo_get_regs_hook) (struct gdbserv *);
extern int  (*demo_get_mem_hook)  (unsigned long);

extern void demo_tfind_open (char *);
extern int tfind_singlestep_program (struct gdbserv *);
extern int tfind_continue_thread (struct gdbserv *, 
				  struct gdbserv_thread *,
				  const struct gdbserv_reg *);

extern enum gdbserv_target_rc tfind_remove_swbp (struct gdbserv *,
						 enum gdbserv_target_bp,
						 struct gdbserv_reg *,
						 struct gdbserv_reg *);
extern enum gdbserv_target_rc tfind_set_swbp (struct gdbserv *,
					      enum gdbserv_target_bp,
					      struct gdbserv_reg *,
					      struct gdbserv_reg *);

#endif
