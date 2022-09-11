//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_EVENT_H
#define SIMULATIONBANQUE_EVENT_H

#include "Simulation.h"

class Event {
protected :
    double _time;
    Simulation* _simulation;
public:
    Event();
    virtual ~Event();
    virtual void process();
    double getTime();

};


#endif //SIMULATIONBANQUE_EVENT_H
