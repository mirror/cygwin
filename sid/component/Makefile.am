## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../config -I ../..

SUBDIRS = @subdirs@ @make_subdirs@

bin_SCRIPTS=siddoc

CXXFLAGS=
TOP_CXXFLAGS=$(CXXFLAGS) @comp_defs@
AM_CXXFLAGS=$(TOP_CXXFLAGS)
AM_MAKEFLAGS= "TOP_CXXFLAGS=$(TOP_CXXFLAGS)"

all-local:
	chmod a+x siddoc

check-recursive:
	(cd testsuite && $(MAKE) $(AM_MAKEFLAGS) check)
