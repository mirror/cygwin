## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I. -I../../../include -I$(srcdir)/../../../include -I$(srcdir)/..

noinst_LTLIBRARIES = libbusif.la

libbusif_la_SOURCES = busif.cxx
libbusif_la_LDFLAGS = -rpath $(VPATH) -module -no-undefined

