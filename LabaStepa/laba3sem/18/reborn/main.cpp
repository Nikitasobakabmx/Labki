#include <iostream>
#include "DataBase.h"

int main()
{
    DataBase base;
    Person man;
    man.name = "Stepan";
    man.surname = "Bogachev";
    man.year = 1999;
    man.sex = "male";
    man.passNumber = 72300;
    base.add(man);
    DataBase baseTwo(man);
    std::cout << base;
    base.erase(man);
    std::cout << base;
    baseTwo.save("Db.txt");
    base.load("Db.txt");
    std::cout << baseTwo;
    std::cout << base;
    return 0;
}