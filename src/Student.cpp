//
// Created by Matteo Welford & Alexander Kolychkine on 2/13/25.
//

#include "Student.h"

Student::Student(int gatorID, std::string name) {
    this->ID = gatorID;
    this->NAME = name;
    this->LEFT = nullptr;
    this->RIGHT = nullptr;
}

Student& Student::operator=(const Student& S)
{
    if (this != &S)
    {
        this->ID = S.ID;
        this->NAME = S.NAME;
    }
    return *this;
}


