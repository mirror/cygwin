// components.cxx - The component_library routines for the various
// nearby components.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"


namespace console_stuff
{
static vector<string>
compConsoleListTypes()
{
  vector<string> types;
  types.push_back("sid-io-stdio");
  types.push_back("sid-io-socket-server");
  types.push_back("sid-io-socket-client");
  return types;
}

static component*
compConsoleCreate(const string& typeName)
{
  if (typeName == "sid-io-stdio")
    return new stdioConsole();
  else if (typeName == "sid-io-socket-server")
    return new socketio(true);
  else if (typeName == "sid-io-socket-client")
    return new socketio(false);
  else
    return 0;
}


static void
compConsoleDelete(component* c)
{
  // One of these dynamic_cast<>s will return 0.  It is safe to delete 0.
  stdioConsole* c1 = dynamic_cast<stdioConsole*>(c);
  if (c1) { delete c1; return; }
  socketio* c2 = dynamic_cast<socketio*>(c);
  if (c2) { delete c2; return; }
}

} // end of namespace console_stuff


extern const sid::component_library console_component_library;
const sid::component_library console_component_library DLLEXPORT =
{
  sid::COMPONENT_LIBRARY_MAGIC,
  & console_stuff::compConsoleListTypes,
  & console_stuff::compConsoleCreate,
  & console_stuff::compConsoleDelete
};
