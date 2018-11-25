#include "mergesort_arraybased.h"

MergeSort_ArrayBased::MergeSort_ArrayBased()
{
    startMergeSort();
}
void MergeSort_ArrayBased::startMergeSort()
{
    int arr[] = {14,33,27,10,35,19,42,44,1};
    int n = 9;
    mergeSortDivide(arr, 0, n-1);

    // Printing the sorted data.
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

void MergeSort_ArrayBased::mergeSortDivide(int *a, int low, int high)
{
    int mid;
    mid = (low+high)/2;
    //Split the data into two half
    if(low < high)
    {
        mergeSortDivide(a,low,mid);
        mergeSortDivide(a,mid+1,high);
    }

    //Merge them to get sorted output.
    mergeSortMerging(a,low,high,mid);

}

void MergeSort_ArrayBased::mergeSortMerging(int *a, int low, int high, int mid)
{
    int i,j,k,temp[high-low+1];
    i = low;
    k = 0;
    j = mid+1;
    //merge the two parts into temp

    for(int z = i; z<= mid; z++)
    {
        cout<<a[z]<<" ";
    }

    for(int x = mid+1; x<= high; x++)
    {
        cout<<a[x]<<" ";
    }
    cout<<endl;
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for(i = low; i<= high; i++)
    {
        a[i] = temp[i-low];
    }
}
