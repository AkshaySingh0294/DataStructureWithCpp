#include "doublelinkedlistcreation.h"

string DoubleLinkedListCreation::getListType() const
{
    return listType;
}

void DoubleLinkedListCreation::setListType(const string &value)
{
    listType = value;
}

DoubleLinkedListCreation::DoubleLinkedListCreation()
{
    
}

dlNode *DoubleLinkedListCreation::addToDll(dlNode *tail, int num)
{
    dlNode *newnode;
    createNewDN(&newnode);
    newnode->data = num;
    if(tail != nullptr)
    {
        newnode->previous = tail;
        tail->next = newnode;
    }
    tail = newnode;
    return tail;
}

void DoubleLinkedListCreation::createNewDN(dlNode **newnode)
{
    dlNode *temp = *newnode;
    temp = new dlNode;
    temp->next = nullptr;
    temp->previous = nullptr;
    *newnode = temp;
}
