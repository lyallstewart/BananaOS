#include "utils.h"
#include "print.h"
#include "../cpu/isr.h"
/*
PRINT FUNCTIONS:
print(string) = print characters, keep previous color
print_color(string,color) = print characters override color
print_fill_color(color) = override all color to this
print_clear() = remove all text, keep colors
print_nuke() = remove all text, reset colors
print_nl(int) = print so many new lines

please use print_nl(1) over print("") for printing a newline.
 print("") just calls print_nl(1) but after a bunch of other code.
*/

u8 port_byte_in (u16 port) {
    u8 result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}
void main() {
    print_nuke();//allows scrolling to work.
    print_fill_color(0xf0);
    print_col_at(" ", 0xb0, 40, 10);

    for(;;) {
        u8 scancode = port_byte_in(0x60);

        if (scancode == 72) {
            print_col_at("U", 0xb0, 40, 10);
        }
        if (scancode == 80) {
            print_col_at("D", 0xb0, 40, 10);
        }
        if (scancode == 75) {
            print_col_at("L", 0xb0, 40, 10);
        }
        if (scancode == 77) {
            print_col_at("R", 0xb0, 40, 10);
        }
    }
    
}