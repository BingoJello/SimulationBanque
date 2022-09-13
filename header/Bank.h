/**
 * @file Bank.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    double _realTime;
    double _averageServiceTime;
    Cashier** _cashiers;
    deque<Cashier*> _freeCashiers;
    Queue* _queue;
public:
    
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals = 3.0, double averageServiceTime = 2.0);
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    double getRealTime();
    Cashier* getFreeCashier();
    Queue* getQueue();
    double getAverageServiceTime();
    deque<Cashier*> getFreeCashiersList();
};


#endif //SIMULATIONBANQUE_BANK_H
