#include "mergesort_doublylinkedlist.h"

MergeSort_DoublyLinkedList::MergeSort_DoublyLinkedList()
{
    createList();
}

void MergeSort_DoublyLinkedList::createList()
{
    int arr[10] = {10,20,15,30,27,88,1,-1,-21,-100};
    dlNode *head = new dlNode;
    dlNode *tail = new dlNode;
    head = tail = nullptr;
    for(int i=0; i<10; i++)
    {
        tail = addToList(tail,arr[i]);
        if(head == nullptr)
            head = tail;
    }


    mergeDivide(&head);
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

dlNode *MergeSort_DoublyLinkedList::addToList(dlNode *tail, int num)
{
    dlNode *node = newNode(num);
    if(tail == nullptr)
    {
        tail = node;
    }
    else
    {
        tail->next = node;
        node->previous = tail;
        tail = node;
    }
    return tail;
}

dlNode *MergeSort_DoublyLinkedList::newNode(int num)
{
    dlNode *node = new dlNode;
    node->data = num;
    node->next = nullptr;
    node->previous = nullptr;
    return node;
}

void MergeSort_DoublyLinkedList::mergeDivide(dlNode **head)
{
   dlNode* first = new dlNode;
   dlNode* second = new dlNode;
   dlNode* temp = new dlNode;
   first = temp = *head;
   if(first == nullptr || first->next ==  nullptr)
       return;
   else
   {
       while(first->next != nullptr)
       {
           first = first->next;
           if(first->next != nullptr)
           {
               temp = temp->next;
               first = first->next;
           }
       }
       second = temp->next;
       temp->next = nullptr;
       first = *head;
   }
   mergeDivide(&first);
   mergeDivide(&second);
   *head = startMerge(first,second);
}

dlNode *MergeSort_DoublyLinkedList::startMerge(dlNode *head, dlNode *tail)
{
    dlNode *result = new dlNode;
    if(head == nullptr)
        return  tail;
    else if(tail ==  nullptr)
        return  head;
    else{
        if(head->data <= tail->data)
        {
            result = head;
            result->next = startMerge(head->next,tail);
            result->next->previous = result;
            result->previous = nullptr;
        }
        else
        {
            result = tail;
            result->next = startMerge(head,tail->next);
            result->next->previous = result;
            result->previous = nullptr;
        }
        return  result;
    }
}
