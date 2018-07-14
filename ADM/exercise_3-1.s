	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_check_par              ## -- Begin function check_par
	.p2align	4, 0x90
_check_par:                             ## @check_par
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$1040, %rsp             ## imm = 0x410
	leaq	-1008(%rbp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rdi, -1024(%rbp)
	addq	$-1, %rax
	movq	%rax, -1032(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-1024(%rbp), %rax
	movsbl	(%rax), %ecx
	cmpl	$0, %ecx
	je	LBB0_8
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-1024(%rbp), %rax
	movsbl	(%rax), %ecx
	cmpl	$40, %ecx
	jne	LBB0_4
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-1032(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -1032(%rbp)
	jmp	LBB0_7
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	movq	-1024(%rbp), %rax
	movsbl	(%rax), %ecx
	cmpl	$41, %ecx
	jne	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	-1032(%rbp), %rax
	addq	$-1, %rax
	movq	%rax, -1032(%rbp)
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_7
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	movq	-1024(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -1024(%rbp)
	jmp	LBB0_1
LBB0_8:
	leaq	-1008(%rbp), %rax
	movq	-1032(%rbp), %rcx
	addq	$-1, %rax
	cmpq	%rax, %rcx
	jne	LBB0_10
## BB#9:
	movl	$1, -1012(%rbp)
	jmp	LBB0_11
LBB0_10:
	movl	$0, -1012(%rbp)
LBB0_11:
	movl	-1012(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -1036(%rbp)       ## 4-byte Spill
	jne	LBB0_13
## BB#12:
	movl	-1036(%rbp), %eax       ## 4-byte Reload
	addq	$1040, %rsp             ## imm = 0x410
	popq	%rbp
	retq
LBB0_13:
	callq	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	L_.str.1(%rip), %rdi
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.4(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.6(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.7(%rip), %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.8(%rip), %rdi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.9(%rip), %rdi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	$32, %edi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_putchar
	leaq	L_.str.10(%rip), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	callq	_check_par
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"()"

L_.str.2:                               ## @.str.2
	.asciz	"((())())()"

L_.str.3:                               ## @.str.3
	.space	1

L_.str.4:                               ## @.str.4
	.asciz	"((("

L_.str.5:                               ## @.str.5
	.asciz	"((())"

L_.str.6:                               ## @.str.6
	.asciz	"((()))"

L_.str.7:                               ## @.str.7
	.asciz	"(((())))(())(((())))()"

L_.str.8:                               ## @.str.8
	.asciz	"7 + (6 \303\227 25 + 3)"

L_.str.9:                               ## @.str.9
	.asciz	"(x^2+y^2)(x+v)"

L_.str.10:                              ## @.str.10
	.asciz	"[(2x+1)+(2a+1)][(3x-1)+(3a-1)]"


.subsections_via_symbols
