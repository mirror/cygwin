## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu -I$(srcdir)/../../memory

noinst_LTLIBRARIES = libvga.la

libvga_la_SOURCES = sid-vga-wrapper.cc sid-vga-wrapper.h vga.cc vga.h

libvga_la_LDFLAGS = -no-undefined
