/* sh64.c - Implementations of hand-written functions for the sh
   simulator. -*- C++ -*-

   Copyright (C) 2006 Red Hat.
   This file is part of SID and is licensed under the GPL.
   See the file COPYING.SID for conditions for redistribution.  */

/* These C functions are not used but needed for static linking.
   We need to refer to the ELF header structure.  */

#include "sysdep.h"
#include "dis-asm.h"
#include "sh64-opc.h"
#include "libiberty.h"
#include "elf-bfd.h"
#include "elf/sh.h"
#include "elf32-sh64.h"

enum sh64_elf_cr_type
sh64_get_contents_type (asection *sec, bfd_vma addr, sh64_elf_crange *rangep)
{
  return CRT_NONE;
}

