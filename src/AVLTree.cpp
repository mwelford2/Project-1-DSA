//
// Created by Matteo Welford on 2/13/25.
//

#include "AVLTree.h"

AVLTree::AVLTree() { root = nullptr; }
AVLTree::~AVLTree() { deleteTree(root); }
void AVLTree::deleteTree(Student* s)
{
    if (s)
    {
        deleteTree(s->left);
        deleteTree(s->right);
        delete s;
    }
}


bool AVLTree::insert(Student* s)
{
    return false;
}

bool AVLTree::removeID(int id)
{
    if (!searchID(id)) return false;
    removeIDHelper(root, id);
    return true;
} //POSSIBLE ERROR: putting both n and prev as root?
Student* AVLTree::removeIDHelper(Student* n, int id)
{
    if (!n) return n; //base case

    if (id > n->ID) n->right = removeIDHelper(n->right, id);
    else if (id < n->ID) n->left = removeIDHelper(n->left, id);

    else
    {
        if (!n->left)
        {
            Student* t = n->right;
            delete n;
            return t;
        }
        if (!n->right)
        {
            Student* t = n->left;
            delete n;
            return t;
        }

        Student* succ = getSuccessor(n);
        n = succ;
        n->right = removeIDHelper(n->right, succ->ID);
    }
    return n;
}



Student* AVLTree::searchID(int id){ return searchIDHelper(root, id); }
Student* AVLTree::searchIDHelper(Student* n, int id)
{
    if(!n) return nullptr;
    if (id == n->ID) return n;
    if (id>n->ID) return searchIDHelper(n->right, id);
    return searchIDHelper(n->left, id);
}

Student* AVLTree::searchName(std::string name) { return searchNameHelper(root, name); }
Student* AVLTree::searchNameHelper(Student* n, std::string Name)
{
    if (!n) return nullptr;
    if (n->name == Name) return n;

    Student* l = searchNameHelper(n->left, Name);
    Student* r = searchNameHelper(n->right, Name);

    if (l) return l;
    return r;
} //O(n), can make more efficient?

