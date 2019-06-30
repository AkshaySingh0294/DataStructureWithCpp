#include "insertionsort.h"

InsertionSort::InsertionSort()
{
    startInsertionSort();
}

void InsertionSort::startInsertionSort()
{
    int array[] = {4,3,2,10,12,1,5,6};
    for(int i = 0; i < 8; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i = 0;i < 8 ; i++)
    {
        int j = i;
        while(array[j] < array[j-1] && i >0)
        {
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            --j;
            for(int i = 0; i < 8; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
    }
}
