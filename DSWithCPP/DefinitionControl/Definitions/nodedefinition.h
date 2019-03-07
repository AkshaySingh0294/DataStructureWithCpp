#ifndef NODEDEFINITION_H
#define NODEDEFINITION_H
struct dlNode{
    int data;
    dlNode *next;
    dlNode *previous;
};

struct node{
    int data;
    node *next;
};

struct tree{
    int info;
    tree *left;
    tree *right;
};

struct dTree{
    int key;
    int count;
    dTree *left, *right;
};

#endif // NODEDEFINITION_H
