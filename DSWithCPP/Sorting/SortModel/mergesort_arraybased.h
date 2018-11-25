#ifndef MERGESORT_ARRAYBASED_H
#define MERGESORT_ARRAYBASED_H
#include <iostream>
using namespace std;


class MergeSort_ArrayBased
{
public:
    MergeSort_ArrayBased();
    void startMergeSort();
    void mergeSortDivide(int *a, int low, int high);
    void mergeSortMerging(int *a, int low, int high, int mid);
};

#endif // MERGESORT_ARRAYBASED_H
