## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libmt.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-mt.txt

libmt_la_SOURCES = mt.cxx mt-decode.cxx mt-sem.cxx mt-write.cxx
libmt_la_LDFLAGS =
libmt_la_LIBADD = mt-asm.lo mt-dis.lo mt-opc.lo mt-ibld.lo mt-desc.lo

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../../opcodes \
	-I../../../../bfd \
	-I../../../../intl \
	-I$(srcdir)/../../../../opcodes \
	-I$(srcdir)/../../../../include \
	-I$(srcdir)/../../../../bfd     \
	-I$(srcdir)/../../../../intl    \
	-D_GNU_SOURCE 

mt-asm.lo: ../../../../opcodes/mt-asm.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mt-dis.lo: ../../../../opcodes/mt-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mt-opc.lo: ../../../../opcodes/mt-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mt-ibld.lo: ../../../../opcodes/mt-ibld.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mt-desc.lo: ../../../../opcodes/mt-desc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGEN_ALL = cgen-mt
.PHONY: cgen-all $(CGEN_ALL)
cgen-all: $(CGEN_ALL)

cgen-mt:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mt "with-scache" mt mt ms1-003 mt "mt-" \
	$(srcdir)/../../../../cpu/mt.cpu \
	"desc.h cpu.h decode.h decode.cxx write.cxx semantics.cxx defs.h"

html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
