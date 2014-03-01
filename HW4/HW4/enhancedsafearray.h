/**
 * Author: Ilya Trofimov
 * Group: 272(2)
 * Date: 18 Feb 2014
 */

#ifndef ENHANCEDSAFEARRAY_H
#define ENHANCEDSAFEARRAY_H

#include "safearray.h"

template <class T> class EnhancedSafeArray : public SafeArray<T> {
public:
	EnhancedSafeArray(void);
	EnhancedSafeArray(int);
	EnhancedSafeArray(const EnhancedSafeArray<T> &);
    int size(void) const;  
	virtual EnhancedSafeArray<T> &operator= (EnhancedSafeArray<T>&);
	virtual bool operator== (EnhancedSafeArray<T> &);
};

template <class T> 
EnhancedSafeArray<T> :: EnhancedSafeArray () : SafeArray<T>() { }

template <class T> 
EnhancedSafeArray<T> :: EnhancedSafeArray (int count) : SafeArray<T>(count) { }

template <class T> 
EnhancedSafeArray<T> :: EnhancedSafeArray (const EnhancedSafeArray<T> &other) : SafeArray<T>(other.count) {
	for (int i = 0; i < count; ++ i) {
		storage[i] = other.storage[i];
	}
}

template <class T> 
EnhancedSafeArray<T>& EnhancedSafeArray<T> :: operator= (EnhancedSafeArray<T> &other) {
	if (this == &other) { 
        return *this; 
    }
	
    delete [] storage;
	
    count = other.count;
	storage = new T[count];
	
    for (int i = 0; i < count; ++ i) {
		storage[i] = other.storage[i];
	}
	
    return *this;
}

template <class T> 
bool EnhancedSafeArray<T> :: operator== (EnhancedSafeArray<T> &other) {
	if (count != other.count) {
		return false;
	}

	for (int i = 0; i < count; ++ i) {
		if (storage[i] != other.storage[i]) {
			return false;
		}
	}

	return true;
}

template <class T>
int EnhancedSafeArray<T>::size() const {
	return count;	
}

#endif