## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../config -I ../..

pkglib_LTLIBRARIES = libexample.la
pkgdata_DATA = $(libexample_la_SOURCES)

INCLUDES = -I. -I../include -I$(srcdir)/../include
libexample_la_SOURCES = timer.cxx
libexample_la_LDFLAGS = -module -no-undefined
