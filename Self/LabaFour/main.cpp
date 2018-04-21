#include <iostream>
#include <string>
#include <fstream>
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
void openReadFile(string src, ifstream *file){
    while(true){
  	cout << "input name of file\n";
  	string name;
  	cin >> name;
  	string path = src + name;
    file->open(path, ios_base::app);
    if(file->is_open())
        break;
    cout << "complete" << endl;
  }
}
void readFile(ifstream &file, Stud *students){
    file >> students->name >> students->gendr >> students->finish >>
      students->adress >> students->grand >> students->date.day >>
      students->date.manth >> students->date.year;
    for(int k = 0; k < 5; k++)
      file >> students->marks[k];
    file >> students->point;
}
void output(Stud students){
    cout << students.name << ' ' << students.gendr <<
        ' ' << students.finish << ' ' << students.adress <<
        ' ' << students.grand << ' ' << students.date.day <<
        ' ' << students.date.manth << ' ' << students.date.year << ' ';
    for(int k = 0; k<5;k++)
        cout << students.marks[k] << ' ';
    cout << students.point << endl;
}
int main(){
  string src = "/home/nikita/Documents/Coding/c++/Labki/Self/LabaFour/";
  ifstream file;
  openReadFile(src, &file);
  cout << "File is open\n";
  Stud students[COUNT];
  cout << "File read and put to struct" <<endl;
  for(int i = 0; i < COUNT; i++)
    readFile(file, &students[i]);
  cout << "Read success\n";
  cout << "Output list" << endl;
  for(int i = 0; i < COUNT; i++)
      output(students[i]);
  cout << "end" <<std::endl;
  file.close();
  return 0;
}
