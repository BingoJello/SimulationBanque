//
// Created by arthur on 07/09/2022.
//

#include "header/Queue.h"

Queue::Queue(Bank* b) {
    _bank = b;
    _nbrMaxClient = 0;
}

void Queue::add(Client* c) {
    _clients.push_back(c);
    int size = _clients.size();
    if(_nbrMaxClient < size){
        _nbrMaxClient = size;
    }
}

Client* Queue::remove() {
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