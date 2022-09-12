// main function
#include <iostream>
#include "header/Bank.h"

int main() {
    Bank *b = new Bank(10.0, 3, 0.6, 1.0);
    b->run();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
