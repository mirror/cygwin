/* Simulator instruction operand writer for mt.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#include "mt.h"

  template <typename ST> 
  static void clear_stacks (ST &st)
  {
    for (int i = 0; i < mt::pipe_sz; i++)
      st[i].clear();
  }

  void mt::write_stacks::reset ()
  {
    clear_stacks (h_spr_writes);
    clear_stacks (h_pc_writes);
  }
  void mt::write_stacks::writeback (int tick, mt::mt_cpu* current_cpu) 
  {

    // register writeback loops
    while (! h_spr_writes[tick].empty())
    {
      write<SI> &w = h_spr_writes[tick].top();
      current_cpu->h_spr_set(w.idx0, w.val);
      h_spr_writes[tick].pop();
    }

    while (! h_pc_writes[tick].empty())
    {
      write<USI> &w = h_pc_writes[tick].top();
      current_cpu->h_pc_set(w.val);
      h_pc_writes[tick].pop();
    }


    // memory writeback loops

  }
