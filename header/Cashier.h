//
// Created by arthur on 11/09/2022.
//

#ifndef SIMULATIONBANQUE_CASHIER_H
#define SIMULATIONBANQUE_CASHIER_H

#include "Bank.h"
#include "Departure.h"
#include "Client.h"

class Bank;

class Cashier {
private:
    Bank* _bank;
    Client* _client;
    int _idCashier;
    int _nbClientsServed;
    double _averageServiceTime;
    double _occupationTime;
public:
    Cashier(int idCashier, double ast, Bank* b);
    void serve(Client* client);
    Client* getClient();
    void releaseClient();
    bool isFree();
    int getNbServedClients();
    double getAverageOccupationTime();
};


#endif //SIMULATIONBANQUE_CASHIER_H
