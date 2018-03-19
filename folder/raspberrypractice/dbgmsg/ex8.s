	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"ex8.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"string1string2\000"
	.align	2
.LC1:
	.ascii	"I am shchoi82.\000"
	.align	2
.LC2:
	.ascii	"I am shchoi82..\000"
	.align	2
.LC3:
	.ascii	"Hi\000"
	.align	2
.LC4:
	.ascii	"I am shchoi82...\000"
	.align	2
.LC5:
	.ascii	"str2\000"
	.align	2
.LC6:
	.ascii	"val1: %d\012\000"
	.align	2
.LC7:
	.ascii	"val2: %d\012\000"
	.align	2
.LC8:
	.ascii	"str1: %s\012\000"
	.align	2
.LC9:
	.ascii	"str2: %s\012\000"
	.align	2
.LC10:
	.ascii	"str3: %s\012\000"
	.align	2
.LC11:
	.ascii	"str4: %s\012\000"
	.align	2
.LC12:
	.ascii	"str5: %s\012\000"
	.align	2
.LC13:
	.ascii	"str6: %s\012\000"
	.align	2
.LC14:
	.ascii	"str7: %s\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #40
	mov	r3, #3
	str	r3, [fp, #-8]
	mov	r3, #6
	str	r3, [fp, #-12]
	ldr	r3, .L3
	str	r3, [fp, #-16]
	ldr	r3, .L3+4
	str	r3, [fp, #-20]
	ldr	r3, .L3+8
	str	r3, [fp, #-24]
	ldr	r3, .L3+12
	str	r3, [fp, #-28]
	ldr	r3, .L3+16
	str	r3, [fp, #-32]
	ldr	r3, [fp, #-16]
	str	r3, [fp, #-36]
	ldr	r3, .L3+20
	str	r3, [fp, #-40]
	ldr	r0, .L3+24
	ldr	r1, [fp, #-8]
	bl	printf
	ldr	r0, .L3+28
	ldr	r1, [fp, #-12]
	bl	printf
	ldr	r0, .L3+32
	ldr	r1, [fp, #-16]
	bl	printf
	ldr	r0, .L3+36
	ldr	r1, [fp, #-20]
	bl	printf
	ldr	r0, .L3+40
	ldr	r1, [fp, #-24]
	bl	printf
	ldr	r0, .L3+44
	ldr	r1, [fp, #-28]
	bl	printf
	ldr	r0, .L3+48
	ldr	r1, [fp, #-32]
	bl	printf
	ldr	r0, .L3+52
	ldr	r1, [fp, #-36]
	bl	printf
	ldr	r0, .L3+56
	ldr	r1, [fp, #-40]
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, pc}
.L4:
	.align	2
.L3:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	.LC7
	.word	.LC8
	.word	.LC9
	.word	.LC10
	.word	.LC11
	.word	.LC12
	.word	.LC13
	.word	.LC14
	.size	main, .-main
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
