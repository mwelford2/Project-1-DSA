//
// Created by Matteo Welford & Alexander Kolychkine on 2/13/25.
//

#include "AVLTree.h"
#include <iostream>
#include <ostream>
using namespace std;

AVLTree::AVLTree() { root = nullptr; }
AVLTree::~AVLTree() { deleteTree(root); }
void AVLTree::deleteTree(Student* S)
{
    if(S)
    {
        deleteTree(S->LEFT);
        deleteTree(S->RIGHT);
        delete S;
    }
}


bool AVLTree::insert(Student* S)
{

    return false;
}

bool AVLTree::removeID(int id)
{
    if (!searchID(id)) return false;
    removeIDHelper(root, id);
    return true;
} //POSSIBLE ERROR: putting both n and prev as root?
Student* AVLTree::removeIDHelper(Student* S, int ID)
{
    if (!S) return S; //base case

    if (ID > S->ID) S->RIGHT = removeIDHelper(S->RIGHT, ID);
    else if (ID < S->ID) S->LEFT = removeIDHelper(S->LEFT, ID);

    else
    {
        if (!S->LEFT)
        {
            Student* t = S->RIGHT;
            delete S;
            return t;
        }
        if (!S->RIGHT)
        {
            Student* t = S->LEFT;
            delete S;
            return t;
        }

        Student* succ = getSuccessor(S);
        S = succ;
        S->RIGHT = removeIDHelper(S->RIGHT, succ->ID);
    }
    return S;
}


//DONE
Student* AVLTree::searchID(int ID)
{
    Student* S = searchIDHelper(root, ID);
    if(S)
        cout << S->NAME << endl;
    else
        cout << "unsuccessful" << endl;

    return S;
}
//DONE (i think)
Student* AVLTree::searchIDHelper(Student* S, int ID)
{
    if(!S) return nullptr;
    if (ID == S->ID) return S;
    if (ID > S->ID)return searchIDHelper(S->RIGHT, ID);
    return searchIDHelper(S->LEFT, ID);
}

//NOT DONE.  the search name function is completely different than the ID function. we have to recode this lol
Student* AVLTree::searchName(std::string NAME)
{


    return searchNameHelper(root, NAME);

}
Student* AVLTree::searchNameHelper(Student* S, std::string NAME)
{
    if (!S) return nullptr;
    if (S->NAME == NAME) return S;

    Student* l = searchNameHelper(S->LEFT, NAME);
    Student* r = searchNameHelper(S->RIGHT, NAME);

    if (l) return l;
    return r;
}

