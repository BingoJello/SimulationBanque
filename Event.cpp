//
// Created by arthur on 07/09/2022.
//

#include "header/Event.h"

Event::Event(double time, Simulation *sim) {
    _time = time;
    _simulation = sim;
}

Event::~Event() {

}

void Event::process() {

}

double Event::getTime() const {
    return _time;
}
