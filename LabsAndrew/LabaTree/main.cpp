#include <iostream>
#include <fstream>
#include <string>
#define COUNT 6
struct Date{
    int day;
    int manth;
    int year;
};

struct Student{
    std::string name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};
void ToString(std::string* src_str, Student students);
int main(){
    std::string data;
    std::string name;
    std::string path("C:\\Users\\Nikita\\Documents\\Coding\\C++\\Labs\\Self\\LabaThree\\");
    std::cout << "input name of file : ";
    std::cin >> name;
    path += name;
    ofstram file(path);
    std::cout << "File is open or create" << std::endl;
    std::cout << "Input list" << std::endl;
    Stud students[COUNT];
    for(int i = 0; i < COUNT; i++){
        std::cin >> students[i].name.name >> students[i].name.surname >>
            students[i].name.patronymic >> students[i].gendr >>
    	    students[i].finish >> students[i].adress >>
    	    students[i].grand >> students[i].date.day >>
    	    students[i].date.manth >> students[i].date.year;
        for(int k = 0; k<5;k++)
            std::cin >> students[i].marks[k];
        std::cin >> students[i].point;
    }
    std::cout << "Write to one str" << std::endl;
    for(int i = 0; i < COUNT; i++)
        ToString(&data, students[i]);
    std::cout << "Write to file " << std::endl;
    file >> data;
    std::cout << "Complete" << std::endl;
    file.close;
    system("pause");
    return 0;
}
void ToString(std::string* src_str, Student students){
    src_str += students.name.name;
    src_str += students.name.surname;
    src_str += students.name.patronymic;
    src_str += students.gendr;
    src_str += students.finish;
    src_str += students.adress;
    src_str += students.grand;
    src_str += std::to_string(students.date.day);
    src_str += std::to_string(students.date.manth);
    src_str += std::to_string(students.date.year);
    for(int i = 0; i < 5; i++)
        src_str += std::to_string(students.marks[i]);
    src_str += std::to_string(students.point);
}