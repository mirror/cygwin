## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

WARN_CFLAGS = @WARN_CFLAGS@
WERROR_CFLAGS = @WERROR_CFLAGS@
AM_CFLAGS = $(WARN_CFLAGS) $(WERROR_CFLAGS)

noinst_PROGRAMS = qe

INCLUDES = -I$(srcdir) -I$(srcdir)/../include

qe_SOURCES = \
	inc-gdblog.c \
	inc-gdbloop.c \
	inc-gdbsched.c \
	inc-gdbserv.c \
	inc-gdbserv-client.c \
	inc-gdbserv-input.c \
	inc-gdbserv-log.c \
	inc-gdbserv-output.c \
	inc-gdbserv-target.c \
	inc-gdbserv-utils.c \
	inc-gdbsocket.c \
	inc-stdio-log.c \
	inc-forward.c \
	inc-backwards.c \
	qe.c
