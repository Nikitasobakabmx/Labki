#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "DataBase.h"
#include "Person.h"
#include "except.h"

DataBase::DataBase(const Person &human)
{
    db.insert(std::pair<std::string, Person>(human.firstName, human));
}

void DataBase::load(const std::string &filename)
{
    rFile.open(filename);
    if(readFile.is_open())
        throw except((char*)"Can\'t open this file\n");
    std::istream_iterator<std::string> is(rFile);
    while(rFile)
    {
        Person tmp;
        tmp.firstName = *is;    ++is;
        tmp.firstName = *is;    ++is;
        tmp.sername = *is;      ++is;
        tmp.year = std::stoi(*is);  ++is;
        tmp.passportNumber = std::stoi(*is);    ++is;
        tmp.sex = *is;   ++is;
        db.insert(std::pair<std::string, Person>(tmp.firstName, tmp));
    //     Person *tmp = new Person;
    //     readFile >> tmp->firstName >> 
    //         tmp->sername >>
    //         tmp->year >>
    //         tmp->passportNumber >>
    //         tmp->sex;
    //     db.insert(std::pair<std::string, Person>(tmp->firstName, *tmp));
    }
}

void DataBase::save(const std::string &filename)
{
    wFile.open(filename);
    std::map<std::string, Person>::iterator a = db.begin(), b = db.end();
    std::ostream_iterator<std::string> oo (wFile);
    for(; a != b; ++a)
    {
        *oo = a->first + " ";
        *oo = a->second.getInfo();
        ++oo;
    }
}

void DataBase::erase(const Person &human)
{
    std::map<std::string, Person>::iterator it;
    it = db.find(human.firstName);
    db.erase(it);
}

void DataBase::add(const Person &human)
{
    db.insert(std::pair<std::string, Person>(human.firstName, human));
}
void DataBase::operator>(std::string key)
{
    std::ostream_iterator<std::string> oo (std::cout);
    *oo = db[key].getInfo();
    ++oo;
}