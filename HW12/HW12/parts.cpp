/**
 * \file    parts.cpp
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-05-13 14:31:59
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-07-19 17:48:37
 */


#include "parts.h"
#include <iostream>

NameContainer partContainer;

void Part::describe(void) {
    map<Part*, int>::iterator it;
    cout << "Part " << name << " " << "subparts are: " << endl;

    if (subparts.size() == 0) {
        cout << "It has no subparts." << endl;
        return;
    }

    for (it = subparts.begin(); it != subparts.end(); it++) {
        cout << it->second << " " << it->first->name << endl;
    }
}

int Part::count_howmany(Part const* p) {
    map<Part*, int>::iterator it;
    int counter = 0;

    for (it = subparts.begin(); it != subparts.end(); it++) {
        if (it->first->name == p->name) {
            return it->second;
        } else if (it->first->subparts.size() != 0) {
            counter += it->second * it->first->count_howmany(p);
        }
    }

    return counter;
}

void add_part(string const& x, int q, string const& y) {
    Part* part = partContainer.lookup(x);
    Part* subPart = partContainer.lookup(y);
    part->subparts.insert(pair<Part*, int>(subPart, q));
}
