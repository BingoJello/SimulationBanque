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

double Cashier::getAverageServiceTime() const {
    return _averageServiceTime;
}

int Cashier::getNbServedClients() const {
    return _nbClientsServed;
}

double Cashier::getOccupationTime() {
    return _occupationTime; // calcul occupation time
}

double Cashier::tauxOccupation() const{
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
    // _bank->add(new Depart(heureDepart,this, client ));
    // _occupationTime+= _banque->simulation()->tempsCourant() - _averageServiceTime;
}


void Cashier::wait() {
    if (_remainingServiceTimeClient > 0) {
        _remainingServiceTimeClient--;
    }
}

double Cashier::getRemainingServiceTimeClient() {
    return _remainingServiceTimeClient;
}


std::ostream &operator<<(std::ostream &os, const Cashier &cashier)
{
    os << "Number of served clients : " << cashier.getNbServedClients() << std::endl;
    os << "Average service time : " << cashier.getAverageServiceTime() << std::endl;
    os << "Occupation rate: " << cashier.tauxOccupation() << std::endl;
   
    return os;
}