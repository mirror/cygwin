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
#if !defined(_MIPSEL) && !defined(_MIPSEB)
#include <stdint.h>
#else
#include <asm-mips/inst.h>
#endif

#include <sys/ptrace.h>
#include <sys/procfs.h>
#include "gdbserv.h"
#include "gdbserv-target.h"
#include "gdbserv-utils.h"

#include "gdb_proc_service.h"
#include "gdbserv-thread-db.h"

#include "server.h"
#include "ptrace-target.h"

/* This is a linux native gdbserv target that uses the RDA library to
   implement a remote gdbserver on a linux host.  It controls the
   process to be debugged on the linux host, allowing GDB to pull the
   strings from any host on the network (or on a serial port).  */

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
  FPXREGS
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

*/

     


#if defined (ARM_LINUX_TARGET)

/* ARM needs to use PTRACE_GETREGS / PTRACE_SETREGS and
   PTRACE_GETFPREGS / PTRACE_SETFPREGS to access all of the registers. 
   */
#define GETREGS_SETREGS_REGINFO 1

enum 
{ 
  PC_REGNUM = 15,
  NUM_REGS = 26
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
  NUM_REGS = 42
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

/* End of X86_LINUX_TARGET */

#elif defined (SH_LINUX_TARGET)

/* Needs to be converted to use either GETREGS_SETREGS_REGINFO or
   PEEKUSER_POKEUSER_REGINFO machinery.  */

enum
{
  SIZEOF_REGMAP = 23,
  SIZEOF_MAPPEDREG = 4,
  NUM_REGS = 24,
  PC_REGNUM = 16
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

#elif defined(MIPS_LINUX_TARGET)

#define PEEKUSER_POKEUSER_REGINFO 1

enum
{
  NUM_REGS = 70,
  PC_REGNUM = 37
};


static struct peekuser_pokeuser_reginfo reginfo[] =
{
  /* MIPS has differing elf_gregset_t and gregset_t structs.  (The
     former contains some leading padding that the latter does not.)
     elf_gregset_t is used to access registers from a core file whereas
     gregset_t is used by the thread library in its interfaces.  Since
     we're concerned about the latter, we'll use the gregset_t offsets
     in the table below.  */
  { 0,             4, GREGS,  0 * 4,  4, 4 },      /* zero */
  { 1,             4, GREGS,  1 * 4,  4, 4 },      /* at */
  { 2,             4, GREGS,  2 * 4,  4, 4 },      /* v0 */
  { 3,             4, GREGS,  3 * 4,  4, 4 },      /* v1 */
  { 4,             4, GREGS,  4 * 4,  4, 4 },      /* a0 */
  { 5,             4, GREGS,  5 * 4,  4, 4 },      /* a1 */
  { 6,             4, GREGS,  6 * 4,  4, 4 },      /* a2 */
  { 7,             4, GREGS,  7 * 4,  4, 4 },      /* a3 */
  { 8,             4, GREGS,  8 * 4,  4, 4 },      /* t0 */
  { 9,             4, GREGS,  9 * 4,  4, 4 },      /* t1 */
  { 10,            4, GREGS,  10 * 4, 4, 4 },      /* t2 */
  { 11,            4, GREGS,  11 * 4, 4, 4 },      /* t3 */
  { 12,            4, GREGS,  12 * 4, 4, 4 },      /* t4 */
  { 13,            4, GREGS,  13 * 4, 4, 4 },      /* t5 */
  { 14,            4, GREGS,  14 * 4, 4, 4 },      /* t6 */
  { 15,            4, GREGS,  15 * 4, 4, 4 },      /* t7 */
  { 16,            4, GREGS,  16 * 4, 4, 4 },      /* s0 */
  { 17,            4, GREGS,  17 * 4, 4, 4 },      /* s1 */
  { 18,            4, GREGS,  18 * 4, 4, 4 },      /* s2 */
  { 19,            4, GREGS,  19 * 4, 4, 4 },      /* s3 */
  { 20,            4, GREGS,  20 * 4, 4, 4 },      /* s4 */
  { 21,            4, GREGS,  21 * 4, 4, 4 },      /* s5 */
  { 22,            4, GREGS,  22 * 4, 4, 4 },      /* s6 */
  { 23,            4, GREGS,  23 * 4, 4, 4 },      /* s7 */
  { 24,            4, GREGS,  24 * 4, 4, 4 },      /* t8 */
  { 25,            4, GREGS,  25 * 4, 4, 4 },      /* t9 */
  { 26,            4, GREGS,  26 * 4, 4, 4 },      /* k0 */
  { 27,            4, GREGS,  27 * 4, 4, 4 },      /* k1 */
  { 28,            4, GREGS,  28 * 4, 4, 4 },      /* gp */
  { 29,            4, GREGS,  29 * 4, 4, 4 },      /* sp */
  { 30,            4, GREGS,  30 * 4, 4, 4 },      /* s8/fp */
  { 31,            4, GREGS,  31 * 4, 4, 4 },      /* ra */
  { 0,             4, NOREGS, 0,      4, 4 },      /* sr */
  { MMLO,          4, GREGS,  33 * 4, 4, 4 },      /* lo */
  { MMHI,          4, GREGS,  32 * 4, 4, 4 },      /* hi */

  /* glibc's ucontext.h doesn't specify the order of the following
     three registerss.  But there is space allocated for them.  (Well,
     for something, anyway - the g_pad[] array is has three elements.)
     We use the same order for these fields as that specified in the
     kernel header for elf_gregset_t; see the EF_ constants in
     asm-mips/reg.h.  Note, however, that the kernel header sandwiches
     the status register (sr, above) in between ``bad'' and ``cause''.  */

  { BADVADDR,      4, GREGS,  35 * 4, 4, 4 },      /* bad */
  { CAUSE,         4, GREGS,  36 * 4, 4, 4 },      /* cause */
  { PC,            4, GREGS,  34 * 4, 4, 4 },      /* pc */

  /* Linux/MIPS floating point is a bit of a mess.  On the one hand,
     the elf_fpregset_t contains space for 32 doubles plus the control
     word.  But on the other hand, the ptrace interface is only able to
     fetch the 32 32-bit wide registers.  This means that we only get
     16 double precision floats via ptrace().  It also means that only
     slightly more than half of elf_fpregset_t is unused.  */

  { FPR_BASE + 0,  4, FPREGS, 0 * 4,  4, 4 },      /* $f0 */
  { FPR_BASE + 1,  4, FPREGS, 1 * 4,  4, 4 },      /* $f1 */
  { FPR_BASE + 2,  4, FPREGS, 2 * 4,  4, 4 },      /* $f2 */
  { FPR_BASE + 3,  4, FPREGS, 3 * 4,  4, 4 },      /* $f3 */
  { FPR_BASE + 4,  4, FPREGS, 4 * 4,  4, 4 },      /* $f4 */
  { FPR_BASE + 5,  4, FPREGS, 5 * 4,  4, 4 },      /* $f5 */
  { FPR_BASE + 6,  4, FPREGS, 6 * 4,  4, 4 },      /* $f6 */
  { FPR_BASE + 7,  4, FPREGS, 7 * 4,  4, 4 },      /* $f7 */
  { FPR_BASE + 8,  4, FPREGS, 8 * 4,  4, 4 },      /* $f8 */
  { FPR_BASE + 9,  4, FPREGS, 9 * 4,  4, 4 },      /* $f9 */
  { FPR_BASE + 10, 4, FPREGS, 10 * 4, 4, 4 },      /* $f10 */
  { FPR_BASE + 11, 4, FPREGS, 11 * 4, 4, 4 },      /* $f11 */
  { FPR_BASE + 12, 4, FPREGS, 12 * 4, 4, 4 },      /* $f12 */
  { FPR_BASE + 13, 4, FPREGS, 13 * 4, 4, 4 },      /* $f13 */
  { FPR_BASE + 14, 4, FPREGS, 14 * 4, 4, 4 },      /* $f14 */
  { FPR_BASE + 15, 4, FPREGS, 15 * 4, 4, 4 },      /* $f15 */
  { FPR_BASE + 16, 4, FPREGS, 16 * 4, 4, 4 },      /* $f16 */
  { FPR_BASE + 17, 4, FPREGS, 17 * 4, 4, 4 },      /* $f17 */
  { FPR_BASE + 18, 4, FPREGS, 18 * 4, 4, 4 },      /* $f18 */
  { FPR_BASE + 19, 4, FPREGS, 19 * 4, 4, 4 },      /* $f19 */
  { FPR_BASE + 20, 4, FPREGS, 20 * 4, 4, 4 },      /* $f20 */
  { FPR_BASE + 21, 4, FPREGS, 21 * 4, 4, 4 },      /* $f21 */
  { FPR_BASE + 22, 4, FPREGS, 22 * 4, 4, 4 },      /* $f22 */
  { FPR_BASE + 23, 4, FPREGS, 23 * 4, 4, 4 },      /* $f23 */
  { FPR_BASE + 24, 4, FPREGS, 24 * 4, 4, 4 },      /* $f24 */
  { FPR_BASE + 25, 4, FPREGS, 25 * 4, 4, 4 },      /* $f25 */
  { FPR_BASE + 26, 4, FPREGS, 26 * 4, 4, 4 },      /* $f26 */
  { FPR_BASE + 27, 4, FPREGS, 27 * 4, 4, 4 },      /* $f27 */
  { FPR_BASE + 28, 4, FPREGS, 28 * 4, 4, 4 },      /* $f28 */
  { FPR_BASE + 29, 4, FPREGS, 29 * 4, 4, 4 },      /* $f29 */
  { FPR_BASE + 30, 4, FPREGS, 30 * 4, 4, 4 },      /* $f30 */
  { FPR_BASE + 31, 4, FPREGS, 31 * 4, 4, 4 },      /* $f31 */
  { FPC_CSR,       4, FPREGS, 64 * 4, 4, 4 }       /* fsr */
};

static void mips_singlestep_program (struct gdbserv *serv);

/* End of MIPS_LINUX_TARGET */

#elif M68K_LINUX_TARGET

/* Needs to be converted to use either GETREGS_SETREGS_REGINFO or
   PEEKUSER_POKEUSER_REGINFO machinery.  */

#error m68k
enum 
{
  SIZEOF_REGMAP = 29, 		/* with FP regs */
  SIZEOF_MAPPEDREG = 4,
  NUM_REGS = 29,
  PC_REGNUM = 17
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
  PC_REGNUM = 64
};

static struct peekuser_pokeuser_reginfo reginfo[] =
{
  { PT_R0 * 4,          4, GREGS,  PT_R0 * 4,  4, 4 },
  { PT_R1 * 4,          4, GREGS,  PT_R1 * 4,  4, 4 },
  { PT_R2 * 4,          4, GREGS,  PT_R2 * 4,  4, 4 },
  { PT_R3 * 4,          4, GREGS,  PT_R3 * 4,  4, 4 },
  { PT_R4 * 4,          4, GREGS,  PT_R4 * 4,  4, 4 },
  { PT_R5 * 4,          4, GREGS,  PT_R5 * 4,  4, 4 },
  { PT_R6 * 4,          4, GREGS,  PT_R6 * 4,  4, 4 },
  { PT_R7 * 4,          4, GREGS,  PT_R7 * 4,  4, 4 },
  { PT_R8 * 4,          4, GREGS,  PT_R8 * 4,  4, 4 },
  { PT_R9 * 4,          4, GREGS,  PT_R9 * 4,  4, 4 },
  { PT_R10 * 4,         4, GREGS,  PT_R10 * 4, 4, 4 },
  { PT_R11 * 4,         4, GREGS,  PT_R11 * 4, 4, 4 },
  { PT_R12 * 4,         4, GREGS,  PT_R12 * 4, 4, 4 },
  { PT_R13 * 4,         4, GREGS,  PT_R13 * 4, 4, 4 },
  { PT_R14 * 4,         4, GREGS,  PT_R14 * 4, 4, 4 },
  { PT_R15 * 4,         4, GREGS,  PT_R15 * 4, 4, 4 },
  { PT_R16 * 4,         4, GREGS,  PT_R16 * 4, 4, 4 },
  { PT_R17 * 4,         4, GREGS,  PT_R17 * 4, 4, 4 },
  { PT_R18 * 4,         4, GREGS,  PT_R18 * 4, 4, 4 },
  { PT_R19 * 4,         4, GREGS,  PT_R19 * 4, 4, 4 },
  { PT_R20 * 4,         4, GREGS,  PT_R20 * 4, 4, 4 },
  { PT_R21 * 4,         4, GREGS,  PT_R21 * 4, 4, 4 },
  { PT_R22 * 4,         4, GREGS,  PT_R22 * 4, 4, 4 },
  { PT_R23 * 4,         4, GREGS,  PT_R23 * 4, 4, 4 },
  { PT_R24 * 4,         4, GREGS,  PT_R24 * 4, 4, 4 },
  { PT_R25 * 4,         4, GREGS,  PT_R25 * 4, 4, 4 },
  { PT_R26 * 4,         4, GREGS,  PT_R26 * 4, 4, 4 },
  { PT_R27 * 4,         4, GREGS,  PT_R27 * 4, 4, 4 },
  { PT_R28 * 4,         4, GREGS,  PT_R28 * 4, 4, 4 },
  { PT_R29 * 4,         4, GREGS,  PT_R29 * 4, 4, 4 },
  { PT_R30 * 4,         4, GREGS,  PT_R30 * 4, 4, 4 },
  { PT_R31 * 4,         4, GREGS,  PT_R31 * 4, 4, 4 },
  { (PT_FPR0 + 0) * 4,  8, FPREGS, 0 * 4,      8, 8 },
  { (PT_FPR0 + 2) * 4,  8, FPREGS, 2 * 4,      8, 8 },
  { (PT_FPR0 + 4) * 4,  8, FPREGS, 4 * 4,      8, 8 },
  { (PT_FPR0 + 6) * 4,  8, FPREGS, 6 * 4,      8, 8 },
  { (PT_FPR0 + 8) * 4,  8, FPREGS, 8 * 4,      8, 8 },
  { (PT_FPR0 + 10) * 4, 8, FPREGS, 10 * 4,     8, 8 },
  { (PT_FPR0 + 12) * 4, 8, FPREGS, 12 * 4,     8, 8 },
  { (PT_FPR0 + 14) * 4, 8, FPREGS, 14 * 4,     8, 8 },
  { (PT_FPR0 + 16) * 4, 8, FPREGS, 16 * 4,     8, 8 },
  { (PT_FPR0 + 18) * 4, 8, FPREGS, 18 * 4,     8, 8 },
  { (PT_FPR0 + 20) * 4, 8, FPREGS, 20 * 4,     8, 8 },
  { (PT_FPR0 + 22) * 4, 8, FPREGS, 22 * 4,     8, 8 },
  { (PT_FPR0 + 24) * 4, 8, FPREGS, 24 * 4,     8, 8 },
  { (PT_FPR0 + 26) * 4, 8, FPREGS, 26 * 4,     8, 8 },
  { (PT_FPR0 + 28) * 4, 8, FPREGS, 28 * 4,     8, 8 },
  { (PT_FPR0 + 30) * 4, 8, FPREGS, 30 * 4,     8, 8 },
  { (PT_FPR0 + 32) * 4, 8, FPREGS, 32 * 4,     8, 8 },
  { (PT_FPR0 + 34) * 4, 8, FPREGS, 34 * 4,     8, 8 },
  { (PT_FPR0 + 36) * 4, 8, FPREGS, 36 * 4,     8, 8 },
  { (PT_FPR0 + 38) * 4, 8, FPREGS, 38 * 4,     8, 8 },
  { (PT_FPR0 + 40) * 4, 8, FPREGS, 40 * 4,     8, 8 },
  { (PT_FPR0 + 42) * 4, 8, FPREGS, 42 * 4,     8, 8 },
  { (PT_FPR0 + 44) * 4, 8, FPREGS, 44 * 4,     8, 8 },
  { (PT_FPR0 + 46) * 4, 8, FPREGS, 46 * 4,     8, 8 },
  { (PT_FPR0 + 48) * 4, 8, FPREGS, 48 * 4,     8, 8 },
  { (PT_FPR0 + 50) * 4, 8, FPREGS, 50 * 4,     8, 8 },
  { (PT_FPR0 + 52) * 4, 8, FPREGS, 52 * 4,     8, 8 },
  { (PT_FPR0 + 54) * 4, 8, FPREGS, 54 * 4,     8, 8 },
  { (PT_FPR0 + 56) * 4, 8, FPREGS, 56 * 4,     8, 8 },
  { (PT_FPR0 + 58) * 4, 8, FPREGS, 58 * 4,     8, 8 },
  { (PT_FPR0 + 60) * 4, 8, FPREGS, 60 * 4,     8, 8 },
  { (PT_FPR0 + 62) * 4, 8, FPREGS, 62 * 4,     8, 8 },
  { PT_NIP * 4,         4, GREGS,  PT_NIP * 4, 4, 4 },
  { PT_MSR * 4,         4, GREGS,  PT_MSR * 4, 4, 4 },
  { PT_CCR * 4,         4, GREGS,  PT_CCR * 4, 4, 4 },
  { PT_LNK * 4,         4, GREGS,  PT_LNK * 4, 4, 4 },
  { PT_CTR * 4,         4, GREGS,  PT_CTR * 4, 4, 4 },
  { PT_XER * 4,         4, GREGS,  PT_XER * 4, 4, 4 },
  { PT_MQ * 4,          4, GREGS,  PT_MQ * 4,  4, 4 }
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
  PC_REGNUM = 64
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
read_reg_bytes (int pid, int regno, void *reg_bytes)
{
  ptrace_arg3_type regaddr;
  int regsize;
  int status;

  if (regno < 0 || regno >= NUM_REGS)
    return -1;

  regaddr = reginfo[regno].ptrace_offset;
  regsize = reginfo[regno].ptrace_size;
  status = ptrace_read_user (pid, regaddr, regsize, reg_bytes);

  /* A non-zero status is the errno value from the ptrace call */
  if (status != 0)
    {
      fprintf (stderr, "Error: PT_READ_U at 0x%08lx in process %d\n",
	       (long) regaddr, pid);
      return -1;
    }
  return 0;
}

/* Fetch the register indicated by REGNO into the buffer REG_BYTES.
   The caller must ensure that a sufficiently large buffer has been
   allocated.
   Returns 0 for success, -1 for failure.  */

static int
write_reg_bytes (int pid, int regno, const void *reg_bytes)
{
  ptrace_arg3_type regaddr;
  int regsize;
  int status;

  if (regno < 0 || regno >= NUM_REGS)
    return -1;

  regaddr = reginfo[regno].ptrace_offset;
  regsize = reginfo[regno].ptrace_size;
  status = ptrace_write_user (pid, regaddr, regsize, reg_bytes);

  /* A non-zero status is the errno value from the ptrace call */
  if (status != 0)
    {
      fprintf (stderr, "Error: PT_WRITE_U status=%d at 0x%08lx in process %d\n",
	       status, (long) regaddr, pid);
      return -1;
    }
  return 0;
}


/* Fetch and return the value of register REGNO.  Helper function for
   debug_get_pc().  This is the PEEKUSER_POKEUSER_REGINFO version.  */
static unsigned long
debug_get_reg (pid_t pid, int regno)
{
  ptrace_xfer_type value;

  if (read_reg_bytes (pid, regno, &value) < 0)
    return 0;
  else
    return (unsigned long) value;
}

/* Fetch and return the value of the PC.  Needed by thread-db.c.  */
unsigned long
debug_get_pc (struct gdbserv *serv, pid_t pid)
{
  return debug_get_reg (pid, PC_REGNUM);
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

  memset (tmp_buf, 0, reginfo[regno].proto_size);

  if (reginfo[regno].whichregs != NOREGS)
    {
      /* Get the register value. */
      status = read_reg_bytes (process->pid, regno, tmp_buf);
      if (status < 0)
	return -1;	/* fail */
    }

  /* Copy the bytes to the gdbserv_reg struct.  */
  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].proto_size, reg);

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
      int len;

      /* Clear out a temporary buffer into which to fetch the bytes that
	 we'll be setting.  We do this in case ptrace_size != proto_size.  */
      memset (tmp_buf, 0, reginfo[regno].ptrace_size);

      /* Copy the bytes from the gdbserv_reg struct to our temporary buffer.  */
      gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, reg);

      if (len != reginfo[regno].proto_size)
	return -1;

      /* Write the child's register. */
      status = write_reg_bytes (process->pid, regno, tmp_buf);
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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != whichregs)
    {
      return -1;
    }

  regbytes = ((char *) regset) + reginfo[regno].regset_field_offset;

  memset (tmp_buf, 0, reginfo[regno].proto_size);
  memcpy (tmp_buf, regbytes, reginfo[regno].regset_field_size);

  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].proto_size, reg);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;
  int len;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != whichregs)
    {
      return -1;
    }

  memset (tmp_buf, 0, reginfo[regno].regset_field_size);
  gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, reg);

  if (len != reginfo[regno].proto_size)
    return -1;

  regbytes = ((char *) regset) + reginfo[regno].regset_field_offset;

  memcpy (regbytes, tmp_buf, reginfo[regno].regset_field_size);

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

	  memset (tmp_buf, 0, reginfo[regno].proto_size);

	  /* Get the register value. */
	  status = read_reg_bytes (pid, regno, tmp_buf);
	  if (status < 0)
	    return -1;	/* fail */

	  /* Copy the bytes to the gdbserv_reg struct.  */
	  gdbserv_host_bytes_to_reg (serv, tmp_buf,
	                             reginfo[regno].proto_size, &reg);

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
	  int len;
	  int status;

	  /* Fetch the reg from the regset.  */
	  reg_from_regset (serv, &reg, regno, regset, whichregs);

	  /* Clear out a temporary buffer into which to put the bytes that
	     we'll be setting.  We do this in case ptrace_size != proto_size.  */
	  memset (tmp_buf, 0, reginfo[regno].ptrace_size);

	  /* Copy the bytes from the gdbserv_reg struct to our temporary buffer.  */
	  gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, &reg);
	  if (len != reginfo[regno].proto_size)
	    return -1;

	  /* Write the child's register. */
	  status = write_reg_bytes (pid, regno, tmp_buf);
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
  char tmp_buf[MAX_REG_SIZE];

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
      /* Do nothing.  */
    }
  else
    {
      return -1;
    }

  /* Adjust buf to point at the starting byte of the register.  */
  buf += reginfo[regno].offset;

  /* We go through these memset / memcpy shenanigans in case
     proto_size != ptrace_size.  */
  memset (tmp_buf, 0, reginfo[regno].proto_size);
  if (reginfo[regno].ptrace_size > 0)
    memcpy (tmp_buf, buf, reginfo[regno].ptrace_size);

  /* Copy the bytes to the gdbserv_reg struct.  */
  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].proto_size, reg);

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
  char tmp_buf[MAX_REG_SIZE];
  int len;

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

  /* Clear out a temporary buffer into which to fetch the bytes that
     we'll be setting.  We do this in case ptrace_size != proto_size.  */
  memset (tmp_buf, 0, reginfo[regno].ptrace_size);

  /* Copy the bytes from the gdbserv_reg struct to our temporary buffer.  */
  gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, reg);

  if (len != reginfo[regno].proto_size)
    return -1;

  /* Copy the bytes to the appropriate position in the ptrace struct.  */
  memcpy (buf, tmp_buf, reginfo[regno].ptrace_size);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != GREGS)
    {
      return -1;
    }

  regbytes = ((char *) gregset) + reginfo[regno].offset;

  memset (tmp_buf, 0, reginfo[regno].proto_size);
  memcpy (tmp_buf, regbytes, reginfo[regno].ptrace_size);

  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].proto_size, reg);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;
  int len;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != GREGS)
    {
      return -1;
    }

  regbytes = ((char *) gregset) + reginfo[regno].offset;

  memset (tmp_buf, 0, reginfo[regno].ptrace_size);
  gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, reg);

  if (len != reginfo[regno].proto_size)
    return -1;

  memcpy (regbytes, tmp_buf, reginfo[regno].ptrace_size);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPREGS)
    {
      return -1;
    }

  regbytes = ((char *) fpregset) + reginfo[regno].offset;

  memset (tmp_buf, 0, reginfo[regno].proto_size);
  memcpy (tmp_buf, regbytes, reginfo[regno].ptrace_size);

  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].proto_size, reg);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;
  int len;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPREGS)
    {
      return -1;
    }

  regbytes = ((char *) fpregset) + reginfo[regno].offset;

  memset (tmp_buf, 0, reginfo[regno].ptrace_size);
  gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, reg);

  if (len != reginfo[regno].proto_size)
    return -1;

  memcpy (regbytes, tmp_buf, reginfo[regno].ptrace_size);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPXREGS)
    {
      return -1;
    }

  regbytes = ((char *) xregset) + reginfo[regno].offset;

  memset (tmp_buf, 0, reginfo[regno].proto_size);
  memcpy (tmp_buf, regbytes, reginfo[regno].ptrace_size);

  gdbserv_host_bytes_to_reg (serv, tmp_buf, reginfo[regno].proto_size, reg);

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
  char tmp_buf[MAX_REG_SIZE];
  char *regbytes;
  int len;

  if (regno < 0 || regno >= NUM_REGS 
      || reginfo[regno].whichregs != FPXREGS)
    {
      return -1;
    }

  regbytes = ((char *) xregset) + reginfo[regno].offset;

  memset (tmp_buf, 0, reginfo[regno].ptrace_size);
  gdbserv_host_bytes_from_reg (serv, tmp_buf, &len, reg);

  if (len != reginfo[regno].proto_size)
    return -1;

  memcpy (regbytes, tmp_buf, reginfo[regno].ptrace_size);

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
linux_read_reg (int pid, int regno, ptrace_xfer_type *regval)
{
  unsigned long u_regs_base = U_REGS_OFFSET;
  ptrace_arg3_type regaddr;

  if ((regaddr = linux_register_offset (regno)) < 0)
    return -1;	/* fail */

  regaddr += U_REGS_OFFSET;
  errno = 0;
  ptrace_read_user (pid, regaddr, sizeof (*regval), regval);

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
linux_write_reg (int pid, int regno, ptrace_xfer_type regval)
{
  unsigned long u_regs_base = U_REGS_OFFSET;
  ptrace_arg3_type regaddr;

  if ((regaddr = linux_register_offset (regno)) < 0)
    return -1;	/* fail */

  regaddr += U_REGS_OFFSET;
  errno = 0;
  ptrace_write_user (pid, regaddr, sizeof (regval), &regval);
  if (errno)
    {
      fprintf (stderr, "PT_WRITE_U 0x%08lx from 0x%08lx in process %d\n",
	       (long) regval, (long) regaddr, pid);
      return -1;
    }
  else
    return 0;
}

/* Helper function for debug_get_pc().  It fetches and returns the
   value of REGNO.  */
static unsigned long
debug_get_reg (pid_t pid, int regno)
{
  ptrace_xfer_type value;

  if (linux_read_reg (pid, regno, &value) < 0)
    return 0;
  else
    return (unsigned long) value;
}

/* Return the value of PC.  Needed by thread-db.c.  */
unsigned long
debug_get_pc (struct gdbserv *serv, pid_t pid)
{
  return debug_get_reg (pid, PC_REGNUM);
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
  if (linux_read_reg (process->pid, regno, &regval) < 0)
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
  struct child_process *process = gdbserv_target_data (serv);
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
  if (linux_write_reg (process->pid, regno, regval) < 0)
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
  if (ptrace_read_user (pid, 0, sizeof (GREGSET_T), (char *) gregset) != 0)
    return -1;
  return 0;
}

/* Function: put_gregset
   write the gregset for pid.
   Return -1 for failure, zero for success. */

static int
put_gregset (struct gdbserv *serv, int pid, const GREGSET_T gregset)
{
  if (ptrace_write_user (pid, 0, sizeof (GREGSET_T), 
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

  if (!strcmp (cmd, "1"))
    {
      process->debug_backend = 1;
    }
  else if (!strcmp (cmd, "0"))
    {
      process->debug_backend = 0;
    }
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
#if defined(_MIPSEL) || defined(_MIPSEB)
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
  extern int thread_db_noisy;
  unsigned long pc;
  int status;

  status = read_reg_as_ulong (serv, pid, PC_REGNUM, &pc);
  if (status < 0)
    return -1;

  pc -= 1;
  if (thread_db_noisy)
    fprintf (stderr, "<decr_pc_after_break: pid %d, addr 0x%08x>\n", pid, pc);
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


#if defined(_MIPSEL) || defined(_MIPSEB)

/* 
 * Worker function to get and return a register
 */

static ptrace_xfer_type
mips_get_reg(struct gdbserv *serv, int regno)
{
  ptrace_xfer_type value;
  struct child_process *process = gdbserv_target_data (serv);
  pid_t pid = process->pid;

  if (read_reg_bytes (pid, regno, &value) < 0)
    return 0;
  else
    return value;
}

/*
 * mips singlestep
 *
 * necessary since no support in ptrace.
 */

static void
mips_singlestep_program (struct gdbserv *serv)
{
  struct child_process *process = gdbserv_target_data (serv);
  ptrace_arg3_type targ;
  ptrace_xfer_type mips_pc;

  union mips_instruction insn;
  int is_branch, is_cond, i;

  ptrace_xfer_type bp_inst = 0x0000000d;

  /* FIXME: handle signals! */
  if (process->debug_backend)
    fprintf (stderr, "mips_singlestep_program %ld\n", process->signal_to_send);
  process->stop_signal = 0;
  process->stop_status = 0;

  errno = 0;

  /* Following is equiv to  ptrace (PTRACE_SINGLESTEP, process->pid, 1L, process->signal_to_send); */

  /* get the current PC */
  mips_pc = mips_get_reg(serv, PC_REGNUM);			
  targ = mips_pc;

  /* get the word there (opcode) */

  insn.word = ptrace (PTRACE_PEEKTEXT, process->pid, mips_pc, 0L);

  is_branch = is_cond = 0;

  /* set flag so handle_waitstatus can restore breakpoint stuff */
  process->is_ss = 1;					

  switch (insn.i_format.opcode) {
  /*
   * jr and jalr are in r_format format.
   */
  case spec_op:
    switch (insn.r_format.func) {
    case jalr_op:
    case jr_op:
    	targ = mips_get_reg(serv, insn.r_format.rs);
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

  /*
   * These are conditional.
   */
  case beq_op:
  case beql_op:
  case bne_op:
  case bnel_op:
  case blez_op:
  case blezl_op:
  case bgtz_op:
  case bgtzl_op:
  case cop0_op:
  case cop1_op:
  case cop2_op:
  case cop1x_op:
    is_branch = is_cond = 1;
    targ += 4 + (insn.i_format.simmediate << 2);
    break;
  }
      	
  if (is_branch) {
    i = 0;
    if (is_cond && targ != (mips_pc + 8)) {
    	process->ss_info[i].ss_addr = mips_pc + 8;
 	process->ss_info[i++].ss_val = ptrace (PTRACE_PEEKTEXT, process->pid, mips_pc+8, 0L);
	ptrace (PTRACE_POKETEXT, process->pid, mips_pc+8, bp_inst);
    }
    process->ss_info[i].ss_addr = targ;
    process->ss_info[i].ss_val = ptrace (PTRACE_PEEKTEXT, process->pid, targ, 0L);
    ptrace (PTRACE_POKETEXT, process->pid, targ, bp_inst);
  } else {
    process->ss_info[0].ss_addr = mips_pc + 4;
    process->ss_info[0].ss_val = ptrace (PTRACE_PEEKTEXT, process->pid, mips_pc+4, 0L);
    process->ss_info[1].ss_addr = 0;
    ptrace (PTRACE_POKETEXT, process->pid, mips_pc+4, bp_inst);
  }

  process->signal_to_send = 0;
  ptrace (PTRACE_CONT, process->pid, 1L, process->signal_to_send); 
}
#endif /* _MIPSEL */


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
