## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libide.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libide_la_SOURCES = compIDE.cxx
libide_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-disk-ide.txt

DEJAGNUTESTS = diskio.exp idebase.exp idedocs.exp idetrigger.exp
checkme:
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

