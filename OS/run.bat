cd Bootloader
nasm -fbin "C:\Users\Lyall Stewart\Documents\GitHub\BananaOS\OS\Bootloader\boot.asm" -o "C:\Users\Lyall Stewart\Documents\GitHub\BananaOS\OS\bin\boot.bin"

pause

qemu-system-x86_64 "C:\Users\Lyall Stewart\Documents\GitHub\BananaOS\OS\bin\boot.bin"

pause