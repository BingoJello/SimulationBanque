//
// Created by arthur on 07/09/2022.
//

#include "header/Cashier.h"

Cashier::Cashier(double ast) {
    _nbClientsServed = 0;
    _occupationTime = 0;
    _averageServiceTime = ast;
    _servedClient = 0;
    _remainingServiceTimeClient = 0
}

double Cashier::getAverageServiceTime() {
    return _averageServiceTime;
}

int Cashier::getNbServedClients() {
    return _nbClientsServed;
}

double Cashier::getOccupationTime() {
    return _occupationTime;
}

bool Cashier::isFree() {
    return _clientServed == 0;
}

void Cashier::serve(Client* client) {
    _servedClient = client;
    _remainingServiceTimeClient = _averageServiceTime;
}

void Cashier::wait() {
    if (_remainingServiceTimeClient > 0) {
        _remainingServiceTimeClient--;
    }
}

double Cashier::getRemainingServiceTimeClient() {
    return _remainingServiceTimeClient;
}