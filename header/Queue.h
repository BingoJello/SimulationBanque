//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_QUEUE_H
#define SIMULATIONBANQUE_QUEUE_H

#include <vector>
#include <deque>
#include <list>
using namespace std;
#include "header/Bank.h"
#include "header/Client.h"


class Queue {
private:
    Bank* _bank;
    // vector<Client*> _clients;
    int _maxLength;
    double averageWaitingTime;
    list<Client*> _servedClients;
    deque<Client*> _clients; // plus adapté pour une
public:
    Queue(Bank* b);
    int getMaxLength();
    double getMediumLength();
    double getAverageWaitingTime();
    void add(Client* c);
    bool isEmpty();
    Client* remove();
};


#endif //SIMULATIONBANQUE_QUEUE_H
