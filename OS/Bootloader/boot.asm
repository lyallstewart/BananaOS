extern print
extern print_nl

[org 0x7c00] ; tell the assembler that our offset is bootsector code

; The main routine makes sure the parameters are ready and then calls the function
mov bx, start
call print

call print_nl

; that's it! we can hang now
jmp $

; remember to include subroutines below the hang
%include "print.asm"


; data
start:
    db 'BananaOS Starting...', 0

; padding and magic number
times 510-($-$$) db 0
dw 0xaa55