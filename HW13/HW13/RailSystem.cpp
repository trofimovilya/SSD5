/**
 * \file    RailSystem.cpp
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-05-20 15:00:07
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-05-20 16:10:40
 */


#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "RailSystem.h"
#include <stack>

const int MAX_FEE = 1000000;

void RailSystem::reset(void) {

    // TODO: reset the data objects of the
    // City objects' contained in cities
    map<string, City*>::iterator it = cities.begin();

    for (; it != cities.end(); it++) {
        it->second->from_city = "";
        it->second->total_distance = 0;
        it->second->total_fee = MAX_FEE;
        it->second->visited = false;
    }
}

RailSystem::RailSystem(string const& filename) {

    load_services(filename);
}

void RailSystem::load_services(string const& filename) {

    ifstream inf(filename.c_str());
    string from, to;
    int fee, distance;

    while (inf.good()) {

        // Read in the from city, to city, the fee, and distance.
        inf >> from >> to >> fee >> distance;

        if (inf.good()) {

            // TODO: Add entries in the cities container and
            // and services in the rail system for the new
            // cities we read in.
            City* fromCity = new City(from);
            City* toCity = new City(to);
            cities.insert(map<string, City*>::value_type(from, fromCity));
            cities.insert(map<string, City*>::value_type(to, toCity));

            if (fee < 0) {
                cout << "\nNegative fees are not available" << endl;
                cout << "Route from " << from << " to " << to ;
                cout << " will be blocked!" << endl;
                fee = MAX_FEE;
            }

            outgoing_services[from].push_back(new Service(to, fee, distance));
        }
    }

    inf.close();
}

RailSystem::~RailSystem(void) {

    // TODO: release all the City* and Service*
    // from cities and outgoing_services
    map<string, City*>::iterator citiesIt = cities.begin();

    for (; citiesIt != cities.end(); citiesIt++) {
        City* p = citiesIt->second;
        delete p;
    }

    cities.clear();

    map<string, list<Service*>>::iterator servicesIt = outgoing_services.begin();

    for (; servicesIt != outgoing_services.end(); servicesIt++) {
        list<Service*> servicesList = servicesIt->second;

        for (int i = 0; i < servicesList.size(); i++) {
            Service* service = servicesList.front();
            servicesList.pop_front();
            delete service;
        }

        servicesList.clear();
    }

    outgoing_services.clear();
}

void RailSystem::output_cheapest_route(const string& from,
                                       const string& to, ostream& out) {

    reset();
    pair<int, int> totals = calc_route(from, to);

    if (totals.first == INT_MAX) {
        out << "There is no route from " << from << " to " << to << "\n";
    } else {
        out << "The cheapest route from " << from << " to " << to << "\n";
        out << "costs " << totals.first << " euros and spans " << totals.second
            << " kilometers\n";
        cout << recover_route(to) << "\n\n";
    }
}

bool RailSystem::is_valid_city(const string& name) {
    return cities.count(name) == 1;
}

void updateCity(City* cityToChange, City* cityFrom, Service* service) {
    cityToChange->total_fee = cityFrom->total_fee + service->fee;
    cityToChange->from_city = cityFrom->name;
    cityToChange->total_distance = cityFrom->total_distance + service->distance;
}

pair<int, int> RailSystem::calc_route(string from, string to) {

    priority_queue<City*, vector<City*>, Cheapest> candidates;

    // TODO: Implement Dijkstra's shortest path algorithm to
    // find the cheapest route between the cities
    City* sourceCity = cities[from];
    sourceCity->total_fee = 0;
    candidates.push(sourceCity);

    while (!candidates.empty()) {
        City* city = candidates.top();
        city->visited = true;
        candidates.pop();

        if (city->name == to) {
            break;
        }

        list<Service*>& servicesOf = outgoing_services[city->name];
        list<Service*>::iterator listOfServicesIt = servicesOf.begin();

        for (; listOfServicesIt != servicesOf.end(); listOfServicesIt++) {
            Service* service = *listOfServicesIt;
            City* nextCity = cities[service->destination];

            if (nextCity->visited == false) {
                if ((city->total_fee + service->fee) < nextCity->total_fee) {
                    if (nextCity->total_fee == MAX_FEE) {
                        updateCity(nextCity, city, service);
                        candidates.push(nextCity);
                    } else {
                        stack<City*> tempStack;

                        while (candidates.top() != nextCity) {
                            tempStack.push(candidates.top());
                            candidates.pop();
                        }

                        candidates.pop();
                        updateCity(nextCity, city, service);
                        candidates.push(nextCity);

                        while (!tempStack.empty()) {
                            candidates.push(tempStack.top());
                            tempStack.pop();
                        }
                    }

                }
            }
        }
    }

    // Return the total fee and total distance.
    // Return (INT_MAX, INT_MAX) if not path is found.
    if (cities[to]->visited) {
        return pair<int, int>(cities[to]->total_fee, cities[to]->total_distance);
    } else {
        return pair<int, int>(INT_MAX, INT_MAX);
    }
}


string RailSystem::recover_route(const string& city) {
    // TODO: walk backwards through the cities
    // container to recover the route we found

    City* toCity = cities[city];
    string path;

    while (true) {
        if (path == "") {
            path = toCity->name;
        } else {
            path = toCity->name + " to " + path;
        }

        if (toCity->from_city == "") {
            break;
        }

        toCity = cities[toCity->from_city];
    }

    return path;
}
