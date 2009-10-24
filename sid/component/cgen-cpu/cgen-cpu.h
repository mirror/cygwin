// cgen-cpu.h  -*- C++ -*-

// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef CGEN_CPU_H
#define CGEN_CPU_H

#include <sidcomp.h>
#include <sidso.h>
#include <sidtypes.h>
#include <sidcomputil.h>
#include <sidattrutil.h>
#include <sidpinutil.h>
#include <sidbusutil.h>
#include <sidcpuutil.h>
#include <sidwatchutil.h>
#include <sidmiscutil.h>
#include <sidpinattrutil.h>

#include "cgen-types.h"
#include "cgen-ops.h"
#include "cgen-engine.h"

#include "bfd.h"
#include "dis-asm.h"
#include "cgen/bitset.h"

// ansidecl.h interferes with this perfectly ordinary word
#undef AND

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


using namespace std;
using namespace sid;
using namespace sidutil;

namespace cgen 
{

  // Mix-in class for cgen cpus.
  // For simplicity, assume they are all bi-endian.
class cgen_bi_endian_cpu: public basic_bi_endian_cpu
{
protected:
  // Types of supported engines.  Not all cpus support all engines.
  enum engine_type {
    ENGINE_UNKNOWN, ENGINE_SIMPLE, ENGINE_SCACHE, ENGINE_PBB
  };
  engine_type engine_type;
  virtual string get_engine_type ();
  virtual component::status set_engine_type (const string& s);

public:
  // true -> print execution warning messages and signal debugger
  // [what it is is at the programmer's whim]
  bool warnings_enabled;

  // Print messages here.  
  // Cover fns to start/end insn tracing.
  void begin_trace (PCADDR pc, const char* insn_name);
  void end_trace ();
  // Disassembly tracing support
  void disassemble (PCADDR pc, disassembler_ftype printfn,
		    enum bfd_flavour flavour, enum bfd_architecture arch,
		    enum bfd_endian endian, const char *name, CGEN_BITSET *isas = 0, int machine = 0);
  string symbol_at_address;
  struct disassemble_info info;
  component *loader;
  output_pin disassembly_symbol_address_pin;

protected:
  static int cgen_read_memory (bfd_vma memaddr, bfd_byte *myaddr,
		     unsigned int length,
		     struct disassemble_info *info);
  static void cgen_print_address(bfd_vma addr, struct disassemble_info *info);
  static void cgen_memory_error(int status, bfd_vma memaddr,
		       struct disassemble_info *info);
  static int cgen_symbol_at_address(bfd_vma addr, struct disassemble_info * info);
  // Counter tracing support
  virtual void trace_counter (PCADDR pc);

public:
  // Called by semantic code to perform branches.
  virtual void
  branch (PCADDR new_pc, PCADDR& npc, sem_status& status)
  {
    branch_was_return = false;
  }

  // Called by the semantic code at the end of a non-cti insn.
  // Make this a NOP; ordinary sequential PC stepping is done
  // elsewhere.
  virtual void done_insn (PCADDR npc, sem_status& status) {}
     
  // Called by the semantic code at the end of a cti insn.
  virtual void
  done_cti_insn (PCADDR npc, sem_status& status)
  {
    if (branch_was_return)
      this->cg_return_pin.drive (npc);
    branch_was_return = false;
  }

  virtual void notify_ret (sid::host_int_4 addr) { branch_was_return = true; last_caller = addr; last_callee = 0; }

protected:
  bool branch_was_return;

public:
  cgen_bi_endian_cpu ();
  ~cgen_bi_endian_cpu () throw();

public:
  // rtl memory access methods
  inline QI
  GETMEMQI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_1 (pc, addr);
    }
  inline UQI
  GETMEMUQI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_1 (pc, addr);
    }
  inline void
  SETMEMBI(PCADDR pc, ADDR addr, BI value)
    {
      return this->write_data_memory_1 (pc, addr, value);
    }
  inline void
  SETMEMQI(PCADDR pc, ADDR addr, QI value)
    {
      return this->write_data_memory_1 (pc, addr, value);
    }
  inline void
  SETMEMUQI(PCADDR pc, ADDR addr, UQI value)
    {
      return this->write_data_memory_1 (pc, addr, value);
    }
  inline HI
  GETMEMHI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_2 (pc, addr);
    }
  inline UHI
  GETMEMUHI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_2 (pc, addr);
    }
  inline void
  SETMEMHI(PCADDR pc, ADDR addr, HI value)
    {
      return this->write_data_memory_2 (pc, addr, value);
    }
  inline void
  SETMEMUHI(PCADDR pc, ADDR addr, UHI value)
    {
      return this->write_data_memory_2 (pc, addr, value);
    }
  inline SI
  GETMEMSI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_4 (pc, addr);
    }
  inline void
  SETMEMSI(PCADDR pc, ADDR addr, SI value)
    {
      return this->write_data_memory_4 (pc, addr, value);
    }
  inline USI
  GETMEMUSI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_4 (pc, addr);
    }
  inline void
  SETMEMUSI(PCADDR pc, ADDR addr, USI value)
    {
      return this->write_data_memory_4 (pc, addr, value);
    }
  inline DI
  GETMEMDI(PCADDR pc, ADDR addr)
    {
      return this->read_data_memory_8 (pc, addr);
    }
  inline void
  SETMEMDI(PCADDR pc, ADDR addr, DI value)
    {
      return this->write_data_memory_8 (pc, addr, value);
    }
  inline void
  SETMEMUDI(PCADDR pc, ADDR addr, UDI value)
    {
      return this->write_data_memory_8 (pc, addr, value);
    }

  // floats (can you think of a better way to do this?)
  inline SF
  GETMEMSF(PCADDR pc, IADDR addr)
    {
      SI iv = this->read_data_memory_4 (pc, addr);
      return * (SF *)(char *)(& iv);
    }
  inline void
  SETMEMSF(PCADDR pc, ADDR addr, SF value)
    {
      SI iv = * (SI *)(char *)(& value);      
      return this->write_data_memory_4 (pc, addr, iv);
    }

  inline DF
  GETMEMDF(PCADDR pc, IADDR addr)
    {
      DI iv = this->read_data_memory_8 (pc, addr);
      return * (DF *)(char *)(& iv);
    }
  inline void
  SETMEMDF(PCADDR pc, ADDR addr, DF value)
    {
      DI iv = * (DI *)(char *)(& value);      
      return this->write_data_memory_8 (pc, addr, iv);
    }

  // IMEM: instruction memory calls

  inline QI
  GETIMEMQI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_1 (pc, addr);
    }
  inline void
  SETIMEMQI(PCADDR pc, ADDR addr, QI value)
    {
      return this->write_insn_memory_1 (pc, addr, value);
    }
  inline UQI
  GETIMEMUQI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_1 (pc, addr);
    }
  inline void
  SETIMEMUQI(PCADDR pc, ADDR addr, UQI value)
    {
      return this->write_insn_memory_1 (pc, addr, value);
    }
  inline HI
  GETIMEMHI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_2 (pc, addr);
    }
  inline void
  SETIMEMHI(PCADDR pc, ADDR addr, HI value)
    {
      return this->write_insn_memory_2 (pc, addr, value);
    }
  inline UHI
  GETIMEMUHI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_2 (pc, addr);
    }
  inline void
  SETIMEMUHI(PCADDR pc, ADDR addr, UHI value)
    {
      return this->write_insn_memory_2 (pc, addr, value);
    }
  inline SI
  GETIMEMSI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_4 (pc, addr);
    }
  inline void
  SETIMEMSI(PCADDR pc, ADDR addr, SI value)
    {
      return this->write_insn_memory_4 (pc, addr, value);
    }
  inline USI
  GETIMEMUSI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_4 (pc, addr);
    }
  inline void
  SETIMEMUSI(PCADDR pc, ADDR addr, USI value)
    {
      return this->write_insn_memory_4 (pc, addr, value);
    }
  inline DI
  GETIMEMDI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_8 (pc, addr);
    }
  inline void
  SETIMEMDI(PCADDR pc, ADDR addr, DI value)
    {
      return this->write_insn_memory_8 (pc, addr, value);
    }
  inline UDI
  GETIMEMUDI(PCADDR pc, IADDR addr)
    {
      return this->read_insn_memory_8 (pc, addr);
    }
  inline void
  SETIMEMUDI(PCADDR pc, ADDR addr, UDI value)
    {
      return this->write_insn_memory_8 (pc, addr, value);
    }



};

} // namespace cgen

#endif /* CGEN_CPU_H */
