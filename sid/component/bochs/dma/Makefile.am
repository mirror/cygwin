## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libdma.la

libdma_la_SOURCES = sid-dma-wrapper.cc sid-dma-wrapper.h dma.cc dma.h

libdma_la_LDFLAGS = -no-undefined
