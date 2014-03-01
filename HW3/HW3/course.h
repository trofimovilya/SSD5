/**
 * Author: Ilya Trofimov
 * Group: 272(2)
 * Date: 11 Feb 2014
 */

#ifndef COURSE_H
#define COURSE_H

#include "safearray.h"

int const MAX_LINES = 10;

class course {

public:
    string name;
    string title;
    safearray<string> description;

    course() : description(safearray<string>(MAX_LINES)), name(""), title("") {}
    course(string name, string title) : description(safearray<string>(MAX_LINES)), name(name), title(title) {}

    friend ostream& operator<<(ostream&, const course&);
    friend istream& operator>>(istream&, course&);
};

ostream& operator<<(ostream& out, const course& c) {

    out << c.name << ": " << c.title << "\n";

    int index = 0;

    try	{
        while (c.description[index] != "") {
            out << c.description[index++] << "\n";
        }
    }

    catch (out_of_range& e) {
        cerr << e.what() << endl;
    }

    return out;
}

istream& operator>>(istream& in, course& c) {
    getline(in, c.name);
    getline(in, c.title);

    string line;
    getline(in, line);
    
    int number = 0;

    try	{
        while (line != "") {
            c.description[number++] = line;
            getline(in, line);
        }
    }

    catch (out_of_range& e) {
        cerr << e.what() << endl;
    }

    return in;
}

#endif
