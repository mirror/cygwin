## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libcmos.la

libcmos_la_SOURCES = sid-cmos-wrapper.cc sid-cmos-wrapper.h cmos.cc cmos.h

libcmos_la_LDFLAGS = -no-undefined
