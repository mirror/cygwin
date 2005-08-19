# Copyright (C) 2000, 2005 Red Hat
#
# This is a component that forwards almost all sid requests to another
# component.  Further, it interjects proxy pin/bus objects between the
# outside world and the victim.  All traffic may be traced.

global this
set this [sid::component::this]

# A handle to my victim component
global victim
set victim ""

# trace calls?
global victim_trace_p
set victim_trace_p 1

# map proxy-pin<->real-pin
global proxy2real_pin_map
global real2proxy_pin_map

proc real2proxy_pin {pin} {
    global proxy2real_pin_map
    global real2proxy_pin_map
    if [info exists real2proxy_pin_map($pin)] then {
	set pin $real2proxy_pin_map($pin)
    } else {
	set proxy [sid::pin::new]
	set proxy2real_pin_map($proxy) $pin
	set real2proxy_pin_map($pin) $proxy
	set pin $proxy
    }
    return $pin
}

proc proxy2real_pin {pin} {
    global proxy2real_pin_map
    if [info exists proxy2real_pin_map($pin)] then {
	set pin $proxy2real_pin_map($pin)
    } else {
	error "Unknown proxy pin $pin"
    }
    return $pin
}

# map proxy-bus<->real-bus
global proxy2real_bus_map
global real2proxy_bus_map

proc real2proxy_bus {bus} {
    global proxy2real_bus_map
    global real2proxy_bus_map
    if [info exists real2proxy_bus_map($bus)] then {
	set bus $real2proxy_bus_map($bus)
    } else {
	set proxy [sid::bus::new]
	set proxy2real_bus_map($proxy) $bus
	set real2proxy_bus_map($bus) $proxy
	set bus $proxy
    }
    return $bus
}

proc proxy2real_bus {bus} {
    global proxy2real_bus_map
    if [info exists proxy2real_bus_map($bus)] then {
	set bus $proxy2real_bus_map($bus)
    } else {
	error "Unknown proxy bus $bus"
    }
    return $bus
}

proc sidtrace {cmd} {
    global victim_trace_p
    if {$victim_trace_p != "0"} then {
	puts -nonewline "$cmd >"
    }
    set result [uplevel 1 $cmd]
    if {$victim_trace_p != "0"} then {
	puts "> $result"
    }
    return $result
}

proc attribute_names {} {
    global victim
    return [sidtrace [list sid::component::attribute_names $victim]]
}

proc attribute_names_in_category {cat} {
    global victim
    # special hack to prevent error message during component instantiation
    if {$victim == ""} then { return [list] }
    # don't add "victim-trace?" - that would make wrapper more translucent
    return [sidtrace [list sid::component::attribute_names_in_category $victim $cat]]
}

proc attribute_value {attr} {
    global victim
    if {$attr == "component-type"} then { return "sid-api-trace" }
    if {$attr == "victim"} then { return "$victim" }
    return [sidtrace [list sid::component::attribute_value $victim $attr]]
}

proc set_attribute_value {attr value} {
    global victim
    if {$attr == "victim-trace?"} then {
	global victim_trace_p
	set victim_trace_p $value
	return "ok"
    } else {
	return [sidtrace [list sid::component::set_attribute_value $victim $attr $value]]
    }
}

proc pin_names {} {
    global victim
    return [sidtrace [list sid::component::pin_names $victim]]
}

proc find_pin {name} {
    global victim
    set pin [sidtrace [list sid::component::find_pin $victim $name]]
    if {$pin == ""} then { return "" } else { return [real2proxy_pin $pin] }
}

proc connect_pin {name pin} {
    global victim
    set proxy [real2proxy_pin $pin]
    return [sidtrace [list sid::component::connect_pin $victim $name $proxy]]
}

proc disconnect_pin {name pin} {
    global victim
    set proxy [real2proxy_pin $pin]
    return [sidtrace [list sid::component::disconnect_pin $victim $name $proxy]]
}

proc connected_pins {name} {
    global victim
    set victimpins [sidtrace [list sid::component::connected_pins $victim $name]]
    set realpins [list]
    foreach pin $victimpins {
	lappend realpins [proxy2real_pin $pin]
    }
    return $realpins
}

proc bus_names {} {
    global victim
    return [sidtrace [list sid::component::bus_names $victim]]
}

proc find_bus {name} {
    global victim
    set bus [sidtrace [list sid::component::find_bus $victim $name]]
    if {$bus == ""} then { return "" } else { return [real2proxy_bus $bus] }
}

proc accessor_names {} {
    global victim
    return [sidtrace [list sid::component::accessor_names $victim]]
}

proc connect_accessor {name bus} {
    global victim
    set proxy [real2proxy_bus $bus]
    return [sidtrace [list sid::component::connect_accessor $victim $name $proxy]]
}

proc disconnect_accessor {name bus} {
    global victim
    set proxy [real2proxy_bus $bus]
    return [sidtrace [list sid::component::disconnect_accessor $victim $name $proxy]]
}

proc connected_bus {name} {
    global victim
    set bus [sidtrace [list sid::component::connected_bus $victim $name]]
    if {$bus == ""} then { return "" } else { return [real2proxy_bus $bus] }
}

proc relationship_names {} {
    global victim
    # don't add "victim" - that would make wrapper more translucent
    return [sidtrace [list sid::component::relationship_names $victim]]
}

proc relate {rel comp} {
    global victim
    if {$rel == "victim"} then {
	set victim $comp
	return "ok"
    } else { 
	return [sidtrace [list sid::component::relate $victim $rel $comp]]
    }
}

proc unrelate {rel comp} {
    global victim
    if {$rel == "victim"} then {
	set victim ""
	return "ok"
    } else { 
	return [sidtrace [list sid::component::unrelate $victim $rel $comp]]
    }
}


proc related_components {rel} {
    global victim
    if {$rel == "victim"} then {
	return $victim
    } else {
	return [sidtrace [list sid::component::related_components $victim $rel]]
    }
}


# proxy pin functions
proc driven_h4 {proxy value} {
    set pin [proxy2real_pin $proxy]
    return [sidtrace [list sid::pin::driven_h4 $pin $value]]
}


# proxy bus functions 

proc write_h4_l1 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_l1 $bus $addr $data]]
}
proc write_h4_l2 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_l2 $bus $addr $data]]
}
proc write_h4_l4 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_l4 $bus $addr $data]]
}
proc write_h4_l8 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_l8 $bus $addr $data]]
}
proc read_h4_l1 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_l1 $bus $addr]]
}
proc read_h4_l2 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_l2 $bus $addr]]
}
proc read_h4_l4 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_l4 $bus $addr]]
}
proc read_h4_l8 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_l8 $bus $addr]]
}


proc write_h4_b1 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_b1 $bus $addr $data]]
}
proc write_h4_b2 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_b2 $bus $addr $data]]
}
proc write_h4_b4 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_b4 $bus $addr $data]]
}
proc write_h4_b8 {proxy addr data} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::write_h4_b8 $bus $addr $data]]
}
proc read_h4_b1 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_b1 $bus $addr]]
}
proc read_h4_b2 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_b2 $bus $addr]]
}
proc read_h4_b4 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_b4 $bus $addr]]
}
proc read_h4_b8 {proxy addr} {
    set bus [proxy2real_bus $proxy]
    return [sidtrace [list sid::bus::read_h4_b8 $bus $addr]]
}
