/* gdbserv-target.h

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
struct gdbserv_reg;

/* The target manages threads using a 100% private target thread
   object.  A trivial thread implementation could simply map the
   thread object onto an internal thread ID using the hack: ``int
   thread_id = thread - (struct gdbserv_thread *) NULL''. */
struct gdbserv_thread;

enum gdbserv_target_rc {
  GDBSERV_TARGET_RC_ERROR = -1, /* Failed, ack with ``Enn''. */
  GDBSERV_TARGET_RC_OK = 0, /* Ok, ack with ``OK'' where applicable. */
  GDBSERV_TARGET_RC_UNKNOWN = 1 /* Not supported, or silent. */
};

enum gdbserv_target_bp {
  GDBSERV_TARGET_BP_UNKNOWN = -1,
  GDBSERV_TARGET_BP_SOFTWARE,
  GDBSERV_TARGET_BP_HARDWARE,
  GDBSERV_TARGET_BP_WRITE,
  GDBSERV_TARGET_BP_READ,
  GDBSERV_TARGET_BP_ACCESS
};


/* GDBSERV's signal encoding.  This is lifted direct from
   gdb/defs.h.  The remote protocol passes back and forth ``gdb''
   signal numbers.  It is up to the target to convert to/from a target
   signal number. */

enum {
  GDBSERV_SIGNONE = 0,
  GDBSERV_SIGHUP = 1,
  GDBSERV_SIGINT = 2, /* program execution interrupted */
  GDBSERV_SIGQUIT = 3,
  GDBSERV_SIGILL  = 4,
  GDBSERV_SIGTRAP = 5, /* program hit breakpoint */
  GDBSERV_SIGABRT = 6,
  GDBSERV_SIGEMT = 7,
  GDBSERV_SIGFPE = 8,
  GDBSERV_SIGKILL = 9,
  GDBSERV_SIGBUS = 10,
  GDBSERV_SIGSEGV = 11,
  GDBSERV_SIGSYS = 12,
  GDBSERV_SIGPIPE = 13,
  GDBSERV_SIGALRM = 14,
  GDBSERV_SIGTERM = 15,
  GDBSERV_SIGURG = 16,
  GDBSERV_SIGSTOP = 17,
  GDBSERV_SIGTSTP = 18,
  GDBSERV_SIGCONT = 19,
  GDBSERV_SIGCHLD = 20,
  GDBSERV_SIGTTIN = 21,
  GDBSERV_SIGTTOU = 22,
  GDBSERV_SIGIO = 23,
  GDBSERV_SIGXCPU = 24,
  GDBSERV_SIGXFSZ = 25,
  GDBSERV_SIGVTALRM = 26,
  GDBSERV_SIGPROF = 27,
  GDBSERV_SIGWINCH = 28,
  GDBSERV_SIGLOST = 29,
  GDBSERV_SIGUSR1 = 30,
  GDBSERV_SIGUSR2 = 31,
  GDBSERV_SIGPWR = 32,
  GDBSERV_SIGPOLL = 33,
  GDBSERV_SIGWIND = 34,
  GDBSERV_SIGPHONE = 35,
  GDBSERV_SIGWAITING = 36,
  GDBSERV_SIGLWP = 37,
  GDBSERV_SIGDANGER = 38,
  GDBSERV_SIGGRANT = 39,
  GDBSERV_SIGRETRACT = 40,
  GDBSERV_SIGMSG = 41,
  GDBSERV_SIGSOUND = 42,
  GDBSERV_SIGSAK = 43,
  GDBSERV_SIGPRIO = 44,
  GDBSERV_SIGRT33 = 45,
  GDBSERV_SIGRT34 = 46,
  GDBSERV_SIGRT35 = 47,
  GDBSERV_SIGRT36 = 48,
  GDBSERV_SIGRT37 = 49,
  GDBSERV_SIGRT38 = 50,
  GDBSERV_SIGRT39 = 51,
  GDBSERV_SIGRT40 = 52,
  GDBSERV_SIGRT41 = 53,
  GDBSERV_SIGRT42 = 54,
  GDBSERV_SIGRT43 = 55,
  GDBSERV_SIGRT44 = 56,
  GDBSERV_SIGRT45 = 57,
  GDBSERV_SIGRT46 = 58,
  GDBSERV_SIGRT47 = 59,
  GDBSERV_SIGRT48 = 60,
  GDBSERV_SIGRT49 = 61,
  GDBSERV_SIGRT50 = 62,
  GDBSERV_SIGRT51 = 63,
  GDBSERV_SIGRT52 = 64,
  GDBSERV_SIGRT53 = 65,
  GDBSERV_SIGRT54 = 66,
  GDBSERV_SIGRT55 = 67,
  GDBSERV_SIGRT56 = 68,
  GDBSERV_SIGRT57 = 69,
  GDBSERV_SIGRT58 = 70,
  GDBSERV_SIGRT59 = 71,
  GDBSERV_SIGRT60 = 72,
  GDBSERV_SIGRT61 = 73,
  GDBSERV_SIGRT62 = 74,
  GDBSERV_SIGRT63 = 75,
  GDBSERV_SIGCANCEL = 76,
  GDBSERV_SIGRT32 = 77,
  GDBSERV_SIGRT64 = 78
};



/* A target event occured.  Report back the details.

   THREAD: On multi-threaded targets, this indicates the thread that
   the event applies to. On true multi-processor systems, some events
   are system wide (eg: halting the system by stopping the clock) a
   NULL thread can be reported.  Libremote will apply a heuristic and
   select a thread that GDB is most likely to expect.  However, when
   taking the system out of reset (or reporting the startup halt
   state) a thread _must_ be supplied.

   EVENT: As defined below, indicates the exact stop reason.

   STOP_ADDR: When non-NULL indicates the address at which the THREAD
   stopped.  Intermediate layers use this value when determining if a
   target has stopped at a previously created breakpoint.  It should
   not be confused with a target architecture program counter (PC,
   NPC, NNNNNMPC).  Most targets pass NULL.

   SIGVAL: As defined below.  The exact encoding is defined by GDB.
   See gdb/defs.h ?include/gdb-signal.h?.  */

enum gdbserv_fromtarget_event {
  /* The target has stopped.  The reason, indicated by SIGVAL could be
     due to: a THREAD reaching a breakpoint (SIGTRAP); a THREAD
     encountering a breakpoint instruction (also SIGTRAP); a stop
     request to stop from the client (SIGINT); or any of a number of
     other events.  For real hardware targets, it is not always
     possible to 1:1 map between a SIGVAL and a hardware interrupt
     event.  If a target chooses to report back such events they
     should: save all the relevant interrupt information in a local
     cache; and identify the interrupt event using an approximatly
     equivalent SIGVAL.  When the target is resumed, the resume SIGVAL
     can be checked against that saved interrupt event: if SIGVAL is
     zero, that interrupt event should be discarded; if they match,
     the interrupt is delivered; and if SIGVAL is some other non-zero
     value then things are target dependant. */
  GDBSERV_FROMTARGET_STOPPED,
  /* The target has exited gracefully. SIGVAL is the exit status as
     passed to exit(3). */
  GDBSERV_FROMTARGET_EXITED,
  /* The target has died from a fatal wound.  SIGVAL is the smoking
     gun. */
  GDBSERV_FROMTARGET_TERMINATED
};

void gdbserv_fromtarget (struct gdbserv *gdbserv,
			 struct gdbserv_thread *thread,
			 enum gdbserv_fromtarget_event event,
			 const struct gdbserv_reg *stop_addr,
			 int sigval);

/* Wrapper / compatibility functions for gdbserv_fromtarget() */
void gdbserv_fromtarget_break (struct gdbserv *client, int sigval);
void gdbserv_fromtarget_thread_break (struct gdbserv *,
				      struct gdbserv_thread *thread,
				      int sigval);
void gdbserv_fromtarget_reset (struct gdbserv *client);
void gdbserv_fromtarget_exit (struct gdbserv *client, int exitval);
void gdbserv_fromtarget_terminate (struct gdbserv *client, int sigval);


/* The following send events from the client TO the TARGET. */

/* Start/resume the target.

   Return GDBSERV_TARGET_RC_OK to indicate that the program was
   successfully resumed.  Return anything else to indicate a problem.

   THREAD: If non-NULL indicates the only thread that should resume
   execution.  This provides a primative form of thread locking.
   Typically it is used to step over memory breakpoints in a
   multi-threaded environment.  Without this, there would be a window
   of oportunity that would allow other threads to sneek past the
   breakpoint.

   EVENT: The exact way that the target is to be resumed.

   START_ADDR: If non-NULL, the address at which the target should be
   resumed.  For targets with multiple PCs (PC, NPC, ...) the target
   should be set up to continue sequential execution at that address.

   SIGVAL: If non-zero, the GDB signal that should be delivered to the
   target.  Hardware targets may need to be liberal in their
   interpretation of SIGVAL.  If START_ADDR is also non-NULL then both
   operations apply - the START_ADDR is set and then SIGVAL is
   delivered. */

enum gdbserv_totarget_event {
  GDBSERV_TOTARGET_SINGLESTEP,
  GDBSERV_TOTARGET_CYCLESTEP,
  GDBSERV_TOTARGET_CONTINUE
};

enum gdbserv_target_rc gdbserv_totarget (struct gdbserv *gdbserv,
					 struct gdbserv_thread *thread,
					 enum gdbserv_totarget_event event,
					 const struct gdbserv_reg *start_addr,
					 int sigval);



struct gdbserv_target {
  /* GDB Client */

  /* Remote Qq packet methods */

  /* This is called when a "q" packet is received from the client. */
  void (*process_get_gen) (struct gdbserv *);
  
  /* This is called when a "Q" packet is received from the client. */
  void (*process_set_gen) (struct gdbserv *);

  /* This is called when a "qRcmd" packet is received from the client. */
  void (*process_rcmd) (struct gdbserv *, const char *cmd, int sizeof_cmd);

  /* This is called when an "A" packet is received from the client. */
  void (*process_set_args) (struct gdbserv *);

  /* Register Processing: old/tested */
  /* Either implement process_set_reg, process_get_regs,
     process_set_regs OR get_sizeof_reg, get_reg, set_reg. */

  /* This is called when a "P" packet is received from the client. */
  int (*process_set_reg) (struct gdbserv *, int reg);

  /* This is called when a "p" packet is received from the client. */
  int (*process_get_reg) (struct gdbserv *, int reg);

  /* This is called when a "G" packet is received from the client. */
  int (*process_set_regs) (struct gdbserv *);

  /* This is called when a "g" packet is received from the client. */
  void (*process_get_regs) (struct gdbserv *);


  /* Register Processing: new/untested/WIP */

  /* Input/Output a ``struct gdbserv_reg'' according to the target
     dependant byte ordering.  See gdbserv_input_reg_{beb,leb} and
     gdbserv_output_reg_{beb,leb}. Return a negative value to indicate
     a parse error. */
  /* Note: These methods are not per-thread - it is assumed that all
     threads have the same byte order.  Before adding support for
     per-thread byte ordering, the remote protocol should be changed
     so that registers can be transfered using network (beb) byte
     ordering - ``REGNR!VAL'' is a possible packet format. */
  int (*input_reg) (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int len);
  void (*output_reg) (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int len);

  /* Return the REG-NR for the ``I''th register in the ``Gg'' packets.
     Return a negative value when there are no more registers. Called
     iteratively starting with 0. */
  int (*gg_reg_nr) (struct gdbserv *, int index);

  /* (optional) Return the REG-NR for ``expedited'' register ``I'' in
     the ``T'' packet.  Return a negative value when there are no more
     registers.  Expedited registers help improve the remote protocol
     performance.  Called iteratively starting with 0. */
  int (*expedited_reg_nr) (struct gdbserv *, int index);

  /* Return the SIZE of a REG-NR register (as returned by REG_NR() or
     EXPEDITED_REG_NR()).  2*SIZE characters are assumed to represent
     that register in the ``Gg'' packets.  Return a negated SIZE if
     there is a ``hole'' in the G packet - data but no corresponding
     register. */
  long (*sizeof_reg) (struct gdbserv *, int regnr);

  /* Update REGNR with the value in REG. Return a negative value if
     the write breaks. */
  int (*set_reg) (struct gdbserv *, int regnr, struct gdbserv_reg *reg);

  /* Return REGNR in ``struct gdbserv_reg''. Return a negative value
     if the write breaks. */
  int (*get_reg) (struct gdbserv *, int regnr, struct gdbserv_reg *reg);


  /* Register Processing: Threaded */

  /* Return the REG-NR for the next register in the ``Gg'' packet.
     Return a negative value when there are no more registers. Called
     iteratively starting with -1. */
  int (*next_gg_reg) (struct gdbserv *, struct gdbserv_thread *,
		      int reg_nr);

  /* (optional but strongly recommended) Return the next register in
     list of ``expedited'' registers included in a ``T'' packet.
     Expedited registers help improve the remote protocol performance.
     Return a negative value when there are no more registers.  Called
     iteratively starting with -1. */
  int (*next_expedited_reg) (struct gdbserv *, struct gdbserv_thread *,
			     int reg_nr);

  /* Return the total SIZE and PADDING of a REG-NR register.  2*SIZE
     characters are assumed to represent that register in the ``Gg''
     packets.  2*PADDING characters are appended (positive) or
     prepended (negative).  */
  int (*reg_format) (struct gdbserv *, struct gdbserv_thread *,
		     int reg_nr, int *size, int *padding);

  /* Update REGNR with the value in REG. Return a negative value if
     the write breaks. */
  int (*set_thread_reg) (struct gdbserv *, struct gdbserv_thread *,
			 int regnr, const struct gdbserv_reg *reg);

  /* Return REGNR in ``struct gdbserv_reg''. Return a negative value
     if the read breaks. (eg when the register isn't available). */
  int (*get_thread_reg) (struct gdbserv *, struct gdbserv_thread *,
			 int regnr, struct gdbserv_reg *reg);


  /* Memory Processing: Transfer LEN bytes of raw memory to/from
     target. Return number of actual bytes transfered or -1 on error. */

  /* This is called when an "m" packet is received from the
     client. Return the number of bytes successfully read (could be
     less than LEN) or -1 if the read completly failed. */
  long (*get_mem) (struct gdbserv *, struct gdbserv_reg *addr, void *data,
		   long len);
  long (*get_thread_mem) (struct gdbserv *, struct gdbserv_thread *,
			  struct gdbserv_reg *addr, void *data, long len);

  /* This is called when an "M" or a "X" packet is received from the client. */
  long (*set_mem) (struct gdbserv *, struct gdbserv_reg *addr, void *data,
		   long len);
  long (*set_thread_mem) (struct gdbserv *, struct gdbserv_thread *,
			  struct gdbserv_reg *addr, void *data, long len);


  /* Other operations. */

  /* This is called when a "c" or "s" packet is received from the client
     with a address to continue/step from.
     It is called before the appropriate continue/step callback is invoked. */
  void (*process_set_pc) (struct gdbserv *, const struct gdbserv_reg *val);

  /* This is called when a "C", "c", "s" or "S" packet is received
     from the client.  It should invalidate all instruction caches.
     It is called before the appropriate continue/step callback is invoked. */
  void (*flush_i_cache) (struct gdbserv *);

  /* For non-threaded targets, this is called when a "C" or "S" packet
     is received from the client specifying a signal to be delivered
     to the application.  Threaded targets have the signal passed
     directly to the resume method.
     It is called before the appropriate continue/step callback is invoked. */
  int (*process_signal) (struct gdbserv *, int sigval);

  /* This is called when an "?" packet is received from the client.
     It is called after the get_trap_number() callback to convert target traps
     into an equivalent (or approx. equivalent) UNIX signal. */
  unsigned long (*compute_signal) (struct gdbserv *, unsigned long);

  /* This is called when an "?" packet is received from the client.
     It returns the target trap number which will be converted to UNIX
     signals by the compute_signal() callback before being sent to gdb.  */
  unsigned long (*get_trap_number) (struct gdbserv *);


  /* Program state methods */

  /* This is called when a "k" packet is received from the client. */
  void (*exit_program) (struct gdbserv *);

  /* This is called when a request to halt / suspend / break the
     target is received from the client.  When/if the target does
     halt, gdbserv is notified via a call to
     gdbserv_fromtarget_break().  The break_program() method must not
     make a direct call to gdbserv_fromtarget_break().  */
  void (*break_program) (struct gdbserv *);

  /* This is called when a "r" packet is received from the client. */
  int (*reset_program) (struct gdbserv *);

  /* This is called when a "R" packet is received from the client. */
  void (*restart_program) (struct gdbserv *);

  /* This is called when a "s" or a "S" packet is received from the
     client.  For thread variant, a NULL thread indicates that the
     system should be single stepped. */
  void (*singlestep_program) (struct gdbserv *);
  void (*singlestep_thread) (struct gdbserv *, struct gdbserv_thread *,
			     const struct gdbserv_reg *signnal);

  /* This is called when an "i" packet is received from the client.
     For thread variant, a NULL thread indicates that the system
     should be cycle stepped and a non-null SIGGNAL should be
     delivered. */
  void (*cyclestep_program) (struct gdbserv *);
  void (*cyclestep_thread) (struct gdbserv *, struct gdbserv_thread *,
			    const struct gdbserv_reg *signnal);

  /* This is called when a "c" or a "s" packet is received from the
     client.  For thread variant, a NULL thread indicates that the
     system should be continued and a non-null SIGGNAL should be
     delivered. */
  void (*continue_program) (struct gdbserv *);
  void (*continue_thread) (struct gdbserv *, struct gdbserv_thread *,
			   const struct gdbserv_reg *signnal);

  /* This is called when a "C" or "S" packet is received from the
     client specifying a signal to be delivered to the application and
     we don't have a process_signal() callback to handle this
     situation or it exists but could not/wanted not handle the
     specific signal.  The step/continue is not performed in this case
     and the application is terminated. */
  void (*sigkill_program) (struct gdbserv *);


  /* Breakpoint methods */

  /* This is called when a "Z" packet is received from the client. */
  enum gdbserv_target_rc (*remove_breakpoint) (struct gdbserv *,
					       enum gdbserv_target_bp type,
					       struct gdbserv_reg *addr,
					       struct gdbserv_reg *len);

  /* This is called when a "z" packet is received from the client. */
  enum gdbserv_target_rc (*set_breakpoint) (struct gdbserv *,
					    enum gdbserv_target_bp type,
					    struct gdbserv_reg *addr,
					    struct gdbserv_reg *len);


  /* Thread info methods */

  /* Create a freshly allocated string containing extr thread info. */
  char *(*thread_info) (struct gdbserv *, struct gdbserv_thread *thread);

  /* A unique ID for the thread. */
  void (*thread_id) (struct gdbserv *, struct gdbserv_thread *thread,
		     struct gdbserv_reg *id);

  /* Map a thread ID onto a thread.  Return a positive value if the ID
     uniquely identifies a thread.  Return ``0'' and select an
     arbitrary thread if the thread ID is zero.  Return ``-1'' and set
     the thread to a an arbitrary value if the ID does not uniquely
     identify a thread or if the thread ID is invalid. */
  int (*thread_lookup_by_id) (struct gdbserv *,
			      const struct gdbserv_reg *id,
			      struct gdbserv_thread **);

  /* Iterate over known threads.  Use NULL to obtain the first
     thread. */
  struct gdbserv_thread *(*thread_next) (struct gdbserv *, struct gdbserv_thread *thread_last);


  /* misc methods */

  /* This is called when an unidentified/unrecognized packet (i.e., one that
   does not start with one of the letters used by the remote protocol) is
   received from the client. */
  void (*process_target_packet) (struct gdbserv *);

  /* shutdown */

  /* This is called when an EOF is sensed on the socket.
     This is *not* called when a "D" packet is received from the client.
     The SERVER code reacts to the "D" packet as a nop (i.e., accepts it but
     does not do anything) because the client will eventually close the
     socket and we will sense the EOF. 
     The second parameter is necessary so that the target can free the
     memory allocated for the target vector in the attach method, if
     needed.*/
  void (*detach) (struct gdbserv *, struct gdbserv_target *);

  /* Instance specific data.  GDBSERV can manage multiple clients each
     accessing a separate target.  The per-target DATA pointer can
     hold target instance specific data.  Use gdbserv_target_data() to
     access this field. */
  void *data;

  /* Pass event FROM TARGET to server. */
  void (*from) (struct gdbserv *gdbserv,
		struct gdbserv_thread *thread,
		enum gdbserv_fromtarget_event event,
		const struct gdbserv_reg *stop_addr,
		int sigval);

  /* Pass event TO TARGET from SERVER. */
  enum gdbserv_target_rc (*to) (struct gdbserv *gdbserv,
				struct gdbserv_thread *thread,
				enum gdbserv_totarget_event event,
				const struct gdbserv_reg *start_addr,
				int sigval);
};


/* Return the target instance specific data from the GDBSERV. */

void *gdbserv_target_data (struct gdbserv *gdbserv);


#ifdef __cplusplus
}
#endif
