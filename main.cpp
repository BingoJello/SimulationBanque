// main function
#include <iostream>
#include "header/Bank.h"

int main() {
    Bank *b = new Bank(400, 3);
    b->run();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
