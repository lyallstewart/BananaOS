#include "utils.h"
#include "print.h"

#define WELCOME "Welcome to BananaOS"

void thisIsNotNeededButItBreaksIfWeDeleteIt() {}

void main() {
    const char welcome[] = "Welcome to BananaOS";
    print(welcome);
    const char longstr[] = "abcdefghijklmnopqrstuvqxyz.,!!!!!!!!?,.<>(){}[]eeeeeeeeeeeeeeee";
    print(longstr);
    const char kbd[] = "Now loading: keyboard driver";
    print(kbd);
}