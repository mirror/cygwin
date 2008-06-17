/*
 * gdbserv-target.h -- part of GDB remote server.
 *
 * Copyright (C) 2000, 2002, 2006 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


struct gdbserv;

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


struct gdbserv_target {
  /* GDB Client */

  /* Remote Qq packet methods */
  void (*process_get_gen) (struct gdbserv *);
  void (*process_set_gen) (struct gdbserv *);
  void (*process_rcmd) (struct gdbserv *, const char *cmd, int sizeof_cmd);

  void (*process_set_args) (struct gdbserv *);

  /* Register Processing: old/tested */
  /* Either implement process_set_reg, process_get_regs,
     process_set_regs OR get_sizeof_reg, get_reg, set_reg. */
  int (*process_set_reg) (struct gdbserv *, int reg);
  int (*process_set_regs) (struct gdbserv *);
  void (*process_get_regs) (struct gdbserv *);

  /* Deprecated / SID Only. */
  void (*process_get_reg) (struct gdbserv *, int reg);
  void (*process_get_exp_regs) (struct gdbserv *);


  /* Register Processing: new/untested/WIP */

  /* Input/Output a ``struct gdbserv_reg'' according to the target
     dependant byte ordering.  See gdbserv_input_reg_{beb,leb} and
     gdbserv_output_reg_{beb,leb}. Return a negative value to indicate
     a parse error. */
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

  /* Deprecated / SID only. */
  void (*process_get_mem) (struct gdbserv *, struct gdbserv_reg *addr, struct gdbserv_reg *len);
  void (*process_set_mem) (struct gdbserv *, struct gdbserv_reg *addr, struct gdbserv_reg *len, int binary);


  /* Memory Processing: Transfer LEN bytes of raw memory to/from
     target. Return number of actual bytes transfered or -1 on
     error. */
  long (*get_mem) (struct gdbserv *, struct gdbserv_reg *addr, void *data, long len);
  long (*set_mem) (struct gdbserv *, struct gdbserv_reg *addr, void *data, long len);

  /* Other operations. */
  void (*process_set_pc) (struct gdbserv *, struct gdbserv_reg *val);
  int (*process_signal) (struct gdbserv *, int sigval);

  void (*flush_i_cache) (struct gdbserv *);

  unsigned long (*compute_signal) (struct gdbserv *, unsigned long);
  unsigned long (*get_trap_number) (struct gdbserv *);


  /* Program state methods */
#if 0 /* ASVP */
  void (*exit_program) (struct gdbserv *);
  void (*break_program) (struct gdbserv *);
  int (*reset_program) (struct gdbserv *);
  void (*restart_program) (struct gdbserv *);
  void (*singlestep_program) (struct gdbserv *);
  void (*cyclestep_program) (struct gdbserv *);
  void (*sigkill_program) (struct gdbserv *);
  void (*continue_program) (struct gdbserv *);
#else /* SID */
  int (*exit_program) (struct gdbserv *);
  int (*break_program) (struct gdbserv *);
  int (*reset_program) (struct gdbserv *);
  void (*restart_program) (struct gdbserv *);
  int (*singlestep_program) (struct gdbserv *);
  int (*rangestep_program) (struct gdbserv *, 
			    struct gdbserv_reg *range_start, 
			    struct gdbserv_reg *range_end);
  void (*cyclestep_program) (struct gdbserv *);
  void (*sigkill_program) (struct gdbserv *);
  int (*continue_program) (struct gdbserv *);
  int (*set_exec_direction) (struct gdbserv *, const char *direction);
#endif

  /* Breakpoint methods */
#if 0 /* ASVP */
  enum gdbserv_target_rc (*remove_breakpoint) (struct gdbserv *,
					       enum gdbserv_target_bp type,
					       struct gdbserv_reg *addr,
					       struct gdbserv_reg *len);
  enum gdbserv_target_rc (*set_breakpoint) (struct gdbserv *,
					    enum gdbserv_target_bp type,
					    struct gdbserv_reg *addr,
					    struct gdbserv_reg *len);
#else /* SID */
  int (*remove_breakpoint) (struct gdbserv *, unsigned long type, 
			    struct gdbserv_reg *addr, struct gdbserv_reg *len);
  int (*set_breakpoint) (struct gdbserv *, unsigned long type,
			 struct gdbserv_reg *addr, struct gdbserv_reg *len);
#endif

  /* misc methods */
  void (*process_target_packet) (struct gdbserv *);

  /* shutdown */
  void (*detach) (struct gdbserv *);

  /* instance specific data */
  void *data;
};

void *gdbserv_target_data (struct gdbserv *gdbserv);


