#include "header/Client.h"

/**
 * @brief Constructeur
 * @param arrivalTime Temps d'arrivé du client
 */
Client::Client(double arrivalTime) {
    _arrivalTime = arrivalTime;
}
/**
 * @return Temps d'arrivé du client
 */
double Client::getArrivalTime() {
    return _arrivalTime;
}