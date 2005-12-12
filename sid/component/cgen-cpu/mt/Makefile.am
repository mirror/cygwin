## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I $(srcdir)/../../../config

noinst_LTLIBRARIES = libms1.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-ms1.txt

libms1_la_SOURCES = ms1.cxx ms1-decode.cxx ms1-sem.cxx ms1-write.cxx
libms1_la_LDFLAGS =
libms1_la_LIBADD = ms1-asm.lo ms1-dis.lo ms1-opc.lo ms1-ibld.lo ms1-desc.lo

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../../opcodes \
	-I../../../../bfd \
	-I../../../../intl \
	-I$(srcdir)/../../../../opcodes \
	-I$(srcdir)/../../../../include \
	-I$(srcdir)/../../../../bfd     \
	-I$(srcdir)/../../../../intl    \
	-D_GNU_SOURCE 

ms1-asm.lo: ../../../../opcodes/ms1-asm.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

ms1-dis.lo: ../../../../opcodes/ms1-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

ms1-opc.lo: ../../../../opcodes/ms1-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

ms1-ibld.lo: ../../../../opcodes/ms1-ibld.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

ms1-desc.lo: ../../../../opcodes/ms1-desc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGEN_ALL = cgen-ms1
.PHONY: cgen-all $(CGEN_ALL)
cgen-all: $(CGEN_ALL)

cgen-ms1:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	ms1 "with-scache" ms1 ms1 ms1-003 ms1 "ms1-" \
	$(srcdir)/../../../../cpu/ms1.cpu \
	"desc.h cpu.h decode.h decode.cxx write.cxx semantics.cxx defs.h"

html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
