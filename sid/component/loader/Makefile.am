## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

pkglib_LTLIBRARIES = libloader.la

pkgdata_DATA = sw-load-elf.txt

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libloader_la_SOURCES = compLoader.cxx elfload.c
libloader_la_LDFLAGS = -module -no-undefined
