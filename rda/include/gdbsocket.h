/* gdbsocket.h

   Copyright 1998, 2001, 2002 Red Hat, Inc.

   This file is part of RDA, the Red Hat Debug Agent (and library).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
   
   Alternative licenses for RDA may be arranged by contacting Red Hat,
   Inc.  */

#ifdef __cplusplus
extern "C" {
#elif 0
}
#endif

struct gdbserv;
struct gdbserv_target;
struct gdblog;

/* When non-NULL, used for logging the socket interface. */
extern struct gdblog *gdbsocket_log;


/* Generic callback function's signature */

typedef struct gdbserv_target *gdbsocket_attach_ftype (struct gdbserv *gdbserv,
						       void *attatch_data);

/* Open/create all connections in asynchronous mode.  Asynchronous
   connections will generate a SIGIO when they are ready for data
   transfer (or attach).  If enabling async, the call would normally
   occure before any sockets have been created.  By default async is
   disabled.  See samples/async.  */

void gdbsocket_async (int async_p);


/* Start a server listening on tcp port PORT_NR.  When an attatch to
   that port is received, call ATTATCH(DATA) to see if the connection
   should be accepted or rejected.  TO_ATTATCH shall return (rejecting
   the connection) or a ``struct gdbserv_target'' (accepting the
   connection).  The server allows multiple connections to the same
   port.  A typical target implementation, however, will only allow
   one active connection, returning NULL when a connection is already
   open. */

extern int gdbsocket_startup (int port_nr,
			      gdbsocket_attach_ftype *to_target_attach,
			      void *target_attatch_data);


/* Shut down the gdbserver.  Force the closure of any active remote
   sessions.  */

void gdbsocket_shutdown (void);


/* ``Re-open'' readfd/writefd as an active gdb-server connection.
   Interface is shutdown using CLOSE when EOF is detected on readfd.
   Does not need an active running gdbsocket server.  The readfd and
   writefd can have the same value.  Returns a negative value if the
   target rejects the connection, otherwise a cardinal is returned.  */

int gdbsocket_reopen (int fdin, int fdout,
		      void (*close) (int fdin, int fdout),
		      gdbsocket_attach_ftype *to_target_attach,
		      void *target_attach_data);



/* External SELECT/POLL interface.

   The interface is loosely based on UNIX select().  A set of
   read/write events to be polled is created using fd_set().
   POLL/SELECT is then called.  The list is then checked, using
   fd_isset() for any returned events. */

enum gdbsocket_fd_event {
  GDBSOCKET_FD_READ,
  GDBSOCKET_FD_WRITE
};

typedef void gdbsocket_fd_set_ftype (int fd, void *context, enum gdbsocket_fd_event event);
typedef int gdbsocket_fd_isset_ftype (int fd, void *context, enum gdbsocket_fd_event event);

/* Iterate through all of GDBSERVER's open file descriptors
   accumulating a list of events to be polled using FD_SET(). */

void gdbsocket_fd_set (gdbsocket_fd_set_ftype *fd_set, void *context);

/* Iterate through all of GDBSERVER's open file descriptors checking
   for any returned events using FD_ISSET().  Process each returned
   event. */

void gdbsocket_fd_isset (gdbsocket_fd_isset_ftype *fd_isset, void *context);

#ifdef __cplusplus
}
#endif
