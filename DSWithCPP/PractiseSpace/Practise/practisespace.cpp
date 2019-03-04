//#include "practisespace.h"

//PractiseSpace::PractiseSpace()
//{
//    root = nullptr;
//    createTree();
//    display(root,1);
//    cout<<endl;
//    preorder(root);
//    cout<<endl;
//    inorder(root);
//    cout<<endl;
//    postorder(root);
//    cout<<endl;
//}

//void PractiseSpace::createTree()
//{
//    int array[10] = {27,32,44,88,99,127,0,1,55,77};
//    for(int i : array)
//    {
//        tree *newnode = new tree;
//        newnode->info = i;
//        insert(root,newnode);
//    }
//}

//void PractiseSpace::find(int item, tree **par, tree **loc)
//{
//    tree *ptr, *ptrsave;
//    if(root == nullptr)
//    {
//        *loc = nullptr;
//        *par = nullptr;
//        return;
//    }
//    if(item == root->info)
//    {
//        *loc = root;
//        *par = nullptr;
//        return;
//    }
//    if(item < root->info)
//    {
//        ptr = root->left;
//    }
//    else
//    {
//        ptr = root->right;
//    }
//    ptrsave = root;
//    while(ptr != nullptr)
//    {
//        if(item == ptr->info)
//        {
//            *loc = ptr;
//            *par = ptrsave;
//            return;
//        }
//        ptrsave = ptr;
//        if(item < ptr->info)
//        {
//            ptr = ptr->left;
//        }
//        else
//        {
//            ptr = ptr->right;
//        }
//        *loc = nullptr;
//        *par = ptrsave;
//    }
//}

//void PractiseSpace::insert(tree *head, tree *newnode)
//{
//    if(root == nullptr)
//    {
//        root = new tree;
//        root->info = newnode->info;
//        root->left = nullptr;
//        root->right = nullptr;
//        return;
//    }
//    if(head->info == newnode->info)
//    {
//        cout<<"Skipping already added element = "<<newnode->info;
//        return;
//    }
//    if(head->info > newnode->info)
//    {
//        if(head->left != nullptr)
//        {
//            insert(head->left,newnode);
//        }
//        else
//        {
//            head->left = newnode;
//            head->left->left = nullptr;
//            head->left->right = nullptr;
//            return;
//        }
//    }
//    else
//    {
//        if(head->right != nullptr)
//        {
//            insert(head->right,newnode);
//        }
//        else
//        {
//            head->right = newnode;
//            head->right->left = nullptr;
//            head->right->right = nullptr;
//            return;
//        }
//    }
//}

//void PractiseSpace::del(int item)
//{
//    tree *parent, *location;
//    if(root == nullptr)
//    {
//        return;
//    }
//    find(item, &parent, &location);
//    if(location == nullptr)
//        return;
//    if(location->left == nullptr && location->right == nullptr)
//    {
//        case_a(parent,location);
//    }
//    if(location->left == nullptr && location->right != nullptr)
//    {
//        case_b(parent,location);
//    }
//    if(location->left != nullptr && location->right == nullptr)
//    {
//        case_b(parent,location);
//    }
//    free(location);
//}

//void PractiseSpace::case_a(tree *par, tree *loc)
//{
//    if(par == nullptr)
//    {
//        root = nullptr;
//    }
//    else
//    {
//        if(loc == par->left)
//            par->left = nullptr;
//        else
//            par->right = nullptr;
//    }
//}

//void PractiseSpace::case_b(tree *par, tree *loc)
//{
//    tree *child;
//    if(loc->left != nullptr)
//    {
//        child = loc->left;
//    }
//    else
//    {
//        child = loc->right;
//    }
//    if(par == nullptr)
//    {
//        root = child;
//    }
//    else
//    {
//        if(loc == par->left)
//        {
//            par->left = child;
//        }
//        else
//        {
//            par->right = child;
//        }
//    }
//}

//void PractiseSpace::case_c(tree *par, tree *loc)
//{
//    tree *ptr, *ptrsave, *suc, *parsuc;
//    ptrsave = loc;
//    ptr = loc->right;
//    while(ptr->left != nullptr)
//    {
//        ptrsave = ptr;
//        ptr = ptr->left;
//    }
//    suc = ptr;
//    parsuc = ptrsave;
//    if(suc->left == nullptr && suc->right == nullptr)
//    {
//        case_a(parsuc,suc);
//    }
//    else
//    {
//        case_b(parsuc,suc);
//    }
//    if(par == nullptr)
//    {
//        root = suc;
//    }
//    else
//    {
//        if(loc == par->left)
//        {
//            par->left = suc;
//        }
//        else
//        {
//            par->right = suc;
//        }
//    }
//    suc->left = loc->right;
//    suc->right = loc->right;
//}

//void PractiseSpace::preorder(tree *ptr)
//{
//    if(root == nullptr)
//    {
//        return;
//    }
//    if(ptr != nullptr)
//    {
//        cout<<ptr->info<<" ";
//        preorder(ptr->left);
//        preorder(ptr->right);
//    }
//}

//void PractiseSpace::inorder(tree *ptr)
//{
//    if(root == nullptr)
//    {
//        return;
//    }
//    if(ptr != nullptr)
//    {
//        inorder(ptr->left);
//        cout<<ptr->info<<" ";
//        inorder(ptr->right);
//    }
//}

//void PractiseSpace::postorder(tree *ptr)
//{
//    if(root == nullptr)
//    {
//        return;
//    }
//    if(ptr != nullptr)
//    {
//        postorder(ptr->left);
//        postorder(ptr->right);
//        cout<<ptr->info<<" ";
//    }
//}

//void PractiseSpace::display(tree *ptr, int level)
//{
//    int i;
//    if (ptr != nullptr)
//    {
//        display(ptr->right, level+1);
//        cout<<endl;
//        if (ptr == root)
//            cout<<"Root->:  ";
//        else
//        {
//            for (i = 0;i < level;i++)
//                cout<<"       ";
//        }
//        cout<<ptr->info;
//        display(ptr->left, level+1);
//    }
//}
