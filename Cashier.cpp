//
// Created by arthur on 07/09/2022.
//

#include "header/Cashier.h"

Cashier::Cashier(double ast) {
    _nbClientsServed = 0;
    _occupationTime = 0;
    _averageServiceTime = ast;
}

void Cashier::wait() {
    //TODO
}

bool Cashier::isFree() {
    //TODO
}

int Cashier::getServedClients() {
    return _nbClientsServed;
}

void Cashier::serve(Client client) {
    //TODO
}

double Cashier::getAverageServiceTime() {
    return _averageServiceTime;
}

double Cashier::getOccupationTime() {
    return _occupationTime;
}