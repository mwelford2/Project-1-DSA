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
    void deleteTree(Student* s);
    Student* searchIDHelper(Student* n, int id);
    Student* searchNameHelper(Student* n, std::string Name);
    Student* removeIDHelper(Student* n, int id);
    Student* getSuccessor(Student* cur){return cur;}
public:
    AVLTree();
    ~AVLTree();

    bool insert(Student* s);
    bool removeID(int id);
    Student* searchID(int id);
    Student* searchName(std::string name);

    std::vector<Student> inorder(){ return {Student(1, "jo")};}
    std::vector<Student> preorder();
    std::vector<Student> postorder();
    int height(){return 1;}
    bool isBalanced(){return false;} //impelemnt correcly later
    bool insert(int s, const char* str) {return false;} //for test assignment
    bool insert(const char* s, const char* str) {return false;} //for test assignment
};



#endif //AVLTREE_H
