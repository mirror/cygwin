# Copyright (C) 1999 Red Hat
#
# A simple tk-based LCD display. 

namespace eval lcd {
namespace export find_pin attribute_names set_attribute_value attribute_value connect* disconnect_pin find_bus driven driven_h4 set_pixel new_frame

variable this
set this [sid::component::this]

variable row_col_pin
set row_col_pin [sid::pin::new]

variable frame_pin
set frame_pin [sid::pin::new]

variable attributes

#default attribute values - width is 20 cols by 8 pixels/col by 4 bits/pixel
set attributes(bits_per_pixel) 4
set attributes(width) [expr 20*8*4]
set attributes(height) [expr 4*8*4]

frame .screen -relief groove -borderwidth 4
pack .screen -side top

canvas .screen.c 
pack .screen.c

proc find_pin {name} {
    variable row_col_pin
    variable frame_pin

    if {$name == "row-col" } { return $row_col_pin }
    if {$name == "FR" } { return $frame_pin }
    return ""
}

proc attribute_names {} { return [array names attributes] }

proc set_attribute_value {attr value} {
     variable attributes

     if {$attr == "width"} then {
         set size [expr $value * $attributes(bits_per_pixel)]
         set attributes(width) $size
	 .screen.c configure -width $size
	 return "ok"
     }

     if {$attr == "height"} then {
         set size [expr $value * $attributes(bits_per_pixel)]
         set attributes(height) $size
	 .screen.c configure -height $size
	 return "ok"
     }

     if {$attr == "bits-per-pixel"} then {
         set attributes(bits_per_pixel) $value
	 return "ok"
     }

     if {$attr == "background-color"} then {
         .screen.c configure -background $value
	 return "ok"
     }

     return "not_found"
}
     
proc attribute_value {attr} {
     variable attributes

     if {$attr == "width"} then {
         return $attributes(width)
     }

     if {$attr == "height"} then {
         return $attributes(height)
     }

     if {$attr == "bits-per-pixel"} then {
         return $attributes(bits_per_pixel)
     }

     if {$attr == "background-color"} then {
         # return just the '#rrggbb' at the end
	 set lbg [split [.screen.c configure -background]]
	 return [lindex $lbg [expr [llength $lbg] - 1]]
     }

     return ""
}
     
proc connect_pin {name pin} { return "not_found" }
proc disconnect_pin {name pin} { return "not_found" }
proc connected_pins {name} { return "" }
proc find_bus {name} { return "" }
proc connect_accessor {name bus} { return "" }
proc connected_bus {name} { return "" }

proc set_pixel {args} {
    variable attributes

    set val $args
    set bpp $attributes(bits_per_pixel)
    set rowp [expr ($val >> 16) * $bpp]
    set colp [expr ($val & 0xffff) * $bpp]

    if {$rowp == 0 && $colp == 0} {
        .screen.c delete all
    }

    .screen.c create rectangle $colp $rowp \
			[expr $colp+($bpp-1)] [expr $rowp+($bpp-1)] \
			-fill black
}

proc new_frame {arg} {
    if {$arg == 1} then {
        .screen.c delete all
    } else {
        update
    }
}

# override these in test cases if necessary
variable hook_driven
variable hook_driven_h4

set hook_driven_h4($row_col_pin) "lcd::set_pixel"
set hook_driven_h4($frame_pin) "lcd::new_frame"

proc driven_h4 {pin value} {
    variable hook_driven_h4

    if {[info exists hook_driven_h4($pin)]} {
	uplevel \#0 $hook_driven_h4($pin) $value
    } else {
	error "pin driven_h4 without hook: $pin"
    }
}

proc driven {pin} {
    variable hook_driven

    if {[info exists hook_driven($pin)]} then {
	uplevel \#0 $hook_driven($pin)
    } else {
	error "pin driven without hook: $pin"
    }
}

# end of namespace lcd
} 


update
