// sidso.h - Magic for components packaged inside shared libraries.
// -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDSO_H
#define SIDSO_H

#include <sidcomp.h>
#include <sidtypes.h>
#include <vector>
#include <string>

// Use these macros to export component_library instances from DLLs.

#ifdef __CYGWIN__
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#else
#define DLLEXPORT 
#define DLLIMPORT 
#endif


namespace sid
{
  // A magic number used to check library version compatibility.
  // Refer to struct sid::component_library.
  // XXX: should include STL library version
  const host_int_4 COMPONENT_LIBRARY_MAGIC = 
    ((API_MAJOR_VERSION << 16) | 
     (API_MINOR_VERSION << 12) |
     (__GNUC__ << 8) | (__GNUC_MINOR__));
  
  // A shared library description record.
  // An instance of this structure must be present in each shared
  // library containing components.
  struct component_library
  {
    // A magic number used to check version compatibility of libraries.
    // Should be initialized to the constant COMPONENT_LIBRARY_MAGIC.
    host_int_4 magic;

    // A pointer to a function that returns the types of the
    // components in this library.
    // Returns the types components that this library supports.  The
    // names can be passed to the create_component function to create
    // new components of those types.
    std::vector<std::string> (*list_component_types) ();

    // A pointer to a function that creates new components.
    // Returns a pointer to the new component or 0 if unsuccessful.
    sid::component* (*create_component) (const std::string& typeName);
    
    // Destroy a component, c. Returns a pointer to the now-destroyed
    // component or 0 if unsuccessful.
    void (*delete_component) (sid::component* c);
  };
};

#endif // H_SIDSO_H
