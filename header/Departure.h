#ifndef SIMULATIONBANQUE_DEPARTURE_H
#define SIMULATIONBANQUE_DEPARTURE_H

#include "Bank.h"
#include "Cashier.h"
#include "Client.h"
#include "Event.h"

class Cashier;

class Departure : public Event {
private:
    Cashier* _cashier;
    Simulation* _simulation;
public:
    /**
    * @brief Constructeur
    * @param time Temps du départ du client
    * @param s Simulation
    * @param cashier Caissier qui traité le client
    */
    Departure(double time, Simulation* s, Cashier* cashier);
    /**
     * @brief Destructeur
     */
    ~Departure();
    /**
     * @brief Processus de départ d'un client
     */
    void process();
};


#endif //SIMULATIONBANQUE_DEPARTURE_H
