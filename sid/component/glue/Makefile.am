## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libglue.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libglue_la_SOURCES = glue.cxx
libglue_la_LDFLAGS = -module -no-undefined

DEJAGNUTESTS=attribbank.exp attribinval.exp attribval.exp \
seqinval.exp sequence.exp sequence1.exp sequence2.exp sequence8.exp \
seqvalid.exp gluemonkey.exp traffic.exp

pkgdata_DATA = hw-glue-sequence.txt hw-glue-probe-bus.txt sw-glue-attribbank.txt

checkme:
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

