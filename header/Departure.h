//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_DEPARTURE_H
#define SIMULATIONBANQUE_DEPARTURE_H

#include "Event.h"
#include "Client.h"
#include "Cashier.h"
#include "Simulation.h"

class Departure : public Event {
private:
    Cashier* _cashier;
    Simulation* _simulation;
public:
    Departure(double time, Simulation* simulation, Cashier* cashier);
    ~Departure();
    void process();
};


#endif //SIMULATIONBANQUE_DEPARTURE_H
