//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Cashier.h"


class Bank {
private:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
public:
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* listAverageServiceTime);
    double getActualDuration();
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    Cashier* getFreeCashier();
};


#endif //SIMULATIONBANQUE_BANK_H
