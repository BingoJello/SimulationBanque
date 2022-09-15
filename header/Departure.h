<<<<<<< HEAD

=======
>>>>>>> 167850d9d12ded965d727dd245df313df24be469
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
<<<<<<< HEAD
   
    Departure(double time, Simulation* simulation, Cashier* cashier);
=======
    Departure(double time, Simulation* s, Cashier* cashier);
>>>>>>> 167850d9d12ded965d727dd245df313df24be469
    ~Departure();
    void process();
};


#endif //SIMULATIONBANQUE_DEPARTURE_H
