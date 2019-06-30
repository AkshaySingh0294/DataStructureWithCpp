#ifndef QUICKSORT_ARRAY_H
#define QUICKSORT_ARRAY_H
#include <iostream>
using namespace std;

class QuickSort_Array
{
public:
    QuickSort_Array();
    void startProcess();
    void startSort(int *a, int low, int high);
    int lastPivotSort(int *a, int low, int high);
    int firstPivotSort(int *a, int low, int high);
    void swap(int *a, int *b);
};

#endif // QUICKSORT_ARRAY_H
