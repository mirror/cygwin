// compGloss.cxx - Gloss component.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "tconfig.h"

#include <sidcomp.h>
#include <sidso.h>

#if SIDTARGET_ARM
#include "angel.h"
#endif
#if SIDTARGET_M32R
#include "m32r.h"
#endif
#if SIDTARGET_MIPS
#include "mips.h"
#endif
#include "gloss.h"

using namespace std;
using namespace sid;


static
vector<string>
compGlossListTypes()
{
  vector<string> types;
#if SIDTARGET_M32R
  types.push_back("sw-gloss-m32r/libgloss");
#endif
#if SIDTARGET_ARM
  types.push_back("sw-gloss-arm/angel");
#endif
#if SIDTARGET_MIPS
  types.push_back("sw-gloss-mips32/idt");
#endif
  types.push_back("sw-gloss-generic/libgloss");
  return types;
}


static
component*
compGlossCreate(const string& typeName)
{
#if SIDTARGET_M32R
  if (typeName == "sw-gloss-m32r/libgloss")
    return new m32r_libgloss();
#endif
#if SIDTARGET_ARM
  if (typeName == "sw-gloss-arm/angel")
    return new arm_angel();
#endif
#if SIDTARGET_MIPS
  if (typeName == "sw-gloss-mips32/idt")
    return new mips32_idt();
#endif
  if (typeName == "sw-gloss-generic/libgloss")
    return new gloss32();
  return 0;
}


static
void
compGlossDelete(component* c)
{
  // Two of these dynamic_cast<>s will return 0.  It is safe to delete 0.
#if SIDTARGET_M32R
  m32r_libgloss* g1 = dynamic_cast<m32r_libgloss*>(c);
  if (g1) { delete g1; return; }
#endif
#if SIDTARGET_ARM
  arm_angel* g2 = dynamic_cast<arm_angel*>(c);
  if (g2) { delete g2; return; }
#endif
#if SIDTARGET_MIPS
  mips32_idt* g3 = dynamic_cast<mips32_idt*>(c);
  if (g3) { delete g3; return; }
#endif
  gloss32* g4 = dynamic_cast<gloss32*>(c);
  if (g4) { delete g4; return; }
}


// static object
extern const component_library gloss_component_library;

const component_library gloss_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compGlossListTypes, 
  & compGlossCreate,
  & compGlossDelete
};
