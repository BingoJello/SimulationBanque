//
// Created by arthur on 07/09/2022.
//

#include "header/Arrival.h"
#include <iostream>

Arrival::Arrival(double time, Simulation* s) : Event(time, s){
    _time = time;
    _simulation = s;
}

void Arrival::process() {
    Client* c = new Client(_time);
    cout << "nouvelle arrive a "<<_time<<" du client "<<c<<"\n" ;
    Bank* b = (Bank*) _simulation;
    Cashier* ca = b->getFreeCashier();
    if(nullptr == ca){
        b->getQueue()->add(c);
    } else{
        ca->serve(c);
    }

    double nextTimeArrival = b->getTime() + SimulationUtility::getValue(b->getTimeBetweenArrivals());
    cout <<nextTimeArrival<<" \t"<<b->getExpectedDuration()<<"\n";
    if(nextTimeArrival < b->getExpectedDuration()) {
        _simulation->add(new Arrival(nextTimeArrival, _simulation));
    }
}