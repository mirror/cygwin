/* gdbsocket.c

   Copyright 1998, 2000, 2001, 2002 Red Hat, Inc.

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

#include "config.h"

#include <sys/types.h>
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#if HAVE_NETINET_TCP_H
#include <netinet/tcp.h>
#endif
#include <signal.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>

#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif

#include <sys/file.h>
#include <fcntl.h>

#include "gdbserv-client.h"
#include "gdbsocket.h"
#include "gdblog.h"


/* Database of servers and their sessions. */

struct session {
  void (*close) (int readfd, int writefd);
  int readfd;
  int writefd;
  struct gdbserv *gdbserv;
  struct session *next;
};

static struct session *session_db;

/* Database of servers accepting connections. */

struct server {
  int fd;
  gdbsocket_attach_ftype *to_target_attach;
  void *target_attach_data;
  struct server *next;
};

static struct server *server_db;


struct gdblog *gdbsocket_log = NULL;


static void
nonblocking_fd (int fd)
{
#if defined(F_SETFL) && (defined (O_ASYNC) || defined (O_NONBLOCK))
  int flags = fcntl (fd, F_GETFL, 0);
  if (gdbsocket_log)
    {
      gdblog_string (gdbsocket_log, "[");
      gdblog_long (gdbsocket_log, fd);
      gdblog_string (gdbsocket_log, ":");
    }
#if defined (O_NONBLOCK)
  flags |= O_NONBLOCK;
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, " O_NONBLOCK");
#endif
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "]\n");
  fcntl (fd, F_SETFL, flags);
#endif
}

static int gdbsocket_async_p;

void
gdbsocket_async (int async_p)
{
  gdbsocket_async_p = 1;
}

static void
async_fd (int fd)
{
  int flags;
  if (!gdbsocket_async_p)
    return;
  gdblog_string (gdbsocket_log, "[");
  gdblog_long (gdbsocket_log, fd);
#if defined(F_SETFL) && (defined (O_ASYNC) || defined (O_NONBLOCK))
  flags = fcntl (fd, F_GETFL, 0);
#if defined (O_ASYNC)
  flags |= O_ASYNC;
  gdblog_string (gdbsocket_log, " O_ASYNC");
#elif defined (FASYNC)
  flags |= FASYNC;
  gdblog_string (gdbsocket_log, " FASYNC");
#endif
  fcntl (fd, F_SETFL, flags);
#endif
#if defined (F_SETOWN)
  /* some systems don't set the process to deliver the SIGIO to. */
  flags = fcntl (fd, F_GETOWN, 0);
  if (flags == 0)
    {
      flags = getpid ();
      fcntl (fd, F_SETOWN, flags);
      gdblog_string (gdbsocket_log, " [OWN ");
      gdblog_long (gdbsocket_log, flags);
      gdblog_string (gdbsocket_log, "]");
    }
#endif
  gdblog_string (gdbsocket_log, "]\n");
}

#if 0
static void
sync_fd (int fd)
{
#if defined(F_SETFL) && (defined (O_ASYNC) || defined (O_NONBLOCK))
  int flags = fcntl (fd, F_GETFL, 0);
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "[%d:", fd);
#if defined (O_ASYNC)
  flags &= ~O_ASYNC;
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, " O_ASYNC");
#endif
#if defined (FASYNC)
  flags &= ~FASYNC;
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, " FASYNC");
#endif
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "]\n");
  fcntl (fd, F_SETFL, flags);
#endif
}
#endif


/* Create a GDB server socket on PORT. */

int
gdbsocket_startup (int port_nr,
		   gdbsocket_attach_ftype *to_target_attach,
		   void *target_attach_data)
{
  int on;
  struct sockaddr_in sockaddr;
  struct server *server;
  int server_fd;

  if (gdbsocket_log)
    {
      gdblog_string (gdbsocket_log, "[gdbsocket_startup port_nr=");
      gdblog_long (gdbsocket_log, port_nr);
    }

  /* Create our socket */
  server_fd = socket (PF_INET, SOCK_STREAM, 0);
  if (server_fd < 0)
    return -1;
  if (gdbsocket_log)
    {
      gdblog_string (gdbsocket_log, " fd=");
      gdblog_long (gdbsocket_log, server_fd);
    }
  
  /* allow reuse */
  on = 1;
  setsockopt (server_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof (on));
  on = 1;
  setsockopt (server_fd, SOL_SOCKET, SO_KEEPALIVE, (char*)&on, sizeof (on));
      
  /* bind it to the requested UDP port */
  sockaddr.sin_family = PF_INET;
  sockaddr.sin_addr.s_addr = htonl (INADDR_ANY);
  sockaddr.sin_port = htons (port_nr);
  if (bind (server_fd, (struct sockaddr *)&sockaddr, sizeof (sockaddr)) < 0)
    {
      int te = errno;
      close (server_fd);
      gdblog_string (gdbsocket_log, " BIND ERROR]\n");
      errno = te;
      return -1;
    }

  listen (server_fd, 1);

  /* Don't let a closed pipe kill us */
  signal (SIGPIPE, SIG_IGN);

  nonblocking_fd (server_fd);
  async_fd (server_fd);

  /* Add this to the server database. */
  server = malloc (sizeof (struct server));
  if (!server)
    {
      int te = errno;
      gdblog_string (gdbsocket_log, " MEMORY ERROR]\n");
      close (server_fd);
      errno = te;
      return -1;
    }
  server->fd = server_fd;
  server->to_target_attach = to_target_attach;
  server->target_attach_data = target_attach_data;
  server->next = server_db;
  server_db = server;

  if (gdbsocket_log)
    {
      gdblog_string (gdbsocket_log, "]\n");
    }

  return server_fd;
}

void
gdbsocket_shutdown (void)
{
  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "[gdbsocket_shutdown");
  
  while (session_db != NULL)
    {
      struct session *tbd = session_db;
      session_db = tbd->next;
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, " session=");
	  gdblog_long (gdbsocket_log, tbd->readfd);
	  gdblog_string (gdbsocket_log, "/");
	  gdblog_long (gdbsocket_log, tbd->writefd);
	}
      tbd->close (tbd->readfd, tbd->writefd);
      free (tbd);
    }

  while (server_db != NULL)
    {
      struct server *tbd = server_db;
      server_db = tbd->next;
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, " server=");
	  gdblog_long (gdbsocket_log, tbd->fd);
	}
      close (tbd->fd);
      free (tbd);
    }

  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "]\n");
}



/* Poll the server port along with any active connections.  TIMEOUT=0
   do not block; TIMEOUT<0 -> infinite block; TIMEOUT>0 specifies nr
   seconds.

   Returns the _NEXT_ session after this one.  If this session is
   closed (EOF) it is unlinked.  FIXME: cagney/2000-04-24: This
   behavour needs to be eliminated.  It makes it very hard to process
   both input and output events. */

static void
dump_buf (const char *buf, int len)
{
  int i;
  for (i = 0; i < len; i++)
    {
      unsigned char ch = buf[i];
      if ((ch >= 32 && ch < 127) && isprint (ch))
	gdblog_char (gdbsocket_log, ch & 0x7f);
      else
	{
	  gdblog_char (gdbsocket_log, '\\');
	  gdblog_char (gdbsocket_log, '0' + ((ch >> 6) & 0x3));
	  gdblog_char (gdbsocket_log, '0' + ((ch >> 3) & 0x7));
	  gdblog_char (gdbsocket_log, '0' + ((ch >> 0) & 0x7));
	}
    }
}

static struct session **
process_read (struct session **session)
{
  unsigned char buf[2048];
  int nr;
  nr = read ((*session)->readfd, buf, sizeof buf);
  if (nr > 0)
    {
      if (gdbsocket_log)
	{
	  int i;
	  gdblog_string (gdbsocket_log, "[");
	  gdblog_long (gdbsocket_log, (*session)->readfd);
	  gdblog_string (gdbsocket_log, "->");
	  gdblog_long (gdbsocket_log, nr);
	  gdblog_string (gdbsocket_log, " ");
	  dump_buf (buf, nr);
	  gdblog_string (gdbsocket_log, " ]\n");
	}
      if (nr == 5 && buf[0] == 0xff && buf[1] == 0xf4
	  && buf[2] == 0xff && buf[3] == 0xfd && buf[4] == 0x06)
	/* If a user telnets into the gdb server and then hits CNTRL-C
           the server receives the above 5 byte character sequence.
           Convert that sequence into a break. */
	gdbserv_fromclient_break ((*session)->gdbserv);
      else
	gdbserv_fromclient_data ((*session)->gdbserv, buf, nr);
    }
  else if (nr == 0 || (nr < 0 && ((errno == ESHUTDOWN) || errno==ECONNRESET)))
    {
      struct session *tbd = (*session);
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, "[read ");
	  gdblog_long (gdbsocket_log, tbd->readfd);
	  gdblog_string (gdbsocket_log, " EOF]\n");
	}
      gdbserv_fromclient_detach ((*session)->gdbserv);
      tbd->close (tbd->readfd, tbd->writefd);
      (*session) = tbd->next;
      free (tbd);
      return session;
    }
  else if (nr < 0 && errno == EAGAIN)
    {
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, "[read ");
	  gdblog_long (gdbsocket_log, (*session)->readfd);
	  gdblog_string (gdbsocket_log, " EAGAIN]\n");
	}
    }
  return &(*session)->next;
}


static void
raw_write (struct gdbserv *gdbserv,
	   const unsigned char *buf,
	   unsigned len)
{
  struct session *server = gdbserv_client_data (gdbserv);
  int nr = write (server->writefd, buf, len);
  if (nr < len)
    {
      printf ("OOPS!\n");
    }
  if (gdbsocket_log)
    {
      int i;
      gdblog_string (gdbsocket_log, "[");
      gdblog_long (gdbsocket_log, server->writefd);
      gdblog_string (gdbsocket_log, "<-");
      gdblog_long (gdbsocket_log, len);
      gdblog_string (gdbsocket_log, " ");
      dump_buf (buf, len);
      gdblog_string (gdbsocket_log, " ]\n");
    }
}


int
gdbsocket_reopen (int fdin, int fdout,
		  void (*close) (int fdin, int fdout),
		  gdbsocket_attach_ftype *to_target_attach,
		  void *target_attach_data)
{
  struct session **session;
  struct gdbserv_client *client;
  /* create/append the new session */
  for (session = &session_db;
       (*session) != NULL;
       session = &(*session)->next)
    /*NOP*/;
  (*session) = malloc (sizeof (struct session));
  memset ((*session), 0, sizeof (struct session));
  /* fill it in */
  (*session)->readfd = fdin;
  (*session)->writefd = fdout;
  (*session)->close = close;
  (*session)->next = NULL;
  client = malloc (sizeof (struct gdbserv_client));
  client->write = raw_write;
  client->data = (*session);
  /* check that the target is willing to handle another accept */
  (*session)->gdbserv = gdbserv_fromclient_attach (client,
						   to_target_attach,
						   target_attach_data);
  if ((*session)->gdbserv == NULL)
    {
      free (client);
      free ((*session));
      (*session) = NULL;
      return -1;
    }
  return 0;
}


static void
session_close (int readfd, int writefd)
{
  close (readfd);
  if (readfd != writefd)
    close (writefd);
}


static void
process_accept (struct server *server)
{
  struct sockaddr_in sockaddr;
  int sizeof_sockaddr = sizeof (sockaddr);
  int fd = accept (server->fd,
		   (struct sockaddr*)&sockaddr,
		   &sizeof_sockaddr);
  if (fd >= 0)
    {
      if (gdbsocket_reopen (fd, fd, session_close,
			    server->to_target_attach,
			    server->target_attach_data)
	  < 0)
	{
	  close (fd);
	  if (gdbsocket_log)
	    {
	      gdblog_string (gdbsocket_log, "[open ");
	      gdblog_long (gdbsocket_log, fd);
	      gdblog_string (gdbsocket_log, " - reject]\n");
	    }
	  return;
	}
      /* configure the socket */
      {
	int on = 1;
	/* Do not delay send to coalesce packets */
	setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, (char *)&on, sizeof (on));
	nonblocking_fd (fd);
	async_fd (fd);
      }
      /* NOTE: There is a small window of oportunity between the time
         that this process accepts the connection and the time that
         the connection is marked as asynchronous.  During this window
         the remote target could (and typically does!) stuff data into
         the socket.  To avoid any problems, force a SIGIO and hence a
         re-read. */
      if (gdbsocket_async_p)
	kill (getpid (), SIGIO);
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, "[open ");
	  gdblog_long (gdbsocket_log, fd);
	  gdblog_string (gdbsocket_log, "]\n");
	}
    }
}

void
gdbsocket_fd_set (gdbsocket_fd_set_ftype *fd_set, void *context)
{
  struct session *session;
  struct server *server;

  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "[fd_set");

  /* Wait on all the clients. */
  for (session = session_db;
       session != NULL;
       session = session->next)
    {
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, " ");
	  gdblog_long (gdbsocket_log, session->readfd);
	  gdblog_string (gdbsocket_log, "/");
	  gdblog_long (gdbsocket_log, session->writefd);
	}
      fd_set (session->readfd, context, GDBSOCKET_FD_READ);
#if 0
      fd_set (session->writefd, context, GDBSOCKET_FD_WRITE);
#endif
    }
  
  /* wait on the server port */
  for (server = server_db;
       server != NULL;
       server = server->next)
    {
      fd_set (server->fd, context, GDBSOCKET_FD_READ);
      if (gdbsocket_log)
	{
	  gdblog_string (gdbsocket_log, " ");
	  gdblog_long (gdbsocket_log, server->fd);
	}
    }

  if (gdbsocket_log)
    gdblog_string (gdbsocket_log, "]\n");
}

void
gdbsocket_fd_isset (gdbsocket_fd_isset_ftype *fd_isset, void *context)
{
  struct session **session;
  struct server *server;
  /* Is there data available on an existing connection? */
  session = &session_db;
  while ((*session) != NULL)
    {
      if (fd_isset ((*session)->readfd, context, GDBSOCKET_FD_READ))
	{
	  session = process_read (session);
	}
#if 0
      /* FIXME: Before this can be enabled, process_read() needs to be
         changed so that it is easier to detect/handle a read that
         caused a file to be closed. */
      if (fd_isset ((*session)->writefd, context, GDBSOCKET_FD_WRITE))
	{
	  session = process_write (session);
	}
#endif
      else
	session = &(*session)->next;
    }
  
  /* Is there a request for a new connection? */
  for (server = server_db;
       server != NULL;
       server = server->next)
    {
      if (fd_isset (server->fd, context, GDBSOCKET_FD_READ))
	{
	  process_accept (server);
	}
    }
}
