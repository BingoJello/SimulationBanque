#ifndef SIMULATIONBANQUE_CLIENT_H
#define SIMULATIONBANQUE_CLIENT_H

class Client {
private:
    double _arrivalTime;
public:
    /**
    * @brief Constructeur
    * @param arrivalTime Temps d'arrivé du client
    */
    Client(double arrivalTime);
    /**
    * @return Temps d'arrivé du client
    */
    double getArrivalTime();
};

#endif //SIMULATIONBANQUE_CLIENT_H
