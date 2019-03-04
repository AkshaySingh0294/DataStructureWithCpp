#ifndef BASICOPERATIONS_H
#define BASICOPERATIONS_H
#include "LinkedListControl/ListCreation/doublelinkedlistcreation.h"
#include "LinkedListControl/ListCreation/singlelinkedlistcreation.h"
#include <iostream>
using namespace std;

class BasicOperations
{
public:
    BasicOperations();

    //For Double Linked List
    void insertionAtDLFront(dlNode **head, int num);
    void insertionAtDLGivenNode(dlNode **head, dlNode **tail, int num, int pos);    //starts from 0th position
    void insertionAtDLEnd(dlNode **head, dlNode **tail, int num);

    //For Single Linked list
    void insertionAtSlFront(node **head, int num);
    void insertionAtSlGivenNode(node **head, int num);
    void insertionAtSlEnd(node **head, node **tail, int num);

    //Show array
    void showDl(dlNode *head);
    void showSl(node *head);

private:
    DoubleLinkedListCreation *dlC;
    SingleLinkedListCreation *slC;
};

#endif // BASICOPERATIONS_H
