[bits 32]

VIDEO_MEMORY equ 0xb8000
VIDEO_MEMORY_END equ 0xb8fa0
COLOR equ 0x0e
BLANK equ " "

print_clear:
	pusha
	mov edx, VIDEO_MEMORY
	mov al, BLANK
	mov ah, COLOR
	clear_loop:
		cmp edx, VIDEO_MEMORY_END
		je print_string_done
		mov [edx], ax
		add edx, 2
		jmp clear_loop

print_string_start:
	pusha
	mov edx, VIDEO_MEMORY

print_string:
	mov al, [ebx]
	mov ah, COLOR

	cmp al, 0
	je print_string_done
	mov [edx], ax

	add ebx, 1
	add edx, 2
	jmp print_string

print_string_done:
	popa
	ret