//
// Created by Matteo Welford & Alexander Kolychkine on 2/13/25.
//

#include "AVLTree.h"
#include <iostream>
#include <ostream>
#include <vector>
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

bool AVLTree::removeID(int ID)
{
    if (!searchID(ID)) return false;
    removeIDHelper(root, ID);
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

//i coded these two functions but idk why i did it lol. it doesnt look like we need them. LMFAO
int AVLTree::height()
{
    return findHeight(root);
}
int AVLTree::findHeight(Student* S)
{
    int leftHeight, rightHeight = 1;
    Student* l = root->LEFT;
    Student* r = root->RIGHT;

    if(l != nullptr)
        leftHeight += findHeight(l);
    if(r != nullptr)
        rightHeight += findHeight(r);

    //return whichever height is greater
    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

//this should work, i think?
void AVLTree::traverseInOrder(Student* S = root)
{
    Student* l = S->LEFT;
    Student* r = S->RIGHT;
    if(l != nullptr)
        traverseInOrder(l);
    if(r != nullptr)
        traverseInOrder(r);
    cout << S->NAME << endl;
    inOrder.push_back(S);
}

void AVLTree::printInOrder()
{
    traverseInOrder();
    for(int i = 0; i < inOrder.size()-1; i++)
        cout << inOrder[i]->NAME << ", ";
    cout << inOrder[inOrder.size()-1]->NAME << endl;
}