//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_SIMULATION_H
#define SIMULATIONBANQUE_SIMULATION_H

#include "Event.h"
#include <deque>
using namespace std;

class Simulation {
protected:
    deque<Event*> _events;
    double _time;
public:
    Simulation();
    void run();
    void add(Event* e);
    double getTime();
};


#endif //SIMULATIONBANQUE_SIMULATION_H
