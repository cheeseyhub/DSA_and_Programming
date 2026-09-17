section .data

section .text
global _start

_start:
    MOV eax , 20
    MOV ebx , 20
    SUB eax, ebx
    jz _start
    




section .bss
    buffer: resb 14
