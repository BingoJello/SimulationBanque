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
    Cashier** _cashiers;
    deque<Cashier*> _freeCashiers;
    Queue* _queue;
public:
<<<<<<< HEAD
    
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals = 3.0, double averageServiceTime = 2.0);
=======
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* averageServiceTime);
>>>>>>> 65667f775a40c879d0eef21f4191fc77b76829dc
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    Cashier* getFreeCashier();
    Queue* getQueue();
    deque<Cashier*> getFreeCashiersList();
};


#endif //SIMULATIONBANQUE_BANK_H
