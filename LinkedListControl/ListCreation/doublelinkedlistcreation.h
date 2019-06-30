#ifndef DOUBLELINKEDLISTCREATION_H
#define DOUBLELINKEDLISTCREATION_H
#include "DefinitionControl/Definitions/nodedefinition.h"
#include <iostream>
using namespace std;
class DoubleLinkedListCreation
{
private:
    string listType = "DoublyLinkedList";
public:
    DoubleLinkedListCreation();
    dlNode *addToDll(dlNode *tail, int num);
    void createNewDN(dlNode **newnode);

    string getListType() const;
    void setListType(const string &value);
};

#endif // DOUBLELINKEDLISTCREATION_H
