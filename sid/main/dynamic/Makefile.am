## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

INCLUDES = -I. -I../../include -I$(srcdir)/../../include

bin_PROGRAMS = sid

# If sid is being compiled without shared library support, arrange to
# statically link in a bunch of component libraries using libtool's
# '-dlpreopen' flag.

if SID_STATIC
NEARBY_LIBS = \
	-dlpreopen ../../component/audio/libaudio.la \
	-dlpreopen ../../component/cfgroot/libconfig.la \
	-dlpreopen ../../component/cgen-cpu/libcgencpu.la \
	-dlpreopen ../../component/consoles/libconsoles.la \
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
AM_CXXFLAGS = -DSID_STATIC
else
NEARBY_LIBS =
AM_CXXFLAGS = 
endif

sid_SOURCES = mainDynamic.cxx
sid_LDFLAGS = -export-dynamic -static -export-symbols-regex '[a-zA-Z0-9]*_library$$' $(NEARBY_LIBS)
sid_LDADD = ../../component/cfgroot/libconfig.la
