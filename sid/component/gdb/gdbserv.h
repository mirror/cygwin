/*
 * gdbserv.h -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


struct gdbserv;
struct gdbserv_target;
struct gdbserv_client;

/* If non-null, used to write tracing from the corresponding comonent */
extern FILE *gdbserv_state_trace;
extern FILE *gdbserv_input_trace;
extern FILE *gdbserv_output_trace;


/* A ``struct gdbserv_reg'' is an object for storing an arbitrary
   numeric value in a system independant way.  Part of an input packet
   will be parsed into a REG object (using gdbserv_input_reg_...) and
   then later converted into a specific value (using
   gdbserv_reg_to_...).  The bytes in BUF are always ordered
   big-endian. */

enum {
  GDBSERV_REG_SIZE = 16 /* space for a 128-bit quantity */
};
struct gdbserv_reg {
  int negative_p;
  int len;
  unsigned char buf[GDBSERV_REG_SIZE];
};

/* This is a callback to the target so that it to is notified of the
   connecting client.  The target can reject the connection by
   returning NULL */

typedef struct gdbserv_target *(gdbserv_target_attach) (struct gdbserv *gdbserv,
							void *globalstate);

/* Notify the server that the client has initiated a connection.
   Returns a gdbser struct for the session (or null if the target
   rejected the connect). */

struct gdbserv *gdbserv_fromclient_attach (struct gdbserv_client *gdbclient,
					   gdbserv_target_attach *to_target_attach,
					   void *target_attach_data);

/* Notify the server that the client has disconnected. */

void gdbserv_fromclient_detach (struct gdbserv *gdbserv);


/* Events comming in from the client */


/* Raw characters from the client<->server. */
void gdbserv_fromclient_data (struct gdbserv *gdbserv, const char *data, int sizeof_data);

/* An out-of-band break/cntrl-c request. */
void gdbserv_fromclient_break (struct gdbserv *gdbserv);


/* Events comming in from the target */


/* The target stops.  Could be: breakpoint (SIGTRAP); stop from remote
   debugger (SIGINT) or a simple request to stop nothing (0).  (See
   gdb/target.h) */
enum {
  GDBSERV_SIGNONE = 0,
  GDBSERV_SIGINT = 2,
  GDBSERV_SIGQUIT = 3,
  GDBSERV_SIGILL = 4,
  GDBSERV_SIGTRAP = 5,
  GDBSERV_SIGFPE = 8,
  GDBSERV_SIGKILL = 9,
  GDBSERV_SIGSEGV = 11
};

/* Target has reset */
void gdbserv_fromtarget_reset (struct gdbserv *client);

/* Target has encountered a break (suspend) condition */
void gdbserv_fromtarget_break (struct gdbserv *client, int sigval);

/* Target has exited */
void gdbserv_fromtarget_exit (struct gdbserv *client, int sigval);


/* Fetch data from the current input packet.
   Return -1 on error. */


/* Number of characters remaining in input packet */
int gdbserv_input_size (struct gdbserv *gdbserv);

/* NIBBLE: 4 bit quantity represented by a single HEX digit.
   BYTE: 8 bit quantity represented by two HEX digits. */
int gdbserv_input_nibble (struct gdbserv *gdbserv);
int gdbserv_input_byte (struct gdbserv *gdbserv);

/* BYTES: LEN 8 bit stream represented by LEN*2 HEX digits.
   BINARY: LEN 8 bit stream represented by LEN bytes + escape characters */
int gdbserv_input_bytes (struct gdbserv *gdbserv, char *buf, int len);
int gdbserv_input_escaped_binary (struct gdbserv *gdbserv, char *buf, int len);

/* Next character/string in packet.  Return -1 on error. */
int gdbserv_input_peek (struct gdbserv *gdbserv);
int gdbserv_input_char (struct gdbserv *gdbserv);
int gdbserv_input_string (struct gdbserv *gdbserv, char *buf, int len);

/* Peek at input packet comparing next few characters against STRING.
   Return -1 on non or partial match.  Return strlen (STRING) on full
   match and skip corresponding number of characters in input
   packet. */
int gdbserv_input_string_match (struct gdbserv *gdbserv, const char *string);

/* A small unsigned integer encoded using HEX. */
int gdbserv_input_hex_ulong (struct gdbserv *gdbserv, unsigned long *val);

/* Parse a HEX value of almost arbitrary length into the ``struct
   gdbserv_reg''.  When BYTE_LEN is zero, it may include a leading
   minus sign. When BYTE_LEN is non-zero it indicates the exact number
   of RAW BYTES (HEX digits / 2) that should be transfered to
   REG. ..._hex_beb () expects a true big-endian hex value.
   ..._hex_leb () expects a hybrid little-endian hex value - the bytes
   are ordered little-endian but the hex encoded nibble-pair that make
   up a byte is ordered big endian (ex: 0x12345678 is leb encoded as
   78563412). */
int gdbserv_input_reg_beb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);
int gdbserv_input_reg_leb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);


/* Write data to the current output packet. */


/* Integer values converted to HEX. */
void gdbserv_output_nibble (struct gdbserv *gdbserv, int h);
void gdbserv_output_byte (struct gdbserv *gdbserv, int h);
void gdbserv_output_bytes (struct gdbserv *gdbserv, const char *buf, unsigned sizeof_buf); 

/* Character values output verbatum. */
void gdbserv_output_char (struct gdbserv *gdbserv, char c);
void gdbserv_output_string (struct gdbserv *gdbserv, const char *buf);

/* Output a HEX value of almost arbitrary length in ``struct
   gdbserv_reg''.  May include a leading minus sign.  When BYTE_LEN is
   non-zero this specifies the exact number of RAW bytes (two HEX
   characters per byte) that should be output. */
/* FIXME: Can't have both a leading minus sign and a non-zero
   BYTE_LENGTH. */
void gdbserv_output_reg_beb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);
void gdbserv_output_reg_leb (struct gdbserv *gdbserv, struct gdbserv_reg *reg, int byte_len);
