## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

SUBDIRS = memory fpu

SUBLIBS = memory/libmemory.la fpu/libfpu.la

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/memory

noinst_LTLIBRARIES = libcpu.la

libcpu_la_SOURCES = init.cc access.cc cpu.cc resolve32.cc fetchdecode.cc exception.cc ctrl_xfer_pro.cc flag_ctrl_pro.cc io_pro.cc protect_ctrl_pro.cc segment_ctrl_pro.cc stack_pro.cc lazy_flags.cc paging.cc vm8086.cc tasking.cc debugstuff.cc arith32.cc mult32.cc data_xfer32.cc logical32.cc ctrl_xfer32.cc stack32.cc shift32.cc arith8.cc mult8.cc data_xfer8.cc logical8.cc ctrl_xfer8.cc shift8.cc resolve16.cc arith16.cc mult16.cc data_xfer16.cc logical16.cc ctrl_xfer16.cc stack16.cc shift16.cc bit.cc flag_ctrl.cc io.cc proc_ctrl.cc protect_ctrl.cc segment_ctrl.cc soft_int.cc string.cc bcd.cc cpu.h lazy_flags.h main-hack.cc sid-x86-cpu-wrapper.cc sid-x86-memory-modes.cc sid-x86-cpu-wrapper.h state_file.h
libcpu_la_LDFLAGS = -no-undefined
libcpu_la_LIBADD = $(SUBLIBS)
libcpu_la_DEPENDENCIES = $(SUBLIBS)
