/* Simulator instruction operand writer for sh.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2009 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "sh4a.h"

  template <typename ST> 
  static void clear_stacks (ST &st)
  {
    for (int i = 0; i < sh4a::pipe_sz; i++)
      st[i].clear();
  }

  void sh4a::write_stacks::reset ()
  {
    clear_stacks (h_pc_writes);
    clear_stacks (h_pr_writes);
  }
  void sh4a::write_stacks::writeback (int tick, sh4a::sh4a_cpu* current_cpu) 
  {

    // register writeback loops
    while (! h_pc_writes[tick].empty())
    {
      write<UDI> &w = h_pc_writes[tick].top();
      current_cpu->h_pc_set(w.val);
      h_pc_writes[tick].pop();
    }

    while (! h_pr_writes[tick].empty())
    {
      write<SI> &w = h_pr_writes[tick].top();
      current_cpu->h_pr_set(w.val);
      h_pr_writes[tick].pop();
    }


    // memory writeback loops

  }
