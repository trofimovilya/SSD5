// Author: Ilya Trofimov
// Group: 272(2)
// Date: 04 Mar 2014

#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car;

class Car {

private:
    string plate;
    unsigned timesMoved;

public:
    Car(string plate);

    string getPlate();
    unsigned getTimesMoved();
    void move();
};

#endif