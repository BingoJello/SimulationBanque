//
// Created by arthur on 07/09/2022.
//

#include "header/Bank.h"
#include "header/SimulationUtility.h"
#include "header/Queue.h"
/**
 *
 * @param expectedDuration //durée prévus de la simulation
 * @param nbCashiers //nombre de caissiers total
 * @param timeBetweenArrivals //temps entre les arrivées des clients
 * @param listAverageServiceTime //liste des temps de service des caissiers
 */
Bank::Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals){
    _expectedDuration = expectedDuration;
    _nbrCashiers = nbCashiers;
    _timeBetweenArrivals = timeBetweenArrivals;
    _time = 0;
    double* listAverageServiceTime = SimulationUtility::getRandomValue(1, 3, 3);
    for(int i=0; i<nbCashiers; i++){
        Cashier c = Cashier(23, this);
    }
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
    //TODO
}

Cashier* Bank::getFreeCashier() {
    //TODO
}

double Bank::getRealTime() {
    return _realTime;
}