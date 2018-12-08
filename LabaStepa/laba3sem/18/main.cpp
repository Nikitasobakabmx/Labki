#include <iostream>
#include "Person.h"
#include "except.h"
#include "DataBase.h"
#include "Person.h"

int main()
{
    DataBase base;
    Person human;
    human.firstName = "Nikita";
    human.sername = "Khmelev";
    human.year = 19;
    human.passportNumber = 2138;
    human.sex = 'm';
    base.add(human);
    return 0;
}