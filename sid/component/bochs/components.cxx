// components.cxx - definitions for this component library. -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "tconfig.h"
#include "config.h"

#include <sidcomp.h>
#include <sidso.h>

#include <vector>
#include <string>

#include "x86.h"

using std::vector;
using std::string;

using sid::component;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;



// ----------------------------------------------------------------------------


static
vector<string>
compX86ListTypes()
{
  vector<string> types;


#if SIDTARGET_X86
  types.push_back("hw-cpu-x86");
#endif

  return types;
}


static
component*
compX86Create(const string& typeName)
{
#if SIDTARGET_X86
    try {
        
        if(typeName == "hw-cpu-x86")
        {
            return new x86_cpu();
        }
    }
    catch (...) { }
#endif
    return 0;
}


static
void
compX86Delete(component* c)
{
#if SIDTARGET_X86
    delete dynamic_cast<sidutil::basic_cpu*>(c);
#endif
}



// static object
extern const component_library x86_component_library;

const component_library x86_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compX86ListTypes, 
  & compX86Create,
  & compX86Delete
};
