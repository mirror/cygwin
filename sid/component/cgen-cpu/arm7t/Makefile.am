## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libarm7t.la

BFDINCLUDES =  -I../../../../bfd -I$(srcdir)/../../../../include
INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include $(BFDINCLUDES)
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-arm7t.txt

libarm7t_la_SOURCES = arm7f.cxx arm-decode.cxx arm-sem.cxx arm-semsw.cxx \
	thumb-decode.cxx thumb-sem.cxx thumb-semsw.cxx

libarm7t_la_LDFLAGS =

DEJAGNUTESTS = armconf.exp armmisc.exp armbsp.exp
check-local: all
	(cd ../../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )


cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGEN_ALL = cgen-arm cgen-arm7f cgen-arm7f-arm cgen-arm7f-thumb
.PHONY: cgen-all $(CGEN_ALL)
cgen-all: $(CGEN_ALL)


# General architecture files.
cgen-arm:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	arm "" arm "arm,thumb" arm7tdmi arm "arm-" \
	$(cgendir)/cpu/arm.cpu \
	"desc.h"

# ARM7 non-isa-specific files.
cgen-arm7f:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	arm "with-multiple-isa with-scache" arm "arm,thumb" arm7tdmi arm "arm-" \
	$(cgendir)/cpu/arm.cpu \
	"cpu.h"

# ARM7 files for ARM ISA side.
cgen-arm7f-arm:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	arm "with-multiple-isa with-scache with-pbb with-sem-frags" arm7f arm arm7tdmi arm "arm-" \
	$(cgendir)/cpu/arm.cpu \
	"decode.h decode.cxx semantics.cxx sem-switch.cxx"

# ARM7 files for Thumb ISA side.
cgen-arm7f-thumb:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	arm "with-multiple-isa with-scache with-pbb" arm7f thumb arm7tdmi thumb "thumb-" \
	$(cgendir)/cpu/arm.cpu \
	"decode.h decode.cxx semantics.cxx sem-switch.cxx"

html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
