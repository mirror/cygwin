## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I ../../config

if SIDTARGET_ARM
FAM0DATA = arm-gloss.conf arm-gloss-tksm.conf arm-glossBE.conf arm-pid.conf arm-pid-tksm.conf arm-pidBE.conf armpid-cygmon.img arm-pid-cygmon-tksm.conf armpid-eCos.img arm-pid-cygmon.conf arm-cma.conf arm-cma-tksm.conf
else
FAM0DATA = 
endif

FAM1DATA =

FAM2DATA = 

FAM3DATA = 

FAM4DATA =

FAM5DATA =

FAM6DATA =

FAM7DATA =

ALLFAMDATA = $(FAM0DATA) $(FAM1DATA) $(FAM2DATA) $(FAM3DATA) $(FAM4DATA) \
		$(FAM5DATA) $(FAM6DATA) $(FAM7DATA)

# Don't run this makefile in parallel, at least for given targets.
.NOTPARALLEL: $(ALLFAMDATA)

pkgdata_DATA = $(ALLFAMDATA)

clean-local:
	rm -f $(ALLFAMDATA)

if MAINTAINER_MODE
$(ALLFAMDATA):	stamp-allfamdata

stamp-allfamdata: ../configrun-sid pregen-configs
	$(SHELL) pregen-configs
	touch stamp-allfamdata
endif
