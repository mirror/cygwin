# -*- Mode:rpm-spec -*-
# sid.spec
#
# RPM build instructions (assuming rpm 4.0 or greater):
#
# In your home directory:
# =======================
#
# 1) Create a directory, rpm-build, containing the following sub-directories:
#
# 	BUILD INSTALL RPMS SOURCES SPECS SRPMS
#
# 2) Create or modify the ~/.rpmmacros file, adding the following lines:
#
#	%_topdir                $(absolute path of your home dir)/rpm-build
#    
#    This tells rpm to use ~/rpm-build as its "home base" rather than the default
#    /usr/src/redhat.  Otherwise, you'd have to be root to build the rpms.
#
# In the SOURCES sub-directory:
# =============================
#
# 3) Check out the sid-without-tcl module from CVS.
#
# 4) Create a tarball named sid.tar.gz from the CVS tree:
#
# 	tar --create --file=sid.tar src
#	gzip sid.tar
#
# 5) Copy this spec file (sid/sid.spec) into the SPECS sub-directory.
#
# In the spec file:
# =================
#
# 6) Change the homedir definition to point to your home directory.
#
# 7) Modify the BuildArchitectures tag and the build commands to reflect
#    the host and target for which you're building.
#
# In the SPECS sub-directory:
# ===========================
#
# 8) Build the RPM:
#
#	rpm -ba sid.spec
#
# The resulting RPM and source RPM will be in the RPMS and SRPMS sub-directories respectively.
#

%define homedir /home/fitzsim
%define sourcesdir src

Summary: SID is a framework for building computer system simulations.
Name: sid
Version: 0.1
Release: 1
Copyright: GPL
Group: Development/Simulators
Source: sid.tar.gz
URL: http://sources.redhat.com/sid
Prefix: /usr
BuildRoot: %{homedir}/rpm-build/INSTALL
BuildArchitectures: i686
BuildRequires: tcl >= 8.0, tk >= 8.0
Requires: tcl >= 8.0, tk >= 8.0
Packager: Thomas Fitzsimmons <fitzsim@redhat.com>
%description 
SID is a framework for building computer system simulations.
Specifically, a simulation is comprised of a collection of loosely
coupled components. Simulated systems may range from a CPU's
instruction set to a large multi-processor embedded system.

SID defines a small component interface which serves to tightly
encapsulate components.  Components may be written in C++, C, Tcl or
any other language to which the API is bound.  Typically, components
are separately compiled and packaged into shared libraries.  A
standard run-time linking/loading interface is defined for these.

%prep
%setup -n %{sourcesdir}

%build
cd ..
rm -rf bld
mkdir bld
cd bld
../%{sourcesdir}/configure --prefix=$RPM_BUILD_ROOT/usr
make

%install
# To make things work with BUILDROOT
if [ "$RPM_BUILD_ROOT" != "%{homedir}/rpm-build/INSTALL" ]
then
  echo
  echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  echo @                                                                    @
  echo @  RPM_BUILD_ROOT is not what I expected.  Please clean it yourself. @
  echo @                                                                    @
  echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  echo
else
  echo Cleaning RPM_BUILD_ROOT: "$RPM_BUILD_ROOT"
  rm -rf $RPM_BUILD_ROOT
fi
cd ..
cd bld
make install

%files
%defattr(-,root,root)
/usr/bin/arm-elf-sid
/usr/bin/i386-elf-sid
/usr/bin/configrun-sid
/usr/bin/m68k-elf-sid
/usr/bin/m32r-elf-sid
/usr/bin/mt-elf-sid
/usr/bin/xstormy16-elf-sid
/usr/bin/sid
/usr/bin/siddoc

/usr/include/sidcomp.h
/usr/include/sidso.h
/usr/include/sidtypes.h

/usr/lib/sidcomp
/usr/lib/sidsamples

/usr/share/sid

/usr/share/sidcomp

/usr/share/sidsamples

%doc ../%{sourcesdir}/sid/COPYING
%doc ../%{sourcesdir}/sid/COPYING.SID
