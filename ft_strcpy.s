; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/10 16:30:05 by atemfack          #+#    #+#              ;
;    Updated: 2020/11/17 23:48:41 by atemfack         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	ft_strcpy				; Declaration of the main function
section	.text

; The arguments will be held in the registers rdi (destination) and rsi (source)

ft_strcpy:						; This is the main function
	mov rax, 0					; initialize the index to 0
	jmp copy

increment:						; this is the increment function
	inc rax						; just increment the value of the index

copy:							; function that does the copy
	mov cl, byte [rsi + rax]	; copy char from srcs (rsi) to register cl
	mov byte [rdi + rax], cl	; copy char from cl to destination (rdi)
	cmp cl, 0					; compare cl to '\0'
	jne increment				; if not end of srcs jump to increment function
	mov rax, rdi				; move the dest to the return string (rax)
	ret							; return
