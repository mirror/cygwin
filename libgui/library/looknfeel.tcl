# looknfeel.tcl - Standard look and feel decisions.
# Copyright (C) 1997 Cygnus Solutions.
# Written by Tom Tromey <tromey@cygnus.com>.

# Run this once just after Tk is initialized.  It will do whatever
# setup is required to make the application conform to our look and
# feel.
proc standard_look_and_feel {} {
  global tcl_platform

  # FIXME: this is really gross: we know how tk_dialog chooses its
  # -wraplength, and we make it bigger.  Instead we should make our
  # own dialog function.
  option add *Dialog.msg.wrapLength 0 startupFile

  # We don't ever want tearoffs.
  option add *Menu.tearOff 0 startupFile

  # The default font should be used by default.
  # The bold font is like the default font, but is bold; use it for
  # emphasis.
  # The fixed font is guaranteed not to be proportional.
  # The status font should be used in status bars and tooltips.
  if {$tcl_platform(platform) == "windows"} then {
    define_font global/default -family windows-message
    # FIXME: this isn't actually a bold font...
    define_font global/bold -family windows-caption
    define_font global/fixed -family fixedsys
    define_font global/status -family windows-status
    # FIXME: we'd like this font to update automatically as well.  But
    # for now we can't.
    array set actual [font actual windows-message]
    set actual(-slant) italic
    eval define_font global/italic [array get actual]
    define_font global/menu -family windows-menu
  } else {
    define_font global/default -family courier -size 9
    define_font global/bold -family courier -size 9 -weight bold
    define_font global/fixed -family courier -size 9
    define_font global/status -family courier -size 9
    define_font global/italic -family courier -size 9 -slant italic
    define_font global/menu -family courier -size 9
  }

  # Make sure this font is actually used by default.
  option add *Font global/default
  option add *Menu.Font global/menu
}
