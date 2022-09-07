//
// Created by arthur on 07/09/2022.
//

#include "header/Client.h"

Client::Client(double arrivalTime) {
    _arrivalTime = arrivalTime;
}
double Client::getArrivalTime() {
    return _arrivalTime;
}