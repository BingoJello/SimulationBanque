//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Cashier.h"
#include "Simulation.h"

class Bank : public Simulation {
protected:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
    double _realTime;
public:
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals);
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    Cashier* getFreeCashier();
    double getRealTime();
};


#endif //SIMULATIONBANQUE_BANK_H
