## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../.. -I$(srcdir)/../../../../include

noinst_LTLIBRARIES = libmemory.la

libmemory_la_SOURCES = sid-bochs-memory.cc sid-bochs-memory.cc

libmemory_la_LDFLAGS = -no-undefined
