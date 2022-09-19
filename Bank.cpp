#include "header/Bank.h"
#include <iostream>

Bank::Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* averageServiceTime){
    _expectedDuration = expectedDuration;
    _nbrCashiers = nbCashiers;
    _timeBetweenArrivals = timeBetweenArrivals;
    _cashiers = new Cashier*[_nbrCashiers];
    for(int i=0; i<_nbrCashiers; i++){
        _cashiers[i] = new Cashier(i, averageServiceTime[i], this);
        _freeCashiers.push_back(_cashiers[i]);
    }
    _queue = new Queue(this);
    add(new Arrival(SimulationUtility::getPoissonValue(_timeBetweenArrivals), this));
}

void Bank::startSimulation() {
    this->run();
    this->getStats();
}

double Bank::getExpectedDuration() {
    return _expectedDuration;
}

double Bank::getTimeBetweenArrivals() {
    return _timeBetweenArrivals;
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

void Bank::addFreeCashiersToList(Cashier* c) {
    _freeCashiers.push_back(c);
}

void Bank::getStats() {
    cout << "\n\n-----------Statistiques de fin de simulation----------------\n\n";
    cout << "Temps attendue de la simulation : " << _expectedDuration << "s\n";
    cout << "Temps reel de la simulation : " << this->getTime() <<"s\n";
    cout << "Temps d'attente moyen dans la file d'attente : " <<_queue->getAverageWaitingTime() <<"s\n";
    cout << "Taille moyenne de la file d'attente : "<< _queue->getAverageLength() << "\n";
    cout << "Taille maximale de la file d'attente : "<< _queue->getMaxLength() << "\n";

    for(int i = 0; i < _nbrCashiers; i++){
        cout << "Cashier ID "<<_cashiers[i]->getIdCashier()<<" : Taux d'occupation = "<<_cashiers[i]->getAverageOccupationTime() * 100
            <<"% du temps total et nombre client servis = "<<_cashiers[i]->getNbServedClients()<<"\n";
    }
    cout <<"Fin simulation : "<<this->getTime()<<"s\n"<<endl;
}