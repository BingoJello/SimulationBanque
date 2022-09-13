

#include "header/Arrival.h"
#include <iostream>

Arrival::Arrival(double time, Simulation* s) : Event(time, s){
    _time = time;
    _simulation = s;
}

void Arrival::process() {
    Client* c = new Client(_time);
    cout << "nouvelle arrive a "<<_time<<" du client "<<c<<"\t" ;
    Bank* b = (Bank*) _simulation;
    Cashier* ca = b->getFreeCashier();
    if(nullptr == ca){
        cout << "le client est ajouter dans la file\n" ;
        b->getQueue()->add(c);
    } else{
        cout << "le client est servi par le caissier ID = " <<ca->getIdCashier()<<"\n" ;
        ca->serve(c);
    }

    double nextTimeArrival = b->getTime() + SimulationUtility::getValue(b->getTimeBetweenArrivals());
    if(nextTimeArrival < b->getExpectedDuration()) {
        _simulation->add(new Arrival(nextTimeArrival, _simulation));
    }
}