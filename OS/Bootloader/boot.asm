[org 0x7c00]

mov bp, 0x8000			 ; this is an address far away from 0x7c00 so that we don't get overwritten
mov sp, bp				 ; if the stack is empty then sp points to bp

mov ah, 0x0e			 ; tty mode

mov al, 'H'
int 0x10
mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
int 0x10                 ;'l' is still on al, remember?
mov al, 'o'
int 0x10
mov al, ' '
int 0x10
mov al, 'W'
int 0x10
mov al, 'o'
int 0x10
mov al, 'r'
int 0x10
mov al, 'l'
int 0x10
mov al, 'd'
int 0x10
mov al, '!'
int 0x10


helloWorld:
	db "Hello, World!", 0

mov bx, helloWorld

printString:
	  

jmp $                    ; jump to current address = infinite loop

times 510 - ($-$$) db 0  ; padding and magic number
dw 0xaa55 


