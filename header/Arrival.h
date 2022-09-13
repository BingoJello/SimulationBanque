/**
* \file Arrival.h
* \brief Classe dérivée de Event. Représente l'arrivée d'un Client.
* \author Arthur Mimouni & Mamadou Bella Diallo
* \date 07/09/2022.
*/


#ifndef SIMULATIONBANQUE_ARRIVAL_H
#define SIMULATIONBANQUE_ARRIVAL_H


#include <iostream>
#include "SimulationUtility.h"
#include "Bank.h"
#include "Client.h"
#include "Event.h"

/**
 * @brief      Décrit une arrivée dans la banque et le traitement de l'arrivée.
 */

class Arrival : public Event{
public:

    /**
     * @brief      Constructeur de la classe Arrivee.
     *
     * @param  time  L'heure de l'arrivée
     * @param  s          La simulation
	*/

    Arrival(double time, Simulation* s);

    /**
		 * @brief      Traiter l'arrivée du Client.
	*/
    void process();
};


#endif //SIMULATIONBANQUE_ARRIVAL_H
