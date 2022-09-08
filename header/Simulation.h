//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_SIMULATION_H
#define SIMULATIONBANQUE_SIMULATION_H

#include "Event.h"

class Simulation {
public:
    void add(Event* e);
    void run();
    double time();
};


#endif //SIMULATIONBANQUE_SIMULATION_H
