dnl aclocal.m4 generated automatically by aclocal 1.4

dnl Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY, to the extent permitted by law; without
dnl even the implied warranty of MERCHANTABILITY or FITNESS FOR A
dnl PARTICULAR PURPOSE.

# Do all the work for Automake.  This macro actually does too much --
# some checks are only needed if your package does certain things.
# But this isn't really a big deal.

# serial 1

dnl Usage:
dnl AM_INIT_AUTOMAKE(package,version, [no-define])

AC_DEFUN(AM_INIT_AUTOMAKE,
[AC_REQUIRE([AC_PROG_INSTALL])
PACKAGE=[$1]
AC_SUBST(PACKAGE)
VERSION=[$2]
AC_SUBST(VERSION)
dnl test to see if srcdir already configured
if test "`cd $srcdir && pwd`" != "`pwd`" && test -f $srcdir/config.status; then
  AC_MSG_ERROR([source directory already configured; run "make distclean" there first])
fi
ifelse([$3],,
AC_DEFINE_UNQUOTED(PACKAGE, "$PACKAGE", [Name of package])
AC_DEFINE_UNQUOTED(VERSION, "$VERSION", [Version number of package]))
AC_REQUIRE([AM_SANITY_CHECK])
AC_REQUIRE([AC_ARG_PROGRAM])
dnl FIXME This is truly gross.
missing_dir=`cd $ac_aux_dir && pwd`
AM_MISSING_PROG(ACLOCAL, aclocal, $missing_dir)
AM_MISSING_PROG(AUTOCONF, autoconf, $missing_dir)
AM_MISSING_PROG(AUTOMAKE, automake, $missing_dir)
AM_MISSING_PROG(AUTOHEADER, autoheader, $missing_dir)
AM_MISSING_PROG(MAKEINFO, makeinfo, $missing_dir)
AC_REQUIRE([AC_PROG_MAKE_SET])])

#
# Check to make sure that the build environment is sane.
#

AC_DEFUN(AM_SANITY_CHECK,
[AC_MSG_CHECKING([whether build environment is sane])
# Just in case
sleep 1
echo timestamp > conftestfile
# Do `set' in a subshell so we don't clobber the current shell's
# arguments.  Must try -L first in case configure is actually a
# symlink; some systems play weird games with the mod time of symlinks
# (eg FreeBSD returns the mod time of the symlink's containing
# directory).
if (
   set X `ls -Lt $srcdir/configure conftestfile 2> /dev/null`
   if test "[$]*" = "X"; then
      # -L didn't work.
      set X `ls -t $srcdir/configure conftestfile`
   fi
   if test "[$]*" != "X $srcdir/configure conftestfile" \
      && test "[$]*" != "X conftestfile $srcdir/configure"; then

      # If neither matched, then we have a broken ls.  This can happen
      # if, for instance, CONFIG_SHELL is bash and it inherits a
      # broken ls alias from the environment.  This has actually
      # happened.  Such a system could not be considered "sane".
      AC_MSG_ERROR([ls -t appears to fail.  Make sure there is not a broken
alias in your environment])
   fi

   test "[$]2" = conftestfile
   )
then
   # Ok.
   :
else
   AC_MSG_ERROR([newly created file is older than distributed files!
Check your system clock])
fi
rm -f conftest*
AC_MSG_RESULT(yes)])

dnl AM_MISSING_PROG(NAME, PROGRAM, DIRECTORY)
dnl The program must properly implement --version.
AC_DEFUN(AM_MISSING_PROG,
[AC_MSG_CHECKING(for working $2)
# Run test in a subshell; some versions of sh will print an error if
# an executable is not found, even if stderr is redirected.
# Redirect stdin to placate older versions of autoconf.  Sigh.
if ($2 --version) < /dev/null > /dev/null 2>&1; then
   $1=$2
   AC_MSG_RESULT(found)
else
   $1="$3/missing $2"
   AC_MSG_RESULT(missing)
fi
AC_SUBST($1)])

# Add --enable-maintainer-mode option to configure.
# From Jim Meyering

# serial 1

AC_DEFUN(AM_MAINTAINER_MODE,
[AC_MSG_CHECKING([whether to enable maintainer-specific portions of Makefiles])
  dnl maintainer-mode is disabled by default
  AC_ARG_ENABLE(maintainer-mode,
[  --enable-maintainer-mode enable make rules and dependencies not useful
                          (and sometimes confusing) to the casual installer],
      USE_MAINTAINER_MODE=$enableval,
      USE_MAINTAINER_MODE=no)
  AC_MSG_RESULT($USE_MAINTAINER_MODE)
  AM_CONDITIONAL(MAINTAINER_MODE, test $USE_MAINTAINER_MODE = yes)
  MAINT=$MAINTAINER_MODE_TRUE
  AC_SUBST(MAINT)dnl
]
)

# Define a conditional.

AC_DEFUN(AM_CONDITIONAL,
[AC_SUBST($1_TRUE)
AC_SUBST($1_FALSE)
if $2; then
  $1_TRUE=
  $1_FALSE='#'
else
  $1_TRUE='#'
  $1_FALSE=
fi])

dnl sidtargets.m4  -*- m4 -*-

dnl Copyright (C) 1999, 2000 Red Hat.
dnl This file is part of SID and is licensed under the GPL.
dnl See the file COPYING.SID for conditions for redistribution.

dnl Use CY_SIDTARGET_CHECK in configure.in to respond to the builder's
dnl selection of --target/--enable-targets

AC_DEFUN(CY_SIDTARGET_CHECK, [


dnl Assume all targets if $host==$target or $target==NONE
sid_host=`${CONFIG_SHELL-/bin/sh} $ac_config_sub $host`
sid_target=`${CONFIG_SHELL-/bin/sh} $ac_config_sub $target`

if test "$sid_host" = "$sid_target" -o "$target" = "NONE"
then
    AC_MSG_WARN(Assuming --enable-targets=all)
    all_targets=""
    sidtarget_default=1
else
    all_targets="$target"
    sidtarget_default=0
fi


AC_ARG_ENABLE(targets,
[  --enable-targets=LIST   support given additional targets, or all],
[
  case "${enable_targets}" in
    all)  sidtarget_default=1 ;;
    no)   sidtarget_default=0 ;;
    *)    all_targets="${all_targets} `echo ${enable_targets} | sed -e 's-,- -g'`" ;;
  esac
])

dnl Enumerate known chip families
sidtarget_arm=$sidtarget_default
sidtarget_mips=$sidtarget_default
sidtarget_m32r=$sidtarget_default
sidtarget_m68k=$sidtarget_default
sidtarget_ppc=$sidtarget_default

dnl Iterate over all listed targets
for targ in $all_targets
do
   case "$targ" in
      arm*)   sidtarget_arm=1 ;;
      thumb*) sidtarget_arm=1 ;;
      mips*)  sidtarget_mips=1 ;;
      m32r*)  sidtarget_m32r=1 ;;
      m68k*)  sidtarget_m68k=1 ;;
      powerpc*) sidtarget_ppc=1 ;;
      ppc*)   sidtarget_ppc=1 ;;
      *)      AC_MSG_WARN("Unknown target $targ") ;;
   esac
done

dnl Ensure at least one of these variables is non-zero.
case 1 in
  ${sidtarget_arm}) ;;
  ${sidtarget_mips}) ;;
  ${sidtarget_m32r}) ;;
  ${sidtarget_m68k}) ;;
  ${sidtarget_ppc}) ;;
  *) AC_MSG_WARN([No selected sid targets: use --enable-targets or --target])
	;;
esac

dnl Report results SIDTARGET_family
dnl nb: Use "x$sidtarget_family" in the tested expression to prevent
dnl     syntax errors in configure when sidtarget_family is left unset.

AC_MSG_CHECKING(ARM family support)
AC_SUBST(sidtarget_arm)
AM_CONDITIONAL(SIDTARGET_ARM,[test "x$sidtarget_arm" = x1])
AC_MSG_RESULT($sidtarget_arm)


AC_MSG_CHECKING(MIPS family support)
AC_SUBST(sidtarget_mips)
AM_CONDITIONAL(SIDTARGET_MIPS,[test "x$sidtarget_mips" = x1])
AC_MSG_RESULT($sidtarget_mips)

AC_MSG_CHECKING(M32R family support)
AC_SUBST(sidtarget_m32r)
AM_CONDITIONAL(SIDTARGET_M32R,[test "x$sidtarget_m32r" = x1])
AC_MSG_RESULT($sidtarget_m32r)

AC_MSG_CHECKING(M68K family support)
AC_SUBST(sidtarget_m68k)
AM_CONDITIONAL(SIDTARGET_M68K,[test "x$sidtarget_m68k" = x1])
AC_MSG_RESULT($sidtarget_m68k)

AC_MSG_CHECKING(PPC family support)
AC_SUBST(sidtarget_ppc)
AM_CONDITIONAL(SIDTARGET_PPC,[test "x$sidtarget_ppc" = x1])
AC_MSG_RESULT($sidtarget_ppc)


])

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

