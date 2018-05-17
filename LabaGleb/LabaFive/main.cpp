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
ifstream openReadFile(string src){
    ifstream file;
    while(true){
  	cout << "input name of file\n";
  	string name;
  	cin >> name;
  	string path = src + name;
    file.open(path, ios_base::out);
    if(file.is_open())
        break;
    cout << "complete" << endl;
  }
  return file;
}
ofstream openWriteFile(string src){
    ofstream file;
    while(true){
  	    cout << "input name of file\n";
  	    string name;
  	    cin >> name;
  	    string path = src + name;
        file.open(path, ios_base::in);
        if(file.is_open())
            break;
        std::cout << "Create in src folder? : ";
        bool qs;
        cin >> qs;
        if(qs){
            file.open(name);
            break;
        }
    }
    cout << "File is open\n";
    return file;
}
Stud readFile(ifstream &file){
    Stud students;
    file >> students.name >> students.gendr >> students.finish >>
      students.adress >> students.grand >> students.date.day >>
      students.date.manth >> students.date.year;
    for(int k = 0; k < 5; k++)
      file >> students.marks[k];
    file >> students.point;
    return students;
}
int main(){
    int centerPoint = 0;
    string src = "C:\\Users\\Nikitka\\Documents\\Coding\\C++\\Labki\\LabaGleb\\LabaFive\\";
    ifstream forRead; //read //iFile
    ofstream forWrite; //write oFile
    ofstream forWrite2; //write     sOFile
    string data("");
    Stud students[COUNT];
    cout << "Open file for write" << endl;
    forWrite = openWriteFile(src);
    cout << "input students" << endl;
    for(int i = 0; i < COUNT; i++){
      cin >> students[i].name >> students[i].gendr >>
    	students[i].finish >> students[i].adress >>
    	students[i].grand >> students[i].date.day >>
    	students[i].date.manth >> students[i].date.year;
      data += students[i].name + " " + students[i].gendr + " " + students[i].finish + " " + 
        students[i].adress + " " + students[i].grand + " " + to_string(students[i].date.day) + " " +
        to_string(students[i].date.manth) + " " + to_string(students[i].date.year) + " ";
  for(int k = 0; k<5;k++){
    cin >> students[i].marks[k];
    data += to_string(students[i].marks[k]) + " ";
  }
  cin >> students[i].point;
  data += to_string(students[i].point) + "\n";
  }
    cout << "Writing to file" << endl;
    forWrite << data;
    forWrite.close();

    cout << "Open file for read" << endl;
    forRead = openReadFile(src);
    cout << "Read and output students" <<endl;
    for(int i = 0; i < COUNT; i++)
        students[i] = readFile(forRead);
    forRead.close();
    for(int i = 0; i < COUNT; i++){
        cout << students[i].name << ' ' << students[i].gendr <<
        ' ' << students[i].finish << ' ' << students[i].adress <<
        ' ' << students[i].grand << ' ' << students[i].date.day <<
        ' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
        for(int k = 0; k<5;k++)
            cout << students[i].marks[k] << ' ';
        cout << students[i].point << endl;
    }

    cout << "input name of file for writing sorted list" << endl;
    forWrite2 = openWriteFile(src);
    cout << "Sorted" << endl;
    data = "";

    for(int i = 0; i < COUNT; i++){
        float tmp = 0;
        for(int k = 0; k < 5; k++)
            tmp += students[i].marks[k];
        centerPoint += tmp / 5;
    }
    centerPoint /= COUNT;
    int count = 0;
    for(int i = 0; i < COUNT ; i++){
        float tmp = 0;
        for(int k = 0; k < 5; k++)
            tmp += students[i].marks[k];
        tmp /= 5;
        if(tmp >= centerPoint){
                cout << students[i].name << ' ' << students[i].gendr <<
        ' ' << students[i].finish << ' ' << students[i].adress <<
        ' ' << students[i].grand << ' ' << students[i].date.day <<
        ' ' << students[i].date.manth << ' ' << students[i].date.year << ' ';
                data += students[i].name + " " + students[i].gendr + " " + students[i].finish + " " + 
                    students[i].adress + " " + students[i].grand + " " + to_string(students[i].date.day) + " " +
                    to_string(students[i].date.manth) + " " + to_string(students[i].date.year) + " ";
                for(int k = 0; k<5;k++){
                    cout << students[i].marks[k] << ' ';
                    data += to_string(students[i].marks[k]) + " ";
                }
                cout << students[i].point << endl;
                data += to_string(students[i].point) + "\n";
                count++;
        }
    }
    cout << "below average : " << count << endl;
    cout << "Write to file" << endl;
    forWrite2 << data;
    forWrite2.close();
    cout << "Complate!" << endl;
    return 0;
}
