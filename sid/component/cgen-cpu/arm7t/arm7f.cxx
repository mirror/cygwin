// arm7f.cxx - Implementations of hand-written functions for the ARM7
// simulator.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "arm7f.h"

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace arm;
using namespace arm7f;


arm7f_cpu::arm7f_cpu ():
  arm_engine (32768),   // XXX: tune size
  thumb_engine (32768), // XXX: tune size
  nfiq_pin (this, & arm7f_cpu::do_nfiq_pin),
  nirq_pin (this, & arm7f_cpu::do_nirq_pin),
  initialized_p (false)
{
  // ??? One might want to quibble over the case of these pins (nFIQ?).
  add_watchable_pin ("nm", & nm_pin);
  add_watchable_pin ("tbit", & tbit_pin);
  // add_watchable_pin ("isync", & isync_pin);
  add_watchable_pin ("nfiq", & nfiq_pin);
  add_watchable_pin ("nirq", & nirq_pin);
  // add_watchable_pin ("nreset", & nreset_pin);

  // Default is the scache engine.
  this->set_scache_engine ();
  // Don't set the registers etc to power-up values here.
  // Defer it to the reset signal.

  // Create attributes to access our innards.

  // R15 is the pc.
  // ??? However, the system distinguishes between the pc as being the
  // current (or next) instruction to execute and the value of r15 read
  // by an instruction (they're different, but related).  The "pc" attribute
  // returns the former, and "r15" the latter.
  for (unsigned i = 0; i < 16; ++i)
    {
      string name = string ("r") + make_numeric_attribute (i);
      SI* value = & this->hardware.h_gr[i];
      this->add_watchable_register (name, value);

      if (i >= 8 && i <= 14)
	{
	  value = & this->hardware.h_gr_fiq[i-8];
	  this->add_watchable_register (name + "_fiq", value);
	}
      if (i >= 13 && i <= 14)
	{
	  this->add_watchable_register (name + "_svc", & this->hardware.h_gr_svc[i-13]);
	  this->add_watchable_register (name + "_abt", & this->hardware.h_gr_abt[i-13]);
	  this->add_watchable_register (name + "_irq", & this->hardware.h_gr_irq[i-13]);
	  this->add_watchable_register (name + "_und", & this->hardware.h_gr_und[i-13]);
	}
    }
  // add pc itself after r15
  if (true)
    {
      string name = "pc";
      USI* value = & this->hardware.h_pc;
      this->add_watchable_register (name, value);
    }

  // ... and for registers exposed via virtual attributes 
  add_attribute_virtual ("cpsr", this,
			 & arm7f_cpu::get_h_cpsr_for_attr,
			 & arm7f_cpu::set_h_cpsr_for_attr, "register");
  this->triggerpoint_manager.add_watchable_attribute ("cpsr");
  this->categorize ("cpsr", "watchable");

  add_attribute_virtual ("cpsr-flags", this,
			 & arm7f_cpu::get_h_cpsr2_for_attr,
			 & arm7f_cpu::set_h_cpsr2_for_attr, "register");

  add_watchable_register ("spsr_fiq", & this->hardware.h_spsr_fiq);
  add_watchable_register ("spsr_svc", & this->hardware.h_spsr_svc);
  add_watchable_register ("spsr_abt", & this->hardware.h_spsr_abt);
  add_watchable_register ("spsr_irq", & this->hardware.h_spsr_irq);
  add_watchable_register ("spsr_und", & this->hardware.h_spsr_und);

  // Add register access for debugger
  this->create_gdb_register_attrs (26, "7;11;13;14;15;25", & this->hardware.h_pc);
}

string
arm7f_cpu::get_h_cpsr2_for_attr ()
{
  string n = this->hardware.h_nbit ? "N" : "";
  string z = this->hardware.h_zbit ? "Z" : "";
  string c = this->hardware.h_cbit ? "C" : "";
  string v = this->hardware.h_vbit ? "V" : "";
  string i = this->hardware.h_ibit ? "I" : "";
  string f = this->hardware.h_fbit ? "F" : "";
  string t = this->hardware.h_tbit ? "T" : "";
  string m = string(":") + 
    (this->hardware.h_mbits == ARM_MODE_USER ? "USER" :
     this->hardware.h_mbits == ARM_MODE_FIQ ? "FIQ" :
     this->hardware.h_mbits == ARM_MODE_IRQ ? "IRQ" :
     this->hardware.h_mbits == ARM_MODE_SUPERVISOR ? "SUPERVISOR" :
     this->hardware.h_mbits == ARM_MODE_ABORT ? "ABORT" :
     this->hardware.h_mbits == ARM_MODE_UNDEFINED ? "UNDEFINED" :
     this->hardware.h_mbits == ARM_MODE_SYSTEM ? "SYSTEM" : "???");

  return n + z + c + v + i + f + t + m;
}



void
arm7f_cpu::reset ()
{
  // initialize registers to powerup values

  // Initialize cpsr in a couple of steps.
  // First "zero out" everything, then set anything that needs it.
  // Remember that the mode bits can only have valid values.
  // h_mbits must always have a valid value, so set it directly first, before
  // calling h_cpsr_set.
  this->hardware.h_mbits = ARM_MODE_SUPERVISOR;
  this->h_cpsr_set (ARM_MODE_SUPERVISOR << 0);
  // Mask out I and F interrupts.
  this->h_ibit_set (1);
  this->h_fbit_set (1);

  // Make sure we are in arm mode
  this->h_tbit_set (0);	

  // Point the PC at the reset handler.
  this->h_pc_set (0);

  // initialize various implementation state

  this->pending_eit = EIT_NONE;

  // Don't need to power-on-reset anything else, but do so anyway to aid
  // debugging.

  // Note that due to the way we handle the pc, setting h_gr[15] does not
  // set the pc.  Quibble if ya want.
  for (int i = 0; i <= 15; ++i)
    this->h_gr_set (i, 0);
  for (int i = 0; i <= 7; ++i)
    this->h_gr_usr_set (i, 0);
  for (int i = 0; i <= 7; ++i)
    this->h_gr_fiq_set (i, 0);
  for (int i = 0; i <= 1; ++i)
    this->h_gr_svc_set (i, 0);
  for (int i = 0; i <= 1; ++i)
    this->h_gr_abt_set (i, 0);
  for (int i = 0; i <= 1; ++i)
    this->h_gr_irq_set (i, 0);
  for (int i = 0; i <= 1; ++i)
    this->h_gr_und_set (i, 0);
  this->h_spsr_fiq_set (0);
  this->h_spsr_svc_set (0);
  this->h_spsr_abt_set (0);
  this->h_spsr_irq_set (0);
  this->h_spsr_und_set (0);

  // enable update_stepper from now on
  this->initialized_p = true;

  this->triggerpoint_manager.check_and_dispatch ();
}


// 
void
arm7f_cpu::step_insns ()
{
  if (! this->initialized_p)
    {
      cerr << "hw-cpu-arm7f: illegal step before initialization." << endl;
      this->reset();
      return;
    }

  if (this->engine_type == ENGINE_PBB)
    {
      if (this->h_tbit_get ())
	this->step_thumb_pbb ();
      else
	this->step_arm_pbb ();	    
    }
  else
    {
      if (this->h_tbit_get ())
	this->step_thumb ();
      else
	this->step_arm ();	    
    }
}






// EIT support.

// Return h-mbits, as an ARM_MODE enum.

arm::ARM_MODE
arm7f_cpu::mode ()
{
  return (arm::ARM_MODE) this->h_mbits_get ();
}

void
arm7f_cpu::queue_eit (arm7f::eit new_eit)
{
  if (this->pending_eit == new_eit)
    return;

  // don't override higher priority eit
  if (this->pending_eit != EIT_NONE)
    {
      // ARM DDI 0029E, page 3-14
      int current_priority = this->eit_priority (this->pending_eit);
      int new_priority = this->eit_priority (new_eit);
      // higher priorities have lower numbers
      if (new_priority >= current_priority)
	return;
    }

  this->pending_eit = new_eit;

  // TODO: simultaneous data abort and fiq interrupt (page 3-14).
}

int
arm7f_cpu::eit_priority (arm7f::eit e)
{
  switch (e)
    {
    case EIT_RESET :
      return 1;
    case EIT_DATA_ABORT :
      return 2;
    case EIT_FIQ :
      return 3;
    case EIT_IRQ :
      return 4;
    case EIT_PREFETCH_ABORT :
      return 5;
    case EIT_UNDEFINED_INSN :
    case EIT_SWI_INSN :
      return 6;
    default :
      assert (0);
    }
}

// FIXME: revisit making pc an arg

void
arm7f_cpu::process_eit (arm7f::eit new_eit)
{
  // Clean the sucker out
  this->flush_icache ();

  PCADDR pc = this->h_pc_get ();

  // At this point in the processing, pc is the address of the next
  // insn to be executed.

  switch (new_eit)
    {
    case EIT_DATA_ABORT :
      // save cpsr
      this->h_spsr_abt_set(this->h_cpsr_get());
      this->h_tbit_set (0);
      // set R14
      this->h_gr_abt_set (1, pc + 8);
      this->h_mbits_set(ARM_MODE_ABORT);
      this->h_pc_set (0x10);
      this->pending_eit = EIT_NONE;
      break;

    case EIT_FIQ :
      assert (! this->h_fbit_get ());
      assert (this->mode () != ARM_MODE_FIQ);
      // save cpsr before setting h-fbit
      this->h_spsr_fiq_set (this->h_cpsr_get ());
      this->h_fbit_set (1);
      this->h_tbit_set (0);
      // set R14_fiq
      this->h_gr_fiq_set (6, pc + 4);
      this->h_mbits_set (ARM_MODE_FIQ);
      this->h_pc_set (0x1c);
      this->pending_eit = EIT_NONE;
      break;

    case EIT_IRQ :
      assert (! this->h_ibit_get ());
      assert (this->mode () != ARM_MODE_IRQ);
      // save cpsr before setting h-ibit
      this->h_spsr_irq_set (this->h_cpsr_get ());
      this->h_ibit_set (1);
      this->h_tbit_set (0);
      // set R14_irq
      this->h_gr_irq_set (1, pc + 4);
      this->h_mbits_set (ARM_MODE_IRQ);
      this->h_pc_set (0x18);
      this->pending_eit = EIT_NONE;
      break;

    case EIT_PREFETCH_ABORT :
      // save cpsr
      this->h_spsr_abt_set(this->h_cpsr_get());
      this->h_tbit_set (0);
      // set R14
      this->h_gr_abt_set (1, pc + 4);
      this->h_mbits_set(ARM_MODE_ABORT);
      this->h_pc_set (0x0c);
      this->pending_eit = EIT_NONE;
      break;

    case EIT_UNDEFINED_INSN :
      this->h_spsr_und_set (this->h_cpsr_get ());
      // set R14_und
      if (this->h_tbit_get ())
	this->h_gr_und_set (1, pc + 2);
      else
	this->h_gr_und_set (1, pc + 4);
      this->h_tbit_set (0);
      this->h_mbits_set (ARM_MODE_UNDEFINED);
      this->h_pc_set (0x4);
      this->pending_eit = EIT_NONE;
      break;

    case EIT_SWI_INSN :
      this->h_spsr_svc_set (this->h_cpsr_get ());
      // set R14_swi
      if (this->h_tbit_get ())
	this->h_gr_svc_set (1, pc + 2);
      else
	this->h_gr_svc_set (1, pc + 4);
      this->h_tbit_set (0);
      this->h_mbits_set (ARM_MODE_SUPERVISOR);
      this->h_pc_set (0x8);
      this->pending_eit = EIT_NONE;
      break;

    default :
      cgen_rtx_error ("Unknown EIT mode");
      break;
    }
}

// Engine support.

// Override for handling sets of the engine-type attribute.

component::status
arm7f_cpu::set_engine_type (const string& s)
{
  component::status status;
 
  status = cgen_bi_endian_cpu::set_engine_type (s);
  if (status != component::ok)
    return status;
  if (this->engine_type == ENGINE_SCACHE)
    this->set_scache_engine ();
  else if (this->engine_type == ENGINE_PBB)
    this->set_pbb_engine ();
  else
    return component::bad_value;
  return component::ok;
}

void
arm7f_cpu::set_pbb_engine ()
{
  this->engine_type = ENGINE_PBB;
  this->update_engine ();
}

void
arm7f_cpu::set_scache_engine ()
{
  this->engine_type = ENGINE_SCACHE;
  this->update_engine ();
}

void
arm7f_cpu::update_engine ()
{
  if (this->engine_type == ENGINE_PBB)
    {
      this->arm_engine.set_pbb_engine ();
      this->thumb_engine.set_pbb_engine ();
    }
  else
    {
      this->arm_engine.set_scache_engine ();
      this->thumb_engine.set_scache_engine ();
    }
}

// Scache steppers

void
arm7f_cpu::step_arm ()
{
  assert (! this->h_tbit_get ());

  // If an eit is queued, process it now.
  if (this->pending_eit != EIT_NONE)
    this->process_eit (this->pending_eit);

  while (true)
    {
      // Fetch/decode the instruction  ------------------------------
      PCADDR pc = this->h_pc_get ();
      bool found;
      arm_scache* sem = this->arm_engine.find (pc, found);
      if (! found)
	{
	  try
	    {
	      USI insn = this->GETIMEMSI (pc, pc);
	      sem->decode (this, pc, insn, insn);
	    }
	  catch (cpu_memory_fault& t)
	    {
	      this->memory_trap (t);
	      break;
	    }
	}

      // Execute the instruction  -----------------------------------
      if (this->trace_result_p)
	this->begin_trace (pc, sem->idesc->insn_name);
      try 
	{
	  if (this->eval_cond (sem->cond, pc))
	    {
	      // Set R15 in case the insn uses it.
	      this->h_gr_set (H_GR_PC, pc + sem->idesc->attrs.get_r15_offset_attr ());
	      sem->idesc->execute (this, sem);
	    }
	  else
	    {
	      this->h_pc_set (pc + 4);
	    }
	}
      catch (cpu_memory_fault& t)
	{
	  this->memory_trap (t);
	  this->yield ();
	}
      catch (cpu_exception& t)
	{
	  this->yield ();
	}
      if (this->trace_result_p)
	this->end_trace ();
      

      // Do post-instruction processing  ----------------------------
      if (this->enable_step_trap_p) 
	this->signal_trap (sidutil::cpu_trap_stepped);
      this->triggerpoint_manager.check_and_dispatch ();
      
      // test for exit condition
      if (stop_after_insns_p (1))
	break;
    }
}


void
arm7f_cpu::step_thumb ()
{
  assert (this->h_tbit_get ());

  // If an eit is queued, process it now.
  if (this->pending_eit != EIT_NONE)
    this->process_eit (this->pending_eit);

  while (true)
    {
      // Fetch/decode the instruction  ------------------------------
      PCADDR pc = this->h_pc_get ();
      bool found;
      thumb_scache* sem = this->thumb_engine.find (pc, found);
      if (! found)
	{
	  try
	    {
	      UHI insn = this->GETIMEMHI (pc, pc);
	      sem->decode (this, pc, insn, insn);
	    }
	  catch (cpu_memory_fault& t)
	    {
	      this->memory_trap (t);
	      break;
	    }
	}

      // Execute the instruction  -----------------------------------
      if (this->trace_result_p)
	this->begin_trace (pc, sem->idesc->insn_name);
      try 
	{
	  // Set R15 in case the insn uses it.
	  this->h_gr_set (H_GR_PC, pc + 4);
	  sem->idesc->execute (this, sem);
	}
      catch (cpu_memory_fault& t)
	{
	  this->memory_trap (t);
	  this->yield ();
	}
      catch (cpu_exception& t)
	{
	  this->yield ();
	}
      if (this->trace_result_p)
	this->end_trace ();
      

      // Do post-instruction processing  ----------------------------
      if (this->enable_step_trap_p) 
	this->signal_trap (sidutil::cpu_trap_stepped);
      this->triggerpoint_manager.check_and_dispatch ();
      
      // test for exit condition
      if (stop_after_insns_p (1))
	break;
    }
}



// PBB steppers and support

void
arm7f_cpu::step_arm_pbb ()
{
  assert (! this->h_tbit_get ());

  // With single-stepping or active triggerpoints, use scache only
  if (this->triggerpoint_manager.checking_any_p ()
      || this->enable_step_trap_p)
    return this->step_arm ();

  // If an eit is queued, process it now.
  if (this->pending_eit != EIT_NONE)
    this->process_eit (this->pending_eit);

  try
    {
      // This function takes care of step_insn_count.
      // There are no triggerpoints or single-stepping to worry about.
      this->arm_pbb_run ();
    }
  catch (cpu_memory_fault& t)
    {
      this->memory_trap (t);
    }
  catch (cpu_exception& t)
    {
    }
}


void
arm7f_cpu::step_thumb_pbb ()
{
  assert (this->h_tbit_get ());
 
  // With single-stepping or active triggerpoints, use scache only
  if (this->triggerpoint_manager.checking_any_p ()
      || this->enable_step_trap_p)
    return this->step_thumb ();

  // If an eit is queued, process it now.
  if (this->pending_eit != EIT_NONE)
    this->process_eit (this->pending_eit);

  try
    {
      // This function takes care of step_insn_count.
      // There are no triggerpoints or single-stepping to worry about.
      this->thumb_pbb_run ();
    }
  catch (cpu_memory_fault& t)
    {
      this->memory_trap (t);
    }
  catch (cpu_exception& t)
    {
    }
}



// Compiler for the ARM PBB engine.

arm_scache*
arm7f_cpu::arm_pbb_begin (PCADDR pc)
{
  bool found;
  arm_scache* vpc;
  arm_engine_t* engine = & this->arm_engine;
  bool trace_p = this->trace_result_p;

  unsigned block_size = engine->max_real_insns (this);

  // Multiply by enough so we have enough space for the virtual insns.
  unsigned alloc_blocks;
  if (trace_p)
    {
      // *4 = before,cond,insn,after insns.  +1 = chain insn.
      alloc_blocks = block_size * 4 + 1;
    }
  else
    {
      // *2 = cond,insn insns.  +1 = chain insn.
      alloc_blocks = block_size * 2 + 1;
    }

  vpc = engine->pbb_find_or_alloc (pc, alloc_blocks, found);
  if (found)
    return vpc;

  // Ok, here's where the real fun begins.  Compile a pseudo-basic-block.

  arm_scache* sc = vpc;

  arm_scache* sc_end;
  if (trace_p)
    sc_end = vpc + (alloc_blocks
		    // back up to ensure there's room for all of the last insn
		    - 3
		    // and room for the final chain insn
		    - 1);
  else
    sc_end = vpc + (alloc_blocks
		    // back up to ensure there's room for all of the last insn
		    - 1
		    // and room for the final chain insn
		    - 1);

  unsigned count = 0;
  do
    {
      USI insn;
      try
	{
	  insn = this->GETIMEMSI (pc, pc);
	}
      catch (cpu_memory_fault& t)
	{
	  this->memory_trap (t);
	  break;
	}

      // FIXME: magic number
      UINT cond = insn >> 28;

      if (trace_p)
	{
	  engine->compile_before_insn (this, sc, pc,
				       // FIXME: magic number
				       sc + (cond == 14 ? 1 : 2));
	  ++sc;
	}

      // First insert a conditional execution handler if needed.
      // FIXME: magic number
      if (cond != 14)
	{
	  engine->compile_cond_insn (this, sc, pc, cond);
	  ++sc;
	}

      // Compile the insn.
      sc->decode (this, pc, insn, insn);
      sc->execute.cgoto = sc->idesc->cgoto;

      // Compute whether we need to end the block at this insn now, while we
      // have sc pointing to the insn's cache entry.
      // ??? One call that tests both?
      bool cti_p = (sc->idesc->attrs.get_uncond_cti_attr ()
		    || sc->idesc->attrs.get_cond_cti_attr ());

      ++sc;

      if (trace_p)
	{
	  engine->compile_after_insn (this, sc, pc, sc - 1);
	  ++sc;
	}

      pc += 4;
      ++count;

      if (cti_p)
	{
	  engine->compile_cti_chain_insn (this, sc, pc, count);
	  return vpc;
	}
    }
  while (sc < sc_end);

  // Compile a chain insn to link to next block.
  engine->compile_chain_insn (this, sc, pc, count);

  return vpc;
}

// Compiler for the Thumb PBB engine.

thumb_scache*
arm7f_cpu::thumb_pbb_begin (PCADDR pc)
{
  bool found;
  thumb_scache* vpc;
  thumb_engine_t* engine = & this->thumb_engine;
  bool trace_p = this->trace_result_p;

  unsigned block_size = engine->max_real_insns (this);

  // Multiply by enough so we have enough space for the virtual insns.
  unsigned alloc_blocks;
  if (trace_p)
    {
      // *3 = before,insn,after insns.  +1 = chain insn.
      alloc_blocks = block_size * 3 + 1;
    }
  else
    {
      // +1 = chain insn.
      alloc_blocks = block_size + 1;
    }

  vpc = engine->pbb_find_or_alloc (pc, alloc_blocks, found);
  if (found)
    return vpc;

  // Ok, here's where the real fun begins.  Compile a pseudo-basic-block.

  thumb_scache* sc = vpc;

  thumb_scache* sc_end;
  if (trace_p)
    sc_end = vpc + (alloc_blocks
		    // back up to ensure there's room for all of the last insn
		    - 2
		    // and room for the final chain insn
		    - 1);
  else
    sc_end = vpc + (alloc_blocks
		    // back up to ensure there's room for the chain insn
		    - 1);

  unsigned count = 0;
  do
    {
      UHI insn;
      try
	{
	  insn = this->GETIMEMHI (pc, pc);
	}
      catch (cpu_memory_fault& t)
	{
	  this->memory_trap (t);
	  break;
	}

      if (trace_p)
	{
	  engine->compile_before_insn  (this, sc, pc, sc + 1);
	  ++sc;
	}

      // Compile the insn.
      sc->decode (this, pc, insn, insn);
      sc->execute.cgoto = sc->idesc->cgoto;

      // Compute whether we need to end the block at this insn now, while we
      // have sc pointing to the insn's cache entry.
      // ??? One call that tests both?
      bool cti_p = (sc->idesc->attrs.get_uncond_cti_attr ()
		    || sc->idesc->attrs.get_cond_cti_attr ());

      ++sc;

      if (trace_p)
	{
	  engine->compile_after_insn (this, sc, pc, sc - 1);
	  ++sc;
	}

      pc += 2;
      ++count;

      if (cti_p)
	{
	  engine->compile_cti_chain_insn (this, sc, pc, count);
	  return vpc;
	}
    }
  while (sc < sc_end);

  // Compile a chain insn to link to next block.
  engine->compile_chain_insn (this, sc, pc, count);

  return vpc;
}

// Memory trap(/fault) handling.

void
arm7f_cpu::memory_trap (const cpu_memory_fault& t)
{
  this->h_gr_set (H_GR_PC, t.pc);
  this->h_pc_set (t.pc);

  if (t.status == bus::delayed)
    return;

  if (this->debug_exec_p)
    cerr << "MEMORY TRAP "
	 << " operation=" << t.operation
	 << " pc=0x" << hex << t.pc << dec
	 << " address=0x" << hex << t.address << dec
	 << " status=" << (int) t.status 
	 << endl;
  
  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_memory_fault, t.address);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      if (string (t.operation) == "insn read")
	this->queue_eit (EIT_PREFETCH_ABORT);
      else
	this->queue_eit (EIT_DATA_ABORT);
      break;

    case cpu_trap_skip:
      {
	PCADDR pc = t.pc + (this->h_tbit_get() ? 2 : 4); // skip this insn
	this->h_gr_set (H_GR_PC, pc);
	this->h_pc_set (pc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
}

// Invalid instruction handling.

// Give a component listening on our trap-type pin an opportunity to
// deal with it.  If that fails, treat the fault like hardware would.
// PC is the address of the invalid insn.

void
arm7f_cpu::invalid_insn (PCADDR pc)
{
  this->h_gr_set (H_GR_PC, pc);
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_invalid_insn, pc);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      this->h_gr_set (H_GR_PC, pc);
      this->h_pc_set (pc);
      this->queue_eit (EIT_UNDEFINED_INSN);
      break;

    case cpu_trap_skip:
      {
	PCADDR npc = pc + (this->h_tbit_get() ? 2 : 4); // skip this insn
	this->h_gr_set (H_GR_PC, npc);
	this->h_pc_set (npc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
}

#if 0

// Special "nreset" pin handling.
void
arm7f_cpu::do_nreset_pin (host_int_4 value)
{
  // FIXME: Should be able to catch transitions but can't do
  // that with callback_pin.
  //if (nreset_pin.sense () == value)
  //  return;

  if (value)
    {
      // Reset pin has gone high, start executing insns.

      // Initialize cpsr in a couple of steps.
      // First "zero out" everything, then set anything that needs it.
      // Remember that the mode bits can only have valid values.
      // h_mbits must always have a valid value, so set it directly first,
      // before calling h_cpsr_set.
      this->hardware.h_mbits = ARM_MODE_SUPERVISOR;
      this->h_cpsr_set (ARM_MODE_SUPERVISOR << 0);
      this->h_ibit_set (1);
      this->h_fbit_set (1);

      this->h_pc_set (0);

      this->pending_eit = EIT_NONE;
    }
  else
    {
      // Reset pin has gone low, put cpu in reset state.
      this->step_pin.set_callback (& arm7f_cpu::step_reset);

      // lock out other interrupts (EIT_RESET has highest priority)
      this->pending_eit = EIT_RESET;
    }
}
#endif

#if 0
// Stepper while reset pin is held low.
// XXX: not implemented
void
arm7f_cpu::step_reset (host_int_4)
{
  assert (! this->nreset_pin.sense ());

  // See ARM DDI 0029E, page 3-15.
  // ??? It doesn't say what happens if a reset happens while in thumb mode
  // [do half-word insns get fetched?], but presumably it doesn't matter.  :-)
  PCADDR pc = this->h_pc_get () & 0xfffffffc;
  //SI insn = this->GETIMEMSI(pc, pc); // FIXME: what if there's a SIGSEGV?
  this->h_pc_set (pc + 4);

  this->triggerpoint_manager.check_and_dispatch ();
}
#endif


// EIT (exception, interrupt, and trap) pins.

void
arm7f_cpu::do_nfiq_pin (host_int_4 value)
{
  // FIXME: Should be able to catch high-low transition but can't do
  // that with callback_pin.
  //if (nfiq_pin.sense () == value)
  //  return;
  if (value)
    return;

  // nFIQ has been driven low.

  // Are FIQ interrupts disabled?
  if (this->h_fbit_get ())
    return;

  // Queue the interrupt.
  this->queue_eit (EIT_FIQ);
}

void
arm7f_cpu::do_nirq_pin (host_int_4 value)
{
  // FIXME: Should be able to catch high-low transition but can't do
  // that with callback_pin.
  //if (nirq_pin.sense () == value)
  //  return;
  if (value)
    return;

  // nIRQ has been driven low.

  // Are IRQ interrupts disabled?
  if (this->h_ibit_get ())
    return;

  // Queue the interrupt.
  this->queue_eit (EIT_IRQ);
}


// Miscellaneous pins.

void
arm7f_cpu::flush_icache ()
{
  this->thumb_engine.flush ();
  this->arm_engine.flush ();
}

// Additional support for setting particular hardware regs.
// Update tbit_pin based on given new value for the T bit.
// Yield from instruction engine loop to make isa switch effective.
void
arm7f_cpu::arm_tbit_set (BI newval)
{
  // Tell existing engine to yield control if we're switching engines.
  // ??? Should only do this if running, though it's harmless if not.
  BI oldval = this->h_tbit_get ();
  if (oldval == newval)
    return;

  this->hardware.h_tbit = newval;

  if (this->debug_exec_p)
    {
      if (newval)
	this->trace_stream << " <switching to thumb mode> ";
      else
	this->trace_stream << " <switching to arm mode> ";
    }

  // Update the tbit pin.
  this->tbit_pin.drive (newval);

  this->yield ();
  // This should arrange an immediate exit from the scache/pbb engine loops.
}


// Update the h-gr regs based on the new value for M4-M0.
// Also update nm_pin.
void
arm7f_cpu::arm_mbits_set (UINT newval)
{
  UINT oldval = this->h_mbits_get ();

  // exit quickly for frequent case
  // N.B. code below assumes this is done
  if (newval == oldval)
    return;

  // swap out the current set of r8-r12
  switch (oldval)
    {
    case ARM_MODE_USER :
    case ARM_MODE_SYSTEM :
    case ARM_MODE_SUPERVISOR :
    case ARM_MODE_ABORT :
    case ARM_MODE_IRQ :
    case ARM_MODE_UNDEFINED :
    case ARM_MODE_FIQ :
      break;

    default:
      cerr << "hw-cpu-arm7t: ignoring invalid h-mbits:" << newval << endl;
      return;
    }

  // swap out the current set of r8-r12
  switch (oldval)
    {
    case ARM_MODE_USER :
    case ARM_MODE_SYSTEM :
    case ARM_MODE_SUPERVISOR :
    case ARM_MODE_ABORT :
    case ARM_MODE_IRQ :
    case ARM_MODE_UNDEFINED :
      // nothing to do unless new mode is fiq
      if (newval != ARM_MODE_FIQ)
	break;
      for (int i = 8; i <= 12; ++i)
	this->h_gr_usr_set (i - 8, this->h_gr_get (i));
      break;
    case ARM_MODE_FIQ :
      for (int i = 8; i <= 12; ++i)
	this->h_gr_fiq_set (i - 8, this->h_gr_get (i));
      break;
    default :
      assert (0);
    }

  // swap in the new set of r8-r12
  switch (newval)
    {
    case ARM_MODE_USER :
    case ARM_MODE_SYSTEM :
    case ARM_MODE_SUPERVISOR :
    case ARM_MODE_ABORT :
    case ARM_MODE_IRQ :
    case ARM_MODE_UNDEFINED :
      // nothing to do unless old mode was fiq
      if (oldval != ARM_MODE_FIQ)
	break;
      for (int i = 8; i <= 12; ++i)
	this->h_gr_set (i, this->h_gr_usr_get (i - 8));
      break;
    case ARM_MODE_FIQ :
      for (int i = 8; i <= 12; ++i)
	this->h_gr_set (i, this->h_gr_fiq_get (i - 8));
      break;
    }

  // swap out the current set of r13,r14
  switch (oldval)
    {
    case ARM_MODE_USER :
    case ARM_MODE_SYSTEM :
      // nothing to do if new mode is the other of the two
      if (newval == ARM_MODE_USER || newval == ARM_MODE_SYSTEM)
	break;
      for (int i = 13; i <= 14; ++i)
	this->h_gr_usr_set (i - 8, this->h_gr_get (i));
      break;
    case ARM_MODE_SUPERVISOR :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_svc_set (i - 13, this->h_gr_get (i));
      break;
    case ARM_MODE_ABORT :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_abt_set (i - 13, this->h_gr_get (i));
      break;
    case ARM_MODE_IRQ :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_irq_set (i - 13, this->h_gr_get (i));
      break;
    case ARM_MODE_UNDEFINED :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_und_set (i - 13, this->h_gr_get (i));
      break;
    case ARM_MODE_FIQ :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_fiq_set (i - 8, this->h_gr_get (i));
      break;
    default :
      assert (0);
    }

  // swap in the new set of r13,r14
  switch (newval)
    {
    case ARM_MODE_USER :
    case ARM_MODE_SYSTEM :
      // nothing to do if old mode was the other of the two
      if (oldval == ARM_MODE_USER || oldval == ARM_MODE_SYSTEM)
	break;
      for (int i = 13; i <= 14; ++i)
	this->h_gr_set (i, this->h_gr_usr_get (i - 8));
      break;
    case ARM_MODE_SUPERVISOR :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_set (i, this->h_gr_svc_get (i - 13));
      break;
    case ARM_MODE_ABORT :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_set (i, this->h_gr_abt_get (i - 13));
      break;
    case ARM_MODE_IRQ :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_set (i, this->h_gr_irq_get (i - 13));
      break;
    case ARM_MODE_UNDEFINED :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_set (i, this->h_gr_und_get (i - 13));
      break;
    case ARM_MODE_FIQ :
      for (int i = 13; i <= 14; ++i)
	this->h_gr_set (i, this->h_gr_fiq_get (i - 8));
      break;
    }

  // Finally update register
  this->hardware.h_mbits = newval;
  // Update the nm pin.
  this->nm_pin.drive ((~newval) & 0x1f);
}

// Software generated interrupt support.

SI
arm7f_cpu::arm_swi (PCADDR pc, UINT arg)
{
  // Update recorded pc in case software trap handling component wants to
  // use it.  This is also needed if the insn is handled as hardware would.
  this->h_gr_set (H_GR_PC, pc);
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_software, arg);

  switch (whatnext)
    {
    case cpu_trap_unhandled:
      this->queue_eit (EIT_SWI_INSN);
      break;

    case cpu_trap_skip:
      {
	PCADDR npc = pc + (this->h_tbit_get() ? 2 : 4); // skip this insn
	this->h_gr_set (H_GR_PC, npc);
	this->h_pc_set (npc);
      }
      break;

    case cpu_trap_handled:
    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
}


SI
arm7f_cpu::thumb_swi (PCADDR pc, UINT arg)
{
  return this->arm_swi (pc, arg);
}

// State dump/restore support.

void 
arm7f_cpu::stream_state (ostream& o) const
{
  // call base class first
  cgen_bi_endian_cpu::stream_state (o);

  // component and cpu variant indicators
  o << " arm-cpu"
    << " arm7tdmi";

  // misc. state
  o << " " << initialized_p
    << " " << static_cast<int>(pending_eit);

  // pins
  o << " " << nm_pin
    << " " << tbit_pin
    << " " << nfiq_pin
    << " " << nirq_pin << endl;

  // XXX: Cheat by dumping the entire hardware struct in binary form.  That
  // means that this state image will not be restorable on a different
  // endianness host platform.
  string hw = string(reinterpret_cast<const char*>(& this->hardware), sizeof(this->hardware));
  o << " " << string2stream(hw);
}

void 
arm7f_cpu::destream_state (istream& i)
{
  // call base class first
  cgen_bi_endian_cpu::destream_state (i);

  string key;
  i >> key;
  if (key != "arm-cpu")
    {
      i.setstate (ios::badbit);
      return;
    }

  string cpu_variant;
  i >> cpu_variant;
  if (cpu_variant != "arm7tdmi")
    {
      i.setstate (ios::badbit);
      return;
    }

  // misc. state
  int pending_eit_asint;
  i >> initialized_p
    >> pending_eit_asint;
  pending_eit = static_cast<arm7f::eit>(pending_eit_asint);

  // pins
  i >> nm_pin
    >> tbit_pin
    >> nfiq_pin
    >> nirq_pin;

  string hw;
  i >> stream2string(hw);
  if (hw.size() != sizeof(this->hardware))
    i.setstate (ios::badbit);
  else
    {
      const char* hwbin = hw.data();
      ::memcpy (reinterpret_cast<char*>(& this->hardware), hwbin, sizeof(this->hardware));
    }

  // reinitialize derived state
  flush_icache ();
}



// Debugger interface functions: return bitwise register images in
// "target byte order".

string
arm7f_cpu::dbg_get_reg (host_int_4 reg)
{
  string attr;

  if (reg < 16) // general purpose registers
    {
      host_int_4 value;

      if (reg == H_GR_PC)
	value = h_pc_get ();
      else
	value = h_gr_get (reg);

      // change to "target endian"
      if (current_endianness() == endian_big)
	{
	  big_int_4 v = value;
	  for (unsigned i=0; i<4; i++)
	    attr += v.read_byte (i);
	}
      else
	{
	  little_int_4 v = value;
	  for (unsigned i=0; i<4; i++)
	    attr += v.read_byte (i);
	}
      assert (attr.length () == 4);
    }
  else if ((reg >= 16) && (reg <= 23)) // floating point registers
    {
      for (unsigned i = 0; i < 12; i++)
	attr += '\0';
      assert (attr.length () == 12);
    }
  else if (reg == 24) // floating point status ?
    {
      for (unsigned i = 0; i < 4; i++)
	attr += '\0';
      assert (attr.length () == 4);
    }
  else if (reg == 25) // cpsr
    {
      host_int_4 value = h_cpsr_get ();

      // change to "target endian"
      if (current_endianness() == endian_big)
	{
	  big_int_4 v = value;
	  for (unsigned i=0; i<4; i++)
	    attr += v.read_byte (i);
	}
      else
	{
	  little_int_4 v = value;
	  for (unsigned i=0; i<4; i++)
	    attr += v.read_byte (i);
	}
      assert (attr.length () == 4);
    }

  return attr;
}


component::status 
arm7f_cpu::dbg_set_reg (host_int_4 reg, const string& attr)
{
  if (reg < 16) // general purpose registers
    {
      if (attr.length () != 4)
	return component::bad_value;

      host_int_4 value;
      // change from "target endian"
      if (current_endianness() == endian_big)
	{
	  big_int_4 v;
	  for (unsigned i=0; i<4; i++)
	    v.write_byte (i, attr[i]);
	  value = v;
	}
      else
	{
	  little_int_4 v;
	  for (unsigned i=0; i<4; i++)
	    v.write_byte (i, attr[i]);
	  value = v;
	}

      if (reg == H_GR_PC)
	h_pc_set (value);
      else
	h_gr_set (reg, value);

      return component::ok;
    }
  else if ((reg >= 16) && (reg <= 23)) // floating point registers
    {
      if (attr.length () != 12)
	return component::bad_value;

      return component::ok;
    }
  else if (reg == 24) // floating point status ?
    {
      if (attr.length () != 4)
	return component::bad_value;

      return component::ok;
    }
  else if (reg == 25) // cpsr
    {
      if (attr.length () != 4)
	return component::bad_value;

      host_int_4 value;
      // change from "target endian"
      if (current_endianness() == endian_big)
	{
	  big_int_4 v;
	  for (unsigned i=0; i<4; i++)
	    v.write_byte (i, attr[i]);
	  value = v;
	}
      else
	{
	  little_int_4 v;
	  for (unsigned i=0; i<4; i++)
	    v.write_byte (i, attr[i]);
	  value = v;
	}

      h_cpsr_set (value);

      return component::ok;
    }

  return component::not_found;
}



// ----------------------------------------------------------------------------
// More semantic helper routines -- too large to inline throughout

  // Support for operand2 in the data processing insns.
  // ??? Move to RTL.

  // Shift RM according to TYPE,SHIFT.
  // XXX: Semantic subroutines in cgen would be useful here.  If the
  // subroutines are inlined the only benefit would be readability of the
  // generated code.  Still, that's not irrelevant.

  // FIXME: making this inline is a quick hack to work around a compilation
  // problem (symbol undefined).

SI 
arm7f_cpu::compute_operand2_immshift (SI rm, int type, int shift)
{
  switch (type)
    {
    case SHIFT_TYPE_LSL : return rm << shift;
    case SHIFT_TYPE_LSR : return (USI) rm >> shift;
    case SHIFT_TYPE_ASR : return rm >> shift;
    case SHIFT_TYPE_ROR : return RORSI (rm, shift);
    }
  abort();
}


SI
arm7f_cpu::compute_operand2_regshift (SI rm, int type, SI shift)
{
  shift &= 255;
      
  switch (type)
    {
    case SHIFT_TYPE_LSL :
      if (shift >= 32)
	return 0;
      return rm << shift;
    case SHIFT_TYPE_LSR :
      if (shift >= 32)
	return 0;
      return (USI) rm >> shift;
    case SHIFT_TYPE_ASR :
      if (shift >= 32)
	return rm >> 31;
      return rm >> shift;
    case SHIFT_TYPE_ROR :
      if (shift > 32)
	shift = ((shift - 1) & 31) + 1;
      if (shift == 0 || shift == 32)
	return rm;
      return RORSI (rm, shift);
    }
  abort ();
}


BI
arm7f_cpu::compute_carry_out_immshift (SI rm, int type, int shift, BI cbit)
{
  switch (type)
    {
    case SHIFT_TYPE_LSL :
      if (shift == 0)
	return cbit;
      return (rm >> (32 - shift)) & 1;
    case SHIFT_TYPE_LSR :
      if (shift == 0)
	return rm < 0;
      return (rm >> (shift - 1)) & 1;
    case SHIFT_TYPE_ASR :
      if (shift == 0)
	return rm < 0;
      return (rm >> (shift - 1)) & 1;
    case SHIFT_TYPE_ROR :
      if (shift > 32)
	shift = ((shift - 1) & 31) + 1;
      if (shift == 0)
	return rm & 1;
      return (rm >> (shift - 1)) & 1;
    }
  abort ();
}


BI arm7f_cpu::compute_carry_out_regshift (SI rm, int type, SI shift, BI cbit)
{
  shift &= 255;
      
  switch (type)
    {
    case SHIFT_TYPE_LSL :
      if (shift == 0)
	return cbit;
      if (shift == 32)
	return rm & 1;
      if (shift > 32)
	return 0;
      return (rm >> (32 - shift)) & 1;
    case SHIFT_TYPE_LSR :
      if (shift == 0)
	return cbit;
      if (shift == 32)
	return rm < 0;
      if (shift > 32)
	return 0;
      return (rm >> (shift - 1)) & 1;
    case SHIFT_TYPE_ASR :
      if (shift == 0)
	return cbit;
      if (shift >= 32)
	return rm < 0;
      return (rm >> (shift - 1)) & 1;
    case SHIFT_TYPE_ROR :
      if (shift == 0)
	return cbit;
      if (shift == 32)
	return rm < 0;
      return (rm >> (shift - 1)) & 1;
    }
  abort ();
}
