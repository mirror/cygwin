// hostops.cxx - System call inteface routines.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <cassert>

#include <sidtypes.h>

#include "hostops.h"

int
hostops::open_flags_to_host (int flags)
{
  int host_flags = 0;

  switch (flags & open_acc_mode)
    {
    case open_read_only : host_flags = O_RDONLY; break;
    case open_write_only : host_flags = O_WRONLY; break;
    case open_read_write : host_flags = O_RDWR; break;
    default : assert (("bad open access mode", 0));
				// expr on left hand of comma has no effect.
    }

#ifdef O_TEXT
  if ((flags & open_text) != 0)
    host_flags |= O_TEXT;
#endif
#ifdef O_BINARY
  if ((flags & open_text) == 0)
    host_flags |= O_BINARY;
#endif

  if ((flags & open_create) != 0)
    host_flags |= O_CREAT;

  if ((flags & open_trunc) != 0)
    host_flags |= O_TRUNC;

  if ((flags & open_append) != 0)
    host_flags |= O_APPEND;

#ifdef O_NONBLOCK
  if ((flags & open_nonblock) != 0)
    host_flags |= O_NONBLOCK;
#elif defined (O_NDELAY)
  if ((flags & open_nonblock) != 0)
    host_flags |= O_NONBLOCK;
#endif

  return host_flags;
}

bool
hostops::open (const char* filename, int flags, int& result_fd, int& errcode)
{
  int fd;

  fd = ::open (filename, open_flags_to_host (flags));
  if (fd < 0)
    {
      errcode = errno;
      return false;
    }
  result_fd = fd;
  return true;
}

bool
hostops::open (const char* filename, int flags, int mode, int& result_fd, int& errcode)
{
  int fd;

  fd = ::open (filename, open_flags_to_host (flags), mode);
  if (fd < 0)
    {
      errcode = errno;
      return false;
    }
  result_fd = fd;
  return true;
}

bool
hostops::close (int fd, int& errcode)
{
  /* don't close the host's stdin, stdout, and stderr */
  if (fd > 2)
    {	
      if (::close (fd) < 0)
        {
          errcode = errno;
          return false;
        }
    }
  return true;
}

bool
hostops::read32 (int fd, char* buf, size32 len,
		 size32& len_read, int& errcode)
{
  ssize_t rc = ::read (fd, buf, len);
  if (rc == -1)
    {
      errcode = errno;
      return false;
    }
  len_read = rc;
  return true;
}

bool
hostops::write32 (int fd, const char* buf, size32 len,
		  size32& len_written, int& errcode)
{
  ssize_t rc = ::write (fd, buf, len);
  if (rc == -1)
    {
      errcode = errno;
      return false;
    }
  len_written = rc;
  return true;
}

bool
hostops::remove (const char* filename, int& errcode)
{
  if (::unlink (filename) < 0)
    {
      errcode = errno;
      return false;
    }
  return true;
}

bool
hostops::rename (const char* oldname, const char* newname, int& errcode)
{
  if (::rename (oldname, newname) < 0)
    {
      errcode = errno;
      return false;
    }
  return true;
}

bool
hostops::lseek32 (int fd, offset32 offset, seek_type how, size32& result, int& errcode)
{
  offset32 result_tmp;
  int int_how;

  switch (how)
    {
    case seek_set : int_how = SEEK_SET; break;
    case seek_cur : int_how = SEEK_CUR; break;
    case seek_end : int_how = SEEK_END; break;
    default : errcode = EINVAL; return false;
    }

  result_tmp = ::lseek (fd, offset, int_how);
  if (result_tmp == -1)
    {
      errcode = errno;
      return false;
    }
  result = result_tmp;
  return true;
}

bool
hostops::getsize32 (int fd, size32& size, int& errcode)
{
  struct stat st;
  if (fstat (fd, &st) < 0)
    {
      errcode = errno;
      return false;
    }
  size = st.st_size;
  return true;
}

bool
hostops::tmpnam (char* filename, int& errcode)
{
  char* filename_ptr;

  filename_ptr = ::tmpnam (filename);
  if (filename_ptr == NULL)
    {
      errcode = errno;
      return false;
    }
  return true;
}
