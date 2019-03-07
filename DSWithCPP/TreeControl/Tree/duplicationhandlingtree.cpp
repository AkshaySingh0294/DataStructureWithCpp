#include "duplicationhandlingtree.h"

DuplicationHandlingTree::DuplicationHandlingTree()
{
    root = nullptr;
    createTree();
    display(root,1);
    cout<<endl;
}

void DuplicationHandlingTree::createTree()
{
    int array[10] = {25,10,15,36,10,15,36,10,15,42};
    for(int i : array)
    {
        dTree *newnode = createNode(i);
        insert(newnode,root);
    }
}

void DuplicationHandlingTree::insert(dTree *newnode,dTree *currentNode)
{;
    if(root == nullptr) {
        root = newnode;
        ++(root->count);
        return;
    }
    if(currentNode->key == newnode->key){
        ++currentNode->count;
        return;
    }
    if(newnode->key < currentNode->key) {
        if(currentNode->left == nullptr) {
            currentNode->left = newnode;
            return;
        }
        else {
            insert(newnode,currentNode->left);
        }
    }
    else {
        if(currentNode->right == nullptr) {
            currentNode->right = newnode;
            return;
        }
        else {
            insert(newnode,currentNode->right);
        }
    }
}

dTree *DuplicationHandlingTree::createNode(int key)
{
    dTree *newnode = new dTree;
    newnode->key = key;
    newnode->left = newnode->right = nullptr;
    newnode->count = 1;
}

void DuplicationHandlingTree::display(dTree *ptr, int level)
{
    int i;
    if (ptr != nullptr) {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->key<<"("<<ptr->count<<")";
        display(ptr->left, level+1);
    }
}
