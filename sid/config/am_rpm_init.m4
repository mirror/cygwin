dnl @synopsis AM_RPM_INIT
dnl
dnl Setup variables for creation of rpms.  It will define several
dnl variables useful for creating rpms on a system where rpms are
dnl supported.  Currently, I requires changes to Makefile.am to
dnl function properly (see the example below).
dnl
dnl Also note that I do not use any non-UNIX OSs (and for the most
dnl part, I only use RedHat), so this is probably generally not useful
dnl for other systems.
dnl
dnl Required setup:
dnl
dnl In configure.in:
dnl
dnl   dnl For my rpm.m4 macros
dnl   RPM_RELEASE=1
dnl   AC_SUBST(RPM_RELEASE)
dnl
dnl   AM_RPM_INIT
dnl   dnl Enable or disable the rpm making rules in Makefile.am
dnl   AM_CONDITIONAL(MAKE_RPMS, test x$make_rpms = xtrue)
dnl
dnl Furthermore, the %GNUconfigure rpm macro has a problem in that it
dnl does not define CXXFLAGS for the target system correctly, so for
dnl compiling C++ code, add the following line _before_ calling
dnl AC_PROG_CXX:
dnl
dnl   dnl This is a little hack to make this work with rpm better (see mysql++.spec.in)
dnl   test -z "$CXXFLAGS" && CXXFLAGS="${CFLAGS}"
dnl
dnl Changes to Makefile.am (I am trying to get rid of this step;
dnl suggestions invited):
dnl
dnl   if MAKE_RPMS
dnl   rpm: @RPM_TARGET@
dnl
dnl   .PHONY: rpm
dnl
dnl   $(RPM_TARGET): $(DISTFILES)
dnl     ${MAKE} dist
dnl     -mkdir -p $(RPM_DIR)/SRPMS
dnl     -mkdir -p `dirname $(RPM_TARGET)`
dnl     $(RPM_PROG) $(RPM_ARGS) $(RPM_TARBALL)
dnl     @echo Congratulations, $(RPM_TARGET) "(and friends)" should now exist.
dnl   else
dnl   endif
dnl
dnl Also, it works best with a XXXX.spec.in file like the following
dnl (this is way down on the wishlist, but a program to generate the
dnl skeleton spec.in much like autoscan would just kick butt!):
dnl
dnl   ---------- 8< ----------
dnl   # -*- Mode:rpm-spec -*-
dnl   # mysql++.spec.in
dnl   Summary: Your package description goes here
dnl   %define rel @RPM_RELEASE@
dnl
dnl   %define version @VERSION@
dnl   %define pkgname @PACKAGE@
dnl   %define prefix /usr
dnl
dnl   %define lt_release @LT_RELEASE@
dnl   %define lt_version @LT_CURRENT@.@LT_REVISION@.@LT_AGE@
dnl
dnl   # This is a hack until I can figure out how to better handle replacing
dnl   # autoconf macros... (gotta love autoconf...)
dnl   %define __aclocal   aclocal || aclocal -I ./macros
dnl   %define configure_args  @RPM_CONFIGURE_ARGS@
dnl
dnl   Name: %{pkgname}
dnl   Version: %{version}
dnl   Release: %{rel}
dnl
dnl   Copyright: LGPL
dnl   Group: # your group name goes here
dnl   Source: %{pkgname}-%{version}.tar.gz
dnl   Requires: # additional requirements
dnl   Buildroot: /tmp/%{pkgname}-root
dnl   URL: http://yoururl.go.here
dnl   Prefix: %{prefix}
dnl   BuildArchitectures: # Target platforms, i.e., i586
dnl   Packager: Your Name <youremail@your.address>
dnl
dnl   %description
dnl   Your package description
dnl
dnl   %changelog
dnl
dnl   %prep
dnl   %setup
dnl   #%patch
dnl
dnl   %build
dnl   %GNUconfigure %{configure_args}
dnl   # This is why we copy the CFLAGS to the CXXFLAGS in configure.in
dnl   # CFLAGS="%{optflags}" CXXFLAGS="%{optflags}" ./configure %{_target_platform} --prefix=%{prefix}
dnl   make
dnl
dnl   %install
dnl   # To make things work with BUILDROOT
dnl   if [ "$RPM_BUILD_ROOT" != "/tmp/%{pkgname}-root" ]
dnl   then
dnl     echo
dnl     echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
dnl     echo @                                                                    @
dnl     echo @  RPM_BUILD_ROOT is not what I expected.  Please clean it yourself. @
dnl     echo @                                                                    @
dnl     echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
dnl     echo
dnl   else
dnl     echo Cleaning RPM_BUILD_ROOT: "$RPM_BUILD_ROOT"
dnl     rm -rf "$RPM_BUILD_ROOT"
dnl   fi
dnl   make DESTDIR="$RPM_BUILD_ROOT" install
dnl
dnl   %clean
dnl   # Call me paranoid, but I do not want to be responsible for nuking
dnl   # someone's harddrive!
dnl   if [ "$RPM_BUILD_ROOT" != "/tmp/%{pkgname}-root" ]
dnl   then
dnl     echo
dnl     echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
dnl     echo @                                                                    @
dnl     echo @  RPM_BUILD_ROOT is not what I expected.  Please clean it yourself. @
dnl     echo @                                                                    @
dnl     echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
dnl     echo
dnl   else
dnl     echo Cleaning RPM_BUILD_ROOT: "$RPM_BUILD_ROOT"
dnl     rm -rf "$RPM_BUILD_ROOT"
dnl   fi
dnl
dnl   %files
dnl   %defattr(-, root, root)
dnl   # Your application file list goes here
dnl   # %{prefix}/lib/lib*.so*
dnl   %doc COPYRIGHT ChangeLog README AUTHORS NEWS
dnl   %doc doc/*
dnl
dnl   # If you install a library
dnl   %post -p /sbin/ldconfig
dnl
dnl   # If you install a library
dnl   %postun -p /sbin/ldconfig
dnl
dnl   %package devel
dnl   Summary: Development files for %{pkgname}
dnl   Group: Applications/Databases
dnl   %description devel
dnl   Development files for %{pkgname}.
dnl
dnl   %files devel
dnl   %defattr(-, root, root)
dnl   # Your development files go here
dnl   # Programmers documentation goes here
dnl   %doc doc
dnl
dnl   # end of file
dnl   ---------- >8 ----------
dnl
dnl @version $Id$
dnl @author Dale K. Hawkins <dhawkins@cdrgts.com>

dnl AM_RPM_INIT
dnl Figure out how to create rpms for this system and setup for an
dnl automake target

AC_DEFUN([AM_RPM_INIT],
[dnl
AC_REQUIRE([AC_CANONICAL_HOST])
dnl Find the RPM program
AC_ARG_WITH(rpm-prog,[  --with-rpm-prog=PROG   Which rpm to use (optional)],
            rpm_prog="$withval", rpm_prog="")

AC_ARG_ENABLE(rpm-rules, [  --enable-rpm-rules       Try to create rpm make rules (defaults to yes for Linux)],
                enable_rpm_rules="$withval",enable_rpm_rules=no)

AC_ARG_WITH(rpm-extra-args, [  --with-rpm-extra-args=ARGS       Run rpm with extra arguments (defaults to none)],
                rpm_extra_args="$withval", rpm_extra_args="")

dnl AC_ARG_ENABLE(rpm-topdir, [  --enable-rpm       Try to create rpm make rules (defaults to yes for Linux)],
dnl             enable_rpm_rules="$withval",no)

dnl echo enable_rpm_rules is $enable_rpm_rules
dnl echo rpm_prog is $rpm_prog

  RPM_TARGET=""

  if test x$enable_rpm_rules = xno ; then
     echo "Not trying to build rpms for your system (use --enable-rpm-rules to override) "
     no_rpm=yes
  else
    if test x$rpm_prog != x ; then
       if test x${RPM_PROG+set} != xset ; then
          RPM_PROG=$rpm_prog
       fi
    fi

    AC_PATH_PROG(RPM_PROG, rpm, no)
    no_rpm=no
    if test "$RPM_PROG" = "no" ; then
echo *** RPM Configuration Failed
echo *** Failed to find the rpm program.  If you want to build rpm packages
echo *** indicate the path to the rpm program using  --with-rpm-prog=PROG
      no_rpm=yes
      RPM_MAKE_RULES=""
    else
      AC_MSG_CHECKING(how rpm sets %{_rpmdir})
      rpmdir=`rpm --eval %{_rpmdir}`
      if test x$rpmdir = x"%{_rpmdir}" ; then
        AC_MSG_RESULT([not set (cannot build rpms?)])
        echo *** Could not determine the value of %{_rpmdir}
        echo *** This could be because it is not set, or your version of rpm does not set it
        echo *** It must be set in order to generate the correct rpm generation commands
        echo ***
        echo *** You might still be able to create rpms, but I could not automate it for you
        echo *** BTW, if you know this is wrong, please help to improve the rpm.m4 module
        echo *** Send corrections, updates and fixes to dhawkins@cdrgts.com.  Thanks.
      else
        AC_MSG_RESULT([$rpmdir])
      fi
      AC_MSG_CHECKING(how rpm sets %{_rpmfilename})
      rpmfilename=$rpmdir/`rpm --eval %{_rpmfilename} | sed "s/%{ARCH}/${host_cpu}/g" | sed "s/%{NAME}/$PACKAGE/g" | sed "s/%{VERSION}/${VERSION}/g" | sed "s/%{RELEASE}/${RPM_RELEASE}/g"`
      AC_MSG_RESULT([$rpmfilename])

      RPM_DIR=${rpmdir}
      RPM_TARGET=$rpmfilename
      RPM_ARGS="-ta $rpm_extra_args"
      RPM_TARBALL=${PACKAGE}-${VERSION}.tar.gz
    fi
  fi

  case "${no_rpm}" in
    yes) make_rpms=false;;
    no) make_rpms=true;;
    *) AC_MSG_WARN([bad value ${no_rpm} for no_rpm (not making rpms)])
       make_rpms=false;;
  esac
  AC_SUBST(RPM_DIR)
  AC_SUBST(RPM_TARGET)
  AC_SUBST(RPM_ARGS)
  AC_SUBST(RPM_TARBALL)

  RPM_CONFIGURE_ARGS=${ac_configure_args}
  AC_SUBST(RPM_CONFIGURE_ARGS)
])

