// fmax-cpu.h - Hand-written code for the Toshiba FMAX coprocessor. -*- C++ -*-

// Copyright (C) 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// This file is included in the middle of the cpu class struct.

public:
// CGEN won't assign SF to SI and vice versa, so do it here
  inline SF fmax_fr_get_handler (UINT regno) const { return this->h_cr_get (regno); }
  inline void fmax_fr_set_handler (UINT regno, SF newval) { this->h_cr_set (regno, newval); }

  static const SI FMAX_E_MASK = 0x20;
  static const SI FMAX_V_MASK = 0x10;
  static const SI FMAX_Z_MASK = 0x08;
  static const SI FMAX_O_MASK = 0x04;
  static const SI FMAX_U_MASK = 0x02;
  static const SI FMAX_I_MASK = 0x01;

  static const unsigned FMAX_CERR = 15;

  // Generated a reserved-operation_exception
  void fmax_reserved_operation_exception (PCADDR pc)
  {
    fmax_record_exception (FMAX_E_MASK);
    throw fp::error (fp::denorm); // any status except fp::ok
  }

  bool fmax_record_exception (int mask)
  {
    SI cerr = hardware.h_ccr[FMAX_CERR];
    mask &= 0x3f;

    // CAUSE bit gets set if ENABLE bit is set. Other CAUSE
    // bits are cleared. Reserved exception (0x20 cannot be masked).
    bool exception;
    int detected = ((cerr >> 16) | 0x20) & mask;
    if (detected)
      {
	cerr &= ~(0x3f << 24);
	cerr |= detected << 24;
	exception = true;
      }
    else
      exception = false;

    // FLAG bits always get set. Other FLAG bits retain their
    // values. There is no E bit (0x20) in FLAGS.
    cerr |= (mask & 0x1f) << 8;

    hardware.h_ccr[FMAX_CERR] = cerr;
    return exception;
  }
