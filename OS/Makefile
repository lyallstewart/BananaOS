C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)
# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o}

# Change this if your cross-compiler is somewhere else
CC = /usr/bin/gcc
GDB = /usr/bin/gdb
# -g: Use debugging symbols in gcc
CFLAGS = -g -std=c99 -m32 -fno-pie

# First rule is run by default
bin/os.bin: bin/boot.bin bin/kernel.bin
	cat $^ > os.bin

# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
bin/kernel.bin: bin/kernel_entry.o bin/kernel.o
	ld -m elf_i386 -s -o $@ -Ttext 0x1000 $^ --oformat binary

# Used for debugging purposes
bin/kernel.elf: bin/kernel_entry.o bin/kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ 

run: clean bin/os.bin
	qemu-system-x86_64 -fda os.bin

# Open the connection to qemu and load our kernel-object file with symbols
debug: clean bin/os.bin bin/kernel.elf
	qemu-system-x86_64 -s -fda os.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file bin/kernel.elf"

# Generic rules for wildcards
# To make an object, always compile from its .c
bin/%.o: src/Kernel/%.c 
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

bin/%.o: src/Kernel/%.asm
	nasm $< -f elf -o $@

bin/%.bin: src/Bootloader/%.asm
	nasm $< -f bin -o $@

bin/%.bin: src/Bootloader/x86/%.asm
	nasm $< -f bin -o $@


clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf bin/*.o bin/*.bin