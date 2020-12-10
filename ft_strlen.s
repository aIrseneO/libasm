; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/10 16:30:05 by atemfack          #+#    #+#              ;
;    Updated: 2020/11/17 23:48:41 by atemfack         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text
global	ft_strlen				; Declaration of the main function

; The argument will be held by the register rdi

ft_strlen:						; This is the main function
	mov	rax, 0					; initialize counter to 0
	jmp	comparison				; jump to the comparison function

increment:						; this is the increment function
	inc rax						; just increment the value of the counter

comparison:
	cmp BYTE [rdi + rax], 0		; compare character in the argument to '\0'
	jne increment				; jump to increment function if char is not '\0'
	ret							; return otherwise
