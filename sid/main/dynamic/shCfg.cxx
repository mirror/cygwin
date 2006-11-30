// shCfg.cxx - configuration for Sh.  -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#if defined (SIDTARGET_SH) || defined (SIDTARGET_SH64)

#include "shCfg.h"

ShBoardCfg::ShBoardCfg (const string &name,
			const string &type,
			SessionCfg *sess,
			const string &syscall_numbering) :
  ComponentCfg (name),
  AggregateCfg (name),
  BoardCfg (name, type, sess, false, true, false),
  is_64bit_p (type == "sh5-64media")
{
  // we build our own gloss here, since we want it to see the data cache and the base class
  // has no idea it exists.
  assert (cpu);
  assert (sess);
  gloss = new GlossCfg ("gloss", cpu, sess);  
  assert (gloss);
  set (gloss, "syscall-numbering-scheme", syscall_numbering);
  add_child (gloss);

  // Insn cache -- 8k, 32 byte lines
  icache = new CacheCfg ("icache", 8, 32);
  set (icache, "data-width", "8");
  sess->init_seq->add_output (1, icache, "invalidate-all");
  add_child (icache);

  // Operand cache -- 16k, 32 byte lines
  ocache = new CacheCfg ("ocache", 16, 32);
  set (ocache, "data-width", "8");
  assert (cache_flush_net);
  cache_flush_net->add_output (0, ocache, "flush-all");
  sess->init_seq->add_output (1, ocache, "invalidate-all");
  add_child (ocache);

  // Main memory -- 0x1000000 bytes for now
  main_memory = new MemCfg ("main-mem", 0x1000000, 1, 0);
  assert (main_memory);
  add_child (main_memory);
}

void
ShBoardCfg::write_config (Writer &w)
{
  assert (cpu);

  // Connect the memory heirarchy.
  cpu->set_imem (icache, "upstream");
  conn_bus (icache, "downstream", main_mapper, "access-port");

  cpu->set_dmem (ocache, "upstream");
  conn_bus (ocache, "downstream", main_mapper, "access-port");
  conn_pin (cpu, "cache-prefetch", ocache, "prefetch");
  conn_bus (gloss, "target-memory", ocache, "upstream");

  cpu->set_disasm_mem (main_mapper, "access-port");
  main_mapper->map (Mapping().low(0x000000).high(0xffffff).slave(main_memory).bus("read-write-port"));

  // Need 64 bit gprof support?
  if (gprof && is_64bit_p)
    gprof->set (gprof, "pc-size", "8");

  // Write the config as usual.
  BoardCfg::write_config (w);
}

// Default sh board.
BoardCfg * 
mk_sh (const string name, SessionCfg *sess)
{
#if defined (SIDTARGET_SH)
  return mk_sh2 (name, sess);
#else
  return mk_sh5_64media (name, sess);
#endif
}

// sh2 board
BoardCfg * 
mk_sh2 (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh2", sess, "sh-compact");
  return board;
}

// sh2e board
BoardCfg * 
mk_sh2e (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh2e", sess, "sh-compact");
  return board;
}

// sh2a board with no fpu
BoardCfg * 
mk_sh2a_nofpu (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh2a-nofpu", sess, "sh-compact");
  return board;
}

// sh2a board with single precision fpu
BoardCfg * 
mk_sh2a_fpu_single (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh2a-fpu-single", sess, "sh-compact");
  return board;
}

// sh2a board with full precision fpu
BoardCfg * 
mk_sh2a_fpu (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh2a-fpu", sess, "sh-compact");
  return board;
}

// default sh2a board -- sh2a-fpu
BoardCfg * 
mk_sh2a (const string name, SessionCfg *sess)
{
  return mk_sh2a_fpu (name, sess);
}

// sh3 board
BoardCfg * 
mk_sh3 (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh3", sess, "sh-compact");
  return board;
}

// sh3e board
BoardCfg * 
mk_sh3e (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh3e", sess, "sh-compact");
  return board;
}

// sh4 board
BoardCfg * 
mk_sh4 (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4", sess, "sh-compact");
  return board;
}

// sh4 board with no fpu
BoardCfg * 
mk_sh4_nofpu (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4-nofpu", sess, "sh-compact");
  return board;
}

// sh4 board with single precision fpu
BoardCfg * 
mk_sh4_single (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4-single", sess, "sh-compact");
  return board;
}

// sh4a board
BoardCfg * 
mk_sh4a (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4a", sess, "sh-compact");
  return board;
}

// sh4a board with no fpu
BoardCfg * 
mk_sh4a_nofpu (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4a-nofpu", sess, "sh-compact");
  return board;
}

// sh4a board with single precision fpu
BoardCfg * 
mk_sh4a_single (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4a-single", sess, "sh-compact");
  return board;
}

// sh4al board
BoardCfg * 
mk_sh4al (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh4al", sess, "sh-compact");
  return board;
}

#if defined (SIDTARGET_SH64)
BoardCfg * 
mk_sh5_compact (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh5-compact", sess, "sh-compact");
  return board;
}

BoardCfg * 
mk_sh5_32media (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh5-32media", sess, "sh-media");
  return board;
}

BoardCfg * 
mk_sh5_64media (const string name, SessionCfg *sess)
{
  ShBoardCfg *board = new ShBoardCfg (name, "sh5-64media", sess, "sh-media");
  return board;
}
#endif // defined (SIDTARGET_SH64)

#endif // defined (SIDTARGET_SH) || defined (SIDTARGET_SH64)
