// hostops.h - Wrapper class around host OS calls.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef HOSTOPS_H
#define HOSTOPS_H

// ??? better place?
typedef sid::host_int_4 uint32;
typedef sid::signed_host_int_4 int32;
typedef sid::host_int_8 uint64;
typedef sid::signed_host_int_8 int64;

typedef uint32 address32;
typedef uint32 size32;
typedef int32 offset32;

typedef uint64 address64;
typedef uint64 size64;
typedef int64 offset64;

class hostops
{
public:

  hostops () {}

  // `flags' argument to open.
  enum open_flags
  {
    open_read_only = 1,
    open_write_only = 2,
    open_read_write = 3,
    // mask of previous 3 values
    open_acc_mode = 3,
    open_text = 4,
    open_create = 8,
    open_trunc = 16,
    open_append = 32,
    open_nonblock = 64
  };

  // `how' argument to lseek.
  enum seek_type { seek_set = 0, seek_cur = 1, seek_end = 2 };

  // Separate 32 bit and 64 bit support.
  // We want correct semantics for 32/64 target on 32/64 host.
  // ??? May also be useful for large file support on 32 bit hosts.
  int open_flags_to_host (int flags);
  bool open (const char* filename, int flags,
	     int& result_fd, int& errcode);
  bool open (const char* filename, int flags, int mode,
	     int& result_fd, int& errcode);
  bool close (int fd, int& errcode);
  bool read32 (int fd, char* buf, size32 len,
	       size32& len_read, int& errcode);
  bool write32 (int fd, const char* buf, size32 len,
		size32& len_written, int& errcode);
  bool remove (const char* filename, int& errcode);
  bool rename (const char* oldname, const char* newname, int& errcode);
  bool lseek32 (int fd, offset32 offset, seek_type how,
		size32& result, int& errcode);
  bool getsize32 (int fd, size32& size, int& errcode);
  bool tmpnam (char* filename, int& errcode);
};

#endif // HOSTOPS_H
