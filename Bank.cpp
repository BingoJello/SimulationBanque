//
// Created by arthur on 07/09/2022.
//

#include "header/Bank.h"

Bank::Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double *listAverageServiceTime) {
    _expectedDuration = expectedDuration;
    _nbrCashiers = nbCashiers;
    _timeBetweenArrivals = timeBetweenArrivals;

    //TODO listAverageServiceTime;
}

double Bank::getActualDuration() {
    //TODO
}

double Bank::getExpectedDuration() {
    return _expectedDuration;
}

Cashier* Bank::getFreeCashier() {
    //TODO
}

int Bank::getNbServedClients() {
    //TODO
}

int Bank::getNbrCashiers() {
    return _nbrCashiers;
}

double Bank::getTimeBetweenArrivals() {
    return _timeBetweenArrivals;
}