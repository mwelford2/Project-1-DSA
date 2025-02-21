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

bool AVLTree::remove(int ID)
{
    if (!search(ID)) return false;
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
Student* AVLTree::search(int ID)
{
    Student* S = searchNameHelper(root, ID);
    if(S == nullptr)
        cout << "unsuccessful" << endl;
    else
        cout << S->NAME << endl;
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
Student* AVLTree::search(std::string NAME)
{

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

//this can also be used to when we are trying to balance the tree. we'll see...
//DONE (i think)
int AVLTree::findHeight(Student* S = root)
{
    if(S == nullptr) return 0; //only returns 0 when the root is nullptr

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

//DONE
void printLevelCount()
{
    cout << findHeight() << endl;
}

//CLEAR INORDER LIST BEFORE CALLING THIS
//DONE (i think)
void AVLTree::traverseInOrder(Student* S = root)
{
    Student* l = S->LEFT;
    Student* r = S->RIGHT;
    if(l != nullptr)
        traverseInOrder(l);
    inOrder.push_back(S);
    if(r != nullptr)
        traverseInOrder(r);
}

//DONE (i think)
void AVLTree::printInOrder()
{
    inOrder.clear();
    traverseInOrder();
    for(int i = 0; i < inOrder.size()-1; i++)
        cout << inOrder[i]->NAME << ", ";
    cout << inOrder[inOrder.size()-1]->NAME << endl;
}

//CLEAR PREORDER LIST BEFORE CALLING THIS
//DONE (i think)
void AVLTree::traversePreOrder(Student* S = root)
{
    preOrder.push_back(S);
    Student* l = S->LEFT;
    Student* r = S->RIGHT;
    if(l != nullptr)
        traversePreOrder(l);
    if(r != nullptr)
        traversePreOrder(r);
}

//DONE (i think)
void AVLTree::printPreOrder()
{
    preOrder.clear();
    traversePreOrder();
    for(int i = 0; i < preOrder.size()-1; i++)
        cout << preOrder[i]->NAME << ", ";
    cout << preOrder[preOrder.size()-1]->NAME << endl;
}

//CLEAR POSTORDER LIST BEFORE CALLING THIS
//DONE (i think)
void AVLTree::traversePostOrder(Student* S = root)
{
    Student* l = S->LEFT;
    Student* r = S->RIGHT;
    if(l != nullptr)
        traversePostOrder(l);
    if(r != nullptr)
        traversePostOrder(r);
    postOrder.push_back(S);
}

//DONE (i think)
void AVLTree::printPostOrder()
{
    postOrder.clear();
    traversePostOrder();
    for(int i = 0; i < postOrder.size()-1; i++)
        cout << postOrder[i]->NAME << ", ";
    cout << postOrder[postOrder.size()-1]->NAME << endl;
}

//DONE (i think)
void AVLTree::removeInorder(int N)
{
    //fyi, N is the index of the student that we have to remove in the inorder traversal
    traverseInOrder();
    if(N > inOrder.size() || N < 0)
        cout << "unsuccessful" << endl;

    Student* S = inOrder[N];
    remove(S->ID);
    cout << "successful" << endl;
}