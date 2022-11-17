; ------------------------------------------------------------------
; File: functions.asm
; Project: CSD1100 Assignment 11
; Author: Vadim Surov, vsurov@digipen.edu
; Co-Author: Benjamin Lee, benjamizhiyuan.lee@digipen.edu
;
; Compile: nasm -f elf64 -g -F dwarf functions.asm -o functions.o
; Link: gcc main.o functions.o -o main.o -lm
; Run: ./main 0
; Debug: gdb main
;  (gdb) b f1
;  (gdb) run
;  ...
;  0
;  ...
;  (gdb) ...
;
; Copyright: 2021, Digipen Institute of Technology, Singapore
;
; Note: All functions use at most 6 parameters
;      p1, p2, p3, p4, p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.
; ------------------------------------------------------------------

    section .text

    global f1
    global f2
    global f3
    global f4
    global f5

f1:
; TODO: - Given two circles with central points at (p1,p2), (p3,p4),
;       and radii p5, p6. All values in p1, ..., p6 are integers.
;       - Create code that determins intersection
;       or non-intersection of the circles.
;       - You code must return 1 when intersecting or 0 otherwise
;       based on the result of calculation.
;       - Tip 1: use the method without square root calculations:
;       if (p1-p3)^2+(p2-p4)^2 <= (p5+p6)^2 then return 1
;       - Tip 2: do not use pow() function to calculate x^2, use 
;       x*x instead.
;       - Note that a point is a circle with radius 0.
    sub rdi, rdx ; p1-p3
    sub rsi, rcx ; p2-p4
    add r8,r9 ; p5+p6

    mov rax, rdi ; move p1-p3 to rax
    imul rax ; multiply p1-p3 by itself
    mov r13,rax ; store (p1-p3)^2 to r13

    mov rax, rsi; move p2-p3 to rax
    imul rax; multiply p2-p3 by itself
    mov r14,rax; store (p2-p4)^2 to r14

    add r13,r14; store (p1-p3)^2+(p2-p4)^2 into r13

    mov rax, r8; move p5+p6 to rax
    imul rax; multiply p5+p6 by itself
    mov r8,rax; store (p5+p6)^2 to r14

    cmp r13,r8; compare (p1-p3)^2+(p2-p4)^2 and (p5+p6)^2
    jle then; if r13 is less or equal to r14 jump to then

    xor rax,rax; else jump to end
    jmp end;

    then:
        mov rax, 1
    end:
        ret    ; return rax;
f2:
; TODO: - Calculare (p1+0)*(p2+0) + (p1+1)*(p2+1) + (p1+2)*(p2+2) + .... +
;           (p1+p3)*(p2+p3)
;       - Tip: Accumulate the result in reverse order by decrementing 
;           p3 or (p1+p3) and (p2+p3)
;      p1, p2, p3, p4, p5, p6
;      located in registers
;      rdi, rsi, rdx, rcx, r8, r9
;      accordingly.

    mov rcx, rdx ; mov p3 to rcx
    mov r13, rdi; mov p1 to r13
    mov r14, rsi; mov p2 to r14
    imul r13,r14
    mov r15,r13
    cmp rcx,0 ; compare rcx to 0
    jle return
    xor rax,rax

    repeat:
    mov r13, rdi; mov p1 to r13
    mov r14, rsi; mov p2 to r14

    add r13,rcx
    add r14,rcx

    mov rax,r13
    imul r14
    add r15,rax

    loopnz repeat

    return:
    mov rax, r15; move p1 to rax
    ret; return rax