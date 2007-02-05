// mep-dmac.h - Class declaration for the Toshiba Media Engine (MeP) DMA
// controller.  -*- C++ -*-

// Copyright (C) 2001, 2002, 2003, 2004, 2005 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef MEP_DMAC_H
#define MEP_DMAC_H

#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidschedutil.h>
#include <sidbusutil.h>
#include <sidcpuutil.h>
#include <sidblockingutil.h>

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;
using namespace std;

class mep_dmac_channel;
class mep_dmac_buffer;

// The actual DMAC component.
// Inherit mix-in classes.
class mep_dmac: public virtual component,
		protected virtual fixed_attribute_map_component,
		protected fixed_bus_map_component,
		protected virtual fixed_pin_map_component,
		protected fixed_accessor_map_component,
		protected no_relation_component,
		public blocking_component
{
public:
  mep_dmac ();

  // Start the DMA transfer.
  void begin_transfer (host_int_2 latency) throw ();

  // Read from local memory
  template<typename DataType>
  bool read_from_local_mem (mep_dmac_channel *channel, big_int_4 address,
			    DataType &buffer, host_int_2 &latency);

  // Return the data bus width in bytes.
  int data_width () { return 1 << (get_dcr_mbdw () + 2); }

  void lock_downstream_for_chain () { lock_downstream (local_mem_bus); }
  void unlock_downstream_for_chain () { unlock_downstream (local_mem_bus); }
  void record_latency (host_int_2 latency, const char* what);

  void set_dcr_mbe  (big_int_4 mbe)  { dcr_value = (dcr_value & ~0x8000) | ((mbe << 15) & 0x8000); }
  void set_dcr_cnn  (big_int_4 cnn)  { /* readonly */ }
  void set_dcr_mbdw (big_int_4 mdbw) { /* readonly */ }
  void set_dcr_lbdw (big_int_4 lbd)  { /* readonly */ }
  void set_dcr_rto  (big_int_4 rto)  { /* readonly */ }
  void set_dcr_cprt (big_int_4 cprt) { dcr_value = (dcr_value & ~0x0001) | (cprt & 0x0001); }

  big_int_4 get_dcr_mbe  () { return (dcr_value >> 15) & 0x1; }
  big_int_4 get_dcr_cnn  () { return (dcr_value >>  8) & 0xf; }
  big_int_4 get_dcr_mbdw () { return (dcr_value >>  6) & 0x3; }
  big_int_4 get_dcr_lbdw () { return (dcr_value >>  4) & 0x1; }
  big_int_4 get_dcr_rto  () { return (dcr_value >>  2) & 0x1; }
  big_int_4 get_dcr_cprt () { return (dcr_value      ) & 0x1; }

  // Debugging
  static const bool debug_burst = false;

public: //Must be callable from the child thread loop
  void do_one_burst () throw ();

private:
  // State flag
  bool active;

  static const int max_channels = 6;
  static const int begin_wait = 1;
  static const int transfer_wait = 1;

  // One control bus for each of the channels.
  control_register_bus<big_int_4> *channel_ctrl_bus[max_channels];
  
  // One additional control bus for overall control.
  control_register_bus<big_int_4> main_ctrl_bus;

  // DCR (DMA Control Register).  Maintained as an integer
  // and accessible as an attribute or via the main_ctrl_bus.
  big_int_4 dcr_value;
  callback_control_register<big_int_4,mep_dmac> dcr;
  void dcr_attribute_set ();

  void set_dcr (big_int_4 value,  big_int_4 unused);
  big_int_4 get_dcr () { return dcr_value; }

  // Default configuration.
  // - 1 channel
  // - 64 bit main bus width
  // - 64 bit local bus width
  // - no rectangular transfer support
  // - round robin priority
  static const host_int_4 dcr_default = 0x00000150;

  // The DMAC Channels
  mep_dmac_channel *channels[max_channels];

  // The current highest priority channel
  int high_channel;

  // Return the next channel in the round robin sequence.
  int next_channel (int c);

  // Internal data buffers.
  mep_dmac_buffer *buffers[2];
  int read_buffer_ix;
  int write_buffer_ix;

  // DMA transfer state machine.
  scheduler_event_subscription<mep_dmac> sched;

  // Handle to local memory bus.
  bus* local_mem_bus;

  // Handle to main memory bus.
  bus* main_mem_bus;

  // Output pins.
  sidutil::output_pin check_address_pin;
  sidutil::output_pin *interrupt_pin[max_channels];
  sidutil::output_pin bus_error_pin;
  sidutil::output_pin error_pin;

  // input pins
  sidutil::input_pin *hw_req_pin[max_channels];

  // Map address to local or main bus.
  bus *bus_for_address (big_int_4 address);

  // Perform a single DMA burst transfer.
  void perform_action () throw ();

  // Perform a single read burst on the given channel.
  host_int_2 perform_read_burst (int channel_num);

  // Choose the channel with highest priority.
  void prioritize_channels ();

  // Perform a single write burst from the current write buffer.
  host_int_2 perform_write_burst (int &channel_num);

  // Read/write from downstream
  template<typename DataType>
  bus::status read_downstream (bus *from_bus, big_int_4 address, DataType &buf);
  template<typename DataType>
  bus::status write_downstream (bus *to_bus, big_int_4 address, DataType buf);

  // The address may need to be adjusted, depending on the bus.
  big_int_4 adjust_address (bus* bus, big_int_4 address);

  // Obtain the channel scheduled for a read burst, if any.
  int read_burst_channel (bool consider_all = false);

  // Return true if a read burst is pending
  bool read_burst_pending () { return read_burst_channel (true) >= 0; }

  // Determine whether a write burst is pending.
  bool write_burst_pending ();

  // Check whether the pending read on this channel is from the same bus
  // as the pending write.
  bool read_write_conflict (int channel_num);

  // Check internal state after a write burst.
  void check_end_burst (int channel_num);

  // Handle a bus error on read or write.
  bool handle_bus_error (sid::bus::status s);
  void signal_bus_error ();

  // Locking of the downstream interface
  void lock_downstream (bus * b);
  void unlock_downstream (bus* b);
  sidutil::binary_output_pin gbif_lock_pin;
  sidutil::binary_output_pin lbif_lock_pin;

  host_int_2 arbitration_latency (int channel_num);

  // This class must be a friend of scheduler_event_subscription<T>.
  friend class scheduler_event_subscription<mep_dmac>;

  virtual void configure (const string &config);
};

// This class represents one control channel of the DMA controller.
//
class mep_dmac_channel
{
 public:
  mep_dmac_channel (mep_dmac &o, control_register_bus<big_int_4> &b,
		    sidutil::output_pin &op, sidutil::input_pin &ip);

  // Initialize for a transfer.
  bool init_transfer (host_int_2 &latency);

  // Make sure that the current configuration represents a valid transfer
  // request.
  bool check_validity ();

  // Start the DMA transfer.
  bool begin_transfer () throw ();

  // Indicate the end of a transfer.
  void transfer_complete ();

  // Update state after a burst.
  void update_after_read_burst (int burst);
  void update_after_write_burst (int burst);

  // Return true if a DMA request is pending on this channel.
  bool request_pending () { return car_act && trc_trc && ! read_completed; }

  // Return true if this channel is available to be scheduled.
  bool ready () { return (! ccr_htrq || hw_req_pin.sense ()); }

  // Access to control registers fields.
  unsigned  get_car_act  () { return car_act; }
  unsigned  get_ccr_htrq () { return ccr_htrq; }
  unsigned  get_ccr_bl   () { return ccr_bl; }
  unsigned  get_ccr_dcm  () { return ccr_dcm; }
  unsigned  get_ccr_nie  () { return ccr_nie; }
  unsigned  get_tcm_did  () { return tcm_did; }
  unsigned  get_tcm_tt   () { return tcm_tt; }
  big_int_4 get_src_sa   () { return src_sa; }
  big_int_4 get_dst_da   () { return dst_da; }
  big_int_4 get_trc_trc  () { return trc_trc; }
  big_int_4 get_lwr_lw   () { return lwr_lw; }
  unsigned  get_lsr_dls  () { return lsr_dls; }
  unsigned  get_lsr_sls  () { return lsr_sls; }
  big_int_4 get_dta_dta  () { return dta_dta; }
  big_int_4 get_dts_dts  () { return dts_dts; }
  unsigned  get_dsr_nc   () { return dsr_nc; }

  void set_car_act  (unsigned act);
  void set_ccr_htrq (unsigned htrq) { ccr_htrq = htrq; }
  void set_ccr_bl   (unsigned bl)   { ccr_bl = bl; }
  void set_ccr_dcm  (unsigned dcm)  { ccr_dcm = dcm; }
  void set_ccr_nie  (unsigned nie)  { ccr_nie = nie; }
  void set_tcm_did  (unsigned did)  { tcm_did = did; }
  void set_tcm_tt   (unsigned tt)   { tcm_tt = tt; }
  void set_src_sa   (big_int_4 sa)  { src_sa = sa & ~(owner.data_width () - 1); }
  void set_dst_da   (big_int_4 da)  { dst_da = da & ~(owner.data_width () - 1); }
  void set_trc_trc  (big_int_4 trc) { trc_trc = trc & ~(owner.data_width () - 1); }
  void set_lwr_lw   (big_int_4 lw)  { lwr_lw = lw & ~(owner.data_width () - 1); }
  void set_lsr_dls  (unsigned dls)  { lsr_dls = dls & ~(owner.data_width () - 1); }
  void set_lsr_sls  (unsigned sls)  { lsr_sls = sls & ~(owner.data_width () - 1); }
  void set_dta_dta  (big_int_4 dta) { dta_dta = dta & ~(owner.data_width () - 1); }
  void set_dts_dts  (big_int_4 dts) { dts_dts = dts; }
  void set_dsr_nc   (unsigned nc);

  // Access to intermediate state
  big_int_4 get_current_src_sa () { return current_src_sa; }
  big_int_4 get_current_dst_da () { return current_dst_da; }

  // Access to control registers as a whole.
  big_int_4 get_car () { return car_act; }
  big_int_4 get_ccr ();
  big_int_4 get_tcm ();
  big_int_4 get_src () { return src_sa; }
  big_int_4 get_dst () { return dst_da; }
  big_int_4 get_trc () { return trc_trc; }
  big_int_4 get_lwr () { return lwr_lw; }
  big_int_4 get_lsr ();
  big_int_4 get_dta () { return 0x00200000 | dta_dta; }
  big_int_4 get_dts () { return dts_dts; }
  big_int_4 get_dsr () { return dsr_nc; }

  void set_car  (big_int_4 val, big_int_4 unused) { set_car_act  ( val        & 0x1); }
  void set_ccr  (big_int_4 val, big_int_4 unused) { set_ccr_htrq ((val >> 12) & 0x1);
                                                    set_ccr_bl   ((val >> 8)  & 0x3);
                                                    set_ccr_dcm  ((val >> 4)  & 0x1);
                                                    set_ccr_nie  ( val        & 0x1); }
  void set_tcm  (big_int_4 val, big_int_4 unused) { set_tcm_did  ((val >> 24) & 0xff);
                                                    set_tcm_tt   ( val        & 0x7); }
  void set_src  (big_int_4 val, big_int_4 unused) { set_src_sa   ( val); }
  void set_dst  (big_int_4 val, big_int_4 unused) { set_dst_da   ( val); }
  void set_trc  (big_int_4 val, big_int_4 unused) { set_trc_trc  ( val        & 0xfffff); }
  void set_lwr  (big_int_4 val, big_int_4 unused) { set_lwr_lw   ( val        & 0xffff); }
  void set_lsr  (big_int_4 val, big_int_4 unused) { set_lsr_dls  ((val >> 16) & 0xffff);
                                                    set_lsr_sls  ( val        & 0xffff); }
  void set_dta  (big_int_4 val, big_int_4 unused) { set_dta_dta  ( val        & 0xfffff); }
  void set_dts  (big_int_4 val, big_int_4 unused) { set_dts_dts  ( val        & 0xff); }
  void set_dsr  (big_int_4 val, big_int_4 unused) { set_dsr_nc   ( val        & 0x1); }

  // Information on the type of transfer.
  bool source_address_fixed () { return tcm_tt == 0x4; }
  bool dest_address_fixed ()   { return tcm_tt == 0x5; }

  // State of current line (for rectangular transfers).
  big_int_4 get_source_line_remain () const { return source_line_remain; }
  big_int_4 get_dest_line_remain () const { return dest_line_remain; }

  // Return the burst size in units of bus-width
  int burst_size () { return 4 << ccr_bl; }

  // Adjust the burst size for alignment and data size limits.
  int limit_read_burst (bool bus_is_main, big_int_4 address,
			big_int_4 length, int burst);
  int limit_write_burst (bool bus_is_main, big_int_4 address,
			 big_int_4 length, int burst);

 private:
  // The owning DMAC
  mep_dmac &owner;

  // The interrupt output pin
  sidutil::output_pin &interrupt_pin;

  // The hw_req input pin
  sidutil::input_pin &hw_req_pin;

  // Control registers for this channel.
  control_register_bus<big_int_4> &control_bus;
  
  // CAR (Channel Active Register)
  unsigned car_act;
  callback_control_register<big_int_4,mep_dmac_channel> car;
  // CCR (Channel Control Register)
  unsigned ccr_htrq;
  unsigned ccr_bl;
  unsigned ccr_dcm;
  unsigned ccr_nie;
  callback_control_register<big_int_4,mep_dmac_channel> ccr;
  // TCM (Transfer Command Register)
  unsigned tcm_did;
  unsigned tcm_tt;
  callback_control_register<big_int_4,mep_dmac_channel> tcm;
  // SRC (Source Address Register)
  big_int_4 src_sa;
  callback_control_register<big_int_4,mep_dmac_channel> src;
  // DST (Destination Address Register)
  big_int_4 dst_da;
  callback_control_register<big_int_4,mep_dmac_channel> dst;
  // TRC (Transfer Count Register)
  big_int_4 trc_trc;
  callback_control_register<big_int_4,mep_dmac_channel> trc;
  // LWR (Line Width Register)
  big_int_4 lwr_lw;
  callback_control_register<big_int_4,mep_dmac_channel> lwr;
  // LSR (Line Step Register)
  unsigned lsr_dls;
  unsigned lsr_sls;
  callback_control_register<big_int_4,mep_dmac_channel> lsr;
  // DTA (Descriptor Table Address Register)
  big_int_4 dta_dta;
  callback_control_register<big_int_4,mep_dmac_channel> dta;
  // DTS (Descriptor Table Size Register)
  big_int_4 dts_dts;
  callback_control_register<big_int_4,mep_dmac_channel> dts;
  // DSR (DMA Status Register)
  unsigned dsr_nc;
  callback_control_register<big_int_4,mep_dmac_channel> dsr;

  // Intermediate state
  big_int_4 current_src_sa;
  big_int_4 current_dst_da;
  bool read_completed;

  // Remaining space left on source and dest lines for rectangular transfers
  big_int_4 source_line_start;
  big_int_4 source_line_remain;
  big_int_4 dest_line_start;
  big_int_4 dest_line_remain;

  // Initialize for transfer.
  bool init_chain (host_int_2 &total_latency);
  void init_source_line ();
  void init_dest_line ();

  int limit_burst (bool bus_is_main, big_int_4 address,
		   big_int_4 length, big_int_4 line_remain, int burst);

  bool is_rectangular () { return tcm_tt >= 1 && tcm_tt <= 3; }
  bool source_rectangular () { return tcm_tt >= 2 && tcm_tt <= 3; }
  bool dest_rectangular () { return tcm_tt == 1 || tcm_tt == 3; }
};

// This class represents one control channel of the DMA controller.
//
class mep_dmac_buffer
{
public:
  mep_dmac_buffer () :
    _channel_num (-1),
    _burst_size (0),
    _data_end_ix (0),
    _data_ix (0)
  {}

  void initialize (int c, int bs)
    {
      _channel_num = c;
      _burst_size = bs;
      _data_end_ix = 0;
      _data_ix = 0;
    }

  int burst_size () const { return _burst_size; }
  int data_size () const { return _data_end_ix - _data_ix; }
  int channel_num () const { return _channel_num; }

  template<typename DataType>
  void add_bytes (DataType data);
  big_int_4 flush_4_bytes ();
  big_int_8 flush_8_bytes ();

  bool write_pending () const { return _data_end_ix > _data_ix; }

  static const int buffer_size = 64;

private:
  int _channel_num;
  int _burst_size;
  int _data_end_ix;
  int _data_ix;
  char _data[buffer_size];
};

#endif // MEP_DMAC_H
