	.file	"Assign_5_solution_CPP.cpp"
	.text
	.p2align 4,,15
	.type	_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105, @function
_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105:
.LFB9147:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	-1(%rdx), %rax
	movq	%rdx, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rax, %rbx
	shrq	$63, %rbx
	addq	%rax, %rbx
	sarq	%rbx
	andl	$1, %ebp
	cmpq	%rbx, %rsi
	jge	.L2
	movq	%rsi, %r10
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L19:
	decq	%r8
	leaq	(%rdi,%r8,4), %r9
	movl	(%r9), %eax
	movl	%eax, (%rdi,%r10,4)
	cmpq	%r8, %rbx
	jle	.L5
.L6:
	movq	%r8, %r10
.L3:
	leaq	1(%r10), %rax
	leaq	(%rax,%rax), %r8
	salq	$3, %rax
	leaq	(%rdi,%rax), %r9
	movl	(%r9), %r11d
	cmpl	%r11d, -4(%rdi,%rax)
	jg	.L19
	movl	%r11d, (%rdi,%r10,4)
	cmpq	%r8, %rbx
	jg	.L6
.L5:
	testq	%rbp, %rbp
	je	.L11
.L7:
	leaq	-1(%r8), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rax, %rdx
	sarq	%rdx
	cmpq	%rsi, %r8
	jle	.L8
	movl	(%rdi,%rdx,4), %r10d
	cmpl	%r10d, %ecx
	jg	.L9
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L10:
	movl	(%rdi,%rax,4), %r10d
	movq	%rdx, %r8
	movq	%rax, %rdx
	cmpl	%ecx, %r10d
	jge	.L8
.L9:
	movl	%r10d, (%rdi,%r8,4)
	leaq	-1(%rdx), %r8
	movq	%r8, %rax
	shrq	$63, %rax
	addq	%r8, %rax
	sarq	%rax
	leaq	(%rdi,%rdx,4), %r9
	cmpq	%rdx, %rsi
	jl	.L10
.L8:
	movl	%ecx, (%r9)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L2:
	.cfi_restore_state
	leaq	(%rdi,%rsi,4), %r9
	movq	%rsi, %r8
	testq	%rbp, %rbp
	jne	.L8
	.p2align 4,,10
	.p2align 3
.L11:
	subq	$2, %rdx
	movq	%rdx, %rax
	shrq	$63, %rax
	addq	%rdx, %rax
	sarq	%rax
	cmpq	%rax, %r8
	jne	.L7
	leaq	2(%r8,%r8), %r8
	movl	-4(%rdi,%r8,4), %eax
	decq	%r8
	movl	%eax, (%r9)
	leaq	(%rdi,%r8,4), %r9
	jmp	.L7
	.cfi_endproc
.LFE9147:
	.size	_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105, .-_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105
	.p2align 4,,15
	.type	_ZSt16__introsort_loopIPilN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92, @function
_ZSt16__introsort_loopIPilN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92:
.LFB9141:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rdx, %r14
	movq	%rsi, %rdx
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	subq	%rdi, %rdx
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	cmpq	$64, %rdx
	jle	.L45
	movq	%rdi, %rbx
	leaq	4(%rdi), %r12
	testq	%r14, %r14
	je	.L49
.L24:
	sarq	$3, %rdx
	leaq	(%rbx,%rdx,4), %r8
	movl	4(%rbx), %ecx
	movl	(%r8), %eax
	decq	%r14
	movl	-4(%rsi), %edi
	movl	(%rbx), %edx
	cmpl	%eax, %ecx
	jge	.L27
	cmpl	%edi, %eax
	jl	.L33
	cmpl	%edi, %ecx
	jl	.L47
.L48:
	movl	%ecx, (%rbx)
	movl	%edx, 4(%rbx)
	movl	-4(%rsi), %edx
.L29:
	movq	%r12, %rbp
	movq	%rsi, %rax
	.p2align 4,,10
	.p2align 3
.L32:
	movl	0(%rbp), %edi
	movq	%rbp, %r13
	cmpl	%ecx, %edi
	jl	.L34
	subq	$4, %rax
	cmpl	%edx, %ecx
	jge	.L35
	.p2align 4,,10
	.p2align 3
.L36:
	subq	$4, %rax
	movl	(%rax), %edx
	cmpl	%ecx, %edx
	jg	.L36
.L35:
	cmpq	%rax, %rbp
	jnb	.L50
	movl	%edx, 0(%rbp)
	movl	%edi, (%rax)
	movl	-4(%rax), %edx
	movl	(%rbx), %ecx
.L34:
	addq	$4, %rbp
	jmp	.L32
	.p2align 4,,10
	.p2align 3
.L27:
	cmpl	%edi, %ecx
	jl	.L48
	cmpl	%edi, %eax
	jge	.L33
.L47:
	movl	%edi, (%rbx)
	movl	%edx, -4(%rsi)
	movl	(%rbx), %ecx
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L50:
	movq	%r14, %rdx
	movq	%rbp, %rdi
	call	_ZSt16__introsort_loopIPilN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92
	movq	%rbp, %rdx
	subq	%rbx, %rdx
	cmpq	$64, %rdx
	jle	.L45
	movq	%rbp, %rsi
	testq	%r14, %r14
	jne	.L24
.L22:
	sarq	$2, %rdx
	leaq	-2(%rdx), %r12
	sarq	%r12
	movl	(%rbx,%r12,4), %ecx
	movq	%r12, %rsi
	movq	%rbx, %rdi
	movq	%rdx, %rbp
	call	_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105
.L25:
	decq	%r12
	movl	(%rbx,%r12,4), %ecx
	movq	%rbp, %rdx
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105
	testq	%r12, %r12
	jne	.L25
	.p2align 4,,10
	.p2align 3
.L26:
	subq	$4, %r13
	movl	(%rbx), %eax
	movq	%r13, %rbp
	subq	%rbx, %rbp
	movl	0(%r13), %ecx
	movl	%eax, 0(%r13)
	movq	%rbp, %rdx
	sarq	$2, %rdx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	call	_ZSt13__adjust_heapIPiliN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.105
	cmpq	$4, %rbp
	jg	.L26
.L45:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L33:
	.cfi_restore_state
	movl	%eax, (%rbx)
	movl	%edx, (%r8)
	movl	(%rbx), %ecx
	movl	-4(%rsi), %edx
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L49:
	movq	%rsi, %r13
	jmp	.L22
	.cfi_endproc
.LFE9141:
	.size	_ZSt16__introsort_loopIPilN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92, .-_ZSt16__introsort_loopIPilN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92
	.p2align 4,,15
	.globl	_Z12getByteIndexi
	.type	_Z12getByteIndexi, @function
_Z12getByteIndexi:
.LFB8213:
	.cfi_startproc
	movl	%edi, %eax
	sarl	$3, %eax
	ret
	.cfi_endproc
.LFE8213:
	.size	_Z12getByteIndexi, .-_Z12getByteIndexi
	.p2align 4,,15
	.globl	_Z11getBitIndexi
	.type	_Z11getBitIndexi, @function
_Z11getBitIndexi:
.LFB8214:
	.cfi_startproc
	movl	%edi, %eax
	andl	$7, %eax
	ret
	.cfi_endproc
.LFE8214:
	.size	_Z11getBitIndexi, .-_Z11getBitIndexi
	.p2align 4,,15
	.globl	_Z18BoolArrayTrueCountR12bitArraySlim
	.type	_Z18BoolArrayTrueCountR12bitArraySlim, @function
_Z18BoolArrayTrueCountR12bitArraySlim:
.LFB8258:
	.cfi_startproc
	movq	(%rdi), %r8
	movl	12(%rdi), %edi
	xorl	%edx, %edx
	leal	-64(%rdi), %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	jle	.L69
	.p2align 4,,10
	.p2align 3
.L54:
	movl	%edx, %ecx
	sarl	$6, %ecx
	movslq	%ecx, %rcx
	addl	$64, %edx
	popcntq	(%r8,%rcx,8), %rcx
	addl	%ecx, %eax
	cmpl	%esi, %edx
	jl	.L54
	leal	-65(%rdi), %edx
	andl	$-64, %edx
	leal	64(%rdx), %ecx
.L57:
	leal	-32(%rdi), %r9d
	movl	%ecx, %edx
	cmpl	%ecx, %r9d
	jle	.L56
	.p2align 4,,10
	.p2align 3
.L55:
	movl	%edx, %esi
	sarl	$5, %esi
	movslq	%esi, %rsi
	movl	(%r8,%rsi,4), %esi
	addl	$32, %edx
	popcntq	%rsi, %rsi
	addl	%esi, %eax
	cmpl	%r9d, %edx
	jl	.L55
	leal	-33(%rdi), %edx
	subl	%ecx, %edx
	andl	$-32, %edx
	leal	32(%rcx,%rdx), %ecx
.L56:
	cmpl	%ecx, %edi
	jle	.L70
	.p2align 4,,10
	.p2align 3
.L58:
	movl	%ecx, %edx
	sarl	$3, %edx
	movslq	%edx, %rdx
	movl	%ecx, %esi
	movzbl	(%r8,%rdx), %edx
	andl	$7, %esi
	sarx	%esi, %edx, %edx
	incl	%ecx
	andl	$1, %edx
	addl	%edx, %eax
	cmpl	%edi, %ecx
	jne	.L58
	ret
	.p2align 4,,10
	.p2align 3
.L69:
	xorl	%ecx, %ecx
	jmp	.L57
	.p2align 4,,10
	.p2align 3
.L70:
	ret
	.cfi_endproc
.LFE8258:
	.size	_Z18BoolArrayTrueCountR12bitArraySlim, .-_Z18BoolArrayTrueCountR12bitArraySlim
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z17CreatePartialSums4spanIiER12bitArraySlim
	.type	_Z17CreatePartialSums4spanIiER12bitArraySlim, @function
_Z17CreatePartialSums4spanIiER12bitArraySlim:
.LFB8275:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA8275
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	movq	%rdx, %r14
	pushq	%r13
	.cfi_offset 13, -40
	movq	%rdi, %r13
	pushq	%r12
	.cfi_offset 12, -48
	movq	%rsi, %r12
	pushq	%rbx
	andq	$-32, %rsp
	.cfi_offset 3, -56
	movl	12(%rdx), %r15d
	testl	%esi, %esi
	jle	.L72
	leal	-1(%rsi), %eax
	cmpl	$6, %eax
	jbe	.L97
	movl	%esi, %edx
	shrl	$3, %edx
	salq	$5, %rdx
	movq	%rdi, %rax
	addq	%rdi, %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	.p2align 4,,10
	.p2align 3
.L75:
	vpaddd	(%rax), %ymm0, %ymm0
	addq	$32, %rax
	cmpq	%rax, %rdx
	jne	.L75
	vextracti128	$1, %ymm0, %xmm1
	vpaddd	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vmovd	%xmm0, %eax
	addl	%eax, %r15d
	movl	%r12d, %eax
	andl	$-8, %eax
	cmpl	%r12d, %eax
	je	.L110
	vzeroupper
.L73:
	movslq	%eax, %rdx
	addl	0(%r13,%rdx,4), %r15d
	leal	1(%rax), %edx
	cmpl	%r12d, %edx
	jge	.L72
	movslq	%edx, %rdx
	addl	0(%r13,%rdx,4), %r15d
	leal	2(%rax), %edx
	cmpl	%edx, %r12d
	jle	.L72
	movslq	%edx, %rdx
	addl	0(%r13,%rdx,4), %r15d
	leal	3(%rax), %edx
	cmpl	%edx, %r12d
	jle	.L72
	movslq	%edx, %rdx
	addl	0(%r13,%rdx,4), %r15d
	leal	4(%rax), %edx
	cmpl	%edx, %r12d
	jle	.L72
	movslq	%edx, %rdx
	addl	0(%r13,%rdx,4), %r15d
	leal	5(%rax), %edx
	cmpl	%edx, %r12d
	jle	.L72
	movslq	%edx, %rdx
	addl	$6, %eax
	addl	0(%r13,%rdx,4), %r15d
	cmpl	%eax, %r12d
	jle	.L72
	cltq
	addl	0(%r13,%rax,4), %r15d
.L72:
	movl	$16, %edi
.LEHB0:
	call	_Znwm
.LEHE0:
	movl	%r15d, 12(%rax)
	testl	%r15d, %r15d
	movq	%rax, %rbx
	leal	7(%r15), %eax
	cmovs	%eax, %r15d
	sarl	$3, %r15d
	incl	%r15d
	movl	%r15d, 8(%rbx)
	movslq	%r15d, %r15
	movq	%r15, %rdi
.LEHB1:
	call	_Znam
.LEHE1:
	movq	%rax, %rcx
	movq	%r15, %rax
	decq	%rax
	js	.L80
	leaq	-2(%r15), %rax
	cmpq	$-1, %rax
	movl	$1, %edx
	cmovge	%r15, %rdx
	movq	%rcx, %rdi
	xorl	%esi, %esi
	call	memset
	movq	%rax, %rcx
.L80:
	movl	8(%r14), %eax
	movq	%rcx, (%rbx)
	testl	%eax, %eax
	jne	.L111
.L79:
	movl	12(%r14), %r9d
	decl	%r9d
	testl	%r12d, %r12d
	jle	.L107
	leal	-1(%r12), %eax
	movq	%r13, %r8
	leaq	4(%r13,%rax,4), %r10
	movl	$8, %r11d
	.p2align 4,,10
	.p2align 3
.L95:
	movl	(%r8), %ecx
	cmpl	$511, %r9d
	jle	.L82
	leal	-256(%r9), %edx
	leal	(%rcx,%rdx), %eax
	movl	%edx, %r12d
	movl	%edx, %edi
	movl	%eax, %esi
	movq	(%rbx), %r13
	andl	$7, %r12d
	sarl	$3, %edi
	sarl	$3, %eax
	movslq	%edi, %rdi
	cltq
	andl	$7, %esi
	movl	%r12d, %r14d
	leaq	1(%r13,%rdi), %rcx
	leaq	1(%r13,%rax), %rax
	subl	%esi, %r14d
	je	.L83
	js	.L84
	cmpl	$7, %r14d
	jg	.L84
	movl	%r11d, %edi
	vlddqu	(%rcx), %ymm0
	vlddqu	1(%rcx), %ymm1
	subl	%r14d, %edi
	vmovq	%rdi, %xmm5
	vmovd	%r14d, %xmm3
	vpsllw	%xmm5, %ymm1, %ymm1
	vpsrlw	%xmm3, %ymm0, %ymm0
	vpor	%ymm1, %ymm0, %ymm0
	jmp	.L89
	.p2align 4,,10
	.p2align 3
.L100:
	movl	%esi, %edx
.L89:
	subq	$31, %rcx
	vlddqu	(%rcx), %ymm2
	vlddqu	1(%rcx), %ymm1
	vlddqu	(%rax), %ymm4
	vpsllw	%xmm5, %ymm1, %ymm1
	vpsrlw	%xmm3, %ymm2, %ymm2
	vpor	%ymm4, %ymm0, %ymm0
	leal	-248(%rdx), %esi
	vmovdqu	%ymm0, (%rax)
	subq	$31, %rax
	vpor	%ymm1, %ymm2, %ymm0
	cmpl	$255, %esi
	jg	.L100
.L109:
	vlddqu	(%rax), %ymm1
	vpor	%ymm1, %ymm0, %ymm0
	vmovdqu	%ymm0, (%rax)
	leal	-496(%rdx), %eax
.L87:
	movl	(%r8), %ecx
	addl	$256, %eax
.L90:
	movl	%eax, %edx
	movq	(%rbx), %rsi
	sarl	$3, %edx
	addl	%eax, %ecx
	movslq	%edx, %rdx
	movl	%ecx, %edi
	movzbl	(%rsi,%rdx), %edx
	movl	%eax, %r12d
	sarl	$3, %edi
	andl	$7, %r12d
	movslq	%edi, %rdi
	sarx	%r12d, %edx, %edx
	andl	$7, %ecx
	andl	$1, %edx
	decl	%eax
	shlx	%ecx, %edx, %ecx
	orb	%cl, (%rsi,%rdi)
	cmpl	$-1, %eax
	je	.L93
	.p2align 4,,10
	.p2align 3
.L92:
	movl	(%r8), %edx
	movl	%eax, %ecx
	movq	(%rbx), %rdi
	sarl	$3, %ecx
	addl	%eax, %edx
	movslq	%ecx, %rcx
	movl	%edx, %esi
	movzbl	(%rdi,%rcx), %ecx
	movl	%eax, %r12d
	sarl	$3, %esi
	andl	$7, %r12d
	movslq	%esi, %rsi
	sarx	%r12d, %ecx, %ecx
	andl	$7, %edx
	andl	$1, %ecx
	decl	%eax
	shlx	%edx, %ecx, %edx
	orb	%dl, (%rdi,%rsi)
	cmpl	$-1, %eax
	jne	.L92
.L93:
	movl	(%r8), %ecx
.L91:
	addq	$4, %r8
	addl	%ecx, %r9d
	cmpq	%r8, %r10
	jne	.L95
	vzeroupper
.L107:
	leaq	-40(%rbp), %rsp
	movq	%rbx, %rax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L82:
	.cfi_restore_state
	testl	%r9d, %r9d
	js	.L91
	movl	%r9d, %eax
	jmp	.L90
	.p2align 4,,10
	.p2align 3
.L84:
	subl	%r12d, %esi
	vlddqu	0(%r13,%rdi), %ymm1
	movl	%r11d, %edi
	vlddqu	(%rcx), %ymm0
	subl	%esi, %edi
	vmovq	%rdi, %xmm5
	vmovd	%esi, %xmm3
	vpsrlw	%xmm5, %ymm1, %ymm1
	vpsllw	%xmm3, %ymm0, %ymm0
	vpor	%ymm1, %ymm0, %ymm0
	jmp	.L86
	.p2align 4,,10
	.p2align 3
.L98:
	movl	%esi, %edx
.L86:
	subq	$31, %rcx
	vlddqu	(%rcx), %ymm2
	vlddqu	-1(%rcx), %ymm1
	vlddqu	(%rax), %ymm4
	vpsrlw	%xmm5, %ymm1, %ymm1
	vpsllw	%xmm3, %ymm2, %ymm2
	vpor	%ymm4, %ymm0, %ymm0
	leal	-248(%rdx), %esi
	vmovdqu	%ymm0, (%rax)
	subq	$31, %rax
	vpor	%ymm1, %ymm2, %ymm0
	cmpl	$255, %esi
	jg	.L98
	jmp	.L109
	.p2align 4,,10
	.p2align 3
.L83:
	vlddqu	(%rcx), %ymm0
	jmp	.L88
	.p2align 4,,10
	.p2align 3
.L99:
	movl	%esi, %edx
.L88:
	vlddqu	(%rax), %ymm2
	subq	$31, %rcx
	vlddqu	(%rcx), %ymm1
	vpor	%ymm2, %ymm0, %ymm0
	leal	-248(%rdx), %esi
	vmovdqu	%ymm0, (%rax)
	subq	$31, %rax
	vmovdqa	%ymm1, %ymm0
	cmpl	$255, %esi
	jg	.L99
	vlddqu	(%rax), %ymm0
	vpor	%ymm1, %ymm0, %ymm1
	vmovdqu	%ymm1, (%rax)
	leal	-496(%rdx), %eax
	jmp	.L87
.L111:
	movq	(%r14), %rsi
	movslq	%eax, %rdx
	movq	%rcx, %rdi
	call	memmove
	jmp	.L79
.L110:
	vzeroupper
	jmp	.L72
.L97:
	xorl	%eax, %eax
	jmp	.L73
.L101:
	movq	%rax, %r12
	jmp	.L96
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA8275:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8275-.LLSDACSB8275
.LLSDACSB8275:
	.uleb128 .LEHB0-.LFB8275
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB8275
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L101-.LFB8275
	.uleb128 0
.LLSDACSE8275:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDAC8275
	.type	_Z17CreatePartialSums4spanIiER12bitArraySlim.cold.107, @function
_Z17CreatePartialSums4spanIiER12bitArraySlim.cold.107:
.L96:
	.cfi_def_cfa 6, 16
	.cfi_offset 3, -56
	.cfi_offset 6, -16
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movl	$16, %esi
	movq	%rbx, %rdi
	vzeroupper
	call	_ZdlPvm
	movq	%r12, %rdi
.LEHB2:
	call	_Unwind_Resume
.LEHE2:
	.cfi_endproc
.LFE8275:
	.section	.gcc_except_table
.LLSDAC8275:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC8275-.LLSDACSBC8275
.LLSDACSBC8275:
	.uleb128 .LEHB2-.LCOLDB0
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSEC8275:
	.section	.text.unlikely
	.text
	.size	_Z17CreatePartialSums4spanIiER12bitArraySlim, .-_Z17CreatePartialSums4spanIiER12bitArraySlim
	.section	.text.unlikely
	.size	_Z17CreatePartialSums4spanIiER12bitArraySlim.cold.107, .-_Z17CreatePartialSums4spanIiER12bitArraySlim.cold.107
.LCOLDE0:
	.text
.LHOTE0:
	.p2align 4,,15
	.globl	_Z13CreateAllSumsiR12bitArraySlimR15PartialSumsData
	.type	_Z13CreateAllSumsiR12bitArraySlimR15PartialSumsData, @function
_Z13CreateAllSumsiR12bitArraySlimR15PartialSumsData:
.LFB8276:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	%edi, %r13d
	movl	$4, %edi
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdx, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	call	_Znam
	movq	%rax, (%rsp)
	movq	$0, 8(%rsp)
	movq	%rax, %rbp
	movl	$1, %eax
	vmovdqa	(%rsp), %xmm1
	movq	%r12, %rdx
	vpinsrd	$2, %eax, %xmm1, %xmm0
	vmovaps	%xmm0, (%rsp)
	movq	8(%rsp), %rsi
	movq	(%rsp), %rdi
	movl	%r13d, 0(%rbp)
	call	_Z17CreatePartialSums4spanIiER12bitArraySlim
	movq	%rax, 48(%rbx)
	movq	%rbp, %rdi
	call	_ZdaPv
	movq	48(%rbx), %rax
	xorl	%edx, %edx
	movl	12(%rax), %ecx
	movq	(%rax), %rdi
	leal	-64(%rcx), %r8d
	xorl	%eax, %eax
	testl	%r8d, %r8d
	jle	.L116
	.p2align 4,,10
	.p2align 3
.L113:
	movl	%eax, %esi
	sarl	$6, %esi
	movslq	%esi, %rsi
	addl	$64, %eax
	popcntq	(%rdi,%rsi,8), %rsi
	addl	%esi, %edx
	cmpl	%r8d, %eax
	jl	.L113
	leal	-65(%rcx), %eax
	andl	$-64, %eax
	addl	$64, %eax
.L116:
	leal	-32(%rcx), %r9d
	movl	%eax, %esi
	cmpl	%r9d, %eax
	jge	.L115
	.p2align 4,,10
	.p2align 3
.L114:
	movl	%esi, %r8d
	sarl	$5, %r8d
	movslq	%r8d, %r8
	movl	(%rdi,%r8,4), %r8d
	addl	$32, %esi
	popcntq	%r8, %r8
	addl	%r8d, %edx
	cmpl	%r9d, %esi
	jl	.L114
	leal	-33(%rcx), %esi
	subl	%eax, %esi
	andl	$-32, %esi
	leal	32(%rax,%rsi), %eax
.L115:
	cmpl	%eax, %ecx
	jle	.L118
	.p2align 4,,10
	.p2align 3
.L117:
	movl	%eax, %esi
	sarl	$3, %esi
	movslq	%esi, %rsi
	movl	%eax, %r8d
	movzbl	(%rdi,%rsi), %esi
	andl	$7, %r8d
	sarx	%r8d, %esi, %esi
	incl	%eax
	andl	$1, %esi
	addl	%esi, %edx
	cmpl	%eax, %ecx
	jne	.L117
.L118:
	movl	%edx, 36(%rbx)
	addq	$24, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE8276:
	.size	_Z13CreateAllSumsiR12bitArraySlimR15PartialSumsData, .-_Z13CreateAllSumsiR12bitArraySlimR15PartialSumsData
	.p2align 4,,15
	.globl	_Z20FinishCreateSumsDataiR12bitArraySlimR15PartialSumsData
	.type	_Z20FinishCreateSumsDataiR12bitArraySlimR15PartialSumsData, @function
_Z20FinishCreateSumsDataiR12bitArraySlimR15PartialSumsData:
.LFB8277:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movl	36(%rdx), %r11d
	cmpl	$-1, %r11d
	je	.L129
	movl	12(%rsi), %r9d
	movq	(%rsi), %r10
	leal	-64(%r9), %edi
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	testl	%edi, %edi
	jle	.L133
	.p2align 4,,10
	.p2align 3
.L130:
	movl	%eax, %edx
	sarl	$6, %edx
	movslq	%edx, %rdx
	addl	$64, %eax
	popcntq	(%r10,%rdx,8), %rdx
	addl	%edx, %ecx
	cmpl	%edi, %eax
	jl	.L130
	leal	-65(%r9), %eax
	andl	$-64, %eax
	addl	$64, %eax
.L133:
	leal	-32(%r9), %ebx
	movl	%eax, %edi
	cmpl	%eax, %ebx
	jle	.L132
	.p2align 4,,10
	.p2align 3
.L131:
	movl	%edi, %edx
	sarl	$5, %edx
	movslq	%edx, %rdx
	movl	(%r10,%rdx,4), %r8d
	addl	$32, %edi
	popcntq	%r8, %r8
	addl	%r8d, %ecx
	cmpl	%ebx, %edi
	jl	.L131
	leal	-33(%r9), %edx
	subl	%eax, %edx
	andl	$-32, %edx
	leal	32(%rax,%rdx), %eax
.L132:
	cmpl	%eax, %r9d
	jle	.L135
	.p2align 4,,10
	.p2align 3
.L134:
	movl	%eax, %edi
	sarl	$3, %edi
	movslq	%edi, %rdi
	movl	%eax, %edx
	movzbl	(%r10,%rdi), %edi
	andl	$7, %edx
	sarx	%edx, %edi, %edi
	incl	%eax
	andl	$1, %edi
	addl	%edi, %ecx
	cmpl	%r9d, %eax
	jne	.L134
.L135:
	movq	$0, 8(%rsp)
	movq	%rsi, (%rsp)
	subl	%ecx, %r11d
	vmovdqa	(%rsp), %xmm1
	vpinsrd	$2, %r11d, %xmm1, %xmm0
	vmovaps	%xmm0, (%rsp)
.L168:
	movq	(%rsp), %rax
	movq	8(%rsp), %rdx
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L129:
	.cfi_restore_state
	movl	%edi, %ebx
	movl	$4, %edi
	movq	%rdx, %r12
	movq	%rsi, %rbp
	call	_Znam
	movq	%rax, (%rsp)
	movq	$0, 8(%rsp)
	movq	%rax, %r13
	movl	$1, %eax
	vmovdqa	(%rsp), %xmm3
	movq	%rbp, %rdx
	vpinsrd	$2, %eax, %xmm3, %xmm2
	vmovaps	%xmm2, (%rsp)
	movq	8(%rsp), %rsi
	movq	(%rsp), %rdi
	movl	%ebx, 0(%r13)
	call	_Z17CreatePartialSums4spanIiER12bitArraySlim
	movq	%rax, 48(%r12)
	movq	%r13, %rdi
	call	_ZdaPv
	movq	48(%r12), %rax
	xorl	%ecx, %ecx
	movl	12(%rax), %edi
	movq	(%rax), %rsi
	leal	-64(%rdi), %r8d
	xorl	%eax, %eax
	testl	%r8d, %r8d
	jle	.L170
	.p2align 4,,10
	.p2align 3
.L137:
	movl	%ecx, %edx
	sarl	$6, %edx
	movslq	%edx, %rdx
	addl	$64, %ecx
	popcntq	(%rsi,%rdx,8), %rdx
	addl	%edx, %eax
	cmpl	%r8d, %ecx
	jl	.L137
	leal	-65(%rdi), %edx
	andl	$-64, %edx
	leal	64(%rdx), %r8d
.L140:
	leal	-32(%rdi), %r9d
	movl	%r8d, %ecx
	cmpl	%r8d, %r9d
	jle	.L139
	.p2align 4,,10
	.p2align 3
.L138:
	movl	%ecx, %edx
	sarl	$5, %edx
	movslq	%edx, %rdx
	movl	(%rsi,%rdx,4), %edx
	addl	$32, %ecx
	popcntq	%rdx, %rdx
	addl	%edx, %eax
	cmpl	%ecx, %r9d
	jg	.L138
	leal	-33(%rdi), %edx
	subl	%r8d, %edx
	andl	$-32, %edx
	leal	32(%r8,%rdx), %r8d
.L139:
	cmpl	%r8d, %edi
	jle	.L142
	.p2align 4,,10
	.p2align 3
.L141:
	movl	%r8d, %edx
	sarl	$3, %edx
	movslq	%edx, %rdx
	movzbl	(%rsi,%rdx), %ecx
	movl	%r8d, %edx
	andl	$7, %edx
	sarx	%edx, %ecx, %ecx
	incl	%r8d
	andl	$1, %ecx
	addl	%ecx, %eax
	cmpl	%edi, %r8d
	jne	.L141
.L142:
	movl	%eax, 36(%r12)
	movl	12(%rbp), %esi
	testl	%esi, %esi
	jle	.L151
	movq	0(%rbp), %rdi
	xorl	%r8d, %r8d
	xorl	%eax, %eax
	jmp	.L146
	.p2align 4,,10
	.p2align 3
.L171:
	incl	%r8d
.L144:
	incl	%eax
	cmpl	%esi, %eax
	je	.L143
.L146:
	movl	%eax, %edx
	sarl	$3, %edx
	movslq	%edx, %rdx
	movzbl	(%rdi,%rdx), %ecx
	movl	%eax, %edx
	andl	$7, %edx
	btl	%edx, %ecx
	jnc	.L144
	leal	(%rax,%rbx), %edx
	cmpl	%edx, %esi
	jle	.L171
	movl	%edx, %ecx
	sarl	$3, %ecx
	movslq	%ecx, %rcx
	movzbl	(%rdi,%rcx), %ecx
	andl	$7, %edx
	sarx	%edx, %ecx, %edx
	andl	$1, %edx
	cmpb	$1, %dl
	adcl	$0, %r8d
	incl	%eax
	cmpl	%esi, %eax
	jne	.L146
.L143:
	movq	$0, 8(%rsp)
	movq	%rbp, (%rsp)
	vmovdqa	(%rsp), %xmm5
	vpinsrd	$2, %r8d, %xmm5, %xmm4
	vmovaps	%xmm4, (%rsp)
	jmp	.L168
	.p2align 4,,10
	.p2align 3
.L170:
	xorl	%r8d, %r8d
	jmp	.L140
	.p2align 4,,10
	.p2align 3
.L151:
	xorl	%r8d, %r8d
	jmp	.L143
	.cfi_endproc
.LFE8277:
	.size	_Z20FinishCreateSumsDataiR12bitArraySlimR15PartialSumsData, .-_Z20FinishCreateSumsDataiR12bitArraySlimR15PartialSumsData
	.p2align 4,,15
	.globl	_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData
	.type	_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData, @function
_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData:
.LFB8278:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdx, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rcx, %rbx
	subq	$80, %rsp
	.cfi_def_cfa_offset 112
	movl	40(%rcx), %eax
	cmpl	$1, %esi
	jle	.L173
	movl	%esi, %edx
	movq	%rdi, (%rsp)
	movq	$0, 8(%rsp)
	sarl	%edx
	movslq	%edx, %rcx
	leaq	(%rdi,%rcx,4), %rdi
	vmovdqa	(%rsp), %xmm1
	movq	$0, 8(%rsp)
	movq	%rdi, (%rsp)
	subl	%edx, %esi
	vpinsrd	$2, %edx, %xmm1, %xmm0
	vmovdqa	(%rsp), %xmm3
	vmovaps	%xmm0, 16(%rsp)
	vpinsrd	$2, %esi, %xmm3, %xmm2
	vmovaps	%xmm2, (%rsp)
	cmpl	%eax, 44(%rbx)
	jge	.L243
.L198:
	xorl	%ecx, %ecx
.L240:
	addq	$80, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movl	%ecx, %eax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L243:
	.cfi_restore_state
	movq	(%rsp), %rdi
	movq	8(%rsp), %rsi
	movq	%rbp, %rdx
	call	_Z17CreatePartialSums4spanIiER12bitArraySlim
	movq	16(%rsp), %rdi
	movq	24(%rsp), %rsi
	movq	%rbx, %rcx
	movq	%rax, %rdx
	movq	%rax, %r12
	call	_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData
	cmpb	$1, %al
	je	.L175
	testq	%r12, %r12
	je	.L175
	movq	(%r12), %rdi
	testq	%rdi, %rdi
	je	.L176
	call	_ZdaPv
.L176:
	movl	$16, %esi
	movq	%r12, %rdi
	call	_ZdlPvm
.L175:
	movl	44(%rbx), %eax
	cmpl	%eax, 40(%rbx)
	jg	.L198
	movq	24(%rsp), %rsi
	movq	16(%rsp), %rdi
	movq	%rbp, %rdx
	call	_Z17CreatePartialSums4spanIiER12bitArraySlim
	movq	8(%rsp), %rsi
	movq	(%rsp), %rdi
	movq	%rax, %rbp
	movq	%rbx, %rcx
	movq	%rax, %rdx
	call	_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData
	testq	%rbp, %rbp
	je	.L198
	cmpb	$1, %al
	je	.L198
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L177
	call	_ZdaPv
.L177:
	movl	$16, %esi
	movq	%rbp, %rdi
	call	_ZdlPvm
	jmp	.L198
	.p2align 4,,10
	.p2align 3
.L173:
	incl	%eax
	movl	%eax, 40(%rcx)
	movq	(%rdx), %r8
	xorl	%eax, %eax
	movl	12(%rdx), %r9d
	xorl	%edx, %edx
	leal	-64(%r9), %esi
	testl	%esi, %esi
	jle	.L183
	.p2align 4,,10
	.p2align 3
.L180:
	movl	%eax, %ecx
	sarl	$6, %ecx
	movslq	%ecx, %rcx
	addl	$64, %eax
	popcntq	(%r8,%rcx,8), %rcx
	addl	%ecx, %edx
	cmpl	%esi, %eax
	jl	.L180
	leal	-65(%r9), %eax
	andl	$-64, %eax
	addl	$64, %eax
.L183:
	leal	-32(%r9), %r10d
	movl	%eax, %ecx
	cmpl	%eax, %r10d
	jle	.L182
	.p2align 4,,10
	.p2align 3
.L181:
	movl	%ecx, %esi
	sarl	$5, %esi
	movslq	%esi, %rsi
	movl	(%r8,%rsi,4), %esi
	addl	$32, %ecx
	popcntq	%rsi, %rsi
	addl	%esi, %edx
	cmpl	%ecx, %r10d
	jg	.L181
	leal	-33(%r9), %ecx
	subl	%eax, %ecx
	andl	$-32, %ecx
	leal	32(%rax,%rcx), %eax
.L182:
	cmpl	%eax, %r9d
	jle	.L185
	.p2align 4,,10
	.p2align 3
.L184:
	movl	%eax, %ecx
	sarl	$3, %ecx
	movslq	%ecx, %rcx
	movl	%eax, %esi
	movzbl	(%r8,%rcx), %ecx
	andl	$7, %esi
	sarx	%esi, %ecx, %ecx
	incl	%eax
	andl	$1, %ecx
	addl	%ecx, %edx
	cmpl	%r9d, %eax
	jne	.L184
.L185:
	movl	36(%rbx), %eax
	xorl	%ecx, %ecx
	subl	%edx, %eax
	cmpl	32(%rbx), %eax
	jg	.L240
	movq	(%rbx), %rsi
	movslq	(%rdi), %rax
	movq	8(%rsi), %rdi
	xorl	%edx, %edx
	movq	%rax, %r12
	divq	%rdi
	movq	(%rsi), %rax
	movq	(%rax,%rdx,8), %rax
	movq	%rdx, %r8
	testq	%rax, %rax
	je	.L187
	movq	(%rax), %rax
	cmpl	8(%rax), %r12d
	je	.L240
	movq	(%rax), %rcx
	testq	%rcx, %rcx
	jne	.L242
	jmp	.L187
	.p2align 4,,10
	.p2align 3
.L244:
	cmpl	%esi, %r12d
	je	.L198
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L187
.L242:
	movslq	8(%rcx), %rax
	xorl	%edx, %edx
	movq	%rax, %rsi
	divq	%rdi
	cmpq	%rdx, %r8
	je	.L244
.L187:
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	movl	%r12d, %edi
	call	_Z20FinishCreateSumsDataiR12bitArraySlimR15PartialSumsData
	movq	%rax, 32(%rsp)
	movq	%rdx, 40(%rsp)
	movq	%rax, 48(%rsp)
	movl	16(%rbx), %eax
	movl	40(%rsp), %edx
	cmpl	%eax, 32(%rbx)
	movl	%eax, %ecx
	cmovle	32(%rbx), %ecx
	movl	%edx, 56(%rsp)
	movl	%ecx, 32(%rbx)
	cmpl	%edx, %eax
	jg	.L190
	jne	.L198
	cmpl	24(%rbx), %r12d
	jge	.L198
	.p2align 4,,10
	.p2align 3
.L190:
	movq	8(%rbx), %rbp
	testq	%rbp, %rbp
	je	.L192
	movq	0(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L193
	call	_ZdaPv
.L193:
	movl	$16, %esi
	movq	%rbp, %rdi
	call	_ZdlPvm
.L192:
	vmovdqa	48(%rsp), %xmm4
	movl	%r12d, 24(%rbx)
	vmovups	%xmm4, 8(%rbx)
	movl	$1, %ecx
	jmp	.L240
	.cfi_endproc
.LFE8278:
	.size	_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData, .-_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData
	.p2align 4,,15
	.globl	_Z22GetFirstReplicateIndex4spanIiE
	.type	_Z22GetFirstReplicateIndex4spanIiE, @function
_Z22GetFirstReplicateIndex4spanIiE:
.LFB8282:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	movq	%rsi, %r12
	pushq	%rbx
	andq	$-32, %rsp
	.cfi_offset 3, -56
	testl	%esi, %esi
	jle	.L246
	leal	-1(%rsi), %eax
	movq	%rdi, %rbx
	movl	%esi, %r13d
	cmpl	$6, %eax
	jbe	.L265
	movl	%esi, %edx
	shrl	$3, %edx
	salq	$5, %rdx
	movq	%rdi, %rax
	addq	%rdi, %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	.p2align 4,,10
	.p2align 3
.L248:
	vpaddd	(%rax), %ymm0, %ymm0
	addq	$32, %rax
	cmpq	%rdx, %rax
	jne	.L248
	vmovdqa	%xmm0, %xmm1
	vextracti128	$1, %ymm0, %xmm0
	vpaddd	%xmm0, %xmm1, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	vpsrldq	$4, %xmm0, %xmm1
	vpaddd	%xmm1, %xmm0, %xmm0
	movl	%r12d, %edx
	vmovd	%xmm0, %eax
	andl	$-8, %edx
	incl	%eax
	cmpl	%edx, %r12d
	je	.L280
	vzeroupper
.L247:
	movslq	%edx, %rcx
	addl	(%rbx,%rcx,4), %eax
	leal	1(%rdx), %ecx
	cmpl	%ecx, %r12d
	jle	.L249
	movslq	%ecx, %rcx
	addl	(%rbx,%rcx,4), %eax
	leal	2(%rdx), %ecx
	cmpl	%ecx, %r12d
	jle	.L249
	movslq	%ecx, %rcx
	addl	(%rbx,%rcx,4), %eax
	leal	3(%rdx), %ecx
	cmpl	%ecx, %r12d
	jle	.L249
	movslq	%ecx, %rcx
	addl	(%rbx,%rcx,4), %eax
	leal	4(%rdx), %ecx
	cmpl	%ecx, %r12d
	jle	.L249
	movslq	%ecx, %rcx
	addl	(%rbx,%rcx,4), %eax
	leal	5(%rdx), %ecx
	cmpl	%ecx, %r12d
	jle	.L249
	movslq	%ecx, %rcx
	addl	$6, %edx
	addl	(%rbx,%rcx,4), %eax
	cmpl	%edx, %r12d
	jle	.L249
	movslq	%edx, %rdx
	addl	(%rbx,%rdx,4), %eax
.L249:
	movslq	%eax, %r14
	movq	%r14, %rdi
	call	_Znam
	movq	%rax, %rcx
	movq	%r14, %rax
	decq	%rax
	js	.L279
	movq	%rcx, %rdi
	movq	%r14, %rdx
	xorl	%esi, %esi
	call	memset
	movq	%rax, %rcx
.L279:
	movb	$1, (%rcx)
	movslq	(%rbx), %rdx
	cmpb	$0, (%rcx,%rdx)
	movq	%rdx, %r8
	jne	.L266
	vmovdqa	.LC1(%rip), %ymm2
	movl	$1, %edi
	xorl	%esi, %esi
	leaq	-1(%rcx), %r9
	.p2align 4,,10
	.p2align 3
.L251:
	testl	%esi, %esi
	js	.L258
	movslq	%esi, %rax
	leaq	(%rax,%rdx), %r11
	leaq	-31(%r11), %r10
	leaq	1(%rax), %r14
	cmpq	%r14, %r10
	setge	%r14b
	leaq	-31(%rax), %r15
	incq	%r11
	cmpq	%r11, %r15
	setge	%r11b
	orb	%r11b, %r14b
	je	.L255
	cmpl	$30, %esi
	jbe	.L255
	leal	1(%rsi), %r14d
	movl	%r14d, %r11d
	shrl	$5, %r11d
	negq	%r11
	addq	%rcx, %r15
	addq	%rcx, %r10
	salq	$5, %r11
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L257:
	vmovdqu	(%r15,%rax), %ymm0
	vmovdqu	(%r10,%rax), %ymm1
	vperm2i128	$1, %ymm0, %ymm0, %ymm0
	vperm2i128	$1, %ymm1, %ymm1, %ymm1
	vpshufb	%ymm2, %ymm0, %ymm0
	vpshufb	%ymm2, %ymm1, %ymm1
	vpor	%ymm1, %ymm0, %ymm0
	vperm2i128	$1, %ymm0, %ymm0, %ymm0
	vpshufb	%ymm2, %ymm0, %ymm0
	vmovdqu	%ymm0, (%r10,%rax)
	subq	$32, %rax
	cmpq	%r11, %rax
	jne	.L257
	movl	%r14d, %r10d
	andl	$-32, %r10d
	movl	%esi, %eax
	subl	%r10d, %eax
	cmpl	%r10d, %r14d
	je	.L258
	cltq
	addq	%rcx, %rdx
	.p2align 4,,10
	.p2align 3
.L260:
	movzbl	(%rcx,%rax), %r10d
	orb	%r10b, (%rdx,%rax)
	decq	%rax
	testl	%eax, %eax
	jns	.L260
.L258:
	addl	%r8d, %esi
	movl	%edi, %eax
	cmpl	%edi, %r13d
	jle	.L281
.L274:
	movslq	(%rbx,%rdi,4), %rdx
	incq	%rdi
	cmpb	$0, (%rcx,%rdx)
	movq	%rdx, %r8
	je	.L251
	vzeroupper
.L277:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L255:
	.cfi_restore_state
	addq	%rcx, %rax
	movq	%r9, %r11
	.p2align 4,,10
	.p2align 3
.L262:
	movzbl	(%rax), %r10d
	orb	%r10b, (%rax,%rdx)
	decq	%rax
	cmpq	%r11, %rax
	jne	.L262
	addl	%r8d, %esi
	movl	%edi, %eax
	cmpl	%edi, %r13d
	jg	.L274
.L281:
	vzeroupper
.L253:
	movq	%rcx, %rdi
	call	_ZdaPv
	leaq	-40(%rbp), %rsp
	popq	%rbx
	movl	%r12d, %eax
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L246:
	.cfi_restore_state
	movl	$1, %edi
	call	_Znam
	movq	%rax, %rcx
	movb	$1, (%rax)
	jmp	.L253
.L280:
	vzeroupper
	jmp	.L249
.L265:
	xorl	%edx, %edx
	movl	$1, %eax
	jmp	.L247
.L266:
	xorl	%eax, %eax
	jmp	.L277
	.cfi_endproc
.LFE8282:
	.size	_Z22GetFirstReplicateIndex4spanIiE, .-_Z22GetFirstReplicateIndex4spanIiE
	.section	.rodata._ZNSt6vectorIiSaIiEE7reserveEm.str1.1,"aMS",@progbits,1
.LC2:
	.string	"vector::reserve"
	.section	.text._ZNSt6vectorIiSaIiEE7reserveEm,"axG",@progbits,_ZNSt6vectorIiSaIiEE7reserveEm,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEE7reserveEm
	.type	_ZNSt6vectorIiSaIiEE7reserveEm, @function
_ZNSt6vectorIiSaIiEE7reserveEm:
.LFB8560:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movabsq	$4611686018427387903, %rax
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	cmpq	%rax, %rsi
	ja	.L294
	movq	(%rdi), %rbp
	movq	16(%rdi), %rax
	movq	%rdi, %rbx
	subq	%rbp, %rax
	sarq	$2, %rax
	cmpq	%rsi, %rax
	jb	.L295
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L295:
	.cfi_restore_state
	movq	8(%rdi), %r15
	leaq	0(,%rsi,4), %r14
	movq	%r15, %r13
	subq	%rbp, %r13
	testq	%rsi, %rsi
	je	.L288
	movq	%r14, %rdi
	call	_Znwm
	movq	(%rbx), %rcx
	movq	%rax, %r12
.L285:
	cmpq	%rbp, %r15
	je	.L286
	movq	%r13, %rdx
	movq	%rbp, %rsi
	movq	%r12, %rdi
	movq	%rcx, 8(%rsp)
	call	memmove
	movq	8(%rsp), %rcx
.L286:
	testq	%rcx, %rcx
	je	.L287
	movq	%rcx, %rdi
	call	_ZdlPv
.L287:
	movq	%r12, (%rbx)
	addq	%r12, %r13
	addq	%r14, %r12
	movq	%r13, 8(%rbx)
	movq	%r12, 16(%rbx)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L288:
	.cfi_restore_state
	movq	%rbp, %rcx
	xorl	%r12d, %r12d
	jmp	.L285
.L294:
	movl	$.LC2, %edi
	call	_ZSt20__throw_length_errorPKc
	.cfi_endproc
.LFE8560:
	.size	_ZNSt6vectorIiSaIiEE7reserveEm, .-_ZNSt6vectorIiSaIiEE7reserveEm
	.section	.text._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.type	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, @function
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB8735:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movq	%rdx, %r15
	movq	%rsi, %rdx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	8(%rdi), %rcx
	movq	(%rdi), %rbp
	movq	%rcx, %rax
	subq	%rbp, %rax
	subq	%rbp, %rdx
	sarq	$2, %rax
	je	.L305
	leaq	(%rax,%rax), %rdi
	movq	$-4, %r14
	cmpq	%rdi, %rax
	jbe	.L311
.L298:
	movq	%r14, %rdi
	movq	%rdx, 16(%rsp)
	movq	%rcx, 8(%rsp)
	call	_Znwm
	movq	16(%rsp), %rdx
	movq	8(%rsp), %rcx
	movq	%rax, %r13
	addq	%rax, %r14
.L299:
	movl	(%r15), %eax
	movq	%rcx, %r8
	leaq	4(%r13,%rdx), %r9
	subq	%r12, %r8
	movl	%eax, 0(%r13,%rdx)
	leaq	(%r9,%r8), %r15
	cmpq	%rbp, %r12
	je	.L300
	movq	%rbp, %rsi
	movq	%r13, %rdi
	movq	%r9, 24(%rsp)
	movq	%r8, 16(%rsp)
	movq	%rcx, 8(%rsp)
	call	memmove
	movq	8(%rsp), %rcx
	movq	16(%rsp), %r8
	cmpq	%rcx, %r12
	movq	24(%rsp), %r9
	je	.L304
.L301:
	movq	%r8, %rdx
	movq	%r12, %rsi
	movq	%r9, %rdi
	call	memcpy
.L303:
	testq	%rbp, %rbp
	jne	.L304
.L302:
	movq	%r13, (%rbx)
	movq	%r15, 8(%rbx)
	movq	%r14, 16(%rbx)
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L304:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZdlPv
	jmp	.L302
	.p2align 4,,10
	.p2align 3
.L311:
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %rdi
	ja	.L298
	xorl	%r14d, %r14d
	xorl	%r13d, %r13d
	testq	%rdi, %rdi
	je	.L299
	jmp	.L297
	.p2align 4,,10
	.p2align 3
.L300:
	cmpq	%rcx, %r12
	jne	.L301
	jmp	.L303
	.p2align 4,,10
	.p2align 3
.L305:
	movl	$1, %edi
.L297:
	leaq	0(,%rdi,4), %r14
	jmp	.L298
	.cfi_endproc
.LFE8735:
	.size	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, .-_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.text
	.p2align 4,,15
	.globl	_Z29CreateCollisionAvoidanceArrayR12bitArraySlim12BestSumsDataR15PartialSumsData
	.type	_Z29CreateCollisionAvoidanceArrayR12bitArraySlim12BestSumsDataR15PartialSumsData, @function
_Z29CreateCollisionAvoidanceArrayR12bitArraySlim12BestSumsDataR15PartialSumsData:
.LFB8283:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	movl	$24, %edi
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movl	36(%rsi), %r13d
	movq	80(%rsp), %r15
	movl	96(%rsp), %ebp
	call	_Znwm
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movl	$24, %edi
	movq	%rax, %r12
	call	_Znwm
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	$0, 16(%rax)
	movslq	%r13d, %rsi
	movq	%r12, %rdi
	movq	%rax, %r14
	call	_ZNSt6vectorIiSaIiEE7reserveEm
	movslq	88(%rsp), %rsi
	movq	%r14, %rdi
	call	_ZNSt6vectorIiSaIiEE7reserveEm
	movl	12(%r15), %ecx
	xorl	%r13d, %r13d
	testl	%ecx, %ecx
	jg	.L313
	jmp	.L323
	.p2align 4,,10
	.p2align 3
.L317:
	movl	%eax, %ecx
	sarl	$3, %ecx
	movslq	%ecx, %rcx
	movzbl	(%rdx,%rcx), %ecx
	movl	%eax, %edx
	andl	$7, %edx
	btl	%edx, %ecx
	jnc	.L358
.L319:
	movq	8(%r12), %rsi
	cmpq	16(%r12), %rsi
	je	.L321
.L359:
	movl	12(%rsp), %eax
	addq	$4, %rsi
	movl	%eax, -4(%rsi)
	movq	%rsi, 8(%r12)
.L322:
	movl	12(%r15), %ecx
.L316:
	incl	%r13d
	cmpl	%ecx, %r13d
	jge	.L323
.L313:
	movl	%r13d, %eax
	sarl	$3, %eax
	movq	(%r15), %rdx
	cltq
	movzbl	(%rdx,%rax), %esi
	movl	%r13d, %eax
	andl	$7, %eax
	btl	%eax, %esi
	jnc	.L316
	leal	0(%r13,%rbp), %eax
	movl	%eax, 12(%rsp)
	cmpl	%eax, %ecx
	jg	.L317
.L358:
	movq	8(%r14), %rsi
	cmpq	16(%r14), %rsi
	je	.L320
	movl	%eax, (%rsi)
	addq	$4, %rsi
	movq	%rsi, 8(%r14)
	movq	8(%r12), %rsi
	cmpq	16(%r12), %rsi
	jne	.L359
.L321:
	leaq	12(%rsp), %rdx
	movq	%r12, %rdi
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L322
.L323:
	movq	(%r14), %rax
	movl	$1, %esi
	cmpq	8(%r14), %rax
	je	.L315
	.p2align 4,,10
	.p2align 3
.L326:
	movl	(%rax), %edx
	addq	$4, %rax
	movl	%edx, %ecx
	sarl	$3, %ecx
	movslq	%ecx, %rcx
	andl	$7, %edx
	addq	(%rbx), %rcx
	shlx	%edx, %esi, %edx
	notl	%edx
	andb	%dl, (%rcx)
	cmpq	%rax, 8(%r14)
	jne	.L326
.L315:
	movl	12(%rbx), %edi
	testl	%edi, %edi
	jle	.L325
	movq	(%r12), %r11
	movq	8(%r12), %r10
	movl	$1, %r9d
	cmpq	%r11, %r10
	je	.L327
	.p2align 4,,10
	.p2align 3
.L332:
	movl	%ebp, %r12d
	subl	%r9d, %r12d
	movq	%r11, %rdx
	.p2align 4,,10
	.p2align 3
.L333:
	movl	(%rdx), %eax
	subl	%r12d, %eax
	cmpl	%edi, %eax
	jge	.L328
	movl	%eax, %ecx
	sarl	$3, %ecx
	movq	(%rbx), %r8
	movslq	%ecx, %rcx
	movzbl	(%r8,%rcx), %esi
	movl	%eax, %ecx
	andl	$7, %ecx
	btl	%ecx, %esi
	jnc	.L328
	incl	%eax
	xorl	%esi, %esi
	jmp	.L329
	.p2align 4,,10
	.p2align 3
.L331:
	movl	%edx, %ecx
	sarl	$3, %ecx
	movslq	%ecx, %rcx
	movzbl	(%r8,%rcx), %ecx
	andl	$7, %edx
	incl	%eax
	btl	%edx, %ecx
	jnc	.L330
.L329:
	incl	%esi
	movl	%eax, %edx
	cmpl	%edi, %eax
	jl	.L331
.L330:
	addl	%esi, %r9d
	cmpl	%edi, %r9d
	jle	.L332
.L325:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	movq	$-1, %rax
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L328:
	.cfi_restore_state
	addq	$4, %rdx
	cmpq	%rdx, %r10
	jne	.L333
.L327:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	movq	%r9, %rax
	movl	%ebp, %r9d
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	salq	$32, %rax
	popq	%r14
	.cfi_def_cfa_offset 16
	orq	%r9, %rax
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L320:
	.cfi_restore_state
	leaq	12(%rsp), %rdx
	movq	%r14, %rdi
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L319
	.cfi_endproc
.LFE8283:
	.size	_Z29CreateCollisionAvoidanceArrayR12bitArraySlim12BestSumsDataR15PartialSumsData, .-_Z29CreateCollisionAvoidanceArrayR12bitArraySlim12BestSumsDataR15PartialSumsData
	.section	.text.unlikely
.LCOLDB4:
	.text
.LHOTB4:
	.p2align 4,,15
	.globl	_Z5Solve4spanIiE
	.type	_Z5Solve4spanIiE, @function
_Z5Solve4spanIiE:
.LFB8284:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA8284
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movslq	%esi, %r14
	salq	$2, %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	leaq	(%rdi,%r14), %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$88, %rsp
	.cfi_def_cfa_offset 144
	cmpq	%r13, %rdi
	je	.L365
	movq	%r14, %rdx
	sarq	$2, %rdx
	bsrq	%rdx, %rdx
	addq	%rdx, %rdx
	movq	%r13, %rsi
	call	_ZSt16__introsort_loopIPilN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92
	leaq	4(%rbp), %rbx
	cmpq	$64, %r14
	jle	.L363
	leaq	64(%rbp), %r15
	jmp	.L364
	.p2align 4,,10
	.p2align 3
.L411:
	cmpq	%rbx, %rbp
	je	.L368
	movq	%rbx, %rdx
	movl	$4, %eax
	subq	%rbp, %rdx
	leaq	0(%rbp,%rax), %rdi
	movq	%rbp, %rsi
	call	memmove
.L368:
	addq	$4, %rbx
	movl	%r14d, 0(%rbp)
	cmpq	%rbx, %r15
	je	.L410
.L364:
	movl	(%rbx), %r14d
	cmpl	0(%rbp), %r14d
	jl	.L411
	movl	-4(%rbx), %edx
	leaq	-4(%rbx), %rax
	cmpl	%edx, %r14d
	jl	.L371
	jmp	.L412
	.p2align 4,,10
	.p2align 3
.L389:
	movq	%rsi, %rax
.L371:
	movl	%edx, 4(%rax)
	movl	-4(%rax), %edx
	leaq	-4(%rax), %rsi
	cmpl	%edx, %r14d
	jl	.L389
.L370:
	addq	$4, %rbx
	movl	%r14d, (%rax)
	cmpq	%rbx, %r15
	jne	.L364
.L410:
	cmpq	%r15, %r13
	je	.L365
	.p2align 4,,10
	.p2align 3
.L366:
	movl	(%r15), %esi
	movl	-4(%r15), %edx
	leaq	-4(%r15), %rax
	cmpl	%edx, %esi
	jl	.L374
	jmp	.L413
	.p2align 4,,10
	.p2align 3
.L391:
	movq	%rcx, %rax
.L374:
	movl	%edx, 4(%rax)
	movl	-4(%rax), %edx
	leaq	-4(%rax), %rcx
	cmpl	%edx, %esi
	jl	.L391
	movl	%esi, (%rax)
	addq	$4, %r15
.L416:
	cmpq	%r15, %r13
	jne	.L366
.L365:
	movq	%rbp, %rdi
	movq	%r12, %rsi
.LEHB3:
	call	_Z22GetFirstReplicateIndex4spanIiE
	movl	$16, %edi
	movl	%eax, %r13d
	call	_Znwm
.LEHE3:
	movq	%rax, %rbx
	movabsq	$4294967297, %rax
	movq	%rax, 8(%rbx)
	movl	$1, %edi
.LEHB4:
	call	_Znam
.LEHE4:
	movq	%rax, (%rbx)
	movb	$1, (%rax)
	vpxor	%xmm0, %xmm0, %xmm0
	movl	$2147483647, %eax
	vpinsrd	$2, %eax, %xmm0, %xmm0
	vmovaps	%xmm0, (%rsp)
	movl	8(%rsp), %eax
	movl	$56, %edi
	vmovq	%xmm0, 24(%rsp)
	movl	%eax, 32(%rsp)
	movl	$-1, 40(%rsp)
.LEHB5:
	call	_Znwm
	leaq	48(%rax), %rdx
	vpxor	%xmm0, %xmm0, %xmm0
	vmovups	%xmm0, 32(%rax)
	movq	%rdx, (%rax)
	movq	$0, 48(%rax)
	movq	$1, 8(%rax)
	movq	$0, 16(%rax)
	movq	$0, 24(%rax)
	movl	$0x3f800000, 32(%rax)
	movq	$0, 40(%rax)
	movq	%rax, 16(%rsp)
	movq	%rbp, %rdi
	movabsq	$-2147483649, %rax
	leaq	16(%rsp), %rcx
	movq	%rbx, %rdx
	movq	%r12, %rsi
	movq	%rax, 48(%rsp)
	movl	$0, 56(%rsp)
	movl	%r13d, 60(%rsp)
	call	_Z18CreateAllSumsDatas4spanIiER12bitArraySlimR15PartialSumsData
	movq	(%rbx), %rdi
	testq	%rdi, %rdi
	je	.L381
	call	_ZdaPv
.L381:
	movl	$16, %esi
	movq	%rbx, %rdi
	call	_ZdlPvm
	movq	16(%rsp), %rbp
	testq	%rbp, %rbp
	je	.L382
	movq	16(%rbp), %rdi
	testq	%rdi, %rdi
	je	.L386
	.p2align 4,,10
	.p2align 3
.L383:
	movq	(%rdi), %rbx
	call	_ZdlPv
	movq	%rbx, %rdi
	testq	%rbx, %rbx
	jne	.L383
.L386:
	movq	8(%rbp), %rax
	movq	0(%rbp), %rdi
	leaq	0(,%rax,8), %rdx
	xorl	%esi, %esi
	call	memset
	movq	0(%rbp), %rdi
	leaq	48(%rbp), %rax
	movq	$0, 24(%rbp)
	movq	$0, 16(%rbp)
	cmpq	%rax, %rdi
	je	.L384
	call	_ZdlPv
.L384:
	movl	$56, %esi
	movq	%rbp, %rdi
	call	_ZdlPvm
.L382:
	subq	$8, %rsp
	.cfi_def_cfa_offset 152
	pushq	48(%rsp)
	.cfi_def_cfa_offset 160
	pushq	48(%rsp)
	.cfi_def_cfa_offset 168
	pushq	48(%rsp)
	.cfi_def_cfa_offset 176
	movq	96(%rsp), %rdi
	leaq	48(%rsp), %rsi
	call	_Z29CreateCollisionAvoidanceArrayR12bitArraySlim12BestSumsDataR15PartialSumsData
.LEHE5:
	addq	$120, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L363:
	.cfi_def_cfa_offset 144
	cmpq	%rbx, %r13
	je	.L365
	movl	$4, %r14d
	jmp	.L380
	.p2align 4,,10
	.p2align 3
.L414:
	cmpq	%rbx, %rbp
	je	.L376
	movq	%rbx, %rdx
	subq	%rbp, %rdx
	leaq	0(%rbp,%r14), %rdi
	movq	%rbp, %rsi
	call	memmove
.L376:
	movl	%r15d, 0(%rbp)
.L377:
	addq	$4, %rbx
	cmpq	%rbx, %r13
	je	.L365
.L380:
	movl	(%rbx), %r15d
	cmpl	0(%rbp), %r15d
	jl	.L414
	movl	-4(%rbx), %edx
	leaq	-4(%rbx), %rax
	cmpl	%edx, %r15d
	jl	.L379
	jmp	.L415
	.p2align 4,,10
	.p2align 3
.L393:
	movq	%rcx, %rax
.L379:
	movl	%edx, 4(%rax)
	movl	-4(%rax), %edx
	leaq	-4(%rax), %rcx
	cmpl	%edx, %r15d
	jl	.L393
.L378:
	movl	%r15d, (%rax)
	jmp	.L377
	.p2align 4,,10
	.p2align 3
.L413:
	movq	%r15, %rax
	movl	%esi, (%rax)
	addq	$4, %r15
	jmp	.L416
.L415:
	movq	%rbx, %rax
	jmp	.L378
.L412:
	movq	%rbx, %rax
	jmp	.L370
.L394:
	movq	%rax, %rbp
	jmp	.L387
	.section	.gcc_except_table
.LLSDA8284:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8284-.LLSDACSB8284
.LLSDACSB8284:
	.uleb128 .LEHB3-.LFB8284
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB8284
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L394-.LFB8284
	.uleb128 0
	.uleb128 .LEHB5-.LFB8284
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE8284:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDAC8284
	.type	_Z5Solve4spanIiE.cold.108, @function
_Z5Solve4spanIiE.cold.108:
.L387:
	.cfi_def_cfa_offset 144
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movl	$16, %esi
	movq	%rbx, %rdi
	vzeroupper
	call	_ZdlPvm
	movq	%rbp, %rdi
.LEHB6:
	call	_Unwind_Resume
.LEHE6:
	.cfi_endproc
.LFE8284:
	.section	.gcc_except_table
.LLSDAC8284:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC8284-.LLSDACSBC8284
.LLSDACSBC8284:
	.uleb128 .LEHB6-.LCOLDB4
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSEC8284:
	.section	.text.unlikely
	.text
	.size	_Z5Solve4spanIiE, .-_Z5Solve4spanIiE
	.section	.text.unlikely
	.size	_Z5Solve4spanIiE.cold.108, .-_Z5Solve4spanIiE.cold.108
.LCOLDE4:
	.text
.LHOTE4:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC5:
	.string	"basic_string::substr"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC6:
	.string	"%s: __pos (which is %zu) > this->size() (which is %zu)"
	.align 8
.LC7:
	.string	"basic_string::_M_construct null not valid"
	.section	.rodata.str1.1
.LC8:
	.string	"stoi"
	.section	.text.unlikely
.LCOLDB9:
	.section	.text.startup,"ax",@progbits
.LHOTB9:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB8306:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA8306
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$_ZSt3cin, %edi
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	leaq	44(%rsp), %rsi
.LEHB7:
	call	_ZNSirsERi
	movl	$_ZSt3cin, %edi
	call	_ZSt2wsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_
	movslq	44(%rsp), %rbx
	movabsq	$2305843009213693950, %rax
	cmpq	%rax, %rbx
	ja	.L418
	leaq	0(,%rbx,4), %r12
	movq	%r12, %rdi
	call	_Znam
.LEHE7:
	movq	%rbx, %rbp
	movq	%rax, 8(%rsp)
	testq	%rbx, %rbx
	je	.L421
	movq	%rax, %rdi
	movq	%r12, %rdx
	xorl	%esi, %esi
	call	memset
.L421:
	movq	8(%rsp), %rax
	movq	$0, 24(%rsp)
	movq	%rax, 16(%rsp)
	leaq	64(%rsp), %rsi
	leaq	80(%rsp), %rax
	vmovdqa	16(%rsp), %xmm1
	movl	$_ZSt3cin, %edi
	vpinsrd	$2, %ebp, %xmm1, %xmm0
	vmovaps	%xmm0, 16(%rsp)
	movq	%rax, 64(%rsp)
	movq	$0, 72(%rsp)
	movb	$0, 80(%rsp)
.LEHB8:
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movq	72(%rsp), %rbp
	testq	%rbp, %rbp
	je	.L423
	movq	8(%rsp), %r12
	xorl	%r13d, %r13d
	xorl	%edx, %edx
	xorl	%eax, %eax
	leaq	112(%rsp), %r14
	.p2align 4,,10
	.p2align 3
.L424:
	cmpq	%rbp, %rax
	jnb	.L452
	movq	64(%rsp), %r8
	addq	%rax, %r8
	movsbl	(%r8), %ecx
	subl	$48, %ecx
	cmpl	$9, %ecx
	ja	.L452
	movq	%rbp, %rcx
	subq	%rax, %rcx
	movl	$1, %eax
	jmp	.L426
	.p2align 4,,10
	.p2align 3
.L428:
	movsbl	(%r8,%rax), %esi
	incq	%rax
	subl	$48, %esi
	cmpl	$9, %esi
	ja	.L427
.L426:
	movslq	%eax, %rdi
	leal	0(%r13,%rax), %ebx
	cmpq	%rax, %rcx
	jne	.L428
.L427:
	cmpq	%rbp, %rdi
	je	.L423
.L425:
	cmpq	%rdx, %rbp
	jb	.L471
	movq	64(%rsp), %r13
	subq	%rdx, %rbp
	addq	%rdx, %r13
	cmpq	%rdi, %rbp
	cmova	%rdi, %rbp
	movq	%r13, %rax
	addq	%rbp, %rax
	movq	%r14, 96(%rsp)
	je	.L431
	testq	%r13, %r13
	je	.L472
.L431:
	movq	%rbp, 48(%rsp)
	cmpq	$15, %rbp
	ja	.L473
	cmpq	$1, %rbp
	jne	.L434
	movzbl	0(%r13), %eax
	movb	%al, 112(%rsp)
	movq	%r14, %rax
.L435:
	movq	%rbp, 104(%rsp)
	movb	$0, (%rax,%rbp)
	call	__errno_location
	movq	96(%rsp), %r13
	movl	(%rax), %r15d
	movl	$0, (%rax)
	movl	$10, %edx
	leaq	56(%rsp), %rsi
	movq	%r13, %rdi
	movq	%rax, %rbp
	call	strtol
	cmpq	56(%rsp), %r13
	je	.L474
	movl	0(%rbp), %edx
	cmpl	$34, %edx
	je	.L437
	movl	$2147483648, %ecx
	addq	%rax, %rcx
	movl	$4294967295, %edi
	cmpq	%rdi, %rcx
	ja	.L437
	testl	%edx, %edx
	jne	.L439
	movl	%r15d, 0(%rbp)
.L439:
	movq	96(%rsp), %rdi
	movl	%eax, (%r12)
	leal	1(%rbx), %r13d
	cmpq	%r14, %rdi
	je	.L467
	call	_ZdlPv
.L467:
	movq	72(%rsp), %rbp
	movslq	%r13d, %rax
	movq	%rax, %rdx
	addq	$4, %r12
	cmpq	%rbp, %rax
	jb	.L424
.L423:
	movq	24(%rsp), %rsi
	movq	16(%rsp), %rdi
	call	_Z5Solve4spanIiE
	movq	8(%rsp), %rdi
	movq	%rax, %rbx
	call	_ZdaPv
	movl	%ebx, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	sarq	$32, %rbx
	movq	%rbx, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	64(%rsp), %rdi
	leaq	80(%rsp), %rax
	cmpq	%rax, %rdi
	je	.L469
	call	_ZdlPv
.L469:
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L434:
	.cfi_restore_state
	movq	%r14, %rax
	testq	%rbp, %rbp
	je	.L435
	jmp	.L433
	.p2align 4,,10
	.p2align 3
.L473:
	xorl	%edx, %edx
	leaq	48(%rsp), %rsi
	leaq	96(%rsp), %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm
.LEHE8:
	movq	48(%rsp), %rdx
	movq	%rax, 96(%rsp)
	movq	%rdx, 112(%rsp)
.L433:
	movq	%rbp, %rdx
	movq	%r13, %rsi
	movq	%rax, %rdi
	call	memcpy
	movq	48(%rsp), %rbp
	movq	96(%rsp), %rax
	jmp	.L435
	.p2align 4,,10
	.p2align 3
.L452:
	movl	%r13d, %ebx
	xorl	%edi, %edi
	jmp	.L425
.L437:
	movl	$.LC8, %edi
.LEHB9:
	call	_ZSt20__throw_out_of_rangePKc
.L474:
	movl	$.LC8, %edi
	call	_ZSt24__throw_invalid_argumentPKc
.LEHE9:
.L472:
	movl	$.LC7, %edi
.LEHB10:
	call	_ZSt19__throw_logic_errorPKc
.L471:
	movq	%rbp, %rcx
	movl	$.LC5, %esi
	movl	$.LC6, %edi
	xorl	%eax, %eax
	call	_ZSt24__throw_out_of_range_fmtPKcz
.LEHE10:
.L454:
	movq	%rax, %rbx
	vzeroupper
	jmp	.L449
.L455:
	movq	%rax, %rbx
	jmp	.L442
	.section	.gcc_except_table
.LLSDA8306:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8306-.LLSDACSB8306
.LLSDACSB8306:
	.uleb128 .LEHB7-.LFB8306
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB8-.LFB8306
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L454-.LFB8306
	.uleb128 0
	.uleb128 .LEHB9-.LFB8306
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L455-.LFB8306
	.uleb128 0
	.uleb128 .LEHB10-.LFB8306
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L454-.LFB8306
	.uleb128 0
.LLSDACSE8306:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDAC8306
	.type	main.cold.109, @function
main.cold.109:
.L418:
	.cfi_def_cfa_offset 192
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
.LEHB11:
	call	__cxa_throw_bad_array_new_length
.L442:
	cmpl	$0, 0(%rbp)
	jne	.L443
	movl	%r15d, 0(%rbp)
.L443:
	movq	96(%rsp), %rdi
	leaq	112(%rsp), %rax
	cmpq	%rax, %rdi
	je	.L468
	vzeroupper
	call	_ZdlPv
.L449:
	movq	64(%rsp), %rdi
	leaq	80(%rsp), %rdx
	cmpq	%rdx, %rdi
	je	.L450
	call	_ZdlPv
.L450:
	movq	%rbx, %rdi
	call	_Unwind_Resume
.LEHE11:
.L468:
	vzeroupper
	jmp	.L449
	.cfi_endproc
.LFE8306:
	.section	.gcc_except_table
.LLSDAC8306:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC8306-.LLSDACSBC8306
.LLSDACSBC8306:
	.uleb128 .LEHB11-.LCOLDB9
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
.LLSDACSEC8306:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold.109, .-main.cold.109
.LCOLDE9:
	.section	.text.startup
.LHOTE9:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z12getByteIndexi, @function
_GLOBAL__sub_I__Z12getByteIndexi:
.LFB9048:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE9048:
	.size	_GLOBAL__sub_I__Z12getByteIndexi, .-_GLOBAL__sub_I__Z12getByteIndexi
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z12getByteIndexi
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC1:
	.byte	15
	.byte	14
	.byte	13
	.byte	12
	.byte	11
	.byte	10
	.byte	9
	.byte	8
	.byte	7
	.byte	6
	.byte	5
	.byte	4
	.byte	3
	.byte	2
	.byte	1
	.byte	0
	.byte	15
	.byte	14
	.byte	13
	.byte	12
	.byte	11
	.byte	10
	.byte	9
	.byte	8
	.byte	7
	.byte	6
	.byte	5
	.byte	4
	.byte	3
	.byte	2
	.byte	1
	.byte	0
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
