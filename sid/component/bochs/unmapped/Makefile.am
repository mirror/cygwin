## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libunmapped.la

libunmapped_la_SOURCES = sid-unmapped-wrapper.cc sid-unmapped-wrapper.h unmapped.cc unmapped.h

libunmapped_la_LDFLAGS = -no-undefined
