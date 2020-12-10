; ./run try <-- to run the program

;db define bite
%macro		printDigit 1
			mov rax, %1
			call _printDigit
%endmacro

%macro		exit 0
			mov rax, 60
			mov rdi, 0
			syscall
%endmacro

section	.data
			text db "Hello, World!",10
			text2 db "Hello, world!",10
			digit db 0,10

section	.text
			global	_start

_start:
			call _print
			printDigit 4
			mov rax, 0

			exit


_printDigit:
			add rax, 48
			mov [digit], al
			
			mov rax, 1
			mov rdi, 1
			mov rsi, digit
			mov rdx, 2
			syscall
			ret

_print:
			mov rax, 1
			mov rdi, 1
			mov rsi, text
			mov rdx, 14
			syscall
			ret

_printLoop:
			inc rax
			inc rbx
			mov cl, [rax]
			cmp cl, 0
			jne _printLoop

			mov rax, 1
			mov rdi, 1
			pop rsi
			mov rdx, rbx
			syscall
			ret
