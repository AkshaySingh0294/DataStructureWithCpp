#ifndef DUPLICATIONHANDLINGTREE_H
#define DUPLICATIONHANDLINGTREE_H

#include "DefinitionControl/Definitions/nodedefinition.h"
#include <iostream>

using namespace std;

class DuplicationHandlingTree
{
public:
    DuplicationHandlingTree();
    void createTree();
    void display(dTree *ptr, int level);
    void insert(dTree *newnode, dTree *currentNode);
    dTree *createNode(int key);
private:
    dTree *root;
};

#endif // DUPLICATIONHANDLINGTREE_H
