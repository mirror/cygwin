// compCGEN.cxx - CPU components.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "tconfig.h"

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "cgen-cpu.h"

#if SIDTARGET_ARM
#include "arm7f.h"
#endif
#if SIDTARGET_M32R
#include "m32rbf.h"
#endif

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace cgen;


// ----------------------------------------------------------------------------
cgen_bi_endian_cpu::cgen_bi_endian_cpu ():
  trace_stream (cout)
{
  debug_exec_p = false;
  add_attribute ("debug-exec?", & debug_exec_p, "setting");
  this->engine_type = ENGINE_UNKNOWN;
  add_attribute_virtual ("engine-type", this, 
			 & cgen_bi_endian_cpu::set_engine_type,
			 & cgen_bi_endian_cpu::get_engine_type,
			 "setting");
}


cgen_bi_endian_cpu::~cgen_bi_endian_cpu () 
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
    << debug_exec_p << " "
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
    >> debug_exec_p;
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
