section .data
	hello db "Hello, Holberton", 0

section .text
	global main

	extern printf

main:
	push rdi
	lea rdi, [hello]
	call printf
	pop rdi

	mov eax, 0
	ret

