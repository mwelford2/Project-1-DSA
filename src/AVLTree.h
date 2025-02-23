//
// Created by Matteo Welford & Alexander Kolychkine on 2/13/25.
//

#ifndef AVLTREE_H
#define AVLTREE_H
#include <vector>

#include "Student.h"

//Generic layout, may be changed if needed

class AVLTree {
    Student* root;
    void deleteTree(Student* S);
    Student* searchIDHelper(Student* n, int id);
    void searchNameHelper(Student* n, std::string Name);
    Student* removeIDHelper(Student* n, int id);
    Student* getSuccessor(Student* cur);
    Student* findNodeToInsertUnder(Student* S, int ID);
    Student* findAncestor(Student* S, int ID);
    bool nameIsOK(std::string& Name);
    void balanceTheTree(Student* theCulprit, Student* ancestor);
    void traverseInOrder(Student* S);
    void traversePreOrder(Student* S);
    void traversePostOrder(Student* S);
    int findHeight(Student* S);

public:
    AVLTree();
    ~AVLTree();

    void insert(std::string Name, int ID);
    bool remove(int ID);
    bool removeInOrder(int n);
    Student* search(int ID);
    void search(std::string NAME);

    std::vector<Student*> inOrder;
    std::vector<Student*> preOrder;
    std::vector<Student*> postOrder;

    void printLevelCount();
    void printInOrder();
    void printPreOrder();
    void printPostOrder();

};



#endif //AVLTREE_H
