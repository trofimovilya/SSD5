#ifndef _RAILSYSTEM_H_
#define _RAILSYSTEM_H_

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <queue>
#include <vector>

#include "Service.h"
#include "City.h"

using namespace std;

class Cheapest {

public:
    Cheapest() {}

    bool operator()(City* city1, City* city2) {

        return city1->total_fee > city2->total_fee;
    }

};


class RailSystem {

private:
    map<string, list<Service*> > outgoing_services;
    map<string, City*> cities;

    void load_services(const string& filename);
    void reset(void);
    string recover_route(const string& city);
    pair<int, int> calc_route(string from, string to);

public:

    RailSystem(const string& filename);
    ~RailSystem(void);

    void output_cheapest_route(const string& from, const string& to, ostream& out);
    bool is_valid_city(const string& name);
};


#endif
