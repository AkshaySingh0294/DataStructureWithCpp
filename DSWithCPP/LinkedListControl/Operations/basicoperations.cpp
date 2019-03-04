#include "basicoperations.h"

BasicOperations::BasicOperations()
{
    dlC = new DoubleLinkedListCreation;
    slC = new SingleLinkedListCreation;
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    dlNode *dHead = new dlNode;
    dlNode *dTail = new dlNode;

    node *sHead = new node;
    node *sTail = new node;

    dHead = dTail = nullptr;
    sHead = sTail = nullptr;
    //Double linked list creation
    for(int i : array)
    {
        dTail = dlC->addToDll(dTail,i);
        if(dHead == nullptr)
        {
            dHead = dTail;
        }
    }

    //Single linked list creation
    for(int i : array)
    {
        sTail = slC->addToSll(sTail,i);
        if(sHead == nullptr)
        {
            sHead = sTail;
        }
    }

    showDl(dHead);
    showSl(sHead);

    insertionAtDLFront(&dHead,100);
    insertionAtSlFront(&sHead,100);

    showDl(dHead);
    showSl(sHead);

    insertionAtDLEnd(&dHead,&dTail,100);
    insertionAtSlEnd(&sHead,&sTail,100);

    showDl(dHead);
    showSl(sHead);

    insertionAtDLGivenNode(&dHead,&dTail,99999,13);
    showDl(dHead);

}

void BasicOperations::insertionAtDLFront(dlNode **head, int num)
{
    dlNode *temp = *head;
    dlNode *newnode;
    dlC->createNewDN(&newnode);
    newnode->data = num;
    temp->previous = newnode;
    newnode->next = temp;
    *head = newnode;
}

void BasicOperations::insertionAtDLGivenNode(dlNode **head, dlNode **tail, int num, int pos)
{
    dlNode *tempHead = *head;
    dlNode *tempTail = *tail;
    if(head == nullptr || tail == nullptr)
    {
        cout<<endl<<"Incorrect List:"<<endl;
        return;
    }
    if(pos == 0)
    {
        insertionAtDLFront(&tempHead,num);
        *head = tempHead;
    }
    else
    {
        int count = 0;
        while(count != pos)
        {
            if(tempHead == tempTail && count <= pos-2)
            {
                cout<<endl<<"Position can be only upto - "<<count+1;
                return;
            }
            tempHead = tempHead->next;
            ++count;
        }
    }
}

void BasicOperations::insertionAtDLEnd(dlNode **head, dlNode **tail, int num)
{
    dlNode *temp1 = *head;
    dlNode *newnode;
    dlC->createNewDN(&newnode);
    newnode->data = num;
    while(temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    temp1->next = newnode;
    newnode->previous = temp1;
    *tail = newnode;
}

void BasicOperations::insertionAtSlFront(node **head, int num)
{
    node *newnode;
    slC->createNewSN(&newnode);
    newnode->data = num;
    newnode->next = *head;
    *head = newnode;
}

void BasicOperations::insertionAtSlGivenNode(node **head, int num)
{

}

void BasicOperations::insertionAtSlEnd(node **head, node **tail, int num)
{
    node *temp1 = *head;
    node *newnode;
    slC->createNewSN(&newnode);
    newnode->data = num;
    while(temp1->next != nullptr)
    {
        temp1 = temp1->next;
    }
    temp1->next = newnode;
    *tail = newnode;
}

void BasicOperations::showDl(dlNode *head)
{
    cout<<endl;
    cout<<"Double Linked List:"<<endl;
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void BasicOperations::showSl(node *head)
{
    cout << endl;
    cout<<"Single Linked List:"<<endl;
    while(head != nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


