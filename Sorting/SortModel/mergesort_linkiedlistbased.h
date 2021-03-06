#ifndef MERGESORT_LINKIEDLISTBASED_H
#define MERGESORT_LINKIEDLISTBASED_H
#include <iostream>
#include "DefinitionControl/Definitions/nodedefinition.h"
using namespace std;

class MergeSort_LinkiedListBased
{
public:
    MergeSort_LinkiedListBased();
    void startMerge();
    node *addToList(node *tail, int data);
    node *newNode(int data);

    void mergeSort(node **head);
    node *mergeFinal(node *h1, node *h2);
};

#endif // MERGESORT_LINKIEDLISTBASED_H
