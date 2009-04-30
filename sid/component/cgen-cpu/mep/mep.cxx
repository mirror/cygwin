// mep.cxx - Implementations of hand-written functions for the Toshiba
// MeP simulator. -*- C++ -*-

// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "mep.h"
#include "fp.h"

extern "C" {
#include "bfd.h"
#include "dis-asm.h"
}

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace mep;


mep_cpu::mep_cpu ()
  :blocking_component (this, mep_cpu_child_thread_root),
   debugger_bus (& data_bus, & control_bus),
   interrupt_pin (this, &mep_cpu::interrupt_pin_handler),
   nmi_pin (this, &mep_cpu::nmi_pin_handler),
   write_to_code_pin (this, &mep_cpu::write_to_code_pin_handler),
   bit_insn_bad_address_pin (this, &mep_cpu::bit_insn_bad_address_pin_handler),
   hw_debugger_p (false),
   interrupt_pending_p (false),
   sleeping_p (false),
   interrupt_channel (-1),
   dsp_exception_pending_p (false),
   raise_ri_exception_p (false),
   config_index (0),
   cop_data_bus_width (32),
   dsp_dmem_if_width (32),
   data_bus_width (64),
   num_timer_channels (0),
   warn_write_to_code (false),
   dsp_user_out (false),
   corrupt_caches (false),
   step_insn_count_1_required (false),
   hwe_option (false),
   stepping (false),
   zap_required (false),
   saved_trace_result_p (false),
   blocked_latency (0),
   insn_buffer (0)
{
  for (int i = 0; i < NUM_INSN_OPTIONS; i++)
    insn_options[i] = false;

  // Initialise read-only registers; these are likely to be
  // overridden in configuration file, but just in case:
  hardware.h_csr[17] = 0x00000100; // ID
  hardware.h_csr[27] = 0x01000100; // RCFG
  hardware.h_csr[28] = 0x00000000; // CCFG
  
  for (int i = 0; i < 16; ++i)
    {
      string name;
      switch (i)
	{
	case 8: name = "$8 ($fp)"; break;
	case 13: name = "$13 ($tp)"; break;
	case 14: name = "$14 ($gp)"; break;
	case 15: name = "$15 ($sp)"; break;
	default:
	  name = string ("$") + make_numeric_attribute (i);
	}
      SI* value = &hardware.h_gpr[i];
      add_watchable_register (name, value);
    }

  for (int i = 0; i < 32; ++i)
    {
      if (i == 26) continue; // omit csr26 == OPT
      string name = string ("csr") + make_numeric_attribute (i);
      USI* value = (i == 0 ? (USI*) & hardware.h_pc :
		    (USI*) & hardware.h_csr[i]);
      add_watchable_register (name, value);
    }
  add_attribute_alias ("pc", "csr0");

  for (int i = 0; i < 64; ++i)
    {
      string name = string ("ccr") + make_numeric_attribute (i);
      SI* value = & hardware.h_ccr[i];
      add_watchable_register (name, value);
    }

  add_attribute ("abs-option?",    &insn_options[ABS],    "setting");
  add_attribute ("ave-option?",    &insn_options[AVE],    "setting");
  add_attribute ("bit-option?",    &insn_options[BIT],    "setting");
  add_attribute ("clip-option?",   &insn_options[CLIP],   "setting");
  add_attribute ("cp-option?",     &insn_options[CP],     "setting");
  add_attribute ("vliw32-option?", &insn_options[VL32],   "setting");
  add_attribute ("vliw64-option?", &insn_options[VL64],   "setting");
  add_attribute ("debug-option?",  &insn_options[DEBUG],  "setting");
  add_attribute ("div-option?",    &insn_options[DIV],    "setting");
  add_attribute ("dsp-option?",    &insn_options[DSP],    "setting");
  add_attribute ("ldz-option?",    &insn_options[LDZ],    "setting");
  add_attribute ("minmax-option?", &insn_options[MINMAX], "setting");
  add_attribute ("mul-option?",    &insn_options[MUL],    "setting");
  add_attribute ("sat-option?",    &insn_options[SAT],    "setting");
  add_attribute ("uci-option?",    &insn_options[UCI],    "setting"); 
  add_attribute ("ivc2-decode?",   &ivc2_decode_p,        "setting"); 
  add_attribute ("warn-write-to-code-option?", &warn_write_to_code, "setting");
  add_attribute ("dsp-user-out-option?", &dsp_user_out, "setting");
  add_attribute ("corrupt-caches?", &corrupt_caches, "setting");
  add_attribute ("hwe-option?", &hwe_option, "setting");
  add_attribute ("step-insn-count-1-required?", &step_insn_count_1_required, "setting");

  add_attribute ("config-index",       &config_index,       "setting"); 
  add_attribute ("cop-data-bus-width", &cop_data_bus_width, "setting"); 
  add_attribute ("dsp-dmem-if-width",  &dsp_dmem_if_width,  "setting"); 
  add_attribute ("data-bus-width",     &data_bus_width,     "setting"); 
  add_attribute ("num-timer-channels", &num_timer_channels, "setting"); 

  interrupt_pin.driven ((unsigned)-1);
  add_watchable_pin ("interrupt", &interrupt_pin);
  add_watchable_pin ("nmi", &nmi_pin);
  add_watchable_pin ("write-to-code-address", &write_to_code_pin);
  add_watchable_pin ("bit-insn-bad-address", &bit_insn_bad_address_pin);

  add_watchable_pin ("insn-cache-enable", &icache_enable_pin);
  add_watchable_pin ("data-cache-enable", &dcache_enable_pin);
  add_watchable_pin ("cache-flush", &cache_flush_pin);
  add_watchable_pin ("cache-index-flush", &cache_index_flush_pin);
  add_watchable_pin ("cache-invalidate", &cache_invalidate_pin);
  add_watchable_pin ("cache-flush-and-invalidate", &cache_flush_and_invalidate_pin);
  add_watchable_pin ("cache-index-invalidate", &cache_index_invalidate_pin);
  add_watchable_pin ("cache-index-flush-and-invalidate", &cache_index_flush_and_invalidate_pin);
  add_watchable_pin ("cache-prefetch", &cache_prefetch_pin);
  add_watchable_pin ("cache-write-hint", &cache_write_hint_pin);
  add_watchable_pin ("data-cache-invalidate-all", &data_cache_invalidate_all_pin);
  add_watchable_pin ("insn-cache-invalidate-all", &insn_cache_invalidate_all_pin);
  add_watchable_pin ("cache-operation-status", &cache_operation_status_pin);

  add_attribute ("hardware-debugger?", &hw_debugger_p, "setting");
  add_attribute ("raise-ri-exception?", &raise_ri_exception_p, "setting");

  control_bus = 0;
  add_accessor ("control-space", & control_bus);

  // override basic_cpu's debugger-bus with ours, which can see
  // control space.
  add_bus ("debugger-bus", & debugger_bus);
  add_attribute ("control-space-low", &(debugger_bus.ctrl_low), "setting"); 
  add_attribute ("control-space-high", &(debugger_bus.ctrl_high), "setting"); 

  // For gloss.
  add_watchable_register ("syscall-arg0", &syscall_arg0);
  add_attribute_alias ("syscall-arg1", "$1");
  add_attribute_alias ("syscall-arg2", "$2");
  add_attribute_alias ("syscall-arg3", "$3");
  add_attribute_alias ("syscall-arg4", "$4");
  add_attribute_alias ("syscall-result", "$0");
  add_attribute_alias ("syscall-error", "$1");

  syscall_trap_num = 47; // arbitrary magic value
  add_attribute ("syscall-trap", & syscall_trap_num);

  // For gdb.
  create_gdb_register_attrs (145, "12;15;16;32", & hardware.h_pc);

  // For uci/dsp connections
  add_pin ("uci-arg1", & this->ucipin_arg1);
  add_pin ("uci-arg2", & this->ucipin_arg2);
  add_pin ("uci-arg3", & this->ucipin_arg3);
  add_pin ("uci-arg4", & this->ucipin_arg4);
  add_pin ("uci-exception", & this->ucipin_exception);
  add_pin ("uci-result", & this->ucipin_result);
  add_pin ("dsp-arg1", & this->dsppin_arg1);
  add_pin ("dsp-arg2", & this->dsppin_arg2);
  add_pin ("dsp-arg3", & this->dsppin_arg3);
  add_pin ("dsp-arg4", & this->dsppin_arg4);
  add_pin ("dsp-arg7", & this->dsppin_arg7);
  add_pin ("dsp-exception", & this->dsppin_exception);
  add_pin ("dsp-cycles", & this->dsppin_cycles);
  add_pin ("dsp-result", & this->dsppin_result);

  // For disassembling state.
  this->downstream_passthrough_pin.set_active_high ();
  add_pin ("downstream-passthrough", & this->downstream_passthrough_pin);

  add_uni_relation ("insn-buffer", & insn_buffer);
}

void
mep_cpu::set_endian(sid::host_int_4 v)
{
  // Warn if the endianness does not match the configured setting
  switch (v)
    {
    case 1:
      if (current_endianness() != endian_big)
	cerr << "Warning: Switching to big endian to match the executable" << endl;
      break;
    case 2:
      if (current_endianness() != endian_little)
	cerr << "Warning: Switching to little endian to match the executable" << endl;
      break;
    default:
      break;
    }
  cgen_bi_endian_cpu::set_endian (v);
}

SI
mep_cpu::cgen_get_csr_value (SI index) const
{
  if (UNLIKELY ((index < 0) || (index >= 32)))
    index = 0; // should not happen!

  switch (index)
    {
    case 0: // PC
      return this->hardware.h_pc + 2;

    case 26: // OPT
      return this->opt_reg_value ();

    default:
      return this->hardware.h_csr [index];
    }
}


void
mep_cpu::cgen_set_csr_value (SI index, SI newval)
{
  if (UNLIKELY ((index < 0) || (index >= 32)))
    index = 0; // should not happen!

  SI writemask = 0xffffffff;

  switch (index)
    {
      // Read-only registers
    case 0: // PC
    case 17: // ID
    case 26: // OPT
    case 27: // RCFG
    case 28: // CCFG
      writemask = 0;
      break;

    case 1: // LP
    case 19: // EPC
    case 23: // NPC
      if (! insn_options[VL32] && ! insn_options[VL64])
	writemask = 0xfffffffe;
      break;

    case 2: // SAR
      writemask = 0x3f;
      break;

    case 4: // RPB
      writemask = 0xfffffffe;
      break;

    case 12: case 13: case 14: case 15: // modulo-address registers
      writemask = 0x0000ffff;
      break;

    case 16: // PSW
      writemask = 0x3ff;
      break;

    case 20: // EXC
      writemask = 0x30f0;
      if (core_type () == CORE_H1) writemask |= 0xce00; // NMI cause bits
      break;

    case 21: // CFG
      writemask = 0x00c00018;
      if (this->hardware.h_csr[28] & 0x007f0000) writemask |= 0x00000002; // icache
      if (this->hardware.h_csr[28] & 0x0000007f) writemask |= 0x00000001; // dcache
      if (core_type () == CORE_H1) writemask |= 0x3800; // ITOE, BTOE, BTPR
      break;

    case 22: // VID -- MEP_CORE_C3 and later only
      if (core_type () >= CORE_C3)
	writemask = 0;
      break;
    case 24: // DBG
      // Bit 10, DBG.BSF, is only written if 0.
      writemask = (newval & 0x400) ? 0x180 : 0x580;
      break;

    case 29: // BEA
    case 30: // TEPC
      if (core_type () == CORE_H1) writemask = 0;
      break;

    default:
      break;
    }

  this->hardware.h_csr[index] =	
    (this->hardware.h_csr[index] & ~writemask) |
    (newval & writemask);

  if (UNLIKELY(this->trace_result_p))
    {
      if (this->hardware.h_csr[index] != newval)
	this->trace_stream << "(0x" << hex << this->hardware.h_csr[index] << dec << ")  ";
    }

  // postprocesing
  if (UNLIKELY (index == 21))
    this->update_cache_pins();
}


SI
mep_cpu::opt_reg_value () const
{
  SI value = 0;

  // Toshiba wants this set to zero for now, even though we have a partial DSU
  // implementation.
  //  value |= insn_options[DEBUG];
  value |= insn_options[UCI] << 1;
  value |= insn_options[DSP] << 2;
  value |= insn_options[CP] << 4;
  value |= insn_options[VL32] << 5;
  value |= insn_options[VL64] << 6;
  value |= (num_timer_channels & 0x7) << 8;
  unsigned bis = (data_bus_width >> 6) & 0x1;
  value |= bis << 12;
  value |= bis << 14;
  value |= insn_options[LDZ] << 16;
  value |= insn_options[ABS] << 18;
  value |= insn_options[AVE] << 19;
  value |= insn_options[MINMAX] << 20;
  value |= insn_options[CLIP] << 21;
  value |= insn_options[SAT] << 22;
  value |= insn_options[BIT] << 23;
  value |= insn_options[MUL] << 24;
  value |= insn_options[DIV] << 25;
  value |= hwe_option << 26;
  if (core_type () >= CORE_C3)
    {
      value |= (cop_data_bus_width & 64) << (30 - 6);
      value |= (dsp_dmem_if_width  & 64) << (28 - 6);
    }

  return value;
}


// Drive new values onto the various output pins that shadow control
// register bits.
void
mep_cpu::update_cache_pins ()
{
  SI cfgreg = h_csr_get (cfg);
  if (!!this->icache_enable_pin.recall() != !!(cfgreg & 0x2))
    this->icache_enable_pin.drive ((cfgreg & 0x02) ? 1 : 0);

  if (!!this->dcache_enable_pin.recall() != !!(cfgreg & 0x1))
    this->dcache_enable_pin.drive ((cfgreg & 0x01) ? 1 : 0);
}

// Initialize the cache tags in the test areas to non-zero.
void
mep_cpu::init_caches ()
{
  // Only do this if --corrupt-caches was specified.
  if (! corrupt_caches)
    return;

  USI csr = h_csr_get (28);
  // Big or little doesn't matter, since it's symetrical.
  big_int_4 value = 0xffffffff;

  // Insn cache.
  USI size = (csr >> 16) & 0x3f;
  USI base = 0x310000;
  USI limit = base + size*1024;
  USI line_size = core_type () >= CORE_C3 ? (0x8 << ((csr >> 24) & 0x7)) : 32;
  for (ADDR addr = base; addr < limit; addr += line_size)
    {
      sid::bus::status s = this->data_bus->write (addr, value);
      assert (s == sid::bus::ok);
    }

  // Data cache.
  size = csr & 0x3f;
  base = 0x330000;
  limit = base + size*1024;
  line_size = core_type () >= CORE_C3 ? (0x8 << ((csr >> 8) & 0x7)) : 32;
  for (ADDR addr = base; addr < limit; addr += line_size)
    {
      sid::bus::status s = this->data_bus->write (addr, value);
      assert (s == sid::bus::ok);
    }
}

void
mep_cpu::reset ()
{
  hardware.h_pc = 0;
  interrupt_pending_p = false;
  dsp_exception_pending_p = false;
  nmi_suspended_p = false;
  nmi_pending_p = false;
  repeat_delayed_branch = false;
  bit_insn_p = false;

  // Clear general purpose registers.
  for (int i = 0; i < 16; i++)
    h_gpr_set (i, 0);

  // Clear coprocessor general purpose registers
  for (int i = 0; i < 32; i++)
    h_cr_set (i, 0);

  // Clear control/special purpose registers, except
  // read-only ones that reflect configuration
  for (int i = 0; i < 32; i++)
    switch (i)
      {
      case 17: // ID
      case 26: // OPT
      case 27: // RCFG
      case 28: // CCFG
	// Allow sid configuration file to set these.
	break;

      case 21: // CFG
	hardware.h_csr[21] = 0x28;
	if (core_type () == CORE_C4)
	  if (current_endianness() == endian_little)
	    hardware.h_csr[21] |= 0x80; // LEND
	break;

      default:
	// Go underneath the cover functions to ensure that even
	// read-only bits are cleared correctly.
	hardware.h_csr[i] = 0;
      }

  init_caches ();
  update_cache_pins ();
}

bool
mep_cpu::halted_p ()
{
  return (h_csr_get (psw) & (1 << 11));
}

bool
mep_cpu::nmi_p ()
{
  return (h_csr_get (psw) & 0x200);
}

void
mep_cpu::interrupt_pin_handler (host_int_4 channel)
{
  if (UNLIKELY (halted_p () || sleeping_p))
    {
      // Clear PSW.HALT.
      h_csr_set_internal (psw, h_csr_get (psw) & ~(1 << 11));
      sleeping_p = false;
    }

  // Test PSW.NMI.
  if (nmi_p ())
    return;

  if (channel != -1)
    {
      if (channel >= 32) return;
      
      // Test PSW.IEC and PSW.HIE.
      if (h_csr_get (psw) & 0x001 && 
	  h_csr_get (psw) & 0x100)
	{
	  // Set PSW.HIP.
	  interrupt_channel = channel;
	  h_csr_set_internal (exc, h_csr_get (exc) | (1 << 8));
	  interrupt_pending_p = true;
	}
    }
  else
    {
      // Clear PSW.HIP.
      h_csr_set_internal (exc, h_csr_get (exc) & ~(1 << 8));
      interrupt_channel = -1;
      interrupt_pending_p = false;
    }
}

void
mep_cpu::nmi_pin_handler (host_int_4 ignored)
{
  if (UNLIKELY (halted_p () || sleeping_p))
    {
      // Clear PSW.HALT.
      h_csr_set_internal (psw, h_csr_get (psw) & ~(1 << 11));
      sleeping_p = false;
    }

  if (nmi_p ())
    nmi_suspended_p = true;
  else
    {
      nmi_suspended_p = false;
      nmi_pending_p = true;
      h_csr_set_internal (psw, h_csr_get (psw) | 0x200);
    }
}

void
mep_cpu::write_to_code_pin_handler (host_int_4 addr)
{
  // Avoid generating an error when GDB is loading the program.
  if (warn_write_to_code && stepping)
    {
      cerr << "Warning: invalid write to code segment address 0x" << std::hex
	   << addr << std::dec << endl;
    }

  // Invalidate this address in the decoder caches.
  zap_required = true;
}

void
mep_cpu::bit_insn_bad_address_pin_handler (host_int_4 addr)
{
  if (bit_insn_p)
    {
      cerr << "Warning: invalid address for bit manipulation instruction: 0x" << std::hex
	   << addr << std::dec << endl;
      bit_insn_p = false; // Only one warning per insn
    }
}

USI
mep_cpu::vector_base_address (bool exception_p)
{
  SI reg = h_csr_get (cfg);
  BI eva = (reg >> 23) & 1;
  BI iva = (reg >> 22) & 1;
  BI evm = (reg >> 4) & 1;
  BI ivm = (reg >> 3) & 1;

  if (exception_p)
    {
      if (!evm)
	return 0;
      else 
	return (!eva) ? 0x200000 : 0x800000;
    }
  else
    {
      unsigned offset = (ivm && !exception_p) ? interrupt_channel * 4 : 0;
      if (!evm)
	return 0x30 + offset;
      else 
	{
	  if (!eva)
	    return (iva) ? (0x800000 + offset) : (0x200030 + offset);
	  else
	    return (iva) ? (0x800030 + offset) : (0x200000 + offset);
	}
    }
}

USI
mep_cpu::ri_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "[RI exception] epc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (exc);
  reg = (reg & ~0xf) | 2;
  h_csr_set_internal (exc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "exc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "psw:=0x" << hex << reg << dec << "  ";

  return vector_base_address () + 0x8;
}

USI
mep_cpu::nmi_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> NPC.NPC. PSW.OM -> NPC.NTOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (npc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "0x" << hex << pc << ": NMI!    npc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (psw);
  reg |= (1 << 9);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "psw:=0x" << hex << reg << dec << "  ";

  return 0x4; // NMI always branches to 0x4
}

USI
mep_cpu::hw_int_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "0x" << hex << pc << ": INTR!   epc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (exc);
  reg = ((reg >> 4) << 4);
  h_csr_set_internal (exc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "exc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "psw:=0x" << hex << reg << dec << "  ";

  return vector_base_address (false);
}


bool
mep_cpu::swi_pending_p ()
{
  if (h_csr_get (psw) & 0x200)
    return false;
  
  // Interrupts enabled?
  if (h_csr_get (psw) & 1)
    {
      unsigned the_psw = h_csr_get (psw);
      unsigned the_exc = h_csr_get (exc);
      // Any swi's pending that are enabled?
      if (the_psw & the_exc & 0xf0)
	return true;
    }

  return false;
}


USI
mep_cpu::swi_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "0x" << hex << pc << ": EXCN   epc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (exc);
  reg = ((reg >> 4) << 4) | 5;
  h_csr_set_internal (exc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "exc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "psw:=0x" << hex << reg << dec << "  ";

  return vector_base_address() + 0x14;
}

USI
mep_cpu::break_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "epc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (exc);
  reg = ((reg >> 4) << 4) | 4;
  h_csr_set_internal (exc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "exc:=0x" << hex << reg << dec << "  ";
  
  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "psw:=0x" << hex << reg << dec << "  ";

  return vector_base_address () + 0x10;
}

USI
mep_cpu::zdiv_exception (PCADDR pc)
{
  // Compute exception address
  USI cfg_reg = h_csr_get (cfg);
  BI emv = (cfg_reg >> 23) & 1;
  BI eva = (cfg_reg >> 4) & 1;

  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
 USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "epc:=0x" << hex << reg << dec << "  ";
  
  reg = h_csr_get (exc);
  reg = ((reg >> 4) << 4) | 3;
  h_csr_set_internal (exc, reg);

  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  if (UNLIKELY (trace_result_p))
    trace_stream << "psw:=0x" << hex << reg << dec << "  ";

  return vector_base_address() + 0xc;
}

USI
mep_cpu::cop_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_semantics_p))
    trace_stream << "[COP exception] epc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (exc);
  reg = (reg & ~0xf) | 8;
  h_csr_set_internal (exc, reg);

  if (UNLIKELY (trace_semantics_p))
    trace_stream << "exc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  return vector_base_address() + 0x20;
}

USI
mep_cpu::dsp_exception (PCADDR pc)
{
  // Upper 31 bits of pc -> EPC.EPC. PSW.OM -> EPC.ETOM.
  USI reg = ((pc >> 1) << 1) | ((h_csr_get (psw) >> 12) & 1);
  h_csr_set_internal (epc, reg);

  if (UNLIKELY (trace_semantics_p))
    trace_stream << "[DSP exception] epc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (exc);
  reg = (reg & ~0xf) | 7;
  h_csr_set_internal (exc, reg);

  if (UNLIKELY (trace_semantics_p))
    trace_stream << "exc:=0x" << hex << reg << dec << "  ";

  reg = h_csr_get (psw);
  // PSW.IEC -> PSW.IEP.
  reg &= static_cast<USI>(~2);
  reg |= (reg & 1) << 1;
  // PSW.UMC -> PSW.UMP.
  reg &= static_cast<USI>(~8);
  reg |= (reg & 4) << 1;
  // Clear bit 0 (PSW.IEC) and bit 2 (PSW.UMC).
  reg &= static_cast<USI>(~5);
  // Always clear PSW.OM (go to core mode).
  reg &= static_cast<USI>(~(1 << 12));
  h_csr_set_internal (psw, reg);

  return vector_base_address() + 0x1c;
}



void
mep_cpu::invalid_insn (PCADDR pc)
{
  if (raise_ri_exception_p)
    h_pc_set (ri_exception (pc));
  else
    {
      cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_invalid_insn, pc);
      switch (whatnext)
	{
	case cpu_trap_unhandled:
	  cerr << "XXX: invalid insn @ " << hex << pc << dec << endl;
	  break;
	  
	case cpu_trap_skip:
	  this->h_pc_set (pc + 2);
	  break;
	  
	case cpu_trap_handled:
	case cpu_trap_reissue:
	  break;
	  
	default:
	  abort ();
	}
    }

  this->yield();
  throw cpu_exception ();
}

VOID
mep_cpu::do_cache (USI& op, int& rma, PCADDR& pc)
{
  // loop until operation is complete
  for (;;)
    {
      USI value = rma;
      switch (op)
	{
	case 0: // address
	  check_option_dcache (pc);
	  cache_flush_pin.drive (value);
	  break;
	case 1: // index
	  check_option_dcache (pc);
	  cache_index_flush_pin.drive (value); 
	  break;
	case 2: // address
	  check_option_dcache (pc);
	  cache_flush_and_invalidate_pin.drive (value); 
	  break;
	case 3: // index
	  check_option_dcache (pc);
	  cache_index_flush_and_invalidate_pin.drive (value); 
	  break;
	case 5:
	  if (core_type () == CORE_C5)
	    {
	      check_option_dcache (pc);
	      cache_write_hint_pin.drive (value);
	    }
	  break;
	case 6: // address
	  if (core_type () == CORE_H1
	      || core_type () == CORE_C5)
	    {
	      check_option_dcache (pc);
	      cache_invalidate_pin.drive (value); 
	    }
	  break;
	case 7: // data cache invalidate all
	  if (core_type () == CORE_H1)
	    {
	      check_option_dcache (pc);
	      data_cache_invalidate_all_pin.drive (value); 
	    }
	  break;
	case 15: // insn cache invalidate all
	  if (core_type () == CORE_H1)
	    {
	      check_option_icache (pc);
	      insn_cache_invalidate_all_pin.drive (value); 
	    }
	  break;
	default:
	  return;
	}
      if (! blockable)
	return; // done

      // May have to wait if the cache was blocked
      host_int_4 cache_status = cache_operation_status_pin.sense ();
      bus::status st (static_cast<bus::status_t>(cache_status & 0xff), (cache_status >> 16) & 0xffff);
      if (st == bus::ok)
	{
	  record_blocked_latency (st);
	  return;
	}
      handle_bus_error (st);
    }
}

VOID
mep_cpu::do_cache_prefetch (USI& op, int rma, PCADDR& pc)
{
  // Only implemented on the H1 and C5 cores.
  if (core_type () != CORE_H1
      && core_type () != CORE_C5)
    {
      invalid_insn (pc);
      return;
    }

  USI value = rma;
  switch (op)
    {
    case 0: // address
      cache_prefetch_pin.drive (value);
      break;
    }
}

SI
mep_cpu::do_ldz (SI rm)
{
  int i;
  for (i = 0; i < 32; i++)
    {
      if (LIKELY ((rm & 0x80000000) == 0))
	rm <<= 1;
      else
	break;
    }
  return i;
}

VOID
mep_cpu::do_smcp (USI rma, DI crn, PCADDR &pc)
{
  if (UNLIKELY(trace_result_p))
    trace_stream << "memory" << '[' <<  "0x" << hex << rma << ']' << ":=0x" << crn << dec << "  ";

  if (cop_data_bus_width == 64)
    SETMEMDI (pc, rma & ~7, crn);
  else
    SETMEMSI (pc, rma & ~7, crn);
}

DI
mep_cpu::do_lmcp (USI rma, PCADDR &pc)
{
  if (cop_data_bus_width == 64)
    return GETMEMDI (pc, rma & ~7);

  return GETMEMSI (pc, rma & ~7);
}

VOID
mep_cpu::do_smcpa (UINT rma_ix, SI cdisp8a8, DI crn, PCADDR &pc)
{
  USI rma = h_gpr_get (rma_ix);
  do_smcp (rma, crn, pc);
  h_gpr_set (rma_ix, rma + cdisp8a8);
}

DI
mep_cpu::do_lmcpa (UINT rma_ix, SI cdisp8a8, PCADDR &pc)
{
  USI rma = h_gpr_get (rma_ix);
  h_gpr_set (rma_ix, rma + cdisp8a8);
  return do_lmcp (rma, pc);
}

VOID
mep_cpu::do_smcpi (UINT rma_ix, DI crn, PCADDR &pc)
{
  if (cop_data_bus_width == 64)
    do_smcpa (rma_ix, 8, crn, pc);
  else
    do_smcpa (rma_ix, 4, crn, pc);
}

DI
mep_cpu::do_lmcpi (UINT rma_ix, PCADDR &pc)
{
  if (cop_data_bus_width == 64)
    return do_lmcpa (rma_ix, 8, pc);

  return do_lmcpa (rma_ix, 4, pc);
}

VOID
mep_cpu::do_smcp16 (USI rma, SI sdisp16, DI crn, PCADDR &pc)
{
  do_smcp (rma + sdisp16, crn, pc);
}

DI
mep_cpu::do_lmcp16 (USI rma, SI sdisp16, PCADDR &pc)
{
  return do_lmcp (rma + sdisp16, pc);
}

VOID
mep_cpu::do_syscall (PCADDR pc, int syscall_num)
{
  // Get the syscall arguments
  syscall_arg0 = syscall_num;
  SI syscall_arg1 = h_gpr_get (1);
  SI syscall_arg2 = h_gpr_get (2);
  SI syscall_arg3 = h_gpr_get (3);
  SI syscall_arg4 = h_gpr_get (4);

  host_int_4 save_passthrough = this->downstream_passthrough_pin.recall ();
  this->downstream_passthrough_pin.on ();

  cpu_trap_disposition whatnext = 
    this->signal_trap (cpu_trap_software, syscall_trap_num);

  this->downstream_passthrough_pin.set (save_passthrough);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      invalid_insn (pc);
      return;

    case cpu_trap_reissue:
      // Restore the syscall arguments
      h_gpr_set (1, syscall_arg1);
      h_gpr_set (2, syscall_arg2);
      h_gpr_set (3, syscall_arg3);
      h_gpr_set (4, syscall_arg4);
      break;

    case cpu_trap_skip:
      this->h_pc_set (pc + 4);
      // fall-through

    case cpu_trap_handled:
      // must get syscall results and place them in current context registers
      string err_attr = attribute_value ("syscall-error");
      string result_attr = attribute_value ("syscall-result");
      
      host_int_4 err_num, result_num;
      parse_attribute(err_attr, err_num);
      parse_attribute(result_attr, result_num);

      // return code in $0
      h_gpr_set (0, result_num);

      // errno in $1
      h_gpr_set (1, err_num);
      return;
    }

  this->yield();
  throw cpu_exception ();
}

SI
mep_cpu::do_ldcb (UINT word_addr)
{
  big_int_4 value;

  sid::bus::status s;
  if (LIKELY (control_bus))
    s = control_bus->read (word_addr * 4, value);
  else
    s = sid::bus::unmapped;

  if (LIKELY (s == sid::bus::ok))
    return (SI) value;

  cerr << "Warning: read from control bus address 0x" << std::hex
       << word_addr << std::dec << " is out of range"
       << endl;

  return 0;
}

VOID
mep_cpu::do_stcb (SI rn, UINT word_addr)
{
  big_int_4 value = rn;

  sid::bus::status s;
  if (LIKELY (control_bus))
    s = control_bus->write (word_addr * 4, value);
  else
    s = sid::bus::unmapped;

  if (UNLIKELY (s != sid::bus::ok))
    {
      cerr << "Warning: write to control bus address 0x" << std::hex
	   << word_addr << std::dec << " is out of range"
	   << endl;
    }
}

bool
mep_cpu::imem_address (UINT address)
{
  SI rcfg_reg = h_csr_get (rcfg);
  unsigned imemsize = (rcfg >> 16) & 0x7f;

  if (address >= 0x200000 && address < 0x200000 + imemsize)
    return true;

  return false;
}

VOID
mep_cpu::check_write_to_text (UINT address)
{
  if (! warn_write_to_code)
    return;

  if (imem_address (address))
    {
      cerr << "Warning: write to IMEM address 0x" << std::hex <<
	address << std::dec << endl;
      return;
    }
}

VOID
mep_cpu::do_sleep ()
{
  sleeping_p = true;
}

// C5 Instructions

VOID
mep_cpu::do_casb3 (SI rl, SI rn, UINT word_addr, UINT pc)
{
  SI temp;

  // Compare and swap byte:
  // temp <- Rl
  // Rl <- ZeroExt (MemByte (Rm))
  // if (temp == Rl)
  //   MemByte (Rm) <- Rn [0..7]
  // else
  //   MemByte (Rm) <- Rl [0..7]

  temp = h_gpr_get (rl);
  h_gpr_set (rl, ZEXTQISI (GETMEMQI (pc, word_addr)));

  if (temp == h_gpr_get (rl))
    SETMEMQI (pc, word_addr, rn);
  else
    SETMEMQI (pc, word_addr, rl);
}

VOID
mep_cpu::do_cash3 (SI rl, SI rn, UINT word_addr, UINT pc)
{
  SI temp;

  temp = h_gpr_get (rl);
  h_gpr_set (rl, ZEXTHISI (GETMEMHI (pc, word_addr)));

  if (temp == h_gpr_get (rl))
    SETMEMHI (pc, word_addr, rn);
  else
    SETMEMHI (pc, word_addr, rl);
}

VOID
mep_cpu::do_casw3 (SI rl, SI rn, UINT word_addr, UINT pc)
{
  SI temp;

  temp = h_gpr_get (rl);
  h_gpr_set (rl, GETMEMSI (pc, word_addr));

  if (temp == h_gpr_get (rl))
    SETMEMSI (pc, word_addr, rn);
  else
    SETMEMSI (pc, word_addr, rl);
}

// UCI/DSP pin protocols

SI
mep_cpu::do_DSP (UINT rn, UINT rm, USI code, PCADDR /* pc */)
{
  // Temporarily suspend normal sid semantic tracing.
  saved_trace_result_p = true;
  trace_result_p_cache = trace_result_p;
  trace_result_p = false;

  // "precharge" input pins
  this->dsppin_result.driven (rn);
  this->dsppin_cycles.driven (1);
  this->dsppin_exception.driven (0);

  this->dsppin_arg1.drive (rn);
  this->dsppin_arg2.drive (rm);
  this->dsppin_arg4.drive (0); // indicates DSP not UCI
  this->dsppin_arg7.drive (0xf0000000 | ((code & 0x00ff0000) << 4) | (code & 0xffff));
  this->dsppin_arg3.drive (code & 0xffff); 
  // if connected, DSP unit will perform computation during previous drive().

  if (this->dsppin_exception.sense ())
    this->dsp_exception_pending_p = true;

  this->update_total_latency (this->dsppin_cycles.sense () - 1);

  return this->dsppin_result.sense ();
}

SI
mep_cpu::do_UCI (UINT rn, UINT rm, USI code, PCADDR /* pc */)
{
  // "precharge" input pins
  this->ucipin_result.driven (rn);
  this->ucipin_exception.driven (0);

  this->ucipin_arg1.drive (rn);
  this->ucipin_arg2.drive (rm);
  this->ucipin_arg4.drive (0xf0020000 | ((code & 0x00ff0000) << 4) | (code & 0xffff));
  this->ucipin_arg3.drive (code & 0xffff);
  // if connected, UCI unit will perform computation during previous drive().

  // if (this->ucipin_exception.sense ())
  //  this->uci_exception_pending_p = true;

  return this->ucipin_result.sense ();
}


// Debug support routines

string
mep_cpu::dbg_get_reg (host_int_4 reg)
{
  host_int_8 value;
  unsigned len = 4;

  if (reg >= 0 && reg < 16)
    value = h_gpr_get (reg);
  else if (reg == 16)
    value = h_pc_get ();
  else if (reg > 16 && reg < 48)
    value = h_csr_get (reg - 16);
  else if (reg > 47 && reg < 80)
    {
      value = h_cr64_get (reg - 48);
      len = 8;
    }
  else if (reg > 79 && reg < 144)
    value = h_ccr_get (reg - 80);
  else if (reg == 144)
    value = config_index;
  else
    value = 0;

  string attr;
  // change to "target endian": write the least significant bits
  // of the value, according to current_endianness ().
  if (current_endianness() == endian_big)
    {
      big_int_8 v = value;
      for (unsigned i = 8 - len; i < 8; i++)
	attr += v.read_byte (i);
    }
  else
    {
      little_int_8 v = value;
      for (unsigned i = 0; i < len; i++)
	attr += v.read_byte (i);
    }
  assert (attr.length () == len);

  return attr;
}

component::status
mep_cpu::dbg_set_reg (host_int_4 reg, const string& attr)
{
  if ((reg < 0) || (reg > 143))
    return component::bad_value;
  
  unsigned len = attr.length ();

  if (reg > 47 && reg < 80)
    {
      /* Coprocessor general-purpose registers are 64 bits long.  */
      if (len != 8)
        return component::bad_value;
    }
  else
    {
      /* All other registers are 32 bits long.  */
      if (len != 4)
        return component::bad_value;
    }
  
  host_int_8 value;
  // change from "target endian": store the new bytes in the least
  // significant end of the value.
  if (current_endianness() == endian_big)
    {
      big_int_8 v;
      for (unsigned i=1; i<=len; i++)
	v.write_byte (8 - i, attr[len - i]);
      value = v;
    }
  else
    {
      little_int_8 v;
      for (unsigned i=0; i<len; i++)
	v.write_byte (i, attr[i]);
      value = v;
    }

  if (reg < 16)
    h_gpr_set (reg, value);
  else if (reg == 16)
    h_pc_set (value);
  else if (reg > 16 && reg < 48)
    h_csr_set (reg - 16, value);
  else if (reg > 47 && reg < 80)
    h_cr64_set (reg - 48, value);
  else if (reg > 79 && reg < 144)
    h_ccr_set (reg - 80, value);

  return component::ok;
}


// Memory trap(/fault) handling.
void
mep_cpu::memory_trap (const cpu_memory_fault& t)
{
  this->h_pc_set (t.pc);
  
  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_memory_fault, t.address);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      cerr << "hw-cpu-mep: memory fault handler unimplemented!" << endl;
      break;

    case cpu_trap_skip:
      this->h_pc_set (t.pc + 2); // XXX: or it may be 4?
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
}

component::status
mep_cpu::dynamic_config(const string& spec)
{
  // Call up to the base class
  component::status s = cgen_bi_endian_cpu::dynamic_config (spec);

  // Check whether insn-count must be forced to 1
  if (step_insn_count_1_required || blockable)
    configure ("insn-count=1");

  return s;
}

void
mep_cpu::configure (const string &config)
{
  // Call up to the base classes first
  cgen_bi_endian_cpu::configure (config);
  blocking_component::configure (config);

  // Now handle relevent configuration for us.
  if (config.size () <= 13)
    return;
  if (config.substr (0, 13) == "model-busses=")
    {
      blockable = (config.substr (13) == "true");
      if (insn_buffer)
	insn_buffer->set_attribute_value ("blockable?", make_attribute (blockable));
      this->downstream_passthrough_pin.set (! blockable);
      return;
    }
}


// Common parts of instruction stepping
void
mep_cpu::step_insns()
{
  PCADDR save_pc;
  stepping = true;

  this->h_regs_flush_write_queue ();

  while (true)
    {
      // Check whether the scaches need to be flushed.
      if (zap_required)
	{
	  zap_scaches ();
	  zap_required = false;
	}

      PCADDR pc = this->h_pc_get ();
      
      // All interrupts are deferred when we are executing the last instruction
      // of a repeat block.

      if (! repeat_delayed_branch)
	{
	  if (UNLIKELY (swi_pending_p ()))
	    pc = swi_exception (pc);
	  
	  // The hw interrupt pin only signals us when its status _changes_;
	  // however, a user program may change our response to the interrupt
	  // signal, by twiddling PSW for example, so we need to re-check
	  // whether an asserted interrupt has any affect on us, each step.
	  if (UNLIKELY (this->interrupt_pin.sense () != -1))
	    this->interrupt_pin_handler (this->interrupt_pin.sense ());
	  
	  if (UNLIKELY (this->interrupt_pending_p))
	    {
	      this->interrupt_pending_p = false;
	      pc = hw_int_exception (pc);
	    }
	  if (UNLIKELY (this->nmi_pending_p))
	    {
	      pc = nmi_exception (pc);
	      this->nmi_pending_p = false;
	    }
	  else if (UNLIKELY (this->nmi_suspended_p))
	    {
	      h_csr_set_internal (psw, h_csr_get (psw) | 0x200);
	      this->nmi_suspended_p = false;
	      pc = nmi_exception (pc);
	    }	  
	}

      if (UNLIKELY (halted_p () || sleeping_p))
	break;

      // Run the instruction

      PCADDR insn_pc = pc;
      sem_status s = SEM_STATUS_NORMAL;
      host_int_4 insn_size;
      try 
	{
	  // Call down to VLIW or non-VLIW steppers
	  s = this->step_one_insn (pc, insn_size);

	  // Now copy any queued writes to the main registers.
	  this->h_regs_flush_write_queue ();

	  // Handle fresh DSP exception
	  if (UNLIKELY (this->dsp_exception_pending_p))
	    {
	      this->dsp_exception_pending_p = false;
	      pc = dsp_exception (pc);
	      this->h_pc_set (pc);
	      s = SEM_STATUS_BRANCH_TAKEN;
	    }

	  // Increment PC, if not already done with a branch.
	  switch (s)
	    {
	    case SEM_STATUS_NORMAL:
	      this->h_pc_set (pc + insn_size);
	      break;

	    case SEM_STATUS_BRANCH_TAKEN:
	      break;

	    case SEM_STATUS_STALLED:
	      this->h_pc_set (pc);
	      break;

	    default:
	      // Can't happen.
	      abort ();
	    }
	}
      // ??? Is this deferred?
      catch (cpu_memory_fault& t)
        {
          this->memory_trap (t);
          break;
        }
      // ??? Is this deferred?
      catch (cpu_exception& t)
        {
           this->yield ();
        }
      catch (fp::error& fe)
        {
	  int status = fe;
	  pc = this->fpu_exception (pc, status);
	  if (status == 0) // no exception
	    this->h_pc_set (pc + insn_size);
	  else
	    this->h_pc_set (pc);
        }

      // Check to see if we're stalled
      if (UNLIKELY (s == SEM_STATUS_STALLED))
	{
	  // stop_after_insns_p increments this, but we don't want to
	  // count this insn yet.
	  --this->total_insn_count;
	}
      else
	{
	  if (UNLIKELY (trace_counter_p || trace_semantics_p
			|| trace_disass_p || trace_result_p))
	    this->end_trace ();
        
	  // Do post-instruction processing  ----------------------------

	  USI rpb = h_csr_get (4);
	  USI rpe = h_csr_get (5);
	  USI rpc = h_csr_get (6);

	  // Branch back to the beginning of a repeat block if the previous
	  // instruction pc matched rpe and the current instruction was not a
	  // taken branch.
	  if (UNLIKELY (repeat_delayed_branch))
	    {
	      repeat_delayed_branch = false;
	      if (s != SEM_STATUS_BRANCH_TAKEN)
		h_pc_set (rpb);
	      else
		// The branch is executed, but RPC is now undefined.
		;
	    }
      
	  if (UNLIKELY (pc == (rpe & ~ (USI) 1)))
	    {
	      // a repeat block is active
	      
	      // Second to last instruction is a taken branch.  RPC is now
	      // undefined.
	      
	      if (s == SEM_STATUS_BRANCH_TAKEN)
		;
	      
	      // EREPEAT
	      else if (rpe & 1)
		repeat_delayed_branch = true;
	      
	      // REPEAT
	      else if (rpc > 0)
		{
		  rpc--;
		  h_csr_set_internal (6, rpc);
		  repeat_delayed_branch = true;
		}
	    }
	  
	  if (! repeat_delayed_branch && this->enable_step_trap_p) 
	    this->signal_trap (sidutil::cpu_trap_stepped);
	  this->triggerpoint_manager.check_and_dispatch ();
	} // not stalled
      
      // test for exit condition
      // Any latency sampled for gprof belongs to this insn, but the pc
      // has already been advanced.
      save_pc = this->h_pc_get ();
      this->h_pc_set (insn_pc);
      if (stop_after_insns_p (1))
	{
	  this->h_pc_set (save_pc);
	  break;
	}
      this->h_pc_set (save_pc);
    }
  stepping = false;
}

// Virtual override of step_pin_handler
//
void 
mep_cpu::step_pin_handler (sid::host_int_4 v)
{
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      continue_child_thread_and_wait ();
      return;
    }

  cgen_bi_endian_cpu::step_pin_handler (v);
}

// Handles bus errors from reads and writes from/to insn and data memory.
// Specifically, bus::busy is handled in blockable mode.
//
bool
mep_cpu::handle_bus_error (sid::bus::status s)
{
  if (s != sid::bus::busy)
    return false; // not handled

  // Reschedule for after the length of time the bus will be busy.
  // This will also block this child thread so that we continue
  // from here when scheduled again.
  record_blocked_latency (s);

  return true;
}

// This function is the root of the blockable child thread. It gets passed
// to pthread_create.
//
extern "C" void *
mep_cpu_child_thread_root (void *comp)
{
  // Set up this thread to receive and handle signals from the parent thread.
  // this need only be done once.
  //
  mep_cpu *cpu = static_cast<mep_cpu *>(comp);
  cpu->child_init ();

  for (;;)
    {
      // Signal completion and wait for the signal to resume
      cpu->child_completed ();

      // Call the parent class' step_pin_handler
      cpu->parent_step_pin_handler (1);
    }

  // We should never reach here.
  return NULL;
}
