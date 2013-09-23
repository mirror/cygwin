## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../config -I ../..

#SUBDIRS = @subdirs@
SUBDIRS =

all-local:
	@echo "Type 'make all-demos' to build the demos."

all-demos:
	make all SUBDIRS="@subdirs@"

clean-demos:
	make clean SUBDIRS="@subdirs@"
