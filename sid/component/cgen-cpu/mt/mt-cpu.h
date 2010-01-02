/* CPU class elements for mt.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

// This file is included in the middle of the cpu class struct.

public:

// CPU state information.

  // Hardware elements.
  struct {
  /* special-purpose registers */
  SI h_spr[16];
  /* program counter */
  USI h_pc;
  } hardware;

  void stream_cgen_hardware (std::ostream &ost) const 
  {
    for (int i = 0; i < 16; i++)
      ost << hardware.h_spr[i] << ' ';
    ost << hardware.h_pc << ' ';
  }
  void destream_cgen_hardware (std::istream &ist) 
  {
    for (int i = 0; i < 16; i++)
      ist >> hardware.h_spr[i];
    ist >> hardware.h_pc;
  }
  template <typename ST> 
  void stream_stacks (const ST &st, std::ostream &ost) const
  {
    for (int i = 0; i < mt::pipe_sz; i++)
    {
      ost << st[i].t << ' ';
      for (int j = 0; j <= st[i].t; j++)
      {
        ost << st[i].buf[j].pc << ' ';
        ost << st[i].buf[j].val << ' ';
        ost << st[i].buf[j].idx0 << ' ';
      }
    }
  }
  
  template <typename ST> 
  void destream_stacks (ST &st, std::istream &ist)
  {
    for (int i = 0; i < mt::pipe_sz; i++)
    {
      ist >> st[i].t;
      for (int j = 0; j <= st[i].t; j++)
      {
        ist >> st[i].buf[j].pc;
        ist >> st[i].buf[j].val;
        ist >> st[i].buf[j].idx0;
      }
    }
  }
  
  void stream_cgen_write_stacks (std::ostream &ost, const mt::write_stacks &stacks) const 
  {
    stream_stacks ( stacks.h_spr_writes, ost);
    stream_stacks ( stacks.h_pc_writes, ost);
  }
  void destream_cgen_write_stacks (std::istream &ist, mt::write_stacks &stacks) 
  {
    destream_stacks ( stacks.h_spr_writes, ist);
    destream_stacks ( stacks.h_pc_writes, ist);
  }
  // C++ register access function templates
#define current_cpu this

  inline SI h_spr_get (UINT regno) const { return this->hardware.h_spr[regno]; }
  inline void h_spr_set (UINT regno, SI newval) { this->hardware.h_spr[regno] = newval; }

  inline USI h_pc_get () const { return this->hardware.h_pc; }
  inline void h_pc_set (USI newval) { this->hardware.h_pc = newval; }

#undef current_cpu

