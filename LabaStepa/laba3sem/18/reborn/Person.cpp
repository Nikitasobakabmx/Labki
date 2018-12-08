// #pragma once
#include "Person.h"
#include <string>
#include <ostream>
#include <istream>
Person::Person()
{

}

std::ostream& operator<< (std::ostream& os, const Person& item)
{
    os << "\t" << item.name << "\n\t" << item.surname << "\n\t" << item.year << "\n\t" <<
        item.sex << "\n\t" << item.passNumber << "\n";
    return os;
}

std::istream& operator>> (std::istream& os, Person& item)
{
    os >> item.name;
    os >> item.surname;
    os >> item.year;
    os >> item.sex;
    os >> item.passNumber ;
    return os;
}

bool Person::operator!= (const Person item)
{
    return ((this->name != item.name)&&
                (this->surname != item.surname)&&
                (this->year != item.year)&&
                (this->sex != item.sex)&&
                (this->passNumber != item.passNumber));
}

Person::~Person()
{
    
}