## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libinterrupt.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include

libinterrupt_la_SOURCES = arm.h arm.cxx cma222.h cma222.cxx \
			  components.h components.cxx
libinterrupt_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-interrupt-arm_ref.txt hw-interrupt-cogent_cma222.txt

DEJAGNUTESTS=arm-interrupt.exp cma222-interrupt.exp interruptdocs.exp interruptmonkey.exp
check-local: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)")

html_stylesheet=$(srcdir)/../component_html.xsl
include $(srcdir)/../../config/Makefile.docs
