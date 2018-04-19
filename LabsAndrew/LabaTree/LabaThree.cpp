#include <conio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
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
int main(){
    ofstream file;
    char *path = "C:\\", *name;
    cout << "Input name of file : ";
    cin >> name;
    strcat(path, name);
    file.open(path);
    if(!file.is_open())
        cout << "Path is not exist\n";
    cout << "File is open\n";
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
    cout<<"Write in file\n";
  	for(int i = 0; i < COUNT; i++){
        file << students[i].name.name << ' ' << students[i].name.surname <<
			' ' << students[i].name.patronymic << ' ' << students[i].gendr <<
    		' ' << students[i].finish << ' ' << students[i].adress <<
    		' ' << students[i].grand << ' ' << students[i].date.day <<
    		' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
  		for(int z = 0; z<5;z++)
    		file << students[i].marks[z] << ' ';
  		file << students[i].point << "\n";
  	}
  	file.close();
    getch();
    return 0;
}
