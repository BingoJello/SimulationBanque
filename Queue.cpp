//
// Created by arthur on 07/09/2022.
//

#include "header/Queue.h"

Queue::Queue(Bank* b) {
    _bank = b;
}

int Queue::getMaxLength() {
    return _maxLength;
}

double Queue::getMediumLength() {
    //TODO
}

void Queue::add(Client* c) {
    _clients.push_back(c);
}


double Queue::getAverageWaitingTime() {
    int totalWaitingTime = 0;
    for (Client* client : _servedClients) {
        int serviceStartTime = client->getServiceStartTime();
        int arrivalTime = client->getArrivalTime();
        totalWaitingTime += serviceStartTime - arrivalTime;
    }
    return totalWaitingTime / (int) _servedClients.size();
}

bool Queue::isEmpty() {
    return _clients.empty() ? true : false;
}

Client* Queue::remove() {
    Client* c = _clients.front();
    double current_time = _bank->getCurrentTime();
    c->setServiceStartTime(current_time);
    _clients.pop_front();
    return c;
}