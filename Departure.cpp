#include "header/Departure.h"

/**
 * @brief Constructeur
 * @param time Temps du départ du client
 * @param s Simulation
 * @param cashier Caissier qui traité le client
 */
Departure::Departure(double time, Simulation* s, Cashier *cashier) : Event(time, s){
    _time = time;
    _simulation = s;
    _cashier = cashier;
}

Departure::~Departure() noexcept {

}

/**
 * @brief Processus de départ d'un client
 */
void Departure::process() {
    cout << _time<<"s : Depart du client "<<_cashier->getClient()<<" traite par le caissier ID "<<_cashier->getIdCashier()<<"\t" ;
    Bank* bank = (Bank*) _simulation;
    Client* c = _cashier->getClient();
    _cashier->releaseClient();
    delete(c);

    if(false == bank->getQueue()->isEmpty()){
        Client* c = bank->getQueue()->remove();
        _cashier->serve(c);
        cout << "Le caissier ID " << _cashier->getIdCashier()<<" traite le client " << c<<"\n";
    } else {
        cout << "Le caissier ID " << _cashier->getIdCashier()<<" est libre \n";
        bank->addFreeCashiersToList(_cashier);
    }
}