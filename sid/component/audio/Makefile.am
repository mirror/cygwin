## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config -I ../../..

pkglib_LTLIBRARIES = libaudio.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
AM_CXXFLAGS = -DSID_EXEC_PREFIX=\"$(exec_prefix)\"

pkgdata_DATA = 
noinst_DATA = 

libaudio_la_SOURCES = components.cxx compCodec.cxx compAudio.cxx
libaudio_la_LDFLAGS = -module -no-undefined


DEJAGNUTESTS = linusraw.exp linuscodec.exp aumonkey.exp
check-local: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
