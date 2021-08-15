extern print
extern print_nl
extern print_hex
extern load_disk
extern gdt_descriptor
extern load_gdt
extern switch_to_pm
extern print_string_start
extern print_clear

[org 0x7c00]
mov bp, 0x9000                      ; set the stack safely away from us
mov sp, bp

mov bx, start
call print
call print_nl

;mov bx, 0x9000 ; es:bx = 0x0000:0x9000 = 0x09000
;mov dh, 2                          ; read 2 sectors
;call load_disk

;mov dx, [0x9000]                   ; retrieve the first loaded word, 0xdada
;call print_hex
;call print_nl

;mov dx, [0x9000 + 512]             ; first word from second loaded sector, 0xface
;call print_hex

mov bx, MSG_REAL_MODE
call print
call switch_to_pm
      
jmp $                               ; Never executed

%include "print.asm"
%include "disk.asm"
%include "print_hex.asm"
%include "./x86/x86_gdt.asm"
%include "./x86/x86_print.asm"
%include "./x86/x86_switch.asm"

[bits 32]
BEGIN_PM:                           ; after the switch we will get hre
    mov ebx, MSG_PROT_MODE
	call print_clear
    call print_string_start         ; Note that this will be written at the top left corner
    
    mov ebx, MSG_STARTUP
    call print_clear
    call print_string_start
    jmp $

; data
start: db "BananaOS Starting...", 0
MSG_REAL_MODE: db "Started in 16-bit real mode", 0
MSG_PROT_MODE: db "Loaded 32-bit protected mode...", 0
MSG_STARTUP: db "Loading BananaOS...", 0


times 510-($-$$) db 0
dw 0xaa55

times 256 dw 0xdada                 ; sector 2 = 512 bytes
times 256 dw 0xface                 ; sector 3 = 512 bytes