## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

SUBDIRS = @subdirs@

pkglib_LTLIBRARIES = libconfig.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include -I$(srcdir)/libltdl
AM_CXXFLAGS = -DSID_EXEC_PREFIX=\"$(exec_prefix)\"

libconfig_la_SOURCES = compConfig.cxx
libconfig_la_LDFLAGS = -module -no-undefined
libconfig_la_LIBADD = @LIBLTDL@

pkgdata_DATA = sid-control-cfgroot.txt

DEJAGNUTESTS=badconf.exp
checkme: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
