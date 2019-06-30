#ifndef MERGESORT_DOUBLYLINKEDLIST_H
#define MERGESORT_DOUBLYLINKEDLIST_H
#include "DefinitionControl/Definitions/nodedefinition.h"
#include <iostream>
using namespace std;

class MergeSort_DoublyLinkedList
{
public:
    MergeSort_DoublyLinkedList();
    void createList();
    dlNode* addToList(dlNode *tail, int num);
    dlNode* newNode(int num);
    void mergeDivide(dlNode **head);
    dlNode *startMerge(dlNode *head, dlNode* tail);
};

#endif // MERGESORT_DOUBLYLINKEDLIST_H
