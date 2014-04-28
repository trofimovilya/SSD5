/**
 * \file    quicksort.cpp
 * \author  Ilya Trofimov
 * \email   ilyatrofimov@outlook.com
 * \date    2014-04-22 09:54:59
 *
 * \modifiedby   Ilya Trofimov
 * \modifiedtime 2014-04-26 21:01:08
 */


#include "quicksort.h"

/*
 * You should implement this. It is the meat of the constructor
 * and is also used by the reset() method.
 *
 * It will create the QuickSort object with an "unsorted" list.
 *
 * - how_many is the number of elements in the list.
 * - workload_type is BEST_CASE, WORST_CASE, or AVG_CASE
 */


void quicksort::init(int how_many, int workload_type) {
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
    srand(clock() / 1000);

    switch (workload_type) {
        case (BEST_CASE):
        case (AVG_CASE): {
            bool isSorted = true;
            bool isReversed = true;

            if (how_many == 1) {
                numbers[0] = rand();
                break;
            }

            while (isSorted || isReversed) {
                isSorted = true;
                isReversed = true;

                numbers[0] = rand();

                for (int i = 1; i < how_many; i++) {
                    numbers[i] = rand();

                    if (numbers[i - 1] > numbers[i]) {
                        isSorted = false;
                    } else if (numbers[i - 1] < numbers[i]) {
                        isReversed = false;
                    }
                }
            }

            break;
        }

        case (WORST_CASE):
            for (int i = 0; i < how_many; i++) {
                numbers[i] = i;
            }

            break;
    }
}


/*
 * This is the constructor. It is nothing more than a shell to
 * call init(). This allows init() to be used by both the constructor
 * and also the parent class's reset() method
 */
quicksort::quicksort(int how_many, int workload_type) {
    this->how_many = how_many;
    this->workload_type = workload_type;

    init(how_many, workload_type);
}


/*
 * This is the implementation of the quick sort algorithm that
 * extends the Sort class's abstract sortNumbers() method.
 *
 * It is really a wrapper for the private helper method, sortPartition(),
 * which does the real "divide and conquer".
 */
void quicksort::sortNumbers() {
    sortPartition(0, how_many - 1);
}

/*
 * This is a helper method called by sortNumbers(). It sorts
 * an individual partition about the pivot point.
 */
int quicksort::partition(int left, int right) {
    int pivot = numbers[left];
    int l = left + 1;
    int r = right;

    while (l <= r) {
        while (l <= right && numbers[l] <= pivot) {
            l++;
        }

        while (r >= left && numbers[r] > pivot) {
            r--;
        }

        if (l < r) {
            swapNumbers(l, r);
            l++;
            r--;
        }
    }

    swapNumbers(left, r); // put pivot in middle
    return r;
}

/*
 * This is a helper method called by sortNumbers(). It recursively
 * calls itself on subpartitions to sort the numbers. The actual
 * sorting within the partition is done by sortPartition(), which
 * is iterative.
 */
void quicksort::sortPartition(int left, int right) {
    int placed = partition(left, right);

    if ((placed - left) > 1) {
        sortPartition(left, placed - 1);
    }

    if ((right - placed) > 1) {
        sortPartition(placed + 1, right);
    }
}
