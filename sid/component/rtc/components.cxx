// components.cxx - definitions for this component library.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"

static
vector<string>
rtcListTypes()
{
  vector<string> types;
  types.push_back("hw-rtc-ds1642");
  types.push_back("hw-rtc-ds1742");
  types.push_back("hw-rtc-sid");
  return types;
}

static
component*
rtcCreate(const string& typeName)
{
  if (typeName == "hw-rtc-ds1642")
    return new ds1642();
  else if (typeName == "hw-rtc-ds1742")
    return new ds1742();
  else if (typeName == "hw-rtc-sid")
    return new sidrtc();
  else
    return 0;
}

static
void
rtcDelete(component* c)
{
  // ds1742 is derived from ds1642
  ds1642* r1 = dynamic_cast<ds1642*>(c);
  if (r1) { delete r1; return; }
  sidrtc* r2 = dynamic_cast<sidrtc*>(c);
  if (r2) { delete r2; return; }
}


// static object
extern const component_library rtc_component_library;

const component_library rtc_component_library DLLEXPORT =
{
  COMPONENT_LIBRARY_MAGIC,
  & rtcListTypes,
  & rtcCreate,
  & rtcDelete
};
