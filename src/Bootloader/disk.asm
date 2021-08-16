extern print
extern print_nl
extern print_hex

; load 'dh' sectors from drive 'dl' into ES:BX

load_disk:
	pusha
	push dx

	mov ah, 0x02
	mov al, dh
	mov cl, 0x02
	mov ch, 0x00
	;dl = drive number
	mov dh, 0x00

	int 0x13

	jc disk_error
    
    pop dx

    cmp al, dh ;check what we got is what we wanted
    jne sectors_error
    
	mov bx, SUCCESS
	call print
 
	popa
    ret
disk_error:
    mov bx, DISK_ERROR
    call print
    call print_nl
    mov dh, ah ; ah = error code, dl = disk drive that dropped the error
    call print_hex ; check out the code at http://stanislavs.org/helppc/int_13-1.html
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print
    call print_nl
    mov dl, al ; ah = error code, dl = disk drive that dropped the error
    call print_hex ; check out the code at http://stanislavs.org/helppc/int_13-1.html
    jmp disk_loop

disk_loop:
    jmp $

DISK_ERROR: db "read error", 0
SECTORS_ERROR: db "sector error", 0
SUCCESS: db "Disk loaded...", 0