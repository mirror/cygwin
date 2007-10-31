// components.cxx -*- C++ -*-

// Copyright (C) 2001, 2002, 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "components.h"
#include "dsu.h"
#include "mep-dmac.h"
#include "mep-intc.h"
#include "mm_int.h"
#include "timer.h"
#include "toshapi.h"
// begin-toshapi-headers
// end-toshapi-headers

// begin-hw-engine-definitions
// end-hw-engine-definitions

// begin-peripheral-definitions
// end-peripheral-definitions

static vector<string>
compMepFamilyListTypes()
{
  vector<string> types;
  types.push_back ("hw-debug-mep");
  types.push_back ("hw-dma-mep");
  types.push_back ("hw-interrupt-mep");
  types.push_back ("hw-mm_int-mep");
  types.push_back ("hw-timer-mep");
  types.push_back ("hw-gbif-mep");
  types.push_back ("hw-gbmif-mep");
  types.push_back ("hw-lbif-mep");
  // begin-hw-engine-constructor-names
  // end-hw-engine-constructor-names
  // begin-peripheral-constructor-names
  // end-peripheral-constructor-names
  // begin-toshapi-constructor-names
  // end-toshapi-constructor-names
  for (unsigned i = 1; i <= 32; i++)
    types.push_back ("hw-interrupt-mep-" + sidutil::make_attribute (i));
  return types;
}

using namespace toshapi;

static component*
compMepFamilyCreate(const string& typeName)
{
  if (typeName == "hw-debug-mep")
    return new mep_dsu ();
  if (typeName == "hw-dma-mep")
    return new mep_dmac ();
  if (typeName == "hw-interrupt-mep")
    return new mep_intc (32);
  if (typeName == "hw-mm_int-mep")
    return new mep_mm_int ();
  if (typeName == "hw-timer-mep")
    return new mep_timer ();
  if (typeName == "hw-gbif-mep")
    return new GlobalBusInterface ();
  if (typeName == "hw-gbmif-mep")
    return new GlobalBus ();
  if (typeName == "hw-lbif-mep")
    return new LocalBus ();
  // begin-hw-engine-constructors
  // end-hw-engine-constructors
  // begin-peripheral-constructors
  // end-peripheral-constructors
  // begin-toshapi-constructors
  // end-toshapi-constructors

  vector <string> parts = sidutil::tokenize (typeName, "-");
  if (parts.size () == 4 && 
      parts[0] == "hw" && parts[1] == "interrupt" && parts[2] == "mep")
    {
      unsigned num_channels;
      if (parse_attribute (parts[3], num_channels) == component::ok &&
	  num_channels <= 32)
	{
	  return new mep_intc (num_channels);
	}
    }
  return 0;
}

static void
compMepFamilyDelete(component* c)
{
  mep_dsu* d1 = dynamic_cast<mep_dsu*> (c);
  if (d1) { delete d1; return; }
  mep_dmac* d2 = dynamic_cast<mep_dmac*> (c);
  if (d2) { delete d2; return; }
  mep_intc* d3 = dynamic_cast<mep_intc*> (c);
  if (d3) { delete d3; return; }
  mep_timer* d4 = dynamic_cast<mep_timer*> (c);
  if (d4) { delete d4; return; }
  GlobalBusInterface* d5 = dynamic_cast<GlobalBusInterface*> (c);
  if (d5) { delete d5; return; }
  GlobalBus* d6 = dynamic_cast<GlobalBus*> (c);
  if (d6) { delete d6; return; }
  LocalBus* d7 = dynamic_cast<LocalBus*> (c);
  if (d7) { delete d7; return; }
  // begin-hw-engine-destructors
  // end-hw-engine-destructors
  // begin-peripheral-destructors
  // end-peripheral-destructors
  // begin-toshapi-destructors
  Memory* t1 = dynamic_cast<Memory*> (c);
  if (t1) { delete t1; return; }
  // end-toshapi-destructors
}

DLLEXPORT extern const component_library mepfamily_component_library;

const component_library mepfamily_component_library =
{
  COMPONENT_LIBRARY_MAGIC,
  &compMepFamilyListTypes,
  &compMepFamilyCreate,
  &compMepFamilyDelete
};
