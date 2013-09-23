## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libsh.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-sh.txt

libsh_la_SOURCES = sh.cxx sh_compact.cxx sh_vliw.cxx common_model.cxx \
 sh2.cxx sh2a.cxx sh2e.cxx sh2a_fpu.cxx sh2a_nofpu.cxx sh2a_model.cxx \
 sh3.cxx sh3e.cxx sh3_model.cxx \
 sh4_nofpu.cxx sh4.cxx sh4_model.cxx \
 sh4a_nofpu.cxx sh4a.cxx sh4a_model.cxx \
 sh4al.cxx \
 sh5.cxx sh5_model.cxx \
 sh2-decode.cxx sh2-model.cxx sh2-sem.cxx sh2-write.cxx \
 sh2e-decode.cxx sh2e-model.cxx sh2e-sem.cxx sh2e-write.cxx \
 sh2a-fpu-decode.cxx sh2a-fpu-model.cxx sh2a-fpu-sem.cxx sh2a-fpu-write.cxx \
 sh2a-nofpu-decode.cxx sh2a-nofpu-model.cxx sh2a-nofpu-sem.cxx sh2a-nofpu-write.cxx \
 sh3-decode.cxx sh3-model.cxx sh3-sem.cxx sh3-write.cxx \
 sh3e-decode.cxx sh3e-model.cxx sh3e-sem.cxx sh3e-write.cxx \
 sh4-nofpu-decode.cxx sh4-nofpu-model.cxx sh4-nofpu-sem.cxx sh4-nofpu-write.cxx \
 sh4-decode.cxx sh4-model.cxx sh4-sem.cxx sh4-write.cxx \
 sh4a-nofpu-decode.cxx sh4a-nofpu-model.cxx sh4a-nofpu-sem.cxx sh4a-nofpu-write.cxx \
 sh4a-decode.cxx sh4a-model.cxx sh4a-sem.cxx sh4a-write.cxx \
 sh4al-decode.cxx sh4al-model.cxx sh4al-sem.cxx sh4al-write.cxx \
 sh5-compact-decode.cxx sh5-compact-model.cxx sh5-compact-sem.cxx sh5-compact-write.cxx \
 sh5-media-decode.cxx sh5-media-model.cxx sh5-media-sem.cxx sh5-media-write.cxx
libsh_la_LDFLAGS =
libsh_la_LIBADD = sh-dis.lo sh64-dis.lo sh64-opc.lo sh64.lo

OPCODES_COMPILE_FLAGS = -DHAVE_CONFIG_H \
	-I../../../../opcodes \
	-I../../../../bfd \
	-I../../../../intl \
	-I$(srcdir)/../../../../opcodes \
	-I$(srcdir)/../../../../include \
	-I$(srcdir)/../../../../bfd     \
	-I$(srcdir)/../../../../intl    \
	-D_GNU_SOURCE 

sh-dis.lo: ../../../../opcodes/sh-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

sh64-dis.lo: ../../../../opcodes/sh64-dis.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

sh64-opc.lo: ../../../../opcodes/sh64-opc.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

sh64.lo: sh64.c
	/bin/sh ./libtool --mode=compile $(CC) $(OPCODES_COMPILE_FLAGS) $(CFLAGS) -c $<

cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGEN_ALL = cgen-sh-desc \
	cgen-sh2 cgen-sh2e cgen-sh2a-fpu cgen-sh2a-nofpu \
	cgen-sh3 cgen-sh3e \
	cgen-sh4-nofpu cgen-sh4 cgen-sh4a-nofpu cgen-sh4a cgen-sh4al \
	cgen-sh5-cpu cgen-sh5-compact cgen-sh5-media
.PHONY: cgen-all $(CGEN_ALL)

cgen-all: $(CGEN_ALL)

cgen-sh-desc:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-multiple-isa with-scache" sh compact,media all "" "sh-" \
	$(cgendir)/cpu/sh.cpu \
	"desc.h"

cgen-sh2:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh2 compact sh2 sh2 "sh2-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh2e:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh2e compact sh2e sh2e "sh2e-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh2a-fpu:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh2a_fpu compact sh2a-fpu sh2a_fpu "sh2a-fpu-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh2a-nofpu:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh2a_nofpu compact sh2a-nofpu sh2a_nofpu "sh2a-nofpu-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh3:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh3 compact sh3 sh3 "sh3-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh3e:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh3e compact sh3e sh3e "sh3e-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh4-nofpu:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh4_nofpu compact sh4-nofpu sh4_nofpu "sh4-nofpu-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh4:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh4 compact sh4 sh4 "sh4-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh4a-nofpu:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh4a_nofpu compact sh4a-nofpu sh4a_nofpu "sh4a-nofpu-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh4a:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh4a compact sh4a sh4a "sh4a-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh4al:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh4al compact sh4al sh4al "sh4al-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh5-cpu:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh5 compact,media sh5 sh5 "sh5-" \
	$(cgendir)/cpu/sh.cpu \
	"cpu.h"

cgen-sh5-compact:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh5 compact sh5 sh5_compact "sh5-compact-" \
	$(cgendir)/cpu/sh.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"

cgen-sh5-media:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	sh "with-scache with-profile=fn" sh5 media sh5 sh5_media "sh5-media-" \
	$(cgendir)/cpu/sh.cpu \
	"decode.h decode.cxx model.h model.cxx semantics.cxx write.cxx defs.h"
