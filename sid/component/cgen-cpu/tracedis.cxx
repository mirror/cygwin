// tracedis.cxx - disassembly tracing support.  -*- C++ -*-

// Copyright (C) 2001-2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <cstdlib>
#include <stdarg.h>
#include "config.h"
#include "libiberty.h"
#include "tracedis.h"
#include "sidcomputil.h"
#include "sidcpuutil.h"

void register_name(enum bfd_architecture, const char *, int);

// XXX: for compatibility with older libraries
static
int trace_printf(void *obj_ptr, const char *fmt, ...)
{
  va_list ap;
  char buf[1024];
  sidutil::basic_cpu* object = (sidutil::basic_cpu*) obj_ptr;
  
  va_start (ap, fmt);
  vsprintf (buf, fmt, ap);
  object->trace_stream << buf;

  // XXX: FIXME.
  return 0;
}

void
cgen_disassemble(bfd_vma pc,
		 disassemble_info *info,
		 void *this_ptr,
		 READMEM read_mem_func,
		 MEMERR memory_error_func,
		 PRINTADDR print_addr_func,
		 SYMATADDR sym_at_addr_func,
		 disassembler_ftype fp,
		 enum bfd_flavour flavour,
		 enum bfd_architecture arch,
		 int machine,
		 enum bfd_endian endian,
		 const char *name,
		 CGEN_BITSET *isas)
{
  register_name(arch, name, machine);
  INIT_DISASSEMBLE_INFO(*info, this_ptr, trace_printf);
  info->application_data = this_ptr;
  info->flavour = flavour;
  info->insn_sets = isas; /* may be NULL */
  info->arch = arch;
  info->mach = machine;
  info->endian = endian;
  info->read_memory_func = read_mem_func;
  info->memory_error_func = memory_error_func;
  info->print_address_func = print_addr_func;
  info->symbol_at_address_func = sym_at_addr_func;

  trace_printf (this_ptr, "0x%08x\t", (unsigned int) pc);
  (void) (*fp) (pc, info);
  trace_printf (this_ptr, "\t");
}

// opcodes needs:
//	enum bfd_architecture bfd_get_arch(bfd *abfd);
//		- disassembler() calls it at the top.  we don't use disassembler().
//	const bfd_arch_info_type *bfd_lookup_arch(enum bfd_architecture arch, unsigned long machine);
//		- cgen generated disassemblers call this to find subarch(?).  this one is not easy to
//		  fix as it uses bfd data.
//	bfd_vma bfd_get_bits (bfd_byte *addr, int bits, boolean big_p);
//	void bfd_put_bits (bfd_vma data, bfd_byte *addr, int bits, boolean big_p);
//		- these two are small and can be replicated.
//
// so that only really leaves bfd_lookup_arch() as an issue...we can hack it.

extern "C" enum bfd_architecture
bfd_get_arch(bfd *abfd)
{ 
  return static_cast<enum bfd_architecture> (0);
}

/* Stolen from libbfd.  */

extern "C" bfd_vma
bfd_getb16 (register const void *addr)
{
  const bfd_byte *byteaddr = static_cast <const bfd_byte *> (addr);
  return (byteaddr[0] << 8) | byteaddr[1];
}

extern "C" bfd_vma
bfd_getl16 (register const void *addr)
{
  const bfd_byte *byteaddr = static_cast <const bfd_byte *> (addr);
  return (byteaddr[1] << 8) | byteaddr[0];
}

extern "C" bfd_vma
bfd_getb32 (register const void *addr)
{
  const bfd_byte *byteaddr = static_cast <const bfd_byte *> (addr);
  unsigned long v;

  v = (unsigned long) byteaddr[0] << 24;
  v |= (unsigned long) byteaddr[1] << 16;
  v |= (unsigned long) byteaddr[2] << 8;
  v |= (unsigned long) byteaddr[3];
  return (bfd_vma) v;
}

extern "C" bfd_vma
bfd_getl32 (register const void *addr)
{
  const bfd_byte *byteaddr = static_cast <const bfd_byte *> (addr);
  unsigned long v;

  v = (unsigned long) byteaddr[0];
  v |= (unsigned long) byteaddr[1] << 8;
  v |= (unsigned long) byteaddr[2] << 16;
  v |= (unsigned long) byteaddr[3] << 24;
  return (bfd_vma) v;
}

extern "C" void
bfd_put_bits (bfd_uint64_t data, void* addr, int bits, bfd_boolean big_p)
{
  bfd_byte *byteaddr = static_cast <bfd_byte *> (addr);
  int i;
  int bytes;

  if (bits % 8 != 0)
    abort ();

  bytes = bits / 8;
  for (i = 0; i < bytes; i++)
    {
      int index = big_p ? bytes - i - 1 : i;

      byteaddr[index] = (bfd_byte) data;
      data >>= 8;
    }
}

/* Stolen from libbfd.  */
extern "C" bfd_uint64_t
bfd_get_bits (const void* addr, int bits, int big_p)
{
  const bfd_byte *byteaddr = static_cast <const bfd_byte *> (addr);
  bfd_uint64_t data;
  int i;
  int bytes;

  if (bits % 8 != 0)
    abort ();

  data = 0;
  bytes = bits / 8;
  for (i = 0; i < bytes; i++)
    {
      int index = big_p ? i : bytes - i - 1;

      data = (data << 8) | byteaddr[index];
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
  int machine;
  const char *name;
};

struct bfd_arch_hack *hack_list;

void
register_name(enum bfd_architecture arch, const char *name, int machine)
{
  struct bfd_arch_hack *p;

  if (hack_list == NULL)
    {
      hack_list = (struct bfd_arch_hack *)xmalloc(sizeof *hack_list);
      hack_list->next = NULL;
      hack_list->arch = arch;
      hack_list->machine = machine;
      hack_list->name = name;
      return;
    }

  for (p = hack_list; p; p = p->next)
    if (strcmp(p->name, name) == 0)
      {
	p->arch = arch;
	p->machine = machine;
	return;
      }
  p = (struct bfd_arch_hack *)xmalloc(sizeof *hack_list);
  p->next = hack_list;
  p->arch = arch;
  p->machine = machine;
  p->name = name;
}

extern "C" const bfd_arch_info_type *
bfd_lookup_arch (enum bfd_architecture arch, unsigned long machine)
{ 
  static bfd_arch_info_type info;
  struct bfd_arch_hack *b;

  for (b = hack_list; b->name; b++)
    {
      if (b->arch == arch && b->machine == machine)
	{
          info.printable_name = b->name;
          return &info;
	}
    }

  return NULL;
}    
