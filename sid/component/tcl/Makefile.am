## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config -I ../../..

pkglib_LTLIBRARIES = libtclapi.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include $(EXTRA_INCLUDES)

pkgdata_DATA = sid-control-tksm.tk hw-visual-probe-bus.blt bridge-tcl.tcl bridge-tk.tk bridge-blt.blt bridge-tcl.txt sid-api-trace.tcl hw-visual-probe-pin.tk
noinst_DATA = tester.tcl

libtclapi_la_SOURCES = compTcl.cxx
libtclapi_la_LDFLAGS = -module -no-undefined

html_stylesheet=$(srcdir)/../component_html.xsl
include $(srcdir)/../../config/Makefile.docs
