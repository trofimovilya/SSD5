// main.cpp -- driver program for "Sum of Its Parts"

#pragma warning(disable:4786)

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "parts.h"

void load_definitions(char* filename) {

    ifstream inf(filename);
    string part, subpart;

    int quantity;

    while (inf.good()) {
        inf >> part >> quantity >> subpart;

        if (!inf.good()) {
            return;
        }

        add_part(part, quantity, subpart);
    };
}

void whatis_query(string const& x) {
    Part* xp = partContainer.lookup(x);
    cout << endl;
    xp->describe();
}

void howmany_query(string const& x, string const& y) {
    Part* xp = partContainer.lookup(x);
    Part* yp = partContainer.lookup(y);
    cout << endl << y << " has " << yp->count_howmany(xp) << " " << x << endl;
}

void process_queries(char* filename) {
    ifstream inf(filename);
    string query, x, y;

    while (inf.good()) {

        inf >> query >> x;

        if (query == "howmany") {
            inf >> y;
        }

        if (!inf.good()) {
            return;
        }

        if (query == "howmany") {
            howmany_query(x, y);
        } else if (query == "whatis") {
            whatis_query(x);
        } else {
            cerr << "*** Illegal query: " << query << endl;
            return;
        };
    };
}

int main(void) {
    load_definitions("definitions.txt");
    process_queries("queries.txt");
    system("pause");
    return EXIT_SUCCESS;
}
