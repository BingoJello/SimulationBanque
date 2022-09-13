//
// Created by arthur on 07/09/2022.
//

#include "header/Queue.h"

Queue::Queue(Bank* b) {
    _bank = b;
    _nbrMaxClient = 0;
    _lastModifTime = 0;
    _timeClientSum = 0;
    _nbrClientServed = 0;
}

void Queue::add(Client* c) {
    _clients.push_back(c);
    int size = _clients.size();
    if(_nbrMaxClient < size){
        _nbrMaxClient = size;
    }
}

Client* Queue::remove() {
    _nbrClientServed++;
    updateAverage();
    Client* c = _clients.front();
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
    _timeClientSum += _clients.size()*timeDiff;
    _lastModifTime = _bank->getTime();
}

/* Returns the number of client waiting in average in the queue */
double Queue::getAverageLength() {
    updateAverage();
    return _timeClientSum / _bank->getTime();
}

double Queue::getAverageWaitingTime() {
    return _timeClientSum / _nbrClientServed;
}