//
// Created by Matteo Welford & Alexander Kolychkine on 2/13/25.
//

#ifndef NODE_H
#define NODE_H
#include <string>


class Student {
public:
    Student* left;
    Student* right;

    std::string name;
    int ID;

    Student(int gatorID, std::string name);
    Student& operator=(const Student& n);
    bool operator==(int n);
    bool operator==(const Student& n) const;
    bool operator<(const Student& n) const;
    bool operator>(const Student& n) const;
};



#endif //NODE_H
