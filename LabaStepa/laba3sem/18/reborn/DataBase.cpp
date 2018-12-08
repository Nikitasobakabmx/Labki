// #pragma once
#include "DataBase.h"
#include "except.h"
#include <string>
#include <ostream>
#include <map>
#include <fstream>
DataBase::DataBase(){}

DataBase::DataBase(const std::string& fileName)
{
    this->load(fileName);
}

DataBase::DataBase(const Person& item)
{
    this->add(item);
}

void DataBase::load(const std::string& fileName)
{
    dB.clear();
    std::ifstream file(fileName);
    if(!file.is_open())
        throw except((char*)"Can\'t open this file\n");
    char *tmp;
    while(file >> tmp)
    {
        Person item;
        file >> item;
        this->add(item);
    }    
}

void DataBase::save(const std::string& fileName)
{
    std::ofstream file(fileName);
    if(!file.is_open())
        throw except((char*)"Can\'t open this file\n");
    std::map<std::string, Person>::iterator it;
    for(it = dB.begin(); it != dB.end(); ++it)
    {
        file << it->first << "\n" << it->second << "\n";
    }
    file.close();
}

std::ostream& operator<< (std::ostream& os, const DataBase& list)
{
    //std::map<std::string, Person>::iterator it;
    for(auto it = list.dB.begin(); it != list.dB.end(); ++it)
    {
        os << it->first << "\n" << it->second << "\n";
    }
    return os;
}

Person DataBase::operator[](std::string key)
{
    return dB.find(key)->second;
}

void DataBase::add(const Person& item)
{
    dB.insert(std::pair<std::string, Person>(item.name, item));
}

void DataBase::erase(const Person& item)
{
    std::map<std::string, Person>::iterator it;
    for(it = dB.begin(); ((it->second != item)&&(it != dB.end())); ++it);
    if((it == dB.end())&&(it->second != item))
        throw except((char*)"Can\'t erase null element\n");
    dB.erase(it);
}

void DataBase::erase(const std::string& key)
{
    dB.erase(key);
}

DataBase::~DataBase(){}