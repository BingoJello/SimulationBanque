//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_EVENT_H
#define SIMULATIONBANQUE_EVENT_H

#include "Simulation.h"

class Event {
private :
    const double _startTime;
public:
    Event(double st);
    virtual void treat();
    double getStartTime();

};


#endif //SIMULATIONBANQUE_EVENT_H
