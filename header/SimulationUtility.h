//
// Created by arthur on 10/09/2022.
//

#ifndef SIMULATIONBANQUE_SIMULATIONUTILITY_H
#define SIMULATIONBANQUE_SIMULATIONUTILITY_H

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <random>
using namespace std;

class SimulationUtility {
public:
    static void init(int seed = 0) {
        srand(seed ? seed : getpid());
    }

    static double getValue(double moy = 1.0) {
        return -log(((double)rand()/RAND_MAX))*moy;
    }

    /* Generate random doubles between min and max in an array */
    static void genRandomDoubles(double min, double max, double** arr, int arrSize) {
        uniform_real_distribution<double> unif(min, max);
        random_device rd;
        default_random_engine re(rd());
        for(int i=0 ; i<arrSize ; i++) {
            *(*arr+i) = unif(re);
        }
    }
};


#endif //SIMULATIONBANQUE_SIMULATIONUTILITY_H
