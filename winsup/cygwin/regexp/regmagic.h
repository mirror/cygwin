/*	$Id: regmagic.h,v 1.1 1997/10/07 21:54:10 noer Exp $ */

/*
 * The first byte of the regexp internal "program" is actually this magic
 * number; the start node begins in the second byte.
 */
#define	MAGIC	0234
