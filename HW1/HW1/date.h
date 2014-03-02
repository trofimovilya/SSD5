/*
* date.h
*
* This is a simple class that represents the date and allows dates
* to be written to a stream and compared.
*
* Include your implementations
* of the member functions of this class in date.cpp.
*/

#ifndef _DATE_H
#define _DATE_H

#include <iostream>

using namespace std;

class date;

ostream &operator<< (ostream &stream, date d);

class date {

private:
    int day;
    int month;
    int year;

public:
    // The default constructor
    date ();

    // Initializes the date with meaningful data
    date (int day, int month, int year);

    // This follows the Java semantics -- we'll look at overloading operators
    // a little bit later.
    int compareTo (date another_date);

    // This is the standard insertion operator. It should produce "mm/dd/yyyy"
    friend ostream &operator<< (ostream &stream, date d);
};

#endif // Nothing belongs below here
