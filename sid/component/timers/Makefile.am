## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
SUBDIRS = @cpu_subdirs@ .
ACLOCAL_AMFLAGS = -I ../../config

pkglib_LTLIBRARIES = libtimers.la

INCLUDES = -I. -I.. @cpu_incl@ -I../../include -I$(srcdir)/../../include

libtimers_la_SOURCES = compTIMERS.cxx
libtimers_la_LDFLAGS = -module -no-undefined
libtimers_la_LIBADD = @cpu_libs@
libtimers_la_DEPENDENCIES = @cpu_libs@

DEJAGNUTESTS=timerbase.exp timersched.exp timermonkey.exp

.PHONY: checkme
checkme:
	-(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
