#include "singlelinkedlistcreation.h"

string SingleLinkedListCreation::getListType() const
{
    return listType;
}

void SingleLinkedListCreation::setListType(const string &value)
{
    listType = value;
}

SingleLinkedListCreation::SingleLinkedListCreation()
{

}

node *SingleLinkedListCreation::addToSll(node *tail, int num)
{
    node *newnode;
    createNewSN(&newnode);
    newnode->data = num;
    if(tail != nullptr)
        tail->next = newnode;
    tail = newnode;
    return tail;
}

void SingleLinkedListCreation::createNewSN(node **newnode)
{
    node *temp = *newnode;
    temp = new node;
    temp->next = nullptr;
    *newnode = temp;
}
