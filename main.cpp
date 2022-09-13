// main function
#include <iostream>
#include "header/Bank.h"
#include "header/SimulationUtility.h"

int main() {
    SimulationUtility::init();
    double* averageServiceTimes = new double[3];
    SimulationUtility::genRandomDoubles(4, 15, &averageServiceTimes, 3);

    Bank *b = new Bank(10.0, 3, 0.6, averageServiceTimes);
    b->run();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
