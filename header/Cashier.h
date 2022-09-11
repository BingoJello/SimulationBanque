//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_CASHIER_H
#define SIMULATIONBANQUE_CASHIER_H
#include "Client.h"

class Cashier {
private:
    int _nbClientsServed;
    double _averageServiceTime;
    double _occupationTime;
    double _remainingServiceTimeClient;
    Client* _servedClient;
    Bank* _bank;

public:
    Cashier(Bank& bank, double ast);
    double getAverageServiceTime();
    int getNbServedClients();
    double getOccupationTime();
    double getRemainingServiceTimeClient();
    double tauxOccupation();
    bool isFree();
    void serve(Client* client);
    void free();
    void wait();
};


#endif //SIMULATIONBANQUE_CASHIER_H
