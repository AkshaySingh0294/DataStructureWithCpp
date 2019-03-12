#include "duplicationhandlingtree.h"

DuplicationHandlingTree::DuplicationHandlingTree()
{
    root = nullptr;
    createTree();
    display(root,1);
    cout<<endl<<endl<<endl<<endl;
    deleteNode(36);
    display(root,1);
    cout<<endl<<endl<<endl<<endl;
    deleteNode(36);
    display(root,1);
    cout<<endl<<endl<<endl<<endl;
    deleteNode(36);
    display(root,1);
    cout<<endl<<endl<<endl<<endl;

}

void DuplicationHandlingTree::createTree()
{
    int array[10] = {25,10,15,36,10,15,36,10,42,24};
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
    return newnode;
}

void DuplicationHandlingTree::deleteNode(int key)
{
    if(root == nullptr)
        return;
    dTree *location, *parent;
    location = parent = nullptr;
    find(&location, &parent, key);
    if(location == nullptr)
        return;
    if(location->left == nullptr && location->right == nullptr)
    {
        case_a(&location, &parent, "");
    }
    if(location->left ==  nullptr && location->right != nullptr)
    {
        case_b(&location, &parent, "");
    }
    if(location->left != nullptr && location->right == nullptr)
    {
        case_b(&location, &parent, "");
    }
    if(location->left != nullptr && location->right != nullptr)
    {
        case_c(&location, &parent);
    }

}

void DuplicationHandlingTree::case_a(dTree **location, dTree **parent, string type)
{
    if(location == nullptr)
        return;
    dTree *par = *parent;
    dTree *loc = *location;

    if(type != "type-c")
    {
        if(loc->count > 1)
        {
            --loc->count;
            return;
        }
    }

    if(par->left ==  loc)
    {
        par->left = nullptr;
    }
    else
    {
        par->right = nullptr;
    }
    if(type != "type-c")
    {
        delete loc;
        return;
    }
}

void DuplicationHandlingTree::case_b(dTree **location, dTree **parent, string type)
{
    if(*location == nullptr)
        return;
    dTree *loc, *par, *child;
    loc = *location;
    par = *parent;
    if(type != "type-c")
    {
        if(loc->count > 1)
        {
            --loc->count;
            return;
        }
    }
    child = loc->left == nullptr ? loc->right : loc->left;
    if(par == nullptr)
        root = child;
    else
    {
        if(par->left == loc)
            par->left = child;
        else
            par->right = child;
    }
    if(type != "type-c")
    {
        delete *location;
        return;
    }
}

void DuplicationHandlingTree::case_c(dTree **location, dTree **parent)
{
    if(*location == nullptr)
        return;
    dTree *loc, *par, *ptr, *ptrsave, *suc, *parsuc;
    loc = *location;
    par = *parent;
    if(loc->count > 1)
    {
        --loc->count;
        return;
    }
    ptrsave = loc;
    ptr = loc->right;
    while(ptr->left != nullptr)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }

    suc = ptr;
    parsuc = ptrsave;

    if(suc->left == nullptr && suc->right == nullptr)
    {
        case_a(&suc, &parsuc, "type-c");
    }
    else
    {
        case_b(&suc, &parsuc, "type-c");
    }
    if(par == nullptr)
    {
        root = suc;
    }
    else
    {
        if(loc == par->left)
        {
            par->left = suc;
        }
        else
        {
            par->right = suc;
        }
    }
    suc->left = loc->left;
    suc->right = loc->right;

    delete *location;
}

void DuplicationHandlingTree::find(dTree **location, dTree **parent, int key)
{
    if(root == nullptr)
        return;
    if(root->key == key){
        *location = root;
        return;
    }
    dTree *ptr, *ptrsave;
    if(key < root->key)
    {
        ptr = root->left;
    }
    else
    {
        ptr = root->right;
    }
    ptrsave = root;
    while(ptr != nullptr)
    {
        if(key == ptr->key)
        {
            *location = ptr;
            *parent = ptrsave;
            return;
        }
        ptrsave = ptr;
        if(key < ptr->key)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
        *location = nullptr;
        *parent = ptrsave;
    }
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
