#include "selectionsort.h"

SelectionSort::SelectionSort()
{
    startSelectionSort();
}

void SelectionSort::startSelectionSort()
{
    int array[] = {14,33,27,10,35,19,42,44};
    for(int i = 0; i < 8; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i < 8; i++)
    {
        int min  = array[i];
        int index = i;
        for(int j = i; j < 8; j++)
        {
            if(array[j] < min)
            {
                min = array[j];
                index = j;
            }
        }
        int temp = array[index];
        array[index] = array[i];
        array[i] = temp;
        for(int i = 0; i < 8; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
}
