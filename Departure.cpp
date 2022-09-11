//
// Created by arthur on 07/09/2022.
//

#include "header/Departure.h"
#include "header/Cashier.h"
#include "header/Client.h"
#include "header/Simulation.h"
#include "header/Bank.h"
#include "header/Queue.h"


Departure::Departure(double time, Simulation* simulation, Cashier *cashier) : Event(){
    _time = time;
    _simulation = simulation;
    _cashier = cashier;
}

void Departure::process() {
    Bank* bank = (Bank*) _simulation;
    Client* c = _cashier->getClient();
    _cashier->releaseClient();
    //Faire stats cashier
    delete(c);

    if(false == bank->getQueue()->isEmpty()){
        Client* c = bank->getQueue()->remove();
        _cashier->serve(c);
    }
}

Departure::~Departure() {

}

