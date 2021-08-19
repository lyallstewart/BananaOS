#!/bin/bash
# A simple script

cd ..

rm "OS/bin/boot.bin"

nasm -fbin "OS/src/Bootloader/boot.asm" -o  "OS/bin/boot.bin"

nasm "OS/src/Kernel/kernel_entry.asm" -f elf -o "OS/bin/kernel_entry.o"
gcc -std=c99 -m32 -fno-pie -ffreestanding -c "OS/src/Kernel/kernel.c" -o "OS/bin/kernel.o"
ld -m elf_i386 -s -Ttext 0x1000 "OS/bin/kernel_entry.o" "OS/bin/kernel.o" --oformat binary -o "OS/bin/kernel.bin" 
nasm "OS/src/Bootloader/boot.asm" -f bin -o "OS/bin/boot.bin"
cat "OS/bin/boot.bin" "OS/bin/kernel.bin" > "OS/bin/os.bin"
read -p "Press return to start vm (WAIT UNTIL BOOTLOADER IS COMPILED!) ..."


sudo qemu-system-x86_64 "OS/bin/os.bin"