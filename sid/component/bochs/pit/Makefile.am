## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libpit.la

libpit_la_SOURCES = sid-pit-wrapper.cc sid-pit-wrapper.h pit.cc pit.h

libpit_la_LDFLAGS = -no-undefined
