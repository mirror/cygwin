/*
 * gdbserv-input.h -- part of GDB remote server.
 *
 * Copyright (C) 2000 Red Hat.
 * This file is part of SID and is licensed under the GPL.
 * See the file COPYING.SID for conditions for redistribution.
 */


enum gdbinput_state {
  /*  0 = looking for start of packet */
  GDBINPUT_STATE_IDLE,
  /*  1 = got start of packet, looking for # terminator */
  GDBINPUT_STATE_TERM,
  /*  2 = looking for first byte of checksum */
  GDBINPUT_STATE_CRC1,
  /*  3 = looking for second byte of checksum (indicating end of packet) */
  GDBINPUT_STATE_CRC2,
  /*  4 = ignoring everything while looking for an ack packet */
  GDBINPUT_STATE_ACK,
};


struct gdbserv_input {
  
  /* The checksum calculated so far (sizeof >= 32 bits). */
  unsigned long checksum;
  /* The checksum we've received from the remote side (sizeof >= 32 bits). */
  unsigned long xmitcsum;
  /* Contents of the accumulated packet. */
  unsigned char *buf;
  unsigned long sizeof_buf;
  /* Number of characters received. */
  unsigned len;
  /* Number of characters retrieved */
  unsigned out;
  /* what we are doing */
  enum gdbinput_state state;

};

void gdbserv_input_attach (struct gdbserv *gdbserv);
void gdbserv_input_detach (struct gdbserv *gdbserv);
void gdbserv_input_data_packet (struct gdbserv *gdbserv, const char *buf, int len);
void gdbserv_input_wait_for_ack (struct gdbserv *gdbserv);

