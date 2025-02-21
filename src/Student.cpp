//
// Created by Matteo Welford on 2/13/25.
//

#include "Student.h"

Student::Student(int gatorID, std::string name) {
    this->ID = gatorID;
    this->name = name;
    this->left = nullptr;
    this->right = nullptr;
}

Student& Student::operator=(const Student& n)
{
    if (this != &n)
    {
        this->ID = n.ID;
        this->name = n.name;
    }
    return *this;
}

bool Student::operator==(int n)
{
    return ID==n;
}

bool Student::operator==(const Student& n) const
{
    return n.ID == this->ID;
}

bool Student::operator>(const Student& n) const
{
    return n.ID>this->ID;
}
bool Student::operator<(const Student& n) const
{
    return n.ID<this->ID;
}


