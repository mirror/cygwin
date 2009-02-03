// compCGEN.cxx - CPU components.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2006 Red Hat.
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
}
#include "tracedis.h"

#if SIDTARGET_ARM
#include "arm7f.h"
#endif
#if SIDTARGET_M32R
#include "m32rbf.h"
#endif
#if SIDTARGET_MEP
#include "mep_basic.h"
// begin-mep-includes
#include "mep_ext1.h"
// end-mep-includes
#endif
#if SIDTARGET_MT
#include "mt.h"
#endif
#if SIDTARGET_SH || SIDTARGET_SH64
#include "sh2.h"
#include "sh2e.h"
#include "sh2a_fpu.h"
#include "sh2a_nofpu.h"
#include "sh3.h"
#include "sh3e.h"
#include "sh4.h"
#include "sh4_nofpu.h"
#include "sh4a.h"
#include "sh4a_nofpu.h"
#include "sh4al.h"
#endif
#if SIDTARGET_SH64
#include "sh5.h"
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
  loader = 0;
  branch_was_return = false;
  warnings_enabled = false;
  add_attribute ("enable-warnings?", & warnings_enabled, "setting");
  this->engine_type = ENGINE_UNKNOWN;
  add_attribute_virtual ("engine-type", this, 
			 & cgen_bi_endian_cpu::set_engine_type,
			 & cgen_bi_endian_cpu::get_engine_type,
			 "setting");
  add_uni_relation("loader", &loader);
  add_pin ("disassembly-symbol-address", & disassembly_symbol_address_pin);
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
  CGEN_BITSET *isas,
  int machine)
{
  cgen_disassemble((bfd_vma)pc, &this->info, this,
                   & cgen_bi_endian_cpu::cgen_read_memory,
                   & cgen_bi_endian_cpu::cgen_memory_error,
                   & cgen_bi_endian_cpu::cgen_print_address,
                   & cgen_bi_endian_cpu::cgen_symbol_at_address,
                   printfn,
                   flavour,
                   arch,
		   machine,
                   endian,
		   name,
		   isas);
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

  thisp->trace_stream << "0x" << hex << addr << dec;

  if (cgen_symbol_at_address (addr, info))
    if (! thisp->symbol_at_address.empty ())
      thisp->trace_stream << " <" << thisp->symbol_at_address << '>';
}

int
cgen_bi_endian_cpu::cgen_symbol_at_address(bfd_vma addr,
					   struct disassemble_info * info)
{
  cgen_bi_endian_cpu *thisp = static_cast<cgen_bi_endian_cpu *>(info->application_data);
  if (thisp->loader)
    {
      thisp->disassembly_symbol_address_pin.drive (addr);
      thisp->symbol_at_address = thisp->loader->attribute_value("current-function");
    }
  else
    thisp->symbol_at_address = "";
    
  if (thisp->symbol_at_address.empty ())
    {
      cerr << "cgen_bi_endian_cpu::symbol_at_address!?" << endl;
      return 0; // failed
    }

  return 1; // success
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
  trace_stream.end_line ();
}

// Counter support

void
cgen_bi_endian_cpu::trace_counter (PCADDR pc)
{
  this->trace_stream
    << this->total_insn_count << ' ' 
    << this->total_insn_count + this->total_latency << '\t';
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
#if SIDTARGET_MEP
  types.push_back ("hw-cpu-mep");
  // begin-mep-types
  types.push_back ("hw-cpu-mep-ext1");
  // end-mep-types
#endif
#if SIDTARGET_MT
  types.push_back ("hw-cpu-mt");
#endif
#if SIDTARGET_SH || SIDTARGET_SH64
  types.push_back ("hw-cpu-sh2");
  types.push_back ("hw-cpu-sh2e");
  types.push_back ("hw-cpu-sh2a-nofpu");
  types.push_back ("hw-cpu-sh2a-fpu-single");
  types.push_back ("hw-cpu-sh2a-fpu");
  types.push_back ("hw-cpu-sh3");
  types.push_back ("hw-cpu-sh3e");
  types.push_back ("hw-cpu-sh4");
  types.push_back ("hw-cpu-sh4-nofpu");
  types.push_back ("hw-cpu-sh4-single");
  types.push_back ("hw-cpu-sh4a");
  types.push_back ("hw-cpu-sh4a-nofpu");
  types.push_back ("hw-cpu-sh4a-single");
  types.push_back ("hw-cpu-sh4al");
#endif
#if SIDTARGET_SH64
  types.push_back ("hw-cpu-sh5-compact");
  types.push_back ("hw-cpu-sh5-32media");
  types.push_back ("hw-cpu-sh5-64media");
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
#if SIDTARGET_MEP
  if (typeName == "hw-cpu-mep")
    return new mep_basic::mep_basic_cpu ();
  // begin-mep-constructors
  if (typeName == "hw-cpu-mep-ext1")
    return new mep_ext1::mep_ext1_cpu ();
  // end-mep-constructors
#endif
#if SIDTARGET_MT
  if (typeName == "hw-cpu-mt")
    return new mt::mt_cpu ();
#endif
#if SIDTARGET_SH || SIDTARGET_SH64
  if (typeName == "hw-cpu-sh2")
    return new sh::sh2_cpu ();
  if (typeName == "hw-cpu-sh2e")
    return new sh::sh2e_cpu ();
  if (typeName == "hw-cpu-sh2a-fpu")
    return new sh::sh2a_fpu_cpu ();
  if (typeName == "hw-cpu-sh2a-fpu-single")
    return new sh::sh2a_fpu_single_cpu ();
  if (typeName == "hw-cpu-sh2a-nofpu")
    return new sh::sh2a_nofpu_cpu ();
  if (typeName == "hw-cpu-sh3")
    return new sh::sh3_cpu ();
  if (typeName == "hw-cpu-sh3e")
    return new sh::sh3e_cpu ();
  if (typeName == "hw-cpu-sh4")
    return new sh::sh4_cpu ();
  if (typeName == "hw-cpu-sh4-nofpu")
    return new sh::sh4_nofpu_cpu ();
  if (typeName == "hw-cpu-sh4-single")
    return new sh::sh4_single_cpu ();
  if (typeName == "hw-cpu-sh4a")
    return new sh::sh4a_cpu ();
  if (typeName == "hw-cpu-sh4a-nofpu")
    return new sh::sh4a_nofpu_cpu ();
  if (typeName == "hw-cpu-sh4a-single")
    return new sh::sh4a_single_cpu ();
  if (typeName == "hw-cpu-sh4al")
    return new sh::sh4al_cpu ();
#endif
#if SIDTARGET_SH64
  if (typeName == "hw-cpu-sh5-compact")
    return new sh::sh5_compact_cpu ();
  if (typeName == "hw-cpu-sh5-32media")
    return new sh::sh5_32media_cpu ();
  if (typeName == "hw-cpu-sh5-64media")
    return new sh::sh5_64media_cpu ();
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
DLLEXPORT extern const component_library cgen_component_library;

const component_library cgen_component_library =
{
  COMPONENT_LIBRARY_MAGIC,
  & compCGENListTypes, 
  & compCGENCreate,
  & compCGENDelete
};
