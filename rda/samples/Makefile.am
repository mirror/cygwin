## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

WARN_CFLAGS = @WARN_CFLAGS@
WERROR_CFLAGS = @WERROR_CFLAGS@
AM_CFLAGS = $(WARN_CFLAGS) $(WERROR_CFLAGS)

noinst_PROGRAMS = sample async poll thread

AM_CPPFLAGS = -I$(srcdir) -I$(srcdir)/../include

sample_SOURCES = main.c demo-target.c
sample_DEPLIBS = ../lib/librda.la 
sample_LDADD = $(sample_DEPLIBS) $(LIBINTL)
sample_DEPENDENCIES = $(sample_DEPLIBS) $(LIBINTL_DEP)

async_SOURCES = async.c demo-target.c
async_LDADD = ../lib/librda.la

poll_SOURCES = poll.c demo-target.c
poll_LDADD = ../lib/librda.la

thread_SOURCES = thread.c demo-target.c
thread_LDADD = ../lib/librda.la
