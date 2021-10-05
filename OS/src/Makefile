C_SOURCES = $(wildcard kernel/*.c cpu/*.c)
HEADERS = $(wildcard kernel/*.h cpu/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o} 

# Change this if your cross-compiler is somewhere else
CC = /usr/bin/gcc
GDB = /usr/bin/gdb
# -g: Use debugging symbols in gcc
CFLAGS = -fno-pie -g -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs \
		 -Wall -Wextra

main: clean os-image.bin

# First rule is run by default
os-image.bin: Bootloader/boot.bin kernel.bin
	cat $^ > os-image.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: Bootloader/kernel_entry.o ${OBJ}
	ld $^ --oformat binary -o $@ -Ttext 0x1000

# Used for debugging purposes
kernel.elf: Bootloader/kernel_entry.o ${OBJ}
	ld $^ -o $@ -Ttext 0x1000 

run: main os-image.bin
	qemu-system-i386 -fda os-image.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: clean os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin -S &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf" -ex "b main" -ex "c"

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf64 -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf kernel/*.o Bootloader/*.bin drivers/*.o Bootloader/*.o cpu/*.o libc/*.o