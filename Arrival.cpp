

#include "header/Arrival.h"

/**
 * @brief Constructeur
 * @param time Temps de la simulation
 * @param s Simulation
 */
Arrival::Arrival(double time, Simulation* s) : Event(time, s){
    _time = time;
    _simulation = s;
}

/**
 * @brief Processus d'arrivée d'un client
 */
void Arrival::process() {
    Client* c = new Client(_time);
    cout << _time<<"s : Arrive d'un nouveau client "<<c<<"\t" ;
    Bank* b = (Bank*) _simulation;
    Cashier* ca = b->getFreeCashier();
    if(nullptr == ca){
        cout << "Le client est ajoute dans la file d'attente\n" ;
        b->getQueue()->add(c);
    } else{
        cout << "Le client est servi par le caissier ID " <<ca->getIdCashier()<<"\n" ;
        ca->serve(c);
    }

    double nextTimeArrival = b->getTime() + SimulationUtility::getPoissonValue(b->getTimeBetweenArrivals());
    if(nextTimeArrival < b->getExpectedDuration()) {
        _simulation->add(new Arrival(nextTimeArrival, _simulation));
    }
}