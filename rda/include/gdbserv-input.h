/* gdbserv-input.h

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

#ifdef __cplusplus
}
#endif
