//
// Created by arthur on 07/09/2022.
//

#include "header/Event.h"

Event::Event(double st, Simulation sim) : _startTime(st) {
    _simulation = sim;
}

double Event::getStartTime() {
    return _startTime;
}

void Event::treat() {

}