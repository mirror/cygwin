## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config

noinst_LTLIBRARIES = libm32r.la

INCLUDES = -I$(srcdir) -I$(srcdir)/.. -I../../../include -I$(srcdir)/../../../include
CXXFLAGS = $(TOP_CXXFLAGS)

pkgdata_DATA = hw-cpu-m32r_d.txt

libm32r_la_SOURCES = m32rbf.cxx \
	m32r-decode.cxx m32r-sem.cxx
libm32r_la_LDFLAGS =

DEJAGNUTESTS = m32rbsp.exp
.PHONY: checkme
checkme:
	(cd ../../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )

cgendir = $(srcdir)/../../../../cgen
CGENFLAGS = -v

CGEN_ALL = cgen-m32r
.PHONY: cgen-all $(CGEN_ALL)
cgen-all: $(CGEN_ALL)

cgen-m32r:
	$(SHELL) ../CGEN.sh cpu-decode $(srcdir) $(cgendir) "$(CGENFLAGS)" \
	m32r "with-scache" m32rbf m32r m32r m32rbf "m32r-" \
	"desc.h cpu.h defs.h decode.h decode.cxx semantics.cxx"
