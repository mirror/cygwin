## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../config

SUBDIRS = . pregen

if SIDTARGET_ARM
FAM0SCRIPTS = arm-elf-sid
endif

if SIDTARGET_M32R
FAM2SCRIPTS = m32r-elf-sid
endif

if SIDTARGET_M68K
FAM3SCRIPTS = m68k-elf-sid
endif

ALLFAMSCRIPTS = $(FAM0SCRIPTS) $(FAM2SCRIPTS) $(FAM3SCRIPTS)

bin_SCRIPTS = configrun-sid $(ALLFAMSCRIPTS)
