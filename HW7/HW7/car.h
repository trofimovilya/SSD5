#include <iostream>
#include <string>
#ifndef _CAR_H_
#define _CAR_H_

using namespace std;

class Car {

    private:
        int moved;
        string license_plate;
		int aisle;
    
    public:
        Car(string); 
		Car(string, int); 
        
		int getTimesMoved(void) const;
		void setTimesMoved(int);
		string getPlate(void) const;
		int getAisle(void) const;

		bool operator < (const Car& rhs) const;
		bool operator == (const Car& rhs) const;
};

#endif