## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libmemory.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
noinst_HEADERS = generic.h ramrom.h flash.h at29.h
libmemory_la_SOURCES = components.cxx generic.cxx ramrom.cxx flash.cxx \
                       at29.cxx am29.cxx
libmemory_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-memory-ram_rom-basic.txt hw-memory-flash-am29.txt hw-memory-flash-at29.txt

DEJAGNUTESTS = am29.exp at29.exp at29xx.exp at29inv.exp at29val.exp genericmemory.exp memdocs.exp memmonkey.exp
checkme: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
