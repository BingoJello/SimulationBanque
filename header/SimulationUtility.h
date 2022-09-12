//
// Created by arthur on 10/09/2022.
//

#ifndef SIMULATIONBANQUE_SIMULATIONUTILITY_H
#define SIMULATIONBANQUE_SIMULATIONUTILITY_H

#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

class SimulationUtility {
public:
    static void init(int seed = 0) {
        srand(seed ? seed : getpid());
    }

    static double getValue(double moy = 1.0) {
        return -log(((double)rand()/RAND_MAX))*moy;
    }
};


#endif //SIMULATIONBANQUE_SIMULATIONUTILITY_H
