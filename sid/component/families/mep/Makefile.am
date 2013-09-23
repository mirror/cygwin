## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

pkglib_LTLIBRARIES = libmepfamily.la

INCLUDES = -I. -I../.. -I../../../include -I$(srcdir)/../../../include -I$(srcdir)/toshapi

TOSHAPI_SOURCES =

libmepfamily_la_SOURCES = dsu.cxx dmac.cxx intc.cxx components.cxx \
			  mm_int.cxx timer.cxx gbif.cxx lbif.cxx gbmif.cxx toshapi.cxx $(TOSHAPI_SOURCES)

libmepfamily_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-debug-mep.txt hw-dma-mep.txt hw-interrupt-mep.txt

DEJAGNUTESTS=mep-interrupt.exp mep-dsu.exp mep-dmac.exp mep-timer.exp
check-local: all
	(cd ../../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
