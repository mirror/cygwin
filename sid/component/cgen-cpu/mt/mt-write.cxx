/* Simulator instruction operand writer for mt.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2005 Red Hat, Inc.

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
    clear_stacks (BI_memory_writes);
    clear_stacks (QI_memory_writes);
    clear_stacks (HI_memory_writes);
    clear_stacks (SI_memory_writes);
    clear_stacks (DI_memory_writes);
    clear_stacks (UQI_memory_writes);
    clear_stacks (UHI_memory_writes);
    clear_stacks (USI_memory_writes);
    clear_stacks (UDI_memory_writes);
    clear_stacks (SF_memory_writes);
    clear_stacks (DF_memory_writes);
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
    while (! BI_memory_writes[tick].empty())
    {
      write<BI> &w = BI_memory_writes[tick].top();
      current_cpu->SETMEMBI (w.pc, w.idx0, w.val);
      BI_memory_writes[tick].pop();
    }

    while (! QI_memory_writes[tick].empty())
    {
      write<QI> &w = QI_memory_writes[tick].top();
      current_cpu->SETMEMQI (w.pc, w.idx0, w.val);
      QI_memory_writes[tick].pop();
    }

    while (! HI_memory_writes[tick].empty())
    {
      write<HI> &w = HI_memory_writes[tick].top();
      current_cpu->SETMEMHI (w.pc, w.idx0, w.val);
      HI_memory_writes[tick].pop();
    }

    while (! SI_memory_writes[tick].empty())
    {
      write<SI> &w = SI_memory_writes[tick].top();
      current_cpu->SETMEMSI (w.pc, w.idx0, w.val);
      SI_memory_writes[tick].pop();
    }

    while (! DI_memory_writes[tick].empty())
    {
      write<DI> &w = DI_memory_writes[tick].top();
      current_cpu->SETMEMDI (w.pc, w.idx0, w.val);
      DI_memory_writes[tick].pop();
    }

    while (! UQI_memory_writes[tick].empty())
    {
      write<UQI> &w = UQI_memory_writes[tick].top();
      current_cpu->SETMEMUQI (w.pc, w.idx0, w.val);
      UQI_memory_writes[tick].pop();
    }

    while (! UHI_memory_writes[tick].empty())
    {
      write<UHI> &w = UHI_memory_writes[tick].top();
      current_cpu->SETMEMUHI (w.pc, w.idx0, w.val);
      UHI_memory_writes[tick].pop();
    }

    while (! USI_memory_writes[tick].empty())
    {
      write<USI> &w = USI_memory_writes[tick].top();
      current_cpu->SETMEMUSI (w.pc, w.idx0, w.val);
      USI_memory_writes[tick].pop();
    }

    while (! UDI_memory_writes[tick].empty())
    {
      write<UDI> &w = UDI_memory_writes[tick].top();
      current_cpu->SETMEMUDI (w.pc, w.idx0, w.val);
      UDI_memory_writes[tick].pop();
    }

    while (! SF_memory_writes[tick].empty())
    {
      write<SF> &w = SF_memory_writes[tick].top();
      current_cpu->SETMEMSF (w.pc, w.idx0, w.val);
      SF_memory_writes[tick].pop();
    }

    while (! DF_memory_writes[tick].empty())
    {
      write<DF> &w = DF_memory_writes[tick].top();
      current_cpu->SETMEMDF (w.pc, w.idx0, w.val);
      DF_memory_writes[tick].pop();
    }


  }
