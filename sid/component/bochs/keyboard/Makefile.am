## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I$(top_builddir)/../../include -I$(srcdir) -I$(srcdir)/.. -I$(srcdir)/../../../include -I$(srcdir)/../cpu

noinst_LTLIBRARIES = libkeyboard.la

libkeyboard_la_SOURCES = sid-keyboard-wrapper.cc sid-keyboard-wrapper.h keyboard.cc keyboard.h keysymbols.h

libkeyboard_la_LDFLAGS = -no-undefined
