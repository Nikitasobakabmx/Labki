#include <iostream>
#include <string>
#include <conio.h>
#define COUNT 6
struct Date{
    int day;
    int manth;
    int year;
};
struct Stud{
    std::string name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};
void Show(Stud students);
void Sort(Stud students[COUNT]);
int main(){
  std::cout << "Input list" << std::endl;
  Stud students[COUNT];
  for(int i = 0; i < COUNT; i++){
      std::cin >> students[i].name >> students[i].gendr >>
    students[i].finish >> students[i].adress >>
    students[i].grand >> students[i].date.day >>
    students[i].date.manth >> students[i].date.year;
  for(int k = 0; k<5;k++)
    std::cin >> students[i].marks[k];
  std::cin >> students[i].point;
  }
  std::cout << "Sorted"<<std::endl;
  for(int i = 0; i < COUNT; i++)
    if((students[i].grand == 'y')
      &&(students[i].date.year >= 1989)
      &&(students[i].date.year <= 1990))
        Show(students[i]);
  getch();
  return 0;
}
void Show(Stud students){
  std::cout << students.name << ' ' << students.gendr <<
    ' ' << students.finish << ' ' << students.adress <<
    ' ' << students.grand << ' ' << students.date.day <<
    ' ' << students.date.manth << ' ' << students.date.year << ' ';
  for(int k = 0; k<5;k++)
    std::cout << students.marks[k] << ' ';
  std::cout << students.point << std::endl;
}
void Sort(Stud students[COUNT]){
  for(int i = 0; i < COUNT; i++){
    if((students[i].grand == 'y')
      &&(students[i].date.year >= 1989)
      &&(students[i].date.year <= 1990)){
        std::cout << students[i].name << ' ' << students[i].gendr <<
          ' ' << students[i].finish << ' ' << students[i].adress <<
          ' ' << students[i].grand << ' ' << students[i].date.day <<
          ' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
        for(int k = 0; k<5;k++)
          std::cout << students[i].marks[k] << ' ';
        std::cout << students[i].point << std::endl;
    }
  }
}
