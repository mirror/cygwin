## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../config

SUBDIRS = @subdirs@ @make_subdirs@

bin_SCRIPTS=siddoc

all-local:
	chmod a+x siddoc
