## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config -I ../../..

INCLUDES = -I. -I../../include -I$(srcdir)/../../include -I$(srcdir)/../../../include
LIBIBERTY = -L../../../libiberty/pic -L../../../libiberty -liberty

bin_PROGRAMS = sid
TARGETCFGS = shCfg.cxx
TARGETDEFINES =

if SIDTARGET_MEP
FAM9LIB = ../../component/families/mep/libmepfamily.la
FAM9LIB2 = -dlpreopen ../../component/families/mep/libmepfamily.la
TARGETCFGS += mepCfg.cxx
TARGETDEFINES += -DSIDTARGET_MEP
endif

if SIDTARGET_SH
TARGETDEFINES += -DSIDTARGET_SH
endif

if SIDTARGET_SH64
TARGETDEFINES += -DSIDTARGET_SH64
endif

# If sid is being compiled without shared library support, arrange to
# statically link in a bunch of component libraries using libtool's
# '-dlpreopen' flag.


ALLFAMLIBS = $(FAM9LIB)
ALLFAMLIBS2 = $(FAM9LIB2)

if SID_STATIC
NEARBY_LIBS = \
	-dlpreopen ../../component/audio/libaudio.la \
	-dlpreopen ../../component/cache/libcache.la \
	-dlpreopen ../../component/cfgroot/libconfig.la \
	-dlpreopen ../../component/cgen-cpu/libcgencpu.la \
	-dlpreopen ../../component/bochs/libx86.la \
	-dlpreopen ../../component/consoles/libconsoles.la \
	$(ALLFAMLIBS2) \
	-dlpreopen ../../component/gdb/libgdb.la \
	-dlpreopen ../../component/gloss/libgloss.la \
	-dlpreopen ../../component/glue/libglue.la \
	-dlpreopen ../../component/ide/libide.la \
	-dlpreopen ../../component/interrupt/libinterrupt.la \
	-dlpreopen ../../component/lcd/libhd44780u.la \
	-dlpreopen ../../component/lcd/liblcd-char-display.la \
	-dlpreopen ../../component/lcd/libt6963c.la \
	-dlpreopen ../../component/loader/libloader.la \
	-dlpreopen ../../component/mapper/libmapper.la \
	-dlpreopen ../../component/memory/libmemory.la \
	-dlpreopen ../../component/mmu/libmmu.la \
	-dlpreopen ../../component/parport/libparport.la \
	-dlpreopen ../../component/profiling/libprof.la \
	-dlpreopen ../../component/rtc/librtc.la \
	-dlpreopen ../../component/sched/libsched.la \
	-dlpreopen ../../component/tcl/libtclapi.la \
	-dlpreopen ../../component/timers/libtimers.la \
	-dlpreopen ../../component/uart/libuart.la
NEARBY_DEPS_LIBS = \
	../../component/audio/libaudio.la \
	../../component/cache/libcache.la \
	../../component/cfgroot/libconfig.la \
	../../component/cgen-cpu/libcgencpu.la \
	../../component/bochs/libx86.la \
	../../component/consoles/libconsoles.la \
	$(ALLFAMLIBS) \
	../../component/gdb/libgdb.la \
	../../component/gloss/libgloss.la \
	../../component/glue/libglue.la \
	../../component/ide/libide.la \
	../../component/interrupt/libinterrupt.la \
	../../component/lcd/libhd44780u.la \
	../../component/lcd/liblcd-char-display.la \
	../../component/lcd/libt6963c.la \
	../../component/loader/libloader.la \
	../../component/mapper/libmapper.la \
	../../component/memory/libmemory.la \
	../../component/mmu/libmmu.la \
	../../component/parport/libparport.la \
	../../component/profiling/libprof.la \
	../../component/rtc/librtc.la \
	../../component/sched/libsched.la \
	../../component/tcl/libtclapi.la \
	../../component/timers/libtimers.la \
	../../component/uart/libuart.la
AM_CXXFLAGS = -DSID_STATIC $(TARGETDEFINES)
else
NEARBY_LIBS = ../../component/cfgroot/libconfig.la
NEARBY_DEPS_LIBS = $(NEARBY_LIBS)
AM_CXXFLAGS = $(TARGETDEFINES)
endif

sid_SOURCES = mainDynamic.cxx baseCfg.cxx commonCfg.cxx $(TARGETCFGS)
sid_LDFLAGS = -export-dynamic -static -export-symbols-regex '[a-zA-Z0-9]*_library$$' $(NEARBY_LIBS)
sid_DEPENDENCIES = $(NEARBY_DEPS_LIBS) ../../version.h
sid_LDADD = $(LIBIBERTY)
