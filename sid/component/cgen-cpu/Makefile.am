## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
SUBDIRS = @cpu_subdirs@ .
ACLOCAL_AMFLAGS = -I ../../config

pkglib_LTLIBRARIES = libcgencpu.la

INCLUDES = -I. -I.. @cpu_incl@ -I../../include -I$(srcdir)/../../include

CXXFLAGS=
TOP_CXXFLAGS=$(CXXFLAGS)
AM_CXXFLAGS=$(TOP_CXXFLAGS)
AM_MAKEFLAGS= "TOP_CXXFLAGS=$(TOP_CXXFLAGS)"
MAKEOVERRIDES=

libcgencpu_la_SOURCES = compCGEN.cxx 
libcgencpu_la_LDFLAGS = -module -no-undefined
libcgencpu_la_LIBADD = @cpu_libs@
libcgencpu_la_DEPENDENCIES = @cpu_libs@

DEJAGNUTESTS = cpumonkey.exp dhrystone.exp
.PHONY: checkme
checkme:
	-(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
	for subdir in @cpu_subdirs@; do \
		( cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) checkme ); \
	done

.PHONY: cgen-all
cgen-all:
	for subdir in @cpu_subdirs@; do \
		( cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) cgen-all ); \
	done

