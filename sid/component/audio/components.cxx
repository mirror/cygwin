// components.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"



static
vector<string>
compAudioListTypes ()
{
  vector<string> types;
#ifndef SOUND_NONE
  types.push_back ("sid-io-audio");
#endif
  types.push_back ("sid-io-audio-nop");
  types.push_back ("hw-audio-sid");
  return types;
}


static
component*
compAudioCreate (const string& typeName)
{
  if (typeName == "sid-io-audio")
    {
#ifdef SOUND_CYGWIN
      return new cygwin_audio ();
#endif
#ifdef SOUND_LINUX
      return new linux_audio ();
#endif
#ifdef SOUND_SOLARIS
      return new solaris_audio ();
#endif
    }
  if (typeName == "sid-io-audio-nop")
    {
      return new nop_audio ();
    }
  if (typeName == "hw-audio-sid")
    {
      return new basic_codec ();
    }
  return 0;
}


static
void
compAudioDelete (component* c)
{
  // Only one of these will return non-zero for any given component*
#ifdef SOUND_LINUX
  linux_audio* a1 = dynamic_cast<linux_audio*>(c);
  if (a1) { delete a1; return; }
#endif
#ifdef SOUND_SOLARIS
  solaris_audio* a2 = dynamic_cast<solaris_audio*>(c);
  if (a2) { delete a2; return; }
#endif
#ifdef SOUND_CYGWIN
  cygwin_audio* a3 = dynamic_cast<cygwin_audio*>(c);
  if (a3) { delete a3; return; }
#endif
  nop_audio* a4 = dynamic_cast<nop_audio*>(c);
  if (a4) { delete a4; return; }

  basic_codec* a5 = dynamic_cast<basic_codec*>(c);
  if (a5) { delete a5; return; }
}


// static object
extern const component_library audio_component_library;

const component_library audio_component_library DLLEXPORT = 
{
  COMPONENT_LIBRARY_MAGIC,
  & compAudioListTypes, 
  & compAudioCreate,
  & compAudioDelete
};
