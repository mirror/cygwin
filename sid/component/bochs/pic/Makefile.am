## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libpic.la

libpic_la_SOURCES = sid-pic-wrapper.cc sid-pic-wrapper.h pic.cc pic.h

libpic_la_LDFLAGS = -no-undefined
