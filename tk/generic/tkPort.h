/*
 * tkPort.h --
 *
 *	This header file handles porting issues that occur because of
 *	differences between systems.  It reads in platform specific
 *	portability files.
 *
 * Copyright (c) 1995 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id: tkPort.h,v 1.7.6.1 2000/05/04 21:26:24 spolk Exp $
 */

#ifndef _TKPORT
#define _TKPORT

#ifndef _TK
#include "tk.h"
#endif
#ifndef _TCL
#include "tcl.h"
#endif

#if defined(__WIN32__) || defined(_WIN32)
#   include "tkWinPort.h"
#else
#   if defined(MAC_TCL)
#	include "tkMacPort.h"
#   else
#	include "../unix/tkUnixPort.h"
#   endif
#endif

#endif /* _TKPORT */

