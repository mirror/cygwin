# treetable.tcl - some treetable bindings; from S-N.
# Copyright (C) 1997 Cygnus Solutions.

proc multix_treetable_bindings {t} {
  # The keybindings to the treetable are compatible with those of
  # listbox.
  bind $t <1> {
    if [winfo exists %W] {
      tkListboxBeginSelect %W [%W index @%x,%y]
    }
  }

  bind $t <B1-Motion> {
    set tkPriv(x) %x
    set tkPriv(y) %y
    tkListboxMotion %W [%W index @%x,%y]
  }
  bind $t <ButtonRelease-1> {
    tkCancelRepeat
    %W activate @%x,%y
  }
  bind $t <Shift-1> {
    tkListboxBeginExtend %W [%W index @%x,%y]
  }
  bind $t <Control-1> {
    tkListboxBeginToggle %W [%W index @%x,%y]
  }
  bind $t <B1-Leave> {
    set tkPriv(x) %x
    set tkPriv(y) %y
    tkListboxAutoScan %W
  }
  bind $t <B1-Enter> {
    tkCancelRepeat
  }

  bind $t <Up> {
    tkListboxUpDown %W -1
  }
  bind $t <Shift-Up> {
    tkListboxExtendUpDown %W -1
  }
  bind $t <Down> {
    tkListboxUpDown %W 1
  }
  bind $t <Shift-Down> {
    tkListboxExtendUpDown %W 1
  }
  bind $t <Left> {
    %W xview scroll -1 units
  }
  bind $t <Control-Left> {
    %W xview scroll -1 pages
  }
  bind $t <Right> {
    %W xview scroll 1 units
  }
  bind $t <Control-Right> {
    %W xview scroll 1 pages
  }
  bind $t <Prior> {
    %W yview scroll -1 pages
    %W activate @0,0
  }
  bind $t <Next> {
    %W yview scroll 1 pages
    %W activate @0,0
  }
  bind $t <Control-Prior> {
    %W xview scroll -1 pages
  }
  bind $t <Control-Next> {
    %W xview scroll 1 pages
  }
  bind $t <Home> {
    %W xview moveto 0
  }
  bind $t <End> {
    %W xview moveto 1
  }
  bind $t <Control-Home> {
    %W activate 0
    %W see 0
    %W selection clear 0 end
    %W selection set 0
  }
  bind $t <Shift-Control-Home> {
    tkListboxDataExtend %W 0
  }
  bind $t <Control-End> {
    %W activate end
    %W see end
    %W selection clear 0 end
    %W selection set end
  }
  bind $t <Shift-Control-End> {
    tkListboxDataExtend %W end
  }
  bind $t <F16> {
    if {[selection own -displayof %W] == "%W"} {
      clipboard clear -displayof %W
      clipboard append -displayof %W [selection get -displayof %W]
    }
  }
  bind $t <space> {
    tkListboxBeginSelect %W [%W index active]
  }
  bind $t <Select> {
    tkListboxBeginSelect %W [%W index active]
  }
  bind $t <Control-Shift-space> {
    tkListboxBeginExtend %W [%W index active]
  }
  bind $t <Shift-Select> {
    tkListboxBeginExtend %W [%W index active]
  }
  bind $t <Escape> {
    tkListboxCancel %W
  }
  bind $t <Control-slash> {
    tkListboxSelectAll %W
  }
  bind $t <Control-backslash> {
    if {[%W cget -selectmode] != "browse"} {
      %W selection clear 0 end
    }
  }

  bind $t <3> {
    %W scan mark %x %y
  }
  bind $t <B3-Motion> {
    %W scan dragto %x %y
  }
  
  # Explicitly exclude traversal keys.
  bind $t <Tab> {;}
  bind $t <Shift-Tab> {;}

  # Other bindings added to default listbox bindings.
  bind $t <KeyPress> {multix_tree_table_search_region %W %A}
  bind $t <Any-F27> 		[bind $t <Home>]; # Sun Home
  bind $t <Any-R13> 		[bind $t <End>]; # Sun End
  bind $t <Any-R15> 		[bind $t <Next>]; # Sun Next
  bind $t <Any-R9> 		[bind $t <Prior>]; # Sun Prior
}

proc multix_tree_table_search_in_widget {w a beg {end end}} {
  if {[$w size] > 20000} {
    $w config -cursor watch
    update idletasks
  }
  set res [$w search -nocase -begins $a $beg $end]
  $w config -cursor {}
  if {$res == ""} {
    return -1
  }
  $w activate $res
  return $res
}

proc multix_tree_table_search_region {w a} {
  if {[string compare $a ""] == 0} {
    return
  }

  upvar #0 $w-pat pat

  append pat $a
  set srch $pat
  set off [$w index active]
  if {[string compare $off ""] == 0} {
    set sel 0
  } else {
    set sel [expr $off + 1]
  }
  # Search from the selection!
  set off [multix_tree_table_search_in_widget $w $srch $sel]

  if {$off == -1 && $sel != 0} {
    # 	Search until the selection!
    set off [multix_tree_table_search_in_widget $w $srch 0 $sel]
  }
  if {$off == -1} {
    if {[string length $pat] > 1} {
      set pat $a
      set srch $pat

      # Search from the selection!
      set off [multix_tree_table_search_in_widget $w $srch $sel]
      if {$off == -1} {
	# 	Search until the selection!
	set off [multix_tree_table_search_in_widget $w $srch 0 $sel]
      }
    }
    if {$off == -1} {
      set pat ""
      bell -displayof $w
      $w selection clear 0 end
      return
    }
  }
  $w activate $off
  $w activate $off
  $w yview see $off
}
