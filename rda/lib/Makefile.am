## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

WARN_CFLAGS = @WARN_CFLAGS@
WERROR_CFLAGS = @WERROR_CFLAGS@
AM_CFLAGS = $(WARN_CFLAGS) $(WERROR_CFLAGS)

noinst_LTLIBRARIES = librda.la

AM_CPPFLAGS = 					\
	-I$(srcdir)				\
	-I$(srcdir)/../include			\
	-I$(srcdir)/../../include

librda_la_SOURCES =				\
	gdbserv-input.c				\
	gdbserv-output.c			\
	gdbserv-state.c				\
	gdbserv-utils.c				\
	gdbsocket.c				\
	gdblog.c				\
	stdio-log.c				\
	gdbserv-log.c				\
	gdbloop.c				\
	gdbsched.c				\
	gdbserv-target.c			\
	crc32.c
