dnl cgen-maint.m4  -*- m4 -*-

dnl Copyright (C) 2001 Red Hat.
dnl This file is part of SID and is licensed under the GPL.
dnl See the file COPYING.SID for conditions for redistribution.

dnl Handle --with-cgen-maint.
dnl FIXME: perhaps this should be enabled by maintainer mode, but
dnl that's undecided.

AC_DEFUN([RH_CGEN_MAINT], [
AC_ARG_ENABLE([cgen-maint],
[  --enable-cgen-maint     automatically rebuild cgen generated files],
[case "${enableval}" in
  no)   cgen_maint=no ;;
  *)    cgen_maint=yes ;;
esac])
AM_CONDITIONAL(CGEN_MAINT, test x${cgen_maint} = xyes)])
