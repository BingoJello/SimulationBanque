//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_DEPARTURE_H
#define SIMULATIONBANQUE_DEPARTURE_H

#include "Event.h"
#include "Client.h"
#include "Cashier.h"
#include "Simulation.h"

class Departure : Event {
protected:
    Client* _client;
    Cashier* _cashier;
    Bank* _bank;
public:
    Departure(double time, Bank* bank, Client* client, Cashier* cashier);
};


#endif //SIMULATIONBANQUE_DEPARTURE_H
