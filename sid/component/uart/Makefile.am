## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
SUBDIRS = . testsuite

pkglib_LTLIBRARIES = libuart.la

pkgdata_DATA = hw-uart-ns16550.txt

INCLUDES = -I. -I../../include -I$(srcdir)/../../include
libuart_la_SOURCES = Uart.cxx
libuart_la_LDFLAGS = -module -no-undefined


