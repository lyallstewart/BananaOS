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
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000                      ; set the stack safely away from us
mov sp, bp




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
call print_nl


call load_kernel
call switch_to_pm
      
jmp $                               ; Never executed

%include "src/Bootloader/disk.asm"
%include "src/Bootloader/print.asm"
%include "src/Bootloader/print_hex.asm"
%include "src/Bootloader/x86/x86_gdt.asm"
%include "src/Bootloader/x86/x86_print.asm"
%include "src/Bootloader/x86/x86_switch.asm"
[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl
    mov bx, KERNEL_OFFSET
    mov dh, 2
    mov dl, [BOOT_DRIVE]
    call load_disk
    ret
[bits 32]
BEGIN_PM:                           ; after the switch we will get hre
    ; Note that this will be written at the top left corner
    mov ebx, MSG_STARTUP
    call print_clear
    call print_string_start
    call KERNEL_OFFSET
    jmp $

; data
MSG_REAL_MODE: db "Started in 16-bit", 0
MSG_LOAD_KERNEL: db "Loading Kernel", 0
MSG_STARTUP: db "Loading BananaOZ", 0
BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xaa55
