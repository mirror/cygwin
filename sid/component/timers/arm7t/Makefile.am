## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../../config -I ../../../..

noinst_LTLIBRARIES = libarm7ttimers.la

INCLUDES = -I. -I../../../include -I$(srcdir)/../../../include
libarm7ttimers_la_SOURCES = arm.cxx
libarm7ttimers_la_LDFLAGS =

pkgdata_DATA = hw-timer-arm_ref.txt


html_stylesheet=$(srcdir)/../../component_html.xsl
include $(srcdir)/../../../config/Makefile.docs
