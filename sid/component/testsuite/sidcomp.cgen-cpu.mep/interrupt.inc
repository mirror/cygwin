
	.equ	INTC_IVR,	0x0000
	.equ	INTC_ISR,	0x0001
	.equ	INTC_IER,	0x0002
	.equ	INTC_IET,	0x0003
	.equ	INTC_ILR0,	0x0004
	.equ	INTC_ILR1,	0x0005
	.equ	INTC_ILR2,	0x0006
	.equ	INTC_ILR3,	0x0007

	.macro clear_bit n reg
	mov $0, \n
	mov $1,0x1
	sll $1,$0
	mov $0,0x0
	nor $1,$0
	and \reg, $1	
	.endm

	.macro set_bit n reg
	mov $0, \n
	mov $1,0x1
	sll $1,$0
	or \reg, $1
	.endm
		
	.macro clear_bit_on_control_bus bit addr
	ldcb $3, \addr
	clear_bit \bit, $3
	stcb $3, \addr
	.endm

	.macro set_bit_on_control_bus bit addr
	ldcb $3,\addr
	set_bit \bit $3
	stcb $3,\addr
	.endm

	.macro set_interrupt_mask_level lev
	mov $1, \lev
	mov $0, 0x8
	sll $1, $0
	stcb $1, INTC_IVR
	.endm

	.macro save_label_to_reg lab reg
	movh \reg, (0xFFFF & (\lab >> 16))
	movu $3, (0xFFFF & \lab)
	or \reg, $3
	.endm
	
	.macro enable_interrupt_channel chan
	set_bit_on_control_bus \chan INTC_IER
	.endm

	.macro disable_interrupt_channel chan
	clear_bit_on_control_bus \chan INTC_IER
	.endm

	.macro set_level_triggered chan
	clear_bit_on_control_bus \chan INTC_IET
	.endm

	.macro set_edge_triggered chan
	set_bit_on_control_bus \chan INTC_IET
	.endm	
		
	.macro enable_hie
	ldc $3, $psw
	set_bit 8, $3
	stc $3, $psw
	.endm
	
	.macro disable_hie
	ldc $3, $psw
	clear_bit 8, $3
	stc $3, $psw
	.endm

	.macro set_umc
	ldc $3, $psw
	set_bit 2, $3
	stc $3, $psw
	.endm
	
	.macro signal_interrupt_handled chan=0
	ldcb $0, INTC_ISR
	clear_bit \chan, $0
	stcb $0, INTC_ISR
	nop
	nop
	nop
	.endm

	.macro check_interrupt_entry_from epc
	ldc $13, $epc
	assert $13 \epc
	ldc $13, $psw
	assert $13 0x10a
	ldc $13, $exc
	assert $13 0x100
	.endm

	.macro set_interrupt_priority chan prio
	ldcb $1, (INTC_ILR0 + (\chan / 8))
	mov $2, \prio
	mov $3, 0xF
	sll $2, (\chan * 4)
	sll $3, (\chan * 4)
	and $2, $3	
	mov $0,0x0
	nor $3,$0
	and $1, $3		
	or $1, $2
	stcb $1, (INTC_ILR0 + (\chan / 8))
	.endm
			
	.macro raise_hw_interrupt chan=0
	mov $1, 0x1
	stcb $1, (0x2000 + \chan)
	.endm

	.macro cancel_hw_interrupt chan=0
	mov $1, 0x0
	stcb $1, (0x2000 + \chan)
	.endm

	.macro load_ILV reg
	ldcb \reg, INTC_IVR
	srl \reg, 12
	mov $3, 0xF
	and \reg, $3
	.endm

	.macro load_ICN reg
	ldcb \reg, INTC_IVR
	mov $3, 0xFF
	and \reg, $3
	srl \reg, 3
	.endm
	
	.macro standard_interrupt_vectors

EntryNMI:	# Non Maskble Interrupt
	mov	$13,0xe2
	jmp	wrong

EntryRI:	# Exepttion of Reserved Instruction
	mov	$13,0xe2
	jmp	wrong

EntryZDIV:
	mov	$13,0xe3
	jmp	wrong

EntryBRK:
	mov	$13,0xe4
	jmp	wrong
EntrySWI:
	mov	$13,0xe5
	jmp	wrong

	.section .vec, "ax"

	.org 0x00000004, 0
	jmp EntryNMI

	.org 0x00000008, 0
	jmp EntryRI

	.org 0x0000000c, 0
	jmp EntryZDIV

	.org 0x00000010, 0
	jmp EntryBRK

	.org 0x00000014, 0
	jmp EntrySWI

.org 0x00000030, 0      # 0x00200030 + n*4(EVM=IVM=1, EVA=IVA=0)
	jmp	EntryINT00
	jmp	EntryINT01
	jmp	EntryINT02
	jmp	EntryINT03
	jmp	EntryINT04
	jmp	EntryINT05
	jmp	EntryINT06
	jmp	EntryINT07
	jmp	EntryINT08
	jmp	EntryINT09
	jmp	EntryINT10
	jmp	EntryINT11
	jmp	EntryINT12
	jmp	EntryINT13
	jmp	EntryINT14
	jmp	EntryINT15
	jmp	EntryINT16
	jmp	EntryINT17
	jmp	EntryINT18
	jmp	EntryINT19
	jmp	EntryINT20
	jmp	EntryINT21
	jmp	EntryINT22
	jmp	EntryINT23
	jmp	EntryINT24
	jmp	EntryINT25
	jmp	EntryINT26
	jmp	EntryINT27
	jmp	EntryINT28
	jmp	EntryINT29
	jmp	EntryINT30
	jmp	EntryINT31
	.endm

	