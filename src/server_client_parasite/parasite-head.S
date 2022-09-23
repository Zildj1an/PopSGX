#include "common/asm/linkage.h"

	.section .head.text, "ax"

#define CONFIG_X86_64
#ifndef CONFIG_X86_64
# error 64-bit parasite should compile with CONFIG_X86_64
#endif

.macro PARASITE_ENTRY num
	subq	$16, %rsp
	andq	$~15, %rsp
	pushq	$\num
	movq	%rsp, %rbp
	movl	__export_parasite_cmd(%rip), %edi
	leaq	__export_parasite_args(%rip), %rsi
	call	parasite_service
.endm

ENTRY(__export_parasite_head_start)
	PARASITE_ENTRY 0
	int	$0x03
END(__export_parasite_head_start)

.align 8
GLOBAL(__export_parasite_cmd)
	.long 0
