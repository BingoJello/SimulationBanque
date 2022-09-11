//
// Created by arthur on 07/09/2022.
//

#ifndef SIMULATIONBANQUE_CLIENT_H
#define SIMULATIONBANQUE_CLIENT_H


class Client {
private:
    double _arrivalTime;
    double _serviceStartTime;
public:
    Client(double arrivalTime);
    double getArrivalTime();
    double getServiceStartTime();
    void setServiceStartTime(double sst);
};


#endif //SIMULATIONBANQUE_CLIENT_H
