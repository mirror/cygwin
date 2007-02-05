// sidblockingutil.h - Elements used for blockable components.  -*- C++ -*-

// Copyright (C) 2004, 2005, 2007 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#ifndef SIDBLOCKINGUTIL_H
#define SIDBLOCKINGUTIL_H

#include <sidconfig.h>
#include <sidattrutil.h>

#include <iostream>
#include <pthread.h>

using std::cerr;
using std::endl;

namespace sidutil
{
  // A mix-in for classes with blocking
  class blocking_component
  : public virtual fixed_attribute_map_with_logging_component
  {
  protected:
    blocking_component (void *child_self, void *(*f)(void *)) :
      name ("unknown"),
      self (child_self),
      child_created (false),
      child_thread_function (f),
      blockable (false),
      still_blockable (false),
      control_status (ctl_parent)
      {
	add_attribute ("name", &name);
	add_attribute_notify ("blockable?", & still_blockable, this,
			      & blocking_component::set_blockable,
			      "setting");
      }
    ~blocking_component ()
      {
      }

    // -------------------------------------------------------------------
    // Child thread management
    //
  public:
    void child_init ()
      {
	log (10, "%s: child_init\n", name.c_str ());
	assert (child_created);
	// Lock both mutexes
	pthread_mutex_lock (& child_resume_mutex);
	pthread_mutex_lock (& child_stopped_mutex);
      }

  protected:
    void parent_init ()
      {
	log (10, "%s: parent_init\n", name.c_str ());

	// Create mutexes for synchronizing the parent and child threads
	pthread_mutex_init (& child_resume_mutex, NULL);
	pthread_cond_init (& child_resume_condition, NULL);
	pthread_mutex_init (& child_stopped_mutex, NULL);
	pthread_cond_init (& child_stopped_condition, NULL);

	// Lock both mutexes
	pthread_mutex_lock (& child_resume_mutex);
	pthread_mutex_lock (& child_stopped_mutex);
	control_status = ctl_parent;
      }

    // Called to ensure that a child thread exists
    //
    void need_child_thread ()
      {
	if (child_created)
	  return;

	log (10, "%s: need_child_thread\n", name.c_str ());

	parent_init ();

	// Create the child thread which will attempt to perform it's given
	// task.
	log (11, "%s: creating child thread\n", name.c_str ());
	child_created = true;
	int rc = pthread_create (& child_thread, NULL, child_thread_function, self);
	if (rc == EAGAIN)
	  {
	    cerr << name
		 << ": Could not create thread for a blockable component"
		 << endl;
	    child_created = false;
	  }
	else
	  log (11, "%s: child thread created\n", name.c_str ());
	  
	// Now wait for the child thread to signal that it is ready
	int status = wait_for_child_thread ();
	assert (status == ctl_child_complete);
      }

    // Called by the parent thread to signal the child thread to resume
    //
    int continue_child_thread_and_wait ()
      {
	log (10, "%s: continue_child_thread\n", name.c_str ());
	if (! child_created)
	  return ctl_child_complete;

	log (11, "%s: signalling child to resume\n", name.c_str ());
	return wait_for_child_thread ();
      }

    int wait_for_child_thread ()
      {
	log (10, "%s: wait_for_child_thread\n", name.c_str ());

	// Signal the child to resume
	assert (control_status != ctl_child_start);
	control_status = ctl_child_start;
	pthread_cond_signal (& child_resume_condition);

	// Unlock the mutex so that the child can gain control
	pthread_mutex_unlock (& child_resume_mutex);

	// Wait for the return signal from the child
	pthread_cond_wait (& child_stopped_condition, & child_stopped_mutex);

	// Reacquire the mutex so that the child can gain control
	pthread_mutex_lock (& child_resume_mutex);

	// Check the value of control_status
	assert (control_status != ctl_child_start);
	return control_status;
      }

  public:
    // Called by the child thread to signal normal completion of the child task
    //
    void child_completed ()
      {
	log (10, "%s: child_completed\n", name.c_str ());
	log (11, "%s: child sending completion signal\n", name.c_str ());
	control_status = ctl_child_complete;
	blockable = still_blockable;
	child_wait_for_resume ();
      }
	    
    // Called by the child thread to signal that it is blocked
    //
    void child_blocked ()
      {
	log (10, "%s: child_blocked\n", name.c_str ());
	log (11, "%s: child sending blocked signal\n", name.c_str ());
	control_status = ctl_child_blocked;
	child_wait_for_resume ();
      }

  protected:	    
    // Called by the child thread to wait for a signal from the parent thread
    // to resume
    void child_wait_for_resume ()
      {
	log (10, "%s: child_wait_for_resume\n", name.c_str ());

	// Signal the parent that we're stopped
	log (11, "%s: child signalling the parent thread\n", name.c_str ());
	pthread_cond_signal (& child_stopped_condition);

	// Unlock the mutex so that the parent can gain control
	pthread_mutex_unlock (& child_stopped_mutex);

	// Wait for a signal to resume
	log (11, "%s: child waiting for parent thread\n", name.c_str ());
	pthread_cond_wait (& child_resume_condition, & child_resume_mutex);

	// Reacquire the stopped mutex
	pthread_mutex_lock (& child_stopped_mutex);
	assert (control_status == ctl_child_start);
      }

    void set_blockable ()
      {
	// Never change the status of 'blockable' while the child thread is
	// active.
	if (control_status == ctl_parent || control_status == ctl_child_complete)
	  blockable = still_blockable;
      }

  protected:
    string name;
    bool blockable;
    bool still_blockable;
    void *self;
    bool child_created;
    pthread_t child_thread;
    void *(*child_thread_function)(void *);
    pthread_mutex_t child_resume_mutex;
    pthread_cond_t child_resume_condition;
    pthread_mutex_t child_stopped_mutex;
    pthread_cond_t child_stopped_condition;
    enum
      {
	ctl_parent, ctl_child_start, ctl_child_blocked, ctl_child_complete
      } control_status;
  };
}

#endif // SIDBLOCKINGUTIL_H
