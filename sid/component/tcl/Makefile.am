## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

pkglib_LTLIBRARIES = libtclapi.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
AM_CXXFLAGS = -DSID_EXEC_PREFIX=\"$(exec_prefix)\"

pkgdata_DATA = sid-control-tksm.tk hw-visual-probe-bus.blt bridge-tcl.tcl bridge-tk.tk bridge-blt.blt bridge-tcl.txt sid-api-trace.tcl
noinst_DATA = tester.tcl

libtclapi_la_SOURCES = compTcl.cxx
libtclapi_la_LDFLAGS = -module -no-undefined
