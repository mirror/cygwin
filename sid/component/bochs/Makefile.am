## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config -I ../../..

pkglib_LTLIBRARIES = libx86.la

if SIDTARGET_X86
SUBDIRLIST = vga gui keyboard pic pit cmos dma floppy unmapped harddrv cpu .
SUBLIBLIST = vga/libvga.la gui/libgui.la keyboard/libkeyboard.la pic/libpic.la pit/libpit.la cmos/libcmos.la dma/libdma.la floppy/libfloppy.la unmapped/libunmapped.la harddrv/libharddrv.la cpu/libcpu.la 
else
SUBDIRLIST =
SUBLIBLIST =
endif

SUBDIRS = $(SUBDIRLIST)

INCLUDES = -I$(top_builddir)/.. -I$(top_builddir)/../../include -I$(srcdir)/../../include -I$(srcdir)/vga -I$(srcdir)/gui -I$(srcdir)/keyboard -I$(srcdir)/pic -I$(srcdir)/pit -I$(srcdir)/cmos -I$(srcdir)/dma -I$(srcdir)/floppy -I$(srcdir)/unmapped -I$(srcdir)/harddrv -I$(srcdir)/cpu -I$(srcdir)/cpu/memory -I$(srcdir)/../memory

libx86_la_SOURCES = components.cxx
libx86_la_LDFLAGS = -module -no-undefined
libx86_la_LIBADD = $(SUBLIBLIST)
libx86_la_DEPENDENCIES = $(SUBLIBLIST)

AUTOHEADER = echo "Not running autoheader"
