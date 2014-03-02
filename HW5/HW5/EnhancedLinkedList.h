// Author: Ilya Trofimov
// Group: 272(2)
// Date: 25 Feb 2013

#ifndef ENHANCEDLINKEDLIST_H
#define ENHANCEDLINKEDLIST_H

#include "LinkedList.h"

using namespace std;

class ListItemNotFoundException : public logic_error {

public:
    ListItemNotFoundException(const string& what_arg) throw() :
        logic_error ("List item not found exception: " + what_arg) {}
};

template<class T>
class EnhancedLinkedList : public LinkedList<T> {

public:
    T& find_first(const T& key);
    EnhancedLinkedList<T> find_all(const T& key);
    void remove_first(const T& key);
    void remove_all(const T& key);
};

#include "EnhancedLinkedList.cpp"
#endif
