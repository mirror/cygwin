# configfile(): interrupt-1s.conf
# mach: all
# ld: -Tdata 0

	.include "testutils.inc"
.data
.org 0x30
	.global vector
vector:
	pass

	start
enable:
	# enable hardware interrupts
        ldc $0, $psw
        or3 $0, $0, 0x100
        stc $0, $psw
	ei

forever:
	bra 0
	fail
