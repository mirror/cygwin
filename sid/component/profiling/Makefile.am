## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libprof.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libprof_la_SOURCES = gprof.cxx
libprof_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = sw-profile-gprof.txt

DEJAGNUTESTS=runprof.exp
checkme:
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

