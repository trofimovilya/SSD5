#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sort.h"

class selectionsort : public sort {
  protected:
    void init(int how_many, int workload_type);

  public:
    selectionsort(int how_many, int workload_type);
    void sortNumbers();

};

#endif
