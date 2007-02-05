// dmac.cxx - An implementation of the DMA controller for the
// Toshiba Media Processor (MeP). -*- C++ -*-

// Copyright (C) 2001-2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "mep-dmac.h"

mep_dmac_channel::mep_dmac_channel (mep_dmac &o,
				    control_register_bus<big_int_4> &b,
				    sidutil::output_pin &op,
				    sidutil::input_pin &ip)
  :
  owner (o),
  interrupt_pin (op),
  hw_req_pin (ip),
  control_bus (b),
  // Ctrl regs and fields. Fields with undefined initial values
  // are not initialized.
  car_act (0),
  car (& control_bus, 0x0, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_car, & mep_dmac_channel::get_car),
  ccr_htrq (0),
  ccr_bl (0),
  ccr_dcm (0),
  ccr_nie (0),
  ccr (& control_bus, 0x1, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_ccr, & mep_dmac_channel::get_ccr),
  tcm_did (0),
  tcm_tt (0),
  tcm (& control_bus, 0x2, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_tcm, & mep_dmac_channel::get_tcm),
  src (& control_bus, 0x3, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_src, & mep_dmac_channel::get_src),
  dst (& control_bus, 0x4, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_dst, & mep_dmac_channel::get_dst),
  trc (& control_bus, 0x5, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_trc, & mep_dmac_channel::get_trc),
  lwr (& control_bus, 0x6, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_lwr, & mep_dmac_channel::get_lwr),
  lsr_dls (0),
  lsr_sls (0),
  lsr (& control_bus, 0x7, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_lsr, & mep_dmac_channel::get_lsr),
  dta (& control_bus, 0x8, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_dta, & mep_dmac_channel::get_dta),
  dts (& control_bus, 0x9, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_dts, & mep_dmac_channel::get_dts),
  dsr_nc (0),
  dsr (& control_bus, 0xa, 0xffffffff, true, true, this,
       & mep_dmac_channel::set_dsr, & mep_dmac_channel::get_dsr),
  source_line_start (0),
  source_line_remain (0),
  dest_line_start (0),
  dest_line_remain (0),
  read_completed (true)
{
}

void mep_dmac_channel::set_car_act (unsigned act)
{
  if (act)
    {
      // Setting this bit when it is already set has no effect.
      if (car_act)
	return;

      car_act = 1;
      if (begin_transfer ())
	return;
    }

  // Bit being cleared, or init failed.
  car_act = 0;
}

void
mep_dmac_channel::set_dsr_nc (unsigned nc)
{
  // Setting this bit to 1 has no effect.
  if (nc == 1)
    return;

  // We must be clearing this bit. Also clear any
  // pending interrupt.
  dsr_nc = 0;
  interrupt_pin.drive (0);
}

// Initialize a DMA transfer
bool
mep_dmac_channel::init_transfer (host_int_2 &latency)
{
  // Initialize for possible chaining
  if (! init_chain (latency))
    return false;

#if 0
  // We and Toshiba both agree that this check *should* be made, however,
  // their simulator does not perform it and they would like sid to model
  // this (buggy) behavior.  The effect is that CAR.ACT remains on for this
  // channel even though there is no data to be transferred.
  if (! request_pending ())
    return false;
#endif

  // Check for a valid tranfer request
  if (! check_validity ())
    return false;

  // Initialize line lengths for possible rectangular transfer
  current_src_sa = src_sa;
  current_dst_da = dst_da;
  init_source_line ();
  init_dest_line ();
  read_completed = false;

  return true; // all is ok
}

// Make sure that the current configuration represents a valid transfer request.
bool
mep_dmac_channel::check_validity ()
{
  // Check that the configured burst size is supported. Bursts of 16 units
  // are not supported when the bus width is 64 bits (8 bytes).
  int bus_width = owner.data_width ();
  int burst = burst_size ();
  if (burst > 16
      || burst == 16 && owner.data_width () == 8)
    return false; // transfer config not valid

  // Check the transfer type
  if (tcm_tt >= 0x6)
    return false;

  // If a rectangular region is specified, check to make sure rectangular
  // transfers are enabled.
  if (is_rectangular ())
    {
      // Make sure rectangular transfers are supported.
      if (! owner.get_dcr_rto ())
	return false; // transfer config not valid
      
      // Make sure the line width is at least as large as the bus width.
      if (lwr_lw < bus_width)
	return false;

      // Make sure the line steps are at least as large as the line width.
      if (source_rectangular () && lsr_sls < lwr_lw)
	return false;
      if (dest_rectangular () && lsr_dls < lwr_lw)
	return false;
    }

  return true; // all is well.
}

void
mep_dmac_channel::init_source_line ()
{
  // Set the source line width as specified if a rectangular region is
  // specified, otherwise set it to the size of the complete transfer (i.e.
  // treat the entire transfer as one line).
  source_line_start = current_src_sa;
  if (source_rectangular ())
    source_line_remain = lwr_lw;
  else if (source_address_fixed ())
    source_line_remain = burst_size () * owner.data_width ();
  else
    source_line_remain = trc_trc;
}

void
mep_dmac_channel::init_dest_line ()
{
  // Set the source line width as specified if a rectangular region is
  // specified, otherwise set it to the size of the complete transfer (i.e.
  // treat the entire transfer as one line).
  dest_line_start = current_dst_da;
  if (dest_rectangular ())
    dest_line_remain = lwr_lw;
  else if (dest_address_fixed ())
    dest_line_remain = burst_size () * owner.data_width ();
  else
    dest_line_remain = trc_trc;
}

// Read in the chain descriptor from memory.
bool
mep_dmac_channel::init_chain (host_int_2 &total_latency)
{
  total_latency = 0;
  if (! ccr_dcm || dts_dts == 0)
    return true; // no chaining, but all is ok.

  if (mep_dmac::debug_burst)
    {
      cout << "chain length is " << dec << dts_dts
	   << " reading descriptor from " << hex << dta_dta << endl;
    }

  // Lock the downstream interface while we read the descriptor chain.
  owner.lock_downstream_for_chain ();

  // Read each register, checking for errors as we go.
  big_int_4 reg;
  host_int_2 latency;
  if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
    {
      owner.unlock_downstream_for_chain ();
      return false; // init failed
    }
  total_latency += latency;
  set_tcm (reg, 0);

  dta_dta = dta_dta + 4;
  if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
    {
      owner.unlock_downstream_for_chain ();
      return false; // init failed
    }
  total_latency += latency;
  set_src (reg, 0);

  dta_dta = dta_dta + 4;
  if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
    {
      owner.unlock_downstream_for_chain ();
      return false; // init failed
    }
  total_latency += latency;
  set_dst (reg, 0);

  // The downstream interface must be unlocked for the final read.
  // If the transfer mode is rectangular, then also read in the LWR and LSR
  dta_dta = dta_dta + 4;
  if (is_rectangular () && owner.get_dcr_rto ())
    {
      if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
	{
	  owner.unlock_downstream_for_chain ();
	  return false; // init failed
	}
      total_latency += latency;
      set_trc (reg, 0);

      dta_dta = dta_dta + 4;
      if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
	{
	  owner.unlock_downstream_for_chain ();
	  return false; // init failed
	}
      total_latency += latency;
      set_lwr (reg, 0);

      owner.unlock_downstream_for_chain ();
      
      dta_dta = dta_dta + 4;
      if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
	return false; // init failed
      set_lsr (reg, 0);
      total_latency += latency;
    }
  else
    {
      owner.unlock_downstream_for_chain ();
      if (! owner.read_from_local_mem (this, dta_dta, reg, latency))
	return false; // init failed
      set_trc (reg, 0);
      total_latency += latency;
    }

  // Update the chaining registers.
  set_dta_dta (dta_dta + 4);
  set_dts_dts (dts_dts - 1);

  return true;
}

// Start a DMA transfer.
bool
mep_dmac_channel::begin_transfer () throw ()
{
  host_int_2 latency;
  if (init_transfer (latency))
    {
      owner.begin_transfer (latency);
      return true;
    }
  return false;
}

// Adjust the burst size for alignment and data size limits.
int
mep_dmac_channel::limit_read_burst (bool bus_is_main, big_int_4 address,
				    big_int_4 length, int burst)
{
  return limit_burst (bus_is_main, address, length, source_line_remain, burst);
}

int
mep_dmac_channel::limit_write_burst (bool bus_is_main, big_int_4 address,
				     big_int_4 length, int burst)
{
  return limit_burst (bus_is_main, address, length, dest_line_remain, burst);
}

// Adjust the burst size for alignment and data size limits.
int
mep_dmac_channel::limit_burst (bool bus_is_main, big_int_4 address,
			       big_int_4 length, big_int_4 line_remain,
			       int burst)
{
  // The size of the transfer is limited by 3 factors
  //
  // 1) Alignment to a burst-size boundary if using the main bus.
  // 2) The specified size of the transfer.
  // 3) The remaining space on the current line (rectangular transfer).
  //
  if (bus_is_main)
    {
      big_int_4 alignment_limit = (address + burst) & ~(burst - 1);
      assert (alignment_limit > address);
      if (mep_dmac::debug_burst && alignment_limit - address < burst)
	{
	  cout << "burst aligned down to "
	       << dec << (alignment_limit - address) << endl;
	}
      burst = alignment_limit - address;
    }
  if (length < burst)
    {
      burst = length;
      if (mep_dmac::debug_burst)
	cout << "burst truncated to transfer count: " << dec << burst << endl;
    }
  if (line_remain < burst)
    {
      burst = line_remain;
      if (mep_dmac::debug_burst)
	cout << "burst truncated to line length: " << dec << burst << endl;
    }
  return burst;
}

void
mep_dmac_channel::update_after_read_burst (int burst)
{
  // Clear any lingering hw_request
  hw_req_pin.driven (0);

  // See if we need to advance to the next line
  source_line_remain = source_line_remain - burst;
  if (source_line_remain <= 0)
    {
      assert (source_line_remain == 0);
      if (source_rectangular ())
	current_src_sa = source_line_start + lsr_sls;
      else if (source_address_fixed ())
	current_src_sa = source_line_start;
      else
	current_src_sa = current_src_sa + burst;
      init_source_line ();
    }
  else
    current_src_sa = current_src_sa + burst;

  if (! source_address_fixed ())
    src_sa = current_src_sa;

  if (burst >= trc_trc)
    read_completed = true;
}

void
mep_dmac_channel::update_after_write_burst (int burst)
{
  // Clear any lingering hw_request
  hw_req_pin.driven (0);

  // See if we need to advance to the next line
  dest_line_remain = dest_line_remain - burst;
  if (dest_line_remain <= 0)
    {
      assert (dest_line_remain == 0);
      if (dest_rectangular ())
	current_dst_da = dest_line_start + lsr_dls;
      else if (dest_address_fixed ())
	current_dst_da = dest_line_start;
      else
	current_dst_da = current_dst_da + burst;
      init_dest_line ();
    }
  else
    current_dst_da  = current_dst_da + burst;

  if (! dest_address_fixed ())
    dst_da = current_dst_da;

  // Update the transfer counter
  set_trc_trc (trc_trc - burst);
}

void
mep_dmac_channel::transfer_complete ()
{
  set_trc_trc (0);
  dsr_nc = 1; // bypass access restrictions
  set_car_act (0);
}

big_int_4
mep_dmac_channel::get_ccr () {
  return ((ccr_htrq << 12) & 0x1000)
       | ((ccr_bl   << 8)  & 0x300)
       | ((ccr_dcm  << 4)  & 0x10)
       | ((ccr_nie         & 0x1));
}

big_int_4
mep_dmac_channel::get_tcm ()
{
  return ((tcm_did << 24) & 0xff000000)
        | (tcm_tt         & 0x7);
}

big_int_4
mep_dmac_channel::get_lsr ()
{
  return ((lsr_dls << 16) & 0xffff0000)
        | (lsr_sls        & 0xffff);
}

extern "C" void *mep_dmac_child_thread_root (void *comp);

mep_dmac::mep_dmac ()
  :
  blocking_component (this, mep_dmac_child_thread_root),
  active (false),
  main_ctrl_bus (),
  dcr_value (dcr_default),
  dcr (& main_ctrl_bus, 0x0, 0xffffffff, true, true, this,
       & mep_dmac::set_dcr, & mep_dmac::get_dcr),
  high_channel (0),
  read_buffer_ix (0),
  write_buffer_ix (0),
  sched ("burst", this, & mep_dmac::perform_action),
  local_mem_bus (0),
  main_mem_bus (0),
  bus_error_pin ()
{
  // Add two accessors to this component: "local-memory" and "main-memory".
  // A bus will be connected to each of these accessors via configuration.
  add_accessor ("local-memory", & local_mem_bus);
  add_accessor ("main-memory", & main_mem_bus);

  // Allocate and assign  a control bus, interrupt pin and a hw_req
  // pin for each channel.
  for (int i = 0; i < max_channels; ++i)
    {
      channels[i] = NULL;
      channel_ctrl_bus[i] = new control_register_bus<big_int_4> ();
      interrupt_pin[i] = new sidutil::output_pin ();
      hw_req_pin[i] = new sidutil::input_pin;
      add_bus ("channel-control-regs-"  + make_numeric_attribute (i), channel_ctrl_bus[i]);
      add_pin ("interrupt-" + make_numeric_attribute (i), interrupt_pin[i]);
      add_pin ("hw-req-" + make_numeric_attribute (i), hw_req_pin[i]);
    }
  add_pin ("gbif-lock", & gbif_lock_pin);
  gbif_lock_pin.set_active_high ();
  add_pin ("lbif-lock", & lbif_lock_pin);
  lbif_lock_pin.set_active_high ();
  add_pin ("check-address", & check_address_pin);
  add_pin ("bus-error", & bus_error_pin);
  add_pin ("error", & error_pin);

  // Add the main control bus.
  add_bus ("main-control-regs", & main_ctrl_bus);

  // Set up the default configuration.
  add_attribute_notify ("dcr", & dcr_value, this, & mep_dmac::dcr_attribute_set,
			"control register setting");
  set_attribute_value ("dcr", make_numeric_attribute (dcr_value));

  // Allocate the internal data buffers.
  buffers[0] = new mep_dmac_buffer ();
  buffers[1] = new mep_dmac_buffer ();
}

// Called after the dcr attribute is set to alter the configuration
// accordingly.
void
mep_dmac::dcr_attribute_set ()
{
  // Allocate the requested number of channels
  int num_channels = get_dcr_cnn ();
  for (int i = 0; i < num_channels; ++i)
    {
      if (channels[i] != NULL)
	continue; // already allocated
      assert (channel_ctrl_bus[i]);
      assert (interrupt_pin[i]);
      channels[i] = new mep_dmac_channel (*this, *channel_ctrl_bus[i],
					  *interrupt_pin[i], *hw_req_pin[i]);
    }
}

void
mep_dmac::begin_transfer (host_int_2 latency) throw ()
{
  record_latency (latency, "chain initialization");

  if (active)
    return;

  // Schedule the transfer with the scheduler.
  active = true;
  sched.schedule_irregular (begin_wait);  
}

void
mep_dmac::perform_action () throw ()
{
  // If we're blockable, then activate the child thread and wait.
  if (blockable)
    {
      // Signal the child thread to resume
      need_child_thread ();
      continue_child_thread_and_wait ();
      return;
    }

  // Not blockable, so simply perform one burst
  do_one_burst ();
}

void
mep_dmac::do_one_burst () throw ()
{
  if (debug_burst)
    cout << "------------------------" << endl;

  // Determine whether a read burst is possible during this cycle.
  int read_channel = read_burst_channel ();

  // See if a write burst is pending.
  //
  int write_channel = -1;
  host_int_2 max_latency = 0;
  if (write_burst_pending ())
    {
      // A write burst will be performed.  Check whether a read burst will still
      // be possible.
      if (read_channel >= 0 && read_write_conflict (read_channel))
	read_channel = -1;
	
      // If the write buffer is still not empty, then the write burst
      // has been split into two bursts because of alignment issues on the main
      // bus.  The write will be completed on the next burst, however, there
      // must be no read in the mean time.
      //
      max_latency = perform_write_burst (write_channel);
      if (! active)
	return; // error

      if (write_burst_pending ())
	read_channel = -1;

      // Write with no read on this cycle, so insert wait cycles
      if (blockable && read_channel < 0)
	{
	  log (7, "%s: Wait 2 additional cycles after write\n", name.c_str ());
	  max_latency += 2;
	}
    }

  // Perform a read burst, if possible. Otherwise,
  // check whether the entire DMAC is now idle.
  //
  if (read_channel >= 0)
    {
      host_int_2 read_latency = perform_read_burst (read_channel);
      if (! active)
	return; // error
      host_int_2 a_latency = arbitration_latency (read_channel);
      read_latency += a_latency;
      if (blockable && read_latency > max_latency)
	{
	  log (7, "%s: Wait %d additional cycles for arbitration after read\n",
	       name.c_str (), a_latency);
	  max_latency = read_latency;
	}
    }

  // Wait for the appropriate latency before doing another cycle
  if (blockable)
    {
      log (7, "%s: Wait total %d cycles after write/read\n", name.c_str (), max_latency);
      sched.schedule_irregular (max_latency);
      child_blocked ();
    }

  // Check whether this write ends the operation for the associated channel.
  if (write_channel >= 0)
    check_end_burst (write_channel);

  // Prioritize only after a cycle containing a read
  if (read_channel >= 0)
    prioritize_channels ();
  else if (! write_burst_pending () && ! read_burst_pending ())
    {
      sched.cancel ();
      active = false;
      return; // all transfers complete.
    }

  // Schedule the next burst
  sched.schedule_irregular (transfer_wait);
}

int
mep_dmac::read_burst_channel (bool consider_all)
{
  // Starting with the channel selected during the last prioritization, look
  // for a channel with a pending request.
  int next = -1;
  for (int c = high_channel; next != high_channel; c = next)
    {
      // Consider channels with a request pending and available to be
      // scheduled.
      if (channels[c]->request_pending ()
	  && (consider_all || channels[c]->ready ()))
	return c;
      next = next_channel (c);
    }

  return -1; // no read burst pending
}

bool
mep_dmac::write_burst_pending ()
{
  return buffers[write_buffer_ix]->write_pending ();
}

// Check whether the pending read on this channel is from the same bus
// as the pending write.
bool
mep_dmac::read_write_conflict (int channel_num)
{
  assert (channel_num >= 0);
  assert (write_burst_pending ());

  mep_dmac_channel *src_channel = channels[channel_num];
  assert (src_channel->request_pending ());
  mep_dmac_buffer *buffer = buffers[write_buffer_ix];
  mep_dmac_channel *dst_channel = channels[buffer->channel_num ()];

  return bus_for_address (dst_channel->get_dst_da ())
         == bus_for_address (src_channel->get_src_sa ());
}

host_int_2
mep_dmac::perform_read_burst (int channel_num)
{
  // This channel is now the high priority channel by virtue of it being
  // the channel currently being served.
  assert (channel_num >= 0);
  high_channel = channel_num;

  // Determine which buffer to read into.
#if 1
  assert (! write_burst_pending ());
#else
  // TODO -- two buffers may not be necessary
  if (read_buffer_ix == write_buffer_ix && write_burst_pending ())
    read_buffer_ix = ! read_buffer_ix;
#endif
  mep_dmac_buffer *buffer = buffers[read_buffer_ix];

  // Get the transfer information
  //
  mep_dmac_channel *channel = channels[channel_num];
  big_int_4 from_addr = channel->get_current_src_sa ();
  big_int_4 trc_trc = channel->get_trc_trc ();

  // Calculate the burst size. CCR_BL is
  // 0 for  4 unit burst
  // 1 for  8 unit burst
  // 2 for 16 unit burst
  int width = data_width ();
  int burst = channel->burst_size () * width;
  assert (burst <= 64);
  buffer->initialize (channel_num, burst);

  // We want the buffer to have the actual burst size, so make any burst size
  // adjustments here, after initializing the buffer.
  bus *from_bus = bus_for_address (from_addr);
  burst = channel->limit_read_burst (from_bus == main_mem_bus, from_addr,
				     trc_trc, burst);

  // The source address may need adjustment, depending on the bus.
  from_addr = adjust_address (from_bus, from_addr);

  // Lock the downstream interface for all but the last access of the burst.
  lock_downstream (from_bus);

  // Read the data.
  host_int_2 total_latency = 0;
  for (int i = 0; i < burst; i += width) 
    {
      // Unlock the downstream interface for the last write
      if (i + width >= burst)
	unlock_downstream (from_bus);

      // Copy 'width' bytes at a time.
      big_int_4 buf4;
      big_int_8 buf8;
      bus::status s;
      if (width == 8)
	s = read_downstream (from_bus, from_addr + i, buf8);
      else
	s = read_downstream (from_bus, from_addr + i, buf4);
      if (s != ok)
	{
	  unlock_downstream (from_bus);
	  signal_bus_error ();
	  return 0;
	}
      total_latency += s.latency;
      if (debug_burst)
	{
	  cout << "channel " << channel_num
	       << " read " << width << " bytes (0x"
	       << hex;
	  if (width == 8)
	    cout << buf8;
	  else
	    cout << buf4;
	  cout << ") from 0x"
	       << (from_addr + i) << " on "
	       << (from_bus == main_mem_bus ? "main bus" : "local bus")
	       << endl;
	}

      if (width == 8)
	buffer->add_bytes (buf8);
      else
	buffer->add_bytes (buf4);
    }

  // Update the channel's control registers.
  channel->update_after_read_burst (burst);

  return total_latency;
}

template<typename DataType>
bus::status
mep_dmac::read_downstream (bus *from_bus, big_int_4 from_addr, DataType &buf)
{
  bus::status s;
  do
    {
      s = from_bus->read (from_addr, buf);
      if (s == ok)
	break;
    }
  while (handle_bus_error (s));
  return s;
}

host_int_2
mep_dmac::arbitration_latency (int channel_num)
{
  mep_dmac_channel *channel = channels[channel_num];

  big_int_4 address = channel->get_current_src_sa ();
  bus *from_bus = bus_for_address (address);

  address = channel->get_current_dst_da ();
  bus *to_bus = bus_for_address (address);

  return from_bus == to_bus ? 2 : to_bus == local_mem_bus ? 3 : 1;
}

big_int_4
mep_dmac::adjust_address (bus* bus, big_int_4 address)
{
  // Local memory is based as address 0x200000 from the
  // point of view of the DMAC.
  assert (bus);
  if (bus == local_mem_bus)
    address = address - 0x200000;

  return address;
}

// Choose the channel with highest priority.
void
mep_dmac:: prioritize_channels ()
{
  if (get_dcr_cprt ())
    {
      // Fixed priority
      high_channel = 0;
      return;
    }

  // Round robin priority
  high_channel = next_channel (high_channel);
}

// Return the next channel in the round robin sequence.
int
mep_dmac::next_channel (int c)
{
  ++c;
  if (c >= get_dcr_cnn ())
    c = 0;
  return c;
}

// Perform a single write burst from the current write buffer.
host_int_2
mep_dmac::perform_write_burst (int &channel_num)
{
  mep_dmac_buffer  *buffer  = buffers[write_buffer_ix];
  channel_num = buffer->channel_num ();
  mep_dmac_channel *channel = channels[channel_num];

  big_int_4 address = channel->get_current_dst_da ();
  bus *to_bus = bus_for_address (address);
  assert (to_bus);

  // Limit the burst to the actual data size.
  int burst = buffer->burst_size ();
  burst = channel->limit_write_burst (to_bus == main_mem_bus, address,
				      buffer->data_size (), burst);

  // The address may need adjustment, depending on the bus.
  big_int_4 effective_address = adjust_address (to_bus, address);

  // Lock the downstream interface for all but the last access of the burst.
  lock_downstream (to_bus);

  host_int_2 total_latency = 0;
  int width = data_width ();
  for (int i = 0; i < burst; i += width) 
    {
      // Unlock the downstream interface for the last write
      if (i + width >= burst)
	unlock_downstream (to_bus);

      // Copy 'width' bytes at a time.
      big_int_4 buf4;
      big_int_8 buf8;
      bus::status s;
      if (width == 8)
	{
	  buf8 = buffer->flush_8_bytes ();
	  if (debug_burst)
	    {
	      cout << "channel " << dec << channel_num
		   << " write 8 bytes (0x"
		   << hex << buf8 << ") to 0x" << (address + i) << " on "
		   << (to_bus == main_mem_bus ? "main bus" : "local bus")
		   << endl;
	    }
	  // Attempt the write.
	  s = write_downstream (to_bus, effective_address + i, buf8);
	}
      else
	{
	  buf4 = buffer->flush_4_bytes ();
	  if (debug_burst)
	    {
	      cout << "channel " << dec << channel_num
		   << " write 4 bytes (0x"
		   << hex << buf4 << ") to 0x" << (address + i) << " on "
		   << (to_bus == main_mem_bus ? "main bus" : "local bus")
		   << endl;
	    }
	  // Attempt the write.
	  s = write_downstream (to_bus, effective_address + i, buf4);
	}

      if (s == bus::unpermitted)
	{
	  // Write to ROM
	  cerr << "DMA channel " << channel_num
	       << ": Invalid write to ROM at 0x" << hex << (address + i) << dec
	       << endl;
	  unlock_downstream (to_bus);
	  error_pin.drive (1);
	  active = false;
	  return 0;
	}
      if (s != bus::ok)
	{
	  unlock_downstream (to_bus);
	  signal_bus_error ();
	  return 0;
	}
      total_latency += s.latency;
      check_address_pin.drive (address + i);
    }

  // The next write will be from the current read buffer.
  if (! buffer->write_pending ())
    write_buffer_ix = read_buffer_ix;

  // Update the channel's control registers.
  channel->update_after_write_burst (burst);

  return total_latency;
}

template<typename DataType>
bus::status
mep_dmac::write_downstream (bus *to_bus, big_int_4 address, DataType buf)
{
  bus::status s;
  do
    {
      s = to_bus->write (address, buf);
      if (s == bus::ok)
	break;
    }
  while (handle_bus_error (s));
  return s;
}

void
mep_dmac::check_end_burst (int channel_num)
{
  assert (channel_num >= 0);
  mep_dmac_channel *channel = channels[channel_num];

  // Check whether the transfer for this channel is complete.
  if (channel->get_trc_trc () <= 0) 
    {
      // First check to see whether there is a chained descriptor to continue
      // with.
      // We need to specifically check for request_pending since it is not
      // done in init_transfer. See the comment in that function as to why.
      host_int_2 latency;
      if (channel->init_transfer (latency) && channel->request_pending ())
	{
	  record_latency (latency, "chain initialization");
	  return; // Still active
	}

      // The transfer on this channel is complete.
      channel->transfer_complete ();

      // Generate an interrupt, if requested.
      if (channel->get_ccr_nie ())
	interrupt_pin[channel_num]->drive(1);
    }
}

template<typename DataType>
bool
mep_dmac::read_from_local_mem (mep_dmac_channel *channel, big_int_4 address,
			       DataType &buffer, host_int_2 &latency)
{
  latency = 0;
  bus::status s;
  do
    {
      s = local_mem_bus->read (address, buffer);
      latency += s.latency;
      if (s == ok)
	break;
    }
  while (handle_bus_error (s));

  if (s != ok)
    {
      signal_bus_error ();
      return false;
    }

  return true;
}

void mep_dmac::set_dcr (big_int_4 value, big_int_4 unused)
{
  // A write of 1 to dcr_mbe has no effect
  if (value & 0x8000)
    value = (value & ~0x8000) | (dcr_value & 0x8000);

  // Mask off read-only fields
  big_int_4 mask = 0xffff7ffe;
  dcr_value = (dcr_value & mask) | (value & ~mask);

  // Check DCR.MBE
  if (! get_dcr_mbe ())
    bus_error_pin.drive (0);
}

void
mep_dmac::signal_bus_error ()
{
  set_dcr_mbe (1);
  int num_channels = get_dcr_cnn ();
  for (int i = 0; i < num_channels; ++i)
    {
      assert (channels[i]);
      channels[i]->set_car_act (0);
    }
  sched.cancel ();
  active = false;
  bus_error_pin.drive (1);
}

bus *
mep_dmac::bus_for_address (big_int_4 address)
{
  // Addresses in the ranges:
  //   0x200000-0x2fffff
  //   0x600000-0x6fffff
  // are on the local bus. Other addresses are on the main bus.
  if (address >= 0x200000)
    {
      if (address <= 0x2fffff
	  || address >= 0x600000 && address <= 0x6fffff)
	return local_mem_bus;
    }

  return main_mem_bus;
}

// Locks the downstream interface for the duration of the burst
void
mep_dmac::lock_downstream (bus *bus)
{
  log (7, "%s: downstream pin %s now 1\n", name.c_str (),
       bus == main_mem_bus ? "GBIF" : "LBIF");

  if (bus == main_mem_bus)
    gbif_lock_pin.on ();
  else
    lbif_lock_pin.on ();
}

void
mep_dmac::unlock_downstream (bus *bus)
{
  log (7, "%s: downstream pin %s now 0\n", name.c_str (),
       bus == main_mem_bus ? "GBIF" : "LBIF");
  if (bus == main_mem_bus)
    gbif_lock_pin.off ();
  else
    lbif_lock_pin.off ();
}

// Handles bus errors from reads and writes from/to memory.
// Specifically, bus::busy is handled in blockable mode.
//
bool
mep_dmac::handle_bus_error (sid::bus::status s)
{
  if (s != sid::bus::busy)
    return false; // not handled

  record_latency (s.latency, "downstream interface busy");
  return true;
}


void
mep_dmac::record_latency (host_int_2 latency, const char* what)
{
  // Wait for the appropriate latency before starting the cycle
  if (blockable && latency != 0)
    {
      log (7, "%s: Wait %d cycles for %s\n", name.c_str (), latency, what);
      sched.schedule_irregular (latency);
      child_blocked ();
    }
}

// This function is the root of the blockable child thread. It gets passed
// to pthread_create.
//
extern "C" void *
mep_dmac_child_thread_root (void *comp)
{
  // Set up this thread to receive and handle signals from the parent thread.
  // this need only be done once.
  //
  mep_dmac *dmac = static_cast<mep_dmac *>(comp);
  dmac->child_init ();

  for (;;)
    {
      // Signal completion and wait for the signal to resume
      dmac->child_completed ();

      // Perform the required action
      dmac->do_one_burst ();
    }

  // We should never reach here.
  return NULL;
}

void
mep_dmac::configure (const string &config)
{
  // Call up to the base class first
  blocking_component::configure (config);

  // Now handle relevent configuration for us.
  if (config.size () <= 13)
    return;
  if (config.substr (0, 13) == "model-busses=")
    {
      set_attribute_value ("blockable?", config.substr (13));
      return;
    }
}

template<typename DataType>
void
mep_dmac_buffer::add_bytes (DataType bytes)
{
  for (unsigned i = 0; i < sizeof (bytes); ++i)
    {
      assert (_data_end_ix < buffer_size);
      _data[_data_end_ix++] = bytes.read_byte (i);
    }
}

big_int_4
mep_dmac_buffer::flush_4_bytes ()
{
  big_int_4 value = 0;

  for (unsigned i = 0; i < 4; ++i)
    {
      assert (_data_ix < _data_end_ix);
      assert (_data_end_ix <= buffer_size);
      value.write_byte (i, _data[_data_ix++]);
    }

  return value;
}

big_int_8
mep_dmac_buffer::flush_8_bytes ()
{
  big_int_8 value = 0;

  for (unsigned i = 0; i < 8; ++i)
    {
      assert (_data_ix < _data_end_ix);
      assert (_data_end_ix <= buffer_size);
      value.write_byte (i, _data[_data_ix++]);
    }

  return value;
}
