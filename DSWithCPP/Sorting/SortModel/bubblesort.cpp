#include "bubblesort.h"

BubbleSort::BubbleSort()
{
    runBubbleSorting();
}

void BubbleSort::runBubbleSorting()
{
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    for(int i = 0; i < int((sizeof (array) * 10)/sizeof (array)); i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < 10; i++){
        for (int j = 0; j< 10; j++){
            if(array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
        for(int i = 0; i < int((sizeof (array) * 10)/sizeof (array)); i++){
            cout<<array[i]<<" ";
        }
        cout <<endl;
    }
}

void BubbleSort::swap(int &a, int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
