## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)
	@for f in `cd $(srcdir); echo *.conf *.img` ; do \
		echo " $(INSTALL_DATA) $(srcdir)/$$f $(DESTDIR)$(pkgdatadir)/$$f"; \
		$(INSTALL_DATA) $(srcdir)/$$f $(DESTDIR)$(pkgdatadir)/$$f; \
	done

if MAINTAINER_MODE
all-local:	stamp-allfamdata

stamp-allfamdata: ../configrun-sid pregen-configs
	$(SHELL) pregen-configs
	touch stamp-allfamdata
endif
