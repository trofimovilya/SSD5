// Author: Ilya Trofimov
// Group: 272(2)
// Date: 04 Mar 2014

#include <iostream>
#include <fstream>
#include <stack>
#include "car.h"

using namespace std;

const int MAX_CARS = 5;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Specify exactly one parameter" << endl;
        return 1;
    }

    ifstream input(argv[1]);

    if (!input) {
        cout << "Failed to open file " << argv[1] << endl;
        return 1;
    }

    stack<Car*> parkingLot, tmp;
    string plate;
    string action;

    while (! input.eof()) {
        input >> plate >> action;

        if (action == "arrives") {
            if (parkingLot.size() >= MAX_CARS) {
                cout << "Sorry " << plate << ", the lot is full" << endl;
                continue;
            }

            Car* car = new Car(plate);
            parkingLot.push(car);
        } else { // action == "departs"
            while (! parkingLot.empty() && parkingLot.top()->getPlate() != plate) {
                tmp.push(parkingLot.top());
                parkingLot.pop();
            }

            if (parkingLot.empty()) {
                cout << plate << " is not here" << endl;

                while (! tmp.empty()) {
                    // the cars were not moved actually
                    parkingLot.push(tmp.top());
                    tmp.pop();
                }
            } else {
                Car* car = parkingLot.top();
                parkingLot.pop();
                cout << car->getPlate() << " was moved " << car->getTimesMoved() << " times while it was here" << endl;
                delete car;

                while (! tmp.empty()) {
                    tmp.top()->move();
                    parkingLot.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }

    while (! parkingLot.empty()) {
        Car* car = parkingLot.top();
        parkingLot.pop();
        cout << car->getPlate() << " was moved " << car->getTimesMoved() << " times while it was here" << endl;
        delete car;
    }
    system("pause");
    return 0;
}
