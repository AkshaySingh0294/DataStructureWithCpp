#include "basicoperations.h"

BasicOperations::BasicOperations()
{
    singleOperation();
    //    doubleOperation();
}

void BasicOperations::singleOperation()
{
    slC = new SingleLinkedListCreation;
    int array[10] = {10,9,8,7,6,6,7,8,9,10};
    node *sHead = new node;
    node *sTail = new node;
    sHead = sTail = nullptr;
    //Single linked list creation
    for(int i : array)
    {
        sTail = slC->addToSll(sTail,i);
        if(sHead == nullptr)
        {
            sHead = sTail;
        }
    }
    showSl(sHead);
    insertionAtSlFront(&sHead,100);
    showSl(sHead);
    insertionAtSlEnd(&sHead,&sTail,100);
    showSl(sHead);
    //    deleteSingleLinkedList(&sHead);
    //    createLoopInSL(&sHead, &sTail);
    //    detectLoop(&sHead);
    //    palindromeCheckSLL(sHead);
    //    palindromeCheckRecursiveSSL(sHead, sHead);
    removeDuplicate(sHead);
    showSl(sHead);

}

void BasicOperations::doubleOperation()
{
    dlC = new DoubleLinkedListCreation;
    dlNode *dHead = new dlNode;
    dlNode *dTail = new dlNode;
    dHead = dTail = nullptr;
    //Double linked list creation
    int array[11] = {10,9,8,7,6,5,6,7,8,9,10};
    for(int i : array)
    {
        dTail = dlC->addToDll(dTail,i);
        if(dHead == nullptr)
        {
            dHead = dTail;
        }
    }
    showDl(dHead);
    insertionAtDLFront(&dHead,100);
    showDl(dHead);
    insertionAtDLEnd(&dHead,&dTail,100);
    showDl(dHead);
    insertionAtDLGivenNode(&dHead,&dTail,99999,13);
    showDl(dHead);
    //    deleteDoubleLinkedList(&dHead);
    //    showDl(dHead);
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

void BasicOperations::deleteDoubleLinkedList(dlNode **head)
{
    dlNode *current = *head;
    if(*head != nullptr){
        dlNode *nextPtr = current->next;
        delete *head;
        *head = nullptr;
        deleteDoubleLinkedList(&nextPtr);
    }
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

void BasicOperations::deleteSingleLinkedList(node **ptr)
{
    node *current = *ptr;
    if(*ptr != nullptr){
        node *nextPtr = current->next;
        delete *ptr;
        *ptr = nullptr;
        deleteSingleLinkedList(&nextPtr);
    }
}

void BasicOperations::createLoopInSL(node **head, node **tail)
{
    node *start = *head;
    node *end = *tail;
    end->next = start->next->next->next;
}

void BasicOperations::detectLoop(node **head)
{
    //The fast pointer slow pointer method
    node *fast, *slow;
    fast = slow = *head;
    fast = fast->next;
    while(1){
        if(slow == nullptr || fast == nullptr || fast->next == nullptr){
            cout<<"There is no loop"<<endl;
            break;
        }
        if(slow == fast){
            cout<<"LOOP FOUND"<<endl;
            fixLoopinSL(head);
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
}

void BasicOperations::fixLoopinSL(node **head)
{
    forward_list<node *> nodeList;
    node * start = *head;
    if(start != nullptr){
        nodeList.push_front(start);
        node *backPtr = start;
        node *fronPtr = start->next;
        while(1){
            for(node *iterator : nodeList){
                if(fronPtr == iterator){
                    backPtr->next = nullptr;
                    return;
                }
            }
            backPtr = fronPtr;
            fronPtr = fronPtr->next;
            nodeList.push_front(backPtr);
        }
    }
}

void BasicOperations::palindromeCheckSLL(node *head)
{
    int array[13];
    node *ptr = head;
    int count = 0;
    while(ptr != nullptr)
    {
        array[count++] = ptr->data;
        ptr = ptr->next;
    }
    ptr = head;
    --count;
    while(ptr != nullptr){
        if(array[count--] != ptr->data)
        {
            cout<<"Not a palindrome";
            return;
        }
        ptr = ptr->next;
    }
    cout<<"Is Palindrome";
}

node* BasicOperations::palindromeCheckRecursiveSSL(node *left, node *right)
{
    if(right != nullptr){
        left = palindromeCheckRecursiveSSL(left, right->next);
        if(left->data == right->data){
            left = left->next;
            if(left == nullptr)
            {
                cout<<"Its a palindrome"<<endl;
            }
            return left;
        }
        else{
            cout<<"Its not a palindrom"<<endl;
            return nullptr;
        }
    }
    return left;
}

void BasicOperations::removeDuplicate(node *head)
{
    node *ptr, *backPtr;
    while(head != nullptr){
        backPtr = head;
        ptr = head->next;
        while(ptr != nullptr){
            if(head->data == ptr->data){
                backPtr->next = ptr->next;
                delete ptr;
                ptr = backPtr->next;
            }else{
                backPtr = ptr;
                ptr = ptr->next;
            }
        }
        head = head->next;
    }
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


