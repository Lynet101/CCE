	.file	"seconds_advanced.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"please enter the amount of seconds to convert: "
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"Error: Invalid input. Please enter a valid positive integer."
	.align 8
.LC3:
	.string	"Weeks: %d\nDays: %d\nHours: %d\nMinutes: %d\nSeconds: %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	cmpl	$1, %eax
	jne	.L2
	movl	-4(%rbp), %eax
	testl	%eax, %eax
	jns	.L3
.L2:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %eax
	jmp	.L5
.L3:
	movl	-4(%rbp), %eax
	leaq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	converter
	movl	-16(%rbp), %edi
	movl	-20(%rbp), %esi
	movl	-24(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-32(%rbp), %eax
	movl	%edi, %r9d
	movl	%esi, %r8d
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	converter
	.type	converter, @function
converter:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1861606989, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$18, %edx
	sarl	$31, %eax
	subl	%eax, %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1861606989, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$18, %ecx
	cltd
	subl	%edx, %ecx
	imull	$604800, %ecx, %edx
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	movq	-16(%rbp), %rax
	leaq	4(%rax), %rdx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	imulq	$-1037155065, %rcx, %rcx
	shrq	$32, %rcx
	addl	%eax, %ecx
	movl	%ecx, %esi
	sarl	$16, %esi
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%esi, %eax
	subl	%ecx, %eax
	movl	%eax, (%rdx)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$-1037155065, %rdx, %rdx
	shrq	$32, %rdx
	addl	%eax, %edx
	movl	%edx, %ecx
	sarl	$16, %ecx
	cltd
	subl	%edx, %ecx
	imull	$86400, %ecx, %edx
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	movq	-16(%rbp), %rax
	leaq	8(%rax), %rdx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	imulq	$-1851608123, %rcx, %rcx
	shrq	$32, %rcx
	addl	%eax, %ecx
	movl	%ecx, %esi
	sarl	$11, %esi
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%esi, %eax
	subl	%ecx, %eax
	movl	%eax, (%rdx)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$-1851608123, %rdx, %rdx
	shrq	$32, %rdx
	addl	%eax, %edx
	movl	%edx, %ecx
	sarl	$11, %ecx
	cltd
	subl	%edx, %ecx
	imull	$3600, %ecx, %edx
	subl	%edx, %eax
	movl	%eax, -4(%rbp)
	movq	-16(%rbp), %rax
	leaq	12(%rax), %rdx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	imulq	$-2004318071, %rcx, %rcx
	shrq	$32, %rcx
	addl	%eax, %ecx
	movl	%ecx, %esi
	sarl	$5, %esi
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%esi, %eax
	subl	%ecx, %eax
	movl	%eax, (%rdx)
	movq	-16(%rbp), %rax
	leaq	16(%rax), %rsi
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$-2004318071, %rdx, %rdx
	shrq	$32, %rdx
	addl	%eax, %edx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$60, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, (%rsi)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	converter, .-converter
	.ident	"GCC: (GNU) 14.2.1 20240912 (Red Hat 14.2.1-3)"
	.section	.note.GNU-stack,"",@progbits
