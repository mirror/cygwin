#include <time.h>
#include <sidcomp.h>
#include <sidcomputil.h>
#include <sidschedutil.h>
#include <sidbusutil.h>

// Use these namespaces for convenience.
using namespace sidutil;
using namespace sid;

class timeofday_engine : public virtual component,
			 protected no_attribute_component,
			 protected fixed_bus_map_component,
			 protected fixed_pin_map_component,
			 protected fixed_accessor_map_component,
			 protected no_relation_component
{
  control_register_bus<big_int_4> ctrlbus; 
  callback_control_register<big_int_4,timeofday_engine> timeofday;

  big_int_4 get_time () 
  {
    return time (NULL);
  }

public:  
  timeofday_engine () :
    ctrlbus (),
    timeofday (& ctrlbus, 0x0, 0xFFFFFFFF, true, false, this, 
	       & timeofday_engine::get_time)
  {
    add_bus ("control-bus", & ctrlbus);
  }
};
