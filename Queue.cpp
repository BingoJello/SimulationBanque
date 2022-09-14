//
// Created by arthur on 07/09/2022.
//

#include "header/Queue.h"

Queue::Queue(Bank* b) {
    _bank = b;
    _lastModifTime = 0;
    _timeSpentClients = 0;
    _queueLength = 0;
    _nbrClientServed = 0;
}

void Queue::add(Client* c) {
    _clients.push_back(c);
    int size = _clients.size();
    cout << size <<"yyyyyyyyyy";
    if(_maxLength < size){
        _maxLength = size;
    }
}

Client* Queue::remove() {
    _nbrClientServed++;
    updateAverage();
    Client* c = _clients.front();
    _timeSpentClients += (_bank->getTime() - c->getArrivalTime());
    _clients.pop_front();
    return c;
}

bool Queue::isEmpty() {
    return _clients.empty() ? true : false;
}

int Queue::getMaxLength() {
    return _maxLength;
}

void Queue::updateAverage() {
    double timeDiff = _bank->getTime() - _lastModifTime;
    _queueLength += _clients.size()*timeDiff;
    _lastModifTime = _bank->getTime();
}

/* Returns the number of client waiting in average in the queue */
double Queue::getAverageLength() {
    if(0 ==_bank->getTime()) return 0;

    updateAverage();
    return _queueLength / _bank->getTime();
}

double Queue::getAverageWaitingTime() {
    if(0 == _nbrClientServed) return 0;
    return _timeSpentClients / _nbrClientServed;
}