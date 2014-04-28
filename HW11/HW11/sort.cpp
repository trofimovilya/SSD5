#include "sort.h"

using namespace std;

/*
 * This resets a Sort object to an unsorted list with exactly the same
 * parameters, so tests can be rerun for accuracy
 */
void sort::reset() {
    init(how_many, workload_type);
}

/*
 * This method performs multiple iterations of the same
 * test and reports the average. It is used for accuracy.
 */
void sort::report() {
    float avg_swaps = 0;

    clock_t start = clock();

    for (int count = 0; count < ITERATIONS; count++) {
        reset();
        numswaps = 0;
        sortNumbers();
        avg_swaps += ((float)numswaps / ITERATIONS);
    }

    clock_t elapsed_time = (clock() - start) / (CLK_TCK / 1000);

    cout << how_many << " items: " << elapsed_time / ITERATIONS << " msec "
         << (int)(avg_swaps + 0.5) << " swaps" << endl;

}

/*
 * This method simply prints the list of number in whatever
 * order they happen to be in
 */
void sort::printNumbers() {
    for (int i = 0; i < how_many; i++) {
        cout << numbers[i] << "\t" << "***" << endl;
    }
}


/*
 * This method is just here as a convenience to the
 * derived sorts. Many of the sorts will need to swap
 * numbers within the list.
 */
void sort::swapNumbers(int x, int y) {

    if (x == y) {
        return;
    }

    numswaps++;

    int t = numbers[x];
    numbers[x] = numbers[y];
    numbers[y] = t;
}
