/**
 * Author: Ilya Trofimov
 * Group: 272(2)
 * Date: 11 Feb 2014
 */

#include "safearray.h"

template <class T>
safearray<T>::safearray(int c) 
	: capacity(c), storage(new T[c]) { }

template <class T>
safearray<T>::~safearray(void) {
	delete[] storage;
}

template <class T>
T& safearray<T>::operator[] (int i) const throw (out_of_range) {
	if (i < 0) {
		throw out_of_range("Index is below 0");
	}
	if (i >= capacity) {
		throw out_of_range("Index is too high");
	}
	return storage[i];
}
