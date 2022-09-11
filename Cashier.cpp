//
// Created by arthur on 07/09/2022.
//

#include "header/Cashier.h"
#include "header/Bank.h"

Cashier::Cashier(Bank* bank, double ast) {
    _nbClientsServed = 0;
    _occupationTime = 0;
    _averageServiceTime = ast;
    _servedClient = 0;
    _remainingServiceTimeClient = 0;
}

double Cashier::getAverageServiceTime() {
    return _averageServiceTime;
}

int Cashier::getNbServedClients() {
    return _nbClientsServed;
}

double Cashier::getOccupationTime() {
    return _occupationTime; // calcul occupation time
}

double Cashier::tauxOccupation(){
    return _occupationTime / _averageServiceTime * 100;
}

bool Cashier::isFree() {
    return _servedClient == 0;
}

void Cashier::serve(Client* client) {
    _servedClient = client;
    _nbClientsServed ++;
    _remainingServiceTimeClient = _averageServiceTime;

    // TODO calculer l'heure de départ du client ensuite ajouter un évenement de départ
    double heureDepart = _averageServiceTime + 2 ; // 2 est le temps pris pour servir à révoir
    _bank->add(new Depart(heureDepart,this, client ));
      _occupationTime+= _banque->simulation()->tempsCourant() - _debutService;
}


void Cashier::wait() {
    if (_remainingServiceTimeClient > 0) {
        _remainingServiceTimeClient--;
    }
}

double Cashier::getRemainingServiceTimeClient() {
    return _remainingServiceTimeClient;
}