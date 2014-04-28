/**
 * @File:   quicksort.h
 * @Author: Ilya Trofimov
 * @Email:  ilyatrofimov@outlook.com
 * @Date:   2014-04-19 22:18:06
 *
 * @Last Modified by:   Ilya Trofimov
 * @Last Modified time: 2014-04-25 19:27:38
 */


#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sort.h"

class quicksort : public sort {
private:
    void sortPartition(int left, int right);
    int findPivot(int left, int right);
    int partition(int left, int right);

protected:
    void init(int how_many, int workload_type);

public:
    quicksort(int how_many, int workload_type);
    void sortNumbers();
};

#endif
