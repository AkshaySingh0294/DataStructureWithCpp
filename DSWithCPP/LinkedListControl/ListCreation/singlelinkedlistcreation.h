#ifndef SINGLELINKEDLISTCREATION_H
#define SINGLELINKEDLISTCREATION_H
#include <string>
#include <iostream>
#include "DefinitionControl/Definitions/nodedefinition.h"
using namespace std;

class SingleLinkedListCreation
{
private:
     string listType = "SingleLinkedList";
public:
    SingleLinkedListCreation();
    node *addToSll(node *tail,int num);
    void createNewSN(node **newnode);

    string getListType() const;
    void setListType(const string &value);
};

#endif // SINGLELINKEDLISTCREATION_H
