// fileio.cxx - A simple output console that uses standard I/O for
// enunciation.  -*- C++ -*-

// Copyright (C) 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <fstream>
#include "config.h"
#include "components.h"

namespace console_stuff
{

fileioConsole::fileioConsole()
  :out_pin(this, & fileioConsole::write),
   out_filename ("-"),
   out_stream (&cout)
{
  add_pin("write", &out_pin);
  add_attribute_notify ("filename", & out_filename, this, & fileioConsole::filename_attribute_set,
			"output file setting");
  add_attribute_virtual ("state-snapshot", this,
			 & fileioConsole::save_state,
			 & fileioConsole::restore_state);
}

fileioConsole::~fileioConsole () throw ()
{
  closeOutStream ();
}

void
fileioConsole::closeOutStream ()
{
  if (out_stream && out_stream != &cout)
    delete out_stream;
}

void
fileioConsole::filename_attribute_set ()
{
  // Associate the out_stream with the new filename
  closeOutStream ();
  if (out_filename == "-")
    out_stream = &cout;
  else
    out_stream = new std::ofstream (out_filename.c_str ());
}

void
fileioConsole::write(host_int_4 value)
{
  if (out_stream)
    (*out_stream) << static_cast<char> (value) << flush;
}

string 
fileioConsole::save_state ( )
{
  return string("fileioConsole");
}

component::status
fileioConsole::restore_state(const string& state)
{
  if ( state == "fileioConsole")
    return component::ok;
  else
    return component::bad_value;
}


} // end of namespace console_stuff
