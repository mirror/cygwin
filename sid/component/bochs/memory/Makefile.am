## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

##         sid/include in build tree       bochs/cpu   component/bochs sid/include in src tree     bochs/memory
INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libmemory.la

libmemory_la_SOURCES = memory.cc memory-sid.cc misc_mem.cc memory.h memory-sid.h

libmemory_la_LDFLAGS = -no-undefined
