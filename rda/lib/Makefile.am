## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

WARN_CFLAGS = @WARN_CFLAGS@
WERROR_CFLAGS = @WERROR_CFLAGS@
AM_CFLAGS = $(WARN_CFLAGS) $(WERROR_CFLAGS)

# Create a libtool convenience archive
# ... and a plain library archive for non-libtool clients
noinst_LTLIBRARIES = librda.la
noinst_LIBRARIES = librda.a

INCLUDES = -I$(srcdir) -I$(srcdir)/../include \
	-I$(srcdir)/../../include

THESOURCES=gdbserv-input.c gdbserv-output.c gdbserv-state.c gdbserv-utils.c gdbsocket.c gdblog.c stdio-log.c gdbserv-log.c gdbloop.c gdbsched.c gdbserv-target.c

librda_la_SOURCES = $(THESOURCES)
librda_a_SOURCES = $(THESOURCES)
