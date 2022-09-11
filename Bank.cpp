//
// Created by arthur on 07/09/2022.
//

#include "header/Cashier.h"
#include "header/Bank.h"
#include "header/SimulationUtility.h"
#include "header/Arrival.h"
#include "header/Queue.h"

Bank::Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals){
    _expectedDuration = expectedDuration;
    _nbrCashiers = nbCashiers;
    _timeBetweenArrivals = timeBetweenArrivals;
    _cashiers = new Cashier*[_nbrCashiers];
    double* listAverageServiceTime = SimulationUtility::getRandomValue(1, 3, 3);
    for(int i=0; i<_nbrCashiers; i++){
        _cashiers[i] = new Cashier(listAverageServiceTime[i], this);
    }
    _queue = new Queue(this);
    add(new Arrival(_time, this));
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

Cashier *Bank::getFreeCashier() {
    for (int i=0; i<_nbrCashiers; i++) {
        if(_cashiers[i]->isFree()){
            return _cashiers[i];
        }
    }
    return 0;
}

Queue* Bank::getQueue() {
    return _queue;
}