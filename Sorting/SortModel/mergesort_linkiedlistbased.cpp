#include "mergesort_linkiedlistbased.h"

MergeSort_LinkiedListBased::MergeSort_LinkiedListBased()
{
    startMerge();
}

void MergeSort_LinkiedListBased::startMerge()
{
    int i,num,n = 10;
    int arr[] = {14,2,3,5,22,11,100,-1,23,56};
    struct node *head = new node;
    struct node *tail = new node;
    head = nullptr;
    tail = nullptr;
    for(i = 0; i < n; i++)
    {
        num = arr[i];
        tail = addToList(tail,num);
        if(head == nullptr)
            head = tail;
    }

    mergeSort(&head);

    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

node *MergeSort_LinkiedListBased::addToList(node *tail, int data)
{
    struct node *newnode;
    newnode = newNode(data);
    if(tail == nullptr)
    {
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = tail->next;
    }
    return  newnode;
}

node *MergeSort_LinkiedListBased::newNode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void MergeSort_LinkiedListBased::mergeSort(node **head)
{
    node *first = new node;
    node *second = new node;
    node *temp = new node;
    first = *head;
    temp = *head;
    if(first == nullptr || first->next == nullptr)
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
    mergeSort(&first);
    mergeSort(&second);

    *head = mergeFinal(first,second);
}

node* MergeSort_LinkiedListBased::mergeFinal(node *a, node*b)
{
    node *result = new node;
    result = nullptr;
    //Base case
    if(a == nullptr)
        return b;
    else if(b == nullptr)
        return a;

    if(a->data <= b->data)
    {
        result = a;
        result->next = mergeFinal(a->next,b);
    }
    else
    {
        result = b;
        result->next = mergeFinal(a,b->next);
    }
    return result;
}
