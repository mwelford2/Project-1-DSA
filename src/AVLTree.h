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
    Student* searchNameHelper(Student* n, std::string Name);
    Student* removeIDHelper(Student* n, int id);
    Student* getSuccessor(Student* cur){return cur;}
public:
    AVLTree();
    ~AVLTree();

    void insert(Student* S);
    Student* findNodeToInsertUnder(Student* S, int ID);
    Student* findAncestor(Student* S, int ID);
    void balanceTheTree(Student* theCulprit, Student* ancestor);
    bool remove(int ID);
    Student* search(int ID);
    Student* search(std::string NAME);

    std::vector<Student*> inOrder;
    std::vector<Student*> preOrder;
    std::vector<Student*> postOrder;
    int findHeight(Student* S);

    void printLevelCount();
    void traverseInOrder(Student* S);
    void printInOrder();
    void traversePreOrder(Student* S);
    void printPreOrder();
    void traversePostOrder(Student* S);
    void printPostOrder();

};



#endif //AVLTREE_H
