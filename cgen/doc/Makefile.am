## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

info_TEXINFOS = cgen.texi

DOCFILES = app.texi cgen.texi intro.texi notes.texi opcodes.texi \
	pmacros.texi porting.texi \
	rtl.texi sim.texi

# version.texi is handled by autoconf/automake
cgen.info: $(DOCFILES) version.texi
cgen.dvi: $(DOCFILES) version.texi

# This one isn't ready for prime time yet.  Not even a little bit.

noinst_TEXINFOS = cgen.texi
