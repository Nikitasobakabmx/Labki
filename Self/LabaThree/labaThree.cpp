#include <io.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 6
#define TO_STRING(char) {data = strncat(data,char,10);data = strncat(data," ",1);};
#define SIZE_OF(obj,type) sizeof(obj)/sizeof(type)
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
struct Student{
    Name name;
    char gendr;
    char finish;
    char adress;
    char grand;
    Date date;
    int marks[5];
    int point;
};
Student students[COUNT];
FILE *document;
char dir[] = "C:\\Users\\Nikita\\Documents\\Coding\\C++\\Labs\\Self\\LabaThree\\";
char name[20];

void writeToFile(Student student);
void OpenFile();
void Input();
int main(){
    OpenFile();
    Input();
    for(int i = 0;i < COUNT; i++){
        writeToFile(students[i]);
        
    }
    printf("Complate!");
    return 0;
}
void writeToFile(Student student){
    int i = 0;
    char *data = (char*) malloc(255);
    printf("...");
    TO_STRING(student.name.name)
    printf("%i",++i);
    TO_STRING(&student.name.surname)
    printf("%i",++i);
    TO_STRING(&student.name.patronymic)
    printf("%i",++i);
    TO_STRING(&student.gendr)
    printf("%i",++i);
    TO_STRING(&student.finish)
    printf("%i",++i);
    TO_STRING(&student.adress)
    printf("%i",++i);
    TO_STRING(&student.grand)
    printf("%i",++i);
    TO_STRING(&(student.date.day + '0'))
    printf("%i",++i);
    TO_STRING(&(student.date.manth + '0'))
    printf("%i",++i);
    TO_STRING(&(student.date.year + '0'))
    printf("%i",++i);
    for(int k = 0; k<5;k++)
        TO_STRING(&(student.marks[k] + '0'))
    printf("%i",++i);
    TO_STRING(&(student.point + '0'))
    TO_STRING("\n")
    //fwrite(data,sizeof(data),SIZE_OF(data,char),document);
}
void OpenFile(){
    while(true){
        printf("Input name of file : ");
        gets(name);
        char *path = strncat(dir,name,255);
        if((document = fopen(path,"w")) != nullptr)
            break;
        printf("\nFile not exist\n");
        printf("Create new? : ");
        int question;
        scanf("%i",&question);
        if(question == 1){
            int create = creat(name,0000200);
            if(create == -1){
                printf("It is anable to create the file \n");
                continue;
            }
            document = fopen(name,"w");
            break;
        }
        free(path);
        fflush(stdout);
    }
    printf("\tFile is open\n\tInput List\n");
}
void Input(){
    for(int i = 0; i < COUNT; i++){
        scanf("%s%s%s%s%s%s%s%i%i%i", &students[i].name.name,
            &students[i].name.surname, &students[i].name.patronymic,
            &students[i].gendr, &students[i].finish, &students[i].adress,
            &students[i].grand, &students[i].date.day, &students[i].date.manth,
            &students[i].date.year);
    for(int k = 0; k<5;k++)
        scanf("%i",&students[i].marks[k]);
        scanf("%i", &students[i].point);
    }
    printf("Write in file\n");
}
