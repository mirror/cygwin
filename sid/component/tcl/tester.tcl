# This is a component that listens on stdin for a command line,
# runs the command, and prints the result.  It does this each
# time its "command-io!" pin is driven.  
#
# In addition, it maintains an arbitrary vector of component relationships.
# The relationships are stored in a global array: relationship($name).


global this
set this [sid::component::this]

global command_io_pin
set command_io_pin [sid::pin::new]

# Array of handles of my victim components
global relationships

# Control command/result hexification mode.  If empty, don't.
global hexify_traffic_p
set hexify_traffic_p ""

proc attribute_names {} { return "hexify?" }
proc attribute_names_in_category {cat} { return "" }
proc attribute_value {attr} { 
    global hexify_traffic_p
    if {$attr == "hexify?"} then {
	return $hexify_traffic_p
    } else {
	return "" 
    }
}
proc set_attribute_value {attr value} { 
    global hexify_traffic_p
    if {$attr == "hexify?"} then {
	# check $value for validity?
	set hexify_traffic_p $value
	return "ok"
    } else {
	return "not_found" 
    }
}

proc find_pin {name} {
    global command_io_pin
    if {$name == "command-io!" } then { return $command_io_pin }
    return ""
}
proc connect_pin {name pin} { return "not_found" }
proc disconnect_pin {name pin} { return "not_found" }
proc connected_pins {name} { return "" }
proc find_bus {name} { return "" }
proc connect_accessor {name bus} { return "" }
proc disconnect_accessor {name bus} { return "" }
proc connected_bus {name} { return "" }

proc relationship_names {} {
    global relationships
    return [array names relationships] 
}

proc relate {rel comp} {
    global relationships
    lappend relationships($rel) $comp
    return "ok"
}

proc related_components {rel} {
    global relationships
    return $relationships($rel)
}


proc command_io {args} {
    global victim
    global hook_driven
    global hook_driven_h4
    global hexify_traffic_p

    # prompt
    puts "command>"
    flush stdout

    # long lines may be split by terminating partial lines with `+'.
    while {1} {
	gets stdin piece
	set plen [string length $piece]
	# reconstruct broken lines
	if {[string index $piece [expr $plen - 1]] == "+"} then {
	    append line [string range $piece 0 [expr $plen - 2]]
	} else {
	    append line $piece
	    break
	}
    }

    # ignore blank lines
    if {$line == ""} then { return }

    if {$hexify_traffic_p != ""} then {
	set cmd [binary format H* $line]
    } else {
	set cmd $line
    }
    set bad [catch {uplevel \#0 $cmd} result]

    if {$hexify_traffic_p != ""} then {
	binary scan $result H* encoded
    } else {
	set encoded $result
    }

    if $bad then {puts "ERROR: $result"} else {
	if {[string length $encoded] > 64} {
	    set iterations [expr [string length $encoded] / 64]
	    for {set i 0} {$i < $iterations} {incr i} {
		set first [expr $i * 64]
		set last [expr $first + 63]
		puts "split>>[string range $encoded $first $last]<<split"
	    }
	    set first [expr $i * 64]
	    puts "split>>[string range $encoded $first end]<<split split-end"
	} else {
	    puts "result>>$encoded<<result"
	}
    }
    flush stdout
}

# override these in test cases if necessary
global hook_driven
global hook_driven_h4

set hook_driven($command_io_pin) "command_io"
set hook_driven_h4($command_io_pin) "command_io"

proc driven_h4 {pin value} {
    global hook_driven_h4

    # pass this value to the hook through a global variable
    global driven_h4_value
    set driven_h4_value $value

    if {[info exists hook_driven_h4($pin)]} then {
	uplevel \#0 $hook_driven_h4($pin)
    } else {
	error "pin driven_h4 without hook: $pin"
    }
}


# Callbacks are held in a 3D array -- e.g. (h4,l4,sid-bus#1).

proc read_h4_l1 {bus addr} {
    puts "inside read_h4_l1"
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian little
    set read_width 1

    if {[info exists hook_read(h4,l1,$bus)]} {
	return [uplevel \#0 $hook_read(h4,l1,$bus)]
    } else {
	error "bus read_h4_l1 without hook: $bus"
    }
}

proc read_h4_l2 {bus addr} {
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian little
    set read_width 2

    if {[info exists hook_read(h4,l2,$bus)]} {
	return [uplevel \#0 $hook_read(h4,l2,$bus)]
    } else {
	error "bus read_h4_l2 without hook: $bus"
    }
}

proc read_h4_l4 {bus addr} {
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian little
    set read_width 4

    if {[info exists hook_read(h4,l4,$bus)]} {
	return [uplevel \#0 $hook_read(h4,l4,$bus)]
    } else {
	error "bus read_h4_l4 without hook: $bus"
    }
}

proc read_h4_l8 {bus addr} {
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian little
    set read_width 8

    if {[info exists hook_read(h4,l8,$bus)]} {
	return [uplevel \#0 $hook_read(h4,l8,$bus)]
    } else {
	error "bus read_h4_l8 without hook: $bus"
    }
}

proc read_h4_b1 {bus addr} {
    puts "inside read_h4_b1"
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian big
    set read_width 1

    if {[info exists hook_read(h4,b1,$bus)]} {
	return [uplevel \#0 $hook_read(h4,b1,$bus)]
    } else {
	error "bus read_h4_b1 without hook: $bus"
    }
}

proc read_h4_b2 {bus addr} {
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian big
    set read_width 2

    if {[info exists hook_read(h4,b2,$bus)]} {
	return [uplevel \#0 $hook_read(h4,b2,$bus)]
    } else {
	error "bus read_h4_b2 without hook: $bus"
    }
}

proc read_h4_b4 {bus addr} {
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian big
    set read_width 4

    if {[info exists hook_read(h4,b4,$bus)]} {
	return [uplevel \#0 $hook_read(h4,b4,$bus)]
    } else {
	error "bus read_h4_b4 without hook: $bus"
    }
}

proc read_h4_b8 {bus addr} {
    global hook_read read_addr read_endian read_width

    set read_addr $addr
    set read_endian big
    set read_width 8

    if {[info exists hook_read(h4,b8,$bus)]} {
	return [uplevel \#0 $hook_read(h4,b8,$bus)]
    } else {
	error "bus read_h4_b8 without hook: $bus"
    }
}

proc write_h4_l1 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian little
    set written_width 1
    
    if {[info exists hook_written(h4,l1,$bus)]} {
	return [uplevel \#0 $hook_written(h4,l1,$bus)]
    } else {
	error "bus write_h4_l1 without hook: $bus"
    }
}

proc write_h4_l2 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian little
    set written_width 2

    if {[info exists hook_written(h4,l2,$bus)]} {
	return [uplevel \#0 $hook_written(h4,l2,$bus)]
    } else {
	error "bus write_h4_l2 without hook: $bus"
    }
}

proc write_h4_l4 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian little
    set written_width 4

    if {[info exists hook_written(h4,l4,$bus)]} {
	return [uplevel \#0 $hook_written(h4,l4,$bus)]
    } else {
	error "bus write_h4_l4 without hook: $bus"
    }
}

proc write_h4_l8 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian little
    set written_width 8

    if {[info exists hook_written(h4,l8,$bus)]} {
	return [uplevel \#0 $hook_written(h4,l8,$bus)]
    } else {
	error "bus write_h4_l8 without hook: $bus"
    }
}

proc write_h4_b1 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian big
    set written_width 1

    if {[info exists hook_written(h4,b1,$bus)]} {
	return [uplevel \#0 $hook_written(h4,b1,$bus)]
    } else {
	error "bus write_h4_b1 without hook: $bus"
    }
}

proc write_h4_b2 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian big
    set written_width 2

    if {[info exists hook_written(h4,b2,$bus)]} {
	return [uplevel \#0 $hook_written(h4,b2,$bus)]
    } else {
	error "bus write_h4_b2 without hook: $bus"
    }
}

proc write_h4_b4 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian big
    set written_width 4

    if {[info exists hook_written(h4,b4,$bus)]} {
	return [uplevel \#0 $hook_written(h4,b4,$bus)]
    } else {
	error "bus write_h4_b4 without hook: $bus"
    }
}

proc write_h4_b8 {bus addr data} {
    global hook_written written_addr written_data written_endian
    global written_width

    set written_addr $addr
    set written_data $data
    set written_endian big
    set written_width 8

    if {[info exists hook_written(h4,b8,$bus)]} {
	return [uplevel \#0 $hook_written(h4,b8,$bus)]
    } else {
	error "bus write_h4_b8 without hook: $bus"
    }
}

puts "tester ready"
