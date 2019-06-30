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
    void deleteNode(int key);
    void find(dTree **location, dTree **parent, int key);
    void case_a(dTree **location, dTree **parent, string type);
    void case_b(dTree **location, dTree **parent, string type);
    void case_c(dTree **location, dTree **parent);
private:
    dTree *root;
};

#endif // DUPLICATIONHANDLINGTREE_H
