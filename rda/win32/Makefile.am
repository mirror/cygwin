## Process this with automake to create Makefile.in

AUTOMAKE_OPTIONS = foreign

noinst_PROGRAMS = server

INCLUDES = -I$(srcdir) -I$(srcdir)/../include

CC = gcc
CFLAGS = -g
CXXFLAGS = $(CFLAGS)


server_SOURCES = server.cc 
EXTRA_server_SOURCES = win32-target.cc win32-strace.cc child_process.cc
server_LDADD = $(TARGET_MODULES) ../lib/librda.a
server_DEPENDENCIES = $(server_OBJECTS) $(TARGET_MODULES)
