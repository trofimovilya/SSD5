/**
 * \file    parts.h
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-05-13 14:48:49
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-07-19 17:48:41
 */


#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Part {

public:
    string name;

    map<Part*, int> subparts;

    Part(string const& n) : name(n) {};
    void describe(void);
    int count_howmany(Part const* p);
};


class NameContainer  {
private:
    map<string, Part*> name_map;
public:
    NameContainer(void) {};

    Part* lookup(string const& name) {

        map<string, Part*>::iterator it;

        for (it = name_map.begin(); it != name_map.end(); it++) {
            if (it->first == name) {
                return it->second;
            }
        }

        Part* part = new Part(name);
        name_map.insert(pair<string, Part*>(name, part));
        return part;
    }
};

extern NameContainer partContainer;

void add_part(string const& x, int q, string const& y);
#endif
