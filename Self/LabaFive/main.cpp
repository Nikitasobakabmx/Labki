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
void readFile(ifstream &file, Stud *students){
    file >> students->name >> students->gendr >> students->finish >>
      students->adress >> students->grand >> students->date.day >>
      students->date.manth >> students->date.year;
    for(int k = 0; k < 5; k++)
      file >> students->marks[k];
    file >> students->point;
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
    string src = "/home/nikita/Documents/Coding/c++/Labki/Self/LabaFive/";
    ifstream iFile; //read
    ofstream oFile; //write
    string data("");
    Stud students[COUNT];
    cout << "Open file for write" << endl;
    openWriteFile(src, &oFile);
    cout << "input students" << endl;
    for(int i = 0; i < COUNT; i++){
        input(&students[i]);
        data += writeString(students[i]);
    }
    cout << "Writing to file" << endl;
    oFile << data;
    oFile.close();
    cout << "Open file for read" << endl;
    openReadFile(src, &iFile);
    cout << "Read and output students" <<endl;
    for(int i = 0; i < COUNT; i++){
        readFile(iFile, &students[i]);
        output(students[i]);
    }
    cout << "input name of file for writing sorted list" << endl;
    openWriteFile(src, &oFile);
    cout << "Sorted" << endl;
    data = "";
    for(int i = 0; i < COUNT; i++){
        if((students[i].grand == 'y')
          &&(students[i].date.year == 1989)
          &&(students[i].date.year == 1990)){
            output(students[i]);
            data += writeString(students[i]);
          }
    }
    cout << "Write to file" << endl;
    oFile << data;
    oFile.close();
    iFile.close();
    cout << "Complate!" << endl;
    return 0;
}