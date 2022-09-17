#include "header/Simulation.h"

void Simulation::run() {
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        _time = e->getTime();
        e->process();
    }
}

void Simulation::add(Event *e) {
    _events.insert(e);
}

double Simulation::getTime() {
    return _time;
}