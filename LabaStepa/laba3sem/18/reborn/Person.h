#include <string>
#include <ostream>
#include <istream>
class Person
{
    public:
        std::string name;
        std::string surname;
        int year;
        std::string sex;
        int passNumber;
        Person();
        friend std::ostream& operator<< (std::ostream& os, const Person& item);
        friend std::istream& operator>> (std::istream& os, Person& item);
        bool operator!= (const Person item);
        ~Person();
};

