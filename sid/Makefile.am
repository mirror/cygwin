## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ./config
SUBDIRS = @subdirs@

EXTRA_DIST = COPYING.SID

install-data-local:
	$(INSTALL_DATA) $(srcdir)/COPYING.SID $(prefix)

install-info:
	true

