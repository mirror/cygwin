// tracedis.c - disassembly tracing support.  -*- C -*-

// Copyright (C) 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "tracedis.h"

void register_name(enum bfd_architecture, const char *);

void
cgen_disassemble(bfd_vma pc,
		 disassemble_info *info,
		 void *this,
		 READMEM read_mem_func,
		 MEMERR memory_error_func,
		 PRINTADDR print_addr_func,
		 SYMATADDR sym_at_addr_func,
		 disassembler_ftype fp,
		 enum bfd_flavour flavour,
		 enum bfd_architecture arch,
		 enum bfd_endian endian,
		 const char *name,
		 unsigned long isa_mask)
{
  register_name(arch, name);
  INIT_DISASSEMBLE_INFO(*info, stdout, fprintf);
  info->application_data = this;
  info->flavour = flavour;
  info->insn_sets = isa_mask; /* may be 0 */
  info->arch = arch;
  info->endian = endian;
  info->read_memory_func = read_mem_func;
  info->memory_error_func = memory_error_func;
  info->print_address_func = print_addr_func;
  info->symbol_at_address_func = sym_at_addr_func;

  printf("0x%08x\t", (unsigned int)pc);
  (void) (*fp) (pc, info);
  printf("\t");
}

// opcodes needs:
//	enum bfd_architecture bfd_get_arch(bfd *abfd);
//		- disassembler() calls it at the top.  we don't use disassembler().
//	const bfd_arch_info_type *bfd_lookup_arch(enum bfd_architecture arch, unsigned long machine);
//		- cgen generated disassemblers call this to find subarch(?).  this one is not easy to
//		  fix as it uses bfd data.
//	bfd_vma bfd_get_bits (bfd_byte *addr, int bits, bfd_boolean big_p);
//	void bfd_put_bits (bfd_vma data, bfd_byte *addr, int bits, bfd_boolean big_p);
//		- these two are small and can be replicated.
//
// so that only really leaves bfd_lookup_arch() as an issue...we can hack it.

enum bfd_architecture
bfd_get_arch(bfd *abfd)
{ 
  return 0;
}

/* Stolen from libbfd.  */

bfd_vma
bfd_getb16 (addr)
     register const bfd_byte *addr;
{
  return (addr[0] << 8) | addr[1];
}

bfd_vma
bfd_getl16 (addr)
     register const bfd_byte *addr;
{
  return (addr[1] << 8) | addr[0];
}

bfd_vma
bfd_getb32 (addr)
     register const bfd_byte *addr;
{
  unsigned long v;

  v = (unsigned long) addr[0] << 24;
  v |= (unsigned long) addr[1] << 16;
  v |= (unsigned long) addr[2] << 8;
  v |= (unsigned long) addr[3];
  return (bfd_vma) v;
}

bfd_vma
bfd_getl32 (addr)
     register const bfd_byte *addr;
{
  unsigned long v;

  v = (unsigned long) addr[0];
  v |= (unsigned long) addr[1] << 8;
  v |= (unsigned long) addr[2] << 16;
  v |= (unsigned long) addr[3] << 24;
  return (bfd_vma) v;
}

void
bfd_put_bits (data, addr, bits, big_p)
     bfd_vma data;
     bfd_byte *addr;
     int bits;
     bfd_boolean big_p;
{
  int i;
  int bytes;

  if (bits % 8 != 0)
    abort ();

  bytes = bits / 8;
  for (i = 0; i < bytes; i++)
    {
      int index = big_p ? bytes - i - 1 : i;

      addr[index] = (bfd_byte) data;
      data >>= 8;
    }
}

/* Stolen from libbfd.  */
bfd_vma
bfd_get_bits (addr, bits, big_p)
     bfd_byte *addr;
     int bits;
     bfd_boolean big_p;
{
  bfd_vma data;
  int i;
  int bytes;

  if (bits % 8 != 0)
    abort ();

  data = 0;
  bytes = bits / 8;
  for (i = 0; i < bytes; i++)
    {
      int index = big_p ? i : bytes - i - 1;

      data = (data << 8) | addr[index];
    }

  return data;
}

/* However, bfd_lookup_arch() is a lot harder and requires us to manage
   our own list of architectures, and return a bfd_arch_info_type with
   just the name set.  */

/* This is a hack.  */
struct bfd_arch_hack {
  struct bfd_arch_hack *next;
  enum bfd_architecture arch;
  const char *name;
};

struct bfd_arch_hack *hack_list;

void
register_name(enum bfd_architecture arch, const char *name)
{
  struct bfd_arch_hack *p;

  if (hack_list == NULL)
    {
      hack_list = (struct bfd_arch_hack *)xmalloc(sizeof *hack_list);
      hack_list->next = NULL;
      hack_list->arch = arch;
      hack_list->name = name;
      return;
    }

  for (p = hack_list; p; p = p->next)
    if (strcmp(p->name, name) == 0)
      {
	p->arch = arch;
	return;
      }
  p = (struct bfd_arch_hack *)xmalloc(sizeof *hack_list);
  p->next = hack_list;
  p->arch = arch;
  p->name = name;
}

const bfd_arch_info_type *
bfd_lookup_arch (arch, machine)
     enum bfd_architecture arch;
     unsigned long machine;
{ 
  static bfd_arch_info_type info;
  struct bfd_arch_hack *b;

  for (b = hack_list; b->name; b++)
    {
      if (b->arch == arch)
	{
          info.printable_name = b->name;
          return &info;
	}
    }

  return NULL;
}    
