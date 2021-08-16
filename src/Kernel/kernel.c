#include "print.h"

void thisIsNotNeededButItBreaksIfWeDeleteIt() {}

void main() {
    static const char welcome[] = "Welcome to BananaOS";
    print(welcome,19);
}