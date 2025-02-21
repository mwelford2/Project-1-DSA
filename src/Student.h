//
// Created by Matteo Welford & Alexander Kolychkine on 2/13/25.
//

#ifndef NODE_H
#define NODE_H
#include <string>


class Student {
public:
    Student* LEFT;
    Student* RIGHT;

    std::string NAME;
    int ID;

    Student(int gatorID, std::string name);
    Student& operator=(const Student& S);
};



#endif //NODE_H
