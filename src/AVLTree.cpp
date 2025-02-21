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
    Student* S = searchIDHelper(root, ID);
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

///still need to check if the names are good (make the nameIsOK() function)
void AVLTree::insert(string Name, int ID)
{
    //makes sure this is a unique ID
    if(!search(ID))
    {
        cout << "unsuccessful" << endl;
        return;
    }

    //makes sure the name follows the constraints
    if(!nameIsOK())
    {
        cout << "unsuccessful" << endl;
        return;
    }

    Student* S = new Student(ID, Name);
    Student* parent = findNodeToInsertUnder(root, S->ID);
    if (parent == nullptr) root = S; //in case the tree is empty

    //insert the child node
    if(S->ID > parent->ID)
        parent->RIGHT = S;
    else
        parent->LEFT = S;

    //now we have to balance this thang lol
    //the only situation you need to find the ancestor is if the height from the root is > 3
    if(findHeight(parent) > 2 && findHeight(root) > 3)
        balanceTheTree(S, findAncestor(root, S->ID));

    cout << "successful" << endl;
}

//DONE (i think)
Student* AVLTree::findAncestor(Student* S, int ID)
{
    Student* l = S->LEFT;
    Student* r = S->RIGHT;
    if(l && l->ID == ID) return S;
    if(r && r->ID == ID) return S;
    if(l && ID < S->ID) return findAncestor(l, ID);
    if(r && ID > S->ID) return findAncestor(r, ID);
    return nullptr;
}

//DONE (i think)
void AVLTree::balanceTheTree(Student* theCulprit, Student* ancestor = nullptr)
{
    //determine the case
    bool RR, LL, LR, RL = false;
    Student* l = theCulprit->LEFT;
    Student* r = theCulprit->RIGHT;
    if(l)
    {
        Student* ll = l->LEFT;
        Student* lr = l->RIGHT;
        if(ll)
            LL = true;
        if(lr)
            LR = true;
    }
    if(r)
    {
        Student* rl = r->LEFT;
        Student* rr = r->RIGHT;
        if(rl)
            RL = true;
        if(rr)
            RR = true;
    }

    //left left case
    if(LL)
    {
        Student* topNode = theCulprit;
        Student* midNode = theCulprit->LEFT;
        topNode->LEFT = nullptr;
        midNode->LEFT = topNode;
        if(ancestor)
            if(midNode->ID < ancestor->ID)
                ancestor->LEFT = midNode;
            else
                ancestor->RIGHT = midNode;
        if(findHeight()==2) root = midNode;
    }

    if(RR)
    {
        Student* topNode = theCulprit;
        Student* midNode = theCulprit->RIGHT;
        topNode->RIGHT = nullptr;
        midNode->RIGHT = topNode;
        if(ancestor)
            if(midNode->ID < ancestor->ID)
                ancestor->LEFT = midNode;
            else
                ancestor->RIGHT = midNode;
        if(findHeight()==2) root = midNode;
    }

    if(LR)
    {
        Student* topNode = theCulprit;
        Student* midNode = theCulprit->LEFT;
        Student* botNode = theCulprit->LEFT->RIGHT;

        topNode->LEFT = nullptr;
        topNode->RIGHT = nullptr;
        midNode->RIGHT = nullptr;
        botNode->LEFT = midNode;
        botNode->RIGHT = topNode;

        if(ancestor)
            if(midNode->ID < ancestor->ID)
                ancestor->LEFT = midNode;
            else
                ancestor->RIGHT = midNode;
        if(findHeight()==2) root = midNode;
    }

    if(RL)
    {
        Student* topNode = theCulprit;
        Student* midNode = theCulprit->RIGHT;
        Student* botNode = theCulprit->RIGHT->LEFT;

        topNode->LEFT = nullptr;
        topNode->RIGHT = nullptr;
        midNode->LEFT = nullptr;
        botNode->LEFT = topNode;
        botNode->RIGHT = midNode;

        if(ancestor)
            if(midNode->ID < ancestor->ID)
                ancestor->LEFT = midNode;
            else
                ancestor->RIGHT = midNode;
        if(findHeight()==2) root = midNode;
    }
}

//DONE (i think)
Student* AVLTree::findNodeToInsertUnder(Student* S, int ID)
{
    if (!S) return nullptr;
    Student* l = S->LEFT;
    Student* r = S->RIGHT;
    if(l && l->ID > ID)
        return findNodeToInsertUnder(l, ID);
    if(r && r->ID < ID)
        return findNodeToInsertUnder(r, ID);
    return S;
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
void AVLTree::printLevelCount()
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