/* Simulator instruction operand writer for sh.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "sh5.h"

  template <typename ST> 
  static void clear_stacks (ST &st)
  {
    for (int i = 0; i < sh5_media::pipe_sz; i++)
      st[i].clear();
  }

  void sh5_media::write_stacks::reset ()
  {
  }
  void sh5_media::write_stacks::writeback (int tick, sh5::sh5_cpu* current_cpu) 
  {

    // register writeback loops

    // memory writeback loops

  }
