//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_EVENT_H
#define SIMULATIONBANQUE_EVENT_H

class Event {
protected :
    double _time;
public:
    Event();
    virtual void process();
    double getTime();

};


#endif //SIMULATIONBANQUE_EVENT_H
