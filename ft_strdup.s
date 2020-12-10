; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: atemfack <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/11/10 16:30:05 by atemfack          #+#    #+#              ;
;    Updated: 2020/11/17 23:48:41 by atemfack         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global ft_strdup				; Declaration of the main function
section .text

extern malloc					; Declaration of malloc for the new string

; The argument will be held in the register rdi

ft_strdup:						; This is the main function
	cmp rdi, 0					; check if argument is NULL
	je _error					; if NULL jump to the error label
	mov rcx, -1					; set the counter to -1 for mystrlen

mystrlen:						; This is the strlenght label
	inc rcx						; increment the counter
	cmp byte [rdi + rcx], 0		; compare character in the argument to '\0'
	jne mystrlen				; loop until the end is reach

	push rdi					; save rdi on the stack, malloc uses register rdi
	mov rdi, rcx				; put the lenght to be allocated in rdi
	call malloc wrt ..plt		; allocate size for the new string
	cmp rax, 0					; check if the new string is NULL
	je _error					; if it's NULL there is an error, jump to error
	pop rdi						; pull rdi from the stack
	mov rcx, -1					; use rcx as a counter for the copy

mystrcpy:						; This is the copy label
	inc rcx						; increment the counter
	mov dl, byte [rdi + rcx]	; copy char from srcs (rdi) to the register dl
	mov byte [rax + rcx], dl	; copy char from dl to the destination (rax)
	cmp dl, 0					; compare dl to '\0' (end of word)
	jne mystrcpy				; loop if end of word isn't reached

	ret							; return

_error:							; This is the error function
	mov rax, 0					; set the return value to NULL
	ret							; return
