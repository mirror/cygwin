// components.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "tconfig.h"
#include "components.h"

// --- m a i n   d r i v e r ---

static vector<string>
compInterruptListTypes()
{
  vector<string> types;
#if SIDTARGET_ARM
  types.push_back(string("hw-interrupt-arm/ref"));
  types.push_back(string("hw-interrupt-cogent/cma222"));
//  types.push_back(string("hw-interrupt-sa"));
#endif
  return types;
}

#include "arm.h"
#include "cma222.h"
//#include "sa.h"

static component*
compInterruptCreate(const string& typeName)
{
#if SIDTARGET_ARM
  if (typeName == "hw-interrupt-arm/ref")
    return new armIntController();
  if (typeName == "hw-interrupt-cogent/cma222")
    return new cma222IntController();
//  if (typeName == "hw-interrupt-sa")
//    return new saIntController();
#endif
  return 0;
}

static void
compInterruptDelete(component* c)
{
#if SIDTARGET_ARM
  delete dynamic_cast<armIntController*>(c);
  delete dynamic_cast<cma222IntController*>(c);
//  delete dynamic_cast<saIntController*>(c);
#endif
}

extern const component_library interrupt_component_library;

const component_library interrupt_component_library DLLEXPORT =
{
  COMPONENT_LIBRARY_MAGIC,
  &compInterruptListTypes,
  &compInterruptCreate,
  &compInterruptDelete
};
