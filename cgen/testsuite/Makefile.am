# Makefile for cgen/testsuite.
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

AUTOMAKE_OPTIONS = 1.9 cygnus

cgendir = $(srcdir)/..

# Default set of tests to run.
TEST_LIST = all

default:
	@echo no default

.phony: check
check: Makefile test-utils.sh
	$(SHELL) ${srcdir}/run-tests.sh $(TEST_LIST)

.PHONY: clean-test-files
clean: clean-test-files
clean-test-files:
	rm -f *.test.cpu*
	rm -f *.out
	rm -f *.tmp
