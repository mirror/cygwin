dnl Process this file with autoconf to produce a configure script.
AC_PREREQ([2.59])
AC_INIT
AC_CONFIG_SRCDIR([cesetup.c])
AC_CONFIG_AUX_DIR(`cd $srcdir;pwd`/../..)

AC_CANONICAL_TARGET
AC_ARG_PROGRAM

AC_PROG_INSTALL

CC=${CC-cc}
AC_PROG_CC

AC_EXEEXT
PROGS='cesetup$(EXEEXT)'
AC_SUBST(PROGS)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
