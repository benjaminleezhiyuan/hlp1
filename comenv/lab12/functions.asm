; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 12
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: Benjamin Lee, benjaminzhiyuan.lee@digipen.edu
;
; Compile: nasm -f elf64 -g -F dwarf functions.asm -o functions.o
; Link: gcc main.o functions.o -o main.o -lm
; Run: ./main 0
; Debug: gdb main
;  (gdb) b len
;  (gdb) run
;  0
;  ...
;  To see a string in memory by address in rdi use gdb's command:
;  (gdb) p/d (char[20]) *$rdi
;   ...
;
; Copyright: 2021, Digipen Institute of Technology, Singapore
;
; Note: All functions use at most 6 parameters
;      p1, p2, p3, p4, p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
; Note 2: Use instruction cmp byte [rdi+rcx], 0 to campare
;         a byte by adddress rdi*rci with 0
; ------------------------------------------------------------------
    section .text

    global len
    global countn
    global counta
    global counts

len:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the length of the string.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
    mov rax,0
    mov r11, 0
    cmp byte [rdi+r11],0
    jne notempty
    ret

    notempty:
    add rax,1
    add r11,1
    cmp byte [rdi+r11],0
    loopne notempty
    ret    ; return rax;

countn:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the number of digits in 
;         the string.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
; Hints:- Digit '0' has ASCII code 48, '1' - 49, ... '9' - 57.
;       - You can use your function len.
    call len
    cmp rax , 0
    je end_n
    mov rcx, rax
    mov r11, 0

next_n:
    cmp byte [rdi+rcx],57
    jg notinrange_n
    cmp byte [rdi+rcx],48
    jl notinrange_n
    jmp inrange_n
    
notinrange_n:
    loopnz next_n
    jmp check_n

inrange_n:
    inc r11
    loopnz next_n
    jmp check_n

check_n:
    cmp byte [rdi],57
    jg n_2
    cmp byte [rdi],48
    jl n_2
    inc r11
    mov rax, r11
    ret

n_2:
    mov rax, r11
    ret

end_n:
    ret

counta:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the number of alphabet letters in 
;         the string.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
; Hints:- Letters have ASCII codes 65-90 and 97-122.
;       - You can use your function len.

    call len
    cmp rax , 0
    je end_a
    mov rcx, rax
    mov r12, 0

next_a:
    cmp byte [rdi+rcx],90
    jg notinrange_a
    cmp byte [rdi+rcx],65
    jl notinrange_a
    jmp inrange_a

notinrange_a:
    cmp byte [rdi+rcx],122
    jg notinrange_a2
    cmp byte [rdi+rcx],97
    jl notinrange_a2

    jmp inrange_a

notinrange_a2:
loopnz next_a
jmp check_a

inrange_a:
inc r12
loopnz next_a
jmp check_a

check_a:
    cmp byte [rdi],90
    jg a2
    cmp byte [rdi],65
    jl a2
    inc r12
    mov rax,r12
    ret

a2:
    cmp byte [rdi],122
    jg a3
    cmp byte [rdi],97
    jl a3
    inc r12
    mov rax,r12
    ret
a3:
    mov rax,r12
    ret

end_a:
    ret

counts:
; TODO: - Given a null-terminated string. First parameter 
;         has address of the string.
;       - Find and return the number of special characters in 
;         the string.
;       - Special character is a character which is neither a digit
;         not a letter.
;       - The string can be any length. When empty, return 0.
;       - It's not allowed to use any standard library function.
; Hint: - You can use your functions len, countn, and counta.
    call len
    mov r13,rax
    call countn
    mov r14,rax
    call counta
    add r14,rax
    sub r13,r14
    mov rax,r13
    
    ret    ; return rax