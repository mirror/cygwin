// rtc-driver.cxx - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include <iostream>
#include "rtc-driver.h"
#include "mem-map.h"
#include <assert.h>

rtc_driver::rtc_driver()
  :CONTROL_ADD (RTC_BASE + 0), SECONDS_ADD (RTC_BASE + 1),
   MINUTES_ADD (RTC_BASE + 2), HOUR_ADD (RTC_BASE + 3),
   DAY_ADD (RTC_BASE + 4),     DATE_ADD (RTC_BASE + 5),
   MONTH_ADD (RTC_BASE + 6),   YEAR_ADD (RTC_BASE + 7)
{ }   

// Courtesy of BJE 
unsigned char
rtc_driver::bcd_to_bin(unsigned char bcd)
{
  return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

// Courtesy of BJE
unsigned char
rtc_driver::bin_to_bcd(unsigned char bin)
{
  assert(bin < 100);

  unsigned tens = bin / 10;
  unsigned ones = bin % 10;

  return ((tens << 4) | ones);
}

void
rtc_driver::read_year ( unsigned char& year) 
 {
   unsigned char year_val;
   year_val = *YEAR_ADD;
   year = bcd_to_bin (year_val); // year_val in bcd format.
 }

void
rtc_driver::read_month ( unsigned char& month) 
 {
   unsigned char month_val;
   month_val = *MONTH_ADD;
   month_val &= 0x1F;
   month = bcd_to_bin (month_val);
 }

void
rtc_driver::read_date ( unsigned char& date ) 
 {
   unsigned char date_val;
   date_val = *DATE_ADD;
   date_val &= 0x3F;
   date = bcd_to_bin (date_val);
 }

void
rtc_driver::read_day ( unsigned char& day ) 
 {
   unsigned char day_val;
   day_val = *DAY_ADD;
   // day val in bcd
   day_val &= 0x07;
   day = bcd_to_bin (day_val);
 }

void
rtc_driver::read_hour ( unsigned char& hour) 
 {
   unsigned char hour_val;
   hour_val = *HOUR_ADD;
   hour_val &= 0x3F;
   hour = bcd_to_bin ( hour_val);
 }

void
rtc_driver::read_minutes (unsigned char& mins)
 { 
   unsigned char min_val;
   min_val = *MINUTES_ADD;
   min_val &= 0x7F;
   mins = bcd_to_bin ( min_val);
 }      

void
rtc_driver::read_seconds (unsigned char& secs) 
 {
   unsigned char sec_val;
   sec_val = *SECONDS_ADD;
   sec_val &= 0x7F;
   secs = bcd_to_bin (sec_val);
 }

void 
rtc_driver::read_century (unsigned char& century) 
 {
   unsigned char cen_val;
   cen_val = *CONTROL_ADD;
   cen_val &= 0x3F;
   century = bcd_to_bin (cen_val);
 }

void
rtc_driver::set_year (unsigned char year) 
 {
   unsigned char year_val;
   year_val = bin_to_bcd (year); 
   *YEAR_ADD =  year_val;
 }
 
void
rtc_driver::set_month (unsigned char month) 
 {
   unsigned char month_val;
   month_val =  bin_to_bcd (month);
  //  month_val &= 0x1F;   
   *MONTH_ADD =  month_val;
 }
         
void 
rtc_driver::set_date (unsigned char date) 
 {
   unsigned char date_val;
   date_val = bin_to_bcd (date);
   // date_val &= 0x3F;
   *DATE_ADD = date_val;
 }

void 
rtc_driver::set_day (unsigned char day) 
 {
   unsigned char day_val, curr_dayreg;
   day_val = bin_to_bcd (day);
   //day_val &= 0x07;
   curr_dayreg = *DAY_ADD;
   curr_dayreg &= 0xC0; // keep BT & FT same as before
   day_val |= curr_dayreg;
   *DAY_ADD = day_val;
 }  

void
rtc_driver::set_hour (unsigned char hour) 
 {
   unsigned char hour_val;
   hour_val  = bin_to_bcd ( hour );
   *HOUR_ADD = hour_val;
 }

void
rtc_driver::set_minutes (unsigned char mins) 
 {
   unsigned char mins_val;
   mins_val = bin_to_bcd ( mins );
   *MINUTES_ADD = mins_val;
 }

void 
rtc_driver::set_seconds (unsigned char secs) 
 {
   unsigned char secs_val, curr_secreg;
   secs_val = bin_to_bcd ( secs );
   curr_secreg = *SECONDS_ADD;
   curr_secreg &= 0x80; // value of oscilator
   secs_val |= curr_secreg;
   *SECONDS_ADD = secs_val;
 }

void
rtc_driver::set_century (unsigned char century) 
 {
   unsigned char cent_val, curr_centreg;
   cent_val = bin_to_bcd ( century );
   //   curr_centreg = *CONTROL_ADD;
   curr_centreg = 0x80;
   cent_val |= curr_centreg;
   *CONTROL_ADD = cent_val;
 }

void
rtc_driver::clear_writemode () 
 {
   unsigned char mask_val = 0x7F;
   unsigned char curr_regval = 0;
   curr_regval  = *CONTROL_ADD;
   curr_regval &= mask_val;
   *CONTROL_ADD = curr_regval;
 }

void
rtc_driver::clear_readmode ()
 {
   unsigned char mask_val = 0xBF;
   unsigned char curr_regval = 0;
   curr_regval = *CONTROL_ADD;
   curr_regval &= mask_val;
   *CONTROL_ADD = curr_regval;
 }

void
rtc_driver::set_writemode () 
 {
   unsigned char mask_val = 0x3F;
   unsigned char curr_regval = 0;
   curr_regval = *CONTROL_ADD;
   curr_regval &= mask_val;
   curr_regval |= 0x80; // Enable write bit
   *CONTROL_ADD = curr_regval;
 }

void
rtc_driver::set_readmode () 
 {
   unsigned char mask_val = 0x3F;
   unsigned char curr_regval = 0;
   curr_regval = *CONTROL_ADD;
   curr_regval &= mask_val;
   curr_regval |= 0x40; // Enable read bit.
   *CONTROL_ADD = curr_regval; 
 }

void
rtc_driver::stop_oscillator ()
 {
   unsigned char curr_regval;
   curr_regval = *SECONDS_ADD;
   curr_regval |= 0x80; // osci stopped. bit # 7 is set.
   *SECONDS_ADD = curr_regval;
 }

void
rtc_driver::start_oscillator () 
 {
   unsigned char mask_data = 0x7F;
   unsigned char curr_regval;
   curr_regval = *SECONDS_ADD;
   curr_regval &= mask_data; // bit # 7 is cleared
   *SECONDS_ADD = curr_regval;
 }

void
rtc_driver::set_frequencytest() 
 {
   unsigned char curr_regval;
   curr_regval = *DAY_ADD;
   curr_regval |= 0x40; // FT bit is set
   *DAY_ADD = curr_regval;
 }

void
rtc_driver::clear_frequencytest() 
 {
   unsigned char curr_regval;
   curr_regval = *DAY_ADD;
   curr_regval &= 0xBF; // FT bit is cleared
   *DAY_ADD =  curr_regval;
 }



/*       
bool set_cent_year ( int cent_year) {
  // cent_years represents years after 1900
  unsigned char century_val = 0;
  unsigned char year_val   = 0;

  century_val = 19 + (cent_year / 100); // century value
  year_val = cent_year % 100; // year value
  if ( (set_year(year_val)) && (set_century(century_val)) )
     return true;
  else
    {
      cerr << " Cannot set year & century \n";
      return false;
    }
}

bool initialize_rtc (time_t res_time) {
  struct tm *curr_time;

  if ( ! set_writemode () ) 
    {
      cerr << " Write mode setting failed \n";
      return false;
    }

  curr_time = localtime(&res_time);
  set_cent_year (curr_time -> tm_year);
  set_month ((curr_time -> tm_mon) + 1);
  set_date (curr_time -> tm_mday);
  set_day  ((curr_time -> tm_wday) + 1);
  set_hour (curr_time -> tm_hour);
  set_minutes ( curr_time -> tm_min);
  set_seconds ( ((curr_time -> tm_sec) > 59) ? 59:(curr_time ->tm_sec) );

  clear_writemode ();
  return true;
}

std::string get_day (unsigned int day_val)
{
  switch (day_val) {
  case 1:
         return "Sun";
  case 2: 
         return "Mon";
  case 3:
	 return "Tue";
  case 4: 
	 return "Wed";
  case 5:
	 return "Thu";
  case 6:
	 return "Fri";
  case 7: 
	 return "Sat";
  default:
    cerr << " day val is out of range \n";
    return "";
  }
}

string get_rtctime ()
{
 unsigned char yy, mm, dt, hh, min;

  set_readmode ();

  read_year(yy);
  read_month(mm);
  read_date(dt);
  read_hour(hh);
  read_minutes(min);

  clear_readmode();
  
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
  string hey (s);	// convert from char* to string
  return hey;
}
*/
