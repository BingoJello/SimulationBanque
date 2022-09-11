//
// Created by arthur on 07/09/2022.
//

#include <iostream>
#include "header/Arrival.h"
#include "header/Client.h"
#include "header/Bank.h"
#include "header/Queue.h"

Arrival::Arrival(double time, Simulation* s) : Event(){
    _time = time;
    _simulation = s;
    cout << _time << endl;
}

void Arrival::process() {
    Client* c = new Client(_time);
    _simulation->add(new Arrival(_time+5, _simulation));
    Bank* b = (Bank*) b;
    Cashier* ca = b->getFreeCashier();
    if(0 != ca){
       ca->serve(c);
    } else{
        b->getQueue()->add(c);
    }
    if(_time + 5 < b->getExpectedDuration()){
        _simulation->add(new Arrival(_time+5, _simulation));
    }
}