#include "header/Bank.h"
#include <iostream>

/**
 * @brief Constructeur
 * @param expectedDuration Temps attendu de la simulation
 * @param nbCashiers Nombre de caissiers
 * @param timeBetweenArrivals Temps moyen d'arrivée des clients
 * @param averageServiceTime Temps moyen du temps de service d'un caissier
 */
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

/**
 * @brief Démarrage de la simulation
 */
void Bank::startSimulation() {
    this->run();
    this->getStats();
}

/**
 *
 * @return Temps attendu de la simulation
 */
double Bank::getExpectedDuration() {
    return _expectedDuration;
}

/**
 *
 * @return Temps moyen d'arrivée des clients
 */
double Bank::getTimeBetweenArrivals() {
    return _timeBetweenArrivals;
}

/**
 *
 * @return Le premier caissier libre
 */
Cashier* Bank::getFreeCashier() {
    if(_freeCashiers.empty()) return nullptr;

    Cashier* c =  _freeCashiers.front();
    _freeCashiers.pop_front();
    return c;
}

/**
 *
 * @return La file d'attente
 */
Queue* Bank::getQueue() {
    return _queue;
}

/**
 * @brief Ajout un caissier libre dans une pile
 * @param c Caissier
 */
void Bank::addFreeCashiersToList(Cashier* c) {
    _freeCashiers.push_back(c);
}

/**
 * @brief Affiche les statistiques finaux de la simulation
 */
void Bank::getStats() {
    cout << "\n\n-----------Statistiques de fin de simulation----------------\n\n";
    cout << "Temps attendue de la simulation : " << _expectedDuration << "s\n";
    cout << "Temps reel de la simulation : " << this->getTime() <<"s\n";
    cout << "Temps d'attente moyen dans la file d'attente : " <<_queue->getAverageWaitingTime() <<"s\n";
    cout << "Taille moyenne de la file de la file d'attente : "<< _queue->getAverageLength() << "\n";
    cout << "Taille maximale de la file de la file d'attente : "<< _queue->getMaxLength() << "\n";

    for(int i = 0; i < _nbrCashiers; i++){
        cout << "Cashier ID "<<_cashiers[i]->getIdCashier()<<" : Taux d'occupation = "<<_cashiers[i]->getAverageOccupationTime() * 100
            <<"% du temps total et nombre client servis = "<<_cashiers[i]->getNbServedClients()<<"\n";
    }

    cout <<"Fin simulation : "<<this->getTime()<<"s\n"<<endl;
}