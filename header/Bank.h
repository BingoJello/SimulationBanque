#ifndef SIMULATIONBANQUE_BANK_H
#define SIMULATIONBANQUE_BANK_H

#include "Cashier.h"
#include "Arrival.h"
#include "Simulation.h"
#include "Queue.h"
#include <deque>

class Cashier;
class Queue;

class Bank : public Simulation {
private:
    double _expectedDuration;
    int _nbrCashiers;
    double _timeBetweenArrivals;
    Cashier** _cashiers;
    deque<Cashier*> _freeCashiers;
    Queue* _queue;
    /**
    * @brief Affiche les statistiques finaux de la simulation
    */
    void getStats();
public:
    /**
     * @brief Constructeur
     * @param expectedDuration Temps attendu de la simulation
     * @param nbCashiers Nombre de caissiers
     * @param timeBetweenArrivals Temps moyen d'arrivée des clients
     * @param averageServiceTime Temps moyen du temps de service d'un caissier
     */
    Bank(double expectedDuration, int nbCashiers, double timeBetweenArrivals, double* averageServiceTime);
    /**
    * @brief Démarrage de la simulation
    */
    void startSimulation();
    /**
    * @return Temps attendu de la simulation
    */
    double getExpectedDuration();
    /**
    * @return Temps moyen d'arrivée des clients
    */
    double getTimeBetweenArrivals();
    /**
    * @return Le premier caissier libre
    */
    Cashier* getFreeCashier();
    /**
    * @return La file d'attente
    */
    Queue* getQueue();
    /**
    * @brief Ajout un caissier libre dans une pile
    * @param c Caissier
    */
    void addFreeCashiersToList(Cashier* c);
};

#endif //SIMULATIONBANQUE_BANK_H
