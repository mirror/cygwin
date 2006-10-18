// sh_vliw.cxx - Implementations of hand-written functions for the sh
// simulator. -*- C++ -*-

// Copyright (C) 2006 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "sh_vliw.h"
#include "sh2a_model.h"
#include "sh4_model.h"
#include "sh4a_model.h"
#include "sh4al_model.h"

using namespace sh;

using sid::host_int_4;
using sid::host_int_8;

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::sh_vliw_cpu (CPU *cpu) :
  sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL> (cpu)
{
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::reset ()
{
  sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::reset ();
  reset_vliw ();
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::reset_vliw ()
{
  next_insn_in_delay_slot_p = false;
  vliw_insns.clear ();
}

// --------------------------------------------------------------------------------
// Some inline-friendly private methods.
//
template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
inline bool
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::is_cti_insn (SCACHE *sc)
{
  return (sc->idesc->attrs.get_uncond_cti_attr ()
	  || sc->idesc->attrs.get_cond_cti_attr ());
}


// --------------------------------------------------------------------------------
// Remaining methods.
//
// Stepper
template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::step_insns ()
{
  bool stop = false;
  do
    {
      PCADDR pc = this->h_pc_get ();
      
      sem_status s;
      this->parallel_possible_p = false;
      try 
	{
	  // Call down to VLIW or non-VLIW steppers
	  s = this->step_one_insn (pc);
	}
      catch (cpu_memory_fault& t)
        {
          this->memory_trap (t);
          break;
        }
      catch (cpu_exception& t)
        {
           this->yield ();
        }
      catch (fp::error& fe)
        {
	  int status = fe;
	  this->fpu_exception (pc, status);
	  if (status == 0) // no exception
	    this->h_pc_set ((pc + this->insn_size (pc)) | this->h_ism_get ());
	  else
	    this->h_pc_set (pc | this->h_ism_get ());
        }

      // Check to see if we're stalled
      if (LIKELY (s != SEM_STATUS_STALLED))
	{
	  if (UNLIKELY (this->trace_counter_p || this->trace_semantics_p
			|| this->trace_disass_p || this->trace_result_p))
	    this->end_trace ();
        
	  // Execute writeback
	  try {
	    this->write_stacks_writeback ();
	  }
	  catch (cpu_memory_fault& t)
	    {
	      this->memory_trap (t);
	    }
	  catch (cpu_exception& t)
	    {
	      this->yield ();
	    }

	  // move ahead thru circular pipeline
	  this->update_tick ();

	  // Do post-instruction processing  ----------------------------
	  if (this->enable_step_trap_p) 
	    this->signal_trap (sidutil::cpu_trap_stepped);
	  this->triggerpoint_manager.check_and_dispatch ();

	  // test for exit condition
	  if (this->stop_after_insns_p (1))
	    stop = true;
	} // Not stalled
    } while (! stop || this->parallel_possible_p);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
sem_status
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::step_one_insn (PCADDR pc)
{
  // Loop over parallel insns
  sem_status s = SEM_STATUS_NORMAL;
  for (;;)
    {
      // Decode the insn  ----------------------------
      this->fetched_insn_pc = pc;
      this->decode_insn (pc);

      // Pre execution processing ----------------------------
      if (UNLIKELY (this->trace_counter_p || this->final_insn_count_p))
	{
	  // Assume that this will be the first insn in the vliw bundle
	  // until proven otherwise.
	  this->model_insn_before ();

	  // See if we're stalled.
	  UINT stall = this->model_before (this->fetched_insn);
	  if (UNLIKELY (stall))
	    {
	      this->update_total_latency (stall);
	      this->model.step_latency ();
	      return SEM_STATUS_STALLED;
	    }

	  if (UNLIKELY (this->trace_counter_p))
	    this->trace_counter (pc);
	}

      if (UNLIKELY (this->trace_disass_p))
	this->disassemble (pc);

      // Run the insn  ----------------------------
      this->execute_insn ();

      // Post execution processing ----------------------------
      if (UNLIKELY (this->trace_counter_p || this->final_insn_count_p))
	{
	  sid::host_int_4 cycles = this->model_after (this->fetched_insn);
	  model_status ms = this->model_insn_after (cycles, pc);
	  if (ms == model_get_insn)
	    continue;
	  if (ms == model_stalled)
	    s = SEM_STATUS_STALLED;
	}

      break;
    } // Loop over parallel insns

  return s;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_step_latency (sid::host_int_4 cycles)
{
  this->model.step_latency (cycles);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_insn_before ()
{
  // Nothing to do if both slots filled.
  if (vliw_insns.size () >= 2)
    return;

  // Current insn is already loaded? This happens after a delayed
  // branch.
  if (vliw_insns.size () > 0)
    {
      insn_info<SCACHE> *insn = vliw_insns.back ();
      if (insn->get_pc () == this->fetched_insn_pc)
	return;
    }

  // Allocate a new insn_info and add it.
  insn_info<SCACHE> *insn = new insn_info<SCACHE>;
  insn->set_pc (this->fetched_insn_pc);
  insn->set_delay_slot (next_insn_in_delay_slot_p);
  next_insn_in_delay_slot_p = false;
  vliw_insns.push_back (insn);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
UINT
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_before (SCACHE *sc)
{
  // Current insn is already loaded in slot 0? This happens after a stall.
  insn_info<SCACHE> *insn;
  if (vliw_insns.size () >= 2)
    {
      insn = vliw_insns[0];
      if (insn && insn->get_pc () == this->fetched_insn_pc)
	return 0;
    }

  // Save the insn and the latency of insn fetch.
  insn = vliw_insns.back ();
  insn->set_sh5_media (false);
  insn->set_insn (sc);
  insn->set_post_fetch_latency (this->get_total_latency ());
  return 0;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
UINT
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_before (sh5_media_scache *sc)
{
  insn_info<SCACHE> *insn = vliw_insns.back ();
  insn->set_sh5_media (true);
  return 0;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::trace_counter (PCADDR pc)
{
  // Do nothing. Will be done later
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::disassemble (PCADDR pc)
{
  // Do nothing if profiling. Will be done later
  if (LIKELY (! this->trace_counter_p && ! this->final_insn_count_p))
    sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::disassemble (pc);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
void
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::execute_insn ()
{
  // Do nothing if profiling. Will be done later
  if (LIKELY (! this->trace_counter_p && ! this->final_insn_count_p))
    this->execute_insn (this->fetched_insn);
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
UINT
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_after (SCACHE *)
{
  // Do nothing. Will be done later
  return 0;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
UINT
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_after (sh5_media_scache *)
{
  // Do nothing.
  return 0;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
model_status
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_insn_after (UINT, PCADDR& pc)
{
  // Ignore the given number of cycles. It will always be zero. Instead,
  // examine the vliw stack and run the model as appropriate.
  // If there is only one insn on the stack, then do nothing.
  // Otherwise, examine the insns on the stack to see if they can be
  // handled in parallel.
  insn_info<SCACHE> *insn1 = vliw_insns[0];
  if (vliw_insns.size () < 2)
    {
      pc = next_pc (insn1, pc);
      return model_get_insn;
    }

  // At least one insn will always be executed/modelled
  // Call the generic model-before method
  insn_info<SCACHE> *insn2 = vliw_insns[1];
  insn_info<SCACHE> *insn = insn1 ? insn1 : insn2;
  this->set_total_latency (insn->get_post_fetch_latency ());
  this->model.step_latency ();

  // Execute/model the insn.
  // If it's stalled advance the model...
  SCACHE *sc = insn->get_insn ();
  UINT stall = this->model.model_before (this->thisp, sc);
  if (UNLIKELY (stall))
    {
      // Update latencies.
      this->update_total_latency (stall);

      // Advance the model.
      // This is what model_insn_before boils down to for this port.
      this->model.step_latency ();
      //      sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::model_before (sc); -- done when we're called again now

      // If the insn is insn 2, then the stall should be counted as one less
      // than indicated.
      host_int_8 post_stall_latency = this->get_total_latency () - (insn == insn2);
      insn->update_post_fetch_latency (post_stall_latency);

      if (insn == insn1)
	insn2->update_post_fetch_latency (post_stall_latency);
      else
	{
	  this->set_total_latency (post_stall_latency);
	  model_reduce_latency (1);

	  // insn2 could now be the first insn in a pair.
	  vliw_insns.erase (vliw_insns.begin ());
	  pc = next_pc (insn, pc);
	}

      return model_stalled;
    }

  // Otherwise, adjust the total latency by 1 for the parallel insn.
  // This compensates for the incrementing of the total insn count.
  if (insn == insn2)
    {
      insn->reduce_post_fetch_latency (1);
      model_reduce_latency (1);
    }
      
  // Resync the total latency
  this->set_total_latency (insn->get_post_fetch_latency ());

  // ... Trace counter, if requested.
  if (UNLIKELY (this->trace_counter_p))
    sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::trace_counter (insn->get_pc ());

  // ... Disassemble, if requested.
  if (UNLIKELY (this->trace_disass_p))
    sh_compact_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::disassemble (insn->get_pc ());

  // ... Execute the insn. Catch any exceptions and pass them on later.
  enum
    {
      no_exception, cpu_memory_fault, cpu_exception, fpu_exception
    } exception = no_exception;
  sidutil::cpu_memory_fault cmf (pc, 0, sid::bus::ok, "");
  sidutil::cpu_exception ce;
  fp::error fe (0);
  try
    {
      this->execute_insn (sc);
    }
  catch (sidutil::cpu_memory_fault &e)
    {
      exception = cpu_memory_fault;
      cmf = e;
    }
  catch (sidutil::cpu_exception &e)
    {
      exception = cpu_exception;
      ce = e;
    }
  catch (fp::error &e)
    {
      exception = fpu_exception;
      fe = e;
    }

  // ... Compute the number of cycles required
  this->model_branch_taken (false);
  host_int_4 cycles = this->model.model_after (this->thisp, sc);

  // The secondary pipelines run independently, so ignore any incidental latency
  // (memory access, etc.) and count only the execution cycles.
  this->set_total_latency (insn->get_post_fetch_latency ());

  // Clean up.
  if (insn1)
    {
      // Determine whether the next insn can be handled in parallel with the current one.
      this->parallel_possible_p = (! insn2->is_sh5_media () && parallel_possible (insn1, insn2, cycles));

      // Second insn has been saved but not executed.
      if (this->parallel_possible_p)
	{
	  // NOTE: Don't call the generic model-after method, since we don't want
	  // "time" to advance before the next insn is executed.
	  // We need to know if the 2nd insn is in a delay slot.
	  if (this->model_branch_taken_p () && sc->idesc->attrs.get_delay_slot_attr ())
	    insn2->set_delay_slot (true);

	  // First insn has been executed, so clear it
	  vliw_insns[0] = 0;
	}
      else
	{
	  // Call the generic model-after method.
	  // This is what model_insn_after boils down to for this port.
	  this->model.step_cycles (cycles);

	  // Set the pc, allowing for an unprocessed delayed branch,
	  // or for a non-delayed branch.
	  PCADDR new_pc = next_pc (sc, cycles, insn2);
	  sem_status s = SEM_STATUS_NORMAL;
	  this->done_insn (new_pc, s);

	  if (this->model_branch_taken_p ())
	    {
	      // Non-delayed branch taken? Then we won't be executing the
	      // second insn.
	      if (! insn2->in_delay_slot ())
		{
		  this->model_branch_stall ();
		  vliw_insns.clear ();
		}
	      else
		{
		  // The second insn could now be the first of a pair.
		  // Adjust the latency.
		  insn2->set_post_fetch_latency (this->get_total_latency ());
		  
		  // Shift insn2 into the first position on the stack.
		  vliw_insns.erase (vliw_insns.begin ());
		}
	    }
	  else {
	    // There may be a pending branch stall
	    this->model_branch_stall ();

	    // The second insn could now be the first of a pair.
	    // Adjust the latency.
	    insn2->set_post_fetch_latency (this->get_total_latency ());

	    // Shift insn2 into the first position on the stack unless it is
	    // an sh5 media insn, in which case clear the stack.
	    if (insn2->is_sh5_media ())
	      vliw_insns.clear ();
	    else
	      vliw_insns.erase (vliw_insns.begin ());
	  }
	}
    }
  else
    {
      // Call the generic model-after method.
      // This is what model_insn_after boils down to for this port.
      this->model.step_cycles (cycles);

      // Note whether the next fetched insn will be in a delay slot.
      if (this->model_branch_taken_p () && sc->idesc->attrs.get_delay_slot_attr ())
	next_insn_in_delay_slot_p = true;
      else
	this->model_branch_stall ();

      // Second insn of pair has been handled. Clear the state.
      vliw_insns.clear ();
    }

  // This insn has been executed.
  delete insn;

  // Pass on any exception which may have occurred
  switch (exception)
    {
    case cpu_memory_fault: throw (cmf);
    case cpu_exception: throw (ce);
    case fpu_exception: throw (fe);
    }

  return model_ok;
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
PCADDR
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::next_pc (insn_info<SCACHE> *insn, PCADDR pc)
{
  // Assume 16 bit insn for now. 32 bit insns are a parallel show stopper
  // in any case.
  if (insn->in_delay_slot ())
    return this->delayed_pc;

  return pc + insn->byte_size ();
}

template <class CPU, class CGEN_CPU, class IDESC, class SCACHE, class MODEL>
PCADDR
sh_vliw_cpu<CPU,CGEN_CPU,IDESC,SCACHE,MODEL>::next_pc (SCACHE *sc, host_int_4 cycles, insn_info<SCACHE> *insn2)
{
  // Set the pc, allowing for an unprocessed delayed branch,
  // or for a non-delayed branch.
  if (this->model_branch_taken_p ())
    {
      // Delayed branch taken?
      if (sc->idesc->attrs.get_delay_slot_attr ())
	{
	  insn2->set_delay_slot (true);
	  return this->delayed_pc;
	}

      // Non-delayed branch taken?
      //      if (is_cti_insn (sc))
	return this->h_pc_get ();
    }

  // Next sequential pc
  return insn2->get_pc () + insn2->byte_size ();
}

// Explicit instantiations
template class sh_vliw_cpu<sh2a_fpu_cpu,sh2a_fpu_cpu_cgen,sh2a_fpu_idesc,sh2a_fpu_scache,
			   sh2a_fpu_model<
                             sh_common_model_with_vliw<
                                sh_common_model_with_fp<sh2a_fpu_sh2a_fpu_model,sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
                                sh2a_fpu_cpu,sh2a_fpu_idesc,sh2a_fpu_scache>,
                              sh2a_fpu_cpu,sh2a_fpu_idesc> >;
template class sh_vliw_cpu<sh2a_nofpu_cpu,sh2a_nofpu_cpu_cgen,sh2a_nofpu_idesc,sh2a_nofpu_scache,
			   sh2a_model<
                             sh_common_model_with_vliw<
                               sh_common_model<sh2a_nofpu_sh2a_nofpu_model,sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
                               sh2a_nofpu_cpu,sh2a_nofpu_idesc,sh2a_nofpu_scache>,
                             sh2a_nofpu_cpu,sh2a_nofpu_idesc> >;
template class sh_vliw_cpu<sh4_cpu,sh4_cpu_cgen,sh4_idesc,sh4_scache,sh4_fpu_model<sh4_cpu, sh4_idesc> >;
template class sh_vliw_cpu<sh4_nofpu_cpu,sh4_nofpu_cpu_cgen,sh4_nofpu_idesc,sh4_nofpu_scache,
			   sh4_model<sh2a_model<sh_common_model<sh4_nofpu_sh4_nofpu_model,sh4_nofpu_cpu,sh4_nofpu_idesc,sh4_nofpu_scache>,
						sh4_nofpu_cpu,sh4_nofpu_idesc>,
				     sh4_nofpu_cpu,sh4_nofpu_idesc> >;
template class sh_vliw_cpu<sh4a_cpu,sh4a_cpu_cgen,sh4a_idesc,sh4a_scache,sh4a_fpu_model<sh4a_cpu,sh4a_idesc> >;
template class sh_vliw_cpu<sh4a_nofpu_cpu,sh4a_nofpu_cpu_cgen,sh4a_nofpu_idesc,sh4a_nofpu_scache,
			   sh4a_model<sh2a_model<sh_common_model<sh4a_nofpu_sh4a_nofpu_model,sh4a_nofpu_cpu,sh4a_nofpu_idesc,sh4a_nofpu_scache>,
						 sh4a_nofpu_cpu,sh4a_nofpu_idesc>,
				      sh4a_nofpu_cpu,sh4a_nofpu_idesc> >;
template class sh_vliw_cpu<sh4al_cpu,sh4al_cpu_cgen,sh4al_idesc,sh4al_scache,sh4al_model>;
template class sh_vliw_cpu<sh5_cpu,sh5_cpu_cgen,sh5_compact_idesc,sh5_compact_scache,sh_common_model_with_fp<sh5_compact_sh5_model,sh5_cpu,sh5_compact_idesc,sh5_compact_scache> >;
