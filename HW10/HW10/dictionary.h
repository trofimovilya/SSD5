/**
 * \file    dictionary.h
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-04-22 10:02:45
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-04-28 22:18:27
 */


#ifndef  _DICTIONARY_H_
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function {
public:
    hash_function() {}

    unsigned int operator()(const string& s)  const {
        unsigned int hash   = 0;
        const char* pointerString = s.c_str();

        while (*pointerString) {
            hash = prime_list[0] * hash + *pointerString;
            ++pointerString;
        }

        return hash;
    }
};

class equality {
public:
    equality() {}
    bool  operator()(const string& A, const string& B)  const {
        return (A == B);
    }
};


class Dictionary: public HashSet<string, hash_function, equality> {
public:
    Dictionary(string fileName) : HashSet<string, hash_function, equality>() {
        ifstream in(fileName);

        if (!in) {
            cerr << "Could not open dictionary: " << fileName << "\n";
            return;
        }

        string line;

        while (in) {
            getline(in, line);
            insert(line);
        }
    }
};

#endif
