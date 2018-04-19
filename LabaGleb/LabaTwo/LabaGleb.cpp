#include <iostream>
#include <string>
#include <conio.h>
#define COUNT 6
using namespace std;
struct Date{
    int day;
    int manth;
    int year;
};
struct Stud{
    string name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};
void Sort(Stud students[6], int centerPoint);
int main(){
  Stud students[COUNT];
  int centerPoint = 0;
  cout << "Input list" <<endl;
  for(int i = 0; i < COUNT; i++){
      cin >> students[i].name >> students[i].gendr >>
    students[i].finish >> students[i].adress >>
    students[i].grand >> students[i].date.day >>
    students[i].date.manth >> students[i].date.year;
  for(int k = 0; k<5;k++)
    cin >> students[i].marks[k];
  cin >> students[i].point;
  centerPoint += students[i].point;
  }
  centerPoint /= COUNT;
  cout<<"Sorted"<<endl;
  Sort(students, centerPoint);
  getch();
  return 0;
}
void Sort(Stud students[6], int centerPoint){
  for(int i = 0; i < COUNT; i++)
    if(students[i].point >= centerPoint){
      cout << students[i].name << ' ' << students[i].gendr <<
    ' ' << students[i].finish << ' ' << students[i].adress <<
    ' ' << students[i].grand << ' ' << students[i].date.day <<
    ' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
  for(int k = 0; k<5;k++)
    cout << students[i].marks[k] << ' ';
  cout << students[i].point << endl;
    }
}
