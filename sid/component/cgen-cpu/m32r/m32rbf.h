// m32rbf.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cgen-cpu.h"
#include "m32r-desc.h"
// FIXME: The m32r- prefix here should really be m32rbf.
#include "m32r-defs.h"
#include "m32r-decode.h"

// ??? How to handle cpu variants (m32rbf vs m32rxf) is wip.

namespace m32rbf 
{

class m32rbf_cpu_cgen
{
// Include cgen generated elements.
#include "m32r-cpu.h"

protected:
  // These are called form within inline functions in m32r-cpu.h
  inline USI m32rbf_h_cr_get_handler (UINT regno) const;
  inline void m32rbf_h_cr_set_handler (UINT regno, USI newval);
  inline DI m32rbf_h_accum_get_handler () const;
  inline void m32rbf_h_accum_set_handler (DI newval);
  inline UQI m32rbf_h_psw_get_handler () const;
  inline void m32rbf_h_psw_set_handler (UQI newval);
};


class m32rbf_cpu: public m32rbf_cpu_cgen, public cgen_bi_endian_cpu
{
private:
  scache_engine<m32rbf_scache> engine;

  void step_insns ();
  void flush_icache ();
  void reset ();

  // debug support routines
  string dbg_get_reg (host_int_4 n);
  component::status dbg_set_reg (host_int_4 n, const string& s);

  // overload state save & restore
  void stream_state(ostream& o) const;
  void destream_state(istream& i);

public:
  m32rbf_cpu ();
  void set_pc (host_int_4 v) 
    { 
      this->hardware.h_pc = (PCADDR) v; 
    }

  // Called by semantic code to perform branches.
  inline void
  branch (PCADDR new_pc, PCADDR& npc, sem_status& status)
    {
      npc = new_pc;
    }

  // Called by the semantic code at the end of a non-cti insn.
  inline void
  done_insn (PCADDR npc, sem_status& status)
    {
      this->h_pc_set (npc);
    }

  // Called by the semantic code at the end of a cti insn.
  inline void
  done_cti_insn (PCADDR npc, sem_status& status)
    {
      this->h_pc_set (npc);
    }

  SI m32r_trap (PCADDR pc, UINT trap);
  void invalid_insn (PCADDR pc);
  void memory_trap (const cpu_memory_fault& t);
};

/* c-code & c-call hooks called from m32r.cpu */

#define PROFILE_COUNT_FILLNOPS(a,b)

inline SI
m32r_trap (m32rbf_cpu* cpu, PCADDR pc, USI trap)
{
  return cpu->m32r_trap (pc, trap);
}

// Support routines for register get/set specs.
// ??? Ideally, this would be written with the get/set specs.

inline USI
m32rbf_cpu_cgen::m32rbf_h_cr_get_handler (UINT regno) const
{
  switch (regno)
    {
    case H_CR_PSW : /* psw */
      return (((this->hardware.h_bpsw & 0xc1) << 8)
	      | ((this->hardware.h_psw & 0xc0) << 0)
	      | this->hardware.h_cond ? 0x01 : 0x00);
    case H_CR_BBPSW : /* backup backup psw */
      return this->hardware.h_bbpsw & 0xc1;
    case H_CR_CBR : /* condition bit */
      return this->hardware.h_cond ? 0x01 : 0x00;
    case H_CR_SPI : /* interrupt stack pointer */
      if ((this->hardware.h_psw & 0x80) == 0)
	return this->hardware.h_gr[H_GR_SP];
      else
	return this->hardware.h_cr[H_CR_SPI];
    case H_CR_SPU : /* user stack pointer */
      if ((this->hardware.h_psw & 0x80) != 0)
	return this->hardware.h_gr[H_GR_SP];
      else
	return this->hardware.h_cr[H_CR_SPU];
    case H_CR_BPC : /* backup pc */
      return this->hardware.h_cr[H_CR_BPC] & 0xfffffffe;
    case H_CR_BBPC : /* backup backup pc */
      return this->hardware.h_cr[H_CR_BBPC] & 0xfffffffe;
    case 4 : /* ??? unspecified, but apparently available */
    case 5 : /* ??? unspecified, but apparently available */
      return this->hardware.h_cr[regno];
    default :
      return 0;
    }
}

inline void
m32rbf_cpu_cgen::m32rbf_h_cr_set_handler (UINT regno, USI newval)
{
  switch (regno)
    {
    case H_CR_PSW : /* psw */
      {
	int old_sm = (this->hardware.h_psw & 0x80) != 0;
	int new_sm = (newval & 0x80) != 0;
	this->hardware.h_bpsw = (newval >> 8) & 0xff;
	this->hardware.h_psw = newval & 0xff;
	this->hardware.h_cond = (newval & 1);
	/* When switching stack modes, update the registers.  */
	if (old_sm != new_sm)
	  {
	    if (old_sm)
	      {
		/* Switching user -> system.  */
		this->hardware.h_cr[H_CR_SPU] = this->hardware.h_gr[H_GR_SP];
		this->hardware.h_gr[H_GR_SP] = this->hardware.h_cr[H_CR_SPI];
	      }
	    else
	      {
		/* Switching system -> user.  */
		this->hardware.h_cr[H_CR_SPI] = this->hardware.h_gr[H_GR_SP];
		this->hardware.h_gr[H_GR_SP] = this->hardware.h_cr[H_CR_SPU];
	      }
	  }
	break;
      }
    case H_CR_BBPSW : /* backup backup psw */
      this->hardware.h_bbpsw = newval & 0xff;
      break;
    case H_CR_CBR : /* condition bit */
      this->hardware.h_cond = (newval & 1);
      break;
    case H_CR_SPI : /* interrupt stack pointer */
      if ((this->hardware.h_psw & 0x80) == 0)
	this->hardware.h_gr[H_GR_SP] = newval;
      else
	this->hardware.h_cr[H_CR_SPI] = newval;
      break;
    case H_CR_SPU : /* user stack pointer */
      if ((this->hardware.h_psw & 0x80) != 0)
	this->hardware.h_gr[H_GR_SP] = newval;
      else
	this->hardware.h_cr[H_CR_SPU] = newval;
      break;
    case H_CR_BPC : /* backup pc */
      this->hardware.h_cr[H_CR_BPC] = newval;
      break;
    case H_CR_BBPC : /* backup backup pc */
      this->hardware.h_cr[H_CR_BBPC] = newval;
      break;
    case 4 : /* ??? unspecified, but apparently available */
    case 5 : /* ??? unspecified, but apparently available */
      this->hardware.h_cr[regno] = newval;
      break;
    default :
      /* ignore */
      break;
    }
}

inline DI
m32rbf_cpu_cgen::m32rbf_h_accum_get_handler () const
{
  DI r;
  r = ANDDI (this->hardware.h_accum, MAKEDI (0xffffff, 0xffffffff));
  r = XORDI (r, MAKEDI (0x800000, 0));
  r = SUBDI (r, MAKEDI (0x800000, 0));
  return r;
}

inline void
m32rbf_cpu_cgen::m32rbf_h_accum_set_handler (DI newval)
{
  this->hardware.h_accum = newval;
}

inline UQI
m32rbf_cpu_cgen::m32rbf_h_psw_get_handler () const
{
  return (this->hardware.h_psw & 0xfe) | (this->hardware.h_cond & 0x01);
}

inline void
m32rbf_cpu_cgen::m32rbf_h_psw_set_handler (UQI newval)
{
  this->hardware.h_psw  = newval & 0xfe; 
  this->hardware.h_cond = newval & 0x01; 
}

} // namespace m32rbf
