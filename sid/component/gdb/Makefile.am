## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libgdb.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include

libgdb_la_SOURCES = gdb.cxx \
	gdbserv-input.c gdbserv-output.c gdbserv-state.c gdbserv-utils.c 

libgdb_la_LDFLAGS = -module -no-undefined


