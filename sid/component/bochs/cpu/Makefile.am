## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

SUBDIRS = memory fpu

SUBLIBS = memory/libmemory.la fpu/libfpu.la

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/memory

noinst_LTLIBRARIES = libcpu.la

libcpu_la_SOURCES =  cpu.cc cpu.h state_file.h main-hack.cc sid-x86-cpu-wrapper.cc access.cc ctrl_xfer8.cc flag_ctrl.cc mult32.cc shift16.cc ctrl_xfer_pro.cc flag_ctrl_pro.cc mult8.cc shift32.cc arith16.cc data_xfer16.cc init.cc paging.cc shift8.cc arith32.cc data_xfer32.cc io.cc proc_ctrl.cc soft_int.cc arith8.cc data_xfer8.cc io_pro.cc protect_ctrl.cc stack16.cc bcd.cc debugstuff.cc lazy_flags.cc protect_ctrl_pro.cc stack32.cc bit.cc decode16.cc logical16.cc resolve16.cc stack_pro.cc decode32.cc logical32.cc resolve32.cc string.cc ctrl_xfer16.cc exception.cc logical8.cc segment_ctrl.cc tasking.cc ctrl_xfer32.cc fetchdecode.cc mult16.cc segment_ctrl_pro.cc vm8086.cc lazy_flags.h sid-x86-cpu-wrapper.h sid-x86-memory-modes.cc
libcpu_la_LDFLAGS = -no-undefined
libcpu_la_LIBADD = $(SUBLIBS)
libcpu_la_DEPENDENCIES = $(SUBLIBS)
