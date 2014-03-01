/*
* homework.h
*
* This class models a homework assignment, including the name, date assigned,
* and due date. It allows assignments to be comapred based on their due
* date, and also allows them to be written to a stream in a nice format.
*
* Include your implementations of the member
* functions of this class in homework.cpp.
*/

#ifndef _HOMEWORK_H
#define _HOMEWORK_H

#include <iostream>
#include <string>
#include "date.h"

class homework;

ostream &operator<< (ostream &stream, homework h);

class homework {

private:
    string name; // Important note: Spaces within a name are not supported
    date assigned_date;
    date due_date;

public:
    homework ();
    homework (string name, date assigned_date, date due_date);

    // This should follow the Java syntax -- we'll discuss overloading
    // oeprators soon enough. The comparison should be based ont he due
    // date.
    int compareTo (homework another_homework);

    // The standard insertion operator.
    // It should output as follows:
    //      HW#1: 1/1/03 - 2/23/03
    friend ostream &operator<< (ostream &stream, homework h);

};

#endif // Nothing belongs below here
