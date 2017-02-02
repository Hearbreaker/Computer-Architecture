	.file	"mb.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"temp is: %d"
.LC1:
	.string	"sum is : %d"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.section	.text.startup,"ax",@progbits
.LHOTB2:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	xorl	%esi, %esi
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	$1717986919, %edi
	jmp	.L4
	.p2align 4,,10
	.p2align 3
.L2:
	xorl	%esi, %esi
	cmpl	%eax, %ecx
	je	.L3
.L5:
	addl	$1, %ebx
	movl	$1, %esi
.L3:
	addl	$1, %ecx
	addl	$1, %ebx
	cmpl	$1000000, %ecx
	je	.L16
.L4:
	movl	%ecx, %eax
	imull	%edi
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	testb	$1, %cl
	je	.L2
	cmpl	%eax, %ecx
	je	.L6
	cmpl	$1, %esi
	je	.L5
	addl	$1, %ecx
	addl	$1, %ebx
	cmpl	$1000000, %ecx
	jne	.L4
.L16:
	movl	$.LC0, %edi
	xorl	%eax, %eax
	call	printf
	movl	%ebx, %esi
	movl	$.LC1, %edi
	xorl	%eax, %eax
	call	printf
	xorl	%eax, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	.cfi_restore_state
	xorl	%esi, %esi
	jmp	.L3
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE2:
	.section	.text.startup
.LHOTE2:
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
