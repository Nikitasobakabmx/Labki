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
void Sort(Stud *students){
	bool ex = false;
	while(!ex){
		ex = true;
		for(int i = 0; i < COUNT-1; i++){
            float tmp1 = 0;
            float tmp2 = 0;
            for(int k = 0; k < 5; k++){
                tmp1 += students[i].marks[k];
                tmp2 += students[i+1].marks[k];
            }
            if(tmp2 < tmp1){    
                Stud tmp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = tmp;
                ex = false;
            }
        }
	}
  
}
int main(){
  Stud students[COUNT];
  cout << "Input list" <<endl;
  for(int i = 0; i < COUNT; i++){
      cin >> students[i].name >> students[i].gendr >>
    students[i].finish >> students[i].adress >>
    students[i].grand >> students[i].date.day >>
    students[i].date.manth >> students[i].date.year;
  for(int k = 0; k<5;k++)
    cin >> students[i].marks[k];
  cin >> students[i].point;
  }
  cout<<"Sorted"<<endl;
  Sort(students);
  for(int i = 0; i < COUNT; i++){
      cout << students[i].name << ' ' << students[i].gendr <<
    ' ' << students[i].finish << ' ' << students[i].adress <<
    ' ' << students[i].grand << ' ' << students[i].date.day <<
    ' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
  for(int k = 0; k<5;k++)
    cout << students[i].marks[k] << ' ';
  cout << students[i].point << endl;
  }
  getch();
  return 0;
}
