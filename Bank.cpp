//
// Created by arthur on 07/09/2022.
//

#include "header/Bank.h"
#include <iostream>

Bank::Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double averageServiceTime){
    _expectedDuration = expectedDuration;
    _nbrCashiers = nbCashiers;
    _timeBetweenArrivals = timeBetweenArrivals;
    _cashiers = new Cashier*[_nbrCashiers];
    _averageServiceTime = averageServiceTime;
    for(int i=0; i<_nbrCashiers; i++){
        _cashiers[i] = new Cashier(i, SimulationUtility::getValue(_averageServiceTime), this);
        _freeCashiers.push_back(_cashiers[i]);
    }
    _queue = new Queue(this);
    add(new Arrival(SimulationUtility::getValue(_timeBetweenArrivals), this));
}

double Bank::getExpectedDuration() {
    return _expectedDuration;
}

double Bank::getTimeBetweenArrivals() {
    return _timeBetweenArrivals;
}

int Bank::getNbrCashiers() {
    return _nbrCashiers;
}

int Bank::getNbServedClients() {
    return 0;
}

double Bank::getRealTime() {
    return _realTime;
}

Cashier* Bank::getFreeCashier() {
    if(_freeCashiers.empty()) return nullptr;

    Cashier* c =  _freeCashiers.front();
    _freeCashiers.pop_front();
    return c;
}

Queue* Bank::getQueue() {
    return _queue;
}

double Bank::getAverageServiceTime() {
    return _averageServiceTime;
}

deque<Cashier *> Bank::getFreeCashiersList() {
    return _freeCashiers;
}