## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libm32r.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-m32r_d.txt

libm32r_la_SOURCES = m32rbf.cxx \
	m32r-decode.cxx m32r-sem.cxx
libm32r_la_LDFLAGS =
libm32r_la_LIBADD = m32r-asm.lo m32r-dis.lo m32r-opc.lo m32r-ibld.lo m32r-desc.lo

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../../opcodes \
	-I../../../../bfd \
	-I../../../../intl \
	-I$(srcdir)/../../../../opcodes \
	-I$(srcdir)/../../../../include \
	-I$(srcdir)/../../../../bfd     \
	-I$(srcdir)/../../../../intl    \
	-D_GNU_SOURCE 

m32r-asm.lo: ../../../../opcodes/m32r-asm.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

m32r-dis.lo: ../../../../opcodes/m32r-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

m32r-opc.lo: ../../../../opcodes/m32r-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

m32r-ibld.lo: ../../../../opcodes/m32r-ibld.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

m32r-desc.lo: ../../../../opcodes/m32r-desc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

DEJAGNUTESTS = m32rbsp.exp
check-local: all
	(cd ../../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

cgendir = $(srcdir)/../../../../cgen
cpudir = $(srcdir)/../../../../cpu
CGENFLAGS = -v

CGEN_ALL = cgen-m32r
.PHONY: cgen-all $(CGEN_ALL)
cgen-all: $(CGEN_ALL)

cgen-m32r:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	m32r "with-scache" m32rbf m32r m32r m32rbf "m32r-" \
	$(cpudir)/m32r.cpu \
	"desc.h cpu.h decode.h decode.cxx semantics.cxx write.cxx defs.h"

html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
