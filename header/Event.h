//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_EVENT_H
#define SIMULATIONBANQUE_EVENT_H

class Simulation;

class Event {
protected :
    double _time;
    Simulation* _simulation;
public:
    explicit Event(double time, Simulation* sim);
    virtual ~Event();
    virtual void process();
    double getTime() const;

};


#endif //SIMULATIONBANQUE_EVENT_H
