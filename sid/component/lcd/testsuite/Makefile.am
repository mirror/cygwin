## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

noinst_LTLIBRARIES = libt6963c-test.la libt6963c-japan.la libhd-two-line.la libhd-one-line.la libhd-5X10.la libhd-europe.la

INCLUDES = -I. -I../../../include -I$(srcdir)/../../../include -I$(srcdir)/..

all-local:
	cp $(srcdir)/hd-one-line.conf .
	cp $(srcdir)/hd-two-line.conf .
	cp $(srcdir)/hd-5X10.conf .
	cp $(srcdir)/hd-europe.conf .
	cp $(srcdir)/t6963c-tcl.conf .
	cp $(srcdir)/t6963c-japan.conf .

libt6963c_test_la_SOURCES = t6963c-tester.cxx
libt6963c_test_la_LDFLAGS = -rpath `pwd` -module -no-undefined

libt6963c_japan_la_SOURCES = t6963c-japan.cxx
libt6963c_japan_la_LDFLAGS = -rpath `pwd` -module -no-undefined

libhd_two_line_la_SOURCES = hd-two-line.cxx hd-tester.cxx
libhd_two_line_la_LDFLAGS = -rpath `pwd` -module -no-undefined

libhd_one_line_la_SOURCES = hd-one-line.cxx hd-tester.cxx
libhd_one_line_la_LDFLAGS = -rpath `pwd` -module -no-undefined

libhd_5X10_la_SOURCES = hd-5X10.cxx hd-tester.cxx
libhd_5X10_la_LDFLAGS = -rpath `pwd` -module -no-undefined

libhd_europe_la_SOURCES = hd-europe.cxx hd-tester.cxx
libhd_europe_la_LDFLAGS = -rpath `pwd` -module -no-undefined

