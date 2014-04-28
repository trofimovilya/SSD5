/**
 * \file    selectionsort.cpp
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-04-22 02:01:23
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-04-26 21:01:29
 */


#include "selectionsort.h"

/*
 * You should implement this. It is the meat of the constructor
 * and is also used by the reset() method.
 *
 * It will create the SelectionSort object with an "unsorted" list.
 *
 * - how_many is the number of elements in the list.
 * - workload_type is BEST_CASE, WORST_CASE, or AVG_CASE
 */


void selectionsort::init(int how_many, int workload_type) {
    /*
     * Insert your code here
     *
     * IMPORTANT NOTE: You need to allocate the numbers array declared in
     * the sort class so that it can hold "how_many" numbers, and you
     * need to fill numbers (integers) into this array. The ordering
     * should be determined by the workload.
     *
     * Since you may be using the same workload for many different sorts
     * and configurations of the same sort, you might want to use
     * helper methods. Helper methods that should be accessible to
     * all of the sorts should be "protected (not public or private) and
     * placed in the Sort class. Helper methods used by only this sort
     * can stay in this file and be made "private".
     *
     * This method should NOT sort the array.
     */

    // seed the random number generator
    srand(clock() / 1000);

    for (int i = 0; i < how_many; i++) {
        numbers[i] = rand();
    }
}


/*
 * This is the constructor. It is nothing more than a shell to
 * call init(). This allows init() to be used by both the constructor
 * and also the parent class's reset() method
 */
selectionsort::selectionsort(int how_many, int workload_type) {
    this->how_many = how_many;
    this->workload_type = workload_type;

    init(how_many, workload_type);
}


/*
 * This is the implementation of the selection sort algorithm that
 * extends the Sort class's abstract sortNumbers() method.
 */
void selectionsort::sortNumbers() {
    for (int look_for = 0; look_for < (how_many - 1); look_for++) {
        int small = look_for;

        for (int candidate = look_for + 1; candidate < how_many; candidate++) {
            if (numbers[candidate] < numbers[small]) {
                small = candidate;
            }
        }

        swapNumbers(look_for, small);
    }
}
