#!/bin/sh

# behave like make(1)
set -e

builddir=`pwd`
top_builddir=$builddir/../../..
top_srcdir=$srcdir/../../..
export CFG_ROOT=`cd $srcdir; pwd`

FILES=$(echo gcc/config/mep/mep.h \
             cgen/cpu/mep*.{cpu,opc} \
	     libgloss/mep/*.{ld,in} \
	     sid/main/dynamic/*.cxx \
	     bfd/elf32-mep.c \
	     sid/component/cgen-cpu/mep/mep.h \
	     sid/component/families/mep/components.cxx)

function customise() {
    (cd $top_srcdir && tar cf $builddir/edited-files.tar $FILES)

    # maybe get MeP-Integrator's flags from the environment?
    ../MeP-Integrator -c $CFG_ROOT $1

    cd $top_builddir/mep-elf/libgloss/mep && ./config.status
    cd $top_builddir/sid/component/cgen-cpu/mep && make cgen-all
    cd $top_builddir/opcodes && make stamp-mep
    cd $top_builddir/gcc && make cgen-maint
    cd $top_builddir && make all
    cd $top_builddir && make install

    # now run make check for this configuration.
    board="mep`echo $1 | sed -e 's,^cfgs/,,' -e 's,\.cfg$,,'`-sid"
    # cd $top_builddir && make RUNTESTFLAGS="--target_board $board" check

    echo "Restoring original source files"
    cd $top_srcdir
    tar xf $builddir/edited-files.tar
    rm $builddir/edited-files.tar
}
