## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = cygnus

noinst_LIBRARIES = libgui.a

if INSTALL_LIBGUI

include_HEADERS = \
	guitcl.h subcommand.h

endif

# tkTable version info
include $(srcdir)/tkTable_version.in

# This sets the name that tkTable will define for itself when loaded
# If you change this, then the demos won't work, but it might be necessary
# for those with another built-in "table" command
TBL_COMMAND     = table

tkTabletcl.h: $(srcdir)/tkTable.tcl
	sed -e '/^$\#/d' -e '/^$$/d' -e 's/\"/\\"/g' -e 's/^/"/' -e 's/$$/\\n"/' <$(srcdir)/tkTable.tcl >tkTabletcl.h || rm tkTabletcl.h 



# Defining lib_LIBRARIES conditionally doesn't do the right thing.
install-exec-local:
if INSTALL_LIBGUI
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(libdir)
	$(INSTALL_DATA) libgui.a $(libdir)/libgui.a
	@$(POST_INSTALL)
	$(RANLIB) $(libdir)/libgui.a
endif

LIBGUI_CFLAGS=@LIBGUI_CFLAGS@

## Some of the files in this directory want to see Tk internals.
## Nasty.
INCLUDES = $(LIBGUI_CFLAGS) $(TCLHDIR) \
$(TKHDIR) \
$(TK_XINCLUDES) $(TCL_DEFS) $(TK_DEFS) \
$(TKHDIR)/../unix $(TKHDIR)/../win \
-DTBL_VERSION=\"$(TBL_VERSION)\"\
-DTBL_COMMAND=\"$(TBL_COMMAND)\"\
-DTCL_RUNTIME=\"tkTable.tcl\"

libgui_a_SOURCES = guitcl.h paths.c subcommand.c subcommand.h \
xpmlib.c tclmain.c tkGraphCanvas.c \
tkCanvEdge.c tkCanvLayout.c tkCanvLayout.h tclhelp.c tclgetdir.c \
tclwinprint.c tclsizebox.c tclshellexe.c tclmapi.c tclwinfont.c	\
tclwingrab.c tclwinmode.c tclwinpath.c tclmsgbox.c tclcursor.c \
tkTable.c tkTableCmd.c tkTableCell.c tkTableTag.c tkTableWin.c \
tkWinPrintText.c tkWinPrintCanvas.c tkWarpPointer.c

## Dependencies

paths.$(OBJEXT): paths.c guitcl.h
subcommand.$(OBJEXT): subcommand.c subcommand.h
tkCanvEdge.$(OBJEXT): tkCanvEdge.c ../config.h
tkCanvLayout.$(OBJEXT): tkCanvLayout.c ../config.h tkCanvLayout.h
tkGraphCanvas.$(OBJEXT): tkGraphCanvas.c tkCanvLayout.h
xpmlib.$(OBJEXT): xpmlib.c guitcl.h
assertions.$(OBJEXT): assertions.c ../config.h assertions.h
tclcursor.$(OBJEXT): tclcursor.c ../config.h guitcl.h subcommand.h
tclhelp.$(OBJEXT): tclhelp.c ../config.h guitcl.h subcommand.h
tclgetdir.$(OBJEXT): tclgetdir.c guitcl.h
tclmain.$(OBJEXT): tclmain.c guitcl.h
tclwinprint.$(OBJEXT): tclwinprint.c guitcl.h subcommand.h
tclsizebox.$(OBJEXT): tclsizebox.c guitcl.h
tclshellexe.$(OBJEXT): tclshellexe.c guitcl.h
tclmapi.$(OBJEXT): tclmapi.c guitcl.h subcommand.h
tclwinfont.$(OBJEXT): tclwinfont.c guitcl.h
tclwingrab.$(OBJEXT): tclwingrab.c guitcl.h
tclwinpath.$(OBJEXT): tclwinpath.c guitcl.h subcommand.h
tclwinmode.$(OBJEXT): tclwinmode.c guitcl.h
tkTable.$(OBJEXT): tkTable.c tkTable.h tkTableCmd.h tkTabletcl.h
tkTableCell.$(OBJEXT): tkTableCell.c tkTable.h tkTableCmd.h
tkTableTag.$(OBJEXT): tkTableTag.c tkTable.h tkTableCmd.h
tkTableWin.$(OBJEXT):tkTableWin.c  tkTable.h tkTableCmd.h
tkTableCmd.$(OBJEXT): tkTableCmd.c tkTableCmd.h
tkTabletcl.h: tkTable.tcl

