
# ------------------------------------------------------------------------
#
# 	Nmakefile for BLT library using VC++.
#
#  	Please note this file may or may not be up-to-date.  
#
#	You can compare it with "Makefile.vc" in this directory.  That's 
#	what I use to build BLT (so it should be current).  It builds BLT
#	with VC++ 6.0 and the cygwin32 tool suite from 
#
#		http://sourceware.cygnus.com
#
# ------------------------------------------------------------------------

!INCLUDE ../win/makedefs

TOOLS32       =	C:/Program Files/Microsoft Visual Studio/Vc98
prefix        =	C:/Program Files/Tcl

AR            =	lib.exe
LD            =	link.exe
CC            =	cl.exe
rc32          =	rc.exe
RM	      = -del

# ------------------------------------------------------------------------
# 	C Compiler options 
# ------------------------------------------------------------------------

DEFINES       =	-D_X86_=1 -D__STDC__ -DWIN32 -DCONSOLE -D_MT \
			$(DEBUG_DEFINES) $(SHLIB_DEFINES)
EXTRA_CFLAGS  =	-nologo -W3 

!IF "$(SHARED)" == "1"
SHLIB_DEFINES = -D_DLL
SHLIB_TARGET  =	build-dll
LIBS =		$(COMMON_LIBS) 
!ELSE
SHLIB_DEFINES = -D_CTYPE_DISABLE_MACROS
LIBS          =	$(COMMON_LIBS) $(EXTRA_LIBS)
!ENDIF

!IF "$(DEBUG)" == "1"
CFLAGS        =	-Z7 -Od
DEBUG_LDFLAGS =	-debug:full -debugtype:cv  
D             =	d
builddir      =	.\Debug
!ELSE
CFLAGS        =	-Ox -GB -GD 
DEBUG_LDFLAGS =	-debug:full -debugtype:cv  
D             =
builddir      =	.\Release
!ENDIF

MSVCRT        =	msvcrt$(DBG).lib
TK_LIB        =	$(TKDIR)/win/$(builddir)/tk$(v2)$(D).lib  
TCL_LIB       =	$(TCLDIR)/win/$(builddir)/tcl$(v2)$(D).lib 

# ------------------------------------------------------------------------
# 	Linker flags and options 
# ------------------------------------------------------------------------

JPEGLIB       =	$(JPEGDIR)/libjpeg.lib

COMMON_LDFLAGS =	-nodefaultlib -release -nologo -warn:3 \
		-machine:IX86 -align:0x1000 \
		$(DEBUG_LDFLAGS)

DLLENTRY      =	@12
SHLIB_LDFLAGS = $(COMMON_LDFLAGS) \
		-subsystem:console -entry:mainCRTStartup \
		-subsystem:windows -entry:WinMainCRTStartup \
		-entry:_DllMainCRTStartup$(DLLENTRY) -dll  

LDFLAGS       =	$(COMMON_LDFLAGS) \
		-fixed:NO -stack:2300000 

COMMON_LIBS   =	$(TK_LIB) $(TCL_LIB) \
		$(MSVCRT) \
		kernel32.lib user32.lib 

EXTRA_LIBS    =	$(OLELIB) \
		$(JPEGLIB) \
		gdi32.lib \
		oldnames.lib \
		advapi32.lib \
		winspool.lib 

TCL_ONLY_LIBS = $(TCL_LIB) $(MSVCRT)  kernel32.lib user32.lib advapi32.lib 

# ------------------------------------------------------------------------
# 	Source and target directories 
# ------------------------------------------------------------------------

srcdir        =	.
instdirs      =	$(prefix) $(exec_prefix) $(bindir) $(libdir) \
		$(includedir)
instdirs      =	$(exec_prefix) $(prefix) $(libdir)

# ------------------------------------------------------------------------
# 	Directories containing Tcl and Tk include files and libraries
# ------------------------------------------------------------------------

JPEGDIR       =	$(srcdir)/../../jpeg-6b
TCLDIR        =	$(srcdir)/../../tcl$(v3)
TKDIR         =	$(srcdir)/../../tk$(v3)
INCLUDES      =	-I. -I$(srcdir) \
		-I"$(TOOLS32)/include" \
		-I$(TCLDIR)/win \
		-I$(TCLDIR)/generic \
		-I$(TKDIR)/win \
		-I$(TKDIR)/generic \
		-I$(TKDIR)/xlib \
		-I$(JPEGDIR) 
SHLIB_LD_LIBS =	$(COMMON_LIBS) $(EXTRA_LIBS)

# ------------------------------------------------------------------------
# 	You don't need to edit anything beyond this point
# ------------------------------------------------------------------------

N_OBJS       =	bltTed.o
V3_OBJS       =	bltTri.o bltGrMt.o 

TK_OBJS       =	tkButton.o tkFrame.o tkScrollbar.o 

GRAPH_OBJS =	bltGrAxis.o \
		bltGrBar.o \
		bltGrElem.o \
		bltGrGrid.o \
		bltGrHairs.o \
		bltGrLegd.o \
		bltGrLine.o \
		bltGrMarker.o \
		bltGrMisc.o \
		bltGrPen.o \
		bltGrPs.o \
		bltGraph.o 

TCL_ONLY_OBJS =	bltAlloc.o \
		bltArrayObj.o \
		bltBgexec.o \
		bltChain.o \
		bltDebug.o \
		bltHash.o \
		bltList.o \
		bltNsUtil.o \
		bltParse.o \
		bltPool.o \
		bltSpline.o \
		bltSwitch.o \
		bltTree.o \
		bltTreeCmd.o \
		bltUtil.o \
		bltVecCmd.o \
		bltVecMath.o \
		bltVecObjCmd.o \
		bltVector.o \
		bltWatch.o  \
		bltWinPipe.o \
		bltWinUtil.o \
		pure_api.o

DEMO_OBJS     =	tkConsole.o bltWinMain.o

OBJS =		$(GRAPH_OBJS) \
		$(TCL_ONLY_OBJS) \
		bltBeep.o \
		bltBind.o \
		bltBitmap.o \
		bltBusy.o \
		bltCanvEps.o \
		bltConfig.o \
		bltContainer.o \
		bltDragdrop.o \
		bltHierbox.o \
		bltHiertable.o \
		bltHtCmd.o \
		bltHtColumn.o \
		bltHtText.o \
		bltHtext.o \
		bltImage.o \
		bltPs.o \
		bltTable.o \
		bltTabnotebook.o \
		bltTabset.o \
		bltText.o \
		bltTile.o \
		bltTreeView.o \
		bltTreeViewCmd.o \
		bltTreeViewEdit.o \
		bltTreeViewColumn.o \
		bltTreeViewStyle.o \
		bltWinDraw.o \
		bltWinPrnt.o \
		bltWindow.o \
		bltObjConfig.o \
		bltWinop.o \
		$(TK_OBJS) $(N_OBJS) 

NOT_YET       =	bltContainer.o \
		bltCutBuffer.o bltColor.o

HEADERS       =	blt.h bltChain.h bltVector.h bltTree.h

shell_name    =	bltwish
version       =	$(BLT_MAJOR_VERSION)$(BLT_MINOR_VERSION)
bltwish =	bltwish.exe
bltsh =		bltsh.exe
bltwish2 =	bltwish$(version).exe
bltsh2 =	bltsh$(version).exe

lib_name =	BLT$(version)
lib_a =		BLT$(version).lib
lib_so =	BLT$(version).dll		
tcl_only_lib_a = BLTlite$(version).lib
tcl_only_lib_so = BLTlite$(version).dll		

CC_SWITCHES   =	$(CFLAGS) $(EXTRA_CFLAGS) $(DEFINES) $(INCLUDES)
VPATH         =	$(srcdir)

all: build-library $(SHLIB_TARGET) build-demos

build-demos: $(SHLIB_TARGET) $(bltwish) $(bltsh)

build-library: $(BLT_LIB)

build-library: $(lib_a) $(tcl_only_lib_a)

build-dll: build-library $(lib_so) $(tcl_only_lib_so)

$(bltwish): $(lib_a) tkConsole.o 
	$(RM) $@
	$(CC) -c $(CC_SWITCHES) -FobltWinMain.o $(srcdir)/bltWinMain.c
	set LIB="$(TOOLS32)\lib"
	$(LD) $(LDFLAGS) tkConsole.o bltWinMain.o -out:$(bltwish) \
		$(lib_a) $(LIBS) 

$(bltsh): $(tcl_only_lib_a) 
	$(RM) $(bltsh) 
	$(CC) -c $(CC_SWITCHES) -DTCL_ONLY \
		-FobltWinMain.o $(srcdir)/bltWinMain.c
	set LIB="$(TOOLS32)\lib"
	$(LD) $(LDFLAGS) bltWinMain.o -out:$(bltsh) \
		$(tcl_only_lib_a) $(TCL_ONLY_LIBS) 

$(lib_a):  bltHash.h $(OBJS)
	$(RM) bltInit.o
	$(CC) -c $(CC_SWITCHES) -FobltInit.o $(srcdir)/bltInit.c
	$(RM) $@
	$(AR) -out:$@ bltInit.o $(OBJS)

$(lib_so): $(lib_a) 
	$(RM) bltInit.o
	$(CC) -c $(CC_SWITCHES) -FobltInit.o $(srcdir)/bltInit.c
	$(RM) $@
	set LIB="$(TOOLS32)\lib"
	$(LD) $(SHLIB_LDFLAGS) -out:$@ bltInit.o $(OBJS) $(SHLIB_LD_LIBS)

$(tcl_only_lib_a):  bltHash.h $(TCL_ONLY_OBJS)
	$(RM) bltInit.o
	$(CC) -c $(CC_SWITCHES) -DTCL_ONLY -FobltInit.o $(srcdir)/bltInit.c
	$(RM) $@
	$(AR) -out:$@ bltInit.o $(TCL_ONLY_OBJS) 

$(tcl_only_lib_so): $(tcl_only_lib_a) 
	$(RM) bltInit.o
	$(CC) -c $(CC_SWITCHES) -DTCL_ONLY -FobltInit.o $(srcdir)/bltInit.c
	$(RM) $@
	set LIB="$(TOOLS32)\lib"
	$(LD) $(SHLIB_LDFLAGS) -out:$@ bltInit.o $(TCL_ONLY_OBJS) \
		$(TCL_ONLY_LIBS) 

# You probably need to hand edit
bltHash.h: bltHash.h.win32
	cp bltHash.h.win32 bltHash.h
	sed -e 's/@SIZEOF_VOID_P@/4/' \
	    -e 's/@SIZEOF_INT@/4/' \
	    -e 's/@SIZEOF_LONG@/4/' \
	    -e 's/@SIZEOF_LONG_LONG@/8/' \
	    -e 's/@HAVE_INTTYPES_H@/0/' \
	    bltHash.h.in > bltHash.h

clean:
	-del *.o 2>nul
	-del *.pdb 2>nul
	-del *.exp 2>nul
	-del $(lib_name).* 2>nul
	-del $(shell_name).* 2>nul
	-del $(srcdir)\*.bak 2>nul
	-del $(srcdir)\*~ 2>nul 
	-del $(srcdir)\"#"* 2>nul

{$(srcdir)}.c.o:
	$(CC) -c $(CC_SWITCHES) -Fo$*.o $<









