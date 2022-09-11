//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Cashier.h"
#include "header/Simulation.h"
#include <ostream>
using namespace std;

class Bank: public Simulation {
private:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
    Cashier** _cashiers;
public:
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* listAverageServiceTime);
    Bank();
    ~Bank();
    double getActualDuration();
    double getExpectedDuration();
    double getTimeBetweenArrivals();
    int getNbrCashiers();
    int getNbServedClients();
    Cashier* getFreeCashier();

    friend std::ostream &operator<<(std::ostream &os, const Bank &bank);
};


#endif //SIMULATIONBANQUE_BANK_H
