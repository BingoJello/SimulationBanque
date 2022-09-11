//
// Created by arthur on 07/09/2022.
//

#include "header/Departure.h"
#include "header/Cashier.h"
#include "header/Client.h"
#include "header/Simulation.h"

Departure::Departure(double time, Bank* bank, Client *client, Cashier *cashier) : Event(){
    _time = time;
    _bank = bank;
    _client = client;
    _cashier = cashier;
    _bank->
}

