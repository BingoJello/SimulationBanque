//
// Created by arthur on 07/09/2022.
//

#include "header/Queue.h"

Queue::Queue(Bank* b) {
    _bank = b;
}

int Queue::maxLength() {

}

double Queue::mediumLength() {

}

void Queue::add(Client* c) {
    _clients.push_back(c);
}


double Queue::averageWaitingTime() {

}

bool Queue::isEmpty() {
    return _clients.empty() ? true : false;
}

Client* Queue::remove() {
    Client* c = _clients.front();
    _clients.pop_front();
    return c;
}