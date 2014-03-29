#include "car.h"

Car::Car(string plate) :
    license_plate(plate),
    moved(0), aisle(-1) {}

Car::Car(string plate, int aisle) :
    license_plate(plate),
    moved(0), aisle(aisle) {}

int Car::getTimesMoved(void) const {

    return moved;
}

void Car::setTimesMoved(int m) {

    moved = m;
}

int Car::getAisle(void) const {

	return aisle;
}

string Car::getPlate(void) const {

    return license_plate;
}

bool Car::operator < (const Car& rhs) const {
	
	return this->getPlate() < rhs.getPlate();
}

bool Car::operator == (const Car& rhs) const {
	
	return this->getPlate() == rhs.getPlate();
}
