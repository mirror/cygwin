## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
SUBDIRS = . testsuite

pkglib_LTLIBRARIES = libhd44780u.la libt6963c.la liblcd-char-display.la

INCLUDES = -I. -I../../include -I$(srcdir)/../../include

libhd44780u_la_SOURCES = HD44780U.cxx rom.cxx rom-japan.cxx rom-europe.cxx rom-5X10.cxx
libhd44780u_la_LDFLAGS = -module -no-undefined

libt6963c_la_SOURCES = T6963C.cxx rom.cxx rom-japan.cxx rom-t6963c.cxx
libt6963c_la_LDFLAGS = -module -no-undefined

liblcd_char_display_la_SOURCES = lcd-char-display.cxx
liblcd_char_display_la_LDFLAGS = -module -no-undefined
liblcd_char_display_la_LIBADD = @lcd_libs@

pkgdata_DATA = hw-visual-lcd.tk hw-visual-lcd.txt hw-lcd-t6963c.txt hw-lcd-hd44780u.txt hw-lcd-char-display.txt

DEJAGNUTESTS=lcdbase.exp lcdmonkey.exp lcd1val.exp lcd1inv.exp
checkme: all
	(cd ../testsuite ; $(MAKE) check RUNTESTFLAGS="$(RUNTESTFLAGS) $(DEJAGNUTESTS)" )
