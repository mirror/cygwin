# EIT (exceptions, interrupts, traps) tcl support

global this
set this [sid::component::this]

# pin to drive to trigger an fiq
# The leading "n" is ARM's way of marking the pin as being active low (`not').
# Handle of pin our nfiq_pin is connected to.
# ??? We never actually create our own pin.
global cpu_nfiq_pin
set cpu_nfiq_pin "-unconnected-"

# pin to drive to trigger an irq
global cpu_nirq_pin
set cpu_nirq_pin "-unconnected-"

# cpu writes to this bus to request us to do something
global tcl_bus
set tcl_bus [sid::bus::new]

# Pins.

proc connect_pin {name pin} {
    if { "$name" == "nfiq!" } {
	global cpu_nfiq_pin
	set cpu_nfiq_pin $pin
	# Initialize pin to 1 (inactive).
	sid::pin::driven_h4 $pin 1
	return "ok"
    }
    if { "$name" == "nirq!" } {
	global cpu_nirq_pin
	set cpu_nirq_pin $pin
	# Initialize pin to 1 (inactive).
	sid::pin::driven_h4 $pin 1
	return "ok"
    }
    return "not_found"
}

# Busses.

proc find_bus {name} {
    global tcl_bus
    if { "$name" == "tcl-bus" } {
	return $tcl_bus
    }
    return ""
}

proc write_h4_l1 {this-bus addr data} {
    #puts "write: ${this-bus} $addr $data\n"
    if { $addr == 0 } {
	global cpu_nfiq_pin
	#puts "driving nfiq pin active: $cpu_nfiq_pin\n"
	set rc [sid::pin::driven_h4 $cpu_nfiq_pin 0]
	if { $rc != "" } {
	    puts "ERROR: can't write to cpu's nfiq pin: $rc\n"
	}
    } elseif { $addr == 1 } {
	global cpu_nirq_pin
	#puts "driving nirq pin active: $cpu_nirq_pin\n"
	set rc [sid::pin::driven_h4 $cpu_nirq_pin 0]
	if { $rc != "" } {
	    puts "ERROR: can't write to cpu's nirq pin: $rc\n"
	}
    }
    return ok
}

proc write_h4_b1 {this-bus addr data} {
    write_h4_l1 ${this-bus} $addr $data
}
