#include <stdlib.h>
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

#define WELCOME "Welcome to BananaOS"
void *malloc(size_t size) {return malloc(size);}

void thisIsNotNeededButItBreaksIfWeDeleteIt() {}
void main() {
    
    print("Welcome to BananaOS");
    print("Type a command, or help for more help ,or quit to shutdown the computer. This text is temporary, just checking wrapping stuff.");

    print("BananaOS veresion alpha v0.0.1");
}