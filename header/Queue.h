#ifndef SIMULATIONBANQUE_QUEUE_H
#define SIMULATIONBANQUE_QUEUE_H

#include <vector>
#include <deque>
#include "Bank.h"
#include "Client.h"

using namespace std;

class Client;
class Bank;

class Queue {
private:
    Bank* _bank;
    deque<Client*> _clients;
    int _maxLength;
    double _lastModifTime;
    double _timeSpentClients;
    double _queueLength;
    int _nbrClientServed;
    /**
    * @brief Effectue une mise à jour de la taille de la file d'attente
    */
    void updateAverage();
public:
    /**
    * @brief Constructeur
    * @param b Banque
    */
    Queue(Bank* b);
    /**
    * @brief Ajout un client dans la file d'attente
    * @param c Client
    */
    void add(Client* c);
    /**
    * @brief Retire le premier client de la file d'attente
    * @return Client
    */
    Client* remove();
    /**
    * @brief Vérifie que la file d'attente est vide
    * @return boolean
    */
    bool isEmpty();
    /**
    * @brief Renvoie la taille maximale de la file d'attente
    * @return Taille max
    */
    int getMaxLength();
    /**
    * @brief Renvoie la taille moyenne de la file d'attente
    * @return Taille moyenne
    */
    double getAverageLength();
    /**
    * @brief Renvoie le temps moyen d'attente des clients dans la file d'attente
    * @return Temps moyen d'attente
    */
    double getAverageWaitingTime();
};

#endif //SIMULATIONBANQUE_QUEUE_H
