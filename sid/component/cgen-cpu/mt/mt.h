// mt.h - Hand-written code for the MT CPU. -*- C++ -*-

// Copyright (C) 2004 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "cgen-cpu.h"
#include "mt-desc.h"
#define WRITE_BUF_SZ 2
#include "mt-defs.h"
#include "mt-decode.h"
#undef WRITE_BUF_SZ

namespace mt
{
  class mt_cpu_cgen
    {
      // Include cgen generated elements.
#include "mt-cpu.h"

    public:
     /* ELF flags */
     USI eflags;
     inline void cgen_rtx_error(const char* msg) const
	{
	  cerr << "mt-cpu rtx error: " << msg << endl;
	}
    };

  class mt_cpu: public mt_cpu_cgen, public cgen_bi_endian_cpu
    {
    private:
      scache_engine<mt_scache> engine;

      // Bus that will be used later for i/o.
      sid::bus *io_bus;

      void step_insns ();
      void flush_icache ();
      void reset ();
      
      // debug support routines
      string dbg_get_reg (host_int_4 reg) { 
	 host_int_4 val4;
         string attr;

         if ( reg >= 0 && reg < 16 )
            val4 = h_spr_get(reg);    
         else if ( reg == 16)
	    val4 = this->h_pc_get();
         else if ( reg == 17 )
            {
                if (this->interrupts_enabled)
	           val4 = 1;
		else
		   val4 = 0;
            }
	 // bits 33-40 of the MAC register only available on ms1-16-003
	 else if ( reg == 18 && this->get_eflags () == 2)
	   val4 = this->mac;
	 else
	    val4 = 0;

	 big_int_4 val = val4;
         /* Convert to a string and return. */
         for (unsigned i=0; i<4; i++)
           attr += val.read_byte (i);
         return attr;
      }

      component::status dbg_set_reg (host_int_4 reg, const string& attr)
	{
	   host_int_4 val4;
	   big_int_4 val;

           if ((reg < 0) || (reg > 46))
              return component::bad_value;

           /* Convert the string to an integer and store. */
           for (unsigned i=0; i<4; i++)
             val.write_byte (i, attr[i]);
           val4 = val;

           if ( reg < 16 ) 
              h_spr_set(reg, val4);
           else if ( reg == 16)
	      this->h_pc_set(val4);
	   else if ( reg == 17 )
	     {
	       if (val4 == 0)
		 this->interrupts_enabled = false;
	       else
		 this->interrupts_enabled = true;
	     }
	   // bits 33-40 of the MAC register only available on ms1-16-003
	   else if ( reg == 18 && this->get_eflags () == 2)
	     this->mac = val4 & 0xff;

           return component::ok;
	}


      // pipeline modelling
      mt::write_stacks write_stacks;
      int tick;

      // Interrupt enable/disable tracking support.
      bool interrupts_enabled;

      
    public:
      mt_cpu ();
      ~mt_cpu () throw() { };

      void set_eflags (host_int_4 v)
      {
	this->eflags = v; 
      }

      inline USI
      get_eflags ()
      {
	return this->eflags;
      }

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
	}
      
      // Called by the semantic code at the end of a cti insn.
      inline void
      done_cti_insn (PCADDR npc, sem_status& status)
	{
	}

      void invalid_insn (PCADDR pc);
      void memory_trap (const cpu_memory_fault& t);

      // Handle software interrupts.
      void do_si (PCADDR pc)
      {
         if ( !this->interrupts_enabled )
         {
	    cout << "Interrupt processing disabled.\n";
            return;
         }
         this->interrupts_enabled = false;
	 cout << "Interrupt Received.\n";
         // More to do here later.
	 
      }
    
      // Enable the processor to receive interrupts.
      void enable_interrupts()
      {
         this->interrupts_enabled = true;
      }

      // Disable the processor from receiving interrupts.
      void disable_interrupts()
      {
         this->interrupts_enabled = false;
      }

      // The syscall and break handling functions.
      void do_syscall(PCADDR);
      void do_break(PCADDR);

      // syscall temporary registers
      SI syscall_arg0;
      SI syscall_arg1;
      SI syscall_arg2;
      SI syscall_arg3;
      SI syscall_error;
      SI syscall_result;
      USI syscall_trap_num;

      // The MAC register.
      SI mac;


     USI io_read (host_int_4, host_int_4);
     void io_write (host_int_4, host_int_4, big_int_4);

      // stream / destream state
     void stream_state (ostream& o) const;
     void destream_state (istream& i); 


    };

} // namespace mt
