#include "basictreeoperation.h"

BasicTreeOperation::BasicTreeOperation()
{
    root = nullptr;
    createTree();
    display(root,1);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}

void BasicTreeOperation::createTree()
{
    int array[10] = {100,22,44,-1,88,5,204,90,299,9};
    for(int i : array)
    {
        tree *newnode = new tree;
        newnode->info = i;
        newnode->left = nullptr;
        newnode->right = nullptr;
        insert(root,newnode);
    }
}

void BasicTreeOperation::insert(tree *par, tree *newnode)
{
    if(root == nullptr)
    {
        root = newnode;
        return;
    }
    if(newnode->info == par->info)
        return;
    if(par->info > newnode->info)
    {
        if(par->left != nullptr)
        {
            insert(par->left,newnode);
        }
        else
        {
            par->left = newnode;
            return;
        }
    }
    else
    {
        if(par->right != nullptr)
        {
            insert(par->right,newnode);
        }
        else
        {
            par->right = newnode;
            return;
        }
    }
}

void BasicTreeOperation::display(tree *ptr, int level)
{
    int i;
    if (ptr != nullptr)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

void BasicTreeOperation::del(int item)
{
    tree *parent, *location;
    if(root ==  nullptr)
    {
        return;
    }
    find(item, &parent, &location);
    if(location == nullptr)
    {
        return;
    }
    if(location->left == nullptr && location->right == nullptr)
    {
        case_a(parent,location);
    }
    if(location->left == nullptr && location->right != nullptr)
    {
        case_b(parent,location);
    }
    if(location->left != nullptr && location->right == nullptr)
    {
        case_b(parent,location);
    }
    if(location->left != nullptr && location->right != nullptr)
    {
        case_c(parent,location);
    }
    delete location;
}

void BasicTreeOperation::find(int item, tree **par, tree **loc)
{
    tree *ptr, *ptrsave;
    if(root == nullptr)
    {
        *loc = nullptr;
        *par = nullptr;
        return;
    }
    if(item == root->info)
    {
        *loc = root;
        *par = nullptr;
        return;
    }
    if(item < root->info)
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
        if(item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if(item < ptr->info)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
        *loc = nullptr;
        *par = ptrsave;
    }
}

void BasicTreeOperation::case_a(tree *par, tree *loc)
{
    if(par == nullptr)
    {
        root = nullptr;
    }
    else
    {
        if(loc == par->left)
        {
            par->left = nullptr;
        }
        else
        {
            par->right = nullptr;
        }
    }

}

void BasicTreeOperation::case_b(tree *par, tree *loc)
{
    tree *child;
    if(loc->left != nullptr)
    {
        child = loc->left;
    }
    else
    {
        child = loc->right;
    }
    if(par == nullptr)
    {
        root = child;
    }
    else
    {
        if(loc == par->left)
        {
            par->left = child;
        }
        else
        {
            par->right = child;
        }
    }
}

void BasicTreeOperation::case_c(tree *par, tree *loc)
{
    tree *ptr, *ptrsave, *suc, *parsuc;
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
        case_a(parsuc,suc);
    }
    else
    {
        case_b(parsuc,suc);
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
}

void BasicTreeOperation::preorder(tree *ptr)
{
    if(root == nullptr)
        return;
    if(ptr != nullptr)
    {
        cout<<ptr->info<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BasicTreeOperation::inorder(tree *ptr)
{
    if(root == nullptr)
        return;
    if(ptr != nullptr)
    {
        preorder(ptr->left);
        cout<<ptr->info<<" ";
        preorder(ptr->right);
    }
}

void BasicTreeOperation::postorder(tree *ptr)
{
    if(root == nullptr)
        return;
    if(ptr != nullptr)
    {
        preorder(ptr->left);
        preorder(ptr->right);
        cout<<ptr->info<<" ";
    }
}
