#ifndef SIMULATIONBANQUE_SIMULATION_H
#define SIMULATIONBANQUE_SIMULATION_H

#include <iostream>
#include <set>
#include "Event.h"
using namespace std;

class Event;

/* Struct used to compare two events for the set of events */
/**
 * @brief Structure qui compare le temps d'arrivé deux événements
 */
struct EventComp {
    bool operator()(const Event* lhs, const Event* rhs) const  {
        /* Events are compared using their execution time */
        return (lhs->getTime() < rhs->getTime());
    }
};

class Simulation {
protected:
    set<Event*, EventComp> _events;
    set<Event*, EventComp>::iterator _eventIterator;
    double _time;
public:
    void run();
    void add(Event* e);
    double getTime();
};


#endif //SIMULATIONBANQUE_SIMULATION_H
