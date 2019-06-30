#ifndef BASICOPERATIONS_H
#define BASICOPERATIONS_H
#include "LinkedListControl/ListCreation/doublelinkedlistcreation.h"
#include "LinkedListControl/ListCreation/singlelinkedlistcreation.h"
#include <iostream>
#include <forward_list>
using namespace std;

class BasicOperations
{
public:
    BasicOperations();

    //For Double Linked List
    void doubleOperation();
    void insertionAtDLFront(dlNode **head, int num);
    void insertionAtDLGivenNode(dlNode **head, dlNode **tail, int num, int pos);    //starts from 0th position
    void insertionAtDLEnd(dlNode **head, dlNode **tail, int num);
    void deleteDoubleLinkedList(dlNode **head);

    //For Single Linked list
    void singleOperation();
    void insertionAtSlFront(node **head, int num);
    void insertionAtSlGivenNode(node **head, int num);
    void insertionAtSlEnd(node **head, node **tail, int num);
    void deleteSingleLinkedList(node **ptr);
    void createLoopInSL(node **head, node **tail);
    void detectLoop(node **head);
    void fixLoopinSL(node **head);
    void palindromeCheckSLL(node *head);
    node *palindromeCheckRecursiveSSL(node *left, node *right);
    void removeDuplicate(node *head);

    //Show array
    void showDl(dlNode *head);
    void showSl(node *head);


private:
    DoubleLinkedListCreation *dlC;
    SingleLinkedListCreation *slC;
};

#endif // BASICOPERATIONS_H
