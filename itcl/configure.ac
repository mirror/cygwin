dnl Process this file with autoconf to produce configure.

AC_INIT(itcl/generic/itcl.h)
AC_CONFIG_AUX_DIR(..)
AM_INIT_AUTOMAKE(itcl, 3.3)
AM_MAINTAINER_MODE
AC_CANONICAL_HOST

# Itcl et al require tclsh and wish. Since they have not been built yet,
# we simply set the environment variables TCLSH_PROG and WISH_PROG so that 
# the two TEA macros do not run.
case "${host}" in
  *-*-cywin* | *-*-mingw* )
    platform="win"
    ;;
  *)
    platform="unix"
    ;;
esac

export TCLSH_PROG=`pwd`/../tcl/${platform}/tclsh
export WISH_PROG=`pwd`/../tk/${platform}/wish

AC_CONFIG_SUBDIRS(itcl itk iwidgets)
AC_OUTPUT(Makefile)
