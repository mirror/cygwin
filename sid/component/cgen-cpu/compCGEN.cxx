// compCGEN.cxx - CPU components.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "tconfig.h"

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "cgen-cpu.h"

extern "C" {
#include "bfd.h"
#include "dis-asm.h"
#include "tracedis.h"
}

#if SIDTARGET_ARM
#include "arm7f.h"
#endif
#if SIDTARGET_M32R
#include "m32rbf.h"
#endif
#if SIDTARGET_XSTORMY16
#include "xstormy16.h"
#endif

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace cgen;


// ----------------------------------------------------------------------------
cgen_bi_endian_cpu::cgen_bi_endian_cpu ()
{
  trace_count = 0;
  warnings_enabled = false;
  add_attribute ("enable-warnings?", & warnings_enabled, "setting");
  this->engine_type = ENGINE_UNKNOWN;
  add_attribute_virtual ("engine-type", this, 
			 & cgen_bi_endian_cpu::set_engine_type,
			 & cgen_bi_endian_cpu::get_engine_type,
			 "setting");
}


cgen_bi_endian_cpu::~cgen_bi_endian_cpu () throw()
{
}



#if 0
void 
bi_endian_cpu::destream_state (istream& i)
{
  // call base class first
  cgen_bi_endian_cpu::destream_state (i);

  string key;
  i >> key;
  if (key != "endianness")
    {
      i.setstate (ios::badbit);
      return;
    }

  i >> endian;
  update_endian ();
}
#endif


// ----------------------------------------------------------------------------

#if 0
void
cgen_cpu::stream_state (ostream& o) const
{
  o << "cgen-cpu "
    << trace_result_p << " " 
    << trace_extract_p << " "
    << step_insn_count << " "
    << warnings_enabled << " "
    << static_cast<int>(engine_type) << " "
    << step_cycles;
}


void
cgen_cpu::destream_state (istream& i)
{
  string key;

  i >> key;
  if (key != "cgen-cpu")
    {
      i.setstate (ios::badbit);
      return;
    }

  i >> trace_result_p
    >> trace_extract_p
    >> step_insn_count
    >> warnings_enabled;
  int et;
  i >> et;
  engine_type = static_cast<enum engine_type>(et);
  i >> step_cycles;
}

#endif

// Basic engine support.

string
cgen_bi_endian_cpu::get_engine_type ()
{
  switch (this->engine_type)
    {
    case ENGINE_UNKNOWN : return "unknown";
    case ENGINE_SIMPLE : return "simple";
    case ENGINE_SCACHE : return "scache";
    case ENGINE_PBB : return "pbb";
    }
  assert (("bad engine_type", 0));
}

component::status
cgen_bi_endian_cpu::set_engine_type (const string& s)
{
  if (s == "simple")
    this->engine_type = ENGINE_SIMPLE;
  else if (s == "scache")
    this->engine_type = ENGINE_SCACHE;
  else if (s == "pbb")
    this->engine_type = ENGINE_PBB;
  else
    return component::bad_value;
  return component::ok;
}


// Disassembly support.

void
cgen::cgen_bi_endian_cpu::disassemble (PCADDR pc,
  disassembler_ftype printfn,
  enum bfd_flavour flavour,
  enum bfd_architecture arch,
  enum bfd_endian endian,
  const char *name,
  unsigned long isa_mask)
{
  cgen_disassemble((bfd_vma)pc, &this->info, this,
                   & cgen_bi_endian_cpu::cgen_read_memory,
                   & cgen_bi_endian_cpu::cgen_memory_error,
                   & cgen_bi_endian_cpu::cgen_print_address,
                   & cgen_bi_endian_cpu::cgen_symbol_at_address,
                   printfn,
                   flavour,
                   arch,
                   endian,
		   name,
		   isa_mask);
}

int
cgen_bi_endian_cpu::cgen_read_memory(bfd_vma memaddr, bfd_byte *myaddr,
		     unsigned int length,
		     struct disassemble_info *info)
{
  cgen_bi_endian_cpu *thisp = static_cast<cgen_bi_endian_cpu *>(info->application_data);

  switch (length) {
#if 0 // XXX not sure if this has byte order dependancies or not
  case 1:
    *((host_int_1 *)myaddr) = thisp->read_insn_memory_1(0, memaddr);
    break;
  case 2:
    *((host_int_2 *)myaddr) = thisp->read_insn_memory_2(0, memaddr);
    break;
  case 4:
    *((host_int_4 *)myaddr) = thisp->read_insn_memory_4(0, memaddr);
    break;
  case 8:
    *((host_int_8 *)myaddr) = thisp->read_insn_memory_8(0, memaddr);
    break;
#endif
  default:
    {
      big_int_1 value;
      for (int i = 0; i < length; i++)
	{
	  sid::bus* bus;
	  bus = (thisp->disassembler_bus) ? thisp->disassembler_bus : thisp->insn_bus;
	  if (UNLIKELY (bus->read (memaddr + i, value) != sid::bus::ok))
	    return 1;
	  else
	    *(myaddr + i) = value;
	}
    }
  }
  return 0;
}

void
cgen_bi_endian_cpu::cgen_memory_error(int status, bfd_vma memaddr,
		       struct disassemble_info *info)
{
  cgen_bi_endian_cpu *thisp = static_cast<cgen_bi_endian_cpu *>(info->application_data);

  thisp->trace_stream 
    << "memory_error: status " << status << " addr 0x" << hex << memaddr << dec << endl;
}

void
cgen_bi_endian_cpu::cgen_print_address(bfd_vma addr, struct disassemble_info *info)
{
  cgen_bi_endian_cpu *thisp = static_cast<cgen_bi_endian_cpu *>(info->application_data);

  thisp->trace_stream
    << "0x" << hex << addr << dec;
}

int
cgen_bi_endian_cpu::cgen_symbol_at_address(bfd_vma addr,
					   struct disassemble_info * info)
{
  cerr << "cgen_bi_endian_cpu::symbol_at_address!?" << endl;
  return 0;
}


// Tracing support.

void
cgen_bi_endian_cpu::begin_trace (PCADDR pc, const char* insn_name)
{
  this->trace_stream
    << "0x" << hex << pc << dec
    << ": " << insn_name << "\t";
}

void
cgen_bi_endian_cpu::end_trace ()
{
  this->trace_stream << endl;
}

// Counter support

void
cgen_bi_endian_cpu::trace_counter (PCADDR pc)
{
  this->trace_stream
    << this->trace_count++ << ' ' 
    << (this->sched_query.now()-1) << '\t';

  // Invalidate any local icaches; they distort approximate cycle counting.
  this->flush_icache (pc);
}


// ----------------------------------------------------------------------------


static
vector<string>
compCGENListTypes ()
{
  vector<string> types;
#if SIDTARGET_M32R
  types.push_back ("hw-cpu-m32r/d");
#endif
#if SIDTARGET_ARM
  types.push_back ("hw-cpu-arm7t");
#endif
#if SIDTARGET_XSTORMY16
  types.push_back ("hw-cpu-xstormy16");
#endif
  return types;
}


static
component*
compCGENCreate (const string& typeName)
{
#if SIDTARGET_M32R
  if(typeName == "hw-cpu-m32r/d")
    return new m32rbf::m32rbf_cpu ();
#endif
#if SIDTARGET_ARM
  if (typeName == "hw-cpu-arm7t")
    return new arm7f::arm7f_cpu ();
#endif
#if SIDTARGET_XSTORMY16
  if (typeName == "hw-cpu-xstormy16")
    return new xstormy16::xstormy16_cpu ();
#endif


  return 0;
}

static
void
compCGENDelete (component* c)
{
  // cgen_cpu is a base class of all objects that may have been created here
  delete dynamic_cast<cgen_bi_endian_cpu*>(c);
}


// static object
extern const component_library cgen_component_library;

const component_library cgen_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compCGENListTypes, 
  & compCGENCreate,
  & compCGENDelete
};
