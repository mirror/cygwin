// shCfg.h - configuration for Sh.  -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef __shCfg_h__
#define __shCfg_h__

#include "commonCfg.h"

class ShBoardCfg :
  virtual public BoardCfg
{
 public:
  ShBoardCfg (const string &name,
	      const string &type,
	      SessionCfg *sess,
	      const string &syscall_numbering);
  virtual ~ShBoardCfg () {}

  virtual void write_config (Writer &w);

protected:
  CacheCfg *icache;
  CacheCfg *ocache;
  MemCfg   *main_memory;
  bool is_64bit_p;
};

extern BoardCfg *mk_sh (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh2 (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh2e (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh2a_nofpu (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh2a_fpu_single (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh2a_fpu (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh2a (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh3 (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh3e (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4 (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4_nofpu (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4_single (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4a (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4a_nofpu (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4a_single (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh4al (const string name, SessionCfg *sess);
#if defined (SIDTARGET_SH64)
extern BoardCfg *mk_sh5_compact (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh5_32media (const string name, SessionCfg *sess);
extern BoardCfg *mk_sh5_64media (const string name, SessionCfg *sess);
#endif

#endif // __mepCfg_h__
