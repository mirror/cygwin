2006-03-23  Daniel Jacobowitz  <dan@codesourcery.com>

	* README.gdb: New file.

2006-02-28  Daniel Jacobowitz  <dan@codesourcery.com>

	* Makefile.in (INTERNAL_CFLAGS): New.
	(CFLAGS): Move bits to INTERNAL_CFLAGS.
	(COMPILE, CXXCOMPILE): Use INTERNAL_CFLAGS.
