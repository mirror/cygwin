## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

LIBIBERTY = -L../../../libiberty -liberty

pkglib_LTLIBRARIES = libloader.la

pkgdata_DATA = sw-load-elf.txt

INCLUDES = -I. -I../../include -I$(srcdir)/../../include -I$(srcdir)/../../../include
libloader_la_SOURCES = compLoader.cxx elfload.c
libloader_la_LDFLAGS = -module -no-undefined
libloader_la_LIBADD = $(LIBIBERTY)

html_stylesheet=$(srcdir)/../component_html.xsl
include $(srcdir)/../../config/Makefile.docs
