#ifndef SIMULATIONBANQUE_QUEUE_H
#define SIMULATIONBANQUE_QUEUE_H

#include <vector>
#include <deque>
#include "Bank.h"
#include "Client.h"

using namespace std;

class Client;
class Bank;

class Queue {
private:
    Bank* _bank;
    deque<Client*> _clients;
    int _maxLength;
    double _lastModifTime;
    double _timeSpentClients;
    double _queueLength;
    int _nbrClientServed;
    void updateAverage();
public:
    Queue(Bank* b);
    void add(Client* c);
    Client* remove();
    bool isEmpty();
    int getMaxLength();
    double getAverageLength();
    double getAverageWaitingTime();
};


#endif //SIMULATIONBANQUE_QUEUE_H
