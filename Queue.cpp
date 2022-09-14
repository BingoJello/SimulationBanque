#include "header/Queue.h"

/**
 * @brief Constructeur
 * @param b Banque
 */
Queue::Queue(Bank* b) {
    _bank = b;
    _lastModifTime = 0;
    _timeSpentClients = 0;
    _queueLength = 0;
    _nbrClientServed = 0;
}

/**
 * @brief Ajout un client dans la file d'attente
 * @param c Client
 */
void Queue::add(Client* c) {
    _clients.push_back(c);
    int size = _clients.size();
    cout << size <<"yyyyyyyyyy";
    if(_maxLength < size){
        _maxLength = size;
    }
}

/**
 * @brief Retire le premier client de la file d'attente
 * @return Client
 */
Client* Queue::remove() {
    _nbrClientServed++;
    updateAverage();
    Client* c = _clients.front();
    _timeSpentClients += (_bank->getTime() - c->getArrivalTime());
    _clients.pop_front();
    return c;
}

/**
 * @brief Vérifie que la file d'attente est vide
 * @return boolean
 */
bool Queue::isEmpty() {
    return _clients.empty() ? true : false;
}

/**
 * @brief Renvoie la taille maximale de la file d'attente
 * @return Taille max
 */
int Queue::getMaxLength() {
    return _maxLength;
}

/**
 * @brief Renvoie la taille moyenne de la file d'attente
 * @return Taille moyenne
 */
/* Returns the number of client waiting in average in the queue */
double Queue::getAverageLength() {
    if(0 ==_bank->getTime()) return 0;

    updateAverage();
    return _queueLength / _bank->getTime();
}

/**
 * @brief Renvoie le temps moyen d'attente des clients dans la file d'attente
 * @return Temps moyen d'attente
 */
double Queue::getAverageWaitingTime() {
    if(0 == _nbrClientServed) return 0;
    return _timeSpentClients / _nbrClientServed;
}

/**
 * @brief Effectue une mise à jour de la taille de la file d'attente
 */
void Queue::updateAverage() {
    double timeDiff = _bank->getTime() - _lastModifTime;
    _queueLength += _clients.size()*timeDiff;
    _lastModifTime = _bank->getTime();
}