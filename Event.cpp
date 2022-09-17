#include "header/Event.h"

Event::Event(double time, Simulation *s) {
    _time = time;
    _simulation = s;
}

Event::~Event() {

}

void Event::process() {

}

double Event::getTime() const {
    return _time;
}