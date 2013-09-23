## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config -I ../../..

CXX = arm-elf-g++
CXXFLAGS = -g -O2

BITMAPS=bp1.bit bp2.bit record.bit play.bit bp3.bit stop.bit

all-local:
	chmod a+x voice-pager-demo
	for f in $(BITMAPS); do cp $(srcdir)/$$f . ; done

noinst_PROGRAMS = Test-voice-pager.out
noinst_SCRIPTS = voice-pager-demo

Test_voice_pager_out_SOURCES = Test-voice-pager.cxx parport-driver.cxx \
rtc-driver.cxx lcd-driver.cxx page-lcd.cxx adac-driver.cxx \
VoicePager.cxx

