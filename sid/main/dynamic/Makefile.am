## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

INCLUDES = -I. -I../../include -I$(srcdir)/../../include

bin_PROGRAMS = sid

# If sid is being compiled without shared library support, arrange to
# statically link in a bunch of component libraries using libtool's
# '-dlpreopen' flag.

NEARBY_LIBS = $(wildcard ../../component/*/*.la)

if SID_STATIC
NEARBY_LIBS2 = $(foreach l,$(NEARBY_LIBS),-dlpreopen $(l))
# This weird little target is needed because automake puts "-dlpreopen FOO1 -dlpreopen FOO2"
# into sid_DEPENDENCIES.
-dlpreopen:
	true
AM_CXXFLAGS = -DSID_STATIC
else
NEARBY_LIBS2 =
AM_CXXFLAGS = 
endif

sid_SOURCES = mainDynamic.cxx
sid_LDFLAGS = -export-dynamic -static -export-symbols-regex '[a-zA-Z0-9]*_component_library$$'
sid_LDADD = ../../component/cfgroot/libconfig.la $(NEARBY_LIBS2)

