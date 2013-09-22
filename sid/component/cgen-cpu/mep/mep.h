// mep.h - Hand-written code for the Toshiba Media Engine. -*- C++ -*-

// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_H
#define MEP_H

#include "cgen-cpu.h"
#include "sidblockingutil.h"
using namespace cgen;

#include "mep-desc.h"

/* This is a hack.  This function is in libopcodes; we call it to tell
   the disassembler what mode and slot we want the bits disassembled
   for.  */
extern "C" void mep_print_insn_set_ivc2_mode (int, int, int);

using sidutil::callback_pin;

// begin-fpu-includes
// end-fpu-includes

namespace mep
{
  class mep_cpu_cgen
    {
      // Include cgen generated elements.
#include "mep-cpu.h"
// begin-copro-cpu-includes
#include "ivc2-cpu.h"
// end-copro-cpu-includes

    public:
      // getter/setter functions for h-csr
      virtual SI cgen_get_csr_value (SI index) const = 0;
      virtual VOID cgen_set_csr_value (SI index, SI newval) = 0;
      virtual VOID cgen_set_ccr_value (SI index, SI newval)
        {
	  this->hardware.h_ccr[index] = newval;
	}

      inline void cgen_rtx_error(const char* msg) const
	{
	  cerr << "mep-cpu rtx error: " << msg << endl;
	}

      // Each queue is a list of which foo_w[] registers need to be
      // copied back to the foo[] registers after an insn bundle
      // cycle.
      unsigned char cr64_queue[64]; /* num regs * num parallel insns */
      unsigned int  cr64_queuelen;
      unsigned char ccr_queue[64]; /* num regs * num parallel insns */
      unsigned int  ccr_queuelen;

      inline void h_cr64_queue_set (int index, DI newval)
        {
	  hardware.h_cr64_w[index] = newval;
	  cr64_queue[cr64_queuelen++] = index;
        }
      inline void h_ccr_queue_set (int index, DI newval)
        {
	  hardware.h_ccr_w[index] = newval;
	  ccr_queue[ccr_queuelen++] = index;
        }
      inline void h_regs_flush_write_queue ()
        {
  	  while (cr64_queuelen)
	    {
	      -- cr64_queuelen;
	      hardware.h_cr64 [cr64_queue [cr64_queuelen]]
		= hardware.h_cr64_w [cr64_queue [cr64_queuelen]];
	    }
	  while (ccr_queuelen)
	    {
	      -- ccr_queuelen;
	      hardware.h_ccr [ccr_queue [ccr_queuelen]]
		= hardware.h_ccr_w [ccr_queue [ccr_queuelen]];
	    }
      }

      // IVC2 instructions
      enum ivc2_slot_types {
	IVC2_CORE, IVC2_C3, IVC2_P0S, IVC2_P0, IVC2_P1
      };
      enum ivc2_slot_types ivc2_slot;

      mep_cpu_cgen()
	: cr64_queuelen(0),
	  ccr_queuelen(0)
        { }

      ~mep_cpu_cgen() throw ()
        { }
    };

  class debugger_bus_with_control_bus_vision :
    public sid::bus
  {
  private:
    sid::bus **data_bus;
    sid::bus **ctrl_bus;
  public:
    sid::host_int_4 ctrl_low;
    sid::host_int_4 ctrl_high;

    debugger_bus_with_control_bus_vision (sid::bus **d, sid::bus **c) :
      data_bus(d), ctrl_bus(c), ctrl_low (0x007c0000), ctrl_high (0x007fffff) 
    {}
    
#define SID_GB_WRITE(dtype) \
      sid::bus::status write(sid::host_int_4 addr, dtype data) throw ()\
	  { sid::bus **target = data_bus;\
            if (UNLIKELY(addr >= ctrl_low && addr <= ctrl_high)) { target = ctrl_bus; addr -= ctrl_low; } \
            if (LIKELY(*target)) return (*target)->write (addr, data); else return sid::bus::unpermitted; \
          }
    
#define SID_GB_READ(dtype) \
      sid::bus::status read(sid::host_int_4 addr, dtype& data) throw ()\
	  { sid::bus **target = data_bus;\
            if (UNLIKELY(addr >= ctrl_low && addr <= ctrl_high)) { target = ctrl_bus; addr -= ctrl_low; } \
            if (LIKELY(*target)) return (*target)->read (addr, data); else return sid::bus::unpermitted; \
          }
    
    SID_GB_WRITE(sid::little_int_1)
    SID_GB_WRITE(sid::big_int_1)
    SID_GB_WRITE(sid::little_int_2)
    SID_GB_WRITE(sid::big_int_2)
    SID_GB_WRITE(sid::little_int_4)
    SID_GB_WRITE(sid::big_int_4)
    SID_GB_WRITE(sid::little_int_8)
    SID_GB_WRITE(sid::big_int_8)

    SID_GB_READ(sid::little_int_1)
    SID_GB_READ(sid::big_int_1)
    SID_GB_READ(sid::little_int_2)
    SID_GB_READ(sid::big_int_2)
    SID_GB_READ(sid::little_int_4)
    SID_GB_READ(sid::big_int_4)
    SID_GB_READ(sid::little_int_8)
    SID_GB_READ(sid::big_int_8)

#undef SID_GB_WRITE
#undef SID_GB_READ

      };

  extern "C" void *mep_cpu_child_thread_root (void *comp);

  // Abstract class!
  class mep_cpu: public mep_cpu_cgen, public cgen_bi_endian_cpu, public blocking_component
    {
    public:
      mep_cpu ();
      ~mep_cpu () throw() { };

      void set_pc (host_int_4 v) 
	{ 
	  this->hardware.h_pc = (PCADDR) v; 
	}
      virtual host_int_4 get_pc () { return this->h_pc_get ();}

      // Called by semantic code to perform branches.
      inline void
      branch (PCADDR new_pc, PCADDR& npc, sem_status& status)
	{
	  cgen_bi_endian_cpu::branch (new_pc, npc, status);
	  npc = new_pc;
	  status = SEM_STATUS_BRANCH_TAKEN;
	}

      // Called by the semantic code at the end of a non-cti insn.
      // Make this a NOP; ordinary sequential PC stepping is done
      // elsewhere.
      inline void done_insn (PCADDR npc, sem_status& status)
      {
	if (saved_trace_result_p)
	  {
	    trace_result_p = trace_result_p_cache;
	    saved_trace_result_p = false;
	  }
	bit_insn_p = false;
      }
     
      // Called by the semantic code at the end of a cti insn.
      inline void
      done_cti_insn (PCADDR npc, sem_status& status)
      {
	cgen_bi_endian_cpu::done_cti_insn (npc, status);
	if (status == SEM_STATUS_BRANCH_TAKEN)
	  this->h_pc_set (npc);
	bit_insn_p = false;
      }

      virtual void invalid_insn (PCADDR pc);
      void memory_trap (const cpu_memory_fault& t);
      virtual PCADDR fpu_exception (PCADDR pc, int &status) { status = 0; return pc; }

      void set_endian(sid::host_int_4 v);
      BI big_endian_p() { return (current_endianness() == endian_big); }
      
      // Exception handlers; called from semantics
      USI zdiv_exception (PCADDR pc);
      USI break_exception (PCADDR pc);
      USI swi_exception (PCADDR pc);
      USI hw_int_exception (PCADDR pc);
      USI nmi_exception (PCADDR pc);
      USI cop_exception (PCADDR pc);
      USI dsp_exception (PCADDR pc);

      // Called from elsewhere
      bool raise_ri_exception_p;
      USI ri_exception (PCADDR pc);

      // Backends for instructions which are hard to express in rtl.
      SI do_ldz (SI rm);
      VOID do_syscall (PCADDR pc, int swi_num);
      SI do_ldcb (UINT word_addr);
      VOID do_stcb (SI rn, UINT word_addr);
      VOID do_cache (USI& op, int& addr, PCADDR& pc);
      VOID do_cache_prefetch (USI& op, int addr, PCADDR& pc);

      VOID do_smcp (USI rma, DI crn, PCADDR &pc);
      VOID do_smcpa (UINT rma_ix, SI cdisp8a8, DI crn, PCADDR &pc);
      VOID do_smcpi (UINT rma_ix, DI crn, PCADDR &pc);
      VOID do_smcp16 (USI rma, SI sdisp16, DI crn, PCADDR &pc);
      DI do_lmcp (USI rma, PCADDR &pc);
      DI do_lmcpa (UINT rma_ix, SI cdisp8a8, PCADDR &pc);
      DI do_lmcpi (UINT rma_ix, PCADDR &pc);
      DI do_lmcp16 (USI rma, SI sdisp16, PCADDR &pc);
      VOID do_sleep ();
      VOID check_write_to_text (UINT address);

      // C5 instructions
      VOID do_casb3 (SI rl, SI rn, UINT word_addr, UINT pc);
      VOID do_cash3 (SI rl, SI rn, UINT word_addr, UINT pc);
      VOID do_casw3 (SI rl, SI rn, UINT word_addr, UINT pc);

      // Methods for checking if an instruction class is activated.
      VOID check_option_abs    (PCADDR &pc) { check_option (ABS, pc);    }
      VOID check_option_ave    (PCADDR &pc) { check_option (AVE, pc);    }
      VOID check_option_bit    (PCADDR &pc) { check_option (BIT, pc); bit_insn_p = true;    }
      VOID check_option_clip   (PCADDR &pc) { check_option (CLIP, pc);   }
      VOID check_option_cp     (PCADDR& pc) { check_option (CP, pc);     }
      VOID check_option_debug  (PCADDR& pc) { check_option (DEBUG, pc);  }
      VOID check_option_div    (PCADDR& pc) { check_option (DIV, pc);    }
      VOID check_option_dsp    (PCADDR& pc) { check_option (DSP, pc);    }
      VOID check_option_ldz    (PCADDR& pc) { check_option (LDZ, pc);    }
      VOID check_option_minmax (PCADDR& pc) { check_option (MINMAX, pc); }
      VOID check_option_mul    (PCADDR& pc) { check_option (MUL, pc);    }
      VOID check_option_sat    (PCADDR& pc) { check_option (SAT, pc);    }
      VOID check_option_uci    (PCADDR& pc) { check_option (UCI, pc);    }

      VOID check_option_dcache (PCADDR& pc)
        {
	  // Check whether CCFG.DCSZ is set
	  if (UNLIKELY (! (this->hardware.h_csr[28] & 0x0000007f)))
	    invalid_insn (pc);
	}

      VOID check_option_icache (PCADDR& pc)
        {
	  // Check whether CCFG.ICSZ is set
	  if (UNLIKELY (! (this->hardware.h_csr[28] & 0x007f0000)))
	    invalid_insn (pc);
	}

      VOID check_option_cp64 (PCADDR& pc)
        {
	  if (UNLIKELY (cop_data_bus_width != 64))
	    invalid_insn (pc);
	}

      // begin-user-sim-includes
      // end-user-sim-includes

      SI cgen_get_csr_value (SI index) const;
      VOID cgen_set_csr_value (SI index, SI newval);

      SI opt_reg_value () const;

    private:
      debugger_bus_with_control_bus_vision debugger_bus;

    protected:
      enum insn_option_types {
	ABS, AVE, BIT, CLIP, CP, VL32, VL64, DEBUG, DIV, DSP,
	LDZ, MINMAX, MUL, SAT, UCI, NUM_INSN_OPTIONS
      };
      bool insn_options[NUM_INSN_OPTIONS];
      bool warn_write_to_code;
      bool dsp_user_out;
      bool corrupt_caches;
      bool step_insn_count_1_required;
      bool hwe_option;
      bool bit_insn_p;
      bool ivc2_decode_p;
      USI p0_insn, p1_insn;
      sid::host_int_4 config_index;
      int cop_data_bus_width;
      int dsp_dmem_if_width;
      int data_bus_width;
      int num_timer_channels;

      static const int CORE_UNKNOWN = 0x00;
      static const int CORE_C2 = 0x02;
      static const int CORE_C3 = 0x03;
      static const int CORE_C4 = 0x04;
      static const int CORE_C5 = 0x08;
      static const int CORE_H1 = 0x10;
      int core_type () const { return (h_csr_get (17) >> 8) & 0xff; }
      int machine () const { switch (core_type ()) {
	case CORE_H1 : return bfd_mach_mep_h1;
	case CORE_C5 : return bfd_mach_mep_c5;
	default: return bfd_mach_mep; } }
      const char *machine_name () const { switch (core_type ()) {
	case CORE_H1 : return "h1";
	case CORE_C5 : return "c5";
	default: return "mep"; } }

    private:
      bool hw_debugger_p;
      int interrupt_channel;

    protected:
      void print_insn_summary (sid::host_int_4 ignored)
      {
	if (print_final_insn_count_p)
	  std::cerr << "cpu " << ((h_csr_get (17) >> 16) & 0xff) << ": ";
	basic_cpu::print_insn_summary (ignored);
      }

      void check_option (enum insn_option_types type, PCADDR& pc)
        {
 	  if (UNLIKELY (!insn_options[type])) invalid_insn (pc);
	}
      bool imem_address (UINT address);

    private:
      // control bus accessor
      sid::bus *control_bus;
      
      void reset ();
      
      // Debug support routines.
      string dbg_get_reg (host_int_4 n);
      component::status dbg_set_reg (host_int_4 n, const string& s);

      // Syscall temporary register
      SI syscall_arg0;
      host_int_4 syscall_trap_num;

      // Commonly used csr register names.
      enum {
	psw = 16, epc = 19, exc = 20, cfg = 21, npc = 23, rcfg = 27
      };

      // Architectural support

      bool halted_p ();
      bool nmi_p ();
      bool interrupt_pending_p;

      bool hip_p()
      {
	return (h_csr_get (exc) & (1 << 8));
      }

      bool sleeping_p;

      callback_pin<mep_cpu> interrupt_pin;
      void interrupt_pin_handler (host_int_4 ignore);

      callback_pin<mep_cpu> nmi_pin;
      void nmi_pin_handler (host_int_4 ignore);
      bool nmi_suspended_p;
      bool nmi_pending_p;

      callback_pin<mep_cpu> write_to_code_pin;
      void write_to_code_pin_handler (host_int_4 addr);

      callback_pin<mep_cpu> bit_insn_bad_address_pin;
      void bit_insn_bad_address_pin_handler (host_int_4 addr);

      input_pin cache_operation_status_pin;

      bool stepping;
      bool zap_required;

      USI vector_base_address (bool exception_p = true);
      bool swi_pending_p ();

      // Shadows of ICE/DCE control bits.
      output_pin icache_enable_pin;
      output_pin dcache_enable_pin;
      void init_caches ();
      void update_cache_pins ();
      
      bool repeat_delayed_branch;

      // Common parts of instruction stepper
      void step_insns ();

      // Used by the CACHE instruction.
      output_pin cache_flush_pin;
      output_pin cache_index_flush_pin;
      output_pin cache_invalidate_pin;
      output_pin cache_index_invalidate_pin;
      output_pin cache_flush_and_invalidate_pin;
      output_pin cache_index_flush_and_invalidate_pin;
      output_pin cache_prefetch_pin;
      output_pin cache_write_hint_pin;
      output_pin data_cache_invalidate_all_pin;
      output_pin insn_cache_invalidate_all_pin;

      // Used by the DSP / UCI instructions.
      output_pin ucipin_arg1, ucipin_arg2, ucipin_arg3, ucipin_arg4;
      input_pin ucipin_exception, ucipin_result;
      output_pin dsppin_arg1, dsppin_arg2, dsppin_arg3, dsppin_arg4, dsppin_arg7;
      input_pin dsppin_exception, dsppin_cycles, dsppin_result;
      bool dsp_exception_pending_p; // XXX: no corresponding signal for UCI
      bool saved_trace_result_p;
      bool trace_result_p_cache;

    public:
      SI do_DSP (UINT rn, UINT rm, USI code, PCADDR pc); 
      SI do_UCI (UINT rn, UINT rm, USI code, PCADDR pc); 

    protected:
      virtual sem_status step_one_insn (PCADDR pc, host_int_4& size) = 0;
      virtual void zap_scaches () = 0;

      void disassemble (PCADDR pc, ISA_ATTR isa)
      {
	static CGEN_BITSET *isas = NULL;
	if (! isas)
	  isas = cgen_bitset_create (ISA_MAX);
	cgen_bitset_clear (isas);
	cgen_bitset_add (isas, isa);
	host_int_4 save_passthrough = this->downstream_passthrough_pin.recall ();
	downstream_passthrough_pin.on ();
	if (ivc2_decode_p)
	  mep_print_insn_set_ivc2_mode (ivc2_decode_p,
					(h_csr_get (16) & 0x1000) && (h_csr_get (26) & 0x40),
					config_index);
	cgen_bi_endian_cpu::disassemble (pc, print_insn_mep,
					 bfd_target_elf_flavour,
					 bfd_arch_mep,
					 (current_endianness() == endian_little ?
					 BFD_ENDIAN_LITTLE : BFD_ENDIAN_BIG),
					 machine_name (), isas, machine ());
	if (ivc2_decode_p)
	  mep_print_insn_set_ivc2_mode (0, 0, 0);
	downstream_passthrough_pin.set (save_passthrough);
      }

      binary_output_pin downstream_passthrough_pin;

      // Set a CSR register, but go under the covers to make sure that even read-only
      // bits get set.
      inline void h_csr_set_internal (UINT regno, SI newval) { hardware.h_csr[regno] = newval; }

      // ------------------------------------------------------------------------
      // blockable thread support
      //
    public:
      virtual void step_pin_handler (sid::host_int_4);
      void parent_step_pin_handler (sid::host_int_4 v)
      {
	blocked_latency = 0;
	cgen_bi_endian_cpu::step_pin_handler (v);
      }

    protected:
      virtual bool handle_insn_memory_read_error (sid::bus::status s, sid::host_int_4 & address) { return handle_bus_error (s); }
      virtual bool handle_insn_memory_write_error (sid::bus::status s, sid::host_int_4 & address) { return handle_bus_error (s); }
      virtual bool handle_data_memory_read_error (sid::bus::status s, sid::host_int_4 & address) { return handle_bus_error (s); }
      virtual bool handle_data_memory_write_error (sid::bus::status s, sid::host_int_4 & address) { return handle_bus_error (s); }
  
      // Handles errors for all of the above.
      virtual bool handle_bus_error (sid::bus::status s);

      virtual void record_insn_memory_read_latency (sid::bus::status s)
        { record_blocked_latency (s); }
      virtual void record_data_memory_read_latency (sid::bus::status s)
        { record_blocked_latency (s); }

      void record_blocked_latency (sid::bus::status s)
        {
	  if (s.latency == 0)
	    return;
	  total_latency += s.latency;
	  if (blockable)
	    {
	      blocked_latency += s.latency;
	      cgen_bi_endian_cpu::stepped (s.latency);
	      child_blocked ();
	    }
	}
      virtual void stepped (sid::host_int_4 n)
        {
	  cgen_bi_endian_cpu::stepped (n - blocked_latency);
	}
      sid::host_int_4 blocked_latency;

      // ----------------------------------------------------------------------
      // Dynamic configuration support
    protected:
  protected:
      virtual component::status dynamic_config(const string& spec);
      virtual void configure (const string &config);

      component *insn_buffer;
  };

  // All the possible ways to bundle instructions
  enum mep_insn_bundling
    {
      MEP_BUNDLING_UNKNOWN,
      MEP_CORE_16,
      MEP_CORE_32,
      MEP_COPRO_32,
      MEP_COPRO_64,
      MEP_CORE_16_COPRO_16, MEP_CORE_16_COPRO_48, MEP_CORE_32_COPRO_32,
      MEP_IVC2_V1, MEP_IVC2_V2, MEP_IVC2_V3,
    };
  
  template <class CPU, class CORE, class VLIW16, class VLIW32, class VLIW48, class VLIW64>
  class mep_cpu_vliw: public mep_cpu
  {
    CPU* thisp; // pointer to subclass instance

    typedef generic_scache_record< pair<mep_insn_bundling,UHI> > mep_bundling_scache;
    scache_engine<mep_bundling_scache> engine_bundling;
    scache_engine<CORE> engine_core;
    scache_engine<VLIW16> engine_cop_16;
    scache_engine<VLIW32> engine_cop_32;
    scache_engine<VLIW48> engine_cop_48;
    scache_engine<VLIW64> engine_cop_64;

    // Bundling cache
    mep_insn_bundling decode_bundling (PCADDR pc, UHI& insn_0);

    void zap_scaches ()
    {
      // Invalidate the decoder caches.
      engine_bundling.flush ();
      engine_core.flush ();
      engine_cop_16.flush ();
      engine_cop_32.flush ();
      engine_cop_48.flush ();
      engine_cop_64.flush ();
    }
    
    // Where the cached data is kept

    // For use in disassembly, tracing
    ISA_ATTR coreisa;
    ISA_ATTR cop16isa;
    ISA_ATTR cop32isa;
    ISA_ATTR cop48isa;
    ISA_ATTR cop64isa;
    sid::host_int_8 pending_latency;

  public:
    mep_cpu_vliw (CPU* t,
		  ISA_ATTR ci,
		  ISA_ATTR c16i,
		  ISA_ATTR c32i,
		  ISA_ATTR c48i,
		  ISA_ATTR c64i)
      :thisp (t),
       engine_bundling (32768),
       engine_core (32768),
       engine_cop_16 (32768),
       engine_cop_32 (32768),
       engine_cop_48 (32768),
       engine_cop_64 (32768),
       coreisa (ci),
       cop16isa (c16i),
       cop32isa (c32i),
       cop48isa (c48i),
       cop64isa (c64i),
       pending_latency (0)
    {}

    ~mep_cpu_vliw () throw () {}

    /* virtual */ sem_status step_one_insn (PCADDR pc, host_int_4& size);
    /* virtual */ void step_one_insn ();

    /* virtual */ void flush_icache ();
    /* virtual */ void flush_icache (host_int_4 pc);
  };


  // All the class template's member functions need to be defined here.

  template <class CPU, class CORE, class VLIW16, class VLIW32, class VLIW48, class VLIW64>
  mep_insn_bundling
  mep::mep_cpu_vliw<CPU,CORE,VLIW16,VLIW32,VLIW48,VLIW64>::decode_bundling (PCADDR pc, UHI& insn_0)
  {
    // Maybe the bundling info is already cached:
    bool found;
    mep_bundling_scache* s = this->engine_bundling.find (pc, found);
    if (LIKELY (found))
      {
	insn_0 = s->content.second;
	return s->content.first;
      }

    // Nope; must compute it afresh.
    SI pswreg = h_csr_get (16);  // PSW register
    SI optreg = h_csr_get (26);  // OPT register
    SI idreg = h_csr_get (17);   // ID register
    bool vliw32 = (pswreg & 0x1000) && (optreg & 0x20);
    bool vliw64 = (pswreg & 0x1000) && (optreg & 0x40);

    mep_insn_bundling result = MEP_BUNDLING_UNKNOWN;

    // imem fetch
    insn_0 = this->GETIMEMHI (pc, pc);
    s->content.second = insn_0;

    // Find the expected core/copro insn sizes.
    if (UNLIKELY (vliw64))
      {
	// We are in vliw64 mode.  We have to find the instruction
	// proportions before we continue.

	if (ivc2_decode_p)
	  {
	    if ((insn_0 & 0xf00f) == 0xf007)
	      result = MEP_IVC2_V3;
	    else if ((insn_0 & 0xc000) == 0xc000)
	      result = MEP_IVC2_V2;
	    else
	      result = MEP_IVC2_V1;
	  }
      
	else if ((insn_0 & 0x8000) && (insn_0 & 0x4000))
	  {
	    // We either have a 64-bit copro insn or a 32-bit
	    // core insn with a 32-bit copro insn.
	    if ( ((insn_0 & 0xf000) == 0xf000) &&
		 ((insn_0 & 0x07) == 0x07) )
	      result = MEP_COPRO_64;
	    else
	      result = MEP_CORE_32_COPRO_32;
	  }
	else
	  result = MEP_CORE_16_COPRO_48;
      }
    else if (UNLIKELY (vliw32))
      {
	// We are in vliw32 mode.  We have to find the instruction
	// proportions before we continue.
      
	if ((insn_0 & 0x8000) && (insn_0 & 0x4000))
	  {
	    // We either have a 32-bit core insn or a 32-bit
	    // copro insn.
	    if ( ((insn_0 & 0xf000) == 0xf000) &&
		 ((insn_0 & 0x07) == 0x07) )
	      result = MEP_COPRO_32;
	    else
	      result = MEP_CORE_32;
	  }
	else
	  result = MEP_CORE_16_COPRO_16;
      }
    else
      {
	// Core mode.
      
	if ( ivc2_decode_p
	     && ((insn_0 & 0xf000) == 0xf000)
	     && ((insn_0 & 0x000f) == 0x0007) )
	  result = MEP_COPRO_32;
	else if ((insn_0 & 0x8000) && (insn_0 & 0x4000))
	  result = MEP_CORE_32;
	else
	  result = MEP_CORE_16;
      }

    if (UNLIKELY (this->trace_extract_p))
      {
	this->trace_stream <<
	  (result == MEP_CORE_16 ? "core-16" :
	   result == MEP_CORE_32 ? "core-32" :
	   result == MEP_COPRO_32 ? "copro-32" :
	   result == MEP_COPRO_64 ? "copro-64" :
	   result == MEP_CORE_16_COPRO_16 ? "core-16-copro-16" :
	   result == MEP_CORE_16_COPRO_48 ? "core-16-copro-48" :
	   result == MEP_CORE_32_COPRO_32 ? "core-32-copro-32" :
	   result == MEP_IVC2_V1 ? "ivc2-v1" :
	   result == MEP_IVC2_V2 ? "ivc2-v2" :
	   result == MEP_IVC2_V3 ? "ivc2-v3" :
	   "core-?-copro-?") << " ";
      }

    s->content.first = result;
    return result;
  }


  template <class CPU, class CORE, class VLIW16, class VLIW32, class VLIW48, class VLIW64>
  void
  mep_cpu_vliw<CPU,CORE,VLIW16,VLIW32,VLIW48,VLIW64>::flush_icache ()
  {
    this->engine_bundling.flush ();
    this->engine_core.flush ();
    this->engine_cop_16.flush ();
    this->engine_cop_32.flush ();
    this->engine_cop_48.flush ();
    this->engine_cop_64.flush ();
  }



  template <class CPU, class CORE, class VLIW16, class VLIW32, class VLIW48, class VLIW64>
  void
  mep_cpu_vliw<CPU,CORE,VLIW16,VLIW32,VLIW48,VLIW64>::flush_icache (host_int_4 pc)
  {
    this->engine_bundling.zap (pc);
    this->engine_core.zap (pc);
    this->engine_cop_16.zap (pc);
    this->engine_cop_32.zap (pc);
    this->engine_cop_48.zap (pc);
    this->engine_cop_64.zap (pc);
  }


  template <class CPU, class CORE, class VLIW16, class VLIW32, class VLIW48, class VLIW64>
  sem_status
  mep_cpu_vliw<CPU,CORE,VLIW16,VLIW32,VLIW48,VLIW64>::step_one_insn (PCADDR pc, host_int_4& insn_size)
  {
    sid::host_int_8 pre_fetch_latency = this->get_total_latency ();
    sem_status s = SEM_STATUS_NORMAL;
    UHI insn_0; // Fetched or cached
    mep_insn_bundling b = this->decode_bundling (pc, insn_0);
  
    insn_size = 0; // # of bytes in this bundle / instruction (pair)
  
    // Decode the instruction bundle  -------------------------
    CORE* sem = 0;
    VLIW16* sem_cop_16 = 0;
    VLIW32* sem_cop_32 = 0;
    VLIW48* sem_cop_48 = 0;
    VLIW64* sem_cop_64 = 0;

    switch (b)
      {
      case MEP_CORE_16:
	{
	  insn_size = 2;
	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      USI insn = insn_0 << 16;
	      sem->decode (thisp, pc, insn, insn);
	    }
	}
	break;

      case MEP_CORE_32:
	{
	  insn_size = 4;
	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_1 = GETIMEMHI (pc, pc + 2);
	      USI insn = (insn_0 << 16) | insn_1;
	      sem->decode (thisp, pc, insn, insn);
	    }
	}
	break;

      case MEP_COPRO_32:
	{
	  insn_size = 4;
	  bool found;
	  sem_cop_32 = this->engine_cop_32.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_1 = GETIMEMHI (pc, pc + 2);
	      USI insn = (insn_0 << 16) | insn_1;
	      sem_cop_32->decode (thisp, pc, insn, insn);
	    }
	}
	break;

      case MEP_COPRO_64:
	{
	  insn_size = 8;
	  bool found;
	  sem_cop_64 = this->engine_cop_64.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_1 = GETIMEMHI (pc, pc + 2);
	      // UHI insn_2 = GETIMEMHI (pc, pc + 4);
	      // UHI insn_3 = GETIMEMHI (pc, pc + 6);
	      USI insn = (insn_0 << 16) | insn_1;
	      // UDI entire_insn = 
	      //  (insn_0 << 48) | (insn_1 << 32) | (insn_2 << 16) | insn_3;
	      // sem_cop_64->decode (this, pc, insn, entire_insn);
	      sem_cop_64->decode (thisp, pc, insn, insn);
	    }
	}
	break;

      case MEP_CORE_16_COPRO_16:
	{
	  insn_size = 4;
	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      USI insn = insn_0 << 16;
	      sem->decode (thisp, pc, insn, insn);
	    }

	  sem_cop_16 = this->engine_cop_16.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_1 = GETIMEMHI (pc, pc + 2);
	      USI insn = insn_1 << 16;
	      sem_cop_16->decode (thisp, pc + 2, insn, insn);
	    }
	}
	break;

      case MEP_CORE_16_COPRO_48:
	{
	  insn_size = 8;
	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      USI insn = (insn_0 << 16);
	      sem->decode (thisp, pc, insn, insn);
	    }

	  sem_cop_48 = this->engine_cop_48.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_1 = GETIMEMHI (pc, pc + 2);
	      UHI insn_2 = GETIMEMHI (pc, pc + 4);
	      // UHI insn_3 = GETIMEMHI (pc, pc + 6);
	      USI insn = (insn_1 << 16) | insn_2;
	      // UDI entire_insn = (insn_1 << 32) | (insn_2 << 16) | insn_3;
	      // sem_cop_48->decode (this, pc, insn, entire_insn);
	      sem_cop_48->decode (thisp, pc + 2, insn, insn);
	    }
	}
	break;

      case MEP_CORE_32_COPRO_32:
	{
	  insn_size = 8;
	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_1 = GETIMEMHI (pc, pc + 2);
	      USI insn = (insn_0 << 16) | insn_1;
	      sem->decode (thisp, pc, insn, insn);
	    }

	  sem_cop_32 = this->engine_cop_32.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      UHI insn_2 = GETIMEMHI (pc, pc + 4);
	      UHI insn_3 = GETIMEMHI (pc, pc + 6);
	      USI insn = (insn_2 << 16) | insn_3;
	      sem_cop_32->decode (thisp, pc + 4, insn, insn);
	    }
	}
	break;

      // IVC instructions need to be unpacked; they're not
      // byte-aligned.  CGEN encodes these msb-justified in a 32 bit
      // word in a single list (p0/p1 format) with a SLOTS attribute
      // that says which instructions can run in which slots.  The p0s
      // instructions are zero-extended to 28 bits, then treated as p0
      // instructions.

      // We use COP16 for p0s instructions, COP48 for p0, and COP64
      // for p1.  COP32 is used for 32-bit core-mode insns.  We store
      // the unpacked instructions in p0_insn and p1_insn.

      case MEP_IVC2_V1:
	{
	  // 01234567 01234567 01234567 01234567 01234567 01234567 01234567 01234567
	  // [-----core------] [--------p0s---------][--------------p1-------------]
	  insn_size = 8;
	  UHI insn_1 = GETIMEMHI (pc, pc + 2);
	  UHI insn_2 = GETIMEMHI (pc, pc + 4);
	  UHI insn_3 = GETIMEMHI (pc, pc + 6);

	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      USI insn = (insn_0 << 16);
	      sem->decode (thisp, pc, insn, insn);
	    }

	  sem_cop_16 = this->engine_cop_16.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      p0_insn = (insn_1 << 8) | ((insn_2 >> 8) & 0xf0);
	      sem_cop_16->decode (thisp, pc, p0_insn, p0_insn);
	    }

	  sem_cop_64 = this->engine_cop_64.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      p1_insn = (insn_2 << 20) | (insn_3 << 4);
	      sem_cop_64->decode (thisp, pc, p1_insn, p1_insn);
	    }
	}
	break;

      case MEP_IVC2_V2:
	{
	  // 01234567 01234567 01234567 01234567 01234567 01234567 01234567 01234567
	  // [---------------core--------------] xxxx[--------------p1-------------]
	  insn_size = 8;
	  UHI insn_1 = GETIMEMHI (pc, pc + 2);
	  UHI insn_2 = GETIMEMHI (pc, pc + 4);
	  UHI insn_3 = GETIMEMHI (pc, pc + 6);

	  bool found;
	  sem = this->engine_core.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      USI insn = (insn_0 << 16) | insn_1;
	      sem->decode (thisp, pc, insn, insn);
	    }

	  sem_cop_64 = this->engine_cop_64.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      p1_insn = (insn_2 << 20) | (insn_3 << 4);
	      sem_cop_64->decode (thisp, pc, p1_insn, p1_insn);
	    }
	}
	break;

      case MEP_IVC2_V3:
	{
	  // 01234567 01234567 01234567 01234567 01234567 01234567 01234567 01234567
	  // 1111[--p0---]0111 [--------p0----------][--------------p1-------------]
	  //     1234 5678     12345678 12345678 12345678

	  insn_size = 8;
	  UHI insn_1 = GETIMEMHI (pc, pc + 2);
	  UHI insn_2 = GETIMEMHI (pc, pc + 4);
	  UHI insn_3 = GETIMEMHI (pc, pc + 6);

	  bool found;
	  sem_cop_48 = this->engine_cop_48.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      p0_insn = (((insn_0 << 20) & 0xff000000)
			 | (insn_1 << 8)
			 | ((insn_2 >> 8) & 0xf0));
	      sem_cop_48->decode (thisp, pc, p0_insn, p0_insn);
	    }

	  sem_cop_64 = this->engine_cop_64.find (pc, found);
	  if (UNLIKELY (! found))
	    {
	      p1_insn = (insn_2 << 20) | (insn_3 << 4);
	      sem_cop_64->decode (thisp, pc, p1_insn, p1_insn);
	    }
	}
	break;

      case MEP_BUNDLING_UNKNOWN:
      default:
	// Shouldn't happen.
	invalid_insn (pc);
	// NOTREACHED
	break;
      }

    // Run the instruction bundle  ----------------------------
    sid::host_int_4 cycles;
    if (UNLIKELY (trace_counter_p || final_insn_count_p))
      {
	thisp->core_model_insn_before (true);
	cycles = 1;
      }

    if (ivc2_decode_p)
      {
	// For IVC2 we disassemble the whole bundle at once, rather
	// than one insn at a time like we do for other coprocessors,
	// as the disassembler needs to know which slot each insn
	// comes from.
	if (UNLIKELY (trace_disass_p))
	  this->disassemble (pc, (b == MEP_COPRO_32) ? cop32isa : coreisa);
      }

    s = SEM_STATUS_NORMAL;
    if (sem) 
      {
	ivc2_slot = IVC2_CORE;
	if (UNLIKELY (trace_counter_p || final_insn_count_p))
	  {
	    // Determine whether there was insn fetch latency. If so,
	    // set it aside for now, since Toshiba wants the cycle count to
	    // be the pre-fetch count.
	    sid::host_int_8 post_fetch_latency = this->get_total_latency ();
	    sid::host_int_8 fetch_latency = post_fetch_latency - pre_fetch_latency;
	    if (fetch_latency)
	      {
		this->pending_latency = fetch_latency;
		this->set_total_latency (pre_fetch_latency);
	      }
		
	    // See if we're stalled.
	    UINT stall = thisp->model_before (sem);
	    if (UNLIKELY (stall))
	      {
		thisp->core_model_step_latency (stall);
		if (blockable)
		  {
		    record_blocked_latency (bus::status (bus::busy, stall));
		    pending_latency += stall;
		    // The stall has been counted twice: once in model_before
		    // and again in record_blocked_latency
		    set_total_latency (get_total_latency () - stall);
		  }
		else
		  return SEM_STATUS_STALLED;
	      }

	    // Not stalled, so print the pre-fetch cycle count and restore the
	    // pending latency.
	    if (UNLIKELY (trace_counter_p))
	      {
		this->trace_stream << ((h_csr_get (17) >> 16) & 0xff) << " ";
		this->trace_counter (pc);
	      }
	    this->set_total_latency (pre_fetch_latency + this->pending_latency);
	    this->pending_latency = 0;
	  }
	if (UNLIKELY (trace_disass_p && !ivc2_decode_p))
	  {
	    if (LIKELY (! dsp_user_out
			|| !(sem->idesc->attrs.bools & (1 << CGEN_INSN_OPTIONAL_DSP_INSN))))
	      this->disassemble (pc, coreisa);
	    else
	      this->trace_stream << "0x" << std::setw(8) << std::setfill('0')
				 << std::hex <<  (unsigned int) pc << "\t"
				 << std::dec;
	  }
	sem_status s1 = sem->idesc->execute (thisp, sem);
	if (UNLIKELY (trace_counter_p || final_insn_count_p))
	  {
	    sid::host_int_4 new_cycles = thisp->model_after (sem);
	    if (new_cycles > cycles)
	      cycles = new_cycles;
	  }
	if (s1 != SEM_STATUS_NORMAL) s = s1;
      }

    if (sem_cop_16)
      {
	ivc2_slot = IVC2_P0S;
	if (UNLIKELY (trace_disass_p && !ivc2_decode_p))
	  this->disassemble (pc + 2, cop16isa);
	if (UNLIKELY (trace_semantics_p))
	  this->begin_trace (pc, sem_cop_16->idesc->insn_name);
	sem_status s1 = sem_cop_16->idesc->execute (thisp, sem_cop_16);
	if (UNLIKELY (trace_counter_p || final_insn_count_p))
	  {
	    sid::host_int_4 new_cycles = thisp->model_after (sem_cop_16);
	    if (new_cycles > cycles)
	      cycles = new_cycles;
	  }
	if (s1 != SEM_STATUS_NORMAL) s = s1;
      }
    if (sem_cop_32)
      {
	ivc2_slot = IVC2_C3;
	if (UNLIKELY (trace_counter_p && b == MEP_COPRO_32))
	  {
	    this->trace_stream << ((h_csr_get (17) >> 16) & 0xff) << " ";
	    this->trace_counter (pc);
	  }
	if (UNLIKELY (trace_disass_p && !ivc2_decode_p))
	  {
	    if (b == MEP_COPRO_32)
	      this->disassemble (pc, cop32isa);
	    else
	      this->disassemble (pc + 4, cop32isa);
	  }
	if (UNLIKELY (trace_semantics_p))
	  this->begin_trace (pc, sem_cop_32->idesc->insn_name);

	sem_status s1 = sem_cop_32->idesc->execute (thisp, sem_cop_32);
	if (UNLIKELY (trace_counter_p || final_insn_count_p))
	  {
	    sid::host_int_4 new_cycles = thisp->model_after (sem_cop_32);
	    if (new_cycles > cycles)
	      cycles = new_cycles;
	  }
	if (s1 != SEM_STATUS_NORMAL) s = s1;
      }
    if (sem_cop_48)
      {
	ivc2_slot = IVC2_P0;
	if (UNLIKELY (trace_disass_p && !ivc2_decode_p))
	  this->disassemble (pc + 2, cop48isa);
	if (UNLIKELY (trace_semantics_p))
	  this->begin_trace (pc, sem_cop_48->idesc->insn_name);

	sem_status s1 = sem_cop_48->idesc->execute (thisp, sem_cop_48);
	if (UNLIKELY (trace_counter_p || final_insn_count_p))
	  {
	    sid::host_int_4 new_cycles = thisp->model_after (sem_cop_48);
	    if (new_cycles > cycles)
	      cycles = new_cycles;
	  }
	if (s1 != SEM_STATUS_NORMAL) s = s1;
      }
    if (sem_cop_64)
      {
	ivc2_slot = IVC2_P1;
	if (UNLIKELY (trace_counter_p))
	  {
	    this->trace_stream << ((h_csr_get (17) >> 16) & 0xff) << " ";
	    this->trace_counter (pc);
	  }
	if (UNLIKELY (trace_disass_p && !ivc2_decode_p))
	  this->disassemble (pc, cop64isa);
	if (UNLIKELY (trace_semantics_p))
	  this->begin_trace (pc, sem_cop_64->idesc->insn_name);

	sem_status s1 = sem_cop_64->idesc->execute (thisp, sem_cop_64);
	if (UNLIKELY (trace_counter_p || final_insn_count_p))
	  {
	    sid::host_int_4 new_cycles = thisp->model_after (sem_cop_64);
	    if (new_cycles > cycles)
	      cycles = new_cycles;
	  }
	if (s1 != SEM_STATUS_NORMAL) s = s1;
      }

    if (UNLIKELY (trace_counter_p || final_insn_count_p))
      thisp->core_model_insn_after (true, cycles);

    return s;
  }

  // These dummy idesc/scache types are used for the VLIW template slots.
  // They should never be used, since generic core code should never get
  // into VLIW mode.
  class dummy_scache;
  struct dummy_idesc
  {
    const char* insn_name;
    dummy_idesc (): insn_name ("nonexistent vliw instruction") {}

    inline sem_status execute (mep_cpu* current_cpu, dummy_scache* sem);
  };

  struct dummy_scache
    {
      dummy_idesc my_idesc; // a private instance
      dummy_idesc* idesc;
      PCADDR addr;
      void decode (const mep_cpu* current_cpu, PCADDR pc, 
		   long base, long entire)
      {
	this->addr = pc;
	this->idesc = & this->my_idesc;
      }
    };
  
  inline sem_status dummy_idesc::execute (mep_cpu* current_cpu, dummy_scache* sem)
    {
      current_cpu->invalid_insn (sem->addr);
      // or abort() ?
      
      // NOTREACHED
      return SEM_STATUS_NORMAL;
    }
} // namespace mep


#endif // MEP_H
