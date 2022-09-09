//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_QUEUE_H
#define SIMULATIONBANQUE_QUEUE_H

#include <vector>
#include <deque>
using namespace std;
#include "Bank.h"
#include "Client.h"


class Queue {
private:
    Bank* _bank;
    vector<Client> _clients;
    deque<Client*> _clients; // plus adapté pour une
public:
    Queue(Bank* b);
    int maxLength();
    double mediumLength();
    double averageWaitingTime();
    void add(Client* c);
    bool isEmpty();
    Client* remove();
};


#endif //SIMULATIONBANQUE_QUEUE_H
