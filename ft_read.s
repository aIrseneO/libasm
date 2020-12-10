; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/10 16:30:05 by atemfack          #+#    #+#              ;
;    Updated: 2020/11/17 23:48:41 by atemfack         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_read					; Declaration of the main function
extern __errno_location			; Declaration of the external error function
section .text

; The arguemnts will be held by the registers rdi(fd), rsi(buf) and rdx(count)

ft_read:						; This is the main function
	mov rax, 0					; system call for read
	syscall						; invoke operating system to do the write
	cmp rax, 0					; compare the number of char read to 0
	jl error					; if it's less than 0 jump to error
	ret							; if it's just return

error:							; This is the error function
        mov r12, rax			; save errno in the preserved r12 register
        push r12				; push r12 on the stack
        call __errno_location WRT ..plt		; call the external error function
        pop r12					; pull the errno from the stack
        neg r12					; make it negative
        mov [rax], r12			; put the errno in the value
        mov rax, -1				; set the return value to -1
        ret						; return
