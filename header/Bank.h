//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Cashier.h"
#include "/Simulation.h"
#include <list>header


class Bank: public Simulation {
private:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
    list<Cashier*> _cashiers;
public:
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* listAverageServiceTime);
    Bank() = default;
    double getActualDuration();
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    Cashier* getFreeCashier();
};


#endif //SIMULATIONBANQUE_BANK_H
