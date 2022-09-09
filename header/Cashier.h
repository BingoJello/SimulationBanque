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

public:
    Cashier(double ast);
    double getAverageServiceTime();
    int getNbServedClients();
    double getOccupationTime();
    double getRemainingServiceTimeClient();
    bool isFree();
    void serve(Client* client);
    void wait();
};


#endif //SIMULATIONBANQUE_CASHIER_H
