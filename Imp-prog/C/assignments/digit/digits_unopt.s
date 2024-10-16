	.file	"digits.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"from 0 to %d, %d numbers have %d present at least once\n"
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
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	call	getchar
	nop
.L2:
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	input
	cmpl	$-1, %eax
	je	.L3
	movl	$0, -8(%rbp)
	jmp	.L4
.L9:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L5
.L8:
	movl	-12(%rbp), %ecx
	movslq	%ecx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	-16(%rbp), %eax
	cmpl	%eax, %edx
	jne	.L6
	addl	$1, -4(%rbp)
	jmp	.L7
.L6:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$2, %ecx
	cltd
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, -12(%rbp)
.L5:
	cmpl	$0, -12(%rbp)
	jg	.L8
.L7:
	addl	$1, -8(%rbp)
.L4:
	movl	-20(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jle	.L9
	movl	-16(%rbp), %ecx
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %edx
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC1:
	.string	"Enter a number (n): "
.LC2:
	.string	"%d"
	.align 8
.LC3:
	.string	"Invalid input. Please enter a valid positive integer for n"
.LC4:
	.string	"Enter a digit (c): "
	.align 8
.LC5:
	.string	"Invalid input. Please enter a positive integer between 0 and 9"
	.text
	.globl	input
	.type	input, @function
input:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	cmpl	$1, %eax
	jne	.L12
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jns	.L13
.L12:
	movl	$.LC3, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L14
.L13:
	call	getchar
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	cmpl	$1, %eax
	jne	.L15
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	js	.L15
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$9, %eax
	jle	.L16
.L15:
	movl	$.LC5, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L14
.L16:
	movl	$0, %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	input, .-input
	.ident	"GCC: (GNU) 14.2.1 20240912 (Red Hat 14.2.1-3)"
	.section	.note.GNU-stack,"",@progbits
