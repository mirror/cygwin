# Process this file with "automake --cygnus Makefile" to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

SUBDIRS = doc

GUILE = `if test -f ../guile/libguile/guile ; then echo ../guile/libguile/guile; else echo guile ; fi`
CGENFLAGS = -v
ARCH = @arch@

# Applications depend on stamp-cgen to tell them when .scm files have
# been changed (so files need to be regenerated).
# ??? Application specific files are kept with cgen for now, but may
# eventually go with the app.  stamp-cgen might still be useful to track
# app-independent files.

all-local: stamp-cgen

stamp-cgen: $(CGENFILES)
	rm -f stamp-cgen
	echo timestamp > stamp-cgen

# Phony targets to run each of the applications,
# though most of these are for development purposes only.
# When actually building the toolchain, the Makefile in the appropriate
# directory will run cgen.

# Build the basic description support.
# We just stuff them in tmp-* files.
# Usage: make desc ARCH=<arch> OPTIONS="<option list>"

.PHONY: desc
# FIXME: needs more dependencies
desc: desc.scm
	rm -f tmp-desc.h tmp-desc.c tmp-opinst.c
	$(GUILE) -s $(srcdir)/cgen-opc.scm \
		-s $(srcdir) \
		$(CGENFLAGS) \
		-f "$(OPTIONS)" \
		-m all -a $(ARCH) \
		-H tmp-desc.h -C tmp-desc.c

# Build the opcodes files.
# We just stuff them in tmp-* files.
# Usage: make opcodes ARCH=<arch> OPTIONS="<option list>"

.PHONY: opcodes
# FIXME: needs more dependencies
opcodes: opcodes.scm
	rm -f tmp-opc.h tmp-itab.c
	rm -f tmp-asm.in tmp-dis.in tmp-ibld.h tmp-ibld.in
	$(GUILE) -s $(srcdir)/cgen-opc.scm \
		-s $(srcdir) \
		$(CGENFLAGS) \
		-f "$(OPTIONS) opinst" \
		-m all -a $(ARCH) \
		-O tmp-opc.h -P tmp-opc.c -Q tmp-opinst.c \
		-B tmp-ibld.h -L tmp-ibld.in \
		-A tmp-asm.in -D tmp-dis.in

# Build the simulator files.
# We just stuff them in tmp-* files.
# Usage: make sim-arch ARCH=<arch> OPTIONS="<option list>"
#        make sim-cpu ARCH=<arch> ISA="<isa>" MACHS="<mach list>" \
#          OPTIONS="<option list>"

.PHONY: sim-arch sim-cpu
# FIXME: needs more dependencies
sim-arch: sim.scm
	rm -f tmp-arch.h tmp-arch.c tmp-cpuall.h
	$(GUILE) -s $(srcdir)/cgen-sim.scm \
		-s $(srcdir) \
		$(CGENFLAGS) \
		-f "$(OPTIONS)" \
		-m all -a $(ARCH) \
		-A tmp-arch.h -B tmp-arch.c -N tmp-cpuall.h
sim-cpu: sim.scm
	rm -f tmp-cpu.h tmp-cpu.c tmp-decode.h tmp-decode.c
	rm -f tmp-model.c tmp-sem.c tmp-sem-switch.c
	$(GUILE) -s $(srcdir)/cgen-sim.scm \
		-s $(srcdir) \
		$(CGENFLAGS) \
		-f "$(OPTIONS)" \
		-i "$(ISA)" -m "$(MACHS)" -a $(ARCH) \
		-C tmp-cpu.h -U tmp-cpu.c \
		-T tmp-decode.h -D tmp-decode.c \
		-M tmp-model.c \
		-S tmp-semantics.c -X tmp-sem-switch.c

# Build GAS testcase generator.

.PHONY: gas-test
gas-test: gas-test.scm cgen-gas.scm
	@if test -z "$(ISA)" ; then \
	  echo "ISA not specified!" ;\
	  exit 1 ;\
	fi
	$(GUILE) -s $(srcdir)/cgen-gas.scm \
		-s $(srcdir) \
		$(CGENFLAGS) \
		-m all \
		-i $(ISA) \
		-a $(ARCH) \
		-B gas-build.sh \
		-E gas-allinsn.exp

# Build simulator testcase generator.

.PHONY: sim-test
sim-test: sim-test.scm cgen-stest.scm
	@if test -z "$(ISA)" ; then \
	  echo "ISA not specified!" ;\
	  exit 1 ;\
	fi
	$(GUILE) -s $(srcdir)/cgen-stest.scm \
		-s $(srcdir) \
		$(CGENFLAGS) \
		-m all \
		-i $(ISA) \
		-a $(ARCH) \
		-B sim-build.sh \
		-E sim-allinsn.exp

CLEANFILES = tmp-*
