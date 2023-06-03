.globl my_ili_handler

.text
.align 4, 0x90
my_ili_handler:
  pushq	%r12
	xorq	%rdi, %rdi

	movq	8(%rsp), %r12
	subq	$8, %r12
	movb	(%r12), %dil
	cmpb	$0x0F, %dil
	jne one_byte
	movb	1(%r12), %dil
one_byte:
	call	what_to_do
	movq	%rax, %rdi
	cmpq	$0, %rdi
	jne	end

	popq	%r12
	call	old_ili_handler
	iretq
end:
	popq	%r12
	iretq
  