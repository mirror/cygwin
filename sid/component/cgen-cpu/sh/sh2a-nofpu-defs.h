/* CPU family header for sh2a_nofpu / sh2a_nofpu.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000-2010 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/

#ifndef DEFS_SH2A_NOFPU_H
#define DEFS_SH2A_NOFPU_H

#include <stack>
#include "cgen-types.h"

// forward declaration

  
namespace sh2a_nofpu {
struct sh2a_nofpu_cpu;
}

namespace sh2a_nofpu {

using namespace cgen;

  static const int max_delay = 1;
  static const int pipe_sz = 2; // max_delay + 1

  template <typename ELT> 
  struct write_stack 
  {
    int t;
    const int sz;
    ELT buf[WRITE_BUF_SZ];

    write_stack       ()             : t(-1), sz(WRITE_BUF_SZ) {}
    inline bool empty ()             { return (t == -1); }
    inline void clear ()             { t = -1; }
    inline void pop   ()             { if (t > -1) t--;}
    inline void push  (const ELT &e) { if (t+1 < sz) buf [++t] = e;}
    inline ELT &top   ()             { return buf [t>0 ? ( t<sz ? t : sz-1) : 0];}
  };

  // look ahead for latest write with index = idx, where time of write is
  // <= dist steps from base (present) in write_stack array st.
  // returning def if no scheduled write is found.

  template <typename STKS, typename VAL>
  inline VAL lookahead (int dist, int base, STKS &st, VAL def, int idx=0)
  {
    for (; dist > 0; --dist)
    {
      write_stack <VAL> &v = st [(base + dist) % pipe_sz];
      for (int i = v.t; i > 0; --i) 
	  if (v.buf [i].idx0 == idx) return v.buf [i];
    }
    return def;
  }



  template <typename MODE>
  struct write
  {
    USI pc;
    MODE val;
    USI idx0;
    write (PCADDR _pc, MODE _val, USI _idx0=0) : pc(_pc), val(_val), idx0(_idx0) {} 
    write() {}
  };


// write stacks used in parallel execution

  struct write_stacks
  {
  // types of stacks

  write_stack< write<UDI> > 	h_pc_writes	[pipe_sz];
  write_stack< write<SI> >  	h_pr_writes	[pipe_sz];


  // unified writeback function (defined in sh2a_nofpu-write.cc)
  void writeback (int tick, sh2a_nofpu::sh2a_nofpu_cpu* current_cpu);
  // unified write-stack clearing function (defined in sh2a_nofpu-write.cc)
  void reset ();

  }; // end struct sh2a_nofpu::write_stacks 

} // end sh2a_nofpu namespace

#endif /* DEFS_SH2A_NOFPU_H */
