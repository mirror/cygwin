// mainDynamic.cxx - One possible mainline.  -*- C++ -*-

// Copyright (C) 1999, 2000 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"

#include <sidcomp.h>
#include <sidso.h>
#include <sidpinutil.h>
#include <sidcomputil.h>

#include <unistd.h>
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif


using namespace std;
using namespace sid;
using namespace sidutil;


// Link to compConfig component directly.
extern component_library /* *not* DLLIMPORT */ config_component_library;


// Stub functions to set breakpoints on
static void sid_pre_configure () {}
static void sid_post_configure () {}
static void sid_pre_run () {}
static void sid_post_run () {}



void
usage ()
{
  cout << "Usage: sid OPTIONS [FILE] ..." << endl;
  cout << "OPTIONS:" << endl;
  cout << "-h        print this help" << endl;
  cout << "-n        load/check configuration but do not run simulation" << endl;
  cout << "-f FILE   also read configuration FILE" << endl;
  cout << "-e LINE   also do configuration LINE" << endl;
  cout << endl;
  cout << "All -f/-e options are performed first, in sequence." << endl;
  cout << "FILE names supplied without -f are done last, in sequence." << endl;
}


// main line
int
main(int argc, char* argv[])
{
  vector< pair<bool,string> > config_items;
  bool dry_run_p = false;
  string config_file;

  if (argc == 1)
    {
      usage();
      return 1;
    }

  while (true)
    {
      int c = getopt (argc, argv, "hne:f:");
      if (c == EOF)
	break;

      switch (c)
	{
	case 'h':
	  usage ();
	  return 0;
	  
	case 'n':
	  dry_run_p = true;
	  break;

	case 'e':
	  config_items.push_back (make_pair (false, string(optarg)));
	  break;

	case 'f':
	  config_items.push_back (make_pair (true, string(optarg)));
	  break;

	default:
	  usage ();
	  return 1;
	}
    }


  // Treat remaining arguments as file names
  for (unsigned j=optind; j<argc; j++)
    {
      config_items.push_back (make_pair (true, string(argv[j])));
    }

  component* main_component = 
    config_component_library.create_component("sid-control-cfgroot");
  if(main_component == 0)
    {
      cerr << "Cannot instantiate configuration root component." << endl;
      return 2;
    }

  sid_pre_configure ();
  // select & load the config file
  bool config_ok = true;


  // NB: There is no problem if config_items is empty.  cfgroot will
  // abort a run if there are no other configured components.

  for (unsigned k=0; k < config_items.size(); k++)
    {
      const pair<bool,string>& item = config_items[k];
      sid::component::status s;

      if (item.first == true)
	s = main_component->set_attribute_value ("config-file!", item.second);
      else
	s = main_component->set_attribute_value ("config-line!", item.second);

      if(s != sid::component::ok)
	config_ok = false;
    }

  if (! config_ok)
    {
      cerr << "Configuration error.  Aborting." << endl;
      return 3;
    }

  sid_post_configure ();


  if (! dry_run_p)
    {
      // drive the root's "run" pin.
      sid_pre_run ();
      sid::pin* run_pin = main_component->find_pin ("run!");
      if (! run_pin)
	{
	  cerr << "Cannot find root run pin." << endl;
	  return 4;
	}
      
      // run the simulation
      run_pin->driven (0);
      // the simulation has ended.
      sid_post_run ();
    }

  // delete cfgroot and the rest of the world
  config_component_library.delete_component (main_component);
}


#ifndef SID_STATIC
// Define a stub lt_preloaded_symbols[], as if libtool's
// "--dlpreopen libnull.la" linker option was given (for an empty libnull.la).
// This must agree with ltmain.sh & libltdl.
struct symbols {
  const char *name;
  void* address;
};
extern struct symbols lt_preloaded_symbols[];
struct symbols lt_preloaded_symbols[] = { 0, 0 };
#endif // !SID_STATIC

