## Process this file with automake to generate Makefile.in
#
#   Copyright 2012 Free Software Foundation
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING3.  If not see
# <http://www.gnu.org/licenses/>.
#

AUTOMAKE_OPTIONS = cygnus

# List of files that go into cgen.info.
DOCFILES = app.texi cgen.texi credits.texi glossary.texi intro.texi \
	notes.texi opcodes.texi pmacros.texi porting.texi \
	rtl.texi running.texi sim.texi

info_TEXINFOS = cgen.texi cgenint.texi

# version.texi is handled by autoconf/automake
cgen_TEXINFOS = $(DOCFILES)

# versionint.texi is handled by autoconf/automake
cgenint_TEXINFOS = cgenint.texi glossary.texi

# These aren't ready for prime time yet.  Not even a little bit.

noinst_TEXINFOS = cgen.texi cgenint.texi

# Maintenance

MAINTAINERCLEANFILES = cgen.info cgenint.info

# Automake 1.9 will only build info files in the objdir if they are
# mentioned in DISTCLEANFILES.  It doesn't have to be unconditional,
# though, so we use a bogus condition.
# NOTE: This is copied from gas.
if GENINSRC_NEVER
DISTCLEANFILES = cgen.info cgenint.info
endif
