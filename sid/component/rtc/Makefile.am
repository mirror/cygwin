## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = librtc.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
librtc_la_SOURCES = ds1x42.cxx components.cxx sidrtc.cxx
librtc_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-visual-clock.tk hw-visual-clock.txt hw-rtc-ds1x42.txt hw-rtc-sid.txt

DEJAGNUTESTS=ds1642.exp ds1742.exp rtcmonkey.exp rtcdocs.exp
checkme: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
