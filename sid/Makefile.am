## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I config -I ..
SUBDIRS = . @subdirs@

EXTRA_DIST = COPYING.SID

install-info:
	true

all-local: version.h

version.h:
	rm -f $@
	echo '#define SID_RELEASE "$(VERSION)"' > $@
