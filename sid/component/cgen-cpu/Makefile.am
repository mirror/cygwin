## Process this with automake to create Makefile.in

## FIXME: Work around apparent bug in automake.
INTLLIBS = @INTLLIBS@

AUTOMAKE_OPTIONS = foreign
SUBDIRS = @cpu_subdirs@ .
ACLOCAL_AMFLAGS = -I ../../config -I ../../..

pkglib_LTLIBRARIES = libcgencpu.la

INCLUDESBFD = -I../../../bfd -I$(srcdir)/../../../include
INCLUDES = -I. -I.. @cpu_incl@ -I../../include -I$(srcdir)/../../include $(INCLUDESBFD)

CXXFLAGS=@cpu_defs@
TOP_CXXFLAGS=$(CXXFLAGS)
AM_CXXFLAGS=$(TOP_CXXFLAGS)
AM_MAKEFLAGS= "TOP_CXXFLAGS=$(TOP_CXXFLAGS)"
MAKEOVERRIDES=

LIBIBERTY = -L../../../libiberty/pic -L../../../libiberty -liberty

libcgencpu_la_SOURCES = compCGEN.cxx cgen-fpu.cxx fp.cxx tracedis.cxx
libcgencpu_la_LDFLAGS = -module -no-undefined
libcgencpu_la_LIBADD = @cpu_libs@ $(INTLLIBS) $(LIBIBERTY) cgen-asm.lo cgen-dis.lo cgen-opc.lo dis-buf.lo dis-init.lo cgen-bitset.lo
libcgencpu_la_DEPENDENCIES = @cpu_libs@ cgen-asm.lo cgen-dis.lo cgen-opc.lo dis-buf.lo dis-init.lo cgen-bitset.lo

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../opcodes \
	-I../../../bfd \
	-I../../../intl \
	-I$(srcdir)/../../../opcodes \
	-I$(srcdir)/../../../include \
	-I$(srcdir)/../../../bfd     \
	-I$(srcdir)/../../../intl    \
	-D_GNU_SOURCE 

cgen-asm.lo: ../../../opcodes/cgen-asm.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

cgen-dis.lo: ../../../opcodes/cgen-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

cgen-opc.lo: ../../../opcodes/cgen-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

dis-buf.lo: ../../../opcodes/dis-buf.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

dis-init.lo: ../../../opcodes/dis-init.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

cgen-bitset.lo: ../../../opcodes/cgen-bitset.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

DEJAGNUTESTS = cpumonkey.exp dhrystone.exp
check-local: all
	-(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
	for subdir in @cpu_subdirs@; do \
		(cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) check); \
	done

.PHONY: cgen-all
cgen-all:
	for subdir in @cpu_subdirs@; do \
		(cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) cgen-all) || exit 1 ; \
	done

