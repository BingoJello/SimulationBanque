//
// Created by arthur on 11/09/2022.
//

#ifndef SIMULATIONBANQUE_CASHIER_H
#define SIMULATIONBANQUE_CASHIER_H

class Client;
class Bank;

class Cashier {
private:
    int _nbClientsServed;
    double _averageServiceTime;
    double _occupationTime;
    double _remainingServiceTimeClient;
    Client* _servedClient;
    Bank* _bank;
    void wait();
public:
    Cashier(double tsa, Bank *b);
    double getAverageServiceTime();
    int getNbServedClients();
    double getOccupationTime();
    double getRemainingServiceTimeClient();
    bool isFree();
    void serve(Client* client);
    Client* getClient();
    void releaseClient();
};


#endif //SIMULATIONBANQUE_CASHIER_H
