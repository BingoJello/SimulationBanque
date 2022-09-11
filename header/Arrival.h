//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_ARRIVAL_H
#define SIMULATIONBANQUE_ARRIVAL_H

#include "Event.h"

class Arrival : public Event{
public:
    Arrival(double time, Simulation* s);
    void process();
};


#endif //SIMULATIONBANQUE_ARRIVAL_H
