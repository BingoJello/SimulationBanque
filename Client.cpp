//
// Created by arthur on 07/09/2022.
//

#include "header/Client.h"

Client::Client(double arrivalTime) {
    _arrivalTime = arrivalTime;
    _serviceStartTime = 0;
}
double Client::getArrivalTime() {
    return _arrivalTime;
}

double Client::getServiceStartTime() {
    return _serviceStartTime;
}

double Client::setServiceStartTime(double sst) {
    _serviceStartTime = sst;
}