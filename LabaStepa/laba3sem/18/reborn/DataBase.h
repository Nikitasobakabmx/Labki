#pragma once
#include "Person.h"
#include <string>
#include <ostream>
#include <map>
class DataBase
{
    private:
        std::map<std::string, Person> dB;
    public:
        DataBase();
        DataBase(const std::string& fileName);
        DataBase(const Person& item);
        void load(const std::string& fileName);
        void save(const std::string& fileName);
        friend std::ostream& operator<< (std::ostream& os, const DataBase& list);
        Person operator[] (std::string key);
        void add(const Person& item);
        void erase(const Person& item);
        void erase(const std::string& key);
        ~DataBase();

};

