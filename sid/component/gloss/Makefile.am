## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libgloss.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include


if SIDTARGET_ARM
ARMGLOSS = angel.cxx
ARMDATA = sw-gloss-arm_angel.txt
else
ARMGLOSS =
ARMDATA =
endif

if SIDTARGET_MIPS
MIPSGLOSS = mips.cxx
MIPSDATA =
else
MIPSGLOSS =
MIPSDATA =
endif

if SIDTARGET_M32R
M32RGLOSS = m32r.cxx
M32RDATA =
else
M32RGLOSS =
M32RDATA =
endif

libgloss_la_SOURCES = \
	compGloss.cxx gloss.cxx hostops.cxx newlib.cxx \
	$(MIPSGLOSS) $(ARMGLOSS) $(M32RGLOSS)

libgloss_la_LDFLAGS = -module -no-undefined

pkgdata_DATA = $(ARMDATA) $(MIPSDATA) $(M32RDATA)

DEJAGNUTESTS=angel.exp
checkme:
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
