## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libparport.la

pkgdata_DATA = hw-parport-ps_2.txt

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libparport_la_SOURCES = ps2.h ps2.cxx
libparport_la_LDFLAGS = -module -no-undefined

DEJAGNUTESTS = parport.exp parportdocs.exp parmonkey.exp
checkme:
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
