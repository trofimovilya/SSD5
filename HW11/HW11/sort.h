#ifndef SORT_H
#define SORT_H

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

const int ITERATIONS = 10;
const int MIN_SIZE = 3000; // Smallest size list to test
const int MAX_SIZE = 24000; // largest size list to test

const int BEST_CASE = 1;
const int AVG_CASE = 2;
const int WORST_CASE = 3;

class sort {
  protected:
    clock_t start_time;
    int numbers[MAX_SIZE]; // list of numbers to sort (and then sorted)
    long numswaps; //incremented after each swap
    int how_many, workload_type;


    void swapNumbers(int x, int y);
    void startTiming();
    clock_t getElapsedTime();

    virtual void init(int how_many, int workload_type) = 0;


  public:
    void reset();
    void report();
    void printNumbers();

    virtual void sortNumbers() = 0;


};

#endif
