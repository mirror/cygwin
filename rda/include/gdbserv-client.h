/* gdbserv-client.h -- Facilities for communicating with remote client
   using GDB remote protocol.

   Copyright 1998, 2000, 2002 Red Hat, Inc.

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

struct gdbserv_client {
  void *data;
  /* Write LEN characters to the remote client. */
  void (*write) (struct gdbserv *gdbserv, const unsigned char *ch,
		 unsigned len);
};

void *gdbserv_client_data (struct gdbserv *gdbserv);


/* This is a call into the target so that it to is notified of the
   connecting client.  The target can reject the connection by
   returning NULL */

/* Notify the server that the client has initiated a connection.
   Returns a GDBSERV struct for the session (or null if the target
   rejected the connect).  The server will, in turn, pass the request
   onto the target.  The target can either reject the connection
   (returning NULL) or accept the connection (returning a target
   object). */

typedef struct gdbserv_target *(gdbserv_target_attach) (struct gdbserv *gdbserv,
							void *attatch_data);

struct gdbserv *gdbserv_fromclient_attach (struct gdbserv_client *gdbclient,
					   gdbserv_target_attach *to_target_attach,
					   void *target_attach_data);


/* Notify the server that the client has disconnected. */

void gdbserv_fromclient_detach (struct gdbserv *gdbserv);



/* The low level client code pumps packets/data into GDBSERV using the
   following. */

/* Raw characters from the client<->server. */

void gdbserv_fromclient_data (struct gdbserv *gdbserv, const char *data,
			      int sizeof_data);

/* The remote client has requested that the target ``break'' (halt).
   Notify gdbserv of the request so that it can pass it through to the
   target (using gdbserv_target->break_program()). */

void gdbserv_fromclient_break (struct gdbserv *gdbserv);

#ifdef __cplusplus
}
#endif
