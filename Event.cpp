#include "header/Event.h"

/**
 * ^brief Evenement (Arrivée ou Départ)
 * @param time Temps de l'apparition de l'évenement
 * @param s Simulation
 */
Event::Event(double time, Simulation *s) {
    _time = time;
    _simulation = s;
}

Event::~Event() {

}

/**
 * @brief Processus de l'évenement
 */
void Event::process() {

}

/**
 * @brief Renvoie le temps d'apparition de l'évenement
 * @return Temps de l'évenement
 */
double Event::getTime() const {
    return _time;
}
