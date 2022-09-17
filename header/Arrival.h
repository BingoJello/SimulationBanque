#ifndef SIMULATIONBANQUE_ARRIVAL_H
#define SIMULATIONBANQUE_ARRIVAL_H

#include <iostream>
#include "SimulationUtility.h"
#include "Bank.h"
#include "Client.h"
#include "Event.h"

class Arrival : public Event{
public:
    /**
    * @brief Constructeur
    * @param time Temps de la simulation
    * @param s Simulation
    */
    Arrival(double time, Simulation* s);
    /**
    * @brief Processus d'arrivée d'un client
    */
    void process();
};

#endif //SIMULATIONBANQUE_ARRIVAL_H