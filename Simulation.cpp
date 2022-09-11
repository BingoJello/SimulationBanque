//
// Created by arthur on 07/09/2022.
//

#include "header/Simulation.h"

Simulation::Simulation() {

}

void Simulation::add(Event *e) {
    _events.push_back(e);
}

void Simulation::run() {
    for (Event* event : _events) {
        //TODO
    }
}

double Simulation::getTime() {
    return _time;
}
