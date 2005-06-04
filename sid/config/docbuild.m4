dnl docbuild.m4  -*- m4 -*-

dnl Copyright (C) 2001 Red Hat.
dnl This file is part of SID and is licensed under the GPL.
dnl See the file COPYING.SID for conditions for redistribution.

dnl Use RH_DOCBUILD_CHECK in configure.in to configure support for
dnl building docs from xml/sgml source, when in maintainer mode.

dnl 

AC_DEFUN([RH_DOCBUILD_CHECK], [

dnl check for presence of "links" text web browser
AC_CHECK_PROG(LINKS,links,true,false)
AM_CONDITIONAL(HAVE_LINKS, test x$LINKS = xtrue)

dnl check for presence of "xsltproc" XSLT processor
AC_CHECK_PROG(XSLTPROC,xsltproc,true,false)
AM_CONDITIONAL(HAVE_XSLTPROC, test x$XSLTPROC = xtrue)

dnl check for presence of "sablotron" XSLT processor
AC_CHECK_PROG(SABLOTRON,sabcmd,true,false)
AM_CONDITIONAL(HAVE_SABLOTRON, test x$SABLOTRON = xtrue)

])
