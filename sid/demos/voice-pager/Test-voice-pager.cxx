// Test-voice-pager.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "VoicePager.h"

int
main()
{
  VoicePager testobj1;

  // Initialize RTC, LCD and parallel port.
  testobj1.initialize_components();

  // Poll for input.
  testobj1.poll_input();

  return 0;
}
