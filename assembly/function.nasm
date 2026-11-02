section .text
global _start

add_numbers:
    push rbp               
    mov rbp, rsp           
    sub rsp, 32            

    mov [rbp - 8], rdi     
    mov [rbp - 16], rsi    

    mov rax, [rbp - 8]     
    add rax, [rbp - 16]    

    mov rsp, rbp           
    pop rbp                
    ret                    

_start:
    mov rdi, 123           
    mov rsi, 457           
    call add_numbers       

    ; --- PROPER EXIT SYSCALL ---
    ; rax already holds the result (580) from add_numbers, 
    ; but let's move it to rdi if you want it as the exit code (optional)
    mov rdi, rax           ; Program exit code will be 580 (& 255 = 68)
    mov rax, 60            ; Linux sys_exit syscall number
    syscall                ; Ask the kernel to close the program safely