//
// Created by arthur on 07/09/2022.
//

#include "header/Departure.h"

Departure::Departure(double time, Simulation* simulation, Cashier *cashier) : Event(time, simulation){
    _time = time;
    _simulation = simulation;
    _cashier = cashier;
    cout << "nouveaux depart a "<<_time<<" du client "<<_cashier->getClient()<<"\n" ;
}

Departure::~Departure() noexcept {

}

void Departure::process() {
    Bank* bank = (Bank*) _simulation;
    Client* c = _cashier->getClient();
    _cashier->releaseClient();
    delete(c);

    if(false == bank->getQueue()->isEmpty()){
        Client* c = bank->getQueue()->remove();
        _cashier->serve(c);
    } else {
        bank->getFreeCashiersList().push_back(_cashier);
    }
}

