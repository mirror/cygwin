// rtc-driver.h - description.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef RTC_DRIVER_DEFH
#define RTC_DRIVER_DEFH

#include <time.h>
#include <string>

class rtc_driver 
{
private:
  volatile unsigned char* const CONTROL_ADD;
  volatile unsigned char* const SECONDS_ADD;
  volatile unsigned char* const MINUTES_ADD;
  volatile unsigned char* const HOUR_ADD;
  volatile unsigned char* const DAY_ADD;
  volatile unsigned char* const DATE_ADD;
  volatile unsigned char* const MONTH_ADD;
  volatile unsigned char* const YEAR_ADD;
  
public:
  rtc_driver();
  
  void read_year(unsigned char& year);
  void read_month(unsigned char& month);
  void read_date (unsigned char& date);
  void read_day (unsigned char& day);
  void read_hour (unsigned char& hour);
  void read_minutes (unsigned char& mins);
  void read_seconds (unsigned char& secs);
  void read_century (unsigned char& century);
  
  void set_year (unsigned char year);
  void set_month (unsigned char month);
  void set_date (unsigned char date);
  void set_day (unsigned char day);
  void set_hour (unsigned char hour); 
  void set_minutes (unsigned char mins);
  void set_seconds (unsigned char secs);
  void set_century (unsigned char century);
  
  void clear_writemode();
  void clear_readmode();
  
  void set_writemode();
  void set_readmode();
  
  void stop_oscillator();
  void start_oscillator();
  
  void set_frequencytest();
  void clear_frequencytest();
  
private:
  unsigned char bcd_to_bin(unsigned char bcd);
  unsigned char bin_to_bcd(unsigned char bin);	   
};

#endif // RTC_DRIVER_DEFH
