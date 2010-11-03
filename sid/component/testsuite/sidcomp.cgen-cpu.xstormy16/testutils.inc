# Common testsuite parts for xstormy16-elf-sid.

	.macro start
	.text
	.global _start
_start:
	.endm

	.data

	.globl pass_str
	.globl fail_str
pass_str:
	.ascii "pass\n"
fail_str:
	.ascii "fail\n"

	.text

        .macro assert reg value
	mov r13, #\value
	bnz r13, \reg, wrong
	.endm

	.macro exit rc
	mov r1, #1	; exit syscall
	mov r2, #\rc	; exit(rc)
	.byte 0x01
	.byte 0x00
	.endm

	.macro pass
	mov     r1, #5	; write syscall
	mov     r2, #1	; write(fileno(stdout), "pass", 5)
	mov.w   r3, #pass_str
	mov     r4, #0
	mov     r5, #5  ; length
	.byte 0x01
	.byte 0x00
	exit 0
	.endm

	.macro fail
	mov     r1, #5	; write syscall
	mov     r2, #1	; write(fileno(stdout), "fail", 5)
	mov.w   r3, #fail_str
	mov     r4, #0
	mov     r5, #5  ; length
	.byte 0x01
	.byte 0x00
	exit 1
	.endm
