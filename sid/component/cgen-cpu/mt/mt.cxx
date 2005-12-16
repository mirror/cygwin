// mt.cxx - Implementations of hand-written functions for the MT
// simulator. -*- C++ -*-

// Copyright (C) 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// Normally, cpu ports are divided into a common part (e.g. arm-cmn.{h,cxx})
// and one or more cpu-family specific parts.  MSi1 is a fairly simple
// port so we don't currently do this.

#include "mt.h"

using namespace std;
using namespace sid;
using namespace sidutil;
using namespace mt;

mt_cpu::mt_cpu ()
  :tick(0),
   engine (32768) // XXX: tune size  
{
  for (unsigned i = 0; i < 16; ++i)
    {
      string name = string ("R") + make_numeric_attribute (i);
      SI* value = & this->hardware.h_spr[i];
      this->add_watchable_register (name, value);
    }

  USI* value = & this->hardware.h_pc;
  this->add_watchable_register (string("pc"), value);
  this->interrupts_enabled = false;
  this->io_bus = NULL;
  // add accessor for I/O bus
  add_accessor("io-memory", & this->io_bus);

  // add syscall registers
  this->add_watchable_register (string("syscall-arg0"), &syscall_arg0);
  this->add_watchable_register (string("syscall-arg1"), &syscall_arg1);
  this->add_watchable_register (string("syscall-arg2"), &syscall_arg2);
  this->add_watchable_register (string("syscall-arg3"), &syscall_arg3);
  this->add_watchable_register (string("syscall-result"), &syscall_result);
  this->add_watchable_register (string("syscall-error"), &syscall_error);
  this->add_attribute (string("syscall-trap"), &syscall_trap_num,"setting");
  this->syscall_trap_num = 0;
  // For gdb.
  this->create_gdb_register_attrs (47, "12;13;14;16", & this->hardware.h_pc);

}

void
mt_cpu::reset()
{
  this->write_stacks.reset();
  this->hardware.h_pc = 0;
  this->interrupts_enabled = false;
  for (unsigned i = 0; i < 16; i++)
    this->hardware.h_spr[i] = 0;
}

void
mt_cpu::flush_icache ()
{
  this->engine.flush ();
}


void
mt_cpu::invalid_insn (PCADDR pc)
{
  cout << hex << "XXX: invalid insn @ " << pc << dec << endl;
  // abort();
}


// Memory trap(/fault) handling.
void
mt_cpu::memory_trap (const cpu_memory_fault& t)
{
  this->h_pc_set (t.pc);
  
  abort();
}


void
mt_cpu::do_syscall (PCADDR pc)
{

  // Get the syscall arguments
  syscall_arg0 = h_spr_get(1); // This specifies which syscall
  syscall_arg1 = h_spr_get(2); // First arg
  syscall_arg2 = h_spr_get(3); // Second arg
  syscall_arg3 = h_spr_get(4); // Third arg


  //this->h_pc_set (this->h_pc_get());
  this->h_pc_set (pc);

  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_software, syscall_trap_num);


  switch (whatnext)
    {
    case cpu_trap_unhandled:
      // cerr << "hw-cpu-mt: invalid insn handler unimplemented!" << endl;
      // When no gloss component is configured, we have to do the normal SI.
      h_pc_set(8);
      return;

    case cpu_trap_reissue:
      break;

    case cpu_trap_skip:
      //this->h_pc_set (this->h_pc_get() + 4);
      this->h_pc_set (pc + 4);
      /* fall-through */

    case cpu_trap_handled:
      {
        // must get syscall results and place them in current context registers
        string errAttr = this->attribute_value ("syscall-error");
        string resultAttr = this->attribute_value ("syscall-result");

        host_int_4 errValue;
        host_int_4 resultValue;
        parse_attribute(errAttr, errValue);
        parse_attribute(resultAttr, resultValue);


        h_spr_set (5, errValue);
        h_spr_set (11, resultValue);
      }
      return;
    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
}

void
mt_cpu::do_break (PCADDR pc)
{
  cpu_trap_disposition whatnext = this->signal_trap (cpu_trap_breakpoint, 0);
  switch (whatnext)
    {
    case cpu_trap_unhandled:
      // cerr << "hw-cpu-mt: breakpoint handler unimplemented!" << endl;
      // No gdb component?  Do the proper break processing.
      // Put pc+4 into R15
      h_spr_set (15, pc +4);
      // Disable interrupts
      this->disable_interrupts();
      // Branch to 0x00000010
      this->h_pc_set (0x10);
      return;
      //break;

    case cpu_trap_skip:
      break;

    case cpu_trap_handled:
      // Gdb processed the trap. 
      break;

    case cpu_trap_reissue:
      break;

    default:
      abort ();
    }

  this->yield();
  throw cpu_exception ();
}

USI
mt_cpu::io_read (host_int_4 pc, host_int_4 address) 
{
  big_int_4 value;
  sid::bus::status s =
    (LIKELY(this->io_bus)) ? this->io_bus->read (address, value) : sid::bus::unmapped;
  if (LIKELY(s == sid::bus::ok))
    return (USI)value;
   
  // A bus tracer has been connected to the io bus accessor in the sid
  // configuration file to verify that reads from and write to the io bus
  // are actaully being requested when io instructions are processed.
  // I/O devices and their associated memory are not part of the ISS so
  // so there is nothing to connect the bus tracer to which will cause
  // an "unmapped" error to occur.  If this were to occur when the io 
  // devices are part of the simulation, the proper thing to do would
  // be to issue a memory fault.  If the ISS is ever expanded to include
  // io devices, uncomment the next line and comment out everything after
  // the remainder of this method.
  //throw cpu_memory_fault (pc, address, s, "IO read");

  // Pretend everything is ok and 0 was read.  (i.e. pretend s == sid::bus::ok)
  return (USI) 0;
} 

void
mt_cpu::io_write (host_int_4 pc, host_int_4 address, big_int_4 value)
{ 
  sid::bus::status s =  
    (LIKELY(this->io_bus)) ? this->io_bus->write (address, value) : sid::bus::unmapped;
  if (LIKELY(s == sid::bus::ok))
    return;

  // A bus tracer has been connected to the io bus accessor in the sid
  // configuration file to verify that reads from and write to the io bus
  // are actaully being requested when io instructions are processed.
  // I/O devices and their associated memory are not part of the ISS so
  // so there is nothing to connect the bus tracer to which will cause
  // an "unmapped" error to occur.  If this were to occur when the io 
  // devices are part of the simulation, the proper thing to do would
  // be to issue a memory fault.  If the ISS is ever expanded to include
  // io devices, uncomment the next line and comment out everything after
  // the remainder of this method.

  // throw cpu_memory_fault (pc, address, s, "IO write");
  
  // Pretend everything is ok.  (i.e. pretend s == sid::bus::ok)
  return;
}

    

// Stepper

void
mt_cpu::step_insns ()
{
  bool found;
  bool increment;
  const char *printable_name;
  this->interrupts_enabled = false;
  while (true)
    {
      increment = true;
      PCADDR pc = this->h_pc_get ();
      bool found;
      mt_scache* sem = engine.find (pc, found);
      if (!found)
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

      // printable_name must agree with bfd/cpu-mt.c.
      if (this->get_eflags () == 2)
	printable_name = "ms1-003";
      else
	printable_name = "ms1";

      // Execute the instruction  -----------------------------------
      if (trace_semantics_p)
	this->begin_trace (pc, sem->idesc->insn_name);

      if (trace_disass_p)
	this->disassemble (pc, print_insn_mt,
			   bfd_target_elf_flavour,
			   bfd_arch_mt,
			   (current_endianness() == endian_little ? 
			    BFD_ENDIAN_LITTLE : BFD_ENDIAN_BIG), 
			   printable_name,
			   0, this->get_eflags ());
      try
	{
	  // R0 is always zero.
	  this->h_spr_set (0, 0);
	  sem->idesc->execute (this, sem, tick, write_stacks);
	  this->h_spr_set (0, 0);
	}
      catch (cpu_memory_fault& t)
	{
	  this->memory_trap (t);
	  this->yield ();
	}
      catch (cpu_exception& t)
	{
	  this->yield ();
          increment = false;
	}
      if (trace_semantics_p)
	this->end_trace ();

      // Advance PC by one word, by default
      if (increment)
         this->h_pc_set (pc + 4);
      // Execute writeback 
      try {
	write_stacks.writeback (tick, this);
	// Overwrite R0 yet again, just in case a delayed load to R0 was performed
	this->h_spr_set (0, 0);
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


      // move ahead thru circular pipeline
      tick = (tick + 1) % mt::pipe_sz;

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
mt_cpu::stream_state (ostream& o) const
{
  o << " mt-cpu-cgen ";
  stream_cgen_hardware (o);
  o << ' ' << tick << ' ';
  stream_cgen_write_stacks (o, write_stacks);
}

void
mt_cpu::destream_state (istream& i)
{
  string key;
  i >> key;
  if (key != "mt-cpu-cgen")
    {
      i.setstate (ios::badbit);
      return;
    }

  destream_cgen_hardware (i);
  i >> tick;
  destream_cgen_write_stacks (i, write_stacks);
}
