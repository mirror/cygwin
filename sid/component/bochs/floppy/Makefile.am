## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libfloppy.la

libfloppy_la_SOURCES = sid-floppy-wrapper.cc sid-floppy-wrapper.h floppy.cc floppy.h

libfloppy_la_LDFLAGS = -no-undefined
