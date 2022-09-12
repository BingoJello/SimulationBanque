//
// Created by arthur on 07/09/2022.
//


#include "header/Arrival.h"

Arrival::Arrival(double time, Simulation* s) : Event(time, s){
    _time = time;
    _simulation = s;
}

void Arrival::process() {
    Client* c = new Client(_time);
    _simulation->add(new Arrival(_time+5, _simulation));
    Bank* b = (Bank*) b;
    Cashier* ca = b->getFreeCashier();
    if(nullptr == ca){
        b->getQueue()->add(c);
    } else{
        ca->serve(c);
    }

    double nextTimeArrival = b->getTime() + SimulationUtility::getValue(b->getTimeBetweenArrivals());
    if(nextTimeArrival < b->getRealTime()) {
        _simulation->add(new Arrival(nextTimeArrival, _simulation));
    }
}