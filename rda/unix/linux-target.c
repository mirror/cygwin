/* linux-target.c

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

#include "config.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#if !defined(_MIPSEL) && !defined(_MIPSEB)
#include <stdint.h>
#else
#include <asm/inst.h>
#endif

#include <sys/ptrace.h>
#include <sys/procfs.h>
#include "gdbserv.h"
#include "gdbserv-target.h"
#include "gdbserv-utils.h"

#include "gdb_proc_service.h"
#include "gdbserv-thread-db.h"

#include "server.h"
#include "arch.h"
#include "ptrace-target.h"
#include "diagnostics.h"

#ifdef STOCK_BREAKPOINTS
#include "stock-breakpoints.h"
#endif

/* This is a linux native gdbserv target that uses the RDA library to
   implement a remote gdbserver on a linux host.  It controls the
   process to be debugged on the linux host, allowing GDB to pull the
   strings from any host on the network (or on a serial port).  */


/* Generic architecture stuff.  */
static struct arch *
allocate_empty_arch (void)
{
  struct arch *a = malloc (sizeof (*a));
  
  memset (a, 0, sizeof (*a));

  return a;
}



/*
 * Messy target-dependent register stuff
 */

#if defined (HAVE_SYS_REG_H)
#include <sys/reg.h>
#elif defined (HAVE_ASM_REG_H)
#include <asm/reg.h>
#else
/* Desperation -- try asm/ptrace.h */
#include <asm/ptrace.h>
#endif
#include <errno.h>
#include <string.h>

enum
{
  /* Maximum size of a register in bytes.  */
  MAX_REG_SIZE = 64
};

enum regset
{
  /* Not available.  */
  NOREGS,

  /* General purpose register.  */
  GREGS,

  /* Floating point register.  */
  FPREGS,

  /* Extended floating point register.  (Probably MMX, SSE, or Altivec...) */
  FPXREGS,

  /* Other; not part of a regset.  Must be fetched by other means.  */
  OTHERREGS
};

/* struct getregs_setregs_reginfo is used to construct register tables
   for architectures which need to use PTRACE_GETREGS, PTRACE_SETREGS,
   PTRACE_GETFPREGS, PTRACE_SETFPREGS, etc.  to access all of the
   registers.  */

struct getregs_setregs_reginfo
{
  /* The register set used to fetch this register, one of GREGS, FPREGS,
     or FPXREGS.  */
  enum regset whichregs;

  /* Register set specific offset needed for accessing the register
     in question.  */
  int offset;

  /* Size of the field being accessed in "ptrace" struct.  */
  int ptrace_size;

  /* Size of field needed by gdb's remote protocol. */
  int proto_size;
};

/* struct peekuser_pokeuser_reginfo is used to construct register
   tables for architectures which can access all of the registers
   via the PTRACE_PEEKUSER and PTRACE_POKEUSER operations.  */

struct peekuser_pokeuser_reginfo
{
  /* Offset to use with PTRACE_PEEKUSER or PTRACE_POKEUSER.  This
     offset should not require any further adjustment.  */
  int ptrace_offset;

  /* Size of field being accessed via PTRACE_PEEKUSER or PTRACE_POKEUSER.
     Note that a large enough value could cause multiple peek/poke
     operations to occur.  */
  int ptrace_size;

  /* Register set (either GREGS or FPREGS) that this register
     belongs to.  */
  enum regset whichregs;

  /* Offset into regset struct at which register is stored.  */
  int regset_field_offset;

  /* Size of field in regset struct.  */
  int regset_field_size;

  /* Size of field as required by gdb's remote protocol.  */
  int proto_size;

  /* Some targets require the use of a different mechanism for fetching
     the registers.   If this field is non-zero, that different method will
     be used.  */
  int (*alternate_register_read_write_method) (struct gdbserv *, int pid,
                                               int regno, void *read_buf,
					       const void *write_buf);
};

/* Obtain the offset of MEMBER from a struct of type TYPE.  */
#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((int) ((char *) &((TYPE *) 0)->MEMBER))
#endif

/* Obtain the size of the field MEMBER from a struct of type TYPE.  */
#define fieldsize(TYPE, MEMBER) (sizeof (((TYPE *)0)->MEMBER))

/* Each architecture must define the following:

  1) An anonymous enum which defines the number of registers
     (NUM_REGS) accessible via a g/G packet.  Note that this may be
     larger or smaller than the total number of registers actually
     available on an architecture.  It can be larger in the case of
     an architecture variant which, e.g, doesn't have floating point
     registers.  It could be smaller when there are certain control
     registers which aren't exposed via GDB's debug interface.

  2) An anonymous enum which defines the index of the PC register (PC_REGNUM).

  3) A table named ``reginfo[]'' which describes the register set.  Indices
     into this table are GDB protocol register numbers.  Elements of the
     table are either peekuser_pokeuser_reginfo or getregs_setregs_reginfo
     structs depending upon which ptrace() operations are required to
     access all of the registers.  Some ptrace() implementations contain
     support for both {get,set}regset and {peek,poke}user operations, but
     those which implement both sets of operations rarely provide support
     for fetching all of the registers via one set of operations.  Usually,
     if the PTRACE_GETREGS operation is implemented, this means that
     struct getregs_setregs_reginfo will need to be used to define reginfo[].
     Otherwise, peekuser_pokeuser_reginfo[] should be used.  If it's the
     case that both sets of operations provide complete access to all of
     the registers of interest, then a slight preference should be given
     to using the peekuser_pokeuser_reginfo struct since this code should
     be somewhat more efficient.  (Though this could change if a register
     cache is implemented.)

  4) Either

	#define PEEKUSER_POKEUSER_REGINFO 1

     or

	#define GETREGS_SETREGS_REGINFO 1

     Actually, there's a third option which is to define neither of
     these, but this is only used by architectures which still use
     the old, decrepit mechanism which doesn't work with threads
     very well, nor handle registers of different sizes, etc.  So,
     do be sure to define one of the above.  Someday, we'll hopefully
     have all of the architectures converted over so that we won't
     even need to mention this third option.

  5) A function-like macro MAKE_ARCH (), expecting no arguments, which
     expands to an expression that evaluates to a pointer to a 'struct
     arch' object for the current architecture.  We use this to
     initialize the 'arch' member of the child_process structure.

     For now, this is optional; if not defined, child_process->arch is
     set to zero.  When we've converted all the architectures to
     produce an arch object, we can remove the default, so new ports
     that don't define a MAKE_ARCH macro will get an error, instead of
     silently losing functionality.

*/

     


#if defined (ARM_LINUX_TARGET)

/* ARM needs to use PTRACE_GETREGS / PTRACE_SETREGS and
   PTRACE_GETFPREGS / PTRACE_SETFPREGS to access all of the registers. 
   */
#define GETREGS_SETREGS_REGINFO 1

enum 
{ 
  PC_REGNUM = 15,
  NUM_REGS = 26,
  sign_extend = 0
};

static struct getregs_setregs_reginfo reginfo[] =
{
  { GREGS, 0 * 4, 4, 4 },					/* r0 */
  { GREGS, 1 * 4, 4, 4 },					/* r1 */
  { GREGS, 2 * 4, 4, 4 },					/* r2 */
  { GREGS, 3 * 4, 4, 4 },					/* r3 */
  { GREGS, 4 * 4, 4, 4 },					/* r4 */
  { GREGS, 5 * 4, 4, 4 },					/* r5 */
  { GREGS, 6 * 4, 4, 4 },					/* r6 */
  { GREGS, 7 * 4, 4, 4 },					/* r7 */
  { GREGS, 8 * 4, 4, 4 },					/* r8 */
  { GREGS, 9 * 4, 4, 4 },					/* r9 */
  { GREGS, 10 * 4, 4, 4 },					/* r10 */
  { GREGS, 11 * 4, 4, 4 },					/* r11 */
  { GREGS, 12 * 4, 4, 4 },					/* r12, sp */
  { GREGS, 13 * 4, 4, 4 },					/* r13, lr */
  { GREGS, 14 * 4, 4, 4 },					/* r14, fp */
  { GREGS, 15 * 4, 4, 4 },					/* r15, pc */
  { FPREGS, offsetof (struct user_fpregs, fpregs[0]),
            fieldsize (struct user_fpregs, fpregs[0]), 12},	/* f0 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[1]),
            fieldsize (struct user_fpregs, fpregs[1]), 12},	/* f1 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[2]),
            fieldsize (struct user_fpregs, fpregs[2]), 12},	/* f2 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[3]),
            fieldsize (struct user_fpregs, fpregs[3]), 12},	/* f3 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[4]),
            fieldsize (struct user_fpregs, fpregs[4]), 12},	/* f4 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[5]),
            fieldsize (struct user_fpregs, fpregs[5]), 12},	/* f5 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[6]),
            fieldsize (struct user_fpregs, fpregs[6]), 12},	/* f6 */
  { FPREGS, offsetof (struct user_fpregs, fpregs[7]),
            fieldsize (struct user_fpregs, fpregs[7]), 12},	/* f7 */
  /* We'd actually like to take the address of the fpsr field, but
     unfortunately, this is a bitfield and it's not possible to take
     its address.  fpregs[8] *should* yield the same address.  */
  { FPREGS, offsetof (struct user_fpregs, fpregs[8]), 4, 4},	/* fps */
  { GREGS, 16 * 4, 4, 4 }					/* cpsr */
};

/* End of ARM_LINUX_TARGET */

#elif defined (X86_LINUX_TARGET)

/* X86 needs to use PTRACE_GETREGS / PTRACE_SETREGS, PTRACE_GETFPREGS /
   PTRACE_SETFPREGS, and PTRACE_GETFPXREGS / PTRACE_SETFPXREGS to
   access all of the registers.   */
#define GETREGS_SETREGS_REGINFO 1

enum 
{ 
  PC_REGNUM = 8,
  NUM_REGS = 42,
  sign_extend = 0
};


static struct getregs_setregs_reginfo reginfo[] =
{
  { GREGS, EAX * 4, 4, 4 },
  { GREGS, ECX * 4, 4, 4 },
  { GREGS, EDX * 4, 4, 4 },
  { GREGS, EBX * 4, 4, 4 },
  { GREGS, UESP * 4, 4, 4 },
  { GREGS, EBP * 4, 4, 4 },
  { GREGS, ESI * 4, 4, 4 },
  { GREGS, EDI * 4, 4, 4 },
  { GREGS, EIP * 4, 4, 4 },
  { GREGS, EFL * 4, 4, 4 },
  { GREGS, CS * 4, 4, 4 },
  { GREGS, SS * 4, 4, 4 },
  { GREGS, DS * 4, 4, 4 },
  { GREGS, ES * 4, 4, 4 },
  { GREGS, FS * 4, 4, 4 },
  { GREGS, GS * 4, 4, 4 },
  /* 8 floating point registers */
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 0*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 1*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 2*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 3*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 4*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 5*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 6*10, 10, 10 },
  { FPREGS, offsetof (struct user_fpregs_struct, st_space[0]) + 7*10, 10, 10 },
  /* FCTRL */
  { FPREGS, offsetof  (struct user_fpregs_struct, cwd),
            fieldsize (struct user_fpregs_struct, cwd), 4},
  /* FSTAT */
  { FPREGS, offsetof  (struct user_fpregs_struct, swd),
            fieldsize (struct user_fpregs_struct, swd), 4},
  /* FTAG */
  { FPREGS, offsetof  (struct user_fpregs_struct, twd),
            fieldsize (struct user_fpregs_struct, twd), 4},
  /* FISEG or FCS */
  { FPREGS, offsetof  (struct user_fpregs_struct, fcs),
            fieldsize (struct user_fpregs_struct, fcs), 4},
  /* FIOFF or FCOFF */
  { FPREGS, offsetof  (struct user_fpregs_struct, fip),
            fieldsize (struct user_fpregs_struct, fip), 4},
  /* FOSEG or FDS */
  { FPREGS, offsetof  (struct user_fpregs_struct, fos),
            fieldsize (struct user_fpregs_struct, fos), 4},
  /* FOOFF or FDOFF */
  { FPREGS, offsetof  (struct user_fpregs_struct, foo),
            fieldsize (struct user_fpregs_struct, foo), 4},
  /* FOP */
  { FPXREGS, offsetof  (struct user_fpxregs_struct, fop),
             fieldsize (struct user_fpxregs_struct, fop), 4},
  /* 8 XMM registers */
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[0 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[1 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[2 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[3 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[4 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[5 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[6 * 4]), 16, 16 },
  { FPXREGS, offsetof (struct user_fpxregs_struct, xmm_space[7 * 4]), 16, 16 },
  /* MXCSR */
  { FPXREGS, offsetof  (struct user_fpxregs_struct, mxcsr),
             fieldsize (struct user_fpxregs_struct, mxcsr), 4},
  /* ORIG_EAX - needed by gdb for signal handling.  */
  { GREGS, ORIG_EAX * 4, 4, 4 } };


/* Breakpoint methods for the x86.  Except for bp_hit_p, these
   are just wrappers for the stock breakpoint methods.  In C++, we
   could use multiple inheritance for this, and it would all just
   work...  */

/* x86 breakpoints tables are just stock breakpoint tables.  But we
   like static typechecking; casts swallow error messages.  */
static struct arch_bp_table *
stock_table_to_x86 (struct stock_bp_table *table)
{
  return (struct arch_bp_table *) table;
}

static struct stock_bp_table *
x86_table_to_stock (struct arch_bp_table *table)
{
  return (struct stock_bp_table *) table;
}

/* x86 breakpoints are just stock breakpoints.  But we like static
   typechecking; casts swallow error messages.  */
static struct arch_bp *
stock_bp_to_x86 (struct stock_bp *bp)
{
  return (struct arch_bp *) bp;
}

static struct stock_bp *
x86_bp_to_stock (struct arch_bp *bp)
{
  return (struct stock_bp *) bp;
}

struct arch_bp_table *
x86_make_bp_table (struct arch *arch,
		   struct gdbserv *serv,
		   struct gdbserv_target *target)
{
  struct stock_bp_table *table = stock_bp_make_table (serv, target);

  /* Use 'int 3' as the breakpoint instruction.  */
  stock_bp_set_bp_insn (table, 1, "\xcc");

  return stock_table_to_x86 (table);
}


static struct arch_bp *
x86_set_bp (struct arch_bp_table *table,
	    struct gdbserv_reg *addr)
{
  /* x86 arch breakpoints are just stock breakpoints.  */
  return stock_bp_to_x86 (stock_bp_set_bp (x86_table_to_stock (table),
					   addr));
}


static int
x86_delete_bp (struct arch_bp *bp)
{
  return stock_bp_delete_bp (x86_bp_to_stock (bp));
}


static int
x86_bp_hit_p (struct gdbserv_thread *thread,
	      struct arch_bp *arch_bp)
{
  struct stock_bp *bp = x86_bp_to_stock (arch_bp);
  struct stock_bp_table *table = stock_bp_table (bp);
  struct gdbserv *serv = stock_bp_table_serv (table);
  struct gdbserv_target *target = stock_bp_table_target (table);
  struct gdbserv_reg bp_addr, pc;
  unsigned long bp_addr_int, pc_int;

  stock_bp_addr (&bp_addr, bp);
  gdbserv_reg_to_ulong (serv, &bp_addr, &bp_addr_int);
  target->get_thread_reg (serv, thread, PC_REGNUM, &pc);
  gdbserv_reg_to_ulong (serv, &pc, &pc_int);

  /* When the x86 hits a breakpoint, the reported PC is one greater
     than the address of the breakpoint.  */
  return bp_addr_int + 1 == pc_int;
}


/* Construct an architecture object for the x86.  */
static struct arch *
x86_make_arch (void)
{
  struct arch *a = allocate_empty_arch ();

  a->closure = 0;		/* No closure needed at the moment.  */
  a->make_bp_table = x86_make_bp_table;
  a->set_bp = x86_set_bp;
  a->delete_bp = x86_delete_bp;
  a->bp_hit_p = x86_bp_hit_p;

  return a;
}

#define MAKE_ARCH() (x86_make_arch ())

/* End of X86_LINUX_TARGET */

#elif defined (AM33_2_0_LINUX_TARGET) || defined (AM33_LINUX_TARGET)

/* AM33 needs to use PTRACE_GETREGS / PTRACE_SETREGS, PTRACE_GETFPREGS /
   PTRACE_SETFPREGS in order to access all of the registers.   */
#define GETREGS_SETREGS_REGINFO 1
#define SOFTWARE_SINGLESTEP 1

enum
{
  PC_REGNUM = 9,
  A0_REGNUM = 4,
  A1_REGNUM = 5,
  A2_REGNUM = 6,
  A3_REGNUM = 7,
  LIR_REGNUM = 12,
  LAR_REGNUM = 13,
  MDR_REGNUM = 10,
  SP_REGNUM = 8,
  NUM_REGS = 64,
  sign_extend=0
};

/* These should match the constants defined in <asm/ptrace.h>  */
#define PT_A3		0
#define PT_A2		1
#define PT_D3		2
#define	PT_D2		3
#define PT_MCVF		4
#define	PT_MCRL		5
#define PT_MCRH		6
#define	PT_MDRQ		7
#define	PT_E1		8
#define	PT_E0		9
#define	PT_E7		10
#define	PT_E6		11
#define	PT_E5		12
#define	PT_E4		13
#define	PT_E3		14
#define	PT_E2		15
#define	PT_SP		16
#define	PT_LAR		17
#define	PT_LIR		18
#define	PT_MDR		19
#define	PT_A1		20
#define	PT_A0		21
#define	PT_D1		22
#define	PT_D0		23
#define PT_ORIG_D0	24
#define	PT_EPSW		25
#define	PT_PC		26

static struct getregs_setregs_reginfo reginfo[] =
{
  { GREGS,  PT_D0 * 4,   4,   4 },
  { GREGS,  PT_D1 * 4,   4,   4 },
  { GREGS,  PT_D2 * 4,   4,   4 },
  { GREGS,  PT_D3 * 4,   4,   4 },
  { GREGS,  PT_A0 * 4,   4,   4 },
  { GREGS,  PT_A1 * 4,   4,   4 },
  { GREGS,  PT_A2 * 4,   4,   4 },
  { GREGS,  PT_A3 * 4,   4,   4 },
  { GREGS,  PT_SP * 4,   4,   4 },
  { GREGS,  PT_PC * 4,   4,   4 },
  { GREGS,  PT_MDR * 4,  4,   4 },
  { GREGS,  PT_EPSW * 4, 4,   4 }, /* psw */
  { GREGS,  PT_LIR * 4,  4,   4 },
  { GREGS,  PT_LAR * 4,  4,   4 },
  { GREGS,  PT_MDRQ * 4, 4,   4 },
  { GREGS,  PT_E0 * 4,   4,   4 }, /* r0 */
  { GREGS,  PT_E1 * 4,   4,   4 }, /* r1 */
  { GREGS,  PT_E2 * 4,   4,   4 }, /* r2 */
  { GREGS,  PT_E3 * 4,   4,   4 }, /* r3 */
  { GREGS,  PT_E4 * 4,   4,   4 }, /* r4 */
  { GREGS,  PT_E5 * 4,   4,   4 }, /* r5 */
  { GREGS,  PT_E6 * 4,   4,   4 }, /* r6 */
  { GREGS,  PT_E7 * 4,   4,   4 }, /* r7 */
  { GREGS,  PT_SP * 4,   4,   4 }, /* ssp */
  { GREGS,  PT_SP * 4,   4,   4 }, /* msp */
  { GREGS,  PT_SP * 4,   4,   4 }, /* usp */
  { GREGS,  PT_MCRH * 4, 4,   4 },
  { GREGS,  PT_MCRL * 4, 4,   4 },
  { GREGS,  PT_MCVF * 4, 4,   4 },

  /* AM33 uses single precision floating point registers where two
     consecutive registers are combined to form a double.  The
     register layout is defined (in the kernel sources) in
     include/asm-mn10300/processor.h.  Unfortunately, this file is not
     easily included, so we'll use hard coded constants for the
     offsets and sizes...  */

  { FPREGS, 32 * 4, 4, 4 }, /* fpcr */

  /* The "g" packet has a gap between fpcr and fs0.  */
  { NOREGS,  0,     0, 4 },
  { NOREGS,  0,     0, 4 },

  { FPREGS,  0 * 4, 4, 4 }, /* fs0 */
  { FPREGS,  1 * 4, 4, 4 }, /* fs1 ... */
  { FPREGS,  2 * 4, 4, 4 },
  { FPREGS,  3 * 4, 4, 4 },
  { FPREGS,  4 * 4, 4, 4 },
  { FPREGS,  5 * 4, 4, 4 },
  { FPREGS,  6 * 4, 4, 4 },
  { FPREGS,  7 * 4, 4, 4 },
  { FPREGS,  8 * 4, 4, 4 },
  { FPREGS,  9 * 4, 4, 4 },
  { FPREGS, 10 * 4, 4, 4 },
  { FPREGS, 11 * 4, 4, 4 },
  { FPREGS, 12 * 4, 4, 4 },
  { FPREGS, 13 * 4, 4, 4 },
  { FPREGS, 14 * 4, 4, 4 },
  { FPREGS, 15 * 4, 4, 4 },
  { FPREGS, 16 * 4, 4, 4 },
  { FPREGS, 17 * 4, 4, 4 },
  { FPREGS, 18 * 4, 4, 4 },
  { FPREGS, 19 * 4, 4, 4 },
  { FPREGS, 20 * 4, 4, 4 },
  { FPREGS, 21 * 4, 4, 4 },
  { FPREGS, 22 * 4, 4, 4 },
  { FPREGS, 23 * 4, 4, 4 },
  { FPREGS, 24 * 4, 4, 4 },
  { FPREGS, 25 * 4, 4, 4 },
  { FPREGS, 26 * 4, 4, 4 },
  { FPREGS, 27 * 4, 4, 4 },
  { FPREGS, 28 * 4, 4, 4 },
  { FPREGS, 29 * 4, 4, 4 },
  { FPREGS, 30 * 4, 4, 4 },
  { FPREGS, 31 * 4, 4, 4 }  /* fs31 */
};

static void am33_singlestep_program (struct gdbserv *serv);

/* Breakpoint methods for the am33.  Except for bp_hit_p, these
   are just wrappers for the stock breakpoint methods.  In C++, we
   could use multiple inheritance for this, and it would all just
   work...  */

/* am33 breakpoints tables are just stock breakpoint tables.  But we
   like static typechecking; casts swallow error messages.  */
static struct arch_bp_table *
stock_table_to_am33 (struct stock_bp_table *table)
{
  return (struct arch_bp_table *) table;
}

static struct stock_bp_table *
am33_table_to_stock (struct arch_bp_table *table)
{
  return (struct stock_bp_table *) table;
}

/* am33 breakpoints are just stock breakpoints.  But we like static
   typechecking; casts swallow error messages.  */
static struct arch_bp *
stock_bp_to_am33 (struct stock_bp *bp)
{
  return (struct arch_bp *) bp;
}

static struct stock_bp *
am33_bp_to_stock (struct arch_bp *bp)
{
  return (struct stock_bp *) bp;
}

struct arch_bp_table *
am33_make_bp_table (struct arch *arch,
		   struct gdbserv *serv,
		   struct gdbserv_target *target)
{
  struct stock_bp_table *table = stock_bp_make_table (serv, target);

  /* Use 0xff as the breakpoint instruction.  */
  stock_bp_set_bp_insn (table, 1, "\xff");

  return stock_table_to_am33 (table);
}


static struct arch_bp *
am33_set_bp (struct arch_bp_table *table,
	    struct gdbserv_reg *addr)
{
  /* am33 arch breakpoints are just stock breakpoints.  */
  return stock_bp_to_am33 (stock_bp_set_bp (am33_table_to_stock (table),
					   addr));
}


static int
am33_delete_bp (struct arch_bp *bp)
{
  return stock_bp_delete_bp (am33_bp_to_stock (bp));
}


static int
am33_bp_hit_p (struct gdbserv_thread *thread,
	      struct arch_bp *arch_bp)
{
  struct stock_bp *bp = am33_bp_to_stock (arch_bp);
  struct stock_bp_table *table = stock_bp_table (bp);
  struct gdbserv *serv = stock_bp_table_serv (table);
  struct gdbserv_target *target = stock_bp_table_target (table);
  struct gdbserv_reg bp_addr, pc;
  unsigned long bp_addr_int, pc_int;

  stock_bp_addr (&bp_addr, bp);
  gdbserv_reg_to_ulong (serv, &bp_addr, &bp_addr_int);
  target->get_thread_reg (serv, thread, PC_REGNUM, &pc);
  gdbserv_reg_to_ulong (serv, &pc, &pc_int);

  /* When the am33 hits a breakpoint, the reported PC value is equal to
     address of the breakpoint.  */
  return bp_addr_int == pc_int;
}


/* Construct an architecture object for the am33.  */
static struct arch *
am33_make_arch (void)
{
  struct arch *a = allocate_empty_arch ();

  a->closure = 0;		/* No closure needed at the moment.  */
  a->make_bp_table = am33_make_bp_table;
  a->set_bp = am33_set_bp;
  a->delete_bp = am33_delete_bp;
  a->bp_hit_p = am33_bp_hit_p;

  return a;
}

#define MAKE_ARCH() (am33_make_arch ())

/* End of AM33_LINUX_TARGET */

#elif defined (SH_LINUX_TARGET)

/* Needs to be converted to use either GETREGS_SETREGS_REGINFO or
   PEEKUSER_POKEUSER_REGINFO machinery.  */

enum
{
  SIZEOF_REGMAP = 23,
  SIZEOF_MAPPEDREG = 4,
  NUM_REGS = 24,
  PC_REGNUM = 16,
  sign_extend = 0
};

static int regmap[SIZEOF_REGMAP] =
{
  REG_REG0,    REG_REG0+1,  REG_REG0+2,  REG_REG0+3, 
  REG_REG0+4,  REG_REG0+5,  REG_REG0+6,  REG_REG0+7, 
  REG_REG0+8,  REG_REG0+9,  REG_REG0+10, REG_REG0+11, 
  REG_REG0+12, REG_REG0+13, REG_REG0+14, REG_REG15, 
  REG_PC,      REG_PR,      REG_GBR,     -1,
  REG_MACH,    REG_MACL,    REG_SR,
};

extern int
is_fp_reg (int regnum)
{
  return 0;
}

int
is_gp_reg (int regnum)
{
  return !is_fp_reg (regnum);
}

extern int
is_extended_reg (int regnum)
{
  return 0;
}

/* End of SH_LINUX_TARGET */

#elif defined MIPS_LINUX_TARGET || (defined MIPS64_LINUX_TARGET && defined MIPS_ABI_O32)

#define PEEKUSER_POKEUSER_REGINFO 1
#define SOFTWARE_SINGLESTEP 1

enum
{
  NUM_REGS = 72,
  PC_REGNUM = 37,
  sign_extend = 1
};

#ifndef FPR_BASE
#define FPR_BASE 32
#endif
#ifndef PC
#define PC		64
#endif
#ifndef CAUSE
#define CAUSE		65
#endif
#ifndef BADVADDR
#define BADVADDR	66
#endif
#ifndef MMHI
#define MMHI		67
#endif
#ifndef MMLO
#define MMLO		68
#endif
#ifndef FPC_CSR
#define FPC_CSR		69
#endif
#ifndef FPC_EIR
#define FPC_EIR		70
#endif

#ifdef MIPS64_LINUX_TARGET
#define PROTO_SIZE 8
#else
#define PROTO_SIZE 4
#endif

static struct peekuser_pokeuser_reginfo reginfo[] =
{
  /* MIPS has differing elf_gregset_t and gregset_t structs.  (The
     former contains some leading padding that the latter does not.)
     elf_gregset_t is used to access registers from a core file whereas
     gregset_t is used by the thread library in its interfaces.  Since
     we're concerned about the latter, we'll use the gregset_t offsets
     in the table below.  */
  { 0,             4, GREGS,  0 * 4,  4, PROTO_SIZE, 0 },      /* zero */
  { 1,             4, GREGS,  1 * 4,  4, PROTO_SIZE, 0 },      /* at */
  { 2,             4, GREGS,  2 * 4,  4, PROTO_SIZE, 0 },      /* v0 */
  { 3,             4, GREGS,  3 * 4,  4, PROTO_SIZE, 0 },      /* v1 */
  { 4,             4, GREGS,  4 * 4,  4, PROTO_SIZE, 0 },      /* a0 */
  { 5,             4, GREGS,  5 * 4,  4, PROTO_SIZE, 0 },      /* a1 */
  { 6,             4, GREGS,  6 * 4,  4, PROTO_SIZE, 0 },      /* a2 */
  { 7,             4, GREGS,  7 * 4,  4, PROTO_SIZE, 0 },      /* a3 */
  { 8,             4, GREGS,  8 * 4,  4, PROTO_SIZE, 0 },      /* t0 */
  { 9,             4, GREGS,  9 * 4,  4, PROTO_SIZE, 0 },      /* t1 */
  { 10,            4, GREGS,  10 * 4, 4, PROTO_SIZE, 0 },      /* t2 */
  { 11,            4, GREGS,  11 * 4, 4, PROTO_SIZE, 0 },      /* t3 */
  { 12,            4, GREGS,  12 * 4, 4, PROTO_SIZE, 0 },      /* t4 */
  { 13,            4, GREGS,  13 * 4, 4, PROTO_SIZE, 0 },      /* t5 */
  { 14,            4, GREGS,  14 * 4, 4, PROTO_SIZE, 0 },      /* t6 */
  { 15,            4, GREGS,  15 * 4, 4, PROTO_SIZE, 0 },      /* t7 */
  { 16,            4, GREGS,  16 * 4, 4, PROTO_SIZE, 0 },      /* s0 */
  { 17,            4, GREGS,  17 * 4, 4, PROTO_SIZE, 0 },      /* s1 */
  { 18,            4, GREGS,  18 * 4, 4, PROTO_SIZE, 0 },      /* s2 */
  { 19,            4, GREGS,  19 * 4, 4, PROTO_SIZE, 0 },      /* s3 */
  { 20,            4, GREGS,  20 * 4, 4, PROTO_SIZE, 0 },      /* s4 */
  { 21,            4, GREGS,  21 * 4, 4, PROTO_SIZE, 0 },      /* s5 */
  { 22,            4, GREGS,  22 * 4, 4, PROTO_SIZE, 0 },      /* s6 */
  { 23,            4, GREGS,  23 * 4, 4, PROTO_SIZE, 0 },      /* s7 */
  { 24,            4, GREGS,  24 * 4, 4, PROTO_SIZE, 0 },      /* t8 */
  { 25,            4, GREGS,  25 * 4, 4, PROTO_SIZE, 0 },      /* t9 */
  { 26,            4, GREGS,  26 * 4, 4, PROTO_SIZE, 0 },      /* k0 */
  { 27,            4, GREGS,  27 * 4, 4, PROTO_SIZE, 0 },      /* k1 */
  { 28,            4, GREGS,  28 * 4, 4, PROTO_SIZE, 0 },      /* gp */
  { 29,            4, GREGS,  29 * 4, 4, PROTO_SIZE, 0 },      /* sp */
  { 30,            4, GREGS,  30 * 4, 4, PROTO_SIZE, 0 },      /* s8/fp */
  { 31,            4, GREGS,  31 * 4, 4, PROTO_SIZE, 0 },      /* ra */
  { 0,             4, NOREGS, 0,      4, PROTO_SIZE, 0 },      /* sr */
  { MMLO,          4, GREGS,  33 * 4, 4, PROTO_SIZE, 0 },      /* lo */
  { MMHI,          4, GREGS,  32 * 4, 4, PROTO_SIZE, 0 },      /* hi */

  /* glibc's ucontext.h doesn't specify the order of the following
     three registerss.  But there is space allocated for them.  (Well,
     for something, anyway - the g_pad[] array is has three elements.)
     We use the same order for these fields as that specified in the
     kernel header for elf_gregset_t; see the EF_ constants in
     asm-mips/reg.h.  Note, however, that the kernel header sandwiches
     the status register (sr, above) in between ``bad'' and ``cause''.  */

#if 0
  /* CAUSE and BADVADDR are readable via ptrace, but they're not writable.  */
  { BADVADDR,      4, GREGS,  35 * 4, 4, PROTO_SIZE, 0 },      /* bad */
  { CAUSE,         4, GREGS,  36 * 4, 4, PROTO_SIZE, 0 },      /* cause */
#else
  { 0,             8, NOREGS, 0,      8, PROTO_SIZE, 0 },      /* bad */
  { 0,             8, NOREGS, 0,      8, PROTO_SIZE, 0 },      /* cause */
#endif
  { PC,            4, GREGS,  34 * 4, 4, PROTO_SIZE, 0 },      /* pc */

  /* Linux/MIPS floating point is a bit of a mess.  On the one hand,
     the elf_fpregset_t contains space for 32 doubles plus the control
     word.  But on the other hand, the ptrace interface is only able to
     fetch the 32 32-bit wide registers.  This means that we only get
     16 double precision floats via ptrace().  It also means that only
     slightly more than half of elf_fpregset_t is unused.  */

  { FPR_BASE + 0,  4, FPREGS, 0 * 4,  4, PROTO_SIZE, 0 },      /* $f0 */
  { FPR_BASE + 1,  4, FPREGS, 1 * 4,  4, PROTO_SIZE, 0 },      /* $f1 */
  { FPR_BASE + 2,  4, FPREGS, 2 * 4,  4, PROTO_SIZE, 0 },      /* $f2 */
  { FPR_BASE + 3,  4, FPREGS, 3 * 4,  4, PROTO_SIZE, 0 },      /* $f3 */
  { FPR_BASE + 4,  4, FPREGS, 4 * 4,  4, PROTO_SIZE, 0 },      /* $f4 */
  { FPR_BASE + 5,  4, FPREGS, 5 * 4,  4, PROTO_SIZE, 0 },      /* $f5 */
  { FPR_BASE + 6,  4, FPREGS, 6 * 4,  4, PROTO_SIZE, 0 },      /* $f6 */
  { FPR_BASE + 7,  4, FPREGS, 7 * 4,  4, PROTO_SIZE, 0 },      /* $f7 */
  { FPR_BASE + 8,  4, FPREGS, 8 * 4,  4, PROTO_SIZE, 0 },      /* $f8 */
  { FPR_BASE + 9,  4, FPREGS, 9 * 4,  4, PROTO_SIZE, 0 },      /* $f9 */
  { FPR_BASE + 10, 4, FPREGS, 10 * 4, 4, PROTO_SIZE, 0 },      /* $f10 */
  { FPR_BASE + 11, 4, FPREGS, 11 * 4, 4, PROTO_SIZE, 0 },      /* $f11 */
  { FPR_BASE + 12, 4, FPREGS, 12 * 4, 4, PROTO_SIZE, 0 },      /* $f12 */
  { FPR_BASE + 13, 4, FPREGS, 13 * 4, 4, PROTO_SIZE, 0 },      /* $f13 */
  { FPR_BASE + 14, 4, FPREGS, 14 * 4, 4, PROTO_SIZE, 0 },      /* $f14 */
  { FPR_BASE + 15, 4, FPREGS, 15 * 4, 4, PROTO_SIZE, 0 },      /* $f15 */
  { FPR_BASE + 16, 4, FPREGS, 16 * 4, 4, PROTO_SIZE, 0 },      /* $f16 */
  { FPR_BASE + 17, 4, FPREGS, 17 * 4, 4, PROTO_SIZE, 0 },      /* $f17 */
  { FPR_BASE + 18, 4, FPREGS, 18 * 4, 4, PROTO_SIZE, 0 },      /* $f18 */
  { FPR_BASE + 19, 4, FPREGS, 19 * 4, 4, PROTO_SIZE, 0 },      /* $f19 */
  { FPR_BASE + 20, 4, FPREGS, 20 * 4, 4, PROTO_SIZE, 0 },      /* $f20 */
  { FPR_BASE + 21, 4, FPREGS, 21 * 4, 4, PROTO_SIZE, 0 },      /* $f21 */
  { FPR_BASE + 22, 4, FPREGS, 22 * 4, 4, PROTO_SIZE, 0 },      /* $f22 */
  { FPR_BASE + 23, 4, FPREGS, 23 * 4, 4, PROTO_SIZE, 0 },      /* $f23 */
  { FPR_BASE + 24, 4, FPREGS, 24 * 4, 4, PROTO_SIZE, 0 },      /* $f24 */
  { FPR_BASE + 25, 4, FPREGS, 25 * 4, 4, PROTO_SIZE, 0 },      /* $f25 */
  { FPR_BASE + 26, 4, FPREGS, 26 * 4, 4, PROTO_SIZE, 0 },      /* $f26 */
  { FPR_BASE + 27, 4, FPREGS, 27 * 4, 4, PROTO_SIZE, 0 },      /* $f27 */
  { FPR_BASE + 28, 4, FPREGS, 28 * 4, 4, PROTO_SIZE, 0 },      /* $f28 */
  { FPR_BASE + 29, 4, FPREGS, 29 * 4, 4, PROTO_SIZE, 0 },      /* $f29 */
  { FPR_BASE + 30, 4, FPREGS, 30 * 4, 4, PROTO_SIZE, 0 },      /* $f30 */
  { FPR_BASE + 31, 4, FPREGS, 31 * 4, 4, PROTO_SIZE, 0 },      /* $f31 */
  { FPC_CSR,       4, FPREGS, 64 * 4, 4, PROTO_SIZE, 0 },      /* fsr */
  /* The "fir" value actually ends up occupying fp_pad in the fpregset
     struct.  */
  { FPC_EIR,       4, FPREGS, 65 * 4, 4, PROTO_SIZE, 0 }       /* fir */
};

static void mips_singlestep_program (struct gdbserv *serv);

/* End of MIPS_LINUX_TARGET */

#elif defined(MIPS64_LINUX_TARGET)

#define PEEKUSER_POKEUSER_REGINFO 1
#define SOFTWARE_SINGLESTEP 1

enum
{
  NUM_REGS = 72,
  PC_REGNUM = 37,
  sign_extend = 1
};


static struct peekuser_pokeuser_reginfo reginfo[] =
{
  /* MIPS has differing elf_gregset_t and gregset_t structs.  (The
     former contains some leading padding that the latter does not.)
     elf_gregset_t is used to access registers from a core file whereas
     gregset_t is used by the thread library in its interfaces.  Since
     we're concerned about the latter, we'll use the gregset_t offsets
     in the table below.  */
  { 0,             8, GREGS,  0 * 8,  8, 8, 0 },      /* zero */
  { 1,             8, GREGS,  1 * 8,  8, 8, 0 },      /* at */
  { 2,             8, GREGS,  2 * 8,  8, 8, 0 },      /* v0 */
  { 3,             8, GREGS,  3 * 8,  8, 8, 0 },      /* v1 */
  { 4,             8, GREGS,  4 * 8,  8, 8, 0 },      /* a0 */
  { 5,             8, GREGS,  5 * 8,  8, 8, 0 },      /* a1 */
  { 6,             8, GREGS,  6 * 8,  8, 8, 0 },      /* a2 */
  { 7,             8, GREGS,  7 * 8,  8, 8, 0 },      /* a3 */
  { 8,             8, GREGS,  8 * 8,  8, 8, 0 },      /* t0 */
  { 9,             8, GREGS,  9 * 8,  8, 8, 0 },      /* t1 */
  { 10,            8, GREGS,  10 * 8, 8, 8, 0 },      /* t2 */
  { 11,            8, GREGS,  11 * 8, 8, 8, 0 },      /* t3 */
  { 12,            8, GREGS,  12 * 8, 8, 8, 0 },      /* t4 */
  { 13,            8, GREGS,  13 * 8, 8, 8, 0 },      /* t5 */
  { 14,            8, GREGS,  14 * 8, 8, 8, 0 },      /* t6 */
  { 15,            8, GREGS,  15 * 8, 8, 8, 0 },      /* t7 */
  { 16,            8, GREGS,  16 * 8, 8, 8, 0 },      /* s0 */
  { 17,            8, GREGS,  17 * 8, 8, 8, 0 },      /* s1 */
  { 18,            8, GREGS,  18 * 8, 8, 8, 0 },      /* s2 */
  { 19,            8, GREGS,  19 * 8, 8, 8, 0 },      /* s3 */
  { 20,            8, GREGS,  20 * 8, 8, 8, 0 },      /* s4 */
  { 21,            8, GREGS,  21 * 8, 8, 8, 0 },      /* s5 */
  { 22,            8, GREGS,  22 * 8, 8, 8, 0 },      /* s6 */
  { 23,            8, GREGS,  23 * 8, 8, 8, 0 },      /* s7 */
  { 24,            8, GREGS,  24 * 8, 8, 8, 0 },      /* t8 */
  { 25,            8, GREGS,  25 * 8, 8, 8, 0 },      /* t9 */
  { 26,            8, GREGS,  26 * 8, 8, 8, 0 },      /* k0 */
  { 27,            8, GREGS,  27 * 8, 8, 8, 0 },      /* k1 */
  { 28,            8, GREGS,  28 * 8, 8, 8, 0 },      /* gp */
  { 29,            8, GREGS,  29 * 8, 8, 8, 0 },      /* sp */
  { 30,            8, GREGS,  30 * 8, 8, 8, 0 },      /* s8/fp */
  { 31,            8, GREGS,  31 * 8, 8, 8, 0 },      /* ra */
  { 0,             8, NOREGS, 0,      8, 8, 0 },      /* sr */
  { 68,            8, GREGS,  33 * 8, 8, 8, 0 },      /* lo */
  { 67,            8, GREGS,  32 * 8, 8, 8, 0 },      /* hi */

  /* glibc's ucontext.h doesn't specify the order of the following
     three registerss.  But there is space allocated for them.  (Well,
     for something, anyway - the g_pad[] array is has three elements.)
     We use the same order for these fields as that specified in the
     kernel header for elf_gregset_t; see the EF_ constants in
     asm-mips/reg.h.  Note, however, that the kernel header sandwiches
     the status register (sr, above) in between ``bad'' and ``cause''.  */

#if 0
  /* CAUSE and BADVADDR are readable via ptrace, but they're not writable.  */
  { 66,            8, GREGS,  35 * 8, 8, 8, 0 },      /* bad */
  { 65,            8, GREGS,  36 * 8, 8, 8, 0 },      /* cause */
#else
  { 0,             8, NOREGS, 0,      8, 8, 0 },      /* bad */
  { 0,             8, NOREGS, 0,      8, 8, 0 },      /* cause */
#endif
  { 64,            8, GREGS,  34 * 8, 8, 8, 0 },      /* pc */

  /* Linux/MIPS floating point is a bit of a mess.  On the one hand,
     the elf_fpregset_t contains space for 32 doubles plus the control
     word.  But on the other hand, the ptrace interface is only able to
     fetch the 32 32-bit wide registers.  This means that we only get
     16 double precision floats via ptrace().  It also means that only
     slightly more than half of elf_fpregset_t is unused.  */

  { 32       + 0,  8, FPREGS, 0 * 8,  8, 8, 0 },      /* $f0 */
  { 32       + 1,  8, FPREGS, 1 * 8,  8, 8, 0 },      /* $f1 */
  { 32       + 2,  8, FPREGS, 2 * 8,  8, 8, 0 },      /* $f2 */
  { 32       + 3,  8, FPREGS, 3 * 8,  8, 8, 0 },      /* $f3 */
  { 32       + 4,  8, FPREGS, 4 * 8,  8, 8, 0 },      /* $f4 */
  { 32       + 5,  8, FPREGS, 5 * 8,  8, 8, 0 },      /* $f5 */
  { 32       + 6,  8, FPREGS, 6 * 8,  8, 8, 0 },      /* $f6 */
  { 32       + 7,  8, FPREGS, 7 * 8,  8, 8, 0 },      /* $f7 */
  { 32       + 8,  8, FPREGS, 8 * 8,  8, 8, 0 },      /* $f8 */
  { 32       + 9,  8, FPREGS, 9 * 8,  8, 8, 0 },      /* $f9 */
  { 32       + 10, 8, FPREGS, 10 * 8, 8, 8, 0 },      /* $f10 */
  { 32       + 11, 8, FPREGS, 11 * 8, 8, 8, 0 },      /* $f11 */
  { 32       + 12, 8, FPREGS, 12 * 8, 8, 8, 0 },      /* $f12 */
  { 32       + 13, 8, FPREGS, 13 * 8, 8, 8, 0 },      /* $f13 */
  { 32       + 14, 8, FPREGS, 14 * 8, 8, 8, 0 },      /* $f14 */
  { 32       + 15, 8, FPREGS, 15 * 8, 8, 8, 0 },      /* $f15 */
  { 32       + 16, 8, FPREGS, 16 * 8, 8, 8, 0 },      /* $f16 */
  { 32       + 17, 8, FPREGS, 17 * 8, 8, 8, 0 },      /* $f17 */
  { 32       + 18, 8, FPREGS, 18 * 8, 8, 8, 0 },      /* $f18 */
  { 32       + 19, 8, FPREGS, 19 * 8, 8, 8, 0 },      /* $f19 */
  { 32       + 20, 8, FPREGS, 20 * 8, 8, 8, 0 },      /* $f20 */
  { 32       + 21, 8, FPREGS, 21 * 8, 8, 8, 0 },      /* $f21 */
  { 32       + 22, 8, FPREGS, 22 * 8, 8, 8, 0 },      /* $f22 */
  { 32       + 23, 8, FPREGS, 23 * 8, 8, 8, 0 },      /* $f23 */
  { 32       + 24, 8, FPREGS, 24 * 8, 8, 8, 0 },      /* $f24 */
  { 32       + 25, 8, FPREGS, 25 * 8, 8, 8, 0 },      /* $f25 */
  { 32       + 26, 8, FPREGS, 26 * 8, 8, 8, 0 },      /* $f26 */
  { 32       + 27, 8, FPREGS, 27 * 8, 8, 8, 0 },      /* $f27 */
  { 32       + 28, 8, FPREGS, 28 * 8, 8, 8, 0 },      /* $f28 */
  { 32       + 29, 8, FPREGS, 29 * 8, 8, 8, 0 },      /* $f29 */
  { 32       + 30, 8, FPREGS, 30 * 8, 8, 8, 0 },      /* $f30 */
  { 32       + 31, 8, FPREGS, 31 * 8, 8, 8, 0 },      /* $f31 */
  { 69,            8, FPREGS, 32 * 8, 4, 8, 0 },      /* fsr */
  /* The "fir" value actually ends up occupying fp_pad in the fpregset
     struct.  */
  { 70,            8, FPREGS, 33 * 8 + 4, 4, 8, 0 }    /* fir */
};

static void mips_singlestep_program (struct gdbserv *serv);

/* End of MIPS64_LINUX_TARGET */

#elif M68K_LINUX_TARGET

/* Needs to be converted to use either GETREGS_SETREGS_REGINFO or
   PEEKUSER_POKEUSER_REGINFO machinery.  */

#error m68k
enum 
{
  SIZEOF_REGMAP = 29, 		/* with FP regs */
  SIZEOF_MAPPEDREG = 4,
  NUM_REGS = 29,
  PC_REGNUM = 17,
  sign_extend = 0
};

static int regmap[SIZEOF_REGMAP] =
{
  PT_D0, PT_D1, PT_D2, PT_D3, PT_D4, PT_D5, PT_D6, PT_D7,
  PT_A0, PT_A1, PT_A2, PT_A3, PT_A4, PT_A5, PT_A6, PT_USP,
  PT_SR, PT_PC,
#if defined (PT_FP0)
  PT_FP0,  PT_FP1,  PT_FP2, PT_FP3, PT_FP4, PT_FP5, PT_FP6, PT_FP7,
  PT_FPCR, PT_FPSR, PT_FPIAR
#else
  -1,      -1,      -1,     -1,     -1,     -1,     -1,     -1,
  -1,      -1,      -1
#endif /* floating point regs */
};

extern int
is_fp_reg (int regnum)
{
  if (regnum < SIZEOF_REGMAP)
    {
      switch (regmap[regnum]) {
#if defined (PT_FP0)
      case PT_FP0: case PT_FP1: case PT_FP2: case PT_FP3:
      case PT_FP4: case PT_FP5: case PT_FP6: case PT_FP7:
      case PT_FPCR: case PT_FPSR: case PT_FPIAR:
	return 1;
#endif
      default:
	return 0;
      }
    }
  return 0;
}

int
is_gp_reg (int regnum)
{
  return !is_fp_reg (regnum);
}

int
is_extended_reg (int regnum)
{
  return 0;
}

/* End of M68_LINUX_TARGET */

#elif defined (PPC_LINUX_TARGET)

#define PEEKUSER_POKEUSER_REGINFO 1

enum
{
  NUM_REGS = 71,
  PC_REGNUM = 64,
  sign_extend = 0
};

static struct peekuser_pokeuser_reginfo reginfo[] =
{
  { PT_R0 * 4,          4, GREGS,  PT_R0 * 4,  4, 4, 0 },
  { PT_R1 * 4,          4, GREGS,  PT_R1 * 4,  4, 4, 0 },
  { PT_R2 * 4,          4, GREGS,  PT_R2 * 4,  4, 4, 0 },
  { PT_R3 * 4,          4, GREGS,  PT_R3 * 4,  4, 4, 0 },
  { PT_R4 * 4,          4, GREGS,  PT_R4 * 4,  4, 4, 0 },
  { PT_R5 * 4,          4, GREGS,  PT_R5 * 4,  4, 4, 0 },
  { PT_R6 * 4,          4, GREGS,  PT_R6 * 4,  4, 4, 0 },
  { PT_R7 * 4,          4, GREGS,  PT_R7 * 4,  4, 4, 0 },
  { PT_R8 * 4,          4, GREGS,  PT_R8 * 4,  4, 4, 0 },
  { PT_R9 * 4,          4, GREGS,  PT_R9 * 4,  4, 4, 0 },
  { PT_R10 * 4,         4, GREGS,  PT_R10 * 4, 4, 4, 0 },
  { PT_R11 * 4,         4, GREGS,  PT_R11 * 4, 4, 4, 0 },
  { PT_R12 * 4,         4, GREGS,  PT_R12 * 4, 4, 4, 0 },
  { PT_R13 * 4,         4, GREGS,  PT_R13 * 4, 4, 4, 0 },
  { PT_R14 * 4,         4, GREGS,  PT_R14 * 4, 4, 4, 0 },
  { PT_R15 * 4,         4, GREGS,  PT_R15 * 4, 4, 4, 0 },
  { PT_R16 * 4,         4, GREGS,  PT_R16 * 4, 4, 4, 0 },
  { PT_R17 * 4,         4, GREGS,  PT_R17 * 4, 4, 4, 0 },
  { PT_R18 * 4,         4, GREGS,  PT_R18 * 4, 4, 4, 0 },
  { PT_R19 * 4,         4, GREGS,  PT_R19 * 4, 4, 4, 0 },
  { PT_R20 * 4,         4, GREGS,  PT_R20 * 4, 4, 4, 0 },
  { PT_R21 * 4,         4, GREGS,  PT_R21 * 4, 4, 4, 0 },
  { PT_R22 * 4,         4, GREGS,  PT_R22 * 4, 4, 4, 0 },
  { PT_R23 * 4,         4, GREGS,  PT_R23 * 4, 4, 4, 0 },
  { PT_R24 * 4,         4, GREGS,  PT_R24 * 4, 4, 4, 0 },
  { PT_R25 * 4,         4, GREGS,  PT_R25 * 4, 4, 4, 0 },
  { PT_R26 * 4,         4, GREGS,  PT_R26 * 4, 4, 4, 0 },
  { PT_R27 * 4,         4, GREGS,  PT_R27 * 4, 4, 4, 0 },
  { PT_R28 * 4,         4, GREGS,  PT_R28 * 4, 4, 4, 0 },
  { PT_R29 * 4,         4, GREGS,  PT_R29 * 4, 4, 4, 0 },
  { PT_R30 * 4,         4, GREGS,  PT_R30 * 4, 4, 4, 0 },
  { PT_R31 * 4,         4, GREGS,  PT_R31 * 4, 4, 4, 0 },
  { (PT_FPR0 + 0) * 4,  8, FPREGS, 0 * 4,      8, 8, 0 },
  { (PT_FPR0 + 2) * 4,  8, FPREGS, 2 * 4,      8, 8, 0 },
  { (PT_FPR0 + 4) * 4,  8, FPREGS, 4 * 4,      8, 8, 0 },
  { (PT_FPR0 + 6) * 4,  8, FPREGS, 6 * 4,      8, 8, 0 },
  { (PT_FPR0 + 8) * 4,  8, FPREGS, 8 * 4,      8, 8, 0 },
  { (PT_FPR0 + 10) * 4, 8, FPREGS, 10 * 4,     8, 8, 0 },
  { (PT_FPR0 + 12) * 4, 8, FPREGS, 12 * 4,     8, 8, 0 },
  { (PT_FPR0 + 14) * 4, 8, FPREGS, 14 * 4,     8, 8, 0 },
  { (PT_FPR0 + 16) * 4, 8, FPREGS, 16 * 4,     8, 8, 0 },
  { (PT_FPR0 + 18) * 4, 8, FPREGS, 18 * 4,     8, 8, 0 },
  { (PT_FPR0 + 20) * 4, 8, FPREGS, 20 * 4,     8, 8, 0 },
  { (PT_FPR0 + 22) * 4, 8, FPREGS, 22 * 4,     8, 8, 0 },
  { (PT_FPR0 + 24) * 4, 8, FPREGS, 24 * 4,     8, 8, 0 },
  { (PT_FPR0 + 26) * 4, 8, FPREGS, 26 * 4,     8, 8, 0 },
  { (PT_FPR0 + 28) * 4, 8, FPREGS, 28 * 4,     8, 8, 0 },
  { (PT_FPR0 + 30) * 4, 8, FPREGS, 30 * 4,     8, 8, 0 },
  { (PT_FPR0 + 32) * 4, 8, FPREGS, 32 * 4,     8, 8, 0 },
  { (PT_FPR0 + 34) * 4, 8, FPREGS, 34 * 4,     8, 8, 0 },
  { (PT_FPR0 + 36) * 4, 8, FPREGS, 36 * 4,     8, 8, 0 },
  { (PT_FPR0 + 38) * 4, 8, FPREGS, 38 * 4,     8, 8, 0 },
  { (PT_FPR0 + 40) * 4, 8, FPREGS, 40 * 4,     8, 8, 0 },
  { (PT_FPR0 + 42) * 4, 8, FPREGS, 42 * 4,     8, 8, 0 },
  { (PT_FPR0 + 44) * 4, 8, FPREGS, 44 * 4,     8, 8, 0 },
  { (PT_FPR0 + 46) * 4, 8, FPREGS, 46 * 4,     8, 8, 0 },
  { (PT_FPR0 + 48) * 4, 8, FPREGS, 48 * 4,     8, 8, 0 },
  { (PT_FPR0 + 50) * 4, 8, FPREGS, 50 * 4,     8, 8, 0 },
  { (PT_FPR0 + 52) * 4, 8, FPREGS, 52 * 4,     8, 8, 0 },
  { (PT_FPR0 + 54) * 4, 8, FPREGS, 54 * 4,     8, 8, 0 },
  { (PT_FPR0 + 56) * 4, 8, FPREGS, 56 * 4,     8, 8, 0 },
  { (PT_FPR0 + 58) * 4, 8, FPREGS, 58 * 4,     8, 8, 0 },
  { (PT_FPR0 + 60) * 4, 8, FPREGS, 60 * 4,     8, 8, 0 },
  { (PT_FPR0 + 62) * 4, 8, FPREGS, 62 * 4,     8, 8, 0 },
  { PT_NIP * 4,         4, GREGS,  PT_NIP * 4, 4, 4, 0 },
  { PT_MSR * 4,         4, GREGS,  PT_MSR * 4, 4, 4, 0 },
  { PT_CCR * 4,         4, GREGS,  PT_CCR * 4, 4, 4, 0 },
  { PT_LNK * 4,         4, GREGS,  PT_LNK * 4, 4, 4, 0 },
  { PT_CTR * 4,         4, GREGS,  PT_CTR * 4, 4, 4, 0 },
  { PT_XER * 4,         4, GREGS,  PT_XER * 4, 4, 4, 0 }
#ifdef PT_MQ
, { PT_MQ * 4,          4, GREGS,  PT_MQ * 4,  4, 4, 0 }
#endif
};

/* End of PPC_LINUX_TARGET */
#elif defined (ALPHA_LINUX_TARGET)

/* Needs to be converted to use either GETREGS_SETREGS_REGINFO or
   PEEKUSER_POKEUSER_REGINFO machinery.  */

enum 
{
  SIZEOF_REGMAP = 66, 
  SIZEOF_MAPPEDREG = 8,
  NUM_REGS = 66,
  PC_REGNUM = 64,
  sign_extend = 0
};

static int regmap[SIZEOF_REGMAP] = 
{
  EF_V0,  EF_T0,  EF_T1, EF_T2,  EF_T3, EF_T4, EF_T5, EF_T6, 
  EF_T7,  EF_S0,  EF_S1, EF_S2,  EF_S3, EF_S4, EF_S5, EF_S6, 
  EF_A0,  EF_A1,  EF_A2, EF_A3,  EF_A4, EF_A5, EF_T8, EF_T9, 
  EF_T10, EF_T11, EF_RA, EF_T12, EF_AT, EF_GP, EF_SP, -1, /* zero */
  /* f0   f1      f2     f3      f4     f5     f6     f7          */
  -1,     -1,     -1,    -1,     -1,    -1,    -1,    -1, 
  /* f8   f9      f10    f11     f12    f13    f14    f15         */
  -1,     -1,     -1,    -1,     -1,    -1,    -1,    -1, 
  /* f16  f17     f18    f19     f20    f21    f22    f23         */
  -1,     -1,     -1,    -1,     -1,    -1,    -1,    -1, 
  /* f24  f25     f26    f27     f28    f29    f30    fpcr        */
  -1,     -1,     -1,    -1,     -1,    -1,    -1,    -1, 
  EF_PC,  -1   /* vpf */
};

int
is_fp_reg (int regnum)
{
  if (regnum >= 32 && regnum < 64)
    return 1;
  else 
    return 0;
}

int
is_gp_reg (int regnum)
{
  return !is_fp_reg (regnum);
}

int
is_extended_reg (int regnum)
{
  return 0;
}

/* End of ALPHA_LINUX_TARGET */
#elif defined(FRV_LINUX_TARGET)

#define PEEKUSER_POKEUSER_REGINFO 1

enum
{
  NUM_REGS = 166,
  PC_REGNUM = 128,
  sign_extend = 0
};

#define greg_offset_and_size(FIELD) GREGS, offsetof (struct user_int_regs, FIELD), fieldsize (struct user_int_regs, FIELD)
#define fpreg_offset_and_size(FIELD) FPREGS, offsetof (struct user_fpmedia_regs, FIELD), fieldsize (struct user_fpmedia_regs, FIELD)
#define noreg_offset_and_size(FIELD) NOREGS, 0, 0

static int frv_fdpic_loadmap_addresses (struct gdbserv *, int, int, void *,
                                        const void *);
static int frv_read_only_register (struct gdbserv *, int, int, void *,
                                   const void *);

static struct peekuser_pokeuser_reginfo reginfo[] =
{
  { PT_GR(0) * 4,   4, greg_offset_and_size (gr[0]),   4, 0 },
  { PT_GR(1) * 4,   4, greg_offset_and_size (gr[1]),   4, 0 },
  { PT_GR(2) * 4,   4, greg_offset_and_size (gr[2]),   4, 0 },
  { PT_GR(3) * 4,   4, greg_offset_and_size (gr[3]),   4, 0 },
  { PT_GR(4) * 4,   4, greg_offset_and_size (gr[4]),   4, 0 },
  { PT_GR(5) * 4,   4, greg_offset_and_size (gr[5]),   4, 0 },
  { PT_GR(6) * 4,   4, greg_offset_and_size (gr[6]),   4, 0 },
  { PT_GR(7) * 4,   4, greg_offset_and_size (gr[7]),   4, 0 },
  { PT_GR(8) * 4,   4, greg_offset_and_size (gr[8]),   4, 0 },
  { PT_GR(9) * 4,   4, greg_offset_and_size (gr[9]),   4, 0 },
  { PT_GR(10) * 4,  4, greg_offset_and_size (gr[10]),  4, 0 },
  { PT_GR(11) * 4,  4, greg_offset_and_size (gr[11]),  4, 0 },
  { PT_GR(12) * 4,  4, greg_offset_and_size (gr[12]),  4, 0 },
  { PT_GR(13) * 4,  4, greg_offset_and_size (gr[13]),  4, 0 },
  { PT_GR(14) * 4,  4, greg_offset_and_size (gr[14]),  4, 0 },
  { PT_GR(15) * 4,  4, greg_offset_and_size (gr[15]),  4, 0 },
  { PT_GR(16) * 4,  4, greg_offset_and_size (gr[16]),  4, 0 },
  { PT_GR(17) * 4,  4, greg_offset_and_size (gr[17]),  4, 0 },
  { PT_GR(18) * 4,  4, greg_offset_and_size (gr[18]),  4, 0 },
  { PT_GR(19) * 4,  4, greg_offset_and_size (gr[19]),  4, 0 },
  { PT_GR(20) * 4,  4, greg_offset_and_size (gr[20]),  4, 0 },
  { PT_GR(21) * 4,  4, greg_offset_and_size (gr[21]),  4, 0 },
  { PT_GR(22) * 4,  4, greg_offset_and_size (gr[22]),  4, 0 },
  { PT_GR(23) * 4,  4, greg_offset_and_size (gr[23]),  4, 0 },
  { PT_GR(24) * 4,  4, greg_offset_and_size (gr[24]),  4, 0 },
  { PT_GR(25) * 4,  4, greg_offset_and_size (gr[25]),  4, 0 },
  { PT_GR(26) * 4,  4, greg_offset_and_size (gr[26]),  4, 0 },
  { PT_GR(27) * 4,  4, greg_offset_and_size (gr[27]),  4, 0 },
  { PT_GR(28) * 4,  4, greg_offset_and_size (gr[28]),  4, 0 },
  { PT_GR(29) * 4,  4, greg_offset_and_size (gr[29]),  4, 0 },
  { PT_GR(30) * 4,  4, greg_offset_and_size (gr[30]),  4, 0 },
  { PT_GR(31) * 4,  4, greg_offset_and_size (gr[31]),  4, 0 },
  { PT_GR(32) * 4,  4, greg_offset_and_size (gr[32]),  4, 0 },
  { PT_GR(33) * 4,  4, greg_offset_and_size (gr[33]),  4, 0 },
  { PT_GR(34) * 4,  4, greg_offset_and_size (gr[34]),  4, 0 },
  { PT_GR(35) * 4,  4, greg_offset_and_size (gr[35]),  4, 0 },
  { PT_GR(36) * 4,  4, greg_offset_and_size (gr[36]),  4, 0 },
  { PT_GR(37) * 4,  4, greg_offset_and_size (gr[37]),  4, 0 },
  { PT_GR(38) * 4,  4, greg_offset_and_size (gr[38]),  4, 0 },
  { PT_GR(39) * 4,  4, greg_offset_and_size (gr[39]),  4, 0 },
  { PT_GR(40) * 4,  4, greg_offset_and_size (gr[40]),  4, 0 },
  { PT_GR(41) * 4,  4, greg_offset_and_size (gr[41]),  4, 0 },
  { PT_GR(42) * 4,  4, greg_offset_and_size (gr[42]),  4, 0 },
  { PT_GR(43) * 4,  4, greg_offset_and_size (gr[43]),  4, 0 },
  { PT_GR(44) * 4,  4, greg_offset_and_size (gr[44]),  4, 0 },
  { PT_GR(45) * 4,  4, greg_offset_and_size (gr[45]),  4, 0 },
  { PT_GR(46) * 4,  4, greg_offset_and_size (gr[46]),  4, 0 },
  { PT_GR(47) * 4,  4, greg_offset_and_size (gr[47]),  4, 0 },
  { PT_GR(48) * 4,  4, greg_offset_and_size (gr[48]),  4, 0 },
  { PT_GR(49) * 4,  4, greg_offset_and_size (gr[49]),  4, 0 },
  { PT_GR(50) * 4,  4, greg_offset_and_size (gr[50]),  4, 0 },
  { PT_GR(51) * 4,  4, greg_offset_and_size (gr[51]),  4, 0 },
  { PT_GR(52) * 4,  4, greg_offset_and_size (gr[52]),  4, 0 },
  { PT_GR(53) * 4,  4, greg_offset_and_size (gr[53]),  4, 0 },
  { PT_GR(54) * 4,  4, greg_offset_and_size (gr[54]),  4, 0 },
  { PT_GR(55) * 4,  4, greg_offset_and_size (gr[55]),  4, 0 },
  { PT_GR(56) * 4,  4, greg_offset_and_size (gr[56]),  4, 0 },
  { PT_GR(57) * 4,  4, greg_offset_and_size (gr[57]),  4, 0 },
  { PT_GR(58) * 4,  4, greg_offset_and_size (gr[58]),  4, 0 },
  { PT_GR(59) * 4,  4, greg_offset_and_size (gr[59]),  4, 0 },
  { PT_GR(60) * 4,  4, greg_offset_and_size (gr[60]),  4, 0 },
  { PT_GR(61) * 4,  4, greg_offset_and_size (gr[61]),  4, 0 },
  { PT_GR(62) * 4,  4, greg_offset_and_size (gr[62]),  4, 0 },
  { PT_GR(63) * 4,  4, greg_offset_and_size (gr[63]),  4, 0 },


  { PT_FR(0) * 4,   4, fpreg_offset_and_size (fr[0]), 4, 0 },
  { PT_FR(1) * 4,   4, fpreg_offset_and_size (fr[1]),  4, 0 },
  { PT_FR(2) * 4,   4, fpreg_offset_and_size (fr[2]),  4, 0 },
  { PT_FR(3) * 4,   4, fpreg_offset_and_size (fr[3]),  4, 0 },
  { PT_FR(4) * 4,   4, fpreg_offset_and_size (fr[4]),  4, 0 },
  { PT_FR(5) * 4,   4, fpreg_offset_and_size (fr[5]),  4, 0 },
  { PT_FR(6) * 4,   4, fpreg_offset_and_size (fr[6]),  4, 0 },
  { PT_FR(7) * 4,   4, fpreg_offset_and_size (fr[7]),  4, 0 },
  { PT_FR(8) * 4,   4, fpreg_offset_and_size (fr[8]),  4, 0 },
  { PT_FR(9) * 4,   4, fpreg_offset_and_size (fr[9]),  4, 0 },
  { PT_FR(10) * 4,  4, fpreg_offset_and_size (fr[10]), 4, 0 },
  { PT_FR(11) * 4,  4, fpreg_offset_and_size (fr[11]), 4, 0 },
  { PT_FR(12) * 4,  4, fpreg_offset_and_size (fr[12]), 4, 0 },
  { PT_FR(13) * 4,  4, fpreg_offset_and_size (fr[13]), 4, 0 },
  { PT_FR(14) * 4,  4, fpreg_offset_and_size (fr[14]), 4, 0 },
  { PT_FR(15) * 4,  4, fpreg_offset_and_size (fr[15]), 4, 0 },
  { PT_FR(16) * 4,  4, fpreg_offset_and_size (fr[16]), 4, 0 },
  { PT_FR(17) * 4,  4, fpreg_offset_and_size (fr[17]), 4, 0 },
  { PT_FR(18) * 4,  4, fpreg_offset_and_size (fr[18]), 4, 0 },
  { PT_FR(19) * 4,  4, fpreg_offset_and_size (fr[19]), 4, 0 },
  { PT_FR(20) * 4,  4, fpreg_offset_and_size (fr[20]), 4, 0 },
  { PT_FR(21) * 4,  4, fpreg_offset_and_size (fr[21]), 4, 0 },
  { PT_FR(22) * 4,  4, fpreg_offset_and_size (fr[22]), 4, 0 },
  { PT_FR(23) * 4,  4, fpreg_offset_and_size (fr[23]), 4, 0 },
  { PT_FR(24) * 4,  4, fpreg_offset_and_size (fr[24]), 4, 0 },
  { PT_FR(25) * 4,  4, fpreg_offset_and_size (fr[25]), 4, 0 },
  { PT_FR(26) * 4,  4, fpreg_offset_and_size (fr[26]), 4, 0 },
  { PT_FR(27) * 4,  4, fpreg_offset_and_size (fr[27]), 4, 0 },
  { PT_FR(28) * 4,  4, fpreg_offset_and_size (fr[28]), 4, 0 },
  { PT_FR(29) * 4,  4, fpreg_offset_and_size (fr[29]), 4, 0 },
  { PT_FR(30) * 4,  4, fpreg_offset_and_size (fr[30]), 4, 0 },
  { PT_FR(31) * 4,  4, fpreg_offset_and_size (fr[31]), 4, 0 },
  { PT_FR(32) * 4,  4, fpreg_offset_and_size (fr[32]), 4, 0 },
  { PT_FR(33) * 4,  4, fpreg_offset_and_size (fr[33]), 4, 0 },
  { PT_FR(34) * 4,  4, fpreg_offset_and_size (fr[34]), 4, 0 },
  { PT_FR(35) * 4,  4, fpreg_offset_and_size (fr[35]), 4, 0 },
  { PT_FR(36) * 4,  4, fpreg_offset_and_size (fr[36]), 4, 0 },
  { PT_FR(37) * 4,  4, fpreg_offset_and_size (fr[37]), 4, 0 },
  { PT_FR(38) * 4,  4, fpreg_offset_and_size (fr[38]), 4, 0 },
  { PT_FR(39) * 4,  4, fpreg_offset_and_size (fr[39]), 4, 0 },
  { PT_FR(40) * 4,  4, fpreg_offset_and_size (fr[40]), 4, 0 },
  { PT_FR(41) * 4,  4, fpreg_offset_and_size (fr[41]), 4, 0 },
  { PT_FR(42) * 4,  4, fpreg_offset_and_size (fr[42]), 4, 0 },
  { PT_FR(43) * 4,  4, fpreg_offset_and_size (fr[43]), 4, 0 },
  { PT_FR(44) * 4,  4, fpreg_offset_and_size (fr[44]), 4, 0 },
  { PT_FR(45) * 4,  4, fpreg_offset_and_size (fr[45]), 4, 0 },
  { PT_FR(46) * 4,  4, fpreg_offset_and_size (fr[46]), 4, 0 },
  { PT_FR(47) * 4,  4, fpreg_offset_and_size (fr[47]), 4, 0 },
  { PT_FR(48) * 4,  4, fpreg_offset_and_size (fr[48]), 4, 0 },
  { PT_FR(49) * 4,  4, fpreg_offset_and_size (fr[49]), 4, 0 },
  { PT_FR(50) * 4,  4, fpreg_offset_and_size (fr[50]), 4, 0 },
  { PT_FR(51) * 4,  4, fpreg_offset_and_size (fr[51]), 4, 0 },
  { PT_FR(52) * 4,  4, fpreg_offset_and_size (fr[52]), 4, 0 },
  { PT_FR(53) * 4,  4, fpreg_offset_and_size (fr[53]), 4, 0 },
  { PT_FR(54) * 4,  4, fpreg_offset_and_size (fr[54]), 4, 0 },
  { PT_FR(55) * 4,  4, fpreg_offset_and_size (fr[55]), 4, 0 },
  { PT_FR(56) * 4,  4, fpreg_offset_and_size (fr[56]), 4, 0 },
  { PT_FR(57) * 4,  4, fpreg_offset_and_size (fr[57]), 4, 0 },
  { PT_FR(58) * 4,  4, fpreg_offset_and_size (fr[58]), 4, 0 },
  { PT_FR(59) * 4,  4, fpreg_offset_and_size (fr[59]), 4, 0 },
  { PT_FR(60) * 4,  4, fpreg_offset_and_size (fr[60]), 4, 0 },
  { PT_FR(61) * 4,  4, fpreg_offset_and_size (fr[61]), 4, 0 },
  { PT_FR(62) * 4,  4, fpreg_offset_and_size (fr[62]), 4, 0 },
  { PT_FR(63) * 4,  4, fpreg_offset_and_size (fr[63]), 4, 0 },

  { PT_PC * 4,      4, greg_offset_and_size (pc),      4, 0 },
  /* The PSR is read-only.  */
  { PT_PSR * 4,     4, greg_offset_and_size (psr),     4, frv_read_only_register },
  { PT_CCR * 4,     4, greg_offset_and_size (ccr),     4, 0 },
  { PT_CCCR * 4,    4, greg_offset_and_size (cccr),    4, 0 },

  /* FDPIC "fake" registers for obtaining loadmap addresses:
     FDPIC_INTERP and FDPIC_EXEC...  */
#define PTRACE_GETFDPIC		31
#define PTRACE_GETFDPIC_EXEC	0
#define PTRACE_GETFDPIC_INTERP	1
  { PTRACE_GETFDPIC_EXEC, 4, OTHERREGS, 0, 0, 4, frv_fdpic_loadmap_addresses },
  { PTRACE_GETFDPIC_INTERP, 4, OTHERREGS, 0, 0, 4, frv_fdpic_loadmap_addresses },

  /* 134 is unspecified.  */
  { 0,              0, noreg_offset_and_size (134),    4, 0 },

  /* tbr */
  { 0,              0, noreg_offset_and_size (135),    4, 0 },

  /* brr */
  { 0,              0, noreg_offset_and_size (136),    4, 0 },

  /* dbar0 - dbar3 */
  { 0,              0, noreg_offset_and_size (137),    4, 0 },
  { 0,              0, noreg_offset_and_size (138),    4, 0 },
  { 0,              0, noreg_offset_and_size (139),    4, 0 },
  { 0,              0, noreg_offset_and_size (140),    4, 0 },

  /* 141 - 144 are unspecified.  */
  { 0,              0, noreg_offset_and_size (141),    4, 0 },
  { 0,              0, noreg_offset_and_size (142),    4, 0 },
  { 0,              0, noreg_offset_and_size (143),    4, 0 },
  { 0,              0, noreg_offset_and_size (144),    4, 0 },

  { PT_LR * 4,      4, greg_offset_and_size (lr),      4, 0 },
  { PT_LCR * 4,     4, greg_offset_and_size (lcr),     4, 0 },

  /* Can't use greg_offset_and_size for iacc0h and iacc0l because the iacc
     field is 64-bits wide.  We need to provide access to the individual
     32-bit halves. */
  { PT_IACC0H * 4,  4, GREGS, offsetof (struct user_int_regs, iacc[0]), 4, 4, 0 },
  { PT_IACC0L * 4,  4, GREGS, offsetof (struct user_int_regs, iacc[0]) + 4, 4, 4, 0 },
  { PT_FSR(0) * 4,  4, fpreg_offset_and_size (fsr[0]), 4, 0 },
  { PT_ACC(0) * 4,  4, fpreg_offset_and_size (acc[0]), 4, 0 },
  { PT_ACC(1) * 4,  4, fpreg_offset_and_size (acc[1]), 4, 0 },
  { PT_ACC(2) * 4,  4, fpreg_offset_and_size (acc[2]), 4, 0 },
  { PT_ACC(3) * 4,  4, fpreg_offset_and_size (acc[3]), 4, 0 },
  { PT_ACC(4) * 4,  4, fpreg_offset_and_size (acc[4]), 4, 0 },
  { PT_ACC(5) * 4,  4, fpreg_offset_and_size (acc[5]), 4, 0 },
  { PT_ACC(6) * 4,  4, fpreg_offset_and_size (acc[6]), 4, 0 },
  { PT_ACC(7) * 4,  4, fpreg_offset_and_size (acc[7]), 4, 0 },

  /* For the one-byte ACCG regs, ptrace() fetches four regs at a time,
     but the user_fpmedia_regs struct breaks the regs out into an array
     of bytes.  Thus, we can't use the fpreg_offset_and_size macro.  */
  { PT_ACCG(0) * 4, 4, FPREGS, offsetof (struct user_fpmedia_regs, acc[0]), 4, 4, 0 },
  { PT_ACCG(1) * 4, 4, FPREGS, offsetof (struct user_fpmedia_regs, acc[4]), 4, 4, 0 },

  { PT_MSR(0) * 4,  4, fpreg_offset_and_size (msr[0]), 4, 0 },
  { PT_MSR(1) * 4,  4, fpreg_offset_and_size (msr[0]), 4, 0 },
  
  { PT_GNER0 * 4,   4, greg_offset_and_size (gner[0]), 4, 0 },
  { PT_GNER1 * 4,   4, greg_offset_and_size (gner[1]), 4, 0 },

  { PT_FNER(0) * 4, 4, fpreg_offset_and_size (fner[0]), 4, 0 },
  { PT_FNER(1) * 4, 4, fpreg_offset_and_size (fner[1]), 4, 0 },
};

int
frv_fdpic_loadmap_addresses (struct gdbserv *serv, int pid, int regno,
                             void *read_buf, const void *write_buf)
{
  /* We can only read the load map addresses; writing them is not supported.  */
  if (read_buf != NULL)
    {
      unsigned long val;
      long status;
      struct child_process *process = gdbserv_target_data (serv);

      status = ptrace (PTRACE_GETFDPIC, pid,
                      (void *)reginfo[regno].ptrace_offset,
		      &val);
      if (process->debug_backend)
	fprintf (stderr, "PTRACE_GETFDPIC pid=%d offset=%d val=%lx\n",
	         pid, reginfo[regno].ptrace_offset, val);
      if (status < 0)
	return errno;
      else
	{
	  memcpy (read_buf, &val, sizeof val);
	  return 0;
	}
    }
  return 0;
}

int
frv_read_only_register (struct gdbserv *serv, int pid, int regno,
                        void *read_buf, const void *write_buf)
{
  if (read_buf != NULL)
    {
      return ptrace_read_user (serv, pid, reginfo[regno].ptrace_offset,
                               reginfo[regno].ptrace_size, read_buf);
    }
  return 0;
}


/* Breakpoint methods for the frv.  These use the stock breakpoint
   code.

   Although the FRV actually does require a custom breakpoint
   implementation (you can only set breakpoints on the first
   instruction in a VLIW bundle), we punt that for now: the only
   client of this breakpoint code at the moment is thread-db.c, which
   always sets breakpoints at function entry points, which are
   guaranteed to be the start of a bundle.  */

/* frv breakpoints tables are just stock breakpoint tables.  But we
   like static typechecking; casts swallow error messages.  */
static struct arch_bp_table *
stock_table_to_frv (struct stock_bp_table *table)
{
  return (struct arch_bp_table *) table;
}

static struct stock_bp_table *
frv_table_to_stock (struct arch_bp_table *table)
{
  return (struct stock_bp_table *) table;
}

/* frv breakpoints are just stock breakpoints.  But we like static
   typechecking; casts swallow error messages.  */
static struct arch_bp *
stock_bp_to_frv (struct stock_bp *bp)
{
  return (struct arch_bp *) bp;
}

static struct stock_bp *
frv_bp_to_stock (struct arch_bp *bp)
{
  return (struct stock_bp *) bp;
}

struct arch_bp_table *
frv_make_bp_table (struct arch *arch,
		   struct gdbserv *serv,
		   struct gdbserv_target *target)
{
  static unsigned char breakpoint[] = {0xc0, 0x70, 0x00, 0x01};
  struct stock_bp_table *table = stock_bp_make_table (serv, target);

  stock_bp_set_bp_insn (table, sizeof (breakpoint), breakpoint);

  return stock_table_to_frv (table);
}


static struct arch_bp *
frv_set_bp (struct arch_bp_table *table,
	    struct gdbserv_reg *addr)
{
  /* frv arch breakpoints are just stock breakpoints.  */
  return stock_bp_to_frv (stock_bp_set_bp (frv_table_to_stock (table),
					   addr));
}


static int
frv_delete_bp (struct arch_bp *bp)
{
  return stock_bp_delete_bp (frv_bp_to_stock (bp));
}


static int
frv_bp_hit_p (struct gdbserv_thread *thread,
	      struct arch_bp *arch_bp)
{
  struct stock_bp *bp = frv_bp_to_stock (arch_bp);
  struct stock_bp_table *table = stock_bp_table (bp);
  struct gdbserv *serv = stock_bp_table_serv (table);
  struct gdbserv_target *target = stock_bp_table_target (table);
  struct gdbserv_reg bp_addr, pc;
  unsigned long bp_addr_int, pc_int;

  stock_bp_addr (&bp_addr, bp);
  gdbserv_reg_to_ulong (serv, &bp_addr, &bp_addr_int);
  target->get_thread_reg (serv, thread, PC_REGNUM, &pc);
  gdbserv_reg_to_ulong (serv, &pc, &pc_int);

  return bp_addr_int == pc_int;
}


/* Construct an architecture object for the frv.  */
static struct arch *
frv_make_arch (void)
{
  struct arch *a = allocate_empty_arch ();

  a->closure = 0;		/* No closure needed at the moment.  */
  a->make_bp_table = frv_make_bp_table;
  a->set_bp = frv_set_bp;
  a->delete_bp = frv_delete_bp;
  a->bp_hit_p = frv_bp_hit_p;

  return a;
}

#define MAKE_ARCH() (frv_make_arch ())

/* End of FRV_LINUX_TARGET */
#else
#error Need a _LINUX_TARGET define for your architecture
#endif

/* The following functions should work either PEEKUSER_POKEUSER_REGINFO,
   GETREGS_SETREGS_REGINFO, or the old mechanism.  */

/* Function: next_gg_reg
   This generic version useful only for targets whose
   register numbers are the same as their position in the g/G packet.
   Return next register number or -1 for end. */

static int
linux_next_gg_reg (struct gdbserv *serv, 
			   struct gdbserv_thread *thread, 
			   int lastreg)
{
  /* This function is an iterator.
     If called with -1, it returns the first register number.
     Else it returns the next register number until there are no more, 
     whereupon it returns -1.  */

  if (lastreg < 0)
    return 0;
  else if (lastreg >= NUM_REGS - 1)
    return -1;
  else 
    return lastreg + 1;
}

/* Function: gg_reg_nr
   This generic version useful only for targets whose
   register numbers are the same as their position in the g/G packet.
   Return register number or -1 for a bad index. */

static int
linux_gg_reg_nr (struct gdbserv *serv, int index)
{
  /* This function returns the register number of the "i'th" register
     in the g/G packet.  In the default case that's just i. */

  if (index >= 0 && index < NUM_REGS)
    return index;
  else
    return -1;
}

/* Function: get_xregsetsize
   Fetch the size of the extended register set.  */

static int
get_xregsetsize (struct gdbserv *serv, int pid)
{
#if defined (X86_LINUX_TARGET)
  return sizeof (elf_fpxregset_t);
#else
  return -1;
#endif
}


#if defined (PEEKUSER_POKEUSER_REGINFO) || defined (GETREGS_SETREGS_REGINFO)
/* The following functions will only work with the PEEKUSER_POKEUSER_REGINFO
   and GETREGS_SETREGS_REGINFO mechanisms.  */

/* Function: reg_format
   This generic version useful only for targets whose
   registers are all the same size.
   Return zero for success, -1 for failure (never fails). */

static int
linux_reg_format (struct gdbserv *serv, 
			  struct gdbserv_thread *thread,
			  int regno, int *size, int *padding)
{
  /* Size and formatting (padding) of thread in g/G packet. */
  *size = reginfo[regno].proto_size;
  *padding = 0;
  return 0;
}

/* Function: sizeof_reg
   This generic version useful only for targets whose
   registers are all the same size.
   Returns size of a register. */
   
static long linux_sizeof_reg (struct gdbserv *serv, int regno)
{
  return reginfo[regno].proto_size;
}

/* Return 1 if REGNUM represents a general purpose register which has
   space allocated for it in GREGSET_T.  Otherwise, return 0.  */

int
is_gp_reg (int regnum)
{
  if (regnum >= 0 && regnum < NUM_REGS)
    return reginfo[regnum].whichregs == GREGS;
  else
    return 0;
}

/* Return 1 if REGNUM represents a floating point register, 0 otherwise.  
   For these purposes, floating point status registers (and perhaps certain
   other registers) are considered to be floating point registers when
   they appear in the fpregset_t struct.  */
   
int
is_fp_reg (int regnum)
{
  if (regnum >= 0 && regnum < NUM_REGS)
    return reginfo[regnum].whichregs == FPREGS;
  else
    return 0;
}

/* Return 1 if REGNUM represents a register in the extended register
   set, 0 otherwise.  The definition of what consitutes an extended
   register is implementation specific.  For x86 though, an extended
   register is one of the extended floating point registers.  */

int
is_extended_reg (int regnum)
{
  if (regnum >= 0 && regnum < NUM_REGS)
    return reginfo[regnum].whichregs == FPXREGS;
  else
    return 0;
}

#endif /* defined (PEEKUSER_POKEUSER_REGINFO) || defined (GETREGS_SETREGS_REGINFO) */

#if defined (PEEKUSER_POKEUSER_REGINFO)

/* Functions which implement the PEEKUSER_POKEUSER_REGINFO machinery...  */

/* Fetch the register indicated by REGNO into the buffer REG_BYTES.
   The caller must ensure that a sufficiently large buffer has been
   allocated.
   Returns 0 for success, -1 for failure.  */

static int
read_reg_bytes (struct gdbserv *serv, int pid, int regno, void *reg_bytes)
{
  ptrace_arg3_type regaddr;
  int regsize;
  int status;

  if (regno < 0 || regno >= NUM_REGS)
    return -1;

  if (reginfo[regno].alternate_register_read_write_method == NULL)
    {
      regaddr = reginfo[regno].ptrace_offset;
      regsize = reginfo[regno].ptrace_size;
      status = ptrace_read_user (serv, pid, regaddr, regsize, reg_bytes);
      /* A non-zero status is the errno value from the ptrace call.  */
      if (status != 0)
	{
	  fprintf (stderr, "Error: PT_READ_U at 0x%08lx in process %d\n",
		   (long) regaddr, pid);
	  return -1;
	}
    }
  else
    {
      /* Use alternate reader.  */
      status = reginfo[regno].alternate_register_read_write_method
	         (serv, pid, regno, reg_bytes, 0);
      if (status != 0)
	{
	  fprintf (stderr,
	           "read_reg_bytes: Error: Couldn't read register using alternate method, regno=%d, status=%d\n",
		   regno, status);
	  return -1;
	}
    }

  return 0;
}

/* Store the buffer REG_BYTES to the register indicated by REGNO.
   Returns 0 for success, -1 for failure.  */

static int
write_reg_bytes (struct gdbserv *serv, int pid, int regno,
                 const void *reg_bytes)
{
  ptrace_arg3_type regaddr;
  int regsize;
  int status;

  if (regno < 0 || regno >= NUM_REGS)
    return -1;

  if (reginfo[regno].alternate_register_read_write_method == NULL)
    {
      regaddr = reginfo[regno].ptrace_offset;
      regsize = reginfo[regno].ptrace_size;
      status = ptrace_write_user (serv, pid, regaddr, regsize, reg_bytes);

      /* A non-zero status is the errno value from the ptrace call */
      if (status != 0)
	{
	  fprintf (stderr, "Error: PT_WRITE_U status=%d at 0x%08lx in process %d\n",
		   status, (long) regaddr, pid);
	  return -1;
	}
    }
  else
    {
      /* Use alternate writer.  */
      status = reginfo[regno].alternate_register_read_write_method
	         (serv, pid, regno, 0, reg_bytes);
      if (status != 0)
	{
	  fprintf (stderr,
	           "write_reg_bytes: Error: Couldn't write register using alternate method, regno=%d, status=%d",
		   regno, status);
	  return -1;
	}
    }
  return 0;
}


/* Fetch and return the value of register REGNO.  Helper function for
   debug_get_pc().  This is the PEEKUSER_POKEUSER_REGINFO version.  */
static unsigned long
debug_get_reg (struct gdbserv *serv, pid_t pid, int regno)
{
  ptrace_xfer_type value;

  if (read_reg_bytes (serv, pid, regno, &value) < 0)
    return 0;
  else
    return (unsigned long) value;
}

/* Fetch and return the value of the PC.  Needed by thread-db.c.  */
unsigned long
debug_get_pc (struct gdbserv *serv, pid_t pid)
{
  return debug_get_reg (serv, pid, PC_REGNUM);
}

/* Function: get_reg
   This version is for targets for which all registers may
   be fetched using PTRACE_PEEKUSER.
   Return -1 for failure, zero for success. */

static int
linux_get_reg (struct gdbserv *serv, int regno, struct gdbserv_reg *reg)
{
  struct child_process *process = gdbserv_target_data (serv);
  char tmp_buf[MAX_REG_SIZE];
  int status;

  if (regno < 0 || regno >= NUM_REGS)
    {
      fprintf (stderr, "Error: linux_get_reg: Register %d out of bounds.\n", regno);
      return -1;
    }

  if (reginfo[regno].whichregs != NOREGS)
    {
      /* Get the register value. */
      status = read_reg_bytes (serv, process->pid, regno, tmp_buf);
      if (status < 0)
	return -1;	/* fail */
    }
  else
    memset (tmp_buf, 0, reginfo[regno].ptrace_size);

  /* Copy the bytes to the gdbserv_reg struct.  */
  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].ptrace_size,
                             reg, reginfo[regno].proto_size, sign_extend);

  return 0;	/* success */
  
}

/* Function: set_reg
   This version is for targets which are capable of setting any register
   via PTRACE_POKEUSER.
   Return -1 for failure, zero for success. */

static int
linux_set_reg (struct gdbserv *serv, int regno, struct gdbserv_reg *reg)
{
  if (regno < 0 || regno >= NUM_REGS)
    {
      fprintf (stderr, "Error: linux_set_reg: Register %d out of bounds.\n", regno);
      return -1;
    }

  if (reginfo[regno].whichregs != NOREGS)
    {
      struct child_process *process = gdbserv_target_data (serv);
      char tmp_buf[MAX_REG_SIZE];
      int status;

      /* Copy the bytes from the gdbserv_reg struct to our temporary buffer.  */
      gdbserv_host_bytes_from_reg (serv, tmp_buf, reginfo[regno].ptrace_size,
                                   reg, sign_extend);

      /* Write the child's register. */
      status = write_reg_bytes (serv, process->pid, regno, tmp_buf);
      if (status < 0)
	return -1;	/* Fail */
    }

  return 0;	/* success */
}

/* gregset functions */

/* Helper function for reg_from_gregset / reg_from_fpregset  */

int
reg_from_regset (struct gdbserv *serv, 
		 struct gdbserv_reg *reg, 
		 int regno, 
		 const void *regset,
		 enum regset whichregs)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != whichregs)
    {
      return -1;
    }

  regbytes = ((char *) regset) + reginfo[regno].regset_field_offset;

  gdbserv_host_bytes_to_reg (serv, regbytes, reginfo[regno].regset_field_size,
                             reg, reginfo[regno].proto_size, sign_extend);

  return 0;
}

/* Helper function for reg_to_gregset / reg_to_fpregset.
   Insert register into the regset indicated by WHICHREGS by REGNO.
   Return -1 for failure, zero for success. */

int
reg_to_regset (struct gdbserv *serv, 
	       const struct gdbserv_reg *reg, 
	       int regno, 
	       void *regset,
	       enum regset whichregs)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != whichregs)
    {
      return -1;
    }

  regbytes = ((char *) regset) + reginfo[regno].regset_field_offset;

  gdbserv_host_bytes_from_reg (serv, regbytes, reginfo[regno].regset_field_size,
                               reg, sign_extend);

  return 0;
}

/* Function: reg_from_gregset
   Extract register from gregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_from_gregset (struct gdbserv *serv, 
		  struct gdbserv_reg *reg, 
		  int regno, 
		  const GREGSET_T gregset)
{
  return reg_from_regset (serv, reg, regno, gregset, GREGS);
}

/* Function: reg_to_gregset
   Insert register into gregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_to_gregset (struct gdbserv *serv, 
		const struct gdbserv_reg *reg, 
		int regno, 
		GREGSET_T gregset)
{
  return reg_to_regset (serv, reg, regno, gregset, GREGS);
}

/* Function: reg_from_fpregset
   Extract register from fpregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_from_fpregset (struct gdbserv *serv, 
		   struct gdbserv_reg *reg, 
		   int regno, 
		   const FPREGSET_T *fpregset)
{
  return reg_from_regset (serv, reg, regno, fpregset, FPREGS);
}

/* Function: reg_to_fpregset
   Insert register into fpregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_to_fpregset (struct gdbserv *serv, 
		 const struct gdbserv_reg *reg, 
		 int regno, 
		 FPREGSET_T *fpregset)
{
  return reg_to_regset (serv, reg, regno, fpregset, FPREGS);
}

/* Function: reg_from_xregset
   Extract register from extended regset by regnum.
   Return -1 for failure, zero for success.  */

int
reg_from_xregset (struct gdbserv *serv, 
		  struct gdbserv_reg *reg, 
		  int regno, 
		  const void *xregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: reg_to_xregset
   Insert register into extended regset by regnum.
   Return -1 for failure, zero for success.  */

int
reg_to_xregset (struct gdbserv *serv, 
		const struct gdbserv_reg *reg, 
		int regno, 
		void *xregset)
{
  return -1;	/* Unimplemented.  */
}

/* Helper function for get_gregset / get_fpregset */

static int
get_regset (struct gdbserv *serv, int pid, void *regset,
            enum regset whichregs)
{
  int regno;

  for (regno = 0; regno < NUM_REGS; regno++)
    {
      if (reginfo[regno].whichregs == whichregs)
	{
	  char tmp_buf[MAX_REG_SIZE];
	  struct gdbserv_reg reg;
	  int status;

	  /* Get the register value. */
	  status = read_reg_bytes (serv, pid, regno, tmp_buf);
	  if (status < 0)
	    return -1;	/* fail */

	  /* Copy the bytes to the gdbserv_reg struct.  */
	  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].ptrace_size,
	                             &reg, reginfo[regno].proto_size,
				     sign_extend);

	  /* Now insert them into the regset.  */
	  reg_to_regset (serv, &reg, regno, regset, whichregs);
	}
    }

  return 0;
}
/* Helper function for put_gregset / put_fpregset.
   Write the regset indicated by WHICHREGS for PID.
   Return -1 for failure, zero for success. */

static int
put_regset (struct gdbserv *serv,
            int pid,
	    const void *regset,
            enum regset whichregs)
{
  int regno;

  for (regno = 0; regno < NUM_REGS; regno++)
    {
      if (reginfo[regno].whichregs == whichregs)
	{
	  char tmp_buf[MAX_REG_SIZE];
	  struct gdbserv_reg reg;
	  int status;

	  /* Fetch the reg from the regset.  */
	  reg_from_regset (serv, &reg, regno, regset, whichregs);

	  /* Copy the bytes from the gdbserv_reg struct to our temporary buffer.  */
	  gdbserv_host_bytes_from_reg (serv, tmp_buf,
	                               reginfo[regno].ptrace_size, &reg,
				       sign_extend);

	  /* Write the child's register. */
	  status = write_reg_bytes (serv, pid, regno, tmp_buf);
	  if (status < 0)
	    return -1;	/* Fail */
	}
    }
  return 0;
}

/* Function: get_gregset
   Read the gregset for pid.
   Return -1 for failure, zero for success. */

static int
get_gregset (struct gdbserv *serv, int pid, GREGSET_T gregset)
{
  return get_regset (serv, pid, gregset, GREGS);
}

/* Function: put_gregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_gregset (struct gdbserv *serv, int pid, const GREGSET_T gregset)
{
  return put_regset (serv, pid, gregset, GREGS);
}

static int
get_fpregset (struct gdbserv *serv, int pid, FPREGSET_T *fpregset)
{
  return get_regset (serv, pid, fpregset, FPREGS);
}

/* Function: put_fpregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_fpregset (struct gdbserv *serv, int pid, const FPREGSET_T *fpregset)
{
  return put_regset (serv, pid, fpregset, FPREGS);
}

/* Function: get_fpregset
   Read the fpregset for pid.
   Return -1 for failure, zero for success. */

static int
get_xregset (struct gdbserv *serv, int pid, void *fpregset)
{
  return -1;
}

/* Function: put_xregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_xregset (struct gdbserv *serv, int pid, const void *fpregset)
{
  return -1;
}

#elif defined (GETREGS_SETREGS_REGINFO)

/* Functions which implement the GETREGS_SETREGS_REGINFO machinery...  */

/* Forward declarations for get_gregset() and put_gregset().  */
static int get_gregset (struct gdbserv *serv, int pid, GREGSET_T gregset);
static int put_gregset (struct gdbserv *serv, int pid, const GREGSET_T gregset);

/* Fetch register REGNO as an unsigned long and return it via the REGVAL
   pointer.  Return 0 for success and -1 for failure.  */
static int
read_reg_as_ulong (struct gdbserv *serv, pid_t pid, int regno,
                   unsigned long *regval)
{
  struct gdbserv_reg reg;
  GREGSET_T gregset;
  int status;

  status = get_gregset (serv, pid, gregset);
  if (status < 0)
    return status;

  status = reg_from_gregset (serv, &reg, regno, gregset);
  if (status < 0)
    return status;

  gdbserv_reg_to_ulong (serv, &reg, regval);
  return status;
}

/* Write the unsigned long value REGVAL to register REGNO.  Return 0
   for success and -1 for failure.  */
static int
write_reg_as_ulong (struct gdbserv *serv, pid_t pid, int regno,
                    unsigned long regval)
{
  struct gdbserv_reg reg;
  GREGSET_T gregset;
  int status;

  status = get_gregset (serv, pid, gregset);
  if (status < 0)
    return status;

  gdbserv_ulong_to_reg (serv, regval, &reg);

  status = reg_to_gregset (serv, &reg, regno, gregset);
  if (status < 0)
    return status;

  status = put_gregset (serv, pid, gregset);

  return status;
}

/* Fetch and return the value of register REGNO.  Helper function for
   debug_get_pc().  This is the GETREGS_SETREGS_REGINFO version.  */
static unsigned long
debug_get_reg (struct gdbserv *serv, pid_t pid, int regno)
{
  int status;
  unsigned long regval;

  status = read_reg_as_ulong (serv, pid, regno, &regval);
  if (status < 0)
    return 0;
  else
    return regval;
}

/* Fetch and return the value of the PC.  Needed by thread-db.c.  */
unsigned long
debug_get_pc (struct gdbserv *serv, pid_t pid)
{
  return debug_get_reg (serv, pid, PC_REGNUM);
}

/* Function: get_reg
   This version is for targets which need to fetch registers
   en masse via ptrace().
   Return -1 for failure, zero for success. */

static int
linux_get_reg (struct gdbserv *serv, int regno, struct gdbserv_reg *reg)
{
  int ret;
  elf_gregset_t gregs;
  elf_fpregset_t fpregs;
  void *fpxregs;
  char *buf;

  if (regno < 0 || regno >= NUM_REGS)
    {
      fprintf (stderr, "Error: linux_get_reg: Register %d out of bounds.\n", regno);
      return -1;
    }

  /* Fetch the appropriate register set.  */
  if (reginfo[regno].whichregs == GREGS)
    {
      ret = ptrace_get_gregs (serv, 0, &gregs);
      if (ret != 0)
        {
	  /* FIXME: Do we need a perror() here?  */
	  return -1;
	}
      buf = (char *) &gregs;
    }
  else if (reginfo[regno].whichregs == FPREGS)
    {
      ret = ptrace_get_fpregs (serv, 0, &fpregs);
      if (ret != 0)
	return -1;
      buf = (char *) &fpregs;
    }
  else if (reginfo[regno].whichregs == FPXREGS)
    {
      struct child_process *process = gdbserv_target_data (serv);
      int xregsize = get_xregsetsize (serv, process->pid);

      assert (xregsize >= 0);

      fpxregs = alloca (xregsize);
      ret = ptrace_get_fpxregs (serv, 0, fpxregs);
      if (ret != 0)
	return -1;
      buf = (char *) fpxregs;
    }
  else if (reginfo[regno].whichregs == NOREGS)
    {
      /* A buffer initialized to zeros we can refer to.  */
      static struct gdbserv_reg zeros;

      /* Make sure we're not going to try to copy out more bytes than
	 we have.  */
      assert (reginfo[regno].ptrace_size <= sizeof (zeros.buf));

      /* Make sure we don't have some random offset that will take us
	 beyond the end of the buffer.  Offsets for NOREGS entries
	 should be zero.  */
      assert (reginfo[regno].offset == 0);

      buf = (char *) zeros.buf;
    }
  else
    {
      return -1;
    }

  /* Adjust buf to point at the starting byte of the register.  */
  buf += reginfo[regno].offset;

  /* Copy the bytes to the gdbserv_reg struct.  */
  gdbserv_host_bytes_to_reg (serv, buf, reginfo[regno].ptrace_size,
                             reg, reginfo[regno].proto_size, sign_extend);

  return 0;
}

/* Function: linux_set_reg
   This version is for targets which need to set registers en masse.
   Return -1 for failure, zero for success. */

static int
linux_set_reg (struct gdbserv *serv, int regno, struct gdbserv_reg *reg)
{
  int ret;
  elf_gregset_t gregs;
  elf_fpregset_t fpregs;
  void *fpxregs = NULL;
  char *buf;

  if (regno < 0 || regno >= NUM_REGS)
    {
      fprintf (stderr, "Error: linux_set_reg: Register %d out of bounds.\n", regno);
      return -1;
    }

  /* Fetch the appropriate register set.  */
  if (reginfo[regno].whichregs == GREGS)
    {
      ret = ptrace_get_gregs (serv, 0, &gregs);
      if (ret != 0)
	return ret;
      buf = (char *) &gregs;
    }
  else if (reginfo[regno].whichregs == FPREGS)
    {
      ret = ptrace_get_fpregs (serv, 0, &fpregs);
      if (ret != 0)
	return ret;
      buf = (char *) &fpregs;
    }
  else if (reginfo[regno].whichregs == FPXREGS)
    {
      struct child_process *process = gdbserv_target_data (serv);
      int xregsize = get_xregsetsize (serv, process->pid);

      assert (xregsize >= 0);

      fpxregs = alloca (xregsize);
      ret = ptrace_get_fpxregs (serv, 0, fpxregs);
      if (ret != 0)
	return ret;
      buf = (char *) fpxregs;
    }
  else if (reginfo[regno].whichregs == NOREGS)
    {
      /* Nothing to do, return immediately.  */
      return 0;
    }
  else
    {
      return -1;
    }

  /* Adjust buf to point at the starting byte of the register.  */
  buf += reginfo[regno].offset;

  /* Copy the bytes from the gdbserv_reg struct to our temporary buffer.  */
  gdbserv_host_bytes_from_reg (serv, buf, reginfo[regno].ptrace_size, reg,
                               sign_extend);

  /* Write the register set to the process.  */
  if (reginfo[regno].whichregs == GREGS)
    {
      ret = ptrace_set_gregs (serv, 0, &gregs);
      if (ret != 0)
	return ret;
    }
  else if (reginfo[regno].whichregs == FPREGS)
    {
      ret = ptrace_set_fpregs (serv, 0, &fpregs);
      if (ret != 0)
	return ret;
    }
  else if (reginfo[regno].whichregs == FPXREGS)
    {
      ret = ptrace_set_fpxregs (serv, 0, &fpxregs);
      if (ret != 0)
	return ret;
    }
  else
    {
      /* Can't happen.  */
      return -1;
    }

  return 0;
}

/* gregset functions */

/* Function: reg_from_gregset
   Extract register from gregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_from_gregset (struct gdbserv *serv, 
		  struct gdbserv_reg *reg, 
		  int regno, 
		  const GREGSET_T gregset)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != GREGS)
    {
      return -1;
    }

  regbytes = ((char *) gregset) + reginfo[regno].offset;

  gdbserv_host_bytes_to_reg (serv, regbytes, reginfo[regno].ptrace_size,
                             reg, reginfo[regno].proto_size, sign_extend);

  return 0;
}

/* Function: reg_to_gregset
   Insert register into gregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_to_gregset (struct gdbserv *serv, 
		const struct gdbserv_reg *reg, 
		int regno, 
		GREGSET_T gregset)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != GREGS)
    {
      return -1;
    }

  regbytes = ((char *) gregset) + reginfo[regno].offset;

  gdbserv_host_bytes_from_reg (serv, regbytes, reginfo[regno].ptrace_size, reg,
                               sign_extend);

  return 0;
}

/* Function: reg_from_fpregset
   Extract register from fpregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_from_fpregset (struct gdbserv *serv, 
		   struct gdbserv_reg *reg, 
		   int regno, 
		   const FPREGSET_T *fpregset)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPREGS)
    {
      return -1;
    }

  regbytes = ((char *) fpregset) + reginfo[regno].offset;

  gdbserv_host_bytes_to_reg (serv, regbytes, reginfo[regno].ptrace_size,
                             reg, reginfo[regno].proto_size, sign_extend);

  return 0;
}

/* Function: reg_to_fpregset
   Insert register into fpregset by regnum.
   Return -1 for failure, zero for success. */

int
reg_to_fpregset (struct gdbserv *serv, 
		 const struct gdbserv_reg *reg, 
		 int regno, 
		 FPREGSET_T *fpregset)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPREGS)
    {
      return -1;
    }

  regbytes = ((char *) fpregset) + reginfo[regno].offset;

  gdbserv_host_bytes_from_reg (serv, regbytes, reginfo[regno].ptrace_size, reg,
                               sign_extend);

  return 0;
}

/* Function: reg_from_xregset
   Extract register from extended regset by regnum.
   Return -1 for failure, zero for success. */

int
reg_from_xregset (struct gdbserv *serv, 
		  struct gdbserv_reg *reg, 
		  int regno, 
		  const void *xregset)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPXREGS)
    {
      return -1;
    }

  regbytes = ((char *) xregset) + reginfo[regno].offset;

  gdbserv_host_bytes_to_reg (serv, regbytes, reginfo[regno].ptrace_size,
                             reg, reginfo[regno].proto_size, sign_extend);

  return 0;
}

/* Function: reg_to_xregset
   Insert register into extended regset by regnum.
   Return -1 for failure, zero for success.  */

int
reg_to_xregset (struct gdbserv *serv, 
		const struct gdbserv_reg *reg, 
		int regno, 
		void *xregset)
{
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPXREGS)
    {
      return -1;
    }

  regbytes = ((char *) xregset) + reginfo[regno].offset;

  gdbserv_host_bytes_from_reg (serv, regbytes, reginfo[regno].ptrace_size, reg,
                               sign_extend);

  return 0;
}

/* Function: get_gregset
   Read the gregset for pid.
   Return -1 for failure, zero for success. */

static int
get_gregset (struct gdbserv *serv, int pid, GREGSET_T gregset)
{
  int status;

  status = ptrace_get_gregs (serv, pid, gregset);
  return status;
}

/* Function: put_gregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_gregset (struct gdbserv *serv, int pid, const GREGSET_T gregset)
{
  int status;

  status = ptrace_set_gregs (serv, pid, gregset);

  return status;
}

/* Function: get_fpregset
   Read the fpregset for pid.
   Return -1 for failure, zero for success. */

static int
get_fpregset (struct gdbserv *serv, int pid, FPREGSET_T *fpregset)
{
  int status;

  status = ptrace_get_fpregs (serv, pid, fpregset);
  return status;
}

/* Function: put_fpregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_fpregset (struct gdbserv *serv, int pid, const FPREGSET_T *fpregset)
{
  int status;

  status = ptrace_set_fpregs (serv, pid, fpregset);

  return status;
}

/* Function: get_fpregset
   Read the fpregset for pid.
   Return -1 for failure, zero for success. */

static int
get_xregset (struct gdbserv *serv, int pid, void *xregset)
{
  int status;

  status = ptrace_get_fpxregs (serv, pid, xregset);
  return status;
}

/* Function: put_xregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_xregset (struct gdbserv *serv, int pid, const void *xregset)
{
  int status;

  status = ptrace_set_fpxregs (serv, pid, xregset);

  return status;
}

#else /* ---------------------------------------------------------- */

/* These functions may be used for architectures whose registers
   are of uniform size and whose registers are all accessible via
   PTRACE_PEEKUSER and PTRACE_POKEUSER.  */

/* Register offset in user struct, or -1 if bad reg num.  */
static long
linux_register_offset (int regnum)
{
  if (regnum < 0 || regnum >= SIZEOF_REGMAP)
    return -1;
  else if (regmap[regnum] < 0)
    return -1;
  else
#if defined(_MIPSEL) || defined(_MIPSEB)
    /* MIPS implementations of PTRACE_PEEKUSER address register 0
       at offset 0, register 1 at offset 1, etc. Do NOT multiply
       the register number by the register size. */

    return regmap[regnum];
#else
    return SIZEOF_MAPPEDREG * regmap[regnum];
#endif
}

/* fetch registers vector.

   NOTE: registers do not generalize well in ptrace, so 
   we're gonna handle them separately per target. */


enum { U_REGS_OFFSET = 0 };	/* FIXME??? */

/* Function: linux_read_reg
   Return -1 for failure, zero for success. */

static int
linux_read_reg (struct gdbserv *serv, int pid, int regno,
                ptrace_xfer_type *regval)
{
  unsigned long u_regs_base = U_REGS_OFFSET;
  ptrace_arg3_type regaddr;

  if ((regaddr = linux_register_offset (regno)) < 0)
    return -1;	/* fail */

  regaddr += U_REGS_OFFSET;
  errno = 0;
  ptrace_read_user (serv, pid, regaddr, sizeof (*regval), regval);

  if (errno)
    {
      fprintf (stderr, "PT_READ_U 0x%08lx from 0x%08lx in process %d\n",
	       (long) *regval, (long) regaddr, pid);
      return -1;
    }
  else
    return 0;
}

/* Function: linux_write_reg
   Return -1 for failure, zero for success. */

static int
linux_write_reg (struct gdbserv *serv, int regno, ptrace_xfer_type regval)
{
  unsigned long u_regs_base = U_REGS_OFFSET;
  ptrace_arg3_type regaddr;
  struct child_process *process = gdbserv_target_data (serv);

  if ((regaddr = linux_register_offset (regno)) < 0)
    return -1;	/* fail */

  regaddr += U_REGS_OFFSET;
  errno = 0;
  ptrace_write_user (serv, process->pid, regaddr, sizeof (regval), &regval);
  if (errno)
    {
      fprintf (stderr, "PT_WRITE_U 0x%08lx from 0x%08lx in process %d\n",
	       (long) regval, (long) regaddr, process->pid);
      return -1;
    }
  else
    return 0;
}

/* Helper function for debug_get_pc().  It fetches and returns the
   value of REGNO.  */
static unsigned long
debug_get_reg (struct gdbserv *serv, pid_t pid, int regno)
{
  ptrace_xfer_type value;

  if (linux_read_reg (serv, pid, regno, &value) < 0)
    return 0;
  else
    return (unsigned long) value;
}

/* Return the value of PC.  Needed by thread-db.c.  */
unsigned long
debug_get_pc (struct gdbserv *serv, pid_t pid)
{
  return debug_get_reg (serv, pid, PC_REGNUM);
}

/* Function: reg_format

   This is an old, decrepit version that we want to eliminate.  If you
   find yourself needing to fix a bug in it, consider changing your
   target to use one of the preferred mechanisms instead.

   Return zero for success, -1 for failure (never fails). */

static int
linux_reg_format (struct gdbserv *serv, 
			  struct gdbserv_thread *thread,
			  int reg, int *size, int *padding)
{
  /* Size and formatting (padding) of thread in g/G packet. */
  *size = SIZEOF_MAPPEDREG;
  *padding = 0;
  return 0;
}

/* Function: linux_sizeof_reg

   This is an old, decrepit version that we want to eliminate.  If you
   find yourself needing to fix a bug in it, consider changing your
   target to use one of the preferred mechanisms instead.

   Returns size of a register. */
   
static long linux_sizeof_reg (struct gdbserv *serv, int regno)
{
  return SIZEOF_MAPPEDREG;
}

/* Function: linux_get_reg

   This is an old, decrepit version that we want to eliminate.  If you
   find yourself needing to fix a bug in it, consider changing your
   target to use one of the preferred mechanisms instead.

   Return -1 for failure, zero for success.  */

static int
linux_get_reg (struct gdbserv *serv, int regno, struct gdbserv_reg *reg)
{
  struct child_process *process = gdbserv_target_data (serv);
  ptrace_xfer_type regval;

  /* Get the register value. */
  if (linux_read_reg (serv, process->pid, regno, &regval) < 0)
    {
      fprintf (stderr, "Error: linux_get_reg: Register %d out of bounds.\n", regno);
      return -1;
    }

  /* Shove it into the gdbserv_reg struct. */
  if (SIZEOF_MAPPEDREG == 4)
    gdbserv_ulong_to_reg (serv, (unsigned long) regval, reg);
  else
    gdbserv_ulonglong_to_reg (serv, (unsigned long long) regval, reg);
  return 0;	/* success */
  
}

/* Function: linux_set_reg

   This is an old, decrepit version that we want to eliminate.  If you
   find yourself needing to fix a bug in it, consider changing your
   target to use one of the preferred mechanisms instead.

   Return -1 for failure, zero for success. */

static int
linux_set_reg (struct gdbserv *serv, int regno, struct gdbserv_reg *reg)
{
  ptrace_xfer_type regval;

  if (regno < 0 || regno >= NUM_REGS)
    {
      fprintf (stderr, "Error: linux_set_reg: Register %d out of bounds.\n", regno);
      return -1;
    }

  /* Get the register value out of the struct gdbserv_reg. */
  if (sizeof (regval) == 4)
    gdbserv_reg_to_ulong (serv, reg, (unsigned long *) &regval);
  else
    gdbserv_reg_to_ulonglong (serv, reg, (unsigned long long *) &regval);

  /* Write the child's register. */
  if (linux_write_reg (serv, regno, regval) < 0)
    return -1;	/* Fail */

  return 0;	/* success */
  
}

/* gregset functions */

/* Function: reg_from_gregset
   Extract register from gregset by regnum.
   Return -1 for failure, zero for success. */

extern int
reg_from_gregset (struct gdbserv *serv, 
		  struct gdbserv_reg *reg, 
		  int regno, 
		  const GREGSET_T gregset)
{
  unsigned long offset = linux_register_offset (regno);
  unsigned long long value;

  if (offset < 0)
    return -1;		/* failure */

  if (SIZEOF_MAPPEDREG == 4)
    {
      value = *((unsigned long *) (((char *) gregset) + offset));
    }
  else if (SIZEOF_MAPPEDREG == 8)
    {
      value = *((unsigned long long *) (((char *) gregset) + offset));
    }
  else
    {
      return -1;	/* failure */
    }  
  gdbserv_ulonglong_to_reg (serv, value, reg);
  return 0;
}

/* Function: reg_to_gregset
   Insert register into gregset by regnum.
   Return -1 for failure, zero for success. */

extern int
reg_to_gregset (struct gdbserv *serv, 
		const struct gdbserv_reg *reg, 
		int regno, 
		GREGSET_T gregset)
{
  unsigned long offset = linux_register_offset (regno);
  unsigned long long value;

  if (offset < 0)
    return -1;		/* failure */

  gdbserv_reg_to_ulonglong (serv, reg, &value);
  if (SIZEOF_MAPPEDREG == 4)
    {
      *((unsigned long *) (((char *) gregset) + offset)) = value;
    }
  else if (SIZEOF_MAPPEDREG == 8)
    {
      *((unsigned long long *) (((char *) gregset) + offset)) = value;
    }
  else
    {
      return -1;	/* failure */
    }
  return 0;
}

/* Function: reg_from_fpregset
   Extract register from fpregset by regnum.
   Return -1 for failure, zero for success.  */

extern int
reg_from_fpregset (struct gdbserv *serv, 
		   struct gdbserv_reg *reg, 
		   int regno, 
		   const FPREGSET_T *fpregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: reg_to_fpregset
   Insert register into fpregset by regnum.
   Return -1 for failure, zero for success. */

extern int
reg_to_fpregset (struct gdbserv *serv, 
		 const struct gdbserv_reg *reg, 
		 int regno, 
		 FPREGSET_T *fpregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: reg_from_xregset
   Extract register from extended regset by regnum.
   Return -1 for failure, zero for success.  */

int
reg_from_xregset (struct gdbserv *serv, 
		  struct gdbserv_reg *reg, 
		  int regno, 
		  const void *xregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: reg_to_xregset
   Insert register into extended regset by regnum.
   Return -1 for failure, zero for success.  */

int
reg_to_xregset (struct gdbserv *serv, 
		const struct gdbserv_reg *reg, 
		int regno, 
		void *xregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: get_gregset
   Read the gregset for pid.
   Return -1 for failure, zero for success. */

static int
get_gregset (struct gdbserv *serv, int pid, GREGSET_T gregset)
{
  if (ptrace_read_user (serv, pid, 0, sizeof (GREGSET_T), (char *) gregset)
      != 0)
    return -1;
  return 0;
}

/* Function: put_gregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_gregset (struct gdbserv *serv, int pid, const GREGSET_T gregset)
{
  if (ptrace_write_user (serv, pid, 0, sizeof (GREGSET_T), 
			 (char *) gregset) != 0)
    return -1;
  return 0;
}

static int
get_fpregset (struct gdbserv *serv, int pid, FPREGSET_T *fpregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: put_fpregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_fpregset (struct gdbserv *serv, int pid, const FPREGSET_T *fpregset)
{
  return -1;	/* Unimplemented.  */
}

/* Function: get_fpregset
   Read the fpregset for pid.
   Return -1 for failure, zero for success. */

static int
get_xregset (struct gdbserv *serv, int pid, void *fpregset)
{
  return -1;
}

/* Function: put_xregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_xregset (struct gdbserv *serv, int pid, const void *fpregset)
{
  return -1;
}

#endif /* Target specific register functions for other architectures */


/* Track sole connection to a remote gdb client. */
/* FIXME: needed? */
static struct gdbserv *linux_connect_lock = NULL;



/* target vector: */

/* private sub-vector for ptrace target: */
static struct gdbserv_target *ptrace_target;	/* FIXME global */

/* Detach vector -- shut down this target connection.
 */

static void
linux_detach (struct gdbserv *serv, struct gdbserv_target *target)
{
  struct child_process *process = gdbserv_target_data (serv);

  assert (linux_connect_lock == serv);

  ptrace_target->detach (serv, target);
  if (process->debug_informational)
    fprintf (stderr, "linux - detached.\n");
  linux_connect_lock = NULL;

  /* Quit out of main loop for this demo.  In general, this is not 
     necessary, as the next incoming connection could again be handled 
     by linux_attach() above.  */
  server_quit_p = 1;
}


/* Process Rcmd vector
 * (apparently a target-specific remote command).
 */

static void
linux_process_rcmd (struct gdbserv *serv, const char *cmd, int cmdsize)
{
  struct child_process *process = gdbserv_target_data (serv);

  if (strcmp (cmd, "rda-backend-noisy") == 0)
    {
      process->debug_backend = 1;
      gdbserv_output_string_as_bytes (serv, "RDA backend diagnostics enabled.\n");
    }
  else if (strcmp (cmd, "rda-backend-quiet") == 0)
    {
      process->debug_backend = 0;
      gdbserv_output_string_as_bytes (serv, "RDA backend diagnostics disabled.\n");
    }
  else if (strcmp (cmd, "thread-db-noisy") == 0)
    {
      thread_db_noisy = 1;
      gdbserv_output_string_as_bytes (serv, "RDA thread-db diagnostics enabled.\n");
    }
  else if (strcmp (cmd, "thread-db-quiet") == 0)
    {
      thread_db_noisy = 0;
      gdbserv_output_string_as_bytes (serv, "RDA thread-db diagnostics disabled.\n");
    }
  else if (strcmp (cmd, "lwp-pool-noisy") == 0)
    {
      debug_lwp_pool = 1;
      gdbserv_output_string_as_bytes (serv, "RDA lwp-pool diagnostics enabled.\n");
    }
  else if (strcmp (cmd, "lwp-pool-quiet") == 0)
    {
      debug_lwp_pool = 0;
      gdbserv_output_string_as_bytes (serv, "RDA lwp-pool diagnostics disabled.\n");
    }
  else if (strcmp (cmd, "all-noisy") == 0)
    {
      process->debug_backend = 1;
      thread_db_noisy = 1;
      debug_lwp_pool = 1;
      gdbserv_output_string_as_bytes (serv, "All RDA diagnostics enabled.\n");
    }
  else if (strcmp (cmd, "all-quiet") == 0)
    {
      process->debug_backend = 0;
      thread_db_noisy = 0;
      debug_lwp_pool = 0;
      gdbserv_output_string_as_bytes (serv, "All RDA diagnostics disabled.\n");
    }
  else if (strcmp (cmd, "interrupt-with-SIGSTOP") == 0)
    {
      process->interrupt_with_SIGSTOP = 1;
      gdbserv_output_string_as_bytes (serv,
        "RDA will use SIGSTOP to perform user requested interrupts.\n");
    }
  else if (strcmp (cmd, "interrupt-with-SIGINT") == 0)
    {
      process->interrupt_with_SIGSTOP = 0;
      gdbserv_output_string_as_bytes (serv,
        "RDA will use SIGINT to perform user requested interrupts.\n");
    }
  else
    gdbserv_output_string_as_bytes (serv,
      "Unrecognized monitor command.\n"
      "Available commands are:\n"
      "  monitor all-noisy\n"
      "  monitor all-quiet\n"
      "  monitor rda-backend-noisy\n"
      "  monitor rda-backend-quiet\n"
      "  monitor thread-db-noisy\n"
      "  monitor thread-db-quiet\n"
      "  monitor lwp-pool-noisy\n"
      "  monitor lwp-pool-quiet\n"
      "  monitor interrupt-with-SIGSTOP\n"
      "  monitor interrupt-with-SIGINT\n");
}

/* This function is called from gdbloop_poll when a new incoming
   connection is attempted.  It may return NULL if the new connection
   is to be refused, or a gdbserv_target vector if the connection is
   accepted.  */

static struct gdbserv_target *
linux_attach (struct gdbserv *serv, void *data)
{
  struct gdbserv_target *linux_target;
  struct child_process *process = data;
  extern struct gdbserv_target *ptrace_attach (struct gdbserv *, void *);
  extern int thread_db_attach (); /* FIXME header <^ */

  /* Enable server tracing. */
  /*  gdbserv_state_trace = stderr;*/

  if (linux_connect_lock != NULL)
    {
      fprintf (stderr, "linux: rejected duplicate connection.\n");
      return NULL;
    }

  if ((ptrace_target = ptrace_attach (serv, data)) == NULL)
    {
      fprintf (stderr, "Linux: unable to open %s\n", process->argv[0]);
      return NULL;
    }

  if (process->debug_informational)
    fprintf (stderr, "linux: accepted gdb connection.\n");
  linux_connect_lock = serv;

  linux_target = malloc (sizeof (struct gdbserv_target));
  memset (linux_target, 0, sizeof (*linux_target));

  /* Callback structure for function pointers that handle processed
     control packets.  See gdbserv-target.h for docs on the individual
     functions. */

  linux_target->process_rcmd          = linux_process_rcmd;
  linux_target->process_set_args      = NULL;
  /* Replace the process_get_reg(s) method with get_regs. */
  linux_target->process_set_reg       = NULL;
  linux_target->process_set_regs      = NULL;
  linux_target->process_get_reg       = NULL;
  linux_target->process_get_regs      = NULL;
  linux_target->get_reg               = linux_get_reg;
  linux_target->set_reg               = linux_set_reg;
  linux_target->sizeof_reg            = linux_sizeof_reg;
  linux_target->gg_reg_nr             = linux_gg_reg_nr;
#if __LITTLE_ENDIAN == __BYTE_ORDER
  linux_target->output_reg            = gdbserv_output_reg_leb;
  linux_target->input_reg             = gdbserv_input_reg_leb;
#elif __BIG_ENDIAN == __BYTE_ORDER
  linux_target->output_reg            = gdbserv_output_reg_beb;
  linux_target->input_reg             = gdbserv_input_reg_beb;
#else
#error unknown endianness
#endif
  linux_target->next_gg_reg           = linux_next_gg_reg;
  linux_target->reg_format            = linux_reg_format;

  linux_target->expedited_reg_nr      = NULL;
  linux_target->get_mem               = ptrace_target->get_mem;
  linux_target->set_mem               = ptrace_target->set_mem;
  linux_target->process_set_pc        = NULL;
  linux_target->flush_i_cache         = ptrace_target->flush_i_cache;
  linux_target->process_signal        = ptrace_target->process_signal;
  linux_target->compute_signal        = ptrace_target->compute_signal;
  linux_target->get_trap_number       = ptrace_target->get_trap_number;
  linux_target->exit_program          = ptrace_target->exit_program;
  linux_target->break_program         = ptrace_target->break_program;
  linux_target->reset_program         = NULL;
  linux_target->restart_program       = NULL;
#if defined(_MIPSEL) || defined(_MIPSEB)
  linux_target->singlestep_program    = mips_singlestep_program;
#elif defined(AM33_2_0_LINUX_TARGET)
  linux_target->singlestep_program    = am33_singlestep_program;
#else
  linux_target->singlestep_program    = ptrace_target->singlestep_program;
#endif
  linux_target->cyclestep_program     = NULL;
  linux_target->sigkill_program       = NULL;
  linux_target->continue_program      = ptrace_target->continue_program;
  linux_target->remove_breakpoint     = NULL;
  linux_target->set_breakpoint        = NULL;
  linux_target->process_target_packet = NULL;
  linux_target->detach                = linux_detach;

  linux_target->data = data;
  process->serv = serv;

#if defined (MAKE_ARCH)
  process->arch = MAKE_ARCH ();
#else
  process->arch = 0;
#endif

  if (process->arch
      && process->arch->make_bp_table)
    process->breakpoint_table
      = process->arch->make_bp_table (process->arch, serv, linux_target);
  else
    process->breakpoint_table = 0;

#if defined(SOFTWARE_SINGLESTEP)
  process->is_ss = 0;
#endif

  /* Attach to thread_db module. */
  /* FIXME: unconditional call to extern function? */
  if ((thread_db_attach (serv, linux_target)) < 0)
    { /* failed */
      fprintf (stderr, "Failed to open thread_db library.\n");
    }

  return linux_target;
}

static int
linux_check_child_state (struct child_process *process)
{
  return ptrace_check_child_state (process);
}

static void
linux_fromtarget_break (struct child_process *process)
{
  int gdb_signal = ptrace_target->compute_signal (process->serv,
						  process->stop_signal);
  gdbserv_fromtarget_break (process->serv, gdb_signal);
}

static void
linux_fromtarget_exit (struct child_process *process)
{
  gdbserv_fromtarget_exit (process->serv, process->stop_signal);
}

static void
linux_fromtarget_terminate (struct child_process *process)
{
  int gdb_signal = ptrace_target->compute_signal (process->serv,
						  process->stop_signal);

  gdbserv_fromtarget_terminate (process->serv, gdb_signal);
}

/* This struct contains the vectors that connect us to main:
 */
struct server_vector gdbserver = 
{
  linux_attach, 
  linux_check_child_state, 
  linux_fromtarget_break, 
  linux_fromtarget_exit,
  linux_fromtarget_terminate
};

/* Function: decr_pc_after_break
   [Must be implemented explicitly for each supported architecture.]

   For multi-thread linux, if several threads hit a breakpoint
   "simultaneously", we will want to set at least one of them up
   so that it will hit the same breakpoint again the next time it
   gets to run (assuming the breakpoint hasn't been removed by then).

   Depending on the target architecture, that may mean setting
   the PC back to point at the trap instruction.  

   Return -1 for failure, zero for success. */

#ifdef X86_LINUX_TARGET

/* For ia32 we do need to decrement the PC to point at the trap. */
int
decr_pc_after_break (struct gdbserv *serv, pid_t pid)
{
  unsigned long pc;
  int status;

  status = read_reg_as_ulong (serv, pid, PC_REGNUM, &pc);
  if (status < 0)
    return -1;

  pc -= 1;
  if (thread_db_noisy)
    fprintf (stderr, "<decr_pc_after_break: pid %d, addr 0x%08lx>\n", pid, pc);
  status = write_reg_as_ulong (serv, pid, PC_REGNUM, pc);
  return status;
}

#else
int
decr_pc_after_break (struct gdbserv *serv, pid_t pid)
{
  return 0;
}
#endif

#ifdef SOFTWARE_SINGLESTEP

/* Set a software-singlestep breakpoint.  */

static void
set_singlestep_breakpoint (struct gdbserv *serv, ptrace_arg3_type addr,
			   char *breakpoint_bytes, int breakpoint_length,
			   void (*restore_action) (struct gdbserv *serv,
			                           struct ss_save *save))
{
  int i = 0;
  struct child_process *process = gdbserv_target_data (serv);

  if (process->ss_info[i].in_use)
    i++;

  assert (!process->ss_info[i].in_use);

  /* set flag so handle_waitstatus can restore breakpoint stuff */
  process->is_ss = 1;					

  /* Mark the breakpoint used.  */
  process->ss_info[i].in_use = 1;

  /* Convert ``addr'' to a struct gdbserv_reg.  */
  gdbserv_host_bytes_to_reg (serv,
                             &addr,
			     sizeof (addr),
			     &process->ss_info[i].ss_addr,
			     sizeof (ptrace_arg3_type),
			     sign_extend);

  /* Set the breakpoint size.  */
  process->ss_info[i].ss_size = breakpoint_length;

  /* Fetch the contents of the memory at which the breakpoint will be
    placed.  */
  ptrace_get_mem (serv,
                  &process->ss_info[i].ss_addr,
		  process->ss_info[i].ss_val,
		  process->ss_info[i].ss_size);

  /* Finally, set the breakpoint!  */
  ptrace_set_mem (serv,
                  &process->ss_info[i].ss_addr,
		  breakpoint_bytes,
		  process->ss_info[i].ss_size);

  process->ss_info[i].restore_action = restore_action;
  if (process->debug_backend)
    fprintf (stderr, "Singlestep breakpoint %d set at location %lx\n", i, addr);
}
#endif /* SOFTWARE_SINGLESTEP */

#if defined(_MIPSEL) || defined(_MIPSEB)

static struct gdbserv_reg
mips_addr_as_reg (struct gdbserv *serv, ptrace_arg3_type addr)
{
  struct gdbserv_reg addr_as_reg;

  gdbserv_host_bytes_to_reg (serv, &addr, sizeof (addr),
                             &addr_as_reg, sizeof (ptrace_arg3_type),
			     sign_extend);
  return addr_as_reg;
}

/* peek / poke mips instructions.  Using an ``unsigned int'' to represent
   a mips instruction is correct (with regard to size) for the o32, n32,
   and n64 ABIs.  */
static unsigned int
mips_peek_instruction (struct gdbserv *serv, ptrace_arg3_type addr)
{
  struct gdbserv_reg addr_as_reg;
  unsigned int insn;

  addr_as_reg = mips_addr_as_reg (serv, addr);
  ptrace_get_mem (serv, &addr_as_reg, &insn, sizeof (insn));
  return insn;
}

/*
 * mips singlestep
 *
 * necessary since no support in ptrace.
 */
void mips_singlestep (struct gdbserv *serv, pid_t pid, int sig);

static void
mips_singlestep_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  mips_singlestep (serv, process->pid, process->signal_to_send);
  process->stop_signal = 0;
  process->stop_status = 0;
  process->signal_to_send = 0;
}

void
mips_singlestep (struct gdbserv *serv, pid_t pid, int sig)
{
  struct child_process *process = gdbserv_target_data (serv);
  ptrace_xfer_type targ, mips_pc;

  union mips_instruction insn;
  int is_branch, is_cond, i;

  unsigned int bp_inst = 0x0000000d;

  /* FIXME: handle signals! */
  if (process->debug_backend)
    fprintf (stderr, "mips_singlestep %d %ld\n", pid, sig);

  errno = 0;

  /* Following is equiv to  ptrace (PTRACE_SINGLESTEP, pid, 1L, sig); */

  /* get the current PC */
  mips_pc = debug_get_reg(serv, pid, PC_REGNUM);
  targ = mips_pc;

  /* get the word there (opcode) */

  insn.word = mips_peek_instruction (serv, mips_pc);

  is_branch = is_cond = 0;

  switch (insn.i_format.opcode) {
  /*
   * jr and jalr are in r_format format.
   */
  case spec_op:
    switch (insn.r_format.func) {
    case jalr_op:
    case jr_op:
    	targ = debug_get_reg(serv, pid, insn.r_format.rs);
    	is_branch = 1;
    	break;
    }
    break;

  /*
   * This group contains:
   * bltz_op, bgez_op, bltzl_op, bgezl_op,
   * bltzal_op, bgezal_op, bltzall_op, bgezall_op.
   */
  case bcond_op:
    is_branch = is_cond = 1;
    targ += 4 + (insn.i_format.simmediate << 2);
    break;

  /*
   * These are unconditional and in j_format.
   */
  case jal_op:
  case j_op:
    is_branch = 1;
    targ += 4;
    targ >>= 28;
    targ <<= 28;
    targ |= (insn.j_format.target << 2);
    break;

  /* Some cop1 instructions are conditional branches.  */
  case cop1_op:
    if (insn.i_format.rs == bc_op
        || insn.i_format.rs == bc_op + 1  /* e.g, BC1ANY2 on MIPS-3D */
	|| insn.i_format.rs == bc_op + 2  /* e.g, BC1ANY4 on MIPS-3D */)
      {
	is_branch = is_cond = 1;
	targ += 4 + (insn.i_format.simmediate << 2);
      }
    break;

  /* Some cop2 instructions are conditional branches.  */
  case cop2_op:
    /* MIPS32 Architecture For Programmers Volume II, rev 1.90 documents
       bc2f, bc2fl, bc2t, and bc2tl.  */
    if (insn.i_format.rs == bc_op)
      {
	is_branch = is_cond = 1;
	targ += 4 + (insn.i_format.simmediate << 2);
      }
    break;

  /* Other conditional branches...  */
  case beq_op:
  case beql_op:
  case bne_op:
  case bnel_op:
  case blez_op:
  case blezl_op:
  case bgtz_op:
  case bgtzl_op:
    is_branch = is_cond = 1;
    targ += 4 + (insn.i_format.simmediate << 2);
    break;
  }
      	
  process->ss_info[1].in_use = 0;	/* Mark unused.  */
  if (is_branch)
    {
      i = 0;
      if (is_cond && targ != (mips_pc + 8))
	{
	  set_singlestep_breakpoint (serv, mips_pc + 8, &bp_inst,
	                              sizeof (bp_inst), NULL);
	}
      set_singlestep_breakpoint (serv, targ, &bp_inst,
				  sizeof (bp_inst), NULL);
    }
  else
    {
      set_singlestep_breakpoint (serv, mips_pc + 4, &bp_inst,
				  sizeof (bp_inst), NULL);
    }

  ptrace (PTRACE_CONT, pid, 1L, sig); 
}
#endif /* _MIPSEL */

#if defined (AM33_2_0_LINUX_TARGET)
/* AM33 single-step support. Lifted from Redboot which was in turn
   lifted from Cygmon.  */

void am33_singlestep (struct gdbserv *serv, pid_t pid, int sig);

static void
am33_singlestep_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);

  am33_singlestep (serv, process->pid, process->signal_to_send);
  process->stop_signal = 0;
  process->stop_status = 0;
  process->signal_to_send = 0;
}

/* Read a 16-bit displacement from address 'addr'.  */
static unsigned char
am33_read_byte(struct gdbserv *serv, ptrace_arg3_type addr)
{
  unsigned char val;
  struct gdbserv_reg addr_as_reg;

  gdbserv_host_bytes_to_reg (serv, &addr, sizeof (addr),
                             &addr_as_reg, sizeof (ptrace_arg3_type),
			     sign_extend);
  ptrace_get_mem (serv, &addr_as_reg, &val, sizeof (val));

  return val;
}

static short
am33_read_disp16(struct gdbserv *serv, ptrace_arg3_type addr)
{
  short val;
  struct gdbserv_reg addr_as_reg;

  gdbserv_host_bytes_to_reg (serv, &addr, sizeof (addr),
                             &addr_as_reg, sizeof (ptrace_arg3_type),
			     sign_extend);
  ptrace_get_mem (serv, &addr_as_reg, &val, sizeof (val));
  
  return val;
}

/* Read a 32-bit displacement from address 'p'. The
   value is stored little-endian.  */

static long
am33_read_disp32(struct gdbserv *serv, ptrace_arg3_type addr)
{
  long val;
  struct gdbserv_reg addr_as_reg;

  gdbserv_host_bytes_to_reg (serv, &addr, sizeof (addr),
                             &addr_as_reg, sizeof (ptrace_arg3_type),
			     sign_extend);
  ptrace_get_mem (serv, &addr_as_reg, &val, sizeof (val));
  
  return val;
}

static ptrace_arg3_type
am33_get_register (struct gdbserv *serv, pid_t pid, int regno)
{
  return debug_get_reg (serv, pid, regno);
}

static int
am33_set_register (struct gdbserv *serv, pid_t pid, int regno, unsigned long regval)
{
  return write_reg_as_ulong (serv, pid, regno, regval);
}


/* Get the contents of An register.  */

static unsigned int
am33_get_areg (struct gdbserv *serv, pid_t pid, int n)
{
  switch (n)
    {
    case 0:
      return am33_get_register (serv, pid, A0_REGNUM);
    case 1:
      return am33_get_register (serv, pid, A1_REGNUM);
    case 2:
      return am33_get_register (serv, pid, A2_REGNUM);
    case 3:
      return am33_get_register (serv, pid, A3_REGNUM);
    }
  return 0;
}

/* Restore LIR after singlestepping an Lcc instruction.  */
static void
am33_restore_lir (struct gdbserv *serv, struct ss_save *save)
{
  struct child_process *process = gdbserv_target_data (serv);
  int pid = process->pid;
  unsigned long lir = am33_get_register (serv, pid, LIR_REGNUM);
  unsigned long addr;
  int rot;

  gdbserv_host_bytes_from_reg (serv, &addr, sizeof (addr), &save->ss_addr,
                               sign_extend);
  rot = addr & 0x3;
  lir = (lir & ~(0xff << (rot * 8))) 
        | (am33_read_byte (serv, addr) << (rot * 8));
  am33_set_register (serv, pid, LIR_REGNUM, lir);
}

/* Table of instruction sizes, indexed by first byte of instruction,
   used to determine the address of the next instruction for single stepping.
   If an entry is zero, special code must handle the case (for example,
   branches or multi-byte opcodes).  */

static char am33_opcode_size[256] =
{
     /* 0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f */
     /*------------------------------------------------*/
/* 0 */ 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3,
/* 1 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
/* 2 */ 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3,
/* 3 */ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1,
/* 4 */ 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2,
/* 5 */ 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
/* 6 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
/* 7 */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
/* 8 */ 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2,
/* 9 */ 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2,
/* a */ 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2,
/* b */ 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2,
/* c */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2,
/* d */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
/* e */ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
/* f */ 0, 2, 2, 2, 2, 2, 2, 0, 0, 3, 0, 4, 0, 6, 7, 1
};

/* Set breakpoint(s) to simulate a single step from the current PC.  */

void
am33_singlestep (struct gdbserv *serv, pid_t pid, int sig)
{
  struct child_process *process = gdbserv_target_data (serv);
  ptrace_arg3_type pc;
  unsigned int opcode;
  int displ;
  static char bp_inst = 0xff;
  static int hw_singlestep_okay = 1;
  pid_t save_pid;

  if (hw_singlestep_okay)
    {
      if (process->debug_backend)
	fprintf (stderr, "PTRACE_SINGLESTEP (am33): pid=%d signal=%d\n",
	         pid, sig);
      errno = 0;
      ptrace (PTRACE_SINGLESTEP, pid, 1L, sig);
      if (errno == 0)
	return;
      /* EINVAL is the expected error when the kernel doesn't support
         PTRACE_SINGLESTEP.  Report all other errors.  */
      if (errno != EINVAL)
	fprintf (stderr, "PTRACE_SINGLESTEP (am33) error: %s in %d\n",
	         strerror (errno), pid);
      else
	{
	  if (process->debug_backend)
	    fprintf (stderr,
	             "Disabling use of PTRACE_SINGLESTEP: It's not supported by this kernel.\n");
	  hw_singlestep_okay = 0;
	}
      /* Fall through into software singlestep code.  */
    }

  /* In a multi-threaded program, process->pid might be a running thread
     and we can't read / write into running threads.  So set process->pid
     to the lwp.  */
  save_pid = process->pid;
  process->pid = pid;

  pc = am33_get_register (serv, pid, PC_REGNUM);
  opcode = am33_read_byte (serv, pc);

  /* Check the table for the simple cases.  */
  displ = am33_opcode_size[opcode];
  if (displ != 0)
    {
      set_singlestep_breakpoint (serv, pc + displ, &bp_inst, sizeof (bp_inst),
                                 NULL);
    }
  else

    /* Handle the more complicated cases.  */
    switch (opcode)
      {
      case 0xc0:
      case 0xc1:
      case 0xc2:
      case 0xc3:
      case 0xc4:
      case 0xc5:
      case 0xc6:
      case 0xc7:
      case 0xc8:
      case 0xc9:
      case 0xca:
	/*
	 *  bxx (d8,PC)
	 */
	displ = (signed char) am33_read_byte (serv, pc + 1);
	set_singlestep_breakpoint (serv, pc + 2, &bp_inst, sizeof (bp_inst), NULL);
	if (displ < 0 || displ > 2)
	  set_singlestep_breakpoint (serv, pc + displ, &bp_inst,
	                             sizeof (bp_inst), NULL);
	break;

      case 0xf7:
	/* Various LIW instructions.  */
	opcode = am33_read_byte (serv, pc + 1);
	if (opcode != 0xe0)
	  {
	    /* Not a MOV_Lcc.  Set breakpoint four bytes after current
	       instruction.  */
	    set_singlestep_breakpoint (serv, pc + 4, &bp_inst,
	                               sizeof (bp_inst), NULL);
	    break;
	  }
	/* If it is a MOV_Lcc, we'll fall through to the Lcc case below.
	   Advance PC so that the code below will work for this instruction
	   too.  */
	pc += 3;
	
	/* Fall through...  */

      case 0xd0:
      case 0xd1:
      case 0xd2:
      case 0xd3:
      case 0xd4:
      case 0xd5:
      case 0xd6:
      case 0xd7:
      case 0xd8:
      case 0xd9:
      case 0xda:
	/* Lcc: This is (conceptually) a conditional branch to the address
	   contained in LAR - 4.  A SETLB instruction should have been
	   executed to set up LAR and LIR.  LIR contains four bytes of
	   prefetched instructions beginning at LAR - 4.  (These will
	   be rotated depending on the low two bits of the address.)
	   In order to singlestep this instruction, we place
	   breakpoints at the instruction following Lcc in addition to
	   the branch target specified by LAR - 4.  However, we can't
	   expect that this latter breakpoint will actually do
	   anything useful since the processor uses the prefetched
	   instruction data contained in LIR.  Therefore, we also
	   place a breakpoint at correct byte of LIR.  The function
	   am33_restore_lir() will restore the correct LIR contents
	   after stopping at the breakpoint.
	   
	   Once the processor has stopped at the first instruction in
	   the prefetched data, the subsequent instructions are executed
	   from memory.  Thus, the effect of these instructions should be
	   identical to that of executing out of the LIR with the proviso
	   that the program doesn't change the LIR after executing the
	   SETLB instruction.  (I guess this would be an interesting way
	   to implement self modifying code...)  */


	{
	  unsigned long lar = am33_get_register (serv, pid, LAR_REGNUM);
	  int rot = lar & 0x3; 
	  if (pc != lar - 4)
	    {
	      unsigned long lir = am33_get_register (serv, pid, LIR_REGNUM);
	      lir = (lir & ~(0xff << (rot * 8))) | (bp_inst << (rot * 8));
	      am33_set_register (serv, pid, LIR_REGNUM, lir);
	      set_singlestep_breakpoint (serv, lar - 4, &bp_inst,
	                               sizeof (bp_inst), am33_restore_lir);
	    }
	  set_singlestep_breakpoint (serv, pc + 1, &bp_inst, sizeof (bp_inst),
	                             NULL);
	}
	break;

      case 0xdb:
	/* setlb:  Simulate execution of setlb instruction.  Advance
	   pc to next instruction and set a breakpoint there too to
	   make it appear that we executed this instruction.
	   
	   If we set a breakpoint on the following instruction and then
	   allow SETLB to execute, we'll end up with a breakpoint in the
	   LIR register.
	   
	   An earlier version of this code attempted to set the
	   breakpoint after the four bytes which are loaded into LIR. 
	   This is incorrect because that location might not be the
	   start of a new instruction.  */

	am33_set_register (serv, pid, PC_REGNUM, pc + 1);
	am33_set_register (serv, pid, LAR_REGNUM, pc + 5);
	{
	  unsigned long lir = (unsigned long) am33_read_disp32 (serv, pc + 1);
	  int rot = (pc + 1) & 0x3; 
	  if (rot != 0)
	    lir = (lir << (rot * 8)) | (lir >> ((4 - rot) * 8));
	  am33_set_register (serv, pid, LIR_REGNUM, lir);
	}
	set_singlestep_breakpoint (serv, pc + 1, &bp_inst, sizeof (bp_inst),
	                           NULL);
	break;

      case 0xcc:
      case 0xcd:
	/*
	 * jmp (d16,PC) or call (d16,PC)
	 */
	displ = am33_read_disp16(serv, pc + 1);
	set_singlestep_breakpoint (serv, pc + displ, &bp_inst,
	                           sizeof (bp_inst), NULL);
	break;

      case 0xdc:
      case 0xdd:
	/*
	 * jmp (d32,PC) or call (d32,PC)
	 */
	displ = am33_read_disp32(serv, pc + 1);
	set_singlestep_breakpoint (serv, pc + displ, &bp_inst,
	                           sizeof (bp_inst), NULL);
	break;

      case 0xde:
	/*
	 *  retf
	 */
	set_singlestep_breakpoint (serv, am33_get_register (serv, pid, MDR_REGNUM),
				   &bp_inst, sizeof (bp_inst), NULL);
	break;

      case 0xdf:
	/*
	 *  ret
	 */
	displ = (signed char) am33_read_byte (serv, pc + 2);
	set_singlestep_breakpoint (
	  serv,
	  am33_read_disp32 (serv,
			    am33_get_register (serv, pid, SP_REGNUM) + displ),
	  &bp_inst, sizeof (bp_inst), NULL);
	break;

      case 0xf0:
	/*
	 *  Some branching 2-byte instructions.
	 */
	opcode = am33_read_byte (serv, pc + 1);
	if (opcode >= 0xf0 && opcode <= 0xf7)
	  {
	    /* jmp (An) / calls (An) */
	    set_singlestep_breakpoint (serv,
				       am33_get_areg (serv, pid, opcode & 3),
				       &bp_inst, sizeof (bp_inst), NULL);

	  }
	else if (opcode == 0xfc)
	  {
	    /* rets */
	    set_singlestep_breakpoint (
	      serv,
	      am33_read_disp32 (serv, am33_get_register (serv, pid, SP_REGNUM)),
				&bp_inst, sizeof (bp_inst), NULL);
      
	  }
	else if (opcode == 0xfd)
	  {
	    /* rti */
	    set_singlestep_breakpoint (
	      serv,
	      am33_read_disp32 (serv,
				am33_get_register (serv, pid, SP_REGNUM) + 4),
	      &bp_inst, sizeof (bp_inst), NULL);

	  }
	else 
	  set_singlestep_breakpoint (serv, pc + 2, &bp_inst, sizeof (bp_inst),
	                             NULL);

	break;

      case 0xf8:
	/*
	 *  Some branching 3-byte instructions.
	 */
	opcode = am33_read_byte (serv, pc + 1);
	if (opcode >= 0xe8 && opcode <= 0xeb)
	  {
	    displ = (signed char) am33_read_byte (serv, pc + 2);
	    set_singlestep_breakpoint (serv, pc + 3, &bp_inst, sizeof (bp_inst),
	                               NULL);
	    if (displ < 0 || displ > 3)
	      set_singlestep_breakpoint (serv, pc + displ,
					 &bp_inst, sizeof (bp_inst), NULL);
      
	  }
	else
	  set_singlestep_breakpoint (serv, pc + 3, &bp_inst, sizeof (bp_inst),
	                             NULL);
	break;

      case 0xfa:
	opcode = am33_read_byte (serv, pc + 1);
	if (opcode == 0xff)
	  {
	    /* calls (d16,PC) */
	    displ = am33_read_disp16 (serv, pc + 2);
	    set_singlestep_breakpoint (serv, pc + displ,
				       &bp_inst, sizeof (bp_inst), NULL);
	  }
	else
	  set_singlestep_breakpoint (serv, pc + 4, &bp_inst, sizeof (bp_inst),
	                             NULL);
	break;

      case 0xfc:
	opcode = am33_read_byte (serv, pc + 1);
	if (opcode == 0xff)
	  {
	    /* calls (d32,PC) */
	    displ = am33_read_disp32 (serv, pc + 2);
	    set_singlestep_breakpoint (serv, pc + displ,
	                               &bp_inst, sizeof (bp_inst), NULL);
	  }
	else
	  set_singlestep_breakpoint (serv, pc + 6,
	                             &bp_inst, sizeof (bp_inst), NULL);
	break;

    }

  if (process->debug_backend)
    fprintf (stderr, "PTRACE_CONT (am33): pid=%d signal=%d\n", pid, sig);
  errno = 0;
  ptrace (PTRACE_CONT, pid, 0, sig); 
  if (errno)
    fprintf (stderr, "PTRACE_CONT (am33) error: %s in %d\n",
	     strerror (errno), pid);

  /* Restore the saved pid.  */
  process->pid = save_pid;
}
#endif

/* proc_service callback functions */

ps_err_e
ps_lgetregs (gdb_ps_prochandle_t ph,		/* Get LWP general regs */
	     lwpid_t     lwpid,
	     GREGSET_T gregset)
{
  if (get_gregset (ph->serv, lwpid, gregset) < 0)
    {
      fprintf (stderr, "<<< ERROR ps_lgetregs %d >>>\n", lwpid);
      return PS_ERR;
    }
  return PS_OK;
}

ps_err_e
ps_lsetregs (gdb_ps_prochandle_t ph,		/* Set LWP general regs */
	     lwpid_t           lwpid,
	     const GREGSET_T gregset)
{
  if (put_gregset (ph->serv, lwpid, gregset) < 0)
    {
      fprintf (stderr, "<<< ERROR ps_lsetregs %d >>>\n", lwpid);
      return PS_ERR;
    }
  return PS_OK;
}

ps_err_e
ps_lgetfpregs (gdb_ps_prochandle_t ph,		/* Get LWP float regs */
	       lwpid_t       lwpid,
	       FPREGSET_T *fpregset)
{
  if (get_fpregset (ph->serv, lwpid, fpregset) < 0)
    {
      fprintf (stderr, "<<< ERROR ps_lgetfpregs %d >>>\n", lwpid);
      return PS_ERR;
    }
  return PS_OK;
}

ps_err_e
ps_lsetfpregs (gdb_ps_prochandle_t ph,		/* Set LWP float regs */
	       lwpid_t             lwpid,
	       const FPREGSET_T *fpregset)
{
  if (put_fpregset (ph->serv, lwpid, fpregset) < 0)
    {
      fprintf (stderr, "<<< ERROR ps_lsetfpregs %d >>>\n", lwpid);
      return PS_ERR;
    }
  return PS_OK;
}

ps_err_e
ps_lgetxregsize (gdb_ps_prochandle_t ph,	/* Get XREG size */
		 lwpid_t lwpid,
		 int *xregsize)
{
  *xregsize = get_xregsetsize (ph->serv, lwpid);
  if (*xregsize > 0)
    return PS_OK;
  else
    return PS_ERR;
}

ps_err_e
ps_lgetxregs (gdb_ps_prochandle_t ph,		/* Get XREGS */
	      lwpid_t lwpid,
	      caddr_t xregset)
{
  if (get_xregset (ph->serv, lwpid, xregset) < 0)
    {
      fprintf (stderr, "<<< ERROR ps_lgetxregs %d >>>\n", lwpid);
      return PS_ERR;
    }
  return PS_OK;
}

ps_err_e
ps_lsetxregs (gdb_ps_prochandle_t ph,		/* Set XREGS */
	      lwpid_t lwpid,
	      caddr_t xregset)
{
  if (put_xregset (ph->serv, lwpid, xregset) < 0)
    {
      fprintf (stderr, "<<< ERROR ps_lsetxregs %d >>>\n", lwpid);
      return PS_ERR;
    }
  return PS_OK;
}

/*
 * ps_getpid
 *
 * return the main pid for the child process
 * (special for Linux -- not used on Solaris)
 */

pid_t
ps_getpid (gdb_ps_prochandle_t ph)
{
  return ph->pid;
}
