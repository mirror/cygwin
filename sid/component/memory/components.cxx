// components.cxx - definitions for this component library. -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>

#include <vector>
#include <string>

#include "am29.h"
#include "at29.h"
#include "ramrom.h"

using std::vector;
using std::string;

using sid::component;
using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;



// ----------------------------------------------------------------------------


static
vector<string>
compMemoryListTypes()
{
  vector<string> types;

  types.push_back("hw-memory-ram/rom-basic");

  types.push_back("hw-memory-flash-at29");
  for (const at29_flash_memory_type* ft = at29_flash_memory::types;
       ft->name != 0;
       ft++)
    {
      types.push_back(string("hw-memory-flash-at29") + ft->name);
    }

  types.push_back("hw-memory-flash-am29");
  for (const am29_flash_memory_type* ft = am29_flash_memory::types;
       ft->name != 0;
       ft++)
    {
      types.push_back(string("hw-memory-flash-am29") + ft->name);
    }

  return types;
}


static
component*
compMemoryCreate(const string& typeName)
{
  // Protect against the constructors throwing exceptions
  try
    {
      if (typeName == "hw-memory-ram/rom-basic")
	return new ramrom_memory();
      
      if (typeName == "hw-memory-flash-at29")
	return new at29_flash_memory(512*1024, 512, 0x5B); // default: AT29C040
      for (const at29_flash_memory_type* ft = at29_flash_memory::types;
	   ft->name != 0;
	   ft++)
	{
	  string that_type = string("hw-memory-flash-at29") + ft->name;
	  if (that_type == typeName)
	    return new at29_flash_memory(ft->memory_size, ft->sector_size, ft->device_id);
	}

      if (typeName == "hw-memory-flash-am29")
	{
	  // default: Am29LV040B
	  return new am29_flash_memory(512*1024, 64*1024, 0x4F);
	}
      for (const am29_flash_memory_type* ft = am29_flash_memory::types;
	   ft->name != 0;
	   ft++)
	{
	  string that_type = string("hw-memory-flash-am29") + ft->name;
	  if (that_type == typeName)
	    return new am29_flash_memory(ft->memory_size, ft->sector_size, ft->device_id);
	}
    }
  catch (...) { }

  return 0;
}


static
void
compMemoryDelete(component* c)
{
  // generic_memory is a base class for all components that may have come from here
  delete dynamic_cast<generic_memory*>(c);
}



// static object
extern const component_library mem_component_library;

const component_library mem_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compMemoryListTypes, 
  & compMemoryCreate,
  & compMemoryDelete
};
