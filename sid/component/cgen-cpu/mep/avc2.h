// avc2.h - Hand-written code for the Toshiba AVC2 coprocessor. -*- C++ -*-

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
	case 0: // csar
	  writemask = 0x0000003f;
	  break;
	case 1: //cbcr
	  writemask = 0x00000001;
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
