//  cpu-sid.cc - override some important bx_cpu_c member functions. -*- C++ -*-
//
//  Copyright (C) 2001 Red Hat.
//
//  Copyright (C) 2001  MandrakeSoft S.A.
//
//    MandrakeSoft S.A.
//    43, rue d'Aboukir
//    75002 Paris - France
//    http://www.linux-mandrake.com/
//    http://www.mandrakesoft.com/
//
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

#include "bochs.h"
#define LOG_THIS BX_CPU_THIS_PTR

static Bit8u *sid_prefetch_data = NULL;

void
sid_cpu_c::cpu_loop(Bit32s max_instr_count)
{
  unsigned ret;
  BxInstruction_t i;
  unsigned maxisize;
  Bit8u *fetch_ptr;
  Boolean is_32;

  static int num_loops = 0;
#if BX_DEBUGGER
  BX_CPU_THIS_PTR break_point = 0;
#ifdef MAGIC_BREAKPOINT
  BX_CPU_THIS_PTR magic_break = 0;
#endif // MAGIC_BREAKPOINT
  BX_CPU_THIS_PTR stop_reason = STOP_NO_REASON;
#endif // BX_DEBUGGER

  (void) setjmp( BX_CPU_THIS_PTR jmp_buf_env );

  BX_CPU_THIS_PTR prev_eip = EIP; // commit new EIP
  BX_CPU_THIS_PTR prev_esp = ESP; // commit new ESP

#if X86_CPU_DEBUG
    printf("At top of main loop, EIP = %p, ESP = %p\n", EIP, ESP);
#endif
    
main_cpu_loop:  

  // ???
  BX_CPU_THIS_PTR EXT = 0;
  BX_CPU_THIS_PTR errorno = 0;

  // First check on events which occurred for previous instructions
  // (traps) and ones which are asynchronous to the CPU
  // (hardware interrupts).
  if (BX_CPU_THIS_PTR async_event)
    goto handle_async_event;

async_events_processed:

  // Now we can handle things which are synchronous to instruction
  // execution.
  if (BX_CPU_THIS_PTR eflags.rf) {
    BX_CPU_THIS_PTR eflags.rf = 0;
    }
#if BX_X86_DEBUGGER
  else {
    // only bother comparing if any breakpoints enabled
    if ( BX_CPU_THIS_PTR dr7 & 0x000000ff ) {
      Bit32u iaddr =
        BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.base +
        BX_CPU_THIS_PTR prev_eip;
      Bit32u dr6_bits;
      if ( (dr6_bits = hwdebug_compare(iaddr, 1, BX_HWDebugInstruction,
                                       BX_HWDebugInstruction)) ) {
        // Add to the list of debug events thus far.
        BX_CPU_THIS_PTR debug_trap |= dr6_bits;
        BX_CPU_THIS_PTR async_event = 1;
        // If debug events are not inhibited on this boundary,
        // fire off a debug fault.  Otherwise handle it on the next
        // boundary. (becomes a trap)
        if ( !(BX_CPU_THIS_PTR inhibit_mask & BX_INHIBIT_DEBUG) ) {
          // Commit debug events to DR6
          BX_CPU_THIS_PTR dr6 = BX_CPU_THIS_PTR debug_trap;
          exception(BX_DB_EXCEPTION, 0, 0); // no error, not interrupt
          }
        }
      }
    }
#endif

  // We have ignored processing of external interrupts and
  // debug events on this boundary.  Reset the mask so they
  // will be processed on the next boundary.
  BX_CPU_THIS_PTR inhibit_mask = 0;


#if BX_DEBUGGER
  {
  Bit32u debug_eip = BX_CPU_THIS_PTR prev_eip;
  if ( dbg_is_begin_instr_bpoint(
         BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].selector.value,
         debug_eip,
         BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.base + debug_eip,
         BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.d_b) ) {
    return;
    }
  }
#endif  // #if BX_DEBUGGER


  is_32 = BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.d_b;

  if (BX_CPU_THIS_PTR bytesleft == 0) {
      prefetch();
    }
  fetch_ptr = BX_CPU_THIS_PTR fetch_ptr;

  maxisize = 16;
  if (BX_CPU_THIS_PTR bytesleft < 16)
    maxisize = BX_CPU_THIS_PTR bytesleft;

  ret = FetchDecode(fetch_ptr, &i, maxisize, is_32);

#if X86_CPU_DEBUG
  printf("FetchDecode returned: %d\n", ret);
  printf("Current opcode: %p, with length: %d, EIP = %p\n", i.b1, i.ilen, this->eip);
#endif
  
  if (ret) {
    if (i.ResolveModrm) {
      // call method on sid_cpu_c object
      BX_CPU_CALL_METHOD_FROM_SID(i.ResolveModrm, (&i));
      }
    BX_CPU_THIS_PTR fetch_ptr += i.ilen;
    BX_CPU_THIS_PTR bytesleft -= i.ilen;
fetch_decode_OK:

    if (i.rep_used && (i.attr & BxRepeatable)) {
repeat_loop:
      if (i.attr & BxRepeatableZF) {
        if (i.as_32) {
          if (ECX != 0) {
            BX_CPU_CALL_METHOD_FROM_SID(i.execute_sid, (&i));
            ECX -= 1;
            }
          if ((i.rep_used==0xf3) && (get_ZF()==0)) goto repeat_done;
          if ((i.rep_used==0xf2) && (get_ZF()!=0)) goto repeat_done;
          if (ECX == 0) goto repeat_done;
          goto repeat_not_done;
          }
        else {
          if (CX != 0) {
            BX_CPU_CALL_METHOD_FROM_SID(i.execute_sid, (&i));
            CX -= 1;
            }
          if ((i.rep_used==0xf3) && (get_ZF()==0)) goto repeat_done;
          if ((i.rep_used==0xf2) && (get_ZF()!=0)) goto repeat_done;
          if (CX == 0) goto repeat_done;
          goto repeat_not_done;
          }
        }
      else { // normal repeat, no concern for ZF
        if (i.as_32) {
          if (ECX != 0) {
            BX_CPU_CALL_METHOD_FROM_SID(i.execute_sid, (&i));
            ECX -= 1;
            }
          if (ECX == 0) goto repeat_done;
          goto repeat_not_done;
          }
        else { // 16bit addrsize
          if (CX != 0) {
            BX_CPU_CALL_METHOD_FROM_SID(i.execute_sid, (&i));
            CX -= 1;
            }
          if (CX == 0) goto repeat_done;
          goto repeat_not_done;
          }
        }
      // shouldn't get here from above
repeat_not_done:
#ifdef REGISTER_IADDR
      REGISTER_IADDR(BX_CPU_THIS_PTR eip + BX_CPU_THIS_PTR sregs[BX_SREG_CS].cache.u.segment.base);
#endif

#if BX_DEBUGGER == 0
      if (BX_CPU_THIS_PTR async_event) {
        invalidate_prefetch_q();
        goto debugger_check;
      }
      goto repeat_loop;
#else  /* if BX_DEBUGGER == 1 */
      invalidate_prefetch_q();
      goto debugger_check;
#endif


repeat_done:
      BX_CPU_THIS_PTR eip += i.ilen;
    }
    else {
      // non repeating instruction
      BX_CPU_THIS_PTR eip += i.ilen;
      BX_CPU_CALL_METHOD_FROM_SID(i.execute_sid, (&i));
    }

    BX_CPU_THIS_PTR prev_eip = EIP; // commit new EIP
    BX_CPU_THIS_PTR prev_esp = ESP; // commit new ESP
#ifdef REGISTER_IADDR
    REGISTER_IADDR(BX_CPU_THIS_PTR eip + BX_CPU_THIS_PTR sregs[BX_SREG_CS].cache.u.segment.base);
#endif

debugger_check:

    // The CHECK_MAX_INSTRUCTIONS macro allows cpu_loop to execute a few
    // instructions and then return so that the other processors have a chance
    // to run.  Every time sid pulses the step pin, cpu_loop executes once
    CHECK_MAX_INSTRUCTIONS(max_instr_count);

#if BX_DEBUGGER
    // BW vm mode switch support is in dbg_is_begin_instr_bpoint
    // note instr generating exceptions never reach this point.

    // (mch) Read/write, time break point support
    if (BX_CPU_THIS_PTR break_point) {
	  switch (BX_CPU_THIS_PTR break_point) {
		case BREAK_POINT_TIME:
		      BX_CPU_THIS_PTR info("[%lld] Caught time breakpoint\n", bx_pc_system.time_ticks());
		      BX_CPU_THIS_PTR stop_reason = STOP_TIME_BREAK_POINT;
		      return;
		case BREAK_POINT_READ:
		      BX_CPU_THIS_PTR info("[%lld] Caught read watch point\n", bx_pc_system.time_ticks());
		      BX_CPU_THIS_PTR stop_reason = STOP_READ_WATCH_POINT;
		      return;
		case BREAK_POINT_WRITE:
		      BX_CPU_THIS_PTR info("[%lld] Caught write watch point\n", bx_pc_system.time_ticks());
		      BX_CPU_THIS_PTR stop_reason = STOP_WRITE_WATCH_POINT;
		      return;
		default:
		      BX_PANIC(("Weird break point condition"));
	  }
    }
#ifdef MAGIC_BREAKPOINT
    // (mch) Magic break point support
    if (BX_CPU_THIS_PTR magic_break) {
	  if (bx_dbg.magic_break_enabled) {
		BX_CPU_THIS_PTR info("Stopped on MAGIC BREAKPOINT\n");
		BX_CPU_THIS_PTR stop_reason = STOP_MAGIC_BREAK_POINT;
		return;
	  } else {
		BX_CPU_THIS_PTR magic_break = 0;
		BX_CPU_THIS_PTR stop_reason = STOP_NO_REASON;
		BX_CPU_THIS_PTR info("Ignoring MAGIC BREAKPOINT\n");
	  }
    }
#endif
    if (BX_CPU_THIS_PTR trace) {
	  BX_CPU_THIS_PTR stop_reason = STOP_TRACE;
	  return;
    }
#endif

#if BX_DEBUGGER
    {
    Bit32u debug_eip = BX_CPU_THIS_PTR prev_eip;
    if ( dbg_is_end_instr_bpoint(
           BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].selector.value,
           debug_eip,
           BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.base + debug_eip,
           BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.d_b) ) {
      return;
      }
    }
#endif  // #if BX_DEBUGGER
    goto main_cpu_loop;
  }
  else {
    unsigned remain, j;
    static Bit8u FetchBuffer[16];
    Bit8u *temp_ptr;

    // read all leftover bytes in current page
    for (j=0; j<BX_CPU_THIS_PTR bytesleft; j++) {
      FetchBuffer[j] = *fetch_ptr++;
      }

    // get remaining bytes for prefetch in next page
    // prefetch() needs eip current
    BX_CPU_THIS_PTR eip += BX_CPU_THIS_PTR bytesleft;
    remain = BX_CPU_THIS_PTR bytesleft;
    prefetch();

    if (BX_CPU_THIS_PTR bytesleft < 16) {
      // make sure (bytesleft - remain) below doesn't go negative
      BX_PANIC(("fetch_decode: bytesleft==0 after prefetch\n"));
      }
    temp_ptr = fetch_ptr = BX_CPU_THIS_PTR fetch_ptr;

    // read leftover bytes in next page
    for (; j<16; j++) {
      FetchBuffer[j] = *temp_ptr++;
      }

    ret = FetchDecode(FetchBuffer, &i, 16, is_32);

#if X86_CPU_DEBUG
      printf("Just returned from prefetch...\n");
      printf("FetchDecode returned: %d\n", ret);
      printf("Current opcode: %p, with length: %d, EIP = %p, prev_eip = %p\n", i.b1, i.ilen, this->eip, this->prev_eip);
#endif

    if (ret==0)
      BX_PANIC(("fetchdecode: cross boundary: ret==0\n"));
    if (i.ResolveModrm) {
      BX_CPU_CALL_METHOD_FROM_SID(i.ResolveModrm, (&i));
      }
    remain = i.ilen - remain;

    // note: eip has already been advanced to beginning of page
    BX_CPU_THIS_PTR fetch_ptr = fetch_ptr + remain;
    BX_CPU_THIS_PTR bytesleft -= remain;
    //BX_CPU_THIS_PTR eip += remain;
    BX_CPU_THIS_PTR eip = BX_CPU_THIS_PTR prev_eip;
    goto fetch_decode_OK;
  }



  //
  // This area is where we process special conditions and events.
  //

handle_async_event:

  if (BX_CPU_THIS_PTR debug_trap & 0x80000000) {
    // I made up the bitmask above to mean HALT state.
#if BX_SMP_PROCESSORS==1
#else      /* BX_SMP_PROCESSORS != 1 */
    // for multiprocessor simulation, even if this CPU is halted we still
    // must give the others a chance to simulate.  If an interrupt has 
    // arrived, then clear the HALT condition; otherwise just return from
    // the CPU loop with stop_reason STOP_CPU_HALTED.
    if (BX_CPU_THIS_PTR INTR && BX_CPU_THIS_PTR eflags.if_) {
      // interrupt ends the HALT condition
      BX_CPU_THIS_PTR debug_trap = 0; // clear traps for after resume
      BX_CPU_THIS_PTR inhibit_mask = 0; // clear inhibits for after resume
      //bx_printf ("halt condition has been cleared in %s\n", name);
    } else {
      // HALT condition remains, return so other CPUs have a chance
#if BX_DEBUGGER
      BX_CPU_THIS_PTR stop_reason = STOP_CPU_HALTED;
#endif
      return;
    }
#endif
  }


  // Priority 1: Hardware Reset and Machine Checks
  //   RESET
  //   Machine Check
  // (bochs doesn't support these)

  // Priority 2: Trap on Task Switch
  //   T flag in TSS is set
  if (BX_CPU_THIS_PTR debug_trap & 0x00008000) {
    BX_CPU_THIS_PTR dr6 |= BX_CPU_THIS_PTR debug_trap;
    exception(BX_DB_EXCEPTION, 0, 0); // no error, not interrupt
    }

  // Priority 3: External Hardware Interventions
  //   FLUSH
  //   STOPCLK
  //   SMI
  //   INIT
  // (bochs doesn't support these)

  // Priority 4: Traps on Previous Instruction
  //   Breakpoints
  //   Debug Trap Exceptions (TF flag set or data/IO breakpoint)
  if ( BX_CPU_THIS_PTR debug_trap &&
       !(BX_CPU_THIS_PTR inhibit_mask & BX_INHIBIT_DEBUG) ) {
    // A trap may be inhibited on this boundary due to an instruction
    // which loaded SS.  If so we clear the inhibit_mask below
    // and don't execute this code until the next boundary.
    // Commit debug events to DR6
    BX_CPU_THIS_PTR dr6 |= BX_CPU_THIS_PTR debug_trap;
    exception(BX_DB_EXCEPTION, 0, 0); // no error, not interrupt
    }

  // Priority 5: External Interrupts
  //   NMI Interrupts
  //   Maskable Hardware Interrupts
  if (BX_CPU_THIS_PTR inhibit_mask & BX_INHIBIT_INTERRUPTS) {
    // Processing external interrupts is inhibited on this
    // boundary because of certain instructions like STI.
    // inhibit_mask is cleared below, in which case we will have
    // an opportunity to check interrupts on the next instruction
    // boundary.
    }
  else if (BX_CPU_THIS_PTR INTR && BX_CPU_THIS_PTR eflags.if_ && BX_DBG_ASYNC_INTR) {
    Bit8u vector;

    // NOTE: similar code in ::take_irq()
#if BX_SUPPORT_APIC
    if (BX_CPU_THIS_PTR int_from_local_apic)
      vector = BX_CPU_THIS_PTR local_apic.acknowledge_int ();
    else
      vector = BX_IAC(); // may set INTR with next interrupt
#else
#if 0 // FIXME: this will eventually be included
    // if no local APIC, always acknowledge the PIC.
    vector = BX_IAC(); // may set INTR with next interrupt
#endif
#endif
    //if (bx_dbg.interrupts) BX_INFO(("decode: interrupt %u\n",
    //                                   (unsigned) vector));
    BX_CPU_THIS_PTR errorno = 0;
    BX_CPU_THIS_PTR EXT   = 1; /* external event */
    interrupt(vector, 0, 0, 0);
    BX_INSTR_HWINTERRUPT(vector, BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].selector.value, BX_CPU_THIS_PTR eip);
    }
#if 0 // FIXME: this will eventually be included
  else if (BX_HRQ && BX_DBG_ASYNC_DMA) {
    // NOTE: similar code in ::take_dma()
    // assert Hold Acknowledge (HLDA) and go into a bus hold state
    BX_RAISE_HLDA();
    }
#endif
  // Priority 6: Faults from fetching next instruction
  //   Code breakpoint fault
  //   Code segment limit violation (priority 7 on 486/Pentium)
  //   Code page fault (priority 7 on 486/Pentium)
  // (handled in main decode loop)

  // Priority 7: Faults from decoding next instruction
  //   Instruction length > 15 bytes
  //   Illegal opcode
  //   Coprocessor not available
  // (handled in main decode loop etc)

  // Priority 8: Faults on executing an instruction
  //   Floating point execution
  //   Overflow
  //   Bound error
  //   Invalid TSS
  //   Segment not present
  //   Stack fault
  //   General protection
  //   Data page fault
  //   Alignment check
  // (handled by rest of the code)


  if (BX_CPU_THIS_PTR eflags.tf) {
    // TF is set before execution of next instruction.  Schedule
    // a debug trap (#DB) after execution.  After completion of
    // next instruction, the code above will invoke the trap.
    BX_CPU_THIS_PTR debug_trap |= 0x00004000; // BS flag in DR6
    }
#if 0 // FIXME: this will eventually be included
  if ( !(BX_CPU_THIS_PTR INTR ||
         BX_CPU_THIS_PTR debug_trap ||
         BX_HRQ ||
         BX_CPU_THIS_PTR eflags.tf) )
    BX_CPU_THIS_PTR async_event = 0;
  goto async_events_processed;
#endif
}

// boundaries of consideration:
//
//  * physical memory boundary: 1024k (1Megabyte) (increments of...)
//  * A20 boundary:             1024k (1Megabyte)
//  * page boundary:            4k
//  * ROM boundary:             2k (dont care since we are only reading)
//  * segment boundary:         any



  void
sid_cpu_c::prefetch(void)
{
  // cs:eIP
  // prefetch QSIZE byte quantity aligned on corresponding boundary
  Bit32u new_linear_addr;
  Bit32u new_phy_addr;
  Bit32u temp_eip, temp_limit;

  temp_eip   = BX_CPU_THIS_PTR eip;
  temp_limit = BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.limit_scaled;

  new_linear_addr = BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.base + temp_eip;
  BX_CPU_THIS_PTR prev_linear_page = new_linear_addr & 0xfffff000;
  if (temp_eip > temp_limit) {
    BX_PANIC(("prefetch: EIP > CS.limit\n"));
    }

#if BX_SUPPORT_PAGING
  if (BX_CPU_THIS_PTR cr0.pg) {
    // aligned block guaranteed to be all in one page, same A20 address
    new_phy_addr = itranslate_linear(new_linear_addr, CPL==3);
    new_phy_addr = A20ADDR(new_phy_addr);
    }
  else {
#endif // BX_SUPPORT_PAGING
    new_phy_addr = A20ADDR(new_linear_addr);
#if BX_SUPPORT_PAGING
    }
#endif // BX_SUPPORT_PAGING

  // max physical address as confined by page boundary
  BX_CPU_THIS_PTR prev_phy_page = new_phy_addr & 0xfffff000;
  BX_CPU_THIS_PTR max_phy_addr = BX_CPU_THIS_PTR prev_phy_page | 0x00000fff;

  // check if segment boundary comes into play
  //if ((temp_limit - temp_eip) < 4096) {
  //  }

  BX_CPU_THIS_PTR bytesleft = 16;
  
  if(!sid_prefetch_data)
      sid_prefetch_data = new Bit8u[16];

#if X86_CPU_DEBUG
    printf("Prefetching 16 new bytes from %p...\n", new_phy_addr);
#endif
    
  BX_CPU_THIS_PTR mem->read_physical(this, new_phy_addr, 16, (void *)sid_prefetch_data);

  BX_CPU_THIS_PTR fetch_ptr = sid_prefetch_data;
}


  // If control has transfered locally, it is possible the prefetch Q is
  // still valid.  This would happen for repeat instructions, and small
  // branches.
  void
sid_cpu_c::revalidate_prefetch_q(void)
{
  Bit32u new_linear_addr, new_linear_page, new_linear_offset;
  Bit32u new_phy_addr;

  new_linear_addr = BX_CPU_THIS_PTR sregs[BX_SEG_REG_CS].cache.u.segment.base + BX_CPU_THIS_PTR eip;

  new_linear_page = new_linear_addr & 0xfffff000;
  if (new_linear_page == BX_CPU_THIS_PTR prev_linear_page) {
    // same linear address, old linear->physical translation valid
    new_linear_offset = new_linear_addr & 0x00000fff;
    new_phy_addr = BX_CPU_THIS_PTR prev_phy_page | new_linear_offset;

    BX_CPU_THIS_PTR bytesleft = 16;
  
    if(!sid_prefetch_data)
        sid_prefetch_data = new Bit8u[16];

#if X86_CPU_DEBUG
      printf("Revalidating prefetch: Prefetching 16 new bytes from %p...\n", new_phy_addr);
#endif
      
    BX_CPU_THIS_PTR mem->read_physical(this, new_phy_addr, 16, (void *)sid_prefetch_data);
    
    BX_CPU_THIS_PTR fetch_ptr = sid_prefetch_data;
  }
  else {
    BX_CPU_THIS_PTR bytesleft = 0; // invalidate prefetch Q
    }
}
