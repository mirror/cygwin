## Process this with automake to create Makefile.in

## FIXME: This is begging to be rewritten once Automake 1.5 is
## released and the += operator works correctly inside conditionals.

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../config -I ../..

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

if SIDTARGET_MT
FAM8SCRIPTS = mt-elf-sid
endif

if SIDTARGET_XSTORMY16
FAM10SCRIPTS = xstormy16-elf-sid
endif

if SIDTARGET_X86
FAM11SCRIPTS = i386-elf-sid
endif

if SIDTARGET_SH64
FAM13SCRIPTS = sh64-elf-sid
endif

if SIDTARGET_SH
FAM14SCRIPTS = sh-elf-sid
endif

ALLFAMSCRIPTS = $(FAM0SCRIPTS) $(FAM1SCRIPTS) $(FAM2SCRIPTS) $(FAM3SCRIPTS) \
		$(FAM4SCRIPTS) $(FAM5SCRIPTS) $(FAM6SCRIPTS) $(FAM7SCRIPTS) \
		$(FAM8SCRIPTS) $(FAM9SCRIPTS) $(FAM10SCRIPTS) $(FAM11SCRIPTS) \
		$(FAM12SCRIPTS) $(FAM13SCRIPTS) $(FAM14SCRIPTS)

bin_SCRIPTS = configrun-sid $(ALLFAMSCRIPTS)
