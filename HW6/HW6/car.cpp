// Author: Ilya Trofimov
// Group: 272(2)
// Date: 04 Mar 2014


#include "car.h"

Car::Car(string plate) : plate(plate), timesMoved(0) { }

string Car::getPlate() {
    return plate;
}

unsigned Car::getTimesMoved() {
    return timesMoved;
}

void Car::move() {
    ++ timesMoved;
}
