//
// Created by arthur on 11/09/2022.
//

#include "header/Cashier.h"
#include "header/Bank.h"
#include "header/Departure.h"

Cashier::Cashier(double ast, Bank *b) {
    _averageServiceTime = ast;
    _nbClientsServed = 0;
    _servedClient = 0;
    _occupationTime = 0;
    _remainingServiceTimeClient = 0;
    _bank = b;
}


int Cashier::getNbServedClients() {
    return _nbClientsServed;
}

double Cashier::getOccupationTime() {
    return _occupationTime;
}

bool Cashier::isFree() {
    return _servedClient == 0;
}

void Cashier::serve(Client* client) {
    _servedClient = client;
    _remainingServiceTimeClient = _averageServiceTime;
    Cashier::wait();
    _bank->add(new Departure(_bank->getTime() + _averageServiceTime, _bank, this));
}

void Cashier::wait() {
    if (_remainingServiceTimeClient > 0) {
        _remainingServiceTimeClient--;
    }
}

double Cashier::getRemainingServiceTimeClient() {
    return _remainingServiceTimeClient;
}

Client* Cashier::getClient() {
    return _servedClient;
}

void Cashier::releaseClient() {
    _servedClient = 0;
}