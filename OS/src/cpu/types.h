#ifndef TYPES_H
#define TYPES_H

typedef unsigned int   u32;
typedef          int   s32;
typedef unsigned short u16;
typedef          short s16;
typedef unsigned char  u8;
typedef          char  s8;

#define low_16(address) (u16)((address) & 0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)
// This allows us to refer to an unsigned int with a more semantic name instead of "u32", etc, etc

#define KERNEL_CS 0x08

/* How every interrupt gate (handler) is defined */
typedef struct {
    u16 low_offset; /* Lower 16 bits of handler function address */
    u16 sel; /* Kernel segment selector */
    u8 always0;
    /* First byte
     * Bit 7: "Interrupt is present"
     * Bits 6-5: Privilege level of caller (0=kernel..3=user)
     * Bit 4: Set to 0 for interrupt gates
     * Bits 3-0: bits 1110 = decimal 14 = "32 bit interrupt gate" */
    u8 flags; 
    u16 high_offset; /* Higher 16 bits of handler function address */
} __attribute__((packed)) idt_gate_t ;

/* A pointer to the array of interrupt handlers.
 * Assembly instruction 'lidt' will read it */
typedef struct {
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;


/* Functions implemented in idt.c */
void set_idt_gate(int n, u32 handler);
void set_idt();

#endif