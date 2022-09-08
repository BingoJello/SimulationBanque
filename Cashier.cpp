//
// Created by arthur on 07/09/2022.
//

#include "header/Cashier.h"

Cashier::Cashier(double ast) {
    _nbClientsServed = 0;
    _occupationTime = 0;
    _averageServiceTime = ast;
}

double Cashier::getAverageServiceTime() {
    return _averageServiceTime;
}

int Cashier::getServedClients() {
    return _nbClientsServed;
}

double Cashier::getOccupationTime() {
    return _occupationTime;
}

bool Cashier::isFree() {
    //TODO
}

void Cashier::serve(Client client) {
    //TODO
}

void Cashier::wait() {
    //TODO
}