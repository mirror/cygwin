## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

pkglib_LTLIBRARIES = libx86.la

if SIDTARGET_X86
SUBDIRLIST = fpu cpu memory .
SUBLIBLIST = fpu/libfpu.la cpu/libcpu.la memory/libmemory.la 
else
SUBDIRLIST =
SUBLIBLIST =
endif

SUBDIRS = $(SUBDIRLIST)

INCLUDES = -I$(top_builddir)/.. -I$(top_builddir)/../../include -I$(srcdir)/../../include -I$(srcdir)/cpu -I$(srcdir)/memory

libx86_la_SOURCES = components.cxx
libx86_la_LDFLAGS = -module -no-undefined
libx86_la_LIBADD = $(SUBLIBLIST)
libx86_la_DEPENDENCIES = $(SUBLIBLIST)

AUTOHEADER = echo "Not running autoheader"

