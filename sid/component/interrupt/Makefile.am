## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libinterrupt.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libinterrupt_la_SOURCES = arm.cxx cma222.cxx components.cxx

libinterrupt_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = hw-interrupt-arm_ref.txt hw-interrupt-cogent_cma222.txt

DEJAGNUTESTS=arm-interrupt.exp cma222-interrupt.exp interruptdocs.exp interruptmonkey.exp
checkme: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
