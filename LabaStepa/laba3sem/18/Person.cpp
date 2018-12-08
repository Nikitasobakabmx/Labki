#pragma once
#include <string>
Person::Person(std::string firstName,
    std::string sername,
    unsigned int year,
    char sex,
    unsigned int passportNumber)
{
    this->firstName = firstName;
    this->sername = sername;
    this->year = year;
    this->passportNumber = passportNumber;
    this->sex = sex;
}

bool Person::operator==(Person human)
{
    return ((firstName == human.firstName) &&
            (sername == human.sername) &&
            (year == human.year) &&
            (passportNumber == human.passportNumber) &&
            (sex == human.sex));
}

std::string Person::getInfo()
{
    return firstName + sername + 
        std::to_string(year) + 
        std::to_string(passportNumber) + 
        std::to_string(sex);
}
Person::~Person()
{}
