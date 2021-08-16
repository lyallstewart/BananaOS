extern BEGIN_PM

[bits 16]
switch_to_pm:
    cli                                 ; disable interrupts
    lgdt [gdt_descriptor]               ; load gdt
    mov eax, cr0
    or eax, 0x1                         ; set 32-bit mode
    mov cr0, eax
    jmp CODE_SEG:init_pm                ; far jump by using a different segment



[bits 32]
init_pm:                                ; this uses 32-bit instructions
    mov ax, DATA_SEG                    ; update segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000                    ; update stack
    mov esp, ebp

    call BEGIN_PM                       ; run boot code