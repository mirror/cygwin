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
#include "sid-vga-wrapper.h"
#if HAVE_X11_XOS_H
#include "x-gui.h"
#endif
#include "sid-keyboard-wrapper.h"

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
  types.push_back("hw-video-vga");
#if HAVE_X11_XOS_H
  types.push_back("sid-io-vga-x");
#endif
  types.push_back("hw-input-keyboard");
#endif

  return types;
}


static
component*
compX86Create(const string& typeName)
{
#if SIDTARGET_X86
  try
    {
      
      if(typeName == "hw-cpu-x86")
        return new x86_cpu();
      else if(typeName == "hw-video-vga")
        return new vga();
#if HAVE_X11_XOS_H
      else if(typeName == "sid-io-vga-x")
        return new x_gui();
#endif
      else if(typeName == "hw-input-keyboard")
        return new keyboard();
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
  x86_cpu *d1 = dynamic_cast<x86_cpu *>(c);
  if(d1)
    {
      delete d1;
      return;
    }
  vga *d2 = dynamic_cast<vga *>(c);
  if(d2)
    {
      delete d2;
      return;
    }
#if HAVE_X11_XOS_H
  x_gui *d3 = dynamic_cast<x_gui *>(c);
  if(d3)
    {
      delete d3;
      return;
    }
#endif
  keyboard *d4 = dynamic_cast<keyboard *>(c);
  if(d4)
    {
      delete d4;
      return;
    }
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
