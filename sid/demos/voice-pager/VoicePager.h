// VoicePager.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef VOICE_PAGER_H
#define VOICE_PAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <time.h>

#include "page-lcd.h"
#include "rtc-driver.h"
#include "parport-driver.h"
#include "adac-driver.h"

using std::map;
using std::vector;

class VoicePager
{
 private:
  parport_driver pport_drobj;   // Object of type parallel port driver
  rtc_driver rtc_drobj;		// object of type rtc driver.

  vector<unsigned char> id_arr; // vector of unique identity numbers
  vector<string> rnd_telnum;	// telephone Numbers

  int record_process;		// bool variable whether recording in process?
  int play_process;		// any message is currently being played?
  unsigned char last_cmd;	// Stores last command.
  unsigned char inuse_idnum;    // Current id which is being played /record

  unsigned char rec_seccounter; // sec at which recording will be disconnected.
  unsigned char rec_curtime; // stores last second value read from RTC


 protected:
  PagerUI *lcdpager_ptr;        // Pointer to lcd pager object
  lcd_driver lcd_drobj;		// object of type lcd driver

 public:
  VoicePager();
  virtual ~VoicePager();

  void initialize_components(); // Initializes RTC, LCD, Parallel port
  void poll_input(); // Polls parallel port for input data

 protected:
  void show_lcdmsg (string lcd_msg, unsigned lcd_rownum);
  void clear_lcddisplay ();

 private:
  enum {
    CMD_UP   = 1,  // UP key code
    CMD_DN   = 2,  // DOWN key code
    CMD_REC  = 4,  // REC key  code
    CMD_PLAY = 8,  // PLAY key code
    CMD_DEL  = 16, // DEL key code
    CMD_DONE = 32, // DONE key code
    CMD_STOP = 64, // STOP key code
    CMD_CLR  = 0   // No key is depressed
  };

  enum {
    TIME_LIMIT = 8, // Our hard limit on max record time
    MAX_SEC = 59  // Max seconds value from RTC
  };

 private:
  void init_idvector(); // Initializes the unique id vector
  void init_rndtelnum();  // Initializes vector of random tel nums
  void initialize_rtc(time_t init_time); // Initializes RTc component
  void initialize_lcd(); // Initializes LCD component

  void scroll_up();    // Up key is pressed
  void scroll_down();  // Down key is pressed
  void record_newmsg(); // Record new message
  void play_storedmsg();  // Sends data to sound object for play
  bool play_done(); // Checking to see if non blocking play is done
  void delete_storedmsg(); // To delet stored message
  void delete_msg(unsigned char del_msgid); // Helper function to delete msg
  void stop_recmsg(); // Stop play/record sound

  void set_hardrectime(); // Sets hard time limit for current recording
  void clear_hardrectime();// Clears hard time as recording is over.
  bool increase_reccounter(unsigned char incr_secs);// increases record time limit counter
  bool crossed_reclimit(); // Did we cross the record limit ?
  
  string get_rndtelnum(); // Returns Random Telephone number
  string get_rtctime(); // Returns Current RTC value 

  void read_rtcseconds(unsigned char& sec_val); // Helper function 
  void display_msg (string temp_msg); // Helper function to display msgs.

 private:
   map<unsigned char, string> rec_msgs;  // Recorded messages 
   adac_driver adac_drobj; // Object of type adac driver.
  
 protected:
   void send_dacdata (unsigned char play_id);
   void remove_storedmsg (unsigned char del_id);
   void get_adcdata (unsigned char rec_id);
   void stop_playmsg (unsigned char play_id);
};

#endif // VOICE_PAGER_H
