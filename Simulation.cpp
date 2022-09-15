#include "header/Simulation.h"

/**
 * @brief Ajout un nouvel événement dans la simulation
 * @param e Événement
 */

void Simulation::add(Event *e) {
    _events.insert(e);
}

/**
 * @brief Démarre la simulation
 */
void Simulation::run() {
    for(_eventIterator = _events.begin() ; _eventIterator != _events.end() ; ++_eventIterator) {
        Event *e = *_eventIterator;
        _time = e->getTime();
        e->process();
    }
}

/**
 * @brief Renvoie le temps de la simulation
 * @return Temps simulation
 */
double Simulation::getTime() {
    return _time;
}
