#include <iostream>
#include <conio.h>
#define COUNT 6
struct Date{
    int day;
    int manth;
    int year;
};
struct Name{
	char name[10];
	char surname;
	char patronymic;
};
struct Stud{
    Name name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};
//void Show(Stud students);
void Sort(Stud students[COUNT]);
int main(){
  std::cout << "Input list" << std::endl;
  Stud students[COUNT];
  for(int i = 0; i < COUNT; i++){
      std::cin >> students[i].name.name >> students[i].name.surname >> students[i].name.patronymic >> students[i].gendr >>
    	students[i].finish >> students[i].adress >>
    	students[i].grand >> students[i].date.day >>
    	students[i].date.manth >> students[i].date.year;
  for(int k = 0; k<5;k++)
    std::cin >> students[i].marks[k];
  std::cin >> students[i].point;
  }
  std::cout << "Sorted"<<std::endl;
  /*for(int i = 0; i < COUNT; i++)
    if((students[i].grand == 'y')
      &&(students[i].date.year >= 1989)
      &&(students[i].date.year <= 1990))
        Show(students[i]);*/
  Sort(students);
  getch();
  return 0;
}
/*void Show(Stud students){
  std::cout << students.name.name << students.name.surname << students.name.patronymic << ' ' << students.gendr <<
    ' ' << students.finish << ' ' << students.adress <<
    ' ' << students.grand << ' ' << students.date.day <<
    ' ' << students.date.manth << ' ' << students.date.year << ' ';
  for(int k = 0; k<5;k++)
    std::cout << students.marks[k] << ' ';
  std::cout << students.point << std::endl;
}*/
void Sort(Stud students[COUNT]){
  for(int i = 0; i < COUNT; i++){
    if((students[i].grand == 'y')
      &&(students[i].date.year >= 1989)
      &&(students[i].date.year <= 1990)){
        std::cout << students[i].name.name << students[i].name.surname << students[i].name.patronymic << ' ' << students[i].gendr <<
    		' ' << students[i].finish << ' ' << students[i].adress <<
    		' ' << students[i].grand << ' ' << students[i].date.day <<
    		' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
  		for(int k = 0; k<5;k++)
    		std::cout << students[i].marks[k] << ' ';
  		std::cout << students[i].point << std::endl;
    }
  }
}
