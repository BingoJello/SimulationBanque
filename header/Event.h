#ifndef SIMULATIONBANQUE_EVENT_H
#define SIMULATIONBANQUE_EVENT_H

class Simulation;

class Event {
protected :
    double _time;
    Simulation* _simulation;
public:
    /**
    * @brief Evenement (Arrivée ou Départ)
    * @param time Temps de l'apparition de l'évenement
    * @param s Simulation
    */
    explicit Event(double time, Simulation* sim);
    /**
     * @brief Destructeur
     */
    virtual ~Event();
    /**
    * @brief Processus de l'évenement
    */
    virtual void process();
    /**
    * @brief Renvoie le temps d'apparition de l'évenement
    * @return Temps de l'évenement
    */
    double getTime() const;
};

#endif //SIMULATIONBANQUE_EVENT_H
