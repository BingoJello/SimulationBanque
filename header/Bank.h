//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Simulation.h"
#include "Cashier.h"

class Queue;

class Bank : public Simulation {
private:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
    double _realTime;
    Cashier** _cashiers;
    Queue* _queue;
public:
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals);
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    double getRealTime();
    Cashier* getFreeCashier();
    Queue* getQueue();
};


#endif //SIMULATIONBANQUE_BANK_H
