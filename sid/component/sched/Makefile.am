## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libsched.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libsched_la_SOURCES = compSched.cxx
libsched_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = sid-visual-sched.tk sid-sched.txt

DEJAGNUTESTS=schedbase.exp schedhost.exp schedhost2.exp schedmonkey.exp
check-local: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

html_stylesheet=$(srcdir)/../component_html.xsl
include $(srcdir)/../../config/Makefile.docs
