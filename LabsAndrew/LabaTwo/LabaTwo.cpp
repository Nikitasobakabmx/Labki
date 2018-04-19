#include <iostream>
#include <conio.h>
#define COUNT 8
using namespace std;
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
int Sort(Stud students[COUNT]);
int main(){
  cout << "Input list" << endl;
  Stud students[COUNT];
  for(int i = 0; i < COUNT; i++){
      cin >> students[i].name.name >> students[i].name.surname >>
	  	students[i].name.patronymic >> students[i].gendr >>
    	students[i].finish >> students[i].adress >>
    	students[i].grand >> students[i].date.day >>
    	students[i].date.manth >> students[i].date.year;
  for(int k = 0; k<5;k++)
    cin >> students[i].marks[k];
  cin >> students[i].point;
  }
  cout << "Sorted"<<endl;
  cout << "Peoples who have 3 : " << Sort(students) << endl;
  getch();
  return 0;
}
int Sort(Stud students[COUNT]){
	int count = 0;
	for(int i = 0; i < COUNT; i++){
  		for(int k = 0; k<5;k++){
    		if(students[i].marks[k] == 3){
        		cout << students[i].name.name << '.' << students[i].name.surname <<
					'.' << students[i].name.patronymic << ' ' << students[i].gendr <<
    				' ' << students[i].finish << ' ' << students[i].adress <<
    				' ' << students[i].grand << ' ' << students[i].date.day <<
    				' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
  				for(int z = 0; z<5;z++)
    				cout << students[i].marks[z] << ' ';
  				cout << students[i].point << endl;
  				count++;
  				break;
			}
    	}
  	}
  	return count;
}
