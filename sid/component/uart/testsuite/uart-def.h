// uart-def.h - UART interface stuff.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef UART_DEF_DEF_H
#define UART_DEF_DEF_H	1

enum uart_addr {	// UART register offsets
  UART_RXB	= 0,    // read-only
  UART_THR	= 0,    // write-only
  UART_DIVL	= 0,    // when DLAB = 1
  UART_DIVM	= 1,    // when DLAB = 1
  UART_IER	= 1,	// when DLAB = 0
  UART_IIR	= 2,	// INTR id, read-only
  UART_FCR	= 2,	// INTR id, write-only
  UART_LCR	= 3,	// Line control
  UART_MCR	= 4,	// Modem control
  UART_LSR	= 5,	// Line status
  UART_MSR	= 6,	// Modem status
  UART_SCRATCH  = 7
};

#define UART_ADDRESS	0xa0000

#endif // UART_DEF_DEF_H
