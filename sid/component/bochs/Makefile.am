## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

pkglib_LTLIBRARIES = libx86.la

if SIDTARGET_X86
SUBDIRLIST = vga gui keyboard fpu cpu memory .
SUBLIBLIST = vga/libvga.la gui/libgui.la keyboard/libkeyboard.la fpu/libfpu.la cpu/libcpu.la memory/libmemory.la 
else
SUBDIRLIST =
SUBLIBLIST =
endif

SUBDIRS = $(SUBDIRLIST)

INCLUDES = -I$(top_builddir)/.. -I$(top_builddir)/../../include -I$(srcdir)/../../include -I$(srcdir)/vga -I$(srcdir)/gui -I$(srcdir)/keyboard -I$(srcdir)/cpu -I$(srcdir)/memory -I$(srcdir)/../memory

libx86_la_SOURCES = components.cxx
libx86_la_LDFLAGS = -module -no-undefined
libx86_la_LIBADD = $(SUBLIBLIST)
libx86_la_DEPENDENCIES = $(SUBLIBLIST)

AUTOHEADER = echo "Not running autoheader"

