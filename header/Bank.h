//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Cashier.h"
#include "Arrival.h"
#include "Simulation.h"
#include "Queue.h"
#include <deque>

class Cashier;
class Queue;

class Bank : public Simulation {
private:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
    Cashier** _cashiers;
    deque<Cashier*> _freeCashiers;
    Queue* _queue;
public:
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* averageServiceTime);
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    Cashier* getFreeCashier();
    Queue* getQueue();
    deque<Cashier*> getFreeCashiersList();
};


#endif //SIMULATIONBANQUE_BANK_H
