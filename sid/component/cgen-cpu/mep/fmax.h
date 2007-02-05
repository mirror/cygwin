// fmax.h - Hand-written code for the Toshiba FMAX coprocessor. -*- C++ -*-

// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// This file is included in the middle of the mep_ext<n>_cpu class struct.

public:
  virtual VOID cgen_set_ccr_value (SI regno, SI newval)
    {
      SI writemask;
      switch (regno)
	{
	case 0: // cirr
	  writemask = 0x00000000;
	  break;
	case 1: //cbcr
	  writemask = 0x00000001;
	  break;
	case 15: //cerr
	  writemask = 0x001f1f03;
	  break;
	default:
	  writemask = 0xffffffff;
	  break;
	}

      SI result = (this->hardware.h_ccr[regno] & ~writemask)
	| (newval & writemask);

      if (UNLIKELY(this->trace_result_p))
	{
	  if (result != newval)
	    this->trace_stream << "(0x" << hex << result << dec << ")  ";
	}

      this->hardware.h_ccr[regno] = result;
    }

  SI fmax_froundws (SF x)
     {
       fmax_fp f;
       f = x;
       fpu.mep_ops->check_operand (& fpu, f);
       SI result = 0;
       try {
	 f.integer (result, fp::round_near);
       }
       catch (fp::error &e) {
	 fpu.mep_ops->check_result (& fpu, f);
       }
       return result;
     }

  SI fmax_ftruncws (SF x)
    {
       fmax_fp f;
       f = x;
       fpu.mep_ops->check_operand (& fpu, f);
       SI result = 0;
       try {
	 f.integer (result, fp::round_zero);
       }
       catch (fp::error &e) {
	 fpu.mep_ops->check_result (& fpu, f);
       }
       return result;
    }

  SI fmax_fceilws (SF x)
    {
       fmax_fp f;
       f = x;
       fpu.mep_ops->check_operand (& fpu, f);
       SI result = 0;
       try {
	 f.integer (result, fp::round_up);
       }
       catch (fp::error &e) {
	 fpu.mep_ops->check_result (& fpu, f);
       }
       return result;
    }

  SI fmax_ffloorws (SF x)
    {
       fmax_fp f;
       f = x;
       fpu.mep_ops->check_operand (& fpu, f);
       SI result = 0;
       try {
	 f.integer (result, fp::round_down);
       }
       catch (fp::error &e) {
	 fpu.mep_ops->check_result (& fpu, f);
       }
       return result;
    }

  SI fmax_fcvtws (SF x)
    {
      SI cerr = this->hardware.h_ccr[15];
      switch (cerr & 0x3)
	{
	case 0:
	  return fmax_froundws (x);
	case 1:
	  return fmax_ftruncws (x);
	case 2:
	  return fmax_fceilws (x);
	case 3:
	  return fmax_ffloorws (x);
	default:
	  break; // can't happen
	}
    }

  // Issue a cop_exception
  virtual PCADDR fpu_exception (PCADDR pc, int &status)
  {
    if (UNLIKELY(trace_result_p))
      trace_stream << "cerr:=0x" << hex << hardware.h_ccr[FMAX_CERR] << dec << "  ";
    this->hardware.h_fmax_compare_i_p = 0;
    pc = cop_exception (pc);
    return pc;
  }

  virtual void invalid_insn (PCADDR pc)
  {
    host_int_2 insn = this->GETIMEMHI (pc, pc);
    if ((insn & 0xf00f) == 0xf007)
      {
	bool exception = fmax_record_exception (FMAX_E_MASK);
	if (exception)
	  throw fp::error (1); // any status will do
      }

    // No cop exception? Do the normal processing
    mep_cpu::invalid_insn (pc);
  }
