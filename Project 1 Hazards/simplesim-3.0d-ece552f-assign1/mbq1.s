	.file	1 "mbq1.c"

 # GNU C 2.7.2.3 [AL 1.1, MM 40, tma 0.1] SimpleScalar running sstrix compiled by GNU C

 # Cc1 defaults:
 # -mgas -mgpOPT

 # Cc1 arguments (-G value = 8, Cpu = default, ISA = 1):
 # -quiet -dumpbase -O2 -o

gcc2_compiled.:
__gnu_compiled_c:
	.rdata
	.align	2
$LC0:
	.ascii	"temp is: %d\000"
	.align	2
$LC1:
	.ascii	"sum is: %d\000"
	.align	2
$LC2:
	.ascii	"q1 is: %d\000"
	.align	2
$LC3:
	.ascii	"q2 is: %d\000"
	.text
	.align	2
	.globl	main

	.extern	stdin, 4
	.extern	stdout, 4

	.text

	.loc	1 4
	.ent	main
main:
	.frame	$sp,32,$31		# vars= 0, regs= 4/0, args= 16, extra= 0
	.mask	0x80070000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$18,24($sp)
	sw	$17,20($sp)
	sw	$16,16($sp)
	jal	__main
	move	$17,$0
	move	$18,$0
	move	$5,$0
	move	$16,$0
	li	$2,0x0000270f		# 9999
$L25:
	addu	$17,$17,2
	addu	$18,$18,$17
	addu	$5,$5,4
	addu	$16,$16,$18
	addu	$16,$16,$5
	subu	$2,$2,1
	bgez	$2,$L25
	la	$4,$LC0
	jal	printf
	la	$4,$LC1
	move	$5,$16
	jal	printf
	la	$4,$LC2
	move	$5,$17
	jal	printf
	la	$4,$LC3
	move	$5,$18
	jal	printf
	move	$2,$0
	lw	$31,28($sp)
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	addu	$sp,$sp,32
	j	$31
	.end	main
