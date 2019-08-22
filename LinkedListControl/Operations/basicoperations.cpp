#include "basicoperations.h"

BasicOperations::BasicOperations()
{
    singleOperation();
    //    doubleOperation();
}

void BasicOperations::singleOperation()
{
    //    slC = new SingleLinkedListCreation;
    //    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    //    node *sHead = new node;
    //    node *sTail = new node;
    //    sHead = sTail = nullptr;
    //    //Single linked list creation
    //    for(int i : array)
    //    {
    //        sTail = slC->addToSll(sTail,i);
    //        if(sHead == nullptr)
    //        {
    //            sHead = sTail;
    //        }
    //    }
    //    showSl(sHead);
    //    insertionAtSlFront(&sHead,100);
    //    showSl(sHead);
    //    insertionAtSlEnd(&sHead,&sTail,100);
    //    showSl(sHead);
    //    deleteSingleLinkedList(&sHead);
    //    createLoopInSL(&sHead, &sTail);
    //    detectLoop(&sHead);
    //    palindromeCheckSLL(sHead);
    //    palindromeCheckRecursiveSSL(sHead, sHead);
    //    removeDuplicate(sHead);
    //    sHead = swapGivenNumberOfNodes(sHead,2,1,5,7); //position start with 0;
    createAndGetLLIntersection();
    cout<<endl;
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

bool BasicOperations::checkIfNodesSwapable(node *head, int number, int position, int number2, int position2)
{
    if(position <  0 || position2 < 0) {
        cout<<"position should be equal to or greater than 0";
        return false;
    }
    if(number <= 0 || number2 <= 0){
        cout<<"number should be greater than 0";
        return false;
    }
    int num1 = number;
    int num2 = number2;
    int length = getSLLLength(head);
    int x1 = length-(position+number);
    int x2 = length-(position2+number2);
    if((length-(position+number)) < 0){
        cout<<"Number 1 and Position 1 are not usable for swapping"<<endl;
        return false;
    }
    if((length-(position2+number2)) < 0){
        cout<<"Number 2 and Position 2 are not usable for swapping"<<endl;
        return false;
    }
    node *array[num1];
    array[0] = head;
    int count = 0;
    int iterator = 0;
    node *ptr = head;
    while(ptr != nullptr){
        if(count >= position && num1 !=0 ){
            array[iterator] = ptr;
            ++iterator;
            --num1;
        }
        if(num1 == 0){
            break;
        }
        ptr = ptr->next;
        ++count;
    }
    ptr = head;
    count = 0;
    while(ptr != nullptr){
        if(count >= position2 && num2 !=0 ){
            for(int i=0; i<number; i++){
                if(array[i] == ptr){
                    cout<<"positions of specifed values overlap eachother--------cannot swap";
                    return false;
                }
            }
            --num2;
        }
        if(num2 == -1){
            break;
        }
        ptr = ptr->next;
        ++count;
    }
    return true;
}

node* BasicOperations::swapGivenNumberOfNodes(node *head, int number, int position, int number2, int position2)
{
    if(position > position2){
        int temp = position2;
        position2 = position;
        position = temp;

        temp = number;
        number = number2;
        number2 = temp;
    }
    if(!checkIfNodesSwapable(head,number,position,number2,position2)){
        cout<<endl<<"Nodes are not swappable";
        return head;
    }

    int pos1, num1, pos2, num2;
    pos1 = position;
    pos2 = position2;
    num1 = number;
    num2 = number2;

    node *ptr2_1, *ptr2_2, *ptr2_3, *ptr2_4;
    ptr2_1 = ptr2_2 = ptr2_3 = ptr2_4 = head;
    node *tempPtr = new node;
    int count = 0;
    int iterator = 0;
    while(iterator != position2-1){
        ptr2_1 = ptr2_1->next;
        ++iterator;
    }
    ptr2_3 = ptr2_2 = ptr2_1->next;
    while(num2 > 1){
        ptr2_3 = ptr2_3->next;
        --num2;
    }
    ptr2_4 = ptr2_3->next;      //right side are made stable

    node *ptr1_1, *ptr1_2, *ptr1_3, *ptr1_4;
    ptr1_1 = ptr1_2 = ptr1_3 = ptr1_4 = head;
    iterator = 0;
    if(position != 0){
        while(iterator != position-1){
            ptr1_1 = ptr1_1->next;
            ++iterator;
        }
    }
    if(position == 0)
        ptr1_3 = ptr1_2 = ptr1_1;
    else
        ptr1_3 = ptr1_2 = ptr1_1->next;
    while(num1 > 1){
        --num1;
        ptr1_3 = ptr1_3->next;
    }
    ptr1_4 = ptr1_3->next;  //left side are made stable.

    if(ptr1_1 == ptr1_2){
        ptr2_3->next = ptr1_4;
        head = ptr2_2;

        ptr2_1->next = ptr1_1;
        ptr1_3->next = ptr2_4;
    }else{
        ptr1_1->next = ptr2_2;
        ptr2_3->next = ptr1_4;

        ptr2_1->next = ptr1_2;
        ptr1_3->next = ptr2_4;
    }
    return head;
}

int BasicOperations::getSLLLength(node *head)
{
    int count = 0;
    while(head != nullptr){
        ++count;
        head = head->next;
    }
    return count;
}

void BasicOperations::createAndGetLLIntersection()
{
    SingleLinkedListCreation *linkedlist = new SingleLinkedListCreation;
    node *head1,*head2, *tail1, *tail2;
    head1 = head2 = tail1 = tail2 = nullptr;
    tail1 = linkedlist->addToSll(tail1,1);
    head1 = tail1;
    tail1 = linkedlist->addToSll(tail1,2);

    tail2 = linkedlist->addToSll(tail2,-1);
    head2 = tail2;
    tail2 = linkedlist->addToSll(tail2,-2);

    int array[5] = {10,11,12,13,14};
    for(int i : array)
    {
        tail1 = slC->addToSll(tail1,i);
    }
    node* newnode = head1;
    int counter = 0;
    while(counter != 2){
        newnode = newnode->next;
        counter++;
    }
    tail2->next = newnode;
    tail2 = tail1;
    tail2 = linkedlist->addToSll(tail2,100);

    cout<<"Dummy lists:"<<endl;
    node* ptr = nullptr;
    ptr = head1;
    while(ptr!= tail1->next){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl;

    ptr = head2;
    while(ptr!= tail2->next){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl<<"Intersection list:"<<endl;
    node* head3, *tail3;
    head3 = tail3 = nullptr;
    node* ptr2 = head2;
    ptr = head1;
    while(ptr != tail1->next){
        ptr2 = head2;
        while(ptr2 != tail2){
            if(ptr == ptr2){
                if(head3 == nullptr){
                    head3 = tail3 = ptr;
                }else{
                    tail3->next = ptr;
                    tail3 = ptr;
                }
                break;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }


    ptr = head3;
    while(ptr!= tail3->next){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
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


