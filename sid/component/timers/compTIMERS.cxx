// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "tconfig.h"

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>

using namespace std;
using namespace sid;

#if SIDTARGET_ARM
#include "arm7t-timer.h"
#endif

 
extern const component_library timer_component_library;

static vector<string>
compTimerListTypes()
{
  vector<string> types;
#if SIDTARGET_ARM
  types.push_back("hw-timer-arm/ref-nosched");
  types.push_back("hw-timer-arm/ref-sched");
#endif
  return types;
}

static component*
compTimerCreate(const string& typeName)
{
#if SIDTARGET_ARM
  if (typeName == "hw-timer-arm/ref-nosched")
    return new armTimerNoSched();
  if (typeName == "hw-timer-arm/ref-sched")
    return new armTimerSched();
#endif

  return 0;
}


static void
compTimerDelete(component* c)
{
#if SIDTARGET_ARM
  // armTimer is a base class of armTimerSched
  delete dynamic_cast<armTimer*>(c);
#endif
}


const component_library timer_component_library DLLEXPORT =
{
  COMPONENT_LIBRARY_MAGIC,
  &compTimerListTypes,
  &compTimerCreate,
  &compTimerDelete
};

