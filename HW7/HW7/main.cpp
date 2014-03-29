/*
* @Author: Ilya Trofimov
* @Date:   2014-03-18 13:01:28
* @Last Modified by:   Ilya Trofimov
* @Last Modified time: 2014-03-18 13:08:00
*/

#pragma warning(disable:4786)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "car.h"

using namespace std;

const int PARKING_SPOTS_PER_AISLE = 3;
const int NUMBER_OF_AISLES = 5;

void handle_arrival(vector<Car>&, vector<stack<string> >&, const string&);
void handle_departure(vector<Car>&, vector<stack<string> >&, const string&);
Car& find_car(vector<Car>&, string);

int main(int argc, char* argv[]) {

    try {

        if (argc != 2) {
            cerr << "Usage:\n" << argv[0] << " data-file";
            return EXIT_FAILURE;
        }

        ifstream inf(argv[1]);

        if (! inf) {
            cerr << "Could not open " << argv[1];
            return EXIT_FAILURE;
        }

        vector<Car> cars;
        vector< stack<string> > parking_lot(NUMBER_OF_AISLES);

        while (! inf.eof()) {

            string action, plate;
            inf >> plate >> action;

            if (action == "arrives") {
                handle_arrival(cars, parking_lot, plate);
            } else if (action == "departs") {
                handle_departure(cars, parking_lot, plate);
            } else {
                cerr << "Unknown action: " << action << endl;
            }

        }

        inf.close();

        cout << "\nHere are all the cars that visited the lot today:\n";

        sort(cars.begin(), cars.end());

        for (auto it = cars.begin(); it != cars.end(); ++it) {
            cout << it->getPlate() << endl;
        }

        vector<Car>().swap(cars);
        vector<stack<string>>().swap(parking_lot);
        
        system("pause");
        return EXIT_SUCCESS;

    } catch (exception& e) {
        cerr << e.what() << endl;
    } catch (...) {
        cerr << "Unknown exception caught!" << endl;
    }

    return EXIT_FAILURE;
}

void handle_arrival(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {
    for (int i = 0; i < NUMBER_OF_AISLES; ++i) {
        if (parking_lot[i].size() < PARKING_SPOTS_PER_AISLE) {
            parking_lot[i].push(plate);
            cars.push_back(Car(plate, i));
            return;
        }
    }

    cout << "All parking lots are full" << endl;
}

void handle_departure(vector<Car>& cars, vector< stack<string> >& parking_lot, const string& plate) {
    stack<string> temp_stack;
    Car temp_car = find_car(cars, plate);
    int aisle_number = temp_car.getAisle();
    string temp_plate = parking_lot[aisle_number].top();

    cout << temp_car.getPlate() << " was moved " << temp_car.getTimesMoved() << " times" << endl;

    while (temp_plate != plate) {
        Car& t = find_car(cars, temp_plate);
        parking_lot[aisle_number].pop();
        t.setTimesMoved(t.getTimesMoved() + 1);
        temp_stack.push(temp_plate);
        temp_plate = parking_lot[aisle_number].top();
    }

    parking_lot[aisle_number].pop();

    while (!temp_stack.empty()) {
        parking_lot[aisle_number].push(temp_stack.top());
        temp_stack.pop();
    }
}

Car& find_car(vector<Car>& cars, string plate) {
    return *find(cars.begin(), cars.end(), Car(plate));
}
