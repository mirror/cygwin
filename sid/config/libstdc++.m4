dnl libstdc++.m4  -*- m4 -*-

dnl Copyright (C) 2000 Red Hat.
dnl This file is part of SID and is licensed under the GPL.
dnl See the file COPYING.SID for conditions for redistribution.

dnl Use CY_LIBSTDC++_CHECK in configure.in to check
dnl whether static/shared libstdc++ are available for the target.  Set
dnl the have_libstdcxx_{static,shared} shell variables to "yes" or "no".

AC_DEFUN(CY_LIBSTDCXX_CHECK, [
if test x$GXX != xyes 
then
  have_libstdcxx_shared=no
  have_libstdcxx_static=no
  AC_MSG_WARN(Cannot test for libstdc++ without g++)
else
  AC_MSG_CHECKING(for libstdc++ {static/shared})

  stlibname=libstdc++.a
  case ${host} in
    *-*-cygwin*) shlibname=libstdc++.dll ;;
    *)           shlibname=libstdc++.so ;;
  esac

  gxx_stlibname=`eval $CXX --print-file-name=$stlibname`
  gxx_shlibname=`eval $CXX --print-file-name=$shlibname`

  gxx_stlibdir=`dirname $gxx_stlibname`
  gxx_shlibdir=`dirname $gxx_shlibname`

  if test "x$gxx_stlibdir" != "x"
  then
    have_libstdcxx_static=yes
  else
    have_libstdcxx_static=no
  fi

  # Expect shared libraries to live right beside their static counterparts.
  # Some installations put libstdc++.so into $prefix/lib/gcc-lib/*, and make
  # it a symlink to $prefix/lib.

  # The heuristics are meant to detect and prevent the case where the host may
  # have *some other* shared libstdc++.so installed, say in /usr/lib, even though
  # the compiler only came with a libstdc++.a in some other directory.
  if test "x$gxx_shlibdir" != "x" -a "x$gxx_stlibdir" = "x$gxx_shlibdir"
  then
    have_libstdcxx_shared=yes
  else
    have_libstdcxx_shared=no
  fi

  AC_MSG_RESULT(${have_libstdcxx_static}/${have_libstdcxx_shared})
fi
])
