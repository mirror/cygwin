/* gdbserv-thread-db.h

   Copyright 2001, 2002 Red Hat, Inc.

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

/* Structure that identifies the target process.  */
struct ps_prochandle
{
  pid_t  pid;
  struct gdbserv *serv;
};

typedef struct ps_prochandle * gdb_ps_prochandle_t;
typedef void *                 gdb_ps_read_buf_t;
typedef void *                 gdb_ps_write_buf_t;
typedef size_t                 gdb_ps_size_t;

extern int thread_db_noisy;

/* Determine if register is a member of GREGSET_T.  */
extern int is_gp_reg (int regnum);

/* Determine if register is a floating point register, specifically
   a member of FPREGSET_T.  */
extern int is_fp_reg (int regnum);

/* Determine if register is an "extended register" (the meaning of which
   is architecture and perhaps even OS or libc dependent).  */
extern int is_extended_reg (int regnum);

/* Insert a register into a gregset. */
extern int reg_to_gregset (struct gdbserv *serv,
			   const struct gdbserv_reg *reg,
			   int regno,
			   GREGSET_T gregset);

/* Extract a register from a gregset. */
extern int reg_from_gregset (struct gdbserv *serv,
			     struct gdbserv_reg *reg,
			     int regno,
			     const GREGSET_T gregset);

/* Insert a register into an fpregset. */
extern int reg_to_fpregset (struct gdbserv *serv,
			    const struct gdbserv_reg *reg,
			    int regno,
			    FPREGSET_T *fpregset);

/* Extract a register from an fpregset. */
extern int reg_from_fpregset (struct gdbserv *serv,
			      struct gdbserv_reg *reg,
			      int regno,
			      const FPREGSET_T *fpregset);

/* Insert a register into an extended regset. */
extern int reg_to_xregset (struct gdbserv *serv, 
		           const struct gdbserv_reg *reg, 
		           int regno, 
		           void *xregset);

/* Extract a register from an extended regset. */
extern int reg_from_xregset (struct gdbserv *serv, 
		             struct gdbserv_reg *reg, 
		             int regno, 
		             const void *xregset);

/* Resume a stopped LWP. */
extern int continue_lwp (lwpid_t lid, int signal);

/* Step a stopped LWP. */
extern int singlestep_lwp (lwpid_t lid, int signal);

/* Attach an LWP. */
extern int attach_lwp (lwpid_t lid);

/* Fetch the value of PC for debugging purposes.  */
extern unsigned long debug_get_pc (struct gdbserv *serv, pid_t pid);

/* Adjust PC value after trap has been hit.  */
extern int decr_pc_after_break (struct gdbserv *serv, pid_t pid);
