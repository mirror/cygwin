//  Copyright (C) 2001, 2002 Red Hat.
//
//  Copyright (C) 2001  MandrakeSoft S.A.
//
//    MandrakeSoft S.A.
//    43, rue d'Aboukir
//    75002 Paris - France
//    http://www.linux-mandrake.com/
//    http://www.mandrakesoft.com/
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

#include "bochs.h"
#include "sid-vga-wrapper.h"

#define LOG_THIS
#define VGA_TRACE_FEATURE

bx_vga_c::bx_vga_c(void)
{
  BX_VGA_THIS s.vga_mem_updated = 0;
  BX_VGA_THIS s.x_tilesize = X_TILESIZE;
  BX_VGA_THIS s.y_tilesize = Y_TILESIZE;
  BX_VGA_THIS setprefix("[VGA ]");
}


bx_vga_c::~bx_vga_c(void)
{
  // nothing for now
}

  void
bx_vga_c::init(vga *vga_comp, Bit8u *vga_mem)
{
  unsigned i;
  unsigned x,y;

  BX_VGA_THIS s.vga_memory = vga_mem;
  // start with vga_memory empty
  memset(BX_VGA_THIS s.vga_memory, 0, 0x20300 * sizeof(Bit8u));

  BX_VGA_THIS s.misc_output.color_emulation  = 1;
  BX_VGA_THIS s.misc_output.enable_ram  = 1;
  BX_VGA_THIS s.misc_output.clock_select     = 0;
  BX_VGA_THIS s.misc_output.select_high_bank = 0;
  BX_VGA_THIS s.misc_output.horiz_sync_pol   = 1;
  BX_VGA_THIS s.misc_output.vert_sync_pol    = 1;

  BX_VGA_THIS s.CRTC.address = 0;

  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.graphics_alpha = 0;
  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.display_type = 0;
  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.enable_line_graphics = 1;
  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.blink_intensity = 0;
  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_panning_compat = 0;
  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_clock_select = 0;
  BX_VGA_THIS s.attribute_ctrl.mode_ctrl.internal_palette_size = 0;

  BX_VGA_THIS s.scan_bits=640;

  for (i=0; i<0x18; i++)
    BX_VGA_THIS s.CRTC.reg[i] = 0;
  BX_VGA_THIS s.CRTC.address = 0;

  BX_VGA_THIS s.attribute_ctrl.flip_flop = 0;
  BX_VGA_THIS s.attribute_ctrl.address = 0;
  BX_VGA_THIS s.attribute_ctrl.video_enabled = 1;
  for (i=0; i<16; i++)
    BX_VGA_THIS s.attribute_ctrl.palette_reg[i] = 0;
  BX_VGA_THIS s.attribute_ctrl.overscan_color = 0;
  BX_VGA_THIS s.attribute_ctrl.color_plane_enable = 0x0f;
  BX_VGA_THIS s.attribute_ctrl.horiz_pel_panning = 0;
  BX_VGA_THIS s.attribute_ctrl.color_select = 0;

  BX_VGA_THIS s.pel.data = (struct rgb_data *)(& vga_mem[0x20000]);
  for (i=0; i<256; i++) {
    BX_VGA_THIS s.pel.data[i].red = 0;
    BX_VGA_THIS s.pel.data[i].green = 0;
    BX_VGA_THIS s.pel.data[i].blue = 0;
    }
  BX_VGA_THIS s.pel.write_data_register = 0;
  BX_VGA_THIS s.pel.write_data_cycle = 0;
  BX_VGA_THIS s.pel.read_data_register = 0;
  BX_VGA_THIS s.pel.read_data_cycle = 0;
  BX_VGA_THIS s.pel.mask = 0xff;

  BX_VGA_THIS s.graphics_ctrl.index = 0;
  BX_VGA_THIS s.graphics_ctrl.set_reset = 0;
  BX_VGA_THIS s.graphics_ctrl.enable_set_reset = 0;
  BX_VGA_THIS s.graphics_ctrl.color_compare = 0;
  BX_VGA_THIS s.graphics_ctrl.data_rotate = 0;
  BX_VGA_THIS s.graphics_ctrl.raster_op    = 0;
  BX_VGA_THIS s.graphics_ctrl.read_map_select = 0;
  BX_VGA_THIS s.graphics_ctrl.write_mode = 0;
  BX_VGA_THIS s.graphics_ctrl.read_mode  = 0;
  BX_VGA_THIS s.graphics_ctrl.odd_even = 0;
  BX_VGA_THIS s.graphics_ctrl.chain_odd_even = 0;
  BX_VGA_THIS s.graphics_ctrl.shift_reg = 0;
  BX_VGA_THIS s.graphics_ctrl.graphics_alpha = 0;
  BX_VGA_THIS s.graphics_ctrl.memory_mapping = 2; // monochrome text mode
  BX_VGA_THIS s.graphics_ctrl.color_dont_care = 0;
  BX_VGA_THIS s.graphics_ctrl.bitmask = 0;
  for (i=0; i<4; i++) {
    BX_VGA_THIS s.graphics_ctrl.latch[i] = 0;
    }

  BX_VGA_THIS s.sequencer.index = 0;
  BX_VGA_THIS s.sequencer.map_mask = 0;
  for (i=0; i<4; i++) {
    BX_VGA_THIS s.sequencer.map_mask_bit[i] = 0;
    }
  BX_VGA_THIS s.sequencer.bit0 = 0;
  BX_VGA_THIS s.sequencer.bit1 = 0;
  BX_VGA_THIS s.sequencer.reg1 = 0;
  BX_VGA_THIS s.sequencer.char_map_select = 0;
  BX_VGA_THIS s.sequencer.extended_mem = 1; // display mem greater than 64K
  BX_VGA_THIS s.sequencer.odd_even = 1; // use sequential addressing mode
  BX_VGA_THIS s.sequencer.chain_four = 0; // use map mask & read map select

  BX_VGA_THIS s.vga_mem_updated = 0;
  for (y=0; y<480/Y_TILESIZE; y++)
    for (x=0; x<640/X_TILESIZE; x++)
      BX_VGA_THIS s.vga_tile_updated[x][y] = 0;

  BX_VGA_THIS vga_component = vga_comp;
  update_text_pins(false);
  update_dimension_pins(false);

  BX_VGA_THIS s.horiz_tick = 0;
  BX_VGA_THIS s.vert_tick = 0;
}

  // static IO port read callback handler
  // redirects to non-static class handler to avoid virtual functions

  Bit32u
bx_vga_c::read_handler(void *this_ptr, Bit32u address, unsigned io_len)
{
#if !BX_USE_VGA_SMF
  bx_vga_c *class_ptr = (bx_vga_c *) this_ptr;

  return( class_ptr->read(address, io_len) );
}


  Bit32u
bx_vga_c::read(Bit32u address, unsigned io_len)
{
#else
  UNUSED(this_ptr);
#endif  // !BX_USE_VGA_SMF
  Boolean  horiz_retrace, vert_retrace;
  Bit8u retval;

#if defined(VGA_TRACE_FEATURE)
  Bit32u ret = 0;
#define RETURN(x) do { ret = (x); goto read_return; } while (0)
#else
#define RETURN return
#endif

  if (io_len > 1)
    BX_PANIC(("io read from address %08x, len=%u\n",
             (unsigned) address, (unsigned) io_len));

#ifdef __OS2__
  if ( bx_options.videomode == BX_VIDEO_DIRECT )
     {
     return _inp(address);
     }
#endif

#if !defined(VGA_TRACE_FEATURE)
    BX_DEBUG(("vga_io_read(%04x)!\n", (unsigned) address));
#endif

  if ( (address >= 0x03b0) && (address <= 0x03bf) &&
       (BX_VGA_THIS s.misc_output.color_emulation) ) {
	RETURN(0xff);
  }
  if ( (address >= 0x03d0) && (address <= 0x03df) &&
       (BX_VGA_THIS s.misc_output.color_emulation==0) ) {
	RETURN(0xff);
  }

  switch (address) {
    case 0x03ba: /* Input Status 1 (monochrome emulation modes) */
    case 0x03ca: /* Feature Control ??? */
    case 0x03da: /* Input Status 1 (color emulation modes) */
      // bit3: Vertical Retrace
      //       0 = display is in the display mode
      //       1 = display is in the vertical retrace mode
      // bit0: Display Enable
      //       0 = display is in the display mode
      //       1 = display is not in the display mode; either the
      //           horizontal or vertical retrace period is active

      //      printf("horiz = %d, vert = %d\n", BX_VGA_THIS s.horiz_tick, BX_VGA_THIS s.vert_tick);

      if(BX_VGA_THIS s.misc_output.clock_select == 0){ // 25.175 clock 112.5% the length of 28.32
	if (BX_VGA_THIS s.horiz_tick >= 112) {
	  BX_VGA_THIS s.horiz_tick = 0;
	  horiz_retrace = 1;
	}
	else {
	  BX_VGA_THIS s.horiz_tick++;
	  horiz_retrace = 0;
	}
	if (BX_VGA_THIS s.vert_tick >= 112) {
	  BX_VGA_THIS s.vert_tick = 0;
	  vert_retrace = 1;
	}
	else {
	  BX_VGA_THIS s.vert_tick++;
	  vert_retrace = 0;
	}
      }else{ // clock_select 1 is assumed to be the 28.32 clock in XF86_VGA16
	if (BX_VGA_THIS s.horiz_tick >= 100) { // ??? bogus # 100
	  BX_VGA_THIS s.horiz_tick = 0;
	  horiz_retrace = 1;
	}
	else {
	  BX_VGA_THIS s.horiz_tick++;
	  horiz_retrace = 0;
	}
	if (BX_VGA_THIS s.vert_tick >= 100) { // ??? bogus # 100
	  BX_VGA_THIS s.vert_tick = 0;
	  vert_retrace = 1;
	}
	else {
	  BX_VGA_THIS s.vert_tick++;
	  vert_retrace = 0;
	}
      } // probably add more clock modes here for diffrent resolutions

      retval = 0;
      if (horiz_retrace || vert_retrace)
        retval = 0x01;
      if (vert_retrace)
        retval |= 0x08;

      /* reading this port resets the flip-flop to address mode */
      BX_VGA_THIS s.attribute_ctrl.flip_flop = 0;
      RETURN(retval);
      break;


    case 0x03c0: /* */
      if (BX_VGA_THIS s.attribute_ctrl.flip_flop == 0) {
        //BX_INFO(("vga_io_read: 3c0: flip_flop = 0\n"));
        retval =
          (BX_VGA_THIS s.attribute_ctrl.video_enabled << 5) |
          BX_VGA_THIS s.attribute_ctrl.address;
        RETURN(retval);
        }
      else {
        BX_PANIC(("vga_io_read: 3c0: flip_flop = 0\n"));
        return(0);
        }
      break;

    case 0x03c1: /* */
      switch (BX_VGA_THIS s.attribute_ctrl.address) {
        case 0x00: case 0x01: case 0x02: case 0x03:
        case 0x04: case 0x05: case 0x06: case 0x07:
        case 0x08: case 0x09: case 0x0a: case 0x0b:
        case 0x0c: case 0x0d: case 0x0e: case 0x0f:
          retval = BX_VGA_THIS s.attribute_ctrl.palette_reg[BX_VGA_THIS s.attribute_ctrl.address];
	  RETURN(retval);
          break;
        case 0x10: /* mode control register */
          retval =
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.graphics_alpha << 0) |
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.display_type << 1) |
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.enable_line_graphics << 2) |
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.blink_intensity << 3) |
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_panning_compat << 5) |
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_clock_select << 6) |
            (BX_VGA_THIS s.attribute_ctrl.mode_ctrl.internal_palette_size << 7);
	  RETURN(retval);
          break;
	case 0x11: /* overscan color register */
	  RETURN(BX_VGA_THIS s.attribute_ctrl.overscan_color);
          break;
	case 0x12: /* color plane enable */
	  RETURN(BX_VGA_THIS s.attribute_ctrl.color_plane_enable);
          break;
        case 0x13: /* horizontal PEL panning register */
          RETURN(BX_VGA_THIS s.attribute_ctrl.horiz_pel_panning);
          break;
        case 0x14: /* color select register */
          RETURN(BX_VGA_THIS s.attribute_ctrl.color_select);
          break;
        default:
          BX_INFO(("vga_io_read: 3c1: address %02xh?\n",
            (unsigned) BX_VGA_THIS s.attribute_ctrl.address));
          RETURN(0);
        }
      break;

    case 0x03c2: /* Input Status 0 */
      BX_DEBUG(("io read 3c2: input status #0: ignoring\n"));
      RETURN(0);
      break;

    case 0x03c3: /* VGA Enable Register */
      RETURN(1);
      break;

    case 0x03c4: /* Sequencer Index Register */
      RETURN(BX_VGA_THIS s.sequencer.index);
      break;

    case 0x03c5: /* Sequencer Registers 00..04 */
      switch (BX_VGA_THIS s.sequencer.index) {
        case 0: /* sequencer: reset */
		  BX_DEBUG(("io read 3c5 case 0: sequencer reset\n"));
          RETURN(BX_VGA_THIS s.sequencer.bit0 | (BX_VGA_THIS s.sequencer.bit1<<1));
          break;
        case 1: /* sequencer: clocking mode */
		  BX_DEBUG(("io read 3c5 case 1: sequencer clocking mode\n"));
          RETURN(BX_VGA_THIS s.sequencer.reg1);
          break;
        case 2: /* sequencer: map mask register */
          RETURN(BX_VGA_THIS s.sequencer.map_mask);
          break;
        case 3: /* sequencer: character map select register */
          RETURN(BX_VGA_THIS s.sequencer.char_map_select);
          break;
        case 4: /* sequencer: memory mode register */
          retval =
            (BX_VGA_THIS s.sequencer.extended_mem   << 1) |
            (BX_VGA_THIS s.sequencer.odd_even       << 2) |
            (BX_VGA_THIS s.sequencer.chain_four     << 3);
          RETURN(retval);
          break;

        default:
          BX_DEBUG(("io read 3c5: index %u unhandled\n",
            (unsigned) BX_VGA_THIS s.sequencer.index));
          RETURN(0);
        }
      break;

    case 0x03c6: /* PEL mask ??? */
      RETURN(BX_VGA_THIS s.pel.mask);
      break;

    case 0x03c9: /* PEL Data Register, colors 00..FF */
      switch (BX_VGA_THIS s.pel.read_data_cycle) {
        case 0:
          retval = BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.read_data_register].red;
          break;
        case 1:
          retval = BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.read_data_register].green;
          break;
        case 2:
          retval = BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.read_data_register].blue;
          break;
        default:
          BX_PANIC(("io write 3c9: data cyle is bad value\n"));
          retval = 0; // keep compiler happy
        }
      BX_VGA_THIS s.pel.read_data_cycle++;
      if (BX_VGA_THIS s.pel.read_data_cycle >= 3) {
        BX_VGA_THIS s.pel.read_data_cycle = 0;
        BX_VGA_THIS s.pel.read_data_register++;
        }
      RETURN(retval);
      break;

    case 0x03cc: /* Miscellaneous Output / Graphics 1 Position ??? */
      retval =
        ((BX_VGA_THIS s.misc_output.color_emulation  & 0x01) << 0) |
        ((BX_VGA_THIS s.misc_output.enable_ram       & 0x01) << 1) |
        ((BX_VGA_THIS s.misc_output.clock_select     & 0x03) << 2) |
        ((BX_VGA_THIS s.misc_output.select_high_bank & 0x01) << 5) |
        ((BX_VGA_THIS s.misc_output.horiz_sync_pol   & 0x01) << 6) |
        ((BX_VGA_THIS s.misc_output.vert_sync_pol    & 0x01) << 7);
      RETURN(retval);
      break;

    case 0x03ce: /* Graphics Controller Index Register */
      RETURN(BX_VGA_THIS s.graphics_ctrl.index);
      break;

    case 0x03cd: /* ??? */
      BX_DEBUG(("io read from 03cd\n"));
      RETURN(0x00);
      break;

    case 0x03cf: /* Graphics Controller Registers 00..08 */
      switch (BX_VGA_THIS s.graphics_ctrl.index) {
        case 0: /* Set/Reset */
          RETURN(BX_VGA_THIS s.graphics_ctrl.set_reset);
          break;
        case 1: /* Enable Set/Reset */
          RETURN(BX_VGA_THIS s.graphics_ctrl.enable_set_reset);
          break;
        case 2: /* Color Compare */
          RETURN(BX_VGA_THIS s.graphics_ctrl.color_compare);
          break;
        case 3: /* Data Rotate */
          retval =
            ((BX_VGA_THIS s.graphics_ctrl.raster_op & 0x03) << 3) |
            ((BX_VGA_THIS s.graphics_ctrl.data_rotate & 0x07) << 0);
          RETURN(retval);
          break;
        case 4: /* Read Map Select */
          RETURN(BX_VGA_THIS s.graphics_ctrl.read_map_select);
          break;
        case 5: /* Mode */
          retval =
            ((BX_VGA_THIS s.graphics_ctrl.shift_reg & 0x03) << 5) |
            ((BX_VGA_THIS s.graphics_ctrl.odd_even & 0x01 ) << 4) |
            ((BX_VGA_THIS s.graphics_ctrl.read_mode & 0x01) << 3) |
            ((BX_VGA_THIS s.graphics_ctrl.write_mode & 0x03) << 0);

if (BX_VGA_THIS s.graphics_ctrl.odd_even ||
    BX_VGA_THIS s.graphics_ctrl.shift_reg)
  BX_INFO(("read 3cf: reg 05 = %02x\n", (unsigned) retval));
          RETURN(retval);
          break;
        case 6: /* Miscellaneous */
          retval =
            ((BX_VGA_THIS s.graphics_ctrl.memory_mapping & 0x03 ) << 2) |
            ((BX_VGA_THIS s.graphics_ctrl.odd_even & 0x01) << 1) |
            ((BX_VGA_THIS s.graphics_ctrl.graphics_alpha & 0x01) << 0);
          RETURN(retval);
          break;
        case 7: /* Color Don't Care */
          RETURN(BX_VGA_THIS s.graphics_ctrl.color_dont_care);
          break;
        case 8: /* Bit Mask */
          RETURN(BX_VGA_THIS s.graphics_ctrl.bitmask);
          break;
        default:
          /* ??? */
          BX_DEBUG(("io read: 3cf: index %u unhandled\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.index));
          RETURN(0);
        }
      BX_PANIC(("io read: 3cf: shouldn't get here\n"));
      break;

    case 0x03d4: /* CRTC Index Register (color emulation modes) */
      RETURN(BX_VGA_THIS s.CRTC.address);
      break;

    case 0x03b5: /* CRTC Registers (monochrome emulation modes) */
    case 0x03d5: /* CRTC Registers (color emulation modes) */
      if (BX_VGA_THIS s.CRTC.address > 0x18)
        BX_INFO(("vga_io_read: 3d5: address = %02xh\n",
          (unsigned) BX_VGA_THIS s.CRTC.address));
      RETURN(BX_VGA_THIS s.CRTC.reg[BX_VGA_THIS s.CRTC.address]);
      break;

    case 0x03b4: /* CRTC Index Register (monochrome emulation modes) */
    case 0x03c7: /* not sure but OpenBSD reads it a lot */
    case 0x03cb: /* not sure but OpenBSD reads it a lot */
    case 0x03c8: /* */
    default:
      BX_PANIC(("*** io read from vga port %x\n", (unsigned) address));
      RETURN(0); /* keep compiler happy */
    }

#if defined(VGA_TRACE_FEATURE)
  read_return:
	BX_DEBUG(("8-bit read from %04x = %02x\n", (unsigned) address, ret));
  return ret;
#endif
}
#if defined(VGA_TRACE_FEATURE)
#undef RETURN
#endif

  // static IO port write callback handler
  // redirects to non-static class handler to avoid virtual functions

  void
bx_vga_c::write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len)
{
#if !BX_USE_VGA_SMF
  bx_vga_c *class_ptr = (bx_vga_c *) this_ptr;

  class_ptr->write(address, value, io_len, 0);
#else
  UNUSED(this_ptr);
  bx_vga.write(address, value, io_len, 0);
#endif
}

  void
bx_vga_c::write_handler_no_log(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len)
{
#if !BX_USE_VGA_SMF
  bx_vga_c *class_ptr = (bx_vga_c *) this_ptr;

  class_ptr->write(address, value, io_len, 1);
#else
  UNUSED(this_ptr);
  bx_vga.write(address, value, io_len, 1);
#endif
}

  void
bx_vga_c::write(Bit32u address, Bit32u value, unsigned io_len, Boolean no_log)
{
  unsigned i;
  Boolean prev_video_enabled;
  Bit8u prev_memory_mapping;
  Boolean prev_graphics_alpha, prev_chain_odd_even;
  Boolean needs_update;

#if defined(VGA_TRACE_FEATURE)
  if (!no_log)
	switch (io_len) {
	      case 1:
		    BX_DEBUG(("8-bit write to %04x = %02x\n", (unsigned)address, (unsigned)value));
		    break;
	      case 2:
		    BX_DEBUG(("16-bit write to %04x = %04x\n", (unsigned)address, (unsigned)value));
		    break;
	      default:
		    BX_PANIC(("Weird VGA write size\n"));
	}
#endif

#if !defined(VGA_TRACE_FEATURE)
    BX_DEBUG(("vga_io_write(%04x)=%02x!\n", (unsigned) address,
      (unsigned) value);
#endif

  if (io_len == 2) {
#if BX_USE_VGA_SMF
    bx_vga_c::write_handler_no_log(0, address, value & 0xff, 1);
    bx_vga_c::write_handler_no_log(0, address+1, (value >> 8) & 0xff, 1);
#else
    bx_vga_c::write(address, value & 0xff, 1, 1);
    bx_vga_c::write(address+1, (value >> 8) & 0xff, 1, 1);
#endif
    return;
    }

#ifdef __OS2__
  if ( bx_options.videomode == BX_VIDEO_DIRECT )
     {
     _outp(address,value);
     return;
     }
#endif

  if ( (address >= 0x03b0) && (address <= 0x03bf) &&
       (BX_VGA_THIS s.misc_output.color_emulation) )
    return;
  if ( (address >= 0x03d0) && (address <= 0x03df) &&
       (BX_VGA_THIS s.misc_output.color_emulation==0) )
    return;

  switch (address) {
    case 0x03b4: /* CRTC Index Register (monochrome emulation modes) */
      if (value > 0x18)
        BX_PANIC(("io write 3b4: value > 18h\n"));
      BX_VGA_THIS s.CRTC.address = value;
      break;

    case 0x03b5: /* CRTC Registers (monochrome emulation modes) */
      if (BX_VGA_THIS s.CRTC.address > 0x18)
        BX_PANIC(("io write 3b5: CRTC reg > 18h\n"));
      BX_VGA_THIS s.CRTC.reg[BX_VGA_THIS s.CRTC.address] = value;
      switch(s.CRTC.address)
        {
        case 12:
        case 13:
        case 14:
        case 15:
          update_text_pins(true);
          break;
        case 6:
        case 7:
        case 9:
        case 18:
        case 19:
        case 20:
        case 23:
          update_dimension_pins(true);
          break;
        }
#if !defined(VGA_TRACE_FEATURE)
      BX_DEBUG(("mono CRTC Reg[%u] = %02x\n",
          (unsigned) BX_VGA_THIS s.CRTC.address, (unsigned) value);
#endif
      break;

    case 0x03ba: /* Feature Control (monochrome emulation modes) */
#if !defined(VGA_TRACE_FEATURE)
      BX_DEBUG(("io write 3ba: feature control: ignoring\n"));
#endif
      break;

    case 0x03c0: /* Attribute Controller */
      if (BX_VGA_THIS s.attribute_ctrl.flip_flop == 0) { /* address mode */
        prev_video_enabled = BX_VGA_THIS s.attribute_ctrl.video_enabled;
        BX_VGA_THIS s.attribute_ctrl.video_enabled = (value >> 5) & 0x01;
#if !defined(VGA_TRACE_FEATURE)
        BX_DEBUG(("io write 3c0: video_enabled = %u\n",
                  (unsigned) BX_VGA_THIS s.attribute_ctrl.video_enabled);
#endif
        if (BX_VGA_THIS s.attribute_ctrl.video_enabled == 0)
        {}
        else if (!prev_video_enabled) {
#if !defined(VGA_TRACE_FEATURE)
          BX_DEBUG(("found enable transition\n"));
#endif
          // Mark all video as updated so the color changes will go through
          memset(BX_VGA_THIS s.text_snapshot, 0,
                 sizeof(BX_VGA_THIS s.text_snapshot));
          BX_VGA_THIS s.vga_mem_updated = 1;
          for (unsigned xti = 0; xti < BX_NUM_X_TILES; xti++) {
            for (unsigned yti = 0; yti < BX_NUM_Y_TILES; yti++) {
              BX_VGA_THIS s.vga_tile_updated[xti][yti] = 1;
              }
            }
          }
        value &= 0x1f; /* address = bits 0..4 */
        BX_VGA_THIS s.attribute_ctrl.address = value;
        switch (value) {
          case 0x00: case 0x01: case 0x02: case 0x03:
          case 0x04: case 0x05: case 0x06: case 0x07:
          case 0x08: case 0x09: case 0x0a: case 0x0b:
          case 0x0c: case 0x0d: case 0x0e: case 0x0f:
            break;

          default:
            BX_DEBUG(("io write 3c0: address mode reg=%u\n",
              (unsigned) value));
          }
        }
      else { /* data-write mode */
        switch (BX_VGA_THIS s.attribute_ctrl.address) {
          case 0x00: case 0x01: case 0x02: case 0x03:
          case 0x04: case 0x05: case 0x06: case 0x07:
          case 0x08: case 0x09: case 0x0a: case 0x0b:
          case 0x0c: case 0x0d: case 0x0e: case 0x0f:
            BX_VGA_THIS s.attribute_ctrl.palette_reg[BX_VGA_THIS s.attribute_ctrl.address] =
              value;
            //BX_DEBUG(("io write: 3c0 palette reg[%u] = %02x\n",
            //  (unsigned) BX_VGA_THIS s.attribute_ctrl.address,
            //  (unsigned) value);
            break;
          case 0x10: // mode control register
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.graphics_alpha =
              (value >> 0) & 0x01;
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.display_type =
              (value >> 1) & 0x01;
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.enable_line_graphics =
              (value >> 2) & 0x01;
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.blink_intensity =
              (value >> 3) & 0x01;
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_panning_compat =
              (value >> 5) & 0x01;
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_clock_select =
              (value >> 6) & 0x01;
            BX_VGA_THIS s.attribute_ctrl.mode_ctrl.internal_palette_size =
              (value >> 7) & 0x01;
#if !defined(VGA_TRACE_FEATURE)
            BX_DEBUG(("io write 3c0: mode control: %02x h\n",
                (unsigned) value);
#endif
            break;
          case 0x11: // Overscan Color Register
            BX_VGA_THIS s.attribute_ctrl.overscan_color = (value & 0x3f);
#if !defined(VGA_TRACE_FEATURE)
            BX_DEBUG(("io write 3c0: overscan color = %02x\n",
                        (unsigned) value);
#endif
            break;
          case 0x12: // Color Plane Enable Register
            BX_VGA_THIS s.attribute_ctrl.color_plane_enable = (value & 0x0f);
#if !defined(VGA_TRACE_FEATURE)
            BX_DEBUG(("io write 3c0: color plane enable = %02x\n",
                        (unsigned) value);
#endif
            break;
          case 0x13: // Horizontal Pixel Panning Register
            BX_VGA_THIS s.attribute_ctrl.horiz_pel_panning = (value & 0x0f);
#if !defined(VGA_TRACE_FEATURE)
            BX_DEBUG(("io write 3c0: horiz pel panning = %02x\n",
                        (unsigned) value);
#endif
            break;
          case 0x14: // Color Select Register
            BX_VGA_THIS s.attribute_ctrl.color_select = (value & 0x0f);
#if !defined(VGA_TRACE_FEATURE)
            BX_DEBUG(("io write 3c0: color select = %02x\n",
                        (unsigned) BX_VGA_THIS s.attribute_ctrl.color_select);
#endif
            break;
          default:
            BX_DEBUG(("io write 3c0: data-write mode %02x h\n",
              (unsigned) BX_VGA_THIS s.attribute_ctrl.address));
          }
        }
      BX_VGA_THIS s.attribute_ctrl.flip_flop = !BX_VGA_THIS s.attribute_ctrl.flip_flop;
      break;

    case 0x03c2: // Miscellaneous Output Register
      BX_VGA_THIS s.misc_output.color_emulation  = (value >> 0) & 0x01;
      BX_VGA_THIS s.misc_output.enable_ram       = (value >> 1) & 0x01;
      BX_VGA_THIS s.misc_output.clock_select     = (value >> 2) & 0x03;
      BX_VGA_THIS s.misc_output.select_high_bank = (value >> 5) & 0x01;
      BX_VGA_THIS s.misc_output.horiz_sync_pol   = (value >> 6) & 0x01;
      BX_VGA_THIS s.misc_output.vert_sync_pol    = (value >> 7) & 0x01;
#if !defined(VGA_TRACE_FEATURE)
        BX_DEBUG(("io write 3c2:\n"));
        BX_DEBUG(("  color_emulation (attempted) = %u\n",
                  (value >> 0) & 0x01 );
        BX_DEBUG(("  enable_ram = %u\n",
                  (unsigned) BX_VGA_THIS s.misc_output.enable_ram);
        BX_DEBUG(("  clock_select = %u\n",
                  (unsigned) BX_VGA_THIS s.misc_output.clock_select);
        BX_DEBUG(("  select_high_bank = %u\n",
                  (unsigned) BX_VGA_THIS s.misc_output.select_high_bank);
        BX_DEBUG(("  horiz_sync_pol = %u\n",
                  (unsigned) BX_VGA_THIS s.misc_output.horiz_sync_pol);
        BX_DEBUG(("  vert_sync_pol = %u\n",
                  (unsigned) BX_VGA_THIS s.misc_output.vert_sync_pol);
#endif
      break;

    case 0x03c3: // VGA enable
      // bit0: enables VGA display if set
#if !defined(VGA_TRACE_FEATURE)
      BX_DEBUG(("io write 3c3: (ignoring) VGA enable = %u\n",
                  (unsigned) (value & 0x01) );
#endif
      break;

    case 0x03c4: /* Sequencer Index Register */
      if (value > 4) {
        BX_DEBUG(("io write 3c4: value > 4\n"));
        }
      BX_VGA_THIS s.sequencer.index = value;
      break;

    case 0x03c5: /* Sequencer Registers 00..04 */
      switch (BX_VGA_THIS s.sequencer.index) {
        case 0: /* sequencer: reset */
#if !defined(VGA_TRACE_FEATURE)
          BX_DEBUG(("io write 3c5=%02x: reset reg: ignoring\n",
                      (unsigned) value);
#endif
BX_VGA_THIS s.sequencer.bit0 = (value >> 0) & 0x01;
BX_VGA_THIS s.sequencer.bit1 = (value >> 1) & 0x01;
          break;
        case 1: /* sequencer: clocking mode */
#if !defined(VGA_TRACE_FEATURE)
          BX_DEBUG(("io write 3c5=%02x: clocking mode reg: ignoring\n",
                      (unsigned) value);
#endif
          BX_VGA_THIS s.sequencer.reg1 = value & 0x3f;
          break;
        case 2: /* sequencer: map mask register */
          BX_VGA_THIS s.sequencer.map_mask = (value & 0x0f);
          for (i=0; i<4; i++)
            BX_VGA_THIS s.sequencer.map_mask_bit[i] = (value >> i) & 0x01;
          break;
        case 3: /* sequencer: character map select register */
          BX_VGA_THIS s.sequencer.char_map_select = value;
          break;
        case 4: /* sequencer: memory mode register */
          BX_VGA_THIS s.sequencer.extended_mem   = (value >> 1) & 0x01;
          BX_VGA_THIS s.sequencer.odd_even       = (value >> 2) & 0x01;
          BX_VGA_THIS s.sequencer.chain_four     = (value >> 3) & 0x01;

          update_dimension_pins(true);

#if !defined(VGA_TRACE_FEATURE)
          BX_DEBUG(("io write 3c5: index 4:\n"));
          BX_DEBUG(("  extended_mem %u\n",
              (unsigned) BX_VGA_THIS s.sequencer.extended_mem);
          BX_DEBUG(("  odd_even %u\n",
              (unsigned) BX_VGA_THIS s.sequencer.odd_even);
          BX_DEBUG(("  chain_four %u\n",
              (unsigned) BX_VGA_THIS s.sequencer.chain_four);
#endif
          break;
        default:
          BX_DEBUG(("io write 3c5: index %u unhandled\n",
            (unsigned) BX_VGA_THIS s.sequencer.index));
        }
      break;

    case 0x03c6: /* PEL mask */
      BX_VGA_THIS s.pel.mask = value;
      if (BX_VGA_THIS s.pel.mask != 0xff)
        BX_DEBUG(("io write 3c6: PEL mask=0x%02x != 0xFF\n"));
      // BX_VGA_THIS s.pel.mask should be and'd with final value before
      // indexing into color registerBX_VGA_THIS s.
      break;

    case 0x03c7: // PEL address, read mode
      BX_VGA_THIS s.pel.read_data_register = value;
      BX_VGA_THIS s.pel.read_data_cycle    = 0;
      break;

    case 0x03c8: /* PEL address write mode */
      BX_VGA_THIS s.pel.write_data_register = value;
      BX_VGA_THIS s.pel.write_data_cycle    = 0;
      break;

    case 0x03c9: /* PEL Data Register, colors 00..FF */
      switch (BX_VGA_THIS s.pel.write_data_cycle) {
        case 0:
          BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.write_data_register].red = value;
          break;
        case 1:
          BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.write_data_register].green = value;
          break;
        case 2:
          BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.write_data_register].blue = value;

          vga_component->drive_palette_change_index_pin(BX_VGA_THIS s.pel.write_data_register);

          break;
        default:
          BX_PANIC(("io write 3c9: data cyle is bad value\n"));
        }

      BX_VGA_THIS s.pel.write_data_cycle++;
      if (BX_VGA_THIS s.pel.write_data_cycle >= 3) {
        //BX_INFO(("BX_VGA_THIS s.pel.data[%u] {r=%u, g=%u, b=%u}\n",
        //  (unsigned) BX_VGA_THIS s.pel.write_data_register,
        //  (unsigned) BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.write_data_register].red,
        //  (unsigned) BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.write_data_register].green,
        //  (unsigned) BX_VGA_THIS s.pel.data[BX_VGA_THIS s.pel.write_data_register].blue);
        BX_VGA_THIS s.pel.write_data_cycle = 0;
        BX_VGA_THIS s.pel.write_data_register++;
        }
      break;

    case 0x03ca: /* Graphics 2 Position (EGA) */
      // ignore, EGA only???
      break;

    case 0x03cc: /* Graphics 1 Position (EGA) */
      // ignore, EGA only???
      break;

    case 0x03ce: /* Graphics Controller Index Register */
      if (value > 0x08) /* ??? */
        BX_DEBUG(("io write: 3ce: value > 8\n"));
      BX_VGA_THIS s.graphics_ctrl.index = value;
      break;

    case 0x03cd: /* ??? */
      BX_DEBUG(("io write to 03cd = %02x\n", (unsigned) value));
      break;

    case 0x03cf: /* Graphics Controller Registers 00..08 */
      switch (BX_VGA_THIS s.graphics_ctrl.index) {
        case 0: /* Set/Reset */
          BX_VGA_THIS s.graphics_ctrl.set_reset = value & 0x0f;
          break;
        case 1: /* Enable Set/Reset */
          BX_VGA_THIS s.graphics_ctrl.enable_set_reset = value & 0x0f;
          break;
        case 2: /* Color Compare */
          BX_VGA_THIS s.graphics_ctrl.color_compare = value & 0x0f;
          break;
        case 3: /* Data Rotate */
          BX_VGA_THIS s.graphics_ctrl.data_rotate = value & 0x07;
          /* ??? is this bits 3..4 or 4..5 */
          BX_VGA_THIS s.graphics_ctrl.raster_op    = (value >> 3) & 0x03; /* ??? */
          break;
        case 4: /* Read Map Select */
          BX_VGA_THIS s.graphics_ctrl.read_map_select = value & 0x03;
#if !defined(VGA_TRACE_FEATURE)
          BX_DEBUG(("io write to 03cf = %02x (RMS)\n", (unsigned) value));
#endif
          break;
        case 5: /* Mode */
          BX_VGA_THIS s.graphics_ctrl.write_mode        = value & 0x03;
          BX_VGA_THIS s.graphics_ctrl.read_mode         = (value >> 3) & 0x01;
          BX_VGA_THIS s.graphics_ctrl.odd_even   = (value >> 4) & 0x01;
          BX_VGA_THIS s.graphics_ctrl.shift_reg         = (value >> 5) & 0x03;

          update_dimension_pins(true);

          if (BX_VGA_THIS s.graphics_ctrl.odd_even)
            BX_DEBUG(("io write: 3cf: reg 05: value = %02xh\n",
              (unsigned) value));
          if (BX_VGA_THIS s.graphics_ctrl.shift_reg)
            BX_DEBUG(("io write: 3cf: reg 05: value = %02xh\n",
              (unsigned) value));
          break;
        case 6: /* Miscellaneous */
          prev_graphics_alpha = BX_VGA_THIS s.graphics_ctrl.graphics_alpha;
          prev_chain_odd_even = BX_VGA_THIS s.graphics_ctrl.chain_odd_even;
          prev_memory_mapping = BX_VGA_THIS s.graphics_ctrl.memory_mapping;

          BX_VGA_THIS s.graphics_ctrl.graphics_alpha = value & 0x01;
          BX_VGA_THIS s.graphics_ctrl.chain_odd_even = (value >> 1) & 0x01;
          BX_VGA_THIS s.graphics_ctrl.memory_mapping = (value >> 2) & 0x03;
#if !defined(VGA_TRACE_FEATURE)
          BX_DEBUG(("memory_mapping set to %u\n",
              (unsigned) BX_VGA_THIS s.graphics_ctrl.memory_mapping));
          BX_DEBUG(("graphics mode set to %u\n",
              (unsigned) BX_VGA_THIS s.graphics_ctrl.graphics_alpha));
          BX_DEBUG(("odd_even mode set to %u\n",
                    (unsigned) BX_VGA_THIS s.graphics_ctrl.odd_even);)
          BX_DEBUG(("io write: 3cf: reg 06: value = %02xh\n",
                (unsigned) value));
#endif
          if (prev_memory_mapping != BX_VGA_THIS s.graphics_ctrl.memory_mapping)
            {
              update_text_pins(true);
              update_dimension_pins(true);
            }
          // other checks here ???
          // check for transition from graphics to alpha mode and clear
          // old snapshot memory
          break;
        case 7: /* Color Don't Care */
          BX_VGA_THIS s.graphics_ctrl.color_dont_care = value & 0x0f;
          break;
        case 8: /* Bit Mask */
          BX_VGA_THIS s.graphics_ctrl.bitmask = value;
          break;
        default:
          /* ??? */
          BX_DEBUG(("io write: 3cf: index %u unhandled\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.index));
        }
      break;

    case 0x03d4: /* CRTC Index Register (color emulation modes) */
      BX_VGA_THIS s.CRTC.address = value;
      if (BX_VGA_THIS s.CRTC.address > 0x18)
        BX_DEBUG(("vga_io_write: 3d4: address = %02xh\n",
          (unsigned) BX_VGA_THIS s.CRTC.address));
      break;

    case 0x03d5: /* CRTC Registers (color emulation modes) */
      if (BX_VGA_THIS s.CRTC.address > 0x18)
        BX_DEBUG(("vga_io_write: 3d5: address = %02xh\n",
          (unsigned) BX_VGA_THIS s.CRTC.address));
      BX_VGA_THIS s.CRTC.reg[BX_VGA_THIS s.CRTC.address] = value;

      switch(s.CRTC.address)
        {
        case 12:
        case 13:
        case 14:
        case 15:
          update_text_pins(true);
          break;
        case 6:
        case 7:
        case 9:
        case 18:
        case 19:
        case 20:
        case 23:
          update_dimension_pins(true);
          break;
        }
      break;

    case 0x03da: /* Feature Control (color emulation modes) */
      BX_DEBUG(("io write: 3da: ignoring: feature ctrl & vert sync\n"));
      break;

    case 0x03c1: /* */
    default:
      BX_PANIC(("unsupported io write to port %x, val=%02x\n",
        (unsigned) address, (unsigned) value));
    }
}

  Bit8u
bx_vga_c::mem_read(Bit32u addr)
{
  Bit32u offset;


#if defined(VGA_TRACE_FEATURE)
//	BX_DEBUG(("8-bit memory read from %08x\n", addr));
#endif

// ??? should get rid of references to shift_reg in this function

#ifdef __OS2__
  if ( bx_options.videomode == BX_VIDEO_DIRECT )
     {
     char value;

     value = devices->mem->video[addr-0xA0000];

     return value;
     }
#endif

  if (BX_VGA_THIS s.graphics_ctrl.graphics_alpha) {
    if (BX_VGA_THIS s.graphics_ctrl.memory_mapping == 3) { // 0xB8000 .. 0xBFFFF
      if (addr < 0xB8000)
        return(0xff);
      // ??? offset = addr - 0xA0000;
      offset = addr - 0xB8000;

      if (BX_VGA_THIS s.graphics_ctrl.shift_reg != 2)
        BX_PANIC(("vga_mem_read: shift_reg = %u\n",
                 (unsigned) BX_VGA_THIS s.graphics_ctrl.shift_reg));
      return(BX_VGA_THIS s.vga_memory[offset]);
      }

    if (BX_VGA_THIS s.graphics_ctrl.memory_mapping != 1) {
      BX_DEBUG(("  location %08x\n", (unsigned) addr));
      BX_PANIC(("vga_mem_read: graphics: mapping = %u?\n",
        (unsigned) BX_VGA_THIS s.graphics_ctrl.memory_mapping));
      return(0);
      }
    if (addr > 0xAFFFF)
      return(0xff);

    // addr between 0xA0000 and 0xAFFFF
    if ( BX_VGA_THIS s.sequencer.chain_four ) {
      offset = addr - 0xA0000;

      // Mode 13h: 320 x 200 256 color mode: chained pixel representation
      return( BX_VGA_THIS s.vga_memory[(offset & ~0x03) + (offset % 4)*65536] );
      }

    /* addr between 0xA0000 and 0xAFFFF */
    switch (BX_VGA_THIS s.graphics_ctrl.read_mode) {
      case 0: /* read mode 0 */
        offset = addr - 0xA0000;
        BX_VGA_THIS s.graphics_ctrl.latch[0] = BX_VGA_THIS s.vga_memory[          offset];
        BX_VGA_THIS s.graphics_ctrl.latch[1] = BX_VGA_THIS s.vga_memory[1*65536 + offset];
        BX_VGA_THIS s.graphics_ctrl.latch[2] = BX_VGA_THIS s.vga_memory[2*65536 + offset];
        BX_VGA_THIS s.graphics_ctrl.latch[3] = BX_VGA_THIS s.vga_memory[3*65536 + offset];
        return(BX_VGA_THIS s.graphics_ctrl.latch[BX_VGA_THIS s.graphics_ctrl.read_map_select]);
        break;

      case 1: /* read mode 1 */
        {
        Bit8u color_compare, color_dont_care;
        Bit8u latch0, latch1, latch2, latch3, retval, pixel_val;

        color_compare   = BX_VGA_THIS s.graphics_ctrl.color_compare & 0x0f;
        color_dont_care = BX_VGA_THIS s.graphics_ctrl.color_dont_care & 0x0f;
        offset = addr - 0xA0000;
        latch0 = BX_VGA_THIS s.graphics_ctrl.latch[0] = BX_VGA_THIS s.vga_memory[          offset];
        latch1 = BX_VGA_THIS s.graphics_ctrl.latch[1] = BX_VGA_THIS s.vga_memory[1*65536 + offset];
        latch2 = BX_VGA_THIS s.graphics_ctrl.latch[2] = BX_VGA_THIS s.vga_memory[2*65536 + offset];
        latch3 = BX_VGA_THIS s.graphics_ctrl.latch[3] = BX_VGA_THIS s.vga_memory[3*65536 + offset];
        retval = 0;
        for (unsigned b=0; b<8; b++) {
          pixel_val =
            ((latch0 << 0) & 0x01) |
            ((latch1 << 1) & 0x02) |
            ((latch2 << 2) & 0x04) |
            ((latch3 << 3) & 0x08);
          latch0 >>= 1;
          latch1 >>= 1;
          latch2 >>= 1;
          latch3 >>= 1;
          if ( (pixel_val & color_dont_care) ==
               (color_compare & color_dont_care) )
            retval |= (1 << b);
          }
        return(retval);
        }
        break;

      default:
        BX_PANIC(("vga_mem_read: read mode %u ?\n",
          (unsigned) BX_VGA_THIS s.graphics_ctrl.read_mode));
        return(0);
      }
    return(0);
    }
  else {
    return(BX_VGA_THIS s.vga_memory[addr - 0xa0000]);
    }
}

  void
bx_vga_c::mem_write(Bit32u addr, Bit8u value)
{
  Bit32u offset;
  Bit8u new_bit, new_val[4], cpu_data_b[4];

#if defined(VGA_TRACE_FEATURE)
//	BX_DEBUG(("8-bit memory write to %08x = %02x\n", addr, value));
#endif

#ifdef __OS2__
  if ( bx_options.videomode == BX_VIDEO_DIRECT )
    {
    devices->mem->video[addr-0xA0000] = value;

    return;
    }
#endif


  if (BX_VGA_THIS s.graphics_ctrl.graphics_alpha) {
    if (BX_VGA_THIS s.graphics_ctrl.memory_mapping == 1) { // 0xA0000 .. 0xAFFFF
      // unsigned x_tileno, y_tileno;

      if ( (addr < 0xA0000) || (addr > 0xAFFFF) )
        return;
      offset = addr - 0xA0000;
      }
    else if (BX_VGA_THIS s.graphics_ctrl.memory_mapping == 3) { // 0xB8000 .. 0xBFFFF
      // unsigned x_tileno, y_tileno;

      if ( (addr < 0xB8000) || (addr > 0xBFFFF) )
        return;
      offset = addr - 0xB8000;
      }
    else {
      BX_PANIC(("vga_mem_write: graphics: mapping = %u\n",
               (unsigned) BX_VGA_THIS s.graphics_ctrl.memory_mapping));
      return;
      }

    if ( BX_VGA_THIS s.sequencer.chain_four ) {
      unsigned x_tileno, y_tileno;

      offset = addr - 0xA0000;

      BX_VGA_THIS s.vga_memory[(offset & ~0x03) + (offset % 4)*65536] = value;
      // 320 x 200 256 color mode: chained pixel representation
      y_tileno = (offset / 320) / Y_TILESIZE;
      x_tileno = (offset % 320) / X_TILESIZE;
      BX_VGA_THIS s.vga_mem_updated = 1;
      BX_VGA_THIS s.vga_tile_updated[x_tileno][y_tileno] = 1;
      return;
      }

    /* addr between 0xA0000 and 0xAFFFF */
    switch (BX_VGA_THIS s.graphics_ctrl.write_mode) {
      Bit8u and_mask, bitmask;
      Bit8u set_reset_b[4];
      unsigned i, b;

      case 0: /* write mode 0 */
        /* perform rotate on CPU data in case its needed */
        value = (value >> BX_VGA_THIS s.graphics_ctrl.data_rotate) |
                (value << (8 - BX_VGA_THIS s.graphics_ctrl.data_rotate));
        bitmask = BX_VGA_THIS s.graphics_ctrl.bitmask;
        for (i=0; i<4; i++ ) {
          new_val[i] = 0;
          }
        set_reset_b[0] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 0) & 0x01;
        set_reset_b[1] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 1) & 0x01;
        set_reset_b[2] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 2) & 0x01;
        set_reset_b[3] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 3) & 0x01;
        and_mask = 1;
        for (b=0; b<8; b++) {
          if (bitmask & 0x01) { /* bit-mask bit set, perform op */
            for (i=0; i<4; i++) {
              /* derive bit from set/reset register */
              if ( (BX_VGA_THIS s.graphics_ctrl.enable_set_reset >> i) & 0x01 ) {
                new_bit = (set_reset_b[i] << b);
                }
              /* derive bit from rotated CPU data */
              else {
                new_bit = (value & and_mask);
                }
              switch (BX_VGA_THIS s.graphics_ctrl.raster_op) {
                case 0: /* replace */
                  new_val[i] |= new_bit;
                  break;
                case 1: /* AND with latch data */
                  new_val[i] |=
                    (new_bit & (BX_VGA_THIS s.graphics_ctrl.latch[i] & and_mask));
                  break;
                case 2: /* OR with latch data */
                  new_val[i] |=
                    (new_bit | (BX_VGA_THIS s.graphics_ctrl.latch[i] & and_mask));
                  break;
                case 3: /* XOR with latch data */
                  new_val[i] |=
                    (new_bit ^ (BX_VGA_THIS s.graphics_ctrl.latch[i] & and_mask));
                  break;
                default:
                  BX_PANIC(("vga_mem_write: write mode 0: op = %u\n",
                    (unsigned) BX_VGA_THIS s.graphics_ctrl.raster_op));
                }
              }
            }
          else { /* bit-mask bit clear, pass data thru from latch */
            new_val[0] |= (BX_VGA_THIS s.graphics_ctrl.latch[0] & and_mask);
            new_val[1] |= (BX_VGA_THIS s.graphics_ctrl.latch[1] & and_mask);
            new_val[2] |= (BX_VGA_THIS s.graphics_ctrl.latch[2] & and_mask);
            new_val[3] |= (BX_VGA_THIS s.graphics_ctrl.latch[3] & and_mask);
            }
          bitmask >>= 1;
          and_mask <<= 1;
          }
        break;

      case 1: /* write mode 1 */
        for (i=0; i<4; i++ ) {
          new_val[i] = BX_VGA_THIS s.graphics_ctrl.latch[i];
          }
        break;

      case 2: /* write mode 2 */
        if (BX_VGA_THIS s.graphics_ctrl.raster_op)
          BX_PANIC(("vga_mem_write: write mode 2: op = %u\n",
                   (unsigned) BX_VGA_THIS s.graphics_ctrl.raster_op));
        bitmask = BX_VGA_THIS s.graphics_ctrl.bitmask;
        for (i=0; i<4; i++ ) {
          new_val[i] = 0;
          }
        cpu_data_b[0] = (value >> 0) & 0x01;
        cpu_data_b[1] = (value >> 1) & 0x01;
        cpu_data_b[2] = (value >> 2) & 0x01;
        cpu_data_b[3] = (value >> 3) & 0x01;
        and_mask = 1;
        for (b=0; b<8; b++) {
          if (bitmask & 0x01) { /* bit-mask bit set, perform op */
            switch (BX_VGA_THIS s.graphics_ctrl.raster_op) {
              case 0: /* replace: write cpu data unmodified */
                new_val[0] |= cpu_data_b[0] << b;
                new_val[1] |= cpu_data_b[1] << b;
                new_val[2] |= cpu_data_b[2] << b;
                new_val[3] |= cpu_data_b[3] << b;
                break;
              case 1: /* AND */
              case 2: /* OR */
              case 3: /* XOR */
              default:
                BX_PANIC(("vga_mem_write: raster_op = %u?\n",
                  (unsigned) BX_VGA_THIS s.graphics_ctrl.raster_op));
              }
            }
          else { /* bit-mask bit clear, pass data thru from latch */
            new_val[0] |= (BX_VGA_THIS s.graphics_ctrl.latch[0] & and_mask);
            new_val[1] |= (BX_VGA_THIS s.graphics_ctrl.latch[1] & and_mask);
            new_val[2] |= (BX_VGA_THIS s.graphics_ctrl.latch[2] & and_mask);
            new_val[3] |= (BX_VGA_THIS s.graphics_ctrl.latch[3] & and_mask);
            }
          bitmask >>= 1;
          and_mask <<= 1;
          }
        break;

      case 3: /* write mode 3 */
        /* perform rotate on CPU data */
        value = (value >> BX_VGA_THIS s.graphics_ctrl.data_rotate) |
                (value << (8 - BX_VGA_THIS s.graphics_ctrl.data_rotate));
        bitmask = (value & BX_VGA_THIS s.graphics_ctrl.bitmask);
        for (i=0; i<4; i++ ) {
          new_val[i] = 0;
          }
        set_reset_b[0] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 0) & 0x01;
        set_reset_b[1] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 1) & 0x01;
        set_reset_b[2] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 2) & 0x01;
        set_reset_b[3] = (BX_VGA_THIS s.graphics_ctrl.set_reset >> 3) & 0x01;
        and_mask = 1;
        for (b=0; b<8; b++) {
          if (bitmask & 0x01) { /* bit-mask bit set, perform op */
            for (i=0; i<4; i++) {
              /* derive bit from set/reset register */
		  /* (mch) I can't find any justification for this... */
		  if ( /* (mch) */ 1 || ((BX_VGA_THIS s.graphics_ctrl.enable_set_reset >> i) & 0x01 )) {
			// (mch) My guess is that the function select logic should go here
			switch (BX_VGA_THIS s.graphics_ctrl.raster_op) {
			      case 0: // write
				    new_val[i] |= (set_reset_b[i] << b);
				    break;
			      case 1: // AND
				    new_val[i] |= (set_reset_b[i] << b) &
					  (BX_VGA_THIS s.graphics_ctrl.latch[i] & (1 << b));
				    break;
			      case 2: // OR
				    new_val[i] |= (set_reset_b[i] << b) |
					  (BX_VGA_THIS s.graphics_ctrl.latch[i] & (1 << b));
				    break;
			      case 3: // XOR
				    new_val[i] |= (set_reset_b[i] << b) ^
					  (BX_VGA_THIS s.graphics_ctrl.latch[i] & (1 << b));
				    break;
			}
                }
              /* derive bit from rotated CPU data */
              else {
                new_val[i] |= (value & and_mask);
                }
              }
            }
          else { /* bit-mask bit clear, pass data thru from latch */
            new_val[0] |= (BX_VGA_THIS s.graphics_ctrl.latch[0] & and_mask);
            new_val[1] |= (BX_VGA_THIS s.graphics_ctrl.latch[1] & and_mask);
            new_val[2] |= (BX_VGA_THIS s.graphics_ctrl.latch[2] & and_mask);
            new_val[3] |= (BX_VGA_THIS s.graphics_ctrl.latch[3] & and_mask);
            }
          bitmask >>= 1;
          and_mask <<= 1;
          }
        break;

      default:
        BX_PANIC(("vga_mem_write: write mode %u ?\n",
          (unsigned) BX_VGA_THIS s.graphics_ctrl.write_mode));
      }

    if (BX_VGA_THIS s.sequencer.map_mask & 0x0f) {
      BX_VGA_THIS s.vga_mem_updated = 1;
      if (BX_VGA_THIS s.sequencer.map_mask_bit[0])
        BX_VGA_THIS s.vga_memory[0*65536 + offset] = new_val[0];
      if (BX_VGA_THIS s.sequencer.map_mask_bit[1])
        BX_VGA_THIS s.vga_memory[1*65536 + offset] = new_val[1];
      if (BX_VGA_THIS s.sequencer.map_mask_bit[2])
        BX_VGA_THIS s.vga_memory[2*65536 + offset] = new_val[2];
      if (BX_VGA_THIS s.sequencer.map_mask_bit[3])
        BX_VGA_THIS s.vga_memory[3*65536 + offset] = new_val[3];
{
unsigned x_tileno, y_tileno;

x_tileno = (offset % (BX_VGA_THIS s.scan_bits/8)) / (X_TILESIZE / 8);
y_tileno = (offset / (BX_VGA_THIS s.scan_bits/8)) / Y_TILESIZE;
BX_VGA_THIS s.vga_tile_updated[x_tileno][y_tileno] = 1;
}
      }
    }
  else {
    BX_VGA_THIS s.vga_memory[addr - 0xa0000] = value;
    vga_component->drive_text_memory_updated_pin();
    BX_VGA_THIS s.vga_mem_updated = 1;
    }
}



  void
bx_vga_c::dump_status(void)
{
  BX_INFO(("s.misc_output.color_emulation = %u\n",
            (unsigned) BX_VGA_THIS s.misc_output.color_emulation));
  BX_INFO(("s.misc_output.enable_ram = %u\n",
            (unsigned) BX_VGA_THIS s.misc_output.enable_ram));
  BX_INFO(("s.misc_output.clock_select = %u\n",
            (unsigned) BX_VGA_THIS s.misc_output.clock_select));
  if (BX_VGA_THIS s.misc_output.clock_select == 0)
    BX_INFO(("  25Mhz 640 horiz pixel clock\n"));
  else
    BX_INFO(("  28Mhz 720 horiz pixel clock\n"));
  BX_INFO(("s.misc_output.select_high_bank = %u\n",
            (unsigned) BX_VGA_THIS s.misc_output.select_high_bank));
  BX_INFO(("s.misc_output.horiz_sync_pol = %u\n",
            (unsigned) BX_VGA_THIS s.misc_output.horiz_sync_pol));
  BX_INFO(("s.misc_output.vert_sync_pol = %u\n",
            (unsigned) BX_VGA_THIS s.misc_output.vert_sync_pol));
  switch ( (BX_VGA_THIS s.misc_output.vert_sync_pol << 1) |
           BX_VGA_THIS s.misc_output.horiz_sync_pol ) {
    case 0: BX_INFO(("  (reserved\n")); break;
    case 1: BX_INFO(("  400 lines\n")); break;
    case 2: BX_INFO(("  350 lines\n")); break;
    case 3: BX_INFO(("  480 lines\n")); break;
    default: BX_INFO(("  ???\n"));
    }

  BX_INFO(("s.graphics_ctrl.odd_even = %u\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.odd_even));
  BX_INFO(("s.graphics_ctrl.chain_odd_even = %u\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.chain_odd_even));
  BX_INFO(("s.graphics_ctrl.shift_reg = %u\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.shift_reg));
  BX_INFO(("s.graphics_ctrl.graphics_alpha = %u\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.graphics_alpha));
  BX_INFO(("s.graphics_ctrl.memory_mapping = %u\n",
            (unsigned) BX_VGA_THIS s.graphics_ctrl.memory_mapping));
  switch (BX_VGA_THIS s.graphics_ctrl.memory_mapping) {
    case 0: BX_INFO(("  A0000-BFFFF\n")); break;
    case 1: BX_INFO(("  A0000-AFFFF\n")); break;
    case 2: BX_INFO(("  B0000-B7FFF\n")); break;
    case 3: BX_INFO(("  B8000-BFFFF\n")); break;
    default: BX_INFO(("  ???\n"));
    }

  BX_INFO(("s.sequencer.extended_mem = %u\n",
            (unsigned) BX_VGA_THIS s.sequencer.extended_mem));
  BX_INFO(("s.sequencer.odd_even = %u (inverted)\n",
            (unsigned) BX_VGA_THIS s.sequencer.odd_even));
  BX_INFO(("s.sequencer.chain_four = %u\n",
            (unsigned) BX_VGA_THIS s.sequencer.chain_four));

  BX_INFO(("s.attribute_ctrl.video_enabled = %u\n",
            (unsigned) BX_VGA_THIS s.attribute_ctrl.video_enabled));
  BX_INFO(("s.attribute_ctrl.mode_ctrl.graphics_alpha = %u\n",
            (unsigned) BX_VGA_THIS s.attribute_ctrl.mode_ctrl.graphics_alpha));
  BX_INFO(("s.attribute_ctrl.mode_ctrl.display_type = %u\n",
            (unsigned) BX_VGA_THIS s.attribute_ctrl.mode_ctrl.display_type));
  BX_INFO(("s.attribute_ctrl.mode_ctrl.internal_palette_size = %u\n",
            (unsigned) BX_VGA_THIS s.attribute_ctrl.mode_ctrl.internal_palette_size));
  BX_INFO(("s.attribute_ctrl.mode_ctrl.pixel_clock_select = %u\n",
            (unsigned) BX_VGA_THIS s.attribute_ctrl.mode_ctrl.pixel_clock_select));
}

void
bx_vga_c::update_dimension_pins(bool schedule_update)
{
  BX_VGA_THIS s.scan_bits=640;
  int piWidth, piHeight;

  if (s.graphics_ctrl.graphics_alpha == 0)
    {
      // text_mode
      piWidth = 80;
      if (s.graphics_ctrl.memory_mapping == 2)
        {
          // monochrome text mode
          piHeight = 25;
        }
      else
        {
          unsigned VDE, MSL, rows;
          
          // Verticle Display End: find out how many lines are displayed
          VDE = BX_VGA_THIS s.CRTC.reg[18] |
            ((BX_VGA_THIS s.CRTC.reg[7] << 7) & 0x100) |
            ((BX_VGA_THIS s.CRTC.reg[7] << 3) & 0x200);
          // Maximum Scan Line: height of character cell
          MSL = BX_VGA_THIS s.CRTC.reg[9] & 0x1f;
          rows = (VDE + 1) / (MSL + 1);
          if (rows > BX_MAX_TEXT_LINES)
            BX_PANIC(("text rows>50\n"));
          
          piHeight = rows;
        }
    }
  else
    {
      if ( BX_VGA_THIS s.graphics_ctrl.shift_reg == 0 )
        {
          piWidth = 640;
          piHeight = 480;
          
          if ( BX_VGA_THIS s.CRTC.reg[6] == 0xBF )
            {
              if (BX_VGA_THIS s.CRTC.reg[23] == 0xA3 &&
                  BX_VGA_THIS s.CRTC.reg[20] == 0x40 &&
                  BX_VGA_THIS s.CRTC.reg[9] == 0x41)
                {
                  piWidth = 320;
                  piHeight = 240;
                }
              if (BX_VGA_THIS s.CRTC.reg[23] == 0xE3 &&
                  BX_VGA_THIS s.CRTC.reg[20] == 0xF &&
                  BX_VGA_THIS s.CRTC.reg[9] == 0x40)
                {
                  piWidth = 640;
                  piHeight = 352;
                }
              if (BX_VGA_THIS s.CRTC.reg[23] == 0xE3 &&
                  BX_VGA_THIS s.CRTC.reg[20] == 0 &&
                  BX_VGA_THIS s.CRTC.reg[9] == 0xC0)
                {
                  if (BX_VGA_THIS s.CRTC.reg[19] == 0x14)
                    {
                      BX_VGA_THIS s.scan_bits=320;
                      piWidth = 320;
                      piHeight = 192;
                    }
                  else
                    {
                      piWidth = 640;
                      piHeight = 208;
                    }
                }
            }
        }
      else if ( BX_VGA_THIS s.graphics_ctrl.shift_reg == 2 )
        {
          piWidth = 320;
          
          if ( BX_VGA_THIS s.sequencer.chain_four )
            {
              piHeight = 208;
            }
          else
            {
              piHeight = 240;
              
              if (BX_VGA_THIS s.CRTC.reg[23] == 0xE3 &&
                  BX_VGA_THIS s.CRTC.reg[20] == 0 &&
                  BX_VGA_THIS s.CRTC.reg[9] == 0x40)
                piHeight = 400;
            }
        }
      else
        {
          piWidth = 640;
          piHeight = 400;
        }
    }
  vga_component->drive_dimension_width_pin(piWidth);
  vga_component->drive_dimension_height_pin(piHeight);

  if(schedule_update)
    vga_component->drive_dimensions_updated_pin();
}

void
bx_vga_c::update_text_pins(bool schedule_update)
{
  unsigned long start_address;
  unsigned long cursor_address, cursor_x, cursor_y;
  
  start_address = 2 * ((BX_VGA_THIS s.CRTC.reg[12] << 8) | BX_VGA_THIS s.CRTC.reg[13]);
  
  if (BX_VGA_THIS s.graphics_ctrl.memory_mapping == 2)
    {
      vga_component->drive_text_start_address_pin(0x10000 + start_address);
    }
  else if (BX_VGA_THIS s.graphics_ctrl.memory_mapping == 3)
    {
      vga_component->drive_text_start_address_pin(0x18000 + start_address);
    }
  cursor_address = 2 * ((BX_VGA_THIS s.CRTC.reg[14] << 8) | BX_VGA_THIS s.CRTC.reg[15]);
  
  if (cursor_address < start_address)
    {
      cursor_x = 0xffff;
      cursor_y = 0xffff;
    }
  else
    {
      cursor_x = ((cursor_address - start_address)/2) % 80;
      cursor_y = ((cursor_address - start_address)/2) / 80;
    }
  
  vga_component->drive_text_cursor_x_pin(cursor_x);
  vga_component->drive_text_cursor_y_pin(cursor_y);

  if(schedule_update)
    vga_component->drive_text_memory_updated_pin();
}
