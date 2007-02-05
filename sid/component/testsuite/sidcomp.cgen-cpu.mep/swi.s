# mep testcase for swi $imm2 -*- Asm -*-
# mach: all
# as:
# ld: -Tdata 0
# configfile(): mep-gloss.conf

	.include "testutils.inc"
	.macro enable_swi value
	ldc $0, $psw
	or3 $0, $0, (0x10 << \value) | 1
	stc $0, $psw
	.endm
	
	.macro clear_swis value
	ldc $0, $exc
	mov $1, -1
	srl $1, 4
	sll $1, 8
	or3 $1, $1, 0xf
	and $0, $1
	stc $0, $exc
	.endm

.data
.org 0x14
	.global vector
vector:
	clear_swis
	reti

	start
	.global swi
swi:
	enable_swi 0
	swi 0
	enable_swi 1
	swi 1
	enable_swi 2
	swi 2
	enable_swi 3
	swi 3

okay:
	pass
