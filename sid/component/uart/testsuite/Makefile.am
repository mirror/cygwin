## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

INCLUDES = -I. -I../../../include -I$(srcdir)/../../../include -I$(srcdir)/..

check_PROGRAMS = uart-driver

uart_driver_SOURCES = driver.cxx Devices.cxx Devices.h uart-def.h 
uart_driver_DEPENDENCIES = ../libuart.la ../../sched/libsched.la
uart_driver_LDADD = ../libuart.la ../../sched/libsched.la

TESTS = uart-driver
