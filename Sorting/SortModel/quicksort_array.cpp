#include "quicksort_array.h"

QuickSort_Array::QuickSort_Array()
{
    startProcess();
}

void QuickSort_Array::startProcess()
{
    int arr[10] = {1,9,8,7,6,5,4,3,2,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    startSort(arr,0,size-1);
    for(int i = 0; i< size; i++)
    {
        cout <<arr[i]<<" ";
    }
}

void QuickSort_Array::startSort(int *a, int low, int high)
{
    if(low < high)
    {
        int newIndex = firstPivotSort(a,low,high);
        startSort(a,low,newIndex-1);
        startSort(a,newIndex+1,high);
    }
}

int QuickSort_Array::lastPivotSort(int *a, int low, int high)
{
    int pivot = a[high]; //pivot
    int i = (low-1); //index of smaller element
    for( int j = low; j <= high-1; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

int QuickSort_Array::firstPivotSort(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    for(int j = low+1; j <= high; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i],&a[low]);
    return i;
}

void QuickSort_Array::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


