# table.tcl --
#
# version 1.8, jeff.hobbs@acm.org
# This file defines the default bindings for Tk table widgets
# and provides procedures that help in implementing those bindings.
#

#--------------------------------------------------------------------------
# tkPriv elements used in this file:
#
# afterId -		Token returned by "after" for autoscanning.
# tablePrev -		The last element to be selected or deselected
#			during a selection operation.
#--------------------------------------------------------------------------

# tkTableClipboardKeysyms --
# This procedure is invoked to identify the keys that correspond to
# the "copy", "cut", and "paste" functions for the clipboard.
#
# Arguments:
# copy -	Name of the key (keysym name plus modifiers, if any,
#		such as "Meta-y") used for the copy operation.
# cut -		Name of the key used for the cut operation.
# paste -	Name of the key used for the paste operation.

proc tkTableClipboardKeysyms {copy cut paste} {
    bind Table <$copy>	{tk_tableCopy %W}
    bind Table <$cut>	{tk_tableCut %W}
    bind Table <$paste>	{tk_tablePaste %W}
}

## Interactive row resizing, affected by -resizeborders option
##
bind Table <3>		{
    ## You might want to check for row returned if you want to
    ## restrict the resizing of certain rows
    %W border mark %x %y
}
bind Table <B3-Motion>	{ %W border dragto %x %y }

## Button events

bind Table <1> {
    if {[winfo exists %W]} {
	tkTableBeginSelect %W [%W index @%x,%y]
	focus %W
    }
}
bind Table <B1-Motion> {
    array set tkPriv {x %x y %y}
    tkTableMotion %W [%W index @%x,%y]
}
bind Table <Double-1> {
    # empty
}
bind Table <ButtonRelease-1> {
    if {[winfo exists %W]} {
	tkCancelRepeat
	%W activate @%x,%y
    }
}

bind Table <Shift-1>	{tkTableBeginExtend %W [%W index @%x,%y]}
bind Table <Control-1>	{tkTableBeginToggle %W [%W index @%x,%y]}
bind Table <B1-Enter>	{tkCancelRepeat}
bind Table <B1-Leave>	{
    array set tkPriv {x %x y %y}
    tkTableAutoScan %W
}
bind Table <2> {
    %W scan mark %x %y
    array set tkPriv {x %x y %y}
    set tkPriv(mouseMoved) 0
}
bind Table <B2-Motion> {
    if {(%x != $tkPriv(x)) || (%y != $tkPriv(y))} { set tkPriv(mouseMoved) 1 }
    if $tkPriv(mouseMoved) { %W scan dragto %x %y }
}
bind Table <ButtonRelease-2> {
    if {!$tkPriv(mouseMoved)} { tk_tablePaste %W [%W index @%x,%y] }
}

## Key events

if {[string comp {} [info command event]]} {
    tkTableClipboardKeysyms <Copy> <Cut> <Paste>
} else {
    tkTableClipboardKeysyms Control-c Control-x Control-v
}

bind Table <Any-Tab> {
    # empty to allow Tk focus movement
}
# This forces a cell commit if an active cell exists
# Remove this if you don't want cell commit to occur
# on every FocusOut
bind Table <FocusOut> {
    catch {%W activate active}
}
bind Table <Shift-Up>		{tkTableExtendSelect %W -1  0}
bind Table <Shift-Down>		{tkTableExtendSelect %W  1  0}
bind Table <Shift-Left>		{tkTableExtendSelect %W  0 -1}
bind Table <Shift-Right>	{tkTableExtendSelect %W  0  1}
bind Table <Prior>		{%W yview scroll -1 pages; %W activate @0,0}
bind Table <Next>		{%W yview scroll  1 pages; %W activate @0,0}
bind Table <Control-Prior>	{%W xview scroll -1 pages}
bind Table <Control-Next>	{%W xview scroll  1 pages}
bind Table <Home>		{%W see origin}
bind Table <End>		{%W see end}
bind Table <Control-Home> {
    %W selection clear all
    %W activate origin
    %W selection set active
    %W see active
}
bind Table <Control-End> {
    %W selection clear all
    %W activate end
    %W selection set active
    %W see active
}
bind Table <Shift-Control-Home>	{tkTableDataExtend %W origin}
bind Table <Shift-Control-End>	{tkTableDataExtend %W end}
bind Table <Select>		{tkTableBeginSelect %W [%W index active]}
bind Table <Shift-Select>	{tkTableBeginExtend %W [%W index active]}
bind Table <Control-slash>	{tkTableSelectAll %W}
bind Table <Control-backslash> {
    if {[string match browse [%W cget -selectmode]]} {%W selection clear all}
}
bind Table <Up>			{tkTableMoveCell %W -1  0}
bind Table <Down>		{tkTableMoveCell %W  1  0}
bind Table <Left>		{tkTableMoveCell %W  0 -1}
bind Table <Right>		{tkTableMoveCell %W  0  1}
bind Table <Any-KeyPress> {
    if {[string compare {} %A]} { %W insert active insert %A }
}
bind Table <BackSpace> {
    set tkPriv(junk) [%W icursor]
    if {[string compare {} $tkPriv(junk)] && $tkPriv(junk)} {
	%W delete active [expr {$tkPriv(junk)-1}]
    }
}
bind Table <Delete>		{%W delete active insert}
bind Table <Escape>		{%W reread}

#bind Table <Return>		{tkTableMoveCell %W 1 0}
bind Table <Return> {
    %W insert active insert "\n"
}

bind Table <Control-Left>	{%W icursor [expr {[%W icursor]-1}]}
bind Table <Control-Right>	{%W icursor [expr {[%W icursor]+1}]}
bind Table <Control-e>		{%W icursor end}
bind Table <Control-a>		{%W icursor 0}
bind Table <Control-k>		{%W delete active insert end}
bind Table <Control-equal>	{tkTableChangeWidth %W active  1}
bind Table <Control-minus>	{tkTableChangeWidth %W active -1}

# tkTableBeginSelect --
#
# This procedure is typically invoked on button-1 presses. It begins
# the process of making a selection in the table. Its exact behavior
# depends on the selection mode currently in effect for the table;
# see the Motif documentation for details.
#
# Arguments:
# w	- The table widget.
# el	- The element for the selection operation (typically the
#	one under the pointer).  Must be in row,col form.

proc tkTableBeginSelect {w el} {
    global tkPriv
    if {[scan $el %d,%d r c] != 2} return
    switch [$w cget -selectmode] {
	multiple {
	    if {[$w tag includes title $el]} {
		## in the title area
		if {$r < [$w cget -titlerows]+[$w cget -roworigin]} {
		    ## We're in a column header
		    if {$c < [$w cget -titlecols]+[$w cget -colorigin]} {
			## We're in the topleft title area
			set inc topleft
			set el2 end
		    } else {
			set inc [$w index topleft row],$c
			set el2 [$w index end row],$c
		    }
		} else {
		    ## We're in a row header
		    set inc $r,[$w index topleft col]
		    set el2 $r,[$w index end col]
		}
	    } else {
		set inc $el
		set el2 $el
	    }
	    if [$w selection includes $inc] {
		$w selection clear $el $el2
	    } else {
		$w selection set $el $el2
	    }
	}
	extended {
	    $w selection clear all
	    if {[$w tag includes title $el]} {
		if {$r < [$w cget -titlerows]+[$w cget -roworigin]} {
		    ## We're in a column header
		    if {$c < [$w cget -titlecols]+[$w cget -colorigin]} {
			$w selection set origin end
		    } else {
			$w selection set $el [$w index end row],$c
		    }
		} else {
		    ## We're in a row header
		    $w selection set $el $r,[$w index end col]
		}
	    } else {
		$w selection set $el
	    }
	    $w selection anchor $el
	    set tkPriv(tablePrev) $el
	}
	default {
	    if {![$w tag includes title $el]} {
		$w selection clear all
		$w selection set $el
		set tkPriv(tablePrev) $el
	    }
	    $w selection anchor $el
	}
    }
}

# tkTableMotion --
#
# This procedure is called to process mouse motion events while
# button 1 is down. It may move or extend the selection, depending
# on the table's selection mode.
#
# Arguments:
# w	- The table widget.
# el	- The element under the pointer (must be in row,col form).

proc tkTableMotion {w el} {
    global tkPriv
    if {![info exists tkPriv(tablePrev)]} {
	set tkPriv(tablePrev) $el
	return
    }
    if {[string match $tkPriv(tablePrev) $el]} return
    switch [$w cget -selectmode] {
	browse {
	    $w selection clear all
	    $w selection set $el
	    set tkPriv(tablePrev) $el
	}
	extended {
	    scan $tkPriv(tablePrev) %d,%d r c
	    scan $el %d,%d elr elc
	    if {[$w tag includes title $el]} {
		if {$r < [$w cget -titlerows]+[$w cget -roworigin]} {
		    ## We're in a column header
		    if {$c < [$w cget -titlecols]+[$w cget -colorigin]} {
			## We're in the topleft title area
			$w selection clear anchor end
		    } else {
			$w selection clear anchor [$w index end row],$c
		    }
		    $w selection set anchor [$w index end row],$elc
		} else {
		    ## We're in a row header
		    $w selection clear anchor $r,[$w index end col]
		    $w selection set anchor $elr,[$w index end col]
		}
	    } else {
		$w selection clear anchor $tkPriv(tablePrev)
		$w selection set anchor $el
	    }
	    set tkPriv(tablePrev) $el
	}
    }
}

# tkTableBeginExtend --
#
# This procedure is typically invoked on shift-button-1 presses. It
# begins the process of extending a selection in the table. Its
# exact behavior depends on the selection mode currently in effect
# for the table; see the Motif documentation for details.
#
# Arguments:
# w - The table widget.
# el - The element for the selection operation (typically the
# one under the pointer). Must be in numerical form.

proc tkTableBeginExtend {w el} {
    if {[string match extended [$w cget -selectmode]] &&
	[$w selection includes anchor]} {
	tkTableMotion $w $el
    }
}

# tkTableBeginToggle --
#
# This procedure is typically invoked on control-button-1 presses. It
# begins the process of toggling a selection in the table. Its
# exact behavior depends on the selection mode currently in effect
# for the table; see the Motif documentation for details.
#
# Arguments:
# w - The table widget.
# el - The element for the selection operation (typically the
# one under the pointer). Must be in numerical form.

proc tkTableBeginToggle {w el} {
    global tkPriv
    if {[string match extended [$w cget -selectmode]]} {
	set tkPriv(tablePrev) $el
	$w selection anchor $el
	if [$w selection includes $el] {
	    $w selection clear $el
	} else {
	    $w selection set $el
	}
    }
}

# tkTableAutoScan --
# This procedure is invoked when the mouse leaves an entry window
# with button 1 down. It scrolls the window up, down, left, or
# right, depending on where the mouse left the window, and reschedules
# itself as an "after" command so that the window continues to scroll until
# the mouse moves back into the window or the mouse button is released.
#
# Arguments:
# w - The entry window.

proc tkTableAutoScan {w} {
    global tkPriv
    if {![winfo exists $w]} return
    set x $tkPriv(x)
    set y $tkPriv(y)
    if {$y >= [winfo height $w]} {
	$w yview scroll 1 units
    } elseif {$y < 0} {
	$w yview scroll -1 units
    } elseif {$x >= [winfo width $w]} {
	$w xview scroll 1 units
    } elseif {$x < 0} {
	$w xview scroll -1 units
    } else {
	return
    }
    tkTableMotion $w [$w index @$x,$y]
    set tkPriv(afterId) [after 50 tkTableAutoScan $w]
}

# tkTableMoveCell --
#
# Moves the location cursor (active element) by the specified number
# of cells and changes the selection if we're in browse or extended
# selection mode.
#
# Arguments:
# w - The table widget.
# x - +1 to move down one cell, -1 to move up one cell.
# y - +1 to move right one cell, -1 to move left one cell.

proc tkTableMoveCell {w x y} {
    global tkPriv
    if {[catch {$w index active row} r]} return
    set c [$w index active col]
    $w activate [incr r $x],[incr c $y]
    $w see active
    switch [$w cget -selectmode] {
	browse {
	    $w selection clear all
	    $w selection set active
	}
	extended {
	    $w selection clear all
	    $w selection set active
	    $w selection anchor active
	    set tkPriv(tablePrev) [$w index active]
	}
    }
}

# tkTableExtendSelect --
#
# Does nothing unless we're in extended selection mode; in this
# case it moves the location cursor (active element) by the specified
# number of cells, and extends the selection to that point.
#
# Arguments:
# w - The table widget.
# x - +1 to move down one cell, -1 to move up one cell.
# y - +1 to move right one cell, -1 to move left one cell.

proc tkTableExtendSelect {w x y} {
    if {[string compare extended [$w cget -selectmode]] ||
	[catch {$w index active row} r]} return
    set c [$w index active col]
    $w activate [incr r $x],[incr c $y]
    $w see active
    tkTableMotion $w [$w index active]
}

# tkTableDataExtend
#
# This procedure is called for key-presses such as Shift-KEndData.
# If the selection mode isnt multiple or extend then it does nothing.
# Otherwise it moves the active element to el and, if we're in
# extended mode, extends the selection to that point.
#
# Arguments:
# w - The table widget.
# el - An integer cell number.

proc tkTableDataExtend {w el} {
    set mode [$w cget -selectmode]
    if {[string match extended $mode]} {
	$w activate $el
	$w see $el
	if [$w selection includes anchor] {tkTableMotion $w $el}
    } elseif {[string match multiple $mode]} {
	$w activate $el
	$w see $el
    }
}

# tkTableSelectAll
#
# This procedure is invoked to handle the "select all" operation.
# For single and browse mode, it just selects the active element.
# Otherwise it selects everything in the widget.
#
# Arguments:
# w - The table widget.

proc tkTableSelectAll {w} {
    if {[regexp {^(single|browse)$} [$w cget -selectmode]]} {
	$w selection clear all
	$w selection set active
	tkTableHandleType $w [$w index active]
    } else {
	$w selection set origin end
    }
}

# tkTableChangeWidth --
# Adjust the widget of the specified cell by $a.
#
# Arguments:
# w - The table widget.
# i - cell index
# a - amount to adjust by

proc tkTableChangeWidth {w i a} {
    set tmp [$w index $i col]
    if {[set width [$w width $tmp]] >= 0} {
	$w width $tmp [incr width $a]
    } else {
	$w width $tmp [incr width -$a]
    }
}

# tk_tableCopy --
# This procedure copies the selection from a table widget into the
# clipboard.
#
# Arguments:
# w -		Name of a table widget.

proc tk_tableCopy w {
    if {[selection own -displayof $w] == "$w"} {
	clipboard clear -displayof $w
	catch {clipboard append -displayof $w [selection get -displayof $w]}
    }
}

# tk_tableCut --
# This procedure copies the selection from a table widget into the
# clipboard, then deletes the selection (if it exists in the given
# widget).
#
# Arguments:
# w -		Name of a table widget.

proc tk_tableCut w {
    if {[selection own -displayof $w] == "$w"} {
	clipboard clear -displayof $w
	catch {
	    clipboard append -displayof $w [selection get -displayof $w]
	    $w cursel set {}
	    $w selection clear all
	}
    }
}

# tk_tablePaste --
# This procedure pastes the contents of the clipboard to the specified
# cell (active by default) in a table widget.
#
# Arguments:
# w -		Name of a table widget.
# cell -	Cell to start pasting in.

proc tk_tablePaste {w {cell {}}} {
    if {[string compare {} $cell]} {
	if {[catch {selection get -displayof $w} data]} return
    } else {
	if {[catch {selection get -displayof $w -selection CLIPBOARD} data]} {
	    return
	}
	set cell active
    }
    tk_tablePasteHandler $w [$w index $cell] $data
    if {[$w cget -state] == "normal"} {focus $w}
}

# tk_tablePasteHandler --
# This procedure handles how data is pasted into the table widget.
# This handles data in the default table selection form.
# NOTE: this allows pasting into all cells, even those with -state disabled
#
# Arguments:
# w -		Name of a table widget.
# cell -	Cell to start pasting in.

proc tk_tablePasteHandler {w cell data} {
    set rows	[expr {[$w cget -rows]-[$w cget -roworigin]}]
    set cols	[expr {[$w cget -cols]-[$w cget -colorigin]}]
    set r	[$w index $cell row]
    set c	[$w index $cell col]
    set rsep	[$w cget -rowseparator]
    set csep	[$w cget -colseparator]
    ## Assume separate rows are split by row separator if specified
    ## If you were to want multi-character row separators, you would need:
    # regsub -all $rsep $data <newline> data
    # set data [join $data <newline>]
    if {[string comp {} $rsep]} { set data [split $data $rsep] }
    set row	$r
    foreach line $data {
	if {$row > $rows} break
	set col	$c
	## Assume separate cols are split by col separator if specified
	## Unless a -separator was specified
	if {[string comp {} $csep]} { set line [split $line $csep] }
	## If you were to want multi-character col separators, you would need:
	# regsub -all $csep $line <newline> line
	# set line [join $line <newline>]
	foreach item $line {
	    if {$col > $cols} break
	    $w set $row,$col $item
	    incr col
	}
	incr row
    }
}
