## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libmep.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS) -DHAVE_CONFIG_H

pkgdata_DATA = hw-cpu-mep.txt

CPU_SOURCES = mep-core1-decode.cxx mep-core1-sem.cxx mep-core1-model.cxx mep-cop1-16-decode.cxx mep-cop1-16-sem.cxx mep-cop1-16-model.cxx mep-cop1-32-decode.cxx mep-cop1-32-sem.cxx mep-cop1-32-model.cxx mep-cop1-48-decode.cxx mep-cop1-48-sem.cxx mep-cop1-48-model.cxx mep-cop1-64-decode.cxx mep-cop1-64-sem.cxx mep-cop1-64-model.cxx ivc2-cop.cxx

libmep_la_SOURCES = mep.cxx common_model.cxx mep-decode.cxx mep-sem.cxx mep-model.cxx $(CPU_SOURCES)
libmep_la_LDFLAGS =
libmep_la_LIBADD = mep-asm.lo mep-dis.lo mep-opc.lo mep-ibld.lo mep-desc.lo

CGEN_MACH = c5

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../../opcodes \
	-I../../../../bfd \
	-I../../../../intl \
	-I$(srcdir)/../../../../opcodes \
	-I$(srcdir)/../../../../include \
	-I$(srcdir)/../../../../bfd     \
	-I$(srcdir)/../../../../intl    \
	-D_GNU_SOURCE 

mep-asm.lo: ../../../../opcodes/mep-asm.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mep-dis.lo: ../../../../opcodes/mep-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mep-opc.lo: ../../../../opcodes/mep-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mep-ibld.lo: ../../../../opcodes/mep-ibld.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

mep-desc.lo: ../../../../opcodes/mep-desc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

DEJAGNUTESTS = mep-allinsn.exp mep-arch.exp
.PHONY: check-local
check-local:
	(cd ../../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)")

cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGENDEPS = ../../../../cgen/stamp-cgen \
        $(cgendir)/sim-arch.scm  $(cgendir)/sim-decode.scm \
        $(cgendir)/sim-test.scm  $(cgendir)/sim-cpu.scm \
        $(cgendir)/sim-model.scm $(cgendir)/sim.scm

CPU_TARGETS = mep-core1 mep-cop1-16 mep-cop1-32 mep-cop1-48 mep-cop1-64

CPU_LIST = mep,ext_core1,ext_cop1_16,ext_cop1_32,ext_cop1_48,ext_cop1_64

CGEN_TARGETS = mep-cpudesc mep-decsemdefs $(CPU_TARGETS)
.PHONY: $(CGEN_TARGETS)

.PHONY: cgen-all
cgen-all: $(CGEN_TARGETS)

# begin-cpus
mep-core1:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache with-profile=fn" mep_ext1 ext_core1 $(CGEN_MACH) mepcore1 "mep-core1-" \
	$(cgendir)/cpu/mep.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h"
mep-cop1-16:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache with-profile=fn" mep_ext1 ext_cop1_16 $(CGEN_MACH) mepcop1_16 "mep-cop1-16-" \
	$(cgendir)/cpu/mep.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h"
mep-cop1-32:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache with-profile=fn" mep_ext1 ext_cop1_32 $(CGEN_MACH) mepcop1_32 "mep-cop1-32-" \
	$(cgendir)/cpu/mep.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h"
mep-cop1-48:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache with-profile=fn" mep_ext1 ext_cop1_48 $(CGEN_MACH) mepcop1_48 "mep-cop1-48-" \
	$(cgendir)/cpu/mep.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h"
mep-cop1-64:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache with-profile=fn" mep_ext1 ext_cop1_64 $(CGEN_MACH) mepcop1_64 "mep-cop1-64-" \
	$(cgendir)/cpu/mep.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h"
# end-cpus
mep-cpudesc:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache" mep $(CPU_LIST) $(CGEN_MACH) "" "mep-" \
	$(cgendir)/cpu/mep.cpu \
	"desc.h cpu.h"

mep-decsemdefs:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	mep "with-multiple-isa with-scache with-profile=fn" mep_basic mep $(CGEN_MACH) mep "mep-" \
	$(cgendir)/cpu/mep.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx defs.h"

html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
