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

#include "sid-x86-cpu-wrapper.h"
#include "sid-vga-wrapper.h"
#if HAVE_X11_XOS_H
#include "x-gui.h"
#endif
#include "sid-cmos-wrapper.h"
#include "sid-dma-wrapper.h"
#include "sid-keyboard-wrapper.h"
#include "sid-pic-wrapper.h"
#include "sid-pit-wrapper.h"
#include "sid-floppy-wrapper.h"
#include "sid-unmapped-wrapper.h"
#include "sid-harddrv-wrapper.h"

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
  types.push_back("hw-cmos-x86");
  types.push_back("hw-dma-x86");
  types.push_back("hw-input-keyboard");
  types.push_back("hw-interrupt-x86");
  types.push_back("hw-timer-x86");
  types.push_back("hw-disk-floppy");
  types.push_back("hw-bochs-misc");
  types.push_back("hw-disk-harddrive");
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
      else if(typeName == "hw-cmos-x86")
        return new cmos();
      else if(typeName == "hw-dma-x86")
        return new dma();
      else if(typeName == "hw-input-keyboard")
        return new keyboard();
      else if(typeName == "hw-interrupt-x86")
        return new pic();
      else if(typeName == "hw-timer-x86")
        return new pit();
      else if(typeName == "hw-disk-floppy")
        return new floppy();
      else if(typeName == "hw-bochs-misc")
        return new unmapped();
      else if(typeName == "hw-disk-harddrive")
        return new harddrive();
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
  cmos *d4 = dynamic_cast<cmos *>(c);
  if(d4)
    {
      delete d4;
      return;
    }
  dma *d5 = dynamic_cast<dma *>(c);
  if(d5)
    {
      delete d5;
      return;
    }
  keyboard *d6 = dynamic_cast<keyboard *>(c);
  if(d6)
    {
      delete d6;
      return;
    }
  pic *d7 = dynamic_cast<pic *>(c);
  if(d7)
    {
      delete d7;
      return;
    }
  pit *d8 = dynamic_cast<pit *>(c);
  if(d8)
    {
      delete d8;
      return;
    }
  floppy *d9 = dynamic_cast<floppy *>(c);
  if(d9)
    {
      delete d9;
      return;
    }
  unmapped *d10 = dynamic_cast<unmapped *>(c);
  if(d10)
    {
      delete d10;
      return;
    }
  harddrive *d11 = dynamic_cast<harddrive *>(c);
  if(d11)
    {
      delete d11;
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
