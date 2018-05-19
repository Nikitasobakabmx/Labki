#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define COUNT 8
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
void openWriteFile(string src, ofstream *file){
    while(true){
  	    cout << "input name of file\n";
  	    string name;
  	    cin >> name;
  	    string path = src + name;
        file->open(path, ios_base::app);
        if(file->is_open())
            return;
        std::cout << "Create in src folder? : ";
        bool qs;
        cin >> qs;
        if(qs){
            file->open(name);
            return;
        }
    }
    cout << "File is open\n";
}
string writeString(Stud students){
    string data("");
    data += students.name + " " + students.gendr + " " + students.finish + " " + 
        students.adress + " " + students.grand + " " + to_string(students.date.day) + " " +
        to_string(students.date.manth) + " " + to_string(students.date.year) + " ";
    for(int k = 0; k<5;k++)
        data += to_string(students.marks[k]) + " ";
    data += to_string(students.point) + "\n";
    return data;
}
void input(Stud *students){
    cin >> students->name >> students->gendr >>
    	students->finish >> students->adress >>
    	students->grand >> students->date.day >>
    	students->date.manth >> students->date.year;
    for(int k = 0; k<5;k++)
        cin >> students->marks[k];
    cin >> students->point;
}
int main(){
    ofstream file;
    Stud students[COUNT];
    string data = "";
    string src = "C:\\Users\\Anrew\\Documents\\Labs\\";
    openWriteFile(src, &file);
    cout << "Input list" << endl;
    for(int i = 0; i < COUNT; i++){
        input(&students[i]);
        data += writeString(students[i]);
    }
    cout<<"Write in file\n";
    file << data;
    file.close();
    return 0;
}
