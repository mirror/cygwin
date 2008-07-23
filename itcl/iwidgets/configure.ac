dnl	This file is an input file used by the GNU "autoconf" program to
dnl	generate the file "configure", which is run during [incr Tcl]
dnl installation to configure the system for the local environment.

AC_INIT(generic/buttonbox.itk)
# RCS: $Id$

ITCL_VERSION=3.2
AC_SUBST(ITCL_VERSION)

PACKAGE_NAME=iwidgets
MAJOR_VERSION=4
MINOR_VERSION=0
PATCHLEVEL=.1

VERSION=${MAJOR_VERSION}.${MINOR_VERSION}${PATCHLEVEL}
IWIDGETS_SRC_DIR=`pwd`

AC_SUBST(PACKAGE_NAME)
AC_SUBST(VERSION)

AC_PREREQ(2.0)

TEA_INIT([3.2])
AC_CONFIG_AUX_DIR(tclconfig)
AC_PROG_INSTALL

case "`uname -s`" in
    *win32* | *WIN32* | *CYGWIN_NT*|*CYGWIN_98*|*CYGWIN_95*)
	CYGPATH="cygpath -w"
	RELPATH=".. .. bin"
    ;;
    *)
	CYGPATH=echo
	RELPATH=..
    ;;
esac

AC_SUBST(CYGPATH)
AC_SUBST(RELPATH)

#--------------------------------------------------------------------
#   See if there was a command-line option for where Tcl is;  if
#   not, search for Tcl.
#--------------------------------------------------------------------

TEA_PATH_TCLCONFIG
TEA_LOAD_TCLCONFIG

#--------------------------------------------------------------------
#   See if there was a command-line option for where Tk is;  if
#   not, search for Tk.
#--------------------------------------------------------------------

TEA_PATH_TKCONFIG
TEA_LOAD_TKCONFIG

#--------------------------------------------------------------------
# See if --with-itcl was specified to give the [incr Tcl] and [incr Tk]
# source code location.  If not, then we'll assume that the Iwidgets
# package is being installed directly beneath the toplevel Itcl directory.
#--------------------------------------------------------------------

AC_ARG_WITH(itcl, [  --with-itcl=DIR         use Itcl 3.0 binaries from DIR],
        itcl_search=$withval, itcl_search=`cd ${IWIDGETS_SRC_DIR}/..; pwd`)

ITCL_LIB_DIR=""
for dir in $exec_prefix/lib $TCL_LIB_DIR $TCL_SRC_DIR/../itcl $itcl_search ; do
  if test -r $dir/itcl/library/itcl.tcl; then
      if test -r $dir/itk/library/itk.tcl; then
            ITCL_LIB_DIR=$dir/itcl/library
            ITCL_SRC_DIR=$dir/itcl
            ITK_LIB_DIR=$dir/itk/library
            ITK_SRC_DIR=$dir/itk
      fi
  fi
done

if test -z "$ITCL_LIB_DIR"; then
    AC_MSG_ERROR(Can't find Itcl source.  Use --with-itcl to specify the the toplevel [incr Tcl] directory on your system.  (This directory should contain itcl/library/itcl.tcl, itk/library/itk.tcl, and config/mkinstalldirs.))
fi

TEA_SETUP_COMPILER

#--------------------------------------------------------------------
#   Needed for running the test suite
#--------------------------------------------------------------------

TEA_PROG_TCLSH

#--------------------------------------------------------------------
#   Fill in template files with the proper info.
#--------------------------------------------------------------------
AC_SUBST(TCL_SRC_DIR)
AC_SUBST(TK_SRC_DIR)
AC_SUBST(ITCL_LIB_DIR)
AC_SUBST(ITCL_SRC_DIR)
AC_SUBST(ITK_LIB_DIR)
AC_SUBST(ITK_SRC_DIR)
AC_SUBST(IWIDGETS_SRC_DIR)

AC_OUTPUT(Makefile \
	iwidgets.tcl \
	pkgIndex.tcl)
