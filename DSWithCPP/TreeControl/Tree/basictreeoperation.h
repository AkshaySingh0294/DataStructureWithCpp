#ifndef BASICTREEOPERATION_H
#define BASICTREEOPERATION_H
#include "DefinitionControl/Definitions/nodedefinition.h"
#include <iostream>
using namespace std;

class BasicTreeOperation
{
public:
    BasicTreeOperation();
    void createTree();
    void insert(tree *par, tree *newnode);
    void display(tree *ptr, int level);
    void del(int item);
    void find(int item, tree **par, tree **loc);
    void case_a(tree *par, tree*loc);
    void case_b(tree *par, tree*loc);
    void case_c(tree *par, tree*loc);
    void preorder(tree *ptr);
    void inorder(tree *ptr);
    void postorder(tree *ptr);

private:
    tree *root;
};

#endif // BASICTREEOPERATION_H
