## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

if HAVE_XOS_HEADER
GUI_FILES = x-gui.cc x-gui.h iconbochs.h
else
GUI_FILES = dummy.cc
endif

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu -I$(srcdir)/../../memory

noinst_LTLIBRARIES = libgui.la

libgui_la_SOURCES = $(GUI_FILES)

libgui_la_LDFLAGS = -no-undefined
