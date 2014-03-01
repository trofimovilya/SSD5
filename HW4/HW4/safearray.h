#ifndef SAFEARRAY_H
#define SAFEARRAY_H

using namespace std;

template <class T>
class SafeArray {

protected:
    T *storage;
    size_t count;

public:
    SafeArray();
    SafeArray(size_t);
    virtual ~SafeArray(void);
    virtual T& operator[] (size_t) throw(out_of_range);
	virtual const T& operator[] (size_t) const throw(out_of_range);
};

// default constructor
template <class T>
SafeArray<T>::SafeArray () : storage(NULL), count(0) {}

// single param constructor
template <class T>
SafeArray<T>::SafeArray (size_t count) : storage(new T[count]), count(count) {}

// destructor
template <class T>
SafeArray<T>::~SafeArray(void) {
    delete [] storage;
}

// overloaded [] operator

template <class T>
T& SafeArray<T>::operator[] (size_t index) throw (out_of_range) {

    if (index < 0) {
        throw out_of_range("Index is below 0");
    }

    if (index >= count) {
        throw out_of_range("Index is too high");
    }

    return storage[index];
}


template <class T> 
const T& SafeArray<T>::operator[] (size_t cap)  const throw(out_of_range)
{
	 return const_cast <SafeArray<T>&>(*this)[cap];
};




#endif