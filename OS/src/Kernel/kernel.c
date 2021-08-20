#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "print.h"
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

void *malloc(size_t size) {return malloc(size);}

void main() {
    print_nuke();//allows scrolling to work.
    
    print_nl(2);
    print("  ____                                 ____   _____         ");
    print(" |  _ \\                               / __ \\ / ____|        ");
    print(" | |_) | __ _ _ __   __ _ _ __   __ _| |  | | (___          ");
    print(" |  _ < / _` | '_ \\ / _` | '_ \\ / _` | |  | |\\___ \\         ");
    print(" | |_) | (_| | | | | (_| | | | | (_| | |__| |____) |  _ _ _ ");
    print(" |____/ \\__,_|_| |_|\\__,_|_| |_|\\__,_|\\____/|_____/  (_|_|_)");

    print_nl(2);
    print("Welcome to BananaOS (v0.0.1a)");
    print_nl(1);

    print("[1/2] Kernal Files Loading...");
    print_color("[1/2] Kernal Files Loaded", 0x02);
    print_nl(1);

    print("[2/2] Loading CPU interrupts");

    int i;
    for (i = 0; i < 15; i++)
    {   
        print("123456789abcdefghijklmnop" + i);
    }
    
    
}