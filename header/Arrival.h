#ifndef SIMULATIONBANQUE_ARRIVAL_H
#define SIMULATIONBANQUE_ARRIVAL_H

#include <iostream>
#include "SimulationUtility.h"
#include "Bank.h"
#include "Client.h"
#include "Event.h"

class Arrival : public Event{
public:
    Arrival(double time, Simulation* s);
    void process();
};

#endif //SIMULATIONBANQUE_ARRIVAL_H
