option add *font {Helvetica 10 bold}

wm title . {Cygnus Voice Pager $Revision: 1.1 $}

if {0} {
    # not needed - just bind to the <Destroy> event.
    frame .mbar -relief raised -bd 2
    pack .mbar -before .screen -side top -fill x
    menubutton .mbar.file -text File -underline 0 -menu .mbar.file.menu
    #menubutton .mbar.help -text Help -underline 0 -menu .mbar.help.menu
    pack .mbar.file -side left
    #pack .mbar.help -side right
    menu .mbar.file.menu
    .mbar.file.menu add command -label Quit -command "done"
}

set this [sid::component::this]

# driven if "UP" button pressed and released. config name is "up-pin"
set up_pin 0

# driven if "DN" button pressed and released. config name is "down-pin"
set down_pin 0

# driven if "REC" button pressed. config name is "rec-pin"
set record_pin 0

# driven if "PLAY" button pressed and released. config name is "play-pin"
set play_pin 0

# driven if "DEL" button pressed and released. config name is "del-pin"
set delete_pin 0

# driven if "Quit" menu item is selected. config name is "done-pin"
set done_pin 0

# driven if "Stop" Button is pressed.
set stop_pin 0

# driven whenever any button is pressed. config name is "ack-pin"
set ack_pin 0

proc find_pin {name} {
    global up_pin
    global down_pin
    global record_pin
    global play_pin
    global done_pin
    global stop_pin
    global ack_pin

    if {$name == "up-pin" } { return $up_pin }
    if {$name == "down-pin" } { return $down_pin }
    if {$name == "rec-pin" } { return $record_pin }
    if {$name == "play-pin" } { return $play_pin }
    if {$name == "del-pin" } { return $delete_pin }
    if {$name == "done-pin" } { return $done_pin }
    if {$name == "stop-pin" } { return $stop_pin }
    if {$name == "ack-pin" } { return $ack_pin }
    return [lcd::find_pin $name]
}

proc connect_pin {name pin} {
    if { $name == "up-pin" } {
	global up_pin
	set up_pin $pin
	return "ok"
    }
    if { $name == "down-pin" } {
	global down_pin
	set down_pin $pin
	return "ok"
    }
    if { $name == "rec-pin" } {
	global record_pin
	set record_pin $pin
	return "ok"
    }
    if { $name == "play-pin" } {
	global play_pin
	set play_pin $pin
	return "ok"
    }
    if { $name == "del-pin" } {
	global delete_pin
	set delete_pin $pin
	return "ok"
    }
    if { $name == "done-pin" } {
	global done_pin
	set done_pin $pin
	return "ok"
    }
    if { $name == "stop-pin" } {
	global stop_pin
	set stop_pin $pin
	return "ok"
    }
    if { $name == "ack-pin" } {
	global ack_pin
	set ack_pin $pin
	return "ok"
    }
    return "not_found"
}
     
proc up_button dr_val {
    global up_pin
    global ack_pin
    sid::pin::driven_h4 $up_pin $dr_val
    sid::pin::driven_h4 $ack_pin 0
    sid::pin::driven_h4 $ack_pin 1
}

proc down_button dr_val {
    global down_pin
    global ack_pin
    sid::pin::driven_h4 $down_pin $dr_val
    sid::pin::driven_h4 $ack_pin 0
    sid::pin::driven_h4 $ack_pin 1
}

proc record_button dr_val {
    global record_pin
    global ack_pin
    sid::pin::driven_h4 $record_pin $dr_val
    sid::pin::driven_h4 $ack_pin 0
    sid::pin::driven_h4 $ack_pin 1
}    

proc play_button dr_val {
    global play_pin
    global ack_pin
    sid::pin::driven_h4 $play_pin $dr_val
    sid::pin::driven_h4 $ack_pin 0
    sid::pin::driven_h4 $ack_pin 1
}

proc delete_button dr_val {
    global delete_pin
    global ack_pin
    sid::pin::driven_h4 $delete_pin $dr_val
    sid::pin::driven_h4 $ack_pin 0
    sid::pin::driven_h4 $ack_pin 1
}

proc stop_button dr_val {
    global stop_pin
    global ack_pin
    sid::pin::driven_h4 $stop_pin $dr_val
    sid::pin::driven_h4 $ack_pin 0
    sid::pin::driven_h4 $ack_pin 1
}

proc done {} {
    global done_pin
    global ack_pin
    sid::pin::driven_h4	$done_pin 1
    sid::pin::driven_h4 $ack_pin 0
}

proc attribute_names {} {
    return [lcd::attribute_names]
}

proc set_attribute_value {attr value} {
    return [lcd::set_attribute_value $attr $value]
}
     
proc attribute_value {attr} {
    return [lcd::attribute_value $attr]
}

proc driven_h4 {pin value} {
        lcd::driven_h4 $pin $value
}

proc driven {pin} {
    lcd::driven $pin 
}


frame .control -relief groove -borderwidth 4

pack .control -side bottom -fill x
button .control.up -bitmap @bp1.bit
button .control.down -bitmap @bp2.bit
button .control.rec -bitmap @record.bit -fg red
button .control.play -bitmap @play.bit
button .control.del -bitmap @bp3.bit
button .control.stop -bitmap @stop.bit

bind .control.up <ButtonPress>   {up_button 1}
bind .control.up <ButtonRelease> {up_button 0}
bind .control.down <ButtonPress>   {down_button 1}
bind .control.down <ButtonRelease> {down_button 0}
bind .control.rec <ButtonPress>   {record_button 1}
bind .control.rec <ButtonRelease> {record_button 0}
bind .control.play <ButtonPress> {play_button 1}
bind .control.play <ButtonRelease> {play_button 0}
bind .control.del <ButtonPress> {delete_button 1}
bind .control.del <ButtonRelease> {delete_button 0}
bind .control.stop <ButtonPress> {stop_button 1}
bind .control.stop <ButtonRelease> {stop_button 0}

pack .control.up .control.down -side left -ipadx 3m -ipady 1m
pack .control.rec .control.play .control.stop .control.del -side right\
    -ipadx 3m -ipady 1m

bind . <Destroy> {done}

update
