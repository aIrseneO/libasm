; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/10 16:30:05 by atemfack          #+#    #+#              ;
;    Updated: 2020/11/17 23:48:41 by atemfack         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	ft_strcmp				; Declaration of the main function
section .text

; The input will be held in the register rdi (s1) and rsi (s2)

ft_strcmp:						; This is the main function
	mov rcx, 0					; initialize the counter to 0
	mov rax, 0					; initialize temp register rax
	mov rdx, 0					; initialize temp register rdx
	jmp compare					; jump to the comparison function

increment:						; this is the increment function
	inc rcx						; increment the value of the counter

compare:						; function that does the comparison
	mov al, byte [rdi + rcx]	; copy char[rcx] from s1 (rdi) to register al
	mov dl, byte [rsi + rcx]	; copy char[rcx] from s2 (rsi) to register dl
	cmp al, 0					; check if end of word
	je return_value				; if true jump to the return_value function
	cmp al, dl					; compare char[rcx] of s1 and s2
	je increment				; if equal increment the counter rcx

return_value:
	sub rax, rdx				; calculate the return value
	ret
