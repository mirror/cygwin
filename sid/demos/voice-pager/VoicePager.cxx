// VoicePager.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2002 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

// This is the main controller will send msgs to rtc, lcd, and snack.
// Gets input from  parallel port and also has look up table.

#include "VoicePager.h"

static const int TIME_DIFFHRS = 7;	// CA time(-3) and no light sav. (-4)

static const int MAX_IDNUM = 20;	// max num of messages to be stored
static const int MAX_RNDTELNUM = 12;	// max num of random telphone numbers.

VoicePager::VoicePager()
{
  lcdpager_ptr = new PagerUI(lcd_drobj);
  record_process = play_process = 0;
  last_cmd = inuse_idnum = 0;
  init_idvector();
  init_rndtelnum();

  for (unsigned char k = 1; k <= MAX_IDNUM; ++k)
    rec_msgs[k] = string ();
}

VoicePager::~VoicePager()
{
  delete lcdpager_ptr;
}

void 
VoicePager::initialize_components()
{
  initialize_lcd();

  pport_drobj.set_ctl(0xF0); // keeping bits 4 & 5 1

  time_t time_val = time(NULL);
  // time_val -= (TIME_DIFFHRS * 60 * 60); 
  initialize_rtc(time_val);
}

void
VoicePager::init_idvector()
{ 
  // Store 1-20 id numbers for snack.
  for (unsigned char i = 1; i <= MAX_IDNUM; ++i)
    id_arr.push_back (i);  
} 

void
VoicePager::poll_input()
{
  unsigned char curr_cmd = CMD_CLR; // no key depressed

  for ( ; ; )
    {
      //     curr_cmd = pport_drobj.read_parport_data(); 
      // read parallel port PR register
      curr_cmd = pport_drobj.get_prreg();
     	  
      if (last_cmd != curr_cmd) 
	{
	  last_cmd = curr_cmd;
	  switch (curr_cmd) {
	  case CMD_UP: 
	    // up button 
	    scroll_up();
	    break;

	  case CMD_DN:
	    // down button
	    scroll_down();
	    break;

	  case CMD_REC:
	    // Record_pin
	    if (!record_process) 
	      {		// no recording currently in process
		if (!play_process)
		  {	// no play currently in process
		    record_newmsg();
		  }
		else
		  {  // Non Blocking play in process. Lets check
		    if (! play_done() )
		      display_msg ("Currently Play in Process");
		    else 
		      record_newmsg(); // Recording message
		  }
	      }
	    else
	      {
	        display_msg ("Prev. Recording in Process");
	      }
	    break;

	  case CMD_PLAY:
	    // Play Pin 
	    if  (! play_process)
	      {		// Not Playing any message
		if (! record_process)
		  {	// Not Recoding any message
		    play_storedmsg();
		  }
		else 
		  display_msg ("Recording in Process");
	      }
	    else 
	      {
		if ( !play_done() )
		  display_msg ("Play in Process");
		else
		  play_storedmsg();
	      }
	    break;

	  case CMD_DEL:
	    // Delete Pin
	    delete_storedmsg ();
	    break;

	  case CMD_DONE:
	    // Done Pin - exit program!
	    return;

	  case CMD_STOP:
	    // Stop Pin
	    stop_recmsg ();
	    break;

	  case CMD_CLR:
	    break;

	  default:
	    std::cerr << " current value of command is  "	<< curr_cmd << std::endl;
	    break;
	  }
	}

      if (record_process)
	adac_drobj.poll_read ();
      if (play_process)
	adac_drobj.poll_write ();

      if (record_process && crossed_reclimit())
	stop_recmsg();
    }
}

void
VoicePager::scroll_up()
{
  lcdpager_ptr -> up();
  lcdpager_ptr -> draw_screen();
}

void
VoicePager::scroll_down()
{
  lcdpager_ptr -> down();
  lcdpager_ptr -> draw_screen();
}

void 
VoicePager::record_newmsg()
{
  if (id_arr.size())
    {
      // if size is > 0. New messages can be stored
      unsigned char avail_id = id_arr[ id_arr.size() - 1 ];
      id_arr.pop_back();

      string curr_msgtime = get_rtctime(); 
      string caller_num = get_rndtelnum();
      string blank_str = " ";
      string curr_fullmsg = curr_msgtime + blank_str;
      curr_fullmsg = curr_fullmsg + caller_num;

      record_process = 1; // record in process

      display_msg ("Recording...");

      adac_drobj.begin_read ();

      set_hardrectime(); // set time for max record time
      inuse_idnum = avail_id; // id number currently in use.
      lcdpager_ptr -> append(avail_id, curr_fullmsg); // update lcd
      lcdpager_ptr -> draw_screen();
    }
  else {
    display_msg ("Maximum 20 messages");
  }

}

void
VoicePager::play_storedmsg()
{
  unsigned char play_id = lcdpager_ptr -> current_id();
  if ( play_id != 0 )
    {
      send_dacdata(play_id); // send data from target to sound component
      play_process = 1;
      inuse_idnum = play_id;
      // play_snd (play_id); // play sound use send_dacdata

      display_msg ("Playing back...");
    }
  else 
    display_msg ("No message to play"); 
}

void
VoicePager::delete_storedmsg()
{
  unsigned char del_msgid = lcdpager_ptr -> current_id();
  if (del_msgid != 0)
    {
      if (del_msgid != inuse_idnum)
	{
	  delete_msg(del_msgid);
	}
      else
	{
          if (record_process)
            display_msg ("Message in record process");
          else
	    { 
	      if (!play_done() )
		display_msg ("Message in play process");
	      else 
		delete_msg(del_msgid);
	    }
	}
    }
  else if (del_msgid == 0) display_msg ("No message to Delete");
}

void
VoicePager::stop_recmsg()
{
  if ( inuse_idnum > 0)
    {
      //      stop_snd (inuse_idnum);
      if ((record_process) && (play_process))
        std::cerr << " ERROR record & play both in process?" << std::endl;

      else 
	{
          if (record_process)
	    {
	      get_adcdata (inuse_idnum); // also call stop snd 
	      clear_hardrectime();
	      lcdpager_ptr -> draw_screen(); // RON brought this
	    }

	  else if (play_process)
	    stop_playmsg(inuse_idnum); 
	 
	  inuse_idnum    = 0;
	  record_process = 0;
	  play_process   = 0;
	}
    }
  else
    {
      display_msg ("No message to Stop");
    }
}

string
VoicePager::get_rndtelnum()
{
  int temp_rndnum = rand();
  temp_rndnum %= MAX_RNDTELNUM;
  return rnd_telnum[temp_rndnum];
}   


void
VoicePager::init_rndtelnum()
{
  rnd_telnum.push_back("416-482-6299");
  rnd_telnum.push_back("770-594-3180");
  rnd_telnum.push_back("408-542-9604");
  rnd_telnum.push_back("408-542-9600");
  rnd_telnum.push_back("416-482-2813");
  rnd_telnum.push_back("780-434-4261");
  rnd_telnum.push_back("770-649-0922");
  rnd_telnum.push_back("800-668-0917");
  rnd_telnum.push_back("800-269-8463");
  rnd_telnum.push_back("800-284-6781");
  rnd_telnum.push_back("408-542-9601");
  rnd_telnum.push_back("416-743-7625");
  rnd_telnum.push_back("780-492-7452");
}


void
VoicePager::display_msg(string temp_msg)
{
  unsigned NCOLS = lcd_drobj.get_numcols();

  clear_lcddisplay();  
  //  string sorry_msg = "Sorry...";

  // show_lcdmsg (sorry_msg, 1*NCOLS);
  show_lcdmsg (temp_msg,  2*NCOLS);

  // wait for one second
  unsigned char waitstart, now;
  read_rtcseconds(waitstart);
  read_rtcseconds(now);
  while (now == waitstart)
    {
      for (unsigned long j = 0; j < 10000; ++j) ;
      read_rtcseconds(now);
    }

  lcdpager_ptr -> draw_screen(); // Back to origiunal screen.
}

void
VoicePager::clear_lcddisplay ()
{
  unsigned NCOLS = lcd_drobj.get_numcols();
  unsigned NROWS = lcd_drobj.get_numrows();

  lcd_drobj.mem_set (0, 0, NROWS*NCOLS);
}

void
VoicePager::show_lcdmsg (string lcd_msg, unsigned lcd_rowcolval)
{
   
  lcd_drobj.set_word_reg( lcd_driver::SET_ADP, lcd_rowcolval, 0 );  
  lcd_drobj.send_cmd( lcd_driver::SET_AWRITE);
  for ( unsigned j=0; j < lcd_msg.size(); j++)
    lcd_drobj.auto_write ( lcd_msg[j] - ' ');
  lcd_drobj.reset_auto( 8 );
}

 
bool
VoicePager::play_done()
{
  if (adac_drobj.count_pending_write() == 0)
    {
      play_process = 0;
      inuse_idnum = 0;
      return true;
    }
  else
    {
      return false;
    }
}


void
VoicePager::delete_msg(unsigned char del_msgid)
{
  remove_storedmsg (del_msgid);
  lcdpager_ptr -> delete_selected ();
  lcdpager_ptr -> draw_screen ();
  id_arr.push_back (del_msgid);
}


void
VoicePager::set_hardrectime()
{
  read_rtcseconds(rec_curtime);
  rec_seccounter = 0;
}        	

void
VoicePager::clear_hardrectime()
{
  rec_seccounter = 0;
}

bool
VoicePager::crossed_reclimit()
{
  unsigned char curr_seconds;
  read_rtcseconds(curr_seconds); // Reading from RTC
 
  if ( curr_seconds != rec_curtime)
    {
      unsigned char diff_secs = 0;

      if ( curr_seconds > rec_curtime)
	{
	  diff_secs = (curr_seconds - rec_curtime); 
	  rec_curtime += diff_secs;
	}

      else if ( curr_seconds < rec_curtime) 
	{
	  diff_secs = (curr_seconds + 1 + 59) - rec_curtime;
	  rec_curtime += diff_secs - 59 - 1;
	  /*   if ( rec_curtime < 0)
	       {
               std::cerr << " ERROR rec time < 0 " << std::endl;
	       rec_time = 0;
	       }*/
	}
      return (increase_reccounter(diff_secs));
    }
  else
    return false;
}

bool
VoicePager::increase_reccounter(unsigned char incr_secs)
{
  if (incr_secs > 0)
    {
      rec_seccounter+=incr_secs ;
      return ( (rec_seccounter > TIME_LIMIT)? true : false) ;
    }
  else 
    {
      std::cerr << " ERROR increment time is < 0" << std::endl;
      return true; // lets disconnect this recording 
    }
}

void
VoicePager::initialize_rtc (time_t init_time)
{
  struct tm* curr_time;

  rtc_drobj.set_writemode();
  curr_time = localtime(&init_time);
 
  rtc_drobj.set_century ((1900 + curr_time -> tm_year) / 100);
  rtc_drobj.set_year ((1900 + curr_time -> tm_year) % 100);
  rtc_drobj.set_month ((curr_time -> tm_mon) + 1);
  rtc_drobj.set_date (curr_time -> tm_mday);
  rtc_drobj.set_day  ((curr_time -> tm_wday) + 1);
  rtc_drobj.set_hour (curr_time -> tm_hour);
  rtc_drobj.set_minutes ( curr_time -> tm_min);
  rtc_drobj.set_seconds ( ((curr_time -> tm_sec) > 59) ? 59:(curr_time ->tm_sec) );

  rtc_drobj.clear_writemode ();
}       


string
VoicePager::get_rtctime ()
{
  unsigned char yy, mm, dt, hh, min;

  rtc_drobj.set_readmode ();

  rtc_drobj.read_year(yy);
  rtc_drobj.read_month(mm);
  rtc_drobj.read_date(dt);
  rtc_drobj.read_hour(hh);
  rtc_drobj.read_minutes(min);

  rtc_drobj.clear_readmode();
  
  unsigned int y_val = yy;
  unsigned int mon_val = mm;
  unsigned int dt_val = dt;
  unsigned int h_val = hh;
  unsigned int min_val = min;

  char s[20];
  sprintf (s, "%d", mon_val); // at most 2 chars
  unsigned int len = strlen(s);
  s[len] = '/';
  sprintf (&s[++len], "%d", dt_val);// at most 2 chars
  len = strlen (s); 
  s[len] =  '/';
  sprintf (&s[++len], "%d", y_val);// at most 2 chars
  len = strlen (s); 
  s[len] = ' ';
  if ( h_val < 10)
    {			// if value is one digit put space first
      s[++len] = ' ';
    }   
  sprintf (&s[++len], "%d", h_val);
  len = strlen (s); 
  s[len] = ':';
  sprintf (&s[++len], "%d", min_val);
  if ( min_val < 10)
    {			// if min value is less than 10 put space after
      s[++len] = ' ';
      s[++len] = 0 ;	// null terminate the array
        
    }
  string rtc_time (s);	// convert from char* to string
  return rtc_time;
}   

void 
VoicePager::read_rtcseconds(unsigned char& sec_val)
{
  rtc_drobj.set_readmode(); 
  rtc_drobj.read_seconds (sec_val);
  rtc_drobj.clear_readmode(); 
}

void
VoicePager::initialize_lcd ()
{
  unsigned NCOLS = lcd_drobj.get_numcols();
  unsigned NROWS = lcd_drobj.get_numrows();

  //intialize the display
  lcd_drobj.set_word_reg( lcd_driver::SET_TXT_HOME, 0x00, 0x00 );
  lcd_drobj.set_word_reg( lcd_driver::SET_TXT_AREA, NCOLS, 0 );
  lcd_drobj.set_word_reg( lcd_driver::SET_GRX_HOME, 0x00, 0x02 );
  lcd_drobj.set_word_reg( lcd_driver::SET_GRX_AREA, NCOLS, 0 );

  // mode set: OR mode, internal cgen
  lcd_drobj.send_cmd( 0x80 );			

  // display: text on, graphics off, no cursor
  lcd_drobj.send_cmd( 0x94 );

  lcd_drobj.mem_set( 0, 0, NCOLS*NROWS );		// clear display

  lcd_drobj.set_word_reg( lcd_driver::SET_OFFSET, 2, 0 );
  lcd_drobj.set_word_reg( lcd_driver::SET_ADP, 0, 0x14 );	// cgen area is 0x1400

  lcd_drobj.send_cmd( lcd_driver::SET_AWRITE );

  lcd_drobj.auto_write( 0x8 );	// initialize the arrow
  lcd_drobj.auto_write( 0xc );
  lcd_drobj.auto_write( 0xe );
  lcd_drobj.auto_write( 0xf );
  lcd_drobj.auto_write( 0xe );
  lcd_drobj.auto_write( 0xc );
  lcd_drobj.auto_write( 0x8 );
  lcd_drobj.auto_write( 0x0 );

  lcd_drobj.reset_auto( 8 );
}


void
VoicePager::get_adcdata(unsigned char id_num)
{
  string sound = adac_drobj.finish_read ();
  rec_msgs[id_num] = sound;
}


void
VoicePager::send_dacdata(unsigned char id_num)
{
  adac_drobj.begin_write (rec_msgs [id_num]);
}


void
VoicePager::remove_storedmsg (unsigned char del_id)
{
  rec_msgs[del_id] = string();
} 


void
VoicePager::stop_playmsg (unsigned char play_id)
{
  adac_drobj.finish_write ();
}


