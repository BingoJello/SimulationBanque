//
// Created by arthur on 07/09/2022.
//

#include <algorithm>
#include <vector>
#include "header/Simulation.h"
#include "header/Event.h"

void Simulation::add(Event *e) {
    _events.push_back(e);
}

void Simulation::run() {
    while(false == _events.empty()){

    }
}

double Simulation::getTime() {
    return _time;
}
