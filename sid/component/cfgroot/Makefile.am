## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config -I ../../.. -I libltdl

SUBDIRS = @subdirs@

pkglib_LTLIBRARIES = libconfig.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include -I$(srcdir)/libltdl

libconfig_la_SOURCES = compConfig.cxx
libconfig_la_LDFLAGS = -module -no-undefined
libconfig_la_LIBADD = @LIBLTDL@
libconfig_la_DEPENDENCIES = @LIBLTDL@

pkgdata_DATA = sid-control-cfgroot.txt sid-control-dynamic-configurator.txt

DEJAGNUTESTS=badconf.exp
check-local: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

html_stylesheet=$(srcdir)/../component_html.xsl
include $(srcdir)/../../config/Makefile.docs
