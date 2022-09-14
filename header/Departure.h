#ifndef SIMULATIONBANQUE_DEPARTURE_H
#define SIMULATIONBANQUE_DEPARTURE_H

#include "Bank.h"
#include "Cashier.h"
#include "Client.h"
#include "Event.h"

class Cashier;

class Departure : public Event {
private:
    Cashier* _cashier;
    Simulation* _simulation;
public:
    Departure(double time, Simulation* s, Cashier* cashier);
    ~Departure();
    void process();
};


#endif //SIMULATIONBANQUE_DEPARTURE_H
