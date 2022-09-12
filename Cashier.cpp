//
// Created by arthur on 11/09/2022.
//

#include "header/Cashier.h"

Cashier::Cashier(int idCashier, double ast, Bank *b) {
    _idCashier = idCashier;
    _averageServiceTime = ast;
    _bank = b;
    _nbClientsServed = 0;
    _client = nullptr;
    _occupationTime = 0;
}

void Cashier::serve(Client* client) {
    _client = client;
    _nbClientsServed++;
    double timeServed = SimulationUtility::getValue(_averageServiceTime);
    _occupationTime+=timeServed;
    _bank->add(new Departure(_bank->getTime() + timeServed, _bank, this));
}

Client* Cashier::getClient() {
    return _client;
}

void Cashier::releaseClient() {
    _client = nullptr;
}

bool Cashier::isFree() {
    return _client == nullptr;
}

int Cashier::getNbServedClients() {
    return _nbClientsServed;
}

double Cashier::getAverageOccupationTime() {
    return (_occupationTime / _bank->getTime());
}