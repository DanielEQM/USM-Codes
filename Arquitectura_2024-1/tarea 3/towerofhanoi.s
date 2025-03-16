	.data
n: .word 3
a: .word 1
c: .word 3
b: .word 2
l: .word

	.text
main:
	mov r0, #0
	mov r2, #0
	ldr r3, =n
	ldr r3, [r3]
	push {r3}
	mov r8, r3
	bl hanoi
	b fin

hanoi:
	cmp r3, #1
	beq if
	bl nodo1
	b fin

if:
	add r2, r2, #1
	mov pc, lr

nodo1:
	sub r3, r3, #1
	push {r3}
	bl hanoi
	pop {r3}
	add r2, r2, #1
	bl hanoi
	b nodo2

nodo2:
	pop {r3}
	cmp r3, r8
	beq fin
	add r2, r2, #1
	bl nodo1

fin:
	bl printInt
	wfi
