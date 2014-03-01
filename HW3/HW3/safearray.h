/**
 * Author: Ilya Trofimov
 * Group: 272(2)
 * Date: 11 Feb 2014
 */

#ifndef SAFEARRAY_H
#define SAFEARRAY_H

template <class T> 
class safearray {

  private:
    T *storage;
    int capacity;
  
  public:
    safearray() : storage(NULL), capacity(0) {} // default constructor
    safearray(int); // single param constructor
    ~safearray(void); // destructor
    T& operator[] (int i) const throw(out_of_range); 
};

#include "safearray.cpp"
#endif