## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

SUBDIRS = . testsuite

pkglib_LTLIBRARIES = libmapper.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libmapper_la_SOURCES = compMapper.cxx
libmapper_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-mapper-basic.txt

DEJAGNUTESTS=basicmapper.exp mapperdocs.exp mappermonkey.exp
checkme: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
