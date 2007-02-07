#! /usr/bin/make -f

# To reconfigure the MeP toolchain and rebuild those bits that require
# rebuilding, run this script as follows
# ./rebuild.mk -jN [MPIFLAGS=] MEP_CONFIG="file1.cfg file2.cfg"
# Where:
#  N is the number of CPUs on your machine, for parallel builds)
#  MPIFLAGS passes options to MeP-Integrator

# This script requires GNU make and must be invoked the top of your
# build directory.

mep-reinstall:

include Makefile

.PHONY: mep-reconfig
mep-reconfig: mep-reconfig-sid \
  mep-reconfig-gcc mep-reconfig-opcodes mep-reconfig-target-libgloss 
mep-config-stmp: utils/mep/MeP-Integrator ${MEP_CONFIG}
ifneq (,${MEP_CONFIG})
ifdef MPIFLAGS
	echo 'turning on Toshiba sim api (cmodel) mode'
	./utils/mep/MeP-Integrator -v ${MPIFLAGS} -s ${srcdir} ${MEP_CONFIG}
else
	./utils/mep/MeP-Integrator -v -s ${srcdir} ${MEP_CONFIG}
endif
endif
	echo ${MEP_CONFIG} > mep-config-stmp

ifneq (${MEP_CONFIG},)
ifneq (${MEP_CONFIG},$(shell cat mep-config-stmp))
mep-config-stmp: force
force:
endif
endif

mep-reconfig-target-libgloss: mep-config-stmp
	if test -f $(TARGET_SUBDIR)/libgloss/config.status; then \
	  (cd $(TARGET_SUBDIR)/libgloss && $(SHELL) ./config.status); \
	  touch $@; \
	else \
	  true; \
	fi
mep-reconfig-opcodes: configure-opcodes
	-rm -f opcodes/stamp-mep
	@dir=opcodes; \
	if test -f $${dir}/Makefile; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) stamp-mep); \
	  touch $@; \
	else \
	  true; \
	fi
mep-reconfig-sid: configure-sid
	@dir=sid/component/cgen-cpu/mep; \
	if test -f $${dir}/Makefile; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) cgen-all); \
	  touch $@; \
	else \
	  true; \
	fi
mep-reconfig-gcc: configure-gcc
	@dir=gcc; \
	if test -f $${dir}/Makefile; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) cgen-maint); \
	  touch $@; \
	else \
	  true; \
	fi

.PHONY: mep-rebuild mep-rebuild-gcc mep-rebuild-target-libgloss
mep-rebuild: \
  all-gdb all-sid mep-rebuild-gcc mep-rebuild-target-libgloss \
  all-opcodes all-bfd all-gprof
mep-rebuild-gcc: all-binutils all-gas all-ld mep-reconfig-gcc
	@dir=gcc; \
	if [ -f ./$${dir}/Makefile ] ; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) start.encap); \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) gcc-cross); \
	else \
	  true; \
	fi
mep-rebuild-target-libgloss: mep-rebuild-gcc mep-reconfig-target-libgloss
	@dir=libgloss; \
	if [ -f $(TARGET_SUBDIR)/$${dir}/Makefile ] ; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $(TARGET_SUBDIR)/$${dir}; \
	    $(MAKE) $(TARGET_FLAGS_TO_PASS) all); \
	else \
	  true; \
	fi

.PHONY: mep-reinstall mep-reinstall-gcc mep-reinstall-gdb mep-reinstall-sid mep-reinstall-utils
mep-reinstall: \
  mep-reinstall-sid mep-reinstall-gcc mep-reinstall-gdb \
  install-gas install-ld install-binutils install-gprof \
  install-target-libgloss mep-reinstall-utils
mep-reinstall-gcc: installdirs mep-rebuild-gcc
	@dir=gcc; \
	if [ -f ./$${dir}/Makefile ] ; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) install-common install-driver); \
	else \
	  true; \
	fi
mep-reinstall-gdb: installdirs all-gdb
	@dir=gdb; \
	if [ -f ./$${dir}/Makefile ] ; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) install); \
	else \
	  true; \
	fi
mep-reinstall-sid: installdirs all-sid
	@for dir in sid/main/dynamic sid/component/cgen-cpu sid/component/families/mep; do \
	  if [ -f ./$${dir}/Makefile ] ; then \
	    r=`pwd`; export r; \
	    s=`cd $(srcdir); pwd`; export s; \
	    $(SET_LIB_PATH) \
	    (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) install); \
	  else \
	    true; \
	  fi \
	done

mep-reinstall-utils: installdirs configure-utils
	@dir=utils/mep; \
	if [ -f ./$${dir}/Makefile ] ; then \
	  r=`pwd`; export r; \
	  s=`cd $(srcdir); pwd`; export s; \
	  $(SET_LIB_PATH) \
	  (cd $${dir}; $(MAKE) $(FLAGS_TO_PASS) install); \
	else \
	  true; \
	fi

# Additional rules for parallel make
configure-opcodes: mep-config-stmp
configure-sid: mep-config-stmp
configure-gcc: mep-config-stmp
configure-utils: mep-config-stmp

all-binutils: mep-reconfig-opcodes
all-gas: mep-reconfig-opcodes
all-ld: mep-reconfig-opcodes
all-opcodes: mep-reconfig-opcodes
all-gdb: configure-gdb all-sid
all-sid: mep-reconfig-sid mep-reconfig-opcodes

install-opcodes: all-opcodes
install-gas: all-gas
install-ld: all-ld
install-bfd: all-bfd
install-binutils: all-binutils
install-gprof: all-gprof
install-target-libgloss: mep-rebuild-target-libgloss
