# $Id: whatsup.spec,v 1.1 2003-02-24 19:30:42 achu Exp $

Name:		whatsup
Version:	0.0
Release:	1

Summary:	whatsup
Group:		Applications/Communications
License:	GPL
URL:		

BuildRoot:	%{_tmppath}/%{name}-%{version}

Source0:	%{name}-%{version}.tgz

%description
whatsup is a tool that works with genders and ganglia to determine what
nodes of a cluster of up or down.  libnodeupdown is a C library that 
allows users to programmatically determine if a node is up or donw.

%prep
%setup

%build
%configure --program-prefix=%{?_program_prefix:%{_program_prefix}}
make

%install
rm -rf "$RPM_BUILD_ROOT"
mkdir -p "$RPM_BUILD_ROOT"
DESTDIR="$RPM_BUILD_ROOT" make install

%clean
rm -rf "$RPM_BUILD_ROOT"

#%pre
#if [ -x /etc/rc.d/init.d/munge ]; then
#  if /etc/rc.d/init.d/munge status | grep running >/dev/null 2>&1; then
#    /etc/rc.d/init.d/munge stop
#  fi
#fi
#
#%post
#if [ -x /etc/rc.d/init.d/munge ]; then
#  [ -x /sbin/chkconfig ] && /sbin/chkconfig --del munge
#  [ -x /sbin/chkconfig ] && /sbin/chkconfig --add munge
#  if ! /etc/rc.d/init.d/munge status | grep running >/dev/null 2>&1; then
#    /etc/rc.d/init.d/munge start
#  fi
#fi
#
#%preun
#if [ "$1" = 0 ]; then
#  if [ -x /etc/rc.d/init.d/munge ]; then
#    [ -x /sbin/chkconfig ] && /sbin/chkconfig --del munge
#    if /etc/rc.d/init.d/munge status | grep running >/dev/null 2>&1; then
#      /etc/rc.d/init.d/munge stop
#    fi
#  fi
#fi
%post
if [ "$1" = 1 ]; then
  /sbin/ldconfig %{_libdir}
fi

%postun
if [ "$1" = 0 ]; then
  /sbin/ldconfig %{_libdir}
fi

%files
%defattr(-,root,root,0755)
%doc AUTHORS
%doc COPYING
%doc ChangeLog
%doc DISCLAIMER
%doc INSTALL
%doc NEWS
%doc README
%{_bindir}/*
%{_includedir}/*
%{_libdir}/*
