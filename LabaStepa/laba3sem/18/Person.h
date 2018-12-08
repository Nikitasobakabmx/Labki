#pragma once
#include <string>
class Person
{
public:
    Person(){};
    std::string firstName;
    std::string sername;
    unsigned int year;
    unsigned int passportNumber;
    char sex; 
    Person(std::string firstName,
    std::string sername,
    unsigned int year,
    char sex,
    unsigned int passportNumber);
    bool operator==(Person human); 
    std::string getInfo();
    ~Person(){};
};
