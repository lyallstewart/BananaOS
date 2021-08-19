#include <stdlib.h>
#include "utils.h"
#include "print.h"

#define WELCOME "Welcome to BananaOS"
void *malloc(size_t size) {return malloc(size);}

void thisIsNotNeededButItBreaksIfWeDeleteIt() {}

void main() {
    const char welcome[] = "Welcome to BananaOS";
    print(welcome);
    const char kbd[] = "Now loading: keyboard driver";

    const char blah[] = "abcdefghijklmnopqrstuvqxyz.,!!!!!!!!?,.<>(){}[]eeeeeeeeeeeeeeeef";
    print(blah);
    //print(kbd);
}