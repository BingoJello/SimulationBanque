//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_CLIENT_H
#define SIMULATIONBANQUE_CLIENT_H


class Client {
private:
    double _arrivalTime;
public:
    Client(double arrivalTime);
    double getArrivalTime();
};


#endif //SIMULATIONBANQUE_CLIENT_H
