## Process this with automake to create Makefile.in

## FIXME: Work around apparent bug in automake.
INTLLIBS = @INTLLIBS@

AUTOMAKE_OPTIONS = foreign
SUBDIRS = @cpu_subdirs@ .
ACLOCAL_AMFLAGS = -I $(srcdir)/../../config

pkglib_LTLIBRARIES = libcgencpu.la

INCLUDESBFD = -I../../../bfd -I$(srcdir)/../../../include
INCLUDES = -I. -I.. @cpu_incl@ -I../../include -I$(srcdir)/../../include $(INCLUDESBFD)

CXXFLAGS=
TOP_CXXFLAGS=$(CXXFLAGS)
AM_CXXFLAGS=$(TOP_CXXFLAGS)
AM_MAKEFLAGS= "TOP_CXXFLAGS=$(TOP_CXXFLAGS)"
MAKEOVERRIDES=

OPCODES = ../../../opcodes/libopcodes.la
LIBIBERTY = -L../../../libiberty -liberty
TRACEDIS = tracedis.c

libcgencpu_la_SOURCES = compCGEN.cxx $(TRACEDIS)
libcgencpu_la_LDFLAGS = -module -no-undefined
libcgencpu_la_LIBADD = @cpu_libs@ $(OPCODES) $(INTLLIBS) $(LIBIBERTY)
libcgencpu_la_DEPENDENCIES = @cpu_libs@

DEJAGNUTESTS = cpumonkey.exp dhrystone.exp
check-local: all
	-(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
	for subdir in @cpu_subdirs@; do \
		(cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) check); \
	done

.PHONY: cgen-all
cgen-all:
	for subdir in @cpu_subdirs@; do \
		(cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) cgen-all); \
	done

