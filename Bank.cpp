//
// Created by arthur on 07/09/2022.
//

#include "header/Bank.h"

Bank::Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double *listAverageServiceTime) {
    _expectedDuration = expectedDuration;
    _nbrCashiers = nbCashiers;
    _timeBetweenArrivals = timeBetweenArrivals;
    _cashiers = new Cashier*[nbCashiers];
    for (int i=0; i < nbCashiers; i++)
        _cashiers[i] = new Cashier(this, listAverageServiceTime[i]);
}

Bank:: ~Bank(){
    delete[] _cashiers;
}

double Bank::getActualDuration() {
    //TODO
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
    int totalServedClients = 0;
    for (int i = 0; i< _nbrCashiers; i++)
        totalServedClients += _cashiers[i]->getNbServedClients();
    return totalServedClients;
}

Cashier* Bank::getFreeCashier() {
    for (int i = 0; i < _nbrCashiers; i++)
        if (_cashiers[i]->isFree()) return _cashiers[i];
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Bank &bank)
{
    os << "output bank data : ";
    return os;
}
