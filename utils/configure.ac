AC_INIT
AC_PREREQ([2.59])
AC_CONFIG_SRCDIR([Makefile.in])

AC_PROG_INSTALL
AC_CANONICAL_TARGET

if test -d ${srcdir}/spu ; then
  configdirs="spu"
fi

case "${target}" in
  mep*-*)
    if test -d ${srcdir}/mep ; then
       configdirs="$configdirs mep"
    fi   
    ;;
  *mips*-*-pe* | *sh*-*-pe* | *arm*-*-wince | *arm*-wince-pe* )
    if test -d ${srcdir}/wince ; then
      configdirs="$configdirs wince"
    fi
    ;;
esac

all_subdirs=""
install_subdirs=""
mostlyclean_subdirs=""
clean_subdirs=""
distclean_subdirs=""
maintainer_clean_subdirs=""

for dir in $configdirs ; do
    all_subdirs="${all_subdirs} all-$dir"
    install_subdirs="${install_subdirs} install-$dir"
    mostlyclean_subdirs="${mostlyclean_subdirs} mostlyclean-$dir"
    clean_subdirs="${clean_subdirs} clean-$dir"
    distclean_subdirs="${distclean_subdirs} distclean-$dir"
    maintainer_clean_subdirs="${maintainer_clean_subdirs} maintainer-clean-$dir"
done

AC_SUBST([all_subdirs])
AC_SUBST([install_subdirs])
AC_SUBST([mostlyclean_subdirs])
AC_SUBST([clean_subdirs])
AC_SUBST([distclean_subdirs])
AC_SUBST([maintainer_clean_subdirs])

case "${srcdir}" in
  [[\\/]]* | ?:[[\\/]]* ) # Absolute
    this_srcdir=${srcdir}
    ;;
  *) 
    this_srcdir="../${srcdir}"
    ;;
esac
AC_SUBST([this_srcdir])

case "${cache_file}" in
  [[\\/]]* | ?:[[\\/]]* ) # Absolute
    this_cache_file=${cache_file}
    ;;
  *) 
    this_cache_file="../${cache_file}"
    ;;
esac
subconfigure_args=${ac_configure_args}
subconfigure_args="${subconfigure_args} --cache-file=${this_cache_file} --srcdir=${this_srcdir}"
AC_SUBST([subconfigure_args])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

