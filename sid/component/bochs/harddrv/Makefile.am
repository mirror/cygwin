## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libharddrv.la

libharddrv_la_SOURCES = sid-harddrv-wrapper.cc sid-harddrv-wrapper.h harddrv.cc harddrv.h

libharddrv_la_LDFLAGS = -no-undefined
