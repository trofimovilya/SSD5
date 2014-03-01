/*
* homeworklist.h
*
* This maintains a collection of homework assignments. 
* It allows assignments to be added to the collection, and
* searched based on their due date. It can store up to 50 
* assignments.
*
* Include your implementations of
* the class member functions in homeworklist.cpp.
*
*/

#ifndef _HOMEWORKLIST_H
#define _HOMEWORKLIST_H

#include "homework.h"

const int LIST_MAX = 50; // Maximum of 50 assignments; change if desired

class homeworklist;

ostream &operator<< (ostream &stream, homeworklist hl);

class homeworklist {

private:
    homework list[LIST_MAX]; // Array of individual assignments
    int current_size; // total currently within array

public:
    homeworklist(); // default constructor
    bool add (homework h); // adds a new assignment to this collection

    // Returns a new homeworklist containing only those homeworks due
    // after, but not on, the specified date
    homeworklist dueafter (date d);

    // Returns a new homeworklist containing only those homeworks due
    // before, but not on, the specified date
    homeworklist duebefore (date d);

    // Returns a new homeworklist containing only those homeworks due
    // exactly on the specified date, but not before or after
    homeworklist dueon (date d);

    // The standard insertion operator. It should just list
    // one homework per line
    friend ostream &operator<< (ostream &stream, homeworklist hl);
};

#endif // Nothing belongs below here
