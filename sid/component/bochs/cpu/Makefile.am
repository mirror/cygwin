## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

##         sid/include in build tree       bochs/cpu   component/bochs sid/include in src tree     bochs/memory
INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../memory -I$(srcdir)/../debug

noinst_LTLIBRARIES = libcpu.la

libcpu_la_SOURCES =  exception-sid.cc cpu.cc cpu.h cpu-sid.h cpu-sid.cc init-sid.cc state_file.h main-hack.cc x86.cc access.cc ctrl_xfer8.cc flag_ctrl.cc mult32.cc shift16.cc ctrl_xfer_pro.cc flag_ctrl_pro.cc mult8.cc shift32.cc arith16.cc data_xfer16.cc init.cc paging.cc shift8.cc arith32.cc data_xfer32.cc io.cc proc_ctrl.cc soft_int.cc soft_int-sid.cc arith8.cc data_xfer8.cc io_pro.cc protect_ctrl.cc stack16.cc bcd.cc debugstuff.cc debugstuff-sid.cc lazy_flags.cc protect_ctrl_pro.cc stack32.cc bit.cc decode16.cc logical16.cc resolve16.cc stack_pro.cc decode32.cc logical32.cc resolve32.cc string.cc ctrl_xfer16.cc exception.cc logical8.cc segment_ctrl.cc tasking.cc ctrl_xfer32.cc ctrl_xfer32-sid.cc fetchdecode.cc fetchdecode-sid.cc mult16.cc segment_ctrl_pro.cc vm8086.cc lazy_flags.h x86.h x86-memory-modes.cc

libcpu_la_LDFLAGS = -no-undefined
