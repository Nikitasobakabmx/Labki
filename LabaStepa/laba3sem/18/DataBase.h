#pragma once
#include "Person.h"
#include <ostream>
#include <fstream>
#include <map>
class DataBase
{
private:
    std::map<std::string, Person> db;
    std::ifstream rFile;
    std::ofstream wFile;
public:
    DataBase(){};
    DataBase(const Person &human);
    void load(const std::string &filename);
    void save(const std::string &filename);
    void operator>(std::string key);
    void add(const Person &human);
    void erase(const Person &human);
    ~DataBase(){};
};