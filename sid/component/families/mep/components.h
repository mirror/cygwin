// components.h - description.  -*- C++ -*-

// Copyright (C) 2001 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidmiscutil.h>
#include <sidschedutil.h>
#include <sidwatchutil.h>

#include <vector>
#include <string>

#if HAVE_SSTREAM
  #include <sstream>
#elif HAVE_STRSTREAM_H
  #include <strstream.h>
#else
  #error "need <sstream> or <strstream.h>!"
#endif

using sid::component_library;
using sid::COMPONENT_LIBRARY_MAGIC;
using std::vector;
using std::string;

#endif // COMPONENTS_H
