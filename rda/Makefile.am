## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

WARN_CFLAGS = @WARN_CFLAGS@
WERROR_CFLAGS = @WERROR_CFLAGS@
AM_CFLAGS = $(WARN_CFLAGS) $(WERROR_CFLAGS)

APPL_DIRS = @targ_subdirs@
SUBDIRS = lib samples qe $(APPL_DIRS)

