//
// Created by arthur on 10/09/2022.
//

#include "header/SimulationUtility.h"
#include <random>
using namespace std;

double* SimulationUtility::getRandomValue(int min, int max, int nbr) {
    double* values = new double[nbr];
    random_device rd;
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(min, max); // define the range
    for(int i=0; i<nbr; i++){
        values[i] = (double)distr(gen);
    }
    return values;
}