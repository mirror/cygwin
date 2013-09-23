## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libxstormy16.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-xstormy16.txt

libxstormy16_la_SOURCES = xstormy16.cxx xstormy16-decode.cxx xstormy16-sem.cxx
libxstormy16_la_LDFLAGS =
libxstormy16_la_LIBADD = xstormy16-asm.lo xstormy16-dis.lo xstormy16-opc.lo xstormy16-ibld.lo xstormy16-desc.lo

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../../opcodes \
	-I../../../../bfd \
	-I../../../../intl \
	-I$(srcdir)/../../../../opcodes \
	-I$(srcdir)/../../../../include \
	-I$(srcdir)/../../../../bfd     \
	-I$(srcdir)/../../../../intl    \
	-D_GNU_SOURCE 

xstormy16-asm.lo: ../../../../opcodes/xstormy16-asm.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

xstormy16-dis.lo: ../../../../opcodes/xstormy16-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

xstormy16-opc.lo: ../../../../opcodes/xstormy16-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

xstormy16-ibld.lo: ../../../../opcodes/xstormy16-ibld.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

xstormy16-desc.lo: ../../../../opcodes/xstormy16-desc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<


cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGEN_ALL = cgen-xstormy16
.PHONY: cgen-all $(CGEN_ALL)

cgen-all: $(CGEN_ALL)

cgen-xstormy16:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	xstormy16 "with-scache" xstormy16 xstormy16 xstormy16 xstormy16 "xstormy16-" \
	$(cgendir)/cpu/xstormy16.cpu \
	"desc.h cpu.h defs.h decode.h decode.cxx semantics.cxx"
