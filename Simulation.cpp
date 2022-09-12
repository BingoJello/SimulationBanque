//
// Created by arthur on 07/09/2022.

#include "header/Simulation.h"
#include <iostream>

void Simulation::add(Event *e) {
    cout << "nouvelle evenement \n";
    _events.insert(e);
}

void Simulation::run() {
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        _time = e->getTime();
        cout << e->getTime() << ":  ";
        e->process();
    }
}

double Simulation::getTime() {
    return _time;
}
